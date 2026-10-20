# keepawake.ps1 -- prevents display-off, screen lock and system sleep while the
# Ember GDS build runs (set-and-forget; runs hidden at machine level).
# Uses SetThreadExecutionState: ES_CONTINUOUS | ES_SYSTEM_REQUIRED | ES_DISPLAY_REQUIRED
$sig = '[DllImport("kernel32.dll")] public static extern uint SetThreadExecutionState(uint esFlags);'
$t = Add-Type -MemberDefinition $sig -Name Sys -Namespace Win32 -PassThru
while ($true) {
  [Win32.Sys]::SetThreadExecutionState(0x80000000 -bor 0x00000001 -bor 0x00000002) | Out-Null
  Start-Sleep -Seconds 60
}
