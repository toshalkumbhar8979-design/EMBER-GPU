// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop___024root___nba_comb__TOP__8(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__8\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ember_top__DOT__u_xbar__DOT__r_fwd_d 
        = ((0U == (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__rstate)) 
           & ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__d_req_v_r) 
              & ((~ (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__h_req_v_r)) 
                 | (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__r_favor_d))));
    vlSelfRef.ember_top__DOT__u_xbar__DOT__r_fwd_h 
        = ((0U == (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__rstate)) 
           & ((~ ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__d_req_v_r) 
                  & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__r_favor_d))) 
              & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__h_req_v_r)));
    vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_d 
        = ((0U == (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__wstate)) 
           & ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__d_req_v_w) 
              & ((~ (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__h_req_v_w)) 
                 | (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_favor_d))));
    vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_h 
        = ((0U == (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__wstate)) 
           & ((~ ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__d_req_v_w) 
                  & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_favor_d))) 
              & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__h_req_v_w)));
    vlSelfRef.ember_top__DOT__u_xbar__DOT__v_ar = ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__r_fwd_h)
                                                    ? vlSelfRef.ember_top__DOT__u_xbar__DOT__h_ar
                                                    : vlSelfRef.ember_top__DOT__u_xbar__DOT__d_ar);
    vlSelfRef.ember_top__DOT__u_xbar__DOT__v_arvalid 
        = ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__r_fwd_d) 
           | (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__r_fwd_h));
    vlSelfRef.ember_top__DOT__u_xbar__DOT__v_awvalid 
        = ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_d) 
           | (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_h));
    if (vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_h) {
        vlSelfRef.ember_top__DOT__u_xbar__DOT__v_aw 
            = vlSelfRef.ember_top__DOT__u_xbar__DOT__h_aw;
        vlSelfRef.ember_top__DOT__u_xbar__DOT__v_w 
            = vlSelfRef.ember_top__DOT__u_xbar__DOT__h_w;
    } else {
        vlSelfRef.ember_top__DOT__u_xbar__DOT__v_aw 
            = vlSelfRef.ember_top__DOT__u_xbar__DOT__d_aw;
        vlSelfRef.ember_top__DOT__u_xbar__DOT__v_w 
            = vlSelfRef.ember_top__DOT__u_xbar__DOT__d_w;
    }
    vlSelfRef.ember_top__DOT__u_xbar__DOT__v_wvalid 
        = (((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__h_wvalid) 
            & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_h)) 
           | ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__d_wvalid) 
              & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_d)));
    vlSelfRef.ember_top__DOT__v_ar = vlSelfRef.ember_top__DOT__u_xbar__DOT__v_ar;
    vlSelfRef.ember_top__DOT__v_arvalid = vlSelfRef.ember_top__DOT__u_xbar__DOT__v_arvalid;
    vlSelfRef.ember_top__DOT__v_awvalid = vlSelfRef.ember_top__DOT__u_xbar__DOT__v_awvalid;
    vlSelfRef.ember_top__DOT__v_aw = vlSelfRef.ember_top__DOT__u_xbar__DOT__v_aw;
    vlSelfRef.ember_top__DOT__v_w = vlSelfRef.ember_top__DOT__u_xbar__DOT__v_w;
    vlSelfRef.ember_top__DOT__v_wvalid = vlSelfRef.ember_top__DOT__u_xbar__DOT__v_wvalid;
    vlSelfRef.ember_top__DOT__u_vram__DOT__s_ar = vlSelfRef.ember_top__DOT__v_ar;
    vlSelfRef.ember_top__DOT__u_vram__DOT__s_arvalid 
        = vlSelfRef.ember_top__DOT__v_arvalid;
    vlSelfRef.ember_top__DOT__u_vram__DOT__s_awvalid 
        = vlSelfRef.ember_top__DOT__v_awvalid;
    vlSelfRef.ember_top__DOT__u_vram__DOT__s_aw = vlSelfRef.ember_top__DOT__v_aw;
    vlSelfRef.ember_top__DOT__u_vram__DOT__s_w = vlSelfRef.ember_top__DOT__v_w;
    vlSelfRef.ember_top__DOT__u_vram__DOT__s_wvalid 
        = vlSelfRef.ember_top__DOT__v_wvalid;
}

void Vtop___024root___nba_comb__TOP__9(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__9\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ember_top__DOT__blit_own = ((~ (IData)(vlSelfRef.ember_top__DOT__rtr_busy)) 
                                          & (IData)(vlSelfRef.ember_top__DOT__blit_busy));
    if (vlSelfRef.ember_top__DOT__rtr_own) {
        vlSelfRef.ember_top__DOT__fpa_we = vlSelfRef.ember_top__DOT__rtr_fpa_we;
        vlSelfRef.ember_top__DOT__fpa_wdata = vlSelfRef.ember_top__DOT__rtr_fpa_wdata;
        vlSelfRef.ember_top__DOT__fpa_be = vlSelfRef.ember_top__DOT__rtr_fpa_be;
        vlSelfRef.ember_top__DOT__fpa_req = vlSelfRef.ember_top__DOT__rtr_fpa_req;
        vlSelfRef.ember_top__DOT__fpa_addr = vlSelfRef.ember_top__DOT__rtr_fpa_addr;
    } else if (vlSelfRef.ember_top__DOT__blit_own) {
        vlSelfRef.ember_top__DOT__fpa_we = vlSelfRef.ember_top__DOT__blit_fpa_we;
        vlSelfRef.ember_top__DOT__fpa_wdata = vlSelfRef.ember_top__DOT__blit_fpa_wdata;
        vlSelfRef.ember_top__DOT__fpa_be = vlSelfRef.ember_top__DOT__blit_fpa_be;
        vlSelfRef.ember_top__DOT__fpa_addr = vlSelfRef.ember_top__DOT__blit_fpa_addr;
        vlSelfRef.ember_top__DOT__fpa_req = vlSelfRef.ember_top__DOT__blit_fpa_req;
    } else {
        vlSelfRef.ember_top__DOT__fpa_we = 0U;
        vlSelfRef.ember_top__DOT__fpa_wdata = 0U;
        vlSelfRef.ember_top__DOT__fpa_be = 0U;
        vlSelfRef.ember_top__DOT__fpa_addr = 0U;
        vlSelfRef.ember_top__DOT__fpa_req = 0U;
    }
    vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_we = vlSelfRef.ember_top__DOT__fpa_we;
    vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_wdata 
        = vlSelfRef.ember_top__DOT__fpa_wdata;
    vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_be = vlSelfRef.ember_top__DOT__fpa_be;
    vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_req 
        = vlSelfRef.ember_top__DOT__fpa_req;
    vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_addr 
        = vlSelfRef.ember_top__DOT__fpa_addr;
    vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_widx 
        = (0x0001ffffU & ((vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_addr 
                           - (IData)(0x00001000U)) 
                          >> 2U));
}

void Vtop___024root___nba_comb__TOP__10(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__10\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_wready 
        = (1U & ((~ (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__w_v)) 
                 | (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__wr_fire)));
    vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_awready 
        = (1U & ((~ (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__aw_v)) 
                 | (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__wr_fire)));
    vlSelfRef.ember_top__DOT__u_cp__DOT__s_wready = vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_wready;
    vlSelfRef.ember_top__DOT__u_cp__DOT__s_awready 
        = vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_awready;
    vlSelfRef.ember_top__DOT__c_wready = vlSelfRef.ember_top__DOT__u_cp__DOT__s_wready;
    vlSelfRef.ember_top__DOT__c_awready = vlSelfRef.ember_top__DOT__u_cp__DOT__s_awready;
    vlSelfRef.ember_top__DOT__u_xbar__DOT__c_wready 
        = vlSelfRef.ember_top__DOT__c_wready;
    vlSelfRef.ember_top__DOT__u_xbar__DOT__c_awready 
        = vlSelfRef.ember_top__DOT__c_awready;
}

void Vtop___024root___nba_sequent__TOP__26(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__26\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ember_top__DOT__u_tu__DOT__tua_rdata 
        = vlSelfRef.ember_top__DOT__tu_tua_rdata;
}

