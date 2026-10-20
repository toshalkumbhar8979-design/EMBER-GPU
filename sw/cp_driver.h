/**
 * cp_driver.h — Ember GPU bare-metal host driver (CP register window).
 *
 * THE host-interface contract of the Ember GPU, usable from any 32-bit
 * bare-metal RISC-V target (NEORV32 on the FPGA board) with the CP window
 * at 0x0000_0000 and VRAM flat at 0x0000_1000 (see ember_top.sv host map).
 * Only <stdint.h> — no libc, no RTOS, no simulator hooks. Polling only.
 *
 * Register map (rtl/ember_pkg.sv, 12-bit offsets from CP_BASE):
 *   0x000 ID (RO 0xEB22)   0x004 STATUS (RO)     0x008 CTRL(W1P sw_reset)
 *   0x00C FENCE (RO)       0x010 FIFOD (push up / pop readback)
 *   0x014 DMA_DST          0x018 DMA_LEN         0x01C CMDX (W1P)
 *   0x020 RTR_KICK (W1P)   0x024..0x034 BLIT_*   0x038..0x048 GSX_*
 *   0x04C CORE_CODE        0x050 CORE_NBLK       0x054 CORE_KICK (W1P)
 *   0x058 TU_A  0x05C TU_W  0x060 TU_C  0x064 TU_CFG2 (form-tagged)
 *   0x068 TU_KICK (W1P)
 * STATUS bits: [0] dma_busy [1] rtr_busy [2] rb_empty [7] blit_busy
 *              [8] gsx_busy [9] core_busy [10] tu_busy
 *
 * Conventions that bit the unwary (all verified in sim):
 *   - DMA_DST/DMA_LEN take VRAM BYTE offsets (CP adds VRAM_BASE itself);
 *     bus masters use full bus addresses (VRAM_BASE + offset).
 *   - Upload FIFO is 64 deep: chunk <= 60 words and wait !dma_busy.
 *   - CMDX is write-1-to-post: dir bit0 (0 = FIFO->VRAM, 1 = VRAM->FIFO),
 *     fence id in [15:8].
 *   - GSX: CFG write with bit31=0 sets mode flags AND resets the emit
 *     slot; call it EVERY frame (Phase-7e lesson). CFG bit31=1 is the
 *     tri_count form. VTX window is 15 words (x,y,z,u,v per vertex).
 *   - BLIT_SIZE packs [23:16]=h [7:0]=w. BLIT_CFG [30]=scale2 [29]=key_en.
 *   - TU_CFG2 is form-tagged [31:30]: 00 = {N,K}, 01 = M, 10 = {mult,shift}.
 *   - CORE params are pushed through the SAME upload FIFO (FIFOD) and
 *     DMA'd to CMDBUF before KICK; the kernel reads them at [%r12+k].
 */
#ifndef CP_DRIVER_H
#define CP_DRIVER_H

#include <stdint.h>

#define CP_BASE        0x00000000u   /* CP register window           */
#define VRAM_BASE      0x00001000u   /* VRAM flat behind the CP regs */
#define VRAM_BYTES     (512u * 1024u)

/* ---- CP register offsets -------------------------------------------- */
#define CP_ID          0x000u
#define CP_STATUS      0x004u
#define CP_CTRL        0x008u
#define CP_FENCE       0x00Cu
#define CP_FIFOD       0x010u
#define CP_DMA_DST     0x014u
#define CP_DMA_LEN     0x018u
#define CP_CMDX        0x01Cu
#define CP_RTR_KICK    0x020u
#define CP_BLIT_CFG    0x024u
#define CP_BLIT_DST    0x028u
#define CP_BLIT_SRC    0x02Cu
#define CP_BLIT_SIZE   0x030u
#define CP_BLIT_KICK   0x034u
#define CP_GSX_MATA    0x038u
#define CP_GSX_VTX     0x03Cu
#define CP_GSX_COL     0x040u
#define CP_GSX_GO      0x044u
#define CP_GSX_CFG     0x048u
#define CP_CORE_CODE   0x04Cu
#define CP_CORE_NBLK   0x050u
#define CP_CORE_KICK   0x054u
#define CP_TU_A        0x058u
#define CP_TU_W        0x05Cu
#define CP_TU_C        0x060u
#define CP_TU_CFG2     0x064u
#define CP_TU_KICK     0x068u

