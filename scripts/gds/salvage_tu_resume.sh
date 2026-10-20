#!/usr/bin/env bash
# salvage_tu_resume.sh -- resume tu salvage after the 2026-10-17 WSL reboot.
#
# The KLayout DEF->GDS export and finalize COMPLETED before the reboot:
#   tu.gds            438,095,280 B  (written 04:57, export proven on blit)
#   gds_validation.json              (finalize passed 04:58)
# The reboot killed the third step (Magic flattened DRC audit) mid-run.
# This script reruns only the remaining acceptance gates, unchanged:
#   1. audit_export.py -> export_audit.json (Magic flattened DRC, drc(full))
#   2. routing evidence check (openroad.log "Number of violations = 0")
#   3. verify_block.py tu
set -u
NAME=tu
DIR=/work/build/gds/$NAME
cd "$DIR" || exit 1
export PATH="$HOME/.local/emberbin:$PATH"
PY=python3

[ -s "$NAME.gds" ] || { echo "tu.gds missing; rerun salvage_tu_def2gds.sh from the top"; exit 3; }
[ -s gds_validation.json ] || { echo "gds_validation.json missing; rerun salvage from finalize"; exit 3; }

echo "== [$NAME] resume: independent export audit (Magic flattened DRC) $(date) =="
GDS_AUDIT_TIMEOUT=28800 nice -n 10 "$PY" /work/scripts/gds/audit_export.py "$NAME" \
  > export_audit_run.log 2>&1 || { echo "EXPORTED GDS AUDIT FAILED"; tail -10 export_audit_run.log; exit 4; }
EDRC=$(python3 -c 'import json; print(json.load(open("export_audit.json"))["whole_layout_flattened_drc"])')
RDRC=$(grep 'Number of violations =' openroad.log | tail -1)
echo "audit_drc=$EDRC routing=[$RDRC]"
if [[ "$RDRC" != *'= 0.'* ]] || [ "$EDRC" != 0 ]; then
  echo "GDS GENERATED, CHECKS NOT CLEAN: routing=[$RDRC] audit=[$EDRC]"
  exit 4
fi
python3 /work/scripts/gds/verify_block.py "$NAME" || exit 4
echo "== [$NAME] SALVAGE DONE (KLayout export, zero routing + flattened DRC) $(date) =="
