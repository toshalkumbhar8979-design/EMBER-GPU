#!/usr/bin/env bash
# core_status.sh [sample-seconds] — one-shot status of the running core P&R.
#
# Prints the rung the ladder is on, the last lines OpenROAD wrote, whether its
# CPU time is still advancing over the sample window (a wedged run shows a
# frozen log AND frozen CPU), and memory.
set -u
SAMPLE=${1:-60}
OUT=/work/build/gds/core

echo "== $(date '+%F %T')"
echo "-- ladder"
tail -3 "$OUT/CORE_STATUS.log" 2>/dev/null | sed 's/^/   /'
echo "-- rung log (last 3)"
tail -3 "$OUT/rebuild_r1.log" 2>/dev/null | sed 's/^/   /'
echo "-- openroad.log (last 3)  [mtime $(date -r "$OUT/openroad.log" '+%H:%M:%S' 2>/dev/null)]"
tail -3 "$OUT/openroad.log" 2>/dev/null | sed 's/^/   /'

pid=$(ps -eo pid,cmd | grep 'openroad -no_init' | grep -v grep | tail -1 | sed 's/^ *//;s/ .*//')
if [ -z "$pid" ]; then
  echo "-- no openroad process"
else
  t1=$(ps -o time= -p "$pid" | tr -d ' ')
  rss1=$(ps -o rss= -p "$pid" | tr -d ' ')
  sleep "$SAMPLE"
  t2=$(ps -o time= -p "$pid" 2>/dev/null | tr -d ' ')
  rss2=$(ps -o rss= -p "$pid" 2>/dev/null | tr -d ' ')
  echo "-- pid $pid cpu ${t1:-?} -> ${t2:-gone}, rss $(( ${rss1:-0} / 1024 )) -> $(( ${rss2:-0} / 1024 )) MB over ${SAMPLE}s"
  [ "${t1:-x}" = "${t2:-y}" ] && echo "   WARNING: cpu time frozen (watchdog counts this)"
fi
free -m | sed -n 2p | sed 's/^/-- mem /'
