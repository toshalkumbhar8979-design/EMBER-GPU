set pdk /root/.volare/volare/sky130/versions/fa87f8f4bbcc7255b6f0c0fb506960f531ae2392/sky130A
scalegrid 1 2
lef read $pdk/libs.ref/sky130_fd_sc_hd/techlef/sky130_fd_sc_hd__nom.tlef
gds read $pdk/libs.ref/sky130_fd_sc_hd/gds/sky130_fd_sc_hd.gds
def read final.def
load ember_xbar -dereference
select top cell
box select
gds write xbar_gridtest.gds
drc on
drc style drc(full)
drc check
drc catchup
puts "GRIDTEST_DRC_COUNT=[drc listall count total]"
puts "GRIDTEST_DRC_CELLS=[drc listall count]"
drc why
quit -noprompt
