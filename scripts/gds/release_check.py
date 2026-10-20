"""Read-only release gate: files existing is not evidence of a final chip."""
import hashlib
import json
from pathlib import Path
import re
import sys

root = Path('/work/build/gds')
blocks = []
for line in Path('/work/scripts/gds/blocks.txt').read_text().splitlines():
    if line and not line.startswith('#'):
        name, top, *_ = line.split('|')
        blocks.append((name, top))
failures = []
for name, top in blocks:
    d = root / name
    errors = []
    try:
        gds = d / f'{name}.gds'
        stat = gds.stat()
        geometry = json.loads((d / 'gds_validation.json').read_text())
        audit = json.loads((d / 'export_audit.json').read_text())
        if geometry.get('top') != top or geometry.get('recursive_shapes', 0) <= 0:
            errors.append('missing intended-top geometry')
        if audit.get('gds_mtime_ns') != stat.st_mtime_ns or audit.get('gds_bytes') != stat.st_size:
            errors.append('stale exported-GDS audit')
        if audit.get('gds_sha256') != hashlib.sha256(gds.read_bytes()).hexdigest():
            errors.append('missing/mismatched content-bound audit')
        if audit.get('whole_layout_flattened_drc') != 0 or audit.get('rules_suppressed') is not False:
            errors.append('exported-layout DRC not zero/unmodified')
        counts = re.findall(r'Number of violations = (\d+)', (d / 'openroad.log').read_text())
        if not counts or int(counts[-1]) != 0:
            errors.append('routing not zero')
    except (OSError, ValueError) as exc:
        errors.append(f'missing evidence: {exc}')
    if errors:
        failures.append(name)
    print(name + ': ' + ('; '.join(errors) if errors else 'block DRC evidence verified (not chip sign-off)'))

# Never bless a shelf-packed gallery as the final integrated GPU.
print('FULL CHIP: NOT RELEASED. Electrical integration, physical SRAM, LVS, '
      'timing closure and full-chip sign-off evidence are not implemented in this gate.')
print('Blocks lacking complete evidence:', ', '.join(failures) or 'none')
sys.exit(1)
