"""Handoff from an older queue without stopping its active block.

Usage: python3 resume_after_block.py <block-pid> <create-time>
The caller stops only the old queue parent, NOT the current harden/OpenROAD
process tree. PID start time prevents waiting on an unrelated reused PID.
"""
from pathlib import Path
import subprocess
import sys
import time

import psutil

pid = int(sys.argv[1])
started = float(sys.argv[2])
print(f'Waiting for active block PID {pid}, start {started}', flush=True)
while True:
    try:
        process = psutil.Process(pid)
        if abs(process.create_time() - started) > 0.01 or process.status() == psutil.STATUS_ZOMBIE:
            break
    except psutil.NoSuchProcess:
        break
    time.sleep(10)
print('Active block finished; resuming corrected pipeline', flush=True)
root = Path('/work')
with (root / 'build/gds/physical_resume.log').open('w') as log:
    result = subprocess.run(['bash', 'scripts/gds/run_cached.sh'], cwd=root,
                            stdin=subprocess.DEVNULL, stdout=log, stderr=subprocess.STDOUT)
print('Pipeline exit:', result.returncode, flush=True)
raise SystemExit(result.returncode)
