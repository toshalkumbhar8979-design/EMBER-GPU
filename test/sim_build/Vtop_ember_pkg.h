// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_EMBER_PKG_H_
#define VERILATED_VTOP_EMBER_PKG_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_ember_pkg final {
  public:

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr CData/*7:0*/ FENCE_CMD = 1U;
    static constexpr CData/*7:0*/ FENCE_FB = 2U;
    static constexpr CData/*7:0*/ FENCE_TEX = 3U;
    static constexpr CData/*1:0*/ RESP_OKAY = 0U;
    static constexpr CData/*1:0*/ RESP_EXOKAY = 1U;
    static constexpr CData/*1:0*/ RESP_SLVERR = 2U;
    static constexpr CData/*1:0*/ RESP_DECERR = 3U;
    static constexpr CData/*1:0*/ TGT_NONE = 3U;
    static constexpr SData/*11:0*/ CP_ID = 0U;
    static constexpr SData/*11:0*/ CP_STATUS = 4U;
    static constexpr SData/*11:0*/ CP_CTRL = 8U;
    static constexpr SData/*11:0*/ CP_FENCE = 0x000cU;
    static constexpr SData/*11:0*/ CP_FIFOD = 0x0010U;
    static constexpr SData/*11:0*/ CP_DMA_DST = 0x0014U;
    static constexpr SData/*11:0*/ CP_DMA_LEN = 0x0018U;
    static constexpr SData/*11:0*/ CP_CMDX = 0x001cU;
    static constexpr SData/*11:0*/ CP_RTR_KICK = 0x0020U;
    static constexpr SData/*11:0*/ CP_BLIT_CFG = 0x0024U;
    static constexpr SData/*11:0*/ CP_BLIT_DST = 0x0028U;
    static constexpr SData/*11:0*/ CP_BLIT_SRC = 0x002cU;
    static constexpr SData/*11:0*/ CP_BLIT_SIZE = 0x0030U;
    static constexpr SData/*11:0*/ CP_BLIT_KICK = 0x0034U;
    static constexpr SData/*11:0*/ CP_GSX_MATA = 0x0038U;
    static constexpr SData/*11:0*/ CP_GSX_VTX = 0x003cU;
    static constexpr SData/*11:0*/ CP_GSX_COL = 0x0040U;
    static constexpr SData/*11:0*/ CP_GSX_GO = 0x0044U;
    static constexpr SData/*11:0*/ CP_GSX_CFG = 0x0048U;
    static constexpr SData/*11:0*/ CP_CORE_CODE = 0x004cU;
    static constexpr SData/*11:0*/ CP_CORE_NBLK = 0x0050U;
    static constexpr SData/*11:0*/ CP_CORE_KICK = 0x0054U;
    static constexpr SData/*11:0*/ CP_TU_A = 0x0058U;
    static constexpr SData/*11:0*/ CP_TU_W = 0x005cU;
    static constexpr SData/*11:0*/ CP_TU_C = 0x0060U;
    static constexpr SData/*11:0*/ CP_TU_CFG2 = 0x0064U;
    static constexpr SData/*11:0*/ CP_TU_KICK = 0x0068U;
    static constexpr IData/*31:0*/ NUM_CORES = 2U;
    static constexpr IData/*31:0*/ THREADS_PER_CORE = 4U;
    static constexpr IData/*31:0*/ GPRS_PER_THREAD = 0x00000010U;
    static constexpr IData/*31:0*/ AXI_ADDR_W = 0x00000020U;
    static constexpr IData/*31:0*/ AXI_DATA_W = 0x00000020U;
    static constexpr IData/*31:0*/ AXI_STRB_W = 4U;
    static constexpr IData/*31:0*/ VRAM_BYTES = 0x00080000U;
    static constexpr IData/*31:0*/ VRAM_AW = 0x00000013U;
    static constexpr IData/*31:0*/ FRAME_W_PX = 0x00000140U;
    static constexpr IData/*31:0*/ FRAME_H_PX = 0x000000f0U;
    static constexpr IData/*31:0*/ FB_STRIDE = 0x00000280U;
    static constexpr IData/*31:0*/ FB0_BASE = 0U;
    static constexpr IData/*31:0*/ ZBUF_BASE = 0x00025800U;
    static constexpr IData/*31:0*/ TEX_BASE = 0x0004b000U;
    static constexpr IData/*31:0*/ TEX_BYTES = 0x00010000U;
    static constexpr IData/*31:0*/ CMDBUF_BASE = 0x0005b000U;
    static constexpr IData/*31:0*/ CMDBUF_BYTES = 0x00008000U;
    static constexpr IData/*31:0*/ CP_WINDOW_BYTES = 0x00001000U;
    static constexpr IData/*31:0*/ CP_BASE = 0U;
    static constexpr IData/*31:0*/ VRAM_BASE = 0x00001000U;
    static constexpr IData/*31:0*/ NUM_MASTERS = 2U;
    static constexpr IData/*31:0*/ NUM_SLAVES = 2U;
    static constexpr IData/*31:0*/ RTR_CMDQ_BASE = 0x0005b000U;
    static constexpr IData/*31:0*/ RTR_CMDQ_WORDS = 0x00000400U;
    static constexpr IData/*31:0*/ RTR_CMD_WORDS = 0x00000013U;

    // CONSTRUCTORS
    Vtop_ember_pkg();
    ~Vtop_ember_pkg();
    void ctor(Vtop__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtop_ember_pkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
