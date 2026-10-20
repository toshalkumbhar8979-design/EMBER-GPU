read_liberty /root/.volare/volare/sky130/versions/fa87f8f4bbcc7255b6f0c0fb506960f531ae2392/sky130A/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_lef /root/.volare/volare/sky130/versions/fa87f8f4bbcc7255b6f0c0fb506960f531ae2392/sky130A/libs.ref/sky130_fd_sc_hd/techlef/sky130_fd_sc_hd__nom.tlef
read_lef /root/.volare/volare/sky130/versions/fa87f8f4bbcc7255b6f0c0fb506960f531ae2392/sky130A/libs.ref/sky130_fd_sc_hd/lef/sky130_fd_sc_hd.lef
read_verilog synth.v
link_design ember_rtr_setup
# 30% (not 45%): at 45% TritonRoute could not converge on congested blocks
# (cp reached 11,841 violations and still climbing), because these blocks have
# no PDN and randomly placed pins. Whitespace is cheaper than a stuck router.
# PPL-0024 guard: the die must have perimeter room for every IO pin BIT.
# (xbar: 610 pin bits on a 111um-square utilization-derived die = impossible;
# place_pins aborted the whole block.) Measured from the PPL error: place_pins
# packs ~0.79um/pin on the perimeter; budget 1.0um/pin in micrometres and
# re-initialize with an explicit die when utilization alone made it too small.
set npins 0
set blk [ord::get_db_block]
foreach bterm [$blk getBTerms] { incr npins }
set min_side [expr {$npins / 4.0 + 30.0}]
initialize_floorplan -utilization 20 -aspect_ratio 1.0 -core_space 10 -site unithd
set diebox [$blk getDieArea]
set dw [expr {[$diebox dx] / 1000}]
set dh [expr {[$diebox dy] / 1000}]
if {$dw < $min_side || $dh < $min_side} {
  initialize_floorplan -die_area [list 0 0 $min_side $min_side] -core_area [list 10 10 [expr {$min_side - 10}] [expr {$min_side - 10}]] -site unithd
}
make_tracks
# sky130 li1 is local interconnect, not a general-purpose signal routing layer.
# Keep signal routes on met2..met5. met1 is RESERVED for pin access (DRT
# -bottom_routing_layer met1): at large scale the global router packed ~50% of
# total wirelength onto met1 and generated ~28 shorts per mm of met1 wire
# (fpu4: 1.88M um met1 -> 53K shorts it could never clean). With met1 signal
# routing removed the bulk moves to met2/met3.
set_routing_layers -signal met2-met5 -clock met2-met5
# OpenROAD's place_pins requires explicit pin layers (PPL-0017 otherwise) and
# it checks their PREFERRED DIRECTION against techlef (PPL-0045 if wrong).
# Verified from sky130_fd_sc_hd__nom.tlef: met1 HORIZONTAL, met2 VERTICAL,
# met3 HORIZONTAL.
place_pins -random -hor_layers met1 -ver_layers met2
if {![catch {get_ports clk}]} { create_clock -name clk -period 20.0 [get_ports clk] }
# Wire RC for parasitic estimation: without it repair_design/repair_timing see
# ZERO wire capacitance ([WARNING RSZ-0014]) and their buffer decisions are
# garbage -- useless buffers mean more congestion for the router.
set_wire_rc -signal -layer met2
set_wire_rc -clock -layer met3
# DRC strategy: relax the placement density (routing needs whitespace), route,
# THEN place FILLER cells so the well/implant and poly rules are satisfied
# between standard-cell rows -- missing fillers are a classic source of
# thousands of "well spacing / min-area" style DRCs on sky130. Filler placement
# lives right after detailed_route below: fillers have no pins, so placing
# them before CTS/route only steals whitespace. (The original filler line here
# also leaked shell redirections into the Tcl and STA-0565-aborted every
# block in the first h2 run.)
global_placement -routability_driven -density 0.30
estimate_parasitics -placement
repair_design
detailed_placement
clock_tree_synthesis
estimate_parasitics -placement
# Bound optimizer effort; unresolved timing is reported, not waived as clean.
repair_timing -max_passes 2 -repair_tns 10
# TAP cells: latchup rules want a well tap every ~14um (OpenLane's sky130
# distance). catch-wrapped so a tapcell problem can never kill the block.
if {[catch {tapcell -distance 14 -tapcell_master sky130_fd_sc_hd__tapvpwrvgnd_1} tmsg]} {
  puts "TAPCELL_WARN: $tmsg"
}
detailed_placement
# ---- POWER DELIVERY: the missing stage that was breaking routing ----
# Yosys emits no power connections (synth.v has zero VPWR refs), so before this
# block every cell's VPWR/VGND/VPB/VNB rail geometry was floating. TritonRoute
# then shorted thousands of met1/li1 wires against those shapes -- cp showed
# 7416 met1 shorts + 3522 li1 shorts at optimization iteration 0, roughly ONE
# SHORT PER CELL, and the count only grew with more iterations. The fix is the
# standard sky130 recipe: global PG connections + met1 followpin rails +
# met4/met5 straps (numbers from the OpenROAD-flow-scripts sky130hd PDN).
# VPB/VNB are tied to the rails (OpenLane convention; hd cells carry internal
# well taps).
add_global_connection -net VPWR -inst_pattern .* -pin_pattern ^VPWR$ -power
add_global_connection -net VPWR -inst_pattern .* -pin_pattern ^VPB$ -power
add_global_connection -net VGND -inst_pattern .* -pin_pattern ^VGND$ -ground
add_global_connection -net VGND -inst_pattern .* -pin_pattern ^VNB$ -ground
global_connect
set_voltage_domain -name CORE -power VPWR -ground VGND
define_pdn_grid -name stdcell -voltage_domains CORE
add_pdn_stripe -grid stdcell -layer met1 -width 0.48 -followpins
add_pdn_stripe -grid stdcell -layer met4 -width 1.6 -pitch 27.14 -offset 13.57
add_pdn_stripe -grid stdcell -layer met5 -width 1.6 -pitch 27.2 -offset 13.6
add_pdn_connect -grid stdcell -layers {met1 met4}
add_pdn_connect -grid stdcell -layers {met4 met5}
pdngen
global_route
# Always keep a globally-routed DEF: if detailed routing cannot converge inside
# the timebox, this still gives a real GDS (labelled "global-route").
write_def global_route.def
if {[info exists ::env(GDS_SKIP_DRT)]} {
  puts "GDS_SKIP_DRT set: keeping the globally-routed DEF (flow label: global-route)"
} else {
  # More iterations = more chances to remove violations. The router reports
  # per-iteration DRC counts into route_drc.rpt; we keep the best DEF it reaches.
  detailed_route -bottom_routing_layer met1 -top_routing_layer met5 -output_drc route_drc.rpt -droute_end_iter 40 -verbose 1
}
# FILL AFTER ROUTE: the master list must be ONE braced Tcl list (unbraced
# args = [ERROR STA-0565] "filler_placement requires one positional argument",
# the bug that failed every block in the first h2 run). Masters verified
# against the PDK LEF: fill_1/2/4/8. catch-wrapped so a filler problem can
# never destroy an already-routed design. $ is escaped for the shell heredoc.
if {[catch {filler_placement {sky130_fd_sc_hd__fill_1 sky130_fd_sc_hd__fill_2 sky130_fd_sc_hd__fill_4 sky130_fd_sc_hd__fill_8}} fmsg]} {
  puts "FILLER_WARN: $fmsg"
}
write_def final.def
write_verilog final_nl.v
puts "DESIGN_AREA=[report_design_area]"
report_wns
report_tns
report_checks -path_delay max -group_count 5
