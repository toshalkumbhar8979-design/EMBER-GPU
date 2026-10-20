#!/usr/bin/env bash
# make_rtr_top_netlist.sh -- hierarchical synthesis of ember_rtr_top.
#
# Monolithic synthesis is impossible: ABC OOM-kills even at 27 GB (RAM+swap)
# on the multiplier-heavy AIG of the concatenated setup+scan+top file.
# Instead: ember_rtr_setup and ember_rtr_scan enter as BLACKBOX macros (their
# hardened netlists exist and validated); only the top FSM glue is synthesized.
# Physical: build/rtr_top with the two macros placed as hard macros
# (rtr_top_pnr.sh), mirroring the die flow.
set -o pipefail
PDK=$(ls -d $HOME/.volare/volare/sky130/versions/*/sky130A 2>/dev/null | head -1)
[ -n "$PDK" ] || { echo "PDK NOT FOUND"; exit 3; }
LIB=$PDK/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
OUT=/work/build/gds/rtr_top
mkdir -p "$OUT"
cd "$OUT"

# extract ONLY the ember_rtr_top module from the self-contained sv2v output
python3 - <<'EOF'
src = open('/work/build/gds/rtr_top.v').read()
i = src.find('module ember_rtr_top (')
assert i > 0
j = src.find('\nendmodule', i)
assert j > 0
open('/work/build/gds/rtr_top/top_glue.v', 'w').write(src[i:j + len('\nendmodule')] + '\n')
print('top_glue.v extracted:', j + 10 - i, 'bytes')
EOF

yosys -p "
read_verilog -lib /work/build/gds/rtr_setup.v /work/build/gds/rtr_scan.v
read_verilog /work/build/gds/rtr_top/top_glue.v
proc
synth -top ember_rtr_top -noalumacc
opt -fast
dfflibmap -liberty $LIB
abc -fast -liberty $LIB
setundef -zero
hilomap -hicell sky130_fd_sc_hd__conb_1 HI -locell sky130_fd_sc_hd__conb_1 LO
opt_clean -purge
write_verilog -noattr -noexpr -nodec synth.v
write_json synth.json
tee -o synth_stat.txt stat -liberty $LIB
" > yosys.log 2>&1
[ $? -ne 0 ] && { echo "RTR_TOP SYNTH FAIL"; tail -15 yosys.log; exit 1; }
python3 /work/scripts/gds/validate_synth.py synth.json ember_rtr_top \
  --allow-blackbox ember_rtr_setup --allow-blackbox ember_rtr_scan \
  || { echo "RTR_TOP NETLIST NOT FULLY MAPPED"; exit 1; }
echo "h2-$(md5sum /work/build/gds/rtr_setup.v /work/build/gds/rtr_scan.v /work/build/gds/rtr_top.v | md5sum | cut -d' ' -f1)" > .synthkey
echo "RTR_TOP NETLIST OK ($(stat -c %s synth.v) bytes)"
grep "Number of cells" synth_stat.txt | tail -1
grep -E "ember_rtr_setup|ember_rtr_scan" synth_stat.txt | head -2
