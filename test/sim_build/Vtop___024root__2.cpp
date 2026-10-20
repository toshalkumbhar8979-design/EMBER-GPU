// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop___024root___nba_sequent__TOP__9(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__9\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ __Vdly__ember_top__DOT__u_blit__DOT__st;
    __Vdly__ember_top__DOT__u_blit__DOT__st = 0;
    CData/*7:0*/ __Vdly__ember_top__DOT__u_blit__DOT__sx;
    __Vdly__ember_top__DOT__u_blit__DOT__sx = 0;
    CData/*7:0*/ __Vdly__ember_top__DOT__u_blit__DOT__sy;
    __Vdly__ember_top__DOT__u_blit__DOT__sy = 0;
    IData/*16:0*/ __Vdly__ember_top__DOT__u_blit__DOT__bx;
    __Vdly__ember_top__DOT__u_blit__DOT__bx = 0;
    // Body
    __Vdly__ember_top__DOT__u_blit__DOT__sx = vlSelfRef.ember_top__DOT__u_blit__DOT__sx;
    __Vdly__ember_top__DOT__u_blit__DOT__sy = vlSelfRef.ember_top__DOT__u_blit__DOT__sy;
    __Vdly__ember_top__DOT__u_blit__DOT__bx = vlSelfRef.ember_top__DOT__u_blit__DOT__bx;
    __Vdly__ember_top__DOT__u_blit__DOT__st = vlSelfRef.ember_top__DOT__u_blit__DOT__st;
    vlSelfRef.ember_top__DOT__u_blit__DOT__done_q = 0U;
    if (vlSelfRef.ember_top__DOT__u_blit__DOT__rst_n) {
        vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_req = 0U;
        vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_we = 0U;
        if ((8U & (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__st))) {
            __Vdly__ember_top__DOT__u_blit__DOT__st = 0U;
        } else if ((4U & (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__st))) {
            if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__st))) {
                if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__st))) {
                    if (((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__sx) 
                         == (0x000000ffU & ((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__w_q) 
                                            - (IData)(1U))))) {
                        __Vdly__ember_top__DOT__u_blit__DOT__sx = 0U;
                        if (((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__sy) 
                             == (0x000000ffU & ((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__h_q) 
                                                - (IData)(1U))))) {
                            vlSelfRef.ember_top__DOT__u_blit__DOT__done_q = 1U;
                            __Vdly__ember_top__DOT__u_blit__DOT__st = 8U;
                        } else {
                            __Vdly__ember_top__DOT__u_blit__DOT__sy 
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
                            __Vdly__ember_top__DOT__u_blit__DOT__bx = 0U;
                            __Vdly__ember_top__DOT__u_blit__DOT__st = 1U;
                        }
                    } else {
                        __Vdly__ember_top__DOT__u_blit__DOT__sx 
                            = (0x000000ffU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__sx)));
                        __Vdly__ember_top__DOT__u_blit__DOT__bx 
                            = (0x0001ffffU & ((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__scale2_q)
                                               ? ((IData)(2U) 
                                                  + vlSelfRef.ember_top__DOT__u_blit__DOT__bx)
                                               : ((IData)(1U) 
                                                  + vlSelfRef.ember_top__DOT__u_blit__DOT__bx)));
                        __Vdly__ember_top__DOT__u_blit__DOT__st = 1U;
                    }
                } else {
                    if ((1U & (~ (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__skip)))) {
                        vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_we = 1U;
                        vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_addr 
                            = (0xfffffffcU & vlSelfRef.ember_top__DOT__u_blit__DOT__daddr3);
                        vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_be 
                            = ((2U & vlSelfRef.ember_top__DOT__u_blit__DOT__daddr3)
                                ? 0x0cU : 3U);
                        vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_wdata 
                            = (((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__pix) 
                                << 0x00000010U) | (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__pix));
                    }
                    __Vdly__ember_top__DOT__u_blit__DOT__st = 7U;
                }
            } else if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__st))) {
                if ((1U & (~ (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__skip)))) {
                    vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_we = 1U;
                    vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_addr 
                        = (0xfffffffcU & vlSelfRef.ember_top__DOT__u_blit__DOT__daddr2);
                    vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_be 
                        = ((2U & vlSelfRef.ember_top__DOT__u_blit__DOT__daddr2)
                            ? 0x0cU : 3U);
                    vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_wdata 
                        = (((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__pix) 
                            << 0x00000010U) | (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__pix));
                }
                __Vdly__ember_top__DOT__u_blit__DOT__st = 6U;
            } else {
                if ((1U & (~ (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__skip)))) {
                    vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_we = 1U;
                    vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_addr 
                        = (0xfffffffcU & vlSelfRef.ember_top__DOT__u_blit__DOT__daddr1);
                    vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_be 
                        = ((2U & vlSelfRef.ember_top__DOT__u_blit__DOT__daddr1)
                            ? 0x0cU : 3U);
                    vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_wdata 
                        = (((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__pix) 
                            << 0x00000010U) | (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__pix));
                }
                __Vdly__ember_top__DOT__u_blit__DOT__st = 5U;
            }
        } else if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__st))) {
            if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__st))) {
                vlSelfRef.ember_top__DOT__u_blit__DOT__pix 
                    = vlSelfRef.ember_top__DOT__u_blit__DOT__rdata_lane;
                vlSelfRef.ember_top__DOT__u_blit__DOT__skip 
                    = vlSelfRef.ember_top__DOT__u_blit__DOT__skip_c;
                vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_we 
                    = (1U & (~ (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__skip_c)));
                vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_addr 
                    = (0xfffffffcU & vlSelfRef.ember_top__DOT__u_blit__DOT__daddr0);
                vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_be 
                    = ((2U & vlSelfRef.ember_top__DOT__u_blit__DOT__daddr0)
                        ? 0x0cU : 3U);
                vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_wdata 
                    = (((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__rdata_lane) 
                        << 0x00000010U) | (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__rdata_lane));
                __Vdly__ember_top__DOT__u_blit__DOT__st 
                    = ((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__scale2_q)
                        ? 4U : 7U);
            } else {
                __Vdly__ember_top__DOT__u_blit__DOT__st = 3U;
            }
        } else if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__st))) {
            vlSelfRef.ember_top__DOT__u_blit__DOT__saddr_q 
                = ((IData)(0x00001000U) + ((vlSelfRef.ember_top__DOT__u_blit__DOT__src_off_q 
                                            + VL_SHIFTL_III(32,32,32, 
                                                            ((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__sy) 
                                                             * (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__w_q)), 1U)) 
                                           + VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__sx), 1U)));
            vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_req = 1U;
            __Vdly__ember_top__DOT__u_blit__DOT__st = 2U;
            vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_addr 
                = (0xfffffffcU & ((IData)(0x00001000U) 
                                  + ((vlSelfRef.ember_top__DOT__u_blit__DOT__src_off_q 
                                      + VL_SHIFTL_III(32,32,32, 
                                                      ((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__sy) 
                                                       * (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__w_q)), 1U)) 
                                     + VL_SHIFTL_III(32,32,32, (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__sx), 1U))));
        } else if (vlSelfRef.ember_top__DOT__u_blit__DOT__kick) {
            __Vdly__ember_top__DOT__u_blit__DOT__sy = 0U;
            vlSelfRef.ember_top__DOT__u_blit__DOT__by = 0U;
            __Vdly__ember_top__DOT__u_blit__DOT__sx = 0U;
            __Vdly__ember_top__DOT__u_blit__DOT__bx = 0U;
            vlSelfRef.ember_top__DOT__u_blit__DOT__skip = 0U;
            __Vdly__ember_top__DOT__u_blit__DOT__st = 1U;
        }
        if (vlSelfRef.ember_top__DOT__u_blit__DOT__csr_we) {
            if ((1U & (~ ((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__csr_addr) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__csr_addr)))) {
                    vlSelfRef.ember_top__DOT__u_blit__DOT__key_en_q 
                        = (1U & (vlSelfRef.ember_top__DOT__u_blit__DOT__csr_wdata 
                                 >> 0x1dU));
                    vlSelfRef.ember_top__DOT__u_blit__DOT__key_color_q 
                        = (0x0000ffffU & vlSelfRef.ember_top__DOT__u_blit__DOT__csr_wdata);
                    vlSelfRef.ember_top__DOT__u_blit__DOT__scale2_q 
                        = (1U & (vlSelfRef.ember_top__DOT__u_blit__DOT__csr_wdata 
                                 >> 0x1eU));
                }
                if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__csr_addr))) {
                    vlSelfRef.ember_top__DOT__u_blit__DOT__dst_off_q 
                        = vlSelfRef.ember_top__DOT__u_blit__DOT__csr_wdata;
                }
            }
            if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__csr_addr))) {
                if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__csr_addr))) {
                    vlSelfRef.ember_top__DOT__u_blit__DOT__w_q 
                        = (0x000000ffU & vlSelfRef.ember_top__DOT__u_blit__DOT__csr_wdata);
                    vlSelfRef.ember_top__DOT__u_blit__DOT__h_q 
                        = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_blit__DOT__csr_wdata 
                                          >> 0x10U));
                }
                if ((1U & (~ (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__csr_addr)))) {
                    vlSelfRef.ember_top__DOT__u_blit__DOT__src_off_q 
                        = vlSelfRef.ember_top__DOT__u_blit__DOT__csr_wdata;
                }
            }
        }
    } else {
        vlSelfRef.ember_top__DOT__u_blit__DOT__key_en_q = 0U;
        vlSelfRef.ember_top__DOT__u_blit__DOT__key_color_q = 0U;
        vlSelfRef.ember_top__DOT__u_blit__DOT__dst_off_q = 0U;
        __Vdly__ember_top__DOT__u_blit__DOT__sy = 0U;
        vlSelfRef.ember_top__DOT__u_blit__DOT__by = 0U;
        __Vdly__ember_top__DOT__u_blit__DOT__st = 0U;
        __Vdly__ember_top__DOT__u_blit__DOT__sx = 0U;
        __Vdly__ember_top__DOT__u_blit__DOT__bx = 0U;
        vlSelfRef.ember_top__DOT__u_blit__DOT__saddr_q = 0U;
        vlSelfRef.ember_top__DOT__u_blit__DOT__pix = 0U;
        vlSelfRef.ember_top__DOT__u_blit__DOT__skip = 0U;
        vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_req = 0U;
        vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_addr = 0U;
        vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_we = 0U;
        vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_wdata = 0U;
        vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_be = 0U;
        vlSelfRef.ember_top__DOT__u_blit__DOT__w_q = 0U;
        vlSelfRef.ember_top__DOT__u_blit__DOT__h_q = 0U;
        vlSelfRef.ember_top__DOT__u_blit__DOT__scale2_q = 0U;
        vlSelfRef.ember_top__DOT__u_blit__DOT__src_off_q = 0U;
    }
    vlSelfRef.ember_top__DOT__u_blit__DOT__sx = __Vdly__ember_top__DOT__u_blit__DOT__sx;
    vlSelfRef.ember_top__DOT__u_blit__DOT__sy = __Vdly__ember_top__DOT__u_blit__DOT__sy;
    vlSelfRef.ember_top__DOT__u_blit__DOT__bx = __Vdly__ember_top__DOT__u_blit__DOT__bx;
    vlSelfRef.ember_top__DOT__u_blit__DOT__st = __Vdly__ember_top__DOT__u_blit__DOT__st;
    vlSelfRef.ember_top__DOT__u_blit__DOT__done = vlSelfRef.ember_top__DOT__u_blit__DOT__done_q;
    vlSelfRef.ember_top__DOT__blit_fpa_req = vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_req;
    vlSelfRef.ember_top__DOT__blit_fpa_we = vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_we;
    vlSelfRef.ember_top__DOT__blit_fpa_be = vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_be;
    vlSelfRef.ember_top__DOT__blit_fpa_wdata = vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_wdata;
    vlSelfRef.ember_top__DOT__u_blit__DOT__daddr0 = 
        ((IData)(0x00001000U) + (vlSelfRef.ember_top__DOT__u_blit__DOT__dst_off_q 
                                 + (((IData)(0x00000280U) 
                                     * vlSelfRef.ember_top__DOT__u_blit__DOT__by) 
                                    + VL_SHIFTL_III(32,32,32, 
                                                    (0x000001ffU 
                                                     & vlSelfRef.ember_top__DOT__u_blit__DOT__bx), 1U))));
    vlSelfRef.ember_top__DOT__blit_fpa_addr = vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_addr;
    vlSelfRef.ember_top__DOT__u_blit__DOT__busy = (0U 
                                                   != (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__st));
    vlSelfRef.ember_top__DOT__u_blit__DOT__daddr1 = 
        ((IData)(2U) + vlSelfRef.ember_top__DOT__u_blit__DOT__daddr0);
    vlSelfRef.ember_top__DOT__u_blit__DOT__daddr2 = 
        ((IData)(0x00000280U) + vlSelfRef.ember_top__DOT__u_blit__DOT__daddr0);
    vlSelfRef.ember_top__DOT__u_blit__DOT__daddr3 = 
        ((IData)(0x00000282U) + vlSelfRef.ember_top__DOT__u_blit__DOT__daddr0);
    vlSelfRef.ember_top__DOT__blit_busy = vlSelfRef.ember_top__DOT__u_blit__DOT__busy;
    vlSelfRef.ember_top__DOT__u_cp__DOT__blit_busy 
        = vlSelfRef.ember_top__DOT__blit_busy;
}

void Vtop___024root___nba_sequent__TOP__10(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__10\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v0;
    __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v0 = 0;
    IData/*16:0*/ __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v0;
    __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v0 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_vram__DOT__ram__v0;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v0 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v1;
    __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v1 = 0;
    IData/*16:0*/ __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v1;
    __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v1 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_vram__DOT__ram__v1;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v1 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v2;
    __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v2 = 0;
    IData/*16:0*/ __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v2;
    __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v2 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_vram__DOT__ram__v2;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v2 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v3;
    __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v3 = 0;
    IData/*16:0*/ __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v3;
    __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v3 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_vram__DOT__ram__v3;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v3 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v4;
    __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v4 = 0;
    IData/*16:0*/ __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v4;
    __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v4 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_vram__DOT__ram__v4;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v4 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v5;
    __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v5 = 0;
    IData/*16:0*/ __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v5;
    __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v5 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_vram__DOT__ram__v5;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v5 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v6;
    __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v6 = 0;
    IData/*16:0*/ __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v6;
    __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v6 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_vram__DOT__ram__v6;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v6 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v7;
    __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v7 = 0;
    IData/*16:0*/ __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v7;
    __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v7 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_vram__DOT__ram__v7;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v7 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v8;
    __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v8 = 0;
    IData/*16:0*/ __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v8;
    __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v8 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_vram__DOT__ram__v8;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v8 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v9;
    __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v9 = 0;
    IData/*16:0*/ __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v9;
    __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v9 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_vram__DOT__ram__v9;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v9 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v10;
    __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v10 = 0;
    IData/*16:0*/ __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v10;
    __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v10 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_vram__DOT__ram__v10;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v10 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v11;
    __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v11 = 0;
    IData/*16:0*/ __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v11;
    __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v11 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_vram__DOT__ram__v11;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v11 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v12;
    __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v12 = 0;
    IData/*16:0*/ __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v12;
    __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v12 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_vram__DOT__ram__v12;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v12 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v13;
    __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v13 = 0;
    IData/*16:0*/ __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v13;
    __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v13 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_vram__DOT__ram__v13;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v13 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v14;
    __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v14 = 0;
    IData/*16:0*/ __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v14;
    __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v14 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_vram__DOT__ram__v14;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v14 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v15;
    __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v15 = 0;
    IData/*16:0*/ __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v15;
    __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v15 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_vram__DOT__ram__v15;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v15 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v16;
    __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v16 = 0;
    IData/*16:0*/ __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v16;
    __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v16 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_vram__DOT__ram__v16;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v16 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v17;
    __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v17 = 0;
    IData/*16:0*/ __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v17;
    __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v17 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_vram__DOT__ram__v17;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v17 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v18;
    __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v18 = 0;
    IData/*16:0*/ __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v18;
    __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v18 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_vram__DOT__ram__v18;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v18 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v19;
    __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v19 = 0;
    IData/*16:0*/ __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v19;
    __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v19 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_vram__DOT__ram__v19;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v19 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v20;
    __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v20 = 0;
    IData/*16:0*/ __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v20;
    __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v20 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_vram__DOT__ram__v20;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v20 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v21;
    __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v21 = 0;
    IData/*16:0*/ __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v21;
    __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v21 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_vram__DOT__ram__v21;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v21 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v22;
    __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v22 = 0;
    IData/*16:0*/ __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v22;
    __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v22 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_vram__DOT__ram__v22;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v22 = 0;
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v23;
    __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v23 = 0;
    IData/*16:0*/ __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v23;
    __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v23 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_vram__DOT__ram__v23;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v23 = 0;
    // Body
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v8 = 0U;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v9 = 0U;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v10 = 0U;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v11 = 0U;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v12 = 0U;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v13 = 0U;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v14 = 0U;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v15 = 0U;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v16 = 0U;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v17 = 0U;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v18 = 0U;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v19 = 0U;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v20 = 0U;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v21 = 0U;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v22 = 0U;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v23 = 0U;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v4 = 0U;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v5 = 0U;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v6 = 0U;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v7 = 0U;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v0 = 0U;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v1 = 0U;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v2 = 0U;
    __VdlySet__ember_top__DOT__u_vram__DOT__ram__v3 = 0U;
    if (vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_we) {
        if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_be))) {
            __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v8 
                = (0x000000ffU & vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_wdata);
            __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v8 
                = vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_widx;
            __VdlySet__ember_top__DOT__u_vram__DOT__ram__v8 = 1U;
        }
        if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_be))) {
            __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v9 
                = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_wdata 
                                  >> 8U));
            __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v9 
                = vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_widx;
            __VdlySet__ember_top__DOT__u_vram__DOT__ram__v9 = 1U;
        }
        if ((4U & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_be))) {
            __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v10 
                = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_wdata 
                                  >> 0x10U));
            __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v10 
                = vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_widx;
            __VdlySet__ember_top__DOT__u_vram__DOT__ram__v10 = 1U;
        }
        if ((8U & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_be))) {
            __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v11 
                = (vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_wdata 
                   >> 0x18U);
            __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v11 
                = vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_widx;
            __VdlySet__ember_top__DOT__u_vram__DOT__ram__v11 = 1U;
        }
    }
    if (vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_we) {
        if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_be))) {
            __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v12 
                = (0x000000ffU & vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_wdata);
            __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v12 
                = vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_widx;
            __VdlySet__ember_top__DOT__u_vram__DOT__ram__v12 = 1U;
        }
        if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_be))) {
            __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v13 
                = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_wdata 
                                  >> 8U));
            __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v13 
                = vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_widx;
            __VdlySet__ember_top__DOT__u_vram__DOT__ram__v13 = 1U;
        }
        if ((4U & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_be))) {
            __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v14 
                = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_wdata 
                                  >> 0x10U));
            __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v14 
                = vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_widx;
            __VdlySet__ember_top__DOT__u_vram__DOT__ram__v14 = 1U;
        }
        if ((8U & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_be))) {
            __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v15 
                = (vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_wdata 
                   >> 0x18U);
            __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v15 
                = vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_widx;
            __VdlySet__ember_top__DOT__u_vram__DOT__ram__v15 = 1U;
        }
    }
    if (vlSelfRef.ember_top__DOT__u_vram__DOT__cxa_we) {
        if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__cxa_be))) {
            __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v16 
                = (0x000000ffU & vlSelfRef.ember_top__DOT__u_vram__DOT__cxa_wdata);
            __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v16 
                = vlSelfRef.ember_top__DOT__u_vram__DOT__cxa_widx;
            __VdlySet__ember_top__DOT__u_vram__DOT__ram__v16 = 1U;
        }
        if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__cxa_be))) {
            __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v17 
                = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_vram__DOT__cxa_wdata 
                                  >> 8U));
            __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v17 
                = vlSelfRef.ember_top__DOT__u_vram__DOT__cxa_widx;
            __VdlySet__ember_top__DOT__u_vram__DOT__ram__v17 = 1U;
        }
        if ((4U & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__cxa_be))) {
            __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v18 
                = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_vram__DOT__cxa_wdata 
                                  >> 0x10U));
            __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v18 
                = vlSelfRef.ember_top__DOT__u_vram__DOT__cxa_widx;
            __VdlySet__ember_top__DOT__u_vram__DOT__ram__v18 = 1U;
        }
        if ((8U & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__cxa_be))) {
            __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v19 
                = (vlSelfRef.ember_top__DOT__u_vram__DOT__cxa_wdata 
                   >> 0x18U);
            __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v19 
                = vlSelfRef.ember_top__DOT__u_vram__DOT__cxa_widx;
            __VdlySet__ember_top__DOT__u_vram__DOT__ram__v19 = 1U;
        }
    }
    if (vlSelfRef.ember_top__DOT__u_vram__DOT__tua_we) {
        if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__tua_be))) {
            __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v20 
                = (0x000000ffU & vlSelfRef.ember_top__DOT__u_vram__DOT__tua_wdata);
            __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v20 
                = vlSelfRef.ember_top__DOT__u_vram__DOT__tua_widx;
            __VdlySet__ember_top__DOT__u_vram__DOT__ram__v20 = 1U;
        }
        if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__tua_be))) {
            __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v21 
                = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_vram__DOT__tua_wdata 
                                  >> 8U));
            __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v21 
                = vlSelfRef.ember_top__DOT__u_vram__DOT__tua_widx;
            __VdlySet__ember_top__DOT__u_vram__DOT__ram__v21 = 1U;
        }
        if ((4U & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__tua_be))) {
            __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v22 
                = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_vram__DOT__tua_wdata 
                                  >> 0x10U));
            __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v22 
                = vlSelfRef.ember_top__DOT__u_vram__DOT__tua_widx;
            __VdlySet__ember_top__DOT__u_vram__DOT__ram__v22 = 1U;
        }
        if ((8U & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__tua_be))) {
            __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v23 
                = (vlSelfRef.ember_top__DOT__u_vram__DOT__tua_wdata 
                   >> 0x18U);
            __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v23 
                = vlSelfRef.ember_top__DOT__u_vram__DOT__tua_widx;
            __VdlySet__ember_top__DOT__u_vram__DOT__ram__v23 = 1U;
        }
    }
    if (((IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__dbg_en) 
         & (0U != (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__dbg_be)))) {
        if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__dbg_be))) {
            __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v4 
                = (0x000000ffU & vlSelfRef.ember_top__DOT__u_vram__DOT__dbg_wdata);
            __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v4 
                = vlSelfRef.ember_top__DOT__u_vram__DOT__dbg_addr;
            __VdlySet__ember_top__DOT__u_vram__DOT__ram__v4 = 1U;
        }
        if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__dbg_be))) {
            __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v5 
                = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_vram__DOT__dbg_wdata 
                                  >> 8U));
            __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v5 
                = vlSelfRef.ember_top__DOT__u_vram__DOT__dbg_addr;
            __VdlySet__ember_top__DOT__u_vram__DOT__ram__v5 = 1U;
        }
        if ((4U & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__dbg_be))) {
            __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v6 
                = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_vram__DOT__dbg_wdata 
                                  >> 0x10U));
            __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v6 
                = vlSelfRef.ember_top__DOT__u_vram__DOT__dbg_addr;
            __VdlySet__ember_top__DOT__u_vram__DOT__ram__v6 = 1U;
        }
        if ((8U & (IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__dbg_be))) {
            __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v7 
                = (vlSelfRef.ember_top__DOT__u_vram__DOT__dbg_wdata 
                   >> 0x18U);
            __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v7 
                = vlSelfRef.ember_top__DOT__u_vram__DOT__dbg_addr;
            __VdlySet__ember_top__DOT__u_vram__DOT__ram__v7 = 1U;
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
            __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v0 
                = (0x000000ffU & (IData)((vlSelfRef.ember_top__DOT__u_vram__DOT__w_q 
                                          >> 4U)));
            __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v0 
                = __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__121__Vfuncout;
            __VdlySet__ember_top__DOT__u_vram__DOT__ram__v0 = 1U;
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
            __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v1 
                = (0x000000ffU & (IData)((vlSelfRef.ember_top__DOT__u_vram__DOT__w_q 
                                          >> 0x0000000cU)));
            __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v1 
                = __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__122__Vfuncout;
            __VdlySet__ember_top__DOT__u_vram__DOT__ram__v1 = 1U;
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
            __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v2 
                = (0x000000ffU & (IData)((vlSelfRef.ember_top__DOT__u_vram__DOT__w_q 
                                          >> 0x00000014U)));
            __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v2 
                = __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__123__Vfuncout;
            __VdlySet__ember_top__DOT__u_vram__DOT__ram__v2 = 1U;
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
            __VdlyVal__ember_top__DOT__u_vram__DOT__ram__v3 
                = (0x000000ffU & (IData)((vlSelfRef.ember_top__DOT__u_vram__DOT__w_q 
                                          >> 0x0000001cU)));
            __VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v3 
                = __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__124__Vfuncout;
            __VdlySet__ember_top__DOT__u_vram__DOT__ram__v3 = 1U;
        }
    }
    if (vlSelfRef.ember_top__DOT__u_vram__DOT__fpa3_req) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__fpa3_rdata_q 
            = vlSelfRef.ember_top__DOT__u_vram__DOT__ram
            [vlSelfRef.ember_top__DOT__u_vram__DOT__fpa3_widx];
    }
    if (vlSelfRef.ember_top__DOT__u_vram__DOT__ixa_req) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ixa_rdata_q 
            = vlSelfRef.ember_top__DOT__u_vram__DOT__ram
            [vlSelfRef.ember_top__DOT__u_vram__DOT__ixa_widx];
    }
    if (vlSelfRef.ember_top__DOT__u_vram__DOT__cxa_req) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__cxa_rdata_q 
            = vlSelfRef.ember_top__DOT__u_vram__DOT__ram
            [vlSelfRef.ember_top__DOT__u_vram__DOT__cxa_widx];
    }
    if (vlSelfRef.ember_top__DOT__u_vram__DOT__tua_req) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__tua_rdata_q 
            = vlSelfRef.ember_top__DOT__u_vram__DOT__ram
            [vlSelfRef.ember_top__DOT__u_vram__DOT__tua_widx];
    }
    if (vlSelfRef.ember_top__DOT__u_vram__DOT__dbg_en) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__dbg_rdata_q 
            = vlSelfRef.ember_top__DOT__u_vram__DOT__ram
            [vlSelfRef.ember_top__DOT__u_vram__DOT__dbg_addr];
    }
    if (vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_req) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_rdata_q 
            = vlSelfRef.ember_top__DOT__u_vram__DOT__ram
            [vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_widx];
    }
    if (vlSelfRef.ember_top__DOT__u_vram__DOT__fpa2_req) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__fpa2_rdata_q 
            = vlSelfRef.ember_top__DOT__u_vram__DOT__ram
            [vlSelfRef.ember_top__DOT__u_vram__DOT__fpa2_widx];
    }
    if (vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_req) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_rdata_q 
            = vlSelfRef.ember_top__DOT__u_vram__DOT__ram
            [vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_widx];
    }
    if (vlSelfRef.ember_top__DOT__u_vram__DOT__ar_accept) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__rdata_q 
            = vlSelfRef.ember_top__DOT__u_vram__DOT__ram
            [([&]() {
                __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__132__a 
                    = (IData)((vlSelfRef.ember_top__DOT__u_vram__DOT__s_ar 
                               >> 3U));
                __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__132__off 
                    = (__Vfunc_ember_top__DOT__u_vram__DOT__addr2word__132__a 
                       - (IData)(0x00001000U));
                __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__132__Vfuncout 
                    = (0x0001ffffU & (__Vfunc_ember_top__DOT__u_vram__DOT__addr2word__132__off 
                                      >> 2U));
            }(), __Vfunc_ember_top__DOT__u_vram__DOT__addr2word__132__Vfuncout)];
    }
    if (__VdlySet__ember_top__DOT__u_vram__DOT__ram__v0) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v0] 
            = ((0xffffff00U & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v0]) 
               | (IData)(__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v0));
    }
    if (__VdlySet__ember_top__DOT__u_vram__DOT__ram__v1) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v1] 
            = ((0xffff00ffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v1]) 
               | ((IData)(__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v1) 
                  << 8U));
    }
    if (__VdlySet__ember_top__DOT__u_vram__DOT__ram__v2) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v2] 
            = ((0xff00ffffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v2]) 
               | ((IData)(__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v2) 
                  << 0x00000010U));
    }
    if (__VdlySet__ember_top__DOT__u_vram__DOT__ram__v3) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v3] 
            = ((0x00ffffffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v3]) 
               | ((IData)(__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v3) 
                  << 0x00000018U));
    }
    if (__VdlySet__ember_top__DOT__u_vram__DOT__ram__v4) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v4] 
            = ((0xffffff00U & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v4]) 
               | (IData)(__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v4));
    }
    if (__VdlySet__ember_top__DOT__u_vram__DOT__ram__v5) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v5] 
            = ((0xffff00ffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v5]) 
               | ((IData)(__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v5) 
                  << 8U));
    }
    if (__VdlySet__ember_top__DOT__u_vram__DOT__ram__v6) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v6] 
            = ((0xff00ffffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v6]) 
               | ((IData)(__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v6) 
                  << 0x00000010U));
    }
    if (__VdlySet__ember_top__DOT__u_vram__DOT__ram__v7) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v7] 
            = ((0x00ffffffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v7]) 
               | ((IData)(__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v7) 
                  << 0x00000018U));
    }
    if (__VdlySet__ember_top__DOT__u_vram__DOT__ram__v8) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v8] 
            = ((0xffffff00U & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v8]) 
               | (IData)(__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v8));
    }
    if (__VdlySet__ember_top__DOT__u_vram__DOT__ram__v9) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v9] 
            = ((0xffff00ffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v9]) 
               | ((IData)(__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v9) 
                  << 8U));
    }
    if (__VdlySet__ember_top__DOT__u_vram__DOT__ram__v10) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v10] 
            = ((0xff00ffffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v10]) 
               | ((IData)(__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v10) 
                  << 0x00000010U));
    }
    if (__VdlySet__ember_top__DOT__u_vram__DOT__ram__v11) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v11] 
            = ((0x00ffffffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v11]) 
               | ((IData)(__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v11) 
                  << 0x00000018U));
    }
    if (__VdlySet__ember_top__DOT__u_vram__DOT__ram__v12) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v12] 
            = ((0xffffff00U & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v12]) 
               | (IData)(__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v12));
    }
    if (__VdlySet__ember_top__DOT__u_vram__DOT__ram__v13) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v13] 
            = ((0xffff00ffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v13]) 
               | ((IData)(__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v13) 
                  << 8U));
    }
    if (__VdlySet__ember_top__DOT__u_vram__DOT__ram__v14) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v14] 
            = ((0xff00ffffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v14]) 
               | ((IData)(__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v14) 
                  << 0x00000010U));
    }
    if (__VdlySet__ember_top__DOT__u_vram__DOT__ram__v15) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v15] 
            = ((0x00ffffffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v15]) 
               | ((IData)(__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v15) 
                  << 0x00000018U));
    }
    if (__VdlySet__ember_top__DOT__u_vram__DOT__ram__v16) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v16] 
            = ((0xffffff00U & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v16]) 
               | (IData)(__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v16));
    }
    if (__VdlySet__ember_top__DOT__u_vram__DOT__ram__v17) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v17] 
            = ((0xffff00ffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v17]) 
               | ((IData)(__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v17) 
                  << 8U));
    }
    if (__VdlySet__ember_top__DOT__u_vram__DOT__ram__v18) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v18] 
            = ((0xff00ffffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v18]) 
               | ((IData)(__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v18) 
                  << 0x00000010U));
    }
    if (__VdlySet__ember_top__DOT__u_vram__DOT__ram__v19) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v19] 
            = ((0x00ffffffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v19]) 
               | ((IData)(__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v19) 
                  << 0x00000018U));
    }
    if (__VdlySet__ember_top__DOT__u_vram__DOT__ram__v20) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v20] 
            = ((0xffffff00U & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v20]) 
               | (IData)(__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v20));
    }
    if (__VdlySet__ember_top__DOT__u_vram__DOT__ram__v21) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v21] 
            = ((0xffff00ffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v21]) 
               | ((IData)(__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v21) 
                  << 8U));
    }
    if (__VdlySet__ember_top__DOT__u_vram__DOT__ram__v22) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v22] 
            = ((0xff00ffffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v22]) 
               | ((IData)(__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v22) 
                  << 0x00000010U));
    }
    if (__VdlySet__ember_top__DOT__u_vram__DOT__ram__v23) {
        vlSelfRef.ember_top__DOT__u_vram__DOT__ram[__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v23] 
            = ((0x00ffffffU & vlSelfRef.ember_top__DOT__u_vram__DOT__ram
                [__VdlyDim0__ember_top__DOT__u_vram__DOT__ram__v23]) 
               | ((IData)(__VdlyVal__ember_top__DOT__u_vram__DOT__ram__v23) 
                  << 0x00000018U));
    }
    vlSelfRef.ember_top__DOT__u_vram__DOT__fpa3_rdata 
        = vlSelfRef.ember_top__DOT__u_vram__DOT__fpa3_rdata_q;
    vlSelfRef.ember_top__DOT__u_vram__DOT__ixa_rdata 
        = vlSelfRef.ember_top__DOT__u_vram__DOT__ixa_rdata_q;
    vlSelfRef.ember_top__DOT__u_vram__DOT__cxa_rdata 
        = vlSelfRef.ember_top__DOT__u_vram__DOT__cxa_rdata_q;
    vlSelfRef.ember_top__DOT__u_vram__DOT__tua_rdata 
        = vlSelfRef.ember_top__DOT__u_vram__DOT__tua_rdata_q;
    vlSelfRef.ember_top__DOT__u_vram__DOT__dbg_rdata 
        = vlSelfRef.ember_top__DOT__u_vram__DOT__dbg_rdata_q;
    vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_rdata 
        = vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_rdata_q;
    vlSelfRef.ember_top__DOT__u_vram__DOT__fpa2_rdata 
        = vlSelfRef.ember_top__DOT__u_vram__DOT__fpa2_rdata_q;
    vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_rdata 
        = vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_rdata_q;
    vlSelfRef.ember_top__DOT__u_vram__DOT__s_r = ((QData)((IData)(vlSelfRef.ember_top__DOT__u_vram__DOT__rdata_q)) 
                                                  << 2U);
    vlSelfRef.ember_top__DOT__fpa3_rdata = vlSelfRef.ember_top__DOT__u_vram__DOT__fpa3_rdata;
    vlSelfRef.ember_top__DOT__core_ixa_rdata = vlSelfRef.ember_top__DOT__u_vram__DOT__ixa_rdata;
    vlSelfRef.ember_top__DOT__core_cxa_rdata = vlSelfRef.ember_top__DOT__u_vram__DOT__cxa_rdata;
    vlSelfRef.ember_top__DOT__tu_tua_rdata = vlSelfRef.ember_top__DOT__u_vram__DOT__tua_rdata;
    vlSelfRef.ember_top__DOT__dbg_rdata = vlSelfRef.ember_top__DOT__u_vram__DOT__dbg_rdata;
    vlSelfRef.ember_top__DOT__gsx_gxa_rdata = vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_rdata;
    vlSelfRef.ember_top__DOT__fpa2_rdata = vlSelfRef.ember_top__DOT__u_vram__DOT__fpa2_rdata;
    vlSelfRef.ember_top__DOT__fpa_rdata = vlSelfRef.ember_top__DOT__u_vram__DOT__fpa_rdata;
    vlSelfRef.ember_top__DOT__v_r = vlSelfRef.ember_top__DOT__u_vram__DOT__s_r;
    vlSelfRef.ember_top__DOT__u_disp__DOT__fpa3_rdata 
        = vlSelfRef.ember_top__DOT__fpa3_rdata;
    vlSelfRef.dbg_rdata = vlSelfRef.ember_top__DOT__dbg_rdata;
    vlSelfRef.ember_top__DOT__u_gsx__DOT__gxa_rdata 
        = vlSelfRef.ember_top__DOT__gsx_gxa_rdata;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__fpa2_rdata 
        = vlSelfRef.ember_top__DOT__fpa2_rdata;
    vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_rdata 
        = vlSelfRef.ember_top__DOT__fpa_rdata;
    vlSelfRef.ember_top__DOT__u_xbar__DOT__v_r = vlSelfRef.ember_top__DOT__v_r;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa2_rdata 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__fpa2_rdata;
    vlSelfRef.ember_top__DOT__u_xbar__DOT__d_r = vlSelfRef.ember_top__DOT__u_xbar__DOT__v_r;
    vlSelfRef.ember_top__DOT__d_r = vlSelfRef.ember_top__DOT__u_xbar__DOT__d_r;
    vlSelfRef.ember_top__DOT__u_cp__DOT__m_r = vlSelfRef.ember_top__DOT__d_r;
    vlSelfRef.ember_top__DOT__u_cp__DOT__rb_data_in 
        = (IData)((vlSelfRef.ember_top__DOT__u_cp__DOT__m_r 
                   >> 2U));
}

