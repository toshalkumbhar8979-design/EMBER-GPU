set pdk $env(HOME)/.volare/volare/sky130/versions/fa87f8f4bbcc7255b6f0c0fb506960f531ae2392/sky130A
scalegrid 1 2
gds read /work/build/gds/xbar/xbar_gridtest.gds
load sky130_fd_sc_hd__nand2_1
select top cell
box select
drc on
drc style drc(full)
drc check
drc catchup
puts "CELL_COUNT=[drc list count total]"
drc why
puts "CELL_DETAILS=[drc listall why]"
load ember_xbar
flatten ember_xbar_audit_flat
load ember_xbar_audit_flat
select top cell
box select
drc check
drc catchup
puts "FLAT_COUNT=[drc list count total]"
drc why
puts "FLAT_DETAILS=[drc listall why]"
quit -noprompt
