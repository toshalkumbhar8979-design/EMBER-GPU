' ember_wsl_pin.vbs -- silent launcher for ember_wsl_pin.ps1.
' wscript.exe is a GUI-subsystem host: it never draws a console window, so the
' scheduled task (EmberWSLPin) runs completely invisibly every 5 minutes.
' Window style 0 = hidden; False = fire-and-forget.
CreateObject("Wscript.Shell").Run _
  "powershell.exe -NoProfile -ExecutionPolicy Bypass -File ""C:\Users\tosha\Downloads\GPU\scripts\gds\ember_wsl_pin.ps1""", _
  0, False