void Vtop___024root___nba_sequent__TOP__11(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__11\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
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
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__Vfuncout;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__Vfuncout);
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__A;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__A = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__B;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__B = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__C;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__C = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__px;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__px = 0;
    QData/*63:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__py;
    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__py = 0;
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__s;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__s);
    VlWide<3>/*95:0*/ __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__sh;
    VL_ZERO_W(96, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__sh);
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
    CData/*3:0*/ __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st;
    __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 0;
    QData/*63:0*/ __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy;
    __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy = 0;
    SData/*15:0*/ __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__ix;
    __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__ix = 0;
    QData/*63:0*/ __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx;
    __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx = 0;
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
    VlWide<3>/*95:0*/ __Vtemp_20;
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
    VlWide<3>/*95:0*/ __Vtemp_36;
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
    VlWide<3>/*95:0*/ __Vtemp_52;
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
    VlWide<3>/*95:0*/ __Vtemp_68;
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
    // Body
    __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy;
    __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx;
    __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__ix 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__ix;
    __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__st;
    if (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__rst_n) {
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__done = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_req = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_we = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa2_req = 0U;
        if ((8U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__st))) {
            if ((4U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__st))) {
                if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__st))) {
                    __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 0U;
                } else if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__st))) {
                    if (((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__ix) 
                         == (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__x_hi_i))) {
                        if (((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__iy) 
                             == (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__y_hi_i))) {
                            vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__done = 1U;
                            __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 0U;
                        } else {
                            vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__iy 
                                = (0x0000ffffU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__iy)));
                            __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy 
                                = (0x0000000000400000ULL 
                                   + vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy);
                            __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__ix 
                                = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__x_lo_i;
                            __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx 
                                = (0x0000000000200000ULL 
                                   + VL_SHIFTL_QQI(64,64,32, 
                                                   (((- (QData)((IData)(
                                                                        (1U 
                                                                         & ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__x_lo_i) 
                                                                            >> 0x0fU))))) 
                                                     << 0x00000010U) 
                                                    | (QData)((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__x_lo_i))), 0x00000016U));
                            __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 1U;
                        }
                    } else {
                        __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__ix 
                            = (0x0000ffffU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__ix)));
                        __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx 
                            = (0x0000000000400000ULL 
                               + vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx);
                        __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 1U;
                    }
                } else {
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_we = 1U;
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_addr 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__zaddr;
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_be 
                        = ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__odd_x)
                            ? 0x0cU : 3U);
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_wdata 
                        = ((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__z_v[0U] 
                            << 0x00000010U) | (0x0000ffffU 
                                               & vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__z_v[0U]));
                    __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 0x0dU;
                }
            } else if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__st))) {
                if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__st))) {
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_we = 1U;
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_addr 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__faddr;
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_be 
                        = ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__odd_x)
                            ? 0x0cU : 3U);
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_wdata 
                        = ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__t_rgbmap)
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
                    __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st 
                        = (((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__t_ztest) 
                            & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__z_pass))
                            ? 0x0cU : 0x0dU);
                } else {
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__100__hi 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__odd_x;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__103__hi 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__odd_x;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__106__hi 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__odd_x;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__100__w 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_rdata;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__103__w 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_rdata;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__106__w 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_rdata;
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
                    __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 0x0bU;
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
                __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 0x0aU;
            } else {
                vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_req = 1U;
                vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_addr 
                    = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__faddr;
                __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 9U;
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
                    __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st 
                        = ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__t_blend)
                            ? 8U : 0x0bU);
                } else {
                    __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 7U;
                }
            } else if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__st))) {
                vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa2_req = 1U;
                vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa2_addr 
                    = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__tex_addr;
                __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 6U;
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
                if (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__t_tex) {
                    __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 5U;
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
                    __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st 
                        = ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__t_blend)
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
                                = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__odd_x;
                            __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__112__w 
                                = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_rdata;
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
                                = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__odd_x;
                            __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__113__w 
                                = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_rdata;
                            __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__113__Vfuncout 
                                = (0x0000ffffU & ((IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__113__hi)
                                                   ? 
                                                  (__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__113__w 
                                                   >> 0x10U)
                                                   : __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__113__w));
                        }(), (IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__half_get__113__Vfuncout)));
                __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st 
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
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__py 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__px 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx;
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__zaddr 
                        = ((IData)(0x00026800U) + vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__pix_word_off);
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__faddr 
                        = ((IData)(0x00001000U) + vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__pix_word_off);
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__C 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__iwC;
                    __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st 
                        = ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__t_ztest)
                            ? 3U : 4U);
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__B 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__iwB;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__A 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__iwA;
                    VL_EXTENDS_WQ(96,64, __Vtemp_20, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__A);
                    VL_EXTENDS_WQ(96,64, __Vtemp_21, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__px);
                    VL_MULS_WWW(96, __Vtemp_22, __Vtemp_20, __Vtemp_21);
                    VL_EXTENDS_WQ(96,64, __Vtemp_23, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__B);
                    VL_EXTENDS_WQ(96,64, __Vtemp_24, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__py);
                    VL_MULS_WWW(96, __Vtemp_25, __Vtemp_23, __Vtemp_24);
                    VL_ADD_W(3, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__s, __Vtemp_22, __Vtemp_25);
                    VL_SHIFTRS_WWI(96,96,32, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__sh, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__s, 0x00000016U);
                    __Vtemp_26[0U] = (IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__C);
                    __Vtemp_26[1U] = (IData)((__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__C 
                                              >> 0x00000020U));
                    __Vtemp_26[2U] = (- (IData)((1U 
                                                 & (IData)(
                                                           (__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__C 
                                                            >> 0x3fU)))));
                    VL_ADD_W(3, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__Vfuncout, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__sh, __Vtemp_26);
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__inv_w_v[0U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__Vfuncout[0U];
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__inv_w_v[1U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__Vfuncout[1U];
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__inv_w_v[2U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__114__Vfuncout[2U];
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__py 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__px 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__C 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__rC;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__B 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__rB;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__A 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__rA;
                    VL_EXTENDS_WQ(96,64, __Vtemp_27, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__A);
                    VL_EXTENDS_WQ(96,64, __Vtemp_28, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__px);
                    VL_MULS_WWW(96, __Vtemp_29, __Vtemp_27, __Vtemp_28);
                    VL_EXTENDS_WQ(96,64, __Vtemp_30, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__B);
                    VL_EXTENDS_WQ(96,64, __Vtemp_31, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__py);
                    VL_MULS_WWW(96, __Vtemp_32, __Vtemp_30, __Vtemp_31);
                    VL_ADD_W(3, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__s, __Vtemp_29, __Vtemp_32);
                    VL_SHIFTRS_WWI(96,96,32, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__sh, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__s, 0x00000016U);
                    __Vtemp_33[0U] = (IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__C);
                    __Vtemp_33[1U] = (IData)((__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__C 
                                              >> 0x00000020U));
                    __Vtemp_33[2U] = (- (IData)((1U 
                                                 & (IData)(
                                                           (__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__C 
                                                            >> 0x3fU)))));
                    VL_ADD_W(3, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__Vfuncout, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__115__sh, __Vtemp_33);
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
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__C 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__gC;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__B 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__gB;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__A 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__gA;
                    VL_EXTENDS_WQ(96,64, __Vtemp_34, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__A);
                    VL_EXTENDS_WQ(96,64, __Vtemp_35, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__px);
                    VL_MULS_WWW(96, __Vtemp_36, __Vtemp_34, __Vtemp_35);
                    VL_EXTENDS_WQ(96,64, __Vtemp_37, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__B);
                    VL_EXTENDS_WQ(96,64, __Vtemp_38, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__py);
                    VL_MULS_WWW(96, __Vtemp_39, __Vtemp_37, __Vtemp_38);
                    VL_ADD_W(3, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__s, __Vtemp_36, __Vtemp_39);
                    VL_SHIFTRS_WWI(96,96,32, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__sh, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__s, 0x00000016U);
                    __Vtemp_40[0U] = (IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__C);
                    __Vtemp_40[1U] = (IData)((__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__C 
                                              >> 0x00000020U));
                    __Vtemp_40[2U] = (- (IData)((1U 
                                                 & (IData)(
                                                           (__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__C 
                                                            >> 0x3fU)))));
                    VL_ADD_W(3, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__Vfuncout, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__116__sh, __Vtemp_40);
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
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__C 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__bC;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__B 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__bB;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__A 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__bA;
                    VL_EXTENDS_WQ(96,64, __Vtemp_41, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__A);
                    VL_EXTENDS_WQ(96,64, __Vtemp_42, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__px);
                    VL_MULS_WWW(96, __Vtemp_43, __Vtemp_41, __Vtemp_42);
                    VL_EXTENDS_WQ(96,64, __Vtemp_44, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__B);
                    VL_EXTENDS_WQ(96,64, __Vtemp_45, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__py);
                    VL_MULS_WWW(96, __Vtemp_46, __Vtemp_44, __Vtemp_45);
                    VL_ADD_W(3, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__s, __Vtemp_43, __Vtemp_46);
                    VL_SHIFTRS_WWI(96,96,32, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__sh, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__s, 0x00000016U);
                    __Vtemp_47[0U] = (IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__C);
                    __Vtemp_47[1U] = (IData)((__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__C 
                                              >> 0x00000020U));
                    __Vtemp_47[2U] = (- (IData)((1U 
                                                 & (IData)(
                                                           (__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__C 
                                                            >> 0x3fU)))));
                    VL_ADD_W(3, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__Vfuncout, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__117__sh, __Vtemp_47);
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
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__C 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__zC;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__B 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__zB;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__A 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__zA;
                    VL_EXTENDS_WQ(96,64, __Vtemp_48, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__A);
                    VL_EXTENDS_WQ(96,64, __Vtemp_49, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__px);
                    VL_MULS_WWW(96, __Vtemp_50, __Vtemp_48, __Vtemp_49);
                    VL_EXTENDS_WQ(96,64, __Vtemp_51, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__B);
                    VL_EXTENDS_WQ(96,64, __Vtemp_52, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__py);
                    VL_MULS_WWW(96, __Vtemp_53, __Vtemp_51, __Vtemp_52);
                    VL_ADD_W(3, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__s, __Vtemp_50, __Vtemp_53);
                    VL_SHIFTRS_WWI(96,96,32, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__sh, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__s, 0x00000016U);
                    __Vtemp_54[0U] = (IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__C);
                    __Vtemp_54[1U] = (IData)((__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__C 
                                              >> 0x00000020U));
                    __Vtemp_54[2U] = (- (IData)((1U 
                                                 & (IData)(
                                                           (__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__C 
                                                            >> 0x3fU)))));
                    VL_ADD_W(3, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__Vfuncout, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__118__sh, __Vtemp_54);
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
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__C 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__uC;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__B 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__uB;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__A 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__uA;
                    VL_EXTENDS_WQ(96,64, __Vtemp_55, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__A);
                    VL_EXTENDS_WQ(96,64, __Vtemp_56, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__px);
                    VL_MULS_WWW(96, __Vtemp_57, __Vtemp_55, __Vtemp_56);
                    VL_EXTENDS_WQ(96,64, __Vtemp_58, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__B);
                    VL_EXTENDS_WQ(96,64, __Vtemp_59, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__py);
                    VL_MULS_WWW(96, __Vtemp_60, __Vtemp_58, __Vtemp_59);
                    VL_ADD_W(3, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__s, __Vtemp_57, __Vtemp_60);
                    VL_SHIFTRS_WWI(96,96,32, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__sh, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__s, 0x00000016U);
                    __Vtemp_61[0U] = (IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__C);
                    __Vtemp_61[1U] = (IData)((__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__C 
                                              >> 0x00000020U));
                    __Vtemp_61[2U] = (- (IData)((1U 
                                                 & (IData)(
                                                           (__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__C 
                                                            >> 0x3fU)))));
                    VL_ADD_W(3, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__Vfuncout, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__119__sh, __Vtemp_61);
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
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__C 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__vC;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__B 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__vB;
                    __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__A 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__vA;
                    VL_EXTENDS_WQ(96,64, __Vtemp_62, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__A);
                    VL_EXTENDS_WQ(96,64, __Vtemp_63, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__px);
                    VL_MULS_WWW(96, __Vtemp_64, __Vtemp_62, __Vtemp_63);
                    VL_EXTENDS_WQ(96,64, __Vtemp_65, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__B);
                    VL_EXTENDS_WQ(96,64, __Vtemp_66, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__py);
                    VL_MULS_WWW(96, __Vtemp_67, __Vtemp_65, __Vtemp_66);
                    VL_ADD_W(3, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__s, __Vtemp_64, __Vtemp_67);
                    VL_SHIFTRS_WWI(96,96,32, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__sh, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__s, 0x00000016U);
                    __Vtemp_68[0U] = (IData)(__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__C);
                    __Vtemp_68[1U] = (IData)((__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__C 
                                              >> 0x00000020U));
                    __Vtemp_68[2U] = (- (IData)((1U 
                                                 & (IData)(
                                                           (__Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__C 
                                                            >> 0x3fU)))));
                    VL_ADD_W(3, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__Vfuncout, __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__sh, __Vtemp_68);
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__v_raw[0U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__Vfuncout[0U];
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__v_raw[1U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__Vfuncout[1U];
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__v_raw[2U] 
                        = __Vfunc_ember_top__DOT__u_rtr__DOT__u_scan__DOT__peval__120__Vfuncout[2U];
                } else {
                    __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 0x0dU;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__st))) {
            __Vtemp_69[0U] = (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dx01);
            __Vtemp_69[1U] = (((IData)((0x7fffffffffffffffULL 
                                        & (- (QData)((IData)(
                                                             (1U 
                                                              & (IData)(
                                                                        (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dx01 
                                                                         >> 0x20U)))))))) 
                               << 1U) | (IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dx01 
                                                 >> 0x00000020U)));
            __Vtemp_69[2U] = (((IData)((0x7fffffffffffffffULL 
                                        & (- (QData)((IData)(
                                                             (1U 
                                                              & (IData)(
                                                                        (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dx01 
                                                                         >> 0x20U)))))))) 
                               >> 0x0000001fU) | ((IData)(
                                                          ((0x7fffffffffffffffULL 
                                                            & (- (QData)((IData)(
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dx01 
                                                                                >> 0x20U))))))) 
                                                           >> 0x00000020U)) 
                                                  << 1U));
            __Vtemp_70[0U] = (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy);
            __Vtemp_70[1U] = (IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy 
                                      >> 0x00000020U));
            __Vtemp_70[2U] = (- (IData)((1U & (IData)(
                                                      (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy 
                                                       >> 0x3fU)))));
            __Vtemp_71[0U] = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__y0;
            __Vtemp_71[1U] = (IData)((- (QData)((IData)(
                                                        (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__y0 
                                                         >> 0x1fU)))));
            __Vtemp_71[2U] = (IData)(((- (QData)((IData)(
                                                         (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__y0 
                                                          >> 0x1fU)))) 
                                      >> 0x00000020U));
            VL_SUB_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
            VL_MUL_W(3, __Vtemp_73, __Vtemp_69, __Vtemp_72);
            __Vtemp_74[0U] = (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dy01);
            __Vtemp_74[1U] = (((IData)((0x7fffffffffffffffULL 
                                        & (- (QData)((IData)(
                                                             (1U 
                                                              & (IData)(
                                                                        (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dy01 
                                                                         >> 0x20U)))))))) 
                               << 1U) | (IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dy01 
                                                 >> 0x00000020U)));
            __Vtemp_74[2U] = (((IData)((0x7fffffffffffffffULL 
                                        & (- (QData)((IData)(
                                                             (1U 
                                                              & (IData)(
                                                                        (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dy01 
                                                                         >> 0x20U)))))))) 
                               >> 0x0000001fU) | ((IData)(
                                                          ((0x7fffffffffffffffULL 
                                                            & (- (QData)((IData)(
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dy01 
                                                                                >> 0x20U))))))) 
                                                           >> 0x00000020U)) 
                                                  << 1U));
            __Vtemp_75[0U] = (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx);
            __Vtemp_75[1U] = (IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx 
                                      >> 0x00000020U));
            __Vtemp_75[2U] = (- (IData)((1U & (IData)(
                                                      (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx 
                                                       >> 0x3fU)))));
            __Vtemp_76[0U] = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__x0;
            __Vtemp_76[1U] = (IData)((- (QData)((IData)(
                                                        (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__x0 
                                                         >> 0x1fU)))));
            __Vtemp_76[2U] = (IData)(((- (QData)((IData)(
                                                         (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__x0 
                                                          >> 0x1fU)))) 
                                      >> 0x00000020U));
            VL_SUB_W(3, __Vtemp_77, __Vtemp_75, __Vtemp_76);
            VL_MUL_W(3, __Vtemp_78, __Vtemp_74, __Vtemp_77);
            VL_SUB_W(3, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__e01, __Vtemp_73, __Vtemp_78);
            if (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__t_ztest) {
                vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_req = 1U;
                vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_addr 
                    = ((IData)(0x00026800U) + vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__pix_word_off);
            }
            __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 2U;
            __Vtemp_79[0U] = (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dx12);
            __Vtemp_79[1U] = (((IData)((0x7fffffffffffffffULL 
                                        & (- (QData)((IData)(
                                                             (1U 
                                                              & (IData)(
                                                                        (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dx12 
                                                                         >> 0x20U)))))))) 
                               << 1U) | (IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dx12 
                                                 >> 0x00000020U)));
            __Vtemp_79[2U] = (((IData)((0x7fffffffffffffffULL 
                                        & (- (QData)((IData)(
                                                             (1U 
                                                              & (IData)(
                                                                        (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dx12 
                                                                         >> 0x20U)))))))) 
                               >> 0x0000001fU) | ((IData)(
                                                          ((0x7fffffffffffffffULL 
                                                            & (- (QData)((IData)(
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dx12 
                                                                                >> 0x20U))))))) 
                                                           >> 0x00000020U)) 
                                                  << 1U));
            __Vtemp_80[0U] = (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy);
            __Vtemp_80[1U] = (IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy 
                                      >> 0x00000020U));
            __Vtemp_80[2U] = (- (IData)((1U & (IData)(
                                                      (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy 
                                                       >> 0x3fU)))));
            __Vtemp_81[0U] = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__y1;
            __Vtemp_81[1U] = (IData)((- (QData)((IData)(
                                                        (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__y1 
                                                         >> 0x1fU)))));
            __Vtemp_81[2U] = (IData)(((- (QData)((IData)(
                                                         (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__y1 
                                                          >> 0x1fU)))) 
                                      >> 0x00000020U));
            VL_SUB_W(3, __Vtemp_82, __Vtemp_80, __Vtemp_81);
            VL_MUL_W(3, __Vtemp_83, __Vtemp_79, __Vtemp_82);
            __Vtemp_84[0U] = (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dy12);
            __Vtemp_84[1U] = (((IData)((0x7fffffffffffffffULL 
                                        & (- (QData)((IData)(
                                                             (1U 
                                                              & (IData)(
                                                                        (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dy12 
                                                                         >> 0x20U)))))))) 
                               << 1U) | (IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dy12 
                                                 >> 0x00000020U)));
            __Vtemp_84[2U] = (((IData)((0x7fffffffffffffffULL 
                                        & (- (QData)((IData)(
                                                             (1U 
                                                              & (IData)(
                                                                        (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dy12 
                                                                         >> 0x20U)))))))) 
                               >> 0x0000001fU) | ((IData)(
                                                          ((0x7fffffffffffffffULL 
                                                            & (- (QData)((IData)(
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dy12 
                                                                                >> 0x20U))))))) 
                                                           >> 0x00000020U)) 
                                                  << 1U));
            __Vtemp_85[0U] = (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx);
            __Vtemp_85[1U] = (IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx 
                                      >> 0x00000020U));
            __Vtemp_85[2U] = (- (IData)((1U & (IData)(
                                                      (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx 
                                                       >> 0x3fU)))));
            __Vtemp_86[0U] = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__x1;
            __Vtemp_86[1U] = (IData)((- (QData)((IData)(
                                                        (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__x1 
                                                         >> 0x1fU)))));
            __Vtemp_86[2U] = (IData)(((- (QData)((IData)(
                                                         (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__x1 
                                                          >> 0x1fU)))) 
                                      >> 0x00000020U));
            VL_SUB_W(3, __Vtemp_87, __Vtemp_85, __Vtemp_86);
            VL_MUL_W(3, __Vtemp_88, __Vtemp_84, __Vtemp_87);
            VL_SUB_W(3, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__e12, __Vtemp_83, __Vtemp_88);
            __Vtemp_89[0U] = (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dx20);
            __Vtemp_89[1U] = (((IData)((0x7fffffffffffffffULL 
                                        & (- (QData)((IData)(
                                                             (1U 
                                                              & (IData)(
                                                                        (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dx20 
                                                                         >> 0x20U)))))))) 
                               << 1U) | (IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dx20 
                                                 >> 0x00000020U)));
            __Vtemp_89[2U] = (((IData)((0x7fffffffffffffffULL 
                                        & (- (QData)((IData)(
                                                             (1U 
                                                              & (IData)(
                                                                        (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dx20 
                                                                         >> 0x20U)))))))) 
                               >> 0x0000001fU) | ((IData)(
                                                          ((0x7fffffffffffffffULL 
                                                            & (- (QData)((IData)(
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dx20 
                                                                                >> 0x20U))))))) 
                                                           >> 0x00000020U)) 
                                                  << 1U));
            __Vtemp_90[0U] = (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy);
            __Vtemp_90[1U] = (IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy 
                                      >> 0x00000020U));
            __Vtemp_90[2U] = (- (IData)((1U & (IData)(
                                                      (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy 
                                                       >> 0x3fU)))));
            __Vtemp_91[0U] = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__y2;
            __Vtemp_91[1U] = (IData)((- (QData)((IData)(
                                                        (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__y2 
                                                         >> 0x1fU)))));
            __Vtemp_91[2U] = (IData)(((- (QData)((IData)(
                                                         (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__y2 
                                                          >> 0x1fU)))) 
                                      >> 0x00000020U));
            VL_SUB_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
            VL_MUL_W(3, __Vtemp_93, __Vtemp_89, __Vtemp_92);
            __Vtemp_94[0U] = (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dy20);
            __Vtemp_94[1U] = (((IData)((0x7fffffffffffffffULL 
                                        & (- (QData)((IData)(
                                                             (1U 
                                                              & (IData)(
                                                                        (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dy20 
                                                                         >> 0x20U)))))))) 
                               << 1U) | (IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dy20 
                                                 >> 0x00000020U)));
            __Vtemp_94[2U] = (((IData)((0x7fffffffffffffffULL 
                                        & (- (QData)((IData)(
                                                             (1U 
                                                              & (IData)(
                                                                        (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dy20 
                                                                         >> 0x20U)))))))) 
                               >> 0x0000001fU) | ((IData)(
                                                          ((0x7fffffffffffffffULL 
                                                            & (- (QData)((IData)(
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dy20 
                                                                                >> 0x20U))))))) 
                                                           >> 0x00000020U)) 
                                                  << 1U));
            __Vtemp_95[0U] = (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx);
            __Vtemp_95[1U] = (IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx 
                                      >> 0x00000020U));
            __Vtemp_95[2U] = (- (IData)((1U & (IData)(
                                                      (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx 
                                                       >> 0x3fU)))));
            __Vtemp_96[0U] = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__x2;
            __Vtemp_96[1U] = (IData)((- (QData)((IData)(
                                                        (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__x2 
                                                         >> 0x1fU)))));
            __Vtemp_96[2U] = (IData)(((- (QData)((IData)(
                                                         (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__x2 
                                                          >> 0x1fU)))) 
                                      >> 0x00000020U));
            VL_SUB_W(3, __Vtemp_97, __Vtemp_95, __Vtemp_96);
            VL_MUL_W(3, __Vtemp_98, __Vtemp_94, __Vtemp_97);
            VL_SUB_W(3, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__e20, __Vtemp_93, __Vtemp_98);
        } else if (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__start) {
            vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__iy 
                = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__y_lo_i;
            __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy 
                = (0x0000000000200000ULL + VL_SHIFTL_QQI(64,64,32, 
                                                         (((- (QData)((IData)(
                                                                              (1U 
                                                                               & ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__y_lo_i) 
                                                                                >> 0x0fU))))) 
                                                           << 0x00000010U) 
                                                          | (QData)((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__y_lo_i))), 0x00000016U));
            __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__ix 
                = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__x_lo_i;
            __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx 
                = (0x0000000000200000ULL + VL_SHIFTL_QQI(64,64,32, 
                                                         (((- (QData)((IData)(
                                                                              (1U 
                                                                               & ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__x_lo_i) 
                                                                                >> 0x0fU))))) 
                                                           << 0x00000010U) 
                                                          | (QData)((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__x_lo_i))), 0x00000016U));
            __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 1U;
        }
    } else {
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__iy = 0U;
        __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy = 0ULL;
        __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__done = 0U;
        __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__ix = 0U;
        __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx = 0ULL;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_req = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_we = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_addr = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_wdata = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_be = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa2_req = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa2_addr = 0U;
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
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy 
        = __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__cy;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx 
        = __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__cx;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__ix 
        = __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__ix;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__st 
        = __Vdly__ember_top__DOT__u_rtr__DOT__u_scan__DOT__st;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__fpa2_req 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa2_req;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__fpa2_addr 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa2_addr;
    VL_SHIFTRS_WWI(96,96,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__u8w, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__u_fin, 0x00000016U);
    VL_SHIFTRS_WWI(96,96,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__v8w, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__v_fin, 0x00000016U);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_we 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_we;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_be 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_be;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_wdata 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_wdata;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_req 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_req;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_fpa_addr 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_addr;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__pix_xy 
        = (((IData)(0x00000140U) * (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__iy)) 
           + (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__ix));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dith_up 
        = (1U & ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__ix) 
                 ^ (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__iy)));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__busy 
        = (0U != (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__st));
    vlSelfRef.ember_top__DOT__fpa2_req = vlSelfRef.ember_top__DOT__u_rtr__DOT__fpa2_req;
    vlSelfRef.ember_top__DOT__fpa2_addr = vlSelfRef.ember_top__DOT__u_rtr__DOT__fpa2_addr;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__tex_addr 
        = ((IData)(0x0004c000U) + ((0x0000ff00U & (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__v8w[0U] 
                                                   << 8U)) 
                                   + (0x000000ffU & vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__u8w[0U])));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__pix_off 
        = VL_SHIFTL_III(32,32,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__pix_xy, 1U);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_busy 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__busy;
    vlSelfRef.ember_top__DOT__u_vram__DOT__fpa2_req 
        = vlSelfRef.ember_top__DOT__fpa2_req;
    vlSelfRef.ember_top__DOT__u_vram__DOT__fpa2_addr 
        = vlSelfRef.ember_top__DOT__fpa2_addr;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__odd_x 
        = (1U & (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__pix_off 
                 >> 1U));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__pix_word_off 
        = (0xfffffffcU & vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__pix_off);
    vlSelfRef.ember_top__DOT__u_vram__DOT__fpa2_widx 
        = (0x0001ffffU & ((vlSelfRef.ember_top__DOT__u_vram__DOT__fpa2_addr 
                           - (IData)(0x00001000U)) 
                          >> 2U));
}

