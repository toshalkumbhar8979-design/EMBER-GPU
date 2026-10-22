#!/usr/bin/env bash
# watch_stall_test.sh — regression test for core_rebuild.sh's stall watchdog.
#
# Why: the first watchdog watched a log file and killed a healthy rung at 00:42
# on 2026-10-23 (OpenROAD's repair_timing ran 342% CPU for 16 min without
# printing a line). These cases pin the replacement (CPU-progress) behaviour:
#   1. quiet-but-busy process  -> must NOT be killed
#   2. wedged (sleeping) process -> MUST be killed
# Usage: bash test/watch_stall_test.sh [script]
set -u
SRC=${1:-/work/scripts/gds/core_rebuild.sh}
[ -f "$SRC" ] || { echo "FAIL: $SRC not found"; exit 2; }

# Pull just the watch_stall function out of the rebuild script, plus a stub say().
TD=$(mktemp -d)
awk '/^watch_stall\(\) \{/{p=1} p{print} p&&/^\}/{exit}' "$SRC" > "$TD/fn.sh"
grep -q '/proc' "$TD/fn.sh" || { echo "FAIL: extracted function is not the CPU-based watchdog"; exit 1; }
printf 'say() { echo "  say: $*"; }\n' | cat - "$TD/fn.sh" > "$TD/harness.sh"

fail=0
run() { bash -c "source '$TD/harness.sh'; $1" ; }

echo "-- case 1: quiet but busy (must survive 90s at mins=1)"
# plain background jobs (no setsid): setsid may fork, leaving $! a dead pid
# and making both cases pass or fail for the wrong reason.
bash -c 's=0; while :; do s=$((s+1)); done' >/dev/null 2>&1 &
busy=$!
sleep 0.3
bash -c "source '$TD/harness.sh'; watch_stall $busy 1" &
w=$!
sleep 90
if kill -0 "$busy" 2>/dev/null; then echo "ok   busy process survived"; else echo "FAIL busy process was killed"; fail=1; fi
kill -KILL "$busy" 2>/dev/null; wait "$busy" 2>/dev/null; kill "$w" 2>/dev/null; wait "$w" 2>/dev/null

echo "-- case 2: wedged process (must be killed at mins=1)"
sleep 600 >/dev/null 2>&1 &
idle=$!
sleep 0.3
t0=$SECONDS
bash -c "source '$TD/harness.sh'; watch_stall $idle 1" > "$TD/w2.log" 2>&1 &
w=$!
# The watchdog samples once a minute and needs two equal samples before it
# counts a minute of idle, so the first kill opportunity is ~2 min in: allow 3.
for _ in $(seq 1 60); do
  kill -0 "$idle" 2>/dev/null || break
  sleep 3
done
if kill -0 "$idle" 2>/dev/null; then echo "FAIL wedged process still alive after 180s"; fail=1
else echo "ok   wedged process killed after $((SECONDS - t0))s"; fi
grep -q "no CPU progress" "$TD/w2.log" && echo "ok   stall reported" || { echo "FAIL no stall message"; cat "$TD/w2.log"; fail=1; }
kill -KILL "$idle" 2>/dev/null; kill "$w" 2>/dev/null

rm -rf "$TD"
[ "$fail" = 0 ] && echo "PASS watch_stall" || echo "FAIL watch_stall"
exit "$fail"
