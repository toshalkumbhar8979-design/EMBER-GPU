#!/usr/bin/env bash
# drc_audit.sh <name> -- whole-layout flattened Magic DRC on the EXPORTED GDS.
#
# Separate from export on purpose: Magic's flatten of a 347k-cell block is the
# single most expensive step in the flow and it must not be able to take the
# GDS down with it. The GDS artifact is already uploaded by the previous job,
# so a DRC job that runs out of time reports "unverified" instead of erasing
# hours of place-and-route work.
#
# Sign-off is unchanged: routing violations must be 0, Magic DRC count must be
# 0, and the audit must be run on the exact file that is uploaded (sha256 is
# recorded in export_audit.json and re-checked after the audit).
#
# Env: GDS_ROOT (default /work), GDS_PDK, GDS_AUDIT_TIMEOUT (s).
set -o pipefail
NAME=$1
ROOT=${GDS_ROOT:-/work}
OUT=$ROOT/build/gds/$NAME

PDK=${GDS_PDK:-}
if [ -z "$PDK" ] && [ -n "${PDK_ROOT:-}" ] && [ -d "$PDK_ROOT/sky130A" ]; then PDK=$PDK_ROOT/sky130A; fi
if [ -z "$PDK" ]; then PDK=$(ls -d "$HOME"/.volare/volare/sky130/versions/*/sky130A 2>/dev/null | head -1); fi
[ -n "$PDK" ] || { echo "PDK NOT FOUND (set GDS_PDK or PDK_ROOT)"; exit 3; }
[ -s "$OUT/$NAME.gds" ] || { echo "NO GDS at $OUT/$NAME.gds"; exit 3; }
cd "$OUT" || exit 3

echo "== [$NAME] whole-layout flattened DRC (timeout ${GDS_AUDIT_TIMEOUT:-7200}s)"
GDS_ROOT="$ROOT" GDS_PDK="$PDK" python3 "$ROOT/scripts/gds/audit_export.py" "$NAME" \
  > export_audit_run.log 2>&1
RC=$?
if [ "$RC" != 0 ]; then
  echo "EXPORTED GDS AUDIT FAILED (rc=$RC)"
  tail -20 export_audit_run.log
  if grep -q 'TimeoutExpired' export_audit_run.log; then
    echo "DRC UNVERIFIED: the flat DRC did not finish in ${GDS_AUDIT_TIMEOUT:-7200}s"
  fi
  exit 4
fi

EDRC=$(python3 -c 'import json; print(json.load(open("export_audit.json"))["whole_layout_flattened_drc"])')
RDRC=$(grep 'Number of violations =' openroad.log 2>/dev/null | tail -1)
echo "routing: ${RDRC:-<unknown>}"
echo "whole-layout DRC: $EDRC"
if [[ "$RDRC" != *'= 0.'* ]] || [ "$EDRC" != 0 ]; then
  echo "CHECKS NOT CLEAN: routing=[${RDRC:-unknown}] audit=[$EDRC]"
  exit 4
fi
echo "== [$NAME] SIGNED OFF: routing 0, whole-layout DRC 0"
