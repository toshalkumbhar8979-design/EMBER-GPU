// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->ember_top__DOT__u_core__DOT__unnamedblk7__DOT__d = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8298515114129936708ull);
    vlSelfRef.__Vtrigprevexpr___TOP__ember_top__DOT__u_xbar__DOT__clk__0 
        = vlSelfRef.ember_top__DOT__u_xbar__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__ember_top__DOT__u_xbar__DOT__rst_n__0 
        = vlSelfRef.ember_top__DOT__u_xbar__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__ember_top__DOT__u_cp__DOT__clk__0 
        = vlSelfRef.ember_top__DOT__u_cp__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__ember_top__DOT__u_cp__DOT__rst_n__0 
        = vlSelfRef.ember_top__DOT__u_cp__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__ember_top__DOT__u_cp__DOT__u_regs__DOT__clk__0 
        = vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__ember_top__DOT__u_cp__DOT__u_regs__DOT__rst_n__0 
        = vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__ember_top__DOT__u_tu__DOT__clk__0 
        = vlSelfRef.ember_top__DOT__u_tu__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__ember_top__DOT__u_tu__DOT__rst_n__0 
        = vlSelfRef.ember_top__DOT__u_tu__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__ember_top__DOT__u_core__DOT__clk__0 
        = vlSelfRef.ember_top__DOT__u_core__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__ember_top__DOT__u_core__DOT__rst_n__0 
        = vlSelfRef.ember_top__DOT__u_core__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__ember_top__DOT__u_core__DOT__u_fpu__DOT__clk__0 
        = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__ember_top__DOT__u_core__DOT__u_fpu__DOT__rst_n__0 
        = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__ember_top__DOT__u_gsx__DOT__clk__0 
        = vlSelfRef.ember_top__DOT__u_gsx__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__ember_top__DOT__u_gsx__DOT__rst_n__0 
        = vlSelfRef.ember_top__DOT__u_gsx__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__clk__0 
        = vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__rst_n__0 
        = vlSelfRef.ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__ember_top__DOT__u_blit__DOT__clk__0 
        = vlSelfRef.ember_top__DOT__u_blit__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__ember_top__DOT__u_blit__DOT__rst_n__0 
        = vlSelfRef.ember_top__DOT__u_blit__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__ember_top__DOT__u_rtr__DOT__clk__0 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__ember_top__DOT__u_rtr__DOT__rst_n__0 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__ember_top__DOT__u_rtr__DOT__u_scan__DOT__clk__0 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__ember_top__DOT__u_rtr__DOT__u_scan__DOT__rst_n__0 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__ember_top__DOT__u_disp__DOT__clk__0 
        = vlSelfRef.ember_top__DOT__u_disp__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__ember_top__DOT__u_disp__DOT__rst_n__0 
        = vlSelfRef.ember_top__DOT__u_disp__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__ember_top__DOT__u_vram__DOT__clk__0 
        = vlSelfRef.ember_top__DOT__u_vram__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__ember_top__DOT__u_vram__DOT__rst_n__0 
        = vlSelfRef.ember_top__DOT__u_vram__DOT__rst_n;
}

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->ember_top__DOT__u_core__DOT__unnamedblk7__DOT__d = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8298515114129936708ull);
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ember_top__DOT__fpa2_we = 0U;
    vlSelfRef.ember_top__DOT__fpa2_wdata = 0U;
    vlSelfRef.ember_top__DOT__fpa2_be = 0U;
    vlSelfRef.ember_top__DOT__u_cp__DOT__m_bready = 1U;
    vlSelfRef.ember_top__DOT__u_cp__DOT__m_rready = 1U;
    vlSelfRef.ember_top__DOT__u_gsx__DOT__unnamedblk1__DOT__r = 0U;
    while (VL_GTS_III(32, 4U, vlSelfRef.ember_top__DOT__u_gsx__DOT__unnamedblk1__DOT__r)) {
        vlSelfRef.ember_top__DOT__u_gsx__DOT__unnamedblk1__DOT__unnamedblk2__DOT__c = 0U;
        while (VL_GTS_III(32, 4U, vlSelfRef.ember_top__DOT__u_gsx__DOT__unnamedblk1__DOT__unnamedblk2__DOT__c)) {
            vlSelfRef.ember_top__DOT__u_gsx__DOT__mata[(0x0000000fU 
                                                        & (VL_MULS_III(32, (IData)(4U), vlSelfRef.ember_top__DOT__u_gsx__DOT__unnamedblk1__DOT__r) 
                                                           + vlSelfRef.ember_top__DOT__u_gsx__DOT__unnamedblk1__DOT__unnamedblk2__DOT__c))] 
                = ((vlSelfRef.ember_top__DOT__u_gsx__DOT__unnamedblk1__DOT__r 
                    == vlSelfRef.ember_top__DOT__u_gsx__DOT__unnamedblk1__DOT__unnamedblk2__DOT__c)
                    ? 0x3f800000U : 0U);
            vlSelfRef.ember_top__DOT__u_gsx__DOT__unnamedblk1__DOT__unnamedblk2__DOT__c 
                = ((IData)(1U) + vlSelfRef.ember_top__DOT__u_gsx__DOT__unnamedblk1__DOT__unnamedblk2__DOT__c);
        }
        vlSelfRef.ember_top__DOT__u_gsx__DOT__unnamedblk1__DOT__r 
            = ((IData)(1U) + vlSelfRef.ember_top__DOT__u_gsx__DOT__unnamedblk1__DOT__r);
    }
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__one0[0U] = 0x00400000U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__one0[1U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__one0[2U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__zero96[0U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__zero96[1U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__zero96[2U] = 0U;
    vlSelfRef.ember_top__DOT__u_xbar__DOT__d_bready = 1U;
    vlSelfRef.ember_top__DOT__d_bready = 1U;
    vlSelfRef.ember_top__DOT__u_xbar__DOT__d_rready = 1U;
    vlSelfRef.ember_top__DOT__d_rready = 1U;
    vlSelfRef.ember_top__DOT__u_xbar__DOT___unused_dma_rdy = 1U;
    vlSelfRef.ember_top__DOT__u_vram__DOT__fpa2_we = 0U;
    vlSelfRef.ember_top__DOT__u_vram__DOT__fpa2_wdata = 0U;
    vlSelfRef.ember_top__DOT__u_vram__DOT__fpa2_be = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__iwA = 0ULL;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__iwB = 0ULL;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ember_top__DOT__fpa2_we = 0U;
    vlSelfRef.ember_top__DOT__fpa2_wdata = 0U;
    vlSelfRef.ember_top__DOT__fpa2_be = 0U;
    vlSelfRef.ember_top__DOT__u_cp__DOT__m_bready = 1U;
    vlSelfRef.ember_top__DOT__u_cp__DOT__m_rready = 1U;
    vlSelfRef.ember_top__DOT__u_gsx__DOT__unnamedblk1__DOT__r = 0U;
    while (VL_GTS_III(32, 4U, vlSelfRef.ember_top__DOT__u_gsx__DOT__unnamedblk1__DOT__r)) {
        vlSelfRef.ember_top__DOT__u_gsx__DOT__unnamedblk1__DOT__unnamedblk2__DOT__c = 0U;
        while (VL_GTS_III(32, 4U, vlSelfRef.ember_top__DOT__u_gsx__DOT__unnamedblk1__DOT__unnamedblk2__DOT__c)) {
            vlSelfRef.ember_top__DOT__u_gsx__DOT__mata[(0x0000000fU 
                                                        & (VL_MULS_III(32, (IData)(4U), vlSelfRef.ember_top__DOT__u_gsx__DOT__unnamedblk1__DOT__r) 
                                                           + vlSelfRef.ember_top__DOT__u_gsx__DOT__unnamedblk1__DOT__unnamedblk2__DOT__c))] 
                = ((vlSelfRef.ember_top__DOT__u_gsx__DOT__unnamedblk1__DOT__r 
                    == vlSelfRef.ember_top__DOT__u_gsx__DOT__unnamedblk1__DOT__unnamedblk2__DOT__c)
                    ? 0x3f800000U : 0U);
            vlSelfRef.ember_top__DOT__u_gsx__DOT__unnamedblk1__DOT__unnamedblk2__DOT__c 
                = ((IData)(1U) + vlSelfRef.ember_top__DOT__u_gsx__DOT__unnamedblk1__DOT__unnamedblk2__DOT__c);
        }
        vlSelfRef.ember_top__DOT__u_gsx__DOT__unnamedblk1__DOT__r 
            = ((IData)(1U) + vlSelfRef.ember_top__DOT__u_gsx__DOT__unnamedblk1__DOT__r);
    }
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__one0[0U] = 0x00400000U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__one0[1U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__one0[2U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__zero96[0U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__zero96[1U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__zero96[2U] = 0U;
    vlSelfRef.ember_top__DOT__u_xbar__DOT__d_bready = 1U;
    vlSelfRef.ember_top__DOT__d_bready = 1U;
    vlSelfRef.ember_top__DOT__u_xbar__DOT__d_rready = 1U;
    vlSelfRef.ember_top__DOT__d_rready = 1U;
    vlSelfRef.ember_top__DOT__u_xbar__DOT___unused_dma_rdy = 1U;
    vlSelfRef.ember_top__DOT__u_vram__DOT__fpa2_we = 0U;
    vlSelfRef.ember_top__DOT__u_vram__DOT__fpa2_wdata = 0U;
    vlSelfRef.ember_top__DOT__u_vram__DOT__fpa2_be = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__iwA = 0ULL;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__iwB = 0ULL;
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("../rtl/../rtl/ember_top.sv", 19, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vtop___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void Vtop___024root___eval_triggers_vec__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers_vec__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__stl\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtop___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge ember_top.u_xbar.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge ember_top.u_xbar.rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge ember_top.u_cp.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @(negedge ember_top.u_cp.rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @(posedge ember_top.u_cp.u_regs.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 5 is active: @(negedge ember_top.u_cp.u_regs.rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 6U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 6 is active: @(posedge ember_top.u_tu.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 7U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 7 is active: @(negedge ember_top.u_tu.rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 8U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 8 is active: @(posedge ember_top.u_core.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 9U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 9 is active: @(negedge ember_top.u_core.rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 10 is active: @(posedge ember_top.u_core.u_fpu.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 11 is active: @(negedge ember_top.u_core.u_fpu.rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 12 is active: @(posedge ember_top.u_gsx.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 13 is active: @(negedge ember_top.u_gsx.rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 14 is active: @(posedge ember_top.u_gsx.u_fpu4.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 15 is active: @(negedge ember_top.u_gsx.u_fpu4.rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000010U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 16 is active: @(posedge ember_top.u_blit.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000011U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 17 is active: @(negedge ember_top.u_blit.rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000012U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 18 is active: @(posedge ember_top.u_rtr.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000013U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 19 is active: @(negedge ember_top.u_rtr.rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000014U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 20 is active: @(posedge ember_top.u_rtr.u_scan.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000015U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 21 is active: @(negedge ember_top.u_rtr.u_scan.rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000016U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 22 is active: @(posedge ember_top.u_disp.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000017U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 23 is active: @(negedge ember_top.u_disp.rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000018U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 24 is active: @(posedge ember_top.u_vram.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000019U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 25 is active: @(negedge ember_top.u_vram.rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1638864771569018232ull);
    vlSelf->h_awaddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3306186483967881600ull);
    vlSelf->h_awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13570373602649413477ull);
    vlSelf->h_awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3389818109297257616ull);
    vlSelf->h_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5819285853907503039ull);
    vlSelf->h_wstrb = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13639240242030129617ull);
    vlSelf->h_wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4090680317215470225ull);
    vlSelf->h_wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3573981534423277325ull);
    vlSelf->h_bresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2239738881706922289ull);
    vlSelf->h_bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15371412215984052598ull);
    vlSelf->h_bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10797290551271487044ull);
    vlSelf->h_araddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13179856835101957988ull);
    vlSelf->h_arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9579488921823352526ull);
    vlSelf->h_arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5308879850375787658ull);
    vlSelf->h_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6336386317323453880ull);
    vlSelf->h_rresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4005771449608891161ull);
    vlSelf->h_rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10952269614062799456ull);
    vlSelf->h_rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11694245265886500392ull);
    vlSelf->dbg_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5810739621415215736ull);
    vlSelf->dbg_addr = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 10106814393097140953ull);
    vlSelf->dbg_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8642705063052842340ull);
    vlSelf->dbg_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 41959679698862960ull);
    vlSelf->dbg_be = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17709635870257393668ull);
    vlSelf->fb_select = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1650786449057680841ull);
    vlSelf->vid_hs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1043177629514943138ull);
    vlSelf->vid_vs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8968019895989120734ull);
    vlSelf->vid_de = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8410564023838534647ull);
    vlSelf->vid_pixel = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9079266898354527289ull);
    vlSelf->ember_top__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15153203439624010667ull);
    vlSelf->ember_top__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 844773040974842218ull);
    vlSelf->ember_top__DOT__h_awaddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17219623180355370015ull);
    vlSelf->ember_top__DOT__h_awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13855771405816893368ull);
    vlSelf->ember_top__DOT__h_awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4066047120356560615ull);
    vlSelf->ember_top__DOT__h_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11228181935060224982ull);
    vlSelf->ember_top__DOT__h_wstrb = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17946492714223892681ull);
    vlSelf->ember_top__DOT__h_wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7772640871667528020ull);
    vlSelf->ember_top__DOT__h_wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6293751037400309778ull);
    vlSelf->ember_top__DOT__h_bresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7455015464152105713ull);
    vlSelf->ember_top__DOT__h_bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 119428876552759972ull);
    vlSelf->ember_top__DOT__h_bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15005176992346621683ull);
    vlSelf->ember_top__DOT__h_araddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13683603900671840319ull);
    vlSelf->ember_top__DOT__h_arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2430299003385291772ull);
    vlSelf->ember_top__DOT__h_arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1171093835863840633ull);
    vlSelf->ember_top__DOT__h_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14082668950408529124ull);
    vlSelf->ember_top__DOT__h_rresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2609626215677864675ull);
    vlSelf->ember_top__DOT__h_rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3404861824296060760ull);
    vlSelf->ember_top__DOT__h_rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16343719923432101285ull);
    vlSelf->ember_top__DOT__dbg_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2289196326521876756ull);
    vlSelf->ember_top__DOT__dbg_addr = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 4207734605569616016ull);
    vlSelf->ember_top__DOT__dbg_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5014941262939174120ull);
    vlSelf->ember_top__DOT__dbg_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16221376979200841474ull);
    vlSelf->ember_top__DOT__dbg_be = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14983133773112985445ull);
    vlSelf->ember_top__DOT__fb_select = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14133903197918214316ull);
    vlSelf->ember_top__DOT__vid_hs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5147171039963939895ull);
    vlSelf->ember_top__DOT__vid_vs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 987488834340163901ull);
    vlSelf->ember_top__DOT__vid_de = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5884347223345356431ull);
    vlSelf->ember_top__DOT__vid_pixel = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9298475041281213469ull);
    vlSelf->ember_top__DOT__h_aw_s = VL_SCOPED_RAND_RESET_Q(35, __VscopeHash, 7479791223495171904ull);
    vlSelf->ember_top__DOT__h_w_s = VL_SCOPED_RAND_RESET_Q(36, __VscopeHash, 6754270863640085244ull);
    vlSelf->ember_top__DOT__h_b_s = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16422423771079877227ull);
    vlSelf->ember_top__DOT__h_ar_s = VL_SCOPED_RAND_RESET_Q(35, __VscopeHash, 18304264440656472514ull);
    vlSelf->ember_top__DOT__h_r_s = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 4804251288369548594ull);
    vlSelf->ember_top__DOT__c_aw = VL_SCOPED_RAND_RESET_Q(35, __VscopeHash, 10278294699114927143ull);
    vlSelf->ember_top__DOT__c_awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15096621808591863668ull);
    vlSelf->ember_top__DOT__c_awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11723547455508137683ull);
    vlSelf->ember_top__DOT__c_w = VL_SCOPED_RAND_RESET_Q(36, __VscopeHash, 8863572520942267842ull);
    vlSelf->ember_top__DOT__c_wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7456034758560310558ull);
    vlSelf->ember_top__DOT__c_wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12761251655472672991ull);
    vlSelf->ember_top__DOT__c_b = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9881059551806651411ull);
    vlSelf->ember_top__DOT__c_bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15012740997800441387ull);
    vlSelf->ember_top__DOT__c_bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16296491266507816176ull);
    vlSelf->ember_top__DOT__c_ar = VL_SCOPED_RAND_RESET_Q(35, __VscopeHash, 17209557417542637718ull);
    vlSelf->ember_top__DOT__c_arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17797164352386383958ull);
    vlSelf->ember_top__DOT__c_arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3842846942471856779ull);
    vlSelf->ember_top__DOT__c_r = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 4908699212764208707ull);
    vlSelf->ember_top__DOT__c_rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16262360189080963524ull);
    vlSelf->ember_top__DOT__c_rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9860881904685560390ull);
    vlSelf->ember_top__DOT__d_aw = VL_SCOPED_RAND_RESET_Q(35, __VscopeHash, 13556025948254131716ull);
    vlSelf->ember_top__DOT__d_awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4759319797616863243ull);
    vlSelf->ember_top__DOT__d_awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15708146869662205927ull);
    vlSelf->ember_top__DOT__d_w = VL_SCOPED_RAND_RESET_Q(36, __VscopeHash, 5015367936795018720ull);
    vlSelf->ember_top__DOT__d_wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9521348423987339031ull);
    vlSelf->ember_top__DOT__d_wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4263264921245028097ull);
    vlSelf->ember_top__DOT__d_b = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16987086895548288608ull);
    vlSelf->ember_top__DOT__d_bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6886397891078517766ull);
    vlSelf->ember_top__DOT__d_bready = 1U;
    ;
    vlSelf->ember_top__DOT__d_ar = VL_SCOPED_RAND_RESET_Q(35, __VscopeHash, 16224916298071126404ull);
    vlSelf->ember_top__DOT__d_arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16102993942059682060ull);
    vlSelf->ember_top__DOT__d_arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12050172132567258740ull);
    vlSelf->ember_top__DOT__d_r = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 851037186917432337ull);
    vlSelf->ember_top__DOT__d_rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5723745467726899885ull);
    vlSelf->ember_top__DOT__d_rready = 1U;
    ;
    vlSelf->ember_top__DOT__v_aw = VL_SCOPED_RAND_RESET_Q(35, __VscopeHash, 4737466178414431296ull);
    vlSelf->ember_top__DOT__v_awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 397283281546283384ull);
    vlSelf->ember_top__DOT__v_awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1797010178437612232ull);
    vlSelf->ember_top__DOT__v_w = VL_SCOPED_RAND_RESET_Q(36, __VscopeHash, 16164590045039379994ull);
    vlSelf->ember_top__DOT__v_wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6310509839659035648ull);
    vlSelf->ember_top__DOT__v_wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11354429936261949095ull);
    vlSelf->ember_top__DOT__v_b = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13143085940199146065ull);
    vlSelf->ember_top__DOT__v_bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14286228914736132182ull);
    vlSelf->ember_top__DOT__v_bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5639861653151959144ull);
    vlSelf->ember_top__DOT__v_ar = VL_SCOPED_RAND_RESET_Q(35, __VscopeHash, 6186895108747600741ull);
    vlSelf->ember_top__DOT__v_arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12499026952872256353ull);
    vlSelf->ember_top__DOT__v_arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16441174400951761280ull);
    vlSelf->ember_top__DOT__v_r = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 121156325105999257ull);
    vlSelf->ember_top__DOT__v_rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15732993925952350441ull);
    vlSelf->ember_top__DOT__v_rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13860764010093340081ull);
    vlSelf->ember_top__DOT__fpa_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6461890578644167811ull);
    vlSelf->ember_top__DOT__fpa_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3347653616542648243ull);
    vlSelf->ember_top__DOT__fpa_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3285106888571511347ull);
    vlSelf->ember_top__DOT__fpa_be = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7703112974524473143ull);
    vlSelf->ember_top__DOT__fpa_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3006560008492964337ull);
    vlSelf->ember_top__DOT__fpa_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11687979080684818797ull);
    vlSelf->ember_top__DOT__fpa2_we = 0U;
    ;
    vlSelf->ember_top__DOT__fpa2_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13073678627600313948ull);
    vlSelf->ember_top__DOT__fpa2_wdata = 0U;
    ;
    vlSelf->ember_top__DOT__fpa2_be = 0U;
    ;
    vlSelf->ember_top__DOT__fpa2_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8249756483020331864ull);
    vlSelf->ember_top__DOT__fpa2_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1091527579477103537ull);
    vlSelf->ember_top__DOT__fpa3_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16419461418630250801ull);
    vlSelf->ember_top__DOT__fpa3_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13230775996676548038ull);
    vlSelf->ember_top__DOT__fpa3_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9900849213953120147ull);
    vlSelf->ember_top__DOT__rtr_kick = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10027660763491886043ull);
    vlSelf->ember_top__DOT__rtr_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17778474834018118610ull);
    vlSelf->ember_top__DOT__blit_csr_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13311603843269742472ull);
    vlSelf->ember_top__DOT__blit_kick = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 943104091096700758ull);
    vlSelf->ember_top__DOT__blit_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18410170444642101486ull);
    vlSelf->ember_top__DOT__blit_csr_addr = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13208025950201327600ull);
    vlSelf->ember_top__DOT__blit_csr_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13410407370715156322ull);
    vlSelf->ember_top__DOT__blit_fpa_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2092103420301098712ull);
    vlSelf->ember_top__DOT__blit_fpa_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14450687367428301262ull);
    vlSelf->ember_top__DOT__blit_fpa_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 496331637362904596ull);
    vlSelf->ember_top__DOT__blit_fpa_be = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3777494253635466509ull);
    vlSelf->ember_top__DOT__blit_fpa_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14090044393759503281ull);
    vlSelf->ember_top__DOT__gsx_csr_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16112054286606912526ull);
    vlSelf->ember_top__DOT__gsx_kick = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 497946833918341822ull);
    vlSelf->ember_top__DOT__gsx_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15759692772897374116ull);
    vlSelf->ember_top__DOT__gsx_csr_addr = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14202250708844840393ull);
    vlSelf->ember_top__DOT__gsx_csr_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4596476475383339556ull);
    vlSelf->ember_top__DOT__gsx_gxa_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6393376185446259161ull);
    vlSelf->ember_top__DOT__gsx_gxa_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4800982326302161237ull);
    vlSelf->ember_top__DOT__gsx_gxa_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3364213157518520172ull);
    vlSelf->ember_top__DOT__gsx_gxa_be = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6749503045652272404ull);
    vlSelf->ember_top__DOT__gsx_gxa_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13245345030720762149ull);
    vlSelf->ember_top__DOT__gsx_gxa_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7208519123675077971ull);
    vlSelf->ember_top__DOT__core_csr_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9892752774504708625ull);
    vlSelf->ember_top__DOT__core_kick = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8149909137065412741ull);
    vlSelf->ember_top__DOT__core_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18224464999378323584ull);
    vlSelf->ember_top__DOT__core_csr_addr = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6646340753003397892ull);
    vlSelf->ember_top__DOT__core_csr_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17864169434700480442ull);
    vlSelf->ember_top__DOT__core_cxa_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8228134039674068401ull);
    vlSelf->ember_top__DOT__core_cxa_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4305248766777142669ull);
    vlSelf->ember_top__DOT__core_cxa_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16909723206464474343ull);
    vlSelf->ember_top__DOT__core_cxa_be = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9542314166072740438ull);
    vlSelf->ember_top__DOT__core_cxa_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12251406981508800935ull);
    vlSelf->ember_top__DOT__core_cxa_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 899226097029654735ull);
    vlSelf->ember_top__DOT__core_ixa_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11942012129297988638ull);
    vlSelf->ember_top__DOT__core_ixa_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18279658278607855748ull);
    vlSelf->ember_top__DOT__core_ixa_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15674944715944680048ull);
    vlSelf->ember_top__DOT__tu_csr_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11877474364952293348ull);
    vlSelf->ember_top__DOT__tu_kick = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4514273452646870770ull);
    vlSelf->ember_top__DOT__tu_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14432395807915391385ull);
    vlSelf->ember_top__DOT__tu_csr_addr = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 614879686060657330ull);
    vlSelf->ember_top__DOT__tu_csr_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7690495686382085444ull);
    vlSelf->ember_top__DOT__tu_tua_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15057867375882867276ull);
    vlSelf->ember_top__DOT__tu_tua_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8464832792458114161ull);
    vlSelf->ember_top__DOT__tu_tua_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15042200261744185807ull);
    vlSelf->ember_top__DOT__tu_tua_be = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10190296083044749415ull);
    vlSelf->ember_top__DOT__tu_tua_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3952300436596455090ull);
    vlSelf->ember_top__DOT__tu_tua_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2881373757430209364ull);
    vlSelf->ember_top__DOT__rtr_fpa_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 333187180505242565ull);
    vlSelf->ember_top__DOT__rtr_fpa_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16164329029828369970ull);
    vlSelf->ember_top__DOT__rtr_fpa_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2789103369297589344ull);
    vlSelf->ember_top__DOT__rtr_fpa_be = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14174612657676081ull);
    vlSelf->ember_top__DOT__rtr_fpa_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10830867195845676654ull);
    vlSelf->ember_top__DOT__rtr_own = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12902535924855438945ull);
    vlSelf->ember_top__DOT__blit_own = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11581124181712103711ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16786309615167641926ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5271111842723768199ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__h_aw = VL_SCOPED_RAND_RESET_Q(35, __VscopeHash, 8466638684576311439ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__h_awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17061234116126836526ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__h_awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4439997540054381566ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__h_w = VL_SCOPED_RAND_RESET_Q(36, __VscopeHash, 18073172784881668369ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__h_wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4925225169622833413ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__h_wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5144233805447974625ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__h_b = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7640685074179642209ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__h_bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8857387631718361190ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__h_bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4514046211688678642ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__h_ar = VL_SCOPED_RAND_RESET_Q(35, __VscopeHash, 18316526263915463350ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__h_arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4891760896315273995ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__h_arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16622291614494084572ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__h_r = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 11871845749335047216ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__h_rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12846172844688459367ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__h_rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15529932782812943808ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__d_aw = VL_SCOPED_RAND_RESET_Q(35, __VscopeHash, 8201846936881109153ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__d_awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2886421196626715863ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__d_awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4725354875130589332ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__d_w = VL_SCOPED_RAND_RESET_Q(36, __VscopeHash, 3652251497619794572ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__d_wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13716447227929863919ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__d_wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6065480515400669702ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__d_b = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16338041312962573909ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__d_bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2300283389736114609ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__d_bready = 1U;
    ;
    vlSelf->ember_top__DOT__u_xbar__DOT__d_ar = VL_SCOPED_RAND_RESET_Q(35, __VscopeHash, 14037905109315912070ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__d_arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4409421121372074855ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__d_arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11050712866306854504ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__d_r = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 17465047795171280812ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__d_rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15238666938030923766ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__d_rready = 1U;
    ;
    vlSelf->ember_top__DOT__u_xbar__DOT__c_aw = VL_SCOPED_RAND_RESET_Q(35, __VscopeHash, 2049308027492029479ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__c_awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 894939647049459548ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__c_awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5105368550977531224ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__c_w = VL_SCOPED_RAND_RESET_Q(36, __VscopeHash, 7454627154157349918ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__c_wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1101164606744653331ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__c_wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15603517899379013522ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__c_b = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14070851404036925850ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__c_bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2906377875023305798ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__c_bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7749712187653857403ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__c_ar = VL_SCOPED_RAND_RESET_Q(35, __VscopeHash, 9170523845482510793ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__c_arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3994930998991783156ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__c_arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1611023361916858675ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__c_r = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 15421945743209479944ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__c_rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1698059413186686810ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__c_rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4231704154443883632ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__v_aw = VL_SCOPED_RAND_RESET_Q(35, __VscopeHash, 7184154237826869237ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__v_awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14990542028193164103ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__v_awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17053979075870792515ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__v_w = VL_SCOPED_RAND_RESET_Q(36, __VscopeHash, 5618063953820820441ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__v_wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 806800945006595843ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__v_wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 428394779327937375ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__v_b = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6951804745602063009ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__v_bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4138484602509150553ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__v_bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15871389146434166225ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__v_ar = VL_SCOPED_RAND_RESET_Q(35, __VscopeHash, 1545747220369487237ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__v_arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10272979988043493371ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__v_arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13942678303227849391ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__v_r = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 13973622779132984612ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__v_rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16334185511672657807ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__v_rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15309424099547056584ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__h_aw_is_cp = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11002827761481530869ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__h_ar_is_cp = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11191181666827555864ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__h_req_v_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10540691897385432185ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__h_req_v_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3554011778331777817ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__d_req_v_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2756655247496997727ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__d_req_v_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8591386553605810979ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__wstate = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8772892179214037179ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__w_favor_d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17884942032716538767ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__w_fwd_h = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 377803299414275880ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__w_fwd_d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6528038550340386627ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__rstate = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17112757709048612345ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__r_favor_d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13969264927640328694ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__r_fwd_h = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7928012990282901194ull);
    vlSelf->ember_top__DOT__u_xbar__DOT__r_fwd_d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6247465694546090366ull);
    vlSelf->ember_top__DOT__u_xbar__DOT___unused_dma_rdy = 1U;
    ;
    vlSelf->ember_top__DOT__u_cp__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12861045175602862467ull);
    vlSelf->ember_top__DOT__u_cp__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2142497748901523162ull);
    vlSelf->ember_top__DOT__u_cp__DOT__s_aw = VL_SCOPED_RAND_RESET_Q(35, __VscopeHash, 11030670947001950975ull);
    vlSelf->ember_top__DOT__u_cp__DOT__s_awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10497280897478327041ull);
    vlSelf->ember_top__DOT__u_cp__DOT__s_awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14752646721144974199ull);
    vlSelf->ember_top__DOT__u_cp__DOT__s_w = VL_SCOPED_RAND_RESET_Q(36, __VscopeHash, 2875485752452734182ull);
    vlSelf->ember_top__DOT__u_cp__DOT__s_wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11274501490101946136ull);
    vlSelf->ember_top__DOT__u_cp__DOT__s_wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11818583703873807754ull);
    vlSelf->ember_top__DOT__u_cp__DOT__s_b = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15519183417515127266ull);
    vlSelf->ember_top__DOT__u_cp__DOT__s_bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8382198503373738342ull);
    vlSelf->ember_top__DOT__u_cp__DOT__s_bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2782749263855271390ull);
    vlSelf->ember_top__DOT__u_cp__DOT__s_ar = VL_SCOPED_RAND_RESET_Q(35, __VscopeHash, 5105042891653561334ull);
    vlSelf->ember_top__DOT__u_cp__DOT__s_arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9984400693226890543ull);
    vlSelf->ember_top__DOT__u_cp__DOT__s_arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11447841624054506735ull);
    vlSelf->ember_top__DOT__u_cp__DOT__s_r = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 9194743187055273337ull);
    vlSelf->ember_top__DOT__u_cp__DOT__s_rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13823680276399349576ull);
    vlSelf->ember_top__DOT__u_cp__DOT__s_rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1958566407979481135ull);
    vlSelf->ember_top__DOT__u_cp__DOT__m_aw = VL_SCOPED_RAND_RESET_Q(35, __VscopeHash, 10802128062847068548ull);
    vlSelf->ember_top__DOT__u_cp__DOT__m_awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12332906851328090082ull);
    vlSelf->ember_top__DOT__u_cp__DOT__m_awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15697235084957803928ull);
    vlSelf->ember_top__DOT__u_cp__DOT__m_w = VL_SCOPED_RAND_RESET_Q(36, __VscopeHash, 7990916699980565586ull);
    vlSelf->ember_top__DOT__u_cp__DOT__m_wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15470178837406073516ull);
    vlSelf->ember_top__DOT__u_cp__DOT__m_wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17356775622079809600ull);
    vlSelf->ember_top__DOT__u_cp__DOT__m_b = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7278786972723408901ull);
    vlSelf->ember_top__DOT__u_cp__DOT__m_bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1341101284848861658ull);
    vlSelf->ember_top__DOT__u_cp__DOT__m_bready = 1U;
    ;
    vlSelf->ember_top__DOT__u_cp__DOT__m_ar = VL_SCOPED_RAND_RESET_Q(35, __VscopeHash, 17011107834864131697ull);
    vlSelf->ember_top__DOT__u_cp__DOT__m_arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10260765336605094168ull);
    vlSelf->ember_top__DOT__u_cp__DOT__m_arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10108131360852997558ull);
    vlSelf->ember_top__DOT__u_cp__DOT__m_r = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 10685418273999939901ull);
    vlSelf->ember_top__DOT__u_cp__DOT__m_rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18096630574288461082ull);
    vlSelf->ember_top__DOT__u_cp__DOT__m_rready = 1U;
    ;
    vlSelf->ember_top__DOT__u_cp__DOT__rtr_kick = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4141041841391334301ull);
    vlSelf->ember_top__DOT__u_cp__DOT__rtr_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2461360817845512878ull);
    vlSelf->ember_top__DOT__u_cp__DOT__blit_csr_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6230002445738724304ull);
    vlSelf->ember_top__DOT__u_cp__DOT__blit_csr_addr = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17102660280067199562ull);
    vlSelf->ember_top__DOT__u_cp__DOT__blit_csr_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13024293804649039116ull);
    vlSelf->ember_top__DOT__u_cp__DOT__blit_kick = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5227814500579992359ull);
    vlSelf->ember_top__DOT__u_cp__DOT__blit_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13240486767048632115ull);
    vlSelf->ember_top__DOT__u_cp__DOT__gsx_csr_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6038967293520849877ull);
    vlSelf->ember_top__DOT__u_cp__DOT__gsx_csr_addr = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13181192334524482166ull);
    vlSelf->ember_top__DOT__u_cp__DOT__gsx_csr_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2645203768214670043ull);
    vlSelf->ember_top__DOT__u_cp__DOT__gsx_kick = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13946433227217966500ull);
    vlSelf->ember_top__DOT__u_cp__DOT__gsx_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16152146644945364234ull);
    vlSelf->ember_top__DOT__u_cp__DOT__core_csr_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13515114865650779123ull);
    vlSelf->ember_top__DOT__u_cp__DOT__core_csr_addr = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12863494653485834613ull);
    vlSelf->ember_top__DOT__u_cp__DOT__core_csr_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1820187171855487516ull);
    vlSelf->ember_top__DOT__u_cp__DOT__core_kick = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1503023412890454580ull);
    vlSelf->ember_top__DOT__u_cp__DOT__core_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14685584578759758188ull);
    vlSelf->ember_top__DOT__u_cp__DOT__tu_csr_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5074654544574994129ull);
    vlSelf->ember_top__DOT__u_cp__DOT__tu_csr_addr = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8682847518742272913ull);
    vlSelf->ember_top__DOT__u_cp__DOT__tu_csr_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7854053079186530350ull);
    vlSelf->ember_top__DOT__u_cp__DOT__tu_kick = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16893546644490453559ull);
    vlSelf->ember_top__DOT__u_cp__DOT__tu_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15226435665191222446ull);
    vlSelf->ember_top__DOT__u_cp__DOT__reg_addr = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 14300765148669222707ull);
    vlSelf->ember_top__DOT__u_cp__DOT__reg_be = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17073307112813623087ull);
    vlSelf->ember_top__DOT__u_cp__DOT__reg_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15572815497173716508ull);
    vlSelf->ember_top__DOT__u_cp__DOT__reg_wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10940587307724881206ull);
    vlSelf->ember_top__DOT__u_cp__DOT__rd_addr = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 14037711802966154153ull);
    vlSelf->ember_top__DOT__u_cp__DOT__dma_dst_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 464046869245481750ull);
    vlSelf->ember_top__DOT__u_cp__DOT__dma_len_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4512224645643487410ull);
    vlSelf->ember_top__DOT__u_cp__DOT__fence_pend_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5309094456122701353ull);
    vlSelf->ember_top__DOT__u_cp__DOT__fence_done_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7473084659757198306ull);
    vlSelf->ember_top__DOT__u_cp__DOT__dma_busy_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15390062155542601667ull);
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->ember_top__DOT__u_cp__DOT__up_mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1896026846424334638ull);
    }
    vlSelf->ember_top__DOT__u_cp__DOT__up_wp = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 1378168180180904217ull);
    vlSelf->ember_top__DOT__u_cp__DOT__up_rp = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 459221840672597885ull);
    vlSelf->ember_top__DOT__u_cp__DOT__up_full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13014458282419914842ull);
    vlSelf->ember_top__DOT__u_cp__DOT__up_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13707158729759630608ull);
    vlSelf->ember_top__DOT__u_cp__DOT__up_push = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2549642408036342587ull);
    vlSelf->ember_top__DOT__u_cp__DOT__up_pop = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5814739010603721974ull);
    vlSelf->ember_top__DOT__u_cp__DOT__up_front = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7272804931700186893ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->ember_top__DOT__u_cp__DOT__rb_mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1479180013790122796ull);
    }
    vlSelf->ember_top__DOT__u_cp__DOT__rb_wp = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4679183531585761603ull);
    vlSelf->ember_top__DOT__u_cp__DOT__rb_rp = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5494749601392635034ull);
    vlSelf->ember_top__DOT__u_cp__DOT__rb_full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6317047517232821659ull);
    vlSelf->ember_top__DOT__u_cp__DOT__rb_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3611009895643918136ull);
    vlSelf->ember_top__DOT__u_cp__DOT__rb_push = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3319692210986005717ull);
    vlSelf->ember_top__DOT__u_cp__DOT__rb_data_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15054783825583187525ull);
    vlSelf->ember_top__DOT__u_cp__DOT__rb_pop = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14966819775330659400ull);
    vlSelf->ember_top__DOT__u_cp__DOT__dstate = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13535970611381716435ull);
    vlSelf->ember_top__DOT__u_cp__DOT__dma_addr_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9294499391889302429ull);
    vlSelf->ember_top__DOT__u_cp__DOT__dma_left_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6642137356545852975ull);
    vlSelf->ember_top__DOT__u_cp__DOT__r_pend_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11837231645357668038ull);
    vlSelf->ember_top__DOT__u_cp__DOT__w_busy_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5141461619826083085ull);
    vlSelf->ember_top__DOT__u_cp__DOT__rd_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8971639866606451459ull);
    vlSelf->ember_top__DOT__u_cp__DOT__rb_count = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5219555676899997232ull);
    vlSelf->ember_top__DOT__u_cp__DOT__blit_csr_zone = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3426785792867258515ull);
    vlSelf->ember_top__DOT__u_cp__DOT__gsx_csr_zone = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8085291520820516031ull);
    vlSelf->ember_top__DOT__u_cp__DOT__core_csr_zone = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1240843167071541165ull);
    vlSelf->ember_top__DOT__u_cp__DOT__tu_csr_zone = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1158868652795099490ull);
    vlSelf->ember_top__DOT__u_cp__DOT___unused = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18028637743118448001ull);
    vlSelf->ember_top__DOT__u_cp__DOT__u_regs__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10713086118268740443ull);
    vlSelf->ember_top__DOT__u_cp__DOT__u_regs__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4328075309467716143ull);
    vlSelf->ember_top__DOT__u_cp__DOT__u_regs__DOT__s_aw = VL_SCOPED_RAND_RESET_Q(35, __VscopeHash, 7562673636538722046ull);
    vlSelf->ember_top__DOT__u_cp__DOT__u_regs__DOT__s_awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9162000204032181451ull);
    vlSelf->ember_top__DOT__u_cp__DOT__u_regs__DOT__s_awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13819926672268417347ull);
    vlSelf->ember_top__DOT__u_cp__DOT__u_regs__DOT__s_w = VL_SCOPED_RAND_RESET_Q(36, __VscopeHash, 8322138343530760687ull);
    vlSelf->ember_top__DOT__u_cp__DOT__u_regs__DOT__s_wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11181761287452585473ull);
    vlSelf->ember_top__DOT__u_cp__DOT__u_regs__DOT__s_wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10930766790003169680ull);
    vlSelf->ember_top__DOT__u_cp__DOT__u_regs__DOT__s_b = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15318259502444336912ull);
    vlSelf->ember_top__DOT__u_cp__DOT__u_regs__DOT__s_bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11396248811901286780ull);
    vlSelf->ember_top__DOT__u_cp__DOT__u_regs__DOT__s_bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13211309685630473527ull);
    vlSelf->ember_top__DOT__u_cp__DOT__u_regs__DOT__s_ar = VL_SCOPED_RAND_RESET_Q(35, __VscopeHash, 15349496725389509280ull);
    vlSelf->ember_top__DOT__u_cp__DOT__u_regs__DOT__s_arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13535052721805369935ull);
    vlSelf->ember_top__DOT__u_cp__DOT__u_regs__DOT__s_arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1863391458972568325ull);
    vlSelf->ember_top__DOT__u_cp__DOT__u_regs__DOT__s_r = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 11148760066275041307ull);
    vlSelf->ember_top__DOT__u_cp__DOT__u_regs__DOT__s_rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11749360831410837776ull);
    vlSelf->ember_top__DOT__u_cp__DOT__u_regs__DOT__s_rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12557668993914180075ull);
    vlSelf->ember_top__DOT__u_cp__DOT__u_regs__DOT__reg_addr = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 6610179028767703823ull);
    vlSelf->ember_top__DOT__u_cp__DOT__u_regs__DOT__reg_be = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13252671225621605025ull);
    vlSelf->ember_top__DOT__u_cp__DOT__u_regs__DOT__reg_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15655554201240139668ull);
    vlSelf->ember_top__DOT__u_cp__DOT__u_regs__DOT__reg_wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1526547941307166052ull);
    vlSelf->ember_top__DOT__u_cp__DOT__u_regs__DOT__rd_addr = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 892874699190733077ull);
    vlSelf->ember_top__DOT__u_cp__DOT__u_regs__DOT__rd_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17962325200968622527ull);
    vlSelf->ember_top__DOT__u_cp__DOT__u_regs__DOT__aw_v = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6439593060219444553ull);
    vlSelf->ember_top__DOT__u_cp__DOT__u_regs__DOT__w_v = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4559698435082929745ull);
    vlSelf->ember_top__DOT__u_cp__DOT__u_regs__DOT__aw_q = VL_SCOPED_RAND_RESET_Q(35, __VscopeHash, 9557017662512382523ull);
    vlSelf->ember_top__DOT__u_cp__DOT__u_regs__DOT__w_q = VL_SCOPED_RAND_RESET_Q(36, __VscopeHash, 8367071957838776894ull);
    vlSelf->ember_top__DOT__u_cp__DOT__u_regs__DOT__wr_fire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18429582198039116986ull);
    vlSelf->ember_top__DOT__u_cp__DOT__u_regs__DOT__ar_v = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10595826380546900588ull);
    vlSelf->ember_top__DOT__u_cp__DOT__u_regs__DOT__ar_accept = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16176400785752838162ull);
    vlSelf->ember_top__DOT__u_tu__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 416818044208332046ull);
    vlSelf->ember_top__DOT__u_tu__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6075187719627591938ull);
    vlSelf->ember_top__DOT__u_tu__DOT__csr_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12203009959133417074ull);
    vlSelf->ember_top__DOT__u_tu__DOT__csr_addr = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8455340304752801621ull);
    vlSelf->ember_top__DOT__u_tu__DOT__csr_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12311123077203761207ull);
    vlSelf->ember_top__DOT__u_tu__DOT__kick = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13230300071182145013ull);
    vlSelf->ember_top__DOT__u_tu__DOT__tua_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6978214347717029261ull);
    vlSelf->ember_top__DOT__u_tu__DOT__tua_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12310784839931519264ull);
    vlSelf->ember_top__DOT__u_tu__DOT__tua_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7581348806058590939ull);
    vlSelf->ember_top__DOT__u_tu__DOT__tua_be = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1451512359769954663ull);
    vlSelf->ember_top__DOT__u_tu__DOT__tua_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10321375707395064579ull);
    vlSelf->ember_top__DOT__u_tu__DOT__tua_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4765132458599326643ull);
    vlSelf->ember_top__DOT__u_tu__DOT__busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11925985607175651329ull);
    vlSelf->ember_top__DOT__u_tu__DOT__a_base_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15513855512098927728ull);
    vlSelf->ember_top__DOT__u_tu__DOT__w_base_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7580279704237145868ull);
    vlSelf->ember_top__DOT__u_tu__DOT__c_base_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12098243562905419827ull);
    vlSelf->ember_top__DOT__u_tu__DOT__req_mult = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9005427332812893934ull);
    vlSelf->ember_top__DOT__u_tu__DOT__req_shift = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15196046317531801630ull);
    vlSelf->ember_top__DOT__u_tu__DOT__dim_n = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 9715498671588903198ull);
    vlSelf->ember_top__DOT__u_tu__DOT__dim_k = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 2162466247984449548ull);
    vlSelf->ember_top__DOT__u_tu__DOT__dim_m = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 12454296363317109230ull);
    vlSelf->ember_top__DOT__u_tu__DOT__cfg2_dim_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9218697246166970319ull);
    vlSelf->ember_top__DOT__u_tu__DOT__cfg2_m_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 155588011830401689ull);
    vlSelf->ember_top__DOT__u_tu__DOT__cfg2_q_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6196792186290853286ull);
    vlSelf->ember_top__DOT__u_tu__DOT__kdim = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2171198458372923350ull);
    vlSelf->ember_top__DOT__u_tu__DOT__ndim = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12931836000839424533ull);
    vlSelf->ember_top__DOT__u_tu__DOT__mdim = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 460548236798634177ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->ember_top__DOT__u_tu__DOT__wrowbuf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14004676563613704412ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->ember_top__DOT__u_tu__DOT__abuf_q[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6568849545480434670ull);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->ember_top__DOT__u_tu__DOT__wbyte[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10700039498519797649ull);
    }
    vlSelf->ember_top__DOT__u_tu__DOT__w_ld = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11651553950023950703ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 16; ++__Vi1) {
            vlSelf->ember_top__DOT__u_tu__DOT__w_regs[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6554911013208592414ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->ember_top__DOT__u_tu__DOT__a_row_byte[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1703691702591231206ull);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 16; ++__Vi1) {
            vlSelf->ember_top__DOT__u_tu__DOT__prod[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2595963316504225885ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->ember_top__DOT__u_tu__DOT__lv1[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1206116791150816532ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->ember_top__DOT__u_tu__DOT__lv2[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12172572714977729088ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 2; ++__Vi1) {
            vlSelf->ember_top__DOT__u_tu__DOT__lv3[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10026568640405715581ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->ember_top__DOT__u_tu__DOT__tree[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11886336945280412244ull);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 16; ++__Vi1) {
            vlSelf->ember_top__DOT__u_tu__DOT__acc[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17293247578289204002ull);
        }
    }
    vlSelf->ember_top__DOT__u_tu__DOT__st = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14942500704498837830ull);
    vlSelf->ember_top__DOT__u_tu__DOT__running = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6569202234890597219ull);
    vlSelf->ember_top__DOT__u_tu__DOT__k0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6946567397460003986ull);
    vlSelf->ember_top__DOT__u_tu__DOT__n0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15131474351614077697ull);
    vlSelf->ember_top__DOT__u_tu__DOT__m0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16881247736014053220ull);
    vlSelf->ember_top__DOT__u_tu__DOT__wrow = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3779492062279101739ull);
    vlSelf->ember_top__DOT__u_tu__DOT__wgrp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17202185029696187884ull);
    vlSelf->ember_top__DOT__u_tu__DOT__mrow = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4891720030070965655ull);
    vlSelf->ember_top__DOT__u_tu__DOT__fcnt = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17772702349426979849ull);
    vlSelf->ember_top__DOT__u_tu__DOT__mac_pend = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5716421333816667851ull);
    vlSelf->ember_top__DOT__u_tu__DOT__rq_pend = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12772567892745207549ull);
    vlSelf->ember_top__DOT__u_tu__DOT__rq_req_cyc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 924801620819995911ull);
    vlSelf->ember_top__DOT__u_tu__DOT__rq_addr_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12521378544271044011ull);
    vlSelf->ember_top__DOT__u_tu__DOT__rq_dst_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1140096316239521791ull);
    vlSelf->ember_top__DOT__u_tu__DOT__rq_aw = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7795334257740274473ull);
    vlSelf->ember_top__DOT__u_tu__DOT__cw_row = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 8091942135066504112ull);
    vlSelf->ember_top__DOT__u_tu__DOT__cw_rblk = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9116006092850123023ull);
    vlSelf->ember_top__DOT__u_tu__DOT__cw_word = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16798624829539091905ull);
    vlSelf->ember_top__DOT__u_tu__DOT__cw_byte0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8615321574899037731ull);
    vlSelf->ember_top__DOT__u_tu__DOT__cw_byte1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1612672910381666240ull);
    vlSelf->ember_top__DOT__u_tu__DOT__cw_byte2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13516677062731577081ull);
    vlSelf->ember_top__DOT__u_tu__DOT__cw_byte3 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5116773798947531490ull);
    vlSelf->ember_top__DOT__u_tu__DOT__unnamedblk1__DOT__r = 0;
    vlSelf->ember_top__DOT__u_tu__DOT__unnamedblk1__DOT__unnamedblk2__DOT__c = 0;
    vlSelf->ember_top__DOT__u_tu__DOT__unnamedblk7__DOT__c = 0;
    vlSelf->ember_top__DOT__u_tu__DOT__unnamedblk5__DOT__r = 0;
    vlSelf->ember_top__DOT__u_tu__DOT__unnamedblk5__DOT__unnamedblk6__DOT__c = 0;
    vlSelf->ember_top__DOT__u_core__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9617664299791022443ull);
    vlSelf->ember_top__DOT__u_core__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15930829597060074076ull);
    vlSelf->ember_top__DOT__u_core__DOT__csr_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9713860559847817378ull);
    vlSelf->ember_top__DOT__u_core__DOT__csr_addr = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2954928186212724037ull);
    vlSelf->ember_top__DOT__u_core__DOT__csr_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15500167210389252978ull);
    vlSelf->ember_top__DOT__u_core__DOT__kick = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16550302121050311657ull);
    vlSelf->ember_top__DOT__u_core__DOT__cxa_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8573992176112148460ull);
    vlSelf->ember_top__DOT__u_core__DOT__cxa_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12886738658279146286ull);
    vlSelf->ember_top__DOT__u_core__DOT__cxa_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17753824649342203900ull);
    vlSelf->ember_top__DOT__u_core__DOT__cxa_be = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 18315824767546823830ull);
    vlSelf->ember_top__DOT__u_core__DOT__cxa_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7359451161976858372ull);
    vlSelf->ember_top__DOT__u_core__DOT__cxa_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13944254949293953069ull);
    vlSelf->ember_top__DOT__u_core__DOT__ixa_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12963929111731988038ull);
    vlSelf->ember_top__DOT__u_core__DOT__ixa_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17436622401685715474ull);
    vlSelf->ember_top__DOT__u_core__DOT__ixa_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1742518288770389751ull);
    vlSelf->ember_top__DOT__u_core__DOT__busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11355942627010605747ull);
    vlSelf->ember_top__DOT__u_core__DOT__code_base_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4746676906011088958ull);
    vlSelf->ember_top__DOT__u_core__DOT__nblk_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16696924674616294049ull);
    vlSelf->ember_top__DOT__u_core__DOT__csr_code_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4603513829108032300ull);
    vlSelf->ember_top__DOT__u_core__DOT__csr_nblk_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14098177230738784181ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->ember_top__DOT__u_core__DOT__T[__Vi0] = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3664893460603082710ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->ember_top__DOT__u_core__DOT__fpc[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1429345959493866042ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 16; ++__Vi1) {
            vlSelf->ember_top__DOT__u_core__DOT__gpr[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3646796256026804877ull);
        }
    }
    vlSelf->ember_top__DOT__u_core__DOT__waitv = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5649079781088711440ull);
    vlSelf->ember_top__DOT__u_core__DOT__barv = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9701240120793844074ull);
    vlSelf->ember_top__DOT__u_core__DOT__ibuf_v = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15586966536432110917ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->ember_top__DOT__u_core__DOT__ibuf_w[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17649828245920784010ull);
    }
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->ember_top__DOT__u_core__DOT__smem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13070044020949564629ull);
    }
    vlSelf->ember_top__DOT__u_core__DOT__f_lane_en = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 18041043799746709515ull);
    vlSelf->ember_top__DOT__u_core__DOT__f_op = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11731968206690455882ull);
    vlSelf->ember_top__DOT__u_core__DOT__f_a0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8436734776149584832ull);
    vlSelf->ember_top__DOT__u_core__DOT__f_b0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8143363092572749396ull);
    vlSelf->ember_top__DOT__u_core__DOT__f_a1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5397425183162479929ull);
    vlSelf->ember_top__DOT__u_core__DOT__f_b1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13864513072542732943ull);
    vlSelf->ember_top__DOT__u_core__DOT__f_a2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10890930778024440858ull);
    vlSelf->ember_top__DOT__u_core__DOT__f_b2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3594464352378638462ull);
    vlSelf->ember_top__DOT__u_core__DOT__f_a3 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3533200339571006030ull);
    vlSelf->ember_top__DOT__u_core__DOT__f_b3 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8269139798366852933ull);
    vlSelf->ember_top__DOT__u_core__DOT__f_go = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2710661243770912152ull);
    vlSelf->ember_top__DOT__u_core__DOT__f_y0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8489924140390452529ull);
    vlSelf->ember_top__DOT__u_core__DOT__f_y1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 879021386211402436ull);
    vlSelf->ember_top__DOT__u_core__DOT__f_y2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7045179593143220342ull);
    vlSelf->ember_top__DOT__u_core__DOT__f_y3 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6016407146769800692ull);
    vlSelf->ember_top__DOT__u_core__DOT__f_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6752075731484234628ull);
    vlSelf->ember_top__DOT__u_core__DOT__f_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 449720954945403289ull);
    vlSelf->ember_top__DOT__u_core__DOT__st = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 18311142349959104474ull);
    vlSelf->ember_top__DOT__u_core__DOT__running = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12669948776151834394ull);
    vlSelf->ember_top__DOT__u_core__DOT__blk = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5484094045428528035ull);
    vlSelf->ember_top__DOT__u_core__DOT__budget = VL_SCOPED_RAND_RESET_I(20, __VscopeHash, 12463787992966122300ull);
    vlSelf->ember_top__DOT__u_core__DOT__ix_pend = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17141292334556601290ull);
    vlSelf->ember_top__DOT__u_core__DOT__ix_req_cyc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11731543825514559068ull);
    vlSelf->ember_top__DOT__u_core__DOT__ix_tid = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7388809870659264996ull);
    vlSelf->ember_top__DOT__u_core__DOT__flush_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17984518208237671045ull);
    vlSelf->ember_top__DOT__u_core__DOT__flush_tid = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9267061552838206662ull);
    vlSelf->ember_top__DOT__u_core__DOT__ld_pend = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8645856050998173964ull);
    vlSelf->ember_top__DOT__u_core__DOT__ld_addr_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6919628197057297980ull);
    vlSelf->ember_top__DOT__u_core__DOT__ld_tid_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9669212089562270194ull);
    vlSelf->ember_top__DOT__u_core__DOT__ld_rd_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17094718648803268226ull);
    vlSelf->ember_top__DOT__u_core__DOT__cx_pend = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 875278863088879688ull);
    vlSelf->ember_top__DOT__u_core__DOT__cx_req_cyc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13529641083927008037ull);
    vlSelf->ember_top__DOT__u_core__DOT__dr_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3447114716848559303ull);
    vlSelf->ember_top__DOT__u_core__DOT__dr_tid = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12255156467367244705ull);
    vlSelf->ember_top__DOT__u_core__DOT__dr_rd = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13305192140054342905ull);
    vlSelf->ember_top__DOT__u_core__DOT__dr_word = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15592291458960835579ull);
    vlSelf->ember_top__DOT__u_core__DOT__fp_pend = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14867973189070249707ull);
    vlSelf->ember_top__DOT__u_core__DOT__fp_tid = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11380512130085638185ull);
    vlSelf->ember_top__DOT__u_core__DOT__fp_rd = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7875309478027839714ull);
    vlSelf->ember_top__DOT__u_core__DOT__bar_count = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15677889636723637827ull);
    vlSelf->ember_top__DOT__u_core__DOT__exec_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1638187374908350111ull);
    vlSelf->ember_top__DOT__u_core__DOT__exec_tid = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10270356571407695630ull);
    vlSelf->ember_top__DOT__u_core__DOT__pick_tid = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6987658577255696701ull);
    vlSelf->ember_top__DOT__u_core__DOT__pick_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12513524467221464409ull);
    vlSelf->ember_top__DOT__u_core__DOT__i_op = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2152729657799811133ull);
    vlSelf->ember_top__DOT__u_core__DOT__i_rd = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13666518889933889231ull);
    vlSelf->ember_top__DOT__u_core__DOT__i_ra = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 18111863093056322544ull);
    vlSelf->ember_top__DOT__u_core__DOT__i_rb = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6308113765630162208ull);
    vlSelf->ember_top__DOT__u_core__DOT__i_imm = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 15484473326477000858ull);
    vlSelf->ember_top__DOT__u_core__DOT__i_sx12 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8562629993948158520ull);
    vlSelf->ember_top__DOT__u_core__DOT__i_sx9 = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 15715724632941941764ull);
    vlSelf->ember_top__DOT__u_core__DOT__i_sx11 = VL_SCOPED_RAND_RESET_I(11, __VscopeHash, 7771214239724640258ull);
    vlSelf->ember_top__DOT__u_core__DOT__rav = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13795902031459684363ull);
    vlSelf->ember_top__DOT__u_core__DOT__rbv = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16800493279982919118ull);
    vlSelf->ember_top__DOT__u_core__DOT___unused = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15231914444504235401ull);
    vlSelf->ember_top__DOT__u_core__DOT__unnamedblk1__DOT__t = 0;
    vlSelf->ember_top__DOT__u_core__DOT__unnamedblk2__DOT__t = 0;
    vlSelf->ember_top__DOT__u_core__DOT__unnamedblk6__DOT__t = 0;
    vlSelf->ember_top__DOT__u_core__DOT__unnamedblk4__DOT__t = 0;
    vlSelf->ember_top__DOT__u_core__DOT__unnamedblk4__DOT__unnamedblk5__DOT__r = 0;
    vlSelf->ember_top__DOT__u_core__DOT__u_fpu__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17736057849069608743ull);
    vlSelf->ember_top__DOT__u_core__DOT__u_fpu__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14641835181077073740ull);
    vlSelf->ember_top__DOT__u_core__DOT__u_fpu__DOT__lane_en = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4743644009683010306ull);
    vlSelf->ember_top__DOT__u_core__DOT__u_fpu__DOT__op = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9271177045907635113ull);
    vlSelf->ember_top__DOT__u_core__DOT__u_fpu__DOT__a0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14844741669496434969ull);
    vlSelf->ember_top__DOT__u_core__DOT__u_fpu__DOT__b0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18364070468190536603ull);
    vlSelf->ember_top__DOT__u_core__DOT__u_fpu__DOT__a1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9779704771569645185ull);
    vlSelf->ember_top__DOT__u_core__DOT__u_fpu__DOT__b1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9657859530231899630ull);
    vlSelf->ember_top__DOT__u_core__DOT__u_fpu__DOT__a2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1930503827132762011ull);
    vlSelf->ember_top__DOT__u_core__DOT__u_fpu__DOT__b2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13254675619674222615ull);
    vlSelf->ember_top__DOT__u_core__DOT__u_fpu__DOT__a3 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17599986528819258150ull);
    vlSelf->ember_top__DOT__u_core__DOT__u_fpu__DOT__b3 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13893439926137848151ull);
    vlSelf->ember_top__DOT__u_core__DOT__u_fpu__DOT__go = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17806494326035095045ull);
    vlSelf->ember_top__DOT__u_core__DOT__u_fpu__DOT__y0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3114151110741036131ull);
    vlSelf->ember_top__DOT__u_core__DOT__u_fpu__DOT__y1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17817768910502028266ull);
    vlSelf->ember_top__DOT__u_core__DOT__u_fpu__DOT__y2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18330326879029827387ull);
    vlSelf->ember_top__DOT__u_core__DOT__u_fpu__DOT__y3 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2775277999016686879ull);
    vlSelf->ember_top__DOT__u_core__DOT__u_fpu__DOT__busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7983532713609343345ull);
    vlSelf->ember_top__DOT__u_core__DOT__u_fpu__DOT__done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4862866877745271934ull);
    VL_SCOPED_RAND_RESET_W(103, vlSelf->ember_top__DOT__u_core__DOT__u_fpu__DOT__s0, __VscopeHash, 8366996542316366791ull);
    VL_SCOPED_RAND_RESET_W(103, vlSelf->ember_top__DOT__u_core__DOT__u_fpu__DOT__s1, __VscopeHash, 6127037439603541620ull);
    VL_SCOPED_RAND_RESET_W(103, vlSelf->ember_top__DOT__u_core__DOT__u_fpu__DOT__s2, __VscopeHash, 16381009660765498990ull);
    VL_SCOPED_RAND_RESET_W(103, vlSelf->ember_top__DOT__u_core__DOT__u_fpu__DOT__s3, __VscopeHash, 11156732728281512641ull);
    vlSelf->ember_top__DOT__u_gsx__DOT____Vlvbound_h370f95ca__0 = 0;
    vlSelf->ember_top__DOT__u_gsx__DOT____Vlvbound_hba015fec__0 = 0;
    vlSelf->ember_top__DOT__u_gsx__DOT____Vlvbound_h7abace7f__0 = 0;
    vlSelf->ember_top__DOT__u_gsx__DOT____Vlvbound_hf660ed79__0 = 0;
    vlSelf->ember_top__DOT__u_gsx__DOT____Vlvbound_h71c33494__0 = 0;
    vlSelf->ember_top__DOT__u_gsx__DOT____Vlvbound_h52fd11d8__0 = 0;
    vlSelf->ember_top__DOT__u_gsx__DOT____Vlvbound_hd1051bc7__0 = 0;
    vlSelf->ember_top__DOT__u_gsx__DOT____Vlvbound_h53f4e5eb__0 = 0;
    vlSelf->ember_top__DOT__u_gsx__DOT____Vlvbound_hdfae5880__0 = 0;
    vlSelf->ember_top__DOT__u_gsx__DOT____Vlvbound_hcc3d737a__0 = 0;
    vlSelf->ember_top__DOT__u_gsx__DOT____Vlvbound_hd21f5caa__0 = 0;
    vlSelf->ember_top__DOT__u_gsx__DOT____Vlvbound_h5e2f4665__0 = 0;
    vlSelf->ember_top__DOT__u_gsx__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13255053640358896242ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18020442838557757783ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__csr_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6119673948235739247ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__csr_addr = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12152003989039681447ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__csr_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9762194637643754543ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__kick = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7105503941834594933ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__gxa_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16925443309567905976ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__gxa_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11935844928164766746ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__gxa_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5393955849807625555ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__gxa_be = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14831787331283030778ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__gxa_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3189698760087584751ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__gxa_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9525851950677617489ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9518360337092560680ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->ember_top__DOT__u_gsx__DOT__mata[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17345460405150753303ull);
    }
    for (int __Vi0 = 0; __Vi0 < 15; ++__Vi0) {
        vlSelf->ember_top__DOT__u_gsx__DOT__vtx[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11652470909084952320ull);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->ember_top__DOT__u_gsx__DOT__col[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15936980223118979463ull);
    }
    vlSelf->ember_top__DOT__u_gsx__DOT__mata_ptr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13361908122132093002ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__vtx_ptr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17978246134756586957ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__col_ptr = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5104527783581518752ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__tri_count = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11565428586978563928ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__cfg_overw = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5896789428769660378ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__cfg_blend = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10902803834375485242ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__cfg_ztest = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16468736493927518558ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__cfg_tex = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11746135259139254787ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__cfg_page = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2917551846968951056ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__cfg_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15514421903996174238ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__cfg_cnt_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6542241548954386781ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__cfg_mode_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 144385670861387753ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__tri_off = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13495568230872578049ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__f_lane_en = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12453556436014299886ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__f_op = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15888317797502705055ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__f_a0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11590375287487307660ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__f_b0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16301194666287454531ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__f_a1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15962636301291391387ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__f_b1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8213123465783410753ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__f_a2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3013046076952442553ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__f_b2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15834501603856018930ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__f_a3 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15820854951286699820ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__f_b3 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2313789246967843228ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__f_go = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3168050990940132184ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__f_y0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 828528901774061110ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__f_y1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9562643212845410150ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__f_y2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9627155905831830033ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__f_y3 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5287867556163909624ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__f_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18133410280003853376ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__f_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8504637883521025744ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__st = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 15469343190379997664ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__busy_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2294478169066195610ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__vidx = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3000843913651676861ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__kstep = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14586937382827200369ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__phase = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6037786776527742672ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__acc0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13178204830218505646ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__acc1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8854183198563953122ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__acc2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8458009634531252475ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__acc3 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3355351929034142374ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__w_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15153574844797134389ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__eidx = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5006427368416809029ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__emit_base = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4514468180269714906ull);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->ember_top__DOT__u_gsx__DOT__px[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3403767497569993614ull);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->ember_top__DOT__u_gsx__DOT__py[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18036785382318917603ull);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->ember_top__DOT__u_gsx__DOT__pz[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11795268241526097038ull);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->ember_top__DOT__u_gsx__DOT__pc[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11168440843345962744ull);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->ember_top__DOT__u_gsx__DOT__pu[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2034646459375011473ull);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->ember_top__DOT__u_gsx__DOT__pv[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12453000469304289614ull);
    }
    vlSelf->ember_top__DOT__u_gsx__DOT___unused = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11751251501876156004ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__unnamedblk1__DOT__r = 0;
    vlSelf->ember_top__DOT__u_gsx__DOT__unnamedblk1__DOT__unnamedblk2__DOT__c = 0;
    vlSelf->ember_top__DOT__u_gsx__DOT__unnamedblk3__DOT__i = 0;
    vlSelf->ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15338511194764203697ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10791079685489776612ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__lane_en = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10386684969160470241ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__op = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14261775625123598066ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__a0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15771451114294371229ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__b0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10567727159741933450ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__a1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10137800997169585640ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__b1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11045413981700367340ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__a2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13371017548112544102ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__b2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5439399346072714183ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__a3 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10660583228051665615ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__b3 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14826855035608912866ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__go = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2627044822227058295ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__y0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13949820529014798519ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__y1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12581263794768244344ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__y2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9586911622039098578ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__y3 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11718700827380472501ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12793252100218421055ull);
    vlSelf->ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8017899876855603378ull);
    VL_SCOPED_RAND_RESET_W(103, vlSelf->ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s0, __VscopeHash, 4879290272497303915ull);
    VL_SCOPED_RAND_RESET_W(103, vlSelf->ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s1, __VscopeHash, 16032026574153510891ull);
    VL_SCOPED_RAND_RESET_W(103, vlSelf->ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s2, __VscopeHash, 15951631490450054720ull);
    VL_SCOPED_RAND_RESET_W(103, vlSelf->ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__s3, __VscopeHash, 16488618055821962655ull);
    vlSelf->ember_top__DOT__u_blit__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1289301085408980464ull);
    vlSelf->ember_top__DOT__u_blit__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15834019651544193129ull);
    vlSelf->ember_top__DOT__u_blit__DOT__csr_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7049936703729172517ull);
    vlSelf->ember_top__DOT__u_blit__DOT__csr_addr = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7947249181478865545ull);
    vlSelf->ember_top__DOT__u_blit__DOT__csr_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14368788525586623882ull);
    vlSelf->ember_top__DOT__u_blit__DOT__kick = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11916287967592199433ull);
    vlSelf->ember_top__DOT__u_blit__DOT__fpa_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16307261922249203808ull);
    vlSelf->ember_top__DOT__u_blit__DOT__fpa_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15799978556767356250ull);
    vlSelf->ember_top__DOT__u_blit__DOT__fpa_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7117065142651818808ull);
    vlSelf->ember_top__DOT__u_blit__DOT__fpa_be = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 426867495881609822ull);
    vlSelf->ember_top__DOT__u_blit__DOT__fpa_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10665449120690487071ull);
    vlSelf->ember_top__DOT__u_blit__DOT__fpa_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4139856765345828394ull);
    vlSelf->ember_top__DOT__u_blit__DOT__busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2397758321148726332ull);
    vlSelf->ember_top__DOT__u_blit__DOT__done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3915800876422622923ull);
    vlSelf->ember_top__DOT__u_blit__DOT__scale2_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15286575931030815093ull);
    vlSelf->ember_top__DOT__u_blit__DOT__key_en_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7791677253202272048ull);
    vlSelf->ember_top__DOT__u_blit__DOT__key_color_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3138741865406491874ull);
    vlSelf->ember_top__DOT__u_blit__DOT__dst_off_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7665953489113713445ull);
    vlSelf->ember_top__DOT__u_blit__DOT__src_off_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17849711681805496597ull);
    vlSelf->ember_top__DOT__u_blit__DOT__w_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7535561482337939632ull);
    vlSelf->ember_top__DOT__u_blit__DOT__h_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10675412707989961208ull);
    vlSelf->ember_top__DOT__u_blit__DOT__done_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14134177856091539808ull);
    vlSelf->ember_top__DOT__u_blit__DOT__st = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10041173364574730888ull);
    vlSelf->ember_top__DOT__u_blit__DOT__rdata_lane = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15501917143363300ull);
    vlSelf->ember_top__DOT__u_blit__DOT__skip_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6410070855932496736ull);
    vlSelf->ember_top__DOT__u_blit__DOT__sx = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2014374003114868841ull);
    vlSelf->ember_top__DOT__u_blit__DOT__sy = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18389031229474622913ull);
    vlSelf->ember_top__DOT__u_blit__DOT__bx = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 17594228754536276090ull);
    vlSelf->ember_top__DOT__u_blit__DOT__by = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 15547197585528613695ull);
    vlSelf->ember_top__DOT__u_blit__DOT__saddr_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15031772336261838919ull);
    vlSelf->ember_top__DOT__u_blit__DOT__pix = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 588509735716925528ull);
    vlSelf->ember_top__DOT__u_blit__DOT__skip = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16465904036953640387ull);
    vlSelf->ember_top__DOT__u_blit__DOT__daddr0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1488463447730339396ull);
    vlSelf->ember_top__DOT__u_blit__DOT__daddr1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14277749439820433167ull);
    vlSelf->ember_top__DOT__u_blit__DOT__daddr2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 913604116265220883ull);
    vlSelf->ember_top__DOT__u_blit__DOT__daddr3 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10249369098239042720ull);
    vlSelf->ember_top__DOT__u_rtr__DOT____Vlvbound_hcfa37505__0 = 0;
    vlSelf->ember_top__DOT__u_rtr__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8241430000044429625ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17235150063622537555ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__kick = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1129937978439162757ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__fpa_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13227146396162241173ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__fpa_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17638252252102733163ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__fpa_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3507067503644082770ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__fpa_be = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15429570154374723682ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__fpa_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12026290546762505792ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__fpa_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16990034426123161954ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__fpa2_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10845284612147694799ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__fpa2_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1677896011615820287ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__fpa2_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13002510370288052997ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1290570497507181910ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__fst = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14871636263367193217ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__cursor = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5795956512512982748ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__fidx = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1754790432780813133ull);
    for (int __Vi0 = 0; __Vi0 < 19; ++__Vi0) {
        vlSelf->ember_top__DOT__u_rtr__DOT__cmd_q[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3904125242224192730ull);
    }
    vlSelf->ember_top__DOT__u_rtr__DOT__fetch_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15159734627714550411ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__fetch_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13975866974178552315ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__scan_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7146402801839468544ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__scan_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4819157657878071881ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__scan_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13387850041224449237ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__vx0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14834355315555498727ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__vy0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 980857068968749583ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__vx1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10060984926783478999ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__vy1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2832307086596254559ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__vx2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3777485471172289197ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__vy2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2420047641884423035ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__vu0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4875331547095831161ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__vv0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16415878447804921398ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__vu1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9745555560482211787ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__vv1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12984845007334052930ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__vu2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12217179131256722799ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__vv2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9778076364088997428ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__vz0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7375295629771392452ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__vz1 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6407180770523431399ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__vz2 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9013695321570508945ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__vr0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11983975014364581276ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__vg0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11835186305165731869ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__vb0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4546798610905990075ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__vr1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3857730530677342338ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__vg1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1839656977141247370ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__vb1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1340029967660932999ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__vr2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10269500611248549723ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__vg2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2238934744536898454ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__vb2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16355740600899846325ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__cull = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12337691489007492398ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__iwA = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 3291191311426475007ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__iwB = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 1476941862970656359ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__iwC = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 12817658592938778637ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__rA = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 15997272369693174236ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__rB = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 5592255668544400249ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__rC = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 1841999214529462645ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__gA = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 9569287193483372068ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__gB = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 1440277828354285071ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__gC = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 17241762211582864661ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__bA = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 5017278726763794485ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__bB = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 360308356322378455ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__bC = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 12711098794160541215ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__zA = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 9779546209506244625ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__zB = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 14287142939894738888ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__zC = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 14473145426369801926ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__uA = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 8068977333890216519ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__uB = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 8566596497532211433ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__uC = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 3384594117608445601ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__vA = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 8241966666828600152ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__vB = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 7354134581742673982ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__vC = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 6237981305159159667ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__x_lo_i = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14729048348155309375ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__x_hi_i = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8961521006767515097ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__y_lo_i = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9190673439005508874ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__y_hi_i = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11356589639538005347ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__dx01 = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 5101060846974488891ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__dy01 = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 8771895293453645517ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__dx12 = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 18411561078430494888ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__dy12 = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 3214687016936602508ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__dx20 = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 6114533398541144049ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__dy20 = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 4353751464068234293ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__scan_fpa_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4063239899358028934ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__scan_fpa_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11343534890090564082ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__scan_fpa_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1040555229768698457ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__scan_fpa_be = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 2303764294670525840ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__scan_fpa_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1874205788488138537ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__in_fetch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5886853169084452473ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__x0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 717239070520004957ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__y0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2851957064667057054ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__x1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14100735553419255994ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__y1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6501142401648262506ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__x2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1063368712304710083ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__y2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4681392966309636611ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__u0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12703921877180742845ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__v0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12429402064721581398ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__u1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3351160959404133044ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__v1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10176955165890000558ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__u2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 808364564591422887ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__v2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 998807051141758604ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__z0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5340034927253862241ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__z1 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8753717529415801259ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__z2 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8712819185374799980ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__r0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17753383126970882077ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__g0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3302858687735149219ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__b0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 106055350815138937ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__r1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1502768575691165017ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__g1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17757249080209692512ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__b1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2056115664235343974ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__r2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3677093686337018996ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__g2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14377400432460290252ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__b2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1472119141825661966ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__cull = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11201023830661606814ull);
    VL_SCOPED_RAND_RESET_W(67, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__area, __VscopeHash, 15577076077860020345ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__iwA = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 4209759387780078709ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__iwB = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 13857606365732621210ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__iwC = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 13880093935378035288ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__rA = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 9455902199162769006ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__rB = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 13870259181267052731ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__rC = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 7672789157048290698ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__gA = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 20199698147978282ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__gB = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 542259875358979238ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__gC = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 6722109570499232060ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__bA = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 16772105890479219417ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__bB = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 11354155504422826716ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__bC = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 2833817485563742208ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__zA = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 8535749274825709702ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__zB = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 11166166449125933815ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__zC = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 2239706512184205148ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__uA = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 2262815111779762271ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__uB = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 13733912449915273555ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__uC = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 11427961716728280055ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__vA = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 8677893206818249123ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__vB = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 15241954357799112022ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__vC = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 7547395493628553009ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__x_lo_i = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4634058314910592952ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__x_hi_i = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2159491688137671261ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__y_lo_i = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3860438188828869812ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__y_hi_i = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8116922691799037633ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx01 = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 16517382254232531965ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy01 = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 10545187711498321443ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx12 = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 11722648633554941530ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy12 = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 9943772916343372791ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx20 = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 6247671972448024784ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy20 = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 7175557554342812673ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy10_ = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 7120385657205961367ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy20_ = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 15417002062585687664ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx10_ = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 10621625695853982089ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx20_ = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 11241540292971828672ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__p1, __VscopeHash, 603911992367601580ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__p2, __VscopeHash, 15617161804365330364ull);
    VL_SCOPED_RAND_RESET_W(67, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__den, __VscopeHash, 14594547397990744190ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__r0e, __VscopeHash, 15896177002291699371ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__r1e, __VscopeHash, 4379752963777305683ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__r2e, __VscopeHash, 17507681246365304763ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__g0e, __VscopeHash, 9081929076163726662ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__g1e, __VscopeHash, 8136833275849509012ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__g2e, __VscopeHash, 10315158984567941959ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__b0e, __VscopeHash, 14658797584476813224ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__b1e, __VscopeHash, 1562130999948656225ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__b2e, __VscopeHash, 14787667032095730955ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__z0e, __VscopeHash, 9035306322134676335ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__z1e, __VscopeHash, 17718396994853236261ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__z2e, __VscopeHash, 7103315165539325430ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__u0e, __VscopeHash, 3332403521274867773ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__u1e, __VscopeHash, 17715690819796756779ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__u2e, __VscopeHash, 2927610438825209169ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__v0e, __VscopeHash, 4435485171242729936ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__v1e, __VscopeHash, 13676798960735904330ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__v2e, __VscopeHash, 5694689482963110624ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__r10, __VscopeHash, 13185087535590826356ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__r20, __VscopeHash, 6623981137769439869ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__g10, __VscopeHash, 4700763884008922745ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__g20, __VscopeHash, 7893087190276564884ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__b10, __VscopeHash, 14873539447143996586ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__b20, __VscopeHash, 13710759250831545442ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__z10, __VscopeHash, 11860827083380774980ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__z20, __VscopeHash, 2554580490503637958ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__u10, __VscopeHash, 16681685238042824201ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__u20, __VscopeHash, 326402537944416221ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__v10, __VscopeHash, 17458371037664756677ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__v20, __VscopeHash, 11681130641304511210ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__one0[0] = 4194304U;
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__one0[1] = 0U;
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__one0[2] = 0U;
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__zero96[0] = 0U;
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__zero96[1] = 0U;
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__zero96[2] = 0U;
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__xmin = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1961761000810626469ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__xmax = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 433684427044388755ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__ymin = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9853148299449180151ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_setup__DOT__ymax = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3616855616233822922ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9139118026997599033ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17098174377231176954ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 454849200352055037ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__t_blend = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4422570050285096375ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__t_ztest = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13434212912512249601ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__t_tex = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3607743010794272757ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__t_dither = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18075901982593080995ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__t_rgbmap = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7017650748947008355ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__t_texpage = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9930872755009748418ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__iwA = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 6353095804717437715ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__iwB = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 8780452019976384383ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__iwC = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 18349363375509394096ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__rA = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 9986814047257840789ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__rB = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 15108919871094376193ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__rC = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 251190808809632565ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__gA = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 17498923783497785514ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__gB = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 14696915663256260415ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__gC = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 15366778818691076203ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__bA = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 7066403065226365178ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__bB = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 17825306669723968468ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__bC = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 7196483424840045334ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__zA = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 7743594844567567501ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__zB = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 5019192351394647408ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__zC = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 10166363074824184145ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__uA = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 3747660834435114578ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__uB = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 11126408174549484008ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__uC = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 2742317044946541151ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__vA = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 10712811479580521223ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__vB = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 8301164036266836168ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__vC = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 8245153167502091476ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__x_lo_i = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 288525434603546085ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__x_hi_i = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15186701233252416806ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__y_lo_i = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12396552851509257182ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__y_hi_i = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5161940724529753861ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__x0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5500480396261490771ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__y0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11233198845328347192ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__x1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1025896289970917821ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__y1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14439098066148515263ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__x2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16793260510685743760ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__y2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12821388575345018158ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__dx01 = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 2197902865210172246ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__dy01 = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 2805427111589583416ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__dx12 = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 18177757535625081336ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__dy12 = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 1423214197964103579ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__dx20 = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 10302286138483211484ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__dy20 = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 7442365583539782115ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18336540026404924745ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4958563236982575869ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8730410563748054357ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_be = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15645880619763694319ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13260364329373414013ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1066667763175840884ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa2_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14746398141323980898ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa2_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17822638363078644256ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa2_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9259376262043145004ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13588810790139524899ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1777183572874961979ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 2666502337851320918ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__ix = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 981796563743667394ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__iy = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12408096344793991322ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 10020641135921570584ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 10981737351656917394ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__e01, __VscopeHash, 6259440380328121725ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__e12, __VscopeHash, 12583826357521174815ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__e20, __VscopeHash, 12244948375873918834ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__r_v, __VscopeHash, 2386905932279787546ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__g_v, __VscopeHash, 17932177672497354662ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__b_v, __VscopeHash, 14760555758145267655ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__z_v, __VscopeHash, 15929381274430450887ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__u_raw, __VscopeHash, 8693880165231031712ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__v_raw, __VscopeHash, 17143564069072020875ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__inv_w_v, __VscopeHash, 8922354866177897915ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__u_fin, __VscopeHash, 2584192017579215412ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__v_fin, __VscopeHash, 13971904883455470824ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__z_pass = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8501098574395902420ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__cr = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6397573838898066336ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__cg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15702962853716720395ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__cb = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5679333761064415912ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__mr = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4064113504179955775ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__mg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13794919935514024328ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__mb = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14902397225559299972ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__zaddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3935202497299831316ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__faddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8543742318801403981ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__u8w, __VscopeHash, 2589424593822108560ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__v8w, __VscopeHash, 3726148910835083443ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__tex_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7021614037587726672ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__texel_shift = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7964442902875309385ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__texel_byte = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13866928029637389361ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__pix_xy = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7111235035320621003ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__pix_off = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8291728721713348315ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__odd_x = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10840388674513522244ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__pix_word_off = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1026193572169264777ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_r = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5753707066143682734ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_g = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11912496325562340994ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__src_b = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8862886448313435444ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__dith_up = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13760166337873052706ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmr = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9727341717204534023ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16327859767145465070ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT__dmb = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4626674108873357223ull);
    vlSelf->ember_top__DOT__u_rtr__DOT__u_scan__DOT___unused = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14054501830593088335ull);
    vlSelf->ember_top__DOT__u_disp__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12793245065253701874ull);
    vlSelf->ember_top__DOT__u_disp__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8258733935861987933ull);
    vlSelf->ember_top__DOT__u_disp__DOT__fb_select = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11284606096716742617ull);
    vlSelf->ember_top__DOT__u_disp__DOT__fpa3_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5840525617559792941ull);
    vlSelf->ember_top__DOT__u_disp__DOT__fpa3_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14515927291402288718ull);
    vlSelf->ember_top__DOT__u_disp__DOT__fpa3_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7040562617451820017ull);
    vlSelf->ember_top__DOT__u_disp__DOT__vid_hs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14624711921787912813ull);
    vlSelf->ember_top__DOT__u_disp__DOT__vid_vs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12114327006474602313ull);
    vlSelf->ember_top__DOT__u_disp__DOT__vid_de = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10554800150860455401ull);
    vlSelf->ember_top__DOT__u_disp__DOT__vid_pixel = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4546719379572317462ull);
    vlSelf->ember_top__DOT__u_disp__DOT__hcnt = VL_SCOPED_RAND_RESET_I(11, __VscopeHash, 4920242699339995114ull);
    vlSelf->ember_top__DOT__u_disp__DOT__vcnt = VL_SCOPED_RAND_RESET_I(11, __VscopeHash, 33053332389677765ull);
    vlSelf->ember_top__DOT__u_disp__DOT__h_visible = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1960871538647298500ull);
    vlSelf->ember_top__DOT__u_disp__DOT__v_visible = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14235786645526513904ull);
    vlSelf->ember_top__DOT__u_disp__DOT__de_now = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2896407039926516178ull);
    vlSelf->ember_top__DOT__u_disp__DOT__hs_now = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3149611737479314062ull);
    vlSelf->ember_top__DOT__u_disp__DOT__vs_now = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3414430665090985114ull);
    vlSelf->ember_top__DOT__u_disp__DOT__vrow = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 1588230161405794175ull);
    vlSelf->ember_top__DOT__u_disp__DOT__vcol = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 8323151335425422225ull);
    vlSelf->ember_top__DOT__u_disp__DOT__odd_x = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15695708114594670694ull);
    vlSelf->ember_top__DOT__u_disp__DOT__word_byte_off = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2530845311876747045ull);
    vlSelf->ember_top__DOT__u_disp__DOT__req_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12757162331310176944ull);
    vlSelf->ember_top__DOT__u_disp__DOT__addr_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13967188261567175449ull);
    vlSelf->ember_top__DOT__u_disp__DOT__word_q1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17090741519195496808ull);
    vlSelf->ember_top__DOT__u_disp__DOT__word_q2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3081139849436270980ull);
    vlSelf->ember_top__DOT__u_disp__DOT__de_d1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5126546881513592209ull);
    vlSelf->ember_top__DOT__u_disp__DOT__de_d2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2907417332131827216ull);
    vlSelf->ember_top__DOT__u_disp__DOT__de_d3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18304588187097243683ull);
    vlSelf->ember_top__DOT__u_disp__DOT__de_d4 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8696385311167151722ull);
    vlSelf->ember_top__DOT__u_disp__DOT__hs_d1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9580139796759122070ull);
    vlSelf->ember_top__DOT__u_disp__DOT__hs_d2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15330500143662448542ull);
    vlSelf->ember_top__DOT__u_disp__DOT__hs_d3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6683320714722263881ull);
    vlSelf->ember_top__DOT__u_disp__DOT__hs_d4 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4681635278075428643ull);
    vlSelf->ember_top__DOT__u_disp__DOT__vs_d1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15556346474736987930ull);
    vlSelf->ember_top__DOT__u_disp__DOT__vs_d2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9452765580384810518ull);
    vlSelf->ember_top__DOT__u_disp__DOT__vs_d3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9713305468158249854ull);
    vlSelf->ember_top__DOT__u_disp__DOT__vs_d4 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10128526357778727873ull);
    vlSelf->ember_top__DOT__u_disp__DOT__odd_d1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15782717786783029520ull);
    vlSelf->ember_top__DOT__u_disp__DOT__odd_d2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1923686121600584720ull);
    vlSelf->ember_top__DOT__u_disp__DOT__odd_d3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3441965514801420402ull);
    vlSelf->ember_top__DOT__u_disp__DOT__odd_d4 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2082988226152536048ull);
    vlSelf->ember_top__DOT__u_disp__DOT___unused = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4683499335158477253ull);
    vlSelf->ember_top__DOT__u_vram__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11404694938535130847ull);
    vlSelf->ember_top__DOT__u_vram__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12377869688503762464ull);
    vlSelf->ember_top__DOT__u_vram__DOT__s_aw = VL_SCOPED_RAND_RESET_Q(35, __VscopeHash, 10996106306417637918ull);
    vlSelf->ember_top__DOT__u_vram__DOT__s_awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11077206661954601534ull);
    vlSelf->ember_top__DOT__u_vram__DOT__s_awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1066679926416303070ull);
    vlSelf->ember_top__DOT__u_vram__DOT__s_w = VL_SCOPED_RAND_RESET_Q(36, __VscopeHash, 4862174477856107879ull);
    vlSelf->ember_top__DOT__u_vram__DOT__s_wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14833897032900987729ull);
    vlSelf->ember_top__DOT__u_vram__DOT__s_wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3512620717638084738ull);
    vlSelf->ember_top__DOT__u_vram__DOT__s_b = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2069811332692648620ull);
    vlSelf->ember_top__DOT__u_vram__DOT__s_bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1115101936729735984ull);
    vlSelf->ember_top__DOT__u_vram__DOT__s_bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1393710554351119310ull);
    vlSelf->ember_top__DOT__u_vram__DOT__s_ar = VL_SCOPED_RAND_RESET_Q(35, __VscopeHash, 10701188110385282250ull);
    vlSelf->ember_top__DOT__u_vram__DOT__s_arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17404800794157707361ull);
    vlSelf->ember_top__DOT__u_vram__DOT__s_arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18032617597944876841ull);
    vlSelf->ember_top__DOT__u_vram__DOT__s_r = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 3346445260896451190ull);
    vlSelf->ember_top__DOT__u_vram__DOT__s_rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 70366394861470319ull);
    vlSelf->ember_top__DOT__u_vram__DOT__s_rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8708636641188689611ull);
    vlSelf->ember_top__DOT__u_vram__DOT__dbg_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12287340712722353006ull);
    vlSelf->ember_top__DOT__u_vram__DOT__dbg_addr = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 11826344590338551121ull);
    vlSelf->ember_top__DOT__u_vram__DOT__dbg_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13888138926548327770ull);
    vlSelf->ember_top__DOT__u_vram__DOT__dbg_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2614490134980604060ull);
    vlSelf->ember_top__DOT__u_vram__DOT__dbg_be = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14841913294011351102ull);
    vlSelf->ember_top__DOT__u_vram__DOT__fpa_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6089254820950382669ull);
    vlSelf->ember_top__DOT__u_vram__DOT__fpa_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13944407658428900182ull);
    vlSelf->ember_top__DOT__u_vram__DOT__fpa_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4620994952279646733ull);
    vlSelf->ember_top__DOT__u_vram__DOT__fpa_be = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16529754322497496379ull);
    vlSelf->ember_top__DOT__u_vram__DOT__fpa_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16161602264392456067ull);
    vlSelf->ember_top__DOT__u_vram__DOT__fpa_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12859966357850495281ull);
    vlSelf->ember_top__DOT__u_vram__DOT__fpa2_we = 0U;
    ;
    vlSelf->ember_top__DOT__u_vram__DOT__fpa2_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10724249485582733243ull);
    vlSelf->ember_top__DOT__u_vram__DOT__fpa2_wdata = 0U;
    ;
    vlSelf->ember_top__DOT__u_vram__DOT__fpa2_be = 0U;
    ;
    vlSelf->ember_top__DOT__u_vram__DOT__fpa2_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10282782023323486636ull);
    vlSelf->ember_top__DOT__u_vram__DOT__fpa2_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 436872016400689136ull);
    vlSelf->ember_top__DOT__u_vram__DOT__fpa3_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2904174015591866942ull);
    vlSelf->ember_top__DOT__u_vram__DOT__fpa3_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9933453756914256174ull);
    vlSelf->ember_top__DOT__u_vram__DOT__fpa3_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13506450216540652568ull);
    vlSelf->ember_top__DOT__u_vram__DOT__gxa_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13531622409484311581ull);
    vlSelf->ember_top__DOT__u_vram__DOT__gxa_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 150937213929283916ull);
    vlSelf->ember_top__DOT__u_vram__DOT__gxa_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 337678850196104817ull);
    vlSelf->ember_top__DOT__u_vram__DOT__gxa_be = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4466075177369182592ull);
    vlSelf->ember_top__DOT__u_vram__DOT__gxa_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9147097544885484780ull);
    vlSelf->ember_top__DOT__u_vram__DOT__gxa_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10123723965763469573ull);
    vlSelf->ember_top__DOT__u_vram__DOT__cxa_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18077339671016024154ull);
    vlSelf->ember_top__DOT__u_vram__DOT__cxa_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2733333156748443772ull);
    vlSelf->ember_top__DOT__u_vram__DOT__cxa_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7661295013298814412ull);
    vlSelf->ember_top__DOT__u_vram__DOT__cxa_be = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10046039420511374025ull);
    vlSelf->ember_top__DOT__u_vram__DOT__cxa_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18385649291647514589ull);
    vlSelf->ember_top__DOT__u_vram__DOT__cxa_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11432315206388276135ull);
    vlSelf->ember_top__DOT__u_vram__DOT__ixa_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9934959737812457932ull);
    vlSelf->ember_top__DOT__u_vram__DOT__ixa_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4567727175206785100ull);
    vlSelf->ember_top__DOT__u_vram__DOT__ixa_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6835392830801764344ull);
    vlSelf->ember_top__DOT__u_vram__DOT__tua_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14507125197116111808ull);
    vlSelf->ember_top__DOT__u_vram__DOT__tua_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13638296981030624936ull);
    vlSelf->ember_top__DOT__u_vram__DOT__tua_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10717067250097892776ull);
    vlSelf->ember_top__DOT__u_vram__DOT__tua_be = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1637877463199502716ull);
    vlSelf->ember_top__DOT__u_vram__DOT__tua_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10066508697927098256ull);
    vlSelf->ember_top__DOT__u_vram__DOT__tua_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1940333681427676239ull);
    for (int __Vi0 = 0; __Vi0 < 131072; ++__Vi0) {
        vlSelf->ember_top__DOT__u_vram__DOT__ram[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1940569882514551431ull);
    }
    vlSelf->ember_top__DOT__u_vram__DOT__aw_q = VL_SCOPED_RAND_RESET_Q(35, __VscopeHash, 7058251503849086767ull);
    vlSelf->ember_top__DOT__u_vram__DOT__aw_v = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 197478667484486063ull);
    vlSelf->ember_top__DOT__u_vram__DOT__w_q = VL_SCOPED_RAND_RESET_Q(36, __VscopeHash, 4519636528047283506ull);
    vlSelf->ember_top__DOT__u_vram__DOT__w_v = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2291989762051291405ull);
    vlSelf->ember_top__DOT__u_vram__DOT__wr_fire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10874474424026174132ull);
    vlSelf->ember_top__DOT__u_vram__DOT__fpa_widx = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 15947430719737029680ull);
    vlSelf->ember_top__DOT__u_vram__DOT__fpa2_widx = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 11807129559077175725ull);
    vlSelf->ember_top__DOT__u_vram__DOT__fpa_rdata_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13161582331209053391ull);
    vlSelf->ember_top__DOT__u_vram__DOT__fpa2_rdata_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6539036914475298684ull);
    vlSelf->ember_top__DOT__u_vram__DOT__fpa3_widx = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 511331876566836610ull);
    vlSelf->ember_top__DOT__u_vram__DOT__fpa3_rdata_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10919934236522935295ull);
    vlSelf->ember_top__DOT__u_vram__DOT__gxa_widx = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 739405902262338600ull);
    vlSelf->ember_top__DOT__u_vram__DOT__gxa_rdata_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15334816317921049023ull);
    vlSelf->ember_top__DOT__u_vram__DOT__cxa_widx = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 63197042465269733ull);
    vlSelf->ember_top__DOT__u_vram__DOT__cxa_rdata_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 184589242424609762ull);
    vlSelf->ember_top__DOT__u_vram__DOT__ixa_widx = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 3990730969465016769ull);
    vlSelf->ember_top__DOT__u_vram__DOT__ixa_rdata_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 427377040546844715ull);
    vlSelf->ember_top__DOT__u_vram__DOT__tua_widx = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 8030389408677850314ull);
    vlSelf->ember_top__DOT__u_vram__DOT__tua_rdata_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6863546582328401813ull);
    vlSelf->ember_top__DOT__u_vram__DOT__ar_v = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14162816148750946224ull);
    vlSelf->ember_top__DOT__u_vram__DOT__ar_accept = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12759894272914480613ull);
    vlSelf->ember_top__DOT__u_vram__DOT__rdata_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16455918354277703292ull);
    vlSelf->ember_top__DOT__u_vram__DOT__dbg_rdata_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12280303845030266605ull);
    vlSelf->__Vdly__ember_top__DOT__u_tu__DOT__rq_pend = 0;
    vlSelf->__Vdly__ember_top__DOT__u_tu__DOT__rq_req_cyc = 0;
    vlSelf->__Vdly__ember_top__DOT__u_tu__DOT__mac_pend = 0;
    vlSelf->__Vdly__ember_top__DOT__u_tu__DOT__st = 0;
    vlSelf->__Vdly__ember_top__DOT__u_tu__DOT__n0 = 0;
    vlSelf->__Vdly__ember_top__DOT__u_tu__DOT__m0 = 0;
    vlSelf->__Vdly__ember_top__DOT__u_tu__DOT__k0 = 0;
    vlSelf->__Vdly__ember_top__DOT__u_tu__DOT__wrow = 0;
    vlSelf->__Vdly__ember_top__DOT__u_tu__DOT__wgrp = 0;
    vlSelf->__Vdly__ember_top__DOT__u_tu__DOT__cw_word = 0;
    vlSelf->__Vdly__ember_top__DOT__u_tu__DOT__cw_rblk = 0;
    vlSelf->__Vdly__ember_top__DOT__u_tu__DOT__mrow = 0;
    vlSelf->__Vdly__ember_top__DOT__u_tu__DOT__fcnt = 0;
    vlSelf->__Vdly__ember_top__DOT__u_gsx__DOT__mata_ptr = 0;
    vlSelf->__Vdly__ember_top__DOT__u_gsx__DOT__vtx_ptr = 0;
    vlSelf->__Vdly__ember_top__DOT__u_gsx__DOT__col_ptr = 0;
    vlSelf->__VdlySet__ember_top__DOT__u_tu__DOT__abuf_q__v0 = 0;
    vlSelf->__VdlySet__ember_top__DOT__u_tu__DOT__wrowbuf__v0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__ember_top__DOT__u_xbar__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ember_top__DOT__u_xbar__DOT__rst_n__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ember_top__DOT__u_cp__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ember_top__DOT__u_cp__DOT__rst_n__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ember_top__DOT__u_cp__DOT__u_regs__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ember_top__DOT__u_cp__DOT__u_regs__DOT__rst_n__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ember_top__DOT__u_tu__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ember_top__DOT__u_tu__DOT__rst_n__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ember_top__DOT__u_core__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ember_top__DOT__u_core__DOT__rst_n__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ember_top__DOT__u_core__DOT__u_fpu__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ember_top__DOT__u_core__DOT__u_fpu__DOT__rst_n__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ember_top__DOT__u_gsx__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ember_top__DOT__u_gsx__DOT__rst_n__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ember_top__DOT__u_gsx__DOT__u_fpu4__DOT__rst_n__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ember_top__DOT__u_blit__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ember_top__DOT__u_blit__DOT__rst_n__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ember_top__DOT__u_rtr__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ember_top__DOT__u_rtr__DOT__rst_n__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ember_top__DOT__u_rtr__DOT__u_scan__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ember_top__DOT__u_rtr__DOT__u_scan__DOT__rst_n__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ember_top__DOT__u_disp__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ember_top__DOT__u_disp__DOT__rst_n__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ember_top__DOT__u_vram__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ember_top__DOT__u_vram__DOT__rst_n__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
