import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys

import pya

# GDS_ROOT/GDS_PDK let the same audit run in CI, where the checkout is not
# necessarily at /work and the PDK is mounted somewhere else.
root = Path(os.environ.get('GDS_ROOT', '/work')) / 'build/gds'
_pdk_env = os.environ.get('GDS_PDK') or os.environ.get('PDK_ROOT')
if _pdk_env:
    _p = Path(_pdk_env)
    pdk = _p if _p.name == 'sky130A' else _p / 'sky130A'
else:
    pdk = next((Path.home() / '.volare/volare/sky130/versions').glob('*/sky130A'))
for name in sys.argv[1:]:
    directory = root / name
    src = directory / f'{name}.gds'
    layout = pya.Layout()
    layout.read(str(src))
    top = layout.cell('ember_' + name)
    if top is None or top.bbox().empty():
        raise SystemExit(f'Missing geometry: {name}')
    source_hash = hashlib.sha256(src.read_bytes()).hexdigest()
    source_stat = src.stat()
    box = top.bbox()
    coords = [box.left * layout.dbu, box.bottom * layout.dbu,
              box.right * layout.dbu, box.top * layout.dbu]
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
    import re
    counts = re.findall(r'^AUDIT_DRC_COUNT=(\d+)$', logpath.read_text(), re.M)
    if result.returncode or not counts:
        raise SystemExit(f'No valid audit result for {name}')
    if hashlib.sha256(src.read_bytes()).hexdigest() != source_hash:
        raise SystemExit(f'GDS changed during audit: {name}')
    evidence = {'top': top.name, 'gds_bytes': source_stat.st_size,
                'gds_mtime_ns': source_stat.st_mtime_ns,
                'gds_sha256': source_hash,
                'whole_layout_flattened_drc': int(counts[-1]),
                'rule_style': 'drc(full)', 'rules_suppressed': False}
    (directory / 'export_audit.json').write_text(json.dumps(evidence, indent=2))
