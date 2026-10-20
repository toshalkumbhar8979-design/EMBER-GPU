gds read /work/build/gds/xbar/xbar.gds
load ember_xbar
select top cell
box 0um 0um 200um 200um
drc on
drc style drc(full)
drc check
drc catchup
puts "AUDIT_DRC_COUNT=[drc listall count total]"
puts "AUDIT_DRC_DETAILS=[drc listall why]"
quit -noprompt
