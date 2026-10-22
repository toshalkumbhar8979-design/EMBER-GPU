#!/usr/bin/env bash
# run_core_rebuild.sh — start (or resume) the guarded ember_core P&R ladder.
#
# Runs INSIDE WSL from /work. Detached with setsid+nohup so it survives the
# calling shell (and this agent's session). Two modes:
#
#   bash test/run_core_rebuild.sh synth   # synthesis only, then stop
#   bash test/run_core_rebuild.sh pnr     # floorplan/place/CTS/route ladder
#
# Output: /work/build/gds/core/CORE_STATUS.log (one line per rung) and
# /work/build/gds/core/rebuild_r<N>.log / synth_r1.log (full tool logs).
set -euo pipefail
MODE=${1:-pnr}
cd /work

# The flow's RSS watchdog imports psutil; only the cocotb venv has it.
PATH="$HOME/.venvs/cocotb2/bin:$PATH"; export PATH

# Synth caches in /work/build/gds were produced under flow tag h2 — keep the
# tag stable or every rung re-synthesises.
export GDS_FLOW_TAG=${GDS_FLOW_TAG:-h2}
# Recipe (see blocks.txt): whitespace + met1 pin-access corridors.
export GDS_UTIL=12 GDS_PL_DENSITY=0.18 GDS_PL_PAD=2 GDS_GRT_TILT=0.25
export GDS_DRT_ITER=${GDS_DRT_ITER:-60}
export GDS_SYNTH_TIMEOUT=${GDS_SYNTH_TIMEOUT:-5400}
# 12 h per rung (core is the only block that needs it -- blocks.txt asks for the
# same) and ONE timing-repair pass instead of two: rung 1 spent 60+ min inside
# repair_timing on 34,688 endpoints at 300% CPU before the budget clock was even
# a third gone, and DRT is what the night is actually for.
export GDS_PNR_TIMEOUT=${GDS_PNR_TIMEOUT:-43200}
export GDS_TIMING_PASSES=${GDS_TIMING_PASSES:-1}
export GDS_THREADS=${GDS_THREADS:-6}

mkdir -p build/gds/core
case "$MODE" in
  synth)
    LOG=build/gds/core/synth_r1.log
    setsid nohup env GDS_SYNTH_ONLY=1 \
      bash scripts/gds/harden_block.sh core ember_core build/gds/core.v \
      </dev/null >"$LOG" 2>&1 &
    echo "started synth-only, pid $! -> $LOG"
    ;;
  pnr)
    LOG=build/gds/core/CORE_REBUILD.out
    setsid nohup bash scripts/gds/core_rebuild.sh </dev/null >"$LOG" 2>&1 &
    echo "started P&R ladder, pid $! -> $LOG"
    ;;
  *)
    echo "usage: $0 [synth|pnr]" >&2; exit 2;;
esac
