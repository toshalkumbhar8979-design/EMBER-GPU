gds read /work/build/gds/blit/blit.gds
load ember_blit
flatten ember_blit_export_audit
load ember_blit_export_audit
select top cell
box 0.0um 0.0um 272.815um 272.815um
drc on
drc style drc(full)
drc check
drc catchup
puts "AUDIT_DRC_COUNT=[drc list count total]"
puts "AUDIT_DRC_DETAILS=[drc listall why]"
quit -noprompt
