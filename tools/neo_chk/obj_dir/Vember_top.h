// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VEMBER_TOP_H_
#define VERILATED_VEMBER_TOP_H_  // guard

#include "verilated.h"

class Vember_top__Syms;
class Vember_top___024root;

// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) Vember_top VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vember_top__Syms* const vlSymsp;

  public:

    // CONSTEXPR CAPABILITIES
    // Verilated with --trace?
    static constexpr bool traceCapable = false;

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&clk,0,0);
    VL_IN8(&rst_n,0,0);
    VL_IN8(&h_awvalid,0,0);
    VL_OUT8(&h_awready,0,0);
    VL_IN8(&h_wstrb,3,0);
    VL_IN8(&h_wvalid,0,0);
    VL_OUT8(&h_wready,0,0);
    VL_OUT8(&h_bresp,1,0);
    VL_OUT8(&h_bvalid,0,0);
    VL_IN8(&h_bready,0,0);
    VL_IN8(&h_arvalid,0,0);
    VL_OUT8(&h_arready,0,0);
    VL_OUT8(&h_rresp,1,0);
    VL_OUT8(&h_rvalid,0,0);
    VL_IN8(&h_rready,0,0);
    VL_IN8(&dbg_en,0,0);
    VL_IN8(&dbg_be,3,0);
    VL_IN8(&fb_select,1,0);
    VL_OUT8(&vid_hs,0,0);
    VL_OUT8(&vid_vs,0,0);
    VL_OUT8(&vid_de,0,0);
    VL_OUT16(&vid_pixel,15,0);
    VL_IN(&h_awaddr,31,0);
    VL_IN(&h_wdata,31,0);
    VL_IN(&h_araddr,31,0);
    VL_OUT(&h_rdata,31,0);
    VL_IN(&dbg_addr,16,0);
    VL_OUT(&dbg_rdata,31,0);
    VL_IN(&dbg_wdata,31,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vember_top___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vember_top(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vember_top(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vember_top();
  private:
    VL_UNCOPYABLE(Vember_top);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedTraceBaseC* tfp, int levels, int options = 0) { contextp()->trace(tfp, levels, options); }
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    /// Prepare for cloning the model at the process level (e.g. fork in Linux)
    /// Release necessary resources. Called before cloning.
    void prepareClone() const;
    /// Re-init after cloning the model at the process level (e.g. fork in Linux)
    /// Re-allocate necessary resources. Called after cloning.
    void atClone() const;
  private:
    // Internal functions - trace registration
    void traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options);
};

#endif  // guard
