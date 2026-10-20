// ember_pkg.sv — Ember GPU global parameters, AXI-Lite struct types, register map, opcodes.
// One source of truth; modules must not declare their own magic constants.
//
// Contract: parameters and types only. `import ember_pkg::*;` everywhere.

`ifndef EMBER_PKG_SV
`define EMBER_PKG_SV

package ember_pkg;

  // ------------------------------------------------------------------ //
  // Geometry of the machine (v1)                                       //
  // ------------------------------------------------------------------ //
  localparam int unsigned NUM_CORES        = 2;    // SIMT cores (Phase 5)
  localparam int unsigned THREADS_PER_CORE = 4;    // SIMT lanes per core
  localparam int unsigned GPRS_PER_THREAD  = 16;   // regs per thread

  localparam int unsigned AXI_ADDR_W = 32;
  localparam int unsigned AXI_DATA_W = 32;
  localparam int unsigned AXI_STRB_W = AXI_DATA_W / 8;

  // ------------------------------------------------------------------ //
  // VRAM map (512 KiB on-chip)                                         //
  // ------------------------------------------------------------------ //
  localparam int unsigned VRAM_BYTES  = 512 * 1024;
  localparam int unsigned VRAM_AW     = $clog2(VRAM_BYTES);            // 19
  localparam int unsigned FRAME_W_PX  = 320;
  localparam int unsigned FRAME_H_PX  = 240;
  localparam int unsigned FB_STRIDE   = FRAME_W_PX * 2;                // RGB565: 640 B/row
  // v1 = single framebuffer (v2 adds FB1 for double buffering once VRAM grows)
  localparam int unsigned FB0_BASE    = 32'h0000_0000;                 // VRAM offsets
  localparam int unsigned ZBUF_BASE   = FB0_BASE + FB_STRIDE * FRAME_H_PX;          // 0x025800
  localparam int unsigned TEX_BASE    = ZBUF_BASE + FRAME_W_PX * FRAME_H_PX * 2;    // 0x04B000
  localparam int unsigned TEX_BYTES   = 64 * 1024;
  localparam int unsigned CMDBUF_BASE = TEX_BASE + TEX_BYTES;          // 0x05B000
  localparam int unsigned CMDBUF_BYTES= 32 * 1024;
  // tail of VRAM above CMDBUF_BASE+CMDBUF_BYTES: scratch

  // ------------------------------------------------------------------ //
  // Bus register map (module windows)                                  //
  // ------------------------------------------------------------------ //
  localparam int unsigned CP_WINDOW_BYTES = 4096;
  localparam int unsigned CP_BASE   = 32'h0000_0000;                   // CP control regs
  localparam int unsigned VRAM_BASE = CP_BASE + CP_WINDOW_BYTES;       // 0x0000_1000

  // ------------------------------------------------------------------ //
  // CP control / status register offsets (byte offsets in CP window)   //
  // ------------------------------------------------------------------ //
  localparam logic [11:0] CP_ID      = 12'h000;  // RO:  0xEB22 ("EB"=Ember, 2=gen)
  localparam logic [11:0] CP_STATUS  = 12'h004;  // RO:  [0]=dma_busy [1]=up_fifo_full [12:8]=up_fifo_count
  localparam logic [11:0] CP_CTRL    = 12'h008;  // W1P: [0]=sw_reset
  localparam logic [11:0] CP_FENCE   = 12'h00C;  // RO:  fence id of last completed DMA
  localparam logic [11:0] CP_FIFOD   = 12'h010;  // W: push upload FIFO / R: pop readback FIFO
  localparam logic [11:0] CP_DMA_DST = 12'h014;  // RW: VRAM byte offset (word aligned)
  localparam logic [11:0] CP_DMA_LEN = 12'h018;  // RW: length in bytes (word multiple)
  localparam logic [11:0] CP_CMDX    = 12'h01C;  // W1P start: [0]=dir (0=FIFO->VRAM, 1=VRAM->FIFO), [15:8]=fence id
  localparam logic [11:0] CP_RTR_KICK= 12'h020;  // W1P: [0]=1 restart RTR command queue from RTR_CMDQ_BASE
  localparam logic [11:0] CP_BLIT_CFG = 12'h024; // RW: [30]=scale2 [29]=key_en [15:0]=key_color
  localparam logic [11:0] CP_BLIT_DST = 12'h028; // RW: FB0 byte offset of dest corner
  localparam logic [11:0] CP_BLIT_SRC = 12'h02C; // RW: src bitmap byte offset
  localparam logic [11:0] CP_BLIT_SIZE= 12'h030; // RW: [23:16]=h [7:0]=w (1..255)
  localparam logic [11:0] CP_BLIT_KICK= 12'h034; // W1P: [0]=1 start blit

  // GSX (geometry) CSR window — decode mirrors the blit CSR passthrough
  localparam logic [11:0] CP_GSX_MATA = 12'h038; // W: 4x4 matrix word, auto-inc write ptr (16 words)
  localparam logic [11:0] CP_GSX_VTX  = 12'h03C; // W: vertex coord word, auto-inc ptr (9 words = 3 verts x xyz, f32)
  localparam logic [11:0] CP_GSX_COL  = 12'h040; // W: vertex color word, auto-inc ptr (3 words, {b,g,r,x})
  localparam logic [11:0] CP_GSX_GO   = 12'h044; // W1P: [0]=1 transform+emit one triangle
  localparam logic [11:0] CP_GSX_CFG  = 12'h048; // W: bit31=1 -> [7:0] tri_count write
                                                 //     bit31=0 -> [24] ztest [26] blend
                                                 //               [27] tex  [29] overw

  // Compute cluster (Phase 5) — dispatcher regs (block scheduling inside
  // ember_core v1: it loops blocks internally)
  localparam logic [11:0] CP_CORE_CODE = 12'h04C; // RW: kernel entry, VRAM byte offset (word aligned)
  localparam logic [11:0] CP_CORE_NBLK = 12'h050; // RW: block count (1..255)
  localparam logic [11:0] CP_CORE_KICK = 12'h054; // W1P: [0]=1 launch

  // STATUS bit 9 = core_busy (compute cluster in flight)

  // Tensor unit (Phase 6) CSR regs
  localparam logic [11:0] CP_TU_A    = 12'h058; // RW: A base, VRAM byte offset
  localparam logic [11:0] CP_TU_W    = 12'h05C; // RW: W base
  localparam logic [11:0] CP_TU_C    = 12'h060; // RW: C base (int8 out)
  localparam logic [11:0] CP_TU_CFG2 = 12'h064; // W: form-tagged ([31:30]):
                                                //   00 dims [11:0]=N [27:16]=K
                                                //   01 M [7:0]
                                                //   10 quant [15:0]mult [23:20]shift
  localparam logic [11:0] CP_TU_KICK = 12'h068; // W1P: [0]=1 run the matmul

  // STATUS bit 10 = tu_busy (tensor unit in flight)

  // STATUS bit 8 = gsx_busy (geometry engine in flight)
  localparam logic [7:0] FENCE_CMD = 8'd1;
  localparam logic [7:0] FENCE_FB  = 8'd2;
  localparam logic [7:0] FENCE_TEX = 8'd3;

  // ------------------------------------------------------------------ //
  // AXI4-Lite channel structs                                          //
  // ------------------------------------------------------------------ //
  typedef struct packed {
    logic [AXI_ADDR_W-1:0] addr;
    logic [2:0]            prot;
  } axil_ar_t;

  typedef struct packed {
    logic [AXI_DATA_W-1:0] data;
    logic [1:0]            resp;
  } axil_r_t;

  typedef struct packed {
    logic [AXI_ADDR_W-1:0] addr;
    logic [2:0]            prot;
  } axil_aw_t;

  typedef struct packed {
    logic [AXI_DATA_W-1:0] data;
    logic [AXI_STRB_W-1:0] strb;
  } axil_w_t;

  typedef struct packed {
    logic [1:0] resp;
  } axil_b_t;

  // AXI responses (OKAY=00, EXOKAY=01, SLVERR=10, DECERR=11)
  localparam logic [1:0] RESP_OKAY   = 2'b00;
  localparam logic [1:0] RESP_EXOKAY = 2'b01;
  localparam logic [1:0] RESP_SLVERR = 2'b10;
  localparam logic [1:0] RESP_DECERR = 2'b11;

  // Number of masters / slaves in the Phase-1 fabric
  localparam int unsigned NUM_MASTERS = 2;   // [0]=CP DMA, [1]=host/debug
  localparam int unsigned NUM_SLAVES  = 2;   // [0]=CP regs, [1]=VRAM
  localparam logic [1:0] TGT_NONE = 2'd3;    // decode miss -> fabric-local error response

  // ---------------- RTR (raster) command FIFO (inside VRAM) ----------------
  localparam int unsigned RTR_CMDQ_BASE = CMDBUF_BASE;  // 0x05B000
  localparam int unsigned RTR_CMDQ_WORDS = 1024;        // 4 KB command queue

  // CMD word 0: [0] tri_valid [1] blend [2] ztest [3] tex_en
  //             [4] dbg_dither [5] dbg_rgbmap [15:8] texture page
  // CMD 1..6:   vx0,vy0,vx1,vy1,vx2,vy2   (s32 Q10.22)
  // CMD 7..9:   z0,z1,z2                  (u16, raw depth)
  // CMD 10..12: {b,g,r,x} per vertex      (u8 x3, byte-packed)
  // CMD 13..18: u0,v0,u1,v1,u2,v2         (s32 Q10.22)
  localparam int unsigned RTR_CMD_WORDS = 19;

  // ------------------------------------------------------------------ //
  // Ember-ISA v2 opcodes (compute cores, Phase 5)                      //
  // ------------------------------------------------------------------ //
  typedef enum logic [7:0] {
    OP_ADD    = 8'h01,
    OP_SUB    = 8'h02,
    OP_MUL    = 8'h03,
    OP_DIV    = 8'h04,
    OP_AND    = 8'h05,
    OP_OR     = 8'h06,
    OP_XOR    = 8'h07,
    OP_SHL    = 8'h08,
    OP_SHR    = 8'h09,
    OP_CMP    = 8'h0A,
    OP_MIN    = 8'h0B,
    OP_MAX    = 8'h0C,
    OP_LDR    = 8'h10,
    OP_STR    = 8'h11,
    OP_LDS    = 8'h12,
    OP_STS    = 8'h13,
    OP_BRNZP  = 8'h20,
    OP_JAL    = 8'h21,
    OP_JR     = 8'h22,
    OP_RET    = 8'h23,
    OP_CALL   = 8'h24,
    OP_BAR    = 8'h25,
    OP_TLD    = 8'h30,
    OP_TST    = 8'h31,
    OP_TEXEC  = 8'h32,
    OP_TWAIT  = 8'h33
  } opcode_e;

endpackage : ember_pkg

`endif // EMBER_PKG_SV
