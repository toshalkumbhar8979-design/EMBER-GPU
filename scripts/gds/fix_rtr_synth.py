#!/usr/bin/env python3
"""Create a RTR-synthesis snapshot of harden_block.sh with the proc-order fix.

Root cause (yosys 0.46): `synth -run begin:coarse` executes ONLY the hierarchy
pass -- the design's always-block processes are never lowered. The subsequent
`techmap -autoproc` then runs on un-lowered processes and leaves the module in
a state where the explicit `proc` aborts with
  ERROR: Multiple edge sensitive events found for this signal!
Fix: run `proc` explicitly right after hierarchy, BEFORE any techmap. Verified
by bisect (E2/E3/E4 pass; E5/E6 fail) on rtr_scan.v.

The running physical queue executes harden_block.sh from disk, so we never edit
that file mid-run; we patch an immutable snapshot instead (retry_rtr.py pattern).
"""
import os
import subprocess
from pathlib import Path

root = Path('/work')
src = (root / 'scripts/gds/harden_block.sh').read_text()

old = ('SYNTH_COMMAND="synth -top $TOP -noalumacc -run begin:coarse; '
       'opt -fast -full; memory_map;')
new = ('# PROC-ORDER FIX (yosys 0.46): `synth -run begin:coarse` runs ONLY the\n'
       '# hierarchy pass here, so the always-block processes survive un-lowered\n'
       '# into `techmap -autoproc`, which corrupts them (proc_dff then aborts with\n'
       '# "Multiple edge sensitive events found for this signal!"). Lower them\n'
       '# explicitly BEFORE techmap -- verified by bisect on rtr_scan.v.\n'
       'SYNTH_COMMAND="proc; synth -top $TOP -noalumacc -run begin:coarse; '
       'opt -fast -full; memory_map;')

if old not in src:
    raise SystemExit('Expected RTR SYNTH_COMMAND line not found -- harden_block.sh changed?')
snapshot = root / 'build/gds/harden_rtr_snapshot2.sh'
snapshot.write_text(src.replace(old, new, 1))
subprocess.run(['bash', '-n', str(snapshot)], check=True)
print('snapshot OK:', snapshot)

env = dict(os.environ, GDS_FLOW_TAG='h2', GDS_SYNTH_ONLY='1')
failed = []
for name in ('rtr_scan', 'rtr_top'):
    print('SYNTHESIS', name, flush=True)
    with (root / f'build/gds/{name}.retry2.log').open('w') as log:
        result = subprocess.run(['bash', str(snapshot), name, 'ember_' + name,
                                 f'build/gds/{name}.v'], cwd=root, env=env,
                                stdin=subprocess.DEVNULL, stdout=log, stderr=subprocess.STDOUT)
    print(('PASS' if result.returncode == 0 else 'FAIL'), name, flush=True)
    if result.returncode:
        failed.append(name)
print('FAILED:', failed, flush=True)
raise SystemExit(bool(failed))
