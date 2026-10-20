#!/usr/bin/env bash
# salvage_tu_def2gds.sh -- tu salvage via the KLayout DEF->GDS fallback.
#
# tu's Magic streamout wedges deterministically at exactly 111,153,152 B on
# every attempt (4th byte-identical repro 2026-10-16; see agentbible). The
# documented recovery is "salvage from final.def": KLayout exports the routed
# DEF (def2gds.py, proven against blit -- identical bbox and zero Magic DRC),
# then the flow's standard content-bound gates run unchanged:
#   finalize.py  -> gds_validation.json
#   audit_export.py -> export_audit.json (flattened Magic DRC, drc(full))
#   verify_block.py -> the queue's own acceptance check
# Routing evidence (openroad.log "Number of violations = 0") is inherited
# from the completed 2026-10-06 PnR and re-checked by verify_block.py.
set -u
NAME=tu
TOP=ember_tu
DIR=/work/build/gds/$NAME
cd "$DIR" || exit 1
PDK=$(ls -d $HOME/.volare/volare/sky130/versions/*/sky130A 2>/dev/null | head -1)
[ -n "$PDK" ] || { echo "PDK NOT FOUND"; exit 3; }
[ -f final.def ] || { echo "final.def missing"; exit 3; }
# pya-capable python and magic both live in emberbin (proven tool paths).
export PATH="$HOME/.local/emberbin:$PATH"
PY=python3

wait_ram() {  # $1 = GiB required before continuing
python3 - "$1" <<'PY'
import sys, time, psutil
need = float(sys.argv[1]) * 2**30
while psutil.virtual_memory().available < need:
    time.sleep(30)
PY
}

echo "== [$NAME] KLayout DEF->GDS export (fallback for Magic streamout wedge) =="
rm -f "$NAME.gds"
wait_ram 3
PDK="$PDK" KLAYOUT_DEF="$DIR/final.def" KLAYOUT_TOP="$TOP" \
  KLAYOUT_OUT="$DIR/$NAME.gds" GDS_MAGIC_TIMEOUT=14400 \
  nice -n 10 "$HOME/.local/emberbin/python3" /work/scripts/gds/def2gds.py \
  > def2gds.log 2>&1 || { echo "DEF2GDS FAILED"; tail -10 def2gds.log; exit 4; }
[ -s "$NAME.gds" ] || { echo "def2gds wrote no GDS"; exit 4; }
ls -la "$NAME.gds"

echo "== [$NAME] KLayout finalize =="
wait_ram 3
KLAYOUT_IN="$NAME.gds" KLAYOUT_OUT="${NAME}_final.gds" KLAYOUT_TOP="$TOP" \
  "$PY" /work/scripts/gds/finalize.py \
  > klayout.log 2>&1 || { echo "GDS VALIDATION FAILED"; tail -10 klayout.log; exit 2; }
mv "${NAME}_final.gds" "$NAME.gds" || exit 2

echo "== [$NAME] independent export audit (Magic flattened DRC) =="
wait_ram 3
GDS_AUDIT_TIMEOUT=28800 nice -n 10 "$PY" /work/scripts/gds/audit_export.py "$NAME" \
  > export_audit_run.log 2>&1 || { echo "EXPORTED GDS AUDIT FAILED"; tail -10 export_audit_run.log; exit 4; }
EDRC=$(python3 -c 'import json; print(json.load(open("export_audit.json"))["whole_layout_flattened_drc"])')
RDRC=$(grep 'Number of violations =' openroad.log | tail -1)
if [[ "$RDRC" != *'= 0.'* ]] || [ "$EDRC" != 0 ]; then
  echo "GDS GENERATED, CHECKS NOT CLEAN: routing=[$RDRC] audit=[$EDRC]"
  exit 4
fi
python3 /work/scripts/gds/verify_block.py "$NAME" || exit 4
echo "== [$NAME] SALVAGE DONE (KLayout export, zero routing + flattened DRC) =="
