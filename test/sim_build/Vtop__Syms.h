// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTOP__SYMS_H_
#define VERILATED_VTOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtop.h"

// INCLUDE MODULE CLASSES
#include "Vtop___024root.h"
#include "Vtop___024unit.h"
#include "Vtop_ember_pkg.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vtop__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtop* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtop___024root                 TOP;
    Vtop_ember_pkg                 TOP__ember_pkg;

    // SCOPE NAMES
    VerilatedScope* __Vscopep_TOP;
    VerilatedScope* __Vscopep_ember_pkg;
    VerilatedScope* __Vscopep_ember_top;
    VerilatedScope* __Vscopep_ember_top__u_blit;
    VerilatedScope* __Vscopep_ember_top__u_core;
    VerilatedScope* __Vscopep_ember_top__u_core__u_fpu;
    VerilatedScope* __Vscopep_ember_top__u_core__unnamedblk1;
    VerilatedScope* __Vscopep_ember_top__u_core__unnamedblk2;
    VerilatedScope* __Vscopep_ember_top__u_core__unnamedblk4;
    VerilatedScope* __Vscopep_ember_top__u_core__unnamedblk4__unnamedblk5;
    VerilatedScope* __Vscopep_ember_top__u_core__unnamedblk6;
    VerilatedScope* __Vscopep_ember_top__u_core__unnamedblk7;
    VerilatedScope* __Vscopep_ember_top__u_cp;
    VerilatedScope* __Vscopep_ember_top__u_cp__u_regs;
    VerilatedScope* __Vscopep_ember_top__u_disp;
    VerilatedScope* __Vscopep_ember_top__u_gsx;
    VerilatedScope* __Vscopep_ember_top__u_gsx__u_fpu4;
    VerilatedScope* __Vscopep_ember_top__u_gsx__unnamedblk1;
    VerilatedScope* __Vscopep_ember_top__u_gsx__unnamedblk1__unnamedblk2;
    VerilatedScope* __Vscopep_ember_top__u_gsx__unnamedblk3;
    VerilatedScope* __Vscopep_ember_top__u_rtr;
    VerilatedScope* __Vscopep_ember_top__u_rtr__u_scan;
    VerilatedScope* __Vscopep_ember_top__u_rtr__u_setup;
    VerilatedScope* __Vscopep_ember_top__u_tu;
    VerilatedScope* __Vscopep_ember_top__u_tu__unnamedblk1;
    VerilatedScope* __Vscopep_ember_top__u_tu__unnamedblk1__unnamedblk2;
    VerilatedScope* __Vscopep_ember_top__u_tu__unnamedblk5;
    VerilatedScope* __Vscopep_ember_top__u_tu__unnamedblk5__unnamedblk6;
    VerilatedScope* __Vscopep_ember_top__u_tu__unnamedblk7;
    VerilatedScope* __Vscopep_ember_top__u_vram;
    VerilatedScope* __Vscopep_ember_top__u_xbar;

    // SCOPE HIERARCHY
    VerilatedHierarchy __Vhier;

    // CONSTRUCTORS
    Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp);
    ~Vtop__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
