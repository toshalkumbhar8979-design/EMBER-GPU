// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vember_top.h for the primary calling header

#include "Vember_top__pch.h"

void Vember_top___024root___ctor_var_reset(Vember_top___024root* vlSelf);

Vember_top___024root::Vember_top___024root(Vember_top__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vember_top___024root___ctor_var_reset(this);
}

void Vember_top___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vember_top___024root::~Vember_top___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
