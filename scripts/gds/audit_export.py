import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import sys

# GDS_ROOT/GDS_PDK let the same audit run in CI, where the checkout is not
# necessarily at /work and the PDK is mounted somewhere else.
root = Path(os.environ.get('GDS_ROOT', '/work')) / 'build/gds'
_pdk_env = os.environ.get('GDS_PDK') or os.environ.get('PDK_ROOT')
if _pdk_env:
    _p = Path(_pdk_env)
    pdk = _p if _p.name == 'sky130A' else _p / 'sky130A'
else:
    pdk = next((Path.home() / '.volare/volare/sky130/versions').glob('*/sky130A'))


def sha256_of(path):
    h = hashlib.sha256()
    with path.open('rb') as fh:
        for block in iter(lambda: fh.read(1 << 20), b''):
            h.update(block)
    return h.hexdigest()


def die_area(def_path):
    """Top-cell bbox in microns, straight from the routed DEF.

    Reading the exported GDS with pya just to get this box costs several GB on
    a 347k-cell block and helped OOM-kill the 2026-10-31 export job; the DEF
    already carries the same rectangle.
    """
    text = def_path.read_text(errors='replace')
    m = re.search(r'DIEAREA\s*\(\s*(-?\d+)\s+(-?\d+)\s*\)\s*'
                  r'\(\s*(-?\d+)\s+(-?\d+)\s*\)\s*;', text)
    if not m:
        raise SystemExit(f'no DIEAREA in {def_path}')
    u = re.search(r'UNITS\s+DISTANCE\s+MICRONS\s+(\d+)', text)
    dbu = int(u.group(1)) if u else 1000
    return [int(v) / dbu for v in m.groups()]


for name in sys.argv[1:]:
    directory = root / name
    src = directory / f'{name}.gds'
    if not src.is_file() or src.stat().st_size == 0:
        raise SystemExit(f'Missing GDS: {name}')
    routed_def = next((p for p in (directory / 'final.def',
                                   directory / 'global_route.def') if p.is_file()), None)
    if routed_def is None:
        raise SystemExit(f'Missing DEF for {name}')
    coords = die_area(routed_def)
    source_hash = sha256_of(src)
    source_stat = src.stat()
    rc = directory / 'audit_export.magicrc'
    rc.write_text(f'tech load {pdk}/libs.tech/magic/sky130A.tech\n'
                  'scalegrid 1 2\ndrc euclidean on\n')
    script = directory / 'audit_export.tcl'
    script.write_text(f'''gds read {src}
load ember_{name}
flatten ember_{name}_export_audit
load ember_{name}_export_audit
select top cell
box {' '.join(str(v) + 'um' for v in coords)}
drc on
drc style drc(full)
drc check
drc catchup
puts "AUDIT_DRC_COUNT=[drc list count total]"
puts "AUDIT_DRC_DETAILS=[drc listall why]"
quit -noprompt
''')
    logpath = directory / 'audit_magic.log'
    with logpath.open('w') as log:
        result = subprocess.run(['magic', '-rcfile', str(rc), '-dnull', '-noconsole', str(script)],
                                stdin=subprocess.DEVNULL, stdout=log, stderr=subprocess.STDOUT,
                                cwd=directory,
                                timeout=int(os.environ.get('GDS_AUDIT_TIMEOUT', '7200')))
    counts = re.findall(r'^AUDIT_DRC_COUNT=(\d+)$', logpath.read_text(), re.M)
    if result.returncode or not counts:
        raise SystemExit(f'No valid audit result for {name}')
    if sha256_of(src) != source_hash:
        raise SystemExit(f'GDS changed during audit: {name}')
    evidence = {'top': f'ember_{name}', 'def': routed_def.name,
                'bbox_um': coords,
                'gds_bytes': source_stat.st_size,
                'gds_mtime_ns': source_stat.st_mtime_ns,
                'gds_sha256': source_hash,
                'whole_layout_flattened_drc': int(counts[-1]),
                'rule_style': 'drc(full)', 'rules_suppressed': False}
    (directory / 'export_audit.json').write_text(json.dumps(evidence, indent=2))
