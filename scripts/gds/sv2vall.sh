#!/usr/bin/env bash
# Convert every Ember RTL block from SystemVerilog to Verilog-2005 with sv2v
# so the OpenLane container's Yosys can synthesize it.
# Run in WSL:  bash scripts/gds/sv2vall.sh
set -e
cd "$(dirname "$0")/../.."
V="$HOME/bin/sv2v"
[ -x "$V" ] || V="$HOME/.local/bin/sv2v"
mkdir -p build/gds

run() {
  name=$1; shift
  out="build/gds/$name.v"
  # -DSYNTHESIS strips sim-only blocks (e.g. ember_memif's collision assert
  # with $display): yosys rejects $print cells as unmapped.
  "$V" -DSYNTHESIS -I rtl "$@" -w "$out"
  echo "$name ok: $(grep -c '^module' "$out") modules"
}

run rtr_scan   rtl/ember_pkg.sv rtl/ember_rtr_scan.sv
run rtr_setup  rtl/ember_pkg.sv rtl/ember_rtr_setup.sv
run rtr_top    rtl/ember_pkg.sv rtl/ember_rtr_setup.sv rtl/ember_rtr_scan.sv rtl/ember_rtr_top.sv
run fpu4       rtl/ember_pkg.sv rtl/ember_fpu4.sv
run cp         rtl/ember_pkg.sv rtl/ember_ram_slave.sv rtl/ember_cp.sv
run xbar       rtl/ember_pkg.sv rtl/ember_xbar.sv
run ram_slave  rtl/ember_pkg.sv rtl/ember_ram_slave.sv
run vram       rtl/ember_pkg.sv rtl/ember_vram.sv
run blit       rtl/ember_pkg.sv rtl/ember_blit.sv
run display    rtl/ember_pkg.sv rtl/ember_display.sv
run gsx        rtl/ember_pkg.sv rtl/ember_fpu4.sv rtl/ember_gsx.sv
run core       rtl/ember_pkg.sv rtl/ember_core.sv
run tu         rtl/ember_pkg.sv rtl/ember_tu.sv
run memif      rtl/ember_pkg.sv rtl/ember_memif.sv
run chip       rtl/ember_pkg.sv rtl/ember_ram_slave.sv rtl/ember_vram.sv rtl/ember_xbar.sv rtl/ember_cp.sv rtl/ember_rtr_setup.sv rtl/ember_rtr_scan.sv rtl/ember_rtr_top.sv rtl/ember_blit.sv rtl/ember_fpu4.sv rtl/ember_gsx.sv rtl/ember_core.sv rtl/ember_tu.sv rtl/ember_display.sv rtl/ember_die.sv rtl/ember_memif.sv rtl/pad_models.sv rtl/ember_chip.sv
run top        rtl/ember_pkg.sv rtl/ember_ram_slave.sv rtl/ember_vram.sv rtl/ember_xbar.sv rtl/ember_cp.sv rtl/ember_rtr_setup.sv rtl/ember_rtr_scan.sv rtl/ember_rtr_top.sv rtl/ember_blit.sv rtl/ember_fpu4.sv rtl/ember_gsx.sv rtl/ember_core.sv rtl/ember_tu.sv rtl/ember_display.sv rtl/ember_top.sv
