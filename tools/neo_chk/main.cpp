// main.cpp — NEORV32 sim-side gate: run the BARE-METAL C demo
// (sw/ember_demo.c) against the full ember_top, with the demo's MMIO
// mapped onto a cycle-accurate AXI4-Lite master model. No cocotb —
// same Verilator C++ pattern as tools/pool_chk.
//
// Build: see Makefile. ember_demo.c is compiled with
//   -Dmain=demo_main
//   -Dcp_mmio_write=ember_register_write
//   -Dcp_mmio_read=ember_register_read
// so its cp_driver.h calls land in this file's bus master.
//
// Time only advances inside bus operations (every cp_driver wait loop
// polls STATUS over the bus, so kicks of any length make progress).
// A watchdog bounds a wedged bus. Frames are read back THROUGH THE BUS
// (CP_CMDX dir=1 + FIFOD pops) exactly like real host software — no
// dbg sidecar anywhere in this gate.
#include <cstdio>
#include <csetjmp>
#include <cstdint>
#include "Vember_top.h"
#include "Vember_top___024root.h"
#include "verilated.h"

// The -D flags rename cp_driver.h's MMIO hooks to these — declare them
// BEFORE the header include in every translation unit. NOTE: plain C++
// linkage (ember_demo.c is g++-compiled here; on the board it is plain
// C and this harness does not exist).
void ember_register_write(uint32_t addr, uint32_t data);
uint32_t ember_register_read(uint32_t addr);
#include "../sw/cp_driver.h"   // register offsets / status bits (shared)

// ---- provided by ember_demo.c (compiled with -Dmain=demo_main) ------
int demo_main(void);

// ---- sim shim state --------------------------------------------------
static int g_gsx_trace = 0;      // set by ember_frame_marker(0)
static jmp_buf g_exit;
static int g_exit_code = 0;
static int g_halted = 0;
static uint64_t g_ticks = 0;
static uint32_t g_last_read = 0;
static Vember_top* d = nullptr;

void ember_putc(char c) { putchar(c); fflush(stdout); }

void ember_frame_marker(int frame) { g_gsx_trace = (frame == 0 || frame == 2); }

void ember_halt(int code) {
    printf("\n[DEMO HALT %d] ticks=%llu\n", code,
           (unsigned long long)g_ticks);
    fflush(stdout);
    g_exit_code = code;
    if (g_halted++) {                 // re-entry: exit hard, no longjmp
        printf("NEO_CHK DONE (forced)\n");
        exit(code);
    }
    longjmp(g_exit, 1);
}

// ---- AXI4-Lite master model ------------------------------------------
// AW and W handshakes are tracked INDEPENDENTLY (the CP slave may accept
// them on different cycles — the cocotb AxiLiteDriver does the same).
static int ch_aw, ch_w, ch_b, ch_r, ch_rv;
static uint32_t m_addr, m_wdata, m_wstrb;

