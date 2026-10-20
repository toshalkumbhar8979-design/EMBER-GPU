import pathlib
import re
import subprocess

root = pathlib.Path('/work/build/gds')
probe = subprocess.run(['yosys', '-Q', '-T', '-p', 'read_verilog +/techmap.v'],
                       capture_output=True, text=True, check=True)
path = re.search(r'frontend: (.+/techmap\.v)', probe.stdout).group(1)
source = pathlib.Path(path).read_text()
module = re.search(r'module \\\$__div_mod_u\s*\(.*?endmodule', source, re.S).group(0)
gold = module.replace(r'\$__div_mod_u', 'gold')
gate = pathlib.Path('/work/scripts/gds/divmod_u.v').read_text().replace(r'\$__div_mod_u', 'gate')
(root / 'divider_equiv.v').write_text(gold + '\n' + gate)
for width in (1, 4, 8):
    script = f'''read_verilog {root}/divider_equiv.v
chparam -set WIDTH {width} gold
chparam -set WIDTH {width} gate
proc
opt
equiv_make gold gate equiv
hierarchy -top equiv
flatten
techmap
opt
equiv_simple
equiv_status -assert
'''
    result = subprocess.run(['yosys', '-Q', '-T', '-p', script], capture_output=True, text=True)
    (root / f'divider_equiv_{width}.log').write_text(result.stdout + result.stderr)
    if result.returncode:
        raise SystemExit(f'Equivalence failed for WIDTH={width}: {result.stderr}')
    print(f'WIDTH={width}: quotient AND remainder formally equivalent')

# Wide simulation against independent Python integer arithmetic, with zero
# divisor, boundary values and deterministic random bit patterns.
import random
rng = random.Random(20261002)
for width in (67, 118, 384):
    mask = (1 << width) - 1
    vectors = [(0, 0), (mask, 0), (mask, 1), (mask, mask), (0, mask),
               (1, mask), (1 << (width-1), 2)]
    vectors += [(rng.getrandbits(width), rng.getrandbits(width)) for _ in range(100)]
    checks = []
    for a, b in vectors:
        q, rem = (a // b, a % b) if b else (mask, a)
        checks.append(f"a={width}'h{a:x}; b={width}'h{b:x}; #1; "
                      f"if (y !== {width}'h{q:x} || r !== {width}'h{rem:x}) "
                      '$fatal(1, "wide divider mismatch");')
    bench = root / f'divider_wide_{width}.v'
    bench.write_text(f'''module tb;
reg [{width-1}:0] a, b;
wire [{width-1}:0] y, r;
\\$__div_mod_u #(.WIDTH({width})) dut(a,b,y,r);
initial begin
''' + '\n'.join(checks) + '\n$display("WIDE PASS"); $finish; end\nendmodule\n')
    executable = root / f'divider_wide_{width}.out'
    subprocess.run(['iverilog', '-g2012', '-s', 'tb', '-o', str(executable),
                    '/work/scripts/gds/divmod_u.v', str(bench)], check=True)
    subprocess.run(['vvp', str(executable)], check=True)
    print(f'WIDTH={width}: {len(vectors)} wide arithmetic vectors passed')
