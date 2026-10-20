#!/usr/bin/env bash
# Bisect which pre-pass makes the standalone `proc` on ember_rtr_scan fail with
# "Multiple edge sensitive events found for this signal!".
cd /work/build/gds || exit 1
run() {
  local tag="$1"; shift
  echo "===== $tag ====="
  timeout 900 yosys -p "read_verilog rtr_scan.v; hierarchy -check -top ember_rtr_scan; $*" 2>&1 \
    | grep -E "ERROR|End of script" | head -3
}
run E1 "proc"
run E2 "opt -fast -full; proc"
run E3 "memory_map; proc"
run E4 "opt -fast -full; memory_map; opt -full; proc"
run E5 "techmap -autoproc -map /work/build/gds/ripple_techmap.v; proc"
run E6 "opt -fast -full; memory_map; opt -full; techmap -autoproc -map /work/build/gds/ripple_techmap.v; proc"
echo "BISECT DONE"
