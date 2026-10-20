import argparse
import json
from pathlib import Path

parser = argparse.ArgumentParser(description='Reject unmapped or unresolved netlists.')
parser.add_argument('path', type=Path)
parser.add_argument('top')
parser.add_argument('--allow-blackbox', action='append', default=[],
                    help='Explicit macro candidate; does not prove physical implementation.')
args = parser.parse_args()
path = args.path
top = args.top
modules = json.loads(path.read_text())['modules']
errors = []
visited = set()
def walk(name):
    if name in visited:
        return
    visited.add(name)
    module = modules[name]
    attrs = module.get('attributes', {})
    is_blackbox = any(str(attrs.get(key, '0')).strip('0') not in ('', 'False')
                      for key in ('blackbox', 'whitebox'))
    if is_blackbox:
        if name not in args.allow_blackbox:
            errors.append(f'{name}: unresolved blackbox (requires explicit macro allowance)')
        return
    if module.get('processes'):
        errors.append(f'{name}: residual behavioral processes')
    for cell in module.get('cells', {}).values():
        kind = cell['type']
        if kind.startswith('sky130_fd_sc_hd__'):
            continue
        if kind in modules:
            walk(kind)
        else:
            errors.append(f'{name}: unmapped cell type {kind}')
if top not in modules:
    errors.append('missing intended top')
else:
    walk(top)
if errors:
    print('\n'.join(sorted(set(errors))))
    raise SystemExit(1)
print('Mapped logic verified:', top)
if args.allow_blackbox:
    print('Macro blackboxes explicitly allowed; physical evidence still required:',
          ', '.join(sorted(set(args.allow_blackbox) & visited)))
