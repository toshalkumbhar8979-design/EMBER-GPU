#!/usr/bin/env bash
# run_all2.sh — second batch: blit, display, gsx, core, tu (the GPU/TPU cores)
set -u
cd /work
PASS=0; FAIL=0; FAILED=""
while IFS='|' read -r name top files; do
  case "$name" in ''|\#*) continue;; esac
  echo "########## BLOCK $name ($top) ##########"
  if bash scripts/gds/harden_block.sh "$name" "$top" "build/gds/$name.v" > "build/gds/$name.harden.log" 2>&1; then
    echo "PASS $name"; PASS=$((PASS+1))
  else
    echo "FAIL $name"; tail -5 "build/gds/$name.harden.log"; FAIL=$((FAIL+1)); FAILED="$FAILED $name"
  fi
done < scripts/gds/blocks2.txt
echo "SUITE2 PASS=$PASS FAIL=$FAIL$FAILED"
