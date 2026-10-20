# cp forensic diagnostic: a SHORT detailed-route pass over cp's existing
# globally-routed DEF (floorplan/place/CTS/PDN already done) purely to harvest
# real violation entries (which nets short, where) from the DRC report.
# Thrown-away run -- the real block flow re-runs from scratch.
set_thread_count 4
read_liberty /root/.volare/volare/sky130/versions/fa87f8f4bbcc7255b6f0c0fb506960f531ae2392/sky130A/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_lef /root/.volare/volare/sky130/versions/fa87f8f4bbcc7255b6f0c0fb506960f531ae2392/sky130A/libs.ref/sky130_fd_sc_hd/techlef/sky130_fd_sc_hd__nom.tlef
read_lef /root/.volare/volare/sky130/versions/fa87f8f4bbcc7255b6f0c0fb506960f531ae2392/sky130A/libs.ref/sky130_fd_sc_hd/lef/sky130_fd_sc_hd.lef
read_def /work/build/gds/cp/global_route.def
# Re-run global routing: reading global-route wires back from a DEF confuses
# TritonRoute ("net net8 initial #node != #rpin" -- DEF round-trip mismatch).
# Fresh guides from the placed+CTS state sidestep it.
set_routing_layers -signal met1-met5 -clock met2-met5
global_route
detailed_route -bottom_routing_layer met1 -top_routing_layer met5 -output_drc /work/build/gds/cp_diag_met1_drc.rpt -droute_end_iter 2 -verbose 1
