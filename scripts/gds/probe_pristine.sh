#!/usr/bin/env bash
# Compare pristine vs post-techmap process state; read techmap -autoproc help.
cd /work/build/gds || exit 1
yosys -p "
read_verilog rtr_scan.v
hierarchy -check -top ember_rtr_scan
write_verilog -noattr /tmp/pristine.v
help techmap
" > /tmp/help.log 2>&1
echo "=== pristine always blocks ==="
grep -n "always" /tmp/pristine.v | head
echo "=== techmap help (autoproc part) ==="
sed -n '/autoproc/,+4p' /tmp/help.log | head -12