void Vtop___024root___nba_sequent__TOP__12(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__12\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*7:0*/ __Vtask_ember_top__DOT__u_core__DOT__init_block__7__b;
    __Vtask_ember_top__DOT__u_core__DOT__init_block__7__b = 0;
    CData/*0:0*/ __Vdly__ember_top__DOT__u_core__DOT__ix_pend;
    __Vdly__ember_top__DOT__u_core__DOT__ix_pend = 0;
    CData/*0:0*/ __Vdly__ember_top__DOT__u_core__DOT__flush_req;
    __Vdly__ember_top__DOT__u_core__DOT__flush_req = 0;
    CData/*0:0*/ __Vdly__ember_top__DOT__u_core__DOT__cx_pend;
    __Vdly__ember_top__DOT__u_core__DOT__cx_pend = 0;
    CData/*0:0*/ __Vdly__ember_top__DOT__u_core__DOT__dr_valid;
    __Vdly__ember_top__DOT__u_core__DOT__dr_valid = 0;
    CData/*1:0*/ __Vdly__ember_top__DOT__u_core__DOT__dr_tid;
    __Vdly__ember_top__DOT__u_core__DOT__dr_tid = 0;
    CData/*3:0*/ __Vdly__ember_top__DOT__u_core__DOT__dr_rd;
    __Vdly__ember_top__DOT__u_core__DOT__dr_rd = 0;
    IData/*31:0*/ __Vdly__ember_top__DOT__u_core__DOT__dr_word;
    __Vdly__ember_top__DOT__u_core__DOT__dr_word = 0;
    CData/*3:0*/ __Vdly__ember_top__DOT__u_core__DOT__waitv;
    __Vdly__ember_top__DOT__u_core__DOT__waitv = 0;
    CData/*0:0*/ __Vdly__ember_top__DOT__u_core__DOT__fp_pend;
    __Vdly__ember_top__DOT__u_core__DOT__fp_pend = 0;
    CData/*1:0*/ __Vdly__ember_top__DOT__u_core__DOT__st;
    __Vdly__ember_top__DOT__u_core__DOT__st = 0;
    CData/*7:0*/ __Vdly__ember_top__DOT__u_core__DOT__blk;
    __Vdly__ember_top__DOT__u_core__DOT__blk = 0;
    CData/*3:0*/ __Vdly__ember_top__DOT__u_core__DOT__barv;
    __Vdly__ember_top__DOT__u_core__DOT__barv = 0;
    CData/*1:0*/ __Vdly__ember_top__DOT__u_core__DOT__bar_count;
    __Vdly__ember_top__DOT__u_core__DOT__bar_count = 0;
    IData/*19:0*/ __Vdly__ember_top__DOT__u_core__DOT__budget;
    __Vdly__ember_top__DOT__u_core__DOT__budget = 0;
    CData/*1:0*/ __Vdly__ember_top__DOT__u_core__DOT__flush_tid;
    __Vdly__ember_top__DOT__u_core__DOT__flush_tid = 0;
    CData/*0:0*/ __Vdly__ember_top__DOT__u_core__DOT__ld_pend;
    __Vdly__ember_top__DOT__u_core__DOT__ld_pend = 0;
    IData/*31:0*/ __Vdly__ember_top__DOT__u_core__DOT__ld_addr_q;
    __Vdly__ember_top__DOT__u_core__DOT__ld_addr_q = 0;
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
    CData/*1:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__T__v8;
    __VdlyDim0__ember_top__DOT__u_core__DOT__T__v8 = 0;
    CData/*1:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__T__v9;
    __VdlyDim0__ember_top__DOT__u_core__DOT__T__v9 = 0;
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
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_core__DOT__smem__v0;
    __VdlySet__ember_top__DOT__u_core__DOT__smem__v0 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__smem__v1;
    __VdlyVal__ember_top__DOT__u_core__DOT__smem__v1 = 0;
    SData/*9:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__smem__v1;
    __VdlyDim0__ember_top__DOT__u_core__DOT__smem__v1 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_core__DOT__smem__v1;
    __VdlySet__ember_top__DOT__u_core__DOT__smem__v1 = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__smem__v2;
    __VdlyVal__ember_top__DOT__u_core__DOT__smem__v2 = 0;
    SData/*9:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__smem__v2;
    __VdlyDim0__ember_top__DOT__u_core__DOT__smem__v2 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_core__DOT__smem__v2;
    __VdlySet__ember_top__DOT__u_core__DOT__smem__v2 = 0;
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
    CData/*2:0*/ __VdlyVal__ember_top__DOT__u_core__DOT__T__v10;
    __VdlyVal__ember_top__DOT__u_core__DOT__T__v10 = 0;
    CData/*1:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__T__v10;
    __VdlyDim0__ember_top__DOT__u_core__DOT__T__v10 = 0;
    CData/*3:0*/ __VdlyElem__ember_top__DOT__u_core__DOT__T__v10;
    __VdlyElem__ember_top__DOT__u_core__DOT__T__v10 = 0;
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
    CData/*1:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__T__v19;
    __VdlyDim0__ember_top__DOT__u_core__DOT__T__v19 = 0;
    CData/*1:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v14;
    __VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v14 = 0;
    CData/*1:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__ibuf_w__v1;
    __VdlyDim0__ember_top__DOT__u_core__DOT__ibuf_w__v1 = 0;
    CData/*3:0*/ __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v44;
    __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v44 = 0;
    CData/*1:0*/ __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v44;
    __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v44 = 0;
    // Body
    __Vdly__ember_top__DOT__u_core__DOT__ix_pend = vlSelfRef.ember_top__DOT__u_core__DOT__ix_pend;
    __Vdly__ember_top__DOT__u_core__DOT__flush_req 
        = vlSelfRef.ember_top__DOT__u_core__DOT__flush_req;
    __Vdly__ember_top__DOT__u_core__DOT__cx_pend = vlSelfRef.ember_top__DOT__u_core__DOT__cx_pend;
    __Vdly__ember_top__DOT__u_core__DOT__dr_valid = vlSelfRef.ember_top__DOT__u_core__DOT__dr_valid;
    __Vdly__ember_top__DOT__u_core__DOT__dr_tid = vlSelfRef.ember_top__DOT__u_core__DOT__dr_tid;
    __Vdly__ember_top__DOT__u_core__DOT__dr_rd = vlSelfRef.ember_top__DOT__u_core__DOT__dr_rd;
    __Vdly__ember_top__DOT__u_core__DOT__dr_word = vlSelfRef.ember_top__DOT__u_core__DOT__dr_word;
    __Vdly__ember_top__DOT__u_core__DOT__fp_pend = vlSelfRef.ember_top__DOT__u_core__DOT__fp_pend;
    __Vdly__ember_top__DOT__u_core__DOT__blk = vlSelfRef.ember_top__DOT__u_core__DOT__blk;
    __Vdly__ember_top__DOT__u_core__DOT__bar_count 
        = vlSelfRef.ember_top__DOT__u_core__DOT__bar_count;
    __Vdly__ember_top__DOT__u_core__DOT__budget = vlSelfRef.ember_top__DOT__u_core__DOT__budget;
    __Vdly__ember_top__DOT__u_core__DOT__flush_tid 
        = vlSelfRef.ember_top__DOT__u_core__DOT__flush_tid;
    __Vdly__ember_top__DOT__u_core__DOT__ld_pend = vlSelfRef.ember_top__DOT__u_core__DOT__ld_pend;
    __Vdly__ember_top__DOT__u_core__DOT__ld_addr_q 
        = vlSelfRef.ember_top__DOT__u_core__DOT__ld_addr_q;
    __VdlySet__ember_top__DOT__u_core__DOT__smem__v0 = 0U;
    __VdlySet__ember_top__DOT__u_core__DOT__smem__v1 = 0U;
    __VdlySet__ember_top__DOT__u_core__DOT__smem__v2 = 0U;
    __Vdly__ember_top__DOT__u_core__DOT__waitv = vlSelfRef.ember_top__DOT__u_core__DOT__waitv;
    __Vdly__ember_top__DOT__u_core__DOT__barv = vlSelfRef.ember_top__DOT__u_core__DOT__barv;
    __Vdly__ember_top__DOT__u_core__DOT__st = vlSelfRef.ember_top__DOT__u_core__DOT__st;
    if ((1U & (~ (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__rst_n)))) {
        vlSelfRef.ember_top__DOT__u_core__DOT__f_a3 = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__f_b2 = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__f_b3 = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__f_a1 = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__f_b1 = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__f_a2 = 0U;
    }
    if (vlSelfRef.ember_top__DOT__u_core__DOT__rst_n) {
        vlSelfRef.ember_top__DOT__u_core__DOT__cxa_we = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__cxa_req = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__ixa_req = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__f_go = 0U;
        if (((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ix_pend) 
             & (~ (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ix_req_cyc)))) {
            __Vdly__ember_top__DOT__u_core__DOT__ix_pend = 0U;
            if (((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__flush_req) 
                 & ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ix_tid) 
                    == (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__flush_tid)))) {
                __Vdly__ember_top__DOT__u_core__DOT__flush_req = 0U;
            } else {
                vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_v 
                    = ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_v) 
                       | (0x0fU & ((IData)(1U) << (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ix_tid))));
                __VdlyVal__ember_top__DOT__u_core__DOT__ibuf_w__v0 
                    = vlSelfRef.ember_top__DOT__u_core__DOT__ixa_rdata;
                __VdlyDim0__ember_top__DOT__u_core__DOT__ibuf_w__v0 
                    = vlSelfRef.ember_top__DOT__u_core__DOT__ix_tid;
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__ibuf_w.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__ibuf_w__v0, (IData)(__VdlyDim0__ember_top__DOT__u_core__DOT__ibuf_w__v0));
            }
        } else if (vlSelfRef.ember_top__DOT__u_core__DOT__flush_req) {
            __Vdly__ember_top__DOT__u_core__DOT__flush_req = 0U;
        }
        if (vlSelfRef.ember_top__DOT__u_core__DOT__ix_req_cyc) {
            vlSelfRef.ember_top__DOT__u_core__DOT__ix_req_cyc = 0U;
        }
        if (((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__cx_pend) 
             & (~ (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__cx_req_cyc)))) {
            __Vdly__ember_top__DOT__u_core__DOT__cx_pend = 0U;
            __Vdly__ember_top__DOT__u_core__DOT__dr_valid = 1U;
            __Vdly__ember_top__DOT__u_core__DOT__dr_tid 
                = vlSelfRef.ember_top__DOT__u_core__DOT__ld_tid_q;
            __Vdly__ember_top__DOT__u_core__DOT__dr_rd 
                = vlSelfRef.ember_top__DOT__u_core__DOT__ld_rd_q;
            __Vdly__ember_top__DOT__u_core__DOT__dr_word 
                = vlSelfRef.ember_top__DOT__u_core__DOT__cxa_rdata;
        }
        if (vlSelfRef.ember_top__DOT__u_core__DOT__cx_req_cyc) {
            vlSelfRef.ember_top__DOT__u_core__DOT__cx_req_cyc = 0U;
        }
        if (vlSelfRef.ember_top__DOT__u_core__DOT__dr_valid) {
            __Vdly__ember_top__DOT__u_core__DOT__dr_valid = 0U;
            __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v0 
                = vlSelfRef.ember_top__DOT__u_core__DOT__dr_word;
            __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v0 
                = vlSelfRef.ember_top__DOT__u_core__DOT__dr_rd;
            __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v0 
                = vlSelfRef.ember_top__DOT__u_core__DOT__dr_tid;
            vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__gpr__v0, (IData)(__VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v0), __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v0);
            __Vdly__ember_top__DOT__u_core__DOT__waitv 
                = ((~ ((IData)(1U) << (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__dr_tid))) 
                   & (IData)(__Vdly__ember_top__DOT__u_core__DOT__waitv));
        }
        if (((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__fp_pend) 
             & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__f_done))) {
            __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v1 
                = vlSelfRef.ember_top__DOT__u_core__DOT__f_y0;
            __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v1 
                = vlSelfRef.ember_top__DOT__u_core__DOT__fp_rd;
            __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v1 
                = vlSelfRef.ember_top__DOT__u_core__DOT__fp_tid;
            vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__gpr__v1, (IData)(__VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v1), __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v1);
            __Vdly__ember_top__DOT__u_core__DOT__waitv 
                = ((~ ((IData)(1U) << (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__fp_tid))) 
                   & (IData)(__Vdly__ember_top__DOT__u_core__DOT__waitv));
            __Vdly__ember_top__DOT__u_core__DOT__fp_pend = 0U;
        }
        if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__st))) {
            if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__st))) {
                vlSelfRef.ember_top__DOT__u_core__DOT__running = 0U;
                __Vdly__ember_top__DOT__u_core__DOT__st = 0U;
            } else if (((0x000000ffU & ((IData)(1U) 
                                        + (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__blk))) 
                        >= (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__nblk_q))) {
                vlSelfRef.ember_top__DOT__u_core__DOT__running = 0U;
                __Vdly__ember_top__DOT__u_core__DOT__st = 3U;
            } else {
                __Vdly__ember_top__DOT__u_core__DOT__blk 
                    = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__blk)));
                __Vtask_ember_top__DOT__u_core__DOT__init_block__7__b 
                    = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__blk)));
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__T.enqueue(0U, 8U, 0U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__fpc.enqueue(0U, 0U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(0x0005b000U, 0U, 0x0cU);
                vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_v = 0U;
                __Vdly__ember_top__DOT__u_core__DOT__waitv = 0U;
                __Vdly__ember_top__DOT__u_core__DOT__barv = 0U;
                __Vdly__ember_top__DOT__u_core__DOT__bar_count = 0U;
                __Vdly__ember_top__DOT__u_core__DOT__budget = 0U;
                __Vdly__ember_top__DOT__u_core__DOT__st = 1U;
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__T.enqueue(0U, 7U, 0U);
                __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v3 
                    = __Vtask_ember_top__DOT__u_core__DOT__init_block__7__b;
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__gpr__v3, 0U, 0x0dU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__fpc.enqueue(0U, 1U);
                __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v4 
                    = vlSelfRef.ember_top__DOT__u_core__DOT__nblk_q;
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__gpr__v4, 0U, 0x0eU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__T.enqueue(0U, 8U, 1U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__fpc.enqueue(0U, 2U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(0U, 0U, 0x0fU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__T.enqueue(0U, 7U, 1U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__fpc.enqueue(0U, 3U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(0x0005b000U, 1U, 0x0cU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__T.enqueue(0U, 8U, 2U);
                __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v7 
                    = __Vtask_ember_top__DOT__u_core__DOT__init_block__7__b;
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__gpr__v7, 1U, 0x0dU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__T.enqueue(0U, 7U, 2U);
                __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v8 
                    = vlSelfRef.ember_top__DOT__u_core__DOT__nblk_q;
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__gpr__v8, 1U, 0x0eU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__T.enqueue(0U, 8U, 3U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(1U, 1U, 0x0fU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__T.enqueue(0U, 7U, 3U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(0x0005b000U, 2U, 0x0cU);
                __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v11 
                    = __Vtask_ember_top__DOT__u_core__DOT__init_block__7__b;
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__gpr__v11, 2U, 0x0dU);
                __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v12 
                    = vlSelfRef.ember_top__DOT__u_core__DOT__nblk_q;
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__gpr__v12, 2U, 0x0eU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(2U, 2U, 0x0fU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(0x0005b000U, 3U, 0x0cU);
                __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v15 
                    = __Vtask_ember_top__DOT__u_core__DOT__init_block__7__b;
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__gpr__v15, 3U, 0x0dU);
                __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v16 
                    = vlSelfRef.ember_top__DOT__u_core__DOT__nblk_q;
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__gpr__v16, 3U, 0x0eU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(3U, 3U, 0x0fU);
            }
        } else if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__st))) {
            __Vdly__ember_top__DOT__u_core__DOT__budget 
                = (0x000fffffU & ((IData)(1U) + vlSelfRef.ember_top__DOT__u_core__DOT__budget));
            if ((0x000fffffU == vlSelfRef.ember_top__DOT__u_core__DOT__budget)) {
                vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk6__DOT__t = 0U;
                while ((4U > vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk6__DOT__t)) {
                    __VdlyDim0__ember_top__DOT__u_core__DOT__T__v8 
                        = (3U & vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk6__DOT__t);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__T.enqueue(8U, 8U, (IData)(__VdlyDim0__ember_top__DOT__u_core__DOT__T__v8));
                    vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk6__DOT__t 
                        = ((IData)(1U) + vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk6__DOT__t);
                }
                __Vdly__ember_top__DOT__u_core__DOT__st = 2U;
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
                                                        __VdlyDim0__ember_top__DOT__u_core__DOT__T__v9 
                                                            = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__T.enqueue(8U, 8U, (IData)(__VdlyDim0__ember_top__DOT__u_core__DOT__T__v9));
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
                                            __Vdly__ember_top__DOT__u_core__DOT__fp_pend = 1U;
                                            vlSelfRef.ember_top__DOT__u_core__DOT__fp_tid 
                                                = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                            vlSelfRef.ember_top__DOT__u_core__DOT__fp_rd 
                                                = vlSelfRef.ember_top__DOT__u_core__DOT__i_rd;
                                            __Vdly__ember_top__DOT__u_core__DOT__waitv 
                                                = ((IData)(__Vdly__ember_top__DOT__u_core__DOT__waitv) 
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
                                                __Vdly__ember_top__DOT__u_core__DOT__barv 
                                                    = 
                                                    ((IData)(__Vdly__ember_top__DOT__u_core__DOT__barv) 
                                                     | (0x0fU 
                                                        & ((IData)(1U) 
                                                           << (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid))));
                                                __Vdly__ember_top__DOT__u_core__DOT__bar_count 
                                                    = 
                                                    (3U 
                                                     & ((IData)(1U) 
                                                        + (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__bar_count)));
                                                if (
                                                    (3U 
                                                     == (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__bar_count))) {
                                                    __Vdly__ember_top__DOT__u_core__DOT__barv = 0U;
                                                    __Vdly__ember_top__DOT__u_core__DOT__bar_count = 0U;
                                                }
                                            } else {
                                                __Vdly__ember_top__DOT__u_core__DOT__flush_req = 1U;
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
                                                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__gpr__v18, (IData)(__VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v18), __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v18);
                                                __Vdly__ember_top__DOT__u_core__DOT__flush_tid 
                                                    = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                                __VdlyVal__ember_top__DOT__u_core__DOT__fpc__v4 
                                                    = 
                                                    (0x000000ffU 
                                                     & (vlSelfRef.ember_top__DOT__u_core__DOT__fpc
                                                        [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid] 
                                                        + (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_sx11)));
                                                __VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v4 
                                                    = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__fpc.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__fpc__v4, (IData)(__VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v4));
                                            }
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                                        if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                                            __Vdly__ember_top__DOT__u_core__DOT__flush_req = 1U;
                                            __VdlyVal__ember_top__DOT__u_core__DOT__fpc__v5 
                                                = (0x000000ffU 
                                                   & vlSelfRef.ember_top__DOT__u_core__DOT__gpr
                                                   [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid][15U]);
                                            __VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v5 
                                                = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                            vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__fpc.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__fpc__v5, (IData)(__VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v5));
                                            __Vdly__ember_top__DOT__u_core__DOT__flush_tid 
                                                = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                        } else {
                                            __Vdly__ember_top__DOT__u_core__DOT__flush_req = 1U;
                                            __VdlyVal__ember_top__DOT__u_core__DOT__fpc__v6 
                                                = (0x000000ffU 
                                                   & vlSelfRef.ember_top__DOT__u_core__DOT__gpr
                                                   [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid]
                                                   [vlSelfRef.ember_top__DOT__u_core__DOT__i_ra]);
                                            __VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v6 
                                                = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                            vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__fpc.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__fpc__v6, (IData)(__VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v6));
                                            __Vdly__ember_top__DOT__u_core__DOT__flush_tid 
                                                = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                                        __Vdly__ember_top__DOT__u_core__DOT__flush_req = 1U;
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
                                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__gpr__v19, (IData)(__VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v19), __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v19);
                                        __Vdly__ember_top__DOT__u_core__DOT__flush_tid 
                                            = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                        __VdlyVal__ember_top__DOT__u_core__DOT__fpc__v7 
                                            = (0x000000ffU 
                                               & (vlSelfRef.ember_top__DOT__u_core__DOT__fpc
                                                  [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid] 
                                                  + (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_sx11)));
                                        __VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v7 
                                            = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__fpc.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__fpc__v7, (IData)(__VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v7));
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
                                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__fpc.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__fpc__v8, (IData)(__VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v8));
                                        __Vdly__ember_top__DOT__u_core__DOT__flush_req = 1U;
                                        __Vdly__ember_top__DOT__u_core__DOT__flush_tid 
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
                                                __VdlySet__ember_top__DOT__u_core__DOT__smem__v0 = 1U;
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
                                            __VdlySet__ember_top__DOT__u_core__DOT__smem__v1 = 1U;
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
                                        __VdlySet__ember_top__DOT__u_core__DOT__smem__v2 = 1U;
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
                                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__gpr__v20, (IData)(__VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v20), __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v20);
                                    }
                                } else if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                                    vlSelfRef.ember_top__DOT__u_core__DOT__cxa_we = 1U;
                                    vlSelfRef.ember_top__DOT__u_core__DOT__cxa_be = 0x0fU;
                                    vlSelfRef.ember_top__DOT__u_core__DOT__cxa_addr 
                                        = ((IData)(0x00001000U) 
                                           + (vlSelfRef.ember_top__DOT__u_core__DOT__rav 
                                              + vlSelfRef.ember_top__DOT__u_core__DOT__i_sx12));
                                    vlSelfRef.ember_top__DOT__u_core__DOT__cxa_wdata 
                                        = vlSelfRef.ember_top__DOT__u_core__DOT__gpr
                                        [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid]
                                        [vlSelfRef.ember_top__DOT__u_core__DOT__i_rd];
                                } else {
                                    __Vdly__ember_top__DOT__u_core__DOT__ld_pend = 1U;
                                    __Vdly__ember_top__DOT__u_core__DOT__ld_addr_q 
                                        = ((IData)(0x00001000U) 
                                           + (vlSelfRef.ember_top__DOT__u_core__DOT__rav 
                                              + vlSelfRef.ember_top__DOT__u_core__DOT__i_sx12));
                                    vlSelfRef.ember_top__DOT__u_core__DOT__ld_tid_q 
                                        = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                    vlSelfRef.ember_top__DOT__u_core__DOT__ld_rd_q 
                                        = vlSelfRef.ember_top__DOT__u_core__DOT__i_rd;
                                    __Vdly__ember_top__DOT__u_core__DOT__waitv 
                                        = ((IData)(__Vdly__ember_top__DOT__u_core__DOT__waitv) 
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
                                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__gpr__v21, (IData)(__VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v21), __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v21);
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
                                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__gpr__v22, (IData)(__VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v22), __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v22);
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
                                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__gpr__v23, (IData)(__VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v23), __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v23);
                                } else {
                                    vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk7__DOT__d 
                                        = (vlSelfRef.ember_top__DOT__u_core__DOT__rav 
                                           - vlSelfRef.ember_top__DOT__u_core__DOT__rbv);
                                    __VdlyVal__ember_top__DOT__u_core__DOT__T__v10 
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
                                    __VdlyDim0__ember_top__DOT__u_core__DOT__T__v10 
                                        = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                                    __VdlyElem__ember_top__DOT__u_core__DOT__T__v10 = 0U;
                                    __VdlyElem__ember_top__DOT__u_core__DOT__T__v10 
                                        = ((8U & (IData)(__VdlyElem__ember_top__DOT__u_core__DOT__T__v10)) 
                                           | (IData)(__VdlyVal__ember_top__DOT__u_core__DOT__T__v10));
                                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__T.enqueue(__VdlyElem__ember_top__DOT__u_core__DOT__T__v10, 7U, (IData)(__VdlyDim0__ember_top__DOT__u_core__DOT__T__v10));
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
                                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__gpr__v24, (IData)(__VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v24), __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v24);
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
                            vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__gpr__v25, (IData)(__VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v25), __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v25);
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
                            vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__gpr__v26, (IData)(__VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v26), __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v26);
                        } else if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_op))) {
                            __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v27 
                                = (vlSelfRef.ember_top__DOT__u_core__DOT__rav 
                                   + vlSelfRef.ember_top__DOT__u_core__DOT__rbv);
                            __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v27 
                                = vlSelfRef.ember_top__DOT__u_core__DOT__i_rd;
                            __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v27 
                                = vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid;
                            vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__gpr__v27, (IData)(__VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v27), __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v27);
                        }
                    }
                }
                if (((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ld_pend) 
                     & (~ (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__cx_pend)))) {
                    __Vdly__ember_top__DOT__u_core__DOT__ld_pend = 0U;
                    __Vdly__ember_top__DOT__u_core__DOT__cx_pend = 1U;
                    vlSelfRef.ember_top__DOT__u_core__DOT__cx_req_cyc = 1U;
                    vlSelfRef.ember_top__DOT__u_core__DOT__cxa_req = 1U;
                    vlSelfRef.ember_top__DOT__u_core__DOT__cxa_addr 
                        = vlSelfRef.ember_top__DOT__u_core__DOT__ld_addr_q;
                }
                if ((((~ (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ix_pend)) 
                      & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__pick_en)) 
                     & (~ ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__flush_req) 
                           & ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__flush_tid) 
                              == (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__pick_tid)))))) {
                    __Vdly__ember_top__DOT__u_core__DOT__ix_pend = 1U;
                    vlSelfRef.ember_top__DOT__u_core__DOT__ix_req_cyc = 1U;
                    vlSelfRef.ember_top__DOT__u_core__DOT__ix_tid 
                        = vlSelfRef.ember_top__DOT__u_core__DOT__pick_tid;
                    vlSelfRef.ember_top__DOT__u_core__DOT__ixa_req = 1U;
                    vlSelfRef.ember_top__DOT__u_core__DOT__ixa_addr 
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
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__fpc.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__fpc__v9, (IData)(__VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v9));
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
                    __Vdly__ember_top__DOT__u_core__DOT__st = 2U;
                }
            }
        } else {
            vlSelfRef.ember_top__DOT__u_core__DOT__running = 0U;
            if (vlSelfRef.ember_top__DOT__u_core__DOT__kick) {
                vlSelfRef.ember_top__DOT__u_core__DOT__running = 1U;
                __Vdly__ember_top__DOT__u_core__DOT__blk = 0U;
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__T.enqueue(0U, 8U, 0U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__fpc.enqueue(0U, 0U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(0x0005b000U, 0U, 0x0cU);
                vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_v = 0U;
                __Vdly__ember_top__DOT__u_core__DOT__waitv = 0U;
                __Vdly__ember_top__DOT__u_core__DOT__barv = 0U;
                __Vdly__ember_top__DOT__u_core__DOT__bar_count = 0U;
                __Vdly__ember_top__DOT__u_core__DOT__budget = 0U;
                __Vdly__ember_top__DOT__u_core__DOT__st = 1U;
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__T.enqueue(0U, 7U, 0U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(0U, 0U, 0x0dU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__fpc.enqueue(0U, 1U);
                __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v30 
                    = vlSelfRef.ember_top__DOT__u_core__DOT__nblk_q;
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__gpr__v30, 0U, 0x0eU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__T.enqueue(0U, 8U, 1U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__fpc.enqueue(0U, 2U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(0U, 0U, 0x0fU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__T.enqueue(0U, 7U, 1U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__fpc.enqueue(0U, 3U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(0x0005b000U, 1U, 0x0cU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__T.enqueue(0U, 8U, 2U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(0U, 1U, 0x0dU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__T.enqueue(0U, 7U, 2U);
                __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v34 
                    = vlSelfRef.ember_top__DOT__u_core__DOT__nblk_q;
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__gpr__v34, 1U, 0x0eU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__T.enqueue(0U, 8U, 3U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(1U, 1U, 0x0fU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__T.enqueue(0U, 7U, 3U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(0x0005b000U, 2U, 0x0cU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(0U, 2U, 0x0dU);
                __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v38 
                    = vlSelfRef.ember_top__DOT__u_core__DOT__nblk_q;
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__gpr__v38, 2U, 0x0eU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(2U, 2U, 0x0fU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(0x0005b000U, 3U, 0x0cU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(0U, 3U, 0x0dU);
                __VdlyVal__ember_top__DOT__u_core__DOT__gpr__v42 
                    = vlSelfRef.ember_top__DOT__u_core__DOT__nblk_q;
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(__VdlyVal__ember_top__DOT__u_core__DOT__gpr__v42, 3U, 0x0eU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(3U, 3U, 0x0fU);
            }
        }
    } else {
        __Vdly__ember_top__DOT__u_core__DOT__flush_req = 0U;
        __Vdly__ember_top__DOT__u_core__DOT__waitv = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk4__DOT__t = 0U;
        __Vdly__ember_top__DOT__u_core__DOT__st = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__running = 0U;
        __Vdly__ember_top__DOT__u_core__DOT__blk = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_v = 0U;
        __Vdly__ember_top__DOT__u_core__DOT__ix_pend = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__ix_req_cyc = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__ix_tid = 0U;
        __Vdly__ember_top__DOT__u_core__DOT__flush_tid = 0U;
        __Vdly__ember_top__DOT__u_core__DOT__ld_pend = 0U;
        __Vdly__ember_top__DOT__u_core__DOT__ld_addr_q = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__ld_tid_q = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__ld_rd_q = 0U;
        __Vdly__ember_top__DOT__u_core__DOT__cx_pend = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__cx_req_cyc = 0U;
        __Vdly__ember_top__DOT__u_core__DOT__dr_valid = 0U;
        __Vdly__ember_top__DOT__u_core__DOT__dr_tid = 0U;
        __Vdly__ember_top__DOT__u_core__DOT__dr_rd = 0U;
        __Vdly__ember_top__DOT__u_core__DOT__dr_word = 0U;
        __Vdly__ember_top__DOT__u_core__DOT__fp_pend = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__fp_tid = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__fp_rd = 0U;
        __Vdly__ember_top__DOT__u_core__DOT__bar_count = 0U;
        __Vdly__ember_top__DOT__u_core__DOT__budget = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__f_lane_en = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__f_go = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__f_op = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__f_a0 = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__f_b0 = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__cxa_we = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__cxa_addr = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__cxa_wdata = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__cxa_be = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__cxa_req = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__ixa_req = 0U;
        vlSelfRef.ember_top__DOT__u_core__DOT__ixa_addr = 0U;
        __Vdly__ember_top__DOT__u_core__DOT__barv = 0U;
        while ((4U > vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk4__DOT__t)) {
            __VdlyDim0__ember_top__DOT__u_core__DOT__T__v19 
                = (3U & vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk4__DOT__t);
            vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__T.enqueue(0U, 0x0fU, (IData)(__VdlyDim0__ember_top__DOT__u_core__DOT__T__v19));
            __VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v14 
                = (3U & vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk4__DOT__t);
            vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__fpc.enqueue(0U, (IData)(__VdlyDim0__ember_top__DOT__u_core__DOT__fpc__v14));
            __VdlyDim0__ember_top__DOT__u_core__DOT__ibuf_w__v1 
                = (3U & vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk4__DOT__t);
            vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__ibuf_w.enqueue(0U, (IData)(__VdlyDim0__ember_top__DOT__u_core__DOT__ibuf_w__v1));
            vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk4__DOT__unnamedblk5__DOT__r = 0U;
            while (VL_GTS_III(32, 0x00000010U, vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk4__DOT__unnamedblk5__DOT__r)) {
                __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v44 
                    = (0x0000000fU & vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk4__DOT__unnamedblk5__DOT__r);
                __VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v44 
                    = (3U & vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk4__DOT__t);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.enqueue(0U, (IData)(__VdlyDim1__ember_top__DOT__u_core__DOT__gpr__v44), __VdlyDim0__ember_top__DOT__u_core__DOT__gpr__v44);
                vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk4__DOT__unnamedblk5__DOT__r 
                    = ((IData)(1U) + vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk4__DOT__unnamedblk5__DOT__r);
            }
            vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk4__DOT__t 
                = ((IData)(1U) + vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk4__DOT__t);
        }
    }
    vlSelfRef.ember_top__DOT__u_core__DOT__ix_pend 
        = __Vdly__ember_top__DOT__u_core__DOT__ix_pend;
    vlSelfRef.ember_top__DOT__u_core__DOT__flush_req 
        = __Vdly__ember_top__DOT__u_core__DOT__flush_req;
    vlSelfRef.ember_top__DOT__u_core__DOT__cx_pend 
        = __Vdly__ember_top__DOT__u_core__DOT__cx_pend;
    vlSelfRef.ember_top__DOT__u_core__DOT__dr_valid 
        = __Vdly__ember_top__DOT__u_core__DOT__dr_valid;
    vlSelfRef.ember_top__DOT__u_core__DOT__dr_tid = __Vdly__ember_top__DOT__u_core__DOT__dr_tid;
    vlSelfRef.ember_top__DOT__u_core__DOT__dr_rd = __Vdly__ember_top__DOT__u_core__DOT__dr_rd;
    vlSelfRef.ember_top__DOT__u_core__DOT__dr_word 
        = __Vdly__ember_top__DOT__u_core__DOT__dr_word;
    vlSelfRef.ember_top__DOT__u_core__DOT__fp_pend 
        = __Vdly__ember_top__DOT__u_core__DOT__fp_pend;
    vlSelfRef.ember_top__DOT__u_core__DOT__blk = __Vdly__ember_top__DOT__u_core__DOT__blk;
    vlSelfRef.ember_top__DOT__u_core__DOT__bar_count 
        = __Vdly__ember_top__DOT__u_core__DOT__bar_count;
    vlSelfRef.ember_top__DOT__u_core__DOT__budget = __Vdly__ember_top__DOT__u_core__DOT__budget;
    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__fpc.commit(vlSelfRef.ember_top__DOT__u_core__DOT__fpc);
    vlSelfRef.ember_top__DOT__u_core__DOT__flush_tid 
        = __Vdly__ember_top__DOT__u_core__DOT__flush_tid;
    vlSelfRef.ember_top__DOT__u_core__DOT__ld_pend 
        = __Vdly__ember_top__DOT__u_core__DOT__ld_pend;
    vlSelfRef.ember_top__DOT__u_core__DOT__ld_addr_q 
        = __Vdly__ember_top__DOT__u_core__DOT__ld_addr_q;
    if (__VdlySet__ember_top__DOT__u_core__DOT__smem__v0) {
        vlSelfRef.ember_top__DOT__u_core__DOT__smem[__VdlyDim0__ember_top__DOT__u_core__DOT__smem__v0] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__smem__v0;
    }
    if (__VdlySet__ember_top__DOT__u_core__DOT__smem__v1) {
        vlSelfRef.ember_top__DOT__u_core__DOT__smem[__VdlyDim0__ember_top__DOT__u_core__DOT__smem__v1] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__smem__v1;
    }
    if (__VdlySet__ember_top__DOT__u_core__DOT__smem__v2) {
        vlSelfRef.ember_top__DOT__u_core__DOT__smem[__VdlyDim0__ember_top__DOT__u_core__DOT__smem__v2] 
            = __VdlyVal__ember_top__DOT__u_core__DOT__smem__v2;
    }
    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__T.commit(vlSelfRef.ember_top__DOT__u_core__DOT__T);
    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__gpr.commit(vlSelfRef.ember_top__DOT__u_core__DOT__gpr);
    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_core__DOT__ibuf_w.commit(vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_w);
    if (vlSelfRef.ember_top__DOT__u_core__DOT__rst_n) {
        if (((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__csr_nblk_we) 
             & (0U != (0x000000ffU & vlSelfRef.ember_top__DOT__u_core__DOT__csr_wdata)))) {
            vlSelfRef.ember_top__DOT__u_core__DOT__nblk_q 
                = (0x000000ffU & vlSelfRef.ember_top__DOT__u_core__DOT__csr_wdata);
        }
        if (vlSelfRef.ember_top__DOT__u_core__DOT__csr_code_we) {
            vlSelfRef.ember_top__DOT__u_core__DOT__code_base_q 
                = (0xfffffffcU & vlSelfRef.ember_top__DOT__u_core__DOT__csr_wdata);
        }
    } else {
        vlSelfRef.ember_top__DOT__u_core__DOT__nblk_q = 1U;
        vlSelfRef.ember_top__DOT__u_core__DOT__code_base_q = 0U;
    }
    vlSelfRef.ember_top__DOT__u_core__DOT__waitv = __Vdly__ember_top__DOT__u_core__DOT__waitv;
    vlSelfRef.ember_top__DOT__u_core__DOT__barv = __Vdly__ember_top__DOT__u_core__DOT__barv;
    vlSelfRef.ember_top__DOT__u_core__DOT__st = __Vdly__ember_top__DOT__u_core__DOT__st;
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__a3 
        = vlSelfRef.ember_top__DOT__u_core__DOT__f_a3;
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__b2 
        = vlSelfRef.ember_top__DOT__u_core__DOT__f_b2;
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__b3 
        = vlSelfRef.ember_top__DOT__u_core__DOT__f_b3;
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__a1 
        = vlSelfRef.ember_top__DOT__u_core__DOT__f_a1;
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__b1 
        = vlSelfRef.ember_top__DOT__u_core__DOT__f_b1;
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__a2 
        = vlSelfRef.ember_top__DOT__u_core__DOT__f_a2;
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__go 
        = vlSelfRef.ember_top__DOT__u_core__DOT__f_go;
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__lane_en 
        = vlSelfRef.ember_top__DOT__u_core__DOT__f_lane_en;
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__op 
        = vlSelfRef.ember_top__DOT__u_core__DOT__f_op;
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__a0 
        = vlSelfRef.ember_top__DOT__u_core__DOT__f_a0;
    vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__b0 
        = vlSelfRef.ember_top__DOT__u_core__DOT__f_b0;
    vlSelfRef.ember_top__DOT__core_cxa_we = vlSelfRef.ember_top__DOT__u_core__DOT__cxa_we;
    vlSelfRef.ember_top__DOT__core_cxa_req = vlSelfRef.ember_top__DOT__u_core__DOT__cxa_req;
    vlSelfRef.ember_top__DOT__core_ixa_req = vlSelfRef.ember_top__DOT__u_core__DOT__ixa_req;
    vlSelfRef.ember_top__DOT__core_cxa_be = vlSelfRef.ember_top__DOT__u_core__DOT__cxa_be;
    vlSelfRef.ember_top__DOT__core_cxa_wdata = vlSelfRef.ember_top__DOT__u_core__DOT__cxa_wdata;
    vlSelfRef.ember_top__DOT__core_cxa_addr = vlSelfRef.ember_top__DOT__u_core__DOT__cxa_addr;
    vlSelfRef.ember_top__DOT__core_ixa_addr = vlSelfRef.ember_top__DOT__u_core__DOT__ixa_addr;
    vlSelfRef.ember_top__DOT__u_core__DOT__busy = vlSelfRef.ember_top__DOT__u_core__DOT__running;
    vlSelfRef.ember_top__DOT__u_core__DOT__pick_en = 0U;
    vlSelfRef.ember_top__DOT__u_core__DOT__pick_tid = 0U;
    vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk2__DOT__t = 3U;
    while (VL_LTES_III(32, 0U, vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk2__DOT__t)) {
        if ((((1U == (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__st)) 
              & (~ (vlSelfRef.ember_top__DOT__u_core__DOT__T
                    [(3U & vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk2__DOT__t)] 
                    >> 3U))) & (~ ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_v) 
                                   >> (3U & vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk2__DOT__t))))) {
            vlSelfRef.ember_top__DOT__u_core__DOT__pick_en = 1U;
            vlSelfRef.ember_top__DOT__u_core__DOT__pick_tid 
                = (3U & vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk2__DOT__t);
        }
        vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk2__DOT__t 
            = (vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk2__DOT__t 
               - (IData)(1U));
    }
    vlSelfRef.ember_top__DOT__u_core__DOT__exec_en = 0U;
    vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid = 0U;
    vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk1__DOT__t = 3U;
    while (VL_LTES_III(32, 0U, vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk1__DOT__t)) {
        if (((((1U == (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__st)) 
               & ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_v) 
                  >> (3U & vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk1__DOT__t))) 
              & (~ ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__waitv) 
                    >> (3U & vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk1__DOT__t)))) 
             & (~ ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__barv) 
                   >> (3U & vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk1__DOT__t))))) {
            vlSelfRef.ember_top__DOT__u_core__DOT__exec_en = 1U;
            vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid 
                = (3U & vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk1__DOT__t);
        }
        vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk1__DOT__t 
            = (vlSelfRef.ember_top__DOT__u_core__DOT__unnamedblk1__DOT__t 
               - (IData)(1U));
    }
    vlSelfRef.ember_top__DOT__u_vram__DOT__cxa_we = vlSelfRef.ember_top__DOT__core_cxa_we;
    vlSelfRef.ember_top__DOT__u_vram__DOT__cxa_req 
        = vlSelfRef.ember_top__DOT__core_cxa_req;
    vlSelfRef.ember_top__DOT__u_vram__DOT__ixa_req 
        = vlSelfRef.ember_top__DOT__core_ixa_req;
    vlSelfRef.ember_top__DOT__u_vram__DOT__cxa_be = vlSelfRef.ember_top__DOT__core_cxa_be;
    vlSelfRef.ember_top__DOT__u_vram__DOT__cxa_wdata 
        = vlSelfRef.ember_top__DOT__core_cxa_wdata;
    vlSelfRef.ember_top__DOT__u_vram__DOT__cxa_addr 
        = vlSelfRef.ember_top__DOT__core_cxa_addr;
    vlSelfRef.ember_top__DOT__u_vram__DOT__ixa_addr 
        = vlSelfRef.ember_top__DOT__core_ixa_addr;
    vlSelfRef.ember_top__DOT__core_busy = vlSelfRef.ember_top__DOT__u_core__DOT__busy;
    vlSelfRef.ember_top__DOT__u_core__DOT__i_op = (vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_w
                                                   [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid] 
                                                   >> 0x00000018U);
    vlSelfRef.ember_top__DOT__u_core__DOT__i_rd = (0x0000000fU 
                                                   & (vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_w
                                                      [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid] 
                                                      >> 0x00000014U));
    vlSelfRef.ember_top__DOT__u_core__DOT__i_ra = (0x0000000fU 
                                                   & (vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_w
                                                      [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid] 
                                                      >> 0x00000010U));
    vlSelfRef.ember_top__DOT__u_core__DOT__i_rb = (0x0000000fU 
                                                   & (vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_w
                                                      [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid] 
                                                      >> 0x0000000cU));
    vlSelfRef.ember_top__DOT__u_core__DOT__i_imm = 
        (0x00000fffU & vlSelfRef.ember_top__DOT__u_core__DOT__ibuf_w
         [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid]);
    vlSelfRef.ember_top__DOT__u_vram__DOT__cxa_widx 
        = (0x0001ffffU & ((vlSelfRef.ember_top__DOT__u_vram__DOT__cxa_addr 
                           - (IData)(0x00001000U)) 
                          >> 2U));
    vlSelfRef.ember_top__DOT__u_vram__DOT__ixa_widx 
        = (0x0001ffffU & ((vlSelfRef.ember_top__DOT__u_vram__DOT__ixa_addr 
                           - (IData)(0x00001000U)) 
                          >> 2U));
    vlSelfRef.ember_top__DOT__u_cp__DOT__core_busy 
        = vlSelfRef.ember_top__DOT__core_busy;
    vlSelfRef.ember_top__DOT__u_core__DOT__rav = vlSelfRef.ember_top__DOT__u_core__DOT__gpr
        [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid]
        [vlSelfRef.ember_top__DOT__u_core__DOT__i_ra];
    vlSelfRef.ember_top__DOT__u_core__DOT__rbv = vlSelfRef.ember_top__DOT__u_core__DOT__gpr
        [vlSelfRef.ember_top__DOT__u_core__DOT__exec_tid]
        [vlSelfRef.ember_top__DOT__u_core__DOT__i_rb];
    vlSelfRef.ember_top__DOT__u_core__DOT__i_sx12 = 
        (((- (IData)((1U & ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_imm) 
                            >> 0x0000000bU)))) << 0x0000000cU) 
         | (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_imm));
    vlSelfRef.ember_top__DOT__u_core__DOT__i_sx9 = 
        (0x000001ffU & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_imm));
    vlSelfRef.ember_top__DOT__u_core__DOT__i_sx11 = 
        (0x000007ffU & (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__i_imm));
}

void Vtop___024root___nba_sequent__TOP__13(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__13\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    QData/*32:0*/ ember_top__DOT__u_rtr__DOT__u_setup__DOT____VdfgRegularize_hede74ea3_0_2;
    ember_top__DOT__u_rtr__DOT__u_setup__DOT____VdfgRegularize_hede74ea3_0_2 = 0;
    QData/*32:0*/ ember_top__DOT__u_rtr__DOT__u_setup__DOT____VdfgRegularize_hede74ea3_0_6;
    ember_top__DOT__u_rtr__DOT__u_setup__DOT____VdfgRegularize_hede74ea3_0_6 = 0;
    VlWide<4>/*117:0*/ __VdfgRegularize_h6e95ff9d_0_4;
    VL_ZERO_W(118, __VdfgRegularize_h6e95ff9d_0_4);
    IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_7;
    __VdfgRegularize_h6e95ff9d_0_7 = 0;
    IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_8;
    __VdfgRegularize_h6e95ff9d_0_8 = 0;
    IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_9;
    __VdfgRegularize_h6e95ff9d_0_9 = 0;
    IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_10;
    __VdfgRegularize_h6e95ff9d_0_10 = 0;
    CData/*2:0*/ __Vdly__ember_top__DOT__u_rtr__DOT__fst;
    __Vdly__ember_top__DOT__u_rtr__DOT__fst = 0;
    IData/*31:0*/ __Vdly__ember_top__DOT__u_rtr__DOT__cursor;
    __Vdly__ember_top__DOT__u_rtr__DOT__cursor = 0;
    CData/*4:0*/ __Vdly__ember_top__DOT__u_rtr__DOT__fidx;
    __Vdly__ember_top__DOT__u_rtr__DOT__fidx = 0;
    IData/*31:0*/ __VdlyVal__ember_top__DOT__u_rtr__DOT__cmd_q__v0;
    __VdlyVal__ember_top__DOT__u_rtr__DOT__cmd_q__v0 = 0;
    CData/*4:0*/ __VdlyDim0__ember_top__DOT__u_rtr__DOT__cmd_q__v0;
    __VdlyDim0__ember_top__DOT__u_rtr__DOT__cmd_q__v0 = 0;
    CData/*0:0*/ __VdlySet__ember_top__DOT__u_rtr__DOT__cmd_q__v0;
    __VdlySet__ember_top__DOT__u_rtr__DOT__cmd_q__v0 = 0;
    VlWide<3>/*95:0*/ __Vtemp_1;
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_5;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_8;
    VlWide<3>/*95:0*/ __Vtemp_11;
    VlWide<3>/*95:0*/ __Vtemp_12;
    VlWide<3>/*95:0*/ __Vtemp_14;
    VlWide<3>/*95:0*/ __Vtemp_15;
    VlWide<3>/*95:0*/ __Vtemp_16;
    VlWide<3>/*95:0*/ __Vtemp_19;
    VlWide<3>/*95:0*/ __Vtemp_20;
    VlWide<3>/*95:0*/ __Vtemp_22;
    VlWide<3>/*95:0*/ __Vtemp_23;
    VlWide<3>/*95:0*/ __Vtemp_24;
    VlWide<3>/*95:0*/ __Vtemp_26;
    VlWide<3>/*95:0*/ __Vtemp_27;
    VlWide<3>/*95:0*/ __Vtemp_28;
    VlWide<3>/*95:0*/ __Vtemp_29;
    VlWide<3>/*95:0*/ __Vtemp_35;
    VlWide<3>/*95:0*/ __Vtemp_36;
    VlWide<3>/*95:0*/ __Vtemp_37;
    VlWide<3>/*95:0*/ __Vtemp_38;
    VlWide<3>/*95:0*/ __Vtemp_39;
    VlWide<4>/*127:0*/ __Vtemp_40;
    VlWide<4>/*127:0*/ __Vtemp_41;
    VlWide<4>/*127:0*/ __Vtemp_42;
    VlWide<4>/*127:0*/ __Vtemp_43;
    VlWide<3>/*95:0*/ __Vtemp_47;
    VlWide<3>/*95:0*/ __Vtemp_48;
    VlWide<3>/*95:0*/ __Vtemp_49;
    VlWide<3>/*95:0*/ __Vtemp_50;
    VlWide<3>/*95:0*/ __Vtemp_51;
    VlWide<4>/*127:0*/ __Vtemp_52;
    VlWide<4>/*127:0*/ __Vtemp_53;
    VlWide<4>/*127:0*/ __Vtemp_54;
    VlWide<4>/*127:0*/ __Vtemp_55;
    VlWide<3>/*95:0*/ __Vtemp_59;
    VlWide<3>/*95:0*/ __Vtemp_60;
    VlWide<3>/*95:0*/ __Vtemp_61;
    VlWide<3>/*95:0*/ __Vtemp_62;
    VlWide<3>/*95:0*/ __Vtemp_63;
    VlWide<4>/*127:0*/ __Vtemp_64;
    VlWide<4>/*127:0*/ __Vtemp_65;
    VlWide<4>/*127:0*/ __Vtemp_66;
    VlWide<4>/*127:0*/ __Vtemp_67;
    VlWide<3>/*95:0*/ __Vtemp_71;
    VlWide<3>/*95:0*/ __Vtemp_72;
    VlWide<3>/*95:0*/ __Vtemp_73;
    VlWide<3>/*95:0*/ __Vtemp_74;
    VlWide<3>/*95:0*/ __Vtemp_75;
    VlWide<4>/*127:0*/ __Vtemp_76;
    VlWide<4>/*127:0*/ __Vtemp_77;
    VlWide<4>/*127:0*/ __Vtemp_78;
    VlWide<4>/*127:0*/ __Vtemp_79;
    VlWide<3>/*95:0*/ __Vtemp_83;
    VlWide<3>/*95:0*/ __Vtemp_84;
    VlWide<3>/*95:0*/ __Vtemp_85;
    VlWide<3>/*95:0*/ __Vtemp_86;
    VlWide<3>/*95:0*/ __Vtemp_87;
    VlWide<4>/*127:0*/ __Vtemp_88;
    VlWide<4>/*127:0*/ __Vtemp_89;
    VlWide<4>/*127:0*/ __Vtemp_90;
    VlWide<4>/*127:0*/ __Vtemp_91;
    VlWide<3>/*95:0*/ __Vtemp_95;
    VlWide<3>/*95:0*/ __Vtemp_96;
    VlWide<3>/*95:0*/ __Vtemp_97;
    VlWide<3>/*95:0*/ __Vtemp_98;
    VlWide<3>/*95:0*/ __Vtemp_99;
    VlWide<4>/*127:0*/ __Vtemp_100;
    VlWide<4>/*127:0*/ __Vtemp_101;
    VlWide<4>/*127:0*/ __Vtemp_102;
    VlWide<4>/*127:0*/ __Vtemp_103;
    VlWide<3>/*95:0*/ __Vtemp_107;
    VlWide<3>/*95:0*/ __Vtemp_108;
    VlWide<3>/*95:0*/ __Vtemp_109;
    VlWide<3>/*95:0*/ __Vtemp_110;
    VlWide<3>/*95:0*/ __Vtemp_111;
    VlWide<4>/*127:0*/ __Vtemp_112;
    VlWide<4>/*127:0*/ __Vtemp_113;
    VlWide<4>/*127:0*/ __Vtemp_114;
    VlWide<4>/*127:0*/ __Vtemp_115;
    VlWide<3>/*95:0*/ __Vtemp_119;
    VlWide<3>/*95:0*/ __Vtemp_120;
    VlWide<3>/*95:0*/ __Vtemp_121;
    VlWide<3>/*95:0*/ __Vtemp_122;
    VlWide<3>/*95:0*/ __Vtemp_123;
    VlWide<4>/*127:0*/ __Vtemp_124;
    VlWide<4>/*127:0*/ __Vtemp_125;
    VlWide<4>/*127:0*/ __Vtemp_126;
    VlWide<4>/*127:0*/ __Vtemp_127;
    VlWide<3>/*95:0*/ __Vtemp_131;
    VlWide<3>/*95:0*/ __Vtemp_132;
    VlWide<3>/*95:0*/ __Vtemp_133;
    VlWide<3>/*95:0*/ __Vtemp_134;
    VlWide<3>/*95:0*/ __Vtemp_135;
    VlWide<4>/*127:0*/ __Vtemp_136;
    VlWide<4>/*127:0*/ __Vtemp_137;
    VlWide<4>/*127:0*/ __Vtemp_138;
    VlWide<4>/*127:0*/ __Vtemp_139;
    VlWide<3>/*95:0*/ __Vtemp_143;
    VlWide<3>/*95:0*/ __Vtemp_144;
    VlWide<3>/*95:0*/ __Vtemp_145;
    VlWide<3>/*95:0*/ __Vtemp_146;
    VlWide<3>/*95:0*/ __Vtemp_147;
    VlWide<4>/*127:0*/ __Vtemp_148;
    VlWide<4>/*127:0*/ __Vtemp_149;
    VlWide<4>/*127:0*/ __Vtemp_150;
    VlWide<4>/*127:0*/ __Vtemp_151;
    VlWide<3>/*95:0*/ __Vtemp_155;
    VlWide<3>/*95:0*/ __Vtemp_156;
    VlWide<3>/*95:0*/ __Vtemp_157;
    VlWide<3>/*95:0*/ __Vtemp_158;
    VlWide<3>/*95:0*/ __Vtemp_159;
    VlWide<4>/*127:0*/ __Vtemp_160;
    VlWide<4>/*127:0*/ __Vtemp_161;
    VlWide<4>/*127:0*/ __Vtemp_162;
    VlWide<4>/*127:0*/ __Vtemp_163;
    VlWide<3>/*95:0*/ __Vtemp_167;
    VlWide<3>/*95:0*/ __Vtemp_168;
    VlWide<3>/*95:0*/ __Vtemp_169;
    VlWide<3>/*95:0*/ __Vtemp_170;
    VlWide<3>/*95:0*/ __Vtemp_171;
    VlWide<4>/*127:0*/ __Vtemp_172;
    VlWide<4>/*127:0*/ __Vtemp_173;
    VlWide<4>/*127:0*/ __Vtemp_174;
    VlWide<4>/*127:0*/ __Vtemp_175;
    VlWide<3>/*95:0*/ __Vtemp_177;
    VlWide<3>/*95:0*/ __Vtemp_178;
    VlWide<3>/*95:0*/ __Vtemp_179;
    VlWide<3>/*95:0*/ __Vtemp_180;
    VlWide<3>/*95:0*/ __Vtemp_181;
    VlWide<3>/*95:0*/ __Vtemp_182;
    VlWide<3>/*95:0*/ __Vtemp_183;
    VlWide<3>/*95:0*/ __Vtemp_184;
    VlWide<3>/*95:0*/ __Vtemp_185;
    VlWide<3>/*95:0*/ __Vtemp_186;
    VlWide<3>/*95:0*/ __Vtemp_187;
    VlWide<3>/*95:0*/ __Vtemp_188;
    VlWide<3>/*95:0*/ __Vtemp_189;
    VlWide<3>/*95:0*/ __Vtemp_190;
    VlWide<3>/*95:0*/ __Vtemp_191;
    VlWide<3>/*95:0*/ __Vtemp_192;
    VlWide<3>/*95:0*/ __Vtemp_193;
    VlWide<3>/*95:0*/ __Vtemp_194;
    VlWide<3>/*95:0*/ __Vtemp_195;
    VlWide<3>/*95:0*/ __Vtemp_196;
    VlWide<3>/*95:0*/ __Vtemp_197;
    VlWide<3>/*95:0*/ __Vtemp_198;
    VlWide<3>/*95:0*/ __Vtemp_199;
    VlWide<3>/*95:0*/ __Vtemp_200;
    VlWide<3>/*95:0*/ __Vtemp_201;
    VlWide<3>/*95:0*/ __Vtemp_202;
    VlWide<3>/*95:0*/ __Vtemp_203;
    VlWide<3>/*95:0*/ __Vtemp_204;
    VlWide<3>/*95:0*/ __Vtemp_205;
    VlWide<3>/*95:0*/ __Vtemp_206;
    VlWide<3>/*95:0*/ __Vtemp_207;
    VlWide<3>/*95:0*/ __Vtemp_208;
    VlWide<3>/*95:0*/ __Vtemp_209;
    VlWide<3>/*95:0*/ __Vtemp_210;
    VlWide<3>/*95:0*/ __Vtemp_211;
    VlWide<3>/*95:0*/ __Vtemp_212;
    VlWide<3>/*95:0*/ __Vtemp_213;
    VlWide<3>/*95:0*/ __Vtemp_214;
    VlWide<3>/*95:0*/ __Vtemp_215;
    VlWide<3>/*95:0*/ __Vtemp_216;
    VlWide<3>/*95:0*/ __Vtemp_217;
    VlWide<3>/*95:0*/ __Vtemp_218;
    VlWide<3>/*95:0*/ __Vtemp_219;
    VlWide<3>/*95:0*/ __Vtemp_220;
    VlWide<3>/*95:0*/ __Vtemp_221;
    VlWide<3>/*95:0*/ __Vtemp_222;
    VlWide<3>/*95:0*/ __Vtemp_223;
    VlWide<3>/*95:0*/ __Vtemp_224;
    // Body
    __Vdly__ember_top__DOT__u_rtr__DOT__cursor = vlSelfRef.ember_top__DOT__u_rtr__DOT__cursor;
    __Vdly__ember_top__DOT__u_rtr__DOT__fidx = vlSelfRef.ember_top__DOT__u_rtr__DOT__fidx;
    __Vdly__ember_top__DOT__u_rtr__DOT__fst = vlSelfRef.ember_top__DOT__u_rtr__DOT__fst;
    __VdlySet__ember_top__DOT__u_rtr__DOT__cmd_q__v0 = 0U;
    if (vlSelfRef.ember_top__DOT__u_rtr__DOT__rst_n) {
        vlSelfRef.ember_top__DOT__u_rtr__DOT__fetch_req = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_start = 0U;
        if ((4U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__fst))) {
            if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__fst))) {
                __Vdly__ember_top__DOT__u_rtr__DOT__fst = 0U;
            } else if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__fst))) {
                __Vdly__ember_top__DOT__u_rtr__DOT__cursor 
                    = ((IData)(0x0000004cU) + vlSelfRef.ember_top__DOT__u_rtr__DOT__cursor);
                __Vdly__ember_top__DOT__u_rtr__DOT__fidx = 0U;
                vlSelfRef.ember_top__DOT__u_rtr__DOT__fetch_req = 1U;
                vlSelfRef.ember_top__DOT__u_rtr__DOT__fetch_addr 
                    = ((IData)(0x0000004cU) + vlSelfRef.ember_top__DOT__u_rtr__DOT__cursor);
                __Vdly__ember_top__DOT__u_rtr__DOT__fst = 1U;
            } else if (vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_done) {
                __Vdly__ember_top__DOT__u_rtr__DOT__fst = 5U;
            }
        } else if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__fst))) {
            if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__fst))) {
                if (vlSelfRef.ember_top__DOT__u_rtr__DOT__cull) {
                    __Vdly__ember_top__DOT__u_rtr__DOT__fst = 5U;
                } else {
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_start = 1U;
                    __Vdly__ember_top__DOT__u_rtr__DOT__fst = 4U;
                }
            } else {
                vlSelfRef.ember_top__DOT__u_rtr__DOT____Vlvbound_hcfa37505__0 
                    = vlSelfRef.ember_top__DOT__u_rtr__DOT__fpa_rdata;
                if ((0x12U >= (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__fidx))) {
                    __VdlyVal__ember_top__DOT__u_rtr__DOT__cmd_q__v0 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT____Vlvbound_hcfa37505__0;
                    __VdlyDim0__ember_top__DOT__u_rtr__DOT__cmd_q__v0 
                        = vlSelfRef.ember_top__DOT__u_rtr__DOT__fidx;
                    __VdlySet__ember_top__DOT__u_rtr__DOT__cmd_q__v0 = 1U;
                }
                if (((0U == (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__fidx)) 
                     & (~ vlSelfRef.ember_top__DOT__u_rtr__DOT__fpa_rdata))) {
                    __Vdly__ember_top__DOT__u_rtr__DOT__fst = 0U;
                } else if ((0x12U == (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__fidx))) {
                    __Vdly__ember_top__DOT__u_rtr__DOT__fst = 3U;
                } else {
                    __Vdly__ember_top__DOT__u_rtr__DOT__fidx 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__fidx)));
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__fetch_req = 1U;
                    vlSelfRef.ember_top__DOT__u_rtr__DOT__fetch_addr 
                        = ((IData)(4U) + (vlSelfRef.ember_top__DOT__u_rtr__DOT__cursor 
                                          + ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__fidx) 
                                             << 2U)));
                    __Vdly__ember_top__DOT__u_rtr__DOT__fst = 1U;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__fst))) {
            __Vdly__ember_top__DOT__u_rtr__DOT__fst = 2U;
        } else if (vlSelfRef.ember_top__DOT__u_rtr__DOT__kick) {
            __Vdly__ember_top__DOT__u_rtr__DOT__cursor = 0x0005c000U;
            __Vdly__ember_top__DOT__u_rtr__DOT__fidx = 0U;
            vlSelfRef.ember_top__DOT__u_rtr__DOT__fetch_req = 1U;
            vlSelfRef.ember_top__DOT__u_rtr__DOT__fetch_addr = 0x0005c000U;
            __Vdly__ember_top__DOT__u_rtr__DOT__fst = 1U;
        }
    } else {
        __Vdly__ember_top__DOT__u_rtr__DOT__fst = 0U;
        __Vdly__ember_top__DOT__u_rtr__DOT__cursor = 0x0005c000U;
        __Vdly__ember_top__DOT__u_rtr__DOT__fidx = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__fetch_req = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_start = 0U;
    }
    vlSelfRef.ember_top__DOT__u_rtr__DOT__cursor = __Vdly__ember_top__DOT__u_rtr__DOT__cursor;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__fidx = __Vdly__ember_top__DOT__u_rtr__DOT__fidx;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__fst = __Vdly__ember_top__DOT__u_rtr__DOT__fst;
    if (__VdlySet__ember_top__DOT__u_rtr__DOT__cmd_q__v0) {
        vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[__VdlyDim0__ember_top__DOT__u_rtr__DOT__cmd_q__v0] 
            = __VdlyVal__ember_top__DOT__u_rtr__DOT__cmd_q__v0;
    }
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__start 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_start;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__in_fetch 
        = ((1U == (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__fst)) 
           | (2U == (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__fst)));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__t_ztest 
        = (1U & (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[0U] 
                 >> 2U));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__t_tex 
        = (1U & (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[0U] 
                 >> 3U));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__t_rgbmap 
        = (1U & (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[0U] 
                 >> 5U));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__t_texpage 
        = (0x000000ffU & (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[0U] 
                          >> 8U));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__t_dither 
        = (1U & (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[0U] 
                 >> 4U));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__t_blend 
        = (1U & (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[0U] 
                 >> 1U));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__vb1 = (0x000000ffU 
                                                 & (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[11U] 
                                                    >> 0x00000010U));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__vg1 = (0x000000ffU 
                                                 & (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[11U] 
                                                    >> 8U));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__vr1 = (0x000000ffU 
                                                 & vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[11U]);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__vb2 = (0x000000ffU 
                                                 & (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[12U] 
                                                    >> 0x00000010U));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__vg2 = (0x000000ffU 
                                                 & (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[12U] 
                                                    >> 8U));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__vr2 = (0x000000ffU 
                                                 & vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[12U]);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__vz1 = (0x0000ffffU 
                                                 & vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[8U]);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__vz2 = (0x0000ffffU 
                                                 & vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[9U]);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__vu1 = vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[15U];
    vlSelfRef.ember_top__DOT__u_rtr__DOT__vv1 = vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[16U];
    vlSelfRef.ember_top__DOT__u_rtr__DOT__vu2 = vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[17U];
    vlSelfRef.ember_top__DOT__u_rtr__DOT__vv2 = vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[18U];
    vlSelfRef.ember_top__DOT__u_rtr__DOT__vb0 = (0x000000ffU 
                                                 & (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[10U] 
                                                    >> 0x00000010U));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__vg0 = (0x000000ffU 
                                                 & (vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[10U] 
                                                    >> 8U));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__vr0 = (0x000000ffU 
                                                 & vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[10U]);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__vz0 = (0x0000ffffU 
                                                 & vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[7U]);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__vu0 = vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[13U];
    vlSelfRef.ember_top__DOT__u_rtr__DOT__vv0 = vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[14U];
    vlSelfRef.ember_top__DOT__u_rtr__DOT__vx2 = vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[5U];
    vlSelfRef.ember_top__DOT__u_rtr__DOT__vy2 = vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[6U];
    vlSelfRef.ember_top__DOT__u_rtr__DOT__vx1 = vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[3U];
    vlSelfRef.ember_top__DOT__u_rtr__DOT__vy1 = vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[4U];
    vlSelfRef.ember_top__DOT__u_rtr__DOT__vx0 = vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[1U];
    vlSelfRef.ember_top__DOT__u_rtr__DOT__vy0 = vlSelfRef.ember_top__DOT__u_rtr__DOT__cmd_q[2U];
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT___unused 
        = (0U != (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__t_texpage));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__b1 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vb1;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__g1 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vg1;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__r1 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vr1;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__b2 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vb2;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__g2 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vg2;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__r2 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vr2;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__z1 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vz1;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__z2 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vz2;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u1 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vu1;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v1 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vv1;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u2 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vu2;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v2 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vv2;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__b0 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vb0;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__g0 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vg0;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__r0 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vr0;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__z0 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vz0;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u0 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vu0;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v0 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vv0;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__x2 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vx2;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x2 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vx2;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__y2 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vy2;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y2 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vy2;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__x1 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vx1;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x1 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vx1;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__y1 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vy1;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y1 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vy1;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__x0 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vx0;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x0 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vx0;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__y0 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vy0;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y0 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vy0;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__b1e[0U] 
        = ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__b1) 
           << 0x00000016U);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__b1e[1U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__b1e[2U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__g1e[0U] 
        = ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__g1) 
           << 0x00000016U);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__g1e[1U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__g1e[2U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__r1e[0U] 
        = ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__r1) 
           << 0x00000016U);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__r1e[1U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__r1e[2U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__b2e[0U] 
        = ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__b2) 
           << 0x00000016U);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__b2e[1U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__b2e[2U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__g2e[0U] 
        = ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__g2) 
           << 0x00000016U);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__g2e[1U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__g2e[2U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__r2e[0U] 
        = ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__r2) 
           << 0x00000016U);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__r2e[1U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__r2e[2U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__z1e[0U] 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__z1;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__z1e[1U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__z1e[2U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__z2e[0U] 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__z2;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__z2e[1U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__z2e[2U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u1e[0U] 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u1;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u1e[1U] 
        = (IData)((- (QData)((IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u1 
                                      >> 0x0000001fU)))));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u1e[2U] 
        = (IData)(((- (QData)((IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u1 
                                       >> 0x0000001fU)))) 
                   >> 0x00000020U));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v1e[0U] 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v1;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v1e[1U] 
        = (IData)((- (QData)((IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v1 
                                      >> 0x0000001fU)))));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v1e[2U] 
        = (IData)(((- (QData)((IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v1 
                                       >> 0x0000001fU)))) 
                   >> 0x00000020U));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u2e[0U] 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u2;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u2e[1U] 
        = (IData)((- (QData)((IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u2 
                                      >> 0x0000001fU)))));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u2e[2U] 
        = (IData)(((- (QData)((IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u2 
                                       >> 0x0000001fU)))) 
                   >> 0x00000020U));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v2e[0U] 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v2;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v2e[1U] 
        = (IData)((- (QData)((IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v2 
                                      >> 0x0000001fU)))));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v2e[2U] 
        = (IData)(((- (QData)((IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v2 
                                       >> 0x0000001fU)))) 
                   >> 0x00000020U));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__b0e[0U] 
        = ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__b0) 
           << 0x00000016U);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__b0e[1U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__b0e[2U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__g0e[0U] 
        = ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__g0) 
           << 0x00000016U);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__g0e[1U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__g0e[2U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__r0e[0U] 
        = ((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__r0) 
           << 0x00000016U);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__r0e[1U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__r0e[2U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__z0e[0U] 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__z0;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__z0e[1U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__z0e[2U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u0e[0U] 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u0;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u0e[1U] 
        = (IData)((- (QData)((IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u0 
                                      >> 0x0000001fU)))));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u0e[2U] 
        = (IData)(((- (QData)((IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u0 
                                       >> 0x0000001fU)))) 
                   >> 0x00000020U));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v0e[0U] 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v0;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v0e[1U] 
        = (IData)((- (QData)((IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v0 
                                      >> 0x0000001fU)))));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v0e[2U] 
        = (IData)(((- (QData)((IData)((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v0 
                                       >> 0x0000001fU)))) 
                   >> 0x00000020U));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx12 
        = (0x00000001ffffffffULL & (VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x2) 
                                    - VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x1)));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy12 
        = (0x00000001ffffffffULL & (VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y2) 
                                    - VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y1)));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx20 
        = (0x00000001ffffffffULL & (VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x0) 
                                    - VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x2)));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__xmin 
        = (VL_LTS_III(32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x0, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x1)
            ? (VL_LTS_III(32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x0, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x2)
                ? vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x0
                : vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x2)
            : (VL_LTS_III(32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x1, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x2)
                ? vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x1
                : vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x2));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__xmax 
        = (VL_GTS_III(32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x0, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x1)
            ? (VL_GTS_III(32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x0, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x2)
                ? vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x0
                : vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x2)
            : (VL_GTS_III(32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x1, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x2)
                ? vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x1
                : vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x2));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx20_ 
        = (0x00000001ffffffffULL & (VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x2) 
                                    - VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x0)));
    ember_top__DOT__u_rtr__DOT__u_setup__DOT____VdfgRegularize_hede74ea3_0_6 
        = (0x00000001ffffffffULL & (VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x1) 
                                    - VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x0)));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy20 
        = (0x00000001ffffffffULL & (VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y0) 
                                    - VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y2)));
    VL_EXTENDS_WQ(96,64, __Vtemp_1, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__iwA);
    VL_EXTENDS_WI(96,32, __Vtemp_2, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x0);
    VL_MULS_WWW(96, __Vtemp_3, __Vtemp_1, __Vtemp_2);
    VL_EXTENDS_WQ(96,64, __Vtemp_4, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__iwB);
    VL_EXTENDS_WI(96,32, __Vtemp_5, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y0);
    VL_MULS_WWW(96, __Vtemp_6, __Vtemp_4, __Vtemp_5);
    VL_ADD_W(3, __Vtemp_7, __Vtemp_3, __Vtemp_6);
    VL_SHIFTRS_WWI(96,96,32, __Vtemp_8, __Vtemp_7, 0x00000016U);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__iwC 
        = (0x0000000000400000ULL - (((QData)((IData)(__Vtemp_8[1U])) 
                                     << 0x00000020U) 
                                    | (QData)((IData)(__Vtemp_8[0U]))));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__ymin 
        = (VL_LTS_III(32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y0, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y1)
            ? (VL_LTS_III(32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y0, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y2)
                ? vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y0
                : vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y2)
            : (VL_LTS_III(32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y1, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y2)
                ? vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y1
                : vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y2));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__ymax 
        = (VL_GTS_III(32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y0, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y1)
            ? (VL_GTS_III(32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y0, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y2)
                ? vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y0
                : vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y2)
            : (VL_GTS_III(32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y1, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y2)
                ? vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y1
                : vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y2));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy20_ 
        = (0x00000001ffffffffULL & (VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y2) 
                                    - VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y0)));
    ember_top__DOT__u_rtr__DOT__u_setup__DOT____VdfgRegularize_hede74ea3_0_2 
        = (0x00000001ffffffffULL & (VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y1) 
                                    - VL_EXTENDS_QI(33,32, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y0)));
    VL_SUB_W(3, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__b10, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__b1e, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__b0e);
    VL_SUB_W(3, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__b20, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__b2e, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__b0e);
    VL_SUB_W(3, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__g10, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__g1e, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__g0e);
    VL_SUB_W(3, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__g20, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__g2e, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__g0e);
    VL_SUB_W(3, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__r10, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__r1e, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__r0e);
    VL_SUB_W(3, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__r20, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__r2e, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__r0e);
    VL_SUB_W(3, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__z10, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__z1e, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__z0e);
    VL_SUB_W(3, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__z20, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__z2e, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__z0e);
    VL_SUB_W(3, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u10, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u1e, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u0e);
    VL_SUB_W(3, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u20, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u2e, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u0e);
    VL_SUB_W(3, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v10, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v1e, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v0e);
    VL_SUB_W(3, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v20, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v2e, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v0e);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__dx12 = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx12;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__dy12 = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy12;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__dx20 = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx20;
    __VdfgRegularize_h6e95ff9d_0_7 = VL_SHIFTRS_III(32,32,32, 
                                                    (VL_GTS_III(32, 0U, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__xmin)
                                                      ? 0U
                                                      : 
                                                     (VL_LTS_III(32, 0x4fc00000U, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__xmin)
                                                       ? 0x4fc00000U
                                                       : vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__xmin)), 0x00000016U);
    __VdfgRegularize_h6e95ff9d_0_8 = VL_SHIFTRS_III(32,32,32, 
                                                    (VL_GTS_III(32, 0U, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__xmax)
                                                      ? 0U
                                                      : 
                                                     (VL_LTS_III(32, 0x4fc00000U, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__xmax)
                                                       ? 0x4fc00000U
                                                       : vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__xmax)), 0x00000016U);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx01 
        = ember_top__DOT__u_rtr__DOT__u_setup__DOT____VdfgRegularize_hede74ea3_0_6;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx10_ 
        = ember_top__DOT__u_rtr__DOT__u_setup__DOT____VdfgRegularize_hede74ea3_0_6;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__dy20 = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy20;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__iwC = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__iwC;
    __VdfgRegularize_h6e95ff9d_0_9 = VL_SHIFTRS_III(32,32,32, 
                                                    (VL_GTS_III(32, 0U, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__ymin)
                                                      ? 0U
                                                      : 
                                                     (VL_LTS_III(32, 0x3bc00000U, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__ymin)
                                                       ? 0x3bc00000U
                                                       : vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__ymin)), 0x00000016U);
    __VdfgRegularize_h6e95ff9d_0_10 = VL_SHIFTRS_III(32,32,32, 
                                                     (VL_GTS_III(32, 0U, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__ymax)
                                                       ? 0U
                                                       : 
                                                      (VL_LTS_III(32, 0x3bc00000U, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__ymax)
                                                        ? 0x3bc00000U
                                                        : vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__ymax)), 0x00000016U);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy01 
        = ember_top__DOT__u_rtr__DOT__u_setup__DOT____VdfgRegularize_hede74ea3_0_2;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy10_ 
        = ember_top__DOT__u_rtr__DOT__u_setup__DOT____VdfgRegularize_hede74ea3_0_2;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dx12 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__dx12;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dy12 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__dy12;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dx20 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__dx20;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x_lo_i 
        = (VL_GTS_III(32, 0U, __VdfgRegularize_h6e95ff9d_0_7)
            ? 0U : (0x0000ffffU & __VdfgRegularize_h6e95ff9d_0_7));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x_hi_i 
        = ((0x0000013fU < __VdfgRegularize_h6e95ff9d_0_8)
            ? 0U : (VL_GTS_III(32, 0U, __VdfgRegularize_h6e95ff9d_0_8)
                     ? 0U : (0x0000ffffU & __VdfgRegularize_h6e95ff9d_0_8)));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__dx01 = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx01;
    VL_EXTENDS_WQ(66,33, __Vtemp_11, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx10_);
    __Vtemp_12[0U] = __Vtemp_11[0U];
    __Vtemp_12[1U] = __Vtemp_11[1U];
    __Vtemp_12[2U] = (3U & __Vtemp_11[2U]);
    VL_EXTENDS_WQ(66,33, __Vtemp_14, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy20_);
    __Vtemp_15[0U] = __Vtemp_14[0U];
    __Vtemp_15[1U] = __Vtemp_14[1U];
    __Vtemp_15[2U] = (3U & __Vtemp_14[2U]);
    VL_MULS_WWW(66, __Vtemp_16, __Vtemp_12, __Vtemp_15);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__p1[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__p1[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__p1[2U] 
        = (3U & __Vtemp_16[2U]);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dy20 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__dy20;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__iwC 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__iwC;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y_lo_i 
        = (VL_GTS_III(32, 0U, __VdfgRegularize_h6e95ff9d_0_9)
            ? 0U : (0x0000ffffU & __VdfgRegularize_h6e95ff9d_0_9));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y_hi_i 
        = ((0x000000efU < __VdfgRegularize_h6e95ff9d_0_10)
            ? 0U : (VL_GTS_III(32, 0U, __VdfgRegularize_h6e95ff9d_0_10)
                     ? 0U : (0x0000ffffU & __VdfgRegularize_h6e95ff9d_0_10)));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__dy01 = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy01;
    VL_EXTENDS_WQ(66,33, __Vtemp_19, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy10_);
    __Vtemp_20[0U] = __Vtemp_19[0U];
    __Vtemp_20[1U] = __Vtemp_19[1U];
    __Vtemp_20[2U] = (3U & __Vtemp_19[2U]);
    VL_EXTENDS_WQ(66,33, __Vtemp_22, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx20_);
    __Vtemp_23[0U] = __Vtemp_22[0U];
    __Vtemp_23[1U] = __Vtemp_22[1U];
    __Vtemp_23[2U] = (3U & __Vtemp_22[2U]);
    VL_MULS_WWW(66, __Vtemp_24, __Vtemp_20, __Vtemp_23);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__p2[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__p2[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__p2[2U] 
        = (3U & __Vtemp_24[2U]);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__x_lo_i = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x_lo_i;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__x_hi_i = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x_hi_i;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dx01 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__dx01;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__y_lo_i = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y_lo_i;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__y_hi_i = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y_hi_i;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__dy01 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__dy01;
    VL_EXTENDS_WW(67,66, __Vtemp_26, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__p1);
    VL_EXTENDS_WW(67,66, __Vtemp_27, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__p2);
    VL_SUB_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__area[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__area[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__area[2U] 
        = (7U & __Vtemp_28[2U]);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__x_lo_i 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__x_lo_i;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__x_hi_i 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__x_hi_i;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__y_lo_i 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__y_lo_i;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__y_hi_i 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__y_hi_i;
    __Vtemp_29[0U] = 0U;
    __Vtemp_29[1U] = 0U;
    __Vtemp_29[2U] = 0U;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__cull 
        = VL_GTES_IWW(67, __Vtemp_29, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__area);
    if ((0U == ((vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__area[0U] 
                 | vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__area[1U]) 
                | vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__area[2U]))) {
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__den[0U] = 1U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__den[1U] = 0U;
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__den[2U] = 0U;
    } else {
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__den[0U] 
            = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__area[0U];
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__den[1U] 
            = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__area[1U];
        vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__den[2U] 
            = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__area[2U];
    }
    vlSelfRef.ember_top__DOT__u_rtr__DOT__cull = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__cull;
    __VdfgRegularize_h6e95ff9d_0_4[0U] = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__den[0U];
    __VdfgRegularize_h6e95ff9d_0_4[1U] = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__den[1U];
    __VdfgRegularize_h6e95ff9d_0_4[2U] = (((IData)(
                                                   (0x0007ffffffffffffULL 
                                                    & (- (QData)((IData)(
                                                                         (1U 
                                                                          & (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__den[2U] 
                                                                             >> 2U))))))) 
                                           << 3U) | vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__den[2U]);
    __VdfgRegularize_h6e95ff9d_0_4[3U] = (((IData)(
                                                   (0x0007ffffffffffffULL 
                                                    & (- (QData)((IData)(
                                                                         (1U 
                                                                          & (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__den[2U] 
                                                                             >> 2U))))))) 
                                           >> 0x0000001dU) 
                                          | ((IData)(
                                                     ((0x0007ffffffffffffULL 
                                                       & (- (QData)((IData)(
                                                                            (1U 
                                                                             & (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__den[2U] 
                                                                                >> 2U)))))) 
                                                      >> 0x00000020U)) 
                                             << 3U));
    VL_EXTENDS_WQ(96,33, __Vtemp_35, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy20_);
    VL_MULS_WWW(96, __Vtemp_36, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__r10, __Vtemp_35);
    VL_EXTENDS_WQ(96,33, __Vtemp_37, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy10_);
    VL_MULS_WWW(96, __Vtemp_38, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__r20, __Vtemp_37);
    VL_SUB_W(3, __Vtemp_39, __Vtemp_36, __Vtemp_38);
    VL_EXTENDS_WW(118,96, __Vtemp_40, __Vtemp_39);
    VL_SHIFTL_WWI(118,118,32, __Vtemp_41, __Vtemp_40, 0x00000016U);
    __Vtemp_42[0U] = __Vtemp_41[0U];
    __Vtemp_42[1U] = __Vtemp_41[1U];
    __Vtemp_42[2U] = __Vtemp_41[2U];
    __Vtemp_42[3U] = (0x003fffffU & __Vtemp_41[3U]);
    VL_DIVS_WWW(118, __Vtemp_43, __Vtemp_42, __VdfgRegularize_h6e95ff9d_0_4);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__rA 
        = (((QData)((IData)(__Vtemp_43[1U])) << 0x00000020U) 
           | (QData)((IData)(__Vtemp_43[0U])));
    VL_EXTENDS_WQ(96,33, __Vtemp_47, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx10_);
    VL_MULS_WWW(96, __Vtemp_48, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__r20, __Vtemp_47);
    VL_EXTENDS_WQ(96,33, __Vtemp_49, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx20_);
    VL_MULS_WWW(96, __Vtemp_50, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__r10, __Vtemp_49);
    VL_SUB_W(3, __Vtemp_51, __Vtemp_48, __Vtemp_50);
    VL_EXTENDS_WW(118,96, __Vtemp_52, __Vtemp_51);
    VL_SHIFTL_WWI(118,118,32, __Vtemp_53, __Vtemp_52, 0x00000016U);
    __Vtemp_54[0U] = __Vtemp_53[0U];
    __Vtemp_54[1U] = __Vtemp_53[1U];
    __Vtemp_54[2U] = __Vtemp_53[2U];
    __Vtemp_54[3U] = (0x003fffffU & __Vtemp_53[3U]);
    VL_DIVS_WWW(118, __Vtemp_55, __Vtemp_54, __VdfgRegularize_h6e95ff9d_0_4);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__rB 
        = (((QData)((IData)(__Vtemp_55[1U])) << 0x00000020U) 
           | (QData)((IData)(__Vtemp_55[0U])));
    VL_EXTENDS_WQ(96,33, __Vtemp_59, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy20_);
    VL_MULS_WWW(96, __Vtemp_60, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__g10, __Vtemp_59);
    VL_EXTENDS_WQ(96,33, __Vtemp_61, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy10_);
    VL_MULS_WWW(96, __Vtemp_62, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__g20, __Vtemp_61);
    VL_SUB_W(3, __Vtemp_63, __Vtemp_60, __Vtemp_62);
    VL_EXTENDS_WW(118,96, __Vtemp_64, __Vtemp_63);
    VL_SHIFTL_WWI(118,118,32, __Vtemp_65, __Vtemp_64, 0x00000016U);
    __Vtemp_66[0U] = __Vtemp_65[0U];
    __Vtemp_66[1U] = __Vtemp_65[1U];
    __Vtemp_66[2U] = __Vtemp_65[2U];
    __Vtemp_66[3U] = (0x003fffffU & __Vtemp_65[3U]);
    VL_DIVS_WWW(118, __Vtemp_67, __Vtemp_66, __VdfgRegularize_h6e95ff9d_0_4);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__gA 
        = (((QData)((IData)(__Vtemp_67[1U])) << 0x00000020U) 
           | (QData)((IData)(__Vtemp_67[0U])));
    VL_EXTENDS_WQ(96,33, __Vtemp_71, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx10_);
    VL_MULS_WWW(96, __Vtemp_72, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__g20, __Vtemp_71);
    VL_EXTENDS_WQ(96,33, __Vtemp_73, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx20_);
    VL_MULS_WWW(96, __Vtemp_74, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__g10, __Vtemp_73);
    VL_SUB_W(3, __Vtemp_75, __Vtemp_72, __Vtemp_74);
    VL_EXTENDS_WW(118,96, __Vtemp_76, __Vtemp_75);
    VL_SHIFTL_WWI(118,118,32, __Vtemp_77, __Vtemp_76, 0x00000016U);
    __Vtemp_78[0U] = __Vtemp_77[0U];
    __Vtemp_78[1U] = __Vtemp_77[1U];
    __Vtemp_78[2U] = __Vtemp_77[2U];
    __Vtemp_78[3U] = (0x003fffffU & __Vtemp_77[3U]);
    VL_DIVS_WWW(118, __Vtemp_79, __Vtemp_78, __VdfgRegularize_h6e95ff9d_0_4);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__gB 
        = (((QData)((IData)(__Vtemp_79[1U])) << 0x00000020U) 
           | (QData)((IData)(__Vtemp_79[0U])));
    VL_EXTENDS_WQ(96,33, __Vtemp_83, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy20_);
    VL_MULS_WWW(96, __Vtemp_84, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__b10, __Vtemp_83);
    VL_EXTENDS_WQ(96,33, __Vtemp_85, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy10_);
    VL_MULS_WWW(96, __Vtemp_86, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__b20, __Vtemp_85);
    VL_SUB_W(3, __Vtemp_87, __Vtemp_84, __Vtemp_86);
    VL_EXTENDS_WW(118,96, __Vtemp_88, __Vtemp_87);
    VL_SHIFTL_WWI(118,118,32, __Vtemp_89, __Vtemp_88, 0x00000016U);
    __Vtemp_90[0U] = __Vtemp_89[0U];
    __Vtemp_90[1U] = __Vtemp_89[1U];
    __Vtemp_90[2U] = __Vtemp_89[2U];
    __Vtemp_90[3U] = (0x003fffffU & __Vtemp_89[3U]);
    VL_DIVS_WWW(118, __Vtemp_91, __Vtemp_90, __VdfgRegularize_h6e95ff9d_0_4);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__bA 
        = (((QData)((IData)(__Vtemp_91[1U])) << 0x00000020U) 
           | (QData)((IData)(__Vtemp_91[0U])));
    VL_EXTENDS_WQ(96,33, __Vtemp_95, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx10_);
    VL_MULS_WWW(96, __Vtemp_96, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__b20, __Vtemp_95);
    VL_EXTENDS_WQ(96,33, __Vtemp_97, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx20_);
    VL_MULS_WWW(96, __Vtemp_98, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__b10, __Vtemp_97);
    VL_SUB_W(3, __Vtemp_99, __Vtemp_96, __Vtemp_98);
    VL_EXTENDS_WW(118,96, __Vtemp_100, __Vtemp_99);
    VL_SHIFTL_WWI(118,118,32, __Vtemp_101, __Vtemp_100, 0x00000016U);
    __Vtemp_102[0U] = __Vtemp_101[0U];
    __Vtemp_102[1U] = __Vtemp_101[1U];
    __Vtemp_102[2U] = __Vtemp_101[2U];
    __Vtemp_102[3U] = (0x003fffffU & __Vtemp_101[3U]);
    VL_DIVS_WWW(118, __Vtemp_103, __Vtemp_102, __VdfgRegularize_h6e95ff9d_0_4);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__bB 
        = (((QData)((IData)(__Vtemp_103[1U])) << 0x00000020U) 
           | (QData)((IData)(__Vtemp_103[0U])));
    VL_EXTENDS_WQ(96,33, __Vtemp_107, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy20_);
    VL_MULS_WWW(96, __Vtemp_108, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__z10, __Vtemp_107);
    VL_EXTENDS_WQ(96,33, __Vtemp_109, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy10_);
    VL_MULS_WWW(96, __Vtemp_110, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__z20, __Vtemp_109);
    VL_SUB_W(3, __Vtemp_111, __Vtemp_108, __Vtemp_110);
    VL_EXTENDS_WW(118,96, __Vtemp_112, __Vtemp_111);
    VL_SHIFTL_WWI(118,118,32, __Vtemp_113, __Vtemp_112, 0x00000016U);
    __Vtemp_114[0U] = __Vtemp_113[0U];
    __Vtemp_114[1U] = __Vtemp_113[1U];
    __Vtemp_114[2U] = __Vtemp_113[2U];
    __Vtemp_114[3U] = (0x003fffffU & __Vtemp_113[3U]);
    VL_DIVS_WWW(118, __Vtemp_115, __Vtemp_114, __VdfgRegularize_h6e95ff9d_0_4);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__zA 
        = (((QData)((IData)(__Vtemp_115[1U])) << 0x00000020U) 
           | (QData)((IData)(__Vtemp_115[0U])));
    VL_EXTENDS_WQ(96,33, __Vtemp_119, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx10_);
    VL_MULS_WWW(96, __Vtemp_120, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__z20, __Vtemp_119);
    VL_EXTENDS_WQ(96,33, __Vtemp_121, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx20_);
    VL_MULS_WWW(96, __Vtemp_122, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__z10, __Vtemp_121);
    VL_SUB_W(3, __Vtemp_123, __Vtemp_120, __Vtemp_122);
    VL_EXTENDS_WW(118,96, __Vtemp_124, __Vtemp_123);
    VL_SHIFTL_WWI(118,118,32, __Vtemp_125, __Vtemp_124, 0x00000016U);
    __Vtemp_126[0U] = __Vtemp_125[0U];
    __Vtemp_126[1U] = __Vtemp_125[1U];
    __Vtemp_126[2U] = __Vtemp_125[2U];
    __Vtemp_126[3U] = (0x003fffffU & __Vtemp_125[3U]);
    VL_DIVS_WWW(118, __Vtemp_127, __Vtemp_126, __VdfgRegularize_h6e95ff9d_0_4);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__zB 
        = (((QData)((IData)(__Vtemp_127[1U])) << 0x00000020U) 
           | (QData)((IData)(__Vtemp_127[0U])));
    VL_EXTENDS_WQ(96,33, __Vtemp_131, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy20_);
    VL_MULS_WWW(96, __Vtemp_132, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u10, __Vtemp_131);
    VL_EXTENDS_WQ(96,33, __Vtemp_133, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy10_);
    VL_MULS_WWW(96, __Vtemp_134, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u20, __Vtemp_133);
    VL_SUB_W(3, __Vtemp_135, __Vtemp_132, __Vtemp_134);
    VL_EXTENDS_WW(118,96, __Vtemp_136, __Vtemp_135);
    VL_SHIFTL_WWI(118,118,32, __Vtemp_137, __Vtemp_136, 0x00000016U);
    __Vtemp_138[0U] = __Vtemp_137[0U];
    __Vtemp_138[1U] = __Vtemp_137[1U];
    __Vtemp_138[2U] = __Vtemp_137[2U];
    __Vtemp_138[3U] = (0x003fffffU & __Vtemp_137[3U]);
    VL_DIVS_WWW(118, __Vtemp_139, __Vtemp_138, __VdfgRegularize_h6e95ff9d_0_4);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__uA 
        = (((QData)((IData)(__Vtemp_139[1U])) << 0x00000020U) 
           | (QData)((IData)(__Vtemp_139[0U])));
    VL_EXTENDS_WQ(96,33, __Vtemp_143, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx10_);
    VL_MULS_WWW(96, __Vtemp_144, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u20, __Vtemp_143);
    VL_EXTENDS_WQ(96,33, __Vtemp_145, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx20_);
    VL_MULS_WWW(96, __Vtemp_146, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u10, __Vtemp_145);
    VL_SUB_W(3, __Vtemp_147, __Vtemp_144, __Vtemp_146);
    VL_EXTENDS_WW(118,96, __Vtemp_148, __Vtemp_147);
    VL_SHIFTL_WWI(118,118,32, __Vtemp_149, __Vtemp_148, 0x00000016U);
    __Vtemp_150[0U] = __Vtemp_149[0U];
    __Vtemp_150[1U] = __Vtemp_149[1U];
    __Vtemp_150[2U] = __Vtemp_149[2U];
    __Vtemp_150[3U] = (0x003fffffU & __Vtemp_149[3U]);
    VL_DIVS_WWW(118, __Vtemp_151, __Vtemp_150, __VdfgRegularize_h6e95ff9d_0_4);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__uB 
        = (((QData)((IData)(__Vtemp_151[1U])) << 0x00000020U) 
           | (QData)((IData)(__Vtemp_151[0U])));
    VL_EXTENDS_WQ(96,33, __Vtemp_155, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy20_);
    VL_MULS_WWW(96, __Vtemp_156, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v10, __Vtemp_155);
    VL_EXTENDS_WQ(96,33, __Vtemp_157, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dy10_);
    VL_MULS_WWW(96, __Vtemp_158, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v20, __Vtemp_157);
    VL_SUB_W(3, __Vtemp_159, __Vtemp_156, __Vtemp_158);
    VL_EXTENDS_WW(118,96, __Vtemp_160, __Vtemp_159);
    VL_SHIFTL_WWI(118,118,32, __Vtemp_161, __Vtemp_160, 0x00000016U);
    __Vtemp_162[0U] = __Vtemp_161[0U];
    __Vtemp_162[1U] = __Vtemp_161[1U];
    __Vtemp_162[2U] = __Vtemp_161[2U];
    __Vtemp_162[3U] = (0x003fffffU & __Vtemp_161[3U]);
    VL_DIVS_WWW(118, __Vtemp_163, __Vtemp_162, __VdfgRegularize_h6e95ff9d_0_4);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__vA 
        = (((QData)((IData)(__Vtemp_163[1U])) << 0x00000020U) 
           | (QData)((IData)(__Vtemp_163[0U])));
    VL_EXTENDS_WQ(96,33, __Vtemp_167, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx10_);
    VL_MULS_WWW(96, __Vtemp_168, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v20, __Vtemp_167);
    VL_EXTENDS_WQ(96,33, __Vtemp_169, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__dx20_);
    VL_MULS_WWW(96, __Vtemp_170, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v10, __Vtemp_169);
    VL_SUB_W(3, __Vtemp_171, __Vtemp_168, __Vtemp_170);
    VL_EXTENDS_WW(118,96, __Vtemp_172, __Vtemp_171);
    VL_SHIFTL_WWI(118,118,32, __Vtemp_173, __Vtemp_172, 0x00000016U);
    __Vtemp_174[0U] = __Vtemp_173[0U];
    __Vtemp_174[1U] = __Vtemp_173[1U];
    __Vtemp_174[2U] = __Vtemp_173[2U];
    __Vtemp_174[3U] = (0x003fffffU & __Vtemp_173[3U]);
    VL_DIVS_WWW(118, __Vtemp_175, __Vtemp_174, __VdfgRegularize_h6e95ff9d_0_4);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__vB 
        = (((QData)((IData)(__Vtemp_175[1U])) << 0x00000020U) 
           | (QData)((IData)(__Vtemp_175[0U])));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__rA = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__rA;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__rB = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__rB;
    VL_EXTENDS_WQ(96,64, __Vtemp_177, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__rA);
    VL_EXTENDS_WI(96,32, __Vtemp_178, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x0);
    VL_MULS_WWW(96, __Vtemp_179, __Vtemp_177, __Vtemp_178);
    VL_EXTENDS_WQ(96,64, __Vtemp_180, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__rB);
    VL_EXTENDS_WI(96,32, __Vtemp_181, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y0);
    VL_MULS_WWW(96, __Vtemp_182, __Vtemp_180, __Vtemp_181);
    VL_ADD_W(3, __Vtemp_183, __Vtemp_179, __Vtemp_182);
    VL_SHIFTRS_WWI(96,96,32, __Vtemp_184, __Vtemp_183, 0x00000016U);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__rC 
        = ((((QData)((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__r0e[1U])) 
             << 0x00000020U) | (QData)((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__r0e[0U]))) 
           - (((QData)((IData)(__Vtemp_184[1U])) << 0x00000020U) 
              | (QData)((IData)(__Vtemp_184[0U]))));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__gA = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__gA;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__gB = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__gB;
    VL_EXTENDS_WQ(96,64, __Vtemp_185, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__gA);
    VL_EXTENDS_WI(96,32, __Vtemp_186, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x0);
    VL_MULS_WWW(96, __Vtemp_187, __Vtemp_185, __Vtemp_186);
    VL_EXTENDS_WQ(96,64, __Vtemp_188, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__gB);
    VL_EXTENDS_WI(96,32, __Vtemp_189, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y0);
    VL_MULS_WWW(96, __Vtemp_190, __Vtemp_188, __Vtemp_189);
    VL_ADD_W(3, __Vtemp_191, __Vtemp_187, __Vtemp_190);
    VL_SHIFTRS_WWI(96,96,32, __Vtemp_192, __Vtemp_191, 0x00000016U);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__gC 
        = ((((QData)((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__g0e[1U])) 
             << 0x00000020U) | (QData)((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__g0e[0U]))) 
           - (((QData)((IData)(__Vtemp_192[1U])) << 0x00000020U) 
              | (QData)((IData)(__Vtemp_192[0U]))));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__bA = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__bA;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__bB = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__bB;
    VL_EXTENDS_WQ(96,64, __Vtemp_193, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__bA);
    VL_EXTENDS_WI(96,32, __Vtemp_194, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x0);
    VL_MULS_WWW(96, __Vtemp_195, __Vtemp_193, __Vtemp_194);
    VL_EXTENDS_WQ(96,64, __Vtemp_196, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__bB);
    VL_EXTENDS_WI(96,32, __Vtemp_197, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y0);
    VL_MULS_WWW(96, __Vtemp_198, __Vtemp_196, __Vtemp_197);
    VL_ADD_W(3, __Vtemp_199, __Vtemp_195, __Vtemp_198);
    VL_SHIFTRS_WWI(96,96,32, __Vtemp_200, __Vtemp_199, 0x00000016U);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__bC 
        = ((((QData)((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__b0e[1U])) 
             << 0x00000020U) | (QData)((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__b0e[0U]))) 
           - (((QData)((IData)(__Vtemp_200[1U])) << 0x00000020U) 
              | (QData)((IData)(__Vtemp_200[0U]))));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__zA = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__zA;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__zB = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__zB;
    VL_EXTENDS_WQ(96,64, __Vtemp_201, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__zA);
    VL_EXTENDS_WI(96,32, __Vtemp_202, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x0);
    VL_MULS_WWW(96, __Vtemp_203, __Vtemp_201, __Vtemp_202);
    VL_EXTENDS_WQ(96,64, __Vtemp_204, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__zB);
    VL_EXTENDS_WI(96,32, __Vtemp_205, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y0);
    VL_MULS_WWW(96, __Vtemp_206, __Vtemp_204, __Vtemp_205);
    VL_ADD_W(3, __Vtemp_207, __Vtemp_203, __Vtemp_206);
    VL_SHIFTRS_WWI(96,96,32, __Vtemp_208, __Vtemp_207, 0x00000016U);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__zC 
        = ((((QData)((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__z0e[1U])) 
             << 0x00000020U) | (QData)((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__z0e[0U]))) 
           - (((QData)((IData)(__Vtemp_208[1U])) << 0x00000020U) 
              | (QData)((IData)(__Vtemp_208[0U]))));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__uA = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__uA;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__uB = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__uB;
    VL_EXTENDS_WQ(96,64, __Vtemp_209, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__uA);
    VL_EXTENDS_WI(96,32, __Vtemp_210, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x0);
    VL_MULS_WWW(96, __Vtemp_211, __Vtemp_209, __Vtemp_210);
    VL_EXTENDS_WQ(96,64, __Vtemp_212, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__uB);
    VL_EXTENDS_WI(96,32, __Vtemp_213, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y0);
    VL_MULS_WWW(96, __Vtemp_214, __Vtemp_212, __Vtemp_213);
    VL_ADD_W(3, __Vtemp_215, __Vtemp_211, __Vtemp_214);
    VL_SHIFTRS_WWI(96,96,32, __Vtemp_216, __Vtemp_215, 0x00000016U);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__uC 
        = ((((QData)((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u0e[1U])) 
             << 0x00000020U) | (QData)((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__u0e[0U]))) 
           - (((QData)((IData)(__Vtemp_216[1U])) << 0x00000020U) 
              | (QData)((IData)(__Vtemp_216[0U]))));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__vA = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__vA;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__vB = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__vB;
    VL_EXTENDS_WQ(96,64, __Vtemp_217, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__vA);
    VL_EXTENDS_WI(96,32, __Vtemp_218, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__x0);
    VL_MULS_WWW(96, __Vtemp_219, __Vtemp_217, __Vtemp_218);
    VL_EXTENDS_WQ(96,64, __Vtemp_220, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__vB);
    VL_EXTENDS_WI(96,32, __Vtemp_221, vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__y0);
    VL_MULS_WWW(96, __Vtemp_222, __Vtemp_220, __Vtemp_221);
    VL_ADD_W(3, __Vtemp_223, __Vtemp_219, __Vtemp_222);
    VL_SHIFTRS_WWI(96,96,32, __Vtemp_224, __Vtemp_223, 0x00000016U);
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__vC 
        = ((((QData)((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v0e[1U])) 
             << 0x00000020U) | (QData)((IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__v0e[0U]))) 
           - (((QData)((IData)(__Vtemp_224[1U])) << 0x00000020U) 
              | (QData)((IData)(__Vtemp_224[0U]))));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__rA 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__rA;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__rB 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__rB;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__rC = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__rC;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__gA 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__gA;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__gB 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__gB;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__gC = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__gC;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__bA 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__bA;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__bB 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__bB;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__bC = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__bC;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__zA 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__zA;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__zB 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__zB;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__zC = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__zC;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__uA 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__uA;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__uB 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__uB;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__uC = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__uC;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__vA 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vA;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__vB 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vB;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__vC = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_setup__DOT__vC;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__rC 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__rC;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__gC 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__gC;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__bC 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__bC;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__zC 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__zC;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__uC 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__uC;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__vC 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__vC;
}

void Vtop___024root___nba_sequent__TOP__14(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__14\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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

void Vtop___024root___nba_sequent__TOP__15(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__15\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_0;
    ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_0 = 0;
    CData/*0:0*/ ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_3;
    ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_3 = 0;
    CData/*0:0*/ ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_6;
    ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_6 = 0;
    CData/*0:0*/ ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_10;
    ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_10 = 0;
    // Body
    if (vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__ar_accept) {
        vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_r 
            = ((QData)((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__rd_data)) 
               << 2U);
    }
    if (vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__wr_fire) {
        vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__reg_wr_en = 1U;
        vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__reg_wdata 
            = (IData)((vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__w_q 
                       >> 4U));
        vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__reg_be 
            = (0x0000000fU & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__w_q));
        vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__reg_addr 
            = (0x00000fffU & (IData)((vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__aw_q 
                                      >> 3U)));
    } else {
        vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__reg_wr_en = 0U;
    }
    vlSelfRef.ember_top__DOT__u_cp__DOT__s_r = vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_r;
    vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wr_en 
        = vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__reg_wr_en;
    vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata 
        = vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__reg_wdata;
    vlSelfRef.ember_top__DOT__u_cp__DOT__reg_be = vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__reg_be;
    vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr = vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__reg_addr;
    vlSelfRef.ember_top__DOT__c_r = vlSelfRef.ember_top__DOT__u_cp__DOT__s_r;
    vlSelfRef.ember_top__DOT__u_cp__DOT__blit_csr_wdata 
        = vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata;
    vlSelfRef.ember_top__DOT__u_cp__DOT__core_csr_wdata 
        = vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata;
    vlSelfRef.ember_top__DOT__u_cp__DOT__gsx_csr_wdata 
        = vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata;
    vlSelfRef.ember_top__DOT__u_cp__DOT__tu_csr_wdata 
        = vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata;
    ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_0 
        = ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wr_en) 
           & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_be));
    vlSelfRef.ember_top__DOT__u_cp__DOT__up_push = 
        ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wr_en) 
         & ((0x0010U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
            & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_be)));
    vlSelfRef.ember_top__DOT__u_cp__DOT__core_csr_addr 
        = (0x0050U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr));
    vlSelfRef.ember_top__DOT__u_cp__DOT__core_csr_zone 
        = ((0x004cU == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
           | (0x0050U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)));
    ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_3 
        = ((0x002cU == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
           | (0x0030U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)));
    ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_6 
        = ((0x0040U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
           | (0x0048U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)));
    ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_10 
        = ((0x0060U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
           | (0x0064U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)));
    vlSelfRef.ember_top__DOT__u_xbar__DOT__c_r = vlSelfRef.ember_top__DOT__c_r;
    vlSelfRef.ember_top__DOT__blit_csr_wdata = vlSelfRef.ember_top__DOT__u_cp__DOT__blit_csr_wdata;
    vlSelfRef.ember_top__DOT__core_csr_wdata = vlSelfRef.ember_top__DOT__u_cp__DOT__core_csr_wdata;
    vlSelfRef.ember_top__DOT__gsx_csr_wdata = vlSelfRef.ember_top__DOT__u_cp__DOT__gsx_csr_wdata;
    vlSelfRef.ember_top__DOT__tu_csr_wdata = vlSelfRef.ember_top__DOT__u_cp__DOT__tu_csr_wdata;
    vlSelfRef.ember_top__DOT__u_cp__DOT__rtr_kick = 
        ((IData)(ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_0) 
         & ((0x0020U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
            & vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata));
    vlSelfRef.ember_top__DOT__u_cp__DOT__blit_kick 
        = ((IData)(ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_0) 
           & ((0x0034U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
              & vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata));
    vlSelfRef.ember_top__DOT__u_cp__DOT__gsx_kick = 
        ((IData)(ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_0) 
         & ((0x0044U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
            & vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata));
    vlSelfRef.ember_top__DOT__u_cp__DOT__core_kick 
        = ((IData)(ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_0) 
           & ((0x0054U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
              & vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata));
    vlSelfRef.ember_top__DOT__u_cp__DOT__tu_kick = 
        ((IData)(ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_0) 
         & ((0x0068U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
            & vlSelfRef.ember_top__DOT__u_cp__DOT__reg_wdata));
    vlSelfRef.ember_top__DOT__core_csr_addr = vlSelfRef.ember_top__DOT__u_cp__DOT__core_csr_addr;
    vlSelfRef.ember_top__DOT__u_cp__DOT__core_csr_we 
        = ((IData)(ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_0) 
           & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__core_csr_zone));
    vlSelfRef.ember_top__DOT__u_cp__DOT__blit_csr_addr 
        = (((IData)(ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_3) 
            << 1U) | ((0x0028U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
                      | (0x0030U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr))));
    vlSelfRef.ember_top__DOT__u_cp__DOT__blit_csr_zone 
        = ((0x0024U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
           | ((0x0028U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
              | (IData)(ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_3)));
    vlSelfRef.ember_top__DOT__u_cp__DOT__gsx_csr_addr 
        = (((IData)(ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_6) 
            << 1U) | ((0x003cU == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
                      | (0x0048U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr))));
    vlSelfRef.ember_top__DOT__u_cp__DOT__gsx_csr_zone 
        = ((0x0038U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
           | ((0x003cU == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
              | (IData)(ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_6)));
    vlSelfRef.ember_top__DOT__u_cp__DOT__tu_csr_addr 
        = (((IData)(ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_10) 
            << 1U) | ((0x005cU == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
                      | (0x0064U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr))));
    vlSelfRef.ember_top__DOT__u_cp__DOT__tu_csr_zone 
        = ((0x0058U == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
           | ((0x005cU == (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__reg_addr)) 
              | (IData)(ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_10)));
    vlSelfRef.ember_top__DOT__u_blit__DOT__csr_wdata 
        = vlSelfRef.ember_top__DOT__blit_csr_wdata;
    vlSelfRef.ember_top__DOT__u_core__DOT__csr_wdata 
        = vlSelfRef.ember_top__DOT__core_csr_wdata;
    vlSelfRef.ember_top__DOT__u_gsx__DOT__csr_wdata 
        = vlSelfRef.ember_top__DOT__gsx_csr_wdata;
    vlSelfRef.ember_top__DOT__rtr_kick = vlSelfRef.ember_top__DOT__u_cp__DOT__rtr_kick;
    vlSelfRef.ember_top__DOT__blit_kick = vlSelfRef.ember_top__DOT__u_cp__DOT__blit_kick;
    vlSelfRef.ember_top__DOT__gsx_kick = vlSelfRef.ember_top__DOT__u_cp__DOT__gsx_kick;
    vlSelfRef.ember_top__DOT__core_kick = vlSelfRef.ember_top__DOT__u_cp__DOT__core_kick;
    vlSelfRef.ember_top__DOT__tu_kick = vlSelfRef.ember_top__DOT__u_cp__DOT__tu_kick;
    vlSelfRef.ember_top__DOT__u_core__DOT__csr_addr 
        = vlSelfRef.ember_top__DOT__core_csr_addr;
    vlSelfRef.ember_top__DOT__core_csr_we = vlSelfRef.ember_top__DOT__u_cp__DOT__core_csr_we;
    vlSelfRef.ember_top__DOT__blit_csr_addr = vlSelfRef.ember_top__DOT__u_cp__DOT__blit_csr_addr;
    vlSelfRef.ember_top__DOT__u_cp__DOT__blit_csr_we 
        = ((IData)(ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_0) 
           & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__blit_csr_zone));
    vlSelfRef.ember_top__DOT__gsx_csr_addr = vlSelfRef.ember_top__DOT__u_cp__DOT__gsx_csr_addr;
    vlSelfRef.ember_top__DOT__u_cp__DOT__gsx_csr_we 
        = ((IData)(ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_0) 
           & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__gsx_csr_zone));
    vlSelfRef.ember_top__DOT__tu_csr_addr = vlSelfRef.ember_top__DOT__u_cp__DOT__tu_csr_addr;
    vlSelfRef.ember_top__DOT__u_cp__DOT__tu_csr_we 
        = ((IData)(ember_top__DOT__u_cp__DOT____VdfgRegularize_hfef97f01_0_0) 
           & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__tu_csr_zone));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__kick = vlSelfRef.ember_top__DOT__rtr_kick;
    vlSelfRef.ember_top__DOT__u_blit__DOT__kick = vlSelfRef.ember_top__DOT__blit_kick;
    vlSelfRef.ember_top__DOT__u_gsx__DOT__kick = vlSelfRef.ember_top__DOT__gsx_kick;
    vlSelfRef.ember_top__DOT__u_core__DOT__kick = vlSelfRef.ember_top__DOT__core_kick;
    vlSelfRef.ember_top__DOT__u_core__DOT__csr_we = vlSelfRef.ember_top__DOT__core_csr_we;
    vlSelfRef.ember_top__DOT__u_blit__DOT__csr_addr 
        = vlSelfRef.ember_top__DOT__blit_csr_addr;
    vlSelfRef.ember_top__DOT__blit_csr_we = vlSelfRef.ember_top__DOT__u_cp__DOT__blit_csr_we;
    vlSelfRef.ember_top__DOT__u_gsx__DOT__csr_addr 
        = vlSelfRef.ember_top__DOT__gsx_csr_addr;
    vlSelfRef.ember_top__DOT__gsx_csr_we = vlSelfRef.ember_top__DOT__u_cp__DOT__gsx_csr_we;
    vlSelfRef.ember_top__DOT__tu_csr_we = vlSelfRef.ember_top__DOT__u_cp__DOT__tu_csr_we;
    vlSelfRef.ember_top__DOT__u_core__DOT__csr_code_we 
        = ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__csr_we) 
           & (0U == (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__csr_addr)));
    vlSelfRef.ember_top__DOT__u_core__DOT__csr_nblk_we 
        = ((IData)(vlSelfRef.ember_top__DOT__u_core__DOT__csr_we) 
           & (1U == (IData)(vlSelfRef.ember_top__DOT__u_core__DOT__csr_addr)));
    vlSelfRef.ember_top__DOT__u_blit__DOT__csr_we = vlSelfRef.ember_top__DOT__blit_csr_we;
    vlSelfRef.ember_top__DOT__u_gsx__DOT__csr_we = vlSelfRef.ember_top__DOT__gsx_csr_we;
    vlSelfRef.ember_top__DOT__u_gsx__DOT__cfg_we = 
        ((IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__csr_we) 
         & (3U == (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__csr_addr)));
    vlSelfRef.ember_top__DOT__u_gsx__DOT__cfg_cnt_we 
        = ((IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__cfg_we) 
           & (vlSelfRef.ember_top__DOT__u_gsx__DOT__csr_wdata 
              >> 0x0000001fU));
    vlSelfRef.ember_top__DOT__u_gsx__DOT__cfg_mode_we 
        = ((~ (vlSelfRef.ember_top__DOT__u_gsx__DOT__csr_wdata 
               >> 0x0000001fU)) & (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__cfg_we));
}

void Vtop___024root___nba_sequent__TOP__16(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__16\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*7:0*/ __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v0;
    __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v0 = 0;
    CData/*3:0*/ __VdlyDim0__ember_top__DOT__u_tu__DOT__w_regs__v0;
    __VdlyDim0__ember_top__DOT__u_tu__DOT__w_regs__v0 = 0;
    CData/*3:0*/ __VdlyDim1__ember_top__DOT__u_tu__DOT__w_regs__v0;
    __VdlyDim1__ember_top__DOT__u_tu__DOT__w_regs__v0 = 0;
    // Body
    vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk1__DOT__r = 0U;
    while ((0x00000010U > vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk1__DOT__r)) {
        if ((1U & ((IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__w_ld) 
                   >> (0x0000000fU & vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk1__DOT__r)))) {
            vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk1__DOT__unnamedblk2__DOT__c = 0U;
            while ((0x00000010U > vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk1__DOT__unnamedblk2__DOT__c)) {
                __VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v0 
                    = vlSelfRef.ember_top__DOT__u_tu__DOT__wbyte
                    [(0x0000000fU & vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk1__DOT__unnamedblk2__DOT__c)];
                __VdlyDim0__ember_top__DOT__u_tu__DOT__w_regs__v0 
                    = (0x0000000fU & vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk1__DOT__unnamedblk2__DOT__c);
                __VdlyDim1__ember_top__DOT__u_tu__DOT__w_regs__v0 
                    = (0x0000000fU & vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk1__DOT__r);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__w_regs.enqueue(__VdlyVal__ember_top__DOT__u_tu__DOT__w_regs__v0, (IData)(__VdlyDim1__ember_top__DOT__u_tu__DOT__w_regs__v0), __VdlyDim0__ember_top__DOT__u_tu__DOT__w_regs__v0);
                vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk1__DOT__unnamedblk2__DOT__c 
                    = ((IData)(1U) + vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk1__DOT__unnamedblk2__DOT__c);
            }
        }
        vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk1__DOT__r 
            = ((IData)(1U) + vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk1__DOT__r);
    }
    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__w_regs.commit(vlSelfRef.ember_top__DOT__u_tu__DOT__w_regs);
}

void Vtop___024root___nba_sequent__TOP__17(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__17\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ember_top__DOT__u_gsx__DOT__mata_ptr 
        = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__mata_ptr;
    vlSelfRef.ember_top__DOT__u_gsx__DOT__vtx_ptr = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__vtx_ptr;
    vlSelfRef.ember_top__DOT__u_gsx__DOT__col_ptr = vlSelfRef.__Vdly__ember_top__DOT__u_gsx__DOT__col_ptr;
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
    vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_we = vlSelfRef.ember_top__DOT__gsx_gxa_we;
    vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_be = vlSelfRef.ember_top__DOT__gsx_gxa_be;
    vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_wdata 
        = vlSelfRef.ember_top__DOT__gsx_gxa_wdata;
    vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_req 
        = vlSelfRef.ember_top__DOT__gsx_gxa_req;
    vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_widx 
        = (0x0001ffffU & ((vlSelfRef.ember_top__DOT__u_vram__DOT__gxa_addr 
                           - (IData)(0x00001000U)) 
                          >> 2U));
}

void Vtop___024root___nba_sequent__TOP__18(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__18\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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

void Vtop___024root___nba_sequent__TOP__19(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__19\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ember_top__DOT__u_xbar__DOT__d_req_v_r 
        = vlSelfRef.ember_top__DOT__u_xbar__DOT__d_arvalid;
    vlSelfRef.ember_top__DOT__u_xbar__DOT__d_req_v_w 
        = vlSelfRef.ember_top__DOT__u_xbar__DOT__d_awvalid;
}

void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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

void Vtop___024root___nba_comb__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.ember_top__DOT__u_cp__DOT__m_rvalid = vlSelfRef.ember_top__DOT__d_rvalid;
    vlSelfRef.ember_top__DOT__u_cp__DOT__m_bvalid = vlSelfRef.ember_top__DOT__d_bvalid;
    vlSelfRef.ember_top__DOT__u_xbar__DOT__v_awready 
        = vlSelfRef.ember_top__DOT__v_awready;
    vlSelfRef.ember_top__DOT__u_xbar__DOT__v_wready 
        = vlSelfRef.ember_top__DOT__v_wready;
    vlSelfRef.ember_top__DOT__u_cp__DOT__rb_push = vlSelfRef.ember_top__DOT__u_cp__DOT__m_rvalid;
}

void Vtop___024root___nba_comb__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.ember_top__DOT__u_cp__DOT__rb_pop = (
                                                   ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__s_arvalid) 
                                                    & (IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__s_arready)) 
                                                   & (0x0000000000000080ULL 
                                                      == 
                                                      (0x0000000000007ff8ULL 
                                                       & vlSelfRef.ember_top__DOT__u_cp__DOT__s_ar)));
    vlSelfRef.ember_top__DOT__c_arready = vlSelfRef.ember_top__DOT__u_cp__DOT__s_arready;
    vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__rd_addr 
        = ((IData)(vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__ar_accept)
            ? (0x00000fffU & (IData)((vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__s_ar 
                                      >> 3U))) : 0U);
    vlSelfRef.ember_top__DOT__u_xbar__DOT__c_arready 
        = vlSelfRef.ember_top__DOT__c_arready;
    vlSelfRef.ember_top__DOT__u_cp__DOT__rd_addr = vlSelfRef.ember_top__DOT__u_cp__DOT__u_regs__DOT__rd_addr;
}

