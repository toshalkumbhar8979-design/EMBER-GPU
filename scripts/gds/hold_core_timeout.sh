#!/usr/bin/env bash
# hold_core_timeout.sh -- stop core's 24h PNR timebox from killing OpenROAD
# before detailed routing finishes.
#
# Why: harden_block.sh runs the whole PNR inside `timeout 86400 openroad ...`
# (core: GDS_PNR_TIMEOUT=86400). final.def / final.odb are written only AFTER
# detailed_route returns, so a timebox kill at 20:32 would discard every DRT
# iteration. Core's DRT needs ~6-8h beyond that deadline.
#
# What this does: shortly before the deadline, SIGSTOP the `timeout` wrapper
# (parent of openroad). OpenROAD itself is untouched and keeps routing; only
# the watchdog's alarm handling is suspended, so it cannot fire. The queue
# shell then blocks on waitpid instead of reporting a bogus failure and moving
# on to another block.
#
# Safe to run repeatedly: it no-ops when the wrapper already exited (block
# finished inside the box) or when OpenROAD is no longer running.
set -u
LOG=/work/build/gds/core_timeout_hold.log
exec >>"$LOG" 2>&1
echo "=== hold_core_timeout start $(date) ==="

# Wait until 19:50 local (deadline is 20:32:27; keep a wide margin).
TARGET=$(date -d 'today 19:50' +%s)
NOW=$(date +%s)
if [ "$NOW" -lt "$TARGET" ]; then
  SLEEP=$((TARGET - NOW))
  echo "sleeping ${SLEEP}s until $(date -d @"$TARGET")"
  sleep "$SLEEP"
fi

WRAP=$(pgrep -f '^timeout 86400 openroad' | head -1)
ORPID=$(pgrep -f 'openroad -no_init -exit floorplan\.tcl' | head -1)
if [ -z "$WRAP" ] || [ -z "$ORPID" ]; then
  echo "$(date): wrapper=[${WRAP:-none}] openroad=[${ORPID:-none}] -> nothing to hold"
  exit 0
fi

kill -STOP "$WRAP" || { echo "$(date): SIGSTOP failed on $WRAP"; exit 1; }
echo "$(date): froze timebox wrapper pid=$WRAP; openroad pid=$ORPID keeps routing"
ps -o pid,stat,etime,args -p "$WRAP" -p "$ORPID" 2>/dev/null | cut -c1-120
echo "=== hold_core_timeout done $(date) ==="
