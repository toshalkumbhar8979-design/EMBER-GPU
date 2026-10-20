// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vember_top.h for the primary calling header

#include "Vember_top__pch.h"

void Vember_top___024root___nba_comb__TOP__0(Vember_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vember_top___024root___nba_comb__TOP__0\n"); );
    Vember_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    QData/*33:0*/ ember_top__DOT__h_r_s;
    ember_top__DOT__h_r_s = 0;
    // Body
    ember_top__DOT__h_r_s = ((1U == (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__rstate))
                              ? ((QData)((IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__rdata_q)) 
                                 << 2U) : vlSelfRef.ember_top__DOT__c_r);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__texel_byte 
        = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_vram__DOT__fpa2_rdata_q 
                          >> (0x00000018U & (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__tex_addr 
                                             << 3U))));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][0U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][0U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[0U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][1U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][1U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[0U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][2U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][2U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[0U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][3U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][3U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[0U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][4U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][4U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[0U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][5U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][5U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[0U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][6U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][6U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[0U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][7U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][7U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[0U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][8U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][8U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[0U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][9U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][9U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[0U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][10U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][10U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[0U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][11U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][11U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[0U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][12U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][12U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[0U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][13U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][13U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[0U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][14U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][14U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[0U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][15U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[0U][15U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[0U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][0U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][0U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[1U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][1U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][1U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[1U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][2U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][2U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[1U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][3U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][3U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[1U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][4U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][4U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[1U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][5U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][5U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[1U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][6U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][6U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[1U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][7U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][7U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[1U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][8U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][8U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[1U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][9U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][9U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[1U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][10U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][10U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[1U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][11U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][11U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[1U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][12U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][12U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[1U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][13U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][13U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[1U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][14U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][14U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[1U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][15U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[1U][15U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[1U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][0U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][0U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[2U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][1U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][1U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[2U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][2U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][2U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[2U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][3U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][3U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[2U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][4U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][4U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[2U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][5U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][5U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[2U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][6U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][6U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[2U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][7U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][7U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[2U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][8U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][8U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[2U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][9U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][9U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[2U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][10U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][10U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[2U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][11U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][11U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[2U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][12U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][12U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[2U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][13U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][13U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[2U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][14U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][14U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[2U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][15U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[2U][15U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[2U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][0U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][0U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[3U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][1U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][1U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[3U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][2U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][2U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[3U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][3U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][3U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[3U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][4U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][4U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[3U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][5U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][5U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[3U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][6U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][6U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[3U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][7U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][7U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[3U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][8U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][8U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[3U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][9U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][9U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[3U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][10U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][10U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[3U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][11U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][11U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[3U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][12U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][12U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[3U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][13U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][13U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[3U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][14U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][14U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[3U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][15U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[3U][15U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[3U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][0U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][0U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[4U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][1U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][1U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[4U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][2U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][2U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[4U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][3U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][3U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[4U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][4U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][4U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[4U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][5U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][5U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[4U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][6U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][6U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[4U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][7U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][7U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[4U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][8U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][8U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[4U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][9U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][9U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[4U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][10U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][10U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[4U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][11U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][11U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[4U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][12U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][12U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[4U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][13U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][13U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[4U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][14U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][14U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[4U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][15U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[4U][15U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[4U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][0U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][0U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[5U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][1U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][1U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[5U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][2U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][2U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[5U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][3U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][3U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[5U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][4U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][4U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[5U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][5U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][5U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[5U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][6U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][6U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[5U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][7U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][7U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[5U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][8U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][8U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[5U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][9U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][9U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[5U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][10U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][10U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[5U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][11U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][11U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[5U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][12U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][12U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[5U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][13U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][13U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[5U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][14U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][14U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[5U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][15U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[5U][15U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[5U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][0U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][0U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[6U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][1U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][1U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[6U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][2U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][2U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[6U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][3U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][3U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[6U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][4U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][4U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[6U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][5U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][5U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[6U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][6U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][6U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[6U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][7U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][7U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[6U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][8U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][8U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[6U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][9U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][9U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[6U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][10U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][10U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[6U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][11U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][11U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[6U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][12U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][12U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[6U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][13U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][13U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[6U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][14U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][14U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[6U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][15U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[6U][15U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[6U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][0U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][0U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[7U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][1U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][1U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[7U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][2U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][2U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[7U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][3U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][3U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[7U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][4U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][4U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[7U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][5U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][5U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[7U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][6U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][6U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[7U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][7U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][7U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[7U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][8U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][8U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[7U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][9U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][9U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[7U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][10U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][10U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[7U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][11U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][11U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[7U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][12U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][12U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[7U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][13U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][13U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[7U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][14U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][14U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[7U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][15U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[7U][15U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[7U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][0U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][0U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[8U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][1U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][1U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[8U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][2U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][2U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[8U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][3U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][3U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[8U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][4U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][4U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[8U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][5U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][5U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[8U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][6U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][6U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[8U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][7U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][7U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[8U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][8U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][8U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[8U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][9U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][9U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[8U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][10U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][10U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[8U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][11U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][11U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[8U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][12U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][12U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[8U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][13U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][13U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[8U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][14U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][14U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[8U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][15U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[8U][15U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[8U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][0U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][0U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[9U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][1U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][1U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[9U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][2U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][2U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[9U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][3U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][3U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[9U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][4U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][4U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[9U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][5U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][5U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[9U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][6U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][6U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[9U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][7U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][7U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[9U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][8U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][8U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[9U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][9U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][9U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[9U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][10U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][10U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[9U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][11U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][11U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[9U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][12U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][12U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[9U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][13U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][13U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[9U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][14U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][14U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[9U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][15U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[9U][15U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[9U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][0U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][0U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[10U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][1U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][1U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[10U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][2U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][2U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[10U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][3U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][3U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[10U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][4U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][4U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[10U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][5U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][5U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[10U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][6U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][6U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[10U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][7U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][7U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[10U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][8U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][8U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[10U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][9U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][9U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[10U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][10U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][10U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[10U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][11U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][11U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[10U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][12U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][12U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[10U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][13U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][13U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[10U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][14U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][14U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[10U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][15U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[10U][15U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[10U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][0U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][0U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[11U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][1U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][1U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[11U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][2U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][2U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[11U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][3U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][3U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[11U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][4U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][4U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[11U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][5U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][5U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[11U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][6U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][6U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[11U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][7U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][7U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[11U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][8U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][8U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[11U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][9U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][9U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[11U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][10U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][10U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[11U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][11U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][11U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[11U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][12U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][12U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[11U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][13U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][13U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[11U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][14U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][14U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[11U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][15U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[11U][15U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[11U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][0U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][0U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[12U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][1U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][1U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[12U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][2U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][2U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[12U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][3U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][3U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[12U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][4U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][4U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[12U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][5U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][5U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[12U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][6U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][6U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[12U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][7U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][7U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[12U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][8U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][8U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[12U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][9U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][9U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[12U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][10U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][10U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[12U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][11U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][11U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[12U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][12U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][12U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[12U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][13U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][13U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[12U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][14U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][14U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[12U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][15U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[12U][15U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[12U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][0U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][0U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[13U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][1U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][1U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[13U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][2U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][2U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[13U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][3U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][3U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[13U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][4U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][4U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[13U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][5U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][5U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[13U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][6U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][6U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[13U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][7U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][7U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[13U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][8U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][8U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[13U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][9U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][9U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[13U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][10U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][10U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[13U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][11U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][11U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[13U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][12U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][12U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[13U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][13U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][13U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[13U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][14U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][14U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[13U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][15U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[13U][15U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[13U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][0U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][0U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[14U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][1U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][1U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[14U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][2U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][2U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[14U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][3U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][3U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[14U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][4U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][4U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[14U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][5U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][5U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[14U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][6U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][6U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[14U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][7U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][7U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[14U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][8U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][8U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[14U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][9U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][9U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[14U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][10U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][10U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[14U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][11U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][11U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[14U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][12U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][12U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[14U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][13U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][13U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[14U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][14U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][14U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[14U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][15U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[14U][15U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[14U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][0U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][0U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[15U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][1U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][1U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[15U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][2U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][2U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[15U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][3U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][3U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[15U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][4U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][4U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[15U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][5U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][5U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[15U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][6U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][6U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[15U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][7U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][7U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[15U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][8U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][8U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[15U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][9U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][9U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[15U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][10U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][10U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[15U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][11U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][11U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[15U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][12U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][12U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[15U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][13U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][13U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[15U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][14U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][14U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[15U]));
    vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][15U] 
        = VL_MULS_III(32, VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs[15U][15U]), 
                      VL_EXTENDS_II(32,8, vlSelfRef.ember_top__DOT__u_tu__DOT__a_row_byte[15U]));
    vlSelfRef.h_rdata = (IData)((ember_top__DOT__h_r_s 
                                 >> 2U));
    vlSelfRef.h_rresp = (3U & (IData)(ember_top__DOT__h_r_s));
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[0U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][0U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[0U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][0U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[0U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][0U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[0U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][0U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[0U][4U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][0U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[0U][5U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][0U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[0U][6U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][0U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[0U][7U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][0U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[1U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][1U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[1U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][1U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[1U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][1U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[1U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][1U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[1U][4U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][1U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[1U][5U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][1U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[1U][6U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][1U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[1U][7U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][1U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[2U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][2U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[2U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][2U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[2U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][2U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[2U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][2U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[2U][4U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][2U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[2U][5U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][2U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[2U][6U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][2U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[2U][7U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][2U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[3U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][3U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[3U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][3U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[3U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][3U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[3U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][3U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[3U][4U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][3U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[3U][5U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][3U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[3U][6U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][3U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[3U][7U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][3U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[4U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][4U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][4U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[4U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][4U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][4U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[4U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][4U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][4U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[4U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][4U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][4U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[4U][4U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][4U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][4U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[4U][5U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][4U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][4U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[4U][6U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][4U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][4U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[4U][7U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][4U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][4U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[5U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][5U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][5U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[5U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][5U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][5U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[5U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][5U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][5U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[5U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][5U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][5U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[5U][4U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][5U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][5U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[5U][5U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][5U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][5U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[5U][6U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][5U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][5U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[5U][7U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][5U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][5U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[6U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][6U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][6U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[6U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][6U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][6U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[6U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][6U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][6U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[6U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][6U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][6U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[6U][4U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][6U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][6U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[6U][5U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][6U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][6U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[6U][6U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][6U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][6U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[6U][7U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][6U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][6U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[7U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][7U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][7U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[7U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][7U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][7U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[7U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][7U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][7U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[7U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][7U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][7U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[7U][4U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][7U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][7U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[7U][5U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][7U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][7U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[7U][6U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][7U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][7U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[7U][7U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][7U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][7U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[8U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][8U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][8U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[8U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][8U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][8U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[8U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][8U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][8U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[8U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][8U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][8U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[8U][4U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][8U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][8U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[8U][5U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][8U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][8U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[8U][6U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][8U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][8U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[8U][7U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][8U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][8U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[9U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][9U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][9U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[9U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][9U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][9U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[9U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][9U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][9U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[9U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][9U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][9U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[9U][4U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][9U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][9U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[9U][5U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][9U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][9U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[9U][6U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][9U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][9U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[9U][7U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][9U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][9U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[10U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][10U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][10U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[10U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][10U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][10U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[10U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][10U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][10U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[10U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][10U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][10U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[10U][4U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][10U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][10U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[10U][5U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][10U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][10U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[10U][6U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][10U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][10U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[10U][7U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][10U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][10U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[11U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][11U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][11U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[11U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][11U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][11U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[11U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][11U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][11U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[11U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][11U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][11U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[11U][4U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][11U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][11U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[11U][5U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][11U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][11U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[11U][6U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][11U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][11U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[11U][7U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][11U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][11U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[12U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][12U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][12U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[12U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][12U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][12U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[12U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][12U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][12U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[12U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][12U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][12U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[12U][4U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][12U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][12U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[12U][5U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][12U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][12U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[12U][6U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][12U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][12U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[12U][7U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][12U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][12U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[13U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][13U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][13U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[13U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][13U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][13U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[13U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][13U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][13U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[13U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][13U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][13U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[13U][4U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][13U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][13U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[13U][5U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][13U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][13U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[13U][6U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][13U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][13U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[13U][7U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][13U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][13U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[14U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][14U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][14U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[14U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][14U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][14U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[14U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][14U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][14U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[14U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][14U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][14U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[14U][4U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][14U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][14U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[14U][5U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][14U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][14U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[14U][6U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][14U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][14U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[14U][7U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][14U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][14U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[15U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[0U][15U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[1U][15U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[15U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[2U][15U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[3U][15U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[15U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[4U][15U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[5U][15U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[15U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[6U][15U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[7U][15U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[15U][4U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[8U][15U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[9U][15U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[15U][5U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[10U][15U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[11U][15U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[15U][6U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[12U][15U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[13U][15U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[15U][7U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__prod[14U][15U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__prod[15U][15U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[0U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[0U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[0U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[0U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[0U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[0U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[0U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[0U][4U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[0U][5U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[0U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[0U][6U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[0U][7U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[1U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[1U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[1U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[1U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[1U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[1U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[1U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[1U][4U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[1U][5U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[1U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[1U][6U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[1U][7U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[2U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[2U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[2U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[2U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[2U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[2U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[2U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[2U][4U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[2U][5U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[2U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[2U][6U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[2U][7U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[3U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[3U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[3U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[3U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[3U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[3U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[3U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[3U][4U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[3U][5U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[3U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[3U][6U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[3U][7U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[4U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[4U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[4U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[4U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[4U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[4U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[4U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[4U][4U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[4U][5U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[4U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[4U][6U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[4U][7U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[5U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[5U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[5U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[5U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[5U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[5U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[5U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[5U][4U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[5U][5U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[5U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[5U][6U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[5U][7U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[6U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[6U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[6U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[6U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[6U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[6U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[6U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[6U][4U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[6U][5U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[6U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[6U][6U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[6U][7U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[7U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[7U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[7U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[7U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[7U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[7U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[7U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[7U][4U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[7U][5U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[7U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[7U][6U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[7U][7U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[8U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[8U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[8U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[8U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[8U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[8U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[8U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[8U][4U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[8U][5U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[8U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[8U][6U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[8U][7U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[9U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[9U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[9U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[9U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[9U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[9U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[9U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[9U][4U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[9U][5U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[9U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[9U][6U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[9U][7U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[10U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[10U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[10U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[10U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[10U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[10U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[10U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[10U][4U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[10U][5U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[10U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[10U][6U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[10U][7U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[11U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[11U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[11U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[11U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[11U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[11U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[11U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[11U][4U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[11U][5U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[11U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[11U][6U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[11U][7U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[12U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[12U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[12U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[12U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[12U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[12U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[12U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[12U][4U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[12U][5U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[12U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[12U][6U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[12U][7U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[13U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[13U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[13U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[13U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[13U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[13U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[13U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[13U][4U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[13U][5U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[13U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[13U][6U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[13U][7U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[14U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[14U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[14U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[14U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[14U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[14U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[14U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[14U][4U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[14U][5U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[14U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[14U][6U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[14U][7U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[15U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[15U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[15U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[15U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[15U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[15U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[15U][2U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[15U][4U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[15U][5U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[15U][3U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[15U][6U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv1[15U][7U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[0U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[0U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[0U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[0U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[0U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[0U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[1U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[1U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[1U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[1U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[1U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[1U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[2U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[2U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[2U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[2U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[2U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[2U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[3U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[3U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[3U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[3U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[3U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[3U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[4U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[4U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[4U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[4U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[4U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[4U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[5U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[5U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[5U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[5U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[5U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[5U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[6U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[6U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[6U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[6U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[6U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[6U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[7U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[7U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[7U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[7U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[7U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[7U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[8U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[8U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[8U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[8U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[8U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[8U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[9U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[9U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[9U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[9U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[9U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[9U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[10U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[10U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[10U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[10U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[10U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[10U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[11U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[11U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[11U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[11U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[11U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[11U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[12U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[12U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[12U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[12U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[12U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[12U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[13U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[13U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[13U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[13U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[13U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[13U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[14U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[14U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[14U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[14U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[14U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[14U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[15U][0U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[15U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[15U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[15U][1U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[15U][2U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv2[15U][3U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__tree[0U] = 
        (vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[0U][0U] 
         + vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[0U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__tree[1U] = 
        (vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[1U][0U] 
         + vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[1U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__tree[2U] = 
        (vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[2U][0U] 
         + vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[2U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__tree[3U] = 
        (vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[3U][0U] 
         + vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[3U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__tree[4U] = 
        (vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[4U][0U] 
         + vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[4U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__tree[5U] = 
        (vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[5U][0U] 
         + vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[5U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__tree[6U] = 
        (vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[6U][0U] 
         + vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[6U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__tree[7U] = 
        (vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[7U][0U] 
         + vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[7U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__tree[8U] = 
        (vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[8U][0U] 
         + vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[8U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__tree[9U] = 
        (vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[9U][0U] 
         + vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[9U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__tree[10U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[10U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[10U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__tree[11U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[11U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[11U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__tree[12U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[12U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[12U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__tree[13U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[13U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[13U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__tree[14U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[14U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[14U][1U]);
    vlSelfRef.ember_top__DOT__u_tu__DOT__tree[15U] 
        = (vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[15U][0U] 
           + vlSelfRef.ember_top__DOT__u_tu__DOT__lv3[15U][1U]);
}

void Vember_top___024root___nba_sequent__TOP__4(Vember_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vember_top___024root___nba_sequent__TOP__4\n"); );
    Vember_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_gsx__DOT__col__v0) {
        vlSelfRef.ember_top__DOT__u_gsx__DOT__col[vlSelfRef.__VdlyDim0__ember_top__DOT__u_gsx__DOT__col__v0] 
            = vlSelfRef.__VdlyVal__ember_top__DOT__u_gsx__DOT__col__v0;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_gsx__DOT__vtx__v0) {
        vlSelfRef.ember_top__DOT__u_gsx__DOT__vtx[vlSelfRef.__VdlyDim0__ember_top__DOT__u_gsx__DOT__vtx__v0] 
            = vlSelfRef.__VdlyVal__ember_top__DOT__u_gsx__DOT__vtx__v0;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_gsx__DOT__mata__v0) {
        vlSelfRef.ember_top__DOT__u_gsx__DOT__mata[vlSelfRef.__VdlyDim0__ember_top__DOT__u_gsx__DOT__mata__v0] 
            = vlSelfRef.__VdlyVal__ember_top__DOT__u_gsx__DOT__mata__v0;
    }
    vlSelfRef.ember_top__DOT__u_vram__DOT__ixa_rdata_q 
        = vlSelfRef.__Vdly__ember_top__DOT__u_vram__DOT__ixa_rdata_q;
    vlSelfRef.ember_top__DOT__u_vram__DOT__cxa_rdata_q 
        = vlSelfRef.__Vdly__ember_top__DOT__u_vram__DOT__cxa_rdata_q;
    vlSelfRef.ember_top__DOT__u_vram__DOT__tua_rdata_q 
        = vlSelfRef.__Vdly__ember_top__DOT__u_vram__DOT__tua_rdata_q;
    if (((IData)(vlSelfRef.ember_top__DOT__rtr_busy)
          ? ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__in_fetch)
              ? (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__fetch_req)
              : (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_req))
          : ((IData)(vlSelfRef.ember_top__DOT__blit_own) 
             & (IData)(vlSelfRef.ember_top__DOT__blit_fpa_req)))) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_rdata_q 
            = vlSelfRef.ember_top__DOT__u_vram__DOT__ram
            [vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_widx];
    }
    if (vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__wr_fire) {
        vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wr_en = 1U;
        vlSelfRef.ember_top__DOT__u_cp__DOT__reg_be 
            = (0x0000000fU & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__w_q));
    } else {
        vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wr_en = 0U;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v0) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v0] 
            = ((0xffffff00U & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v0]) 
               | (IData)(vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v0));
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v1) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v1] 
            = ((0xffff00ffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v1]) 
               | ((IData)(vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v1) 
                  << 8U));
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v2) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v2] 
            = ((0xff00ffffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v2]) 
               | ((IData)(vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v2) 
                  << 0x00000010U));
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v3) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v3] 
            = ((0x00ffffffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v3]) 
               | ((IData)(vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v3) 
                  << 0x00000018U));
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v4) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v4] 
            = ((0xffffff00U & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v4]) 
               | (IData)(vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v4));
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v5) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v5] 
            = ((0xffff00ffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v5]) 
               | ((IData)(vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v5) 
                  << 8U));
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v6) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v6] 
            = ((0xff00ffffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v6]) 
               | ((IData)(vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v6) 
                  << 0x00000010U));
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v7) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v7] 
            = ((0x00ffffffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v7]) 
               | ((IData)(vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v7) 
                  << 0x00000018U));
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v8) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v8] 
            = ((0xffffff00U & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v8]) 
               | (IData)(vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v8));
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v9) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v9] 
            = ((0xffff00ffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v9]) 
               | ((IData)(vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v9) 
                  << 8U));
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v10) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v10] 
            = ((0xff00ffffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v10]) 
               | ((IData)(vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v10) 
                  << 0x00000010U));
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v11) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v11] 
            = ((0x00ffffffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v11]) 
               | ((IData)(vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v11) 
                  << 0x00000018U));
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v12) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v12] 
            = ((0xffffff00U & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v12]) 
               | (IData)(vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v12));
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v13) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v13] 
            = ((0xffff00ffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v13]) 
               | ((IData)(vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v13) 
                  << 8U));
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v14) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v14] 
            = ((0xff00ffffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v14]) 
               | ((IData)(vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v14) 
                  << 0x00000010U));
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v15) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v15] 
            = ((0x00ffffffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v15]) 
               | ((IData)(vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v15) 
                  << 0x00000018U));
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v16) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v16] 
            = ((0xffffff00U & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v16]) 
               | (IData)(vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v16));
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v17) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v17] 
            = ((0xffff00ffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v17]) 
               | ((IData)(vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v17) 
                  << 8U));
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v18) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v18] 
            = ((0xff00ffffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v18]) 
               | ((IData)(vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v18) 
                  << 0x00000010U));
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v19) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v19] 
            = ((0x00ffffffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v19]) 
               | ((IData)(vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v19) 
                  << 0x00000018U));
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v20) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v20] 
            = ((0xffffff00U & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v20]) 
               | (IData)(vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v20));
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v21) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v21] 
            = ((0xffff00ffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v21]) 
               | ((IData)(vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v21) 
                  << 8U));
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v22) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v22] 
            = ((0xff00ffffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v22]) 
               | ((IData)(vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v22) 
                  << 0x00000010U));
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_vram__DOT__ram__v23) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v23] 
            = ((0x00ffffffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [vlSelfRef.__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v23]) 
               | ((IData)(vlSelfRef.__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v23) 
                  << 0x00000018U));
    }
}

void Vember_top___024root___nba_sequent__TOP__5(Vember_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vember_top___024root___nba_sequent__TOP__5\n"); );
    Vember_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ember_top__DOT__u_rtr__DOT__fetch_req 
        = vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__fetch_req;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_req 
        = vlSelfRef.__Vdly__ember_top__DOT__u_rtr__DOT__scan_fpa_req;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__in_fetch 
        = ((1U == (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__fst)) 
           | (2U == (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__fst)));
    vlSelfRef.ember_top__DOT__rtr_busy = ((0U != (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__fst)) 
                                          | (0U != (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__st)));
    if (vlSelfRef.rst_n) {
        vlSelfRef.ember_top__DOT__blit_fpa_req = 0U;
        vlSelfRef.ember_top__DOT__blit_fpa_we = 0U;
        if ((8U & (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__st))) {
            vlSelfRef.__Vdly__ember_top__DOT__u_blit__DOT__st = 0U;
        } else if ((4U & (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__st))) {
            if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__st))) {
                if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__st))) {
                    if (((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__sx) 
                         == (0x000000ffU & ((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__w_q) 
                                            - (IData)(1U))))) {
                        vlSelfRef.__Vdly__ember_top__DOT__u_blit__DOT__sx = 0U;
                        if (((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__sy) 
                             == (0x000000ffU & ((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__h_q) 
                                                - (IData)(1U))))) {
                            vlSelfRef.__Vdly__ember_top__DOT__u_blit__DOT__st = 8U;
                        } else {
                            vlSelfRef.__Vdly__ember_top__DOT__u_blit__DOT__sy 
                                = (0x000000ffU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__sy)));
                            vlSelfRef.ember_top__DOT__u_blit__DOT__by 
                                = (0x0001ffffU & ((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__scale2_q)
                                                   ? 
                                                  ((IData)(2U) 
                                                   + vlSelfRef.ember_top__DOT__u_blit__DOT__by)
                                                   : 
                                                  ((IData)(1U) 
                                                   + vlSelfRef.ember_top__DOT__u_blit__DOT__by)));
                            vlSelfRef.__Vdly__ember_top__DOT__u_blit__DOT__bx = 0U;
                            vlSelfRef.__Vdly__ember_top__DOT__u_blit__DOT__st = 1U;
                        }
                    } else {
                        vlSelfRef.__Vdly__ember_top__DOT__u_blit__DOT__sx 
                            = (0x000000ffU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__sx)));
                        vlSelfRef.__Vdly__ember_top__DOT__u_blit__DOT__bx 
                            = (0x0001ffffU & ((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__scale2_q)
                                               ? ((IData)(2U) 
                                                  + vlSelfRef.ember_top__DOT__u_blit__DOT__bx)
                                               : ((IData)(1U) 
                                                  + vlSelfRef.ember_top__DOT__u_blit__DOT__bx)));
                        vlSelfRef.__Vdly__ember_top__DOT__u_blit__DOT__st = 1U;
                    }
                } else {
                    if ((1U & (~ (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__skip)))) {
                        vlSelfRef.ember_top__DOT__blit_fpa_we = 1U;
                        vlSelfRef.ember_top__DOT__blit_fpa_addr 
                            = (0xfffffffcU & ((IData)(0x00001282U) 
                                              + vlSelfRef.ember_top__DOT__u_blit__DOT____VdfgRegularize_hffd9f26e_0_0));
                        vlSelfRef.ember_top__DOT__blit_fpa_be 
                            = ((2U & ((IData)(0x00001282U) 
                                      + vlSelfRef.ember_top__DOT__u_blit__DOT____VdfgRegularize_hffd9f26e_0_0))
                                ? 0x0cU : 3U);
                        vlSelfRef.ember_top__DOT__blit_fpa_wdata 
                            = (((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__pix) 
                                << 0x00000010U) | (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__pix));
                    }
                    vlSelfRef.__Vdly__ember_top__DOT__u_blit__DOT__st = 7U;
                }
            } else if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__st))) {
                if ((1U & (~ (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__skip)))) {
                    vlSelfRef.ember_top__DOT__blit_fpa_we = 1U;
                    vlSelfRef.ember_top__DOT__blit_fpa_addr 
                        = (0xfffffffcU & ((IData)(0x00001280U) 
                                          + vlSelfRef.ember_top__DOT__u_blit__DOT____VdfgRegularize_hffd9f26e_0_0));
                    vlSelfRef.ember_top__DOT__blit_fpa_be 
                        = ((2U & ((IData)(0x00001280U) 
                                  + vlSelfRef.ember_top__DOT__u_blit__DOT____VdfgRegularize_hffd9f26e_0_0))
                            ? 0x0cU : 3U);
                    vlSelfRef.ember_top__DOT__blit_fpa_wdata 
                        = (((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__pix) 
                            << 0x00000010U) | (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__pix));
                }
                vlSelfRef.__Vdly__ember_top__DOT__u_blit__DOT__st = 6U;
            } else {
                if ((1U & (~ (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__skip)))) {
                    vlSelfRef.ember_top__DOT__blit_fpa_we = 1U;
                    vlSelfRef.ember_top__DOT__blit_fpa_addr 
                        = (0xfffffffcU & ((IData)(0x00001002U) 
                                          + vlSelfRef.ember_top__DOT__u_blit__DOT____VdfgRegularize_hffd9f26e_0_0));
                    vlSelfRef.ember_top__DOT__blit_fpa_be 
                        = ((2U & ((IData)(0x00001002U) 
                                  + vlSelfRef.ember_top__DOT__u_blit__DOT____VdfgRegularize_hffd9f26e_0_0))
                            ? 0x0cU : 3U);
                    vlSelfRef.ember_top__DOT__blit_fpa_wdata 
                        = (((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__pix) 
                            << 0x00000010U) | (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__pix));
                }
                vlSelfRef.__Vdly__ember_top__DOT__u_blit__DOT__st = 5U;
            }
        } else if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__st))) {
            if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__st))) {
                vlSelfRef.ember_top__DOT__u_blit__DOT__pix 
                    = vlSelfRef.ember_top__DOT__u_blit__DOT__rdata_lane;
                vlSelfRef.ember_top__DOT__u_blit__DOT__skip 
                    = vlSelfRef.ember_top__DOT__u_blit__DOT__skip_c;
                vlSelfRef.ember_top__DOT__blit_fpa_we 
                    = (1U & (~ (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__skip_c)));
                vlSelfRef.ember_top__DOT__blit_fpa_addr 
                    = (0xfffffffcU & ((IData)(0x00001000U) 
                                      + vlSelfRef.ember_top__DOT__u_blit__DOT____VdfgRegularize_hffd9f26e_0_0));
                vlSelfRef.ember_top__DOT__blit_fpa_be 
                    = ((2U & ((IData)(0x00001000U) 
                              + vlSelfRef.ember_top__DOT__u_blit__DOT____VdfgRegularize_hffd9f26e_0_0))
                        ? 0x0cU : 3U);
                vlSelfRef.ember_top__DOT__blit_fpa_wdata 
                    = (((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__rdata_lane) 
                        << 0x00000010U) | (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__rdata_lane));
                vlSelfRef.__Vdly__ember_top__DOT__u_blit__DOT__st 
                    = ((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__scale2_q)
                        ? 4U : 7U);
            } else {
                vlSelfRef.__Vdly__ember_top__DOT__u_blit__DOT__st = 3U;
            }
        } else if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__st))) {
            vlSelfRef.ember_top__DOT__u_blit__DOT__saddr_q 
                = ((IData)(0x00001000U) + ((vlSelfRef.ember_top__DOT__u_blit__DOT__src_off_q 
                                            + VL_SHIFTL_III(32,32,32, 
                                                            ((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__sy) 
                                                             * (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__w_q)), 1U)) 
                                           + VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__sx), 1U)));
            vlSelfRef.ember_top__DOT__blit_fpa_req = 1U;
            vlSelfRef.__Vdly__ember_top__DOT__u_blit__DOT__st = 2U;
            vlSelfRef.ember_top__DOT__blit_fpa_addr 
                = (0xfffffffcU & ((IData)(0x00001000U) 
                                  + ((vlSelfRef.ember_top__DOT__u_blit__DOT__src_off_q 
                                      + VL_SHIFTL_III(32,32,32, 
                                                      ((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__sy) 
                                                       * (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__w_q)), 1U)) 
                                     + VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__sx), 1U))));
        } else if (((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_0) 
                    & ((0x0034U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
                       & vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata))) {
            vlSelfRef.__Vdly__ember_top__DOT__u_blit__DOT__sy = 0U;
            vlSelfRef.ember_top__DOT__u_blit__DOT__by = 0U;
            vlSelfRef.__Vdly__ember_top__DOT__u_blit__DOT__sx = 0U;
            vlSelfRef.__Vdly__ember_top__DOT__u_blit__DOT__bx = 0U;
            vlSelfRef.ember_top__DOT__u_blit__DOT__skip = 0U;
            vlSelfRef.__Vdly__ember_top__DOT__u_blit__DOT__st = 1U;
        }
        if (vlSelfRef.ember_top__DOT__blit_csr_we) {
            if ((2U & (IData)(vlSelfRef.ember_top__DOT__blit_csr_addr))) {
                if ((1U & (IData)(vlSelfRef.ember_top__DOT__blit_csr_addr))) {
                    vlSelfRef.ember_top__DOT__u_blit__DOT__w_q 
                        = (0x000000ffU & vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata);
                    vlSelfRef.ember_top__DOT__u_blit__DOT__h_q 
                        = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata 
                                          >> 0x10U));
                }
                if ((1U & (~ (IData)(vlSelfRef.ember_top__DOT__blit_csr_addr)))) {
                    vlSelfRef.ember_top__DOT__u_blit__DOT__src_off_q 
                        = vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata;
                }
            }
            if ((1U & (~ ((IData)(vlSelfRef.ember_top__DOT__blit_csr_addr) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelfRef.ember_top__DOT__blit_csr_addr)))) {
                    vlSelfRef.ember_top__DOT__u_blit__DOT__scale2_q 
                        = (1U & (vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata 
                                 >> 0x1eU));
                }
            }
        }
    } else {
        vlSelfRef.__Vdly__ember_top__DOT__u_blit__DOT__sy = 0U;
        vlSelfRef.ember_top__DOT__u_blit__DOT__by = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_blit__DOT__st = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_blit__DOT__sx = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_blit__DOT__bx = 0U;
        vlSelfRef.ember_top__DOT__u_blit__DOT__saddr_q = 0U;
        vlSelfRef.ember_top__DOT__u_blit__DOT__pix = 0U;
        vlSelfRef.ember_top__DOT__u_blit__DOT__skip = 0U;
        vlSelfRef.ember_top__DOT__blit_fpa_req = 0U;
        vlSelfRef.ember_top__DOT__blit_fpa_addr = 0U;
        vlSelfRef.ember_top__DOT__blit_fpa_we = 0U;
        vlSelfRef.ember_top__DOT__blit_fpa_wdata = 0U;
        vlSelfRef.ember_top__DOT__blit_fpa_be = 0U;
        vlSelfRef.ember_top__DOT__u_blit__DOT__w_q = 0U;
        vlSelfRef.ember_top__DOT__u_blit__DOT__h_q = 0U;
        vlSelfRef.ember_top__DOT__u_blit__DOT__scale2_q = 0U;
        vlSelfRef.ember_top__DOT__u_blit__DOT__src_off_q = 0U;
    }
    vlSelfRef.ember_top__DOT__u_blit__DOT__sx = vlSelfRef.__Vdly__ember_top__DOT__u_blit__DOT__sx;
    vlSelfRef.ember_top__DOT__u_blit__DOT__sy = vlSelfRef.__Vdly__ember_top__DOT__u_blit__DOT__sy;
    vlSelfRef.ember_top__DOT__u_blit__DOT__bx = vlSelfRef.__Vdly__ember_top__DOT__u_blit__DOT__bx;
    vlSelfRef.ember_top__DOT__u_blit__DOT__st = vlSelfRef.__Vdly__ember_top__DOT__u_blit__DOT__st;
    vlSelfRef.ember_top__DOT__u_blit__DOT____VdfgRegularize_hffd9f26e_0_0 
        = (vlSelfRef.ember_top__DOT__u_blit__DOT__dst_off_q 
           + (((IData)(0x00000280U) * vlSelfRef.ember_top__DOT__u_blit__DOT__by) 
              + VL_SHIFTL_III(32,32,32, (0x000001ffU 
                                         & vlSelfRef.ember_top__DOT__u_blit__DOT__bx), 1U)));
    vlSelfRef.ember_top__DOT__blit_own = ((~ (IData)(vlSelfRef.ember_top__DOT__rtr_busy)) 
                                          & (0U != (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__st)));
    if (vlSelfRef.ember_top__DOT__rtr_busy) {
        if (vlSelfRef.ember_top__DOT__u_rtr__DOT__in_fetch) {
            vlSelfRef.ember_top__DOT__fpa_wdata = 0U;
            vlSelfRef.ember_top__DOT__fpa_be = 0x0fU;
        } else {
            vlSelfRef.ember_top__DOT__fpa_wdata = vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_wdata;
            vlSelfRef.ember_top__DOT__fpa_be = vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_be;
        }
    } else if (vlSelfRef.ember_top__DOT__blit_own) {
        vlSelfRef.ember_top__DOT__fpa_wdata = vlSelfRef.ember_top__DOT__blit_fpa_wdata;
        vlSelfRef.ember_top__DOT__fpa_be = vlSelfRef.ember_top__DOT__blit_fpa_be;
    } else {
        vlSelfRef.ember_top__DOT__fpa_wdata = 0U;
        vlSelfRef.ember_top__DOT__fpa_be = 0U;
    }
    vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_widx 
        = (0x0001ffffU & ((((IData)(vlSelfRef.ember_top__DOT__rtr_busy)
                             ? ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__in_fetch)
                                 ? vlSelfRef.ember_top__DOT__u_rtr__DOT__fetch_addr
                                 : vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_addr)
                             : ((IData)(vlSelfRef.ember_top__DOT__blit_own)
                                 ? vlSelfRef.ember_top__DOT__blit_fpa_addr
                                 : 0U)) - (IData)(0x00001000U)) 
                          >> 2U));
}

void Vember_top___024root___nba_sequent__TOP__6(Vember_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vember_top___024root___nba_sequent__TOP__6\n"); );
    Vember_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_3;
    ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_3 = 0;
    CData/*0:0*/ ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_6;
    ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_6 = 0;
    CData/*0:0*/ ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_10;
    ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_10 = 0;
    // Body
    vlSelfRef.ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_0 
        = ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wr_en) 
           & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_be));
    if (vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__wr_fire) {
        vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr 
            = (0x00000fffU & (IData)((vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__aw_q 
                                      >> 3U)));
        vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata 
            = (IData)((vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__w_q 
                       >> 4U));
    }
    ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_3 
        = ((0x002cU == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
           | (0x0030U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)));
    ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_6 
        = ((0x0040U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
           | (0x0048U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)));
    ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_10 
        = ((0x0060U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
           | (0x0064U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)));
    vlSelfRef.ember_top__DOT__core_csr_we = ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_0) 
                                             & ((0x004cU 
                                                 == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
                                                | (0x0050U 
                                                   == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr))));
    vlSelfRef.ember_top__DOT__blit_csr_addr = (((IData)(ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_3) 
                                                << 1U) 
                                               | ((0x0028U 
                                                   == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
                                                  | (0x0030U 
                                                     == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr))));
    vlSelfRef.ember_top__DOT__blit_csr_we = ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_0) 
                                             & ((0x0024U 
                                                 == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
                                                | ((0x0028U 
                                                    == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
                                                   | (IData)(ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_3))));
    vlSelfRef.ember_top__DOT__gsx_csr_addr = (((IData)(ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_6) 
                                               << 1U) 
                                              | ((0x003cU 
                                                  == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
                                                 | (0x0048U 
                                                    == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr))));
    vlSelfRef.ember_top__DOT__gsx_csr_we = ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_0) 
                                            & ((0x0038U 
                                                == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
                                               | ((0x003cU 
                                                   == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
                                                  | (IData)(ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_6))));
    vlSelfRef.ember_top__DOT__tu_csr_addr = (((IData)(ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_10) 
                                              << 1U) 
                                             | ((0x005cU 
                                                 == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
                                                | (0x0064U 
                                                   == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr))));
    vlSelfRef.ember_top__DOT__tu_csr_we = ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_0) 
                                           & ((0x0058U 
                                               == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
                                              | ((0x005cU 
                                                  == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
                                                 | (IData)(ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_10))));
    vlSelfRef.ember_top__DOT__u_gsx__DOT__cfg_we = 
        ((IData)(vlSelfRef.ember_top__DOT__gsx_csr_we) 
         & (3U == (IData)(vlSelfRef.ember_top__DOT__gsx_csr_addr)));
    vlSelfRef.ember_top__DOT__u_tu__DOT____VdfgRegularize_h0ebfa33a_0_0 
        = ((IData)(vlSelfRef.ember_top__DOT__tu_csr_we) 
           & (3U == (IData)(vlSelfRef.ember_top__DOT__tu_csr_addr)));
    vlSelfRef.ember_top__DOT__u_gsx__DOT__cfg_mode_we 
        = ((~ (vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata 
               >> 0x0000001fU)) & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__cfg_we));
    vlSelfRef.ember_top__DOT__u_tu__DOT__cfg2_dim_we 
        = ((IData)(vlSelfRef.ember_top__DOT__u_tu__DOT____VdfgRegularize_h0ebfa33a_0_0) 
           & (0U == (vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata 
                     >> 0x0000001eU)));
    vlSelfRef.ember_top__DOT__u_tu__DOT__cfg2_q_we 
        = ((IData)(vlSelfRef.ember_top__DOT__u_tu__DOT____VdfgRegularize_h0ebfa33a_0_0) 
           & (2U == (vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata 
                     >> 0x0000001eU)));
}

void Vember_top___024root___nba_comb__TOP__1(Vember_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vember_top___024root___nba_comb__TOP__1\n"); );
    Vember_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ember_top__DOT__u_blit__DOT__rdata_lane 
        = (0x0000ffffU & ((2U & vlSelfRef.ember_top__DOT__u_blit__DOT__saddr_q)
                           ? (vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_rdata_q 
                              >> 0x00000010U) : vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_rdata_q));
    vlSelfRef.ember_top__DOT__u_blit__DOT__skip_c = 
        ((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__key_en_q) 
         & ((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__key_color_q) 
            == (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__rdata_lane)));
}

void Vember_top___024root___nba_sequent__TOP__7(Vember_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vember_top___024root___nba_sequent__TOP__7\n"); );
    Vember_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__wr_fire 
        = ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__aw_v) 
           & ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__w_v) 
              & ((~ (IData)(vlSelfRef.ember_top__DOT__c_bvalid)) 
                 | (IData)(vlSelfRef.ember_top__DOT__c_bready))));
    if (vlSelfRef.rst_n) {
        if (((IData)(vlSelfRef.ember_top__DOT__c_awvalid) 
             & (IData)(vlSelfRef.ember_top__DOT__c_awready))) {
            vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__aw_q 
                = ((QData)((IData)(vlSelfRef.h_awaddr)) 
                   << 3U);
        }
        if (((IData)(vlSelfRef.ember_top__DOT__c_wvalid) 
             & (IData)(vlSelfRef.ember_top__DOT__c_wready))) {
            vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__w_q 
                = vlSelfRef.ember_top__DOT__h_w_s;
        }
    } else {
        vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__aw_q = 0ULL;
        vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__w_q = 0ULL;
    }
    vlSelfRef.ember_top__DOT__c_awready = (1U & ((~ (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__aw_v)) 
                                                 | (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__wr_fire)));
    vlSelfRef.ember_top__DOT__c_wready = (1U & ((~ (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__w_v)) 
                                                | (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__wr_fire)));
    if ((0U == (vlSelfRef.h_awaddr >> 0x0000000cU))) {
        vlSelfRef.h_awready = vlSelfRef.ember_top__DOT__c_awready;
        vlSelfRef.h_wready = vlSelfRef.ember_top__DOT__c_wready;
    } else {
        vlSelfRef.h_awready = ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_h) 
                               & (IData)(vlSelfRef.ember_top__DOT__v_awready));
        vlSelfRef.h_wready = ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_h) 
                              & (IData)(vlSelfRef.ember_top__DOT__v_wready));
    }
}

void Vember_top___024root___nba_sequent__TOP__0(Vember_top___024root* vlSelf);
void Vember_top___024root___nba_sequent__TOP__1(Vember_top___024root* vlSelf);
void Vember_top___024root___nba_sequent__TOP__2(Vember_top___024root* vlSelf);
void Vember_top___024root___nba_sequent__TOP__3(Vember_top___024root* vlSelf);

void Vember_top___024root___eval_nba(Vember_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vember_top___024root___eval_nba\n"); );
    Vember_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __Vinline__nba_sequent__TOP__6_ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_3;
    __Vinline__nba_sequent__TOP__6_ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_3 = 0;
    CData/*0:0*/ __Vinline__nba_sequent__TOP__6_ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_6;
    __Vinline__nba_sequent__TOP__6_ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_6 = 0;
    CData/*0:0*/ __Vinline__nba_sequent__TOP__6_ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_10;
    __Vinline__nba_sequent__TOP__6_ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_10 = 0;
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vember_top___024root___nba_sequent__TOP__0(vlSelf);
        Vember_top___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vember_top___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vember_top___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vember_top___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vember_top___024root___nba_sequent__TOP__4(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vember_top___024root___nba_sequent__TOP__5(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_0 
            = ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wr_en) 
               & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_be));
        if (vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__wr_fire) {
            vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr 
                = (0x00000fffU & (IData)((vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__aw_q 
                                          >> 3U)));
            vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata 
                = (IData)((vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__w_q 
                           >> 4U));
        }
        __Vinline__nba_sequent__TOP__6_ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_3 
            = ((0x002cU == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
               | (0x0030U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)));
        __Vinline__nba_sequent__TOP__6_ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_6 
            = ((0x0040U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
               | (0x0048U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)));
        __Vinline__nba_sequent__TOP__6_ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_10 
            = ((0x0060U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
               | (0x0064U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)));
        vlSelfRef.ember_top__DOT__core_csr_we = ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_0) 
                                                 & ((0x004cU 
                                                     == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
                                                    | (0x0050U 
                                                       == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr))));
        vlSelfRef.ember_top__DOT__blit_csr_addr = (
                                                   ((IData)(__Vinline__nba_sequent__TOP__6_ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_3) 
                                                    << 1U) 
                                                   | ((0x0028U 
                                                       == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
                                                      | (0x0030U 
                                                         == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr))));
        vlSelfRef.ember_top__DOT__blit_csr_we = ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_0) 
                                                 & ((0x0024U 
                                                     == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
                                                    | ((0x0028U 
                                                        == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
                                                       | __Vinline__nba_sequent__TOP__6_ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_3)));
        vlSelfRef.ember_top__DOT__gsx_csr_addr = (((IData)(__Vinline__nba_sequent__TOP__6_ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_6) 
                                                   << 1U) 
                                                  | ((0x003cU 
                                                      == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
                                                     | (0x0048U 
                                                        == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr))));
        vlSelfRef.ember_top__DOT__gsx_csr_we = ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_0) 
                                                & ((0x0038U 
                                                    == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
                                                   | ((0x003cU 
                                                       == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
                                                      | __Vinline__nba_sequent__TOP__6_ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_6)));
        vlSelfRef.ember_top__DOT__tu_csr_addr = (((IData)(__Vinline__nba_sequent__TOP__6_ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_10) 
                                                  << 1U) 
                                                 | ((0x005cU 
                                                     == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
                                                    | (0x0064U 
                                                       == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr))));
        vlSelfRef.ember_top__DOT__tu_csr_we = ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_0) 
                                               & ((0x0058U 
                                                   == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
                                                  | ((0x005cU 
                                                      == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
                                                     | __Vinline__nba_sequent__TOP__6_ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_10)));
        vlSelfRef.ember_top__DOT__u_gsx__DOT__cfg_we 
            = ((IData)(vlSelfRef.ember_top__DOT__gsx_csr_we) 
               & (3U == (IData)(vlSelfRef.ember_top__DOT__gsx_csr_addr)));
        vlSelfRef.ember_top__DOT__u_tu__DOT____VdfgRegularize_h0ebfa33a_0_0 
            = ((IData)(vlSelfRef.ember_top__DOT__tu_csr_we) 
               & (3U == (IData)(vlSelfRef.ember_top__DOT__tu_csr_addr)));
        vlSelfRef.ember_top__DOT__u_gsx__DOT__cfg_mode_we 
            = ((~ (vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata 
                   >> 0x0000001fU)) & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__cfg_we));
        vlSelfRef.ember_top__DOT__u_tu__DOT__cfg2_dim_we 
            = ((IData)(vlSelfRef.ember_top__DOT__u_tu__DOT____VdfgRegularize_h0ebfa33a_0_0) 
               & (0U == (vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata 
                         >> 0x0000001eU)));
        vlSelfRef.ember_top__DOT__u_tu__DOT__cfg2_q_we 
            = ((IData)(vlSelfRef.ember_top__DOT__u_tu__DOT____VdfgRegularize_h0ebfa33a_0_0) 
               & (2U == (vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata 
                         >> 0x0000001eU)));
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.ember_top__DOT__u_blit__DOT__rdata_lane 
            = (0x0000ffffU & ((2U & vlSelfRef.ember_top__DOT__u_blit__DOT__saddr_q)
                               ? (vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_rdata_q 
                                  >> 0x00000010U) : vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_rdata_q));
        vlSelfRef.ember_top__DOT__u_blit__DOT__skip_c 
            = ((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__key_en_q) 
               & ((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__key_color_q) 
                  == (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__rdata_lane)));
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__wr_fire 
            = ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__aw_v) 
               & ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__w_v) 
                  & ((~ (IData)(vlSelfRef.ember_top__DOT__c_bvalid)) 
                     | (IData)(vlSelfRef.ember_top__DOT__c_bready))));
        if (vlSelfRef.rst_n) {
            if (((IData)(vlSelfRef.ember_top__DOT__c_awvalid) 
                 & (IData)(vlSelfRef.ember_top__DOT__c_awready))) {
                vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__aw_q 
                    = ((QData)((IData)(vlSelfRef.h_awaddr)) 
                       << 3U);
            }
            if (((IData)(vlSelfRef.ember_top__DOT__c_wvalid) 
                 & (IData)(vlSelfRef.ember_top__DOT__c_wready))) {
                vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__w_q 
                    = vlSelfRef.ember_top__DOT__h_w_s;
            }
        } else {
            vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__aw_q = 0ULL;
            vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__w_q = 0ULL;
        }
        vlSelfRef.ember_top__DOT__c_awready = (1U & 
                                               ((~ (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__aw_v)) 
                                                | (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__wr_fire)));
        vlSelfRef.ember_top__DOT__c_wready = (1U & 
                                              ((~ (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__w_v)) 
                                               | (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__wr_fire)));
        if ((0U == (vlSelfRef.h_awaddr >> 0x0000000cU))) {
            vlSelfRef.h_awready = vlSelfRef.ember_top__DOT__c_awready;
            vlSelfRef.h_wready = vlSelfRef.ember_top__DOT__c_wready;
        } else {
            vlSelfRef.h_awready = ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_h) 
                                   & (IData)(vlSelfRef.ember_top__DOT__v_awready));
            vlSelfRef.h_wready = ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_h) 
                                  & (IData)(vlSelfRef.ember_top__DOT__v_wready));
        }
    }
}

void Vember_top___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vember_top___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

void Vember_top___024root___eval_triggers_vec__act(Vember_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vember_top___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vember_top___024root___eval_phase__act(Vember_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vember_top___024root___eval_phase__act\n"); );
    Vember_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vember_top___024root___eval_triggers_vec__act(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vember_top___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vember_top___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vember_top___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vember_top___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vember_top___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

bool Vember_top___024root___eval_phase__nba(Vember_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vember_top___024root___eval_phase__nba\n"); );
    Vember_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vember_top___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vember_top___024root___eval_nba(vlSelf);
        Vember_top___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vember_top___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
bool Vember_top___024root___eval_phase__ico(Vember_top___024root* vlSelf);

void Vember_top___024root___eval(Vember_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vember_top___024root___eval\n"); );
    Vember_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vember_top___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("../../rtl/ember_top.sv", 19, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = Vember_top___024root___eval_phase__ico(vlSelf);
        vlSelfRef.__VicoFirstIteration = 0U;
    } while (vlSelfRef.__VicoPhaseResult);
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vember_top___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("../../rtl/ember_top.sv", 19, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vember_top___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("../../rtl/ember_top.sv", 19, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = Vember_top___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vember_top___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vember_top___024root___eval_debug_assertions(Vember_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vember_top___024root___eval_debug_assertions\n"); );
    Vember_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");
    }
    if (VL_UNLIKELY(((vlSelfRef.h_awvalid & 0xfeU)))) {
        Verilated::overWidthError("h_awvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.h_wstrb & 0xf0U)))) {
        Verilated::overWidthError("h_wstrb");
    }
    if (VL_UNLIKELY(((vlSelfRef.h_wvalid & 0xfeU)))) {
        Verilated::overWidthError("h_wvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.h_bready & 0xfeU)))) {
        Verilated::overWidthError("h_bready");
    }
    if (VL_UNLIKELY(((vlSelfRef.h_arvalid & 0xfeU)))) {
        Verilated::overWidthError("h_arvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.h_rready & 0xfeU)))) {
        Verilated::overWidthError("h_rready");
    }
    if (VL_UNLIKELY(((vlSelfRef.dbg_en & 0xfeU)))) {
        Verilated::overWidthError("dbg_en");
    }
    if (VL_UNLIKELY(((vlSelfRef.dbg_addr & 0xfffe0000U)))) {
        Verilated::overWidthError("dbg_addr");
    }
    if (VL_UNLIKELY(((vlSelfRef.dbg_be & 0xf0U)))) {
        Verilated::overWidthError("dbg_be");
    }
    if (VL_UNLIKELY(((vlSelfRef.fb_select & 0xfcU)))) {
        Verilated::overWidthError("fb_select");
    }
}
#endif  // VL_DEBUG
