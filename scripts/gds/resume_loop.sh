#!/bin/bash
# resume_loop.sh -- RESUME-ONLY detailed routing rounds for ember_core.
# Reads final.odb each round (log shows RESUME_SOURCE=final.odb). NEVER rebuilds:
# no synthesis, no floorplan, no placement. Stops at violations = 0 or on round failure.
set -u
cd /work/build/gds/core || exit 1
OPENROAD=/nix/store/zzypcxbrgw1qink1l7fwgwpbk7fvdwpg-openroad/bin/openroad
STATUS=/work/build/gds/core/RESUME_LOOP_STATUS.log
log() { echo "$(date '+%F %T') $*" >> "$STATUS"; }

# Preserve the pristine checkpoint exactly once.
if [ ! -f final.odb.cp_initial ]; then
  cp -p final.odb final.odb.cp_initial
  cp -p final.def final.def.cp_initial
  log "archived pristine checkpoint -> final.odb.cp_initial / final.def.cp_initial"
fi

round=2
while true; do
  LOG=openroad_resume_${round}.log
  log "round ${round} START source=final.odb"
  "$OPENROAD" -no_init -exit route_resume.tcl > "$LOG" 2>&1
  rc=$?
  if grep -q "RESUME_ROUND_DONE" "$LOG"; then
    V=$(grep -oE "Number of violations = [0-9]+" "$LOG" | tail -1 | grep -oE "[0-9]+$")
    log "round ${round} DONE rc=${rc} violations=${V}"
    if [ -f final_new.odb ] && [ -f final_new.def ]; then
      mv -f final.odb final.odb.prev
      mv -f final_new.odb final.odb
      mv -f final.def final.def.prev
      mv -f final_new.def final.def
      log "round ${round} rotated final_new.* -> final.* (previous kept as *.prev)"
    else
      log "round ${round} ERROR: final_new.odb/def missing after DONE -- stopping (checkpoint untouched)"
      break
    fi
    if [ "${V:-1}" = "0" ]; then
      log "VIOLATIONS=0 -- detailed routing complete"
      touch /work/build/gds/core/ROUTING_ZERO_VIOLATIONS
      break
    fi
    round=$((round + 1))
  else
    log "round ${round} FAILED rc=${rc} -- no RESUME_ROUND_DONE, stopping loop (checkpoint untouched, NO REBUILD)"
    break
  fi
done
log "resume_loop exit"
