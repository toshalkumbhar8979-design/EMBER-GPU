"""Build a small cached block without disturbing the primary queue.

Usage: python3 run_small_block.py cp
Only CP/setup are eligible; large blocks remain sequential under the 16GB VM
limit. Stops this child's tree if its RSS exceeds 3 GiB or VM headroom falls
below 2 GiB. No rules are waived and a killed run is reported as incomplete.
"""
import os
from pathlib import Path
import subprocess
import sys
import time

import psutil

root = Path('/work')
name = sys.argv[1]
if name not in ('cp', 'rtr_setup'):
    raise SystemExit('Only small cached blocks cp/rtr_setup may run alongside the primary queue')
if psutil.virtual_memory().available < 8 * 2**30:
    raise SystemExit('Not enough headroom: need 8 GiB before starting a parallel block')
for process in psutil.process_iter(['cmdline', 'status']):
    command = process.info['cmdline'] or []
    if process.info['status'] != psutil.STATUS_ZOMBIE and any(
            arg.endswith(('harden_block.sh', 'harden_physical_snapshot.sh')) for arg in command
    ) and name in command:
        raise SystemExit(f'{name} already building; refusing a duplicate run')
snapshot = root / 'build/gds/harden_physical_snapshot.sh'
if not snapshot.is_file():
    raise SystemExit('Physical-only snapshot missing')
env = dict(os.environ, GDS_PHYSICAL_ONLY='1', GDS_FLOW_TAG='h2',
           GDS_UTIL='20', GDS_PL_DENSITY='0.30', GDS_DRT_ITER='40',
           GDS_PNR_TIMEOUT='14400', OMP_NUM_THREADS='2')
logpath = root / f'build/gds/{name}.parallel.log'
with logpath.open('w') as log:
    child = subprocess.Popen(['bash', str(snapshot), name, 'ember_' + name,
                              f'build/gds/{name}.v'], cwd=root, env=env,
                             stdin=subprocess.DEVNULL, stdout=log, stderr=subprocess.STDOUT,
                             start_new_session=True)
    print(f'Started {name}: PID {child.pid}; 3 GiB RSS budget; log {logpath}', flush=True)
    while child.poll() is None:
        try:
            parent = psutil.Process(child.pid)
            tree = [parent] + parent.children(recursive=True)
            rss = sum(p.memory_info().rss for p in tree
                      if p.is_running() and p.status() != psutil.STATUS_ZOMBIE)
            available = psutil.virtual_memory().available
            if rss > 3 * 2**30 or available < 2 * 2**30:
                print(f'{name}: memory guard STOP (RSS {rss/2**30:.2f} GiB, '
                      f'available {available/2**30:.2f} GiB); primary queue untouched', flush=True)
                for process in reversed(tree):
                    try:
                        process.kill()
                    except psutil.NoSuchProcess:
                        pass
                child.wait()
                raise SystemExit(2)
        except psutil.NoSuchProcess:
            break
        time.sleep(5)
    result = child.wait()
print(f'{name}: flow exit {result}', flush=True)
if result:
    raise SystemExit(result)
subprocess.run(['python3', 'scripts/gds/verify_block.py', name], cwd=root, check=True)
subprocess.run(['python3', 'tools/gds/collect_results.py', '/work/build/gds'],
               cwd=root, check=True)
print(f'{name}: independently verified exported GDS; paper counts refreshed', flush=True)
