gds read /work/build/gds/ram_slave/ram_slave.gds
load ember_ram_slave
flatten ember_ram_slave_export_audit
load ember_ram_slave_export_audit
select top cell
box 0.0um 0.0um 143.28um 143.28um
drc on
drc style drc(full)
drc check
drc catchup
puts "AUDIT_DRC_COUNT=[drc list count total]"
puts "AUDIT_DRC_DETAILS=[drc listall why]"
quit -noprompt
