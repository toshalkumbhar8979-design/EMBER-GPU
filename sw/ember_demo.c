/*
 * ember_demo.c — NEORV32 sim-side gate: the 32-frame INPUT-DRIVEN game
 * demo written as bare-metal host software over cp_driver.h (the real
 * CP register contract), with the gamestate kernel on the compute core.
 *
 * This is the EXACT program shape of the future NEORV32 firmware: MMIO
 * + polling, no libc beyond <stdint.h>. The framebuffer, camera state,
 * and HUD live in Ember VRAM; the RISC-V host only:
 *   - uploads code/data once (texture, HUD, kernel, scene vertices),
 *   - per frame: pushes 2 input words, runs the kernel, patches the two
 *     MVP words from the kernel's fp32 outputs, kicks GSX (8 tris),
 *     kicks the RTR, blits the HUD.
 *
 * Sim plumbing: to run this against the RTL without new silicon, the
 * harness (tools/neo_chk) maps this driver's MMIO calls onto the
 * ember_top AXI-Lite port and provides a tiny POSIX-ish shim
 * (EMBER_HALT / EMBER_PUTC / frame counter). On the real board the shim
 * vanishes: main() runs as-is from NEORV32's crt0.
 */
#include <stdint.h>

/* MMIO hooks — provided by the sim harness (tools/neo_chk) or the board
 * support layer. Declared BEFORE cp_driver.h so the driver's weak
 * defaults are never instantiated in this translation unit. */
extern void ember_register_write(uint32_t addr, uint32_t data);
extern uint32_t ember_register_read(uint32_t addr);
#define cp_mmio_write ember_register_write
#define cp_mmio_read  ember_register_read

#include "cp_driver.h"
#include "scene_data.h"
#include "gamestate_words.h"
#include "demo_inputs.h"
#include "mvp_base.h"

/* ---- sim shim hooks (provided by the harness; weak no-ops on HW) ---- */
extern void ember_putc(char c);
extern void ember_halt(int code);
extern uint32_t ember_frame_query(void);

#define HUD_X 128
#define HUD_Y 96
#define HUD_W 32
#define HUD_H 16

/* 32x16 HUD panel: border + 3 pips + key-transparent glass (color 0). */
static uint32_t hud_words[HUD_W * HUD_H / 2];

static void hud_build(void) {
    for (int y = 0; y < HUD_H; y++) {
        for (int x = 0; x < HUD_W; x += 2) {
            int edge = (x == 0) || (x == HUD_W - 2) ||
                       (y == 0) || (y == HUD_H - 1);
            int pip0 = (y >= 6) && (y < 10) && (x >= 3) && (x < 30)
                       && (((x - 3) % 10) < 7);
            int pip1 = (y >= 6) && (y < 10) && (x + 1 >= 3) && (x + 1 < 30)
                       && ((((x + 1) - 3) % 10) < 7);
            uint32_t c0 = edge ? 0xFFFFu : (pip0 ? 0x07E0u : 0x0000u);
            uint32_t c1 = edge ? 0xFFFFu : (pip1 ? 0x07E0u : 0x0000u);
            hud_words[y * (HUD_W / 2) + x / 2] = c0 | (c1 << 16);
        }
    }
}

static void put_pixel16_pair(uint32_t fb_off, uint32_t a, uint32_t b) {
    (void)fb_off; (void)a; (void)b;
    /* unused: the demo never CPU-writes the framebuffer */
}

/* 256x256 CLUT page texture (brick pattern), packed 4 texels/word. */
static uint32_t tex_words[65536 / 4];

static void tex_build(void) {
    for (int v = 0; v < 256; v++) {
        for (int u = 0; u < 256; u += 4) {
            uint32_t word = 0;
            for (int k = 0; k < 4; k++) {
                int course = v >> 5;
                int off = (course & 1) << 4;
                int bu = (u + k + off) >> 6;
                int mortar = ((v & 31) == 31)
                             || (((u + k + off) & 63) == 63);
                uint32_t c = mortar ? 70u
                    : (150u + (uint32_t)((bu * 37 + course * 17) % 60));
                word |= (c & 0xFFu) << (8 * k);
            }
            tex_words[(v << 6) + (u >> 2)] = word;
        }
    }
}

/* fp32 bits of a float64 value (host side; the KERNEL does the camera).
 * MUST round through `float` first: the high word of the DOUBLE is NOT
 * the f32 encoding (f2b(532.27) once returned the double's hi word
 * 0x4080BE04 instead of 0x44051152 — the whole scene collapsed left). */
static uint32_t f2b(double d) {
    float f = (float)d;
    union { float f; uint32_t b; } u;
    u.f = f;
    return u.b;
}

/* SX as an exact IEEE double (generated): bit-identical row0 folding to
 * the Python golden — no printf/strtod rounding drift. */
static double sx_exact(void) {
    union { uint64_t b; double d; } u;
    u.b = SX_DOUBLE_BITS;
    return u.d;
}

/* MVP base + per-frame patch: row0[3] host-folded, row3[3] kernel's f2q
 * word (f32m(mvp_fly_words(0,0)) comes from mvp_base.h, generated). */
static uint32_t mvp_patch[16];

static void mvp_build(uint32_t row0_word, uint32_t row3_word) {
    for (int i = 0; i < 16; i++)
        mvp_patch[i] = mvp_base[i];
    mvp_patch[3] = row0_word;
    mvp_patch[15] = row3_word;
}

