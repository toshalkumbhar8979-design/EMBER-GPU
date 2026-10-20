# Smoke: golden fp32 vs struct-based single math (double-compute -> single round).
# Correctly rounded for add/sub/mul (exact in double); div can double-round rarely.
import random
import sys
import os
sys.path.insert(0, os.path.dirname(__file__))
import fpu

random.seed(20260926)

def rnd_normal():
    while True:
        e = random.randint(1, 254)
        m = random.getrandbits(23)
        s = random.getrandbits(1)
        b = (s << 31) | (e << 23) | m
        if abs(fpu.b2f(b)) < 1e30 and abs(fpu.b2f(b)) > 1e-30:
            return b

def cast32(x):  # round double to single bits (RNE via struct)
    try:
        return fpu.f2b(x)
    except OverflowError:
        return 0x7F800000 if x > 0 else 0xFF800000  # overflow -> Inf

def ftz_ok(got, want):
    """True when the only difference is golden's designed FTZ of a subnormal.
    (struct honors subnormals; golden/RTL flush them to zero by contract.)"""
    gm, wm = got & 0x7FFFFFFF, want & 0x7FFFFFFF
    return wm == 0 and 0 < gm < 0x00800000

n = 20000
bad = {0: 0, 1: 0, 2: 0, 3: 0}
shown = {0: 0, 1: 0, 2: 0, 3: 0}
for _ in range(n):
    a = rnd_normal()
    b = rnd_normal()
    fa, fb = fpu.b2f(a), fpu.b2f(b)
    for op, expr in ((0, fa + fb), (1, fa - fb), (2, fa * fb)):
        want = fpu.fp_exec(op, a, b)
        got = cast32(expr)
        if want != got and not ftz_ok(got, want):
            bad[op] += 1
            if shown[op] < 3:
                shown[op] += 1
                print(f"MISMATCH op{op} a={a:08x} b={b:08x} golden={want:08x} struct={got:08x}")
    # div: allow double-rounding tolerance; skip when quotient overflows single
    want = fpu.fp_exec(3, a, b)
    q = fa / fb
    if abs(q) < 3.4e38 and (q != 0.0 or abs(fa) < 1e-30):
        got = cast32(q)
        if want != got and not ftz_ok(got, want):
            bad[3] += 1
            if shown[3] < 5:
                shown[3] += 1
                print(f"DIVDIFF a={a:08x} b={b:08x} golden={want:08x} struct={got:08x}")

print(f"n={n} add_bad={bad[0]} sub_bad={bad[1]} mul_bad={bad[2]} div_diff={bad[3]}")
ok = bad[0] == 0 and bad[1] == 0 and bad[2] == 0 and bad[3] == 0
print("SMOKE PASS" if ok else "SMOKE FAIL")
sys.exit(0 if ok else 1)
