// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VEMBER_TOP__SYMS_H_
#define VERILATED_VEMBER_TOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vember_top.h"

// INCLUDE MODULE CLASSES
#include "Vember_top___024root.h"
#include "Vember_top___024unit.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vember_top__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vember_top* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vember_top___024root           TOP;

    // CONSTRUCTORS
    Vember_top__Syms(VerilatedContext* contextp, const char* namep, Vember_top* modelp);
    ~Vember_top__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
