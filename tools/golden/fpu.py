# tools/golden/fpu.py — Golden IEEE-754 single-precision reference (pure
# Python integers; mirrors the RTL algorithm in rtl/ember_fpu4.sv bit-for-bit:
# RNE, FTZ of subnormal results, 10-bit exponent with explicit wrap detect
# (values >= 512 are wrapped negatives -> FTZ), windows: ADD [0..255+carry],
# MUL [0..385], DIV [0..257]).
# Only assumes `struct` and integer math — no numpy.
import struct


def f2b(f):
    """Python float -> 32-bit IEEE single encoding (as unsigned int)."""
    return struct.unpack('<I', struct.pack('<f', f))[0]


def b2f(b):
    """32-bit IEEE single encoding -> Python float."""
    return struct.unpack('<f', struct.pack('<I', b & 0xFFFFFFFF))[0]


def _fields(b):
    return ((b >> 31) & 1, (b >> 23) & 0xFF, b & 0x7FFFFF)


def _is_nan(s, e, m):
    return e == 0xFF and m != 0


def _is_inf(s, e, m):
    return e == 0xFF and m == 0


def _is_z(e, m):
    return e == 0 and m == 0


def fp_add(ab, bb, sub):
    """IEEE-754 single ADD/SUB, RNE, FTZ subnormal results."""
    sa, ea, ma = _fields(ab)
    sb, eb, mb = _fields(bb)
    sbs = sb ^ (1 if sub else 0)
    if _is_nan(sa, ea, ma):
        return ab
    if _is_nan(sb, eb, mb):
        return bb
    if _is_inf(sa, ea, ma) and _is_inf(sb, eb, mb) and sa != sbs:
        return 0x7FC00000
    if _is_inf(sa, ea, ma):
        return ab
    if _is_inf(sb, eb, mb):
        return (sbs << 31) | 0x7F800000
    if _is_z(ea, ma) and _is_z(eb, mb):
        return 0
    if _is_z(ea, ma):
        return (sbs << 31) | (eb << 23) | mb
    if _is_z(eb, mb):
        return ab

    big_a = (ea > eb) or (ea == eb and ma >= mb)
    big_e = ea if big_a else eb
    delta = abs(ea - eb)

    fa = (1 << 33) | (ma << 10)          # 34-bit field, hidden bit at 33
    fb = (1 << 33) | (mb << 10)
    if delta >= 34:
        shifted = 1                          # pure sticky in guard field
    else:
        lost = fb if big_a else fa
        shifted = (lost >> delta) | (1 if (lost & ((1 << delta) - 1)) != 0 else 0)
    fa_al = fa if big_a else shifted
    fb_al = shifted if big_a else fb

    if sa == sbs:
        fsum = fa_al + fb_al
        sign_r = sa
    elif big_a:
        fsum = fa_al - fb_al
        sign_r = sa
    else:
        fsum = fb_al - fa_al
        sign_r = sbs

    if fsum == 0:
        return 0

    if fsum >> 34:
        norm = fsum >> 1
        e9 = big_e + 1
        s = ((fsum & 1) != 0) or ((norm & 0x1FF) != 0)
    else:
        top = fsum.bit_length() - 1
        norm = fsum << (33 - top)
        e9 = big_e + top - 33
        s = (norm & 0x1FF) != 0
    if e9 < 0:
        e9 += 2048                        # 11-bit wrap (RTL 11-bit exponent)

    fr = (norm >> 10) & 0x7FFFFF
    g = (norm >> 9) & 1
    if g and (s or (fr & 1)):
        if fr == 0x7FFFFF:
            e9 += 1
        fr = (fr + 1) & 0x7FFFFF

    if e9 >= 512:                        # wrapped underflow
        return sign_r << 31
    if e9 >= 255:
        return (sign_r << 31) | 0x7F800000
    if e9 == 0:
        return sign_r << 31
    return (sign_r << 31) | (e9 << 23) | fr