static void gsx_watch(void) {
    // after each posedge: catch CFG writes + kick fall + emit activity
    auto* r = d->rootp;
    static int prev_busy = 0;
    int csr_we = r->ember_top__DOT__gsx_csr_we;
    int busy = r->ember_top__DOT__u_gsx__DOT__busy_r;        if (g_gsx_trace && (csr_we || (prev_busy && !busy))) {
        unsigned cfgaddr = r->ember_top__DOT__gsx_csr_addr;
        unsigned tcnt = r->ember_top__DOT__u_gsx__DOT__tri_count;
        unsigned etex = r->ember_top__DOT__u_gsx__DOT__cfg_tex;
        unsigned ebase = r->ember_top__DOT__u_gsx__DOT__emit_base;
        if (cfgaddr != 1)      // skip the 15 VTX words per tri (noise)
            printf("[gsx t=%llu] we=%d addr=%u tri_count=%u tex=%u "
                   "busy=%d emit_base=%x\n",
                   (unsigned long long)g_ticks, csr_we, cfgaddr,
                   tcnt, etex, busy, ebase);
    }
    prev_busy = busy;

    // scan FB-write trace: MUXED top-level fpa signals at the VRAM pin
    static int scan_writes = 0;
    static int prev_rtr_busy = 0;
    int rtr_busy = r->ember_top__DOT__rtr_busy;
    if (prev_rtr_busy && !rtr_busy) scan_writes = 0;   // new sweep
    if (g_gsx_trace && rtr_busy && scan_writes < 12) {
        if (r->ember_top__DOT__u_rtr__DOT__scan_fpa_we) {
            printf("[fb t=%llu] we=1 addr=%08x data=%08x be=%x widx=%x\n",
                   (unsigned long long)g_ticks,
                   r->ember_top__DOT__u_rtr__DOT__scan_fpa_addr,
                   r->ember_top__DOT__u_rtr__DOT__scan_fpa_wdata,
                   r->ember_top__DOT__u_rtr__DOT__scan_fpa_be,
                   r->ember_top__DOT__u_vram__DOT__fpa_widx);
            scan_writes++;
        }
    }
    prev_rtr_busy = rtr_busy;
}

static void tick(void) {
    // drive master signals
    d->h_awaddr = m_addr;  d->h_awvalid = ch_aw;
    d->h_wdata = m_wdata;  d->h_wstrb = m_wstrb; d->h_wvalid = ch_w;
    d->h_araddr = m_addr;  d->h_arvalid = ch_r;
    d->h_bready = ch_b;
    d->h_rready = ch_rv;

    d->clk = 0; d->eval();                 // combinational settle
    // sample handshakes AS THEY WILL BE AT THE POSEDGE (post-edge sampling
    // misses acceptances whose ready drops on the accepting edge — the
    // ram_slave's arready falls the cycle it accepts, and a tolerant
    // retry would DOUBLE-POP the destructive FIFOD read register)
    int aw_ok = ch_aw && d->h_awready;
    int w_ok  = ch_w  && d->h_wready;
    int b_ok  = ch_b  && d->h_bvalid;
    int r_ok  = ch_r  && d->h_arready;
    int rv_ok = ch_rv && d->h_rvalid;
    uint32_t rdata = d->h_rdata;

    d->clk = 1; d->eval();                 // posedge: slave acts on beats
    g_ticks++;

    gsx_watch();

    if (aw_ok) ch_aw = 0;
    if (w_ok)  ch_w = 0;
    if (b_ok)  ch_b = 0;
    if (r_ok)  { ch_r = 0; ch_rv = 1; }
    if (rv_ok) { g_last_read = rdata; ch_rv = 0; }

    if ((g_ticks & 0xFFFFFu) == 0)
        printf("[wd %llu] aw=%d w=%d b=%d r=%d rv=%d addr=%08x\n",
               (unsigned long long)g_ticks, ch_aw, ch_w, ch_b, ch_r,
               ch_rv, m_addr);
}

static void bus_write(uint32_t addr, uint32_t data) {
    m_addr = addr; m_wdata = data; m_wstrb = 0xF;
    ch_aw = 1; ch_w = 1; ch_b = 1;
    uint64_t guard = 0;
    while (ch_aw || ch_w || ch_b) {
        tick();
        if (++guard > 10000) {
            printf("BUS WRITE STALL addr=%08x t=%llu\n", addr,
                   (unsigned long long)g_ticks);
            ember_halt(9);
        }
    }
}

static uint32_t bus_read(uint32_t addr) {
    m_addr = addr;
    ch_r = 1; ch_rv = 0;
    uint64_t guard = 0;
    while (ch_r || ch_rv) {
        tick();
        if (++guard > 10000) {
            printf("BUS READ STALL addr=%08x t=%llu\n", addr,
                   (unsigned long long)g_ticks);
            ember_halt(9);
        }
    }
    return g_last_read;
}

void ember_register_write(uint32_t addr, uint32_t data) {
    bus_write(addr, data);
}
uint32_t ember_register_read(uint32_t addr) {
    return bus_read(addr);
}

