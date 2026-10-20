gds read /work/build/gds/display/display.gds
load ember_display
flatten ember_display_export_audit
load ember_display_export_audit
select top cell
box 0.0um 0.0um 150.605um 150.605um
drc on
drc style drc(full)
drc check
drc catchup
puts "AUDIT_DRC_COUNT=[drc list count total]"
puts "AUDIT_DRC_DETAILS=[drc listall why]"
quit -noprompt
