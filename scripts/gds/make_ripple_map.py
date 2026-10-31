import pathlib
import re
import subprocess

# Yosys ships its techmap templates inside techmap.v and renames them between
# releases ($lcu is `_90_lcu_brent_kung` in 0.65, `_90_lcu` in 0.38), so match
# the attribute rather than the module name and keep whatever name that build
# uses. 2026-10-31: the CI container's 0.38 copy failed the old name-anchored
# regex with "Expected one LCU template, got 0" and killed the rtr_* synth jobs.
ROOT = pathlib.Path('/work')


def yosys_version():
    try:
        out = subprocess.run(['yosys', '-V'], capture_output=True, text=True)
        return out.stdout.strip() or out.stderr.strip() or 'unknown'
    except OSError as exc:
        return f'unavailable ({exc})'


probe = subprocess.run(['yosys', '-Q', '-T', '-p', 'read_verilog +/techmap.v'],
                       capture_output=True, text=True)
if probe.returncode != 0:
    raise SystemExit(f'yosys cannot load +/techmap.v ({yosys_version()}): '
                     f'{(probe.stderr or probe.stdout).strip()[-300:]}')
match = re.search(r'frontend: (.+/techmap\.v)', probe.stdout)
if not match:
    raise SystemExit(f'Cannot resolve installed techmap.v ({yosys_version()})')
techmap = pathlib.Path(match.group(1))
source = techmap.read_text()

# ---- carry lookahead: replace whatever $lcu implementation this build has ---
lcu_pattern = re.compile(
    r'\(\*[^*]*techmap_celltype\s*=\s*"\$lcu"[^*]*\*\)\s*module\s+(\w+)\b.*?endmodule',
    re.S)
found = lcu_pattern.search(source)
if not found:
    raise SystemExit(f'no techmap_celltype="$lcu" template in {techmap} '
                     f'({yosys_version()})')
lcu_name = found.group(1)
replacement = (ROOT / 'scripts/gds/ripple_lcu.v').read_text()
replacement = replacement.replace('ember_ripple_lcu', lcu_name)
source = source[:found.start()] + replacement + source[found.end():]
print(f'ripple LCU: replaced {lcu_name} in {techmap} ({yosys_version()})')

# ---- divider: swap in long division with a WIDTH+1 remainder ----------------
divider_pattern = re.compile(r'module \\\$__div_mod_u\s*\(.*?endmodule', re.S)
found = divider_pattern.search(source)
if not found:
    raise SystemExit(f'no \\$__div_mod_u template in {techmap} ({yosys_version()})')
divider = (ROOT / 'scripts/gds/divmod_u.v').read_text()
source = source[:found.start()] + divider + source[found.end():]

out = ROOT / 'build/gds/ripple_techmap.v'
out.write_text(source)
print('Generated ripple_techmap.v from', techmap)