void Vtop___024root___nba_sequent__TOP__20(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__20\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ember_top__DOT__u_vram__DOT__fpa3_req 
        = vlSelfRef.ember_top__DOT__fpa3_req;
    vlSelfRef.ember_top__DOT__u_vram__DOT__fpa3_widx 
        = (0x0001ffffU & ((vlSelfRef.ember_top__DOT__u_vram__DOT__fpa3_addr 
                           - (IData)(0x00001000U)) 
                          >> 2U));
}

void Vtop___024root___nba_comb__TOP__3(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ember_top__DOT__u_gsx__DOT___unused = 
        (1U & (VL_REDXOR_32(vlSelfRef.ember_top__DOT__u_gsx__DOT__gxa_rdata) 
               | (IData)(vlSelfRef.ember_top__DOT__u_gsx__DOT__f_busy)));
}

void Vtop___024root___nba_comb__TOP__4(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__4\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ember_top__DOT__u_blit__DOT__rdata_lane 
        = (0x0000ffffU & ((2U & vlSelfRef.ember_top__DOT__u_blit__DOT__saddr_q)
                           ? (vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_rdata 
                              >> 0x00000010U) : vlSelfRef.ember_top__DOT__u_blit__DOT__fpa_rdata));
    vlSelfRef.ember_top__DOT__u_blit__DOT__skip_c = 
        ((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__key_en_q) 
         & ((IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__key_color_q) 
            == (IData)(vlSelfRef.ember_top__DOT__u_blit__DOT__rdata_lane)));
}

