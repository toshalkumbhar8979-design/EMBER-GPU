// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vember_top.h for the primary calling header

#include "Vember_top__pch.h"

void Vember_top___024unit___ctor_var_reset(Vember_top___024unit* vlSelf);

Vember_top___024unit::Vember_top___024unit() = default;
Vember_top___024unit::~Vember_top___024unit() = default;

void Vember_top___024unit::ctor(Vember_top__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vember_top___024unit___ctor_var_reset(this);
}

void Vember_top___024unit::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vember_top___024unit::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
