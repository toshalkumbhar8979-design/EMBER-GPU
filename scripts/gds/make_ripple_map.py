import pathlib
import re
import subprocess

# Resolve the installed Yosys resource path from the frontend log.
probe = subprocess.run(['yosys', '-Q', '-T', '-p', 'read_verilog +/techmap.v'],
                       capture_output=True, text=True, check=True)
match = re.search(r'frontend: (.+/techmap\.v)', probe.stdout)
if not match:
    raise SystemExit('Cannot resolve installed techmap.v')
source = pathlib.Path(match.group(1)).read_text()
replacement = pathlib.Path('/work/scripts/gds/ripple_lcu.v').read_text()
replacement = replacement.replace('ember_ripple_lcu', '_90_lcu_brent_kung')
pattern = r'\(\* techmap_celltype = "\$lcu" \*\)\s*module _90_lcu_brent_kung\b.*?endmodule'
source, count = re.subn(pattern, lambda _: replacement, source, flags=re.S)
if count != 1:
    raise SystemExit(f'Expected one LCU template, got {count}')
divider = pathlib.Path('/work/scripts/gds/divmod_u.v').read_text()
pattern = r'module \\\$__div_mod_u\s*\(.*?endmodule'
source, count = re.subn(pattern, lambda _: divider, source, flags=re.S)
if count != 1:
    raise SystemExit(f'Expected one unsigned divider template, got {count}')
pathlib.Path('/work/build/gds/ripple_techmap.v').write_text(source)
print('Generated ripple_techmap.v from', match.group(1))
