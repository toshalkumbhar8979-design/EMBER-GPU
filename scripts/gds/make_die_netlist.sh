#!/usr/bin/env bash
# make_die_netlist.sh -- synthesize the integrated-die top netlist.
# The 8 hardened GPU blocks enter as BLACKBOX instances (they become hard
# macros in physical); only the top-level glue (fpa ownership mux, CSR bus,
# struct adapters, tie-offs) is synthesized to sky130 std cells.
# Run INSIDE the container.
set -o pipefail
PDK=$(ls -d $HOME/.volare/volare/sky130/versions/*/sky130A 2>/dev/null | head -1)
[ -n "$PDK" ] || { echo "PDK NOT FOUND"; exit 3; }
LIB=$PDK/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
OUT=/work/build/gds/die
mkdir -p "$OUT"
cd "$OUT"

yosys -p "
read_verilog -lib /work/build/gds/xbar.v /work/build/gds/cp.v /work/build/gds/tu.v /work/build/gds/core.v /work/build/gds/gsx.v /work/build/gds/blit.v /work/build/gds/display.v /work/build/gds/rtr_top.v
read_verilog /work/build/gds/die/ember_die.v
proc
synth -top ember_die -noalumacc
opt -fast
dfflibmap -liberty $LIB
abc -fast -liberty $LIB
setundef -zero
hilomap -hicell sky130_fd_sc_hd__conb_1 HI -locell sky130_fd_sc_hd__conb_1 LO
opt_clean -purge
write_verilog -noattr -noexpr -nodec top.v
write_json top.json
tee -o top_stat.txt stat -liberty $LIB
" > yosys.log 2>&1
RC=$?
[ $RC -ne 0 ] && { echo "DIE SYNTH FAIL"; tail -15 yosys.log; exit 1; }

python3 /work/scripts/gds/validate_synth.py top.json ember_die \
  --allow-blackbox ember_xbar --allow-blackbox ember_cp \
  --allow-blackbox ember_tu --allow-blackbox ember_core \
  --allow-blackbox ember_gsx --allow-blackbox ember_blit \
  --allow-blackbox ember_display --allow-blackbox ember_rtr_top \
  || { echo "DIE NETLIST NOT FULLY MAPPED"; exit 1; }
echo "DIE NETLIST OK ($(stat -c %s top.v) bytes)"
grep "Number of cells" top_stat.txt | tail -1
grep -E "ember_xbar|ember_cp|ember_tu|ember_core|ember_gsx|ember_blit|ember_display|ember_rtr_top" top_stat.txt | head -8
