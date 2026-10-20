gds read /work/build/gds/xbar/xbar.gds
load ember_xbar
flatten ember_xbar_export_audit
load ember_xbar_export_audit
select top cell
box 0.0um 0.0um 182.5um 182.5um
drc on
drc style drc(full)
drc check
drc catchup
puts "AUDIT_DRC_COUNT=[drc list count total]"
puts "AUDIT_DRC_DETAILS=[drc listall why]"
quit -noprompt
