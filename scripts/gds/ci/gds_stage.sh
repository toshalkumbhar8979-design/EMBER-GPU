#!/usr/bin/env bash
# gds_stage.sh <name> <top> -- Magic merge/DRC, KLayout finalize, exported-GDS audit.
#
# Extracted from harden_block.sh so the final stage can run as its own CI job
# after the router has produced final.def. Takes an existing DEF and never
# places, routes or synthesises anything.
#
# Env: GDS_ROOT (default /work), GDS_PDK, GDS_MAGIC_TIMEOUT, GDS_AUDIT_TIMEOUT,
#      GDS_KEEP_GLOBAL_ROUTE=1 (fall back to global_route.def if final.def is
#      absent, labelled "global-route").
set -o pipefail
NAME=$1; TOP=$2
ROOT=${GDS_ROOT:-/work}
OUT=$ROOT/build/gds/$NAME

PDK=${GDS_PDK:-}
if [ -z "$PDK" ] && [ -n "${PDK_ROOT:-}" ] && [ -d "$PDK_ROOT/sky130A" ]; then PDK=$PDK_ROOT/sky130A; fi
if [ -z "$PDK" ]; then PDK=$(ls -d "$HOME"/.volare/volare/sky130/versions/*/sky130A 2>/dev/null | head -1); fi
[ -n "$PDK" ] || { echo "PDK NOT FOUND (set GDS_PDK or PDK_ROOT)"; exit 3; }
[ -d "$OUT" ] || { echo "NO BLOCK DIR: $OUT"; exit 3; }
cd "$OUT" || exit 3

DEF=final.def; FLOWN=detailed-route
if [ ! -f final.def ]; then
  if [ -f global_route.def ] && [ "${GDS_KEEP_GLOBAL_ROUTE:-0}" = 1 ]; then
    DEF=global_route.def; FLOWN=global-route
  else
    echo "NO DEF (detailed route checkpoint missing)"; exit 1
  fi
fi
echo "$FLOWN" > flow.txt
echo "   using DEF: $DEF ($FLOWN)"

echo "== [$NAME] 3/4 Magic GDS merge + DRC =="
# Magic auto-reads .magicrc from the cwd; it must load the sky130A tech and put
# full-cell .mag views ahead of LEF abstracts, or gds write refuses.
cat > .magicrc <<EOF
set PDKPATH $PDK
tech load \$PDKPATH/libs.tech/magic/sky130A.tech
scalegrid 1 2
addpath \$PDKPATH/libs.ref/sky130_fd_sc_hd/mag
addpath \$PDKPATH/libs.ref/sky130_fd_sc_hd/maglef
drc euclidean on
EOF
cat > magic.tcl <<EOF
lef read $PDK/libs.ref/sky130_fd_sc_hd/techlef/sky130_fd_sc_hd__nom.tlef
gds read $PDK/libs.ref/sky130_fd_sc_hd/gds/sky130_fd_sc_hd.gds
def read $DEF
load $TOP -dereference
gds write $NAME.gds
flatten ${TOP}_drc_flat
load ${TOP}_drc_flat
select top cell
box select
drc on
drc style drc(full)
drc check
drc catchup
set drcerr [drc list count total]
puts "DRC_DETAILS=[drc listall why]"
puts "DRC_COUNT=\$drcerr"
EOF
# 3 h default: fpu4's gds write was truncated at 45 min mid-stream once.
timeout "${GDS_MAGIC_TIMEOUT:-10800}" magic -rcfile .magicrc -dnull -noconsole magic.tcl > magic.log 2>&1 \
  || echo "MAGIC FAIL (falling back to KLayout DEF->GDS)"
grep -m1 DRC_COUNT magic.log || echo "DRC_COUNT=?"

if [ ! -f "$NAME.gds" ]; then
  echo "   Magic produced no GDS -> KLayout DEF->GDS fallback"
  PDK="$PDK" KLAYOUT_DEF="$DEF" KLAYOUT_TOP=$TOP KLAYOUT_OUT=$NAME.gds \
    klayout -b -r "$ROOT/scripts/gds/def2gds.py" > klayout_def.log 2>&1 || true
fi

echo "== [$NAME] 4/4 KLayout finalize =="
KLAYOUT_IN=$NAME.gds KLAYOUT_OUT=${NAME}_final.gds KLAYOUT_TOP=$TOP \
  klayout -b -r "$ROOT/scripts/gds/finalize.py" > klayout.log 2>&1 \
  || { echo "GDS VALIDATION FAILED"; tail -10 klayout.log; exit 2; }
mv "${NAME}_final.gds" "$NAME.gds" || exit 2
ls -la "$NAME.gds"
GDS_ROOT="$ROOT" GDS_PDK="$PDK" python3 "$ROOT/scripts/gds/audit_export.py" "$NAME" > export_audit_run.log 2>&1 \
  || { echo "EXPORTED GDS AUDIT FAILED"; tail -10 export_audit_run.log; exit 4; }
EDRC=$(python3 -c 'import json; print(json.load(open("export_audit.json"))["whole_layout_flattened_drc"])')
# A file existing is NOT sign-off: routing and whole-layout DRC must both be
# explicitly zero. A blank/missing count is unverified, never a pass.
RDRC=$(grep 'Number of violations =' openroad.log 2>/dev/null | tail -1)
MDRC=$(grep '^DRC_COUNT=' magic.log | tail -1)
if [[ "$RDRC" != *'= 0.'* ]] || [ "$MDRC" != 'DRC_COUNT=0' ] || [ "$EDRC" != 0 ]; then
  echo "GDS GENERATED, CHECKS NOT CLEAN: routing=[$RDRC] magic=[$MDRC] audit=[$EDRC]"
  exit 4
fi
echo "== [$NAME] DONE (validated GDS, routing and Magic DRC zero) =="