/* ---- STATUS bits ------------------------------------------------------ */
#define ST_DMA_BUSY    (1u << 0)
#define ST_RTR_BUSY    (1u << 1)
#define ST_RB_EMPTY    (1u << 2)
#define ST_BLIT_BUSY   (1u << 7)
#define ST_GSX_BUSY    (1u << 8)
#define ST_CORE_BUSY   (1u << 9)
#define ST_TU_BUSY     (1u << 10)

/* ---- common VRAM layout (v1.1 map + demo slots) ----------------------- */
#define VRAM_FB0       0x000000u
#define VRAM_ZBUF      0x025800u
#define VRAM_TEX       0x04B000u
#define VRAM_CMDBUF    0x05B000u
#define VRAM_CODEBUF   (VRAM_CMDBUF + 0x400u)
#define VRAM_GS        0x071000u   /* gamestate kernel state (8 words)   */
#define VRAM_GI        0x072000u   /* gamestate kernel inputs (2 words)  */
#define VRAM_SPRITE    0x070000u   /* HUD sprite scratch                 */
#define VRAM_A         0x20000u    /* TU A / core scratch                */
#define VRAM_W         0x45000u    /* TU W                               */
#define VRAM_C         0x6A000u    /* TU C (int8 out)                    */

#define CP_ID_CODE     0xEB22u   /* HIGH halfword: the RTL register
                                    * reads 0xEB22_0002 (low half = gen 2) */

/* ------------------------------------------------------------------ */
/* MMIO primitives — port target. For NEORV32 this is the standard     */
/* peripheral bus window; the generic default below works for any      */
/* memory-mapped target. Override by defining cp_mmio_write/Read       */
/* before including this header.                                       */
/* ------------------------------------------------------------------ */
#ifndef cp_mmio_write
static inline void cp_mmio_write(uint32_t addr, uint32_t data) {
    *(volatile uint32_t *)(uintptr_t)addr = data;
}
#endif
#ifndef cp_mmio_read
static inline uint32_t cp_mmio_read(uint32_t addr) {
    return *(volatile uint32_t *)(uintptr_t)addr;
}
#endif

static inline void cp_write(uint32_t off, uint32_t data) {
    cp_mmio_write(CP_BASE + off, data);
}
static inline uint32_t cp_read(uint32_t off) {
    return cp_mmio_read(CP_BASE + off);
}
static inline uint32_t cp_status(void)      { return cp_read(CP_STATUS); }
static inline uint32_t cp_id(void)          { return cp_read(CP_ID); }
static inline uint32_t cp_fence_last(void)  { return cp_read(CP_FENCE); }
static inline int      cp_id_ok(void) {
    return (cp_id() >> 16) == CP_ID_CODE;
}

/* ------------------------------------------------------------------ */
/* DMA upload / download (FIFO <-> VRAM)                               */
/* ------------------------------------------------------------------ */
static inline void cp_upload(uint32_t vram_off, const uint32_t *words,
                             uint32_t nwords, uint8_t fence) {
    uint32_t i = 0;
    while (i < nwords) {
        uint32_t chunk = nwords - i;
        if (chunk > 60u) chunk = 60u;              /* FIFO is 64 deep */
        for (uint32_t k = 0; k < chunk; k++)
            cp_write(CP_FIFOD, words[i + k]);
        cp_write(CP_DMA_DST, vram_off + 4u * i);
        cp_write(CP_DMA_LEN, 4u * chunk);
        cp_write(CP_CMDX, ((uint32_t)fence << 8) | 0u);
        while (cp_status() & ST_DMA_BUSY) { }
        i += chunk;
    }
}

/* Download nwords from VRAM into words[] via the readback FIFO.
 * The readback FIFO is 8 deep with no documented full stall, so chunk
 * to 4 words and wait !dma_busy between chunks (same conservatism as
 * the upload path). */
static inline void cp_download(uint32_t vram_off, uint32_t *words,
                               uint32_t nwords, uint8_t fence) {
    uint32_t i = 0;
    while (i < nwords) {
        uint32_t chunk = nwords - i;
        if (chunk > 4u) chunk = 4u;
        cp_write(CP_DMA_DST, vram_off + 4u * i);
        cp_write(CP_DMA_LEN, 4u * chunk);
        cp_write(CP_CMDX, ((uint32_t)fence << 8) | 1u);
        for (uint32_t k = 0; k < chunk; k++) {
            while (cp_status() & ST_RB_EMPTY) { }
            words[i + k] = cp_read(CP_FIFOD);
        }
        while (cp_status() & ST_DMA_BUSY) { }
        i += chunk;
    }
}

