#!/usr/bin/env bash
# After techmap -autoproc, dump which modules still contain processes.
cd /work/build/gds || exit 1
timeout 900 yosys -p "
read_verilog rtr_scan.v
hierarchy -check -top ember_rtr_scan
techmap -autoproc -map /work/build/gds/ripple_techmap.v
write_verilog -noattr /tmp/state_after_techmap.v
" > /tmp/state.log 2>&1
echo "exit=$?"
python3 - <<'EOF'
src = open('/tmp/state_after_techmap.v').read()
cur = None
for line in src.splitlines():
    if line.startswith('module '):
        cur = line.split()[1].split('(')[0]
    if 'always' in line:
        print(f'{cur}: {line.strip()[:110]}')
EOF
echo "--- template modules instantiated in main design: ---"
grep -c '_90_shift' /tmp/state_after_techmap.v
