"""Compare Yosys wrapper connection bits with physical macro LEF pins.

Usage: python3 check_macro_interfaces.py top.json wrapper block...
LEF pins from splitnets are individual bus bits; the wrapper JSON retains bus
ports. Power pins are connected by the PDN separately.
"""
import json
from pathlib import Path
import re
import sys


def check(netlist, top_name, macros, root):
    modules = json.loads(Path(netlist).read_text())['modules']
    top = modules[top_name]
    failures = []
    for name in macros:
        module_name = 'ember_' + name
        module = modules.get(module_name)
        if module is None:
            failures.append(f'{name}: no interface module in wrapper JSON')
            continue
        instances = [cell for cell in top.get('cells', {}).values()
                     if cell['type'] == module_name]
        if len(instances) != 1:
            failures.append(f'{name}: expected one macro instance, got {len(instances)}')
            continue
        ports = module.get('ports', {})
        expected = set()
        for port_name, port in ports.items():
            bits = port['bits']
            offset = port.get('offset', 0)
            if len(bits) == 1 and not port.get('upto') and not offset:
                expected.add(port_name)
            else:
                expected.update(f'{port_name}[{i + offset}]' for i in range(len(bits)))
            connected = instances[0].get('connections', {}).get(port_name, [])
            # An unused OUTPUT (e.g. blit.done) may legally be disconnected.
            if port.get('direction') == 'output' and not connected:
                continue
            if len(connected) != len(bits):
                failures.append(f'{name}/{port_name}: connection width {len(connected)} '
                                f'!= interface width {len(bits)}')
        lef = Path(root) / name / (name + '.lef')
        pins = {pin.replace('\\', '') for pin in
                re.findall(r'^\s*PIN\s+(\S+)', lef.read_text(), re.MULTILINE)}
        pins -= {'VPWR', 'VGND', 'VPB', 'VNB'}
        missing, extra = expected - pins, pins - expected
        if missing or extra:
            failures.append(f'{name}: missing LEF pins {sorted(missing)[:12]}; '
                            f'extra LEF pins {sorted(extra)[:12]}')
        else:
            print(f'{name}: {len(pins)} signal pins match wrapper interface')
    if failures:
        raise ValueError('\n'.join(failures))


if __name__ == '__main__':
    try:
        check(sys.argv[1], sys.argv[2], sys.argv[3:], '/work/build/gds')
    except (OSError, KeyError, ValueError) as exc:
        print(exc)
        raise SystemExit(1)
