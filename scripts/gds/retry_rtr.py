import os
from pathlib import Path
import subprocess

root = Path('/work')
source = (root / 'scripts/gds/harden_block.sh').read_text()
if 'techmap -autoproc' not in source or 'validate_synth.py' not in source:
    raise SystemExit('Expected process lowering and mapped-netlist validation')
snapshot = root / 'build/gds/harden_rtr_snapshot.sh'
snapshot.write_text(source)
subprocess.run(['bash', '-n', str(snapshot)], check=True)
env = dict(os.environ, GDS_FLOW_TAG='h2', GDS_SYNTH_ONLY='1')
failed = []
for name in ('rtr_setup', 'rtr_scan', 'rtr_top'):
    print('SYNTHESIS', name, flush=True)
    with (root / f'build/gds/{name}.retry.log').open('w') as log:
        result = subprocess.run(['bash', str(snapshot), name, 'ember_' + name,
                                 f'build/gds/{name}.v'], cwd=root, env=env,
                                stdin=subprocess.DEVNULL, stdout=log, stderr=subprocess.STDOUT)
    print(('PASS' if result.returncode == 0 else 'FAIL'), name, flush=True)
    if result.returncode:
        failed.append(name)
print('FAILED:', failed, flush=True)
raise SystemExit(bool(failed))
