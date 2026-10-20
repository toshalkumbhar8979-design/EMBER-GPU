// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtop__pch.h"

//============================================================
// Constructors

Vtop::Vtop(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtop__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , h_awvalid{vlSymsp->TOP.h_awvalid}
    , h_awready{vlSymsp->TOP.h_awready}
    , h_wstrb{vlSymsp->TOP.h_wstrb}
    , h_wvalid{vlSymsp->TOP.h_wvalid}
    , h_wready{vlSymsp->TOP.h_wready}
    , h_bresp{vlSymsp->TOP.h_bresp}
    , h_bvalid{vlSymsp->TOP.h_bvalid}
    , h_bready{vlSymsp->TOP.h_bready}
    , h_arvalid{vlSymsp->TOP.h_arvalid}
    , h_arready{vlSymsp->TOP.h_arready}
    , h_rresp{vlSymsp->TOP.h_rresp}
    , h_rvalid{vlSymsp->TOP.h_rvalid}
    , h_rready{vlSymsp->TOP.h_rready}
    , dbg_en{vlSymsp->TOP.dbg_en}
    , dbg_be{vlSymsp->TOP.dbg_be}
    , fb_select{vlSymsp->TOP.fb_select}
    , vid_hs{vlSymsp->TOP.vid_hs}
    , vid_vs{vlSymsp->TOP.vid_vs}
    , vid_de{vlSymsp->TOP.vid_de}
    , vid_pixel{vlSymsp->TOP.vid_pixel}
    , h_awaddr{vlSymsp->TOP.h_awaddr}
    , h_wdata{vlSymsp->TOP.h_wdata}
    , h_araddr{vlSymsp->TOP.h_araddr}
    , h_rdata{vlSymsp->TOP.h_rdata}
    , dbg_addr{vlSymsp->TOP.dbg_addr}
    , dbg_rdata{vlSymsp->TOP.dbg_rdata}
    , dbg_wdata{vlSymsp->TOP.dbg_wdata}
    , __PVT__ember_pkg{vlSymsp->TOP.__PVT__ember_pkg}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtop::Vtop(const char* _vcname__)
    : Vtop(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtop::~Vtop() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
void Vtop___024root___eval_static(Vtop___024root* vlSelf);
void Vtop___024root___eval_initial(Vtop___024root* vlSelf);
void Vtop___024root___eval_settle(Vtop___024root* vlSelf);
void Vtop___024root___eval(Vtop___024root* vlSelf);

void Vtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtop___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtop___024root___eval_static(&(vlSymsp->TOP));
        Vtop___024root___eval_initial(&(vlSymsp->TOP));
        Vtop___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtop___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtop::eventsPending() { return false; }

uint64_t Vtop::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vtop::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtop___024root___eval_final(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop::final() {
    Vtop___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtop::hierName() const { return vlSymsp->name(); }
const char* Vtop::modelName() const { return "Vtop"; }
unsigned Vtop::threads() const { return 1; }
void Vtop::prepareClone() const { contextp()->prepareClone(); }
void Vtop::atClone() const {
    contextp()->threadPoolpOnClone();
}
