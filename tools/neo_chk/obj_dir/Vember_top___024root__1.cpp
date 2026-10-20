// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vember_top.h for the primary calling header

#include "Vember_top__pch.h"

void Vember_top___024root___nba_sequent__TOP__1(Vember_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vember_top___024root___nba_sequent__TOP__1\n"); );
    Vember_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__9__Vfuncout;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__9__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__9__opc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__9__opc = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__9__av;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__9__av = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__9__bv;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__9__bv = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__Vfuncout;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__av;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__av = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__bv;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__bv = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sub_op;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sub_op = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sa = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sb = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sbs;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sbs = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__big_a;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__big_a = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sign_r;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sign_r = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__ea;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__ea = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__eb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__eb = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__big_e;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__big_e = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__delta;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__delta = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fa = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fb = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fr;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fr = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__a_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__a_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__b_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__b_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__a_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__a_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__b_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__b_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__a_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__a_z = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__b_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__b_z = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fa_w;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fa_w = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fb_w;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fb_w = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__norm;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__norm = 0;
    QData/*34:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fsum;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fsum = 0;
    CData/*5:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__top;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__top = 0;
    SData/*15:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sh_l;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sh_l = 0;
    SData/*10:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__e9;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__e9 = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__g;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__g = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__s;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__s = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__inc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__inc = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fc = 0;
    CData/*5:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__Vfuncout;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__Vfuncout = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v = 0;
    CData/*5:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__Vfuncout;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__av;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__av = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__bv;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__bv = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sub_op;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sub_op = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sa = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sb = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sbs;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sbs = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__big_a;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__big_a = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sign_r;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sign_r = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__ea;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__ea = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__eb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__eb = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__big_e;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__big_e = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__delta;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__delta = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fa = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fb = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fr;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fr = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__a_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__a_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__b_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__b_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__a_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__a_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__b_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__b_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__a_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__a_z = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__b_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__b_z = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fa_w;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fa_w = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fb_w;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fb_w = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__norm;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__norm = 0;
    QData/*34:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fsum;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fsum = 0;
    CData/*5:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__top;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__top = 0;
    SData/*15:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sh_l;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sh_l = 0;
    SData/*10:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__e9;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__e9 = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__g;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__g = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__s;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__s = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__inc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__inc = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fc = 0;
    CData/*5:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__Vfuncout;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__Vfuncout = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v = 0;
    CData/*5:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__Vfuncout;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__av;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__av = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__bv;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__bv = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__sa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__sa = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__sb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__sb = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__sg;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__sg = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__ea;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__ea = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__eb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__eb = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fa = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fb = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fr;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fr = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__a_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__a_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__b_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__b_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__a_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__a_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__b_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__b_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__a_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__a_z = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__b_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__b_z = 0;
    QData/*47:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__prod;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__prod = 0;
    IData/*23:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__f24;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__f24 = 0;
    SData/*10:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__e9;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__e9 = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__g;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__g = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__s;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__s = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__inc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__inc = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fc = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__Vfuncout;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__av;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__av = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__bv;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__bv = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sa = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sb = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sg;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sg = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__ea;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__ea = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__eb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__eb = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fa = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fb = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fr;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fr = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__a_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__a_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__b_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__b_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__a_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__a_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__b_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__b_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__a_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__a_z = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__b_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__b_z = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q = 0;
    IData/*23:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__f24;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__f24 = 0;
    SData/*10:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__e9;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__e9 = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__g;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__g = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__s;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__s = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__inc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__inc = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fc = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__23__Vfuncout;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__23__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__23__opc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__23__opc = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__23__av;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__23__av = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__23__bv;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__23__bv = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__Vfuncout;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__av;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__av = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__bv;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__bv = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sub_op;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sub_op = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sa = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sb = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sbs;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sbs = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__big_a;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__big_a = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sign_r;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sign_r = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__ea;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__ea = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__eb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__eb = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__big_e;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__big_e = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__delta;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__delta = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fa = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fb = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fr;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fr = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__a_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__a_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__b_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__b_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__a_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__a_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__b_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__b_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__a_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__a_z = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__b_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__b_z = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fa_w;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fa_w = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fb_w;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fb_w = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__norm;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__norm = 0;
    QData/*34:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fsum;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fsum = 0;
    CData/*5:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__top;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__top = 0;
    SData/*15:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sh_l;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sh_l = 0;
    SData/*10:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__e9;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__e9 = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__g;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__g = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__s;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__s = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__inc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__inc = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fc = 0;
    CData/*5:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__Vfuncout;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__Vfuncout = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v = 0;
    CData/*5:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__Vfuncout;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__av;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__av = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__bv;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__bv = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sub_op;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sub_op = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sa = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sb = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sbs;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sbs = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__big_a;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__big_a = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sign_r;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sign_r = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__ea;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__ea = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__eb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__eb = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__big_e;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__big_e = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__delta;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__delta = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fa = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fb = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fr;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fr = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__a_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__a_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__b_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__b_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__a_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__a_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__b_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__b_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__a_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__a_z = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__b_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__b_z = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fa_w;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fa_w = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fb_w;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fb_w = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__norm;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__norm = 0;
    QData/*34:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fsum;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fsum = 0;
    CData/*5:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__top;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__top = 0;
    SData/*15:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sh_l;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sh_l = 0;
    SData/*10:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__e9;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__e9 = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__g;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__g = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__s;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__s = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__inc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__inc = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fc = 0;
    CData/*5:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__Vfuncout;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__Vfuncout = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v = 0;
    CData/*5:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__Vfuncout;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__av;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__av = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__bv;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__bv = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__sa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__sa = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__sb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__sb = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__sg;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__sg = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__ea;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__ea = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__eb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__eb = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fa = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fb = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fr;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fr = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__a_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__a_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__b_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__b_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__a_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__a_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__b_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__b_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__a_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__a_z = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__b_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__b_z = 0;
    QData/*47:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__prod;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__prod = 0;
    IData/*23:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__f24;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__f24 = 0;
    SData/*10:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__e9;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__e9 = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__g;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__g = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__s;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__s = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__inc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__inc = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fc = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__Vfuncout;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__av;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__av = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__bv;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__bv = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sa = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sb = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sg;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sg = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__ea;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__ea = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__eb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__eb = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fa = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fb = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fr;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fr = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__a_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__a_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__b_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__b_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__a_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__a_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__b_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__b_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__a_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__a_z = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__b_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__b_z = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q = 0;
    IData/*23:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__f24;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__f24 = 0;
    SData/*10:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__e9;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__e9 = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__g;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__g = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__s;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__s = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__inc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__inc = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fc = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__30__Vfuncout;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__30__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__30__opc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__30__opc = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__30__av;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__30__av = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__30__bv;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__30__bv = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__Vfuncout;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__av;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__av = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__bv;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__bv = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sub_op;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sub_op = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sa = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sb = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sbs;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sbs = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__big_a;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__big_a = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sign_r;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sign_r = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__ea;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__ea = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__eb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__eb = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__big_e;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__big_e = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__delta;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__delta = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fa = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fb = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fr;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fr = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__a_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__a_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__b_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__b_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__a_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__a_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__b_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__b_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__a_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__a_z = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__b_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__b_z = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fa_w;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fa_w = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fb_w;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fb_w = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__norm;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__norm = 0;
    QData/*34:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fsum;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fsum = 0;
    CData/*5:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__top;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__top = 0;
    SData/*15:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sh_l;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sh_l = 0;
    SData/*10:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__e9;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__e9 = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__g;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__g = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__s;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__s = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__inc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__inc = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fc = 0;
    CData/*5:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__Vfuncout;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__Vfuncout = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v = 0;
    CData/*5:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__Vfuncout;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__av;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__av = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__bv;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__bv = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sub_op;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sub_op = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sa = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sb = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sbs;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sbs = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__big_a;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__big_a = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sign_r;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sign_r = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__ea;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__ea = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__eb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__eb = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__big_e;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__big_e = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__delta;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__delta = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fa = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fb = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fr;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fr = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__a_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__a_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__b_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__b_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__a_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__a_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__b_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__b_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__a_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__a_z = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__b_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__b_z = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fa_w;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fa_w = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fb_w;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fb_w = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__norm;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__norm = 0;
    QData/*34:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fsum;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fsum = 0;
    CData/*5:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__top;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__top = 0;
    SData/*15:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sh_l;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sh_l = 0;
    SData/*10:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__e9;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__e9 = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__g;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__g = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__s;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__s = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__inc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__inc = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fc = 0;
    CData/*5:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__Vfuncout;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__Vfuncout = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v = 0;
    CData/*5:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__Vfuncout;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__av;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__av = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__bv;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__bv = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__sa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__sa = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__sb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__sb = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__sg;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__sg = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__ea;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__ea = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__eb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__eb = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fa = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fb = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fr;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fr = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__a_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__a_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__b_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__b_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__a_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__a_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__b_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__b_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__a_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__a_z = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__b_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__b_z = 0;
    QData/*47:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__prod;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__prod = 0;
    IData/*23:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__f24;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__f24 = 0;
    SData/*10:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__e9;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__e9 = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__g;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__g = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__s;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__s = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__inc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__inc = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fc = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__Vfuncout;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__av;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__av = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__bv;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__bv = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sa = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sb = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sg;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sg = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__ea;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__ea = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__eb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__eb = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fa = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fb = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fr;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fr = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__a_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__a_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__b_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__b_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__a_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__a_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__b_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__b_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__a_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__a_z = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__b_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__b_z = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q = 0;
    IData/*23:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__f24;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__f24 = 0;
    SData/*10:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__e9;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__e9 = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__g;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__g = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__s;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__s = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__inc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__inc = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fc = 0;
    VlWide<3>/*95:0*/ __Vtemp_7;
    // Body
    if (vlSelfRef.rst_n) {
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U] 
            = (0x0000005fU & vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U]);
        if (((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__f_go) 
             & ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__f_lane_en) 
                >> 2U))) {
            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U] 
                = (0x00000040U | vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U]);
            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[1U] 
                = vlSelfRef.ember_top__DOT__u_core__DOT__f_b2;
            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[2U] 
                = (IData)((QData)((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__f_a2)));
            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U] 
                = ((0x00000060U & vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U]) 
                   | (0x0000007fU & ((0x00000018U & 
                                      ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__f_op) 
                                       << 3U)) | (IData)(
                                                         ((QData)((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__f_a2)) 
                                                          >> 0x00000020U)))));
            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[0U] = 0U;
        } else if ((0x00000040U & vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U])) {
            if ((4U == (7U & vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U]))) {
                vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U] 
                    = (0x00000020U | (0x0000001fU & vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U]));
                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__23__bv 
                    = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[1U];
                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__23__av 
                    = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[2U];
                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__23__opc 
                    = (3U & (vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U] 
                             >> 3U));
                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__23__Vfuncout = 0;
                if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__23__opc))) {
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sub_op = 0U;
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__bv 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__23__bv;
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__av 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__23__av;
                    {
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__Vfuncout = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sbs = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__big_a = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sign_r = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__ea = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__eb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__big_e = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__delta = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fr = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__a_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__b_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__a_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__b_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__a_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__b_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fa_w = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fb_w = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__norm = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fsum = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__top = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sh_l = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__e9 = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__g = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__s = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__inc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sa 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__av 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__ea 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__av 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fa 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__av);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sb 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__bv 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__eb 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__bv 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fb 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__bv);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sbs 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sb) 
                               ^ (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sub_op));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__a_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__ea)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__b_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__eb)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__a_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__b_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__a_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__b_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fb));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__a_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__av;
                            goto __Vlabel0;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__b_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__bv;
                            goto __Vlabel0;
                        }
                        if ((((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__a_inf) 
                              & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__b_inf)) 
                             & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sa) 
                                != (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sbs)))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__Vfuncout = 0x7fc00000U;
                            goto __Vlabel0;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__a_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__av;
                            goto __Vlabel0;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__b_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sbs) 
                                                  << 0x0000001fU));
                            goto __Vlabel0;
                        }
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__a_z) 
                             & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__b_z))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__Vfuncout = 0U;
                            goto __Vlabel0;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__a_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__Vfuncout 
                                = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sbs) 
                                    << 0x0000001fU) 
                                   | (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__eb) 
                                       << 0x00000017U) 
                                      | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fb));
                            goto __Vlabel0;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__b_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__av;
                            goto __Vlabel0;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__big_a 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__ea) 
                                > (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__eb)) 
                               | (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__ea) 
                                   == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__eb)) 
                                  & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fa 
                                     >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fb)));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__big_a) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__big_e 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__ea;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__delta 
                                = (0x000000ffU & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__ea) 
                                                  - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__eb)));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__big_e 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__eb;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__delta 
                                = (0x000000ffU & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__eb) 
                                                  - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__ea)));
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fa_w 
                            = (0x0000000200000000ULL 
                               | ((QData)((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fa)) 
                                  << 0x0000000aU));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fb_w 
                            = (0x0000000200000000ULL 
                               | ((QData)((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fb)) 
                                  << 0x0000000aU));
                        if ((0U != (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__delta))) {
                            if ((0x22U <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__delta))) {
                                if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__big_a) {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fb_w = 1ULL;
                                } else {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fa_w = 1ULL;
                                }
                            } else {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sh_l 
                                    = (0x0000ffffU 
                                       & ((IData)(0x0022U) 
                                          - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__delta)));
                                if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__big_a) {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fb_w 
                                        = (VL_SHIFTR_QQI(34,34,8, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fb_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__delta)) 
                                           | (QData)((IData)(
                                                             (0U 
                                                              != 
                                                              (0x00000003ffffffffULL 
                                                               & VL_SHIFTL_QQI(34,34,16, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fb_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sh_l)))))));
                                } else {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fa_w 
                                        = (VL_SHIFTR_QQI(34,34,8, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fa_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__delta)) 
                                           | (QData)((IData)(
                                                             (0U 
                                                              != 
                                                              (0x00000003ffffffffULL 
                                                               & VL_SHIFTL_QQI(34,34,16, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fa_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sh_l)))))));
                                }
                            }
                        }
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sa) 
                             == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sbs))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fsum 
                                = (0x00000007ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fa_w 
                                      + __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fb_w));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sign_r 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sa;
                        } else if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__big_a) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fsum 
                                = (0x00000007ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fa_w 
                                      - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fb_w));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sign_r 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sa;
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fsum 
                                = (0x00000007ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fb_w 
                                      - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fa_w));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sign_r 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sbs;
                        }
                        if ((0ULL == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fsum)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__Vfuncout = 0U;
                            goto __Vlabel0;
                        }
                        if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fsum 
                                           >> 0x22U)))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__norm 
                                = (0x00000003ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fsum 
                                      >> 1U));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__e9 
                                = (0x000007ffU & ((IData)(1U) 
                                                  + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__big_e)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__s 
                                = (1U & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fsum) 
                                         | (0U != (0x000001ffU 
                                                   & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__norm)))));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                = (0x00000003ffffffffULL 
                                   & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fsum);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__Vfuncout = 0;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 0;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 0U;
                            if ((1U & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 0U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 1U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 1U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 2U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 2U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 3U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 3U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 4U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 4U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 5U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 5U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 6U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 6U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 7U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 7U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 8U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 8U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 9U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 9U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 0x0aU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 0x0aU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 0x0bU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 0x0bU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 0x0cU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 0x0cU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 0x0dU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 0x0dU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 0x0eU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 0x0eU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 0x0fU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 0x0fU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 0x10U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 0x10U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 0x11U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 0x11U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 0x12U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 0x12U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 0x13U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 0x13U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 0x14U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 0x14U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 0x15U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 0x15U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 0x16U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 0x16U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 0x17U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 0x17U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 0x18U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 0x18U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 0x19U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 0x19U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 0x1aU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 0x1aU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 0x1bU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 0x1bU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 0x1cU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 0x1cU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 0x1dU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 0x1dU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 0x1eU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 0x1eU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 0x1fU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 0x1fU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 0x20U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 0x20U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__v 
                                               >> 0x21U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r = 0x21U;
                            }
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__r;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__top 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__25__Vfuncout;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__norm 
                                = (0x00000003ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fsum 
                                      << (0x0000003fU 
                                          & ((IData)(0x21U) 
                                             - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__top)))));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__e9 
                                = (0x000007ffU & (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__big_e) 
                                                   + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__top)) 
                                                  - (IData)(0x0021U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__s 
                                = (0U != (0x000001ffU 
                                          & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__norm)));
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fr 
                            = (0x007fffffU & (IData)(
                                                     (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__norm 
                                                      >> 0x0aU)));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__g 
                            = (1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__norm 
                                             >> 9U)));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__inc 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__g) 
                               & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__s) 
                                  | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fr));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__inc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fc 
                                = (0x007fffffU == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fr);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fr 
                                = (0x007fffffU & ((IData)(1U) 
                                                  + __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fr));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fc = 0U;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__e9 
                                = (0x000007ffU & ((IData)(1U) 
                                                  + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__e9)));
                        }
                        if ((0x0200U <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sign_r) 
                                   << 0x0000001fU);
                            goto __Vlabel0;
                        }
                        if ((0x00ffU <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sign_r) 
                                                  << 0x0000001fU));
                            goto __Vlabel0;
                        }
                        if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sign_r) 
                                   << 0x0000001fU);
                            goto __Vlabel0;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__Vfuncout 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sign_r) 
                                << 0x0000001fU) | (
                                                   (0x7f800000U 
                                                    & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__e9) 
                                                       << 0x00000017U)) 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fr));
                        __Vlabel0: ;
                    }
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__23__Vfuncout 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__Vfuncout;
                } else if ((1U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__23__opc))) {
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sub_op = 1U;
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__bv 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__23__bv;
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__av 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__23__av;
                    {
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__Vfuncout = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sbs = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__big_a = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sign_r = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__ea = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__eb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__big_e = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__delta = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fr = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__a_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__b_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__a_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__b_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__a_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__b_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fa_w = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fb_w = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__norm = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fsum = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__top = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sh_l = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__e9 = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__g = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__s = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__inc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sa 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__av 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__ea 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__av 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fa 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__av);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sb 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__bv 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__eb 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__bv 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fb 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__bv);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sbs 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sb) 
                               ^ (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sub_op));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__a_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__ea)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__b_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__eb)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__a_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__b_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__a_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__b_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fb));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__a_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__av;
                            goto __Vlabel1;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__b_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__bv;
                            goto __Vlabel1;
                        }
                        if ((((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__a_inf) 
                              & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__b_inf)) 
                             & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sa) 
                                != (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sbs)))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__Vfuncout = 0x7fc00000U;
                            goto __Vlabel1;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__a_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__av;
                            goto __Vlabel1;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__b_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sbs) 
                                                  << 0x0000001fU));
                            goto __Vlabel1;
                        }
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__a_z) 
                             & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__b_z))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__Vfuncout = 0U;
                            goto __Vlabel1;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__a_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__Vfuncout 
                                = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sbs) 
                                    << 0x0000001fU) 
                                   | (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__eb) 
                                       << 0x00000017U) 
                                      | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fb));
                            goto __Vlabel1;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__b_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__av;
                            goto __Vlabel1;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__big_a 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__ea) 
                                > (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__eb)) 
                               | (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__ea) 
                                   == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__eb)) 
                                  & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fa 
                                     >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fb)));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__big_a) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__big_e 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__ea;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__delta 
                                = (0x000000ffU & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__ea) 
                                                  - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__eb)));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__big_e 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__eb;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__delta 
                                = (0x000000ffU & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__eb) 
                                                  - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__ea)));
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fa_w 
                            = (0x0000000200000000ULL 
                               | ((QData)((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fa)) 
                                  << 0x0000000aU));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fb_w 
                            = (0x0000000200000000ULL 
                               | ((QData)((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fb)) 
                                  << 0x0000000aU));
                        if ((0U != (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__delta))) {
                            if ((0x22U <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__delta))) {
                                if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__big_a) {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fb_w = 1ULL;
                                } else {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fa_w = 1ULL;
                                }
                            } else {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sh_l 
                                    = (0x0000ffffU 
                                       & ((IData)(0x0022U) 
                                          - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__delta)));
                                if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__big_a) {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fb_w 
                                        = (VL_SHIFTR_QQI(34,34,8, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fb_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__delta)) 
                                           | (QData)((IData)(
                                                             (0U 
                                                              != 
                                                              (0x00000003ffffffffULL 
                                                               & VL_SHIFTL_QQI(34,34,16, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fb_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sh_l)))))));
                                } else {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fa_w 
                                        = (VL_SHIFTR_QQI(34,34,8, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fa_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__delta)) 
                                           | (QData)((IData)(
                                                             (0U 
                                                              != 
                                                              (0x00000003ffffffffULL 
                                                               & VL_SHIFTL_QQI(34,34,16, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fa_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sh_l)))))));
                                }
                            }
                        }
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sa) 
                             == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sbs))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fsum 
                                = (0x00000007ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fa_w 
                                      + __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fb_w));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sign_r 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sa;
                        } else if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__big_a) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fsum 
                                = (0x00000007ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fa_w 
                                      - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fb_w));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sign_r 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sa;
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fsum 
                                = (0x00000007ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fb_w 
                                      - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fa_w));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sign_r 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sbs;
                        }
                        if ((0ULL == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fsum)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__Vfuncout = 0U;
                            goto __Vlabel1;
                        }
                        if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fsum 
                                           >> 0x22U)))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__norm 
                                = (0x00000003ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fsum 
                                      >> 1U));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__e9 
                                = (0x000007ffU & ((IData)(1U) 
                                                  + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__big_e)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__s 
                                = (1U & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fsum) 
                                         | (0U != (0x000001ffU 
                                                   & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__norm)))));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                = (0x00000003ffffffffULL 
                                   & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fsum);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__Vfuncout = 0;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 0;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 0U;
                            if ((1U & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 0U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 1U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 1U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 2U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 2U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 3U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 3U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 4U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 4U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 5U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 5U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 6U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 6U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 7U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 7U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 8U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 8U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 9U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 9U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 0x0aU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 0x0aU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 0x0bU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 0x0bU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 0x0cU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 0x0cU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 0x0dU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 0x0dU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 0x0eU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 0x0eU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 0x0fU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 0x0fU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 0x10U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 0x10U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 0x11U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 0x11U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 0x12U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 0x12U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 0x13U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 0x13U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 0x14U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 0x14U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 0x15U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 0x15U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 0x16U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 0x16U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 0x17U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 0x17U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 0x18U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 0x18U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 0x19U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 0x19U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 0x1aU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 0x1aU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 0x1bU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 0x1bU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 0x1cU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 0x1cU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 0x1dU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 0x1dU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 0x1eU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 0x1eU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 0x1fU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 0x1fU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 0x20U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 0x20U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__v 
                                               >> 0x21U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r = 0x21U;
                            }
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__r;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__top 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__27__Vfuncout;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__norm 
                                = (0x00000003ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fsum 
                                      << (0x0000003fU 
                                          & ((IData)(0x21U) 
                                             - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__top)))));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__e9 
                                = (0x000007ffU & (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__big_e) 
                                                   + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__top)) 
                                                  - (IData)(0x0021U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__s 
                                = (0U != (0x000001ffU 
                                          & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__norm)));
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fr 
                            = (0x007fffffU & (IData)(
                                                     (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__norm 
                                                      >> 0x0aU)));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__g 
                            = (1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__norm 
                                             >> 9U)));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__inc 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__g) 
                               & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__s) 
                                  | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fr));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__inc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fc 
                                = (0x007fffffU == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fr);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fr 
                                = (0x007fffffU & ((IData)(1U) 
                                                  + __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fr));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fc = 0U;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__e9 
                                = (0x000007ffU & ((IData)(1U) 
                                                  + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__e9)));
                        }
                        if ((0x0200U <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sign_r) 
                                   << 0x0000001fU);
                            goto __Vlabel1;
                        }
                        if ((0x00ffU <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sign_r) 
                                                  << 0x0000001fU));
                            goto __Vlabel1;
                        }
                        if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sign_r) 
                                   << 0x0000001fU);
                            goto __Vlabel1;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__Vfuncout 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sign_r) 
                                << 0x0000001fU) | (
                                                   (0x7f800000U 
                                                    & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__e9) 
                                                       << 0x00000017U)) 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fr));
                        __Vlabel1: ;
                    }
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__23__Vfuncout 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__Vfuncout;
                } else if ((2U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__23__opc))) {
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__bv 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__23__bv;
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__av 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__23__av;
                    {
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__Vfuncout = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__sa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__sb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__sg = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__ea = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__eb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fr = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__a_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__b_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__a_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__b_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__a_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__b_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__prod = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__f24 = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__e9 = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__g = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__s = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__inc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__sa 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__av 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__ea 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__av 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fa 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__av);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__sb 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__bv 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__eb 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__bv 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fb 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__bv);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__a_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__ea)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__b_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__eb)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__a_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__b_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__a_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__b_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fb));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__a_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__av;
                            goto __Vlabel2;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__b_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__bv;
                            goto __Vlabel2;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__sg 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__sa) 
                               ^ (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__sb));
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__a_inf) 
                             | (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__b_inf))) {
                            if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__a_z) 
                                 | (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__b_z))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__Vfuncout 
                                    = (0x7fc00000U 
                                       | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__sg) 
                                          << 0x0000001fU));
                                goto __Vlabel2;
                            }
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel2;
                        }
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__a_z) 
                             | (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__b_z))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel2;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__prod 
                            = (0x0000ffffffffffffULL 
                               & ((QData)((IData)((0x00800000U 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fa))) 
                                  * (QData)((IData)(
                                                    (0x00800000U 
                                                     | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fb)))));
                        if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__prod 
                                           >> 0x2fU)))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__f24 
                                = (0x00ffffffU & (IData)(
                                                         (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__prod 
                                                          >> 0x00000018U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__g 
                                = (1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__prod 
                                                 >> 0x17U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__s 
                                = (0U != (0x007fffffU 
                                          & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__prod)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__e9 
                                = (0x000007ffU & (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__ea) 
                                                   + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__eb)) 
                                                  - (IData)(0x007eU)));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__f24 
                                = (0x00ffffffU & (IData)(
                                                         (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__prod 
                                                          >> 0x00000017U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__g 
                                = (1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__prod 
                                                 >> 0x16U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__s 
                                = (0U != (0x003fffffU 
                                          & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__prod)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__e9 
                                = (0x000007ffU & (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__ea) 
                                                   + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__eb)) 
                                                  - (IData)(0x007fU)));
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fr 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__f24);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__inc 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__g) 
                               & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__s) 
                                  | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fr));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__inc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fc 
                                = (0x007fffffU == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fr);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fr 
                                = (0x007fffffU & ((IData)(1U) 
                                                  + __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fr));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fc = 0U;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__e9 
                                = (0x000007ffU & ((IData)(1U) 
                                                  + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__e9)));
                        }
                        if ((0x0200U <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel2;
                        }
                        if ((0x00ffU <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel2;
                        }
                        if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel2;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__Vfuncout 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__sg) 
                                << 0x0000001fU) | (
                                                   (0x7f800000U 
                                                    & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__e9) 
                                                       << 0x00000017U)) 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fr));
                        __Vlabel2: ;
                    }
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__23__Vfuncout 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__Vfuncout;
                } else {
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__bv 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__23__bv;
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__av 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__23__av;
                    {
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__Vfuncout = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sg = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__ea = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__eb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fr = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__a_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__b_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__a_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__b_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__a_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__b_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__f24 = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__e9 = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__g = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__s = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__inc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sa 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__av 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__ea 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__av 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fa 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__av);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sb 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__bv 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__eb 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__bv 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fb 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__bv);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__a_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__ea)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__b_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__eb)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__a_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__b_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__a_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__b_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fb));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__a_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__av;
                            goto __Vlabel3;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__b_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__bv;
                            goto __Vlabel3;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sg 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sa) 
                               ^ (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sb));
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__a_inf) 
                             & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__b_inf))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__Vfuncout = 0x7fc00000U;
                            goto __Vlabel3;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__a_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel3;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__b_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel3;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__b_z) {
                            if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__a_z) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__Vfuncout = 0x7fc00000U;
                                goto __Vlabel3;
                            }
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel3;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__a_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel3;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                            = (0x0002000000000000ULL 
                               | ((QData)((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fa)) 
                                  << 0x0000001aU));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den 
                            = (0x0000000000800000ULL 
                               | (QData)((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fb)));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem = 0ULL;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q = 0ULL;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (QData)((IData)((1U & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x3fU)))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x8000000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x3eU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x4000000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x3dU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x2000000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x3cU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x1000000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x3bU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0800000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x3aU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0400000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x39U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0200000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x38U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0100000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x37U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0080000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x36U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0040000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x35U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0020000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x34U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0010000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x33U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0008000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x32U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0004000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x31U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0002000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x30U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0001000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x2fU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000800000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x2eU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000400000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x2dU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000200000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x2cU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000100000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x2bU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000080000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x2aU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000040000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x29U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000020000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x28U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000010000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x27U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000008000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x26U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000004000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x25U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000002000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x24U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000001000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x23U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000800000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x22U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000400000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x21U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000200000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x20U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000100000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x1fU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000080000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x1eU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000040000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x1dU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000020000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x1cU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000010000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x1bU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000008000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x1aU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000004000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x19U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000002000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x18U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000001000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x17U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000000800000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x16U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000000400000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x15U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000000200000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x14U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000000100000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x13U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000000080000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x12U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000000040000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x11U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000000020000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x10U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000000010000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x0fU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000000008000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x0eU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000000004000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x0dU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000000002000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x0cU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000000001000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x0bU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000000000800ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 0x0aU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000000000400ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 9U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000000000200ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 8U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000000000100ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 7U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000000000080ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 6U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000000000040ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 5U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000000000020ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 4U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (0x0000000000000010ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 3U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (8ULL | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 2U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (4ULL | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num 
                                                             >> 1U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (2ULL | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__num)))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                = (1ULL | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q);
                        }
                        if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                           >> 0x1aU)))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__f24 
                                = (0x00ffffffU & (IData)(
                                                         (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                                          >> 3U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__g 
                                = (1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                                 >> 2U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__s 
                                = (IData)(((0ULL != 
                                            (3ULL & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q)) 
                                           | (0ULL 
                                              != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__e9 
                                = (0x000007ffU & ((IData)(0x007fU) 
                                                  + 
                                                  ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__ea) 
                                                   - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__eb))));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__f24 
                                = (0x00ffffffU & (IData)(
                                                         (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                                          >> 2U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__g 
                                = (1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q 
                                                 >> 1U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__s 
                                = (1U & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__q) 
                                         | (0ULL != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__rem)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__e9 
                                = (0x000007ffU & ((IData)(0x007eU) 
                                                  + 
                                                  ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__ea) 
                                                   - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__eb))));
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fr 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__f24);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__inc 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__g) 
                               & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__s) 
                                  | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fr));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__inc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fc 
                                = (0x007fffffU == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fr);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fr 
                                = (0x007fffffU & ((IData)(1U) 
                                                  + __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fr));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fc = 0U;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__e9 
                                = (0x000007ffU & ((IData)(1U) 
                                                  + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__e9)));
                        }
                        if ((0x0200U <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel3;
                        }
                        if ((0x00ffU <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel3;
                        }
                        if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel3;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__Vfuncout 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sg) 
                                << 0x0000001fU) | (
                                                   (0x7f800000U 
                                                    & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__e9) 
                                                       << 0x00000017U)) 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fr));
                        __Vlabel3: ;
                    }
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__23__Vfuncout 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__Vfuncout;
                }
                vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[0U] 
                    = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__23__Vfuncout;
            } else {
                vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U] 
                    = ((0x00000078U & vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U]) 
                       | (7U & ((IData)(1U) + vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U])));
            }
        }
    } else {
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[0U] = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[1U] = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[2U] = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U] = 0U;
    }
    if (vlSelfRef.rst_n) {
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U] 
            = (0x0000005fU & vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U]);
        if (((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__f_go) 
             & ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__f_lane_en) 
                >> 3U))) {
            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U] 
                = (0x00000040U | vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U]);
            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[1U] 
                = vlSelfRef.ember_top__DOT__u_core__DOT__f_b3;
            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[2U] 
                = (IData)((QData)((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__f_a3)));
            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U] 
                = ((0x00000060U & vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U]) 
                   | (0x0000007fU & ((0x00000018U & 
                                      ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__f_op) 
                                       << 3U)) | (IData)(
                                                         ((QData)((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__f_a3)) 
                                                          >> 0x00000020U)))));
            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[0U] = 0U;
        } else if ((0x00000040U & vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U])) {
            if ((4U == (7U & vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U]))) {
                vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U] 
                    = (0x00000020U | (0x0000001fU & vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U]));
                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__30__bv 
                    = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[1U];
                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__30__av 
                    = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[2U];
                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__30__opc 
                    = (3U & (vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U] 
                             >> 3U));
                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__30__Vfuncout = 0;
                if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__30__opc))) {
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sub_op = 0U;
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__bv 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__30__bv;
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__av 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__30__av;
                    {
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__Vfuncout = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sbs = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__big_a = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sign_r = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__ea = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__eb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__big_e = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__delta = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fr = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__a_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__b_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__a_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__b_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__a_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__b_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fa_w = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fb_w = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__norm = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fsum = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__top = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sh_l = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__e9 = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__g = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__s = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__inc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sa 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__av 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__ea 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__av 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fa 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__av);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sb 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__bv 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__eb 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__bv 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fb 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__bv);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sbs 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sb) 
                               ^ (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sub_op));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__a_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__ea)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__b_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__eb)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__a_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__b_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__a_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__b_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fb));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__a_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__av;
                            goto __Vlabel4;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__b_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__bv;
                            goto __Vlabel4;
                        }
                        if ((((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__a_inf) 
                              & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__b_inf)) 
                             & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sa) 
                                != (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sbs)))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__Vfuncout = 0x7fc00000U;
                            goto __Vlabel4;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__a_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__av;
                            goto __Vlabel4;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__b_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sbs) 
                                                  << 0x0000001fU));
                            goto __Vlabel4;
                        }
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__a_z) 
                             & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__b_z))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__Vfuncout = 0U;
                            goto __Vlabel4;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__a_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__Vfuncout 
                                = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sbs) 
                                    << 0x0000001fU) 
                                   | (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__eb) 
                                       << 0x00000017U) 
                                      | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fb));
                            goto __Vlabel4;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__b_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__av;
                            goto __Vlabel4;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__big_a 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__ea) 
                                > (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__eb)) 
                               | (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__ea) 
                                   == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__eb)) 
                                  & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fa 
                                     >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fb)));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__big_a) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__big_e 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__ea;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__delta 
                                = (0x000000ffU & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__ea) 
                                                  - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__eb)));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__big_e 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__eb;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__delta 
                                = (0x000000ffU & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__eb) 
                                                  - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__ea)));
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fa_w 
                            = (0x0000000200000000ULL 
                               | ((QData)((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fa)) 
                                  << 0x0000000aU));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fb_w 
                            = (0x0000000200000000ULL 
                               | ((QData)((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fb)) 
                                  << 0x0000000aU));
                        if ((0U != (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__delta))) {
                            if ((0x22U <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__delta))) {
                                if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__big_a) {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fb_w = 1ULL;
                                } else {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fa_w = 1ULL;
                                }
                            } else {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sh_l 
                                    = (0x0000ffffU 
                                       & ((IData)(0x0022U) 
                                          - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__delta)));
                                if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__big_a) {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fb_w 
                                        = (VL_SHIFTR_QQI(34,34,8, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fb_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__delta)) 
                                           | (QData)((IData)(
                                                             (0U 
                                                              != 
                                                              (0x00000003ffffffffULL 
                                                               & VL_SHIFTL_QQI(34,34,16, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fb_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sh_l)))))));
                                } else {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fa_w 
                                        = (VL_SHIFTR_QQI(34,34,8, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fa_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__delta)) 
                                           | (QData)((IData)(
                                                             (0U 
                                                              != 
                                                              (0x00000003ffffffffULL 
                                                               & VL_SHIFTL_QQI(34,34,16, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fa_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sh_l)))))));
                                }
                            }
                        }
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sa) 
                             == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sbs))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fsum 
                                = (0x00000007ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fa_w 
                                      + __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fb_w));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sign_r 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sa;
                        } else if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__big_a) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fsum 
                                = (0x00000007ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fa_w 
                                      - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fb_w));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sign_r 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sa;
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fsum 
                                = (0x00000007ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fb_w 
                                      - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fa_w));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sign_r 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sbs;
                        }
                        if ((0ULL == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fsum)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__Vfuncout = 0U;
                            goto __Vlabel4;
                        }
                        if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fsum 
                                           >> 0x22U)))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__norm 
                                = (0x00000003ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fsum 
                                      >> 1U));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__e9 
                                = (0x000007ffU & ((IData)(1U) 
                                                  + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__big_e)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__s 
                                = (1U & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fsum) 
                                         | (0U != (0x000001ffU 
                                                   & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__norm)))));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                = (0x00000003ffffffffULL 
                                   & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fsum);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__Vfuncout = 0;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 0;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 0U;
                            if ((1U & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 0U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 1U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 1U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 2U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 2U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 3U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 3U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 4U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 4U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 5U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 5U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 6U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 6U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 7U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 7U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 8U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 8U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 9U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 9U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 0x0aU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 0x0aU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 0x0bU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 0x0bU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 0x0cU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 0x0cU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 0x0dU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 0x0dU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 0x0eU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 0x0eU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 0x0fU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 0x0fU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 0x10U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 0x10U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 0x11U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 0x11U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 0x12U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 0x12U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 0x13U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 0x13U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 0x14U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 0x14U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 0x15U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 0x15U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 0x16U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 0x16U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 0x17U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 0x17U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 0x18U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 0x18U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 0x19U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 0x19U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 0x1aU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 0x1aU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 0x1bU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 0x1bU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 0x1cU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 0x1cU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 0x1dU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 0x1dU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 0x1eU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 0x1eU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 0x1fU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 0x1fU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 0x20U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 0x20U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__v 
                                               >> 0x21U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r = 0x21U;
                            }
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__r;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__top 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__32__Vfuncout;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__norm 
                                = (0x00000003ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fsum 
                                      << (0x0000003fU 
                                          & ((IData)(0x21U) 
                                             - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__top)))));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__e9 
                                = (0x000007ffU & (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__big_e) 
                                                   + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__top)) 
                                                  - (IData)(0x0021U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__s 
                                = (0U != (0x000001ffU 
                                          & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__norm)));
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fr 
                            = (0x007fffffU & (IData)(
                                                     (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__norm 
                                                      >> 0x0aU)));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__g 
                            = (1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__norm 
                                             >> 9U)));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__inc 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__g) 
                               & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__s) 
                                  | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fr));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__inc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fc 
                                = (0x007fffffU == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fr);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fr 
                                = (0x007fffffU & ((IData)(1U) 
                                                  + __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fr));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fc = 0U;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__e9 
                                = (0x000007ffU & ((IData)(1U) 
                                                  + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__e9)));
                        }
                        if ((0x0200U <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sign_r) 
                                   << 0x0000001fU);
                            goto __Vlabel4;
                        }
                        if ((0x00ffU <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sign_r) 
                                                  << 0x0000001fU));
                            goto __Vlabel4;
                        }
                        if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sign_r) 
                                   << 0x0000001fU);
                            goto __Vlabel4;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__Vfuncout 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sign_r) 
                                << 0x0000001fU) | (
                                                   (0x7f800000U 
                                                    & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__e9) 
                                                       << 0x00000017U)) 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fr));
                        __Vlabel4: ;
                    }
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__30__Vfuncout 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__Vfuncout;
                } else if ((1U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__30__opc))) {
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sub_op = 1U;
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__bv 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__30__bv;
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__av 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__30__av;
                    {
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__Vfuncout = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sbs = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__big_a = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sign_r = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__ea = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__eb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__big_e = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__delta = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fr = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__a_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__b_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__a_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__b_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__a_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__b_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fa_w = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fb_w = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__norm = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fsum = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__top = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sh_l = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__e9 = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__g = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__s = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__inc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sa 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__av 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__ea 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__av 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fa 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__av);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sb 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__bv 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__eb 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__bv 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fb 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__bv);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sbs 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sb) 
                               ^ (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sub_op));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__a_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__ea)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__b_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__eb)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__a_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__b_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__a_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__b_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fb));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__a_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__av;
                            goto __Vlabel5;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__b_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__bv;
                            goto __Vlabel5;
                        }
                        if ((((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__a_inf) 
                              & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__b_inf)) 
                             & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sa) 
                                != (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sbs)))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__Vfuncout = 0x7fc00000U;
                            goto __Vlabel5;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__a_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__av;
                            goto __Vlabel5;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__b_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sbs) 
                                                  << 0x0000001fU));
                            goto __Vlabel5;
                        }
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__a_z) 
                             & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__b_z))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__Vfuncout = 0U;
                            goto __Vlabel5;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__a_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__Vfuncout 
                                = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sbs) 
                                    << 0x0000001fU) 
                                   | (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__eb) 
                                       << 0x00000017U) 
                                      | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fb));
                            goto __Vlabel5;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__b_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__av;
                            goto __Vlabel5;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__big_a 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__ea) 
                                > (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__eb)) 
                               | (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__ea) 
                                   == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__eb)) 
                                  & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fa 
                                     >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fb)));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__big_a) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__big_e 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__ea;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__delta 
                                = (0x000000ffU & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__ea) 
                                                  - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__eb)));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__big_e 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__eb;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__delta 
                                = (0x000000ffU & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__eb) 
                                                  - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__ea)));
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fa_w 
                            = (0x0000000200000000ULL 
                               | ((QData)((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fa)) 
                                  << 0x0000000aU));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fb_w 
                            = (0x0000000200000000ULL 
                               | ((QData)((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fb)) 
                                  << 0x0000000aU));
                        if ((0U != (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__delta))) {
                            if ((0x22U <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__delta))) {
                                if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__big_a) {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fb_w = 1ULL;
                                } else {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fa_w = 1ULL;
                                }
                            } else {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sh_l 
                                    = (0x0000ffffU 
                                       & ((IData)(0x0022U) 
                                          - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__delta)));
                                if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__big_a) {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fb_w 
                                        = (VL_SHIFTR_QQI(34,34,8, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fb_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__delta)) 
                                           | (QData)((IData)(
                                                             (0U 
                                                              != 
                                                              (0x00000003ffffffffULL 
                                                               & VL_SHIFTL_QQI(34,34,16, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fb_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sh_l)))))));
                                } else {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fa_w 
                                        = (VL_SHIFTR_QQI(34,34,8, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fa_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__delta)) 
                                           | (QData)((IData)(
                                                             (0U 
                                                              != 
                                                              (0x00000003ffffffffULL 
                                                               & VL_SHIFTL_QQI(34,34,16, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fa_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sh_l)))))));
                                }
                            }
                        }
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sa) 
                             == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sbs))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fsum 
                                = (0x00000007ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fa_w 
                                      + __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fb_w));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sign_r 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sa;
                        } else if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__big_a) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fsum 
                                = (0x00000007ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fa_w 
                                      - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fb_w));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sign_r 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sa;
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fsum 
                                = (0x00000007ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fb_w 
                                      - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fa_w));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sign_r 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sbs;
                        }
                        if ((0ULL == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fsum)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__Vfuncout = 0U;
                            goto __Vlabel5;
                        }
                        if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fsum 
                                           >> 0x22U)))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__norm 
                                = (0x00000003ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fsum 
                                      >> 1U));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__e9 
                                = (0x000007ffU & ((IData)(1U) 
                                                  + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__big_e)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__s 
                                = (1U & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fsum) 
                                         | (0U != (0x000001ffU 
                                                   & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__norm)))));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                = (0x00000003ffffffffULL 
                                   & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fsum);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__Vfuncout = 0;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 0;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 0U;
                            if ((1U & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 0U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 1U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 1U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 2U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 2U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 3U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 3U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 4U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 4U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 5U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 5U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 6U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 6U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 7U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 7U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 8U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 8U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 9U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 9U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 0x0aU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 0x0aU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 0x0bU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 0x0bU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 0x0cU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 0x0cU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 0x0dU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 0x0dU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 0x0eU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 0x0eU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 0x0fU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 0x0fU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 0x10U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 0x10U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 0x11U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 0x11U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 0x12U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 0x12U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 0x13U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 0x13U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 0x14U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 0x14U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 0x15U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 0x15U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 0x16U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 0x16U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 0x17U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 0x17U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 0x18U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 0x18U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 0x19U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 0x19U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 0x1aU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 0x1aU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 0x1bU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 0x1bU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 0x1cU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 0x1cU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 0x1dU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 0x1dU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 0x1eU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 0x1eU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 0x1fU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 0x1fU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 0x20U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 0x20U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__v 
                                               >> 0x21U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r = 0x21U;
                            }
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__r;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__top 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__34__Vfuncout;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__norm 
                                = (0x00000003ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fsum 
                                      << (0x0000003fU 
                                          & ((IData)(0x21U) 
                                             - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__top)))));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__e9 
                                = (0x000007ffU & (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__big_e) 
                                                   + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__top)) 
                                                  - (IData)(0x0021U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__s 
                                = (0U != (0x000001ffU 
                                          & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__norm)));
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fr 
                            = (0x007fffffU & (IData)(
                                                     (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__norm 
                                                      >> 0x0aU)));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__g 
                            = (1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__norm 
                                             >> 9U)));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__inc 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__g) 
                               & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__s) 
                                  | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fr));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__inc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fc 
                                = (0x007fffffU == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fr);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fr 
                                = (0x007fffffU & ((IData)(1U) 
                                                  + __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fr));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fc = 0U;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__e9 
                                = (0x000007ffU & ((IData)(1U) 
                                                  + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__e9)));
                        }
                        if ((0x0200U <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sign_r) 
                                   << 0x0000001fU);
                            goto __Vlabel5;
                        }
                        if ((0x00ffU <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sign_r) 
                                                  << 0x0000001fU));
                            goto __Vlabel5;
                        }
                        if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sign_r) 
                                   << 0x0000001fU);
                            goto __Vlabel5;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__Vfuncout 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sign_r) 
                                << 0x0000001fU) | (
                                                   (0x7f800000U 
                                                    & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__e9) 
                                                       << 0x00000017U)) 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fr));
                        __Vlabel5: ;
                    }
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__30__Vfuncout 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__Vfuncout;
                } else if ((2U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__30__opc))) {
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__bv 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__30__bv;
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__av 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__30__av;
                    {
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__Vfuncout = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__sa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__sb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__sg = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__ea = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__eb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fr = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__a_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__b_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__a_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__b_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__a_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__b_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__prod = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__f24 = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__e9 = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__g = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__s = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__inc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__sa 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__av 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__ea 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__av 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fa 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__av);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__sb 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__bv 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__eb 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__bv 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fb 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__bv);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__a_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__ea)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__b_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__eb)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__a_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__b_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__a_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__b_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fb));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__a_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__av;
                            goto __Vlabel6;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__b_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__bv;
                            goto __Vlabel6;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__sg 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__sa) 
                               ^ (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__sb));
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__a_inf) 
                             | (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__b_inf))) {
                            if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__a_z) 
                                 | (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__b_z))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__Vfuncout 
                                    = (0x7fc00000U 
                                       | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__sg) 
                                          << 0x0000001fU));
                                goto __Vlabel6;
                            }
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel6;
                        }
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__a_z) 
                             | (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__b_z))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel6;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__prod 
                            = (0x0000ffffffffffffULL 
                               & ((QData)((IData)((0x00800000U 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fa))) 
                                  * (QData)((IData)(
                                                    (0x00800000U 
                                                     | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fb)))));
                        if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__prod 
                                           >> 0x2fU)))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__f24 
                                = (0x00ffffffU & (IData)(
                                                         (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__prod 
                                                          >> 0x00000018U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__g 
                                = (1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__prod 
                                                 >> 0x17U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__s 
                                = (0U != (0x007fffffU 
                                          & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__prod)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__e9 
                                = (0x000007ffU & (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__ea) 
                                                   + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__eb)) 
                                                  - (IData)(0x007eU)));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__f24 
                                = (0x00ffffffU & (IData)(
                                                         (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__prod 
                                                          >> 0x00000017U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__g 
                                = (1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__prod 
                                                 >> 0x16U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__s 
                                = (0U != (0x003fffffU 
                                          & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__prod)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__e9 
                                = (0x000007ffU & (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__ea) 
                                                   + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__eb)) 
                                                  - (IData)(0x007fU)));
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fr 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__f24);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__inc 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__g) 
                               & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__s) 
                                  | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fr));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__inc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fc 
                                = (0x007fffffU == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fr);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fr 
                                = (0x007fffffU & ((IData)(1U) 
                                                  + __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fr));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fc = 0U;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__e9 
                                = (0x000007ffU & ((IData)(1U) 
                                                  + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__e9)));
                        }
                        if ((0x0200U <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel6;
                        }
                        if ((0x00ffU <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel6;
                        }
                        if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel6;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__Vfuncout 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__sg) 
                                << 0x0000001fU) | (
                                                   (0x7f800000U 
                                                    & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__e9) 
                                                       << 0x00000017U)) 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fr));
                        __Vlabel6: ;
                    }
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__30__Vfuncout 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__Vfuncout;
                } else {
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__bv 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__30__bv;
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__av 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__30__av;
                    {
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__Vfuncout = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sg = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__ea = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__eb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fr = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__a_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__b_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__a_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__b_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__a_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__b_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__f24 = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__e9 = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__g = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__s = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__inc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sa 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__av 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__ea 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__av 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fa 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__av);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sb 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__bv 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__eb 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__bv 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fb 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__bv);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__a_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__ea)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__b_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__eb)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__a_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__b_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__a_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__b_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fb));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__a_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__av;
                            goto __Vlabel7;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__b_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__bv;
                            goto __Vlabel7;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sg 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sa) 
                               ^ (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sb));
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__a_inf) 
                             & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__b_inf))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__Vfuncout = 0x7fc00000U;
                            goto __Vlabel7;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__a_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel7;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__b_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel7;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__b_z) {
                            if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__a_z) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__Vfuncout = 0x7fc00000U;
                                goto __Vlabel7;
                            }
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel7;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__a_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel7;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                            = (0x0002000000000000ULL 
                               | ((QData)((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fa)) 
                                  << 0x0000001aU));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den 
                            = (0x0000000000800000ULL 
                               | (QData)((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fb)));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem = 0ULL;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q = 0ULL;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (QData)((IData)((1U & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x3fU)))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x8000000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x3eU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x4000000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x3dU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x2000000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x3cU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x1000000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x3bU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0800000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x3aU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0400000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x39U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0200000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x38U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0100000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x37U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0080000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x36U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0040000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x35U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0020000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x34U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0010000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x33U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0008000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x32U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0004000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x31U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0002000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x30U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0001000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x2fU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000800000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x2eU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000400000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x2dU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000200000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x2cU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000100000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x2bU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000080000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x2aU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000040000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x29U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000020000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x28U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000010000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x27U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000008000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x26U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000004000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x25U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000002000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x24U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000001000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x23U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000800000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x22U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000400000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x21U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000200000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x20U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000100000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x1fU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000080000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x1eU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000040000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x1dU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000020000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x1cU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000010000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x1bU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000008000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x1aU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000004000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x19U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000002000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x18U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000001000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x17U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000000800000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x16U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000000400000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x15U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000000200000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x14U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000000100000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x13U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000000080000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x12U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000000040000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x11U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000000020000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x10U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000000010000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x0fU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000000008000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x0eU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000000004000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x0dU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000000002000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x0cU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000000001000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x0bU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000000000800ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 0x0aU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000000000400ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 9U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000000000200ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 8U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000000000100ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 7U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000000000080ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 6U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000000000040ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 5U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000000000020ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 4U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (0x0000000000000010ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 3U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (8ULL | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 2U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (4ULL | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num 
                                                             >> 1U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (2ULL | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__num)))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                = (1ULL | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q);
                        }
                        if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                           >> 0x1aU)))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__f24 
                                = (0x00ffffffU & (IData)(
                                                         (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                                          >> 3U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__g 
                                = (1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                                 >> 2U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__s 
                                = (IData)(((0ULL != 
                                            (3ULL & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q)) 
                                           | (0ULL 
                                              != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__e9 
                                = (0x000007ffU & ((IData)(0x007fU) 
                                                  + 
                                                  ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__ea) 
                                                   - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__eb))));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__f24 
                                = (0x00ffffffU & (IData)(
                                                         (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                                          >> 2U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__g 
                                = (1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q 
                                                 >> 1U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__s 
                                = (1U & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__q) 
                                         | (0ULL != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__rem)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__e9 
                                = (0x000007ffU & ((IData)(0x007eU) 
                                                  + 
                                                  ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__ea) 
                                                   - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__eb))));
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fr 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__f24);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__inc 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__g) 
                               & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__s) 
                                  | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fr));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__inc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fc 
                                = (0x007fffffU == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fr);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fr 
                                = (0x007fffffU & ((IData)(1U) 
                                                  + __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fr));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fc = 0U;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__e9 
                                = (0x000007ffU & ((IData)(1U) 
                                                  + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__e9)));
                        }
                        if ((0x0200U <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel7;
                        }
                        if ((0x00ffU <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel7;
                        }
                        if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel7;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__Vfuncout 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sg) 
                                << 0x0000001fU) | (
                                                   (0x7f800000U 
                                                    & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__e9) 
                                                       << 0x00000017U)) 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fr));
                        __Vlabel7: ;
                    }
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__30__Vfuncout 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__Vfuncout;
                }
                vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[0U] 
                    = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__30__Vfuncout;
            } else {
                vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U] 
                    = ((0x00000078U & vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U]) 
                       | (7U & ((IData)(1U) + vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U])));
            }
        }
    } else {
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[0U] = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[1U] = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[2U] = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U] = 0U;
    }
    if (vlSelfRef.rst_n) {
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U] 
            = (0x0000005fU & vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U]);
        if (((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__f_go) 
             & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__f_lane_en))) {
            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U] 
                = (0x00000040U | vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U]);
            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[1U] 
                = vlSelfRef.ember_top__DOT__u_core__DOT__f_b0;
            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[2U] 
                = (IData)((QData)((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__f_a0)));
            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U] 
                = ((0x00000060U & vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U]) 
                   | (0x0000007fU & ((0x00000018U & 
                                      ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__f_op) 
                                       << 3U)) | (IData)(
                                                         ((QData)((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__f_a0)) 
                                                          >> 0x00000020U)))));
            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[0U] = 0U;
        } else if ((0x00000040U & vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U])) {
            if ((4U == (7U & vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U]))) {
                vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U] 
                    = (0x00000020U | (0x0000001fU & vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U]));
                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__9__bv 
                    = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[1U];
                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__9__av 
                    = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[2U];
                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__9__opc 
                    = (3U & (vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U] 
                             >> 3U));
                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__9__Vfuncout = 0;
                if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__9__opc))) {
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sub_op = 0U;
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__bv 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__9__bv;
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__av 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__9__av;
                    {
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__Vfuncout = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sbs = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__big_a = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sign_r = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__ea = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__eb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__big_e = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__delta = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fr = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__a_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__b_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__a_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__b_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__a_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__b_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fa_w = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fb_w = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__norm = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fsum = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__top = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sh_l = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__e9 = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__g = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__s = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__inc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sa 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__av 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__ea 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__av 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fa 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__av);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sb 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__bv 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__eb 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__bv 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fb 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__bv);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sbs 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sb) 
                               ^ (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sub_op));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__a_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__ea)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__b_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__eb)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__a_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__b_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__a_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__b_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fb));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__a_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__av;
                            goto __Vlabel8;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__b_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__bv;
                            goto __Vlabel8;
                        }
                        if ((((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__a_inf) 
                              & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__b_inf)) 
                             & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sa) 
                                != (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sbs)))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__Vfuncout = 0x7fc00000U;
                            goto __Vlabel8;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__a_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__av;
                            goto __Vlabel8;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__b_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sbs) 
                                                  << 0x0000001fU));
                            goto __Vlabel8;
                        }
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__a_z) 
                             & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__b_z))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__Vfuncout = 0U;
                            goto __Vlabel8;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__a_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__Vfuncout 
                                = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sbs) 
                                    << 0x0000001fU) 
                                   | (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__eb) 
                                       << 0x00000017U) 
                                      | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fb));
                            goto __Vlabel8;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__b_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__av;
                            goto __Vlabel8;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__big_a 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__ea) 
                                > (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__eb)) 
                               | (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__ea) 
                                   == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__eb)) 
                                  & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fa 
                                     >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fb)));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__big_a) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__big_e 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__ea;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__delta 
                                = (0x000000ffU & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__ea) 
                                                  - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__eb)));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__big_e 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__eb;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__delta 
                                = (0x000000ffU & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__eb) 
                                                  - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__ea)));
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fa_w 
                            = (0x0000000200000000ULL 
                               | ((QData)((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fa)) 
                                  << 0x0000000aU));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fb_w 
                            = (0x0000000200000000ULL 
                               | ((QData)((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fb)) 
                                  << 0x0000000aU));
                        if ((0U != (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__delta))) {
                            if ((0x22U <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__delta))) {
                                if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__big_a) {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fb_w = 1ULL;
                                } else {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fa_w = 1ULL;
                                }
                            } else {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sh_l 
                                    = (0x0000ffffU 
                                       & ((IData)(0x0022U) 
                                          - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__delta)));
                                if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__big_a) {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fb_w 
                                        = (VL_SHIFTR_QQI(34,34,8, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fb_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__delta)) 
                                           | (QData)((IData)(
                                                             (0U 
                                                              != 
                                                              (0x00000003ffffffffULL 
                                                               & VL_SHIFTL_QQI(34,34,16, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fb_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sh_l)))))));
                                } else {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fa_w 
                                        = (VL_SHIFTR_QQI(34,34,8, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fa_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__delta)) 
                                           | (QData)((IData)(
                                                             (0U 
                                                              != 
                                                              (0x00000003ffffffffULL 
                                                               & VL_SHIFTL_QQI(34,34,16, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fa_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sh_l)))))));
                                }
                            }
                        }
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sa) 
                             == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sbs))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fsum 
                                = (0x00000007ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fa_w 
                                      + __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fb_w));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sign_r 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sa;
                        } else if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__big_a) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fsum 
                                = (0x00000007ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fa_w 
                                      - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fb_w));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sign_r 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sa;
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fsum 
                                = (0x00000007ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fb_w 
                                      - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fa_w));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sign_r 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sbs;
                        }
                        if ((0ULL == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fsum)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__Vfuncout = 0U;
                            goto __Vlabel8;
                        }
                        if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fsum 
                                           >> 0x22U)))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__norm 
                                = (0x00000003ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fsum 
                                      >> 1U));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__e9 
                                = (0x000007ffU & ((IData)(1U) 
                                                  + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__big_e)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__s 
                                = (1U & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fsum) 
                                         | (0U != (0x000001ffU 
                                                   & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__norm)))));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                = (0x00000003ffffffffULL 
                                   & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fsum);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__Vfuncout = 0;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 0;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 0U;
                            if ((1U & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 0U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 1U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 1U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 2U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 2U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 3U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 3U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 4U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 4U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 5U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 5U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 6U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 6U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 7U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 7U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 8U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 8U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 9U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 9U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 0x0aU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 0x0aU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 0x0bU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 0x0bU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 0x0cU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 0x0cU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 0x0dU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 0x0dU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 0x0eU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 0x0eU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 0x0fU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 0x0fU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 0x10U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 0x10U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 0x11U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 0x11U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 0x12U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 0x12U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 0x13U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 0x13U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 0x14U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 0x14U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 0x15U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 0x15U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 0x16U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 0x16U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 0x17U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 0x17U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 0x18U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 0x18U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 0x19U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 0x19U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 0x1aU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 0x1aU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 0x1bU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 0x1bU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 0x1cU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 0x1cU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 0x1dU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 0x1dU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 0x1eU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 0x1eU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 0x1fU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 0x1fU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 0x20U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 0x20U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__v 
                                               >> 0x21U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r = 0x21U;
                            }
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__r;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__top 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__11__Vfuncout;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__norm 
                                = (0x00000003ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fsum 
                                      << (0x0000003fU 
                                          & ((IData)(0x21U) 
                                             - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__top)))));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__e9 
                                = (0x000007ffU & (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__big_e) 
                                                   + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__top)) 
                                                  - (IData)(0x0021U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__s 
                                = (0U != (0x000001ffU 
                                          & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__norm)));
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fr 
                            = (0x007fffffU & (IData)(
                                                     (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__norm 
                                                      >> 0x0aU)));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__g 
                            = (1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__norm 
                                             >> 9U)));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__inc 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__g) 
                               & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__s) 
                                  | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fr));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__inc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fc 
                                = (0x007fffffU == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fr);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fr 
                                = (0x007fffffU & ((IData)(1U) 
                                                  + __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fr));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fc = 0U;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__e9 
                                = (0x000007ffU & ((IData)(1U) 
                                                  + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__e9)));
                        }
                        if ((0x0200U <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sign_r) 
                                   << 0x0000001fU);
                            goto __Vlabel8;
                        }
                        if ((0x00ffU <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sign_r) 
                                                  << 0x0000001fU));
                            goto __Vlabel8;
                        }
                        if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sign_r) 
                                   << 0x0000001fU);
                            goto __Vlabel8;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__Vfuncout 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sign_r) 
                                << 0x0000001fU) | (
                                                   (0x7f800000U 
                                                    & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__e9) 
                                                       << 0x00000017U)) 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fr));
                        __Vlabel8: ;
                    }
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__9__Vfuncout 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__Vfuncout;
                } else if ((1U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__9__opc))) {
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sub_op = 1U;
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__bv 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__9__bv;
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__av 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__9__av;
                    {
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__Vfuncout = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sbs = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__big_a = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sign_r = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__ea = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__eb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__big_e = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__delta = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fr = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__a_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__b_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__a_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__b_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__a_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__b_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fa_w = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fb_w = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__norm = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fsum = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__top = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sh_l = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__e9 = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__g = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__s = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__inc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sa 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__av 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__ea 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__av 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fa 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__av);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sb 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__bv 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__eb 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__bv 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fb 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__bv);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sbs 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sb) 
                               ^ (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sub_op));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__a_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__ea)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__b_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__eb)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__a_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__b_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__a_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__b_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fb));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__a_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__av;
                            goto __Vlabel9;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__b_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__bv;
                            goto __Vlabel9;
                        }
                        if ((((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__a_inf) 
                              & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__b_inf)) 
                             & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sa) 
                                != (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sbs)))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__Vfuncout = 0x7fc00000U;
                            goto __Vlabel9;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__a_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__av;
                            goto __Vlabel9;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__b_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sbs) 
                                                  << 0x0000001fU));
                            goto __Vlabel9;
                        }
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__a_z) 
                             & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__b_z))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__Vfuncout = 0U;
                            goto __Vlabel9;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__a_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__Vfuncout 
                                = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sbs) 
                                    << 0x0000001fU) 
                                   | (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__eb) 
                                       << 0x00000017U) 
                                      | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fb));
                            goto __Vlabel9;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__b_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__av;
                            goto __Vlabel9;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__big_a 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__ea) 
                                > (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__eb)) 
                               | (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__ea) 
                                   == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__eb)) 
                                  & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fa 
                                     >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fb)));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__big_a) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__big_e 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__ea;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__delta 
                                = (0x000000ffU & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__ea) 
                                                  - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__eb)));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__big_e 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__eb;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__delta 
                                = (0x000000ffU & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__eb) 
                                                  - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__ea)));
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fa_w 
                            = (0x0000000200000000ULL 
                               | ((QData)((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fa)) 
                                  << 0x0000000aU));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fb_w 
                            = (0x0000000200000000ULL 
                               | ((QData)((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fb)) 
                                  << 0x0000000aU));
                        if ((0U != (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__delta))) {
                            if ((0x22U <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__delta))) {
                                if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__big_a) {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fb_w = 1ULL;
                                } else {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fa_w = 1ULL;
                                }
                            } else {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sh_l 
                                    = (0x0000ffffU 
                                       & ((IData)(0x0022U) 
                                          - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__delta)));
                                if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__big_a) {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fb_w 
                                        = (VL_SHIFTR_QQI(34,34,8, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fb_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__delta)) 
                                           | (QData)((IData)(
                                                             (0U 
                                                              != 
                                                              (0x00000003ffffffffULL 
                                                               & VL_SHIFTL_QQI(34,34,16, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fb_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sh_l)))))));
                                } else {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fa_w 
                                        = (VL_SHIFTR_QQI(34,34,8, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fa_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__delta)) 
                                           | (QData)((IData)(
                                                             (0U 
                                                              != 
                                                              (0x00000003ffffffffULL 
                                                               & VL_SHIFTL_QQI(34,34,16, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fa_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sh_l)))))));
                                }
                            }
                        }
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sa) 
                             == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sbs))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fsum 
                                = (0x00000007ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fa_w 
                                      + __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fb_w));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sign_r 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sa;
                        } else if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__big_a) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fsum 
                                = (0x00000007ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fa_w 
                                      - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fb_w));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sign_r 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sa;
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fsum 
                                = (0x00000007ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fb_w 
                                      - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fa_w));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sign_r 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sbs;
                        }
                        if ((0ULL == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fsum)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__Vfuncout = 0U;
                            goto __Vlabel9;
                        }
                        if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fsum 
                                           >> 0x22U)))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__norm 
                                = (0x00000003ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fsum 
                                      >> 1U));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__e9 
                                = (0x000007ffU & ((IData)(1U) 
                                                  + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__big_e)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__s 
                                = (1U & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fsum) 
                                         | (0U != (0x000001ffU 
                                                   & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__norm)))));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                = (0x00000003ffffffffULL 
                                   & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fsum);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__Vfuncout = 0;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 0;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 0U;
                            if ((1U & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 0U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 1U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 1U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 2U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 2U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 3U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 3U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 4U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 4U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 5U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 5U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 6U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 6U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 7U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 7U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 8U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 8U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 9U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 9U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 0x0aU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 0x0aU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 0x0bU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 0x0bU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 0x0cU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 0x0cU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 0x0dU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 0x0dU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 0x0eU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 0x0eU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 0x0fU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 0x0fU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 0x10U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 0x10U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 0x11U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 0x11U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 0x12U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 0x12U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 0x13U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 0x13U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 0x14U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 0x14U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 0x15U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 0x15U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 0x16U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 0x16U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 0x17U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 0x17U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 0x18U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 0x18U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 0x19U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 0x19U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 0x1aU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 0x1aU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 0x1bU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 0x1bU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 0x1cU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 0x1cU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 0x1dU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 0x1dU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 0x1eU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 0x1eU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 0x1fU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 0x1fU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 0x20U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 0x20U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__v 
                                               >> 0x21U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r = 0x21U;
                            }
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__r;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__top 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__13__Vfuncout;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__norm 
                                = (0x00000003ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fsum 
                                      << (0x0000003fU 
                                          & ((IData)(0x21U) 
                                             - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__top)))));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__e9 
                                = (0x000007ffU & (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__big_e) 
                                                   + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__top)) 
                                                  - (IData)(0x0021U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__s 
                                = (0U != (0x000001ffU 
                                          & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__norm)));
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fr 
                            = (0x007fffffU & (IData)(
                                                     (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__norm 
                                                      >> 0x0aU)));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__g 
                            = (1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__norm 
                                             >> 9U)));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__inc 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__g) 
                               & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__s) 
                                  | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fr));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__inc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fc 
                                = (0x007fffffU == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fr);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fr 
                                = (0x007fffffU & ((IData)(1U) 
                                                  + __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fr));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fc = 0U;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__e9 
                                = (0x000007ffU & ((IData)(1U) 
                                                  + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__e9)));
                        }
                        if ((0x0200U <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sign_r) 
                                   << 0x0000001fU);
                            goto __Vlabel9;
                        }
                        if ((0x00ffU <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sign_r) 
                                                  << 0x0000001fU));
                            goto __Vlabel9;
                        }
                        if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sign_r) 
                                   << 0x0000001fU);
                            goto __Vlabel9;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__Vfuncout 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sign_r) 
                                << 0x0000001fU) | (
                                                   (0x7f800000U 
                                                    & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__e9) 
                                                       << 0x00000017U)) 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fr));
                        __Vlabel9: ;
                    }
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__9__Vfuncout 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__Vfuncout;
                } else if ((2U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__9__opc))) {
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__bv 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__9__bv;
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__av 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__9__av;
                    {
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__Vfuncout = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__sa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__sb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__sg = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__ea = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__eb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fr = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__a_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__b_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__a_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__b_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__a_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__b_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__prod = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__f24 = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__e9 = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__g = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__s = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__inc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__sa 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__av 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__ea 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__av 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fa 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__av);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__sb 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__bv 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__eb 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__bv 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fb 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__bv);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__a_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__ea)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__b_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__eb)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__a_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__b_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__a_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__b_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fb));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__a_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__av;
                            goto __Vlabel10;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__b_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__bv;
                            goto __Vlabel10;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__sg 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__sa) 
                               ^ (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__sb));
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__a_inf) 
                             | (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__b_inf))) {
                            if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__a_z) 
                                 | (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__b_z))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__Vfuncout 
                                    = (0x7fc00000U 
                                       | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__sg) 
                                          << 0x0000001fU));
                                goto __Vlabel10;
                            }
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel10;
                        }
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__a_z) 
                             | (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__b_z))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel10;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__prod 
                            = (0x0000ffffffffffffULL 
                               & ((QData)((IData)((0x00800000U 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fa))) 
                                  * (QData)((IData)(
                                                    (0x00800000U 
                                                     | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fb)))));
                        if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__prod 
                                           >> 0x2fU)))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__f24 
                                = (0x00ffffffU & (IData)(
                                                         (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__prod 
                                                          >> 0x00000018U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__g 
                                = (1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__prod 
                                                 >> 0x17U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__s 
                                = (0U != (0x007fffffU 
                                          & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__prod)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__e9 
                                = (0x000007ffU & (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__ea) 
                                                   + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__eb)) 
                                                  - (IData)(0x007eU)));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__f24 
                                = (0x00ffffffU & (IData)(
                                                         (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__prod 
                                                          >> 0x00000017U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__g 
                                = (1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__prod 
                                                 >> 0x16U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__s 
                                = (0U != (0x003fffffU 
                                          & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__prod)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__e9 
                                = (0x000007ffU & (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__ea) 
                                                   + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__eb)) 
                                                  - (IData)(0x007fU)));
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fr 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__f24);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__inc 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__g) 
                               & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__s) 
                                  | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fr));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__inc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fc 
                                = (0x007fffffU == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fr);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fr 
                                = (0x007fffffU & ((IData)(1U) 
                                                  + __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fr));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fc = 0U;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__e9 
                                = (0x000007ffU & ((IData)(1U) 
                                                  + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__e9)));
                        }
                        if ((0x0200U <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel10;
                        }
                        if ((0x00ffU <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel10;
                        }
                        if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel10;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__Vfuncout 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__sg) 
                                << 0x0000001fU) | (
                                                   (0x7f800000U 
                                                    & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__e9) 
                                                       << 0x00000017U)) 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fr));
                        __Vlabel10: ;
                    }
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__9__Vfuncout 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__Vfuncout;
                } else {
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__bv 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__9__bv;
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__av 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__9__av;
                    {
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__Vfuncout = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sg = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__ea = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__eb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fr = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__a_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__b_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__a_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__b_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__a_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__b_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__f24 = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__e9 = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__g = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__s = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__inc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sa 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__av 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__ea 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__av 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fa 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__av);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sb 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__bv 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__eb 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__bv 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fb 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__bv);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__a_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__ea)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__b_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__eb)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__a_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__b_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__a_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__b_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fb));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__a_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__av;
                            goto __Vlabel11;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__b_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__bv;
                            goto __Vlabel11;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sg 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sa) 
                               ^ (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sb));
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__a_inf) 
                             & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__b_inf))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__Vfuncout = 0x7fc00000U;
                            goto __Vlabel11;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__a_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel11;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__b_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel11;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__b_z) {
                            if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__a_z) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__Vfuncout = 0x7fc00000U;
                                goto __Vlabel11;
                            }
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel11;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__a_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel11;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                            = (0x0002000000000000ULL 
                               | ((QData)((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fa)) 
                                  << 0x0000001aU));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den 
                            = (0x0000000000800000ULL 
                               | (QData)((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fb)));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem = 0ULL;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q = 0ULL;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (QData)((IData)((1U & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x3fU)))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x8000000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x3eU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x4000000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x3dU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x2000000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x3cU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x1000000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x3bU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0800000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x3aU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0400000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x39U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0200000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x38U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0100000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x37U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0080000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x36U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0040000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x35U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0020000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x34U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0010000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x33U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0008000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x32U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0004000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x31U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0002000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x30U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0001000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x2fU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000800000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x2eU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000400000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x2dU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000200000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x2cU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000100000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x2bU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000080000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x2aU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000040000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x29U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000020000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x28U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000010000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x27U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000008000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x26U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000004000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x25U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000002000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x24U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000001000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x23U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000800000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x22U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000400000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x21U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000200000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x20U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000100000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x1fU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000080000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x1eU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000040000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x1dU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000020000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x1cU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000010000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x1bU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000008000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x1aU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000004000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x19U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000002000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x18U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000001000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x17U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000000800000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x16U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000000400000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x15U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000000200000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x14U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000000100000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x13U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000000080000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x12U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000000040000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x11U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000000020000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x10U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000000010000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x0fU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000000008000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x0eU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000000004000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x0dU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000000002000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x0cU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000000001000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x0bU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000000000800ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 0x0aU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000000000400ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 9U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000000000200ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 8U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000000000100ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 7U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000000000080ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 6U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000000000040ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 5U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000000000020ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 4U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (0x0000000000000010ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 3U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (8ULL | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 2U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (4ULL | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num 
                                                             >> 1U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (2ULL | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__num)))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                = (1ULL | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q);
                        }
                        if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                           >> 0x1aU)))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__f24 
                                = (0x00ffffffU & (IData)(
                                                         (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                                          >> 3U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__g 
                                = (1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                                 >> 2U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__s 
                                = (IData)(((0ULL != 
                                            (3ULL & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q)) 
                                           | (0ULL 
                                              != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__e9 
                                = (0x000007ffU & ((IData)(0x007fU) 
                                                  + 
                                                  ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__ea) 
                                                   - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__eb))));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__f24 
                                = (0x00ffffffU & (IData)(
                                                         (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                                          >> 2U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__g 
                                = (1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q 
                                                 >> 1U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__s 
                                = (1U & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__q) 
                                         | (0ULL != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__rem)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__e9 
                                = (0x000007ffU & ((IData)(0x007eU) 
                                                  + 
                                                  ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__ea) 
                                                   - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__eb))));
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fr 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__f24);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__inc 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__g) 
                               & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__s) 
                                  | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fr));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__inc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fc 
                                = (0x007fffffU == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fr);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fr 
                                = (0x007fffffU & ((IData)(1U) 
                                                  + __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fr));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fc = 0U;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__e9 
                                = (0x000007ffU & ((IData)(1U) 
                                                  + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__e9)));
                        }
                        if ((0x0200U <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel11;
                        }
                        if ((0x00ffU <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel11;
                        }
                        if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel11;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__Vfuncout 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sg) 
                                << 0x0000001fU) | (
                                                   (0x7f800000U 
                                                    & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__e9) 
                                                       << 0x00000017U)) 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fr));
                        __Vlabel11: ;
                    }
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__9__Vfuncout 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__Vfuncout;
                }
                vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[0U] 
                    = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__9__Vfuncout;
            } else {
                vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U] 
                    = ((0x00000078U & vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U]) 
                       | (7U & ((IData)(1U) + vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U])));
            }
        }
    } else {
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[0U] = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[1U] = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[2U] = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U] = 0U;
    }
    if (vlSelfRef.rst_n) {
        if (vlSelfRef.ember_top__DOT__u_vram__DOT__wr_fire) {
            vlSelfRef.ember_top__DOT__v_b = 0U;
        }
        if (vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__wr_fire) {
            vlSelfRef.ember_top__DOT__c_b = 0U;
        }
        if (((IData)(vlSelfRef.ember_top__DOT__v_awvalid) 
             & (IData)(vlSelfRef.ember_top__DOT__v_awready))) {
            vlSelfRef.ember_top__DOT__u_vram__DOT__aw_v = 1U;
        } else if (vlSelfRef.ember_top__DOT__u_vram__DOT__wr_fire) {
            vlSelfRef.ember_top__DOT__u_vram__DOT__aw_v = 0U;
        }
        if (((IData)(vlSelfRef.ember_top__DOT__v_wvalid) 
             & (IData)(vlSelfRef.ember_top__DOT__v_wready))) {
            vlSelfRef.ember_top__DOT__u_vram__DOT__w_v = 1U;
        } else if (vlSelfRef.ember_top__DOT__u_vram__DOT__wr_fire) {
            vlSelfRef.ember_top__DOT__u_vram__DOT__w_v = 0U;
        }
        if (((IData)(vlSelfRef.ember_top__DOT__c_awvalid) 
             & (IData)(vlSelfRef.ember_top__DOT__c_awready))) {
            vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__aw_v = 1U;
        } else if (vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__wr_fire) {
            vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__aw_v = 0U;
        }
        if (((IData)(vlSelfRef.ember_top__DOT__c_wvalid) 
             & (IData)(vlSelfRef.ember_top__DOT__c_wready))) {
            vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__w_v = 1U;
        } else if (vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__wr_fire) {
            vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__w_v = 0U;
        }
        if (vlSelfRef.ember_top__DOT__blit_csr_we) {
            if ((1U & (~ ((IData)(vlSelfRef.ember_top__DOT__blit_csr_addr) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelfRef.ember_top__DOT__blit_csr_addr)))) {
                    vlSelfRef.ember_top__DOT__u_blit__DOT__key_en_q 
                        = (1U & (vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata 
                                 >> 0x1dU));
                    vlSelfRef.ember_top__DOT__u_blit__DOT__key_color_q 
                        = (0x0000ffffU & vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata);
                }
                if ((1U & (IData)(vlSelfRef.ember_top__DOT__blit_csr_addr))) {
                    vlSelfRef.ember_top__DOT__u_blit__DOT__dst_off_q 
                        = vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata;
                }
            }
        }
        vlSelfRef.ember_top__DOT__u_disp__DOT__word_q2 
            = vlSelfRef.ember_top__DOT__u_disp__DOT__word_q1;
        vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__fetch_req = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__scan_start = 0U;
        if ((4U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__fst))) {
            if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__fst))) {
                vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__fst = 0U;
            } else if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__fst))) {
                vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__cursor 
                    = ((IData)(0x0000004cU) + vlSelfRef.ember_top__DOT__u_rtr__DOT__cursor);
                vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__fidx = 0U;
                vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__fetch_req = 1U;
                vlSelfRef.ember_top__DOT__u_rtr__DOT__fetch_addr 
                    = ((IData)(0x0000004cU) + vlSelfRef.ember_top__DOT__u_rtr__DOT__cursor);
                vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__fst = 1U;
            } else if (vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_done) {
                vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__fst = 5U;
            }
        } else if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__fst))) {
            if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__fst))) {
                __Vtemp_7[0U] = 0U;
                __Vtemp_7[1U] = 0U;
                __Vtemp_7[2U] = 0U;
                if (VL_GTES_IWW(67, __Vtemp_7, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__area)) {
                    vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__fst = 5U;
                } else {
                    vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__scan_start = 1U;
                    vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__fst = 4U;
                }
            } else {
                vlSelfRef.ember_top__DOT__u_rtr__DOT____Vlvbound_hcfa37505__0 
                    = vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_rdata_q;
                if ((0x12U >= (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__fidx))) {
                    vlSelfRef.__VdlyVal__ember_top__DOT__u_rtr__DOT__cmd_q__v0 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT____Vlvbound_hcfa37505__0;
                    vlSelfRef.__VdlyDim0__ember_top__DOT__u_rtr__DOT__cmd_q__v0 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__fidx;
                    vlSelfRef.__VdlySet__ember_top__DOT__u_rtr__DOT__cmd_q__v0 = 1U;
                }
                if (((0U == (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__fidx)) 
                     & (~ vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_rdata_q))) {
                    vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__fst = 0U;
                } else if ((0x12U == (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__fidx))) {
                    vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__fst = 3U;
                } else {
                    vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__fidx 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__fidx)));
                    vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__fetch_req = 1U;
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__fetch_addr 
                        = ((IData)(4U) + (vlSelfRef.ember_top__DOT__u_rtr__DOT__cursor 
                                          + ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__fidx) 
                                             << 2U)));
                    vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__fst = 1U;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__fst))) {
            vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__fst = 2U;
        } else if (((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_0) 
                    & ((0x0020U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
                       & vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata))) {
            vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__cursor = 0x0005c000U;
            vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__fidx = 0U;
            vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__fetch_req = 1U;
            vlSelfRef.ember_top__DOT__u_rtr__DOT__fetch_addr = 0x0005c000U;
            vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__fst = 1U;
        }
        vlSelfRef.ember_top__DOT__u_disp__DOT__word_q1 
            = vlSelfRef.ember_top__DOT__u_vram__DOT__fpa3_rdata_q;
    } else {
        vlSelfRef.ember_top__DOT__v_b = 0U;
        vlSelfRef.ember_top__DOT__c_b = 0U;
        vlSelfRef.ember_top__DOT__u_vram__DOT__aw_v = 0U;
        vlSelfRef.ember_top__DOT__u_vram__DOT__w_v = 0U;
        vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__aw_v = 0U;
        vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__w_v = 0U;
        vlSelfRef.ember_top__DOT__u_blit__DOT__key_en_q = 0U;
        vlSelfRef.ember_top__DOT__u_blit__DOT__key_color_q = 0U;
        vlSelfRef.ember_top__DOT__u_blit__DOT__dst_off_q = 0U;
        vlSelfRef.ember_top__DOT__u_disp__DOT__word_q2 = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__fst = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__cursor = 0x0005c000U;
        vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__fidx = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__fetch_req = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__scan_start = 0U;
        vlSelfRef.ember_top__DOT__u_disp__DOT__word_q1 = 0U;
    }
    vlSelfRef.ember_top__DOT__u_disp__DOT__vs_d4 = 
        ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.ember_top__DOT__u_disp__DOT__vs_d3));
    vlSelfRef.ember_top__DOT__u_disp__DOT__hs_d4 = 
        ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.ember_top__DOT__u_disp__DOT__hs_d3));
    vlSelfRef.ember_top__DOT__u_disp__DOT__odd_d4 = 
        ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.ember_top__DOT__u_disp__DOT__odd_d3));
    vlSelfRef.ember_top__DOT__u_disp__DOT__de_d4 = 
        ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.ember_top__DOT__u_disp__DOT__de_d3));
    vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__ar_v 
        = vlSelfRef.__Vdly__ember_top__DOT__u_cp__DOT__u_regs__DOT__ar_v;
    vlSelfRef.ember_top__DOT__c_bvalid = vlSelfRef.__Vdly__ember_top__DOT__c_bvalid;
    vlSelfRef.ember_top__DOT__u_vram__DOT__ar_v = vlSelfRef.__Vdly__ember_top__DOT__u_vram__DOT__ar_v;
    vlSelfRef.ember_top__DOT__v_bvalid = vlSelfRef.__Vdly__ember_top__DOT__v_bvalid;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__cursor = vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__cursor;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__fidx = vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__fidx;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__fst = vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__fst;
    if ((1U == (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__rstate))) {
        vlSelfRef.h_rvalid = vlSelfRef.ember_top__DOT__u_vram__DOT__ar_v;
        vlSelfRef.ember_top__DOT__v_rready = vlSelfRef.h_rready;
    } else {
        vlSelfRef.h_rvalid = vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__ar_v;
        vlSelfRef.ember_top__DOT__v_rready = (2U == (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__rstate));
    }
    vlSelfRef.ember_top__DOT__c_rready = ((1U != (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__rstate)) 
                                          & (IData)(vlSelfRef.h_rready));
    if ((1U == (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__wstate))) {
        vlSelfRef.h_bvalid = vlSelfRef.ember_top__DOT__v_bvalid;
        vlSelfRef.ember_top__DOT__v_bready = vlSelfRef.h_bready;
        vlSelfRef.h_bresp = vlSelfRef.ember_top__DOT__v_b;
    } else {
        vlSelfRef.h_bvalid = vlSelfRef.ember_top__DOT__c_bvalid;
        vlSelfRef.ember_top__DOT__v_bready = (2U == (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__wstate));
        vlSelfRef.h_bresp = vlSelfRef.ember_top__DOT__c_b;
    }
    vlSelfRef.ember_top__DOT__c_bready = ((1U != (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__wstate)) 
                                          & (IData)(vlSelfRef.h_bready));
    if ((1U & (~ (IData)(vlSelfRef.rst_n)))) {
        vlSelfRef.ember_top__DOT__u_core__DOT__f_a1 = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__f_b1 = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__f_a2 = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__f_b2 = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__f_a3 = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__f_b3 = 0U;
    }
    vlSelfRef.vid_vs = vlSelfRef.ember_top__DOT__u_disp__DOT__vs_d4;
    vlSelfRef.ember_top__DOT__u_disp__DOT__vs_d3 = 
        ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.ember_top__DOT__u_disp__DOT__vs_d2));
    vlSelfRef.vid_hs = vlSelfRef.ember_top__DOT__u_disp__DOT__hs_d4;
    vlSelfRef.ember_top__DOT__u_disp__DOT__hs_d3 = 
        ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.ember_top__DOT__u_disp__DOT__hs_d2));
    vlSelfRef.ember_top__DOT__u_disp__DOT__odd_d3 = 
        ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.ember_top__DOT__u_disp__DOT__odd_d2));
    vlSelfRef.vid_de = vlSelfRef.ember_top__DOT__u_disp__DOT__de_d4;
    vlSelfRef.ember_top__DOT__u_disp__DOT__de_d3 = 
        ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.ember_top__DOT__u_disp__DOT__de_d2));
    vlSelfRef.vid_pixel = ((IData)(vlSelfRef.ember_top__DOT__u_disp__DOT__de_d4)
                            ? (0x0000ffffU & ((IData)(vlSelfRef.ember_top__DOT__u_disp__DOT__odd_d4)
                                               ? (vlSelfRef.ember_top__DOT__u_disp__DOT__word_q2 
                                                  >> 0x00000010U)
                                               : vlSelfRef.ember_top__DOT__u_disp__DOT__word_q2))
                            : 0U);
    vlSelfRef.ember_top__DOT__c_arready = (1U & ((~ (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__ar_v)) 
                                                 | ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__ar_v) 
                                                    & (IData)(vlSelfRef.ember_top__DOT__c_rready))));
    vlSelfRef.ember_top__DOT__u_disp__DOT__vs_d2 = 
        ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.ember_top__DOT__u_disp__DOT__vs_d1));
    vlSelfRef.ember_top__DOT__u_disp__DOT__hs_d2 = 
        ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.ember_top__DOT__u_disp__DOT__hs_d1));
    vlSelfRef.ember_top__DOT__u_disp__DOT__odd_d2 = 
        ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.ember_top__DOT__u_disp__DOT__odd_d1));
    vlSelfRef.ember_top__DOT__u_disp__DOT__de_d2 = 
        ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.ember_top__DOT__u_disp__DOT__de_d1));
    vlSelfRef.ember_top__DOT__u_disp__DOT__vs_d1 = 
        ((IData)(vlSelfRef.rst_n) && ((0x01eaU <= (IData)(vlSelfRef.ember_top__DOT__u_disp__DOT__vcnt)) 
                                      & (0x01ecU > (IData)(vlSelfRef.ember_top__DOT__u_disp__DOT__vcnt))));
    vlSelfRef.ember_top__DOT__u_disp__DOT__hs_d1 = 
        ((IData)(vlSelfRef.rst_n) && ((0x0290U <= (IData)(vlSelfRef.ember_top__DOT__u_disp__DOT__hcnt)) 
                                      & (0x02f0U > (IData)(vlSelfRef.ember_top__DOT__u_disp__DOT__hcnt))));
    vlSelfRef.ember_top__DOT__u_disp__DOT__odd_d1 = 
        ((IData)(vlSelfRef.rst_n) && (1U & ((IData)(vlSelfRef.ember_top__DOT__u_disp__DOT__hcnt) 
                                            >> 1U)));
    vlSelfRef.ember_top__DOT__u_disp__DOT__de_d1 = 
        ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.ember_top__DOT__u_disp__DOT__de_now));
}

