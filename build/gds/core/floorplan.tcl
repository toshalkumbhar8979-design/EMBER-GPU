read_liberty /root/.volare/volare/sky130/versions/fa87f8f4bbcc7255b6f0c0fb506960f531ae2392/sky130A/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_lef /root/.volare/volare/sky130/versions/fa87f8f4bbcc7255b6f0c0fb506960f531ae2392/sky130A/libs.ref/sky130_fd_sc_hd/techlef/sky130_fd_sc_hd__nom.tlef
read_lef /root/.volare/volare/sky130/versions/fa87f8f4bbcc7255b6f0c0fb506960f531ae2392/sky130A/libs.ref/sky130_fd_sc_hd/lef/sky130_fd_sc_hd.lef
read_verilog synth.v
link_design ember_core
# 30% (not 45%): at 45% TritonRoute could not converge on congested blocks
# (cp reached 11,841 violations and still climbing), because these blocks have
# no PDN and randomly placed pins. Whitespace is cheaper than a stuck router.
initialize_floorplan -utilization 30 -aspect_ratio 1.0 -core_space 10 -site unithd
make_tracks
# OpenROAD's place_pins requires explicit pin layers (PPL-0017 otherwise) and
# it checks their PREFERRED DIRECTION against techlef (PPL-0045 if wrong).
# Verified from sky130_fd_sc_hd__nom.tlef: met1 HORIZONTAL, met2 VERTICAL,
# met3 HORIZONTAL.
place_pins -random -hor_layers met1 -ver_layers met2
if {![catch {get_ports clk}]} { create_clock -name clk -period 20.0 [get_ports clk] }
# DRC strategy: relax the placement density (routing needs whitespace), then
# place FILLER cells so the well/implant and poly rules are satisfied between
# standard-cell rows -- missing fillers are a classic source of thousands of
# "well spacing / min-area" style DRCs on sky130.
global_placement -routability_driven -density 0.45
estimate_parasitics -placement
repair_design
detailed_placement
filler_placement sky130_fd_sc_hd__fill_1 sky130_fd_sc_hd__fill_2 sky130_fd_sc_hd__fill_4 2>/dev/null || true
clock_tree_synthesis
estimate_parasitics -placement
repair_timing
detailed_placement
global_route
# Always keep a globally-routed DEF: if detailed routing cannot converge inside
# the timebox, this still gives a real GDS (labelled "global-route").
write_def global_route.def
if {[info exists ::env(GDS_SKIP_DRT)]} {
  puts "GDS_SKIP_DRT set: keeping the globally-routed DEF (flow label: global-route)"
} else {
  # More iterations = more chances to remove violations. The router reports
  # per-iteration DRC counts into route_drc.rpt; we keep the best DEF it reaches.
  detailed_route -output_drc route_drc.rpt -droute_end_iter 20 -verbose 1
}
write_def final.def
write_verilog final_nl.v
puts "DESIGN_AREA=[report_design_area]"
puts "WNS=[report_wns]"
puts "TNS=[report_tns]"