def fp_mul(ab, bb):
    """IEEE-754 single MUL, RNE, FTZ subnormal results."""
    sa, ea, ma = _fields(ab)
    sb, eb, mb = _fields(bb)
    sg = sa ^ sb
    if _is_nan(sa, ea, ma):
        return ab
    if _is_nan(sb, eb, mb):
        return bb
    if _is_inf(sa, ea, ma) or _is_inf(sb, eb, mb):
        if _is_z(ea, ma) or _is_z(eb, mb):
            return (sg << 31) | 0x7FC00000
        return (sg << 31) | 0x7F800000
    if _is_z(ea, ma) or _is_z(eb, mb):
        return sg << 31

    prod = (1 << 23 | ma) * (1 << 23 | mb)   # exact 48-bit product
    if prod >> 47:
        f24 = (prod >> 24) & 0xFFFFFF          # hidden=bit47, frac=[46:24]
        g = (prod >> 23) & 1
        s = (prod & 0x7FFFFF) != 0
        e9 = ea + eb - 126
    else:
        f24 = (prod >> 23) & 0xFFFFFF          # hidden=bit46, frac=[45:23]
        g = (prod >> 22) & 1
        s = (prod & 0x3FFFFF) != 0
        e9 = ea + eb - 127
    if e9 < 0:
        e9 += 2048                        # 11-bit wrap (RTL 11-bit exponent)
    fr = f24 & 0x7FFFFF
    if g and (s or (fr & 1)):
        if fr == 0x7FFFFF:
            e9 += 1
        fr = (fr + 1) & 0x7FFFFF
    if e9 >= 512:                        # wrapped underflow
        return sg << 31
    if e9 >= 255:
        return (sg << 31) | 0x7F800000
    if e9 == 0:
        return sg << 31
    return (sg << 31) | (e9 << 23) | fr


def fp_div(ab, bb):
    """IEEE-754 single DIV, RNE, FTZ subnormal results."""
    sa, ea, ma = _fields(ab)
    sb, eb, mb = _fields(bb)
    sg = sa ^ sb
    if _is_nan(sa, ea, ma):
        return ab
    if _is_nan(sb, eb, mb):
        return bb
    if _is_inf(sa, ea, ma) and _is_inf(sb, eb, mb):
        return 0x7FC00000
    if _is_inf(sa, ea, ma):
        return (sg << 31) | 0x7F800000
    if _is_inf(sb, eb, mb):
        return sg << 31
    if _is_z(eb, mb):
        if _is_z(ea, ma):
            return 0x7FC00000
        return (sg << 31) | 0x7F800000
    if _is_z(ea, ma):
        return sg << 31

    num = (1 << 23 | ma) << 26               # dividend, 50 bits
    den = 1 << 23 | mb
    q = 0
    rem = 0
    for i in range(50):
        rem = (rem << 1) | ((num >> (49 - i)) & 1)
        q <<= 1
        if rem >= den:
            rem -= den
            q |= 1
    # quotient in [2^25, 2^27): leading 1 at bit 26 or 25
    if (q >> 26) & 1:
        f24 = (q >> 3) & 0xFFFFFF
        g = (q >> 2) & 1
        s = ((q & 0x3) != 0) or rem != 0
        e9 = ea - eb + 127
    else:
        f24 = (q >> 2) & 0xFFFFFF
        g = (q >> 1) & 1
        s = (q & 0x1) != 0 or rem != 0
        e9 = ea - eb + 126
    if e9 < 0:
        e9 += 2048                        # 11-bit wrap (RTL 11-bit exponent)
    fr = f24 & 0x7FFFFF
    if g and (s or (fr & 1)):
        if fr == 0x7FFFFF:
            e9 += 1
        fr = (fr + 1) & 0x7FFFFF
    if e9 >= 512:                        # wrapped underflow
        return sg << 31
    if e9 >= 255:
        return (sg << 31) | 0x7F800000
    if e9 == 0:
        return sg << 31
    return (sg << 31) | (e9 << 23) | fr


def fp_exec(op, ab, bb):
    """op: 0=ADD 1=SUB 2=MUL 3=DIV (matches RTL op[1:0])."""
    if op == 0:
        return fp_add(ab, bb, False)
    if op == 1:
        return fp_add(ab, bb, True)
    if op == 2:
        return fp_mul(ab, bb)
    return fp_div(ab, bb)
