#!/usr/bin/env python3
"""RTR synthesis variant 4.

v3 (19.5 GB tree limit) still SIGKILLed ABC on rtr_scan: the machine has
21.5 GB RAM + 6 GB swap, so the right move is to let ABC spill to swap instead
of killing it. This variant raises the watchdog to 27 GB (RAM+swap) and waits
for free memory before each block so the two never collide.
"""
import os
import subprocess
import time
from pathlib import Path

import psutil

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

lean = ('# LEAN-ABC FIX (v3): default `abc -fast` OOM-killed on the multiplier-heavy\n'
        '# scan/setup AIGs. Map with a minimal script instead:\n'
        'LEAN_ABC="/work/build/gds/abc_lean.script"\n')
anchor = 'GDS_RSS_LIMIT_KB=${GDS_RSS_LIMIT_KB:-14000000}   # 14 GB\n'
assert anchor in src, 'RSS-limit anchor not found'

out = src.replace(old, new, 1).replace(anchor, anchor + lean, 1)
out = out.replace('abc -fast -liberty $LIB', 'abc -liberty $LIB -script $LEAN_ABC')

snapshot = root / 'build/gds/harden_rtr_snapshot4.sh'
snapshot.write_text(out)
subprocess.run(['bash', '-n', str(snapshot)], check=True)
print('snapshot OK:', snapshot)


def wait_for_ram(min_avail_gb: float, label: str) -> None:
    while True:
        avail = psutil.virtual_memory().available / 2**30
        swap_free = psutil.swap_memory().free / 2**30
        print(f'[{label}] waiting: avail {avail:.1f}G + swapfree {swap_free:.1f}G', flush=True)
        if avail >= min_avail_gb:
            return
        time.sleep(30)


env = dict(os.environ, GDS_FLOW_TAG='h4', GDS_SYNTH_ONLY='1',
           GDS_RSS_LIMIT_KB='27000000')
failed = []
for name in ('rtr_scan', 'rtr_top'):
    wait_for_ram(8.0, name)
    print('SYNTHESIS', name, flush=True)
    with (root / f'build/gds/{name}.retry4.log').open('w') as log:
        result = subprocess.run(['bash', str(snapshot), name, 'ember_' + name,
                                 f'build/gds/{name}.v'], cwd=root, env=env,
                                stdin=subprocess.DEVNULL, stdout=log, stderr=subprocess.STDOUT)
    print(('PASS' if result.returncode == 0 else 'FAIL'), name, flush=True)
    if result.returncode:
        failed.append(name)
print('FAILED:', failed, flush=True)
raise SystemExit(bool(failed))
