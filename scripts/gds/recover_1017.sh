#!/usr/bin/env bash
# recover_1017.sh -- post-reboot recovery chain (2026-10-17, WSL restarted
# ~08:00 and killed core's route mid-DRT-iteration-13, the tu audit mid-run,
# and chip_watch).
#
# Sequencing is RAM-serial on purpose: core's OpenROAD peaks at 16.5 GB of
# the 17 GB WSL budget, so the tu Magic flattened-DRC audit (several GB of
# its own) must run first, on the empty machine, before the queue restarts.
#   1. salvage_tu_resume.sh  -- tu audit + verify_block (export already done)
#   2. run_cached.sh         -- core -> rtr_scan -> rtr_top -> die (KEEPs the
#                               audited blocks; resumes from synth caches)
# chip_watch.sh (relaunched separately) composes chip.gds when die.gds lands.
set -u
cd /work
# Tool PATH first: the autostart `su` launch carries a stripped PATH (no
# ~/.local/emberbin), which made openroad "not found" and psutil unimportable
# on 2026-10-17 20:14. Everything downstream inherits this.
export PATH="$HOME/.local/emberbin:$HOME/.nix-profile/bin:$PATH"
LOG=/work/build/gds/recover_1017.log
exec >> "$LOG" 2>&1
echo "=== recover_1017 start $(date) pid=$$ ==="
# PAUSE_BUILD: user-requested stop (2026-10-20). Stays off until the marker
# is removed: rm /work/build/gds/PAUSE_BUILD
if [ -f /work/build/gds/PAUSE_BUILD ]; then
  echo "PAUSE_BUILD marker present; recovery paused (user request)"
  exit 0
fi

# Short-circuit: a stale boot hook re-fires every ~5 min and used to redo
# the tu verify and re-exec the master on every firing. If the chain is
# already alive, this relaunch is a pure no-op. (Anchored so the pgrep
# cannot match the hook's own `su -c` command line or this script.)
if pgrep -f '^bash /work/scripts/gds/(auto_core_master|run_cached)[.]sh' >/dev/null 2>&1; then
  echo "=== recover_1017 $(date): chain already active; nothing to do ==="
  exit 0
fi

# Idempotent: a relaunch after a WSL restart must not redo the multi-hour tu
# audit when tu already passes the full content-audited acceptance check.
if python3 /work/scripts/gds/verify_block.py tu >/dev/null 2>&1; then
  echo "=== tu already verified; skipping salvage resume $(date) ==="
else
  bash /work/scripts/gds/salvage_tu_resume.sh
  TU_RC=$?
  echo "=== tu salvage resume rc=$TU_RC $(date) ==="
  if [ "$TU_RC" -ne 0 ]; then
    echo "TU SALVAGE NOT CLEAN: queue still runs, but die/chip claims stay blocked until tu verifies"
  fi
fi

# USER POLICY (2026-10-19): a routed core checkpoint must NEVER be rebuilt.
# If core still needs work and a routed checkpoint exists, hand over to the
# resume-only controller (it resumes routing from final.odb, runs the GDS tail
# and then relaunches run_cached.sh itself after core verifies). This guards
# every boot path, including stale autostart hooks.
if ! python3 /work/scripts/gds/verify_block.py core >/dev/null 2>&1 \
   && { [ -s /work/build/gds/core/final.odb ] || [ -s /work/build/gds/core/final.def ] || [ -s /work/build/gds/core/final_iter40_backup.def ]; }; then
  echo "core unverified with routed checkpoint -> exec auto_core_master (resume-only; no rebuild) $(date)"
  exec bash /work/scripts/gds/auto_core_master.sh
fi

bash /work/scripts/gds/run_cached.sh
Q_RC=$?
echo "=== queue done rc=$Q_RC $(date) ==="
exit "$Q_RC"
