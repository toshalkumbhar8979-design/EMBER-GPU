// pad_models.sv — BEHAVIORAL pad-cell wrappers for simulation and lint only.
//
// Each wrapper matches the interface used by rtl/ember_chip.sv. For the
// physical flow, scripts/gds/make_pad_ring.py emits
// build/gds/chip/pad_cells_physical.v with the SAME module names built from
// real sky130_fd_io cells (sky130_fd_io__top_gpiov2 / __top_xres4v2, with the
// caravel-style DM/OE_N/ENABLE configuration per direction). The flow picks
// one file or the other; ember_chip.sv does not change.
//
// Directions are fixed per wrapper (no tristates) because the pinout
// (scripts/gds/pinout.csv) assigns every chip pin a fixed direction.

// Input pad: external pin -> core.
module pad_in
(
  input  wire PAD,
  output wire IN
);
  assign IN = PAD;
endmodule : pad_in

// Output pad: core -> external pin.
module pad_out
(
  output wire PAD,
  input  wire OUT
);
  assign PAD = OUT;
endmodule : pad_out

// External reset pad (sky130_fd_io__top_xres4v2): the filtered PAD is the
// active-low chip reset. TIE_WEAK_HI_H / PULLUP_H are physical options.
module pad_xres
(
  input  wire PAD,
  output wire XRES_H_N
);
  assign XRES_H_N = PAD;
endmodule : pad_xres

// Power / ground / corner pads carry no logic: they are placed physically by
// the pad-ring generator and connect to the supply rails (VDDIO/VCCD/VSSIO/
// VSSD/VDDA/VSSA). They are therefore absent from the RTL netlist; see
// docs/chip_pinout.md ("Power plan").
