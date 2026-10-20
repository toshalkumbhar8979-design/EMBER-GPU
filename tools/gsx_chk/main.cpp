// tools/gsx_chk/main.cpp — minimal Verilator probe for ember_gsx (Phase 4b debug).
// Runs two scenarios against a C++ VRAM model:
//   A) identity matrix + screen-space triangle  -> expect px = coord << 22
//   B) matrix m33 = -1                          -> expect culled (no emit)
// Traces st/f_op/operands/results per cycle and dumps the emitted cmd words.
#include <cstdio>
#include <cstring>
#include "Vember_gsx.h"
#include "Vember_gsx___024root.h"
#include "verilated.h"

#define I(name) (d->rootp->ember_gsx__DOT__##name)

static uint32_t ram[131072];   // 512 KB VRAM word model

static inline uint32_t f2w(float f) { uint32_t w; std::memcpy(&w, &f, 4); return w; }

// BUS addresses: VRAM window at 0x1000; cmdq at VRAM offset 0x05B000.
static const uint32_t VRAM_BASE = 0x1000;
static const uint32_t CMDQ_BUS  = VRAM_BASE + 0x05B000;

static void commit_gxa(Vember_gsx* d) {
    if (!d->gxa_we) return;
    uint32_t off = (d->gxa_addr - VRAM_BASE) >> 2;
    ram[off & 0x1FFFF] = d->gxa_wdata;
    printf("    gxa wr [%08x] = %08x\n", d->gxa_addr, d->gxa_wdata);
}

static void csr_write(Vember_gsx* d, int addr, uint32_t data) {
    d->csr_we = 1; d->csr_addr = addr; d->csr_wdata = data;
    d->clk = 0; d->eval(); d->clk = 1; d->eval();
    d->csr_we = 0;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vember_gsx* d = new Vember_gsx;

    auto tick = [&]() { d->clk = 0; d->eval(); d->clk = 1; d->eval(); };

    d->clk = 0; d->rst_n = 0;
    d->csr_we = 0; d->csr_addr = 0; d->csr_wdata = 0; d->kick = 0;
    d->gxa_we = 0; d->gxa_addr = 0; d->gxa_wdata = 0; d->gxa_be = 0;
    d->gxa_req = 0;
    for (int i = 0; i < 5; i++) tick();
    d->rst_n = 1; tick();

    for (int scen = 0; scen < 2; scen++) {
        printf("\n=== SCENARIO %s ===\n", scen == 0 ? "A: identity" : "B: m33=-1 cull");
        std::memset(ram, 0, sizeof(ram));

        // load matrix
        for (int i = 0; i < 16; i++) {
            uint32_t w = 0;
            if (scen == 0) w = (i % 5 == 0) ? f2w(1.0f) : 0;
            else           w = (i == 15) ? f2w(-1.0f) : 0;
            csr_write(d, 0, w);
        }
        // vertices: (30,50,0.25) (150,100,0.25) (72,90,0.25) as fp32
        float vx[3] = {30.0f, 150.0f, 72.0f};
        float vy[3] = {50.0f, 100.0f, 90.0f};
        float vz[3] = {0.25f, 0.25f, 0.25f};
        for (int i = 0; i < 9; i++) {
            float f = (i % 3 == 0) ? vx[i/3] : (i % 3 == 1) ? vy[i/3] : vz[i/3];
            csr_write(d, 1, f2w(f));
        }
        for (int i = 0; i < 3; i++) csr_write(d, 2, 0x001464C8);  // {b,g,r,x}

        // kick + trace
        d->kick = 1; tick(); d->kick = 0;
        int cycles = 0;
        while (d->busy && cycles < 3000) {
            printf("c%04d st=%2d go=%d op=%d a0=%08x b0=%08x y0=%08x acc=%08x,%08x,%08x,%08x v=%u k=%u ph=%u win=%08x\n",
                   cycles, (int)I(st), (int)I(f_go), (int)I(f_op),
                   I(f_a0), I(f_b0), I(f_y0),
                   I(acc0), I(acc1), I(acc2), I(acc3),
                   (unsigned)I(vidx), (unsigned)I(kstep), (unsigned)I(phase),
                   I(w_in));
            commit_gxa(d);
            tick();
            cycles++;
        }
        commit_gxa(d);
        printf("busy released after %d cycles; tri_count now %u\n",
               cycles, (unsigned)I(tri_count));
        // dump emitted triangle words
        for (int i = 0; i < 20; i++)
            printf("  cmd[%02d] = %08x\n", i,
                   ram[((CMDQ_BUS - VRAM_BASE) >> 2) + i]);

        // reset between scenarios
        d->rst_n = 0; for (int i = 0; i < 5; i++) tick(); d->rst_n = 1; tick();
    }

    delete d;
    printf("DONE\n");
    return 0;
}