void Vtop___024root___nba_sequent__TOP__27(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__27\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ ember_top__DOT__u_tu__DOT____VdfgRegularize_h0ebfa33a_0_0;
    ember_top__DOT__u_tu__DOT____VdfgRegularize_h0ebfa33a_0_0 = 0;
    // Body
    vlSelfRef.ember_top__DOT__u_tu__DOT__kick = vlSelfRef.ember_top__DOT__tu_kick;
    vlSelfRef.ember_top__DOT__u_tu__DOT__csr_we = vlSelfRef.ember_top__DOT__tu_csr_we;
    vlSelfRef.ember_top__DOT__u_tu__DOT__csr_addr = vlSelfRef.ember_top__DOT__tu_csr_addr;
    vlSelfRef.ember_top__DOT__u_tu__DOT__csr_wdata 
        = vlSelfRef.ember_top__DOT__tu_csr_wdata;
    ember_top__DOT__u_tu__DOT____VdfgRegularize_h0ebfa33a_0_0 
        = ((IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__csr_we) 
           & (3U == (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__csr_addr)));
    vlSelfRef.ember_top__DOT__u_tu__DOT__cfg2_dim_we 
        = ((IData)(ember_top__DOT__u_tu__DOT____VdfgRegularize_h0ebfa33a_0_0) 
           & (0U == (vlSelfRef.ember_top__DOT__u_tu__DOT__csr_wdata 
                     >> 0x0000001eU)));
    vlSelfRef.ember_top__DOT__u_tu__DOT__cfg2_m_we 
        = ((IData)(ember_top__DOT__u_tu__DOT____VdfgRegularize_h0ebfa33a_0_0) 
           & (1U == (vlSelfRef.ember_top__DOT__u_tu__DOT__csr_wdata 
                     >> 0x0000001eU)));
    vlSelfRef.ember_top__DOT__u_tu__DOT__cfg2_q_we 
        = ((IData)(ember_top__DOT__u_tu__DOT____VdfgRegularize_h0ebfa33a_0_0) 
           & (2U == (vlSelfRef.ember_top__DOT__u_tu__DOT__csr_wdata 
                     >> 0x0000001eU)));
}

void Vtop___024root___nba_comb__TOP__11(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__11\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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

void Vtop___024root___nba_comb__TOP__12(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__12\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ember_top__DOT__u_cp__DOT__rd_data = 
        ((0U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rd_addr))
          ? 0xeb220002U : ((4U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rd_addr))
                            ? (((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__tu_busy) 
                                << 0x0000000aU) | (
                                                   (((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__core_busy) 
                                                     << 9U) 
                                                    | (((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__gsx_busy) 
                                                        << 8U) 
                                                       | ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__blit_busy) 
                                                          << 7U))) 
                                                   | (((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rb_count) 
                                                       << 3U) 
                                                      | (((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rb_empty) 
                                                          << 2U) 
                                                         | (((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rtr_busy) 
                                                             << 1U) 
                                                            | (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__dma_busy_q))))))
                            : ((0x000cU == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rd_addr))
                                ? (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__fence_done_q)
                                : ((0x0010U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rd_addr))
                                    ? ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rb_empty)
                                        ? 0U : vlSelfRef.ember_top__DOT__u_cp__DOT__rb_mem
                                       [(7U & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rb_rp))])
                                    : ((0x0014U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rd_addr))
                                        ? vlSelfRef.ember_top__DOT__u_cp__DOT__dma_dst_q
                                        : ((0x0018U 
                                            == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rd_addr))
                                            ? vlSelfRef.ember_top__DOT__u_cp__DOT__dma_len_q
                                            : 0U))))));
    vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__rd_data 
        = vlSelfRef.ember_top__DOT__u_cp__DOT__rd_data;
}

void Vtop___024root___nba_comb__TOP__13(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__13\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ember_top__DOT__u_xbar__DOT__d_arready 
        = ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__r_fwd_d) 
           & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__v_arready));
    vlSelfRef.ember_top__DOT__u_xbar__DOT__d_awready 
        = ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__v_awready) 
           & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_d));
    vlSelfRef.ember_top__DOT__u_xbar__DOT__d_wready 
        = ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__v_wready) 
           & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_d));
    vlSelfRef.ember_top__DOT__u_vram__DOT__ar_accept 
        = ((IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__s_arready) 
           & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__s_arvalid));
    vlSelfRef.ember_top__DOT__d_arready = vlSelfRef.ember_top__DOT__u_xbar__DOT__d_arready;
    vlSelfRef.ember_top__DOT__d_awready = vlSelfRef.ember_top__DOT__u_xbar__DOT__d_awready;
    vlSelfRef.ember_top__DOT__d_wready = vlSelfRef.ember_top__DOT__u_xbar__DOT__d_wready;
    vlSelfRef.ember_top__DOT__u_cp__DOT__m_arready 
        = vlSelfRef.ember_top__DOT__d_arready;
    vlSelfRef.ember_top__DOT__u_cp__DOT__m_awready 
        = vlSelfRef.ember_top__DOT__d_awready;
    vlSelfRef.ember_top__DOT__u_cp__DOT__m_wready = vlSelfRef.ember_top__DOT__d_wready;
}

