gds read /work/build/gds/cp/cp.gds
load ember_cp
flatten ember_cp_export_audit
load ember_cp_export_audit
select top cell
box 0.0um 0.0um 706.475um 706.475um
drc on
drc style drc(full)
drc check
drc catchup
puts "AUDIT_DRC_COUNT=[drc list count total]"
puts "AUDIT_DRC_DETAILS=[drc listall why]"
quit -noprompt
