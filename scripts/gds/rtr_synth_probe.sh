#!/usr/bin/env bash
# Probe: exact flow synth recipe for rtr_scan (hierarchical netlist), with
# peak-RSS measurement. Decides flat-queue vs hard-macro strategy.
set -u
P=$(ls -d $HOME/.volare/volare/sky130/versions/*/sky130A | head -1)
[ -n "$P" ] || { echo "PDK NOT FOUND"; exit 3; }
LIB=$P/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
OUT=/tmp/rtr_synth_test
rm -rf "$OUT"; mkdir -p "$OUT"; cd "$OUT" || exit 1
python3 /work/scripts/gds/make_ripple_map.py || exit 3
# sample yosys peak RSS from a background python watcher (no /usr/bin/time)
python3 - <<'PY' &
import psutil, time, os
peak = 0
while True:
    try:
        for p in psutil.process_iter(['name', 'memory_info']):
            if p.info['name'] == 'yosys':
                rss = p.info['memory_info'].rss
                if rss > peak:
                    peak = rss
                    with open('/tmp/rtr_synth_test/peak_rss.txt', 'w') as f:
                        f.write(f'{peak/2**30:.2f} GiB\n')
    except Exception:
        pass
    time.sleep(2)
PY
WPID=$!
yosys -p "
read_verilog /work/build/gds/rtr_scan.v
hierarchy -check -top ember_rtr_scan
# Convert behavioral processes (async-reset FSM) BEFORE synth: yosys 0.46's
# synth-internal passes + later techmap/proc choke on the raw process.
proc
synth -top ember_rtr_scan -noalumacc -run begin:coarse
opt -fast -full
memory_map
opt -full
techmap -autoproc -map /work/build/gds/ripple_techmap.v
proc
opt -fast
techmap -autoproc -map /work/build/gds/ripple_techmap.v
proc
opt -fast
hierarchy -check
check
dfflibmap -liberty $LIB
abc -fast -liberty $LIB
setundef -zero
hilomap -hicell sky130_fd_sc_hd__conb_1 HI -locell sky130_fd_sc_hd__conb_1 LO
opt_clean -purge
write_verilog -noattr -noexpr -nodec synth.v
write_json synth.json
tee -o synth_stat.txt stat -liberty $LIB
" > yosys.log 2>&1
RC=$?
kill $WPID 2>/dev/null
echo "RC=$RC PEAK=$(cat /tmp/rtr_synth_test/peak_rss.txt 2>/dev/null || echo n/a)" >> yosys.log
tail -3 yosys.log
exit $RC
