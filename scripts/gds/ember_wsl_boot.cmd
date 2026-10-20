@echo off
REM ember_wsl_boot.cmd -- Windows Startup (logon) hook for the Ember GDS build.
REM Wakes the WSL VM; /etc/wsl.conf [boot] then runs ember_autostart.sh as root,
REM which relaunches the build chain only if BUILD_IN_PROGRESS is still present.
REM Idempotent: safe to run at every logon, never disturbs a live build.
wsl -e echo WSL_UP >nul 2>&1
wsl -u root -e /usr/local/sbin/ember_autostart.sh >nul 2>&1
