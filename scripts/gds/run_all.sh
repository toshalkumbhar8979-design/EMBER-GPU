#!/usr/bin/env bash
# run_all.sh — harden every Ember block, sequentially, inside the container.
# Usage (from /work):  bash scripts/gds/run_all.sh
set -u
cd /work
PASS=0; FAIL=0; FAILED=""
while IFS='|' read -r name top files envover; do
  case "$name" in ''|\#*) continue;; esac
  # every build/gds/<name>.v is SELF-CONTAINED: sv2v inlines the package and
  # sub-modules (rtr_top.v carries setup+scan+top, gsx.v carries fpu4+gsx, ...)
  # optional 4th field: per-block env overrides (GDS_UTIL / GDS_PL_DENSITY /
  # GDS_DRT_ITER / GDS_PNR_TIMEOUT) for the bus-dense blocks that diverge at
  # the default packing -- see blocks.txt.
  echo "########## BLOCK $name ($top) ${envover:+[$envover]} ##########"
  # </dev/null: some tool in the block flow reads stdin, which would swallow
  # the REST of blocks.txt and silently end the batch after one block
  # (observed: the h3b batch ran display then hit EOF).
  if env $envover bash scripts/gds/harden_block.sh "$name" "$top" "build/gds/$name.v" \
       < /dev/null > "build/gds/$name.harden.log" 2>&1; then
    echo "PASS $name"; PASS=$((PASS+1))
  else
    echo "FAIL $name"; tail -5 "build/gds/$name.harden.log"; FAIL=$((FAIL+1)); FAILED="$FAILED $name"
  fi
done < scripts/gds/blocks.txt
echo "SUITE PASS=$PASS FAIL=$FAIL$FAILED"
