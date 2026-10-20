// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vember_top.h for the primary calling header

#include "Vember_top__pch.h"

void Vember_top___024root___nba_sequent__TOP__3(Vember_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vember_top___024root___nba_sequent__TOP__3\n"); );
    Vember_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    QData/*32:0*/ ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy20_;
    ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy20_ = 0;
    QData/*32:0*/ ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx20_;
    ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx20_ = 0;
    VlWide<3>/*66:0*/ ember_top__DOT__u_rtr__DOT__u_setup__DOT__den;
    VL_ZERO_W(67, ember_top__DOT__u_rtr__DOT__u_setup__DOT__den);
    VlWide<3>/*95:0*/ ember_top__DOT__u_rtr__DOT__u_setup__DOT__r10;
    VL_ZERO_W(96, ember_top__DOT__u_rtr__DOT__u_setup__DOT__r10);
    VlWide<3>/*95:0*/ ember_top__DOT__u_rtr__DOT__u_setup__DOT__r20;
    VL_ZERO_W(96, ember_top__DOT__u_rtr__DOT__u_setup__DOT__r20);
    VlWide<3>/*95:0*/ ember_top__DOT__u_rtr__DOT__u_setup__DOT__g10;
    VL_ZERO_W(96, ember_top__DOT__u_rtr__DOT__u_setup__DOT__g10);
    VlWide<3>/*95:0*/ ember_top__DOT__u_rtr__DOT__u_setup__DOT__g20;
    VL_ZERO_W(96, ember_top__DOT__u_rtr__DOT__u_setup__DOT__g20);
    VlWide<3>/*95:0*/ ember_top__DOT__u_rtr__DOT__u_setup__DOT__b10;
    VL_ZERO_W(96, ember_top__DOT__u_rtr__DOT__u_setup__DOT__b10);
    VlWide<3>/*95:0*/ ember_top__DOT__u_rtr__DOT__u_setup__DOT__b20;
    VL_ZERO_W(96, ember_top__DOT__u_rtr__DOT__u_setup__DOT__b20);
    VlWide<3>/*95:0*/ ember_top__DOT__u_rtr__DOT__u_setup__DOT__z10;
    VL_ZERO_W(96, ember_top__DOT__u_rtr__DOT__u_setup__DOT__z10);
    VlWide<3>/*95:0*/ ember_top__DOT__u_rtr__DOT__u_setup__DOT__z20;
    VL_ZERO_W(96, ember_top__DOT__u_rtr__DOT__u_setup__DOT__z20);
    VlWide<3>/*95:0*/ ember_top__DOT__u_rtr__DOT__u_setup__DOT__u10;
    VL_ZERO_W(96, ember_top__DOT__u_rtr__DOT__u_setup__DOT__u10);
    VlWide<3>/*95:0*/ ember_top__DOT__u_rtr__DOT__u_setup__DOT__u20;
    VL_ZERO_W(96, ember_top__DOT__u_rtr__DOT__u_setup__DOT__u20);
    VlWide<3>/*95:0*/ ember_top__DOT__u_rtr__DOT__u_setup__DOT__v10;
    VL_ZERO_W(96, ember_top__DOT__u_rtr__DOT__u_setup__DOT__v10);
    VlWide<3>/*95:0*/ ember_top__DOT__u_rtr__DOT__u_setup__DOT__v20;
    VL_ZERO_W(96, ember_top__DOT__u_rtr__DOT__u_setup__DOT__v20);
    IData/*31:0*/ ember_top__DOT__u_rtr__DOT__u_setup__DOT__xmin;
    ember_top__DOT__u_rtr__DOT__u_setup__DOT__xmin = 0;
    IData/*31:0*/ ember_top__DOT__u_rtr__DOT__u_setup__DOT__xmax;
    ember_top__DOT__u_rtr__DOT__u_setup__DOT__xmax = 0;
    IData/*31:0*/ ember_top__DOT__u_rtr__DOT__u_setup__DOT__ymin;
    ember_top__DOT__u_rtr__DOT__u_setup__DOT__ymin = 0;
    IData/*31:0*/ ember_top__DOT__u_rtr__DOT__u_setup__DOT__ymax;
    ember_top__DOT__u_rtr__DOT__u_setup__DOT__ymax = 0;
    CData/*7:0*/ ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_r;
    ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_r = 0;
    CData/*7:0*/ ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_g;
    ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_g = 0;
    CData/*7:0*/ ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_b;
    ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_b = 0;
    CData/*0:0*/ ember_top__DOT__u_rtr__DOT__u_scan__DOT__dith_up;
    ember_top__DOT__u_rtr__DOT__u_scan__DOT__dith_up = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__Vfuncout;
    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__c32;
    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__c32 = 0;
    SData/*15:0*/ __Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__mult;
    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__mult = 0;
    CData/*3:0*/ __Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__shift;
    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__shift = 0;
    QData/*47:0*/ __Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__full;
    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__full = 0;
    QData/*47:0*/ __Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__half;
    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__half = 0;
    QData/*47:0*/ __Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__res;
    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__res = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__Vfuncout;
    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__c32;
    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__c32 = 0;
    SData/*15:0*/ __Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__mult;
    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__mult = 0;
    CData/*3:0*/ __Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__shift;
    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__shift = 0;
    QData/*47:0*/ __Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__full;
    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__full = 0;
    QData/*47:0*/ __Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__half;
    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__half = 0;
    QData/*47:0*/ __Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__res;
    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__res = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__Vfuncout;
    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__c32;
    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__c32 = 0;
    SData/*15:0*/ __Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__mult;
    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__mult = 0;
    CData/*3:0*/ __Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__shift;
    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__shift = 0;
    QData/*47:0*/ __Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__full;
    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__full = 0;
    QData/*47:0*/ __Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__half;
    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__half = 0;
    QData/*47:0*/ __Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__res;
    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__res = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__Vfuncout;
    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__c32;
    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__c32 = 0;
    SData/*15:0*/ __Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__mult;
    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__mult = 0;
    CData/*3:0*/ __Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__shift;
    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__shift = 0;
    QData/*47:0*/ __Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__full;
    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__full = 0;
    QData/*47:0*/ __Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__half;
    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__half = 0;
    QData/*47:0*/ __Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__res;
    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__res = 0;
    CData/*7:0*/ __Vtask_ember_top__DOT__u_core__DOT__init_block__7__b;
    __Vtask_ember_top__DOT__u_core__DOT__init_block__7__b = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_gsx__DOT__sat22__37__Vfuncout;
    __Vfunc_ember_top__DOT__u_gsx__DOT__sat22__37__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_gsx__DOT__sat22__37__v;
    __Vfunc_ember_top__DOT__u_gsx__DOT__sat22__37__v = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__Vfuncout;
    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__fb;
    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__fb = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__e;
    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__e = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__i24;
    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__i24 = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__sh;
    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__sh = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_gsx__DOT__sat22__39__Vfuncout;
    __Vfunc_ember_top__DOT__u_gsx__DOT__sat22__39__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_gsx__DOT__sat22__39__v;
    __Vfunc_ember_top__DOT__u_gsx__DOT__sat22__39__v = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__Vfuncout;
    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__fb;
    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__fb = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__e;
    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__e = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__i24;
    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__i24 = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__sh;
    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__sh = 0;
    SData/*15:0*/ __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_z16__41__Vfuncout;
    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_z16__41__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_z16__41__fb;
    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_z16__41__fb = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_z16__41__e;
    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_z16__41__e = 0;
    QData/*39:0*/ __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_z16__41__prod;
    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_z16__41__prod = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__Vfuncout;
    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__fb;
    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__fb = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__e;
    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__e = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__i24;
    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__i24 = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__sh;
    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__sh = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__Vfuncout;
    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__fb;
    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__fb = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__e;
    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__e = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__i24;
    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__i24 = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__sh;
    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__sh = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__98__Vfuncout;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__98__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__98__a;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__98__a = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__98__b;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__98__b = 0;
    SData/*8:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__98__s;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__98__s = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__expand565_r__99__Vfuncout;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__expand565_r__99__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__expand565_r__99__p;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__expand565_r__99__p = 0;
    SData/*15:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__100__Vfuncout;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__100__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__100__w;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__100__w = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__100__hi;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__100__hi = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__101__Vfuncout;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__101__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__101__a;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__101__a = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__101__b;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__101__b = 0;
    SData/*8:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__101__s;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__101__s = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__expand565_g__102__Vfuncout;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__expand565_g__102__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__expand565_g__102__p;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__expand565_g__102__p = 0;
    SData/*15:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__103__Vfuncout;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__103__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__103__w;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__103__w = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__103__hi;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__103__hi = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__104__Vfuncout;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__104__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__104__a;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__104__a = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__104__b;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__104__b = 0;
    SData/*8:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__104__s;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__104__s = 0;
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__expand565_b__105__Vfuncout;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__expand565_b__105__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__expand565_b__105__p;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__expand565_b__105__p = 0;
    SData/*15:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__106__Vfuncout;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__106__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__106__w;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__106__w = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__106__hi;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__106__hi = 0;
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__Vfuncout;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__Vfuncout);
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__num;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__num);
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__den;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__den);
    VlWide<6>/*191:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__n;
    VL_ZERO_W(192, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__n);
    VlWide<6>/*191:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__d;
    VL_ZERO_W(192, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__d);
    VlWide<6>/*191:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__q;
    VL_ZERO_W(192, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__q);
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__Vfuncout;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__Vfuncout);
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__num;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__num);
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__den;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__den);
    VlWide<6>/*191:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__n;
    VL_ZERO_W(192, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__n);
    VlWide<6>/*191:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__d;
    VL_ZERO_W(192, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__d);
    VlWide<6>/*191:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__q;
    VL_ZERO_W(192, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__q);
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__109__Vfuncout;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__109__Vfuncout = 0;
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__109__v;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__109__v);
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__109__t;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__109__t);
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__110__Vfuncout;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__110__Vfuncout = 0;
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__110__v;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__110__v);
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__110__t;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__110__t);
    CData/*7:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__111__Vfuncout;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__111__Vfuncout = 0;
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__111__v;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__111__v);
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__111__t;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__111__t);
    SData/*15:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__112__Vfuncout;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__112__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__112__w;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__112__w = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__112__hi;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__112__hi = 0;
    SData/*15:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__113__Vfuncout;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__113__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__113__w;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__113__w = 0;
    CData/*0:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__113__hi;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__113__hi = 0;
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__Vfuncout;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__Vfuncout);
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__A;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__A = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__B;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__B = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__C;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__C = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__px;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__px = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__py;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__py = 0;
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__s;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__s);
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__sh;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__sh);
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__Vfuncout;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__Vfuncout);
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__A;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__A = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__B;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__B = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__C;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__C = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__px;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__px = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__py;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__py = 0;
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__s;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__s);
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__sh;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__sh);
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__Vfuncout;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__Vfuncout);
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__A;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__A = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__B;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__B = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__C;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__C = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__px;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__px = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__py;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__py = 0;
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__s;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__s);
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__sh;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__sh);
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__Vfuncout;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__Vfuncout);
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__A;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__A = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__B;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__B = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__C;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__C = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__px;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__px = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__py;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__py = 0;
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__s;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__s);
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__sh;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__sh);
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__Vfuncout;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__Vfuncout);
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__A;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__A = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__B;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__B = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__C;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__C = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__px;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__px = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__py;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__py = 0;
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__s;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__s);
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__sh;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__sh);
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__Vfuncout;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__Vfuncout);
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__A;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__A = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__B;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__B = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__C;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__C = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__px;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__px = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__py;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__py = 0;
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__s;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__s);
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__sh;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__sh);
    VlWide<4>/*117:0*/ __VdfgRegularize_h6e95ff9d_0_4;
    VL_ZERO_W(118, __VdfgRegularize_h6e95ff9d_0_4);
    IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_7;
    __VdfgRegularize_h6e95ff9d_0_7 = 0;
    IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_9;
    __VdfgRegularize_h6e95ff9d_0_9 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__abuf_q__v0;
    __VdlyVal__ember_top__DOT__u_tu__DOT__abuf_q__v0 = 0;
    CData/*1:0*/ __VdlyDim0__ember_top__DOT__u_tu__DOT__abuf_q__v0;
    __VdlyDim0__ember_top__DOT__u_tu__DOT__abuf_q__v0 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__wrowbuf__v0;
    __VdlyVal__ember_top__DOT__u_tu__DOT__wrowbuf__v0 = 0;
    CData/*1:0*/ __VdlyDim0__ember_top__DOT__u_tu__DOT__wrowbuf__v0;
    __VdlyDim0__ember_top__DOT__u_tu__DOT__wrowbuf__v0 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v0;
    __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v0 = 0;
    CData/*3:0*/ __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v0;
    __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v0 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v1;
    __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v1 = 0;
    CData/*3:0*/ __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v1;
    __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v1 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v2;
    __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v2 = 0;
    CData/*3:0*/ __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v2;
    __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v2 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v3;
    __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v3 = 0;
    CData/*3:0*/ __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v3;
    __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v3 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v4;
    __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v4 = 0;
    CData/*3:0*/ __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v4;
    __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v4 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v5;
    __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v5 = 0;
    CData/*3:0*/ __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v5;
    __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v5 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v6;
    __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v6 = 0;
    CData/*3:0*/ __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v6;
    __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v6 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v7;
    __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v7 = 0;
    CData/*3:0*/ __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v7;
    __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v7 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v8;
    __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v8 = 0;
    CData/*3:0*/ __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v8;
    __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v8 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v9;
    __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v9 = 0;
    CData/*3:0*/ __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v9;
    __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v9 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v10;
    __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v10 = 0;
    CData/*3:0*/ __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v10;
    __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v10 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v11;
    __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v11 = 0;
    CData/*3:0*/ __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v11;
    __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v11 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v12;
    __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v12 = 0;
    CData/*3:0*/ __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v12;
    __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v12 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v13;
    __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v13 = 0;
    CData/*3:0*/ __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v13;
    __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v13 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v14;
    __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v14 = 0;
    CData/*3:0*/ __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v14;
    __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v14 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v15;
    __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v15 = 0;
    CData/*3:0*/ __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v15;
    __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v15 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__ibuf_w__v0;
    __VdlyVal__ember_top__DOT__u_core__DOT__ibuf_w__v0 = 0;
    CData/*1:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__ibuf_w__v0;
    __VdlyDim0__ember_top__DOT__u_core__DOT__ibuf_w__v0 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v0;
    __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v0 = 0;
    CData/*3:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v0;
    __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v0 = 0;
    CData/*1:0*/ __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v0;
    __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v0 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v1;
    __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v1 = 0;
    CData/*3:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v1;
    __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v1 = 0;
    CData/*1:0*/ __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v1;
    __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v1 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v3;
    __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v3 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v4;
    __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v4 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v7;
    __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v7 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v8;
    __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v8 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v11;
    __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v11 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v12;
    __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v12 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v15;
    __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v15 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v16;
    __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v16 = 0;
    CData/*1:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__T__v12;
    __VdlyDim0__ember_top__DOT__u_core__DOT__T__v12 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v18;
    __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v18 = 0;
    CData/*3:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v18;
    __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v18 = 0;
    CData/*1:0*/ __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v18;
    __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v18 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__fpc__v4;
    __VdlyVal__ember_top__DOT__u_core__DOT__fpc__v4 = 0;
    CData/*1:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v4;
    __VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v4 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__fpc__v5;
    __VdlyVal__ember_top__DOT__u_core__DOT__fpc__v5 = 0;
    CData/*1:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v5;
    __VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v5 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__fpc__v6;
    __VdlyVal__ember_top__DOT__u_core__DOT__fpc__v6 = 0;
    CData/*1:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v6;
    __VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v6 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v19;
    __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v19 = 0;
    CData/*3:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v19;
    __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v19 = 0;
    CData/*1:0*/ __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v19;
    __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v19 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__fpc__v7;
    __VdlyVal__ember_top__DOT__u_core__DOT__fpc__v7 = 0;
    CData/*1:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v7;
    __VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v7 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__fpc__v8;
    __VdlyVal__ember_top__DOT__u_core__DOT__fpc__v8 = 0;
    CData/*1:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v8;
    __VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v8 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__smem__v0;
    __VdlyVal__ember_top__DOT__u_core__DOT__smem__v0 = 0;
    SData/*9:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__smem__v0;
    __VdlyDim0__ember_top__DOT__u_core__DOT__smem__v0 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__smem__v1;
    __VdlyVal__ember_top__DOT__u_core__DOT__smem__v1 = 0;
    SData/*9:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__smem__v1;
    __VdlyDim0__ember_top__DOT__u_core__DOT__smem__v1 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__smem__v2;
    __VdlyVal__ember_top__DOT__u_core__DOT__smem__v2 = 0;
    SData/*9:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__smem__v2;
    __VdlyDim0__ember_top__DOT__u_core__DOT__smem__v2 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v20;
    __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v20 = 0;
    CData/*3:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v20;
    __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v20 = 0;
    CData/*1:0*/ __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v20;
    __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v20 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v21;
    __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v21 = 0;
    CData/*3:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v21;
    __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v21 = 0;
    CData/*1:0*/ __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v21;
    __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v21 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v22;
    __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v22 = 0;
    CData/*3:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v22;
    __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v22 = 0;
    CData/*1:0*/ __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v22;
    __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v22 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v23;
    __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v23 = 0;
    CData/*3:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v23;
    __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v23 = 0;
    CData/*1:0*/ __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v23;
    __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v23 = 0;
    CData/*2:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__T__v13;
    __VdlyVal__ember_top__DOT__u_core__DOT__T__v13 = 0;
    CData/*1:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__T__v13;
    __VdlyDim0__ember_top__DOT__u_core__DOT__T__v13 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v24;
    __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v24 = 0;
    CData/*3:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v24;
    __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v24 = 0;
    CData/*1:0*/ __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v24;
    __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v24 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v25;
    __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v25 = 0;
    CData/*3:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v25;
    __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v25 = 0;
    CData/*1:0*/ __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v25;
    __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v25 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v26;
    __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v26 = 0;
    CData/*3:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v26;
    __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v26 = 0;
    CData/*1:0*/ __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v26;
    __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v26 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v27;
    __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v27 = 0;
    CData/*3:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v27;
    __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v27 = 0;
    CData/*1:0*/ __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v27;
    __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v27 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__fpc__v9;
    __VdlyVal__ember_top__DOT__u_core__DOT__fpc__v9 = 0;
    CData/*1:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v9;
    __VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v9 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v30;
    __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v30 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v34;
    __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v34 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v38;
    __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v38 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v42;
    __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v42 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_gsx__DOT__px__v0;
    __VdlyVal__ember_top__DOT__u_gsx__DOT__px__v0 = 0;
    CData/*1:0*/ __VdlyDim0__ember_top__DOT__u_gsx__DOT__px__v0;
    __VdlyDim0__ember_top__DOT__u_gsx__DOT__px__v0 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_gsx__DOT__py__v0;
    __VdlyVal__ember_top__DOT__u_gsx__DOT__py__v0 = 0;
    CData/*1:0*/ __VdlyDim0__ember_top__DOT__u_gsx__DOT__py__v0;
    __VdlyDim0__ember_top__DOT__u_gsx__DOT__py__v0 = 0;
    SData/*15:0*/ __VdlyVal__ember_top__DOT__u_gsx__DOT__pz__v0;
    __VdlyVal__ember_top__DOT__u_gsx__DOT__pz__v0 = 0;
    CData/*1:0*/ __VdlyDim0__ember_top__DOT__u_gsx__DOT__pz__v0;
    __VdlyDim0__ember_top__DOT__u_gsx__DOT__pz__v0 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_gsx__DOT__pc__v0;
    __VdlyVal__ember_top__DOT__u_gsx__DOT__pc__v0 = 0;
    CData/*1:0*/ __VdlyDim0__ember_top__DOT__u_gsx__DOT__pc__v0;
    __VdlyDim0__ember_top__DOT__u_gsx__DOT__pc__v0 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_gsx__DOT__pu__v0;
    __VdlyVal__ember_top__DOT__u_gsx__DOT__pu__v0 = 0;
    CData/*1:0*/ __VdlyDim0__ember_top__DOT__u_gsx__DOT__pu__v0;
    __VdlyDim0__ember_top__DOT__u_gsx__DOT__pu__v0 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_gsx__DOT__pv__v0;
    __VdlyVal__ember_top__DOT__u_gsx__DOT__pv__v0 = 0;
    CData/*1:0*/ __VdlyDim0__ember_top__DOT__u_gsx__DOT__pv__v0;
    __VdlyDim0__ember_top__DOT__u_gsx__DOT__pv__v0 = 0;
    VlWide<3>/*95:0*/ __Vtemp_1;
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_5;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<6>/*191:0*/ __Vtemp_10;
    VlWide<6>/*191:0*/ __Vtemp_14;
    VlWide<3>/*95:0*/ __Vtemp_15;
    VlWide<3>/*95:0*/ __Vtemp_16;
    VlWide<3>/*95:0*/ __Vtemp_17;
    VlWide<3>/*95:0*/ __Vtemp_18;
    VlWide<3>/*95:0*/ __Vtemp_19;
    VlWide<3>/*95:0*/ __Vtemp_21;
    VlWide<3>/*95:0*/ __Vtemp_22;
    VlWide<3>/*95:0*/ __Vtemp_23;
    VlWide<3>/*95:0*/ __Vtemp_24;
    VlWide<3>/*95:0*/ __Vtemp_25;
    VlWide<3>/*95:0*/ __Vtemp_26;
    VlWide<3>/*95:0*/ __Vtemp_27;
    VlWide<3>/*95:0*/ __Vtemp_28;
    VlWide<3>/*95:0*/ __Vtemp_29;
    VlWide<3>/*95:0*/ __Vtemp_30;
    VlWide<3>/*95:0*/ __Vtemp_31;
    VlWide<3>/*95:0*/ __Vtemp_32;
    VlWide<3>/*95:0*/ __Vtemp_33;
    VlWide<3>/*95:0*/ __Vtemp_34;
    VlWide<3>/*95:0*/ __Vtemp_35;
    VlWide<3>/*95:0*/ __Vtemp_37;
    VlWide<3>/*95:0*/ __Vtemp_38;
    VlWide<3>/*95:0*/ __Vtemp_39;
    VlWide<3>/*95:0*/ __Vtemp_40;
    VlWide<3>/*95:0*/ __Vtemp_41;
    VlWide<3>/*95:0*/ __Vtemp_42;
    VlWide<3>/*95:0*/ __Vtemp_43;
    VlWide<3>/*95:0*/ __Vtemp_44;
    VlWide<3>/*95:0*/ __Vtemp_45;
    VlWide<3>/*95:0*/ __Vtemp_46;
    VlWide<3>/*95:0*/ __Vtemp_47;
    VlWide<3>/*95:0*/ __Vtemp_48;
    VlWide<3>/*95:0*/ __Vtemp_49;
    VlWide<3>/*95:0*/ __Vtemp_50;
    VlWide<3>/*95:0*/ __Vtemp_51;
    VlWide<3>/*95:0*/ __Vtemp_53;
    VlWide<3>/*95:0*/ __Vtemp_54;
    VlWide<3>/*95:0*/ __Vtemp_55;
    VlWide<3>/*95:0*/ __Vtemp_56;
    VlWide<3>/*95:0*/ __Vtemp_57;
    VlWide<3>/*95:0*/ __Vtemp_58;
    VlWide<3>/*95:0*/ __Vtemp_59;
    VlWide<3>/*95:0*/ __Vtemp_60;
    VlWide<3>/*95:0*/ __Vtemp_61;
    VlWide<3>/*95:0*/ __Vtemp_62;
    VlWide<3>/*95:0*/ __Vtemp_63;
    VlWide<3>/*95:0*/ __Vtemp_64;
    VlWide<3>/*95:0*/ __Vtemp_65;
    VlWide<3>/*95:0*/ __Vtemp_66;
    VlWide<3>/*95:0*/ __Vtemp_67;
    VlWide<3>/*95:0*/ __Vtemp_69;
    VlWide<3>/*95:0*/ __Vtemp_70;
    VlWide<3>/*95:0*/ __Vtemp_71;
    VlWide<3>/*95:0*/ __Vtemp_72;
    VlWide<3>/*95:0*/ __Vtemp_73;
    VlWide<3>/*95:0*/ __Vtemp_74;
    VlWide<3>/*95:0*/ __Vtemp_75;
    VlWide<3>/*95:0*/ __Vtemp_76;
    VlWide<3>/*95:0*/ __Vtemp_77;
    VlWide<3>/*95:0*/ __Vtemp_78;
    VlWide<3>/*95:0*/ __Vtemp_79;
    VlWide<3>/*95:0*/ __Vtemp_80;
    VlWide<3>/*95:0*/ __Vtemp_81;
    VlWide<3>/*95:0*/ __Vtemp_82;
    VlWide<3>/*95:0*/ __Vtemp_83;
    VlWide<3>/*95:0*/ __Vtemp_84;
    VlWide<3>/*95:0*/ __Vtemp_85;
    VlWide<3>/*95:0*/ __Vtemp_86;
    VlWide<3>/*95:0*/ __Vtemp_87;
    VlWide<3>/*95:0*/ __Vtemp_88;
    VlWide<3>/*95:0*/ __Vtemp_89;
    VlWide<3>/*95:0*/ __Vtemp_90;
    VlWide<3>/*95:0*/ __Vtemp_91;
    VlWide<3>/*95:0*/ __Vtemp_92;
    VlWide<3>/*95:0*/ __Vtemp_93;
    VlWide<3>/*95:0*/ __Vtemp_94;
    VlWide<3>/*95:0*/ __Vtemp_95;
    VlWide<3>/*95:0*/ __Vtemp_96;
    VlWide<3>/*95:0*/ __Vtemp_97;
    VlWide<3>/*95:0*/ __Vtemp_98;
    VlWide<3>/*95:0*/ __Vtemp_99;
    VlWide<3>/*95:0*/ __Vtemp_100;
    VlWide<3>/*95:0*/ __Vtemp_101;
    VlWide<3>/*95:0*/ __Vtemp_102;
    VlWide<3>/*95:0*/ __Vtemp_103;
    VlWide<3>/*95:0*/ __Vtemp_104;
    VlWide<3>/*95:0*/ __Vtemp_105;
    VlWide<3>/*95:0*/ __Vtemp_106;
    VlWide<3>/*95:0*/ __Vtemp_107;
    VlWide<3>/*95:0*/ __Vtemp_108;
    VlWide<3>/*95:0*/ __Vtemp_109;
    VlWide<3>/*95:0*/ __Vtemp_110;
    VlWide<3>/*95:0*/ __Vtemp_111;
    VlWide<3>/*95:0*/ __Vtemp_112;
    VlWide<3>/*95:0*/ __Vtemp_113;
    VlWide<3>/*95:0*/ __Vtemp_114;
    VlWide<3>/*95:0*/ __Vtemp_115;
    VlWide<3>/*95:0*/ __Vtemp_116;
    VlWide<3>/*95:0*/ __Vtemp_117;
    VlWide<3>/*95:0*/ __Vtemp_118;
    VlWide<3>/*95:0*/ __Vtemp_119;
    VlWide<3>/*95:0*/ __Vtemp_120;
    VlWide<3>/*95:0*/ __Vtemp_121;
    VlWide<3>/*95:0*/ __Vtemp_122;
    VlWide<3>/*95:0*/ __Vtemp_123;
    VlWide<3>/*95:0*/ __Vtemp_124;
    VlWide<3>/*95:0*/ __Vtemp_125;
    VlWide<3>/*95:0*/ __Vtemp_126;
    VlWide<3>/*95:0*/ __Vtemp_127;
    VlWide<3>/*95:0*/ __Vtemp_128;
    VlWide<3>/*95:0*/ __Vtemp_129;
    VlWide<3>/*95:0*/ __Vtemp_130;
    VlWide<3>/*95:0*/ __Vtemp_131;
    VlWide<3>/*95:0*/ __Vtemp_132;
    VlWide<3>/*95:0*/ __Vtemp_133;
    VlWide<3>/*95:0*/ __Vtemp_134;
    VlWide<3>/*95:0*/ __Vtemp_135;
    VlWide<3>/*95:0*/ __Vtemp_136;
    VlWide<3>/*95:0*/ __Vtemp_137;
    VlWide<3>/*95:0*/ __Vtemp_138;
    VlWide<3>/*95:0*/ __Vtemp_139;
    VlWide<3>/*95:0*/ __Vtemp_140;
    VlWide<3>/*95:0*/ __Vtemp_141;
    VlWide<3>/*95:0*/ __Vtemp_142;
    VlWide<3>/*95:0*/ __Vtemp_143;
    VlWide<3>/*95:0*/ __Vtemp_144;
    VlWide<3>/*95:0*/ __Vtemp_145;
    VlWide<3>/*95:0*/ __Vtemp_146;
    VlWide<3>/*95:0*/ __Vtemp_147;
    VlWide<3>/*95:0*/ __Vtemp_148;
    VlWide<3>/*95:0*/ __Vtemp_149;
    VlWide<3>/*95:0*/ __Vtemp_150;
    VlWide<3>/*95:0*/ __Vtemp_151;
    VlWide<3>/*95:0*/ __Vtemp_152;
    VlWide<3>/*95:0*/ __Vtemp_153;
    VlWide<3>/*95:0*/ __Vtemp_154;
    VlWide<3>/*95:0*/ __Vtemp_155;
    VlWide<3>/*95:0*/ __Vtemp_156;
    VlWide<3>/*95:0*/ __Vtemp_157;
    VlWide<3>/*95:0*/ __Vtemp_158;
    VlWide<3>/*95:0*/ __Vtemp_159;
    VlWide<3>/*95:0*/ __Vtemp_160;
    VlWide<3>/*95:0*/ __Vtemp_161;
    VlWide<3>/*95:0*/ __Vtemp_162;
    VlWide<3>/*95:0*/ __Vtemp_163;
    VlWide<3>/*95:0*/ __Vtemp_164;
    VlWide<3>/*95:0*/ __Vtemp_165;
    VlWide<3>/*95:0*/ __Vtemp_169;
    VlWide<3>/*95:0*/ __Vtemp_170;
    VlWide<3>/*95:0*/ __Vtemp_172;
    VlWide<3>/*95:0*/ __Vtemp_173;
    VlWide<3>/*95:0*/ __Vtemp_174;
    VlWide<3>/*95:0*/ __Vtemp_175;
    VlWide<3>/*95:0*/ __Vtemp_176;
    VlWide<3>/*95:0*/ __Vtemp_179;
    VlWide<3>/*95:0*/ __Vtemp_180;
    VlWide<3>/*95:0*/ __Vtemp_182;
    VlWide<3>/*95:0*/ __Vtemp_183;
    VlWide<3>/*95:0*/ __Vtemp_184;
    VlWide<3>/*95:0*/ __Vtemp_185;
    VlWide<3>/*95:0*/ __Vtemp_186;
    VlWide<3>/*95:0*/ __Vtemp_187;
    VlWide<3>/*95:0*/ __Vtemp_193;
    VlWide<3>/*95:0*/ __Vtemp_194;
    VlWide<3>/*95:0*/ __Vtemp_195;
    VlWide<3>/*95:0*/ __Vtemp_196;
    VlWide<3>/*95:0*/ __Vtemp_197;
    VlWide<4>/*127:0*/ __Vtemp_198;
    VlWide<4>/*127:0*/ __Vtemp_199;
    VlWide<4>/*127:0*/ __Vtemp_200;
    VlWide<4>/*127:0*/ __Vtemp_201;
    VlWide<3>/*95:0*/ __Vtemp_205;
    VlWide<3>/*95:0*/ __Vtemp_206;
    VlWide<3>/*95:0*/ __Vtemp_207;
    VlWide<3>/*95:0*/ __Vtemp_208;
    VlWide<3>/*95:0*/ __Vtemp_209;
    VlWide<4>/*127:0*/ __Vtemp_210;
    VlWide<4>/*127:0*/ __Vtemp_211;
    VlWide<4>/*127:0*/ __Vtemp_212;
    VlWide<4>/*127:0*/ __Vtemp_213;
    VlWide<3>/*95:0*/ __Vtemp_217;
    VlWide<3>/*95:0*/ __Vtemp_218;
    VlWide<3>/*95:0*/ __Vtemp_219;
    VlWide<3>/*95:0*/ __Vtemp_220;
    VlWide<3>/*95:0*/ __Vtemp_221;
    VlWide<4>/*127:0*/ __Vtemp_222;
    VlWide<4>/*127:0*/ __Vtemp_223;
    VlWide<4>/*127:0*/ __Vtemp_224;
    VlWide<4>/*127:0*/ __Vtemp_225;
    VlWide<3>/*95:0*/ __Vtemp_229;
    VlWide<3>/*95:0*/ __Vtemp_230;
    VlWide<3>/*95:0*/ __Vtemp_231;
    VlWide<3>/*95:0*/ __Vtemp_232;
    VlWide<3>/*95:0*/ __Vtemp_233;
    VlWide<4>/*127:0*/ __Vtemp_234;
    VlWide<4>/*127:0*/ __Vtemp_235;
    VlWide<4>/*127:0*/ __Vtemp_236;
    VlWide<4>/*127:0*/ __Vtemp_237;
    VlWide<3>/*95:0*/ __Vtemp_241;
    VlWide<3>/*95:0*/ __Vtemp_242;
    VlWide<3>/*95:0*/ __Vtemp_243;
    VlWide<3>/*95:0*/ __Vtemp_244;
    VlWide<3>/*95:0*/ __Vtemp_245;
    VlWide<4>/*127:0*/ __Vtemp_246;
    VlWide<4>/*127:0*/ __Vtemp_247;
    VlWide<4>/*127:0*/ __Vtemp_248;
    VlWide<4>/*127:0*/ __Vtemp_249;
    VlWide<3>/*95:0*/ __Vtemp_253;
    VlWide<3>/*95:0*/ __Vtemp_254;
    VlWide<3>/*95:0*/ __Vtemp_255;
    VlWide<3>/*95:0*/ __Vtemp_256;
    VlWide<3>/*95:0*/ __Vtemp_257;
    VlWide<4>/*127:0*/ __Vtemp_258;
    VlWide<4>/*127:0*/ __Vtemp_259;
    VlWide<4>/*127:0*/ __Vtemp_260;
    VlWide<4>/*127:0*/ __Vtemp_261;
    VlWide<3>/*95:0*/ __Vtemp_265;
    VlWide<3>/*95:0*/ __Vtemp_266;
    VlWide<3>/*95:0*/ __Vtemp_267;
    VlWide<3>/*95:0*/ __Vtemp_268;
    VlWide<3>/*95:0*/ __Vtemp_269;
    VlWide<4>/*127:0*/ __Vtemp_270;
    VlWide<4>/*127:0*/ __Vtemp_271;
    VlWide<4>/*127:0*/ __Vtemp_272;
    VlWide<4>/*127:0*/ __Vtemp_273;
    VlWide<3>/*95:0*/ __Vtemp_277;
    VlWide<3>/*95:0*/ __Vtemp_278;
    VlWide<3>/*95:0*/ __Vtemp_279;
    VlWide<3>/*95:0*/ __Vtemp_280;
    VlWide<3>/*95:0*/ __Vtemp_281;
    VlWide<4>/*127:0*/ __Vtemp_282;
    VlWide<4>/*127:0*/ __Vtemp_283;
    VlWide<4>/*127:0*/ __Vtemp_284;
    VlWide<4>/*127:0*/ __Vtemp_285;
    VlWide<3>/*95:0*/ __Vtemp_289;
    VlWide<3>/*95:0*/ __Vtemp_290;
    VlWide<3>/*95:0*/ __Vtemp_291;
    VlWide<3>/*95:0*/ __Vtemp_292;
    VlWide<3>/*95:0*/ __Vtemp_293;
    VlWide<4>/*127:0*/ __Vtemp_294;
    VlWide<4>/*127:0*/ __Vtemp_295;
    VlWide<4>/*127:0*/ __Vtemp_296;
    VlWide<4>/*127:0*/ __Vtemp_297;
    VlWide<3>/*95:0*/ __Vtemp_301;
    VlWide<3>/*95:0*/ __Vtemp_302;
    VlWide<3>/*95:0*/ __Vtemp_303;
    VlWide<3>/*95:0*/ __Vtemp_304;
    VlWide<3>/*95:0*/ __Vtemp_305;
    VlWide<4>/*127:0*/ __Vtemp_306;
    VlWide<4>/*127:0*/ __Vtemp_307;
    VlWide<4>/*127:0*/ __Vtemp_308;
    VlWide<4>/*127:0*/ __Vtemp_309;
    VlWide<3>/*95:0*/ __Vtemp_313;
    VlWide<3>/*95:0*/ __Vtemp_314;
    VlWide<3>/*95:0*/ __Vtemp_315;
    VlWide<3>/*95:0*/ __Vtemp_316;
    VlWide<3>/*95:0*/ __Vtemp_317;
    VlWide<4>/*127:0*/ __Vtemp_318;
    VlWide<4>/*127:0*/ __Vtemp_319;
    VlWide<4>/*127:0*/ __Vtemp_320;
    VlWide<4>/*127:0*/ __Vtemp_321;
    VlWide<3>/*95:0*/ __Vtemp_325;
    VlWide<3>/*95:0*/ __Vtemp_326;
    VlWide<3>/*95:0*/ __Vtemp_327;
    VlWide<3>/*95:0*/ __Vtemp_328;
    VlWide<3>/*95:0*/ __Vtemp_329;
    VlWide<4>/*127:0*/ __Vtemp_330;
    VlWide<4>/*127:0*/ __Vtemp_331;
    VlWide<4>/*127:0*/ __Vtemp_332;
    VlWide<4>/*127:0*/ __Vtemp_333;
    // Body
    vlSelfRef.ember_top__DOT__u_gsx__DOT__mata_ptr 
        = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__mata_ptr;
    vlSelfRef.ember_top__DOT__u_gsx__DOT__vtx_ptr = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__vtx_ptr;
    vlSelfRef.ember_top__DOT__u_gsx__DOT__col_ptr = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__col_ptr;
    vlSelfRef.ember_top__DOT__u_vram__DOT__wr_fire 
        = ((IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__aw_v) 
           & ((IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__w_v) 
              & ((~ (IData)(vlSelfRef.ember_top__DOT__v_bvalid)) 
                 | (IData)(vlSelfRef.ember_top__DOT__v_bready))));
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_cp__DOT__rb_mem__v0) {
        vlSelfRef.ember_top__DOT__u_cp__DOT__rb_mem[vlSelfRef.__VdlyDim0__ember_top__DOT__u_cp__DOT__rb_mem__v0] 
            = vlSelfRef.__VdlyVal__ember_top__DOT__u_cp__DOT__rb_mem__v0;
    }
    vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__ar_accept 
        = ((IData)(vlSelfRef.ember_top__DOT__c_arvalid) 
           & (IData)(vlSelfRef.ember_top__DOT__c_arready));
    vlSelfRef.ember_top__DOT__u_cp__DOT__rb_wp = vlSelfRef.__Vdly__ember_top__DOT__u_cp__DOT__rb_wp;
    vlSelfRef.ember_top__DOT__u_cp__DOT__rb_rp = vlSelfRef.__Vdly__ember_top__DOT__u_cp__DOT__rb_rp;
    if (vlSelfRef.rst_n) {
        if (((IData)(vlSelfRef.ember_top__DOT__v_awvalid) 
             & (IData)(vlSelfRef.ember_top__DOT__v_awready))) {
            vlSelfRef.ember_top__DOT__u_vram__DOT__aw_q 
                = ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_h)
                    ? ((QData)((IData)(vlSelfRef.h_awaddr)) 
                       << 3U) : vlSelfRef.ember_top__DOT__d_aw);
        }
        if (((IData)(vlSelfRef.ember_top__DOT__v_wvalid) 
             & (IData)(vlSelfRef.ember_top__DOT__v_wready))) {
            vlSelfRef.ember_top__DOT__u_vram__DOT__w_q 
                = ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_h)
                    ? vlSelfRef.ember_top__DOT__h_w_s
                    : vlSelfRef.ember_top__DOT__d_w);
        }
    } else {
        vlSelfRef.ember_top__DOT__u_vram__DOT__aw_q = 0ULL;
        vlSelfRef.ember_top__DOT__u_vram__DOT__w_q = 0ULL;
    }
    if (vlSelfRef.rst_n) {
        vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_done = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__scan_fpa_req = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_we = 0U;
        vlSelfRef.ember_top__DOT__fpa2_req = 0U;
        if ((8U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__st))) {
            if ((4U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__st))) {
                if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__st))) {
                    vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 0U;
                } else if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__st))) {
                    if (((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__ix) 
                         == ((0x0000013fU < vlSelfRef.__VdfgRegularize_h6e95ff9d_0_8)
                              ? 0U : (VL_GTS_III(32, 0U, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_8)
                                       ? 0U : (0x0000ffffU 
                                               & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_8))))) {
                        if (((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__iy) 
                             == ((0x000000efU < vlSelfRef.__VdfgRegularize_h6e95ff9d_0_10)
                                  ? 0U : (VL_GTS_III(32, 0U, vlSelfRef.__VdfgRegularize_h6e95ff9d_0_10)
                                           ? 0U : (0x0000ffffU 
                                                   & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_10))))) {
                            vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_done = 1U;
                            vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 0U;
                        } else {
                            vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__iy 
                                = (0x0000ffffU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__iy)));
                            vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy 
                                = (0x0000000000400000ULL 
                                   + vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy);
                            vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__ix 
                                = vlSelfRef.ember_top__DOT__u_rtr__DOT__x_lo_i;
                            vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx 
                                = (0x0000000000200000ULL 
                                   + VL_SHIFTL_QQI(64,64,32, 
                                                   (((- (QData)((IData)(
                                                                        (1U 
                                                                         & ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__x_lo_i) 
                                                                            >> 0x0fU))))) 
                                                     << 0x00000010U) 
                                                    | (QData)((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__x_lo_i))), 0x00000016U));
                            vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 1U;
                        }
                    } else {
                        vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__ix 
                            = (0x0000ffffU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__ix)));
                        vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx 
                            = (0x0000000000400000ULL 
                               + vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx);
                        vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 1U;
                    }
                } else {
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_we = 1U;
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_addr 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__zaddr;
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_be 
                        = ((2U & vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__pix_off)
                            ? 0x0cU : 3U);
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_wdata 
                        = ((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__z_v[0U] 
                            << 0x00000010U) | (0x0000ffffU 
                                               & vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__z_v[0U]));
                    vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 0x0dU;
                }
            } else if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__st))) {
                if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__st))) {
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_we = 1U;
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_addr 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__faddr;
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_be 
                        = ((2U & vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__pix_off)
                            ? 0x0cU : 3U);
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_wdata 
                        = ((0x00000020U & vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[0U])
                            ? ((((0x0000f800U & ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmb) 
                                                 << 8U)) 
                                 | ((0x000007e0U & 
                                     ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmg) 
                                      << 3U)) | (0x0000001fU 
                                                 & ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmr) 
                                                    >> 3U)))) 
                                << 0x00000010U) | (
                                                   (0x0000f800U 
                                                    & ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmb) 
                                                       << 8U)) 
                                                   | ((0x000007e0U 
                                                       & ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmg) 
                                                          << 3U)) 
                                                      | (0x0000001fU 
                                                         & ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmr) 
                                                            >> 3U)))))
                            : ((((0x0000f800U & ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmr) 
                                                 << 8U)) 
                                 | ((0x000007e0U & 
                                     ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmg) 
                                      << 3U)) | (0x0000001fU 
                                                 & ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmb) 
                                                    >> 3U)))) 
                                << 0x00000010U) | (
                                                   (0x0000f800U 
                                                    & ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmr) 
                                                       << 8U)) 
                                                   | ((0x000007e0U 
                                                       & ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmg) 
                                                          << 3U)) 
                                                      | (0x0000001fU 
                                                         & ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmb) 
                                                            >> 3U))))));
                    vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st 
                        = (((vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[0U] 
                             >> 2U) & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__z_pass))
                            ? 0x0cU : 0x0dU);
                } else {
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__100__hi 
                        = (1U & (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__pix_off 
                                 >> 1U));
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__103__hi 
                        = (1U & (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__pix_off 
                                 >> 1U));
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__106__hi 
                        = (1U & (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__pix_off 
                                 >> 1U));
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__100__w 
                        = vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_rdata_q;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__103__w 
                        = vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_rdata_q;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__106__w 
                        = vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_rdata_q;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__100__Vfuncout 
                        = (0x0000ffffU & ((IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__100__hi)
                                           ? (__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__100__w 
                                              >> 0x10U)
                                           : __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__100__w));
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__103__Vfuncout 
                        = (0x0000ffffU & ((IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__103__hi)
                                           ? (__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__103__w 
                                              >> 0x10U)
                                           : __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__103__w));
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__106__Vfuncout 
                        = (0x0000ffffU & ((IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__106__hi)
                                           ? (__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__106__w 
                                              >> 0x10U)
                                           : __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__106__w));
                    vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 0x0bU;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__expand565_r__99__p 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__100__Vfuncout;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__expand565_g__102__p 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__103__Vfuncout;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__expand565_b__105__p 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__106__Vfuncout;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__expand565_r__99__Vfuncout 
                        = (0x000000f8U & ((IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__expand565_r__99__p) 
                                          >> 8U));
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__expand565_g__102__Vfuncout 
                        = (0x000000fcU & ((IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__expand565_g__102__p) 
                                          >> 3U));
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__expand565_b__105__Vfuncout 
                        = (0x000000f8U & ((IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__expand565_b__105__p) 
                                          << 3U));
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__98__b 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__expand565_r__99__Vfuncout;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__101__b 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__expand565_g__102__Vfuncout;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__104__b 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__expand565_b__105__Vfuncout;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__98__a 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cr;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__101__a 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cg;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__104__a 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cb;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__98__s 
                        = (0x000001ffU & ((IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__98__a) 
                                          + (IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__98__b)));
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__101__s 
                        = (0x000001ffU & ((IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__101__a) 
                                          + (IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__101__b)));
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__104__s 
                        = (0x000001ffU & ((IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__104__a) 
                                          + (IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__104__b)));
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__98__Vfuncout 
                        = (0x000000ffU & ((IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__98__s) 
                                          >> 1U));
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__101__Vfuncout 
                        = (0x000000ffU & ((IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__101__s) 
                                          >> 1U));
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__104__Vfuncout 
                        = (0x000000ffU & ((IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__104__s) 
                                          >> 1U));
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__mr 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__98__Vfuncout;
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__mg 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__101__Vfuncout;
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__mb 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__avg2__104__Vfuncout;
                }
            } else if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__st))) {
                vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 0x0aU;
            } else {
                vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__scan_fpa_req = 1U;
                vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_addr 
                    = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__faddr;
                vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 9U;
            }
        } else if ((4U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__st))) {
            if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__st))) {
                if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__st))) {
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cr 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__texel_byte;
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cg 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__texel_byte;
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cb 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__texel_byte;
                    vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st 
                        = ((2U & vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[0U])
                            ? 8U : 0x0bU);
                } else {
                    vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 7U;
                }
            } else if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__st))) {
                vlSelfRef.ember_top__DOT__fpa2_req = 1U;
                vlSelfRef.ember_top__DOT__fpa2_addr 
                    = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__tex_addr;
                vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 6U;
            } else {
                __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__den[0U] 
                    = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__inv_w_v[0U];
                __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__den[1U] 
                    = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__inv_w_v[1U];
                __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__den[2U] 
                    = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__inv_w_v[2U];
                __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__den[0U] 
                    = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__inv_w_v[0U];
                __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__den[1U] 
                    = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__inv_w_v[1U];
                __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__den[2U] 
                    = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__inv_w_v[2U];
                __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__num[0U] 
                    = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__u_raw[0U];
                __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__num[1U] 
                    = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__u_raw[1U];
                __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__num[2U] 
                    = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__u_raw[2U];
                __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__num[0U] 
                    = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__v_raw[0U];
                __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__num[1U] 
                    = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__v_raw[1U];
                __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__num[2U] 
                    = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__v_raw[2U];
                VL_ZERO_W(192, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__n);
                VL_ZERO_W(192, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__n);
                if ((8U & vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[0U])) {
                    vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 5U;
                } else {
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__109__v[0U] 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__r_v[0U];
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__109__v[1U] 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__r_v[1U];
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__109__v[2U] 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__r_v[2U];
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__110__v[0U] 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__g_v[0U];
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__110__v[1U] 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__g_v[1U];
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__110__v[2U] 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__g_v[2U];
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__111__v[0U] 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__b_v[0U];
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__111__v[1U] 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__b_v[1U];
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__111__v[2U] 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__b_v[2U];
                    VL_SHIFTRS_WWI(96,96,32, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__109__t, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__109__v, 0x00000016U);
                    VL_SHIFTRS_WWI(96,96,32, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__110__t, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__110__v, 0x00000016U);
                    VL_SHIFTRS_WWI(96,96,32, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__111__t, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__111__v, 0x00000016U);
                    __Vtemp_1[0U] = 0U;
                    __Vtemp_1[1U] = 0U;
                    __Vtemp_1[2U] = 0U;
                    __Vtemp_2[0U] = 0x000000ffU;
                    __Vtemp_2[1U] = 0U;
                    __Vtemp_2[2U] = 0U;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__109__Vfuncout 
                        = (VL_GTS_IWW(96, __Vtemp_1, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__109__t)
                            ? 0U : (VL_LTS_IWW(96, __Vtemp_2, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__109__t)
                                     ? 0x000000ffU : 
                                    (0x000000ffU & __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__109__t[0U])));
                    __Vtemp_3[0U] = 0U;
                    __Vtemp_3[1U] = 0U;
                    __Vtemp_3[2U] = 0U;
                    __Vtemp_4[0U] = 0x000000ffU;
                    __Vtemp_4[1U] = 0U;
                    __Vtemp_4[2U] = 0U;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__110__Vfuncout 
                        = (VL_GTS_IWW(96, __Vtemp_3, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__110__t)
                            ? 0U : (VL_LTS_IWW(96, __Vtemp_4, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__110__t)
                                     ? 0x000000ffU : 
                                    (0x000000ffU & __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__110__t[0U])));
                    __Vtemp_5[0U] = 0U;
                    __Vtemp_5[1U] = 0U;
                    __Vtemp_5[2U] = 0U;
                    __Vtemp_6[0U] = 0x000000ffU;
                    __Vtemp_6[1U] = 0U;
                    __Vtemp_6[2U] = 0U;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__111__Vfuncout 
                        = (VL_GTS_IWW(96, __Vtemp_5, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__111__t)
                            ? 0U : (VL_LTS_IWW(96, __Vtemp_6, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__111__t)
                                     ? 0x000000ffU : 
                                    (0x000000ffU & __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__111__t[0U])));
                    vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st 
                        = ((2U & vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[0U])
                            ? 8U : 0x0bU);
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cr 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__109__Vfuncout;
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cg 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__110__Vfuncout;
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cb 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__clamp8__111__Vfuncout;
                }
                VL_ZERO_W(192, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__d);
                VL_ZERO_W(192, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__d);
                VL_ZERO_W(192, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__q);
                VL_ZERO_W(192, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__q);
                if ((0U == ((__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__den[0U] 
                             | __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__den[1U]) 
                            | __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__den[2U]))) {
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__Vfuncout[0U] = 0U;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__Vfuncout[1U] = 0U;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__Vfuncout[2U] = 0U;
                } else {
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__n[0U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__num[0U];
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__n[1U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__num[1U];
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__n[2U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__num[2U];
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__n[3U] 
                        = (- (IData)((__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__num[2U] 
                                      >> 0x0000001fU)));
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__n[4U] 
                        = (- (IData)((__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__num[2U] 
                                      >> 0x0000001fU)));
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__n[5U] 
                        = (- (IData)((__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__num[2U] 
                                      >> 0x0000001fU)));
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__d[0U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__den[0U];
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__d[1U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__den[1U];
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__d[2U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__den[2U];
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__d[3U] 
                        = (- (IData)((__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__den[2U] 
                                      >> 0x0000001fU)));
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__d[4U] 
                        = (- (IData)((__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__den[2U] 
                                      >> 0x0000001fU)));
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__d[5U] 
                        = (- (IData)((__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__den[2U] 
                                      >> 0x0000001fU)));
                    VL_SHIFTL_WWI(192,192,32, __Vtemp_10, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__n, 0x00000016U);
                    VL_DIVS_WWW(192, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__q, __Vtemp_10, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__d);
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__Vfuncout[0U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__q[0U];
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__Vfuncout[1U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__q[1U];
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__Vfuncout[2U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__q[2U];
                }
                if ((0U == ((__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__den[0U] 
                             | __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__den[1U]) 
                            | __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__den[2U]))) {
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__Vfuncout[0U] = 0U;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__Vfuncout[1U] = 0U;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__Vfuncout[2U] = 0U;
                } else {
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__n[0U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__num[0U];
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__n[1U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__num[1U];
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__n[2U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__num[2U];
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__n[3U] 
                        = (- (IData)((__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__num[2U] 
                                      >> 0x0000001fU)));
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__n[4U] 
                        = (- (IData)((__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__num[2U] 
                                      >> 0x0000001fU)));
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__n[5U] 
                        = (- (IData)((__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__num[2U] 
                                      >> 0x0000001fU)));
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__d[0U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__den[0U];
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__d[1U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__den[1U];
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__d[2U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__den[2U];
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__d[3U] 
                        = (- (IData)((__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__den[2U] 
                                      >> 0x0000001fU)));
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__d[4U] 
                        = (- (IData)((__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__den[2U] 
                                      >> 0x0000001fU)));
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__d[5U] 
                        = (- (IData)((__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__den[2U] 
                                      >> 0x0000001fU)));
                    VL_SHIFTL_WWI(192,192,32, __Vtemp_14, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__n, 0x00000016U);
                    VL_DIVS_WWW(192, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__q, __Vtemp_14, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__d);
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__Vfuncout[0U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__q[0U];
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__Vfuncout[1U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__q[1U];
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__Vfuncout[2U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__q[2U];
                }
                vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__u_fin[0U] 
                    = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__Vfuncout[0U];
                vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__u_fin[1U] 
                    = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__Vfuncout[1U];
                vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__u_fin[2U] 
                    = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__107__Vfuncout[2U];
                vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__v_fin[0U] 
                    = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__Vfuncout[0U];
                vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__v_fin[1U] 
                    = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__Vfuncout[1U];
                vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__v_fin[2U] 
                    = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__pdiv__108__Vfuncout[2U];
            }
        } else if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__st))) {
            if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__st))) {
                VL_EXTEND_WI(96,16, __Vtemp_15, ([&]() {
                            __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__112__hi 
                                = (1U & (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__pix_off 
                                         >> 1U));
                            __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__112__w 
                                = vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_rdata_q;
                            __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__112__Vfuncout 
                                = (0x0000ffffU & ((IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__112__hi)
                                                   ? 
                                                  (__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__112__w 
                                                   >> 0x10U)
                                                   : __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__112__w));
                        }(), (IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__112__Vfuncout)));
                vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__z_pass 
                    = VL_LTS_IWW(96, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__z_v, __Vtemp_15);
                VL_EXTEND_WI(96,16, __Vtemp_16, ([&]() {
                            __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__113__hi 
                                = (1U & (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__pix_off 
                                         >> 1U));
                            __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__113__w 
                                = vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_rdata_q;
                            __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__113__Vfuncout 
                                = (0x0000ffffU & ((IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__113__hi)
                                                   ? 
                                                  (__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__113__w 
                                                   >> 0x10U)
                                                   : __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__113__w));
                        }(), (IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__113__Vfuncout)));
                vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st 
                    = (VL_GTES_IWW(96, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__z_v, __Vtemp_16)
                        ? 0x0dU : 4U);
            } else {
                __Vtemp_17[0U] = 0U;
                __Vtemp_17[1U] = 0U;
                __Vtemp_17[2U] = 0U;
                __Vtemp_18[0U] = 0U;
                __Vtemp_18[1U] = 0U;
                __Vtemp_18[2U] = 0U;
                __Vtemp_19[0U] = 0U;
                __Vtemp_19[1U] = 0U;
                __Vtemp_19[2U] = 0U;
                if (((VL_LTS_IWW(96, __Vtemp_17, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__e01) 
                      & VL_LTS_IWW(96, __Vtemp_18, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__e12)) 
                     & VL_LTS_IWW(96, __Vtemp_19, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__e20))) {
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__zaddr 
                        = ((IData)(0x00026800U) + (0xfffffffcU 
                                                   & vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__pix_off));
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__faddr 
                        = ((IData)(0x00001000U) + (0xfffffffcU 
                                                   & vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__pix_off));
                    vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st 
                        = ((4U & vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[0U])
                            ? 3U : 4U);
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__inv_w_v[0U] = 0x00400000U;
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__inv_w_v[1U] = 0U;
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__inv_w_v[2U] = 0U;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__py 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__px 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx;
                    VL_EXTENDS_WQ(96,64, __Vtemp_21, vlSelfRef.ember_top__DOT__u_rtr__DOT__rA);
                    VL_EXTENDS_WI(96,32, __Vtemp_22, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[1U]);
                    VL_MULS_WWW(96, __Vtemp_23, __Vtemp_21, __Vtemp_22);
                    VL_EXTENDS_WQ(96,64, __Vtemp_24, vlSelfRef.ember_top__DOT__u_rtr__DOT__rB);
                    VL_EXTENDS_WI(96,32, __Vtemp_25, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[2U]);
                    VL_MULS_WWW(96, __Vtemp_26, __Vtemp_24, __Vtemp_25);
                    VL_ADD_W(3, __Vtemp_27, __Vtemp_23, __Vtemp_26);
                    VL_SHIFTRS_WWI(96,96,32, __Vtemp_28, __Vtemp_27, 0x00000016U);
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__C 
                        = ((QData)((IData)((0x3fc00000U 
                                            & (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[10U] 
                                               << 0x00000016U)))) 
                           - (((QData)((IData)(__Vtemp_28[1U])) 
                               << 0x00000020U) | (QData)((IData)(__Vtemp_28[0U]))));
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__B 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__rB;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__A 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__rA;
                    VL_EXTENDS_WQ(96,64, __Vtemp_29, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__A);
                    VL_EXTENDS_WQ(96,64, __Vtemp_30, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__px);
                    VL_MULS_WWW(96, __Vtemp_31, __Vtemp_29, __Vtemp_30);
                    VL_EXTENDS_WQ(96,64, __Vtemp_32, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__B);
                    VL_EXTENDS_WQ(96,64, __Vtemp_33, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__py);
                    VL_MULS_WWW(96, __Vtemp_34, __Vtemp_32, __Vtemp_33);
                    VL_ADD_W(3, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__s, __Vtemp_31, __Vtemp_34);
                    VL_SHIFTRS_WWI(96,96,32, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__sh, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__s, 0x00000016U);
                    __Vtemp_35[0U] = (IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__C);
                    __Vtemp_35[1U] = (IData)((__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__C 
                                              >> 0x00000020U));
                    __Vtemp_35[2U] = (- (IData)((1U 
                                                 & (IData)(
                                                           (__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__C 
                                                            >> 0x3fU)))));
                    VL_ADD_W(3, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__Vfuncout, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__sh, __Vtemp_35);
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__r_v[0U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__Vfuncout[0U];
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__r_v[1U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__Vfuncout[1U];
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__r_v[2U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__Vfuncout[2U];
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__py 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__px 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx;
                    VL_EXTENDS_WQ(96,64, __Vtemp_37, vlSelfRef.ember_top__DOT__u_rtr__DOT__gA);
                    VL_EXTENDS_WI(96,32, __Vtemp_38, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[1U]);
                    VL_MULS_WWW(96, __Vtemp_39, __Vtemp_37, __Vtemp_38);
                    VL_EXTENDS_WQ(96,64, __Vtemp_40, vlSelfRef.ember_top__DOT__u_rtr__DOT__gB);
                    VL_EXTENDS_WI(96,32, __Vtemp_41, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[2U]);
                    VL_MULS_WWW(96, __Vtemp_42, __Vtemp_40, __Vtemp_41);
                    VL_ADD_W(3, __Vtemp_43, __Vtemp_39, __Vtemp_42);
                    VL_SHIFTRS_WWI(96,96,32, __Vtemp_44, __Vtemp_43, 0x00000016U);
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__C 
                        = ((QData)((IData)((0x3fc00000U 
                                            & (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[10U] 
                                               << 0x0000000eU)))) 
                           - (((QData)((IData)(__Vtemp_44[1U])) 
                               << 0x00000020U) | (QData)((IData)(__Vtemp_44[0U]))));
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__B 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__gB;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__A 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__gA;
                    VL_EXTENDS_WQ(96,64, __Vtemp_45, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__A);
                    VL_EXTENDS_WQ(96,64, __Vtemp_46, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__px);
                    VL_MULS_WWW(96, __Vtemp_47, __Vtemp_45, __Vtemp_46);
                    VL_EXTENDS_WQ(96,64, __Vtemp_48, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__B);
                    VL_EXTENDS_WQ(96,64, __Vtemp_49, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__py);
                    VL_MULS_WWW(96, __Vtemp_50, __Vtemp_48, __Vtemp_49);
                    VL_ADD_W(3, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__s, __Vtemp_47, __Vtemp_50);
                    VL_SHIFTRS_WWI(96,96,32, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__sh, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__s, 0x00000016U);
                    __Vtemp_51[0U] = (IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__C);
                    __Vtemp_51[1U] = (IData)((__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__C 
                                              >> 0x00000020U));
                    __Vtemp_51[2U] = (- (IData)((1U 
                                                 & (IData)(
                                                           (__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__C 
                                                            >> 0x3fU)))));
                    VL_ADD_W(3, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__Vfuncout, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__sh, __Vtemp_51);
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__g_v[0U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__Vfuncout[0U];
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__g_v[1U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__Vfuncout[1U];
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__g_v[2U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__Vfuncout[2U];
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__py 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__px 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx;
                    VL_EXTENDS_WQ(96,64, __Vtemp_53, vlSelfRef.ember_top__DOT__u_rtr__DOT__bA);
                    VL_EXTENDS_WI(96,32, __Vtemp_54, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[1U]);
                    VL_MULS_WWW(96, __Vtemp_55, __Vtemp_53, __Vtemp_54);
                    VL_EXTENDS_WQ(96,64, __Vtemp_56, vlSelfRef.ember_top__DOT__u_rtr__DOT__bB);
                    VL_EXTENDS_WI(96,32, __Vtemp_57, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[2U]);
                    VL_MULS_WWW(96, __Vtemp_58, __Vtemp_56, __Vtemp_57);
                    VL_ADD_W(3, __Vtemp_59, __Vtemp_55, __Vtemp_58);
                    VL_SHIFTRS_WWI(96,96,32, __Vtemp_60, __Vtemp_59, 0x00000016U);
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__C 
                        = ((QData)((IData)((0x3fc00000U 
                                            & (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[10U] 
                                               << 6U)))) 
                           - (((QData)((IData)(__Vtemp_60[1U])) 
                               << 0x00000020U) | (QData)((IData)(__Vtemp_60[0U]))));
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__B 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__bB;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__A 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__bA;
                    VL_EXTENDS_WQ(96,64, __Vtemp_61, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__A);
                    VL_EXTENDS_WQ(96,64, __Vtemp_62, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__px);
                    VL_MULS_WWW(96, __Vtemp_63, __Vtemp_61, __Vtemp_62);
                    VL_EXTENDS_WQ(96,64, __Vtemp_64, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__B);
                    VL_EXTENDS_WQ(96,64, __Vtemp_65, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__py);
                    VL_MULS_WWW(96, __Vtemp_66, __Vtemp_64, __Vtemp_65);
                    VL_ADD_W(3, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__s, __Vtemp_63, __Vtemp_66);
                    VL_SHIFTRS_WWI(96,96,32, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__sh, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__s, 0x00000016U);
                    __Vtemp_67[0U] = (IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__C);
                    __Vtemp_67[1U] = (IData)((__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__C 
                                              >> 0x00000020U));
                    __Vtemp_67[2U] = (- (IData)((1U 
                                                 & (IData)(
                                                           (__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__C 
                                                            >> 0x3fU)))));
                    VL_ADD_W(3, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__Vfuncout, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__sh, __Vtemp_67);
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__b_v[0U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__Vfuncout[0U];
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__b_v[1U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__Vfuncout[1U];
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__b_v[2U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__Vfuncout[2U];
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__py 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__px 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx;
                    VL_EXTENDS_WQ(96,64, __Vtemp_69, vlSelfRef.ember_top__DOT__u_rtr__DOT__zA);
                    VL_EXTENDS_WI(96,32, __Vtemp_70, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[1U]);
                    VL_MULS_WWW(96, __Vtemp_71, __Vtemp_69, __Vtemp_70);
                    VL_EXTENDS_WQ(96,64, __Vtemp_72, vlSelfRef.ember_top__DOT__u_rtr__DOT__zB);
                    VL_EXTENDS_WI(96,32, __Vtemp_73, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[2U]);
                    VL_MULS_WWW(96, __Vtemp_74, __Vtemp_72, __Vtemp_73);
                    VL_ADD_W(3, __Vtemp_75, __Vtemp_71, __Vtemp_74);
                    VL_SHIFTRS_WWI(96,96,32, __Vtemp_76, __Vtemp_75, 0x00000016U);
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__C 
                        = ((QData)((IData)((0x0000ffffU 
                                            & vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[7U]))) 
                           - (((QData)((IData)(__Vtemp_76[1U])) 
                               << 0x00000020U) | (QData)((IData)(__Vtemp_76[0U]))));
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__B 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__zB;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__A 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__zA;
                    VL_EXTENDS_WQ(96,64, __Vtemp_77, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__A);
                    VL_EXTENDS_WQ(96,64, __Vtemp_78, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__px);
                    VL_MULS_WWW(96, __Vtemp_79, __Vtemp_77, __Vtemp_78);
                    VL_EXTENDS_WQ(96,64, __Vtemp_80, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__B);
                    VL_EXTENDS_WQ(96,64, __Vtemp_81, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__py);
                    VL_MULS_WWW(96, __Vtemp_82, __Vtemp_80, __Vtemp_81);
                    VL_ADD_W(3, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__s, __Vtemp_79, __Vtemp_82);
                    VL_SHIFTRS_WWI(96,96,32, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__sh, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__s, 0x00000016U);
                    __Vtemp_83[0U] = (IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__C);
                    __Vtemp_83[1U] = (IData)((__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__C 
                                              >> 0x00000020U));
                    __Vtemp_83[2U] = (- (IData)((1U 
                                                 & (IData)(
                                                           (__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__C 
                                                            >> 0x3fU)))));
                    VL_ADD_W(3, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__Vfuncout, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__sh, __Vtemp_83);
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__z_v[0U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__Vfuncout[0U];
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__z_v[1U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__Vfuncout[1U];
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__z_v[2U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__Vfuncout[2U];
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__py 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__px 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx;
                    VL_EXTENDS_WQ(96,64, __Vtemp_84, vlSelfRef.ember_top__DOT__u_rtr__DOT__uA);
                    VL_EXTENDS_WI(96,32, __Vtemp_85, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[1U]);
                    VL_MULS_WWW(96, __Vtemp_86, __Vtemp_84, __Vtemp_85);
                    VL_EXTENDS_WQ(96,64, __Vtemp_87, vlSelfRef.ember_top__DOT__u_rtr__DOT__uB);
                    VL_EXTENDS_WI(96,32, __Vtemp_88, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[2U]);
                    VL_MULS_WWW(96, __Vtemp_89, __Vtemp_87, __Vtemp_88);
                    VL_ADD_W(3, __Vtemp_90, __Vtemp_86, __Vtemp_89);
                    VL_SHIFTRS_WWI(96,96,32, __Vtemp_91, __Vtemp_90, 0x00000016U);
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__C 
                        = ((((QData)((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u0e[1U])) 
                             << 0x00000020U) | (QData)((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u0e[0U]))) 
                           - (((QData)((IData)(__Vtemp_91[1U])) 
                               << 0x00000020U) | (QData)((IData)(__Vtemp_91[0U]))));
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__B 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__uB;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__A 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__uA;
                    VL_EXTENDS_WQ(96,64, __Vtemp_92, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__A);
                    VL_EXTENDS_WQ(96,64, __Vtemp_93, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__px);
                    VL_MULS_WWW(96, __Vtemp_94, __Vtemp_92, __Vtemp_93);
                    VL_EXTENDS_WQ(96,64, __Vtemp_95, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__B);
                    VL_EXTENDS_WQ(96,64, __Vtemp_96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__py);
                    VL_MULS_WWW(96, __Vtemp_97, __Vtemp_95, __Vtemp_96);
                    VL_ADD_W(3, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__s, __Vtemp_94, __Vtemp_97);
                    VL_SHIFTRS_WWI(96,96,32, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__sh, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__s, 0x00000016U);
                    __Vtemp_98[0U] = (IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__C);
                    __Vtemp_98[1U] = (IData)((__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__C 
                                              >> 0x00000020U));
                    __Vtemp_98[2U] = (- (IData)((1U 
                                                 & (IData)(
                                                           (__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__C 
                                                            >> 0x3fU)))));
                    VL_ADD_W(3, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__Vfuncout, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__sh, __Vtemp_98);
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__u_raw[0U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__Vfuncout[0U];
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__u_raw[1U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__Vfuncout[1U];
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__u_raw[2U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__Vfuncout[2U];
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__py 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__px 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx;
                    VL_EXTENDS_WQ(96,64, __Vtemp_99, vlSelfRef.ember_top__DOT__u_rtr__DOT__vA);
                    VL_EXTENDS_WI(96,32, __Vtemp_100, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[1U]);
                    VL_MULS_WWW(96, __Vtemp_101, __Vtemp_99, __Vtemp_100);
                    VL_EXTENDS_WQ(96,64, __Vtemp_102, vlSelfRef.ember_top__DOT__u_rtr__DOT__vB);
                    VL_EXTENDS_WI(96,32, __Vtemp_103, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[2U]);
                    VL_MULS_WWW(96, __Vtemp_104, __Vtemp_102, __Vtemp_103);
                    VL_ADD_W(3, __Vtemp_105, __Vtemp_101, __Vtemp_104);
                    VL_SHIFTRS_WWI(96,96,32, __Vtemp_106, __Vtemp_105, 0x00000016U);
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__C 
                        = ((((QData)((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v0e[1U])) 
                             << 0x00000020U) | (QData)((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v0e[0U]))) 
                           - (((QData)((IData)(__Vtemp_106[1U])) 
                               << 0x00000020U) | (QData)((IData)(__Vtemp_106[0U]))));
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__B 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vB;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__A 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vA;
                    VL_EXTENDS_WQ(96,64, __Vtemp_107, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__A);
                    VL_EXTENDS_WQ(96,64, __Vtemp_108, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__px);
                    VL_MULS_WWW(96, __Vtemp_109, __Vtemp_107, __Vtemp_108);
                    VL_EXTENDS_WQ(96,64, __Vtemp_110, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__B);
                    VL_EXTENDS_WQ(96,64, __Vtemp_111, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__py);
                    VL_MULS_WWW(96, __Vtemp_112, __Vtemp_110, __Vtemp_111);
                    VL_ADD_W(3, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__s, __Vtemp_109, __Vtemp_112);
                    VL_SHIFTRS_WWI(96,96,32, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__sh, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__s, 0x00000016U);
                    __Vtemp_113[0U] = (IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__C);
                    __Vtemp_113[1U] = (IData)((__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__C 
                                               >> 0x00000020U));
                    __Vtemp_113[2U] = (- (IData)((1U 
                                                  & (IData)(
                                                            (__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__C 
                                                             >> 0x3fU)))));
                    VL_ADD_W(3, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__Vfuncout, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__sh, __Vtemp_113);
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__v_raw[0U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__Vfuncout[0U];
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__v_raw[1U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__Vfuncout[1U];
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__v_raw[2U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__Vfuncout[2U];
                } else {
                    vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 0x0dU;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__st))) {
            __Vtemp_114[0U] = (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__dx01);
            __Vtemp_114[1U] = (((IData)((0x7fffffffffffffffULL 
                                         & (- (QData)((IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.ember_top__DOT__u_rtr__DOT__dx01 
                                                                          >> 0x20U)))))))) 
                                << 1U) | (IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__dx01 
                                                  >> 0x00000020U)));
            __Vtemp_114[2U] = (((IData)((0x7fffffffffffffffULL 
                                         & (- (QData)((IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.ember_top__DOT__u_rtr__DOT__dx01 
                                                                          >> 0x20U)))))))) 
                                >> 0x0000001fU) | ((IData)(
                                                           ((0x7fffffffffffffffULL 
                                                             & (- (QData)((IData)(
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlSelfRef.ember_top__DOT__u_rtr__DOT__dx01 
                                                                                >> 0x20U))))))) 
                                                            >> 0x00000020U)) 
                                                   << 1U));
            __Vtemp_115[0U] = (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy);
            __Vtemp_115[1U] = (IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy 
                                       >> 0x00000020U));
            __Vtemp_115[2U] = (- (IData)((1U & (IData)(
                                                       (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy 
                                                        >> 0x3fU)))));
            __Vtemp_116[0U] = vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[2U];
            __Vtemp_116[1U] = (IData)((- (QData)((IData)(
                                                         (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[2U] 
                                                          >> 0x1fU)))));
            __Vtemp_116[2U] = (IData)(((- (QData)((IData)(
                                                          (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[2U] 
                                                           >> 0x1fU)))) 
                                       >> 0x00000020U));
            VL_SUB_W(3, __Vtemp_117, __Vtemp_115, __Vtemp_116);
            VL_MUL_W(3, __Vtemp_118, __Vtemp_114, __Vtemp_117);
            __Vtemp_119[0U] = (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__dy01);
            __Vtemp_119[1U] = (((IData)((0x7fffffffffffffffULL 
                                         & (- (QData)((IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.ember_top__DOT__u_rtr__DOT__dy01 
                                                                          >> 0x20U)))))))) 
                                << 1U) | (IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__dy01 
                                                  >> 0x00000020U)));
            __Vtemp_119[2U] = (((IData)((0x7fffffffffffffffULL 
                                         & (- (QData)((IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.ember_top__DOT__u_rtr__DOT__dy01 
                                                                          >> 0x20U)))))))) 
                                >> 0x0000001fU) | ((IData)(
                                                           ((0x7fffffffffffffffULL 
                                                             & (- (QData)((IData)(
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlSelfRef.ember_top__DOT__u_rtr__DOT__dy01 
                                                                                >> 0x20U))))))) 
                                                            >> 0x00000020U)) 
                                                   << 1U));
            __Vtemp_120[0U] = (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx);
            __Vtemp_120[1U] = (IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx 
                                       >> 0x00000020U));
            __Vtemp_120[2U] = (- (IData)((1U & (IData)(
                                                       (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx 
                                                        >> 0x3fU)))));
            __Vtemp_121[0U] = vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[1U];
            __Vtemp_121[1U] = (IData)((- (QData)((IData)(
                                                         (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[1U] 
                                                          >> 0x1fU)))));
            __Vtemp_121[2U] = (IData)(((- (QData)((IData)(
                                                          (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[1U] 
                                                           >> 0x1fU)))) 
                                       >> 0x00000020U));
            VL_SUB_W(3, __Vtemp_122, __Vtemp_120, __Vtemp_121);
            VL_MUL_W(3, __Vtemp_123, __Vtemp_119, __Vtemp_122);
            VL_SUB_W(3, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__e01, __Vtemp_118, __Vtemp_123);
            if ((4U & vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[0U])) {
                vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__scan_fpa_req = 1U;
                vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_addr 
                    = ((IData)(0x00026800U) + (0xfffffffcU 
                                               & vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__pix_off));
            }
            vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 2U;
            __Vtemp_124[0U] = (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__dx12);
            __Vtemp_124[1U] = (((IData)((0x7fffffffffffffffULL 
                                         & (- (QData)((IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.ember_top__DOT__u_rtr__DOT__dx12 
                                                                          >> 0x20U)))))))) 
                                << 1U) | (IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__dx12 
                                                  >> 0x00000020U)));
            __Vtemp_124[2U] = (((IData)((0x7fffffffffffffffULL 
                                         & (- (QData)((IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.ember_top__DOT__u_rtr__DOT__dx12 
                                                                          >> 0x20U)))))))) 
                                >> 0x0000001fU) | ((IData)(
                                                           ((0x7fffffffffffffffULL 
                                                             & (- (QData)((IData)(
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlSelfRef.ember_top__DOT__u_rtr__DOT__dx12 
                                                                                >> 0x20U))))))) 
                                                            >> 0x00000020U)) 
                                                   << 1U));
            __Vtemp_125[0U] = (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy);
            __Vtemp_125[1U] = (IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy 
                                       >> 0x00000020U));
            __Vtemp_125[2U] = (- (IData)((1U & (IData)(
                                                       (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy 
                                                        >> 0x3fU)))));
            __Vtemp_126[0U] = vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[4U];
            __Vtemp_126[1U] = (IData)((- (QData)((IData)(
                                                         (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[4U] 
                                                          >> 0x1fU)))));
            __Vtemp_126[2U] = (IData)(((- (QData)((IData)(
                                                          (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[4U] 
                                                           >> 0x1fU)))) 
                                       >> 0x00000020U));
            VL_SUB_W(3, __Vtemp_127, __Vtemp_125, __Vtemp_126);
            VL_MUL_W(3, __Vtemp_128, __Vtemp_124, __Vtemp_127);
            __Vtemp_129[0U] = (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__dy12);
            __Vtemp_129[1U] = (((IData)((0x7fffffffffffffffULL 
                                         & (- (QData)((IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.ember_top__DOT__u_rtr__DOT__dy12 
                                                                          >> 0x20U)))))))) 
                                << 1U) | (IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__dy12 
                                                  >> 0x00000020U)));
            __Vtemp_129[2U] = (((IData)((0x7fffffffffffffffULL 
                                         & (- (QData)((IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.ember_top__DOT__u_rtr__DOT__dy12 
                                                                          >> 0x20U)))))))) 
                                >> 0x0000001fU) | ((IData)(
                                                           ((0x7fffffffffffffffULL 
                                                             & (- (QData)((IData)(
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlSelfRef.ember_top__DOT__u_rtr__DOT__dy12 
                                                                                >> 0x20U))))))) 
                                                            >> 0x00000020U)) 
                                                   << 1U));
            __Vtemp_130[0U] = (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx);
            __Vtemp_130[1U] = (IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx 
                                       >> 0x00000020U));
            __Vtemp_130[2U] = (- (IData)((1U & (IData)(
                                                       (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx 
                                                        >> 0x3fU)))));
            __Vtemp_131[0U] = vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[3U];
            __Vtemp_131[1U] = (IData)((- (QData)((IData)(
                                                         (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[3U] 
                                                          >> 0x1fU)))));
            __Vtemp_131[2U] = (IData)(((- (QData)((IData)(
                                                          (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[3U] 
                                                           >> 0x1fU)))) 
                                       >> 0x00000020U));
            VL_SUB_W(3, __Vtemp_132, __Vtemp_130, __Vtemp_131);
            VL_MUL_W(3, __Vtemp_133, __Vtemp_129, __Vtemp_132);
            VL_SUB_W(3, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__e12, __Vtemp_128, __Vtemp_133);
            __Vtemp_134[0U] = (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__dx20);
            __Vtemp_134[1U] = (((IData)((0x7fffffffffffffffULL 
                                         & (- (QData)((IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.ember_top__DOT__u_rtr__DOT__dx20 
                                                                          >> 0x20U)))))))) 
                                << 1U) | (IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__dx20 
                                                  >> 0x00000020U)));
            __Vtemp_134[2U] = (((IData)((0x7fffffffffffffffULL 
                                         & (- (QData)((IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.ember_top__DOT__u_rtr__DOT__dx20 
                                                                          >> 0x20U)))))))) 
                                >> 0x0000001fU) | ((IData)(
                                                           ((0x7fffffffffffffffULL 
                                                             & (- (QData)((IData)(
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlSelfRef.ember_top__DOT__u_rtr__DOT__dx20 
                                                                                >> 0x20U))))))) 
                                                            >> 0x00000020U)) 
                                                   << 1U));
            __Vtemp_135[0U] = (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy);
            __Vtemp_135[1U] = (IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy 
                                       >> 0x00000020U));
            __Vtemp_135[2U] = (- (IData)((1U & (IData)(
                                                       (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy 
                                                        >> 0x3fU)))));
            __Vtemp_136[0U] = vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[6U];
            __Vtemp_136[1U] = (IData)((- (QData)((IData)(
                                                         (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[6U] 
                                                          >> 0x1fU)))));
            __Vtemp_136[2U] = (IData)(((- (QData)((IData)(
                                                          (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[6U] 
                                                           >> 0x1fU)))) 
                                       >> 0x00000020U));
            VL_SUB_W(3, __Vtemp_137, __Vtemp_135, __Vtemp_136);
            VL_MUL_W(3, __Vtemp_138, __Vtemp_134, __Vtemp_137);
            __Vtemp_139[0U] = (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__dy20);
            __Vtemp_139[1U] = (((IData)((0x7fffffffffffffffULL 
                                         & (- (QData)((IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.ember_top__DOT__u_rtr__DOT__dy20 
                                                                          >> 0x20U)))))))) 
                                << 1U) | (IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__dy20 
                                                  >> 0x00000020U)));
            __Vtemp_139[2U] = (((IData)((0x7fffffffffffffffULL 
                                         & (- (QData)((IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.ember_top__DOT__u_rtr__DOT__dy20 
                                                                          >> 0x20U)))))))) 
                                >> 0x0000001fU) | ((IData)(
                                                           ((0x7fffffffffffffffULL 
                                                             & (- (QData)((IData)(
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlSelfRef.ember_top__DOT__u_rtr__DOT__dy20 
                                                                                >> 0x20U))))))) 
                                                            >> 0x00000020U)) 
                                                   << 1U));
            __Vtemp_140[0U] = (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx);
            __Vtemp_140[1U] = (IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx 
                                       >> 0x00000020U));
            __Vtemp_140[2U] = (- (IData)((1U & (IData)(
                                                       (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx 
                                                        >> 0x3fU)))));
            __Vtemp_141[0U] = vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[5U];
            __Vtemp_141[1U] = (IData)((- (QData)((IData)(
                                                         (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[5U] 
                                                          >> 0x1fU)))));
            __Vtemp_141[2U] = (IData)(((- (QData)((IData)(
                                                          (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[5U] 
                                                           >> 0x1fU)))) 
                                       >> 0x00000020U));
            VL_SUB_W(3, __Vtemp_142, __Vtemp_140, __Vtemp_141);
            VL_MUL_W(3, __Vtemp_143, __Vtemp_139, __Vtemp_142);
            VL_SUB_W(3, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__e20, __Vtemp_138, __Vtemp_143);
        } else if (vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_start) {
            vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__iy 
                = vlSelfRef.ember_top__DOT__u_rtr__DOT__y_lo_i;
            vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy 
                = (0x0000000000200000ULL + VL_SHIFTL_QQI(64,64,32, 
                                                         (((- (QData)((IData)(
                                                                              (1U 
                                                                               & ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__y_lo_i) 
                                                                                >> 0x0fU))))) 
                                                           << 0x00000010U) 
                                                          | (QData)((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__y_lo_i))), 0x00000016U));
            vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__ix 
                = vlSelfRef.ember_top__DOT__u_rtr__DOT__x_lo_i;
            vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx 
                = (0x0000000000200000ULL + VL_SHIFTL_QQI(64,64,32, 
                                                         (((- (QData)((IData)(
                                                                              (1U 
                                                                               & ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__x_lo_i) 
                                                                                >> 0x0fU))))) 
                                                           << 0x00000010U) 
                                                          | (QData)((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__x_lo_i))), 0x00000016U));
            vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 1U;
        }
    } else {
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__iy = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy = 0ULL;
        vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_done = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__ix = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx = 0ULL;
        vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__scan_fpa_req = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_we = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_addr = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_wdata = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_be = 0U;
        vlSelfRef.ember_top__DOT__fpa2_req = 0U;
        vlSelfRef.ember_top__DOT__fpa2_addr = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__e01[0U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__e01[1U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__e01[2U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__e12[0U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__e12[1U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__e12[2U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__e20[0U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__e20[1U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__e20[2U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__r_v[0U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__r_v[1U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__r_v[2U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__g_v[0U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__g_v[1U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__g_v[2U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__b_v[0U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__b_v[1U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__b_v[2U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__z_v[0U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__z_v[1U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__z_v[2U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__u_raw[0U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__u_raw[1U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__u_raw[2U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__v_raw[0U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__v_raw[1U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__v_raw[2U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__inv_w_v[0U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__inv_w_v[1U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__inv_w_v[2U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__u_fin[0U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__u_fin[1U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__u_fin[2U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__v_fin[0U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__v_fin[1U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__v_fin[2U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__z_pass = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cr = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cg = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cb = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__mr = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__mg = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__mb = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__zaddr = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__faddr = 0U;
    }
    vlSelfRef.ember_top__DOT__u_cp__DOT__rd_addr = 
        ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__ar_accept)
          ? (0x00000fffU & vlSelfRef.h_araddr) : 0U);
    vlSelfRef.ember_top__DOT__u_cp__DOT__rb_full = 
        (((1U & ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rb_wp) 
                 >> 3U)) != (1U & ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rb_rp) 
                                   >> 3U))) & ((7U 
                                                & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rb_wp)) 
                                               == (7U 
                                                   & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rb_rp))));
    vlSelfRef.ember_top__DOT__u_cp__DOT__rb_empty = 
        ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rb_rp) 
         == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rb_wp));
    if ((1U & (~ (IData)(vlSelfRef.rst_n)))) {
        vlSelfRef.ember_top__DOT__u_cp__DOT__dma_busy_q = 0U;
        vlSelfRef.ember_top__DOT__u_cp__DOT__fence_done_q = 0U;
    }
    if (vlSelfRef.rst_n) {
        vlSelfRef.ember_top__DOT__u_gsx__DOT__f_go = 0U;
        vlSelfRef.ember_top__DOT__gsx_gxa_we = 0U;
        if ((0x00000010U & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__st))) {
            vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__st = 0U;
            vlSelfRef.ember_top__DOT__u_gsx__DOT__busy_r = 0U;
        } else if ((8U & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__st))) {
            if ((4U & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__st))) {
                vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__st = 0U;
                vlSelfRef.ember_top__DOT__u_gsx__DOT__busy_r = 0U;
            } else if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__st))) {
                vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__st = 0U;
                vlSelfRef.ember_top__DOT__u_gsx__DOT__busy_r = 0U;
            } else if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__st))) {
                vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__st = 0U;
                vlSelfRef.ember_top__DOT__u_gsx__DOT__busy_r = 0U;
            } else if (vlSelfRef.ember_top__DOT__u_gsx__DOT__cfg_overw) {
                vlSelfRef.ember_top__DOT__u_gsx__DOT__busy_r = 0U;
                vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__st = 0U;
            } else {
                vlSelfRef.ember_top__DOT__gsx_gxa_we = 1U;
                vlSelfRef.ember_top__DOT__gsx_gxa_be = 0x0fU;
                vlSelfRef.ember_top__DOT__gsx_gxa_addr 
                    = ((IData)(0x0000004cU) + vlSelfRef.ember_top__DOT__u_gsx__DOT__emit_base);
                vlSelfRef.ember_top__DOT__gsx_gxa_wdata = 0U;
                vlSelfRef.ember_top__DOT__u_gsx__DOT__busy_r = 0U;
                vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__st = 0U;
            }
        } else if ((4U & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__st))) {
            if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__st))) {
                if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__st))) {
                    vlSelfRef.ember_top__DOT__gsx_gxa_we = 1U;
                    vlSelfRef.ember_top__DOT__gsx_gxa_be = 0x0fU;
                    vlSelfRef.ember_top__DOT__gsx_gxa_addr 
                        = (vlSelfRef.ember_top__DOT__u_gsx__DOT__emit_base 
                           + ((IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__eidx) 
                              << 2U));
                    vlSelfRef.ember_top__DOT__gsx_gxa_wdata 
                        = ((6U >= (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__eidx))
                            ? ((0x00000010U & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__eidx))
                                ? vlSelfRef.ember_top__DOT__u_gsx__DOT__py[2U]
                                : ((8U & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__eidx))
                                    ? vlSelfRef.ember_top__DOT__u_gsx__DOT__py[2U]
                                    : ((4U & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__eidx))
                                        ? ((2U & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__eidx))
                                            ? vlSelfRef.ember_top__DOT__u_gsx__DOT__py[2U]
                                            : ((1U 
                                                & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__eidx))
                                                ? vlSelfRef.ember_top__DOT__u_gsx__DOT__px[2U]
                                                : vlSelfRef.ember_top__DOT__u_gsx__DOT__py[1U]))
                                        : ((2U & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__eidx))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__eidx))
                                                ? vlSelfRef.ember_top__DOT__u_gsx__DOT__px[1U]
                                                : vlSelfRef.ember_top__DOT__u_gsx__DOT__py[0U])
                                            : ((1U 
                                                & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__eidx))
                                                ? vlSelfRef.ember_top__DOT__u_gsx__DOT__px[0U]
                                                : vlSelfRef.ember_top__DOT__u_gsx__DOT__py[2U])))))
                            : ((9U >= (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__eidx))
                                ? ((7U == (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__eidx))
                                    ? vlSelfRef.ember_top__DOT__u_gsx__DOT__pz[0U]
                                    : ((8U == (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__eidx))
                                        ? vlSelfRef.ember_top__DOT__u_gsx__DOT__pz[1U]
                                        : vlSelfRef.ember_top__DOT__u_gsx__DOT__pz[2U]))
                                : ((0x0cU >= (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__eidx))
                                    ? ((0x0aU == (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__eidx))
                                        ? vlSelfRef.ember_top__DOT__u_gsx__DOT__pc[0U]
                                        : ((0x0bU == (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__eidx))
                                            ? vlSelfRef.ember_top__DOT__u_gsx__DOT__pc[1U]
                                            : vlSelfRef.ember_top__DOT__u_gsx__DOT__pc[2U]))
                                    : ((IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__cfg_tex)
                                        ? ((0x00000010U 
                                            & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__eidx))
                                            ? ((8U 
                                                & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__eidx))
                                                ? vlSelfRef.ember_top__DOT__u_gsx__DOT__pv[2U]
                                                : (
                                                   (4U 
                                                    & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__eidx))
                                                    ? vlSelfRef.ember_top__DOT__u_gsx__DOT__pv[2U]
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__eidx))
                                                     ? vlSelfRef.ember_top__DOT__u_gsx__DOT__pv[2U]
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__eidx))
                                                      ? vlSelfRef.ember_top__DOT__u_gsx__DOT__pu[2U]
                                                      : vlSelfRef.ember_top__DOT__u_gsx__DOT__pv[1U]))))
                                            : ((8U 
                                                & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__eidx))
                                                ? (
                                                   (4U 
                                                    & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__eidx))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__eidx))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__eidx))
                                                      ? vlSelfRef.ember_top__DOT__u_gsx__DOT__pu[1U]
                                                      : vlSelfRef.ember_top__DOT__u_gsx__DOT__pv[0U])
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__eidx))
                                                      ? vlSelfRef.ember_top__DOT__u_gsx__DOT__pu[0U]
                                                      : vlSelfRef.ember_top__DOT__u_gsx__DOT__pv[2U]))
                                                    : vlSelfRef.ember_top__DOT__u_gsx__DOT__pv[2U])
                                                : vlSelfRef.ember_top__DOT__u_gsx__DOT__pv[2U]))
                                        : 0U))));
                    if ((0x12U == (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__eidx))) {
                        vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__eidx = 0U;
                        vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__st = 8U;
                    } else {
                        vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__eidx 
                            = (0x0000001fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__eidx)));
                    }
                } else {
                    vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__eidx = 1U;
                    vlSelfRef.ember_top__DOT__gsx_gxa_we = 1U;
                    vlSelfRef.ember_top__DOT__gsx_gxa_be = 0x0fU;
                    vlSelfRef.ember_top__DOT__gsx_gxa_addr 
                        = vlSelfRef.ember_top__DOT__u_gsx__DOT__emit_base;
                    vlSelfRef.ember_top__DOT__gsx_gxa_wdata 
                        = (1U | (((IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__cfg_page) 
                                  << 5U) | ((((IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__cfg_tex) 
                                              << 3U) 
                                             | ((IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__cfg_ztest) 
                                                << 2U)) 
                                            | ((IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__cfg_blend) 
                                               << 1U))));
                    vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__st = 7U;
                }
            } else if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__st))) {
                if (((vlSelfRef.ember_top__DOT__u_gsx__DOT__w_in 
                      >> 0x0000001fU) | (0U == (0x7fffffffU 
                                                & vlSelfRef.ember_top__DOT__u_gsx__DOT__w_in)))) {
                    vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__st = 8U;
                } else if ((2U == (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__vidx))) {
                    vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__st = 6U;
                } else {
                    vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__vidx 
                        = (3U & ((IData)(1U) + (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__vidx)));
                    vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__kstep = 0U;
                    vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__phase = 0U;
                    vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__acc0 = 0U;
                    vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__acc1 = 0U;
                    vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__acc2 = 0U;
                    vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__acc3 = 0U;
                    vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__st = 1U;
                }
            } else if (vlSelfRef.ember_top__DOT__u_gsx__DOT__f_done) {
                __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__fb 
                    = vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s0[0U];
                __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__Vfuncout = 0;
                vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__st = 5U;
                __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__sh = 0;
                __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__e 
                    = (0x000000ffU & (__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__fb 
                                      >> 0x17U));
                __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__i24 
                    = (0x00800000U | (0x007fffffU & __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__fb));
                if ((0U == (0x7fffffffU & __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__fb))) {
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__Vfuncout = 0U;
                } else if ((0x88U <= (IData)(__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__e))) {
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__Vfuncout 
                        = ((__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__fb 
                            >> 0x1fU) ? 0x80000000U
                            : 0x7fffffffU);
                } else if ((0x80U <= (IData)(__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__e))) {
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__sh 
                        = VL_SHIFTL_III(32,32,8, __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__i24, 
                                        (0x000000ffU 
                                         & ((IData)(__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__e) 
                                            - (IData)(0x80U))));
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__Vfuncout 
                        = __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__sh;
                } else {
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__sh 
                        = VL_SHIFTR_III(32,32,8, __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__i24, 
                                        (0x000000ffU 
                                         & ((IData)(0x80U) 
                                            - (IData)(__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__e))));
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__Vfuncout 
                        = __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__sh;
                }
                if (((__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__fb 
                      >> 0x1fU) & (0U != __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__Vfuncout))) {
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__Vfuncout 
                        = ((IData)(1U) + (~ __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__Vfuncout));
                }
                __Vfunc_ember_top__DOT__u_gsx__DOT__sat22__37__v 
                    = __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__38__Vfuncout;
                __Vfunc_ember_top__DOT__u_gsx__DOT__sat22__37__Vfuncout 
                    = (VL_LTS_III(32, 0x7ffffd78U, __Vfunc_ember_top__DOT__u_gsx__DOT__sat22__37__v)
                        ? 0x7ffffd78U : (VL_GTS_III(32, 0x80000288U, __Vfunc_ember_top__DOT__u_gsx__DOT__sat22__37__v)
                                          ? 0x80000288U
                                          : __Vfunc_ember_top__DOT__u_gsx__DOT__sat22__37__v));
                vlSelfRef.ember_top__DOT__u_gsx__DOT____Vlvbound_hcc3d737a__0 
                    = __Vfunc_ember_top__DOT__u_gsx__DOT__sat22__37__Vfuncout;
                __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__fb 
                    = vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s1[0U];
                __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__Vfuncout = 0;
                __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__sh = 0;
                __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__e 
                    = (0x000000ffU & (__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__fb 
                                      >> 0x17U));
                __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__i24 
                    = (0x00800000U | (0x007fffffU & __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__fb));
                if ((0U == (0x7fffffffU & __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__fb))) {
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__Vfuncout = 0U;
                } else if ((0x88U <= (IData)(__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__e))) {
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__Vfuncout 
                        = ((__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__fb 
                            >> 0x1fU) ? 0x80000000U
                            : 0x7fffffffU);
                } else if ((0x80U <= (IData)(__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__e))) {
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__sh 
                        = VL_SHIFTL_III(32,32,8, __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__i24, 
                                        (0x000000ffU 
                                         & ((IData)(__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__e) 
                                            - (IData)(0x80U))));
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__Vfuncout 
                        = __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__sh;
                } else {
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__sh 
                        = VL_SHIFTR_III(32,32,8, __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__i24, 
                                        (0x000000ffU 
                                         & ((IData)(0x80U) 
                                            - (IData)(__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__e))));
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__Vfuncout 
                        = __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__sh;
                }
                if (((__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__fb 
                      >> 0x1fU) & (0U != __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__Vfuncout))) {
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__Vfuncout 
                        = ((IData)(1U) + (~ __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__Vfuncout));
                }
                __Vfunc_ember_top__DOT__u_gsx__DOT__sat22__39__v 
                    = __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__40__Vfuncout;
                __Vfunc_ember_top__DOT__u_gsx__DOT__sat22__39__Vfuncout 
                    = (VL_LTS_III(32, 0x7ffffd78U, __Vfunc_ember_top__DOT__u_gsx__DOT__sat22__39__v)
                        ? 0x7ffffd78U : (VL_GTS_III(32, 0x80000288U, __Vfunc_ember_top__DOT__u_gsx__DOT__sat22__39__v)
                                          ? 0x80000288U
                                          : __Vfunc_ember_top__DOT__u_gsx__DOT__sat22__39__v));
                vlSelfRef.ember_top__DOT__u_gsx__DOT____Vlvbound_hdfae5880__0 
                    = __Vfunc_ember_top__DOT__u_gsx__DOT__sat22__39__Vfuncout;
                __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_z16__41__fb 
                    = vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s2[0U];
                __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_z16__41__Vfuncout = 0;
                __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_z16__41__prod = 0;
                __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_z16__41__e 
                    = (0x000000ffU & (__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_z16__41__fb 
                                      >> 0x17U));
                if (((__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_z16__41__fb 
                      >> 0x0000001fU) | (0U == (0x7fffffffU 
                                                & __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_z16__41__fb)))) {
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_z16__41__Vfuncout = 0U;
                } else if ((0x7fU <= (IData)(__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_z16__41__e))) {
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_z16__41__Vfuncout = 0xffffU;
                } else {
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_z16__41__prod 
                        = (0x000000ffffffffffULL & 
                           (0x000000000000ffffULL * (QData)((IData)(
                                                                    (0x00800000U 
                                                                     | (0x007fffffU 
                                                                        & __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_z16__41__fb))))));
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_z16__41__Vfuncout 
                        = (0x0000ffffU & (IData)(VL_SHIFTR_QQI(40,40,8, __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_z16__41__prod, 
                                                               (0x000000ffU 
                                                                & ((IData)(0x96U) 
                                                                   - (IData)(__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_z16__41__e))))));
                }
                vlSelfRef.ember_top__DOT__u_gsx__DOT____Vlvbound_h53f4e5eb__0 
                    = __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_z16__41__Vfuncout;
                __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__fb 
                    = ((0x0eU >= (0x0000000fU & ((IData)(3U) 
                                                 + 
                                                 ((IData)(5U) 
                                                  * (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__vidx)))))
                        ? vlSelfRef.ember_top__DOT__u_gsx__DOT__vtx
                       [(0x0000000fU & ((IData)(3U) 
                                        + ((IData)(5U) 
                                           * (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__vidx))))]
                        : 0U);
                __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__Vfuncout = 0;
                __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__sh = 0;
                __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__e 
                    = (0x000000ffU & (__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__fb 
                                      >> 0x17U));
                __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__i24 
                    = (0x00800000U | (0x007fffffU & __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__fb));
                if ((0U == (0x7fffffffU & __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__fb))) {
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__Vfuncout = 0U;
                } else if ((0x88U <= (IData)(__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__e))) {
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__Vfuncout 
                        = ((__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__fb 
                            >> 0x1fU) ? 0x80000000U
                            : 0x7fffffffU);
                } else if ((0x80U <= (IData)(__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__e))) {
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__sh 
                        = VL_SHIFTL_III(32,32,8, __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__i24, 
                                        (0x000000ffU 
                                         & ((IData)(__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__e) 
                                            - (IData)(0x80U))));
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__Vfuncout 
                        = __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__sh;
                } else {
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__sh 
                        = VL_SHIFTR_III(32,32,8, __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__i24, 
                                        (0x000000ffU 
                                         & ((IData)(0x80U) 
                                            - (IData)(__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__e))));
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__Vfuncout 
                        = __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__sh;
                }
                if (((__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__fb 
                      >> 0x1fU) & (0U != __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__Vfuncout))) {
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__Vfuncout 
                        = ((IData)(1U) + (~ __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__Vfuncout));
                }
                vlSelfRef.ember_top__DOT__u_gsx__DOT____Vlvbound_h52fd11d8__0 
                    = __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__42__Vfuncout;
                __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__fb 
                    = ((0x0eU >= (0x0000000fU & ((IData)(4U) 
                                                 + 
                                                 ((IData)(5U) 
                                                  * (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__vidx)))))
                        ? vlSelfRef.ember_top__DOT__u_gsx__DOT__vtx
                       [(0x0000000fU & ((IData)(4U) 
                                        + ((IData)(5U) 
                                           * (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__vidx))))]
                        : 0U);
                __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__Vfuncout = 0;
                __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__sh = 0;
                __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__e 
                    = (0x000000ffU & (__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__fb 
                                      >> 0x17U));
                __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__i24 
                    = (0x00800000U | (0x007fffffU & __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__fb));
                if ((0U == (0x7fffffffU & __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__fb))) {
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__Vfuncout = 0U;
                } else if ((0x88U <= (IData)(__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__e))) {
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__Vfuncout 
                        = ((__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__fb 
                            >> 0x1fU) ? 0x80000000U
                            : 0x7fffffffU);
                } else if ((0x80U <= (IData)(__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__e))) {
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__sh 
                        = VL_SHIFTL_III(32,32,8, __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__i24, 
                                        (0x000000ffU 
                                         & ((IData)(__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__e) 
                                            - (IData)(0x80U))));
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__Vfuncout 
                        = __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__sh;
                } else {
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__sh 
                        = VL_SHIFTR_III(32,32,8, __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__i24, 
                                        (0x000000ffU 
                                         & ((IData)(0x80U) 
                                            - (IData)(__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__e))));
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__Vfuncout 
                        = __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__sh;
                }
                if (((__Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__fb 
                      >> 0x1fU) & (0U != __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__Vfuncout))) {
                    __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__Vfuncout 
                        = ((IData)(1U) + (~ __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__Vfuncout));
                }
                vlSelfRef.ember_top__DOT__u_gsx__DOT____Vlvbound_h71c33494__0 
                    = __Vfunc_ember_top__DOT__u_gsx__DOT__fp_to_q22__43__Vfuncout;
                if ((2U >= (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__vidx))) {
                    __VdlyVal__ember_top__DOT__u_gsx__DOT__px__v0 
                        = vlSelfRef.ember_top__DOT__u_gsx__DOT____Vlvbound_hcc3d737a__0;
                    __VdlyDim0__ember_top__DOT__u_gsx__DOT__px__v0 
                        = vlSelfRef.ember_top__DOT__u_gsx__DOT__vidx;
                    vlSelfRef.__VdlySet__ember_top__DOT__u_gsx__DOT__px__v0 = 1U;
                    __VdlyVal__ember_top__DOT__u_gsx__DOT__py__v0 
                        = vlSelfRef.ember_top__DOT__u_gsx__DOT____Vlvbound_hdfae5880__0;
                    __VdlyDim0__ember_top__DOT__u_gsx__DOT__py__v0 
                        = vlSelfRef.ember_top__DOT__u_gsx__DOT__vidx;
                    vlSelfRef.__VdlySet__ember_top__DOT__u_gsx__DOT__py__v0 = 1U;
                    __VdlyVal__ember_top__DOT__u_gsx__DOT__pz__v0 
                        = vlSelfRef.ember_top__DOT__u_gsx__DOT____Vlvbound_h53f4e5eb__0;
                    __VdlyDim0__ember_top__DOT__u_gsx__DOT__pz__v0 
                        = vlSelfRef.ember_top__DOT__u_gsx__DOT__vidx;
                    vlSelfRef.__VdlySet__ember_top__DOT__u_gsx__DOT__pz__v0 = 1U;
                    vlSelfRef.ember_top__DOT__u_gsx__DOT____Vlvbound_hd1051bc7__0 
                        = (0x7fffffffU & vlSelfRef.ember_top__DOT__u_gsx__DOT__col
                           [vlSelfRef.ember_top__DOT__u_gsx__DOT__vidx]);
                    __VdlyVal__ember_top__DOT__u_gsx__DOT__pc__v0 
                        = vlSelfRef.ember_top__DOT__u_gsx__DOT____Vlvbound_hd1051bc7__0;
                    __VdlyDim0__ember_top__DOT__u_gsx__DOT__pc__v0 
                        = vlSelfRef.ember_top__DOT__u_gsx__DOT__vidx;
                    vlSelfRef.__VdlySet__ember_top__DOT__u_gsx__DOT__pc__v0 = 1U;
                    __VdlyVal__ember_top__DOT__u_gsx__DOT__pu__v0 
                        = vlSelfRef.ember_top__DOT__u_gsx__DOT____Vlvbound_h52fd11d8__0;
                    __VdlyDim0__ember_top__DOT__u_gsx__DOT__pu__v0 
                        = vlSelfRef.ember_top__DOT__u_gsx__DOT__vidx;
                    vlSelfRef.__VdlySet__ember_top__DOT__u_gsx__DOT__pu__v0 = 1U;
                    __VdlyVal__ember_top__DOT__u_gsx__DOT__pv__v0 
                        = vlSelfRef.ember_top__DOT__u_gsx__DOT____Vlvbound_h71c33494__0;
                    __VdlyDim0__ember_top__DOT__u_gsx__DOT__pv__v0 
                        = vlSelfRef.ember_top__DOT__u_gsx__DOT__vidx;
                    vlSelfRef.__VdlySet__ember_top__DOT__u_gsx__DOT__pv__v0 = 1U;
                } else {
                    vlSelfRef.ember_top__DOT__u_gsx__DOT____Vlvbound_hd1051bc7__0 = 0U;
                }
            }
        } else if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__st))) {
            if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__st))) {
                vlSelfRef.ember_top__DOT__u_gsx__DOT__f_lane_en = 0x0fU;
                vlSelfRef.ember_top__DOT__u_gsx__DOT__f_op = 3U;
                vlSelfRef.ember_top__DOT__u_gsx__DOT__f_a0 
                    = vlSelfRef.ember_top__DOT__u_gsx__DOT__acc0;
                vlSelfRef.ember_top__DOT__u_gsx__DOT__f_b0 
                    = vlSelfRef.ember_top__DOT__u_gsx__DOT__acc3;
                vlSelfRef.ember_top__DOT__u_gsx__DOT__f_a1 
                    = vlSelfRef.ember_top__DOT__u_gsx__DOT__acc1;
                vlSelfRef.ember_top__DOT__u_gsx__DOT__f_a2 
                    = vlSelfRef.ember_top__DOT__u_gsx__DOT__acc2;
                vlSelfRef.ember_top__DOT__u_gsx__DOT__f_a3 = 0x3f800000U;
                vlSelfRef.ember_top__DOT__u_gsx__DOT__f_go = 1U;
                vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__st = 4U;
                vlSelfRef.ember_top__DOT__u_gsx__DOT__f_b1 
                    = vlSelfRef.ember_top__DOT__u_gsx__DOT__acc3;
                vlSelfRef.ember_top__DOT__u_gsx__DOT__f_b2 
                    = vlSelfRef.ember_top__DOT__u_gsx__DOT__acc3;
                vlSelfRef.ember_top__DOT__u_gsx__DOT__f_b3 
                    = vlSelfRef.ember_top__DOT__u_gsx__DOT__acc3;
                vlSelfRef.ember_top__DOT__u_gsx__DOT__w_in 
                    = vlSelfRef.ember_top__DOT__u_gsx__DOT__acc3;
            } else if (vlSelfRef.ember_top__DOT__u_gsx__DOT__f_done) {
                if (vlSelfRef.ember_top__DOT__u_gsx__DOT__phase) {
                    vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__acc0 
                        = vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s0[0U];
                    vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__acc1 
                        = vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s1[0U];
                    vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__acc2 
                        = vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s2[0U];
                    vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__acc3 
                        = vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s3[0U];
                    if ((3U == (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__kstep))) {
                        vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__st = 3U;
                    } else {
                        vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__kstep 
                            = (3U & ((IData)(1U) + (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__kstep)));
                        vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__phase = 0U;
                        vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__st = 1U;
                    }
                } else {
                    vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__phase = 1U;
                    vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__st = 1U;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__st))) {
            vlSelfRef.ember_top__DOT__u_gsx__DOT__f_lane_en = 0x0fU;
            vlSelfRef.ember_top__DOT__u_gsx__DOT__f_go = 1U;
            if (vlSelfRef.ember_top__DOT__u_gsx__DOT__phase) {
                vlSelfRef.ember_top__DOT__u_gsx__DOT__f_op = 0U;
                vlSelfRef.ember_top__DOT__u_gsx__DOT__f_a0 
                    = vlSelfRef.ember_top__DOT__u_gsx__DOT__acc0;
                vlSelfRef.ember_top__DOT__u_gsx__DOT__f_b0 
                    = vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s0[0U];
                vlSelfRef.ember_top__DOT__u_gsx__DOT__f_a1 
                    = vlSelfRef.ember_top__DOT__u_gsx__DOT__acc1;
                vlSelfRef.ember_top__DOT__u_gsx__DOT__f_b1 
                    = vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s1[0U];
                vlSelfRef.ember_top__DOT__u_gsx__DOT__f_a2 
                    = vlSelfRef.ember_top__DOT__u_gsx__DOT__acc2;
                vlSelfRef.ember_top__DOT__u_gsx__DOT__f_b2 
                    = vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s2[0U];
                vlSelfRef.ember_top__DOT__u_gsx__DOT__f_a3 
                    = vlSelfRef.ember_top__DOT__u_gsx__DOT__acc3;
                vlSelfRef.ember_top__DOT__u_gsx__DOT__f_b3 
                    = vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s3[0U];
            } else {
                vlSelfRef.ember_top__DOT__u_gsx__DOT__f_op = 2U;
                if ((3U == (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__kstep))) {
                    vlSelfRef.ember_top__DOT__u_gsx__DOT__f_a0 
                        = vlSelfRef.ember_top__DOT__u_gsx__DOT__mata[3U];
                    vlSelfRef.ember_top__DOT__u_gsx__DOT__f_b0 = 0x3f800000U;
                    vlSelfRef.ember_top__DOT__u_gsx__DOT__f_a1 
                        = vlSelfRef.ember_top__DOT__u_gsx__DOT__mata[7U];
                    vlSelfRef.ember_top__DOT__u_gsx__DOT__f_b1 = 0x3f800000U;
                    vlSelfRef.ember_top__DOT__u_gsx__DOT__f_a2 
                        = vlSelfRef.ember_top__DOT__u_gsx__DOT__mata[11U];
                    vlSelfRef.ember_top__DOT__u_gsx__DOT__f_b2 = 0x3f800000U;
                    vlSelfRef.ember_top__DOT__u_gsx__DOT__f_a3 
                        = vlSelfRef.ember_top__DOT__u_gsx__DOT__mata[15U];
                    vlSelfRef.ember_top__DOT__u_gsx__DOT__f_b3 = 0x3f800000U;
                } else {
                    vlSelfRef.ember_top__DOT__u_gsx__DOT__f_a0 
                        = vlSelfRef.ember_top__DOT__u_gsx__DOT__mata
                        [(0x0000000fU & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__kstep))];
                    if ((0x0eU >= (0x0000000fU & (((IData)(5U) 
                                                   * (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__vidx)) 
                                                  + (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__kstep))))) {
                        vlSelfRef.ember_top__DOT__u_gsx__DOT__f_b0 
                            = vlSelfRef.ember_top__DOT__u_gsx__DOT__vtx
                            [(0x0000000fU & (((IData)(5U) 
                                              * (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__vidx)) 
                                             + (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__kstep)))];
                        vlSelfRef.ember_top__DOT__u_gsx__DOT__f_b1 
                            = vlSelfRef.ember_top__DOT__u_gsx__DOT__vtx
                            [(0x0000000fU & (((IData)(5U) 
                                              * (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__vidx)) 
                                             + (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__kstep)))];
                        vlSelfRef.ember_top__DOT__u_gsx__DOT__f_b2 
                            = vlSelfRef.ember_top__DOT__u_gsx__DOT__vtx
                            [(0x0000000fU & (((IData)(5U) 
                                              * (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__vidx)) 
                                             + (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__kstep)))];
                        vlSelfRef.ember_top__DOT__u_gsx__DOT__f_b3 
                            = vlSelfRef.ember_top__DOT__u_gsx__DOT__vtx
                            [(0x0000000fU & (((IData)(5U) 
                                              * (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__vidx)) 
                                             + (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__kstep)))];
                    } else {
                        vlSelfRef.ember_top__DOT__u_gsx__DOT__f_b0 = 0U;
                        vlSelfRef.ember_top__DOT__u_gsx__DOT__f_b1 = 0U;
                        vlSelfRef.ember_top__DOT__u_gsx__DOT__f_b2 = 0U;
                        vlSelfRef.ember_top__DOT__u_gsx__DOT__f_b3 = 0U;
                    }
                    vlSelfRef.ember_top__DOT__u_gsx__DOT__f_a1 
                        = vlSelfRef.ember_top__DOT__u_gsx__DOT__mata
                        [(0x0000000fU & ((IData)(4U) 
                                         + (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__kstep)))];
                    vlSelfRef.ember_top__DOT__u_gsx__DOT__f_a2 
                        = vlSelfRef.ember_top__DOT__u_gsx__DOT__mata
                        [(0x0000000fU & ((IData)(8U) 
                                         + (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__kstep)))];
                    vlSelfRef.ember_top__DOT__u_gsx__DOT__f_a3 
                        = vlSelfRef.ember_top__DOT__u_gsx__DOT__mata
                        [(0x0000000fU & ((IData)(0x0cU) 
                                         + (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__kstep)))];
                }
            }
            vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__st = 2U;
        } else {
            vlSelfRef.ember_top__DOT__u_gsx__DOT__busy_r = 0U;
            if (((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_0) 
                 & ((0x0044U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
                    & vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata))) {
                vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__vidx = 0U;
                vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__eidx = 0U;
                vlSelfRef.ember_top__DOT__u_gsx__DOT__busy_r = 1U;
                vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__kstep = 0U;
                vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__phase = 0U;
                vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__acc0 = 0U;
                vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__acc1 = 0U;
                vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__acc2 = 0U;
                vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__acc3 = 0U;
                vlSelfRef.ember_top__DOT__u_gsx__DOT__emit_base 
                    = ((IData)(0x0005c000U) + ((IData)(0x0000004cU) 
                                               * (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__tri_count)));
                vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__st = 1U;
            }
        }
        vlSelfRef.ember_top__DOT__core_cxa_we = 0U;
        vlSelfRef.ember_top__DOT__core_cxa_req = 0U;
        vlSelfRef.ember_top__DOT__core_ixa_req = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__f_go = 0U;
        if (((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ix_pend) 
             & (~ (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ix_req_cyc)))) {
            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__ix_pend = 0U;
            if (((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__flush_req) 
                 & ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ix_tid) 
                    == (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__flush_tid)))) {
                vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__flush_req = 0U;
            } else {
                vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_v 
                    = ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_v) 
                       | (0x0fU & ((IData)(1U) << (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ix_tid))));
                __VdlyVal__ember_top__DOT__u_core__DOT__ibuf_w__v0 
                    = vlSelfRef.ember_top__DOT__u_vram__DOT__ixa_rdata_q;
                __VdlyDim0__ember_top__DOT__u_core__DOT__ibuf_w__v0 
                    = vlSelfRef.ember_top__DOT__u_core__DOT__ix_tid;
                vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__ibuf_w__v0 = 1U;
            }
        } else if (vlSelfRef.ember_top__DOT__u_core__DOT__flush_req) {
            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__flush_req = 0U;
        }
        if (vlSelfRef.ember_top__DOT__u_core__DOT__ix_req_cyc) {
            vlSelfRef.ember_top__DOT__u_core__DOT__ix_req_cyc = 0U;
        }
        if (((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__cx_pend) 
             & (~ (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__cx_req_cyc)))) {
            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__cx_pend = 0U;
            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__dr_valid = 1U;
            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__dr_tid 
                = vlSelfRef.ember_top__DOT__u_core__DOT__ld_tid_q;
            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__dr_rd 
                = vlSelfRef.ember_top__DOT__u_core__DOT__ld_rd_q;
            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__dr_word 
                = vlSelfRef.ember_top__DOT__u_vram__DOT__cxa_rdata_q;
        }
        if (vlSelfRef.ember_top__DOT__u_core__DOT__cx_req_cyc) {
            vlSelfRef.ember_top__DOT__u_core__DOT__cx_req_cyc = 0U;
        }
        if (vlSelfRef.ember_top__DOT__u_core__DOT__dr_valid) {
            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__dr_valid = 0U;
            __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v0 
                = vlSelfRef.ember_top__DOT__u_core__DOT__dr_word;
            __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v0 
                = vlSelfRef.ember_top__DOT__u_core__DOT__dr_rd;
            __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v0 
                = vlSelfRef.ember_top__DOT__u_core__DOT__dr_tid;
            vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__gpr__v0 = 1U;
            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__waitv 
                = ((~ ((IData)(1U) << (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__dr_tid))) 
                   & (IData)(vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__waitv));
        }
        if (((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__fp_pend) 
             & ((vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U] 
                 | (vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[3U] 
                    | (vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U] 
                       | vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U]))) 
                >> 5U))) {
            __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v1 
                = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[0U];
            __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v1 
                = vlSelfRef.ember_top__DOT__u_core__DOT__fp_rd;
            __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v1 
                = vlSelfRef.ember_top__DOT__u_core__DOT__fp_tid;
            vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__gpr__v1 = 1U;
            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__waitv 
                = ((~ ((IData)(1U) << (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__fp_tid))) 
                   & (IData)(vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__waitv));
            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__fp_pend = 0U;
        }
        if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__st))) {
            if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__st))) {
                vlSelfRef.ember_top__DOT__u_core__DOT__running = 0U;
                vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__st = 0U;
            } else if (((0x000000ffU & ((IData)(1U) 
                                        + (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__blk))) 
                        >= (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__nblk_q))) {
                vlSelfRef.ember_top__DOT__u_core__DOT__running = 0U;
                vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__st = 3U;
            } else {
                vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__blk 
                    = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__blk)));
                __Vtask_ember_top__DOT__u_core__DOT__init_block__7__b 
                    = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__blk)));
                vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__T__v0 = 1U;
                vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_v = 0U;
                vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__waitv = 0U;
                vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__barv = 0U;
                vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__bar_count = 0U;
                vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__budget = 0U;
                vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__st = 1U;
                vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__T__v1 = 1U;
                __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v3 
                    = __Vtask_ember_top__DOT__u_core__DOT__init_block__7__b;
                __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v4 
                    = vlSelfRef.ember_top__DOT__u_core__DOT__nblk_q;
                __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v7 
                    = __Vtask_ember_top__DOT__u_core__DOT__init_block__7__b;
                __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v8 
                    = vlSelfRef.ember_top__DOT__u_core__DOT__nblk_q;
                __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v11 
                    = __Vtask_ember_top__DOT__u_core__DOT__init_block__7__b;
                __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v12 
                    = vlSelfRef.ember_top__DOT__u_core__DOT__nblk_q;
                __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v15 
                    = __Vtask_ember_top__DOT__u_core__DOT__init_block__7__b;
                __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v16 
                    = vlSelfRef.ember_top__DOT__u_core__DOT__nblk_q;
            }
        } else if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__st))) {
            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__budget 
                = (0x000fffffU & ((IData)(1U) + vlSelfRef.ember_top__DOT__u_core__DOT__budget));
            if ((0x000fffffU == vlSelfRef.ember_top__DOT__u_core__DOT__budget)) {
                vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__T__v8 = 1U;
                vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__st = 2U;
                vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__T__v9 = 1U;
            } else {
                if (vlSelfRef.ember_top__DOT__u_core__DOT__exec_en) {
                    vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_v 
                        = ((~ ((IData)(1U) << (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid))) 
                           & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_v));
                    if ((1U & (~ (vlSelfRef.ember_top__DOT__u_core__DOT__T
                                  [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid] 
                                  >> 3U)))) {
                        if ((0x00000080U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                            if ((0x00000040U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                                if ((0x00000020U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                                    if ((0x00000010U 
                                         & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                                        if ((8U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                                            if ((4U 
                                                 & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                                                    if (
                                                        (1U 
                                                         & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                                                        __VdlyDim0__ember_top__DOT__u_core__DOT__T__v12 
                                                            = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                                        vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__T__v12 = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((0x00000040U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                            if ((1U & (~ ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op) 
                                          >> 5U)))) {
                                if ((1U & (~ ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op) 
                                              >> 4U)))) {
                                    if ((1U & (~ ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op) 
                                                  >> 3U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op) 
                                                    >> 2U)))) {
                                            vlSelfRef.ember_top__DOT__u_core__DOT__f_lane_en = 1U;
                                            vlSelfRef.ember_top__DOT__u_core__DOT__f_op 
                                                = (3U 
                                                   & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op));
                                            vlSelfRef.ember_top__DOT__u_core__DOT__f_a0 
                                                = vlSelfRef.ember_top__DOT__u_core__DOT__rav;
                                            vlSelfRef.ember_top__DOT__u_core__DOT__f_b0 
                                                = vlSelfRef.ember_top__DOT__u_core__DOT__rbv;
                                            vlSelfRef.ember_top__DOT__u_core__DOT__f_go = 1U;
                                            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__fp_pend = 1U;
                                            vlSelfRef.ember_top__DOT__u_core__DOT__fp_tid 
                                                = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                            vlSelfRef.ember_top__DOT__u_core__DOT__fp_rd 
                                                = vlSelfRef.ember_top__DOT__u_core__DOT__i_rd;
                                            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__waitv 
                                                = ((IData)(vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__waitv) 
                                                   | (0x0fU 
                                                      & ((IData)(1U) 
                                                         << (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid))));
                                        }
                                    }
                                }
                            }
                        } else if ((0x00000020U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                            if ((1U & (~ ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op) 
                                          >> 4U)))) {
                                if ((1U & (~ ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op) 
                                              >> 3U)))) {
                                    if ((4U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op) 
                                                    >> 1U)))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                                                vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__barv 
                                                    = 
                                                    ((IData)(vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__barv) 
                                                     | (0x0fU 
                                                        & ((IData)(1U) 
                                                           << (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid))));
                                                vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__bar_count 
                                                    = 
                                                    (3U 
                                                     & ((IData)(1U) 
                                                        + (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__bar_count)));
                                                if (
                                                    (3U 
                                                     == (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__bar_count))) {
                                                    vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__barv = 0U;
                                                    vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__bar_count = 0U;
                                                }
                                            } else {
                                                vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__flush_req = 1U;
                                                __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v18 
                                                    = vlSelfRef.ember_top__DOT__u_core__DOT__fpc
                                                    [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid];
                                                __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v18 
                                                    = 
                                                    ((0x21U 
                                                      == (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))
                                                      ? (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_rd)
                                                      : 0x0fU);
                                                __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v18 
                                                    = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                                vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__gpr__v18 = 1U;
                                                vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__flush_tid 
                                                    = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                                __VdlyVal__ember_top__DOT__u_core__DOT__fpc__v4 
                                                    = 
                                                    (0x000000ffU 
                                                     & (vlSelfRef.ember_top__DOT__u_core__DOT__fpc
                                                        [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid] 
                                                        + (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_sx11)));
                                                __VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v4 
                                                    = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                                vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__fpc__v4 = 1U;
                                            }
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                                        if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                                            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__flush_req = 1U;
                                            __VdlyVal__ember_top__DOT__u_core__DOT__fpc__v5 
                                                = (0x000000ffU 
                                                   & vlSelfRef.ember_top__DOT__u_core__DOT__gpr
                                                   [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid][15U]);
                                            __VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v5 
                                                = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                            vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__fpc__v5 = 1U;
                                            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__flush_tid 
                                                = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                        } else {
                                            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__flush_req = 1U;
                                            __VdlyVal__ember_top__DOT__u_core__DOT__fpc__v6 
                                                = (0x000000ffU 
                                                   & vlSelfRef.ember_top__DOT__u_core__DOT__gpr
                                                   [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid]
                                                   [vlSelfRef.ember_top__DOT__u_core__DOT__i_ra]);
                                            __VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v6 
                                                = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                            vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__fpc__v6 = 1U;
                                            vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__flush_tid 
                                                = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                                        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__flush_req = 1U;
                                        __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v19 
                                            = vlSelfRef.ember_top__DOT__u_core__DOT__fpc
                                            [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid];
                                        __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v19 
                                            = ((0x21U 
                                                == (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))
                                                ? (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_rd)
                                                : 0x0fU);
                                        __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v19 
                                            = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                        vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__gpr__v19 = 1U;
                                        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__flush_tid 
                                            = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                        __VdlyVal__ember_top__DOT__u_core__DOT__fpc__v7 
                                            = (0x000000ffU 
                                               & (vlSelfRef.ember_top__DOT__u_core__DOT__fpc
                                                  [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid] 
                                                  + (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_sx11)));
                                        __VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v7 
                                            = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                        vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__fpc__v7 = 1U;
                                    } else if ((0U 
                                                != 
                                                (7U 
                                                 & (vlSelfRef.ember_top__DOT__u_core__DOT__T
                                                    [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid] 
                                                    & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_rd))))) {
                                        __VdlyVal__ember_top__DOT__u_core__DOT__fpc__v8 
                                            = (0x000000ffU 
                                               & (vlSelfRef.ember_top__DOT__u_core__DOT__fpc
                                                  [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid] 
                                                  + (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_sx9)));
                                        __VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v8 
                                            = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                        vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__fpc__v8 = 1U;
                                        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__flush_req = 1U;
                                        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__flush_tid 
                                            = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                    }
                                }
                            }
                        } else if ((0x00000010U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                            if ((1U & (~ ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op) 
                                          >> 3U)))) {
                                if ((4U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                                    if ((1U & (~ ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op) 
                                                  >> 1U)))) {
                                        if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                                            if (VL_GTS_III(32, vlSelfRef.ember_top__DOT__u_core__DOT__gpr
                                                           [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid]
                                                           [vlSelfRef.ember_top__DOT__u_core__DOT__i_rd], vlSelfRef.ember_top__DOT__u_core__DOT__smem
                                                           [
                                                           (0x000003ffU 
                                                            & (vlSelfRef.ember_top__DOT__u_core__DOT__rav 
                                                               + vlSelfRef.ember_top__DOT__u_core__DOT__i_sx12))])) {
                                                __VdlyVal__ember_top__DOT__u_core__DOT__smem__v0 
                                                    = vlSelfRef.ember_top__DOT__u_core__DOT__gpr
                                                    [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid]
                                                    [vlSelfRef.ember_top__DOT__u_core__DOT__i_rd];
                                                __VdlyDim0__ember_top__DOT__u_core__DOT__smem__v0 
                                                    = 
                                                    (0x000003ffU 
                                                     & (vlSelfRef.ember_top__DOT__u_core__DOT__rav 
                                                        + vlSelfRef.ember_top__DOT__u_core__DOT__i_sx12));
                                                vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__smem__v0 = 1U;
                                            }
                                        } else {
                                            __VdlyVal__ember_top__DOT__u_core__DOT__smem__v1 
                                                = (vlSelfRef.ember_top__DOT__u_core__DOT__smem
                                                   [
                                                   (0x000003ffU 
                                                    & (vlSelfRef.ember_top__DOT__u_core__DOT__rav 
                                                       + vlSelfRef.ember_top__DOT__u_core__DOT__i_sx12))] 
                                                   + vlSelfRef.ember_top__DOT__u_core__DOT__gpr
                                                   [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid]
                                                   [vlSelfRef.ember_top__DOT__u_core__DOT__i_rd]);
                                            __VdlyDim0__ember_top__DOT__u_core__DOT__smem__v1 
                                                = (0x000003ffU 
                                                   & (vlSelfRef.ember_top__DOT__u_core__DOT__rav 
                                                      + vlSelfRef.ember_top__DOT__u_core__DOT__i_sx12));
                                            vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__smem__v1 = 1U;
                                        }
                                    }
                                } else if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                                    if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                                        __VdlyVal__ember_top__DOT__u_core__DOT__smem__v2 
                                            = vlSelfRef.ember_top__DOT__u_core__DOT__gpr
                                            [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid]
                                            [vlSelfRef.ember_top__DOT__u_core__DOT__i_rd];
                                        __VdlyDim0__ember_top__DOT__u_core__DOT__smem__v2 
                                            = (0x000003ffU 
                                               & (vlSelfRef.ember_top__DOT__u_core__DOT__rav 
                                                  + vlSelfRef.ember_top__DOT__u_core__DOT__i_sx12));
                                        vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__smem__v2 = 1U;
                                    } else {
                                        __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v20 
                                            = vlSelfRef.ember_top__DOT__u_core__DOT__smem
                                            [(0x000003ffU 
                                              & (vlSelfRef.ember_top__DOT__u_core__DOT__rav 
                                                 + vlSelfRef.ember_top__DOT__u_core__DOT__i_sx12))];
                                        __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v20 
                                            = vlSelfRef.ember_top__DOT__u_core__DOT__i_rd;
                                        __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v20 
                                            = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                        vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__gpr__v20 = 1U;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                                    vlSelfRef.ember_top__DOT__core_cxa_we = 1U;
                                    vlSelfRef.ember_top__DOT__core_cxa_be = 0x0fU;
                                    vlSelfRef.ember_top__DOT__core_cxa_addr 
                                        = ((IData)(0x00001000U) 
                                           + (vlSelfRef.ember_top__DOT__u_core__DOT__rav 
                                              + vlSelfRef.ember_top__DOT__u_core__DOT__i_sx12));
                                    vlSelfRef.ember_top__DOT__core_cxa_wdata 
                                        = vlSelfRef.ember_top__DOT__u_core__DOT__gpr
                                        [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid]
                                        [vlSelfRef.ember_top__DOT__u_core__DOT__i_rd];
                                } else {
                                    vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__ld_pend = 1U;
                                    vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__ld_addr_q 
                                        = ((IData)(0x00001000U) 
                                           + (vlSelfRef.ember_top__DOT__u_core__DOT__rav 
                                              + vlSelfRef.ember_top__DOT__u_core__DOT__i_sx12));
                                    vlSelfRef.ember_top__DOT__u_core__DOT__ld_tid_q 
                                        = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                    vlSelfRef.ember_top__DOT__u_core__DOT__ld_rd_q 
                                        = vlSelfRef.ember_top__DOT__u_core__DOT__i_rd;
                                    vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__waitv 
                                        = ((IData)(vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__waitv) 
                                           | (0x0fU 
                                              & ((IData)(1U) 
                                                 << (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid))));
                                }
                            }
                        } else if ((8U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                            if ((4U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                                if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                                    if ((1U & (~ (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op)))) {
                                        __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v21 
                                            = (((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_ra) 
                                                << 0x0000000cU) 
                                               | (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_imm));
                                        __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v21 
                                            = vlSelfRef.ember_top__DOT__u_core__DOT__i_rd;
                                        __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v21 
                                            = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                        vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__gpr__v21 = 1U;
                                    }
                                } else {
                                    __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v22 
                                        = ((1U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))
                                            ? (((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_ra) 
                                                << 0x0000000cU) 
                                               | (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_imm))
                                            : (VL_GTS_III(32, vlSelfRef.ember_top__DOT__u_core__DOT__rav, vlSelfRef.ember_top__DOT__u_core__DOT__rbv)
                                                ? vlSelfRef.ember_top__DOT__u_core__DOT__rav
                                                : vlSelfRef.ember_top__DOT__u_core__DOT__rbv));
                                    __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v22 
                                        = vlSelfRef.ember_top__DOT__u_core__DOT__i_rd;
                                    __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v22 
                                        = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                    vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__gpr__v22 = 1U;
                                }
                            } else if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                                if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                                    __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v23 
                                        = (VL_LTS_III(32, vlSelfRef.ember_top__DOT__u_core__DOT__rav, vlSelfRef.ember_top__DOT__u_core__DOT__rbv)
                                            ? vlSelfRef.ember_top__DOT__u_core__DOT__rav
                                            : vlSelfRef.ember_top__DOT__u_core__DOT__rbv);
                                    __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v23 
                                        = vlSelfRef.ember_top__DOT__u_core__DOT__i_rd;
                                    __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v23 
                                        = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                    vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__gpr__v23 = 1U;
                                } else {
                                    vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk7__DOT__d 
                                        = (vlSelfRef.ember_top__DOT__u_core__DOT__rav 
                                           - vlSelfRef.ember_top__DOT__u_core__DOT__rbv);
                                    __VdlyVal__ember_top__DOT__u_core__DOT__T__v13 
                                        = ((4U & (vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk7__DOT__d 
                                                  >> 0x0000001dU)) 
                                           | (((0U 
                                                == vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk7__DOT__d) 
                                               << 1U) 
                                              | ((~ 
                                                  (vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk7__DOT__d 
                                                   >> 0x1fU)) 
                                                 & (0U 
                                                    != vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk7__DOT__d))));
                                    __VdlyDim0__ember_top__DOT__u_core__DOT__T__v13 
                                        = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                    vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__T__v13 = 1U;
                                }
                            } else {
                                __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v24 
                                    = ((1U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))
                                        ? (vlSelfRef.ember_top__DOT__u_core__DOT__rav 
                                           >> (0x0000001fU 
                                               & vlSelfRef.ember_top__DOT__u_core__DOT__rbv))
                                        : (vlSelfRef.ember_top__DOT__u_core__DOT__rav 
                                           << (0x0000001fU 
                                               & vlSelfRef.ember_top__DOT__u_core__DOT__rbv)));
                                __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v24 
                                    = vlSelfRef.ember_top__DOT__u_core__DOT__i_rd;
                                __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v24 
                                    = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__gpr__v24 = 1U;
                            }
                        } else if ((4U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                            __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v25 
                                = ((2U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))
                                    ? ((1U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))
                                        ? (vlSelfRef.ember_top__DOT__u_core__DOT__rav 
                                           ^ vlSelfRef.ember_top__DOT__u_core__DOT__rbv)
                                        : (vlSelfRef.ember_top__DOT__u_core__DOT__rav 
                                           | vlSelfRef.ember_top__DOT__u_core__DOT__rbv))
                                    : ((1U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))
                                        ? (vlSelfRef.ember_top__DOT__u_core__DOT__rav 
                                           & vlSelfRef.ember_top__DOT__u_core__DOT__rbv)
                                        : ((0U == vlSelfRef.ember_top__DOT__u_core__DOT__rbv)
                                            ? 0U : 
                                           VL_DIV_III(32, vlSelfRef.ember_top__DOT__u_core__DOT__rav, vlSelfRef.ember_top__DOT__u_core__DOT__rbv))));
                            __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v25 
                                = vlSelfRef.ember_top__DOT__u_core__DOT__i_rd;
                            __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v25 
                                = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                            vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__gpr__v25 = 1U;
                        } else if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                            __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v26 
                                = ((1U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))
                                    ? VL_MULS_III(32, vlSelfRef.ember_top__DOT__u_core__DOT__rav, vlSelfRef.ember_top__DOT__u_core__DOT__rbv)
                                    : (vlSelfRef.ember_top__DOT__u_core__DOT__rav 
                                       - vlSelfRef.ember_top__DOT__u_core__DOT__rbv));
                            __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v26 
                                = vlSelfRef.ember_top__DOT__u_core__DOT__i_rd;
                            __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v26 
                                = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                            vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__gpr__v26 = 1U;
                        } else if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                            __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v27 
                                = (vlSelfRef.ember_top__DOT__u_core__DOT__rav 
                                   + vlSelfRef.ember_top__DOT__u_core__DOT__rbv);
                            __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v27 
                                = vlSelfRef.ember_top__DOT__u_core__DOT__i_rd;
                            __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v27 
                                = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                            vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__gpr__v27 = 1U;
                        }
                    }
                }
                if (((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ld_pend) 
                     & (~ (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__cx_pend)))) {
                    vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__ld_pend = 0U;
                    vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__cx_pend = 1U;
                    vlSelfRef.ember_top__DOT__u_core__DOT__cx_req_cyc = 1U;
                    vlSelfRef.ember_top__DOT__core_cxa_req = 1U;
                    vlSelfRef.ember_top__DOT__core_cxa_addr 
                        = vlSelfRef.ember_top__DOT__u_core__DOT__ld_addr_q;
                }
                if ((((~ (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ix_pend)) 
                      & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__pick_en)) 
                     & (~ ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__flush_req) 
                           & ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__flush_tid) 
                              == (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__pick_tid)))))) {
                    vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__ix_pend = 1U;
                    vlSelfRef.ember_top__DOT__u_core__DOT__ix_req_cyc = 1U;
                    vlSelfRef.ember_top__DOT__u_core__DOT__ix_tid 
                        = vlSelfRef.ember_top__DOT__u_core__DOT__pick_tid;
                    vlSelfRef.ember_top__DOT__core_ixa_req = 1U;
                    vlSelfRef.ember_top__DOT__core_ixa_addr 
                        = ((IData)(0x00001000U) + (vlSelfRef.ember_top__DOT__u_core__DOT__code_base_q 
                                                   + 
                                                   (vlSelfRef.ember_top__DOT__u_core__DOT__fpc
                                                    [vlSelfRef.ember_top__DOT__u_core__DOT__pick_tid] 
                                                    << 2U)));
                    __VdlyVal__ember_top__DOT__u_core__DOT__fpc__v9 
                        = (0x000000ffU & ((IData)(1U) 
                                          + vlSelfRef.ember_top__DOT__u_core__DOT__fpc
                                          [vlSelfRef.ember_top__DOT__u_core__DOT__pick_tid]));
                    __VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v9 
                        = vlSelfRef.ember_top__DOT__u_core__DOT__pick_tid;
                    vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__fpc__v9 = 1U;
                }
                if ((((((((((~ (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__exec_en)) 
                            & (~ (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__pick_en))) 
                           & (~ (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ix_pend))) 
                          & (~ (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__cx_pend))) 
                         & (~ (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__dr_valid))) 
                        & (~ (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__fp_pend))) 
                       & (~ (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ld_pend))) 
                      & (0U == (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__waitv))) 
                     & (0U == (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__barv)))) {
                    vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__st = 2U;
                }
            }
        } else {
            vlSelfRef.ember_top__DOT__u_core__DOT__running = 0U;
            if (((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_0) 
                 & ((0x0054U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
                    & vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata))) {
                vlSelfRef.ember_top__DOT__u_core__DOT__running = 1U;
                vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__blk = 0U;
                vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__T__v14 = 1U;
                vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_v = 0U;
                vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__waitv = 0U;
                vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__barv = 0U;
                vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__bar_count = 0U;
                vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__budget = 0U;
                vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__st = 1U;
                vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__T__v15 = 1U;
                __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v30 
                    = vlSelfRef.ember_top__DOT__u_core__DOT__nblk_q;
                __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v34 
                    = vlSelfRef.ember_top__DOT__u_core__DOT__nblk_q;
                __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v38 
                    = vlSelfRef.ember_top__DOT__u_core__DOT__nblk_q;
                __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v42 
                    = vlSelfRef.ember_top__DOT__u_core__DOT__nblk_q;
            }
        }
        vlSelfRef.ember_top__DOT__tu_tua_we = 0U;
        vlSelfRef.ember_top__DOT__tu_tua_req = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_ld = 0U;
        if (((IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__rq_pend) 
             & (~ (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__rq_req_cyc)))) {
            vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__rq_pend = 0U;
            if (vlSelfRef.ember_top__DOT__u_tu__DOT__rq_dst_w) {
                __VdlyVal__ember_top__DOT__u_tu__DOT__abuf_q__v0 
                    = vlSelfRef.ember_top__DOT__u_vram__DOT__tua_rdata_q;
                __VdlyDim0__ember_top__DOT__u_tu__DOT__abuf_q__v0 
                    = vlSelfRef.ember_top__DOT__u_tu__DOT__rq_aw;
                vlSelfRef.__VdlySet__ember_top__DOT__u_tu__DOT__abuf_q__v0 = 1U;
            } else {
                __VdlyVal__ember_top__DOT__u_tu__DOT__wrowbuf__v0 
                    = vlSelfRef.ember_top__DOT__u_vram__DOT__tua_rdata_q;
                __VdlyDim0__ember_top__DOT__u_tu__DOT__wrowbuf__v0 
                    = vlSelfRef.ember_top__DOT__u_tu__DOT__rq_aw;
                vlSelfRef.__VdlySet__ember_top__DOT__u_tu__DOT__wrowbuf__v0 = 1U;
            }
        }
        if (vlSelfRef.ember_top__DOT__u_tu__DOT__rq_req_cyc) {
            vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__rq_req_cyc = 0U;
        }
        if (vlSelfRef.ember_top__DOT__u_tu__DOT__mac_pend) {
            __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v0 
                = (vlSelfRef.ember_top__DOT__u_tu__DOT__acc
                   [vlSelfRef.ember_top__DOT__u_tu__DOT__mrow][0U] 
                   + vlSelfRef.ember_top__DOT__u_tu__DOT__tree[0U]);
            __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v0 
                = vlSelfRef.ember_top__DOT__u_tu__DOT__mrow;
            vlSelfRef.__VdlySet__ember_top__DOT__u_tu__DOT__acc__v0 = 1U;
            vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__mac_pend = 0U;
            __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v1 
                = (vlSelfRef.ember_top__DOT__u_tu__DOT__acc
                   [vlSelfRef.ember_top__DOT__u_tu__DOT__mrow][1U] 
                   + vlSelfRef.ember_top__DOT__u_tu__DOT__tree[1U]);
            __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v1 
                = vlSelfRef.ember_top__DOT__u_tu__DOT__mrow;
            vlSelfRef.__VdlySet__ember_top__DOT__u_tu__DOT__acc__v1 = 1U;
            __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v2 
                = (vlSelfRef.ember_top__DOT__u_tu__DOT__acc
                   [vlSelfRef.ember_top__DOT__u_tu__DOT__mrow][2U] 
                   + vlSelfRef.ember_top__DOT__u_tu__DOT__tree[2U]);
            __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v2 
                = vlSelfRef.ember_top__DOT__u_tu__DOT__mrow;
            __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v3 
                = (vlSelfRef.ember_top__DOT__u_tu__DOT__acc
                   [vlSelfRef.ember_top__DOT__u_tu__DOT__mrow][3U] 
                   + vlSelfRef.ember_top__DOT__u_tu__DOT__tree[3U]);
            __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v3 
                = vlSelfRef.ember_top__DOT__u_tu__DOT__mrow;
            __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v4 
                = (vlSelfRef.ember_top__DOT__u_tu__DOT__acc
                   [vlSelfRef.ember_top__DOT__u_tu__DOT__mrow][4U] 
                   + vlSelfRef.ember_top__DOT__u_tu__DOT__tree[4U]);
            __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v4 
                = vlSelfRef.ember_top__DOT__u_tu__DOT__mrow;
            __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v5 
                = (vlSelfRef.ember_top__DOT__u_tu__DOT__acc
                   [vlSelfRef.ember_top__DOT__u_tu__DOT__mrow][5U] 
                   + vlSelfRef.ember_top__DOT__u_tu__DOT__tree[5U]);
            __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v5 
                = vlSelfRef.ember_top__DOT__u_tu__DOT__mrow;
            __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v6 
                = (vlSelfRef.ember_top__DOT__u_tu__DOT__acc
                   [vlSelfRef.ember_top__DOT__u_tu__DOT__mrow][6U] 
                   + vlSelfRef.ember_top__DOT__u_tu__DOT__tree[6U]);
            __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v6 
                = vlSelfRef.ember_top__DOT__u_tu__DOT__mrow;
            __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v7 
                = (vlSelfRef.ember_top__DOT__u_tu__DOT__acc
                   [vlSelfRef.ember_top__DOT__u_tu__DOT__mrow][7U] 
                   + vlSelfRef.ember_top__DOT__u_tu__DOT__tree[7U]);
            __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v7 
                = vlSelfRef.ember_top__DOT__u_tu__DOT__mrow;
            __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v8 
                = (vlSelfRef.ember_top__DOT__u_tu__DOT__acc
                   [vlSelfRef.ember_top__DOT__u_tu__DOT__mrow][8U] 
                   + vlSelfRef.ember_top__DOT__u_tu__DOT__tree[8U]);
            __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v8 
                = vlSelfRef.ember_top__DOT__u_tu__DOT__mrow;
            __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v9 
                = (vlSelfRef.ember_top__DOT__u_tu__DOT__acc
                   [vlSelfRef.ember_top__DOT__u_tu__DOT__mrow][9U] 
                   + vlSelfRef.ember_top__DOT__u_tu__DOT__tree[9U]);
            __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v9 
                = vlSelfRef.ember_top__DOT__u_tu__DOT__mrow;
            __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v10 
                = (vlSelfRef.ember_top__DOT__u_tu__DOT__acc
                   [vlSelfRef.ember_top__DOT__u_tu__DOT__mrow][10U] 
                   + vlSelfRef.ember_top__DOT__u_tu__DOT__tree[10U]);
            __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v10 
                = vlSelfRef.ember_top__DOT__u_tu__DOT__mrow;
            __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v11 
                = (vlSelfRef.ember_top__DOT__u_tu__DOT__acc
                   [vlSelfRef.ember_top__DOT__u_tu__DOT__mrow][11U] 
                   + vlSelfRef.ember_top__DOT__u_tu__DOT__tree[11U]);
            __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v11 
                = vlSelfRef.ember_top__DOT__u_tu__DOT__mrow;
            __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v12 
                = (vlSelfRef.ember_top__DOT__u_tu__DOT__acc
                   [vlSelfRef.ember_top__DOT__u_tu__DOT__mrow][12U] 
                   + vlSelfRef.ember_top__DOT__u_tu__DOT__tree[12U]);
            __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v12 
                = vlSelfRef.ember_top__DOT__u_tu__DOT__mrow;
            __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v13 
                = (vlSelfRef.ember_top__DOT__u_tu__DOT__acc
                   [vlSelfRef.ember_top__DOT__u_tu__DOT__mrow][13U] 
                   + vlSelfRef.ember_top__DOT__u_tu__DOT__tree[13U]);
            __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v13 
                = vlSelfRef.ember_top__DOT__u_tu__DOT__mrow;
            __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v14 
                = (vlSelfRef.ember_top__DOT__u_tu__DOT__acc
                   [vlSelfRef.ember_top__DOT__u_tu__DOT__mrow][14U] 
                   + vlSelfRef.ember_top__DOT__u_tu__DOT__tree[14U]);
            __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v14 
                = vlSelfRef.ember_top__DOT__u_tu__DOT__mrow;
            __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v15 
                = (vlSelfRef.ember_top__DOT__u_tu__DOT__acc
                   [vlSelfRef.ember_top__DOT__u_tu__DOT__mrow][15U] 
                   + vlSelfRef.ember_top__DOT__u_tu__DOT__tree[15U]);
            __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v15 
                = vlSelfRef.ember_top__DOT__u_tu__DOT__mrow;
        }
        if ((8U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__st))) {
            if ((4U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__st))) {
                vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__st = 0U;
            } else if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__st))) {
                if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__st))) {
                    vlSelfRef.ember_top__DOT__u_tu__DOT__running = 0U;
                    vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__st = 0U;
                } else if ((((IData)(0x00000010U) + vlSelfRef.ember_top__DOT__u_tu__DOT__m0) 
                            >= (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__dim_m))) {
                    if ((((IData)(0x00000010U) + vlSelfRef.ember_top__DOT__u_tu__DOT__n0) 
                         >= (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__dim_n))) {
                        vlSelfRef.ember_top__DOT__u_tu__DOT__running = 0U;
                        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__st = 0x0bU;
                    } else {
                        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__n0 
                            = ((IData)(0x00000010U) 
                               + vlSelfRef.ember_top__DOT__u_tu__DOT__n0);
                        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__m0 = 0U;
                        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__k0 = 0U;
                        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__wrow = 0U;
                        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__wgrp = 0U;
                        vlSelfRef.__VdlySet__ember_top__DOT__u_tu__DOT__acc__v16 = 1U;
                        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__st = 1U;
                        vlSelfRef.__VdlySet__ember_top__DOT__u_tu__DOT__acc__v17 = 1U;
                    }
                } else {
                    vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__m0 
                        = ((IData)(0x00000010U) + vlSelfRef.ember_top__DOT__u_tu__DOT__m0);
                    vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__k0 = 0U;
                    vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__wrow = 0U;
                    vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__wgrp = 0U;
                    vlSelfRef.__VdlySet__ember_top__DOT__u_tu__DOT__acc__v272 = 1U;
                    vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__st = 1U;
                    vlSelfRef.__VdlySet__ember_top__DOT__u_tu__DOT__acc__v273 = 1U;
                }
            } else if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__st))) {
                vlSelfRef.ember_top__DOT__tu_tua_we = 1U;
                vlSelfRef.ember_top__DOT__tu_tua_be = 0x0fU;
                vlSelfRef.ember_top__DOT__tu_tua_addr 
                    = ((IData)(0x00001000U) + (((vlSelfRef.ember_top__DOT__u_tu__DOT__c_base_q 
                                                 + 
                                                 ((IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__cw_row) 
                                                  * (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__dim_n))) 
                                                + vlSelfRef.ember_top__DOT__u_tu__DOT__n0) 
                                               + ((IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__cw_word) 
                                                  << 2U)));
                vlSelfRef.ember_top__DOT__tu_tua_wdata 
                    = ((((IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__cw_byte3) 
                         << 0x00000018U) | ((IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__cw_byte2) 
                                            << 0x00000010U)) 
                       | (((IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__cw_byte1) 
                           << 8U) | (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__cw_byte0)));
                if ((3U == (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__cw_word))) {
                    vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__cw_word = 0U;
                    if ((0x0fU == (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__cw_rblk))) {
                        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__st = 0x0aU;
                    } else {
                        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__cw_rblk 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__cw_rblk)));
                        vlSelfRef.ember_top__DOT__u_tu__DOT__cw_row 
                            = (0x00000fffU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__cw_row)));
                        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__st = 8U;
                    }
                } else {
                    vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__cw_word 
                        = (3U & ((IData)(1U) + (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__cw_word)));
                    vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__st = 8U;
                }
            } else {
                __Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__shift 
                    = vlSelfRef.ember_top__DOT__u_tu__DOT__req_shift;
                __Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__mult 
                    = vlSelfRef.ember_top__DOT__u_tu__DOT__req_mult;
                __Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__c32 
                    = vlSelfRef.ember_top__DOT__u_tu__DOT__acc
                    [vlSelfRef.ember_top__DOT__u_tu__DOT__cw_rblk]
                    [(0x0000000fU & VL_SHIFTL_III(4,32,32, (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__cw_word), 2U))];
                vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__st = 9U;
                __Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__half = 0;
                __Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__full 
                    = (0x0000ffffffffffffULL & VL_MULS_QQQ(48, 
                                                           (0x0000ffffffffffffULL 
                                                            & VL_EXTENDS_QI(48,32, __Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__c32)), (QData)((IData)(__Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__mult))));
                if ((0U == (IData)(__Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__shift))) {
                    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__res 
                        = __Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__full;
                } else {
                    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__half 
                        = (0x0000ffffffffffffULL & 
                           (1ULL << (0x0000000fU & 
                                     ((IData)(__Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__shift) 
                                      - (IData)(1U)))));
                    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__res 
                        = (0x0000ffffffffffffULL & 
                           VL_SHIFTRS_QQI(48,48,4, 
                                          (0x0000ffffffffffffULL 
                                           & (__Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__full 
                                              + __Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__half)), (IData)(__Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__shift)));
                }
                __Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__Vfuncout 
                    = (0x000000ffU & (IData)(__Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__res));
                vlSelfRef.ember_top__DOT__u_tu__DOT__cw_byte0 
                    = __Vfunc_ember_top__DOT__u_tu__DOT__requant8__2__Vfuncout;
                __Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__shift 
                    = vlSelfRef.ember_top__DOT__u_tu__DOT__req_shift;
                __Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__mult 
                    = vlSelfRef.ember_top__DOT__u_tu__DOT__req_mult;
                __Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__c32 
                    = vlSelfRef.ember_top__DOT__u_tu__DOT__acc
                    [vlSelfRef.ember_top__DOT__u_tu__DOT__cw_rblk]
                    [(0x0000000fU & ((IData)(1U) + 
                                     VL_SHIFTL_III(4,32,32, (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__cw_word), 2U)))];
                __Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__half = 0;
                __Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__full 
                    = (0x0000ffffffffffffULL & VL_MULS_QQQ(48, 
                                                           (0x0000ffffffffffffULL 
                                                            & VL_EXTENDS_QI(48,32, __Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__c32)), (QData)((IData)(__Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__mult))));
                if ((0U == (IData)(__Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__shift))) {
                    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__res 
                        = __Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__full;
                } else {
                    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__half 
                        = (0x0000ffffffffffffULL & 
                           (1ULL << (0x0000000fU & 
                                     ((IData)(__Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__shift) 
                                      - (IData)(1U)))));
                    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__res 
                        = (0x0000ffffffffffffULL & 
                           VL_SHIFTRS_QQI(48,48,4, 
                                          (0x0000ffffffffffffULL 
                                           & (__Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__full 
                                              + __Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__half)), (IData)(__Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__shift)));
                }
                __Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__Vfuncout 
                    = (0x000000ffU & (IData)(__Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__res));
                vlSelfRef.ember_top__DOT__u_tu__DOT__cw_byte1 
                    = __Vfunc_ember_top__DOT__u_tu__DOT__requant8__3__Vfuncout;
                __Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__shift 
                    = vlSelfRef.ember_top__DOT__u_tu__DOT__req_shift;
                __Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__mult 
                    = vlSelfRef.ember_top__DOT__u_tu__DOT__req_mult;
                __Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__c32 
                    = vlSelfRef.ember_top__DOT__u_tu__DOT__acc
                    [vlSelfRef.ember_top__DOT__u_tu__DOT__cw_rblk]
                    [(0x0000000fU & ((IData)(2U) + 
                                     VL_SHIFTL_III(4,32,32, (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__cw_word), 2U)))];
                __Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__half = 0;
                __Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__full 
                    = (0x0000ffffffffffffULL & VL_MULS_QQQ(48, 
                                                           (0x0000ffffffffffffULL 
                                                            & VL_EXTENDS_QI(48,32, __Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__c32)), (QData)((IData)(__Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__mult))));
                if ((0U == (IData)(__Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__shift))) {
                    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__res 
                        = __Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__full;
                } else {
                    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__half 
                        = (0x0000ffffffffffffULL & 
                           (1ULL << (0x0000000fU & 
                                     ((IData)(__Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__shift) 
                                      - (IData)(1U)))));
                    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__res 
                        = (0x0000ffffffffffffULL & 
                           VL_SHIFTRS_QQI(48,48,4, 
                                          (0x0000ffffffffffffULL 
                                           & (__Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__full 
                                              + __Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__half)), (IData)(__Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__shift)));
                }
                __Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__Vfuncout 
                    = (0x000000ffU & (IData)(__Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__res));
                vlSelfRef.ember_top__DOT__u_tu__DOT__cw_byte2 
                    = __Vfunc_ember_top__DOT__u_tu__DOT__requant8__4__Vfuncout;
                __Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__shift 
                    = vlSelfRef.ember_top__DOT__u_tu__DOT__req_shift;
                __Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__mult 
                    = vlSelfRef.ember_top__DOT__u_tu__DOT__req_mult;
                __Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__c32 
                    = vlSelfRef.ember_top__DOT__u_tu__DOT__acc
                    [vlSelfRef.ember_top__DOT__u_tu__DOT__cw_rblk]
                    [(0x0000000fU & ((IData)(3U) + 
                                     VL_SHIFTL_III(4,32,32, (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__cw_word), 2U)))];
                __Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__half = 0;
                __Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__full 
                    = (0x0000ffffffffffffULL & VL_MULS_QQQ(48, 
                                                           (0x0000ffffffffffffULL 
                                                            & VL_EXTENDS_QI(48,32, __Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__c32)), (QData)((IData)(__Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__mult))));
                if ((0U == (IData)(__Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__shift))) {
                    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__res 
                        = __Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__full;
                } else {
                    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__half 
                        = (0x0000ffffffffffffULL & 
                           (1ULL << (0x0000000fU & 
                                     ((IData)(__Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__shift) 
                                      - (IData)(1U)))));
                    __Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__res 
                        = (0x0000ffffffffffffULL & 
                           VL_SHIFTRS_QQI(48,48,4, 
                                          (0x0000ffffffffffffULL 
                                           & (__Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__full 
                                              + __Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__half)), (IData)(__Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__shift)));
                }
                __Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__Vfuncout 
                    = (0x000000ffU & (IData)(__Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__res));
                vlSelfRef.ember_top__DOT__u_tu__DOT__cw_byte3 
                    = __Vfunc_ember_top__DOT__u_tu__DOT__requant8__5__Vfuncout;
            }
        } else if ((4U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__st))) {
            if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__st))) {
                if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__st))) {
                    if ((((IData)(0x00000010U) + vlSelfRef.ember_top__DOT__u_tu__DOT__k0) 
                         >= (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__dim_k))) {
                        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__cw_rblk = 0U;
                        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__cw_word = 0U;
                        vlSelfRef.ember_top__DOT__u_tu__DOT__cw_row 
                            = (0x00000fffU & vlSelfRef.ember_top__DOT__u_tu__DOT__m0);
                        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__st = 8U;
                    } else {
                        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__k0 
                            = ((IData)(0x00000010U) 
                               + vlSelfRef.ember_top__DOT__u_tu__DOT__k0);
                        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__wrow = 0U;
                        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__wgrp = 0U;
                        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__st = 1U;
                    }
                } else if ((1U & (~ (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__mac_pend)))) {
                    if ((0x0fU == (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__mrow))) {
                        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__st = 7U;
                    } else {
                        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__mrow 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__mrow)));
                        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__fcnt = 0U;
                        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__st = 4U;
                    }
                }
            } else if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__st))) {
                if ((1U & ((~ (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__rq_pend)) 
                           & (~ (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__rq_req_cyc))))) {
                    vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__mac_pend = 1U;
                    vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__st = 6U;
                }
            } else if ((1U & (~ (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__rq_pend)))) {
                vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__rq_pend = 1U;
                vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__rq_req_cyc = 1U;
                vlSelfRef.ember_top__DOT__u_tu__DOT__rq_dst_w = 1U;
                vlSelfRef.ember_top__DOT__u_tu__DOT__rq_aw 
                    = (3U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__fcnt));
                vlSelfRef.ember_top__DOT__tu_tua_req = 1U;
                vlSelfRef.ember_top__DOT__tu_tua_addr 
                    = ((IData)(0x00001000U) + (((vlSelfRef.ember_top__DOT__u_tu__DOT__a_base_q 
                                                 + 
                                                 ((vlSelfRef.ember_top__DOT__u_tu__DOT__m0 
                                                   + (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__mrow)) 
                                                  * (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__dim_k))) 
                                                + vlSelfRef.ember_top__DOT__u_tu__DOT__k0) 
                                               + (0x0000000cU 
                                                  & ((IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__fcnt) 
                                                     << 2U))));
                if ((3U == (3U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__fcnt)))) {
                    vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__st = 5U;
                }
                vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__fcnt 
                    = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__fcnt)));
            }
        } else if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__st))) {
            if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__st))) {
                vlSelfRef.ember_top__DOT__u_tu__DOT__w_ld 
                    = ((IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__w_ld) 
                       | (0x0000ffffU & ((IData)(1U) 
                                         << (0x0000000fU 
                                             & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__wrow)))));
                if ((0x0fU == (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__wrow))) {
                    vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__mrow = 0U;
                    vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__wrow = 0U;
                    vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__fcnt = 0U;
                    vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__st = 4U;
                } else {
                    vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__wrow 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__wrow)));
                    vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__wgrp = 0U;
                    vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__st = 1U;
                }
            } else if ((1U & ((~ (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__rq_pend)) 
                              & (~ (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__rq_req_cyc))))) {
                if ((3U == (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__wgrp))) {
                    vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__st = 3U;
                } else {
                    vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__wgrp 
                        = (3U & ((IData)(1U) + (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__wgrp)));
                    vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__st = 1U;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__st))) {
            if ((1U & (~ (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__rq_pend)))) {
                vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__rq_pend = 1U;
                vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__rq_req_cyc = 1U;
                vlSelfRef.ember_top__DOT__u_tu__DOT__rq_dst_w = 0U;
                vlSelfRef.ember_top__DOT__u_tu__DOT__rq_aw 
                    = vlSelfRef.ember_top__DOT__u_tu__DOT__wgrp;
                vlSelfRef.ember_top__DOT__tu_tua_req = 1U;
                vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__st = 2U;
                vlSelfRef.ember_top__DOT__tu_tua_addr 
                    = ((IData)(0x00001000U) + (((vlSelfRef.ember_top__DOT__u_tu__DOT__w_base_q 
                                                 + 
                                                 ((vlSelfRef.ember_top__DOT__u_tu__DOT__k0 
                                                   + (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__wrow)) 
                                                  * (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__dim_n))) 
                                                + vlSelfRef.ember_top__DOT__u_tu__DOT__n0) 
                                               + ((IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__wgrp) 
                                                  << 2U)));
            }
        } else {
            vlSelfRef.ember_top__DOT__u_tu__DOT__running = 0U;
            if (((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_0) 
                 & ((0x0068U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
                    & vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata))) {
                vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__n0 = 0U;
                vlSelfRef.ember_top__DOT__u_tu__DOT__running = 1U;
                vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__m0 = 0U;
                vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__k0 = 0U;
                vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__wrow = 0U;
                vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__wgrp = 0U;
                vlSelfRef.__VdlySet__ember_top__DOT__u_tu__DOT__acc__v528 = 1U;
                vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__st = 1U;
                vlSelfRef.__VdlySet__ember_top__DOT__u_tu__DOT__acc__v529 = 1U;
            }
        }
        if (vlSelfRef.ember_top__DOT__u_disp__DOT__de_now) {
            vlSelfRef.ember_top__DOT__u_disp__DOT__addr_q 
                = ((IData)(0x00001000U) + (((IData)(0x00000280U) 
                                            * (0x000003ffU 
                                               & ((IData)(vlSelfRef.ember_top__DOT__u_disp__DOT__vcnt) 
                                                  >> 1U))) 
                                           + VL_SHIFTL_III(32,32,32, 
                                                           (0x000003feU 
                                                            & ((IData)(vlSelfRef.ember_top__DOT__u_disp__DOT__hcnt) 
                                                               >> 1U)), 1U)));
        }
        vlSelfRef.ember_top__DOT__u_cp__DOT__up_pop = 0U;
        if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__dstate))) {
            if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__dstate))) {
                if (vlSelfRef.ember_top__DOT__d_rvalid) {
                    vlSelfRef.__Vdly__ember_top__DOT__u_cp__DOT__dma_addr_q 
                        = ((IData)(4U) + vlSelfRef.ember_top__DOT__u_cp__DOT__dma_addr_q);
                    vlSelfRef.__Vdly__ember_top__DOT__u_cp__DOT__r_pend_q = 0U;
                    if ((4U >= vlSelfRef.ember_top__DOT__u_cp__DOT__dma_left_q)) {
                        vlSelfRef.__Vdly__ember_top__DOT__u_cp__DOT__dstate = 0U;
                        vlSelfRef.ember_top__DOT__u_cp__DOT__dma_busy_q = 0U;
                        vlSelfRef.ember_top__DOT__u_cp__DOT__fence_done_q 
                            = vlSelfRef.ember_top__DOT__u_cp__DOT__fence_pend_q;
                    } else {
                        vlSelfRef.__Vdly__ember_top__DOT__u_cp__DOT__dma_left_q 
                            = (vlSelfRef.ember_top__DOT__u_cp__DOT__dma_left_q 
                               - (IData)(4U));
                    }
                }
                if (((((~ (IData)(vlSelfRef.ember_top__DOT__d_arvalid)) 
                       & (~ (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__r_pend_q))) 
                      & (~ (IData)(vlSelfRef.ember_top__DOT__d_rvalid))) 
                     & (0U < vlSelfRef.ember_top__DOT__u_cp__DOT__dma_left_q))) {
                    vlSelfRef.__Vdly__ember_top__DOT__d_arvalid = 1U;
                    vlSelfRef.ember_top__DOT__d_ar 
                        = ((QData)((IData)(((IData)(0x00001000U) 
                                            + vlSelfRef.ember_top__DOT__u_cp__DOT__dma_addr_q))) 
                           << 3U);
                }
                if (((IData)(vlSelfRef.ember_top__DOT__d_arvalid) 
                     & ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__r_fwd_d) 
                        & (IData)(vlSelfRef.ember_top__DOT__v_arready)))) {
                    vlSelfRef.__Vdly__ember_top__DOT__d_arvalid = 0U;
                    vlSelfRef.__Vdly__ember_top__DOT__u_cp__DOT__r_pend_q = 1U;
                }
            } else if ((1U & (~ (IData)(vlSelfRef.ember_top__DOT__d_awvalid)))) {
                vlSelfRef.__Vdly__ember_top__DOT__u_cp__DOT__dstate = 0U;
                vlSelfRef.ember_top__DOT__u_cp__DOT__dma_busy_q = 0U;
                vlSelfRef.ember_top__DOT__u_cp__DOT__fence_done_q 
                    = vlSelfRef.ember_top__DOT__u_cp__DOT__fence_pend_q;
            }
        } else if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__dstate))) {
            if (((((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__up_rp) 
                   != (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__up_wp)) 
                  & (~ (IData)(vlSelfRef.ember_top__DOT__d_awvalid))) 
                 & (~ (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__w_busy_q)))) {
                vlSelfRef.__Vdly__ember_top__DOT__d_awvalid = 1U;
                vlSelfRef.__Vdly__ember_top__DOT__d_wvalid = 1U;
                vlSelfRef.ember_top__DOT__u_cp__DOT__w_busy_q = 1U;
                vlSelfRef.ember_top__DOT__d_aw = ((QData)((IData)(
                                                                  ((IData)(0x00001000U) 
                                                                   + vlSelfRef.ember_top__DOT__u_cp__DOT__dma_addr_q))) 
                                                  << 3U);
                vlSelfRef.ember_top__DOT__d_w = (0x000000000000000fULL 
                                                 | ((QData)((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__up_mem
                                                                    [
                                                                    (0x0000003fU 
                                                                     & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__up_rp))])) 
                                                    << 4U));
                vlSelfRef.ember_top__DOT__u_cp__DOT__up_pop = 1U;
            }
            if (((IData)(vlSelfRef.ember_top__DOT__d_awvalid) 
                 & ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_d) 
                    & (IData)(vlSelfRef.ember_top__DOT__v_awready)))) {
                vlSelfRef.__Vdly__ember_top__DOT__d_awvalid = 0U;
            }
            if (((IData)(vlSelfRef.ember_top__DOT__d_wvalid) 
                 & ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_d) 
                    & (IData)(vlSelfRef.ember_top__DOT__v_wready)))) {
                vlSelfRef.__Vdly__ember_top__DOT__u_cp__DOT__dma_addr_q 
                    = ((IData)(4U) + vlSelfRef.ember_top__DOT__u_cp__DOT__dma_addr_q);
                vlSelfRef.__Vdly__ember_top__DOT__d_wvalid = 0U;
                vlSelfRef.ember_top__DOT__u_cp__DOT__w_busy_q = 0U;
                if ((4U >= vlSelfRef.ember_top__DOT__u_cp__DOT__dma_left_q)) {
                    vlSelfRef.__Vdly__ember_top__DOT__u_cp__DOT__dstate 
                        = ((IData)(vlSelfRef.ember_top__DOT__d_awvalid)
                            ? 2U : 0U);
                    if ((1U & (~ (IData)(vlSelfRef.ember_top__DOT__d_awvalid)))) {
                        vlSelfRef.ember_top__DOT__u_cp__DOT__dma_busy_q = 0U;
                        vlSelfRef.ember_top__DOT__u_cp__DOT__fence_done_q 
                            = vlSelfRef.ember_top__DOT__u_cp__DOT__fence_pend_q;
                    }
                } else {
                    vlSelfRef.__Vdly__ember_top__DOT__u_cp__DOT__dma_left_q 
                        = (vlSelfRef.ember_top__DOT__u_cp__DOT__dma_left_q 
                           - (IData)(4U));
                }
            }
        } else if ((((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wr_en) 
                     & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_be)) 
                    & (0x001cU == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)))) {
            vlSelfRef.__Vdly__ember_top__DOT__u_cp__DOT__dma_addr_q 
                = vlSelfRef.ember_top__DOT__u_cp__DOT__dma_dst_q;
            vlSelfRef.__Vdly__ember_top__DOT__u_cp__DOT__dma_left_q 
                = vlSelfRef.ember_top__DOT__u_cp__DOT__dma_len_q;
            vlSelfRef.ember_top__DOT__u_cp__DOT__dma_busy_q = 1U;
            if ((0U == vlSelfRef.ember_top__DOT__u_cp__DOT__dma_len_q)) {
                vlSelfRef.ember_top__DOT__u_cp__DOT__dma_busy_q = 0U;
                vlSelfRef.ember_top__DOT__u_cp__DOT__fence_done_q 
                    = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata 
                                      >> 8U));
            } else {
                vlSelfRef.__Vdly__ember_top__DOT__u_cp__DOT__dstate 
                    = ((1U & vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata)
                        ? 3U : 1U);
            }
        }
        if ((((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wr_en) 
              & (8U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr))) 
             & vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata)) {
            vlSelfRef.__Vdly__ember_top__DOT__u_cp__DOT__r_pend_q = 0U;
            vlSelfRef.__Vdly__ember_top__DOT__d_wvalid = 0U;
            vlSelfRef.__Vdly__ember_top__DOT__u_cp__DOT__dstate = 0U;
            vlSelfRef.ember_top__DOT__u_cp__DOT__dma_busy_q = 0U;
            vlSelfRef.ember_top__DOT__u_cp__DOT__fence_done_q = 0U;
            vlSelfRef.ember_top__DOT__u_cp__DOT__w_busy_q = 0U;
            vlSelfRef.__Vdly__ember_top__DOT__d_awvalid = 0U;
            vlSelfRef.__Vdly__ember_top__DOT__d_arvalid = 0U;
        }
        if (vlSelfRef.ember_top__DOT__u_gsx__DOT__cfg_mode_we) {
            vlSelfRef.ember_top__DOT__u_gsx__DOT__cfg_tex 
                = (1U & (vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata 
                         >> 0x1bU));
            vlSelfRef.ember_top__DOT__u_gsx__DOT__cfg_page 
                = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata 
                                  >> 0x10U));
            vlSelfRef.ember_top__DOT__u_gsx__DOT__cfg_ztest 
                = (1U & (vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata 
                         >> 0x18U));
            vlSelfRef.ember_top__DOT__u_gsx__DOT__cfg_blend 
                = (1U & (vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata 
                         >> 0x1aU));
            vlSelfRef.ember_top__DOT__u_gsx__DOT__cfg_overw 
                = (1U & (vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata 
                         >> 0x1dU));
        }
        if ((((IData)(vlSelfRef.ember_top__DOT__core_csr_we) 
              & (0x0050U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr))) 
             & (0U != (0x000000ffU & vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata)))) {
            vlSelfRef.ember_top__DOT__u_core__DOT__nblk_q 
                = (0x000000ffU & vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata);
        }
        if (((0x0050U != (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
             & (IData)(vlSelfRef.ember_top__DOT__core_csr_we))) {
            vlSelfRef.ember_top__DOT__u_core__DOT__code_base_q 
                = (0xfffffffcU & vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata);
        }
        if (vlSelfRef.ember_top__DOT__u_tu__DOT__cfg2_dim_we) {
            vlSelfRef.ember_top__DOT__u_tu__DOT__dim_n 
                = (0x00000fffU & vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata);
            vlSelfRef.ember_top__DOT__u_tu__DOT__dim_k 
                = (0x00000fffU & (vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata 
                                  >> 0x10U));
        }
        if (vlSelfRef.ember_top__DOT__u_tu__DOT__cfg2_q_we) {
            vlSelfRef.ember_top__DOT__u_tu__DOT__req_shift 
                = (0x0000000fU & (vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata 
                                  >> 0x14U));
            vlSelfRef.ember_top__DOT__u_tu__DOT__req_mult 
                = (0x0000ffffU & vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata);
        }
        if (((IData)(vlSelfRef.ember_top__DOT__u_tu__DOT____VdfgRegularize_h0ebfa33a_0_0) 
             & (1U == (vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata 
                       >> 0x0000001eU)))) {
            vlSelfRef.ember_top__DOT__u_tu__DOT__dim_m 
                = (0x00000fffU & vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata);
        }
        if (vlSelfRef.ember_top__DOT__tu_csr_we) {
            if ((0U != (IData)(vlSelfRef.ember_top__DOT__tu_csr_addr))) {
                if ((1U != (IData)(vlSelfRef.ember_top__DOT__tu_csr_addr))) {
                    if ((2U == (IData)(vlSelfRef.ember_top__DOT__tu_csr_addr))) {
                        vlSelfRef.ember_top__DOT__u_tu__DOT__c_base_q 
                            = (0xfffffffcU & vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata);
                    }
                }
                if ((1U == (IData)(vlSelfRef.ember_top__DOT__tu_csr_addr))) {
                    vlSelfRef.ember_top__DOT__u_tu__DOT__w_base_q 
                        = (0xfffffffcU & vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata);
                }
            }
            if ((0U == (IData)(vlSelfRef.ember_top__DOT__tu_csr_addr))) {
                vlSelfRef.ember_top__DOT__u_tu__DOT__a_base_q 
                    = (0xfffffffcU & vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata);
            }
        }
        if (vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wr_en) {
            if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_be))) {
                if ((0x0014U != (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr))) {
                    if ((0x0018U != (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr))) {
                        if ((0x001cU == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr))) {
                            vlSelfRef.ember_top__DOT__u_cp__DOT__fence_pend_q 
                                = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata 
                                                  >> 8U));
                        }
                    }
                    if ((0x0018U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr))) {
                        vlSelfRef.ember_top__DOT__u_cp__DOT__dma_len_q 
                            = vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata;
                    }
                }
                if ((0x0014U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr))) {
                    vlSelfRef.ember_top__DOT__u_cp__DOT__dma_dst_q 
                        = vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata;
                }
            }
        }
    } else {
        vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__vidx = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__eidx = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__st = 0U;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__busy_r = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__kstep = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__phase = 0U;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__w_in = 0x3f800000U;
        vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__acc0 = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__acc1 = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__acc2 = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__acc3 = 0U;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__emit_base = 0U;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__f_lane_en = 0U;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__f_go = 0U;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__f_op = 0U;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__f_a0 = 0U;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__f_b0 = 0U;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__f_a1 = 0U;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__f_b1 = 0U;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__f_a2 = 0U;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__f_b2 = 0U;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__f_a3 = 0U;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__f_b3 = 0U;
        vlSelfRef.ember_top__DOT__gsx_gxa_we = 0U;
        vlSelfRef.ember_top__DOT__gsx_gxa_addr = 0U;
        vlSelfRef.ember_top__DOT__gsx_gxa_wdata = 0U;
        vlSelfRef.ember_top__DOT__gsx_gxa_be = 0U;
        vlSelfRef.__VdlySet__ember_top__DOT__u_gsx__DOT__px__v1 = 1U;
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__flush_req = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__waitv = 0U;
        vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__gpr__v44 = 1U;
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__st = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__running = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__blk = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_v = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__ix_pend = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__ix_req_cyc = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__ix_tid = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__flush_tid = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__ld_pend = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__ld_addr_q = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__ld_tid_q = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__ld_rd_q = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__cx_pend = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__cx_req_cyc = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__dr_valid = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__dr_tid = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__dr_rd = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__dr_word = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__fp_pend = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__fp_tid = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__fp_rd = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__bar_count = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__budget = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__f_lane_en = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__f_go = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__f_op = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__f_a0 = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__f_b0 = 0U;
        vlSelfRef.ember_top__DOT__core_cxa_we = 0U;
        vlSelfRef.ember_top__DOT__core_cxa_addr = 0U;
        vlSelfRef.ember_top__DOT__core_cxa_wdata = 0U;
        vlSelfRef.ember_top__DOT__core_cxa_be = 0U;
        vlSelfRef.ember_top__DOT__core_cxa_req = 0U;
        vlSelfRef.ember_top__DOT__core_ixa_req = 0U;
        vlSelfRef.ember_top__DOT__core_ixa_addr = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__barv = 0U;
        vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__T__v22 = 1U;
        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__n0 = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__mrow = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__cw_row = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__cw_rblk = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__cw_word = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__st = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__running = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__k0 = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__m0 = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__wrow = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__wgrp = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__fcnt = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__mac_pend = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__rq_pend = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__rq_req_cyc = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__rq_dst_w = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__rq_aw = 0U;
        vlSelfRef.ember_top__DOT__tu_tua_we = 0U;
        vlSelfRef.ember_top__DOT__tu_tua_addr = 0U;
        vlSelfRef.ember_top__DOT__tu_tua_wdata = 0U;
        vlSelfRef.ember_top__DOT__tu_tua_be = 0U;
        vlSelfRef.ember_top__DOT__tu_tua_req = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_ld = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__cw_byte0 = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__cw_byte1 = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__cw_byte2 = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__cw_byte3 = 0U;
        vlSelfRef.__VdlySet__ember_top__DOT__u_tu__DOT__acc__v784 = 1U;
        vlSelfRef.ember_top__DOT__u_disp__DOT__addr_q = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_cp__DOT__dma_addr_q = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_cp__DOT__dma_left_q = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_cp__DOT__r_pend_q = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__d_wvalid = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_cp__DOT__dstate = 0U;
        vlSelfRef.ember_top__DOT__u_cp__DOT__dma_busy_q = 0U;
        vlSelfRef.ember_top__DOT__u_cp__DOT__fence_done_q = 0U;
        vlSelfRef.ember_top__DOT__u_cp__DOT__w_busy_q = 0U;
        vlSelfRef.ember_top__DOT__u_cp__DOT__up_pop = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__d_awvalid = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__d_arvalid = 0U;
        vlSelfRef.ember_top__DOT__d_aw = 0ULL;
        vlSelfRef.ember_top__DOT__d_w = 0ULL;
        vlSelfRef.ember_top__DOT__d_ar = 0ULL;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__cfg_tex = 0U;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__cfg_page = 0U;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__cfg_ztest = 0U;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__cfg_blend = 0U;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__cfg_overw = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__nblk_q = 1U;
        vlSelfRef.ember_top__DOT__u_core__DOT__code_base_q = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__dim_n = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__req_shift = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__req_mult = 1U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__dim_k = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__dim_m = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__c_base_q = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__a_base_q = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_base_q = 0U;
        vlSelfRef.ember_top__DOT__u_cp__DOT__fence_pend_q = 0U;
        vlSelfRef.ember_top__DOT__u_cp__DOT__dma_dst_q = 0U;
        vlSelfRef.ember_top__DOT__u_cp__DOT__dma_len_q = 0U;
    }
    vlSelfRef.ember_top__DOT__u_disp__DOT__req_q = 
        ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.ember_top__DOT__u_disp__DOT__de_now));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_start 
        = vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__scan_start;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy 
        = vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx 
        = vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__ix 
        = vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__ix;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__st 
        = vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st;
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_rtr__DOT__cmd_q__v0) {
        vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[vlSelfRef.__VdlyDim0__ember_top__DOT__u_rtr__DOT__cmd_q__v0] 
            = vlSelfRef.__VdlyVal__ember_top__DOT__u_rtr__DOT__cmd_q__v0;
    }
    vlSelfRef.ember_top__DOT__u_gsx__DOT__st = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__st;
    vlSelfRef.ember_top__DOT__u_gsx__DOT__eidx = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__eidx;
    vlSelfRef.ember_top__DOT__u_gsx__DOT__vidx = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__vidx;
    vlSelfRef.ember_top__DOT__u_gsx__DOT__kstep = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__kstep;
    vlSelfRef.ember_top__DOT__u_gsx__DOT__phase = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__phase;
    vlSelfRef.ember_top__DOT__u_gsx__DOT__acc0 = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__acc0;
    vlSelfRef.ember_top__DOT__u_gsx__DOT__acc1 = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__acc1;
    vlSelfRef.ember_top__DOT__u_gsx__DOT__acc2 = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__acc2;
    vlSelfRef.ember_top__DOT__u_gsx__DOT__acc3 = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__acc3;
    vlSelfRef.ember_top__DOT__u_gsx__DOT__tri_count 
        = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__tri_count;
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_gsx__DOT__pu__v0) {
        vlSelfRef.ember_top__DOT__u_gsx__DOT__pu[__VdlyDim0__ember_top__DOT__u_gsx__DOT__pu__v0] 
            = __VdlyVal__ember_top__DOT__u_gsx__DOT__pu__v0;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_gsx__DOT__pv__v0) {
        vlSelfRef.ember_top__DOT__u_gsx__DOT__pv[__VdlyDim0__ember_top__DOT__u_gsx__DOT__pv__v0] 
            = __VdlyVal__ember_top__DOT__u_gsx__DOT__pv__v0;
    }
    vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s0[0U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s0[0U];
    vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s0[1U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s0[1U];
    vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s0[2U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s0[2U];
    vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s0[3U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s0[3U];
    vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s1[0U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s1[0U];
    vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s1[1U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s1[1U];
    vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s1[2U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s1[2U];
    vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s1[3U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s1[3U];
    vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s2[0U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s2[0U];
    vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s2[1U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s2[1U];
    vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s2[2U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s2[2U];
    vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s2[3U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s2[3U];
    vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s3[0U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s3[0U];
    vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s3[1U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s3[1U];
    vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s3[2U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s3[2U];
    vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s3[3U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s3[3U];
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_gsx__DOT__px__v0) {
        vlSelfRef.ember_top__DOT__u_gsx__DOT__px[__VdlyDim0__ember_top__DOT__u_gsx__DOT__px__v0] 
            = __VdlyVal__ember_top__DOT__u_gsx__DOT__px__v0;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_gsx__DOT__py__v0) {
        vlSelfRef.ember_top__DOT__u_gsx__DOT__py[__VdlyDim0__ember_top__DOT__u_gsx__DOT__py__v0] 
            = __VdlyVal__ember_top__DOT__u_gsx__DOT__py__v0;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_gsx__DOT__pz__v0) {
        vlSelfRef.ember_top__DOT__u_gsx__DOT__pz[__VdlyDim0__ember_top__DOT__u_gsx__DOT__pz__v0] 
            = __VdlyVal__ember_top__DOT__u_gsx__DOT__pz__v0;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_gsx__DOT__pc__v0) {
        vlSelfRef.ember_top__DOT__u_gsx__DOT__pc[__VdlyDim0__ember_top__DOT__u_gsx__DOT__pc__v0] 
            = __VdlyVal__ember_top__DOT__u_gsx__DOT__pc__v0;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_gsx__DOT__px__v1) {
        vlSelfRef.ember_top__DOT__u_gsx__DOT__px[0U] = 0U;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__px[1U] = 0U;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__px[2U] = 0U;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__py[0U] = 0U;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__py[1U] = 0U;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__py[2U] = 0U;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__pz[0U] = 0U;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__pz[1U] = 0U;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__pz[2U] = 0U;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__pc[0U] = 0U;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__pc[1U] = 0U;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__pc[2U] = 0U;
    }
    vlSelfRef.ember_top__DOT__u_core__DOT__ix_pend 
        = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__ix_pend;
    vlSelfRef.ember_top__DOT__u_core__DOT__flush_req 
        = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__flush_req;
    vlSelfRef.ember_top__DOT__u_core__DOT__cx_pend 
        = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__cx_pend;
    vlSelfRef.ember_top__DOT__u_core__DOT__dr_valid 
        = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__dr_valid;
    vlSelfRef.ember_top__DOT__u_core__DOT__dr_tid = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__dr_tid;
    vlSelfRef.ember_top__DOT__u_core__DOT__dr_rd = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__dr_rd;
    vlSelfRef.ember_top__DOT__u_core__DOT__dr_word 
        = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__dr_word;
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[0U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[0U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[1U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[1U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[2U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[2U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s0[3U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[0U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[0U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[1U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[1U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[2U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[2U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[3U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s1[3U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[0U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[0U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[1U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[1U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[2U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[2U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s2[3U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[0U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[0U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[1U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[1U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[2U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[2U];
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U] 
        = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__u_fpu__DOT__s3[3U];
    vlSelfRef.ember_top__DOT__u_core__DOT__fp_pend 
        = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__fp_pend;
    vlSelfRef.ember_top__DOT__u_core__DOT__blk = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__blk;
    vlSelfRef.ember_top__DOT__u_core__DOT__bar_count 
        = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__bar_count;
    vlSelfRef.ember_top__DOT__u_core__DOT__budget = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__budget;
    vlSelfRef.ember_top__DOT__u_core__DOT__flush_tid 
        = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__flush_tid;
    vlSelfRef.ember_top__DOT__u_core__DOT__ld_pend 
        = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__ld_pend;
    vlSelfRef.ember_top__DOT__u_core__DOT__ld_addr_q 
        = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__ld_addr_q;
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__smem__v0) {
        vlSelfRef.ember_top__DOT__u_core__DOT__smem[__VdlyDim0__ember_top__DOT__u_core__DOT__smem__v0] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__smem__v0;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__smem__v1) {
        vlSelfRef.ember_top__DOT__u_core__DOT__smem[__VdlyDim0__ember_top__DOT__u_core__DOT__smem__v1] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__smem__v1;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__smem__v2) {
        vlSelfRef.ember_top__DOT__u_core__DOT__smem[__VdlyDim0__ember_top__DOT__u_core__DOT__smem__v2] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__smem__v2;
    }
    vlSelfRef.ember_top__DOT__u_core__DOT__waitv = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__waitv;
    vlSelfRef.ember_top__DOT__u_core__DOT__barv = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__barv;
    vlSelfRef.ember_top__DOT__u_core__DOT__st = vlSelfRef.__Vdly__ember_top__DOT__u_core__DOT__st;
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__T__v0) {
        vlSelfRef.ember_top__DOT__u_core__DOT__T[0U] 
            = (7U & vlSelfRef.ember_top__DOT__u_core__DOT__T[0U]);
        vlSelfRef.ember_top__DOT__u_core__DOT__fpc[0U] = 0U;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__T__v1) {
        vlSelfRef.ember_top__DOT__u_core__DOT__T[0U] 
            = (8U & vlSelfRef.ember_top__DOT__u_core__DOT__T[0U]);
        vlSelfRef.ember_top__DOT__u_core__DOT__T[1U] 
            = (7U & vlSelfRef.ember_top__DOT__u_core__DOT__T[1U]);
        vlSelfRef.ember_top__DOT__u_core__DOT__T[1U] 
            = (8U & vlSelfRef.ember_top__DOT__u_core__DOT__T[1U]);
        vlSelfRef.ember_top__DOT__u_core__DOT__T[2U] 
            = (7U & vlSelfRef.ember_top__DOT__u_core__DOT__T[2U]);
        vlSelfRef.ember_top__DOT__u_core__DOT__T[2U] 
            = (8U & vlSelfRef.ember_top__DOT__u_core__DOT__T[2U]);
        vlSelfRef.ember_top__DOT__u_core__DOT__T[3U] 
            = (7U & vlSelfRef.ember_top__DOT__u_core__DOT__T[3U]);
        vlSelfRef.ember_top__DOT__u_core__DOT__T[3U] 
            = (8U & vlSelfRef.ember_top__DOT__u_core__DOT__T[3U]);
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__T__v8) {
        vlSelfRef.ember_top__DOT__u_core__DOT__T[0U] 
            = (8U | vlSelfRef.ember_top__DOT__u_core__DOT__T[0U]);
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__T__v9) {
        vlSelfRef.ember_top__DOT__u_core__DOT__T[1U] 
            = (8U | vlSelfRef.ember_top__DOT__u_core__DOT__T[1U]);
        vlSelfRef.ember_top__DOT__u_core__DOT__T[2U] 
            = (8U | vlSelfRef.ember_top__DOT__u_core__DOT__T[2U]);
        vlSelfRef.ember_top__DOT__u_core__DOT__T[3U] 
            = (8U | vlSelfRef.ember_top__DOT__u_core__DOT__T[3U]);
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__T__v12) {
        vlSelfRef.ember_top__DOT__u_core__DOT__T[__VdlyDim0__ember_top__DOT__u_core__DOT__T__v12] 
            = (8U | vlSelfRef.ember_top__DOT__u_core__DOT__T
               [__VdlyDim0__ember_top__DOT__u_core__DOT__T__v12]);
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__T__v13) {
        vlSelfRef.ember_top__DOT__u_core__DOT__T[__VdlyDim0__ember_top__DOT__u_core__DOT__T__v13] 
            = ((8U & vlSelfRef.ember_top__DOT__u_core__DOT__T
                [__VdlyDim0__ember_top__DOT__u_core__DOT__T__v13]) 
               | (IData)(__VdlyVal__ember_top__DOT__u_core__DOT__T__v13));
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__T__v14) {
        vlSelfRef.ember_top__DOT__u_core__DOT__T[0U] 
            = (7U & vlSelfRef.ember_top__DOT__u_core__DOT__T[0U]);
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__T__v1) {
        vlSelfRef.ember_top__DOT__u_core__DOT__fpc[1U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__fpc[2U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__fpc[3U] = 0U;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__fpc__v4) {
        vlSelfRef.ember_top__DOT__u_core__DOT__fpc[__VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v4] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__fpc__v4;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__fpc__v5) {
        vlSelfRef.ember_top__DOT__u_core__DOT__fpc[__VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v5] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__fpc__v5;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__fpc__v6) {
        vlSelfRef.ember_top__DOT__u_core__DOT__fpc[__VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v6] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__fpc__v6;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__fpc__v7) {
        vlSelfRef.ember_top__DOT__u_core__DOT__fpc[__VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v7] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__fpc__v7;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__fpc__v8) {
        vlSelfRef.ember_top__DOT__u_core__DOT__fpc[__VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v8] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__fpc__v8;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__fpc__v9) {
        vlSelfRef.ember_top__DOT__u_core__DOT__fpc[__VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v9] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__fpc__v9;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__T__v14) {
        vlSelfRef.ember_top__DOT__u_core__DOT__fpc[0U] = 0U;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__ibuf_w__v0) {
        vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_w[__VdlyDim0__ember_top__DOT__u_core__DOT__ibuf_w__v0] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__ibuf_w__v0;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__T__v15) {
        vlSelfRef.ember_top__DOT__u_core__DOT__T[0U] 
            = (8U & vlSelfRef.ember_top__DOT__u_core__DOT__T[0U]);
        vlSelfRef.ember_top__DOT__u_core__DOT__T[1U] 
            = (7U & vlSelfRef.ember_top__DOT__u_core__DOT__T[1U]);
        vlSelfRef.ember_top__DOT__u_core__DOT__T[1U] 
            = (8U & vlSelfRef.ember_top__DOT__u_core__DOT__T[1U]);
        vlSelfRef.ember_top__DOT__u_core__DOT__T[2U] 
            = (7U & vlSelfRef.ember_top__DOT__u_core__DOT__T[2U]);
        vlSelfRef.ember_top__DOT__u_core__DOT__T[2U] 
            = (8U & vlSelfRef.ember_top__DOT__u_core__DOT__T[2U]);
        vlSelfRef.ember_top__DOT__u_core__DOT__T[3U] 
            = (7U & vlSelfRef.ember_top__DOT__u_core__DOT__T[3U]);
        vlSelfRef.ember_top__DOT__u_core__DOT__T[3U] 
            = (8U & vlSelfRef.ember_top__DOT__u_core__DOT__T[3U]);
        vlSelfRef.ember_top__DOT__u_core__DOT__fpc[1U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__fpc[2U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__fpc[3U] = 0U;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__gpr__v0) {
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[__VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v0][__VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v0] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v0;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__gpr__v1) {
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[__VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v1][__VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v1] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v1;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__T__v0) {
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[0U][12U] = 0x0005b000U;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__T__v1) {
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[0U][13U] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v3;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[0U][14U] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v4;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[0U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[1U][12U] = 0x0005b000U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[1U][13U] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v7;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[1U][14U] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v8;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[1U][15U] = 1U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[2U][12U] = 0x0005b000U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[2U][13U] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v11;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[2U][14U] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v12;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[2U][15U] = 2U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[3U][12U] = 0x0005b000U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[3U][13U] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v15;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[3U][14U] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v16;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[3U][15U] = 3U;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__gpr__v18) {
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[__VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v18][__VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v18] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v18;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__gpr__v19) {
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[__VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v19][__VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v19] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v19;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__gpr__v20) {
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[__VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v20][__VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v20] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v20;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__gpr__v21) {
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[__VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v21][__VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v21] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v21;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__gpr__v22) {
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[__VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v22][__VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v22] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v22;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__gpr__v23) {
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[__VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v23][__VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v23] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v23;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__gpr__v24) {
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[__VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v24][__VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v24] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v24;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__gpr__v25) {
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[__VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v25][__VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v25] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v25;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__gpr__v26) {
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[__VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v26][__VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v26] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v26;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__gpr__v27) {
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[__VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v27][__VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v27] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v27;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__T__v14) {
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[0U][12U] = 0x0005b000U;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__T__v15) {
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[0U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[0U][14U] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v30;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[0U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[1U][12U] = 0x0005b000U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[1U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[1U][14U] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v34;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[1U][15U] = 1U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[2U][12U] = 0x0005b000U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[2U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[2U][14U] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v38;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[2U][15U] = 2U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[3U][12U] = 0x0005b000U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[3U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[3U][14U] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v42;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[3U][15U] = 3U;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__gpr__v44) {
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[0U][0U] = 0U;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_core__DOT__T__v22) {
        vlSelfRef.ember_top__DOT__u_core__DOT__T[0U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__T[1U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__T[2U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__T[3U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__fpc[0U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__fpc[1U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__fpc[2U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__fpc[3U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_w[0U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_w[1U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_w[2U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_w[3U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[0U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[0U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[0U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[0U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[0U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[0U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[0U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[0U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[0U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[0U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[0U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[0U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[0U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[0U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[0U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[1U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[1U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[1U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[1U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[1U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[1U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[1U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[1U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[1U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[1U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[1U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[1U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[1U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[1U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[1U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[1U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[2U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[2U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[2U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[2U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[2U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[2U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[2U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[2U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[2U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[2U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[2U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[2U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[2U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[2U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[2U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[2U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[3U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[3U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[3U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[3U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[3U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[3U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[3U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[3U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[3U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[3U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[3U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[3U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[3U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[3U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[3U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__gpr[3U][15U] = 0U;
    }
    vlSelfRef.ember_top__DOT__u_tu__DOT__rq_pend = vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__rq_pend;
    vlSelfRef.ember_top__DOT__u_tu__DOT__rq_req_cyc 
        = vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__rq_req_cyc;
    vlSelfRef.ember_top__DOT__u_tu__DOT__mac_pend = vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__mac_pend;
    vlSelfRef.ember_top__DOT__u_tu__DOT__st = vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__st;
    vlSelfRef.ember_top__DOT__u_tu__DOT__n0 = vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__n0;
    vlSelfRef.ember_top__DOT__u_tu__DOT__m0 = vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__m0;
    vlSelfRef.ember_top__DOT__u_tu__DOT__k0 = vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__k0;
    vlSelfRef.ember_top__DOT__u_tu__DOT__wrow = vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__wrow;
    vlSelfRef.ember_top__DOT__u_tu__DOT__wgrp = vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__wgrp;
    vlSelfRef.ember_top__DOT__u_tu__DOT__cw_word = vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__cw_word;
    vlSelfRef.ember_top__DOT__u_tu__DOT__cw_rblk = vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__cw_rblk;
    vlSelfRef.ember_top__DOT__u_tu__DOT__mrow = vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__mrow;
    vlSelfRef.ember_top__DOT__u_tu__DOT__fcnt = vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__fcnt;
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_tu__DOT__acc__v0) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[__VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v0][0U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v0;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_tu__DOT__acc__v1) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[__VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v1][1U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v1;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[__VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v2][2U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v2;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[__VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v3][3U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v3;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[__VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v4][4U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v4;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[__VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v5][5U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v5;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[__VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v6][6U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v6;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[__VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v7][7U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v7;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[__VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v8][8U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v8;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[__VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v9][9U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v9;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[__VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v10][10U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v10;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[__VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v11][11U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v11;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[__VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v12][12U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v12;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[__VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v13][13U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v13;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[__VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v14][14U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v14;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[__VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v15][15U] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v15;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_tu__DOT__acc__v16) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][0U] = 0U;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_tu__DOT__acc__v17) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][15U] = 0U;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_tu__DOT__acc__v272) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][0U] = 0U;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_tu__DOT__acc__v273) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][15U] = 0U;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_tu__DOT__acc__v528) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][0U] = 0U;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_tu__DOT__acc__v529) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][15U] = 0U;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_tu__DOT__acc__v784) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[0U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[1U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[2U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[3U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[4U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[5U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[6U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[7U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[8U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[9U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[10U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[11U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[12U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[13U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[14U][15U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][0U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][1U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][2U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][3U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][4U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][5U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][6U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][7U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][8U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][9U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][10U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][11U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][12U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][13U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][14U] = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__acc[15U][15U] = 0U;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_tu__DOT__wrowbuf__v0) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__wrowbuf[__VdlyDim0__ember_top__DOT__u_tu__DOT__wrowbuf__v0] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__wrowbuf__v0;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_tu__DOT__abuf_q__v0) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__abuf_q[__VdlyDim0__ember_top__DOT__u_tu__DOT__abuf_q__v0] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__abuf_q__v0;
    }
    vlSelfRef.ember_top__DOT__u_disp__DOT__vcnt = vlSelfRef.__Vdly__ember_top__DOT__u_disp__DOT__vcnt;
    vlSelfRef.ember_top__DOT__u_disp__DOT__hcnt = vlSelfRef.__Vdly__ember_top__DOT__u_disp__DOT__hcnt;
    VL_SHIFTRS_WWI(96,96,32, __Vtemp_144, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__v_fin, 0x00000016U);
    VL_SHIFTRS_WWI(96,96,32, __Vtemp_145, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__u_fin, 0x00000016U);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__tex_addr 
        = ((IData)(0x0004c000U) + ((0x0000ff00U & (__Vtemp_144[0U] 
                                                   << 8U)) 
                                   + (0x000000ffU & __Vtemp_145[0U])));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__pix_off 
        = VL_SHIFTL_III(32,32,32, (((IData)(0x00000140U) 
                                    * (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__iy)) 
                                   + (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__ix)), 1U);
    ember_top__DOT__u_rtr__DOT__u_scan__DOT__dith_up 
        = (1U & ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__ix) 
                 ^ (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__iy)));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__dx12 = (0x00000001ffffffffULL 
                                                  & (VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[5U]) 
                                                     - 
                                                     VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[3U])));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__dy12 = (0x00000001ffffffffULL 
                                                  & (VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[6U]) 
                                                     - 
                                                     VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[4U])));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__dx20 = (0x00000001ffffffffULL 
                                                  & (VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[1U]) 
                                                     - 
                                                     VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[5U])));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__dy20 = (0x00000001ffffffffULL 
                                                  & (VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[2U]) 
                                                     - 
                                                     VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[6U])));
    ember_top__DOT__u_rtr__DOT__u_setup__DOT__xmax 
        = (VL_GTS_III(32, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[1U], vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[3U])
            ? (VL_GTS_III(32, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[1U], vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[5U])
                ? vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[1U]
                : vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[5U])
            : (VL_GTS_III(32, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[3U], vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[5U])
                ? vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[3U]
                : vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[5U]));
    ember_top__DOT__u_rtr__DOT__u_setup__DOT__ymax 
        = (VL_GTS_III(32, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[2U], vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[4U])
            ? (VL_GTS_III(32, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[2U], vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[6U])
                ? vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[2U]
                : vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[6U])
            : (VL_GTS_III(32, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[4U], vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[6U])
                ? vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[4U]
                : vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[6U]));
    ember_top__DOT__u_rtr__DOT__u_setup__DOT__xmin 
        = (VL_LTS_III(32, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[1U], vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[3U])
            ? (VL_LTS_III(32, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[1U], vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[5U])
                ? vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[1U]
                : vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[5U])
            : (VL_LTS_III(32, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[3U], vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[5U])
                ? vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[3U]
                : vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[5U]));
    ember_top__DOT__u_rtr__DOT__u_setup__DOT__ymin 
        = (VL_LTS_III(32, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[2U], vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[4U])
            ? (VL_LTS_III(32, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[2U], vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[6U])
                ? vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[2U]
                : vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[6U])
            : (VL_LTS_III(32, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[4U], vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[6U])
                ? vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[4U]
                : vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[6U]));
    if ((2U & vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[0U])) {
        ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_r 
            = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__mr;
        ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_g 
            = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__mg;
        ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_b 
            = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__mb;
    } else {
        ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_r 
            = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cr;
        ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_g 
            = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cg;
        ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_b 
            = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cb;
    }
    __Vtemp_146[0U] = (0x3fc00000U & (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[11U] 
                                      << 0x00000016U));
    __Vtemp_146[1U] = 0U;
    __Vtemp_146[2U] = 0U;
    __Vtemp_147[0U] = (0x3fc00000U & (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[10U] 
                                      << 0x00000016U));
    __Vtemp_147[1U] = 0U;
    __Vtemp_147[2U] = 0U;
    VL_SUB_W(3, ember_top__DOT__u_rtr__DOT__u_setup__DOT__r10, __Vtemp_146, __Vtemp_147);
    __Vtemp_148[0U] = (0x3fc00000U & (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[12U] 
                                      << 0x00000016U));
    __Vtemp_148[1U] = 0U;
    __Vtemp_148[2U] = 0U;
    __Vtemp_149[0U] = (0x3fc00000U & (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[10U] 
                                      << 0x00000016U));
    __Vtemp_149[1U] = 0U;
    __Vtemp_149[2U] = 0U;
    VL_SUB_W(3, ember_top__DOT__u_rtr__DOT__u_setup__DOT__r20, __Vtemp_148, __Vtemp_149);
    __Vtemp_150[0U] = (0x3fc00000U & (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[11U] 
                                      << 0x0000000eU));
    __Vtemp_150[1U] = 0U;
    __Vtemp_150[2U] = 0U;
    __Vtemp_151[0U] = (0x3fc00000U & (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[10U] 
                                      << 0x0000000eU));
    __Vtemp_151[1U] = 0U;
    __Vtemp_151[2U] = 0U;
    VL_SUB_W(3, ember_top__DOT__u_rtr__DOT__u_setup__DOT__g10, __Vtemp_150, __Vtemp_151);
    __Vtemp_152[0U] = (0x3fc00000U & (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[12U] 
                                      << 0x0000000eU));
    __Vtemp_152[1U] = 0U;
    __Vtemp_152[2U] = 0U;
    __Vtemp_153[0U] = (0x3fc00000U & (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[10U] 
                                      << 0x0000000eU));
    __Vtemp_153[1U] = 0U;
    __Vtemp_153[2U] = 0U;
    VL_SUB_W(3, ember_top__DOT__u_rtr__DOT__u_setup__DOT__g20, __Vtemp_152, __Vtemp_153);
    __Vtemp_154[0U] = (0x3fc00000U & (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[11U] 
                                      << 6U));
    __Vtemp_154[1U] = 0U;
    __Vtemp_154[2U] = 0U;
    __Vtemp_155[0U] = (0x3fc00000U & (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[10U] 
                                      << 6U));
    __Vtemp_155[1U] = 0U;
    __Vtemp_155[2U] = 0U;
    VL_SUB_W(3, ember_top__DOT__u_rtr__DOT__u_setup__DOT__b10, __Vtemp_154, __Vtemp_155);
    __Vtemp_156[0U] = (0x3fc00000U & (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[12U] 
                                      << 6U));
    __Vtemp_156[1U] = 0U;
    __Vtemp_156[2U] = 0U;
    __Vtemp_157[0U] = (0x3fc00000U & (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[10U] 
                                      << 6U));
    __Vtemp_157[1U] = 0U;
    __Vtemp_157[2U] = 0U;
    VL_SUB_W(3, ember_top__DOT__u_rtr__DOT__u_setup__DOT__b20, __Vtemp_156, __Vtemp_157);
    __Vtemp_158[0U] = (0x0000ffffU & vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[8U]);
    __Vtemp_158[1U] = 0U;
    __Vtemp_158[2U] = 0U;
    __Vtemp_159[0U] = (0x0000ffffU & vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[7U]);
    __Vtemp_159[1U] = 0U;
    __Vtemp_159[2U] = 0U;
    VL_SUB_W(3, ember_top__DOT__u_rtr__DOT__u_setup__DOT__z10, __Vtemp_158, __Vtemp_159);
    __Vtemp_160[0U] = (0x0000ffffU & vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[9U]);
    __Vtemp_160[1U] = 0U;
    __Vtemp_160[2U] = 0U;
    __Vtemp_161[0U] = (0x0000ffffU & vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[7U]);
    __Vtemp_161[1U] = 0U;
    __Vtemp_161[2U] = 0U;
    VL_SUB_W(3, ember_top__DOT__u_rtr__DOT__u_setup__DOT__z20, __Vtemp_160, __Vtemp_161);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u0e[0U] 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[13U];
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u0e[1U] 
        = (IData)((- (QData)((IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[13U] 
                                      >> 0x0000001fU)))));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u0e[2U] 
        = (IData)(((- (QData)((IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[13U] 
                                       >> 0x0000001fU)))) 
                   >> 0x00000020U));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v0e[0U] 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[14U];
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v0e[1U] 
        = (IData)((- (QData)((IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[14U] 
                                      >> 0x0000001fU)))));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v0e[2U] 
        = (IData)(((- (QData)((IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[14U] 
                                       >> 0x0000001fU)))) 
                   >> 0x00000020U));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__dx01 = (0x00000001ffffffffULL 
                                                  & (VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[3U]) 
                                                     - 
                                                     VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[1U])));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__dy01 = (0x00000001ffffffffULL 
                                                  & (VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[4U]) 
                                                     - 
                                                     VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[2U])));
    ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy20_ 
        = (0x00000001ffffffffULL & (VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[6U]) 
                                    - VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[2U])));
    ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx20_ 
        = (0x00000001ffffffffULL & (VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[5U]) 
                                    - VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[1U])));
    vlSelfRef.ember_top__DOT__u_gsx__DOT__f_done = 
        (1U & ((vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s0[3U] 
                | (vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s1[3U] 
                   | (vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s2[3U] 
                      | vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s3[3U]))) 
               >> 5U));
    vlSelfRef.ember_top__DOT__u_core__DOT__exec_en = 0U;
    if (((((1U == (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__st)) 
           & ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_v) 
              >> 3U)) & (~ ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__waitv) 
                            >> 3U))) & (~ ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__barv) 
                                           >> 3U)))) {
        vlSelfRef.ember_top__DOT__u_core__DOT__exec_en = 1U;
    }
    if (((((1U == (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__st)) 
           & ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_v) 
              >> 2U)) & (~ ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__waitv) 
                            >> 2U))) & (~ ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__barv) 
                                           >> 2U)))) {
        vlSelfRef.ember_top__DOT__u_core__DOT__exec_en = 1U;
    }
    if (((((1U == (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__st)) 
           & ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_v) 
              >> 1U)) & (~ ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__waitv) 
                            >> 1U))) & (~ ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__barv) 
                                           >> 1U)))) {
        vlSelfRef.ember_top__DOT__u_core__DOT__exec_en = 1U;
    }
    vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid = 0U;
    if (((((1U == (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__st)) 
           & ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_v) 
              >> 3U)) & (~ ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__waitv) 
                            >> 3U))) & (~ ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__barv) 
                                           >> 3U)))) {
        vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid = 3U;
    }
    if (((((1U == (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__st)) 
           & ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_v) 
              >> 2U)) & (~ ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__waitv) 
                            >> 2U))) & (~ ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__barv) 
                                           >> 2U)))) {
        vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid = 2U;
    }
    if (((((1U == (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__st)) 
           & ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_v) 
              >> 1U)) & (~ ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__waitv) 
                            >> 1U))) & (~ ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__barv) 
                                           >> 1U)))) {
        vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid = 1U;
    }
    if (((((1U == (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__st)) 
           & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_v)) 
          & (~ (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__waitv))) 
         & (~ (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__barv)))) {
        vlSelfRef.ember_top__DOT__u_core__DOT__exec_en = 1U;
        vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid = 0U;
    }
    vlSelfRef.ember_top__DOT__u_core__DOT__pick_en = 0U;
    if ((((1U == (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__st)) 
          & (~ (vlSelfRef.ember_top__DOT__u_core__DOT__T[3U] 
                >> 3U))) & (~ ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_v) 
                               >> 3U)))) {
        vlSelfRef.ember_top__DOT__u_core__DOT__pick_en = 1U;
    }
    if ((((1U == (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__st)) 
          & (~ (vlSelfRef.ember_top__DOT__u_core__DOT__T[2U] 
                >> 3U))) & (~ ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_v) 
                               >> 2U)))) {
        vlSelfRef.ember_top__DOT__u_core__DOT__pick_en = 1U;
    }
    if ((((1U == (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__st)) 
          & (~ (vlSelfRef.ember_top__DOT__u_core__DOT__T[1U] 
                >> 3U))) & (~ ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_v) 
                               >> 1U)))) {
        vlSelfRef.ember_top__DOT__u_core__DOT__pick_en = 1U;
    }
    vlSelfRef.ember_top__DOT__u_core__DOT__pick_tid = 0U;
    if ((((1U == (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__st)) 
          & (~ (vlSelfRef.ember_top__DOT__u_core__DOT__T[3U] 
                >> 3U))) & (~ ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_v) 
                               >> 3U)))) {
        vlSelfRef.ember_top__DOT__u_core__DOT__pick_tid = 3U;
    }
    if ((((1U == (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__st)) 
          & (~ (vlSelfRef.ember_top__DOT__u_core__DOT__T[2U] 
                >> 3U))) & (~ ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_v) 
                               >> 2U)))) {
        vlSelfRef.ember_top__DOT__u_core__DOT__pick_tid = 2U;
    }
    if ((((1U == (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__st)) 
          & (~ (vlSelfRef.ember_top__DOT__u_core__DOT__T[1U] 
                >> 3U))) & (~ ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_v) 
                               >> 1U)))) {
        vlSelfRef.ember_top__DOT__u_core__DOT__pick_tid = 1U;
    }
    if ((((1U == (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__st)) 
          & (~ (vlSelfRef.ember_top__DOT__u_core__DOT__T[0U] 
                >> 3U))) & (~ (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_v)))) {
        vlSelfRef.ember_top__DOT__u_core__DOT__pick_en = 1U;
        vlSelfRef.ember_top__DOT__u_core__DOT__pick_tid = 0U;
    }
    vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[0U] 
        = (0x000000ffU & vlSelfRef.ember_top__DOT__u_tu__DOT__wrowbuf[0U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[1U] 
        = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_tu__DOT__wrowbuf[0U] 
                          >> 8U));
    vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[2U] 
        = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_tu__DOT__wrowbuf[0U] 
                          >> 0x00000010U));
    vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__wrowbuf[0U] 
           >> 0x00000018U);
    vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[4U] 
        = (0x000000ffU & vlSelfRef.ember_top__DOT__u_tu__DOT__wrowbuf[1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[5U] 
        = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_tu__DOT__wrowbuf[1U] 
                          >> 8U));
    vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[6U] 
        = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_tu__DOT__wrowbuf[1U] 
                          >> 0x00000010U));
    vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[7U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__wrowbuf[1U] 
           >> 0x00000018U);
    vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[8U] 
        = (0x000000ffU & vlSelfRef.ember_top__DOT__u_tu__DOT__wrowbuf[2U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[9U] 
        = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_tu__DOT__wrowbuf[2U] 
                          >> 8U));
    vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[10U] 
        = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_tu__DOT__wrowbuf[2U] 
                          >> 0x00000010U));
    vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[11U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__wrowbuf[2U] 
           >> 0x00000018U);
    vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[12U] 
        = (0x000000ffU & vlSelfRef.ember_top__DOT__u_tu__DOT__wrowbuf[3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[13U] 
        = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_tu__DOT__wrowbuf[3U] 
                          >> 8U));
    vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[14U] 
        = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_tu__DOT__wrowbuf[3U] 
                          >> 0x00000010U));
    vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte[15U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__wrowbuf[3U] 
           >> 0x00000018U);
    vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[0U] 
        = (0x000000ffU & vlSelfRef.ember_top__DOT__u_tu__DOT__abuf_q[0U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[1U] 
        = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_tu__DOT__abuf_q[0U] 
                          >> 8U));
    vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[2U] 
        = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_tu__DOT__abuf_q[0U] 
                          >> 0x00000010U));
    vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__abuf_q[0U] 
           >> 0x00000018U);
    vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[4U] 
        = (0x000000ffU & vlSelfRef.ember_top__DOT__u_tu__DOT__abuf_q[1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[5U] 
        = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_tu__DOT__abuf_q[1U] 
                          >> 8U));
    vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[6U] 
        = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_tu__DOT__abuf_q[1U] 
                          >> 0x00000010U));
    vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[7U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__abuf_q[1U] 
           >> 0x00000018U);
    vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[8U] 
        = (0x000000ffU & vlSelfRef.ember_top__DOT__u_tu__DOT__abuf_q[2U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[9U] 
        = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_tu__DOT__abuf_q[2U] 
                          >> 8U));
    vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[10U] 
        = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_tu__DOT__abuf_q[2U] 
                          >> 0x00000010U));
    vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[11U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__abuf_q[2U] 
           >> 0x00000018U);
    vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[12U] 
        = (0x000000ffU & vlSelfRef.ember_top__DOT__u_tu__DOT__abuf_q[3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[13U] 
        = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_tu__DOT__abuf_q[3U] 
                          >> 8U));
    vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[14U] 
        = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_tu__DOT__abuf_q[3U] 
                          >> 0x00000010U));
    vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[15U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__abuf_q[3U] 
           >> 0x00000018U);
    vlSelfRef.ember_top__DOT__u_disp__DOT__de_now = 
        ((0x0280U > (IData)(vlSelfRef.ember_top__DOT__u_disp__DOT__hcnt)) 
         & (0x01e0U > (IData)(vlSelfRef.ember_top__DOT__u_disp__DOT__vcnt)));
    vlSelfRef.ember_top__DOT__u_cp__DOT__dma_addr_q 
        = vlSelfRef.__Vdly__ember_top__DOT__u_cp__DOT__dma_addr_q;
    vlSelfRef.ember_top__DOT__u_cp__DOT__r_pend_q = vlSelfRef.__Vdly__ember_top__DOT__u_cp__DOT__r_pend_q;
    vlSelfRef.ember_top__DOT__u_cp__DOT__dstate = vlSelfRef.__Vdly__ember_top__DOT__u_cp__DOT__dstate;
    vlSelfRef.ember_top__DOT__u_cp__DOT__dma_left_q 
        = vlSelfRef.__Vdly__ember_top__DOT__u_cp__DOT__dma_left_q;
    vlSelfRef.ember_top__DOT__d_rvalid = ((2U == (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__rstate)) 
                                          & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__ar_v));
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_cp__DOT__up_mem__v0) {
        vlSelfRef.ember_top__DOT__u_cp__DOT__up_mem[vlSelfRef.__VdlyDim0__ember_top__DOT__u_cp__DOT__up_mem__v0] 
            = vlSelfRef.__VdlyVal__ember_top__DOT__u_cp__DOT__up_mem__v0;
    }
    vlSelfRef.ember_top__DOT__u_cp__DOT__up_rp = vlSelfRef.__Vdly__ember_top__DOT__u_cp__DOT__up_rp;
    vlSelfRef.ember_top__DOT__u_cp__DOT__up_wp = vlSelfRef.__Vdly__ember_top__DOT__u_cp__DOT__up_wp;
    vlSelfRef.ember_top__DOT__d_wvalid = vlSelfRef.__Vdly__ember_top__DOT__d_wvalid;
    vlSelfRef.ember_top__DOT__v_awready = (1U & ((~ (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__aw_v)) 
                                                 | (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__wr_fire)));
    vlSelfRef.ember_top__DOT__v_wready = (1U & ((~ (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__w_v)) 
                                                | (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__wr_fire)));
    vlSelfRef.ember_top__DOT__v_arready = (1U & ((~ (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__ar_v)) 
                                                 | ((IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__ar_v) 
                                                    & (IData)(vlSelfRef.ember_top__DOT__v_rready))));
    vlSelfRef.ember_top__DOT__d_arvalid = vlSelfRef.__Vdly__ember_top__DOT__d_arvalid;
    vlSelfRef.ember_top__DOT__d_awvalid = vlSelfRef.__Vdly__ember_top__DOT__d_awvalid;
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_8 = VL_SHIFTRS_III(32,32,32, 
                                                              (VL_GTS_III(32, 0U, ember_top__DOT__u_rtr__DOT__u_setup__DOT__xmax)
                                                                ? 0U
                                                                : 
                                                               (VL_LTS_III(32, 0x4fc00000U, ember_top__DOT__u_rtr__DOT__u_setup__DOT__xmax)
                                                                 ? 0x4fc00000U
                                                                 : ember_top__DOT__u_rtr__DOT__u_setup__DOT__xmax)), 0x00000016U);
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_10 = VL_SHIFTRS_III(32,32,32, 
                                                               (VL_GTS_III(32, 0U, ember_top__DOT__u_rtr__DOT__u_setup__DOT__ymax)
                                                                 ? 0U
                                                                 : 
                                                                (VL_LTS_III(32, 0x3bc00000U, ember_top__DOT__u_rtr__DOT__u_setup__DOT__ymax)
                                                                  ? 0x3bc00000U
                                                                  : ember_top__DOT__u_rtr__DOT__u_setup__DOT__ymax)), 0x00000016U);
    __VdfgRegularize_h6e95ff9d_0_7 = VL_SHIFTRS_III(32,32,32, 
                                                    (VL_GTS_III(32, 0U, ember_top__DOT__u_rtr__DOT__u_setup__DOT__xmin)
                                                      ? 0U
                                                      : 
                                                     (VL_LTS_III(32, 0x4fc00000U, ember_top__DOT__u_rtr__DOT__u_setup__DOT__xmin)
                                                       ? 0x4fc00000U
                                                       : ember_top__DOT__u_rtr__DOT__u_setup__DOT__xmin)), 0x00000016U);
    __VdfgRegularize_h6e95ff9d_0_9 = VL_SHIFTRS_III(32,32,32, 
                                                    (VL_GTS_III(32, 0U, ember_top__DOT__u_rtr__DOT__u_setup__DOT__ymin)
                                                      ? 0U
                                                      : 
                                                     (VL_LTS_III(32, 0x3bc00000U, ember_top__DOT__u_rtr__DOT__u_setup__DOT__ymin)
                                                       ? 0x3bc00000U
                                                       : ember_top__DOT__u_rtr__DOT__u_setup__DOT__ymin)), 0x00000016U);
    if ((0x00000010U & vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[0U])) {
        if (ember_top__DOT__u_rtr__DOT__u_scan__DOT__dith_up) {
            vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmr 
                = (0x000000ffU & ((0xffU == (IData)(ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_r))
                                   ? 0xffU : ((IData)(1U) 
                                              + (IData)(ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_r))));
            vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmg 
                = (0x000000ffU & ((0xffU == (IData)(ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_g))
                                   ? 0xffU : ((IData)(1U) 
                                              + (IData)(ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_g))));
            vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmb 
                = (0x000000ffU & ((0xffU == (IData)(ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_b))
                                   ? 0xffU : ((IData)(1U) 
                                              + (IData)(ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_b))));
        } else {
            vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmr 
                = (0x000000ffU & ((0U == (IData)(ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_r))
                                   ? 0U : ((IData)(ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_r) 
                                           - (IData)(1U))));
            vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmg 
                = (0x000000ffU & ((0U == (IData)(ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_g))
                                   ? 0U : ((IData)(ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_g) 
                                           - (IData)(1U))));
            vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmb 
                = (0x000000ffU & ((0U == (IData)(ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_b))
                                   ? 0U : ((IData)(ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_b) 
                                           - (IData)(1U))));
        }
    } else {
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmr 
            = (0x000000ffU & (IData)(ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_r));
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmg 
            = (0x000000ffU & (IData)(ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_g));
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmb 
            = (0x000000ffU & (IData)(ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_b));
    }
    __Vtemp_162[0U] = vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[15U];
    __Vtemp_162[1U] = (IData)((- (QData)((IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[15U] 
                                                  >> 0x0000001fU)))));
    __Vtemp_162[2U] = (IData)(((- (QData)((IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[15U] 
                                                   >> 0x0000001fU)))) 
                               >> 0x00000020U));
    VL_SUB_W(3, ember_top__DOT__u_rtr__DOT__u_setup__DOT__u10, __Vtemp_162, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u0e);
    __Vtemp_163[0U] = vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[17U];
    __Vtemp_163[1U] = (IData)((- (QData)((IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[17U] 
                                                  >> 0x0000001fU)))));
    __Vtemp_163[2U] = (IData)(((- (QData)((IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[17U] 
                                                   >> 0x0000001fU)))) 
                               >> 0x00000020U));
    VL_SUB_W(3, ember_top__DOT__u_rtr__DOT__u_setup__DOT__u20, __Vtemp_163, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u0e);
    __Vtemp_164[0U] = vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[16U];
    __Vtemp_164[1U] = (IData)((- (QData)((IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[16U] 
                                                  >> 0x0000001fU)))));
    __Vtemp_164[2U] = (IData)(((- (QData)((IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[16U] 
                                                   >> 0x0000001fU)))) 
                               >> 0x00000020U));
    VL_SUB_W(3, ember_top__DOT__u_rtr__DOT__u_setup__DOT__v10, __Vtemp_164, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v0e);
    __Vtemp_165[0U] = vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[18U];
    __Vtemp_165[1U] = (IData)((- (QData)((IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[18U] 
                                                  >> 0x0000001fU)))));
    __Vtemp_165[2U] = (IData)(((- (QData)((IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[18U] 
                                                   >> 0x0000001fU)))) 
                               >> 0x00000020U));
    VL_SUB_W(3, ember_top__DOT__u_rtr__DOT__u_setup__DOT__v20, __Vtemp_165, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v0e);
    VL_EXTENDS_WQ(66,33, __Vtemp_169, vlSelfRef.ember_top__DOT__u_rtr__DOT__dx01);
    __Vtemp_170[0U] = __Vtemp_169[0U];
    __Vtemp_170[1U] = __Vtemp_169[1U];
    __Vtemp_170[2U] = (3U & __Vtemp_169[2U]);
    VL_EXTENDS_WQ(66,33, __Vtemp_172, ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy20_);
    __Vtemp_173[0U] = __Vtemp_172[0U];
    __Vtemp_173[1U] = __Vtemp_172[1U];
    __Vtemp_173[2U] = (3U & __Vtemp_172[2U]);
    VL_MULS_WWW(66, __Vtemp_174, __Vtemp_170, __Vtemp_173);
    __Vtemp_175[0U] = __Vtemp_174[0U];
    __Vtemp_175[1U] = __Vtemp_174[1U];
    __Vtemp_175[2U] = (3U & __Vtemp_174[2U]);
    VL_EXTENDS_WW(67,66, __Vtemp_176, __Vtemp_175);
    VL_EXTENDS_WQ(66,33, __Vtemp_179, vlSelfRef.ember_top__DOT__u_rtr__DOT__dy01);
    __Vtemp_180[0U] = __Vtemp_179[0U];
    __Vtemp_180[1U] = __Vtemp_179[1U];
    __Vtemp_180[2U] = (3U & __Vtemp_179[2U]);
    VL_EXTENDS_WQ(66,33, __Vtemp_182, ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx20_);
    __Vtemp_183[0U] = __Vtemp_182[0U];
    __Vtemp_183[1U] = __Vtemp_182[1U];
    __Vtemp_183[2U] = (3U & __Vtemp_182[2U]);
    VL_MULS_WWW(66, __Vtemp_184, __Vtemp_180, __Vtemp_183);
    __Vtemp_185[0U] = __Vtemp_184[0U];
    __Vtemp_185[1U] = __Vtemp_184[1U];
    __Vtemp_185[2U] = (3U & __Vtemp_184[2U]);
    VL_EXTENDS_WW(67,66, __Vtemp_186, __Vtemp_185);
    VL_SUB_W(3, __Vtemp_187, __Vtemp_176, __Vtemp_186);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__area[0U] 
        = __Vtemp_187[0U];
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__area[1U] 
        = __Vtemp_187[1U];
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__area[2U] 
        = (7U & __Vtemp_187[2U]);
    vlSelfRef.ember_top__DOT__u_core__DOT__i_op = (vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_w
                                                   [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid] 
                                                   >> 0x00000018U);
    vlSelfRef.ember_top__DOT__u_core__DOT__i_rd = (0x0000000fU 
                                                   & (vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_w
                                                      [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid] 
                                                      >> 0x00000014U));
    vlSelfRef.ember_top__DOT__u_core__DOT__i_sx9 = 
        (0x000001ffU & vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_w
         [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid]);
    vlSelfRef.ember_top__DOT__u_core__DOT__i_sx11 = 
        (0x000007ffU & vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_w
         [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid]);
    vlSelfRef.ember_top__DOT__u_core__DOT__rbv = vlSelfRef.ember_top__DOT__u_core__DOT__gpr
        [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid]
        [(0x0000000fU & (vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_w
                         [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid] 
                         >> 0x0000000cU))];
    vlSelfRef.ember_top__DOT__u_core__DOT__i_ra = (0x0000000fU 
                                                   & (vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_w
                                                      [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid] 
                                                      >> 0x00000010U));
    vlSelfRef.ember_top__DOT__u_core__DOT__i_imm = 
        (0x00000fffU & vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_w
         [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid]);
    vlSelfRef.ember_top__DOT__u_cp__DOT__up_full = 
        (((1U & ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__up_wp) 
                 >> 6U)) != (1U & ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__up_rp) 
                                   >> 6U))) & ((0x0000003fU 
                                                & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__up_wp)) 
                                               == (0x0000003fU 
                                                   & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__up_rp))));
    vlSelfRef.ember_top__DOT__u_xbar__DOT__r_fwd_d 
        = ((0U == (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__rstate)) 
           & ((IData)(vlSelfRef.ember_top__DOT__d_arvalid) 
              & ((~ (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__h_req_v_r)) 
                 | (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__r_favor_d))));
    vlSelfRef.ember_top__DOT__u_xbar__DOT__r_fwd_h 
        = ((0U == (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__rstate)) 
           & ((~ ((IData)(vlSelfRef.ember_top__DOT__d_arvalid) 
                  & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__r_favor_d))) 
              & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__h_req_v_r)));
    vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_d 
        = ((0U == (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__wstate)) 
           & ((IData)(vlSelfRef.ember_top__DOT__d_awvalid) 
              & ((~ (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__h_req_v_w)) 
                 | (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_favor_d))));
    vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_h 
        = ((0U == (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__wstate)) 
           & ((~ ((IData)(vlSelfRef.ember_top__DOT__d_awvalid) 
                  & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_favor_d))) 
              & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__h_req_v_w)));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__x_lo_i = 
        (VL_GTS_III(32, 0U, __VdfgRegularize_h6e95ff9d_0_7)
          ? 0U : (0x0000ffffU & __VdfgRegularize_h6e95ff9d_0_7));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__y_lo_i = 
        (VL_GTS_III(32, 0U, __VdfgRegularize_h6e95ff9d_0_9)
          ? 0U : (0x0000ffffU & __VdfgRegularize_h6e95ff9d_0_9));
    if ((0U == ((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__area[0U] 
                 | vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__area[1U]) 
                | vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__area[2U]))) {
        ember_top__DOT__u_rtr__DOT__u_setup__DOT__den[0U] = 1U;
        ember_top__DOT__u_rtr__DOT__u_setup__DOT__den[1U] = 0U;
        ember_top__DOT__u_rtr__DOT__u_setup__DOT__den[2U] = 0U;
    } else {
        ember_top__DOT__u_rtr__DOT__u_setup__DOT__den[0U] 
            = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__area[0U];
        ember_top__DOT__u_rtr__DOT__u_setup__DOT__den[1U] 
            = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__area[1U];
        ember_top__DOT__u_rtr__DOT__u_setup__DOT__den[2U] 
            = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__area[2U];
    }
    vlSelfRef.ember_top__DOT__u_core__DOT__rav = vlSelfRef.ember_top__DOT__u_core__DOT__gpr
        [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid]
        [vlSelfRef.ember_top__DOT__u_core__DOT__i_ra];
    vlSelfRef.ember_top__DOT__u_core__DOT__i_sx12 = 
        (((- (IData)((1U & (vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_w
                            [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid] 
                            >> 0x0000000bU)))) << 0x0000000cU) 
         | (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_imm));
    vlSelfRef.ember_top__DOT__u_vram__DOT__ar_accept 
        = (((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__r_fwd_h) 
            | (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__r_fwd_d)) 
           & (IData)(vlSelfRef.ember_top__DOT__v_arready));
    vlSelfRef.h_arready = ((0U == (vlSelfRef.h_araddr 
                                   >> 0x0000000cU))
                            ? (IData)(vlSelfRef.ember_top__DOT__c_arready)
                            : ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__r_fwd_h) 
                               & (IData)(vlSelfRef.ember_top__DOT__v_arready)));
    vlSelfRef.ember_top__DOT__v_awvalid = ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_h) 
                                           | (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_d));
    vlSelfRef.ember_top__DOT__v_wvalid = (((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_h) 
                                           & (IData)(vlSelfRef.h_wvalid)) 
                                          | ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_d) 
                                             & (IData)(vlSelfRef.ember_top__DOT__d_wvalid)));
    __VdfgRegularize_h6e95ff9d_0_4[0U] = ember_top__DOT__u_rtr__DOT__u_setup__DOT__den[0U];
    __VdfgRegularize_h6e95ff9d_0_4[1U] = ember_top__DOT__u_rtr__DOT__u_setup__DOT__den[1U];
    __VdfgRegularize_h6e95ff9d_0_4[2U] = (((IData)(
                                                   (0x0007ffffffffffffULL 
                                                    & (- (QData)((IData)(
                                                                         (1U 
                                                                          & (ember_top__DOT__u_rtr__DOT__u_setup__DOT__den[2U] 
                                                                             >> 2U))))))) 
                                           << 3U) | ember_top__DOT__u_rtr__DOT__u_setup__DOT__den[2U]);
    __VdfgRegularize_h6e95ff9d_0_4[3U] = (((IData)(
                                                   (0x0007ffffffffffffULL 
                                                    & (- (QData)((IData)(
                                                                         (1U 
                                                                          & (ember_top__DOT__u_rtr__DOT__u_setup__DOT__den[2U] 
                                                                             >> 2U))))))) 
                                           >> 0x0000001dU) 
                                          | ((IData)(
                                                     ((0x0007ffffffffffffULL 
                                                       & (- (QData)((IData)(
                                                                            (1U 
                                                                             & (ember_top__DOT__u_rtr__DOT__u_setup__DOT__den[2U] 
                                                                                >> 2U)))))) 
                                                      >> 0x00000020U)) 
                                             << 3U));
    VL_EXTENDS_WQ(96,33, __Vtemp_193, ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy20_);
    VL_MULS_WWW(96, __Vtemp_194, ember_top__DOT__u_rtr__DOT__u_setup__DOT__r10, __Vtemp_193);
    VL_EXTENDS_WQ(96,33, __Vtemp_195, vlSelfRef.ember_top__DOT__u_rtr__DOT__dy01);
    VL_MULS_WWW(96, __Vtemp_196, ember_top__DOT__u_rtr__DOT__u_setup__DOT__r20, __Vtemp_195);
    VL_SUB_W(3, __Vtemp_197, __Vtemp_194, __Vtemp_196);
    VL_EXTENDS_WW(118,96, __Vtemp_198, __Vtemp_197);
    VL_SHIFTL_WWI(118,118,32, __Vtemp_199, __Vtemp_198, 0x00000016U);
    __Vtemp_200[0U] = __Vtemp_199[0U];
    __Vtemp_200[1U] = __Vtemp_199[1U];
    __Vtemp_200[2U] = __Vtemp_199[2U];
    __Vtemp_200[3U] = (0x003fffffU & __Vtemp_199[3U]);
    VL_DIVS_WWW(118, __Vtemp_201, __Vtemp_200, __VdfgRegularize_h6e95ff9d_0_4);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__rA = (((QData)((IData)(__Vtemp_201[1U])) 
                                                 << 0x00000020U) 
                                                | (QData)((IData)(__Vtemp_201[0U])));
    VL_EXTENDS_WQ(96,33, __Vtemp_205, vlSelfRef.ember_top__DOT__u_rtr__DOT__dx01);
    VL_MULS_WWW(96, __Vtemp_206, ember_top__DOT__u_rtr__DOT__u_setup__DOT__r20, __Vtemp_205);
    VL_EXTENDS_WQ(96,33, __Vtemp_207, ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx20_);
    VL_MULS_WWW(96, __Vtemp_208, ember_top__DOT__u_rtr__DOT__u_setup__DOT__r10, __Vtemp_207);
    VL_SUB_W(3, __Vtemp_209, __Vtemp_206, __Vtemp_208);
    VL_EXTENDS_WW(118,96, __Vtemp_210, __Vtemp_209);
    VL_SHIFTL_WWI(118,118,32, __Vtemp_211, __Vtemp_210, 0x00000016U);
    __Vtemp_212[0U] = __Vtemp_211[0U];
    __Vtemp_212[1U] = __Vtemp_211[1U];
    __Vtemp_212[2U] = __Vtemp_211[2U];
    __Vtemp_212[3U] = (0x003fffffU & __Vtemp_211[3U]);
    VL_DIVS_WWW(118, __Vtemp_213, __Vtemp_212, __VdfgRegularize_h6e95ff9d_0_4);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__rB = (((QData)((IData)(__Vtemp_213[1U])) 
                                                 << 0x00000020U) 
                                                | (QData)((IData)(__Vtemp_213[0U])));
    VL_EXTENDS_WQ(96,33, __Vtemp_217, ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy20_);
    VL_MULS_WWW(96, __Vtemp_218, ember_top__DOT__u_rtr__DOT__u_setup__DOT__g10, __Vtemp_217);
    VL_EXTENDS_WQ(96,33, __Vtemp_219, vlSelfRef.ember_top__DOT__u_rtr__DOT__dy01);
    VL_MULS_WWW(96, __Vtemp_220, ember_top__DOT__u_rtr__DOT__u_setup__DOT__g20, __Vtemp_219);
    VL_SUB_W(3, __Vtemp_221, __Vtemp_218, __Vtemp_220);
    VL_EXTENDS_WW(118,96, __Vtemp_222, __Vtemp_221);
    VL_SHIFTL_WWI(118,118,32, __Vtemp_223, __Vtemp_222, 0x00000016U);
    __Vtemp_224[0U] = __Vtemp_223[0U];
    __Vtemp_224[1U] = __Vtemp_223[1U];
    __Vtemp_224[2U] = __Vtemp_223[2U];
    __Vtemp_224[3U] = (0x003fffffU & __Vtemp_223[3U]);
    VL_DIVS_WWW(118, __Vtemp_225, __Vtemp_224, __VdfgRegularize_h6e95ff9d_0_4);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__gA = (((QData)((IData)(__Vtemp_225[1U])) 
                                                 << 0x00000020U) 
                                                | (QData)((IData)(__Vtemp_225[0U])));
    VL_EXTENDS_WQ(96,33, __Vtemp_229, vlSelfRef.ember_top__DOT__u_rtr__DOT__dx01);
    VL_MULS_WWW(96, __Vtemp_230, ember_top__DOT__u_rtr__DOT__u_setup__DOT__g20, __Vtemp_229);
    VL_EXTENDS_WQ(96,33, __Vtemp_231, ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx20_);
    VL_MULS_WWW(96, __Vtemp_232, ember_top__DOT__u_rtr__DOT__u_setup__DOT__g10, __Vtemp_231);
    VL_SUB_W(3, __Vtemp_233, __Vtemp_230, __Vtemp_232);
    VL_EXTENDS_WW(118,96, __Vtemp_234, __Vtemp_233);
    VL_SHIFTL_WWI(118,118,32, __Vtemp_235, __Vtemp_234, 0x00000016U);
    __Vtemp_236[0U] = __Vtemp_235[0U];
    __Vtemp_236[1U] = __Vtemp_235[1U];
    __Vtemp_236[2U] = __Vtemp_235[2U];
    __Vtemp_236[3U] = (0x003fffffU & __Vtemp_235[3U]);
    VL_DIVS_WWW(118, __Vtemp_237, __Vtemp_236, __VdfgRegularize_h6e95ff9d_0_4);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__gB = (((QData)((IData)(__Vtemp_237[1U])) 
                                                 << 0x00000020U) 
                                                | (QData)((IData)(__Vtemp_237[0U])));
    VL_EXTENDS_WQ(96,33, __Vtemp_241, ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy20_);
    VL_MULS_WWW(96, __Vtemp_242, ember_top__DOT__u_rtr__DOT__u_setup__DOT__b10, __Vtemp_241);
    VL_EXTENDS_WQ(96,33, __Vtemp_243, vlSelfRef.ember_top__DOT__u_rtr__DOT__dy01);
    VL_MULS_WWW(96, __Vtemp_244, ember_top__DOT__u_rtr__DOT__u_setup__DOT__b20, __Vtemp_243);
    VL_SUB_W(3, __Vtemp_245, __Vtemp_242, __Vtemp_244);
    VL_EXTENDS_WW(118,96, __Vtemp_246, __Vtemp_245);
    VL_SHIFTL_WWI(118,118,32, __Vtemp_247, __Vtemp_246, 0x00000016U);
    __Vtemp_248[0U] = __Vtemp_247[0U];
    __Vtemp_248[1U] = __Vtemp_247[1U];
    __Vtemp_248[2U] = __Vtemp_247[2U];
    __Vtemp_248[3U] = (0x003fffffU & __Vtemp_247[3U]);
    VL_DIVS_WWW(118, __Vtemp_249, __Vtemp_248, __VdfgRegularize_h6e95ff9d_0_4);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__bA = (((QData)((IData)(__Vtemp_249[1U])) 
                                                 << 0x00000020U) 
                                                | (QData)((IData)(__Vtemp_249[0U])));
    VL_EXTENDS_WQ(96,33, __Vtemp_253, vlSelfRef.ember_top__DOT__u_rtr__DOT__dx01);
    VL_MULS_WWW(96, __Vtemp_254, ember_top__DOT__u_rtr__DOT__u_setup__DOT__b20, __Vtemp_253);
    VL_EXTENDS_WQ(96,33, __Vtemp_255, ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx20_);
    VL_MULS_WWW(96, __Vtemp_256, ember_top__DOT__u_rtr__DOT__u_setup__DOT__b10, __Vtemp_255);
    VL_SUB_W(3, __Vtemp_257, __Vtemp_254, __Vtemp_256);
    VL_EXTENDS_WW(118,96, __Vtemp_258, __Vtemp_257);
    VL_SHIFTL_WWI(118,118,32, __Vtemp_259, __Vtemp_258, 0x00000016U);
    __Vtemp_260[0U] = __Vtemp_259[0U];
    __Vtemp_260[1U] = __Vtemp_259[1U];
    __Vtemp_260[2U] = __Vtemp_259[2U];
    __Vtemp_260[3U] = (0x003fffffU & __Vtemp_259[3U]);
    VL_DIVS_WWW(118, __Vtemp_261, __Vtemp_260, __VdfgRegularize_h6e95ff9d_0_4);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__bB = (((QData)((IData)(__Vtemp_261[1U])) 
                                                 << 0x00000020U) 
                                                | (QData)((IData)(__Vtemp_261[0U])));
    VL_EXTENDS_WQ(96,33, __Vtemp_265, ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy20_);
    VL_MULS_WWW(96, __Vtemp_266, ember_top__DOT__u_rtr__DOT__u_setup__DOT__z10, __Vtemp_265);
    VL_EXTENDS_WQ(96,33, __Vtemp_267, vlSelfRef.ember_top__DOT__u_rtr__DOT__dy01);
    VL_MULS_WWW(96, __Vtemp_268, ember_top__DOT__u_rtr__DOT__u_setup__DOT__z20, __Vtemp_267);
    VL_SUB_W(3, __Vtemp_269, __Vtemp_266, __Vtemp_268);
    VL_EXTENDS_WW(118,96, __Vtemp_270, __Vtemp_269);
    VL_SHIFTL_WWI(118,118,32, __Vtemp_271, __Vtemp_270, 0x00000016U);
    __Vtemp_272[0U] = __Vtemp_271[0U];
    __Vtemp_272[1U] = __Vtemp_271[1U];
    __Vtemp_272[2U] = __Vtemp_271[2U];
    __Vtemp_272[3U] = (0x003fffffU & __Vtemp_271[3U]);
    VL_DIVS_WWW(118, __Vtemp_273, __Vtemp_272, __VdfgRegularize_h6e95ff9d_0_4);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__zA = (((QData)((IData)(__Vtemp_273[1U])) 
                                                 << 0x00000020U) 
                                                | (QData)((IData)(__Vtemp_273[0U])));
    VL_EXTENDS_WQ(96,33, __Vtemp_277, vlSelfRef.ember_top__DOT__u_rtr__DOT__dx01);
    VL_MULS_WWW(96, __Vtemp_278, ember_top__DOT__u_rtr__DOT__u_setup__DOT__z20, __Vtemp_277);
    VL_EXTENDS_WQ(96,33, __Vtemp_279, ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx20_);
    VL_MULS_WWW(96, __Vtemp_280, ember_top__DOT__u_rtr__DOT__u_setup__DOT__z10, __Vtemp_279);
    VL_SUB_W(3, __Vtemp_281, __Vtemp_278, __Vtemp_280);
    VL_EXTENDS_WW(118,96, __Vtemp_282, __Vtemp_281);
    VL_SHIFTL_WWI(118,118,32, __Vtemp_283, __Vtemp_282, 0x00000016U);
    __Vtemp_284[0U] = __Vtemp_283[0U];
    __Vtemp_284[1U] = __Vtemp_283[1U];
    __Vtemp_284[2U] = __Vtemp_283[2U];
    __Vtemp_284[3U] = (0x003fffffU & __Vtemp_283[3U]);
    VL_DIVS_WWW(118, __Vtemp_285, __Vtemp_284, __VdfgRegularize_h6e95ff9d_0_4);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__zB = (((QData)((IData)(__Vtemp_285[1U])) 
                                                 << 0x00000020U) 
                                                | (QData)((IData)(__Vtemp_285[0U])));
    VL_EXTENDS_WQ(96,33, __Vtemp_289, ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy20_);
    VL_MULS_WWW(96, __Vtemp_290, ember_top__DOT__u_rtr__DOT__u_setup__DOT__u10, __Vtemp_289);
    VL_EXTENDS_WQ(96,33, __Vtemp_291, vlSelfRef.ember_top__DOT__u_rtr__DOT__dy01);
    VL_MULS_WWW(96, __Vtemp_292, ember_top__DOT__u_rtr__DOT__u_setup__DOT__u20, __Vtemp_291);
    VL_SUB_W(3, __Vtemp_293, __Vtemp_290, __Vtemp_292);
    VL_EXTENDS_WW(118,96, __Vtemp_294, __Vtemp_293);
    VL_SHIFTL_WWI(118,118,32, __Vtemp_295, __Vtemp_294, 0x00000016U);
    __Vtemp_296[0U] = __Vtemp_295[0U];
    __Vtemp_296[1U] = __Vtemp_295[1U];
    __Vtemp_296[2U] = __Vtemp_295[2U];
    __Vtemp_296[3U] = (0x003fffffU & __Vtemp_295[3U]);
    VL_DIVS_WWW(118, __Vtemp_297, __Vtemp_296, __VdfgRegularize_h6e95ff9d_0_4);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__uA = (((QData)((IData)(__Vtemp_297[1U])) 
                                                 << 0x00000020U) 
                                                | (QData)((IData)(__Vtemp_297[0U])));
    VL_EXTENDS_WQ(96,33, __Vtemp_301, vlSelfRef.ember_top__DOT__u_rtr__DOT__dx01);
    VL_MULS_WWW(96, __Vtemp_302, ember_top__DOT__u_rtr__DOT__u_setup__DOT__u20, __Vtemp_301);
    VL_EXTENDS_WQ(96,33, __Vtemp_303, ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx20_);
    VL_MULS_WWW(96, __Vtemp_304, ember_top__DOT__u_rtr__DOT__u_setup__DOT__u10, __Vtemp_303);
    VL_SUB_W(3, __Vtemp_305, __Vtemp_302, __Vtemp_304);
    VL_EXTENDS_WW(118,96, __Vtemp_306, __Vtemp_305);
    VL_SHIFTL_WWI(118,118,32, __Vtemp_307, __Vtemp_306, 0x00000016U);
    __Vtemp_308[0U] = __Vtemp_307[0U];
    __Vtemp_308[1U] = __Vtemp_307[1U];
    __Vtemp_308[2U] = __Vtemp_307[2U];
    __Vtemp_308[3U] = (0x003fffffU & __Vtemp_307[3U]);
    VL_DIVS_WWW(118, __Vtemp_309, __Vtemp_308, __VdfgRegularize_h6e95ff9d_0_4);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__uB = (((QData)((IData)(__Vtemp_309[1U])) 
                                                 << 0x00000020U) 
                                                | (QData)((IData)(__Vtemp_309[0U])));
    VL_EXTENDS_WQ(96,33, __Vtemp_313, ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy20_);
    VL_MULS_WWW(96, __Vtemp_314, ember_top__DOT__u_rtr__DOT__u_setup__DOT__v10, __Vtemp_313);
    VL_EXTENDS_WQ(96,33, __Vtemp_315, vlSelfRef.ember_top__DOT__u_rtr__DOT__dy01);
    VL_MULS_WWW(96, __Vtemp_316, ember_top__DOT__u_rtr__DOT__u_setup__DOT__v20, __Vtemp_315);
    VL_SUB_W(3, __Vtemp_317, __Vtemp_314, __Vtemp_316);
    VL_EXTENDS_WW(118,96, __Vtemp_318, __Vtemp_317);
    VL_SHIFTL_WWI(118,118,32, __Vtemp_319, __Vtemp_318, 0x00000016U);
    __Vtemp_320[0U] = __Vtemp_319[0U];
    __Vtemp_320[1U] = __Vtemp_319[1U];
    __Vtemp_320[2U] = __Vtemp_319[2U];
    __Vtemp_320[3U] = (0x003fffffU & __Vtemp_319[3U]);
    VL_DIVS_WWW(118, __Vtemp_321, __Vtemp_320, __VdfgRegularize_h6e95ff9d_0_4);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__vA = (((QData)((IData)(__Vtemp_321[1U])) 
                                                 << 0x00000020U) 
                                                | (QData)((IData)(__Vtemp_321[0U])));
    VL_EXTENDS_WQ(96,33, __Vtemp_325, vlSelfRef.ember_top__DOT__u_rtr__DOT__dx01);
    VL_MULS_WWW(96, __Vtemp_326, ember_top__DOT__u_rtr__DOT__u_setup__DOT__v20, __Vtemp_325);
    VL_EXTENDS_WQ(96,33, __Vtemp_327, ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx20_);
    VL_MULS_WWW(96, __Vtemp_328, ember_top__DOT__u_rtr__DOT__u_setup__DOT__v10, __Vtemp_327);
    VL_SUB_W(3, __Vtemp_329, __Vtemp_326, __Vtemp_328);
    VL_EXTENDS_WW(118,96, __Vtemp_330, __Vtemp_329);
    VL_SHIFTL_WWI(118,118,32, __Vtemp_331, __Vtemp_330, 0x00000016U);
    __Vtemp_332[0U] = __Vtemp_331[0U];
    __Vtemp_332[1U] = __Vtemp_331[1U];
    __Vtemp_332[2U] = __Vtemp_331[2U];
    __Vtemp_332[3U] = (0x003fffffU & __Vtemp_331[3U]);
    VL_DIVS_WWW(118, __Vtemp_333, __Vtemp_332, __VdfgRegularize_h6e95ff9d_0_4);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__vB = (((QData)((IData)(__Vtemp_333[1U])) 
                                                 << 0x00000020U) 
                                                | (QData)((IData)(__Vtemp_333[0U])));
}