void Vtop___024root___nba_comb__TOP__5(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__5\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__texel_shift 
        = (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa2_rdata 
           >> (0x00000018U & (vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__tex_addr 
                              << 3U)));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__texel_byte 
        = (0x000000ffU & vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__texel_shift);
}

void Vtop___024root___nba_sequent__TOP__21(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__21\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ember_top__DOT__u_core__DOT__ixa_rdata 
        = vlSelfRef.ember_top__DOT__core_ixa_rdata;
    vlSelfRef.ember_top__DOT__u_core__DOT__cxa_rdata 
        = vlSelfRef.ember_top__DOT__core_cxa_rdata;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__fpa_rdata 
        = vlSelfRef.ember_top__DOT__fpa_rdata;
    vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__fpa_rdata 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__fpa_rdata;
}

void Vtop___024root___nba_sequent__TOP__22(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__22\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ember_top__DOT__u_core__DOT__f_done = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__done;
    vlSelfRef.ember_top__DOT__u_core__DOT__f_y0 = vlSelfRef.ember_top__DOT__u_core__DOT__u_fpu__DOT__y0;
}

void Vtop___024root___nba_sequent__TOP__23(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__23\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_done 
        = vlSelfRef.ember_top__DOT__u_rtr__DOT__u_scan__DOT__done;
}