/* ------------------------------------------------------------------ */
/* GSX (geometry)                                                      */
/* ------------------------------------------------------------------ */
/* mode_flags: bit24 ztest, bit26 blend, bit27 tex. Resets the emit slot */
static inline void cp_gsx_setup(uint32_t mode_flags) {
    cp_write(CP_GSX_CFG, mode_flags & 0x7FFFFFFFu);
    cp_write(CP_GSX_CFG, 0x80000000u);           /* append mode */
}

static inline void cp_gsx_matrix(const uint32_t *mata16) {
    for (int i = 0; i < 16; i++)
        cp_write(CP_GSX_MATA, mata16[i]);
}

/* Emit one triangle: v15 = 15 words (x,y,z,u,v x3), col3 = {b,g,r,x}. */
static inline void cp_gsx_tri(const uint32_t *v15, uint32_t col) {
    for (int i = 0; i < 15; i++)
        cp_write(CP_GSX_VTX, v15[i]);
    for (int i = 0; i < 3; i++)
        cp_write(CP_GSX_COL, col & 0x00FFFFFFu);
    cp_write(CP_GSX_GO, 1u);
    while (cp_status() & ST_GSX_BUSY) { }
}

/* ------------------------------------------------------------------ */
/* RTR / blitter                                                       */
/* ------------------------------------------------------------------ */
static inline void cp_rtr_sweep(void) {
    cp_write(CP_RTR_KICK, 1u);
    while (cp_status() & ST_RTR_BUSY) { }
}

static inline void cp_blit(uint32_t dst_off, uint32_t src_off,
                           uint32_t w, uint32_t h,
                           uint32_t key_en, uint32_t key_color,
                           uint32_t scale2) {
    cp_write(CP_BLIT_CFG, ((scale2 & 1u) << 30) | ((key_en & 1u) << 29)
                          | (key_color & 0xFFFFu));
    cp_write(CP_BLIT_DST, dst_off);
    cp_write(CP_BLIT_SRC, src_off);
    cp_write(CP_BLIT_SIZE, ((h & 0xFFu) << 16) | (w & 0xFFu));
    cp_write(CP_BLIT_KICK, 1u);
    while (cp_status() & ST_BLIT_BUSY) { }
}

/* ------------------------------------------------------------------ */
/* Compute cluster                                                     */
/* ------------------------------------------------------------------ */
/* params[] are pushed through the upload FIFO to CMDBUF, then the      */
/* kernel at code_off runs with 1 block; kernel reads [%r12 + 4k].      */
static inline void cp_core_run(uint32_t code_off, uint32_t nblk,
                               const uint32_t *params, uint32_t nparams,
                               uint8_t fence) {
    cp_upload(VRAM_CMDBUF, params, nparams, fence);
    cp_write(CP_CORE_CODE, code_off);
    cp_write(CP_CORE_NBLK, nblk);
    cp_write(CP_CORE_KICK, 1u);
    while (cp_status() & ST_CORE_BUSY) { }
}

/* ------------------------------------------------------------------ */
/* Tensor unit: C[m,n] (int8) = requant(A[m,k] x W[k,n])                */
/* A row-major (stride K), W row-major (stride N).                      */
/* ------------------------------------------------------------------ */
static inline void cp_tu_matmul(uint32_t a_off, uint32_t w_off,
                                uint32_t c_off, uint32_t m, uint32_t k,
                                uint32_t n, uint16_t mult, uint8_t shift) {
    cp_write(CP_TU_A, a_off);
    cp_write(CP_TU_W, w_off);
    cp_write(CP_TU_C, c_off);
    cp_write(CP_TU_CFG2, (0u << 30) | ((k & 0xFFFu) << 16) | (n & 0xFFFu));
    cp_write(CP_TU_CFG2, (1u << 30) | (m & 0xFFFu));
    cp_write(CP_TU_CFG2, (2u << 30) | (((uint32_t)shift & 0xFu) << 20)
                         | (mult & 0xFFFFu));
    cp_write(CP_TU_KICK, 1u);
    while (cp_status() & ST_TU_BUSY) { }
}

#endif /* CP_DRIVER_H */