void Vtop___024root___nba_comb__TOP__14(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__14\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ember_top__DOT__u_xbar__DOT__h_arready 
        = ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__h_ar_is_cp)
            ? (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__c_arready)
            : ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__r_fwd_h) 
               & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__v_arready)));
    if (vlSelfRef.ember_top__DOT__u_xbar__DOT__h_aw_is_cp) {
        vlSelfRef.ember_top__DOT__u_xbar__DOT__h_wready 
            = vlSelfRef.ember_top__DOT__u_xbar__DOT__c_wready;
        vlSelfRef.ember_top__DOT__u_xbar__DOT__h_awready 
            = vlSelfRef.ember_top__DOT__u_xbar__DOT__c_awready;
    } else {
        vlSelfRef.ember_top__DOT__u_xbar__DOT__h_wready 
            = ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__v_wready) 
               & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_h));
        vlSelfRef.ember_top__DOT__u_xbar__DOT__h_awready 
            = ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__v_awready) 
               & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_h));
    }
    vlSelfRef.ember_top__DOT__h_arready = vlSelfRef.ember_top__DOT__u_xbar__DOT__h_arready;
    vlSelfRef.ember_top__DOT__h_wready = vlSelfRef.ember_top__DOT__u_xbar__DOT__h_wready;
    vlSelfRef.ember_top__DOT__h_awready = vlSelfRef.ember_top__DOT__u_xbar__DOT__h_awready;
    vlSelfRef.h_arready = vlSelfRef.ember_top__DOT__h_arready;
    vlSelfRef.h_wready = vlSelfRef.ember_top__DOT__h_wready;
    vlSelfRef.h_awready = vlSelfRef.ember_top__DOT__h_awready;
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__6(Vtop___024root* vlSelf);
extern const VlUnpacked<CData/*0:0*/, 64> Vtop__ConstPool__TABLE_hac274646_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vtop__ConstPool__TABLE_hbc651652_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_hd6d163cc_0;
extern const VlUnpacked<CData/*1:0*/, 128> Vtop__ConstPool__TABLE_h047d7390_0;
void Vtop___024root___nba_sequent__TOP__8(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__9(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__10(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__11(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__12(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__13(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__15(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__25(Vtop___024root* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vinline__nba_sequent__TOP__1___VdlyVal__ember_top__DOT__u_gsx__DOT__mata__v0;
    __Vinline__nba_sequent__TOP__1___VdlyVal__ember_top__DOT__u_gsx__DOT__mata__v0 = 0;
    CData/*3:0*/ __Vinline__nba_sequent__TOP__1___VdlyDim0__ember_top__DOT__u_gsx__DOT__mata__v0;
    __Vinline__nba_sequent__TOP__1___VdlyDim0__ember_top__DOT__u_gsx__DOT__mata__v0 = 0;
    CData/*0:0*/ __Vinline__nba_sequent__TOP__1___VdlySet__ember_top__DOT__u_gsx__DOT__mata__v0;
    __Vinline__nba_sequent__TOP__1___VdlySet__ember_top__DOT__u_gsx__DOT__mata__v0 = 0;
    IData/*31:0*/ __Vinline__nba_sequent__TOP__1___VdlyVal__ember_top__DOT__u_gsx__DOT__vtx__v0;
    __Vinline__nba_sequent__TOP__1___VdlyVal__ember_top__DOT__u_gsx__DOT__vtx__v0 = 0;
    CData/*3:0*/ __Vinline__nba_sequent__TOP__1___VdlyDim0__ember_top__DOT__u_gsx__DOT__vtx__v0;
    __Vinline__nba_sequent__TOP__1___VdlyDim0__ember_top__DOT__u_gsx__DOT__vtx__v0 = 0;
    CData/*0:0*/ __Vinline__nba_sequent__TOP__1___VdlySet__ember_top__DOT__u_gsx__DOT__vtx__v0;
    __Vinline__nba_sequent__TOP__1___VdlySet__ember_top__DOT__u_gsx__DOT__vtx__v0 = 0;
    IData/*31:0*/ __Vinline__nba_sequent__TOP__1___VdlyVal__ember_top__DOT__u_gsx__DOT__col__v0;
    __Vinline__nba_sequent__TOP__1___VdlyVal__ember_top__DOT__u_gsx__DOT__col__v0 = 0;
    CData/*1:0*/ __Vinline__nba_sequent__TOP__1___VdlyDim0__ember_top__DOT__u_gsx__DOT__col__v0;
    __Vinline__nba_sequent__TOP__1___VdlyDim0__ember_top__DOT__u_gsx__DOT__col__v0 = 0;
    CData/*0:0*/ __Vinline__nba_sequent__TOP__1___VdlySet__ember_top__DOT__u_gsx__DOT__col__v0;
    __Vinline__nba_sequent__TOP__1___VdlySet__ember_top__DOT__u_gsx__DOT__col__v0 = 0;
    CData/*0:0*/ __Vinline__nba_sequent__TOP__4___Vdly__ember_top__DOT__u_cp__DOT__u_regs__DOT__s_bvalid;
    __Vinline__nba_sequent__TOP__4___Vdly__ember_top__DOT__u_cp__DOT__u_regs__DOT__s_bvalid = 0;
    CData/*0:0*/ __Vinline__nba_sequent__TOP__5___Vdly__ember_top__DOT__u_vram__DOT__s_bvalid;
    __Vinline__nba_sequent__TOP__5___Vdly__ember_top__DOT__u_vram__DOT__s_bvalid = 0;
    CData/*6:0*/ __Vinline__nba_sequent__TOP__7___Vtableidx1;
    __Vinline__nba_sequent__TOP__7___Vtableidx1 = 0;
    CData/*5:0*/ __Vinline__nba_sequent__TOP__7___Vtableidx2;
    __Vinline__nba_sequent__TOP__7___Vtableidx2 = 0;
    CData/*6:0*/ __Vinline__nba_sequent__TOP__7___Vtableidx3;
    __Vinline__nba_sequent__TOP__7___Vtableidx3 = 0;
    CData/*5:0*/ __Vinline__nba_sequent__TOP__7___Vtableidx4;
    __Vinline__nba_sequent__TOP__7___Vtableidx4 = 0;
    CData/*7:0*/ __Vinline__nba_sequent__TOP__16___VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v0;
    __Vinline__nba_sequent__TOP__16___VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v0 = 0;
    CData/*3:0*/ __Vinline__nba_sequent__TOP__16___VdlyDim0__ember_top__DOT__u_tu__DOT__w_regs__v0;
    __Vinline__nba_sequent__TOP__16___VdlyDim0__ember_top__DOT__u_tu__DOT__w_regs__v0 = 0;
    CData/*3:0*/ __Vinline__nba_sequent__TOP__16___VdlyDim1__ember_top__DOT__u_tu__DOT__w_regs__v0;
    __Vinline__nba_sequent__TOP__16___VdlyDim1__ember_top__DOT__u_tu__DOT__w_regs__v0 = 0;
    CData/*0:0*/ __Vinline__nba_sequent__TOP__27_ember_top__DOT__u_tu__DOT____VdfgRegularize_h0ebfa33a_0_0;
    __Vinline__nba_sequent__TOP__27_ember_top__DOT__u_tu__DOT____VdfgRegularize_h0ebfa33a_0_0 = 0;
    // Body
    if ((0x0000000000003000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0x0000000000001000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        __Vinline__nba_sequent__TOP__1___VdlySet__ember_top__DOT__u_gsx__DOT__mata__v0 = 0U;
        __Vinline__nba_sequent__TOP__1___VdlySet__ember_top__DOT__u_gsx__DOT__vtx__v0 = 0U;
        __Vinline__nba_sequent__TOP__1___VdlySet__ember_top__DOT__u_gsx__DOT__col__v0 = 0U;
        if (vlSelfRef.ember_top__DOT__u_gsx__DOT__csr_we) {
            if ((0U == (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__csr_addr))) {
                __Vinline__nba_sequent__TOP__1___VdlyVal__ember_top__DOT__u_gsx__DOT__mata__v0 
                    = vlSelfRef.ember_top__DOT__u_gsx__DOT__csr_wdata;
                __Vinline__nba_sequent__TOP__1___VdlyDim0__ember_top__DOT__u_gsx__DOT__mata__v0 
                    = vlSelfRef.ember_top__DOT__u_gsx__DOT__mata_ptr;
                __Vinline__nba_sequent__TOP__1___VdlySet__ember_top__DOT__u_gsx__DOT__mata__v0 = 1U;
            }
            if ((0U != (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__csr_addr))) {
                if ((1U == (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__csr_addr))) {
                    vlSelfRef.ember_top__DOT__u_gsx__DOT____Vlvbound_h5e2f4665__0 
                        = vlSelfRef.ember_top__DOT__u_gsx__DOT__csr_wdata;
                    if ((0x0eU >= (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__vtx_ptr))) {
                        __Vinline__nba_sequent__TOP__1___VdlyVal__ember_top__DOT__u_gsx__DOT__vtx__v0 
                            = vlSelfRef.ember_top__DOT__u_gsx__DOT____Vlvbound_h5e2f4665__0;
                        __Vinline__nba_sequent__TOP__1___VdlyDim0__ember_top__DOT__u_gsx__DOT__vtx__v0 
                            = vlSelfRef.ember_top__DOT__u_gsx__DOT__vtx_ptr;
                        __Vinline__nba_sequent__TOP__1___VdlySet__ember_top__DOT__u_gsx__DOT__vtx__v0 = 1U;
                    }
                }
                if ((1U != (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__csr_addr))) {
                    if ((2U == (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__csr_addr))) {
                        vlSelfRef.ember_top__DOT__u_gsx__DOT____Vlvbound_hd21f5caa__0 
                            = vlSelfRef.ember_top__DOT__u_gsx__DOT__csr_wdata;
                        if ((2U >= (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__col_ptr))) {
                            __Vinline__nba_sequent__TOP__1___VdlyVal__ember_top__DOT__u_gsx__DOT__col__v0 
                                = vlSelfRef.ember_top__DOT__u_gsx__DOT____Vlvbound_hd21f5caa__0;
                            __Vinline__nba_sequent__TOP__1___VdlyDim0__ember_top__DOT__u_gsx__DOT__col__v0 
                                = vlSelfRef.ember_top__DOT__u_gsx__DOT__col_ptr;
                            __Vinline__nba_sequent__TOP__1___VdlySet__ember_top__DOT__u_gsx__DOT__col__v0 = 1U;
                        }
                    }
                }
            }
        }
        if (__Vinline__nba_sequent__TOP__1___VdlySet__ember_top__DOT__u_gsx__DOT__mata__v0) {
            vlSelfRef.ember_top__DOT__u_gsx__DOT__mata[__Vinline__nba_sequent__TOP__1___VdlyDim0__ember_top__DOT__u_gsx__DOT__mata__v0] 
                = __Vinline__nba_sequent__TOP__1___VdlyVal__ember_top__DOT__u_gsx__DOT__mata__v0;
        }
        if (__Vinline__nba_sequent__TOP__1___VdlySet__ember_top__DOT__u_gsx__DOT__vtx__v0) {
            vlSelfRef.ember_top__DOT__u_gsx__DOT__vtx[__Vinline__nba_sequent__TOP__1___VdlyDim0__ember_top__DOT__u_gsx__DOT__vtx__v0] 
                = __Vinline__nba_sequent__TOP__1___VdlyVal__ember_top__DOT__u_gsx__DOT__vtx__v0;
        }
        if (__Vinline__nba_sequent__TOP__1___VdlySet__ember_top__DOT__u_gsx__DOT__col__v0) {
            vlSelfRef.ember_top__DOT__u_gsx__DOT__col[__Vinline__nba_sequent__TOP__1___VdlyDim0__ember_top__DOT__u_gsx__DOT__col__v0] 
                = __Vinline__nba_sequent__TOP__1___VdlyVal__ember_top__DOT__u_gsx__DOT__col__v0;
        }
    }
    if ((0x0000000000c00000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((0x000000000000000cULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((0x0000000000000030ULL & vlSelfRef.__VnbaTriggered[0U])) {
        __Vinline__nba_sequent__TOP__4___Vdly__ember_top__DOT__u_cp__DOT__u_regs__DOT__s_bvalid 
            = vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_bvalid;
        if (vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__rst_n) {
            if (vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__wr_fire) {
                __Vinline__nba_sequent__TOP__4___Vdly__ember_top__DOT__u_cp__DOT__u_regs__DOT__s_bvalid = 1U;
                vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_b = 0U;
            } else if (((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_bvalid) 
                        & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_bready))) {
                __Vinline__nba_sequent__TOP__4___Vdly__ember_top__DOT__u_cp__DOT__u_regs__DOT__s_bvalid = 0U;
            }
            if (((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_awvalid) 
                 & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_awready))) {
                vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__aw_v = 1U;
            } else if (vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__wr_fire) {
                vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__aw_v = 0U;
            }
            if (((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_wvalid) 
                 & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_wready))) {
                vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__w_v = 1U;
            } else if (vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__wr_fire) {
                vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__w_v = 0U;
            }
            if (vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__ar_accept) {
                vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__ar_v = 1U;
            } else if (((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_rvalid) 
                        & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_rready))) {
                vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__ar_v = 0U;
            }
        } else {
            __Vinline__nba_sequent__TOP__4___Vdly__ember_top__DOT__u_cp__DOT__u_regs__DOT__s_bvalid = 0U;
            vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_b = 0U;
            vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__aw_v = 0U;
            vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__w_v = 0U;
            vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__ar_v = 0U;
        }
        vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_bvalid 
            = __Vinline__nba_sequent__TOP__4___Vdly__ember_top__DOT__u_cp__DOT__u_regs__DOT__s_bvalid;
        vlSelfRef.ember_top__DOT__u_cp__DOT__s_bvalid 
            = vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_bvalid;
        vlSelfRef.ember_top__DOT__u_cp__DOT__s_b = vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_b;
        vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_rvalid 
            = vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__ar_v;
        vlSelfRef.ember_top__DOT__c_bvalid = vlSelfRef.ember_top__DOT__u_cp__DOT__s_bvalid;
        vlSelfRef.ember_top__DOT__c_b = vlSelfRef.ember_top__DOT__u_cp__DOT__s_b;
        vlSelfRef.ember_top__DOT__u_cp__DOT__s_rvalid 
            = vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_rvalid;
        vlSelfRef.ember_top__DOT__u_xbar__DOT__c_bvalid 
            = vlSelfRef.ember_top__DOT__c_bvalid;
        vlSelfRef.ember_top__DOT__u_xbar__DOT__c_b 
            = vlSelfRef.ember_top__DOT__c_b;
        vlSelfRef.ember_top__DOT__c_rvalid = vlSelfRef.ember_top__DOT__u_cp__DOT__s_rvalid;
        vlSelfRef.ember_top__DOT__u_xbar__DOT__c_rvalid 
            = vlSelfRef.ember_top__DOT__c_rvalid;
    }
    if ((0x0000000003000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        __Vinline__nba_sequent__TOP__5___Vdly__ember_top__DOT__u_vram__DOT__s_bvalid 
            = vlSelfRef.ember_top__DOT__u_vram__DOT__s_bvalid;
        if (vlSelfRef.ember_top__DOT__u_vram__DOT__rst_n) {
            if (vlSelfRef.ember_top__DOT__u_vram__DOT__wr_fire) {
                __Vinline__nba_sequent__TOP__5___Vdly__ember_top__DOT__u_vram__DOT__s_bvalid = 1U;
                vlSelfRef.ember_top__DOT__u_vram__DOT__s_b = 0U;
            } else if (((IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__s_bvalid) 
                        & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__s_bready))) {
                __Vinline__nba_sequent__TOP__5___Vdly__ember_top__DOT__u_vram__DOT__s_bvalid = 0U;
            }
            if (((IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__s_awvalid) 
                 & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__s_awready))) {
                vlSelfRef.ember_top__DOT__u_vram__DOT__aw_v = 1U;
            } else if (vlSelfRef.ember_top__DOT__u_vram__DOT__wr_fire) {
                vlSelfRef.ember_top__DOT__u_vram__DOT__aw_v = 0U;
            }
            if (((IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__s_wvalid) 
                 & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__s_wready))) {
                vlSelfRef.ember_top__DOT__u_vram__DOT__w_v = 1U;
            } else if (vlSelfRef.ember_top__DOT__u_vram__DOT__wr_fire) {
                vlSelfRef.ember_top__DOT__u_vram__DOT__w_v = 0U;
            }
            if (vlSelfRef.ember_top__DOT__u_vram__DOT__ar_accept) {
                vlSelfRef.ember_top__DOT__u_vram__DOT__ar_v = 1U;
            } else if (((IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__s_rvalid) 
                        & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__s_rready))) {
                vlSelfRef.ember_top__DOT__u_vram__DOT__ar_v = 0U;
            }
        } else {
            __Vinline__nba_sequent__TOP__5___Vdly__ember_top__DOT__u_vram__DOT__s_bvalid = 0U;
            vlSelfRef.ember_top__DOT__u_vram__DOT__s_b = 0U;
            vlSelfRef.ember_top__DOT__u_vram__DOT__aw_v = 0U;
            vlSelfRef.ember_top__DOT__u_vram__DOT__w_v = 0U;
            vlSelfRef.ember_top__DOT__u_vram__DOT__ar_v = 0U;
        }
        vlSelfRef.ember_top__DOT__u_vram__DOT__s_bvalid 
            = __Vinline__nba_sequent__TOP__5___Vdly__ember_top__DOT__u_vram__DOT__s_bvalid;
        vlSelfRef.ember_top__DOT__v_bvalid = vlSelfRef.ember_top__DOT__u_vram__DOT__s_bvalid;
        vlSelfRef.ember_top__DOT__v_b = vlSelfRef.ember_top__DOT__u_vram__DOT__s_b;
        vlSelfRef.ember_top__DOT__u_vram__DOT__s_rvalid 
            = vlSelfRef.ember_top__DOT__u_vram__DOT__ar_v;
        vlSelfRef.ember_top__DOT__u_xbar__DOT__v_b 
            = vlSelfRef.ember_top__DOT__v_b;
        vlSelfRef.ember_top__DOT__v_rvalid = vlSelfRef.ember_top__DOT__u_vram__DOT__s_rvalid;
        vlSelfRef.ember_top__DOT__u_xbar__DOT__d_b 
            = vlSelfRef.ember_top__DOT__u_xbar__DOT__v_b;
        vlSelfRef.ember_top__DOT__d_b = vlSelfRef.ember_top__DOT__u_xbar__DOT__d_b;
        vlSelfRef.ember_top__DOT__u_cp__DOT__m_b = vlSelfRef.ember_top__DOT__d_b;
    }
    if ((0x000000000000c000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__6(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        __Vinline__nba_sequent__TOP__7___Vtableidx4 
            = ((((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__r_favor_d) 
                 << 5U) | (((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__d_req_v_r) 
                            << 4U) | ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__h_req_v_r) 
                                      << 3U))) | (((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__rstate) 
                                                   << 1U) 
                                                  | (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__rst_n)));
        if (Vtop__ConstPool__TABLE_hac274646_0[__Vinline__nba_sequent__TOP__7___Vtableidx4]) {
            vlSelfRef.ember_top__DOT__u_xbar__DOT__r_favor_d 
                = Vtop__ConstPool__TABLE_hbc651652_0
                [__Vinline__nba_sequent__TOP__7___Vtableidx4];
        }
        __Vinline__nba_sequent__TOP__7___Vtableidx2 
            = ((((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_favor_d) 
                 << 5U) | (((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__d_req_v_w) 
                            << 4U) | ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__h_req_v_w) 
                                      << 3U))) | (((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__wstate) 
                                                   << 1U) 
                                                  | (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__rst_n)));
        if (Vtop__ConstPool__TABLE_hac274646_0[__Vinline__nba_sequent__TOP__7___Vtableidx2]) {
            vlSelfRef.ember_top__DOT__u_xbar__DOT__w_favor_d 
                = Vtop__ConstPool__TABLE_hbc651652_0
                [__Vinline__nba_sequent__TOP__7___Vtableidx2];
        }
        __Vinline__nba_sequent__TOP__7___Vtableidx3 
            = ((((((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__v_rready) 
                   << 3U) | ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__v_rvalid) 
                             << 2U)) | (((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__d_req_v_r) 
                                         << 1U) | (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__h_req_v_r))) 
                << 3U) | (((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__rstate) 
                           << 1U) | (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__rst_n)));
        if (Vtop__ConstPool__TABLE_hd6d163cc_0[__Vinline__nba_sequent__TOP__7___Vtableidx3]) {
            vlSelfRef.ember_top__DOT__u_xbar__DOT__rstate 
                = Vtop__ConstPool__TABLE_h047d7390_0
                [__Vinline__nba_sequent__TOP__7___Vtableidx3];
        }
        __Vinline__nba_sequent__TOP__7___Vtableidx1 
            = ((((((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__v_bready) 
                   << 3U) | ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__v_bvalid) 
                             << 2U)) | (((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__d_req_v_w) 
                                         << 1U) | (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__h_req_v_w))) 
                << 3U) | (((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__wstate) 
                           << 1U) | (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__rst_n)));
        if (Vtop__ConstPool__TABLE_hd6d163cc_0[__Vinline__nba_sequent__TOP__7___Vtableidx1]) {
            vlSelfRef.ember_top__DOT__u_xbar__DOT__wstate 
                = Vtop__ConstPool__TABLE_h047d7390_0
                [__Vinline__nba_sequent__TOP__7___Vtableidx1];
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
        vlSelfRef.ember_top__DOT__u_cp__DOT__s_rready 
            = vlSelfRef.ember_top__DOT__c_rready;
        vlSelfRef.ember_top__DOT__u_cp__DOT__s_bready 
            = vlSelfRef.ember_top__DOT__c_bready;
        vlSelfRef.ember_top__DOT__u_vram__DOT__s_bready 
            = vlSelfRef.ember_top__DOT__v_bready;
        vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_rready 
            = vlSelfRef.ember_top__DOT__u_cp__DOT__s_rready;
        vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_bready 
            = vlSelfRef.ember_top__DOT__u_cp__DOT__s_bready;
    }
    if ((0x0000000000000c00ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__8(vlSelf);
    }
    if ((0x0000000000030000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__9(vlSelf);
    }
    if ((0x0000000001000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__10(vlSelf);
    }
    if ((0x0000000000300000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__11(vlSelf);
    }
    if ((0x0000000000000300ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__12(vlSelf);
    }
    if ((0x00000000000c0000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__13(vlSelf);
    }
    if ((0x00000000000000c0ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__rq_pend 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__rq_pend;
        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__rq_req_cyc 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__rq_req_cyc;
        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__mac_pend 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__mac_pend;
        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__st 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__st;
        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__n0 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__n0;
        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__m0 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__m0;
        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__k0 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__k0;
        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__wrow 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wrow;
        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__wgrp 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__wgrp;
        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__cw_word 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__cw_word;
        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__cw_rblk 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__cw_rblk;
        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__mrow 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__mrow;
        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__fcnt 
            = vlSelfRef.ember_top__DOT__u_tu__DOT__fcnt;
        vlSelfRef.__VdlySet__ember_top__DOT__u_tu__DOT__wrowbuf__v0 = 0U;
        vlSelfRef.__VdlySet__ember_top__DOT__u_tu__DOT__abuf_q__v0 = 0U;
        if (vlSelfRef.ember_top__DOT__u_tu__DOT__rst_n) {
            if (vlSelfRef.ember_top__DOT__u_tu__DOT__cfg2_m_we) {
                vlSelfRef.ember_top__DOT__u_tu__DOT__dim_m 
                    = (0x00000fffU & vlSelfRef.ember_top__DOT__u_tu__DOT__csr_wdata);
            }
            if (vlSelfRef.ember_top__DOT__u_tu__DOT__cfg2_dim_we) {
                vlSelfRef.ember_top__DOT__u_tu__DOT__dim_n 
                    = (0x00000fffU & vlSelfRef.ember_top__DOT__u_tu__DOT__csr_wdata);
                vlSelfRef.ember_top__DOT__u_tu__DOT__dim_k 
                    = (0x00000fffU & (vlSelfRef.ember_top__DOT__u_tu__DOT__csr_wdata 
                                      >> 0x10U));
            }
        } else {
            vlSelfRef.ember_top__DOT__u_tu__DOT__dim_m = 0U;
            vlSelfRef.ember_top__DOT__u_tu__DOT__dim_n = 0U;
            vlSelfRef.ember_top__DOT__u_tu__DOT__dim_k = 0U;
        }
    }
    if ((0x0000000000000010ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__15(vlSelf);
    }
    if ((0x0000000000000040ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk1__DOT__r = 0U;
        while ((0x00000010U > vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk1__DOT__r)) {
            if ((1U & ((IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__w_ld) 
                       >> (0x0000000fU & vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk1__DOT__r)))) {
                vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk1__DOT__unnamedblk2__DOT__c = 0U;
                while ((0x00000010U > vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk1__DOT__unnamedblk2__DOT__c)) {
                    __Vinline__nba_sequent__TOP__16___VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v0 
                        = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte
                        [(0x0000000fU & vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk1__DOT__unnamedblk2__DOT__c)];
                    __Vinline__nba_sequent__TOP__16___VdlyDim0__ember_top__DOT__u_tu__DOT__w_regs__v0 
                        = (0x0000000fU & vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk1__DOT__unnamedblk2__DOT__c);
                    __Vinline__nba_sequent__TOP__16___VdlyDim1__ember_top__DOT__u_tu__DOT__w_regs__v0 
                        = (0x0000000fU & vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk1__DOT__r);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__w_regs.enqueue(__Vinline__nba_sequent__TOP__16___VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v0, __Vinline__nba_sequent__TOP__16___VdlyDim1__ember_top__DOT__u_tu__DOT__w_regs__v0, __Vinline__nba_sequent__TOP__16___VdlyDim0__ember_top__DOT__u_tu__DOT__w_regs__v0);
                    vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk1__DOT__unnamedblk2__DOT__c 
                        = ((IData)(1U) + vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk1__DOT__unnamedblk2__DOT__c);
                }
            }
            vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk1__DOT__r 
                = ((IData)(1U) + vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk1__DOT__r);
        }
        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__w_regs.commit(vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs);
    }
    if ((0x0000000000003000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.ember_top__DOT__u_gsx__DOT__mata_ptr 
            = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__mata_ptr;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__vtx_ptr 
            = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__vtx_ptr;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__col_ptr 
            = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__col_ptr;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__a0 
            = vlSelfRef.ember_top__DOT__u_gsx__DOT__f_a0;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__b0 
            = vlSelfRef.ember_top__DOT__u_gsx__DOT__f_b0;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__a1 
            = vlSelfRef.ember_top__DOT__u_gsx__DOT__f_a1;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__b1 
            = vlSelfRef.ember_top__DOT__u_gsx__DOT__f_b1;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__a2 
            = vlSelfRef.ember_top__DOT__u_gsx__DOT__f_a2;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__b2 
            = vlSelfRef.ember_top__DOT__u_gsx__DOT__f_b2;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__a3 
            = vlSelfRef.ember_top__DOT__u_gsx__DOT__f_a3;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__b3 
            = vlSelfRef.ember_top__DOT__u_gsx__DOT__f_b3;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__go 
            = vlSelfRef.ember_top__DOT__u_gsx__DOT__f_go;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__lane_en 
            = vlSelfRef.ember_top__DOT__u_gsx__DOT__f_lane_en;
        vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__op 
            = vlSelfRef.ember_top__DOT__u_gsx__DOT__f_op;
        vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_we 
            = vlSelfRef.ember_top__DOT__gsx_gxa_we;
        vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_be 
            = vlSelfRef.ember_top__DOT__gsx_gxa_be;
        vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_wdata 
            = vlSelfRef.ember_top__DOT__gsx_gxa_wdata;
        vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_req 
            = vlSelfRef.ember_top__DOT__gsx_gxa_req;
        vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_widx 
            = (0x0001ffffU & ((vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_addr 
                               - (IData)(0x00001000U)) 
                              >> 2U));
    }
    if ((0x0000000003000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.ember_top__DOT__u_xbar__DOT__v_rvalid 
            = vlSelfRef.ember_top__DOT__v_rvalid;
        vlSelfRef.ember_top__DOT__u_xbar__DOT__v_bvalid 
            = vlSelfRef.ember_top__DOT__v_bvalid;
        if (vlSelfRef.ember_top__DOT__u_vram__DOT__rst_n) {
            if (((IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__s_wvalid) 
                 & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__s_wready))) {
                vlSelfRef.ember_top__DOT__u_vram__DOT__w_q 
                    = vlSelfRef.ember_top__DOT__u_vram__DOT__s_w;
            }
            if (((IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__s_awvalid) 
                 & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__s_awready))) {
                vlSelfRef.ember_top__DOT__u_vram__DOT__aw_q 
                    = vlSelfRef.ember_top__DOT__u_vram__DOT__s_aw;
            }
        } else {
            vlSelfRef.ember_top__DOT__u_vram__DOT__w_q = 0ULL;
            vlSelfRef.ember_top__DOT__u_vram__DOT__aw_q = 0ULL;
        }
    }
    if ((0x000000000000000cULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.ember_top__DOT__u_xbar__DOT__d_req_v_r 
            = vlSelfRef.ember_top__DOT__u_xbar__DOT__d_arvalid;
        vlSelfRef.ember_top__DOT__u_xbar__DOT__d_req_v_w 
            = vlSelfRef.ember_top__DOT__u_xbar__DOT__d_awvalid;
    }
    if ((0x0000000003000033ULL & vlSelfRef.__VnbaTriggered[0U])) {
        if ((1U == (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__wstate))) {
            vlSelfRef.ember_top__DOT__u_xbar__DOT__h_b 
                = vlSelfRef.ember_top__DOT__u_xbar__DOT__v_b;
            vlSelfRef.ember_top__DOT__u_xbar__DOT__h_bvalid 
                = vlSelfRef.ember_top__DOT__u_xbar__DOT__v_bvalid;
        } else {
            vlSelfRef.ember_top__DOT__u_xbar__DOT__h_b 
                = vlSelfRef.ember_top__DOT__u_xbar__DOT__c_b;
            vlSelfRef.ember_top__DOT__u_xbar__DOT__h_bvalid 
                = vlSelfRef.ember_top__DOT__u_xbar__DOT__c_bvalid;
        }
        vlSelfRef.ember_top__DOT__u_xbar__DOT__h_rvalid 
            = ((1U == (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__rstate))
                ? (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__v_rvalid)
                : (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__c_rvalid));
        vlSelfRef.ember_top__DOT__h_b_s = vlSelfRef.ember_top__DOT__u_xbar__DOT__h_b;
        vlSelfRef.ember_top__DOT__h_rvalid = vlSelfRef.ember_top__DOT__u_xbar__DOT__h_rvalid;
        vlSelfRef.ember_top__DOT__h_bvalid = vlSelfRef.ember_top__DOT__u_xbar__DOT__h_bvalid;
        vlSelfRef.ember_top__DOT__h_bresp = vlSelfRef.ember_top__DOT__h_b_s;
        vlSelfRef.h_rvalid = vlSelfRef.ember_top__DOT__h_rvalid;
        vlSelfRef.h_bvalid = vlSelfRef.ember_top__DOT__h_bvalid;
        vlSelfRef.h_bresp = vlSelfRef.ember_top__DOT__h_bresp;
    }
    if ((0x0000000003000003ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__s_arready 
            = (1U & ((~ (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__ar_v)) 
                     | ((IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__s_rready) 
                        & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__s_rvalid))));
        vlSelfRef.ember_top__DOT__u_vram__DOT__wr_fire 
            = ((IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__aw_v) 
               & ((IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__w_v) 
                  & ((~ (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__s_bvalid)) 
                     | (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__s_bready))));
        vlSelfRef.ember_top__DOT__u_xbar__DOT__d_rvalid 
            = ((2U == (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__rstate)) 
               & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__v_rvalid));
        vlSelfRef.ember_top__DOT__u_xbar__DOT__d_bvalid 
            = ((2U == (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__wstate)) 
               & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__v_bvalid));
        vlSelfRef.ember_top__DOT__v_arready = vlSelfRef.ember_top__DOT__u_vram__DOT__s_arready;
        vlSelfRef.ember_top__DOT__u_vram__DOT__s_awready 
            = (1U & ((~ (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__aw_v)) 
                     | (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__wr_fire)));
        vlSelfRef.ember_top__DOT__u_vram__DOT__s_wready 
            = (1U & ((~ (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__w_v)) 
                     | (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__wr_fire)));
        vlSelfRef.ember_top__DOT__d_rvalid = vlSelfRef.ember_top__DOT__u_xbar__DOT__d_rvalid;
        vlSelfRef.ember_top__DOT__d_bvalid = vlSelfRef.ember_top__DOT__u_xbar__DOT__d_bvalid;
        vlSelfRef.ember_top__DOT__u_xbar__DOT__v_arready 
            = vlSelfRef.ember_top__DOT__v_arready;
        vlSelfRef.ember_top__DOT__v_awready = vlSelfRef.ember_top__DOT__u_vram__DOT__s_awready;
        vlSelfRef.ember_top__DOT__v_wready = vlSelfRef.ember_top__DOT__u_vram__DOT__s_wready;
        vlSelfRef.ember_top__DOT__u_cp__DOT__m_rvalid 
            = vlSelfRef.ember_top__DOT__d_rvalid;
        vlSelfRef.ember_top__DOT__u_cp__DOT__m_bvalid 
            = vlSelfRef.ember_top__DOT__d_bvalid;
        vlSelfRef.ember_top__DOT__u_xbar__DOT__v_awready 
            = vlSelfRef.ember_top__DOT__v_awready;
        vlSelfRef.ember_top__DOT__u_xbar__DOT__v_wready 
            = vlSelfRef.ember_top__DOT__v_wready;
        vlSelfRef.ember_top__DOT__u_cp__DOT__rb_push 
            = vlSelfRef.ember_top__DOT__u_cp__DOT__m_rvalid;
    }
    if ((0x0000000000000033ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_arready 
            = (1U & ((~ (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__ar_v)) 
                     | ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_rready) 
                        & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_rvalid))));
        vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__wr_fire 
            = ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__aw_v) 
               & ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__w_v) 
                  & ((~ (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_bvalid)) 
                     | (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_bready))));
        vlSelfRef.ember_top__DOT__u_cp__DOT__s_arready 
            = vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_arready;
        vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__ar_accept 
            = ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_arready) 
               & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_arvalid));
        vlSelfRef.ember_top__DOT__u_cp__DOT__rb_pop 
            = (((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__s_arvalid) 
                & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__s_arready)) 
               & (0x0000000000000080ULL == (0x0000000000007ff8ULL 
                                            & vlSelfRef.ember_top__DOT__u_cp__DOT__s_ar)));
        vlSelfRef.ember_top__DOT__c_arready = vlSelfRef.ember_top__DOT__u_cp__DOT__s_arready;
        vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__rd_addr 
            = ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__ar_accept)
                ? (0x00000fffU & (IData)((vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_ar 
                                          >> 3U))) : 0U);
        vlSelfRef.ember_top__DOT__u_xbar__DOT__c_arready 
            = vlSelfRef.ember_top__DOT__c_arready;
        vlSelfRef.ember_top__DOT__u_cp__DOT__rd_addr 
            = vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__rd_addr;
    }
    if ((0x0000000000c00000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__fpa3_req 
            = vlSelfRef.ember_top__DOT__fpa3_req;
        vlSelfRef.ember_top__DOT__u_vram__DOT__fpa3_widx 
            = (0x0001ffffU & ((vlSelfRef.ember_top__DOT__u_vram__DOT__fpa3_addr 
                               - (IData)(0x00001000U)) 
                              >> 2U));
    }
    if ((0x000000000100c000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.ember_top__DOT__u_gsx__DOT___unused 
            = (1U & (VL_REDXOR_32(vlSelfRef.ember_top__DOT__u_gsx__DOT__gxa_rdata) 
                     | (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__f_busy)));
    }
    if ((0x0000000001030000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.ember_top__DOT__u_blit__DOT__rdata_lane 
            = (0x0000ffffU & ((2U & vlSelfRef.ember_top__DOT__u_blit__DOT__saddr_q)
                               ? (vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_rdata 
                                  >> 0x00000010U) : vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_rdata));
        vlSelfRef.ember_top__DOT__u_blit__DOT__skip_c 
            = ((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__key_en_q) 
               & ((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__key_color_q) 
                  == (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__rdata_lane)));
    }
    if ((0x0000000001300000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__texel_shift 
            = (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa2_rdata 
               >> (0x00000018U & (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__tex_addr 
                                  << 3U)));
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__texel_byte 
            = (0x000000ffU & vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__texel_shift);
    }
    if ((0x0000000001000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.ember_top__DOT__u_core__DOT__ixa_rdata 
            = vlSelfRef.ember_top__DOT__core_ixa_rdata;
        vlSelfRef.ember_top__DOT__u_core__DOT__cxa_rdata 
            = vlSelfRef.ember_top__DOT__core_cxa_rdata;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__fpa_rdata 
            = vlSelfRef.ember_top__DOT__fpa_rdata;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_rdata 
            = vlSelfRef.ember_top__DOT__u_rtr__DOT__fpa_rdata;
    }
    if ((0x0000000000000c00ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.ember_top__DOT__u_core__DOT__f_done 
            = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__done;
        vlSelfRef.ember_top__DOT__u_core__DOT__f_y0 
            = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__y0;
    }
    if ((0x0000000000300000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_done 
            = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__done;
    }
    if ((0x00000000003c0000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.ember_top__DOT__u_rtr__DOT__busy 
            = ((0U != (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__fst)) 
               | (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_busy));
        vlSelfRef.ember_top__DOT__u_rtr__DOT__fpa_we 
            = ((~ (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__in_fetch)) 
               & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_we));
        if (vlSelfRef.ember_top__DOT__u_rtr__DOT__in_fetch) {
            vlSelfRef.ember_top__DOT__u_rtr__DOT__fpa_wdata = 0U;
            vlSelfRef.ember_top__DOT__u_rtr__DOT__fpa_be = 0x0fU;
            vlSelfRef.ember_top__DOT__u_rtr__DOT__fpa_req 
                = vlSelfRef.ember_top__DOT__u_rtr__DOT__fetch_req;
            vlSelfRef.ember_top__DOT__u_rtr__DOT__fpa_addr 
                = vlSelfRef.ember_top__DOT__u_rtr__DOT__fetch_addr;
        } else {
            vlSelfRef.ember_top__DOT__u_rtr__DOT__fpa_wdata 
                = vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_wdata;
            vlSelfRef.ember_top__DOT__u_rtr__DOT__fpa_be 
                = vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_be;
            vlSelfRef.ember_top__DOT__u_rtr__DOT__fpa_req 
                = vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_req;
            vlSelfRef.ember_top__DOT__u_rtr__DOT__fpa_addr 
                = vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_addr;
        }
        if (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__t_blend) {
            vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_r 
                = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__mr;
            vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_g 
                = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__mg;
            vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_b 
                = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__mb;
        } else {
            vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_r 
                = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cr;
            vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_g 
                = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cg;
            vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_b 
                = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cb;
        }
        vlSelfRef.ember_top__DOT__rtr_busy = vlSelfRef.ember_top__DOT__u_rtr__DOT__busy;
        vlSelfRef.ember_top__DOT__rtr_fpa_we = vlSelfRef.ember_top__DOT__u_rtr__DOT__fpa_we;
        vlSelfRef.ember_top__DOT__rtr_fpa_wdata = vlSelfRef.ember_top__DOT__u_rtr__DOT__fpa_wdata;
        vlSelfRef.ember_top__DOT__rtr_fpa_be = vlSelfRef.ember_top__DOT__u_rtr__DOT__fpa_be;
        vlSelfRef.ember_top__DOT__rtr_fpa_req = vlSelfRef.ember_top__DOT__u_rtr__DOT__fpa_req;
        vlSelfRef.ember_top__DOT__rtr_fpa_addr = vlSelfRef.ember_top__DOT__u_rtr__DOT__fpa_addr;
        if (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__t_dither) {
            if (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dith_up) {
                vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmr 
                    = (0x000000ffU & ((0xffU == (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_r))
                                       ? 0xffU : ((IData)(1U) 
                                                  + (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_r))));
                vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmg 
                    = (0x000000ffU & ((0xffU == (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_g))
                                       ? 0xffU : ((IData)(1U) 
                                                  + (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_g))));
                vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmb 
                    = (0x000000ffU & ((0xffU == (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_b))
                                       ? 0xffU : ((IData)(1U) 
                                                  + (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_b))));
            } else {
                vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmr 
                    = (0x000000ffU & ((0U == (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_r))
                                       ? 0U : ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_r) 
                                               - (IData)(1U))));
                vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmg 
                    = (0x000000ffU & ((0U == (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_g))
                                       ? 0U : ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_g) 
                                               - (IData)(1U))));
                vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmb 
                    = (0x000000ffU & ((0U == (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_b))
                                       ? 0U : ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_b) 
                                               - (IData)(1U))));
            }
        } else {
            vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmr 
                = (0x000000ffU & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_r));
            vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmg 
                = (0x000000ffU & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_g));
            vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmb 
                = (0x000000ffU & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_b));
        }
        vlSelfRef.ember_top__DOT__u_cp__DOT__rtr_busy 
            = vlSelfRef.ember_top__DOT__rtr_busy;
        vlSelfRef.ember_top__DOT__rtr_own = vlSelfRef.ember_top__DOT__rtr_busy;
    }
    if ((0x0000000000000030ULL & vlSelfRef.__VnbaTriggered[0U])) {
        if (vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__rst_n) {
            if (((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_wvalid) 
                 & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_wready))) {
                vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__w_q 
                    = vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_w;
            }
            if (((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_awvalid) 
                 & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_awready))) {
                vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__aw_q 
                    = vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_aw;
            }
        } else {
            vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__w_q = 0ULL;
            vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__aw_q = 0ULL;
        }
    }
    if ((0x0000000001000013ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.ember_top__DOT__u_xbar__DOT__h_r 
            = ((1U == (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__rstate))
                ? vlSelfRef.ember_top__DOT__u_xbar__DOT__v_r
                : vlSelfRef.ember_top__DOT__u_xbar__DOT__c_r);
        vlSelfRef.ember_top__DOT__h_r_s = vlSelfRef.ember_top__DOT__u_xbar__DOT__h_r;
        vlSelfRef.ember_top__DOT__h_rdata = (IData)(
                                                    (vlSelfRef.ember_top__DOT__h_r_s 
                                                     >> 2U));
        vlSelfRef.ember_top__DOT__h_rresp = (3U & (IData)(vlSelfRef.ember_top__DOT__h_r_s));
        vlSelfRef.h_rdata = vlSelfRef.ember_top__DOT__h_rdata;
        vlSelfRef.h_rresp = vlSelfRef.ember_top__DOT__h_rresp;
    }
    if ((0x00000000000000c0ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__25(vlSelf);
    }
    if ((0x000000000000000fULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.ember_top__DOT__u_xbar__DOT__r_fwd_d 
            = ((0U == (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__rstate)) 
               & ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__d_req_v_r) 
                  & ((~ (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__h_req_v_r)) 
                     | (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__r_favor_d))));
        vlSelfRef.ember_top__DOT__u_xbar__DOT__r_fwd_h 
            = ((0U == (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__rstate)) 
               & ((~ ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__d_req_v_r) 
                      & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__r_favor_d))) 
                  & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__h_req_v_r)));
        vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_d 
            = ((0U == (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__wstate)) 
               & ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__d_req_v_w) 
                  & ((~ (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__h_req_v_w)) 
                     | (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_favor_d))));
        vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_h 
            = ((0U == (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__wstate)) 
               & ((~ ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__d_req_v_w) 
                      & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_favor_d))) 
                  & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__h_req_v_w)));
        vlSelfRef.ember_top__DOT__u_xbar__DOT__v_ar 
            = ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__r_fwd_h)
                ? vlSelfRef.ember_top__DOT__u_xbar__DOT__h_ar
                : vlSelfRef.ember_top__DOT__u_xbar__DOT__d_ar);
        vlSelfRef.ember_top__DOT__u_xbar__DOT__v_arvalid 
            = ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__r_fwd_d) 
               | (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__r_fwd_h));
        vlSelfRef.ember_top__DOT__u_xbar__DOT__v_awvalid 
            = ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_d) 
               | (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_h));
        if (vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_h) {
            vlSelfRef.ember_top__DOT__u_xbar__DOT__v_aw 
                = vlSelfRef.ember_top__DOT__u_xbar__DOT__h_aw;
            vlSelfRef.ember_top__DOT__u_xbar__DOT__v_w 
                = vlSelfRef.ember_top__DOT__u_xbar__DOT__h_w;
        } else {
            vlSelfRef.ember_top__DOT__u_xbar__DOT__v_aw 
                = vlSelfRef.ember_top__DOT__u_xbar__DOT__d_aw;
            vlSelfRef.ember_top__DOT__u_xbar__DOT__v_w 
                = vlSelfRef.ember_top__DOT__u_xbar__DOT__d_w;
        }
        vlSelfRef.ember_top__DOT__u_xbar__DOT__v_wvalid 
            = (((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__h_wvalid) 
                & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_h)) 
               | ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__d_wvalid) 
                  & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_d)));
        vlSelfRef.ember_top__DOT__v_ar = vlSelfRef.ember_top__DOT__u_xbar__DOT__v_ar;
        vlSelfRef.ember_top__DOT__v_arvalid = vlSelfRef.ember_top__DOT__u_xbar__DOT__v_arvalid;
        vlSelfRef.ember_top__DOT__v_awvalid = vlSelfRef.ember_top__DOT__u_xbar__DOT__v_awvalid;
        vlSelfRef.ember_top__DOT__v_aw = vlSelfRef.ember_top__DOT__u_xbar__DOT__v_aw;
        vlSelfRef.ember_top__DOT__v_w = vlSelfRef.ember_top__DOT__u_xbar__DOT__v_w;
        vlSelfRef.ember_top__DOT__v_wvalid = vlSelfRef.ember_top__DOT__u_xbar__DOT__v_wvalid;
        vlSelfRef.ember_top__DOT__u_vram__DOT__s_ar 
            = vlSelfRef.ember_top__DOT__v_ar;
        vlSelfRef.ember_top__DOT__u_vram__DOT__s_arvalid 
            = vlSelfRef.ember_top__DOT__v_arvalid;
        vlSelfRef.ember_top__DOT__u_vram__DOT__s_awvalid 
            = vlSelfRef.ember_top__DOT__v_awvalid;
        vlSelfRef.ember_top__DOT__u_vram__DOT__s_aw 
            = vlSelfRef.ember_top__DOT__v_aw;
        vlSelfRef.ember_top__DOT__u_vram__DOT__s_w 
            = vlSelfRef.ember_top__DOT__v_w;
        vlSelfRef.ember_top__DOT__u_vram__DOT__s_wvalid 
            = vlSelfRef.ember_top__DOT__v_wvalid;
    }
    if ((0x00000000003f0000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.ember_top__DOT__blit_own = ((~ (IData)(vlSelfRef.ember_top__DOT__rtr_busy)) 
                                              & (IData)(vlSelfRef.ember_top__DOT__blit_busy));
        if (vlSelfRef.ember_top__DOT__rtr_own) {
            vlSelfRef.ember_top__DOT__fpa_we = vlSelfRef.ember_top__DOT__rtr_fpa_we;
            vlSelfRef.ember_top__DOT__fpa_wdata = vlSelfRef.ember_top__DOT__rtr_fpa_wdata;
            vlSelfRef.ember_top__DOT__fpa_be = vlSelfRef.ember_top__DOT__rtr_fpa_be;
            vlSelfRef.ember_top__DOT__fpa_req = vlSelfRef.ember_top__DOT__rtr_fpa_req;
            vlSelfRef.ember_top__DOT__fpa_addr = vlSelfRef.ember_top__DOT__rtr_fpa_addr;
        } else if (vlSelfRef.ember_top__DOT__blit_own) {
            vlSelfRef.ember_top__DOT__fpa_we = vlSelfRef.ember_top__DOT__blit_fpa_we;
            vlSelfRef.ember_top__DOT__fpa_wdata = vlSelfRef.ember_top__DOT__blit_fpa_wdata;
            vlSelfRef.ember_top__DOT__fpa_be = vlSelfRef.ember_top__DOT__blit_fpa_be;
            vlSelfRef.ember_top__DOT__fpa_addr = vlSelfRef.ember_top__DOT__blit_fpa_addr;
            vlSelfRef.ember_top__DOT__fpa_req = vlSelfRef.ember_top__DOT__blit_fpa_req;
        } else {
            vlSelfRef.ember_top__DOT__fpa_we = 0U;
            vlSelfRef.ember_top__DOT__fpa_wdata = 0U;
            vlSelfRef.ember_top__DOT__fpa_be = 0U;
            vlSelfRef.ember_top__DOT__fpa_addr = 0U;
            vlSelfRef.ember_top__DOT__fpa_req = 0U;
        }
        vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_we 
            = vlSelfRef.ember_top__DOT__fpa_we;
        vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_wdata 
            = vlSelfRef.ember_top__DOT__fpa_wdata;
        vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_be 
            = vlSelfRef.ember_top__DOT__fpa_be;
        vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_req 
            = vlSelfRef.ember_top__DOT__fpa_req;
        vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_addr 
            = vlSelfRef.ember_top__DOT__fpa_addr;
        vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_widx 
            = (0x0001ffffU & ((vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_addr 
                               - (IData)(0x00001000U)) 
                              >> 2U));
    }
    if ((0x0000000000000033ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_wready 
            = (1U & ((~ (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__w_v)) 
                     | (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__wr_fire)));
        vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_awready 
            = (1U & ((~ (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__aw_v)) 
                     | (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__wr_fire)));
        vlSelfRef.ember_top__DOT__u_cp__DOT__s_wready 
            = vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_wready;
        vlSelfRef.ember_top__DOT__u_cp__DOT__s_awready 
            = vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_awready;
        vlSelfRef.ember_top__DOT__c_wready = vlSelfRef.ember_top__DOT__u_cp__DOT__s_wready;
        vlSelfRef.ember_top__DOT__c_awready = vlSelfRef.ember_top__DOT__u_cp__DOT__s_awready;
        vlSelfRef.ember_top__DOT__u_xbar__DOT__c_wready 
            = vlSelfRef.ember_top__DOT__c_wready;
        vlSelfRef.ember_top__DOT__u_xbar__DOT__c_awready 
            = vlSelfRef.ember_top__DOT__c_awready;
    }
    if ((0x0000000001000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__tua_rdata 
            = vlSelfRef.ember_top__DOT__tu_tua_rdata;
    }
    if ((0x0000000000000010ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__kick = vlSelfRef.ember_top__DOT__tu_kick;
        vlSelfRef.ember_top__DOT__u_tu__DOT__csr_we 
            = vlSelfRef.ember_top__DOT__tu_csr_we;
        vlSelfRef.ember_top__DOT__u_tu__DOT__csr_addr 
            = vlSelfRef.ember_top__DOT__tu_csr_addr;
        vlSelfRef.ember_top__DOT__u_tu__DOT__csr_wdata 
            = vlSelfRef.ember_top__DOT__tu_csr_wdata;
        __Vinline__nba_sequent__TOP__27_ember_top__DOT__u_tu__DOT____VdfgRegularize_h0ebfa33a_0_0 
            = ((IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__csr_we) 
               & (3U == (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__csr_addr)));
        vlSelfRef.ember_top__DOT__u_tu__DOT__cfg2_dim_we 
            = (__Vinline__nba_sequent__TOP__27_ember_top__DOT__u_tu__DOT____VdfgRegularize_h0ebfa33a_0_0 
               & (0U == (vlSelfRef.ember_top__DOT__u_tu__DOT__csr_wdata 
                         >> 0x0000001eU)));
        vlSelfRef.ember_top__DOT__u_tu__DOT__cfg2_m_we 
            = (__Vinline__nba_sequent__TOP__27_ember_top__DOT__u_tu__DOT____VdfgRegularize_h0ebfa33a_0_0 
               & (1U == (vlSelfRef.ember_top__DOT__u_tu__DOT__csr_wdata 
                         >> 0x0000001eU)));
        vlSelfRef.ember_top__DOT__u_tu__DOT__cfg2_q_we 
            = (__Vinline__nba_sequent__TOP__27_ember_top__DOT__u_tu__DOT____VdfgRegularize_h0ebfa33a_0_0 
               & (2U == (vlSelfRef.ember_top__DOT__u_tu__DOT__csr_wdata 
                         >> 0x0000001eU)));
    }
    if ((0x00000000000000c0ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__11(vlSelf);
    }
    if ((0x00000000003f33ffULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.ember_top__DOT__u_cp__DOT__rd_data 
            = ((0U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rd_addr))
                ? 0xeb220002U : ((4U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rd_addr))
                                  ? (((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__tu_busy) 
                                      << 0x0000000aU) 
                                     | ((((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__core_busy) 
                                          << 9U) | 
                                         (((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__gsx_busy) 
                                           << 8U) | 
                                          ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__blit_busy) 
                                           << 7U))) 
                                        | (((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rb_count) 
                                            << 3U) 
                                           | (((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rb_empty) 
                                               << 2U) 
                                              | (((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rtr_busy) 
                                                  << 1U) 
                                                 | (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__dma_busy_q))))))
                                  : ((0x000cU == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rd_addr))
                                      ? (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__fence_done_q)
                                      : ((0x0010U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rd_addr))
                                          ? ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rb_empty)
                                              ? 0U : vlSelfRef.ember_top__DOT__u_cp__DOT__rb_mem
                                             [(7U & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rb_rp))])
                                          : ((0x0014U 
                                              == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rd_addr))
                                              ? vlSelfRef.ember_top__DOT__u_cp__DOT__dma_dst_q
                                              : ((0x0018U 
                                                  == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__rd_addr))
                                                  ? vlSelfRef.ember_top__DOT__u_cp__DOT__dma_len_q
                                                  : 0U))))));
        vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__rd_data 
            = vlSelfRef.ember_top__DOT__u_cp__DOT__rd_data;
    }
    if ((0x000000000300000fULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.ember_top__DOT__u_xbar__DOT__d_arready 
            = ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__r_fwd_d) 
               & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__v_arready));
        vlSelfRef.ember_top__DOT__u_xbar__DOT__d_awready 
            = ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__v_awready) 
               & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_d));
        vlSelfRef.ember_top__DOT__u_xbar__DOT__d_wready 
            = ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__v_wready) 
               & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_d));
        vlSelfRef.ember_top__DOT__u_vram__DOT__ar_accept 
            = ((IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__s_arready) 
               & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__s_arvalid));
        vlSelfRef.ember_top__DOT__d_arready = vlSelfRef.ember_top__DOT__u_xbar__DOT__d_arready;
        vlSelfRef.ember_top__DOT__d_awready = vlSelfRef.ember_top__DOT__u_xbar__DOT__d_awready;
        vlSelfRef.ember_top__DOT__d_wready = vlSelfRef.ember_top__DOT__u_xbar__DOT__d_wready;
        vlSelfRef.ember_top__DOT__u_cp__DOT__m_arready 
            = vlSelfRef.ember_top__DOT__d_arready;
        vlSelfRef.ember_top__DOT__u_cp__DOT__m_awready 
            = vlSelfRef.ember_top__DOT__d_awready;
        vlSelfRef.ember_top__DOT__u_cp__DOT__m_wready 
            = vlSelfRef.ember_top__DOT__d_wready;
    }
    if ((0x000000000300003fULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.ember_top__DOT__u_xbar__DOT__h_arready 
            = ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__h_ar_is_cp)
                ? (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__c_arready)
                : ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__r_fwd_h) 
                   & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__v_arready)));
        if (vlSelfRef.ember_top__DOT__u_xbar__DOT__h_aw_is_cp) {
            vlSelfRef.ember_top__DOT__u_xbar__DOT__h_wready 
                = vlSelfRef.ember_top__DOT__u_xbar__DOT__c_wready;
            vlSelfRef.ember_top__DOT__u_xbar__DOT__h_awready 
                = vlSelfRef.ember_top__DOT__u_xbar__DOT__c_awready;
        } else {
            vlSelfRef.ember_top__DOT__u_xbar__DOT__h_wready 
                = ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__v_wready) 
                   & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_h));
            vlSelfRef.ember_top__DOT__u_xbar__DOT__h_awready 
                = ((IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__v_awready) 
                   & (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__w_fwd_h));
        }
        vlSelfRef.ember_top__DOT__h_arready = vlSelfRef.ember_top__DOT__u_xbar__DOT__h_arready;
        vlSelfRef.ember_top__DOT__h_wready = vlSelfRef.ember_top__DOT__u_xbar__DOT__h_wready;
        vlSelfRef.ember_top__DOT__h_awready = vlSelfRef.ember_top__DOT__u_xbar__DOT__h_awready;
        vlSelfRef.h_arready = vlSelfRef.ember_top__DOT__h_arready;
        vlSelfRef.h_wready = vlSelfRef.ember_top__DOT__h_wready;
        vlSelfRef.h_awready = vlSelfRef.ember_top__DOT__h_awready;
    }
}

void Vtop___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

void Vtop___024root___eval_triggers_vec__act(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_triggers_vec__act(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtop___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vtop___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        Vtop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf);

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("../rtl/../rtl/ember_top.sv", 19, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = Vtop___024root___eval_phase__ico(vlSelf);
        vlSelfRef.__VicoFirstIteration = 0U;
    } while (vlSelfRef.__VicoPhaseResult);
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("../rtl/../rtl/ember_top.sv", 19, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("../rtl/../rtl/ember_top.sv", 19, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = Vtop___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtop___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
