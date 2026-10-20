// main.cpp — C++ probe: ember_rtr_top over a C++ RAM model, running the
// dumped temple-scene queue. Watches the S_TRQ->S_TRD handoff on fpa2.
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>
#include "Vember_rtr_top.h"
#include "Vember_rtr_top___024root.h"
#include "verilated.h"

static const uint32_t VB = 0x1000;
static uint32_t ram[128 * 1024];   // 512 KB

static uint64_t ticks = 0;

void half_step(Vember_rtr_top* d) {
    d->clk = 0; d->eval();
    d->clk = 1; d->eval();
    ticks++;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    std::memset(ram, 0, sizeof(ram));
    // ---- texture page from the TB dump (TEX_BASE byte offset) ----
    {
        std::ifstream tf("scene_tex.txt");
        if (!tf) { printf("FAIL: no scene_tex.txt\n"); return 2; }
        uint32_t base_w = 0x04B000u / 4;
        std::string line; int b = 0;
        while (std::getline(tf, line)) {
            uint8_t byte = (uint8_t)std::strtoul(line.c_str(), nullptr, 16);
            uint32_t w = base_w + (b >> 2);
            int sh = (b & 3) * 8;
            ram[w] = (ram[w] & ~(0xFFu << sh)) | (byte << sh);
            b++;
        }
        printf("tex bytes loaded: %d (word[TEX+0]=%08x word[TEX+FFC/4]=%08x)\n",
               b, ram[base_w], ram[base_w + 0x0FFC]);
    }
    // ---- command queue from the TB dump (CMDBUF byte offset) ----
    {
        std::ifstream qf("scene_cmdq.txt");
        if (!qf) { printf("FAIL: no scene_cmdq.txt\n"); return 2; }
        uint32_t base_w = 0x05B000u / 4;
        std::string line; int i = 0;
        while (std::getline(qf, line)) {
            ram[base_w + i] = std::strtoul(line.c_str(), nullptr, 16);
            i++;
        }
        printf("queue words loaded: %d (q[0]=%08x)\n", i, ram[base_w]);
    }
    // ---- Z buffer = FFFF ----
    for (uint32_t w = 0x025800u / 4; w < 0x04B000u / 4; w++) ram[w] = 0xFFFFFFFF;

    Vember_rtr_top* d = new Vember_rtr_top;
    d->rst_n = 0; d->kick = 0;
    for (int i = 0; i < 4; i++) half_step(d);
    d->rst_n = 1;
    for (int i = 0; i < 2; i++) half_step(d);

    d->kick = 1; half_step(d);
    d->kick = 0;

    int tris_done = 0;
    int trq_logged = 0;
    int trq_logged2 = 0;
    int max_trq = 12;
    uint64_t timeout = 20'000'000;
    uint32_t st_count[16] = {0};
    bool traced = false;

    while (ticks < timeout) {
        // observe BEFORE the edge (combinational state of the current cycle)
        auto* r = d->rootp;
        uint8_t st   = r->ember_rtr_top__DOT__u_scan__DOT__st;
        uint8_t fst  = r->ember_rtr_top__DOT__fst;
        st_count[st & 0xF]++;
        if (!traced && ticks > 20 && ticks < 60) {
            printf("[T%04llu] fst=%u st=%2u cmd0=%08x t_tex=%u "
                   "t_ztest=%u fpa2_req=%u\n",
                   (unsigned long long)ticks, fst, st,
                   r->ember_rtr_top__DOT__cmd_q[0],
                   r->ember_rtr_top__DOT__u_scan__DOT__t_tex,
                   r->ember_rtr_top__DOT__u_scan__DOT__t_ztest,
                   d->fpa2_req);
        }
        if (ticks >= 60 && !traced) {
            traced = true;
            printf("[early trace done - check st histogram]\n");
        }
        // top-level OUTPUT ports are live via d->port
        uint8_t trq  = d->fpa2_req;
        uint32_t ta  = d->fpa2_addr;
        uint32_t trd = d->fpa2_rdata;
        if (trq && trq_logged < max_trq) {
            printf("[TRQ] st=%2u texaddr_bus=%08x (off=%05x) rdata=%08x\n",
                   st, ta, ta - VB, trd);
            trq_logged++;
        }
        // S_TRC (texel consume): what byte did the scan latch?
        if (st == 7 && trq_logged2 < 999999) {
            uint8_t tb = r->ember_rtr_top__DOT__u_scan__DOT__texel_byte;
            printf("[TRC] texel_byte=%02x cr=%02x\n", tb,
                   r->ember_rtr_top__DOT__u_scan__DOT__cr);
            trq_logged2++;
        }
        // VRAM model: fpa2 reads (1-cycle latency, capture at posedge).
        // TOP-LEVEL INPUT ports MUST be driven via d->port (rootp copies
        // of inputs are NOT live).
        if (r->ember_rtr_top__DOT__fpa2_req) {
            uint32_t widx = (r->ember_rtr_top__DOT__fpa2_addr - VB) >> 2;
            d->fpa2_rdata = ram[widx & 0x1FFFF];
        }
        // fpa model: reads + writes (capture at posedge below)
        uint8_t fpa_req = r->ember_rtr_top__DOT__fpa_req;
        uint8_t fpa_we  = r->ember_rtr_top__DOT__fpa_we;
        uint32_t fpa_addr = r->ember_rtr_top__DOT__fpa_addr;
        uint32_t fpa_wd = r->ember_rtr_top__DOT__fpa_wdata;
        uint8_t fpa_be  = r->ember_rtr_top__DOT__fpa_be;
        if (fpa_req) {
            uint32_t widx = (fpa_addr - VB) >> 2;
            if (fpa_we) {
                uint32_t cur = ram[widx & 0x1FFFF];
                uint32_t nw = cur;
                if (fpa_be & 1) nw = (nw & 0xFFFFFF00u) | (fpa_wd & 0xFF);
                if (fpa_be & 2) nw = (nw & 0xFFFF00FFu) | (fpa_wd & 0xFF00);
                if (fpa_be & 4) nw = (nw & 0xFF00FFFFu) | (fpa_wd & 0xFF0000u);
                if (fpa_be & 8) nw = (nw & 0x00FFFFFFu) | (fpa_wd & 0xFF000000u);
                ram[widx & 0x1FFFF] = nw;
            } else {
                d->fpa_rdata = ram[widx & 0x1FFFF];
            }
        }

        half_step(d);

        // count finished triangles: F_ADV -> F_FETCH transition without scan
        static uint8_t prev_fst = 99;
        uint8_t now_fst = r->ember_rtr_top__DOT__fst;
        if (prev_fst == 5 && now_fst != 5) tris_done++;
        prev_fst = now_fst;
        if (!d->busy) break;
    }

    printf("cycles=%llu tris_done=%d\n",
           (unsigned long long)ticks, tris_done);
    printf("scan st histogram:");
    for (int i = 0; i < 16; i++) printf(" %d:%u", i, st_count[i]);
    printf("\n");

    // FB stats
    long nz = 0;
    for (uint32_t w = 0; w < (0x025800u / 4); w++) if (ram[w]) nz++;
    printf("fb words nonzero: %ld / %u\n", nz, 0x025800u / 4);
    printf("PROBE DONE\n");
    delete d;
    return 0;
}
