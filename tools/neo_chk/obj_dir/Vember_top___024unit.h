// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vember_top.h for the primary calling header

#ifndef VERILATED_VEMBER_TOP___024UNIT_H_
#define VERILATED_VEMBER_TOP___024UNIT_H_  // guard

#include "verilated.h"


class Vember_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vember_top___024unit final {
  public:

    // INTERNAL VARIABLES
    Vember_top__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vember_top___024unit();
    ~Vember_top___024unit();
    void ctor(Vember_top__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vember_top___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
