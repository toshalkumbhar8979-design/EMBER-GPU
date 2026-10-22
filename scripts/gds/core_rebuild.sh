#!/usr/bin/env bash
# core_rebuild.sh — guarded, self-escalating rebuild of the ember_core block.
#
# Why this exists: ember_core is 347 k mapped cells / 389 k nets. A single
# 12-hour gamble on it fails in one of two ways, both of which waste the whole
# night:
#   * global_route never returns (worked 4 h at 13.6 GB in one run, no print),
#   * detailed_route plateaus (105 violations for two days) and never finishes.
# So: run attempts from a parameter ladder, watch each attempt for a STALL
# (log file stops growing), escalate automatically when an attempt stalls or
# comes back with more than GDS_MAX_VIOL violations, and keep whichever DEF is
# best. Nothing here re-synthesises: harden_block.sh reuses the synth cache.
#
# Usage (from /work):
#   bash scripts/gds/core_rebuild.sh                 # full ladder
#   bash scripts/gds/core_rebuild.sh --self-test     # exercise the logic only
#   GDS_STALL_MIN=15 GDS_MAX_VIOL=1000 bash scripts/gds/core_rebuild.sh
#
# Ladder: "util density pad tilt" — more area and more pin-access room each rung.
set -u

# OpenROAD/Magic/KLayout live in the nix store on this host; the openlane
# container has no PDK mount. Put them on PATH so the flow runs natively (this
# is how ember_autostart.sh set the environment up).
if ! command -v openroad >/dev/null 2>&1; then
  for d in /nix/store/*-openroad/bin /nix/store/*-magic-vlsi/bin /nix/store/*-klayout/bin; do
    [ -d "$d" ] && PATH="$d:$PATH"
  done
  export PATH
fi
# harden_block.sh runs yosys under a python RSS guard that needs psutil; the
# cocotb venv is the only python here that has it.
if [ -x "$HOME/.venvs/cocotb2/bin/python3" ]; then
  PATH="$HOME/.venvs/cocotb2/bin:$PATH"
  export PATH
fi
# The synth caches in /work/build/gds were built with flow tag h2; without
# this every rung would re-synthesise (and core's netlist needs fpu4 to be
# linked, which the cached synth.v already has).
export GDS_FLOW_TAG="${GDS_FLOW_TAG:-h2}"
NAME=core
TOP=ember_core
VFILE=build/gds/core.v
OUT=/work/build/gds/$NAME
STATUS=$OUT/CORE_STATUS.log
STALL_MIN=${GDS_STALL_MIN:-20}       # minutes of log silence => stuck
MAX_VIOL=${GDS_MAX_VIOL:-1000}       # a rung worse than this escalates
DRT_ITER=${GDS_DRT_ITER:-60}
BUDGET=${GDS_PNR_TIMEOUT:-14400}     # seconds per rung
LADDER=${GDS_LADDER:-"12 0.18 2 0.25
10 0.14 3 0.30
8 0.12 4 0.35"}

say() { echo "$(date '+%F %T') | $*" | tee -a "$STATUS"; }

# ---------------------------------------------------------------- helpers ---
# Last DRT violation count in a log (empty when routing never reported one).
viol() { grep -oE 'Number of violations = [0-9]+' "$1" 2>/dev/null | tail -1 | grep -oE '[0-9]+'; }

# How many iterations reported a count (per-iteration reports come from
# -drc_report_iter_step 2 in harden_block.sh).
iters() { grep -cE 'Number of violations =' "$1" 2>/dev/null; }

# decide <violations> <best-so-far>
#   done     -> routing is clean, stop
#   keep     -> usable result under MAX_VIOL, keep and stop escalating
#   escalate -> worse than MAX_VIOL or unusable, try the next rung
decide() {
  v=$1; best=${2:-999999}
  if [ -z "$v" ]; then echo escalate; return; fi
  if [ "$v" -eq 0 ]; then echo done; return; fi
  if [ "$v" -le "$best" ] && [ "$v" -le "$MAX_VIOL" ]; then echo keep; return; fi
  echo escalate
}

# kill_tree <pid> [signal]: signal a process and every descendant.
#
# WHY NOT JUST THE PROCESS GROUP: on 2026-10-23 the stall kill left orphaned
# openroad processes behind (logged `-- -pgid` did not reach them), and three
# of them then ran at once, competing for the 8 cores and invalidating the
# measurements. Walk the tree explicitly instead.
kill_tree() {
  p=$1; sig=${2:-TERM}; c=
  for c in $(pgrep -P "$p" 2>/dev/null); do kill_tree "$c" "$sig"; done
  kill -"$sig" "$p" 2>/dev/null || true
}

# watch_stall <pid> <minutes>: kill the attempt's process group when it stops
# consuming CPU.
#
# WHY CPU AND NOT LOG SIZE: the first version watched rebuild_rN.log and killed
# a perfectly healthy rung 1 at 00:42 on 2026-10-23, because that file only gets
# harden_block.sh's stage headers -- the real progress goes to openroad.log, and
# OpenROAD's repair_timing prints nothing for tens of minutes while it works
# (log frozen 00:26:50 -> 00:42:10 at 342% CPU). Watching even openroad.log has
# the same flaw. CPU time of the whole process tree only stops advancing when
# the run is actually wedged (the GRT 13.6 GB silent hang had ~0% CPU).
watch_stall() {
  w=$1; mins=$2
  last=-1; idle=0
  while kill -0 "$w" 2>/dev/null; do
    sleep 60
    cpu=$(python3 - "$w" <<'PY' 2>/dev/null || echo -1
# stdlib only (/proc), so the watchdog works under any python3: psutil is only
# installed in the cocotb venv, and a missing psutil used to mean "never kill".
import os, sys
root = int(sys.argv[1])
def field(pid, i):
    with open('/proc/%d/stat' % pid) as f:
        return f.read().rsplit(')', 1)[1].split()[i]
def cpu(pid):
    # utime/stime are fields 14/15; after the ')' they start at field 3
    return int(field(pid, 11)) + int(field(pid, 12))
tree = {root}
grown = True
while grown:
    grown = False
    for d in os.listdir('/proc'):
        if not d.isdigit():
            continue
        p = int(d)
        if p in tree:
            continue
        try:
            if int(field(p, 1)) in tree:
                tree.add(p)
                grown = True
        except OSError:
            pass
total = 0
for p in tree:
    try:
        total += cpu(p)
    except OSError:
        pass  # exited between the scan and the read
print(total)
PY
)
    # -1 = cannot measure (no psutil): never claim a stall, the rung budget
    # timeout is the backstop.
    if [ "${cpu:--1}" -lt 0 ] 2>/dev/null; then last=-1; continue; fi
    if [ "$cpu" = "$last" ]; then
      idle=$((idle + 1))
      if [ "$idle" -ge "$mins" ]; then
        say "STALL: no CPU progress for ${idle} min (cpu=${cpu}s) -> killing attempt"
        kill -TERM -- "-$w" 2>/dev/null || true
        kill_tree "$w" TERM
        sleep 5
        kill -KILL -- "-$w" 2>/dev/null || true
        kill_tree "$w" KILL
        return
      fi
    else
      idle=0
    fi
    last=$cpu
  done
}

# -------------------------------------------------------------- self-test ---
if [ "${1:-}" = "--self-test" ]; then
  TD=$(mktemp -d); fail=0
  chk() { if [ "$2" = "$3" ]; then echo "ok   $1 = $3"; else echo "FAIL $1 = $2 (want $3)"; fail=1; fi; }
  printf 'Number of violations = 238451\nNumber of violations = 9172\n' > "$TD/a.log"
  chk "last count" "$(viol "$TD/a.log")" "9172"
  chk "iterations" "$(iters "$TD/a.log")" "2"
  : > "$TD/empty.log"
  chk "no count" "$(viol "$TD/empty.log")" ""
  chk "clean" "$(decide 0 100)" "done"
  chk "under cap" "$(decide 840 5000)" "keep"
  chk "over cap" "$(decide 238451 5000)" "escalate"
  chk "bad rung" "$(decide 900 300)" "escalate"
  chk "never routed" "$(decide "" 300)" "escalate"
  rm -rf "$TD"
  exit $fail
fi

# -------------------------------------------------------------- preflight ---
# Fail in seconds instead of hanging: every stage needs the tools on PATH, the
# PDK, and the self-contained block netlist.
preflight() {
  for t in yosys openroad magic klayout; do
    command -v "$t" >/dev/null 2>&1 || echo "TOOL MISSING: $t"
  done
  pdk=$(ls -d "$HOME"/.volare/volare/sky130/versions/*/sky130A 2>/dev/null | head -1)
  [ -n "$pdk" ] || echo "PDK NOT FOUND under $HOME/.volare"
  [ -f "$VFILE" ] || echo "NETLIST NOT FOUND: $VFILE (run the synthesis stage first)"
}

