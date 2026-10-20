// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop_ember_pkg
constexpr CData/*7:0*/ Vtop_ember_pkg::FENCE_CMD;
constexpr CData/*7:0*/ Vtop_ember_pkg::FENCE_FB;
constexpr CData/*7:0*/ Vtop_ember_pkg::FENCE_TEX;
constexpr CData/*1:0*/ Vtop_ember_pkg::RESP_OKAY;
constexpr CData/*1:0*/ Vtop_ember_pkg::RESP_EXOKAY;
constexpr CData/*1:0*/ Vtop_ember_pkg::RESP_SLVERR;
constexpr CData/*1:0*/ Vtop_ember_pkg::RESP_DECERR;
constexpr CData/*1:0*/ Vtop_ember_pkg::TGT_NONE;
constexpr SData/*11:0*/ Vtop_ember_pkg::CP_ID;
constexpr SData/*11:0*/ Vtop_ember_pkg::CP_STATUS;
constexpr SData/*11:0*/ Vtop_ember_pkg::CP_CTRL;
constexpr SData/*11:0*/ Vtop_ember_pkg::CP_FENCE;
constexpr SData/*11:0*/ Vtop_ember_pkg::CP_FIFOD;
constexpr SData/*11:0*/ Vtop_ember_pkg::CP_DMA_DST;
constexpr SData/*11:0*/ Vtop_ember_pkg::CP_DMA_LEN;
constexpr SData/*11:0*/ Vtop_ember_pkg::CP_CMDX;
constexpr SData/*11:0*/ Vtop_ember_pkg::CP_RTR_KICK;
constexpr SData/*11:0*/ Vtop_ember_pkg::CP_BLIT_CFG;
constexpr SData/*11:0*/ Vtop_ember_pkg::CP_BLIT_DST;
constexpr SData/*11:0*/ Vtop_ember_pkg::CP_BLIT_SRC;
constexpr SData/*11:0*/ Vtop_ember_pkg::CP_BLIT_SIZE;
constexpr SData/*11:0*/ Vtop_ember_pkg::CP_BLIT_KICK;
constexpr SData/*11:0*/ Vtop_ember_pkg::CP_GSX_MATA;
constexpr SData/*11:0*/ Vtop_ember_pkg::CP_GSX_VTX;
constexpr SData/*11:0*/ Vtop_ember_pkg::CP_GSX_COL;
constexpr SData/*11:0*/ Vtop_ember_pkg::CP_GSX_GO;
constexpr SData/*11:0*/ Vtop_ember_pkg::CP_GSX_CFG;
constexpr SData/*11:0*/ Vtop_ember_pkg::CP_CORE_CODE;
constexpr SData/*11:0*/ Vtop_ember_pkg::CP_CORE_NBLK;
constexpr SData/*11:0*/ Vtop_ember_pkg::CP_CORE_KICK;
constexpr SData/*11:0*/ Vtop_ember_pkg::CP_TU_A;
constexpr SData/*11:0*/ Vtop_ember_pkg::CP_TU_W;
constexpr SData/*11:0*/ Vtop_ember_pkg::CP_TU_C;
constexpr SData/*11:0*/ Vtop_ember_pkg::CP_TU_CFG2;
constexpr SData/*11:0*/ Vtop_ember_pkg::CP_TU_KICK;
constexpr IData/*31:0*/ Vtop_ember_pkg::NUM_CORES;
constexpr IData/*31:0*/ Vtop_ember_pkg::THREADS_PER_CORE;
constexpr IData/*31:0*/ Vtop_ember_pkg::GPRS_PER_THREAD;
constexpr IData/*31:0*/ Vtop_ember_pkg::AXI_ADDR_W;
constexpr IData/*31:0*/ Vtop_ember_pkg::AXI_DATA_W;
constexpr IData/*31:0*/ Vtop_ember_pkg::AXI_STRB_W;
constexpr IData/*31:0*/ Vtop_ember_pkg::VRAM_BYTES;
constexpr IData/*31:0*/ Vtop_ember_pkg::VRAM_AW;
constexpr IData/*31:0*/ Vtop_ember_pkg::FRAME_W_PX;
constexpr IData/*31:0*/ Vtop_ember_pkg::FRAME_H_PX;
constexpr IData/*31:0*/ Vtop_ember_pkg::FB_STRIDE;
constexpr IData/*31:0*/ Vtop_ember_pkg::FB0_BASE;
constexpr IData/*31:0*/ Vtop_ember_pkg::ZBUF_BASE;
constexpr IData/*31:0*/ Vtop_ember_pkg::TEX_BASE;
constexpr IData/*31:0*/ Vtop_ember_pkg::TEX_BYTES;
constexpr IData/*31:0*/ Vtop_ember_pkg::CMDBUF_BASE;
constexpr IData/*31:0*/ Vtop_ember_pkg::CMDBUF_BYTES;
constexpr IData/*31:0*/ Vtop_ember_pkg::CP_WINDOW_BYTES;
constexpr IData/*31:0*/ Vtop_ember_pkg::CP_BASE;
constexpr IData/*31:0*/ Vtop_ember_pkg::VRAM_BASE;
constexpr IData/*31:0*/ Vtop_ember_pkg::NUM_MASTERS;
constexpr IData/*31:0*/ Vtop_ember_pkg::NUM_SLAVES;
constexpr IData/*31:0*/ Vtop_ember_pkg::RTR_CMDQ_BASE;
constexpr IData/*31:0*/ Vtop_ember_pkg::RTR_CMDQ_WORDS;
constexpr IData/*31:0*/ Vtop_ember_pkg::RTR_CMD_WORDS;


void Vtop_ember_pkg___ctor_var_reset(Vtop_ember_pkg* vlSelf);

Vtop_ember_pkg::Vtop_ember_pkg() = default;
Vtop_ember_pkg::~Vtop_ember_pkg() = default;

void Vtop_ember_pkg::ctor(Vtop__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vtop_ember_pkg___ctor_var_reset(this);
}

void Vtop_ember_pkg::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vtop_ember_pkg::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