// ---- frame readback THROUGH THE BUS (CP readback FIFO) ---------------
static void vram_read(uint32_t vram_off, uint32_t* words, uint32_t nwords,
                      uint8_t fence) {
    cp_download(vram_off, words, nwords, fence);
}

static int frame_count = 0;

static void dump_frame_ppm(void) {
    // every 2nd row, 320 px — SAME sampling as tb_input's artifacts so a
    // pixel diff against input_rtl_f30.ppm is meaningful
    const uint32_t ROWS = 120;                 // 240/2
    static uint32_t buf[120 * 160];
    for (int r = 0; r < (int)ROWS; r++) {
        uint32_t y = 2u * r;
        uint32_t off = 2u * (y * 320u);
        vram_read(off, &buf[r * 160], 160, 9);
    }
    char name[64];
    snprintf(name, sizeof(name), "neo_frame_%02d.ppm", frame_count);
    FILE* f = fopen(name, "w");
    fprintf(f, "P3\n320 %u\n255\n", ROWS);
    for (uint32_t r = 0; r < ROWS; r++) {
        for (int x = 0; x < 320; x++) {
            uint32_t w = buf[r * 160 + (x >> 1)];
            uint32_t p = ((x & 1) ? (w >> 16) : w) & 0xFFFF;
            fprintf(f, "%u %u %u ",
                    ((p >> 11) & 0x1F) << 3, ((p >> 5) & 0x3F) << 2,
                    (p & 0x1F) << 3);
        }
        fprintf(f, "\n");
    }
    fclose(f);
    frame_count++;
}