void Vember_top___024root___nba_sequent__TOP__2(Vember_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vember_top___024root___nba_sequent__TOP__2\n"); );
    Vember_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*16:0*/ __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__121__Vfuncout;
    __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__121__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__121__a;
    __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__121__a = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__121__off;
    __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__121__off = 0;
    IData/*16:0*/ __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__122__Vfuncout;
    __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__122__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__122__a;
    __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__122__a = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__122__off;
    __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__122__off = 0;
    IData/*16:0*/ __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__123__Vfuncout;
    __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__123__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__123__a;
    __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__123__a = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__123__off;
    __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__123__off = 0;
    IData/*16:0*/ __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__124__Vfuncout;
    __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__124__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__124__a;
    __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__124__a = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__124__off;
    __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__124__off = 0;
    IData/*16:0*/ __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__132__Vfuncout;
    __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__132__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__132__a;
    __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__132__a = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__132__off;
    __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__132__off = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v0;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v0 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v0;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v0 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v1;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v1 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v2;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v2 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v3;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v3 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v4;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v4 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v5;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v5 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v6;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v6 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v7;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v7 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v8;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v8 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v9;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v9 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v10;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v10 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v11;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v11 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v12;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v12 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v13;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v13 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v14;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v14 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v15;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v15 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v16;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v16 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v16;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v16 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v17;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v17 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v18;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v18 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v19;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v19 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v20;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v20 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v21;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v21 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v22;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v22 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v23;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v23 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v24;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v24 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v25;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v25 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v26;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v26 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v27;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v27 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v28;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v28 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v29;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v29 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v30;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v30 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v31;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v31 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v32;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v32 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v32;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v32 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v33;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v33 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v34;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v34 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v35;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v35 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v36;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v36 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v37;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v37 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v38;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v38 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v39;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v39 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v40;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v40 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v41;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v41 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v42;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v42 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v43;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v43 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v44;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v44 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v45;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v45 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v46;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v46 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v47;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v47 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v48;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v48 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v48;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v48 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v49;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v49 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v50;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v50 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v51;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v51 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v52;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v52 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v53;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v53 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v54;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v54 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v55;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v55 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v56;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v56 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v57;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v57 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v58;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v58 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v59;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v59 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v60;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v60 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v61;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v61 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v62;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v62 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v63;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v63 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v64;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v64 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v64;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v64 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v65;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v65 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v66;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v66 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v67;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v67 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v68;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v68 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v69;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v69 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v70;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v70 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v71;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v71 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v72;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v72 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v73;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v73 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v74;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v74 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v75;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v75 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v76;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v76 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v77;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v77 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v78;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v78 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v79;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v79 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v80;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v80 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v80;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v80 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v81;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v81 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v82;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v82 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v83;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v83 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v84;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v84 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v85;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v85 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v86;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v86 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v87;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v87 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v88;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v88 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v89;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v89 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v90;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v90 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v91;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v91 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v92;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v92 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v93;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v93 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v94;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v94 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v95;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v95 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v96;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v96 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v96;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v96 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v97;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v97 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v98;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v98 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v99;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v99 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v100;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v100 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v101;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v101 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v102;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v102 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v103;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v103 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v104;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v104 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v105;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v105 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v106;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v106 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v107;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v107 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v108;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v108 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v109;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v109 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v110;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v110 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v111;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v111 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v112;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v112 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v112;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v112 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v113;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v113 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v114;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v114 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v115;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v115 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v116;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v116 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v117;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v117 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v118;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v118 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v119;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v119 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v120;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v120 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v121;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v121 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v122;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v122 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v123;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v123 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v124;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v124 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v125;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v125 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v126;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v126 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v127;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v127 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v128;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v128 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v128;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v128 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v129;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v129 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v130;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v130 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v131;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v131 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v132;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v132 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v133;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v133 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v134;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v134 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v135;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v135 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v136;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v136 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v137;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v137 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v138;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v138 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v139;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v139 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v140;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v140 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v141;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v141 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v142;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v142 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v143;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v143 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v144;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v144 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v144;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v144 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v145;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v145 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v146;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v146 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v147;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v147 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v148;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v148 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v149;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v149 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v150;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v150 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v151;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v151 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v152;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v152 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v153;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v153 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v154;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v154 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v155;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v155 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v156;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v156 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v157;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v157 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v158;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v158 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v159;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v159 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v160;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v160 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v160;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v160 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v161;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v161 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v162;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v162 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v163;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v163 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v164;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v164 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v165;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v165 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v166;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v166 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v167;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v167 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v168;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v168 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v169;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v169 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v170;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v170 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v171;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v171 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v172;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v172 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v173;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v173 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v174;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v174 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v175;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v175 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v176;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v176 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v176;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v176 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v177;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v177 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v178;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v178 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v179;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v179 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v180;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v180 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v181;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v181 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v182;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v182 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v183;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v183 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v184;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v184 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v185;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v185 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v186;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v186 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v187;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v187 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v188;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v188 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v189;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v189 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v190;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v190 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v191;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v191 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v192;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v192 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v192;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v192 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v193;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v193 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v194;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v194 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v195;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v195 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v196;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v196 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v197;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v197 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v198;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v198 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v199;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v199 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v200;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v200 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v201;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v201 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v202;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v202 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v203;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v203 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v204;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v204 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v205;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v205 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v206;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v206 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v207;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v207 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v208;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v208 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v208;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v208 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v209;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v209 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v210;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v210 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v211;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v211 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v212;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v212 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v213;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v213 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v214;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v214 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v215;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v215 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v216;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v216 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v217;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v217 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v218;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v218 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v219;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v219 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v220;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v220 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v221;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v221 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v222;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v222 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v223;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v223 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v224;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v224 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v224;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v224 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v225;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v225 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v226;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v226 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v227;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v227 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v228;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v228 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v229;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v229 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v230;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v230 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v231;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v231 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v232;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v232 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v233;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v233 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v234;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v234 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v235;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v235 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v236;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v236 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v237;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v237 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v238;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v238 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v239;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v239 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v240;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v240 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v240;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v240 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v241;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v241 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v242;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v242 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v243;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v243 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v244;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v244 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v245;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v245 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v246;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v246 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v247;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v247 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v248;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v248 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v249;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v249 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v250;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v250 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v251;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v251 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v252;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v252 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v253;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v253 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v254;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v254 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v255;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v255 = 0;
    // Body
    vlSelfRef.__VdlySet__ember_top__DOT__u_gsx__DOT__mata__v0 = 0U;
    vlSelfRef.__VdlySet__ember_top__DOT__u_gsx__DOT__vtx__v0 = 0U;
    vlSelfRef.__VdlySet__ember_top__DOT__u_gsx__DOT__col__v0 = 0U;
    vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v4 = 0U;
    vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v5 = 0U;
    vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v6 = 0U;
    vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v7 = 0U;
    vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v8 = 0U;
    vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v9 = 0U;
    vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v10 = 0U;
    vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v11 = 0U;
    vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v0 = 0U;
    vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v1 = 0U;
    vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v2 = 0U;
    vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v3 = 0U;
    vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v12 = 0U;
    vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v13 = 0U;
    vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v14 = 0U;
    vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v15 = 0U;
    vlSelfRef.__Vdly__ember_top__DOT__u_vram__DOT__ixa_rdata_q 
        = vlSelfRef.ember_top__DOT__u_vram__DOT__ixa_rdata_q;
    vlSelfRef.__Vdly__ember_top__DOT__u_vram__DOT__cxa_rdata_q 
        = vlSelfRef.ember_top__DOT__u_vram__DOT__cxa_rdata_q;
    vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v16 = 0U;
    vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v17 = 0U;
    vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v18 = 0U;
    vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v19 = 0U;
    vlSelfRef.__Vdly__ember_top__DOT__u_vram__DOT__tua_rdata_q 
        = vlSelfRef.ember_top__DOT__u_vram__DOT__tua_rdata_q;
    vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v20 = 0U;
    vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v21 = 0U;
    vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v22 = 0U;
    vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v23 = 0U;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v0 = 0U;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v16 = 0U;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v32 = 0U;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v48 = 0U;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v64 = 0U;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v80 = 0U;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v96 = 0U;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v112 = 0U;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v128 = 0U;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v144 = 0U;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v160 = 0U;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v176 = 0U;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v192 = 0U;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v208 = 0U;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v224 = 0U;
    __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v240 = 0U;
    if (vlSelfRef.ember_top__DOT__gsx_csr_we) {
        if ((0U == (IData)(vlSelfRef.ember_top__DOT__gsx_csr_addr))) {
            vlSelfRef.__VdlyVal__ember_top__DOT__u_gsx__DOT__mata__v0 
                = vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata;
            vlSelfRef.__VdlyDim0__ember_top__DOT__u_gsx__DOT__mata__v0 
                = vlSelfRef.ember_top__DOT__u_gsx__DOT__mata_ptr;
            vlSelfRef.__VdlySet__ember_top__DOT__u_gsx__DOT__mata__v0 = 1U;
        }
        if ((0U != (IData)(vlSelfRef.ember_top__DOT__gsx_csr_addr))) {
            if ((1U == (IData)(vlSelfRef.ember_top__DOT__gsx_csr_addr))) {
                vlSelfRef.ember_top__DOT__u_gsx__DOT____Vlvbound_h5e2f4665__0 
                    = vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata;
                if ((0x0eU >= (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__vtx_ptr))) {
                    vlSelfRef.__VdlyVal__ember_top__DOT__u_gsx__DOT__vtx__v0 
                        = vlSelfRef.ember_top__DOT__u_gsx__DOT____Vlvbound_h5e2f4665__0;
                    vlSelfRef.__VdlyDim0__ember_top__DOT__u_gsx__DOT__vtx__v0 
                        = vlSelfRef.ember_top__DOT__u_gsx__DOT__vtx_ptr;
                    vlSelfRef.__VdlySet__ember_top__DOT__u_gsx__DOT__vtx__v0 = 1U;
                }
            }
            if ((1U != (IData)(vlSelfRef.ember_top__DOT__gsx_csr_addr))) {
                if ((2U == (IData)(vlSelfRef.ember_top__DOT__gsx_csr_addr))) {
                    vlSelfRef.ember_top__DOT__u_gsx__DOT____Vlvbound_hd21f5caa__0 
                        = vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata;
                    if ((2U >= (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__col_ptr))) {
                        vlSelfRef.__VdlyVal__ember_top__DOT__u_gsx__DOT__col__v0 
                            = vlSelfRef.ember_top__DOT__u_gsx__DOT____Vlvbound_hd21f5caa__0;
                        vlSelfRef.__VdlyDim0__ember_top__DOT__u_gsx__DOT__col__v0 
                            = vlSelfRef.ember_top__DOT__u_gsx__DOT__col_ptr;
                        vlSelfRef.__VdlySet__ember_top__DOT__u_gsx__DOT__col__v0 = 1U;
                    }
                }
            }
        }
    }
    if (((IData)(vlSelfRef.dbg_en) & (0U != (IData)(vlSelfRef.dbg_be)))) {
        if ((1U & (IData)(vlSelfRef.dbg_be))) {
            vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v4 
                = (0x000000ffU & vlSelfRef.dbg_wdata);
            vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v4 
                = vlSelfRef.dbg_addr;
            vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v4 = 1U;
        }
        if ((2U & (IData)(vlSelfRef.dbg_be))) {
            vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v5 
                = (0x000000ffU & (vlSelfRef.dbg_wdata 
                                  >> 8U));
            vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v5 
                = vlSelfRef.dbg_addr;
            vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v5 = 1U;
        }
        if ((4U & (IData)(vlSelfRef.dbg_be))) {
            vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v6 
                = (0x000000ffU & (vlSelfRef.dbg_wdata 
                                  >> 0x10U));
            vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v6 
                = vlSelfRef.dbg_addr;
            vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v6 = 1U;
        }
        if ((8U & (IData)(vlSelfRef.dbg_be))) {
            vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v7 
                = (vlSelfRef.dbg_wdata >> 0x18U);
            vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v7 
                = vlSelfRef.dbg_addr;
            vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v7 = 1U;
        }
    }
    if (((IData)(vlSelfRef.ember_top__DOT__rtr_busy)
          ? ((~ (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__in_fetch)) 
             & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_we))
          : ((IData)(vlSelfRef.ember_top__DOT__blit_own) 
             & (IData)(vlSelfRef.ember_top__DOT__blit_fpa_we)))) {
        if ((1U & (IData)(vlSelfRef.ember_top__DOT__fpa_be))) {
            vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v8 
                = (0x000000ffU & vlSelfRef.ember_top__DOT__fpa_wdata);
            vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v8 
                = vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_widx;
            vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v8 = 1U;
        }
        if ((2U & (IData)(vlSelfRef.ember_top__DOT__fpa_be))) {
            vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v9 
                = (0x000000ffU & (vlSelfRef.ember_top__DOT__fpa_wdata 
                                  >> 8U));
            vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v9 
                = vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_widx;
            vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v9 = 1U;
        }
        if ((4U & (IData)(vlSelfRef.ember_top__DOT__fpa_be))) {
            vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v10 
                = (0x000000ffU & (vlSelfRef.ember_top__DOT__fpa_wdata 
                                  >> 0x10U));
            vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v10 
                = vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_widx;
            vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v10 = 1U;
        }
        if ((8U & (IData)(vlSelfRef.ember_top__DOT__fpa_be))) {
            vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v11 
                = (vlSelfRef.ember_top__DOT__fpa_wdata 
                   >> 0x18U);
            vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v11 
                = vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_widx;
            vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v11 = 1U;
        }
    }
    if (vlSelfRef.ember_top__DOT__u_vram__DOT__wr_fire) {
        if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__w_q))) {
            __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__121__a 
                = (IData)((vlSelfRef.ember_top__DOT__u_vram__DOT__aw_q 
                           >> 3U));
            __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__121__off 
                = (__Vfunc_ember_top__DOT__u_vram__DOT__addr2word__121__a 
                   - (IData)(0x00001000U));
            __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__121__Vfuncout 
                = (0x0001ffffU & (__Vfunc_ember_top__DOT__u_vram__DOT__addr2word__121__off 
                                  >> 2U));
            vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v0 
                = (0x000000ffU & (IData)((vlSelfRef.ember_top__DOT__u_vram__DOT__w_q 
                                          >> 4U)));
            vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v0 
                = __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__121__Vfuncout;
            vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v0 = 1U;
        }
        if ((1U & (IData)((vlSelfRef.ember_top__DOT__u_vram__DOT__w_q 
                           >> 1U)))) {
            __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__122__a 
                = (IData)((vlSelfRef.ember_top__DOT__u_vram__DOT__aw_q 
                           >> 3U));
            __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__122__off 
                = (__Vfunc_ember_top__DOT__u_vram__DOT__addr2word__122__a 
                   - (IData)(0x00001000U));
            __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__122__Vfuncout 
                = (0x0001ffffU & (__Vfunc_ember_top__DOT__u_vram__DOT__addr2word__122__off 
                                  >> 2U));
            vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v1 
                = (0x000000ffU & (IData)((vlSelfRef.ember_top__DOT__u_vram__DOT__w_q 
                                          >> 0x0000000cU)));
            vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v1 
                = __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__122__Vfuncout;
            vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v1 = 1U;
        }
        if ((1U & (IData)((vlSelfRef.ember_top__DOT__u_vram__DOT__w_q 
                           >> 2U)))) {
            __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__123__a 
                = (IData)((vlSelfRef.ember_top__DOT__u_vram__DOT__aw_q 
                           >> 3U));
            __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__123__off 
                = (__Vfunc_ember_top__DOT__u_vram__DOT__addr2word__123__a 
                   - (IData)(0x00001000U));
            __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__123__Vfuncout 
                = (0x0001ffffU & (__Vfunc_ember_top__DOT__u_vram__DOT__addr2word__123__off 
                                  >> 2U));
            vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v2 
                = (0x000000ffU & (IData)((vlSelfRef.ember_top__DOT__u_vram__DOT__w_q 
                                          >> 0x00000014U)));
            vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v2 
                = __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__123__Vfuncout;
            vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v2 = 1U;
        }
        if ((1U & (IData)((vlSelfRef.ember_top__DOT__u_vram__DOT__w_q 
                           >> 3U)))) {
            __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__124__a 
                = (IData)((vlSelfRef.ember_top__DOT__u_vram__DOT__aw_q 
                           >> 3U));
            __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__124__off 
                = (__Vfunc_ember_top__DOT__u_vram__DOT__addr2word__124__a 
                   - (IData)(0x00001000U));
            __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__124__Vfuncout 
                = (0x0001ffffU & (__Vfunc_ember_top__DOT__u_vram__DOT__addr2word__124__off 
                                  >> 2U));
            vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v3 
                = (0x000000ffU & (IData)((vlSelfRef.ember_top__DOT__u_vram__DOT__w_q 
                                          >> 0x0000001cU)));
            vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v3 
                = __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__124__Vfuncout;
            vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v3 = 1U;
        }
    }
    if (vlSelfRef.ember_top__DOT__gsx_gxa_we) {
        if ((1U & (IData)(vlSelfRef.ember_top__DOT__gsx_gxa_be))) {
            vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v12 
                = (0x000000ffU & vlSelfRef.ember_top__DOT__gsx_gxa_wdata);
            vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v12 
                = (0x0001ffffU & ((vlSelfRef.ember_top__DOT__gsx_gxa_addr 
                                   - (IData)(0x00001000U)) 
                                  >> 2U));
            vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v12 = 1U;
        }
        if ((2U & (IData)(vlSelfRef.ember_top__DOT__gsx_gxa_be))) {
            vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v13 
                = (0x000000ffU & (vlSelfRef.ember_top__DOT__gsx_gxa_wdata 
                                  >> 8U));
            vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v13 
                = (0x0001ffffU & ((vlSelfRef.ember_top__DOT__gsx_gxa_addr 
                                   - (IData)(0x00001000U)) 
                                  >> 2U));
            vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v13 = 1U;
        }
        if ((4U & (IData)(vlSelfRef.ember_top__DOT__gsx_gxa_be))) {
            vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v14 
                = (0x000000ffU & (vlSelfRef.ember_top__DOT__gsx_gxa_wdata 
                                  >> 0x10U));
            vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v14 
                = (0x0001ffffU & ((vlSelfRef.ember_top__DOT__gsx_gxa_addr 
                                   - (IData)(0x00001000U)) 
                                  >> 2U));
            vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v14 = 1U;
        }
        if ((8U & (IData)(vlSelfRef.ember_top__DOT__gsx_gxa_be))) {
            vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v15 
                = (vlSelfRef.ember_top__DOT__gsx_gxa_wdata 
                   >> 0x18U);
            vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v15 
                = (0x0001ffffU & ((vlSelfRef.ember_top__DOT__gsx_gxa_addr 
                                   - (IData)(0x00001000U)) 
                                  >> 2U));
            vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v15 = 1U;
        }
    }
    if (vlSelfRef.ember_top__DOT__core_ixa_req) {
        vlSelfRef.__Vdly__ember_top__DOT__u_vram__DOT__ixa_rdata_q 
            = vlSelfRef.ember_top__DOT__u_vram__DOT__ram
            [(0x0001ffffU & ((vlSelfRef.ember_top__DOT__core_ixa_addr 
                              - (IData)(0x00001000U)) 
                             >> 2U))];
    }
    if (vlSelfRef.ember_top__DOT__core_cxa_req) {
        vlSelfRef.__Vdly__ember_top__DOT__u_vram__DOT__cxa_rdata_q 
            = vlSelfRef.ember_top__DOT__u_vram__DOT__ram
            [(0x0001ffffU & ((vlSelfRef.ember_top__DOT__core_cxa_addr 
                              - (IData)(0x00001000U)) 
                             >> 2U))];
    }
    if (vlSelfRef.ember_top__DOT__core_cxa_we) {
        if ((1U & (IData)(vlSelfRef.ember_top__DOT__core_cxa_be))) {
            vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v16 
                = (0x000000ffU & vlSelfRef.ember_top__DOT__core_cxa_wdata);
            vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v16 
                = (0x0001ffffU & ((vlSelfRef.ember_top__DOT__core_cxa_addr 
                                   - (IData)(0x00001000U)) 
                                  >> 2U));
            vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v16 = 1U;
        }
        if ((2U & (IData)(vlSelfRef.ember_top__DOT__core_cxa_be))) {
            vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v17 
                = (0x000000ffU & (vlSelfRef.ember_top__DOT__core_cxa_wdata 
                                  >> 8U));
            vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v17 
                = (0x0001ffffU & ((vlSelfRef.ember_top__DOT__core_cxa_addr 
                                   - (IData)(0x00001000U)) 
                                  >> 2U));
            vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v17 = 1U;
        }
        if ((4U & (IData)(vlSelfRef.ember_top__DOT__core_cxa_be))) {
            vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v18 
                = (0x000000ffU & (vlSelfRef.ember_top__DOT__core_cxa_wdata 
                                  >> 0x10U));
            vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v18 
                = (0x0001ffffU & ((vlSelfRef.ember_top__DOT__core_cxa_addr 
                                   - (IData)(0x00001000U)) 
                                  >> 2U));
            vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v18 = 1U;
        }
        if ((8U & (IData)(vlSelfRef.ember_top__DOT__core_cxa_be))) {
            vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v19 
                = (vlSelfRef.ember_top__DOT__core_cxa_wdata 
                   >> 0x18U);
            vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v19 
                = (0x0001ffffU & ((vlSelfRef.ember_top__DOT__core_cxa_addr 
                                   - (IData)(0x00001000U)) 
                                  >> 2U));
            vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v19 = 1U;
        }
    }
    if (vlSelfRef.ember_top__DOT__tu_tua_req) {
        vlSelfRef.__Vdly__ember_top__DOT__u_vram__DOT__tua_rdata_q 
            = vlSelfRef.ember_top__DOT__u_vram__DOT__ram
            [(0x0001ffffU & ((vlSelfRef.ember_top__DOT__tu_tua_addr 
                              - (IData)(0x00001000U)) 
                             >> 2U))];
    }
    if (vlSelfRef.ember_top__DOT__tu_tua_we) {
        if ((1U & (IData)(vlSelfRef.ember_top__DOT__tu_tua_be))) {
            vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v20 
                = (0x000000ffU & vlSelfRef.ember_top__DOT__tu_tua_wdata);
            vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v20 
                = (0x0001ffffU & ((vlSelfRef.ember_top__DOT__tu_tua_addr 
                                   - (IData)(0x00001000U)) 
                                  >> 2U));
            vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v20 = 1U;
        }
        if ((2U & (IData)(vlSelfRef.ember_top__DOT__tu_tua_be))) {
            vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v21 
                = (0x000000ffU & (vlSelfRef.ember_top__DOT__tu_tua_wdata 
                                  >> 8U));
            vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v21 
                = (0x0001ffffU & ((vlSelfRef.ember_top__DOT__tu_tua_addr 
                                   - (IData)(0x00001000U)) 
                                  >> 2U));
            vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v21 = 1U;
        }
        if ((4U & (IData)(vlSelfRef.ember_top__DOT__tu_tua_be))) {
            vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v22 
                = (0x000000ffU & (vlSelfRef.ember_top__DOT__tu_tua_wdata 
                                  >> 0x10U));
            vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v22 
                = (0x0001ffffU & ((vlSelfRef.ember_top__DOT__tu_tua_addr 
                                   - (IData)(0x00001000U)) 
                                  >> 2U));
            vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v22 = 1U;
        }
        if ((8U & (IData)(vlSelfRef.ember_top__DOT__tu_tua_be))) {
            vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v23 
                = (vlSelfRef.ember_top__DOT__tu_tua_wdata 
                   >> 0x18U);
            vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v23 
                = (0x0001ffffU & ((vlSelfRef.ember_top__DOT__tu_tua_addr 
                                   - (IData)(0x00001000U)) 
                                  >> 2U));
            vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v23 = 1U;
        }
    }
    if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__w_ld))) {
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v0 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[0U];
        __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v0 = 1U;
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v1 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[1U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v2 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[2U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v3 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[3U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v4 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[4U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v5 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[5U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v6 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[6U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v7 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[7U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v8 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[8U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v9 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[9U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v10 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[10U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v11 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[11U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v12 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[12U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v13 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[13U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v14 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[14U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v15 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[15U];
    }
    if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__w_ld))) {
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v16 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[0U];
        __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v16 = 1U;
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v17 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[1U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v18 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[2U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v19 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[3U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v20 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[4U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v21 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[5U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v22 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[6U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v23 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[7U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v24 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[8U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v25 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[9U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v26 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[10U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v27 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[11U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v28 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[12U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v29 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[13U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v30 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[14U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v31 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[15U];
    }
    if ((4U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__w_ld))) {
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v32 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[0U];
        __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v32 = 1U;
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v33 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[1U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v34 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[2U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v35 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[3U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v36 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[4U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v37 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[5U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v38 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[6U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v39 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[7U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v40 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[8U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v41 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[9U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v42 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[10U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v43 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[11U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v44 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[12U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v45 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[13U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v46 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[14U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v47 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[15U];
    }
    if ((8U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__w_ld))) {
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v48 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[0U];
        __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v48 = 1U;
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v49 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[1U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v50 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[2U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v51 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[3U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v52 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[4U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v53 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[5U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v54 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[6U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v55 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[7U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v56 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[8U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v57 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[9U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v58 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[10U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v59 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[11U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v60 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[12U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v61 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[13U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v62 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[14U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v63 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[15U];
    }
    if ((0x00000010U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__w_ld))) {
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v64 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[0U];
        __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v64 = 1U;
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v65 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[1U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v66 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[2U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v67 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[3U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v68 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[4U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v69 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[5U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v70 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[6U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v71 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[7U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v72 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[8U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v73 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[9U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v74 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[10U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v75 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[11U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v76 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[12U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v77 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[13U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v78 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[14U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v79 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[15U];
    }
    if ((0x00000020U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__w_ld))) {
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v80 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[0U];
        __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v80 = 1U;
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v81 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[1U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v82 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[2U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v83 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[3U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v84 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[4U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v85 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[5U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v86 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[6U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v87 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[7U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v88 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[8U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v89 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[9U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v90 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[10U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v91 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[11U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v92 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[12U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v93 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[13U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v94 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[14U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v95 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[15U];
    }
    if ((0x00000040U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__w_ld))) {
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v96 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[0U];
        __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v96 = 1U;
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v97 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[1U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v98 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[2U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v99 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[3U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v100 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[4U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v101 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[5U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v102 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[6U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v103 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[7U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v104 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[8U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v105 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[9U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v106 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[10U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v107 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[11U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v108 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[12U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v109 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[13U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v110 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[14U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v111 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[15U];
    }
    if ((0x00000080U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__w_ld))) {
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v112 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[0U];
        __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v112 = 1U;
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v113 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[1U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v114 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[2U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v115 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[3U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v116 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[4U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v117 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[5U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v118 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[6U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v119 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[7U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v120 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[8U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v121 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[9U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v122 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[10U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v123 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[11U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v124 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[12U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v125 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[13U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v126 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[14U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v127 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[15U];
    }
    if ((0x00000100U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__w_ld))) {
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v128 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[0U];
        __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v128 = 1U;
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v129 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[1U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v130 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[2U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v131 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[3U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v132 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[4U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v133 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[5U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v134 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[6U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v135 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[7U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v136 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[8U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v137 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[9U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v138 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[10U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v139 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[11U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v140 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[12U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v141 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[13U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v142 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[14U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v143 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[15U];
    }
    if ((0x00000200U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__w_ld))) {
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v144 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[0U];
        __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v144 = 1U;
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v145 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[1U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v146 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[2U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v147 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[3U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v148 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[4U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v149 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[5U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v150 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[6U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v151 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[7U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v152 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[8U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v153 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[9U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v154 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[10U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v155 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[11U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v156 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[12U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v157 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[13U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v158 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[14U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v159 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[15U];
    }
    if ((0x00000400U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__w_ld))) {
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v160 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[0U];
        __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v160 = 1U;
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v161 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[1U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v162 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[2U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v163 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[3U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v164 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[4U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v165 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[5U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v166 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[6U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v167 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[7U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v168 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[8U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v169 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[9U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v170 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[10U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v171 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[11U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v172 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[12U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v173 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[13U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v174 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[14U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v175 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[15U];
    }
    if ((0x00000800U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__w_ld))) {
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v176 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[0U];
        __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v176 = 1U;
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v177 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[1U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v178 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[2U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v179 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[3U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v180 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[4U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v181 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[5U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v182 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[6U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v183 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[7U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v184 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[8U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v185 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[9U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v186 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[10U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v187 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[11U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v188 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[12U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v189 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[13U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v190 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[14U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v191 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[15U];
    }
    if ((0x00001000U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__w_ld))) {
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v192 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[0U];
        __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v192 = 1U;
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v193 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[1U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v194 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[2U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v195 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[3U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v196 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[4U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v197 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[5U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v198 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[6U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v199 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[7U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v200 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[8U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v201 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[9U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v202 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[10U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v203 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[11U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v204 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[12U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v205 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[13U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v206 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[14U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v207 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[15U];
    }
    if ((0x00002000U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__w_ld))) {
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v208 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[0U];
        __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v208 = 1U;
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v209 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[1U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v210 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[2U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v211 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[3U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v212 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[4U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v213 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[5U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v214 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[6U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v215 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[7U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v216 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[8U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v217 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[9U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v218 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[10U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v219 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[11U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v220 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[12U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v221 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[13U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v222 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[14U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v223 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[15U];
    }
    if ((0x00004000U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__w_ld))) {
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v224 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[0U];
        __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v224 = 1U;
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v225 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[1U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v226 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[2U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v227 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[3U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v228 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[4U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v229 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[5U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v230 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[6U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v231 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[7U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v232 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[8U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v233 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[9U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v234 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[10U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v235 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[11U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v236 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[12U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v237 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[13U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v238 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[14U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v239 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[15U];
    }
    if ((0x00008000U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__w_ld))) {
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v240 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[0U];
        __VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v240 = 1U;
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v241 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[1U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v242 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[2U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v243 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[3U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v244 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[4U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v245 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[5U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v246 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[6U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v247 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[7U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v248 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[8U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v249 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[9U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v250 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[10U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v251 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[11U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v252 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[12U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v253 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[13U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v254 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[14U];
        __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v255 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[15U];
    }
    if (vlSelfRef.dbg_en) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__dbg_rdata_q 
            = vlSelfRef.ember_top__DOT__u_vram__DOT__ram
            [vlSelfRef.dbg_addr];
    }
    if (vlSelfRef.ember_top__DOT__fpa2_req) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__fpa2_rdata_q 
            = vlSelfRef.ember_top__DOT__u_vram__DOT__ram
            [(0x0001ffffU & ((vlSelfRef.ember_top__DOT__fpa2_addr 
                              - (IData)(0x00001000U)) 
                             >> 2U))];
    }
    if (vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__ar_accept) {
        vlSelfRef.ember_top__DOT__c_r = ((QData)((IData)(
                                                         ((0U 
                                                           == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rd_addr))
                                                           ? 0xeb220002U
                                                           : 
                                                          ((4U 
                                                            == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rd_addr))
                                                            ? 
                                                           (((IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__running) 
                                                             << 0x0000000aU) 
                                                            | ((((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__running) 
                                                                 << 9U) 
                                                                | (((IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__busy_r) 
                                                                    << 8U) 
                                                                   | ((0U 
                                                                       != (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__st)) 
                                                                      << 7U))) 
                                                               | ((0x00000078U 
                                                                   & (((7U 
                                                                        & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rb_wp)) 
                                                                       - 
                                                                       (7U 
                                                                        & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rb_rp))) 
                                                                      << 3U)) 
                                                                  | (((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rb_empty) 
                                                                      << 2U) 
                                                                     | (((IData)(vlSelfRef.ember_top__DOT__rtr_busy) 
                                                                         << 1U) 
                                                                        | (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__dma_busy_q))))))
                                                            : 
                                                           ((0x000cU 
                                                             == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rd_addr))
                                                             ? (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__fence_done_q)
                                                             : 
                                                            ((0x0010U 
                                                              == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rd_addr))
                                                              ? 
                                                             ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rb_empty)
                                                               ? 0U
                                                               : vlSelfRef.ember_top__DOT__u_cp__DOT__rb_mem
                                                              [
                                                              (7U 
                                                               & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rb_rp))])
                                                              : 
                                                             ((0x0014U 
                                                               == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rd_addr))
                                                               ? vlSelfRef.ember_top__DOT__u_cp__DOT__dma_dst_q
                                                               : 
                                                              ((0x0018U 
                                                                == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rd_addr))
                                                                ? vlSelfRef.ember_top__DOT__u_cp__DOT__dma_len_q
                                                                : 0U)))))))) 
                                         << 2U);
    }
    if (vlSelfRef.ember_top__DOT__u_vram__DOT__ar_accept) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__rdata_q 
            = vlSelfRef.ember_top__DOT__u_vram__DOT__ram
            [([&]() {
                __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__132__a 
                    = (IData)((((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__r_fwd_h)
                                 ? ((QData)((IData)(vlSelfRef.h_araddr)) 
                                    << 3U) : vlSelfRef.ember_top__DOT__d_ar) 
                               >> 3U));
                __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__132__off 
                    = (__Vfunc_ember_top__DOT__u_vram__DOT__addr2word__132__a 
                       - (IData)(0x00001000U));
                __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__132__Vfuncout 
                    = (0x0001ffffU & (__Vfunc_ember_top__DOT__u_vram__DOT__addr2word__132__off 
                                      >> 2U));
            }(), __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__132__Vfuncout)];
    }
    if (vlSelfRef.ember_top__DOT__u_disp__DOT__req_q) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__fpa3_rdata_q 
            = vlSelfRef.ember_top__DOT__u_vram__DOT__ram
            [(0x0001ffffU & ((vlSelfRef.ember_top__DOT__u_disp__DOT__addr_q 
                              - (IData)(0x00001000U)) 
                             >> 2U))];
    }
    if (__VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v0) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][0U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v0;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][1U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v1;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][2U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v2;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][3U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v3;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][4U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v4;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][5U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v5;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][6U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v6;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][7U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v7;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][8U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v8;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][9U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v9;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][10U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v10;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][11U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v11;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][12U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v12;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][13U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v13;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][14U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v14;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][15U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v15;
    }
    if (__VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v16) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][0U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v16;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][1U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v17;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][2U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v18;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][3U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v19;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][4U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v20;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][5U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v21;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][6U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v22;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][7U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v23;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][8U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v24;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][9U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v25;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][10U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v26;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][11U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v27;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][12U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v28;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][13U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v29;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][14U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v30;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][15U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v31;
    }
    if (__VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v32) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][0U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v32;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][1U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v33;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][2U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v34;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][3U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v35;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][4U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v36;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][5U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v37;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][6U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v38;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][7U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v39;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][8U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v40;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][9U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v41;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][10U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v42;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][11U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v43;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][12U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v44;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][13U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v45;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][14U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v46;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][15U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v47;
    }
    if (__VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v48) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][0U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v48;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][1U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v49;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][2U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v50;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][3U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v51;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][4U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v52;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][5U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v53;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][6U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v54;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][7U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v55;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][8U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v56;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][9U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v57;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][10U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v58;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][11U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v59;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][12U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v60;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][13U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v61;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][14U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v62;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][15U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v63;
    }
    if (__VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v64) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][0U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v64;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][1U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v65;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][2U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v66;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][3U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v67;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][4U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v68;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][5U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v69;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][6U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v70;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][7U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v71;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][8U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v72;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][9U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v73;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][10U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v74;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][11U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v75;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][12U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v76;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][13U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v77;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][14U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v78;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][15U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v79;
    }
    if (__VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v80) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][0U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v80;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][1U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v81;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][2U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v82;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][3U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v83;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][4U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v84;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][5U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v85;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][6U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v86;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][7U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v87;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][8U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v88;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][9U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v89;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][10U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v90;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][11U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v91;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][12U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v92;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][13U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v93;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][14U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v94;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][15U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v95;
    }
    if (__VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v96) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][0U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v96;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][1U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v97;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][2U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v98;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][3U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v99;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][4U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v100;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][5U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v101;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][6U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v102;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][7U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v103;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][8U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v104;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][9U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v105;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][10U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v106;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][11U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v107;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][12U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v108;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][13U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v109;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][14U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v110;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][15U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v111;
    }
    if (__VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v112) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][0U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v112;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][1U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v113;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][2U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v114;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][3U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v115;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][4U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v116;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][5U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v117;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][6U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v118;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][7U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v119;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][8U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v120;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][9U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v121;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][10U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v122;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][11U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v123;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][12U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v124;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][13U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v125;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][14U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v126;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][15U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v127;
    }
    if (__VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v128) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][0U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v128;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][1U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v129;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][2U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v130;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][3U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v131;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][4U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v132;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][5U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v133;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][6U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v134;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][7U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v135;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][8U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v136;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][9U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v137;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][10U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v138;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][11U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v139;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][12U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v140;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][13U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v141;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][14U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v142;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][15U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v143;
    }
    if (__VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v144) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][0U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v144;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][1U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v145;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][2U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v146;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][3U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v147;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][4U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v148;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][5U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v149;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][6U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v150;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][7U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v151;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][8U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v152;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][9U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v153;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][10U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v154;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][11U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v155;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][12U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v156;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][13U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v157;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][14U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v158;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][15U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v159;
    }
    if (__VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v160) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][0U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v160;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][1U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v161;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][2U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v162;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][3U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v163;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][4U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v164;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][5U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v165;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][6U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v166;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][7U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v167;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][8U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v168;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][9U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v169;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][10U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v170;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][11U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v171;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][12U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v172;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][13U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v173;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][14U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v174;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][15U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v175;
    }
    if (__VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v176) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][0U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v176;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][1U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v177;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][2U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v178;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][3U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v179;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][4U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v180;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][5U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v181;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][6U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v182;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][7U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v183;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][8U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v184;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][9U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v185;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][10U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v186;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][11U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v187;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][12U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v188;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][13U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v189;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][14U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v190;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][15U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v191;
    }
    if (__VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v192) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][0U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v192;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][1U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v193;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][2U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v194;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][3U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v195;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][4U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v196;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][5U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v197;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][6U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v198;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][7U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v199;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][8U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v200;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][9U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v201;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][10U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v202;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][11U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v203;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][12U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v204;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][13U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v205;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][14U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v206;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][15U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v207;
    }
    if (__VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v208) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][0U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v208;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][1U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v209;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][2U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v210;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][3U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v211;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][4U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v212;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][5U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v213;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][6U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v214;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][7U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v215;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][8U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v216;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][9U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v217;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][10U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v218;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][11U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v219;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][12U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v220;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][13U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v221;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][14U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v222;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][15U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v223;
    }
    if (__VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v224) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][0U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v224;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][1U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v225;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][2U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v226;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][3U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v227;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][4U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v228;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][5U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v229;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][6U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v230;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][7U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v231;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][8U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v232;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][9U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v233;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][10U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v234;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][11U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v235;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][12U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v236;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][13U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v237;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][14U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v238;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][15U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v239;
    }
    if (__VdlySet__ember_top__DOT__u_tu__DOT__w_regs__v240) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][0U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v240;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][1U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v241;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][2U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v242;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][3U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v243;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][4U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v244;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][5U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v245;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][6U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v246;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][7U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v247;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][8U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v248;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][9U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v249;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][10U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v250;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][11U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v251;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][12U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v252;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][13U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v253;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][14U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v254;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][15U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v255;
    }
    vlSelfRef.dbg_rdata = vlSelfRef.ember_top__DOT__u_vram__DOT__dbg_rdata_q;
}
