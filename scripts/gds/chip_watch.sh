#!/usr/bin/env bash
# chip_watch.sh -- autonomous end-game watcher.
# Waits for the run_cached.sh queue to finish the die phase, then runs the
# full block audit + final chip composition (die + memif + pad ring) and logs
# every step. Safe to run repeatedly: composition is content-verified, and it
# refuses to overwrite a chip.gds that already passes verification.
set -u
cd /work || exit 1
LOG=/work/build/gds/chip_watch.log
exec >> "$LOG" 2>&1
# Single-instance lock: the boot hook re-fires every ~5 min and used to
# leave one extra waiter behind per firing (100+ piled up overnight). Any
# instance that cannot take this lock exits immediately.
exec 8>/work/build/gds/.chip_watch.lock
if ! flock -n 8; then
  echo "=== chip_watch $(date) pid=$$: another instance active; exiting ==="
  exit 0
fi
echo "=== chip_watch start $(date) pid=$$ ==="

P="$HOME/.local/emberbin/python3"

# 1. Wait for the die GDS (die_pnr.sh writes it) -- unbounded, poll 60 s.
while [ ! -s build/gds/die/die.gds ]; do
  sleep 60
done
echo "die.gds appeared: $(date) ($(stat -c%s build/gds/die/die.gds) bytes)"

# 2. Wait for the queue's own die audit to settle (run_cached.sh calls
#    verify_block.py die). Give it a moment, then audit everything ourselves.
sleep 30
PASS=0; FAIL=0
for name in memif core tu gsx blit rtr_top xbar display cp rtr_scan die; do
  if python3 scripts/gds/verify_block.py "$name"; then
    echo "AUDIT PASS $name"
    PASS=$((PASS+1))
  else
    echo "AUDIT FAIL $name"
    FAIL=$((FAIL+1))
  fi
done
echo "BLOCK AUDITS PASS=$PASS FAIL=$FAIL"

# 3. Compose the final chip (die + memif + pad ring) unless a verified one
#    already exists.
if [ -s build/gds/chip/chip.gds ]; then
  echo "chip.gds exists ($(stat -c%s build/gds/chip/chip.gds) bytes) -- leaving untouched"
else
  "$P" scripts/gds/make_pad_ring_gds.py \
      --die build/gds/die/die.gds --memif build/gds/memif/memif.gds \
      --out build/gds/chip/chip.gds --top ember_chip
  echo "COMPOSE RC=$?"
fi

echo "=== chip_watch done $(date) ==="
