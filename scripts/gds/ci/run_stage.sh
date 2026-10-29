#!/usr/bin/env bash
# run_stage.sh <block> <synth|place|grt|drt|gds>
#
# Runs ONE stage of the block flow inside the OpenLane container and leaves a
# checkpoint plus ci_stage.json in build/gds/<block>/. The GitHub workflow calls
# this once per job; nothing here depends on a previous stage still being in
# memory, so a killed job never loses completed work.
#
# Env: GDS_ROOT (default /work), GDS_PDK, GDS_STAGE_TIMEOUT (seconds),
#      plus the usual GDS_UTIL / GDS_PL_DENSITY / GDS_PL_PAD / GDS_GRT_TILT /
#      GDS_DRT_ITER / GDS_THREADS / GDS_REPAIR_TIMING knobs.
set -o pipefail
ROOT=${GDS_ROOT:-/work}
NAME=${1:?usage: run_stage.sh <block> <stage>}
STAGE=${2:?usage: run_stage.sh <block> <stage>}
BLOCKS=$ROOT/scripts/gds/blocks.txt

[ -f "$BLOCKS" ] || { echo "NO blocks.txt at $BLOCKS"; exit 2; }
LINE=$(grep -m1 "^${NAME}|" "$BLOCKS" || true)
[ -n "$LINE" ] || { echo "BLOCK NOT IN blocks.txt: $NAME"; exit 2; }
IFS='|' read -r _b TOP SRCS OVERRIDES <<< "$LINE"
[ -n "$TOP" ] || { echo "NO TOP FOR $NAME"; exit 2; }

# blocks.txt per-block tuning is a DEFAULT: an explicitly exported value from
# the workflow (e.g. GDS_UTIL=12) wins.
for kv in $OVERRIDES; do
  k=${kv%%=*}; v=${kv#*=}
  if [ -z "${!k:-}" ]; then export "$k=$v"; fi
done

PDK=${GDS_PDK:-}
[ -n "$PDK" ] || { echo "GDS_PDK is not set"; exit 3; }
[ -d "$PDK" ] || { echo "GDS_PDK does not exist: $PDK"; exit 3; }
OUT=$ROOT/build/gds/$NAME
mkdir -p "$OUT"
export GDS_ROOT="$ROOT" GDS_PDK="$PDK" GDS_STAGE="$STAGE"

TMO=${GDS_STAGE_TIMEOUT:-19800}
START=$(date +%s)
echo "CI_STAGE: block=$NAME top=$TOP stage=$STAGE timeout=${TMO}s"
echo "CI_ENV: util=${GDS_UTIL:-default} density=${GDS_PL_DENSITY:-default} pad=${GDS_PL_PAD:-0} tilt=${GDS_GRT_TILT:-off} drt_iter=${GDS_DRT_ITER:-20} threads=${GDS_THREADS:-4} repair_timing=${GDS_REPAIR_TIMING:-1}"
nproc
free -g 2>/dev/null | head -2 || true

abspath() { case "$1" in /*) echo "$1";; *) echo "$ROOT/$1";; esac; }

case "$STAGE" in
  synth)
    # Yosys cannot read the SystemVerilog package/struct sources directly;
    # harden_block.sh consumes the sv2v-converted, self-contained netlist that
    # sv2vall.sh writes to build/gds/<name>.v (tracked for core/rtr_*/gsx).
    VF=$ROOT/build/gds/$NAME.v
    if [ ! -s "$VF" ]; then
      echo "MISSING $VF -- run scripts/gds/sv2vall.sh first"
      exit 3
    fi
    # harden_block.sh with GDS_SYNTH_ONLY=1 stops after validate_synth.py.
    export GDS_SYNTH_ONLY=1
    timeout "$TMO" bash "$ROOT/scripts/gds/harden_block.sh" "$NAME" "$TOP" "$VF"
    RC=$?
    ;;
  place|grt|drt)
    timeout "$TMO" openroad -no_init -exit "$ROOT/scripts/gds/ci/pnr.tcl" \
      > "$OUT/openroad_$STAGE.log" 2>&1
    RC=$?
    tail -25 "$OUT/openroad_$STAGE.log" || true
    if [ "$STAGE" = drt ]; then cp -f "$OUT/openroad_drt.log" "$OUT/openroad.log"; fi
    ;;
  gds)
    timeout "$TMO" bash "$ROOT/scripts/gds/ci/gds_stage.sh" "$NAME" "$TOP"
    RC=$?
    ;;
  *)
    echo "UNKNOWN STAGE: $STAGE"; exit 2;;
esac

END=$(date +%s)
DUR=$((END - START))
# Metrics: the workflow prints this file into the job summary.
VIOL=""
for L in "$OUT/openroad.log" "$OUT/openroad_drt.log" "$OUT/rebuild_r1.log"; do
  [ -f "$L" ] || continue
  V=$(grep -oE 'Number of violations = [0-9]+' "$L" 2>/dev/null | tail -1 | grep -oE '[0-9]+$' || true)
  [ -n "$V" ] && VIOL=$V
done
[ -n "$VIOL" ] || VIOL=$(grep -oE 'Number of violations = [0-9]+' "$OUT"/openroad_*.log 2>/dev/null | tail -1 | grep -oE '[0-9]+$' || true)
AREA=$(grep -oE 'CORE_AREA_UM2=[0-9.]+' "$OUT"/openroad_*.log 2>/dev/null | tail -1 | grep -oE '[0-9.]+$' || true)
[ -n "$AREA" ] || AREA=$(grep -oE 'DESIGN_AREA:? ?[0-9.]+' "$OUT"/openroad_*.log 2>/dev/null | tail -1 | grep -oE '[0-9.]+$' || true)
GDS_BYTES=""; [ -f "$OUT/$NAME.gds" ] && GDS_BYTES=$(wc -c < "$OUT/$NAME.gds")
CKPT=""
for f in placed.odb grt.odb final.def; do
  [ -s "$OUT/$f" ] && CKPT="${CKPT:+$CKPT }$f"
done
cat > "$OUT/ci_stage.json" <<JSON
{
  "block": "$NAME",
  "top": "$TOP",
  "stage": "$STAGE",
  "rc": $RC,
  "seconds": $DUR,
  "threads": ${GDS_THREADS:-4},
  "util": "${GDS_UTIL:-}",
  "density": "${GDS_PL_DENSITY:-}",
  "pad": "${GDS_PL_PAD:-0}",
  "tilt": "${GDS_GRT_TILT:-}",
  "drt_iter": "${GDS_DRT_ITER:-}",
  "repair_timing": "${GDS_REPAIR_TIMING:-1}",
  "violations": "${VIOL:-}",
  "design_area": "${AREA:-}",
  "gds_bytes": "${GDS_BYTES:-}",
  "checkpoints": "$CKPT",
  "finished": "$(date -u +%FT%TZ)"
}
JSON
echo "CI_RESULT: rc=$RC seconds=$DUR violations=${VIOL:-none} checkpoints=${CKPT:-none}"
exit "$RC"
