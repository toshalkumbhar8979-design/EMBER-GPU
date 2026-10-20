#!/usr/bin/env bash
# stop.sh — kill any in-flight synthesis/PnR inside the container.
# Lives in a FILE on purpose: running the kill loop inline makes the killer's
# own command line match the pattern and it SIGKILLs itself (exit 137).
TARGETS=(yosys abc openroad magic klayout)
SELF=$$
for p in $(ls /proc | grep -E '^[0-9]+$'); do
  [ "$p" = "$SELF" ] && continue
  c=$(tr '\0' ' ' < "/proc/$p/cmdline" 2>/dev/null) || continue
  for t in "${TARGETS[@]}"; do
    case "$c" in
      *"/$t"*|*" $t "*) kill -9 "$p" 2>/dev/null && echo "killed $p ($t)";;
    esac
  done
  case "$c" in
    *"gds/run_"[a-z]*".sh"*) kill -9 "$p" 2>/dev/null && echo "killed $p (runner)";;
    *"harden_block.sh"*) kill -9 "$p" 2>/dev/null && echo "killed $p (block)";;
  esac
done
rm -f /work/scripts/gds/stop.pid
echo "stop.sh done"
