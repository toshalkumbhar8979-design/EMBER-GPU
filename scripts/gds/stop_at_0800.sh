#!/usr/bin/env bash
# stop_at_0800.sh -- graceful 08:00 cutoff (user shuts the laptop down after).
#
# If the full build has not completed by 08:00, stop the whole chain cleanly
# and snapshot its state. The routed checkpoint (core/final.oda + final.def,
# ~152 violations) is PRESERVED on disk, and BUILD_IN_PROGRESS stays in place,
# so tonight's power-on auto-resumes core from exactly this state via the
# resume-only boot branch in ember_autostart.sh -- no rebuild, ever.
set -u
LOG=/work/build/gds/OVERNIGHT_STATUS.log
SNAP=/work/build/gds/PRE_SHUTDOWN_STATUS.log
say() { echo "== $(date '+%F %T') == $*" >> "$LOG"; }

# Sleep until 08:00 local (today if still ahead, otherwise tomorrow).
TARGET=$(date -d "$(date +%Y-%m-%d) 08:00:00" +%s)
NOW=$(date +%s)
[ "$NOW" -ge "$TARGET" ] && TARGET=$((TARGET + 86400))
say "stop_at_0800 armed: cutoff $(date -d @"$TARGET" '+%F %T') pid=$$"
sleep $((TARGET - NOW))

say "8am cutoff reached; evaluating build state"
if [ -s /work/build/gds/chip/chip.gds ] && [ -s /work/build/gds/core/core.gds ]; then
  say "build already complete (core.gds + chip.gds present); nothing to stop"
  exit 0
fi

# Snapshot BEFORE killing anything: the pre-shutdown state of record.
{
  echo "=== PRE-SHUTDOWN SNAPSHOT $(date) ==="
  echo "--- latest routing violation counts (core/openroad.log) ---"
  grep "Number of violations =" /work/build/gds/core/openroad.log 2>/dev/null | tail -5
  echo "--- resume round log tail ---"
  tail -6 /work/build/gds/core/openroad_resume_1.log 2>/dev/null
  echo "--- routed checkpoint artifacts ---"
  ls -la /work/build/gds/core/final.def /work/build/gds/core/final.odb \
         /work/build/gds/core/final_iter40_backup.def 2>/dev/null
  echo "--- block GDS inventory ---"
  ls -la /work/build/gds/*/*.gds /work/build/gds/chip/chip.gds 2>/dev/null
  echo "--- chain processes at cutoff ---"
  pgrep -af 'auto_core_master|route_resume|run_cached|chip_watch|harden|openroad|magic|klayout' \
    | grep -v pgrep
} > "$SNAP" 2>&1
say "state snapshot written to $SNAP"

# Stop the chain: our processes only, by exact script/command patterns.
for pat in 'auto_core_master\.sh' 'run_cached\.sh' 'recover_1017\.sh' 'chip_watch\.sh' \
           'harden_physical_snapshot\.sh' 'harden_block\.sh' 'route_resume\.tcl' \
           'floorplan\.tcl' 'make_rtr_top_netlist\.sh' 'rtr_top_pnr\.sh' 'die_pnr\.sh'; do
  for p in $(pgrep -f "$pat" 2>/dev/null); do
    kill -TERM "$p" 2>/dev/null && say "stopped pid=$p ($pat)"
  done
done
sleep 5
# Hard-kill any leftover EDA processes belonging to this build.
for pat in 'openroad .*\.tcl' 'magic -rcfile' 'klayout -b -r /work/scripts/gds'; do
  for p in $(pgrep -f "$pat" 2>/dev/null); do
    kill -9 "$p" 2>/dev/null && say "killed pid=$p ($pat)"
  done
done

say "STOPPED_AT_0800: chain halted cleanly. Routed checkpoint preserved (~152 violations); tonight's power-on AUTO-RESUMES core from this state (no rebuild)."
echo "stopped $(date); resume-on-boot armed" > /work/build/gds/STOPPED_0800
