# DRC-only companion for fpu4: re-derive the layout from final.def and run the
# same full Magic DRC as the flow's magic.tcl, in a separate process with its
# own timebox. The flow's combined merge+DRC run keeps the GDS's final buffered
# bytes until the whole tcl ends, so a DRC overrun truncates the GDS; this
# companion only produces a DRC count and touches no GDS file.
lef read /root/.volare/volare/sky130/versions/fa87f8f4bbcc7255b6f0c0fb506960f531ae2392/sky130A/libs.ref/sky130_fd_sc_hd/techlef/sky130_fd_sc_hd__nom.tlef
gds read /root/.volare/volare/sky130/versions/fa87f8f4bbcc7255b6f0c0fb506960f531ae2392/sky130A/libs.ref/sky130_fd_sc_hd/gds/sky130_fd_sc_hd.gds
def read final.def
load ember_fpu4 -dereference
drc euclidean on
flatten ember_fpu4_drc_flat
load ember_fpu4_drc_flat
select top cell
box select
drc on
drc style drc(full)
drc check
drc catchup
set drcerr [drc list count total]
puts "DRC_DETAILS=[drc listall why]"
puts "DRC_COUNT=$drcerr"