/* Demo input script: demo_inputs.h is GENERATED from
 * tools/golden/gamestate.py demo_script() — identical bytes to the RTL
 * testbench run, so a host-vs-TB compare is meaningful. */

/* Clear the whole FB (0 = black) via DMA from the FIFO: push the same
 * word repeatedly through 60-word chunks. NOTE: cp_upload takes a VRAM
 * offset — the region BASE must be added (the missing VRAM_ZBUF here once
 * whitewashed the FB while the real Z-buffer stayed 0 -> every fragment
 * failed z-test -> the scene never rendered).
 *
 * KERNEL-PARAM STAGING GOTCHA: cp_core_run DMA's its params to VRAM_CMDBUF
 * = 0x5B000 = RTR cmdq SLOT 0, words 0-2. That's benign BETWEEN frames
 * (GSX re-emits the whole cmdq before the next sweep) but it means the
 * cmdq's first 3 words are ALWAYS kernel params whenever the core ran
 * more recently than GSX — never diagnose a "corrupted cmdq" without
 * checking what staged there last. */
static void fb_clear(void) {
    static uint32_t zeros[60];
    for (int i = 0; i < 60; i++) zeros[i] = 0u;
    for (uint32_t off = 0; off < 320u * 240u * 2u; off += 240u)
        cp_upload(VRAM_FB0 + off, zeros, 60, 4);
}

static void zbuf_clear(void) {
    static uint32_t ff[60];
    for (int i = 0; i < 60; i++) ff[i] = 0xFFFFFFFFu;
    for (uint32_t off = 0; off < 320u * 240u * 2u; off += 240u)
        cp_upload(VRAM_ZBUF + off, ff, 60, 4);
}

int main(void) {
    /* ---- bring-up: CP alive? ------------------------------------- */
    if (!cp_id_ok()) {
        ember_putc('I'); ember_putc('D'); ember_putc('?');
        ember_halt(2);
    }

    /* ---- one-time uploads ---------------------------------------- */
    tex_build();
    cp_upload(VRAM_TEX, tex_words, 65536 / 4, 4);
    hud_build();
    cp_upload(VRAM_SPRITE, hud_words, HUD_W * HUD_H / 2, 4);
    cp_upload(VRAM_CODEBUF, gamestate_words, GAMESTATE_NWORDS, 4);

    static const uint32_t zero8[8] = {0};
    cp_upload(VRAM_GS, zero8, 8, 4);                 /* zero state */

    /* MVP base is the GENERATED f32m(mvp_fly_words(0,0)) — no hand math */
    (void)put_pixel16_pair;

    /* ---- 32-frame game loop --------------------------------------- */
    for (int frame = 0; frame < 32; frame++) {
        uint8_t cookie = (uint8_t)(0x40 + frame);
        int render = (frame % 2) == 0;

        if (render) {
            zbuf_clear();
            fb_clear();
        }

        { extern void ember_frame_marker(int); ember_frame_marker(frame); }
        /* per-frame INPUTS -> kernel integrates on-core */
        uint32_t in_words[2] = {
            (uint32_t)(int32_t)demo_ax[frame],
            (uint32_t)(int32_t)demo_az[frame],
        };
        cp_upload(VRAM_GI, in_words, 2, 5);
        uint32_t params[3] = {VRAM_GS >> 2, VRAM_GI >> 2, cookie};
        cp_core_run(VRAM_CODEBUF, 1, params, 3, 6);

        /* read back the 8-word state (pos, vel, f32 words, echo) */
        uint32_t st[8];
        cp_download(VRAM_GS, st, 8, 6);
        if ((st[6] >> 8) != cookie) {
            ember_putc('E'); ember_putc('C'); ember_putc('H');
            ember_halt(3);
        }
        int32_t pos_x = (int32_t)st[0];
        int32_t pos_z = (int32_t)st[1];

        if (!render) {
            continue;
        }

        /* patch the MVP: row0[3] host-folded (exact SX double),
         * row3[3] = the KERNEL's own f2q word */
        uint32_t row0 = f2b(480.0 - sx_exact()
                            * ((double)pos_x / 65536.0));
        mvp_build(row0, st[7]);

        /* GSX: 8 textured tris */
        cp_gsx_setup((1u << 27) | (1u << 24));   /* tex + ztest */
        cp_gsx_matrix(mvp_patch);
        for (int t = 0; t < SCENE_TRIS; t++)
            cp_gsx_tri(&scene_v15[15 * t], 0u);

        cp_rtr_sweep();
        cp_blit(2u * (HUD_Y * 320u + HUD_X), VRAM_SPRITE, HUD_W, HUD_H,
                1u, 0u, 0u);

        /* TU exercised in the loop too (C = 1x1 requant matmul over the
         * state block) — the AI-demo path runs from the same host loop: */
        cp_upload(VRAM_A, st, 8, 7);
        cp_upload(VRAM_W, gamestate_words, 16, 7);
        cp_tu_matmul(VRAM_A, VRAM_W, VRAM_C, 8, 16, 16, 1, 0);
        {
            uint32_t cwords[4];
            cp_download(VRAM_C, cwords, 4, 7);
        }

        ember_putc('.');                          /* frame tick */
    }

    ember_putc('\n');
    ember_putc('O'); ember_putc('K');
    ember_halt(0);
    return 0;
}
