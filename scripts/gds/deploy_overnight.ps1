# deploy_overnight.ps1 -- installs the logon hook and starts the keep-awake process.
$ErrorActionPreference = 'Stop'
$startup = Join-Path $env:APPDATA 'Microsoft\Windows\Start Menu\Programs\Startup'
$src = Join-Path $PSScriptRoot 'ember_wsl_boot.cmd'
Copy-Item $src (Join-Path $startup 'ember_wsl_boot.cmd') -Force
$ka = Join-Path $PSScriptRoot 'keepawake.ps1'
# Only one keep-awake instance
if (-not (Get-CimInstance Win32_Process -Filter "Name='powershell.exe'" | Where-Object { $_.CommandLine -like '*keepawake.ps1*' })) {
  Start-Process powershell -WindowStyle Hidden -ArgumentList '-NoProfile','-ExecutionPolicy','Bypass','-File',$ka
  Start-Sleep -Seconds 2
}
Write-Output ('STARTUP_HOOK=' + (Test-Path (Join-Path $startup 'ember_wsl_boot.cmd')))
Write-Output ('KEEPAWAKE_RUNNING=' + [bool](Get-CimInstance Win32_Process -Filter "Name='powershell.exe'" | Where-Object { $_.CommandLine -like '*keepawake.ps1*' }))