void Vtop___024root___nba_comb__TOP__6(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__6\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ember_top__DOT__u_rtr__DOT__busy = ((0U 
                                                   != (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__fst)) 
                                                  | (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__scan_busy));
    vlSelfRef.ember_top__DOT__u_rtr__DOT__fpa_we = 
        ((~ (IData)(vlSelfRef.ember_top__DOT__u_rtr__DOT__in_fetch)) 
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
    vlSelfRef.ember_top__DOT__u_cp__DOT__rtr_busy = vlSelfRef.ember_top__DOT__rtr_busy;
    vlSelfRef.ember_top__DOT__rtr_own = vlSelfRef.ember_top__DOT__rtr_busy;
}

void Vtop___024root___nba_sequent__TOP__24(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__24\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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

void Vtop___024root___nba_comb__TOP__7(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__7\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ember_top__DOT__u_xbar__DOT__h_r = ((1U 
                                                   == (IData)(vlSelfRef.ember_top__DOT__u_xbar__DOT__rstate))
                                                   ? vlSelfRef.ember_top__DOT__u_xbar__DOT__v_r
                                                   : vlSelfRef.ember_top__DOT__u_xbar__DOT__c_r);
    vlSelfRef.ember_top__DOT__h_r_s = vlSelfRef.ember_top__DOT__u_xbar__DOT__h_r;
    vlSelfRef.ember_top__DOT__h_rdata = (IData)((vlSelfRef.ember_top__DOT__h_r_s 
                                                 >> 2U));
    vlSelfRef.ember_top__DOT__h_rresp = (3U & (IData)(vlSelfRef.ember_top__DOT__h_r_s));
    vlSelfRef.h_rdata = vlSelfRef.ember_top__DOT__h_rdata;
    vlSelfRef.h_rresp = vlSelfRef.ember_top__DOT__h_rresp;
}

void Vtop___024root___nba_sequent__TOP__25(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__25\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
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
    CData/*3:0*/ __VdlyDim0__ember_top__DOT__u_tu__DOT__acc__v0;
    __VdlyDim0__ember_top__DOT__u_tu__DOT__acc__v0 = 0;
    CData/*3:0*/ __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v0;
    __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v0 = 0;
    CData/*3:0*/ __VdlyDim0__ember_top__DOT__u_tu__DOT__acc__v769;
    __VdlyDim0__ember_top__DOT__u_tu__DOT__acc__v769 = 0;
    CData/*3:0*/ __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v769;
    __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v769 = 0;
    // Body
    if (vlSelfRef.ember_top__DOT__u_tu__DOT__rst_n) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__tua_we = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__tua_req = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_ld = 0U;
        if (((IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__rq_pend) 
             & (~ (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__rq_req_cyc)))) {
            vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__rq_pend = 0U;
            if (vlSelfRef.ember_top__DOT__u_tu__DOT__rq_dst_w) {
                __VdlyVal__ember_top__DOT__u_tu__DOT__abuf_q__v0 
                    = vlSelfRef.ember_top__DOT__u_tu__DOT__tua_rdata;
                __VdlyDim0__ember_top__DOT__u_tu__DOT__abuf_q__v0 
                    = vlSelfRef.ember_top__DOT__u_tu__DOT__rq_aw;
                vlSelfRef.__VdlySet__ember_top__DOT__u_tu__DOT__abuf_q__v0 = 1U;
            } else {
                __VdlyVal__ember_top__DOT__u_tu__DOT__wrowbuf__v0 
                    = vlSelfRef.ember_top__DOT__u_tu__DOT__tua_rdata;
                __VdlyDim0__ember_top__DOT__u_tu__DOT__wrowbuf__v0 
                    = vlSelfRef.ember_top__DOT__u_tu__DOT__rq_aw;
                vlSelfRef.__VdlySet__ember_top__DOT__u_tu__DOT__wrowbuf__v0 = 1U;
            }
        }
        if (vlSelfRef.ember_top__DOT__u_tu__DOT__rq_req_cyc) {
            vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__rq_req_cyc = 0U;
        }
        if (vlSelfRef.ember_top__DOT__u_tu__DOT__mac_pend) {
            vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk7__DOT__c = 0U;
            vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__mac_pend = 0U;
            while ((0x00000010U > vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk7__DOT__c)) {
                __VdlyVal__ember_top__DOT__u_tu__DOT__acc__v0 
                    = (vlSelfRef.ember_top__DOT__u_tu__DOT__acc
                       [vlSelfRef.ember_top__DOT__u_tu__DOT__mrow]
                       [(0x0000000fU & vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk7__DOT__c)] 
                       + vlSelfRef.ember_top__DOT__u_tu__DOT__tree
                       [(0x0000000fU & vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk7__DOT__c)]);
                __VdlyDim0__ember_top__DOT__u_tu__DOT__acc__v0 
                    = (0x0000000fU & vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk7__DOT__c);
                __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v0 
                    = vlSelfRef.ember_top__DOT__u_tu__DOT__mrow;
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(__VdlyVal__ember_top__DOT__u_tu__DOT__acc__v0, (IData)(__VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v0), __VdlyDim0__ember_top__DOT__u_tu__DOT__acc__v0);
                vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk7__DOT__c 
                    = ((IData)(1U) + vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk7__DOT__c);
            }
        }
        if ((8U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__st))) {
            if ((4U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__st))) {
                vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__st = 0U;
            } else if ((2U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__st))) {
                if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__st))) {
                    vlSelfRef.ember_top__DOT__u_tu__DOT__running = 0U;
                    vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__st = 0U;
                } else if ((((IData)(0x00000010U) + vlSelfRef.ember_top__DOT__u_tu__DOT__m0) 
                            >= vlSelfRef.ember_top__DOT__u_tu__DOT__mdim)) {
                    if ((((IData)(0x00000010U) + vlSelfRef.ember_top__DOT__u_tu__DOT__n0) 
                         >= vlSelfRef.ember_top__DOT__u_tu__DOT__ndim)) {
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
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 0U);
                        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__st = 1U;
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 1U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 2U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 3U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 4U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 5U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 6U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 7U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 8U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 9U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 0x0aU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 0x0bU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 0x0cU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 0x0dU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 0x0eU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 0x0fU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 0U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 1U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 2U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 3U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 4U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 5U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 6U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 7U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 8U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 9U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 0x0aU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 0x0bU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 0x0cU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 0x0dU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 0x0eU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 0x0fU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 0U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 1U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 2U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 3U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 4U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 5U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 6U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 7U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 8U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 9U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 0x0aU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 0x0bU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 0x0cU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 0x0dU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 0x0eU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 0x0fU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 0U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 1U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 2U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 3U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 4U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 5U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 6U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 7U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 8U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 9U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 0x0aU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 0x0bU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 0x0cU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 0x0dU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 0x0eU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 0x0fU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 0U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 1U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 2U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 3U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 4U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 5U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 6U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 7U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 8U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 9U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 0x0aU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 0x0bU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 0x0cU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 0x0dU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 0x0eU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 0x0fU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 0U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 1U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 2U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 3U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 4U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 5U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 6U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 7U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 8U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 9U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 0x0aU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 0x0bU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 0x0cU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 0x0dU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 0x0eU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 0x0fU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 0U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 1U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 2U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 3U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 4U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 5U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 6U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 7U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 8U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 9U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 0x0aU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 0x0bU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 0x0cU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 0x0dU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 0x0eU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 0x0fU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 0U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 1U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 2U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 3U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 4U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 5U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 6U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 7U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 8U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 9U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 0x0aU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 0x0bU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 0x0cU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 0x0dU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 0x0eU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 0x0fU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 0U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 1U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 2U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 3U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 4U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 5U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 6U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 7U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 8U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 9U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 0x0aU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 0x0bU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 0x0cU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 0x0dU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 0x0eU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 0x0fU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 0U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 1U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 2U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 3U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 4U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 5U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 6U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 7U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 8U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 9U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 0x0aU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 0x0bU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 0x0cU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 0x0dU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 0x0eU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 0x0fU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 0U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 1U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 2U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 3U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 4U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 5U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 6U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 7U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 8U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 9U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 0x0aU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 0x0bU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 0x0cU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 0x0dU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 0x0eU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 0x0fU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 0U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 1U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 2U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 3U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 4U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 5U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 6U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 7U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 8U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 9U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 0x0aU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 0x0bU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 0x0cU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 0x0dU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 0x0eU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 0x0fU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 0U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 1U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 2U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 3U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 4U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 5U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 6U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 7U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 8U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 9U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 0x0aU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 0x0bU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 0x0cU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 0x0dU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 0x0eU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 0x0fU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 0U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 1U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 2U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 3U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 4U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 5U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 6U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 7U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 8U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 9U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 0x0aU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 0x0bU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 0x0cU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 0x0dU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 0x0eU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 0x0fU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 0U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 1U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 2U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 3U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 4U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 5U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 6U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 7U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 8U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 9U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 0x0aU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 0x0bU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 0x0cU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 0x0dU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 0x0eU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 0x0fU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 0U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 1U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 2U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 3U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 4U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 5U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 6U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 7U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 8U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 9U);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 0x0aU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 0x0bU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 0x0cU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 0x0dU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 0x0eU);
                        vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 0x0fU);
                    }
                } else {
                    vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__m0 
                        = ((IData)(0x00000010U) + vlSelfRef.ember_top__DOT__u_tu__DOT__m0);
                    vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__k0 = 0U;
                    vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__wrow = 0U;
                    vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__wgrp = 0U;
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 0U);
                    vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__st = 1U;
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 1U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 2U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 3U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 4U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 5U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 6U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 7U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 8U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 9U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 0x0aU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 0x0bU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 0x0cU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 0x0dU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 0x0eU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 0x0fU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 0U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 1U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 2U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 3U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 4U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 5U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 6U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 7U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 8U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 9U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 0x0aU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 0x0bU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 0x0cU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 0x0dU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 0x0eU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 0x0fU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 0U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 1U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 2U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 3U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 4U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 5U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 6U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 7U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 8U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 9U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 0x0aU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 0x0bU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 0x0cU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 0x0dU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 0x0eU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 0x0fU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 0U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 1U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 2U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 3U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 4U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 5U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 6U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 7U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 8U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 9U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 0x0aU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 0x0bU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 0x0cU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 0x0dU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 0x0eU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 0x0fU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 0U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 1U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 2U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 3U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 4U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 5U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 6U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 7U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 8U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 9U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 0x0aU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 0x0bU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 0x0cU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 0x0dU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 0x0eU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 0x0fU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 0U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 1U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 2U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 3U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 4U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 5U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 6U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 7U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 8U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 9U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 0x0aU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 0x0bU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 0x0cU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 0x0dU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 0x0eU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 0x0fU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 0U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 1U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 2U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 3U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 4U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 5U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 6U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 7U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 8U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 9U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 0x0aU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 0x0bU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 0x0cU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 0x0dU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 0x0eU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 0x0fU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 0U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 1U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 2U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 3U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 4U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 5U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 6U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 7U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 8U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 9U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 0x0aU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 0x0bU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 0x0cU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 0x0dU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 0x0eU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 0x0fU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 0U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 1U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 2U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 3U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 4U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 5U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 6U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 7U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 8U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 9U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 0x0aU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 0x0bU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 0x0cU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 0x0dU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 0x0eU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 0x0fU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 0U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 1U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 2U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 3U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 4U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 5U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 6U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 7U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 8U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 9U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 0x0aU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 0x0bU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 0x0cU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 0x0dU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 0x0eU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 0x0fU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 0U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 1U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 2U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 3U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 4U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 5U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 6U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 7U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 8U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 9U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 0x0aU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 0x0bU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 0x0cU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 0x0dU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 0x0eU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 0x0fU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 0U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 1U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 2U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 3U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 4U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 5U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 6U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 7U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 8U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 9U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 0x0aU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 0x0bU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 0x0cU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 0x0dU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 0x0eU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 0x0fU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 0U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 1U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 2U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 3U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 4U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 5U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 6U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 7U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 8U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 9U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 0x0aU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 0x0bU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 0x0cU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 0x0dU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 0x0eU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 0x0fU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 0U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 1U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 2U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 3U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 4U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 5U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 6U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 7U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 8U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 9U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 0x0aU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 0x0bU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 0x0cU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 0x0dU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 0x0eU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 0x0fU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 0U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 1U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 2U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 3U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 4U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 5U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 6U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 7U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 8U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 9U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 0x0aU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 0x0bU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 0x0cU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 0x0dU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 0x0eU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 0x0fU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 0U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 1U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 2U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 3U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 4U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 5U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 6U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 7U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 8U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 9U);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 0x0aU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 0x0bU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 0x0cU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 0x0dU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 0x0eU);
                    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 0x0fU);
                }
            } else if ((1U & (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__st))) {
                vlSelfRef.ember_top__DOT__u_tu__DOT__tua_we = 1U;
                vlSelfRef.ember_top__DOT__u_tu__DOT__tua_be = 0x0fU;
                vlSelfRef.ember_top__DOT__u_tu__DOT__tua_addr 
                    = ((IData)(0x00001000U) + (((vlSelfRef.ember_top__DOT__u_tu__DOT__c_base_q 
                                                 + 
                                                 ((IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__cw_row) 
                                                  * vlSelfRef.ember_top__DOT__u_tu__DOT__ndim)) 
                                                + vlSelfRef.ember_top__DOT__u_tu__DOT__n0) 
                                               + ((IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__cw_word) 
                                                  << 2U)));
                vlSelfRef.ember_top__DOT__u_tu__DOT__tua_wdata 
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
                         >= vlSelfRef.ember_top__DOT__u_tu__DOT__kdim)) {
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
                vlSelfRef.ember_top__DOT__u_tu__DOT__tua_req = 1U;
                vlSelfRef.ember_top__DOT__u_tu__DOT__tua_addr 
                    = ((IData)(0x00001000U) + (((vlSelfRef.ember_top__DOT__u_tu__DOT__a_base_q 
                                                 + 
                                                 ((vlSelfRef.ember_top__DOT__u_tu__DOT__m0 
                                                   + (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__mrow)) 
                                                  * vlSelfRef.ember_top__DOT__u_tu__DOT__kdim)) 
                                                + vlSelfRef.ember_top__DOT__u_tu__DOT__k0) 
                                               + (0x0000000cU 
                                                  & ((IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__fcnt) 
                                                     << 2U))));
                vlSelfRef.ember_top__DOT__u_tu__DOT__rq_addr_q 
                    = ((IData)(0x00001000U) + (((vlSelfRef.ember_top__DOT__u_tu__DOT__a_base_q 
                                                 + 
                                                 ((vlSelfRef.ember_top__DOT__u_tu__DOT__m0 
                                                   + (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__mrow)) 
                                                  * vlSelfRef.ember_top__DOT__u_tu__DOT__kdim)) 
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
                vlSelfRef.ember_top__DOT__u_tu__DOT__tua_req = 1U;
                vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__st = 2U;
                vlSelfRef.ember_top__DOT__u_tu__DOT__tua_addr 
                    = ((IData)(0x00001000U) + (((vlSelfRef.ember_top__DOT__u_tu__DOT__w_base_q 
                                                 + 
                                                 ((vlSelfRef.ember_top__DOT__u_tu__DOT__k0 
                                                   + (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__wrow)) 
                                                  * vlSelfRef.ember_top__DOT__u_tu__DOT__ndim)) 
                                                + vlSelfRef.ember_top__DOT__u_tu__DOT__n0) 
                                               + ((IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__wgrp) 
                                                  << 2U)));
                vlSelfRef.ember_top__DOT__u_tu__DOT__rq_addr_q 
                    = ((IData)(0x00001000U) + (((vlSelfRef.ember_top__DOT__u_tu__DOT__w_base_q 
                                                 + 
                                                 ((vlSelfRef.ember_top__DOT__u_tu__DOT__k0 
                                                   + (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__wrow)) 
                                                  * vlSelfRef.ember_top__DOT__u_tu__DOT__ndim)) 
                                                + vlSelfRef.ember_top__DOT__u_tu__DOT__n0) 
                                               + ((IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__wgrp) 
                                                  << 2U)));
            }
        } else {
            vlSelfRef.ember_top__DOT__u_tu__DOT__running = 0U;
            if (vlSelfRef.ember_top__DOT__u_tu__DOT__kick) {
                vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__n0 = 0U;
                vlSelfRef.ember_top__DOT__u_tu__DOT__running = 1U;
                vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__m0 = 0U;
                vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__k0 = 0U;
                vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__wrow = 0U;
                vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__wgrp = 0U;
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 0U);
                vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__st = 1U;
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 1U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 2U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 3U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 4U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 5U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 6U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 7U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 8U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 9U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 0x0aU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 0x0bU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 0x0cU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 0x0dU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 0x0eU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0U, 0x0fU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 0U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 1U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 2U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 3U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 4U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 5U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 6U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 7U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 8U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 9U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 0x0aU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 0x0bU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 0x0cU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 0x0dU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 0x0eU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 1U, 0x0fU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 0U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 1U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 2U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 3U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 4U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 5U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 6U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 7U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 8U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 9U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 0x0aU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 0x0bU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 0x0cU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 0x0dU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 0x0eU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 2U, 0x0fU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 0U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 1U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 2U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 3U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 4U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 5U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 6U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 7U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 8U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 9U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 0x0aU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 0x0bU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 0x0cU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 0x0dU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 0x0eU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 3U, 0x0fU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 0U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 1U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 2U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 3U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 4U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 5U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 6U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 7U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 8U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 9U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 0x0aU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 0x0bU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 0x0cU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 0x0dU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 0x0eU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 4U, 0x0fU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 0U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 1U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 2U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 3U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 4U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 5U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 6U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 7U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 8U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 9U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 0x0aU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 0x0bU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 0x0cU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 0x0dU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 0x0eU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 5U, 0x0fU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 0U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 1U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 2U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 3U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 4U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 5U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 6U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 7U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 8U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 9U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 0x0aU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 0x0bU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 0x0cU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 0x0dU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 0x0eU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 6U, 0x0fU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 0U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 1U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 2U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 3U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 4U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 5U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 6U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 7U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 8U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 9U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 0x0aU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 0x0bU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 0x0cU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 0x0dU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 0x0eU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 7U, 0x0fU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 0U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 1U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 2U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 3U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 4U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 5U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 6U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 7U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 8U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 9U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 0x0aU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 0x0bU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 0x0cU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 0x0dU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 0x0eU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 8U, 0x0fU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 0U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 1U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 2U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 3U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 4U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 5U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 6U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 7U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 8U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 9U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 0x0aU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 0x0bU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 0x0cU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 0x0dU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 0x0eU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 9U, 0x0fU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 0U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 1U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 2U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 3U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 4U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 5U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 6U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 7U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 8U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 9U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 0x0aU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 0x0bU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 0x0cU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 0x0dU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 0x0eU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0aU, 0x0fU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 0U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 1U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 2U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 3U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 4U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 5U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 6U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 7U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 8U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 9U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 0x0aU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 0x0bU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 0x0cU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 0x0dU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 0x0eU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0bU, 0x0fU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 0U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 1U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 2U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 3U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 4U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 5U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 6U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 7U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 8U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 9U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 0x0aU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 0x0bU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 0x0cU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 0x0dU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 0x0eU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0cU, 0x0fU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 0U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 1U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 2U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 3U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 4U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 5U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 6U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 7U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 8U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 9U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 0x0aU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 0x0bU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 0x0cU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 0x0dU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 0x0eU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0dU, 0x0fU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 0U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 1U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 2U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 3U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 4U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 5U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 6U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 7U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 8U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 9U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 0x0aU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 0x0bU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 0x0cU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 0x0dU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 0x0eU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0eU, 0x0fU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 0U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 1U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 2U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 3U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 4U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 5U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 6U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 7U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 8U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 9U);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 0x0aU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 0x0bU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 0x0cU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 0x0dU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 0x0eU);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, 0x0fU, 0x0fU);
            }
        }
    } else {
        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__n0 = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__mrow = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__cw_row = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__cw_rblk = 0U;
        vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__cw_word = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk5__DOT__r = 0U;
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
        vlSelfRef.ember_top__DOT__u_tu__DOT__rq_addr_q = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__rq_dst_w = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__rq_aw = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__tua_we = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__tua_addr = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__tua_wdata = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__tua_be = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__tua_req = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_ld = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__cw_byte0 = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__cw_byte1 = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__cw_byte2 = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__cw_byte3 = 0U;
        while ((0x00000010U > vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk5__DOT__r)) {
            vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk5__DOT__unnamedblk6__DOT__c = 0U;
            while ((0x00000010U > vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk5__DOT__unnamedblk6__DOT__c)) {
                __VdlyDim0__ember_top__DOT__u_tu__DOT__acc__v769 
                    = (0x0000000fU & vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk5__DOT__unnamedblk6__DOT__c);
                __VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v769 
                    = (0x0000000fU & vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk5__DOT__r);
                vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.enqueue(0U, (IData)(__VdlyDim1__ember_top__DOT__u_tu__DOT__acc__v769), __VdlyDim0__ember_top__DOT__u_tu__DOT__acc__v769);
                vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk5__DOT__unnamedblk6__DOT__c 
                    = ((IData)(1U) + vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk5__DOT__unnamedblk6__DOT__c);
            }
            vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk5__DOT__r 
                = ((IData)(1U) + vlSelfRef.ember_top__DOT__u_tu__DOT__unnamedblk5__DOT__r);
        }
    }
    vlSelfRef.ember_top__DOT__u_tu__DOT__mdim = vlSelfRef.ember_top__DOT__u_tu__DOT__dim_m;
    vlSelfRef.ember_top__DOT__u_tu__DOT__ndim = vlSelfRef.ember_top__DOT__u_tu__DOT__dim_n;
    vlSelfRef.ember_top__DOT__u_tu__DOT__kdim = vlSelfRef.ember_top__DOT__u_tu__DOT__dim_k;
    vlSelfRef.ember_top__DOT__u_tu__DOT__rq_pend = vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__rq_pend;
    vlSelfRef.ember_top__DOT__u_tu__DOT__rq_req_cyc 
        = vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__rq_req_cyc;
    vlSelfRef.ember_top__DOT__u_tu__DOT__mac_pend = vlSelfRef.__Vdly__ember_top__DOT__u_tu__DOT__mac_pend;
    vlSelfRef.__VdlyCommitQueueember_top__DOT__u_tu__DOT__acc.commit(vlSelfRef.ember_top__DOT__u_tu__DOT__acc);
    if (vlSelfRef.ember_top__DOT__u_tu__DOT__rst_n) {
        if (vlSelfRef.ember_top__DOT__u_tu__DOT__cfg2_q_we) {
            vlSelfRef.ember_top__DOT__u_tu__DOT__req_shift 
                = (0x0000000fU & (vlSelfRef.ember_top__DOT__u_tu__DOT__csr_wdata 
                                  >> 0x14U));
            vlSelfRef.ember_top__DOT__u_tu__DOT__req_mult 
                = (0x0000ffffU & vlSelfRef.ember_top__DOT__u_tu__DOT__csr_wdata);
        }
        if (vlSelfRef.ember_top__DOT__u_tu__DOT__csr_we) {
            if ((0U != (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__csr_addr))) {
                if ((1U != (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__csr_addr))) {
                    if ((2U == (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__csr_addr))) {
                        vlSelfRef.ember_top__DOT__u_tu__DOT__c_base_q 
                            = (0xfffffffcU & vlSelfRef.ember_top__DOT__u_tu__DOT__csr_wdata);
                    }
                }
                if ((1U == (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__csr_addr))) {
                    vlSelfRef.ember_top__DOT__u_tu__DOT__w_base_q 
                        = (0xfffffffcU & vlSelfRef.ember_top__DOT__u_tu__DOT__csr_wdata);
                }
            }
            if ((0U == (IData)(vlSelfRef.ember_top__DOT__u_tu__DOT__csr_addr))) {
                vlSelfRef.ember_top__DOT__u_tu__DOT__a_base_q 
                    = (0xfffffffcU & vlSelfRef.ember_top__DOT__u_tu__DOT__csr_wdata);
            }
        }
    } else {
        vlSelfRef.ember_top__DOT__u_tu__DOT__req_shift = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__req_mult = 1U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__c_base_q = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__a_base_q = 0U;
        vlSelfRef.ember_top__DOT__u_tu__DOT__w_base_q = 0U;
    }
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
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_tu__DOT__wrowbuf__v0) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__wrowbuf[__VdlyDim0__ember_top__DOT__u_tu__DOT__wrowbuf__v0] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__wrowbuf__v0;
    }
    if (vlSelfRef.__VdlySet__ember_top__DOT__u_tu__DOT__abuf_q__v0) {
        vlSelfRef.ember_top__DOT__u_tu__DOT__abuf_q[__VdlyDim0__ember_top__DOT__u_tu__DOT__abuf_q__v0] 
            = __VdlyVal__ember_top__DOT__u_tu__DOT__abuf_q__v0;
    }
    vlSelfRef.ember_top__DOT__tu_tua_we = vlSelfRef.ember_top__DOT__u_tu__DOT__tua_we;
    vlSelfRef.ember_top__DOT__tu_tua_req = vlSelfRef.ember_top__DOT__u_tu__DOT__tua_req;
    vlSelfRef.ember_top__DOT__tu_tua_be = vlSelfRef.ember_top__DOT__u_tu__DOT__tua_be;
    vlSelfRef.ember_top__DOT__tu_tua_wdata = vlSelfRef.ember_top__DOT__u_tu__DOT__tua_wdata;
    vlSelfRef.ember_top__DOT__tu_tua_addr = vlSelfRef.ember_top__DOT__u_tu__DOT__tua_addr;
    vlSelfRef.ember_top__DOT__u_tu__DOT__busy = vlSelfRef.ember_top__DOT__u_tu__DOT__running;
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
    vlSelfRef.ember_top__DOT__u_vram__DOT__tua_we = vlSelfRef.ember_top__DOT__tu_tua_we;
    vlSelfRef.ember_top__DOT__u_vram__DOT__tua_req 
        = vlSelfRef.ember_top__DOT__tu_tua_req;
    vlSelfRef.ember_top__DOT__u_vram__DOT__tua_be = vlSelfRef.ember_top__DOT__tu_tua_be;
    vlSelfRef.ember_top__DOT__u_vram__DOT__tua_wdata 
        = vlSelfRef.ember_top__DOT__tu_tua_wdata;
    vlSelfRef.ember_top__DOT__u_vram__DOT__tua_addr 
        = vlSelfRef.ember_top__DOT__tu_tua_addr;
    vlSelfRef.ember_top__DOT__tu_busy = vlSelfRef.ember_top__DOT__u_tu__DOT__busy;
    vlSelfRef.ember_top__DOT__u_vram__DOT__tua_widx 
        = (0x0001ffffU & ((vlSelfRef.ember_top__DOT__u_vram__DOT__tua_addr 
                           - (IData)(0x00001000U)) 
                          >> 2U));
    vlSelfRef.ember_top__DOT__u_cp__DOT__tu_busy = vlSelfRef.ember_top__DOT__tu_busy;
}
