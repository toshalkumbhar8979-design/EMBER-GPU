#!/usr/bin/env bash
# export_gds.sh <name> <top> -- routed DEF -> standalone GDS, no Magic.
#
# Why not Magic: Magic's def read + flatten + gds write on a 347k-cell block
# cannot finish inside a 6 h GitHub job (the 2026-10-30 run spent 4 h 20 m in
# that one script and was killed before it had written a single byte of GDS).
# KLayout's LEF/DEF importer resolves every standard cell against the real PDK
# GDS masters and writes the hierarchy directly, which is minutes, not hours.
#
# Env: GDS_ROOT (default /work), GDS_PDK, GDS_KEEP_GLOBAL_ROUTE=1 (accept
#      global_route.def when final.def is absent, labelled "global-route").
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
echo "== [$NAME] 1/2 KLayout DEF->GDS ($DEF, $FLOWN)"
PDK="$PDK" KLAYOUT_DEF="$DEF" KLAYOUT_TOP="$TOP" KLAYOUT_OUT="$NAME.gds" \
  klayout -b -r "$ROOT/scripts/gds/def2gds.py" > klayout_def.log 2>&1 \
  || { echo "KLAYOUT DEF->GDS FAILED"; tail -20 klayout_def.log; exit 2; }
[ -s "$NAME.gds" ] || { echo "KLAYOUT WROTE NO GDS"; tail -20 klayout_def.log; exit 2; }
tail -3 klayout_def.log

echo "== [$NAME] 2/2 GDS completeness check (streaming)"
# Not finalize.py: re-reading a routed core with pya.Layout costs several GB and
# the rewrite was OOM-killed on a 16 GB runner. The failure that matters is
# truncation, which the record walk detects in one streaming pass.
python3 "$ROOT/scripts/gds/ci/check_gds.py" "$NAME.gds" gds_validation.json \
  || { echo "GDS CHECK FAILED (truncated or not GDSII)"; exit 2; }
python3 - "$TOP" "$DEF" "$FLOWN" <<'PY'
import json
import sys

path = 'gds_validation.json'
with open(path) as fh:
    data = json.load(fh)
data.update({'top': sys.argv[1], 'def': sys.argv[2], 'flow': sys.argv[3]})
with open(path, 'w') as fh:
    json.dump(data, fh, indent=2)
PY
cat gds_validation.json
ls -la "$NAME.gds"
echo "== [$NAME] export done; whole-layout DRC is the next CI job"
