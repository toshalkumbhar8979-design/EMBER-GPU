// tools/tu_chk/main.cpp — minimal Verilator probe for ember_tu (Phase 6).
// 256x256x256 identity-matrix timing case: C == A exactly; measures the
// wall-clock cycle count so the cocotb GOPS gate has ground truth.
#include <cstdio>
#include <cstring>
#include "Vember_tu.h"
#include "Vember_tu___024root.h"

#define I(name) (d->rootp->ember_tu__DOT__##name)

static uint32_t ram[131072];

static const uint32_t VRAM_BASE = 0x1000;
static const uint32_t A_OFF = 0x20000, W_OFF = 0x45000, C_OFF = 0x6A000;

static uint32_t nwr = 0, nrd = 0;

static void run_case(int M, int K, int N, long long& cyc_out);
static int g_bad;

static int8_t A5[5][32], W5[32][16];   // tu_small replicas (padded)
static int8_t G5[5][16];               // golden C for tu_small

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vember_tu* d = new Vember_tu;

    auto tick = [&]() { d->clk = 0; d->eval(); d->clk = 1; d->eval(); };

    d->clk = 0; d->rst_n = 0;
    d->csr_we = 0; d->csr_addr = 0; d->csr_wdata = 0; d->kick = 0;
    d->tua_we = 0; d->tua_addr = 0; d->tua_wdata = 0; d->tua_be = 0;
    d->tua_req = 0;
    for (int i = 0; i < 5; i++) tick();
    d->rst_n = 1; tick();

    // A = 256x256 arbitrary bytes; W = identity 256x256 (so C == A)
    for (int i = 0; i < 256 * 256; i++) {
        ((uint8_t*)ram)[A_OFF + i] = (uint8_t)((i * 7 + 3) & 0xFF);
        ((uint8_t*)ram)[W_OFF + i] = ((i / 256) == (i % 256)) ? 1 : 0;
    }

    // CSR: bases
    d->csr_we = 1; d->csr_addr = 0; d->csr_wdata = A_OFF; tick();
    d->csr_we = 1; d->csr_addr = 1; d->csr_wdata = W_OFF; tick();
    d->csr_we = 1; d->csr_addr = 2; d->csr_wdata = C_OFF; tick();
    // CFG2 form 00: N=256, K=256; form 01: M=256; form 10: mult=1 shift=0
    d->csr_we = 1; d->csr_addr = 3; d->csr_wdata = (256 << 16) | 256; tick();
    d->csr_we = 1; d->csr_addr = 3; d->csr_wdata = (1u << 30) | 256; tick();
    d->csr_we = 1; d->csr_addr = 3; d->csr_wdata = (2u << 30) | 1; tick();
    d->csr_we = 0;

    long long cyc = 0;
    int first_mac = -1;
    d->kick = 1; tick(); d->kick = 0;

    while (I(st) != 0 && cyc < 20'000'000) {   // T_IDLE = done
        if (first_mac < 0 && I(st) == 6 && I(mac_pend)) {   // NEXT + mac_pend
            first_mac = (int)cyc;
            printf("first MAC @ c%d: w_regs[7][7]=%d a_row[7]=%d "
                   "abuf1=%08x wrowbuf1=%08x tree7=%d acc7=%d\n",
                   (int)cyc,
                   (int)d->rootp->ember_tu__DOT__w_regs[7][7],
                   (int)d->rootp->ember_tu__DOT__a_row_byte[7],
                   d->rootp->ember_tu__DOT__abuf_q[1],
                   d->rootp->ember_tu__DOT__wrowbuf[1],
                   (int)d->rootp->ember_tu__DOT__tree[7],
                   (int)d->rootp->ember_tu__DOT__acc[7][7]);
        }
        if (I(tua_req)) {
            uint32_t off = (I(tua_addr) - VRAM_BASE) >> 2;
            d->tua_rdata = ram[off & 0x1FFFF];
            nrd++;
        }
        if (I(tua_we)) {
            uint32_t off = (I(tua_addr) - VRAM_BASE) >> 2;
            ram[off & 0x1FFFF] = I(tua_wdata);
            nwr++;
        }
        tick();
        cyc++;
    }

    // verify C == A
    int bad = 0;
    for (int i = 0; i < 256 * 256; i++) {
        uint8_t got = ((uint8_t*)ram)[C_OFF + i];
        uint8_t want = ((uint8_t*)ram)[A_OFF + i];
        if (got != want) {
            if (bad < 8)
                printf("  MISMATCH at %d: got %d want %d\n", i, got, want);
            bad++;
        }
    }
    printf("256-cube identity: %d mismatches\n", bad);
    printf("cycles=%lld rd=%u wr=%u -> %.2f GOPS @100MHz "
           "(array peak 25.6)\n", cyc, nrd, nwr,
           (256.0 * 256 * 256 * 2) / (cyc * 10.0));
    printf("%s\n", bad == 0 ? "TU_PROBE PASS" : "TU_PROBE FAIL");

    delete d;
    return bad == 0 ? 0 : 1;
}

// (run_case reserved for scenario 2; identity case is inline above)
