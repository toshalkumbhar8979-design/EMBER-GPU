// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop___024root
constexpr CData/*1:0*/ Vtop___024root::ember_top__DOT__u_core__DOT__u_fpu__DOT__FOP_ADD;
constexpr CData/*1:0*/ Vtop___024root::ember_top__DOT__u_core__DOT__u_fpu__DOT__FOP_SUB;
constexpr CData/*1:0*/ Vtop___024root::ember_top__DOT__u_core__DOT__u_fpu__DOT__FOP_MUL;
constexpr CData/*1:0*/ Vtop___024root::ember_top__DOT__u_core__DOT__u_fpu__DOT__FOP_DIV;
constexpr CData/*1:0*/ Vtop___024root::ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__FOP_ADD;
constexpr CData/*1:0*/ Vtop___024root::ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__FOP_SUB;
constexpr CData/*1:0*/ Vtop___024root::ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__FOP_MUL;
constexpr CData/*1:0*/ Vtop___024root::ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__FOP_DIV;
constexpr IData/*31:0*/ Vtop___024root::ember_top__DOT__u_cp__DOT__UP_DEPTH;
constexpr IData/*31:0*/ Vtop___024root::ember_top__DOT__u_cp__DOT__UP_AW;
constexpr IData/*31:0*/ Vtop___024root::ember_top__DOT__u_cp__DOT__RB_DEPTH;
constexpr IData/*31:0*/ Vtop___024root::ember_top__DOT__u_cp__DOT__RB_AW;
constexpr IData/*31:0*/ Vtop___024root::ember_top__DOT__u_tu__DOT__N16;
constexpr IData/*31:0*/ Vtop___024root::ember_top__DOT__u_core__DOT__NT;
constexpr IData/*31:0*/ Vtop___024root::ember_top__DOT__u_core__DOT__SAW;
constexpr IData/*31:0*/ Vtop___024root::ember_top__DOT__u_core__DOT__u_fpu__DOT__AW;
constexpr IData/*31:0*/ Vtop___024root::ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__AW;
constexpr IData/*31:0*/ Vtop___024root::ember_top__DOT__u_blit__DOT__FB_BUS;
constexpr IData/*31:0*/ Vtop___024root::ember_top__DOT__u_rtr__DOT__CMDQ_BUS;
constexpr IData/*31:0*/ Vtop___024root::ember_top__DOT__u_rtr__DOT__CMD_STRIDE;
constexpr IData/*31:0*/ Vtop___024root::ember_top__DOT__u_rtr__DOT__u_setup__DOT__XMAX_Q;
constexpr IData/*31:0*/ Vtop___024root::ember_top__DOT__u_rtr__DOT__u_setup__DOT__YMAX_Q;
constexpr IData/*31:0*/ Vtop___024root::ember_top__DOT__u_rtr__DOT__u_scan__DOT__FB0;
constexpr IData/*31:0*/ Vtop___024root::ember_top__DOT__u_rtr__DOT__u_scan__DOT__ZB;
constexpr IData/*31:0*/ Vtop___024root::ember_top__DOT__u_disp__DOT__H_VISIBLE;
constexpr IData/*31:0*/ Vtop___024root::ember_top__DOT__u_disp__DOT__H_FP;
constexpr IData/*31:0*/ Vtop___024root::ember_top__DOT__u_disp__DOT__H_SYNC;
constexpr IData/*31:0*/ Vtop___024root::ember_top__DOT__u_disp__DOT__H_BP;
constexpr IData/*31:0*/ Vtop___024root::ember_top__DOT__u_disp__DOT__H_TOTAL;
constexpr IData/*31:0*/ Vtop___024root::ember_top__DOT__u_disp__DOT__V_VISIBLE;
constexpr IData/*31:0*/ Vtop___024root::ember_top__DOT__u_disp__DOT__V_FP;
constexpr IData/*31:0*/ Vtop___024root::ember_top__DOT__u_disp__DOT__V_SYNC;
constexpr IData/*31:0*/ Vtop___024root::ember_top__DOT__u_disp__DOT__V_BP;
constexpr IData/*31:0*/ Vtop___024root::ember_top__DOT__u_disp__DOT__V_TOTAL;
constexpr IData/*31:0*/ Vtop___024root::ember_top__DOT__u_disp__DOT__VID_LAT;
constexpr IData/*31:0*/ Vtop___024root::ember_top__DOT__u_disp__DOT__FB_BUS;
constexpr IData/*31:0*/ Vtop___024root::ember_top__DOT__u_vram__DOT__RAM_WORDS;
constexpr QData/*63:0*/ Vtop___024root::ember_top__DOT__u_rtr__DOT__u_setup__DOT__ONE_Q;
constexpr QData/*63:0*/ Vtop___024root::ember_top__DOT__u_rtr__DOT__u_scan__DOT__HALF_Q;


void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf);

Vtop___024root::Vtop___024root(Vtop__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vtop___024root___ctor_var_reset(this);
}

void Vtop___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop___024root::~Vtop___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
