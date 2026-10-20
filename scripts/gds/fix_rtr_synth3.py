#!/usr/bin/env python3
"""RTR synthesis variant 3.

v1: default `abc -fast` OOMs (>14 GB) -- ABC's default script runs dc2/dch
    rewriting passes that balloon on the ~1M-node multiplier-heavy AIG.
v2: raised limit to 18.5 GB -- still killed (rc 137) inside ABC.
v3: LEAN ABC script (strash; map; topo; buffer; upsize; dnsize) -- mapping
    without the rewriting passes. Run ALONE first (physical queue held back)
    so ABC gets the whole WSL2 allocation (~19.5 GB headroom).
"""
import os
import subprocess
from pathlib import Path

root = Path('/work')
src = (root / 'scripts/gds/harden_block.sh').read_text()

old = ('SYNTH_COMMAND="synth -top $TOP -noalumacc -run begin:coarse; '
       'opt -fast -full; memory_map;')
new = ('# PROC-ORDER FIX (yosys 0.46): `synth -run begin:coarse` runs ONLY the\n'
       '# hierarchy pass here, so always-block processes survive un-lowered into\n'
       '# `techmap -autoproc`, which corrupts them (proc_dff aborts with "Multiple\n'
       '# edge sensitive events found for this signal!"). Lower them explicitly\n'
       '# BEFORE techmap -- verified by bisect on rtr_scan.v.\n'
       'SYNTH_COMMAND="proc; synth -top $TOP -noalumacc -run begin:coarse; '
       'opt -fast -full; memory_map;')
assert old in src, 'RTR SYNTH_COMMAND anchor not found'

lean = ('# LEAN-ABC FIX (v3): default `abc -fast` OOM-killed (>18 GB) on the\n'
        '# multiplier-heavy scan/setup AIGs (rc 137). Map with a minimal script\n'
        '# (no dc2/dch rewriting) instead: scripts/gds/abc_lean.script.\n'
        'LEAN_ABC="/work/build/gds/abc_lean.script"\n')
anchor = 'GDS_RSS_LIMIT_KB=${GDS_RSS_LIMIT_KB:-14000000}   # 14 GB\n'
assert anchor in src, 'RSS-limit anchor not found'

out = src.replace(old, new, 1).replace(anchor, anchor + lean, 1)
out = out.replace('abc -fast -liberty $LIB', 'abc -liberty $LIB -script $LEAN_ABC')

snapshot = root / 'build/gds/harden_rtr_snapshot3.sh'
snapshot.write_text(out)
subprocess.run(['bash', '-n', str(snapshot)], check=True)
print('snapshot OK:', snapshot)

env = dict(os.environ, GDS_FLOW_TAG='h3', GDS_SYNTH_ONLY='1',
           GDS_RSS_LIMIT_KB='19500000')
failed = []
for name in ('rtr_scan', 'rtr_top'):
    print('SYNTHESIS', name, flush=True)
    with (root / f'build/gds/{name}.retry3.log').open('w') as log:
        result = subprocess.run(['bash', str(snapshot), name, 'ember_' + name,
                                 f'build/gds/{name}.v'], cwd=root, env=env,
                                stdin=subprocess.DEVNULL, stdout=log, stderr=subprocess.STDOUT)
    print(('PASS' if result.returncode == 0 else 'FAIL'), name, flush=True)
    if result.returncode:
        failed.append(name)
print('FAILED:', failed, flush=True)
raise SystemExit(bool(failed))
