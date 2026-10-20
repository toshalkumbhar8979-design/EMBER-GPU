// main.cpp — C++ probe: ember_core running the pool2d kernel, traced.
// Same layout as the cocotb TB: params at CMDBUF (0x05B000), code at
// CMDBUF+0x400, planes at 0x25000, outputs at 0x26000 (VRAM offsets;
// the core's LD/ST take VRAM byte offsets directly).
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "Vember_core.h"
#include "Vember_core___024root.h"
#include "verilated.h"

// VRAM offsets the kernel uses
static const uint32_t CMDBUF = 0x05B000, CODEBUF = CMDBUF + 0x400;
static const uint32_t CORE_A = 0x25000, CORE_O = 0x28000;
// (CORE_A needs 2704 words = 0x2A40 bytes; CORE_O MUST sit above it —
// 0x26000 OVERLAPPED the input and the 'outputs' were raw input bytes)
static const uint32_t VB = 0x1000;   // VRAM_BASE: core LD/ST/fetch are BUS
                                     // addresses; strip it like addr2word
static uint32_t vram[128 * 1024];

static uint64_t ticks = 0;

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    memset(vram, 0, sizeof(vram));

    // ---- params: [0]=base [1]=obase [2]=opx [3]=ow [4]=nchan [5]=ws4
    //              [6]=ppc                                            ----
    uint32_t params[7] = {CORE_A, CORE_O, 169, 13, 4, 4 * 26, 676};
    memcpy((uint8_t*)vram + CMDBUF, params, sizeof(params));

    // ---- plane: deterministic pseudo-random bytes. 4ch x 676 px = 2704
    // pixels, ONE PER WORD = 2704 words (do NOT overshoot into CORE_O!) --
    for (uint32_t i = 0; i < 2704; i++) {
        uint32_t j = i;
        j = (j ^ 61) ^ (j >> 16);
        j = j + (j << 3);
        j = j ^ (j >> 4);
        j = j * 0x27d4eb2d;
        j = j ^ (j >> 15);
        vram[(CORE_A >> 2) + i] = (j & 0xFF);   // raw byte 0..255
    }

    // ---- kernel: assemble offline, hex file one word per line ----
    FILE* kf = fopen("pool_words.txt", "r");
    if (!kf) { printf("FAIL: no pool_words.txt\n"); return 2; }
    std::vector<uint32_t> code;
    unsigned w;
    while (fscanf(kf, "%x", &w) == 1) code.push_back(w);
    fclose(kf);
    printf("kernel words: %zu\n", code.size());
    memcpy((uint8_t*)vram + CODEBUF, code.data(), code.size() * 4);

    Vember_core* d = new Vember_core;
    d->rst_n = 0;
    d->kick = 0;
    d->csr_we = 0;
    for (int i = 0; i < 4; i++) { d->clk = 0; d->eval(); d->clk = 1; d->eval(); }
    d->rst_n = 1;
    for (int i = 0; i < 2; i++) { d->clk = 0; d->eval(); d->clk = 1; d->eval(); }

    // program via CSR: addr0 = code base, addr1 = nblk (like the CP does)
    auto csr_write = [&](uint32_t addr2, uint32_t data) {
        d->csr_addr = addr2;
        d->csr_wdata = data;
        d->csr_we = 1;
        d->clk = 0; d->eval(); d->clk = 1; d->eval();
        d->csr_we = 0;
    };
    csr_write(0, CODEBUF);
    csr_write(1, 1);

    d->kick = 1;
    { d->clk = 0; d->eval(); d->clk = 1; d->eval(); }
    d->kick = 0;

    // snapshot inputs for the golden check
    uint32_t in_snap[2704];
    memcpy(in_snap, (uint8_t*)vram + CORE_A, sizeof(in_snap));

    auto* r = d->rootp;
    int traced = 0;
    while (ticks < 6000000) {
        uint8_t st = r->ember_core__DOT__st;
        uint8_t running = r->ember_core__DOT__running;
        uint8_t etid = r->ember_core__DOT__exec_tid;
        // trace EXECUTE events (exec_en is combinational; ibuf_v gate it)
        if (running && (r->ember_core__DOT__ibuf_v >> etid) & 1 &&
            (ticks > 2000) && (ticks < 2600) && etid == 0 && traced < 200) {
            uint32_t iw = r->ember_core__DOT__ibuf_w[etid];
            printf("[T%05llu] tid=%u pc=%02u op=%02x rd=%u ra=%u rb=%u "
                   "imm=%03x nzp=%u r14=%08x r9=%u r13=%08x\n",
                   (unsigned long long)ticks, etid,
                   r->ember_core__DOT__fpc[etid], iw >> 24,
                   (iw >> 20) & 0xF, (iw >> 16) & 0xF, (iw >> 12) & 0xF,
                   iw & 0xFFF,
                   (r->ember_core__DOT__T[etid] >> 0) & 0x7,
                   r->ember_core__DOT__gpr[0][14],
                   r->ember_core__DOT__gpr[0][9],
                   r->ember_core__DOT__gpr[0][13]);
            traced++;
        }
        // ---- VRAM models: ixa (fetch) + cxa (data). The core consumes
        // ixa_rdata the cycle AFTER the req edge (req cycle N -> capture
        // reads rdata at N+1), so drive rdata from the latched address
        // AFTER the clk edge of the req — i.e. always keep rdata current
        // for the PREVIOUS cycle's address (mirror ember_vram: rdata_q
        // updates at the posedge while req is high).
        if (r->ember_core__DOT__ix_pend && !r->ember_core__DOT__ix_req_cyc) {
            // capture happens THIS edge using current ixa_rdata
        }
        if (r->ember_core__DOT__ixa_req || r->ember_core__DOT__ix_pend) {
            uint32_t a = r->ember_core__DOT__ixa_addr;
            if (ticks < 12)
                printf("[FETCH %05llu] ixa_addr=%08x word=%08x\n",
                       (unsigned long long)ticks, a,
                       vram[((a - VB) >> 2) & 0x1FFFF]);
            d->ixa_rdata = vram[((a - VB) >> 2) & 0x1FFFF];
        }
        // ST: cxa_we is a REGISTERED output high during EXECUTE (the write
        // commits at that posedge, like ember_vram's `if (cxa_we)`). It is
        // NOT gated by cxa_req — gate on we alone or the store is missed.
        if (r->ember_core__DOT__cxa_we) {
            vram[((r->ember_core__DOT__cxa_addr - VB) >> 2) & 0x1FFFF] =
                r->ember_core__DOT__cxa_wdata;
        }
        if (r->ember_core__DOT__cxa_req || r->ember_core__DOT__cx_pend) {
            uint32_t a = r->ember_core__DOT__cxa_addr;
            if (!r->ember_core__DOT__cxa_we)
                d->cxa_rdata = vram[((a - VB) >> 2) & 0x1FFFF];
        }
        d->clk = 0; d->eval();
        d->clk = 1; d->eval();
        ticks++;
        if (ticks % 100000 == 0) {
            printf("[SNAP %05llu] st=%u busy=%u budget=%07x fpc=[%u %u %u %u] "
                   "ld_pend=%u cx_pend=%u fp_pend=%u waitv=%x\n",
                   (unsigned long long)ticks,
                   r->ember_core__DOT__st, d->busy,
                   r->ember_core__DOT__budget,
                   r->ember_core__DOT__fpc[0], r->ember_core__DOT__fpc[1],
                   r->ember_core__DOT__fpc[2], r->ember_core__DOT__fpc[3],
                   r->ember_core__DOT__ld_pend,
                   r->ember_core__DOT__cx_pend,
                   r->ember_core__DOT__fp_pend,
                   r->ember_core__DOT__waitv);
        }
        if (!d->busy) break;
    }

    printf("ticks=%llu traced=%d\n", (unsigned long long)ticks, traced);

    // ---- golden check: 2x2 max pool, 4 ch x 26x26 -> 13x13 ----
    int bad = 0, badper[4] = {0, 0, 0, 0};
    for (int c = 0; c < 4; c++) {
        for (int p = 0; p < 169; p++) {
            int y = p / 13, x = p % 13;
            uint32_t t00 = in_snap[c * 676 + (2 * y) * 26 + 2 * x];
            uint32_t t01 = in_snap[c * 676 + (2 * y) * 26 + 2 * x + 1];
            uint32_t t10 = in_snap[c * 676 + (2 * y + 1) * 26 + 2 * x];
            uint32_t t11 = in_snap[c * 676 + (2 * y + 1) * 26 + 2 * x + 1];
            int m = -128;
            uint32_t taps[4] = {t00, t01, t10, t11};
            for (int k = 0; k < 4; k++) {
                int v = (int8_t)(taps[k] & 0xFF);
                if (v > m) m = v;
            }
            uint32_t got = vram[(CORE_O >> 2) + c * 169 + p] & 0xFF;
            if (got != (uint32_t)(m & 0xFF)) {
                if (bad < 8)
                    printf("BAD c=%d p=%d got=%02x want=%02x\n",
                           c, p, got, m & 0xFF);
                bad++;
                badper[c]++;
            }
        }
    }
    printf("golden check: %d bad / 676 (per-ch: %d %d %d %d)\n",
           bad, badper[0], badper[1], badper[2], badper[3]);
    printf("out[c0 p0..9]:");
    for (int i = 0; i < 10; i++)
        printf(" %02x", vram[(CORE_O >> 2) + i] & 0xFF);
    printf("\nPROBE DONE\n");
    delete d;
    return 0;
}
