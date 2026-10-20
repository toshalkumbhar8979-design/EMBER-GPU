// tools/core_chk/main.cpp — minimal Verilator probe for ember_core (Phase 5).
// Currently configured for the matadd scenario: A[i]=i, B[i]=2i, expect
// A[i] -> 3i. Traces the FSM per cycle and dumps the first A words after.
#include <cstdio>
#include <cstring>
#include "Vember_core.h"
#include "Vember_core___024root.h"

#define I(name) (d->rootp->ember_core__DOT__##name)

static uint32_t ram[131072];   // 512 KB VRAM word model

static const uint32_t VRAM_BASE = 0x1000;
static const uint32_t CMDBUF = 0x5B000;          // VRAM offset (params)
static const uint32_t CODEBUF = CMDBUF + 0x400;  // VRAM offset (kernel)
static const uint32_t A_OFF = 0x59000, B_OFF = 0x59800;

// matadd kernel words (from tools/assembler.py output, verified)
static const uint32_t prog[] = {
    0x0da00001, 0x0d900002, 0x102c0000, 0x103c0004, 0x0d400020,
    0x035f4000, 0x08559000, 0x0d100000, 0x01625000, 0x01735000,
    0x10860000, 0x10970000, 0x01889000, 0x11860000, 0x0111a000,
    0x0ab14000, 0x204001f7, 0xff000000,
};
static const int NPROG = sizeof(prog) / sizeof(prog[0]);

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vember_core* d = new Vember_core;

    auto tick = [&]() { d->clk = 0; d->eval(); d->clk = 1; d->eval(); };

    d->clk = 0; d->rst_n = 0;
    d->csr_we = 0; d->csr_addr = 0; d->csr_wdata = 0; d->kick = 0;
    d->cxa_we = 0; d->cxa_addr = 0; d->cxa_wdata = 0; d->cxa_be = 0;
    d->cxa_req = 0; d->ixa_req = 0; d->ixa_addr = 0;
    for (int i = 0; i < 5; i++) tick();
    d->rst_n = 1; tick();

    // A[i] = i, B[i] = 2i  (word arrays at their VRAM offsets)
    for (int i = 0; i < 128; i++) {
        ram[(A_OFF >> 2) + i] = i;
        ram[(B_OFF >> 2) + i] = 2 * i;
    }
    // params: [0] = A offset, [1] = B offset
    ram[(CMDBUF >> 2) + 0] = A_OFF;
    ram[(CMDBUF >> 2) + 1] = B_OFF;
    // kernel words
    for (int i = 0; i < NPROG; i++)
        ram[(CODEBUF >> 2) + i] = prog[i];

    // CSR: code base
    d->csr_we = 1; d->csr_addr = 0; d->csr_wdata = CODEBUF; tick();
    d->csr_we = 0;
    // kick
    d->kick = 1; tick(); d->kick = 0;

    auto name = [](int s) -> const char* {
        switch (s) { case 0: return "IDLE"; case 1: return "EXEC";
                     case 2: return "BEND"; default: return "DONE"; }
    };

    for (int cyc = 0; cyc < 3000; cyc++) {
        uint32_t pcv[4], wv[4];
        for (int t = 0; t < 4; t++) {
            pcv[t] = d->rootp->ember_core__DOT__fpc[t];
            wv[t]  = d->rootp->ember_core__DOT__ibuf_w[t];
        }
        if (cyc < 80 || (cyc % 100) == 0)
            printf("c%04d st=%-4s exe=%u%u pick=%u%u ibv=%u "
                   "w=%08x,%08x,%08x,%08x waitv=%u barv=%u ixp=%d cxp=%d "
                   "drv=%d ldp=%d fpc=%u,%u,%u,%u\n",
                   cyc, name((int)I(st)), (unsigned)I(exec_en),
                   (unsigned)I(exec_tid), (unsigned)I(pick_en),
                   (unsigned)I(pick_tid), (unsigned)I(ibuf_v),
                   wv[0], wv[1], wv[2], wv[3],
                   (unsigned)I(waitv), (unsigned)I(barv), (int)I(ix_pend),
                   (int)I(cx_pend), (int)I(dr_valid), (int)I(ld_pend),
                   pcv[0], pcv[1], pcv[2], pcv[3]);

        // ---- bus emulation BEFORE the clock edge ----
        if (I(ixa_req)) {
            uint32_t off = (I(ixa_addr) - VRAM_BASE) >> 2;
            d->ixa_rdata = ram[off & 0x1FFFF];
        }
        if (I(cxa_req)) {
            uint32_t off = (I(cxa_addr) - VRAM_BASE) >> 2;
            d->cxa_rdata = ram[off & 0x1FFFF];
        }
        if (I(cxa_we)) {
            uint32_t off = (I(cxa_addr) - VRAM_BASE) >> 2;
            ram[off & 0x1FFFF] = I(cxa_wdata);
            printf("  W c%04d [%06x] = %08x\n", cyc, off << 2, I(cxa_wdata));
        }

        tick();
        if (I(st) == 2 || I(st) == 3) break;        // BEND/DONE
    }

    printf("\n-- final A[] (want 0,3,6,9,...) --\n");
    for (int i = 0; i < 8; i++)
        printf("  A[%d] = %08x (want %08x)\n", i, ram[(A_OFF >> 2) + i],
               (3 * i) & 0xFFFFFFFFu);
    uint32_t pcv[4];
    for (int t = 0; t < 4; t++) pcv[t] = d->rootp->ember_core__DOT__fpc[t];
    printf("st=%u fpc=%u,%u,%u,%u\n", (unsigned)I(st),
           pcv[0], pcv[1], pcv[2], pcv[3]);

    delete d;
    printf("DONE\n");
    return 0;
}
