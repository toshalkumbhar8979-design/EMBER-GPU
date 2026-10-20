#!/usr/bin/env bash
# salvage_magic_final.sh -- redo ONLY the Magic merge/DRC + KLayout finalize +
# independent export audit for a block whose detailed routing already completed.
#
# Motivated by fpu4 (2026-10-03): its 2700 s magic box expired mid-gds-write,
# truncating fpu4.gds after 2h15m of successful PnR (final.def with zero
# routing violations). Re-running the whole flow would repeat that PnR; this
# script reuses final.def and repeats only the export stages, with a longer
# default magic box and RAM headroom guards so it can run beside the primary
# queue without risking the 16 GB WSL cap.
#
# Usage (inside the container): bash salvage_magic_final.sh <name> [top]
set -u
NAME=${1:?block name required}
TOP=${2:-ember_$NAME}
DIR=/work/build/gds/$NAME
cd "$DIR" || exit 1
[ -f magic.tcl ] || { echo "magic.tcl missing in $DIR (run the snapshot flow first)"; exit 1; }
[ -f final.def ] || { echo "final.def missing in $DIR"; exit 1; }
PDK=$(ls -d $HOME/.volare/volare/sky130/versions/*/sky130A 2>/dev/null | head -1)
[ -n "$PDK" ] || { echo "PDK NOT FOUND"; exit 3; }
grep -q "lef read $PDK" magic.tcl || { echo "magic.tcl PDK path mismatch"; exit 3; }

wait_ram() {  # $1 = GiB required before continuing
python3 - "$1" <<'PY'
import sys, time, psutil
need = float(sys.argv[1]) * 2**30
while psutil.virtual_memory().available < need:
    time.sleep(30)
PY
}

# The previous failure mode: timeout killed magic mid-gds-write -> truncated
# GDS. Remove the stale file so every check below sees only fresh output.
rm -f "$NAME.gds" "${NAME}_final.gds"
echo "== [$NAME] magic merge + DRC (box ${GDS_MAGIC_TIMEOUT:-10800}s) =="
wait_ram 3
timeout "${GDS_MAGIC_TIMEOUT:-10800}" magic -rcfile .magicrc -dnull -noconsole magic.tcl > magic.log 2>&1 \
  || { echo "MAGIC FAILED"; tail -5 magic.log; exit 4; }
grep -m1 '^DRC_COUNT=' magic.log || { echo "no DRC_COUNT in magic.log"; exit 4; }
[ -f "$NAME.gds" ] || { echo "magic wrote no GDS"; exit 4; }
echo "== [$NAME] KLayout finalize =="
wait_ram 5
KLAYOUT_IN="$NAME.gds" KLAYOUT_OUT="${NAME}_final.gds" KLAYOUT_TOP="$TOP" \
  klayout -b -r /work/scripts/gds/finalize.py > klayout.log 2>&1 \
  || { echo "GDS VALIDATION FAILED"; tail -10 klayout.log; exit 2; }
mv "${NAME}_final.gds" "$NAME.gds" || exit 2
ls -la "$NAME.gds"
echo "== [$NAME] independent export audit =="
wait_ram 3
python3 /work/scripts/gds/audit_export.py "$NAME" > export_audit_run.log 2>&1 \
  || { echo "EXPORTED GDS AUDIT FAILED"; tail -10 export_audit_run.log; exit 4; }
EDRC=$(python3 -c 'import json; print(json.load(open("export_audit.json"))["whole_layout_flattened_drc"])')
# A file existing is NOT sign-off. Routing, Magic whole-layout DRC and the
# independent reimport audit must all be explicitly zero.
RDRC=$(grep 'Number of violations =' openroad.log | tail -1)
MDRC=$(grep '^DRC_COUNT=' magic.log | tail -1)
if [[ "$RDRC" != *'= 0.'* ]] || [ "$MDRC" != 'DRC_COUNT=0' ] || [ "$EDRC" != 0 ]; then
  echo "GDS GENERATED, CHECKS NOT CLEAN: routing=[$RDRC] magic=[$MDRC] audit=[$EDRC]"
  exit 4
fi
echo "== [$NAME] SALVAGE DONE (validated GDS, routing and Magic DRC zero) =="
