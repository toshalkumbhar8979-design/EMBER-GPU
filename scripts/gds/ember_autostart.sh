#!/usr/bin/env bash
# ember_autostart.sh -- WSL [boot] hook (runs as root at every VM start).
#
# Relaunches the Ember GDS build chain after ANY WSL restart, so a VM kill
# costs at most the current block, never the whole queue (run_cached.sh KEEPs
# content-audited blocks; the tu salvage resumes from its completed export).
# Also relaunched at Windows logon by the Startup-folder ember_wsl_boot.cmd.
#
# Guarded three ways so repeated starts are safe:
#   1. BUILD_IN_PROGRESS marker (removed here once die+chip are done)
#   2. live-process check (pgrep on the chain scripts)
#   3. flock on .autostart.lock
exec >> /work/build/gds/autostart.log 2>&1
echo "=== ember_autostart $(date) uid=$(id -u) ==="
# PAUSE_BUILD: user-requested stop (2026-10-20). Auto-restart stays off until
# the marker is removed: rm /work/build/gds/PAUSE_BUILD
if [ -f /work/build/gds/PAUSE_BUILD ]; then
  echo "PAUSE_BUILD marker present; auto-restart paused (user request)"
  exit 0
fi
MARKER=/work/build/gds/BUILD_IN_PROGRESS
if [ ! -f "$MARKER" ]; then
  echo "no BUILD_IN_PROGRESS marker; nothing to do"
  exit 0
fi
# Fully done? die verified and chip composed -> self-clean and stop.
if python3 /work/scripts/gds/verify_block.py die >/dev/null 2>&1 \
   && [ -s /work/build/gds/chip/chip.gds ]; then
  echo "build complete (die verified + chip.gds present); removing marker"
  rm -f "$MARKER"
  exit 0
fi
if pgrep -f 'run_cached\.sh|recover_1017\.sh|auto_core_master\.sh' >/dev/null 2>&1; then
  echo "chain already running; nothing to do"
  exit 0
fi
exec 9> /work/build/gds/.autostart.lock
if ! flock -n 9; then
  echo "another autostart holds the lock; exiting"
  exit 0
fi
# verify_block as the build user: root may lack the flow's python3 env.
core_verified() {
  if [ "$(id -u)" = 0 ]; then
    su -s /bin/bash toshal -c 'export PATH="$HOME/.local/emberbin:$PATH"; python3 /work/scripts/gds/verify_block.py core' >/dev/null 2>&1
  else
    python3 /work/scripts/gds/verify_block.py core >/dev/null 2>&1
  fi
}
# Core not verified AND a routed checkpoint exists -> RESUME-ONLY relaunch
# (user policy 2026-10-19): start ONLY auto_core_master (it resumes routing
# from final.odb, runs the GDS tail, verifies core, then restarts the queue
# itself) + chip_watch. Letting run_cached start now would REBUILD core from
# scratch and throw away the routed checkpoint's progress.
if ! core_verified && [ -s /work/build/gds/core/final.def ]; then
  echo "core unverified with routed checkpoint -> resume-only relaunch (master + chip_watch)"
  if [ "$(id -u)" = 0 ]; then
    chown toshal:toshal "$MARKER" /work/build/gds/.autostart.lock 2>/dev/null
    su -s /bin/bash toshal -c 'export PATH="$HOME/.local/emberbin:$HOME/.nix-profile/bin:$PATH"; setsid nohup bash /work/scripts/gds/auto_core_master.sh </dev/null >/dev/null 2>&1 9>&- & setsid nohup bash /work/scripts/gds/chip_watch.sh </dev/null >>/work/build/gds/chip_watch.log 2>&1 9>&- & sleep 2; pgrep -af "auto_core_master|chip_watch" || echo RELAUNCH_FAILED'
  else
    setsid nohup bash /work/scripts/gds/auto_core_master.sh </dev/null >/dev/null 2>&1 9>&- &
    setsid nohup bash /work/scripts/gds/chip_watch.sh </dev/null >>/work/build/gds/chip_watch.log 2>&1 9>&- &
    sleep 2
    pgrep -af 'auto_core_master|chip_watch' || echo RELAUNCH_FAILED
  fi
  echo "=== autostart done (resume-only) $(date) ==="
  exit 0
fi
if [ "$(id -u)" = 0 ]; then
  chown toshal:toshal "$MARKER" /work/build/gds/.autostart.lock 2>/dev/null
  # PATH export: su resets PATH and the flow needs ~/.local/emberbin
  # (openroad/magic/klayout/yosys/python3+psutil). 9>&- on every child:
  # otherwise the chain inherits the flock FD and holds the lock forever
  # (chip_watch waits for die.gds), blocking all future auto-revives.
  su -s /bin/bash toshal -c 'export PATH="$HOME/.local/emberbin:$HOME/.nix-profile/bin:$PATH"; setsid nohup bash /work/scripts/gds/recover_1017.sh </dev/null >/dev/null 2>&1 9>&- & setsid nohup bash /work/scripts/gds/chip_watch.sh </dev/null >>/work/build/gds/chip_watch.log 2>&1 9>&- & setsid nohup bash /work/scripts/gds/auto_core_master.sh </dev/null >/dev/null 2>&1 9>&- & sleep 2; pgrep -af "recover_1017|chip_watch|auto_core_master" || echo RELAUNCH_FAILED'
else
  setsid nohup bash /work/scripts/gds/recover_1017.sh </dev/null >/dev/null 2>&1 9>&- &
  setsid nohup bash /work/scripts/gds/chip_watch.sh </dev/null >>/work/build/gds/chip_watch.log 2>&1 9>&- &
  setsid nohup bash /work/scripts/gds/auto_core_master.sh </dev/null >/dev/null 2>&1 9>&- &
  sleep 2
  pgrep -af 'recover_1017|chip_watch|auto_core_master' || echo RELAUNCH_FAILED
fi
echo "=== autostart done $(date) ==="
