gds read /work/build/gds/rtr_setup/rtr_setup.gds
load ember_rtr_setup
flatten ember_rtr_setup_export_audit
load ember_rtr_setup_export_audit
select top cell
box 0.0um 0.0um 805.265um 805.265um
drc on
drc style drc(full)
drc check
drc catchup
puts "AUDIT_DRC_COUNT=[drc list count total]"
puts "AUDIT_DRC_DETAILS=[drc listall why]"
quit -noprompt
