#!/usr/bin/env bash
# Sequential physical pipeline. Safe to resume: keep only content-audited clean
# blocks; validated mapped JSON is required before reusing any synthesis cache.
set -u
cd /work || exit 1
python3 scripts/gds/prepare_cached_flow.py || exit 1
PASS=0; FAIL=0
while IFS='|' read -r name top files overrides; do
  case "$name" in ''|\#*) continue;; esac
  # A bounded small-block build may already be running alongside this queue.
  # Wait for that block rather than deleting its artifacts or starting twice.
  python3 - "$name" <<'PY'
import sys
import time
import psutil
name = sys.argv[1]
while True:
    active = []
    for p in psutil.process_iter(['cmdline', 'status']):
        cmd = p.info['cmdline'] or []
        if p.info['status'] != psutil.STATUS_ZOMBIE and name in cmd and any(
                arg.endswith(('harden_block.sh', 'harden_physical_snapshot.sh')) for arg in cmd):
            active.append(p.pid)
    if not active:
        break
    print(f'WAIT {name}: active physical build {active}', flush=True)
    time.sleep(15)
PY
  if python3 scripts/gds/verify_block.py "$name" >/dev/null 2>&1; then
    echo "KEEP $name: audited zero-routing/DRC GDS"
    PASS=$((PASS + 1))
    continue
  fi
  # A routed core checkpoint must NEVER be rebuilt (user policy 2026-10-19):
  # harden_physical_snapshot.sh wipes final.def on start. Delegate to the
  # resume-only controller instead; it relaunches this queue after core
  # verifies, so the remaining blocks still run in order.
  if [ "$name" = core ] && { [ -s "build/gds/core/final.odb" ] || [ -s "build/gds/core/final.def" ] || [ -s "build/gds/core/final_iter40_backup.def" ]; }; then
    echo "KEEP core routed checkpoint: delegating to auto_core_master (resume-only; no rebuild)"
    exec bash /work/scripts/gds/auto_core_master.sh
  fi
  read -r -a settings <<< "$overrides"
  echo "BLOCK $name [$overrides]"
  if [ "$name" = rtr_top ]; then
    if bash scripts/gds/make_rtr_top_netlist.sh < /dev/null \
        > build/gds/rtr_top.hier_synth.log 2>&1 \
        && bash scripts/gds/rtr_top_pnr.sh < /dev/null \
        > build/gds/rtr_top.physical.log 2>&1; then
      result=0
    else
      result=1
    fi
  else
    result=1
    if [ -s "build/gds/$name/synth.v" ] && [ -f "build/gds/$name/.synthkey" ]; then
      if env "${settings[@]}" GDS_FLOW_TAG=h2 GDS_PHYSICAL_ONLY=1 \
          bash build/gds/harden_physical_snapshot.sh "$name" "$top" "build/gds/$name.v" \
          < /dev/null > "build/gds/$name.physical.log" 2>&1; then
        result=0
      fi
    else
      echo "FAIL $name: no completed synthesis cache"
    fi
  fi
  if [ "$result" -eq 0 ] && python3 scripts/gds/verify_block.py "$name"; then
    echo "PASS $name: content-audited zero-routing/DRC GDS"
    PASS=$((PASS + 1))
  else
    echo "FAIL $name: incomplete; no clean-build claim"
    tail -8 "build/gds/$name.physical.log" 2>/dev/null
    FAIL=$((FAIL + 1))
  fi
  python3 tools/gds/collect_results.py /work/build/gds
 done < scripts/gds/blocks.txt

echo "PHYSICAL SUITE PASS=$PASS FAIL=$FAIL"
if [ "$FAIL" -ne 0 ]; then
  echo "DIE BLOCKED: unresolved block implementation evidence"
  exit 1
fi
for name in core tu gsx blit rtr_top xbar display cp; do
  openroad -python -no_init -exit scripts/gds/make_block_lef.py "$name" \
    > "build/gds/$name/lef.log" 2>&1 || exit 1
done
bash scripts/gds/make_die_netlist.sh < /dev/null || exit 1
bash scripts/gds/die_pnr.sh < /dev/null > build/gds/die.physical.log 2>&1 || exit 1
python3 scripts/gds/verify_block.py die || exit 1
echo "LOGIC DIE DRC VERIFIED: external-memory variant; LVS/timing still pending"
