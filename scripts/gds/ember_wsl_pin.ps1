# ember_wsl_pin.ps1 -- WSL VM pin + Ember GDS chain watchdog.
#
# Owned by Windows Task Scheduler (task "EmberWSLPin", every 5 min), NOT by
# Freebuff, so the build keeps running when a Freebuff session ends or is not
# started. Reason: in this environment the WSL VM shuts down when its last
# wsl.exe client exits, which kills the [boot]-launched build chain. The pin
# is a detached wsl.exe client that outlives this script and any app session.
#
# The chain itself is relaunched by the WSL [boot] hook (ember_autostart.sh)
# whenever the VM starts; this script additionally revives it if it ever
# stops while the VM stays up. All relaunches are idempotent (flock + pgrep
# + BUILD_IN_PROGRESS marker inside ember_autostart.sh).

$ErrorActionPreference = 'Continue'
$log = Join-Path $PSScriptRoot 'ember_wsl_pin.log'
function Log($m) { "$(Get-Date -Format 'yyyy-MM-dd HH:mm:ss') $m" | Add-Content -Path $log }

# 1) Pin the VM: detached hidden wsl client, started only if none exists.
$pin = Get-CimInstance Win32_Process -Filter "Name='wsl.exe'" |
       Where-Object { $_.CommandLine -match 'ember-pin|sleep infinity' }
if (-not $pin) {
    # NOTE: ArgumentList must be ONE string with embedded quotes. PowerShell's
    # array form does not re-quote multi-word elements, which turns `bash -c
    # "exec -a ember-pin sleep infinity"` into `bash -c exec` (instant exit).
    Start-Process -FilePath 'wsl.exe' `
        -ArgumentList '-e bash -c "exec -a ember-pin sleep infinity"' `
        -WindowStyle Hidden
    Log 'pin started (VM was unheld)'
}

# 2) Chain watchdog: revive via the idempotent autostart if nothing is building.
#    The probe wsl call also boots the VM if it is down, which triggers [boot].
$alive = (& wsl.exe -e bash -c "pgrep -f 'recover_1017\.sh|run_cached\.sh' >/dev/null && echo YES || echo NO" |
          Out-String).Trim()
if ($alive -notmatch 'YES') {
    & wsl.exe -u root -e /usr/local/sbin/ember_autostart.sh
    Log 'chain was down -> autostart invoked'
}
else {
    Log 'chain alive'
}
