#!/usr/bin/env bash
# viol_recorder.sh -- detached violation-trend recorder (survives session end).
# Appends the latest DRT violation count to VIOL_TREND.log every 5 minutes and
# self-exits once routing reports zero violations. Single instance via pidfile.
set -u
PIDFILE=/work/build/gds/.viol_recorder.pid
LOG=/work/build/gds/VIOL_TREND.log
echo $$ > "$PIDFILE"
trap 'rm -f "$PIDFILE"' EXIT
while true; do
  T=$(date "+%F %T")
  P=$(ls -t /work/build/gds/core/openroad_resume_*.log 2>/dev/null | head -1)
  V=$(grep -h "Number of violations =" /work/build/gds/core/openroad_resume_*.log 2>/dev/null | tail -1 | grep -oE '[0-9]+\.?$?')
  L=$(tail -1 "$P" 2>/dev/null | tr -d '\r' | cut -c1-60)
  echo "$T | violations=${V:-?} | $L" >> "$LOG"
  if [ "$V" = "0" ] || [ "$V" = "0." ]; then
    echo "$T | ZERO reached, recorder exiting" >> "$LOG"
    exit 0
  fi
  sleep 300
done
