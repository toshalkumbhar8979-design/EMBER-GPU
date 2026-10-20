"""Verify one exported block before it is used as a hard macro.

This checks geometry/routing/DRC evidence, not LVS or timing sign-off.
"""
import hashlib
import json
from pathlib import Path
import re
import sys


def verify(directory, name):
    directory = Path(directory)
    gds = directory / (name + '.gds')
    stat = gds.stat()
    geometry = json.loads((directory / 'gds_validation.json').read_text())
    audit = json.loads((directory / 'export_audit.json').read_text())
    errors = []
    if geometry.get('top') != 'ember_' + name or geometry.get('recursive_shapes', 0) <= 0:
        errors.append('missing intended-top geometry')
    if (audit.get('top') != 'ember_' + name
            or audit.get('gds_bytes') != stat.st_size
            or audit.get('gds_mtime_ns') != stat.st_mtime_ns
            or audit.get('gds_sha256') != hashlib.sha256(gds.read_bytes()).hexdigest()):
        errors.append('missing/stale content-bound exported-GDS audit')
    if audit.get('whole_layout_flattened_drc') != 0 or audit.get('rules_suppressed') is not False:
        errors.append('exported-layout DRC not zero with unmodified rules')
    counts = re.findall(r'Number of violations = (\d+)',
                        (directory / 'openroad.log').read_text(errors='replace'))
    if not counts or int(counts[-1]) != 0:
        errors.append('routing not zero')
    if errors:
        raise ValueError('; '.join(errors))
    return gds


if __name__ == '__main__':
    name = sys.argv[1]
    root = Path(sys.argv[2]) if len(sys.argv) > 2 else Path('/work/build/gds')
    try:
        verify(root / name, name)
    except (OSError, ValueError, KeyError) as exc:
        print(f'{name}: NOT READY: {exc}')
        sys.exit(1)
    print(f'{name}: content-bound zero-routing/DRC evidence verified (LVS/timing pending)')