#ifdef main
#undef main                  // the -Dmain=demo_main flag is for the demo TU
#endif
int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    d = new Vember_top;
    d->rst_n = 0;
    d->fb_select = 0;
    d->h_awvalid = 0; d->h_wvalid = 0; d->h_arvalid = 0;
    d->h_bready = 0;  d->h_rready = 0;
    d->dbg_en = 0; d->dbg_addr = 0; d->dbg_wdata = 0; d->dbg_be = 0;
    for (int i = 0; i < 4; i++) {
        d->clk = 0; d->eval(); d->clk = 1; d->eval();
    }
    d->rst_n = 1;
    for (int i = 0; i < 2; i++) {
        d->clk = 0; d->eval(); d->clk = 1; d->eval();
    }

    if (setjmp(g_exit) == 0) {
        // bring-up probe: can this master see the CP at all?
        printf("[probe] ID=%08x STATUS=%08x\n",
               bus_read(CP_BASE + CP_ID), bus_read(CP_BASE + CP_STATUS));

        // ---- minimal core-kick probe: 3-word MATADD at CMDBUF+0x200 ----
        {
            const uint32_t CODE = 0x05B400u;
            const uint32_t code[4] = {0x214A0000u, 0x0E4B0008u, 0x114B0008u,
                                      0xFF000000u};
            const uint32_t params[2] = {0x55AA55AAu, 0x12345678u};
            bus_write(CP_BASE + CP_FIFOD, params[0]);
            bus_write(CP_BASE + CP_FIFOD, params[1]);
            bus_write(CP_BASE + CP_DMA_DST, CODE);
            bus_write(CP_BASE + CP_DMA_LEN, 8);
            bus_write(CP_BASE + CP_CMDX, (6u << 8) | 0u);
            while (bus_read(CP_BASE + CP_STATUS) & ST_DMA_BUSY) { }
            for (int i = 0; i < 4; i++)
                bus_write(CP_BASE + CP_FIFOD, code[i]);
            bus_write(CP_BASE + CP_DMA_DST, CODE + 0x200u);
            bus_write(CP_BASE + CP_DMA_LEN, 16);
            bus_write(CP_BASE + CP_CMDX, (6u << 8) | 0u);
            while (bus_read(CP_BASE + CP_STATUS) & ST_DMA_BUSY) { }
            uint32_t pb[4];
            cp_download(CODE + 0x200u, pb, 4, 6);
            printf("[probe] code@%x: %08x %08x %08x %08x\n",
                   CODE + 0x200u, pb[0], pb[1], pb[2], pb[3]);
            bus_write(CP_BASE + CP_CORE_CODE, CODE + 0x200u);
            bus_write(CP_BASE + CP_CORE_NBLK, 1);
            bus_write(CP_BASE + CP_CORE_KICK, 1);
            int saw_busy = 0;
            for (int i = 0; i < 8000000; i++) {
                uint32_t st = bus_read(CP_BASE + CP_STATUS);
                if (st & ST_CORE_BUSY) saw_busy = 1;
                if (!(st & ST_CORE_BUSY)) break;
            }
            printf("[probe] matadd: saw_busy=%d STATUS=%08x\n",
                   saw_busy, bus_read(CP_BASE + CP_STATUS));
            cp_download(CODE, pb, 2, 6);
            printf("[probe] out: %08x %08x (want 68DEF022)\n",
                   pb[0], pb[1]);
        }
        // trace GSX only for the first frame of the demo
        g_gsx_trace = 1;
        demo_main();               // the bare-metal demo, as-is
        printf("[demo_main returned without halt]\n");
        g_exit_code = 8;
    }

    // cmdq forensics: what did GSX actually emit? Slots 0..2 + slot 120
    uint32_t cq[57];
    vram_read(0x05B000u, cq, 57, 9);
    for (int s = 0; s < 3; s++) {
        printf("[probe] slot%d w0-6:", s);
        for (int i = 0; i < 7; i++) printf(" %08x", cq[s * 19 + i]);
        printf("\n");
    }
    // decisive: FB words 0xB9F0..0xBA04 (around traced write @0xB9F8)
    uint32_t fbw[6];
    vram_read(0xB9F0u, fbw, 6, 9);
    printf("[probe] FB@B9F0:");
    for (int i = 0; i < 6; i++) printf(" %08x", fbw[i]);
    printf("\n");
    // GSX's mata registers = ground truth of the last-loaded matrix
    printf("[probe] GSX mata:\n");
    for (int r = 0; r < 4; r++) {
        printf("[probe]  row%d:", r);
        for (int c = 0; c < 4; c++)
            printf(" %08x",
                   d->rootp->ember_top__DOT__u_gsx__DOT__mata[4 * r + c]);
        printf("\n");
    }
    uint32_t cq2[19];
    vram_read(0x05B000u + 120u * 76u, cq2, 19, 9);
    printf("[probe] slot120 w0-6:");
    for (int i = 0; i < 7; i++) printf(" %08x", cq2[i]);
    printf("\n");

    // post-demo probes: did the DMA uploads actually land?
    uint32_t pb[8];
    vram_read(0x0, pb, 4, 9);      // FB words 0..3
    printf("[probe] FB[0..3]=%08x %08x %08x %08x\n",
           pb[0], pb[1], pb[2], pb[3]);
    vram_read(0x025800, pb, 2, 9); // Z words 0..1
    printf("[probe] Z[0..1]=%08x %08x\n", pb[0], pb[1]);
    vram_read(0x04B000, pb, 2, 9); // TEX words 0..1
    printf("[probe] TEX[0..1]=%08x %08x\n", pb[0], pb[1]);
    vram_read(0x071000, pb, 8, 9); // gamestate block
    printf("[probe] GS=%08x %08x f32x=%08x f32z=%08x echo=%08x r3=%08x\n",
           pb[0], pb[1], pb[4], pb[5], pb[6], pb[7]);

    dump_frame_ppm();              // eyeball the last rendered frame
    printf("ticks=%llu frames_dumped=%d exit=%d\n",
           (unsigned long long)g_ticks, frame_count, g_exit_code);
    printf("NEO_CHK DONE\n");
    delete d;
    return g_exit_code;
}
