"""Prepare physical-only snapshot without editing an active harden_block.sh."""
from pathlib import Path
import subprocess

root = Path('/work')
source = (root / 'scripts/gds/harden_block.sh').read_text()
anchor = 'if [ -f synth.v ] && [ "$(cat .synthkey 2>/dev/null)" = "$SH" ]; then'
assert source.count(anchor) == 1
replacement = '''if [ "${GDS_PHYSICAL_ONLY:-0}" = 1 ]; then
  [ -s synth.v ] && [ -f .synthkey ] || { echo "NO COMPLETED SYNTHESIS CACHE"; exit 1; }
  # Older accepted caches predate write_json. Reparse the existing mapped
  # Verilog into JSON without resynthesis, then apply the same strict gate.
  if [ ! -f synth.json ] || [ synth.v -nt synth.json ]; then
    timeout 300 yosys -p "read_verilog synth.v; write_json synth.json" > cache_json.log 2>&1 \\
      || { echo "CACHED NETLIST PARSE FAILED"; exit 1; }
  fi
  python3 /work/scripts/gds/validate_synth.py synth.json "$TOP" \\
    || { echo "CACHED NETLIST NOT FULLY MAPPED"; exit 1; }
  echo "   (validated physical-only cache; synthesis not repeated)"
elif [ -f synth.v ] && [ "$(cat .synthkey 2>/dev/null)" = "$SH" ]; then'''
snapshot = root / 'build/gds/harden_physical_snapshot.sh'
snapshot.write_text(source.replace(anchor, replacement))
subprocess.run(['bash', '-n', str(snapshot)], check=True)
print('Physical-only immutable snapshot:', snapshot)
