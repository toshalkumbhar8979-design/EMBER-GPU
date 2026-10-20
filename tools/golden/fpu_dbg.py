# Debug a few MUL/DIV mismatches with intermediate values.
import random, sys, os
sys.path.insert(0, os.path.dirname(__file__))
import fpu

random.seed(7)

def rnd_normal():
    while True:
        e = random.randint(1, 254)
        m = random.getrandbits(23)
        s = random.getrandbits(1)
        b = (s << 31) | (e << 23) | m
        if abs(fpu.b2f(b)) < 1e30 and abs(fpu.b2f(b)) > 1e-30:
            return b

def cast32(x):
    try:
        return fpu.f2b(x)
    except OverflowError:
        return 0x7F800000 if x > 0 else 0xFF800000

shown = 0
while shown < 4:
    a = rnd_normal()
    b = rnd_normal()
    fa, fb = fpu.b2f(a), fpu.b2f(b)
    got = cast32(fa * fb)
    want = fpu.fp_mul(a, b)
    if want != got and shown < 2:
        shown += 1
        prod = (1 << 23 | (a & 0x7FFFFF)) * (1 << 23 | (b & 0x7FFFFF))
        print(f"MUL a={a:08x} b={b:08x} golden={want:08x} struct={got:08x} "
              f"prod={prod:012x} prod47={(prod >> 47) & 1}")
    q = fa / fb
    if abs(q) < 3.4e38 and (q != 0.0 or abs(fa) < 1e-30):
        gotd = cast32(q)
        wantd = fpu.fp_div(a, b)
        if wantd != gotd and shown < 4:
            shown += 1
            print(f"DIV a={a:08x} b={b:08x} golden={wantd:08x} struct={gotd:08x}")
