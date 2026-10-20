gds read /work/build/gds/fpu4/fpu4.gds
load ember_fpu4
flatten ember_fpu4_export_audit
load ember_fpu4_export_audit
select top cell
box 0.0um 0.0um 1722.68um 1722.68um
drc on
drc style drc(full)
drc check
drc catchup
puts "AUDIT_DRC_COUNT=[drc list count total]"
puts "AUDIT_DRC_DETAILS=[drc listall why]"
quit -noprompt