# ------------------------------------------------------------------ main ----
mkdir -p "$OUT"
preflight_out=$(preflight)
if [ -n "$preflight_out" ]; then
  echo "CORE REBUILD PRECHECK FAILED:"
  echo "$preflight_out" | sed 's/^/  /'
  echo "Fix the environment, then re-run. Nothing was started."
  exit 4
fi
say "CORE REBUILD start: ladder='$(echo "$LADDER" | tr '\n' ';')' cap=$MAX_VIOL stall=${STALL_MIN}m rung-budget=${BUDGET}s"

rung=0
best=999999
best_str=""
# one ladder rung per LINE: "util density pad tilt"
while IFS=' ' read -r util dens pad tilt; do
  [ -z "${util:-}" ] && continue
  rung=$((rung + 1))
  log=$OUT/rebuild_r$rung.log
  say "RUNG $rung: util=$util density=$dens pad=$pad tilt=$tilt"

  setsid env GDS_UTIL="$util" GDS_PL_DENSITY="$dens" GDS_PL_PAD="$pad" \
    GDS_GRT_TILT="$tilt" GDS_DRT_ITER="$DRT_ITER" \
    GDS_PNR_TIMEOUT="$BUDGET" \
    bash /work/scripts/gds/harden_block.sh "$NAME" "$TOP" "$VFILE" \
    </dev/null > "$log" 2>&1 &
  pid=$!
  watch_stall "$pid" "$STALL_MIN" &
  watcher=$!
  wait "$pid"; rc=$?
  kill "$watcher" 2>/dev/null; wait "$watcher" 2>/dev/null

  v=$(viol "$log")
  say "RUNG $rung done rc=$rc violations=${v:-none} drt-reports=$(iters "$log")"

  # keep the best routed DEF this flow has produced
  if [ -n "$v" ] && [ "$v" -lt "$best" ]; then
    best=$v
    if [ -s "$OUT/final.def" ]; then
      cp -f "$OUT/final.def" "$OUT/best_${v}_final.def" 2>/dev/null || true
      best_str="final.def@$v"
    fi
  fi

  case $(decide "$v" "$best") in
    done)
      say "CLEAN: routing reached zero violations on rung $rung"
      echo 0 > "$OUT/ROUTING_ZERO_VIOLATIONS"
      exit 0
      ;;
    keep)
      say "ACCEPT: ${v} violations (cap $MAX_VIOL) -- best DEF kept, not escalating"
      echo "$v" > "$OUT/ROUTING_RESIDUAL_VIOLATIONS"
      exit 0
      ;;
    *)
      say "ESCALATE: rung $rung unusable (violations=${v:-none})"
      ;;
  esac
done <<< "$LADDER"

say "CORE REBUILD exhausted the ladder; best=${best} (${best_str:-no routed DEF})"
echo "${best}" > "$OUT/ROUTING_RESIDUAL_VIOLATIONS"
[ "$best" -le "$MAX_VIOL" ] || echo "${best} > ${MAX_VIOL} $(date)" > "$OUT/CORE_NEEDS_ATTENTION"
exit 1
