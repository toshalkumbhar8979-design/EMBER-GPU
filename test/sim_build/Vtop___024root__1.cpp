// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

extern const VlUnpacked<CData/*0:0*/, 64> Vtop__ConstPool__TABLE_hac274646_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vtop__ConstPool__TABLE_hbc651652_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_hd6d163cc_0;
extern const VlUnpacked<CData/*1:0*/, 128> Vtop__ConstPool__TABLE_h047d7390_0;

void Vtop___024root___nba_sequent__TOP__7(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__7\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*5:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*6:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    CData/*5:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    // Body
    __Vtableidx4 = ((((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__r_favor_d) 
                      << 5U) | (((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__d_req_v_r) 
                                 << 4U) | ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__h_req_v_r) 
                                           << 3U))) 
                    | (((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__rstate) 
                        << 1U) | (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__rst_n)));
    if (Vtop__ConstPool__TABLE_hac274646_0[__Vtableidx4]) {
        vlSelfRef.ember_top__DOT__u_xbar__DOT__r_favor_d 
            = Vtop__ConstPool__TABLE_hbc651652_0[__Vtableidx4];
    }
    __Vtableidx2 = ((((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_favor_d) 
                      << 5U) | (((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__d_req_v_w) 
                                 << 4U) | ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__h_req_v_w) 
                                           << 3U))) 
                    | (((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__wstate) 
                        << 1U) | (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__rst_n)));
    if (Vtop__ConstPool__TABLE_hac274646_0[__Vtableidx2]) {
        vlSelfRef.ember_top__DOT__u_xbar__DOT__w_favor_d 
            = Vtop__ConstPool__TABLE_hbc651652_0[__Vtableidx2];
    }
    __Vtableidx3 = ((((((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__v_rready) 
                        << 3U) | ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__v_rvalid) 
                                  << 2U)) | (((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__d_req_v_r) 
                                              << 1U) 
                                             | (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__h_req_v_r))) 
                     << 3U) | (((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__rstate) 
                                << 1U) | (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__rst_n)));
    if (Vtop__ConstPool__TABLE_hd6d163cc_0[__Vtableidx3]) {
        vlSelfRef.ember_top__DOT__u_xbar__DOT__rstate 
            = Vtop__ConstPool__TABLE_h047d7390_0[__Vtableidx3];
    }
    __Vtableidx1 = ((((((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__v_bready) 
                        << 3U) | ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__v_bvalid) 
                                  << 2U)) | (((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__d_req_v_w) 
                                              << 1U) 
                                             | (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__h_req_v_w))) 
                     << 3U) | (((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__wstate) 
                                << 1U) | (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__rst_n)));
    if (Vtop__ConstPool__TABLE_hd6d163cc_0[__Vtableidx1]) {
        vlSelfRef.ember_top__DOT__u_xbar__DOT__wstate 
            = Vtop__ConstPool__TABLE_h047d7390_0[__Vtableidx1];
    }
    vlSelfRef.ember_top__DOT__u_xbar__DOT__v_rready 
        = ((1U == (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__rstate))
            ? (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__h_rready)
            : (2U == (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__rstate)));
    vlSelfRef.ember_top__DOT__u_xbar__DOT__c_rready 
        = ((1U != (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__rstate)) 
           & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__h_rready));
    vlSelfRef.ember_top__DOT__u_xbar__DOT__c_bready 
        = ((1U != (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__wstate)) 
           & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__h_bready));
    vlSelfRef.ember_top__DOT__u_xbar__DOT__v_bready 
        = ((1U == (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__wstate))
            ? (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__h_bready)
            : (2U == (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__wstate)));
    vlSelfRef.ember_top__DOT__v_rready = vlSelfRef.ember_top__DOT__u_xbar__DOT__v_rready;
    vlSelfRef.ember_top__DOT__c_rready = vlSelfRef.ember_top__DOT__u_xbar__DOT__c_rready;
    vlSelfRef.ember_top__DOT__c_bready = vlSelfRef.ember_top__DOT__u_xbar__DOT__c_bready;
    vlSelfRef.ember_top__DOT__v_bready = vlSelfRef.ember_top__DOT__u_xbar__DOT__v_bready;
    vlSelfRef.ember_top__DOT__u_vram__DOT__s_rready 
        = vlSelfRef.ember_top__DOT__v_rready;
    vlSelfRef.ember_top__DOT__u_cp__DOT__s_rready = vlSelfRef.ember_top__DOT__c_rready;
    vlSelfRef.ember_top__DOT__u_cp__DOT__s_bready = vlSelfRef.ember_top__DOT__c_bready;
    vlSelfRef.ember_top__DOT__u_vram__DOT__s_bready 
        = vlSelfRef.ember_top__DOT__v_bready;
    vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_rready 
        = vlSelfRef.ember_top__DOT__u_cp__DOT__s_rready;
    vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_bready 
        = vlSelfRef.ember_top__DOT__u_cp__DOT__s_bready;
}

void Vtop___024root___nba_sequent__TOP__8(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__8\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__16__Vfuncout;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__16__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__16__opc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__16__opc = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__16__av;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__16__av = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__16__bv;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__16__bv = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__Vfuncout;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__av;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__av = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__bv;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__bv = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sub_op;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sub_op = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sa = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sb = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sbs;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sbs = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__big_a;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__big_a = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sign_r;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sign_r = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__ea;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__ea = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__eb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__eb = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__big_e;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__big_e = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__delta;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__delta = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fa = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fb = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fr;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fr = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__a_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__a_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__b_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__b_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__a_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__a_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__b_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__b_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__a_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__a_z = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__b_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__b_z = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fa_w;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fa_w = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fb_w;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fb_w = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__norm;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__norm = 0;
    QData/*34:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fsum;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fsum = 0;
    CData/*5:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__top;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__top = 0;
    SData/*15:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sh_l;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sh_l = 0;
    SData/*10:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__e9;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__e9 = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__g;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__g = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__s;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__s = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__inc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__inc = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fc = 0;
    CData/*5:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__Vfuncout;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__Vfuncout = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v = 0;
    CData/*5:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__Vfuncout;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__av;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__av = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__bv;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__bv = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sub_op;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sub_op = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sa = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sb = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sbs;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sbs = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__big_a;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__big_a = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sign_r;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sign_r = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__ea;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__ea = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__eb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__eb = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__big_e;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__big_e = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__delta;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__delta = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fa = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fb = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fr;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fr = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__a_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__a_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__b_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__b_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__a_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__a_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__b_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__b_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__a_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__a_z = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__b_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__b_z = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fa_w;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fa_w = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fb_w;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fb_w = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__norm;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__norm = 0;
    QData/*34:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fsum;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fsum = 0;
    CData/*5:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__top;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__top = 0;
    SData/*15:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sh_l;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sh_l = 0;
    SData/*10:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__e9;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__e9 = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__g;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__g = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__s;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__s = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__inc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__inc = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fc = 0;
    CData/*5:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__Vfuncout;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__Vfuncout = 0;
    QData/*33:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v = 0;
    CData/*5:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__Vfuncout;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__av;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__av = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__bv;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__bv = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__sa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__sa = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__sb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__sb = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__sg;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__sg = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__ea;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__ea = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__eb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__eb = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fa = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fb = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fr;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fr = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__a_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__a_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__b_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__b_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__a_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__a_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__b_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__b_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__a_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__a_z = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__b_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__b_z = 0;
    QData/*47:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__prod;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__prod = 0;
    IData/*23:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__f24;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__f24 = 0;
    SData/*10:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__e9;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__e9 = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__g;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__g = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__s;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__s = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__inc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__inc = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fc = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__Vfuncout;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__av;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__av = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__bv;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__bv = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__sa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__sa = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__sb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__sb = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__sg;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__sg = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__ea;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__ea = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__eb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__eb = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fa;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fa = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fb;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fb = 0;
    IData/*22:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fr;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fr = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__a_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__a_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__b_nan;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__b_nan = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__a_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__a_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__b_inf;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__b_inf = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__a_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__a_z = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__b_z;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__b_z = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q = 0;
    IData/*23:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__f24;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__f24 = 0;
    SData/*10:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__e9;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__e9 = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__g;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__g = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__s;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__s = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__inc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__inc = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fc;
    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fc = 0;
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
    VlWide<4>/*102:0*/ __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0;
    VL_ZERO_W(103, __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0);
    VlWide<4>/*102:0*/ __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1;
    VL_ZERO_W(103, __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1);
    VlWide<4>/*102:0*/ __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2;
    VL_ZERO_W(103, __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2);
    VlWide<4>/*102:0*/ __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3;
    VL_ZERO_W(103, __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3);
    // Body
    __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[0U] 
        = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[0U];
    __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[1U] 
        = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[1U];
    __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[2U] 
        = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[2U];
    __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U] 
        = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U];
    __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[0U] 
        = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[0U];
    __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[1U] 
        = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[1U];
    __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[2U] 
        = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[2U];
    __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[3U] 
        = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[3U];
    __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[0U] 
        = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[0U];
    __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[1U] 
        = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[1U];
    __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[2U] 
        = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[2U];
    __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U] 
        = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U];
    __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[0U] 
        = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[0U];
    __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[1U] 
        = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[1U];
    __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[2U] 
        = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[2U];
    __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U] 
        = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U];
    if (vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__rst_n) {
        __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U] 
            = (0x0000005fU & __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U]);
        if (((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__go) 
             & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__lane_en))) {
            __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U] 
                = (0x00000040U | __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U]);
            __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[1U] 
                = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__b0;
            __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[2U] 
                = (IData)((QData)((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__a0)));
            __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U] 
                = ((0x00000060U & __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U]) 
                   | (0x0000007fU & ((0x00000018U & 
                                      ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__op) 
                                       << 3U)) | (IData)(
                                                         ((QData)((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__a0)) 
                                                          >> 0x00000020U)))));
            __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[0U] = 0U;
        } else if ((0x00000040U & vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U])) {
            if ((4U == (7U & vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U]))) {
                __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U] 
                    = (0x00000020U | (0x0000001fU & __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U]));
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
                            goto __Vlabel0;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__b_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__bv;
                            goto __Vlabel0;
                        }
                        if ((((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__a_inf) 
                              & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__b_inf)) 
                             & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sa) 
                                != (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sbs)))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__Vfuncout = 0x7fc00000U;
                            goto __Vlabel0;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__a_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__av;
                            goto __Vlabel0;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__b_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sbs) 
                                                  << 0x0000001fU));
                            goto __Vlabel0;
                        }
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__a_z) 
                             & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__b_z))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__Vfuncout = 0U;
                            goto __Vlabel0;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__a_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__Vfuncout 
                                = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sbs) 
                                    << 0x0000001fU) 
                                   | (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__eb) 
                                       << 0x00000017U) 
                                      | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fb));
                            goto __Vlabel0;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__b_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__av;
                            goto __Vlabel0;
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
                            goto __Vlabel0;
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
                            goto __Vlabel0;
                        }
                        if ((0x00ffU <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sign_r) 
                                                  << 0x0000001fU));
                            goto __Vlabel0;
                        }
                        if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sign_r) 
                                   << 0x0000001fU);
                            goto __Vlabel0;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__Vfuncout 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__sign_r) 
                                << 0x0000001fU) | (
                                                   (0x7f800000U 
                                                    & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__e9) 
                                                       << 0x00000017U)) 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__10__fr));
                        __Vlabel0: ;
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
                            goto __Vlabel1;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__b_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__bv;
                            goto __Vlabel1;
                        }
                        if ((((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__a_inf) 
                              & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__b_inf)) 
                             & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sa) 
                                != (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sbs)))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__Vfuncout = 0x7fc00000U;
                            goto __Vlabel1;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__a_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__av;
                            goto __Vlabel1;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__b_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sbs) 
                                                  << 0x0000001fU));
                            goto __Vlabel1;
                        }
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__a_z) 
                             & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__b_z))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__Vfuncout = 0U;
                            goto __Vlabel1;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__a_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__Vfuncout 
                                = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sbs) 
                                    << 0x0000001fU) 
                                   | (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__eb) 
                                       << 0x00000017U) 
                                      | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fb));
                            goto __Vlabel1;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__b_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__av;
                            goto __Vlabel1;
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
                            goto __Vlabel1;
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
                            goto __Vlabel1;
                        }
                        if ((0x00ffU <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sign_r) 
                                                  << 0x0000001fU));
                            goto __Vlabel1;
                        }
                        if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sign_r) 
                                   << 0x0000001fU);
                            goto __Vlabel1;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__Vfuncout 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__sign_r) 
                                << 0x0000001fU) | (
                                                   (0x7f800000U 
                                                    & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__e9) 
                                                       << 0x00000017U)) 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__12__fr));
                        __Vlabel1: ;
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
                            goto __Vlabel2;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__b_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__bv;
                            goto __Vlabel2;
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
                                goto __Vlabel2;
                            }
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel2;
                        }
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__a_z) 
                             | (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__b_z))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel2;
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
                            goto __Vlabel2;
                        }
                        if ((0x00ffU <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel2;
                        }
                        if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel2;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__Vfuncout 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__sg) 
                                << 0x0000001fU) | (
                                                   (0x7f800000U 
                                                    & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__e9) 
                                                       << 0x00000017U)) 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__14__fr));
                        __Vlabel2: ;
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
                            goto __Vlabel3;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__b_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__bv;
                            goto __Vlabel3;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sg 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sa) 
                               ^ (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sb));
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__a_inf) 
                             & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__b_inf))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__Vfuncout = 0x7fc00000U;
                            goto __Vlabel3;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__a_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel3;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__b_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel3;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__b_z) {
                            if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__a_z) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__Vfuncout = 0x7fc00000U;
                                goto __Vlabel3;
                            }
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel3;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__a_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel3;
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
                            goto __Vlabel3;
                        }
                        if ((0x00ffU <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel3;
                        }
                        if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel3;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__Vfuncout 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__sg) 
                                << 0x0000001fU) | (
                                                   (0x7f800000U 
                                                    & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__e9) 
                                                       << 0x00000017U)) 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__fr));
                        __Vlabel3: ;
                    }
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__9__Vfuncout 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__15__Vfuncout;
                }
                __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[0U] 
                    = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__9__Vfuncout;
            } else {
                __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U] 
                    = ((0x00000078U & __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U]) 
                       | (7U & ((IData)(1U) + vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U])));
            }
        }
    } else {
        __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[0U] = 0U;
        __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[1U] = 0U;
        __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[2U] = 0U;
        __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U] = 0U;
    }
    if (vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__rst_n) {
        __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[3U] 
            = (0x0000005fU & __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[3U]);
        if (((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__go) 
             & ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__lane_en) 
                >> 1U))) {
            __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[3U] 
                = (0x00000040U | __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[3U]);
            __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[1U] 
                = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__b1;
            __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[2U] 
                = (IData)((QData)((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__a1)));
            __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[3U] 
                = ((0x00000060U & __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[3U]) 
                   | (0x0000007fU & ((0x00000018U & 
                                      ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__op) 
                                       << 3U)) | (IData)(
                                                         ((QData)((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__a1)) 
                                                          >> 0x00000020U)))));
            __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[0U] = 0U;
        } else if ((0x00000040U & vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[3U])) {
            if ((4U == (7U & vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[3U]))) {
                __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[3U] 
                    = (0x00000020U | (0x0000001fU & __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[3U]));
                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__16__bv 
                    = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[1U];
                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__16__av 
                    = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[2U];
                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__16__opc 
                    = (3U & (vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[3U] 
                             >> 3U));
                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__16__Vfuncout = 0;
                if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__16__opc))) {
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sub_op = 0U;
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__bv 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__16__bv;
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__av 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__16__av;
                    {
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__Vfuncout = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sbs = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__big_a = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sign_r = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__ea = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__eb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__big_e = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__delta = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fr = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__a_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__b_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__a_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__b_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__a_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__b_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fa_w = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fb_w = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__norm = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fsum = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__top = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sh_l = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__e9 = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__g = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__s = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__inc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sa 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__av 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__ea 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__av 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fa 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__av);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sb 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__bv 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__eb 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__bv 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fb 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__bv);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sbs 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sb) 
                               ^ (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sub_op));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__a_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__ea)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__b_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__eb)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__a_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__b_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__a_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__b_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fb));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__a_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__av;
                            goto __Vlabel4;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__b_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__bv;
                            goto __Vlabel4;
                        }
                        if ((((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__a_inf) 
                              & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__b_inf)) 
                             & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sa) 
                                != (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sbs)))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__Vfuncout = 0x7fc00000U;
                            goto __Vlabel4;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__a_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__av;
                            goto __Vlabel4;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__b_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sbs) 
                                                  << 0x0000001fU));
                            goto __Vlabel4;
                        }
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__a_z) 
                             & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__b_z))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__Vfuncout = 0U;
                            goto __Vlabel4;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__a_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__Vfuncout 
                                = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sbs) 
                                    << 0x0000001fU) 
                                   | (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__eb) 
                                       << 0x00000017U) 
                                      | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fb));
                            goto __Vlabel4;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__b_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__av;
                            goto __Vlabel4;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__big_a 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__ea) 
                                > (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__eb)) 
                               | (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__ea) 
                                   == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__eb)) 
                                  & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fa 
                                     >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fb)));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__big_a) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__big_e 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__ea;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__delta 
                                = (0x000000ffU & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__ea) 
                                                  - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__eb)));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__big_e 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__eb;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__delta 
                                = (0x000000ffU & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__eb) 
                                                  - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__ea)));
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fa_w 
                            = (0x0000000200000000ULL 
                               | ((QData)((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fa)) 
                                  << 0x0000000aU));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fb_w 
                            = (0x0000000200000000ULL 
                               | ((QData)((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fb)) 
                                  << 0x0000000aU));
                        if ((0U != (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__delta))) {
                            if ((0x22U <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__delta))) {
                                if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__big_a) {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fb_w = 1ULL;
                                } else {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fa_w = 1ULL;
                                }
                            } else {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sh_l 
                                    = (0x0000ffffU 
                                       & ((IData)(0x0022U) 
                                          - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__delta)));
                                if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__big_a) {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fb_w 
                                        = (VL_SHIFTR_QQI(34,34,8, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fb_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__delta)) 
                                           | (QData)((IData)(
                                                             (0U 
                                                              != 
                                                              (0x00000003ffffffffULL 
                                                               & VL_SHIFTL_QQI(34,34,16, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fb_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sh_l)))))));
                                } else {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fa_w 
                                        = (VL_SHIFTR_QQI(34,34,8, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fa_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__delta)) 
                                           | (QData)((IData)(
                                                             (0U 
                                                              != 
                                                              (0x00000003ffffffffULL 
                                                               & VL_SHIFTL_QQI(34,34,16, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fa_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sh_l)))))));
                                }
                            }
                        }
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sa) 
                             == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sbs))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fsum 
                                = (0x00000007ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fa_w 
                                      + __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fb_w));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sign_r 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sa;
                        } else if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__big_a) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fsum 
                                = (0x00000007ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fa_w 
                                      - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fb_w));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sign_r 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sa;
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fsum 
                                = (0x00000007ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fb_w 
                                      - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fa_w));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sign_r 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sbs;
                        }
                        if ((0ULL == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fsum)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__Vfuncout = 0U;
                            goto __Vlabel4;
                        }
                        if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fsum 
                                           >> 0x22U)))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__norm 
                                = (0x00000003ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fsum 
                                      >> 1U));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__e9 
                                = (0x000007ffU & ((IData)(1U) 
                                                  + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__big_e)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__s 
                                = (1U & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fsum) 
                                         | (0U != (0x000001ffU 
                                                   & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__norm)))));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                = (0x00000003ffffffffULL 
                                   & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fsum);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__Vfuncout = 0;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 0;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 0U;
                            if ((1U & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 0U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 1U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 1U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 2U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 2U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 3U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 3U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 4U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 4U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 5U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 5U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 6U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 6U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 7U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 7U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 8U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 8U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 9U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 9U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 0x0aU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 0x0aU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 0x0bU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 0x0bU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 0x0cU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 0x0cU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 0x0dU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 0x0dU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 0x0eU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 0x0eU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 0x0fU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 0x0fU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 0x10U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 0x10U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 0x11U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 0x11U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 0x12U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 0x12U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 0x13U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 0x13U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 0x14U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 0x14U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 0x15U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 0x15U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 0x16U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 0x16U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 0x17U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 0x17U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 0x18U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 0x18U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 0x19U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 0x19U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 0x1aU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 0x1aU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 0x1bU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 0x1bU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 0x1cU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 0x1cU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 0x1dU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 0x1dU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 0x1eU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 0x1eU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 0x1fU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 0x1fU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 0x20U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 0x20U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__v 
                                               >> 0x21U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r = 0x21U;
                            }
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__r;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__top 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__18__Vfuncout;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__norm 
                                = (0x00000003ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fsum 
                                      << (0x0000003fU 
                                          & ((IData)(0x21U) 
                                             - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__top)))));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__e9 
                                = (0x000007ffU & (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__big_e) 
                                                   + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__top)) 
                                                  - (IData)(0x0021U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__s 
                                = (0U != (0x000001ffU 
                                          & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__norm)));
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fr 
                            = (0x007fffffU & (IData)(
                                                     (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__norm 
                                                      >> 0x0aU)));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__g 
                            = (1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__norm 
                                             >> 9U)));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__inc 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__g) 
                               & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__s) 
                                  | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fr));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__inc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fc 
                                = (0x007fffffU == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fr);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fr 
                                = (0x007fffffU & ((IData)(1U) 
                                                  + __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fr));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fc = 0U;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__e9 
                                = (0x000007ffU & ((IData)(1U) 
                                                  + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__e9)));
                        }
                        if ((0x0200U <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sign_r) 
                                   << 0x0000001fU);
                            goto __Vlabel4;
                        }
                        if ((0x00ffU <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sign_r) 
                                                  << 0x0000001fU));
                            goto __Vlabel4;
                        }
                        if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sign_r) 
                                   << 0x0000001fU);
                            goto __Vlabel4;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__Vfuncout 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__sign_r) 
                                << 0x0000001fU) | (
                                                   (0x7f800000U 
                                                    & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__e9) 
                                                       << 0x00000017U)) 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__fr));
                        __Vlabel4: ;
                    }
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__16__Vfuncout 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__17__Vfuncout;
                } else if ((1U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__16__opc))) {
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sub_op = 1U;
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__bv 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__16__bv;
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__av 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__16__av;
                    {
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__Vfuncout = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sbs = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__big_a = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sign_r = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__ea = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__eb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__big_e = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__delta = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fr = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__a_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__b_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__a_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__b_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__a_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__b_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fa_w = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fb_w = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__norm = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fsum = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__top = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sh_l = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__e9 = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__g = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__s = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__inc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sa 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__av 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__ea 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__av 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fa 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__av);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sb 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__bv 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__eb 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__bv 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fb 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__bv);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sbs 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sb) 
                               ^ (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sub_op));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__a_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__ea)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__b_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__eb)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__a_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__b_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__a_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__b_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fb));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__a_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__av;
                            goto __Vlabel5;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__b_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__bv;
                            goto __Vlabel5;
                        }
                        if ((((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__a_inf) 
                              & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__b_inf)) 
                             & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sa) 
                                != (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sbs)))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__Vfuncout = 0x7fc00000U;
                            goto __Vlabel5;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__a_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__av;
                            goto __Vlabel5;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__b_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sbs) 
                                                  << 0x0000001fU));
                            goto __Vlabel5;
                        }
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__a_z) 
                             & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__b_z))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__Vfuncout = 0U;
                            goto __Vlabel5;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__a_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__Vfuncout 
                                = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sbs) 
                                    << 0x0000001fU) 
                                   | (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__eb) 
                                       << 0x00000017U) 
                                      | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fb));
                            goto __Vlabel5;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__b_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__av;
                            goto __Vlabel5;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__big_a 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__ea) 
                                > (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__eb)) 
                               | (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__ea) 
                                   == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__eb)) 
                                  & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fa 
                                     >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fb)));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__big_a) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__big_e 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__ea;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__delta 
                                = (0x000000ffU & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__ea) 
                                                  - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__eb)));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__big_e 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__eb;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__delta 
                                = (0x000000ffU & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__eb) 
                                                  - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__ea)));
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fa_w 
                            = (0x0000000200000000ULL 
                               | ((QData)((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fa)) 
                                  << 0x0000000aU));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fb_w 
                            = (0x0000000200000000ULL 
                               | ((QData)((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fb)) 
                                  << 0x0000000aU));
                        if ((0U != (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__delta))) {
                            if ((0x22U <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__delta))) {
                                if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__big_a) {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fb_w = 1ULL;
                                } else {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fa_w = 1ULL;
                                }
                            } else {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sh_l 
                                    = (0x0000ffffU 
                                       & ((IData)(0x0022U) 
                                          - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__delta)));
                                if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__big_a) {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fb_w 
                                        = (VL_SHIFTR_QQI(34,34,8, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fb_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__delta)) 
                                           | (QData)((IData)(
                                                             (0U 
                                                              != 
                                                              (0x00000003ffffffffULL 
                                                               & VL_SHIFTL_QQI(34,34,16, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fb_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sh_l)))))));
                                } else {
                                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fa_w 
                                        = (VL_SHIFTR_QQI(34,34,8, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fa_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__delta)) 
                                           | (QData)((IData)(
                                                             (0U 
                                                              != 
                                                              (0x00000003ffffffffULL 
                                                               & VL_SHIFTL_QQI(34,34,16, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fa_w, (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sh_l)))))));
                                }
                            }
                        }
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sa) 
                             == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sbs))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fsum 
                                = (0x00000007ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fa_w 
                                      + __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fb_w));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sign_r 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sa;
                        } else if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__big_a) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fsum 
                                = (0x00000007ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fa_w 
                                      - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fb_w));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sign_r 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sa;
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fsum 
                                = (0x00000007ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fb_w 
                                      - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fa_w));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sign_r 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sbs;
                        }
                        if ((0ULL == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fsum)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__Vfuncout = 0U;
                            goto __Vlabel5;
                        }
                        if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fsum 
                                           >> 0x22U)))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__norm 
                                = (0x00000003ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fsum 
                                      >> 1U));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__e9 
                                = (0x000007ffU & ((IData)(1U) 
                                                  + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__big_e)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__s 
                                = (1U & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fsum) 
                                         | (0U != (0x000001ffU 
                                                   & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__norm)))));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                = (0x00000003ffffffffULL 
                                   & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fsum);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__Vfuncout = 0;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 0;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 0U;
                            if ((1U & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 0U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 1U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 1U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 2U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 2U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 3U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 3U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 4U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 4U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 5U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 5U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 6U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 6U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 7U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 7U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 8U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 8U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 9U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 9U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 0x0aU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 0x0aU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 0x0bU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 0x0bU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 0x0cU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 0x0cU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 0x0dU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 0x0dU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 0x0eU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 0x0eU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 0x0fU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 0x0fU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 0x10U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 0x10U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 0x11U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 0x11U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 0x12U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 0x12U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 0x13U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 0x13U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 0x14U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 0x14U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 0x15U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 0x15U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 0x16U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 0x16U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 0x17U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 0x17U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 0x18U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 0x18U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 0x19U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 0x19U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 0x1aU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 0x1aU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 0x1bU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 0x1bU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 0x1cU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 0x1cU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 0x1dU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 0x1dU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 0x1eU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 0x1eU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 0x1fU)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 0x1fU;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 0x20U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 0x20U;
                            }
                            if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__v 
                                               >> 0x21U)))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r = 0x21U;
                            }
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__r;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__top 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__msb_idx34__20__Vfuncout;
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__norm 
                                = (0x00000003ffffffffULL 
                                   & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fsum 
                                      << (0x0000003fU 
                                          & ((IData)(0x21U) 
                                             - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__top)))));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__e9 
                                = (0x000007ffU & (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__big_e) 
                                                   + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__top)) 
                                                  - (IData)(0x0021U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__s 
                                = (0U != (0x000001ffU 
                                          & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__norm)));
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fr 
                            = (0x007fffffU & (IData)(
                                                     (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__norm 
                                                      >> 0x0aU)));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__g 
                            = (1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__norm 
                                             >> 9U)));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__inc 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__g) 
                               & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__s) 
                                  | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fr));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__inc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fc 
                                = (0x007fffffU == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fr);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fr 
                                = (0x007fffffU & ((IData)(1U) 
                                                  + __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fr));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fc = 0U;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__e9 
                                = (0x000007ffU & ((IData)(1U) 
                                                  + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__e9)));
                        }
                        if ((0x0200U <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sign_r) 
                                   << 0x0000001fU);
                            goto __Vlabel5;
                        }
                        if ((0x00ffU <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sign_r) 
                                                  << 0x0000001fU));
                            goto __Vlabel5;
                        }
                        if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sign_r) 
                                   << 0x0000001fU);
                            goto __Vlabel5;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__Vfuncout 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__sign_r) 
                                << 0x0000001fU) | (
                                                   (0x7f800000U 
                                                    & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__e9) 
                                                       << 0x00000017U)) 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__fr));
                        __Vlabel5: ;
                    }
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__16__Vfuncout 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__19__Vfuncout;
                } else if ((2U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__16__opc))) {
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__bv 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__16__bv;
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__av 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__16__av;
                    {
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__Vfuncout = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__sa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__sb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__sg = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__ea = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__eb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fr = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__a_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__b_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__a_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__b_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__a_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__b_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__prod = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__f24 = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__e9 = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__g = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__s = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__inc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__sa 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__av 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__ea 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__av 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fa 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__av);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__sb 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__bv 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__eb 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__bv 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fb 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__bv);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__a_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__ea)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__b_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__eb)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__a_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__b_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__a_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__b_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fb));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__a_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__av;
                            goto __Vlabel6;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__b_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__bv;
                            goto __Vlabel6;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__sg 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__sa) 
                               ^ (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__sb));
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__a_inf) 
                             | (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__b_inf))) {
                            if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__a_z) 
                                 | (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__b_z))) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__Vfuncout 
                                    = (0x7fc00000U 
                                       | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__sg) 
                                          << 0x0000001fU));
                                goto __Vlabel6;
                            }
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel6;
                        }
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__a_z) 
                             | (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__b_z))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel6;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__prod 
                            = (0x0000ffffffffffffULL 
                               & ((QData)((IData)((0x00800000U 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fa))) 
                                  * (QData)((IData)(
                                                    (0x00800000U 
                                                     | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fb)))));
                        if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__prod 
                                           >> 0x2fU)))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__f24 
                                = (0x00ffffffU & (IData)(
                                                         (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__prod 
                                                          >> 0x00000018U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__g 
                                = (1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__prod 
                                                 >> 0x17U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__s 
                                = (0U != (0x007fffffU 
                                          & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__prod)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__e9 
                                = (0x000007ffU & (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__ea) 
                                                   + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__eb)) 
                                                  - (IData)(0x007eU)));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__f24 
                                = (0x00ffffffU & (IData)(
                                                         (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__prod 
                                                          >> 0x00000017U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__g 
                                = (1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__prod 
                                                 >> 0x16U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__s 
                                = (0U != (0x003fffffU 
                                          & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__prod)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__e9 
                                = (0x000007ffU & (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__ea) 
                                                   + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__eb)) 
                                                  - (IData)(0x007fU)));
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fr 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__f24);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__inc 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__g) 
                               & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__s) 
                                  | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fr));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__inc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fc 
                                = (0x007fffffU == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fr);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fr 
                                = (0x007fffffU & ((IData)(1U) 
                                                  + __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fr));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fc = 0U;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__e9 
                                = (0x000007ffU & ((IData)(1U) 
                                                  + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__e9)));
                        }
                        if ((0x0200U <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel6;
                        }
                        if ((0x00ffU <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel6;
                        }
                        if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel6;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__Vfuncout 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__sg) 
                                << 0x0000001fU) | (
                                                   (0x7f800000U 
                                                    & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__e9) 
                                                       << 0x00000017U)) 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__fr));
                        __Vlabel6: ;
                    }
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__16__Vfuncout 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__21__Vfuncout;
                } else {
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__bv 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__16__bv;
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__av 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__16__av;
                    {
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__Vfuncout = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__sa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__sb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__sg = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__ea = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__eb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fa = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fb = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fr = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__a_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__b_nan = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__a_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__b_inf = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__a_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__b_z = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__f24 = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__e9 = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__g = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__s = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__inc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fc = 0;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__sa 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__av 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__ea 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__av 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fa 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__av);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__sb 
                            = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__bv 
                               >> 0x1fU);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__eb 
                            = (0x000000ffU & (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__bv 
                                              >> 0x17U));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fb 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__bv);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__a_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__ea)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__b_nan 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__eb)) 
                               & (0U != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__a_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__b_inf 
                            = ((0xffU == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fb));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__a_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__ea)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fa));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__b_z 
                            = ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__eb)) 
                               & (0U == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fb));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__a_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__av;
                            goto __Vlabel7;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__b_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__bv;
                            goto __Vlabel7;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__sg 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__sa) 
                               ^ (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__sb));
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__a_inf) 
                             & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__b_inf))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__Vfuncout = 0x7fc00000U;
                            goto __Vlabel7;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__a_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel7;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__b_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel7;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__b_z) {
                            if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__a_z) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__Vfuncout = 0x7fc00000U;
                                goto __Vlabel7;
                            }
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel7;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__a_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel7;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                            = (0x0002000000000000ULL 
                               | ((QData)((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fa)) 
                                  << 0x0000001aU));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den 
                            = (0x0000000000800000ULL 
                               | (QData)((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fb)));
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem = 0ULL;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q = 0ULL;
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (QData)((IData)((1U & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x3fU)))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x8000000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x3eU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x4000000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x3dU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x2000000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x3cU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x1000000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x3bU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0800000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x3aU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0400000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x39U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0200000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x38U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0100000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x37U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0080000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x36U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0040000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x35U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0020000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x34U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0010000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x33U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0008000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x32U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0004000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x31U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0002000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x30U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0001000000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x2fU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000800000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x2eU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000400000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x2dU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000200000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x2cU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000100000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x2bU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000080000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x2aU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000040000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x29U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000020000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x28U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000010000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x27U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000008000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x26U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000004000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x25U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000002000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x24U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000001000000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x23U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000800000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x22U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000400000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x21U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000200000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x20U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000100000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x1fU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000080000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x1eU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000040000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x1dU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000020000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x1cU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000010000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x1bU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000008000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x1aU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000004000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x19U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000002000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x18U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000001000000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x17U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000000800000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x16U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000000400000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x15U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000000200000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x14U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000000100000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x13U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000000080000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x12U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000000040000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x11U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000000020000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x10U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000000010000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x0fU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000000008000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x0eU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000000004000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x0dU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000000002000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x0cU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000000001000ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x0bU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000000000800ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 0x0aU))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000000000400ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 9U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000000000200ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 8U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000000000100ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 7U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000000000080ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 6U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000000000040ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 5U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000000000020ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 4U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (0x0000000000000010ULL 
                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 3U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (8ULL | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 2U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (4ULL | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num 
                                                             >> 1U))))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (2ULL | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                            = (VL_SHIFTL_QQI(64,64,32, __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem, 1U) 
                               | (QData)((IData)((1U 
                                                  & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__num)))));
                        if ((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                             >= __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den)) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                = (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem 
                                   - __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__den);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                = (1ULL | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q);
                        }
                        if ((1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                           >> 0x1aU)))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__f24 
                                = (0x00ffffffU & (IData)(
                                                         (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                                          >> 3U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__g 
                                = (1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                                 >> 2U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__s 
                                = (IData)(((0ULL != 
                                            (3ULL & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q)) 
                                           | (0ULL 
                                              != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__e9 
                                = (0x000007ffU & ((IData)(0x007fU) 
                                                  + 
                                                  ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__ea) 
                                                   - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__eb))));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__f24 
                                = (0x00ffffffU & (IData)(
                                                         (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                                          >> 2U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__g 
                                = (1U & (IData)((__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q 
                                                 >> 1U)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__s 
                                = (1U & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__q) 
                                         | (0ULL != __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__rem)));
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__e9 
                                = (0x000007ffU & ((IData)(0x007eU) 
                                                  + 
                                                  ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__ea) 
                                                   - (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__eb))));
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fr 
                            = (0x007fffffU & __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__f24);
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__inc 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__g) 
                               & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__s) 
                                  | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fr));
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__inc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fc 
                                = (0x007fffffU == __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fr);
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fr 
                                = (0x007fffffU & ((IData)(1U) 
                                                  + __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fr));
                        } else {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fc = 0U;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fc) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__e9 
                                = (0x000007ffU & ((IData)(1U) 
                                                  + (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__e9)));
                        }
                        if ((0x0200U <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel7;
                        }
                        if ((0x00ffU <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel7;
                        }
                        if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel7;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__Vfuncout 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__sg) 
                                << 0x0000001fU) | (
                                                   (0x7f800000U 
                                                    & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__e9) 
                                                       << 0x00000017U)) 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__fr));
                        __Vlabel7: ;
                    }
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__16__Vfuncout 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__22__Vfuncout;
                }
                __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[0U] 
                    = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__16__Vfuncout;
            } else {
                __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[3U] 
                    = ((0x00000078U & __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[3U]) 
                       | (7U & ((IData)(1U) + vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[3U])));
            }
        }
    } else {
        __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[0U] = 0U;
        __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[1U] = 0U;
        __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[2U] = 0U;
        __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[3U] = 0U;
    }
    if (vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__rst_n) {
        __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U] 
            = (0x0000005fU & __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U]);
        if (((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__go) 
             & ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__lane_en) 
                >> 2U))) {
            __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U] 
                = (0x00000040U | __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U]);
            __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[1U] 
                = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__b2;
            __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[2U] 
                = (IData)((QData)((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__a2)));
            __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U] 
                = ((0x00000060U & __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U]) 
                   | (0x0000007fU & ((0x00000018U & 
                                      ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__op) 
                                       << 3U)) | (IData)(
                                                         ((QData)((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__a2)) 
                                                          >> 0x00000020U)))));
            __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[0U] = 0U;
        } else if ((0x00000040U & vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U])) {
            if ((4U == (7U & vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U]))) {
                __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U] 
                    = (0x00000020U | (0x0000001fU & __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U]));
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
                            goto __Vlabel8;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__b_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__bv;
                            goto __Vlabel8;
                        }
                        if ((((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__a_inf) 
                              & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__b_inf)) 
                             & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sa) 
                                != (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sbs)))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__Vfuncout = 0x7fc00000U;
                            goto __Vlabel8;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__a_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__av;
                            goto __Vlabel8;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__b_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sbs) 
                                                  << 0x0000001fU));
                            goto __Vlabel8;
                        }
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__a_z) 
                             & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__b_z))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__Vfuncout = 0U;
                            goto __Vlabel8;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__a_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__Vfuncout 
                                = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sbs) 
                                    << 0x0000001fU) 
                                   | (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__eb) 
                                       << 0x00000017U) 
                                      | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fb));
                            goto __Vlabel8;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__b_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__av;
                            goto __Vlabel8;
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
                            goto __Vlabel8;
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
                            goto __Vlabel8;
                        }
                        if ((0x00ffU <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sign_r) 
                                                  << 0x0000001fU));
                            goto __Vlabel8;
                        }
                        if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sign_r) 
                                   << 0x0000001fU);
                            goto __Vlabel8;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__Vfuncout 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__sign_r) 
                                << 0x0000001fU) | (
                                                   (0x7f800000U 
                                                    & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__e9) 
                                                       << 0x00000017U)) 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__24__fr));
                        __Vlabel8: ;
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
                            goto __Vlabel9;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__b_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__bv;
                            goto __Vlabel9;
                        }
                        if ((((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__a_inf) 
                              & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__b_inf)) 
                             & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sa) 
                                != (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sbs)))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__Vfuncout = 0x7fc00000U;
                            goto __Vlabel9;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__a_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__av;
                            goto __Vlabel9;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__b_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sbs) 
                                                  << 0x0000001fU));
                            goto __Vlabel9;
                        }
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__a_z) 
                             & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__b_z))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__Vfuncout = 0U;
                            goto __Vlabel9;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__a_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__Vfuncout 
                                = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sbs) 
                                    << 0x0000001fU) 
                                   | (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__eb) 
                                       << 0x00000017U) 
                                      | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fb));
                            goto __Vlabel9;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__b_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__av;
                            goto __Vlabel9;
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
                            goto __Vlabel9;
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
                            goto __Vlabel9;
                        }
                        if ((0x00ffU <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sign_r) 
                                                  << 0x0000001fU));
                            goto __Vlabel9;
                        }
                        if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sign_r) 
                                   << 0x0000001fU);
                            goto __Vlabel9;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__Vfuncout 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__sign_r) 
                                << 0x0000001fU) | (
                                                   (0x7f800000U 
                                                    & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__e9) 
                                                       << 0x00000017U)) 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__26__fr));
                        __Vlabel9: ;
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
                            goto __Vlabel10;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__b_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__bv;
                            goto __Vlabel10;
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
                                goto __Vlabel10;
                            }
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel10;
                        }
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__a_z) 
                             | (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__b_z))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel10;
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
                            goto __Vlabel10;
                        }
                        if ((0x00ffU <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel10;
                        }
                        if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel10;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__Vfuncout 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__sg) 
                                << 0x0000001fU) | (
                                                   (0x7f800000U 
                                                    & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__e9) 
                                                       << 0x00000017U)) 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__28__fr));
                        __Vlabel10: ;
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
                            goto __Vlabel11;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__b_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__bv;
                            goto __Vlabel11;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sg 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sa) 
                               ^ (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sb));
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__a_inf) 
                             & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__b_inf))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__Vfuncout = 0x7fc00000U;
                            goto __Vlabel11;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__a_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel11;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__b_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel11;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__b_z) {
                            if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__a_z) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__Vfuncout = 0x7fc00000U;
                                goto __Vlabel11;
                            }
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel11;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__a_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel11;
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
                            goto __Vlabel11;
                        }
                        if ((0x00ffU <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel11;
                        }
                        if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel11;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__Vfuncout 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__sg) 
                                << 0x0000001fU) | (
                                                   (0x7f800000U 
                                                    & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__e9) 
                                                       << 0x00000017U)) 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__fr));
                        __Vlabel11: ;
                    }
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__23__Vfuncout 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__29__Vfuncout;
                }
                __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[0U] 
                    = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__23__Vfuncout;
            } else {
                __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U] 
                    = ((0x00000078U & __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U]) 
                       | (7U & ((IData)(1U) + vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U])));
            }
        }
    } else {
        __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[0U] = 0U;
        __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[1U] = 0U;
        __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[2U] = 0U;
        __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U] = 0U;
    }
    if (vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__rst_n) {
        __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U] 
            = (0x0000005fU & __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U]);
        if (((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__go) 
             & ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__lane_en) 
                >> 3U))) {
            __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U] 
                = (0x00000040U | __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U]);
            __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[1U] 
                = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__b3;
            __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[2U] 
                = (IData)((QData)((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__a3)));
            __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U] 
                = ((0x00000060U & __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U]) 
                   | (0x0000007fU & ((0x00000018U & 
                                      ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__op) 
                                       << 3U)) | (IData)(
                                                         ((QData)((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__a3)) 
                                                          >> 0x00000020U)))));
            __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[0U] = 0U;
        } else if ((0x00000040U & vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U])) {
            if ((4U == (7U & vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U]))) {
                __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U] 
                    = (0x00000020U | (0x0000001fU & __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U]));
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
                            goto __Vlabel12;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__b_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__bv;
                            goto __Vlabel12;
                        }
                        if ((((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__a_inf) 
                              & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__b_inf)) 
                             & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sa) 
                                != (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sbs)))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__Vfuncout = 0x7fc00000U;
                            goto __Vlabel12;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__a_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__av;
                            goto __Vlabel12;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__b_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sbs) 
                                                  << 0x0000001fU));
                            goto __Vlabel12;
                        }
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__a_z) 
                             & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__b_z))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__Vfuncout = 0U;
                            goto __Vlabel12;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__a_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__Vfuncout 
                                = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sbs) 
                                    << 0x0000001fU) 
                                   | (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__eb) 
                                       << 0x00000017U) 
                                      | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fb));
                            goto __Vlabel12;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__b_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__av;
                            goto __Vlabel12;
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
                            goto __Vlabel12;
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
                            goto __Vlabel12;
                        }
                        if ((0x00ffU <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sign_r) 
                                                  << 0x0000001fU));
                            goto __Vlabel12;
                        }
                        if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sign_r) 
                                   << 0x0000001fU);
                            goto __Vlabel12;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__Vfuncout 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__sign_r) 
                                << 0x0000001fU) | (
                                                   (0x7f800000U 
                                                    & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__e9) 
                                                       << 0x00000017U)) 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__31__fr));
                        __Vlabel12: ;
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
                            goto __Vlabel13;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__b_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__bv;
                            goto __Vlabel13;
                        }
                        if ((((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__a_inf) 
                              & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__b_inf)) 
                             & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sa) 
                                != (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sbs)))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__Vfuncout = 0x7fc00000U;
                            goto __Vlabel13;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__a_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__av;
                            goto __Vlabel13;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__b_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sbs) 
                                                  << 0x0000001fU));
                            goto __Vlabel13;
                        }
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__a_z) 
                             & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__b_z))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__Vfuncout = 0U;
                            goto __Vlabel13;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__a_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__Vfuncout 
                                = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sbs) 
                                    << 0x0000001fU) 
                                   | (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__eb) 
                                       << 0x00000017U) 
                                      | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fb));
                            goto __Vlabel13;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__b_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__av;
                            goto __Vlabel13;
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
                            goto __Vlabel13;
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
                            goto __Vlabel13;
                        }
                        if ((0x00ffU <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sign_r) 
                                                  << 0x0000001fU));
                            goto __Vlabel13;
                        }
                        if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sign_r) 
                                   << 0x0000001fU);
                            goto __Vlabel13;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__Vfuncout 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__sign_r) 
                                << 0x0000001fU) | (
                                                   (0x7f800000U 
                                                    & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__e9) 
                                                       << 0x00000017U)) 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_add__33__fr));
                        __Vlabel13: ;
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
                            goto __Vlabel14;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__b_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__bv;
                            goto __Vlabel14;
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
                                goto __Vlabel14;
                            }
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel14;
                        }
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__a_z) 
                             | (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__b_z))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel14;
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
                            goto __Vlabel14;
                        }
                        if ((0x00ffU <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel14;
                        }
                        if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel14;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__Vfuncout 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__sg) 
                                << 0x0000001fU) | (
                                                   (0x7f800000U 
                                                    & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__e9) 
                                                       << 0x00000017U)) 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_mul__35__fr));
                        __Vlabel14: ;
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
                            goto __Vlabel15;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__b_nan) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__Vfuncout 
                                = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__bv;
                            goto __Vlabel15;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sg 
                            = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sa) 
                               ^ (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sb));
                        if (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__a_inf) 
                             & (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__b_inf))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__Vfuncout = 0x7fc00000U;
                            goto __Vlabel15;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__a_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel15;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__b_inf) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel15;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__b_z) {
                            if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__a_z) {
                                __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__Vfuncout = 0x7fc00000U;
                                goto __Vlabel15;
                            }
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel15;
                        }
                        if (__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__a_z) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel15;
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
                            goto __Vlabel15;
                        }
                        if ((0x00ffU <= (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__Vfuncout 
                                = (0x7f800000U | ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sg) 
                                                  << 0x0000001fU));
                            goto __Vlabel15;
                        }
                        if ((0U == (IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__e9))) {
                            __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__Vfuncout 
                                = ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sg) 
                                   << 0x0000001fU);
                            goto __Vlabel15;
                        }
                        __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__Vfuncout 
                            = (((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__sg) 
                                << 0x0000001fU) | (
                                                   (0x7f800000U 
                                                    & ((IData)(__Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__e9) 
                                                       << 0x00000017U)) 
                                                   | __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__fr));
                        __Vlabel15: ;
                    }
                    __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__30__Vfuncout 
                        = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_div__36__Vfuncout;
                }
                __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[0U] 
                    = __Vfunc_ember_top__DOT__u_core__DOT__u_fpu__DOT__fpu_exec__30__Vfuncout;
            } else {
                __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U] 
                    = ((0x00000078U & __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U]) 
                       | (7U & ((IData)(1U) + vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U])));
            }
        }
    } else {
        __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[0U] = 0U;
        __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[1U] = 0U;
        __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[2U] = 0U;
        __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U] = 0U;
    }
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[0U] 
        = __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[0U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[1U] 
        = __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[1U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[2U] 
        = __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[2U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U] 
        = __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[0U] 
        = __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[0U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[1U] 
        = __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[1U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[2U] 
        = __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[2U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[3U] 
        = __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[3U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[0U] 
        = __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[0U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[1U] 
        = __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[1U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[2U] 
        = __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[2U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U] 
        = __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[0U] 
        = __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[0U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[1U] 
        = __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[1U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[2U] 
        = __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[2U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U] 
        = __Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__y0 
        = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[0U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__y1 
        = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[0U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__y2 
        = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[0U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__done 
        = (1U & ((vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U] 
                  | (vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[3U] 
                     | (vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U] 
                        | vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U]))) 
                 >> 5U));
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__y3 
        = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[0U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__busy 
        = (1U & ((vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U] 
                  | (vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[3U] 
                     | (vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U] 
                        | vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U]))) 
                 >> 6U));
    vlSelfRef.ember_top__DOT__u_core__DOT__f_y1 = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__y1;
    vlSelfRef.ember_top__DOT__u_core__DOT__f_y2 = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__y2;
    vlSelfRef.ember_top__DOT__u_core__DOT__f_y3 = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__y3;
    vlSelfRef.ember_top__DOT__u_core__DOT__f_busy = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__busy;
    vlSelfRef.ember_top__DOT__u_core__DOT___unused 
        = (1U & (VL_REDXOR_32((vlSelfRef.ember_top__DOT__u_core__DOT__f_y1 
                               ^ vlSelfRef.ember_top__DOT__u_core__DOT__f_y2)) 
                 ^ (VL_REDXOR_32(vlSelfRef.ember_top__DOT__u_core__DOT__f_y3) 
                    ^ (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__f_busy))));
}
