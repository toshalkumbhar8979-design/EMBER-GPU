"""
tools/golden/gamestate.py — Phase-7 closure: golden mirror of
kernels/gamestate.asm (the INPUT-DRIVEN game state kernel).

The kernel runs the per-frame game loop ON THE CORE in Q16 fixed point:
  vel += in*ACC - (KFR*vel >> 16)      (inertia: vel decays toward 0)
  vel  = clamp(vel, -VMAX, +VMAX)
  pos += vel ;  pos clamped to the walk path (|x|<=2, z in [0,1])
and converts the camera position to fp32 BIT form (round-half-up at
mantissa bit 23) so the TB can patch the GSX MVP words (row0[3] = cam_x,
row3[3] = 3.0 + cam_z) and render. Camera position -> pixels is RTL
end-to-end; only per-frame INPUTS come from the TB.

All arithmetic mirrors the KERNEL (int32 wraparound, logical >>16 of the
signed product, signed MIN/MAXC, +64 >>7 round-half-up), NOT ideal math.
State block layout (byte offsets) matches the kernel header exactly.
"""
import math

Q = 65536                       # Q16: 65536 = 1.0
ACC = 1638                      # 0.025/frame^2
VMAX = 20 * Q                   # 1310720
PX = 2 * Q                      # walk-path x clamp (131072)
PZ = 1 * Q                      # walk-path z clamp (65536)
FRAMES = 32                     # input script length
M32 = 0xFFFFFFFF


def _s32(v):
    v &= M32
    return v - (1 << 32) if v >= (1 << 31) else v


def _shl(v, n):
    return _s32(v << n)


def _shr_logical(v, n):
    return (v & M32) >> n


def _clamp_s32(v):
    """Simulate the 32-bit register write-back (only reachable transiently)."""
    return _s32(v)


def step_state(st, ax, az):
    """One frame of the kernel physics. st = [pos_x, pos_z, vel_x, vel_z].

    Exact mirror of kernels/gamestate.asm: signed 32-bit arithmetic with
    wraparound; magnitude-form decay (SHR is LOGICAL, so the signed
    product trick only works for v >= 0): f = |v| >> 4 (floor, |v| >= 0
    makes logical == arithmetic), v -= f if v > 0 else v += f — matching
    the kernel's maxc/branch pair, INCLUDING v == 0 -> the branch takes
    the subtract path (0 - 0 = 0, harmless); signed MIN/MAXC clamps.
    """
    s32 = _s32

    def decay(v):
        av = max(v, _s32(-v))                  # maxc(v, -v) = |v|
        f = av >> 4                            # logical >>4 == arith here
        if v > 0:
            return s32(v - f)                  # kernel fxp path
        return s32(v + f)                      # kernel fall-through (v<=0)

    vx, vz = st[2], st[3]
    vx = s32(vx + s32(ax * ACC))               # vel += in*ACC
    vz = s32(vz + s32(az * ACC))
    vx = decay(vx)                             # then decay (kernel order)
    vz = decay(vz)
    vx = min(max(vx, s32(-VMAX)), VMAX)        # signed MIN/MAXC
    vz = min(max(vz, s32(-VMAX)), VMAX)
    px = s32(st[0] + vx)                       # pos += vel
    pz = s32(st[1] + vz)
    px = min(max(px, s32(-PX)), PX)            # walk-path clamps
    pz = min(max(pz, 0), PZ)
    st[0], st[1], st[2], st[3] = px, pz, vx, vz
    return st


def f2q(q16):
    """Bit-exact mirror of the kernel's f2q: fp32 bits of q16/65536.

    Normalize until bit 30 set (s = shift count), exponent field
    141 - s, mantissa = ((N + 64) >> 7) & 0x7FFFFF (round-half-up),
    sign bit via 0x8000 << 16. Zero -> 0.
    """
    q = _s32(q16)
    if q == 0:
        return 0
    if q < 0:
        sign = 0x8000 << 16
        q = _s32(-q)
    else:
        sign = 0
    s = 0
    while (q >> 30) & 1 == 0:
        q = _shl(q, 1)
        s += 1
    n = q
    mant = ((n + 64) >> 7) & 0x7FFFFF
    e = 141 - s
    return sign | ((e & 0xFF) << 23) | mant


def state_echo(cookie, counter):
    """Echo word: (cookie << 8) | free-running frame counter, low byte."""
    return ((cookie << 8) | (counter & 0xFF)) & M32


def patch_mvp(mata, row0_word, row3_word):
    """Return mata with row0[3]=row0_word, row3[3]=row3_word replaced.

    f32m is ROW-major: row0[3] = word 3, row3[3] = word 15.

    row3[3] = 3.0 + cam_z is a pure Q16 addition -> the KERNEL's f2q word
    is used directly. row0[3] = 480 - sx*cam_x folds the 136.8 viewport
    scale: in Q16 the product needs 37 bits and MUL truncates at 32, so
    this word is folded TB-side with double math + f2b from the kernel's
    pos state (same arithmetic as mvp_fly_words)."""
    m = list(mata)
    m[3] = row0_word & M32
    m[15] = row3_word & M32
    return m


_SCRIPT_CACHE = None


def demo_inputs():
    """The search-chosen 32-frame input script (segment order: forward,
    left, right, released — the idle tail coasts on inertia, which is the
    whole point of the on-core physics). Values in integer input units
    (consumed as in*ACC); sign = direction."""
    return demo_script()[0]


def script_path(inputs):
    """Run the golden physics over an input list -> list of (cam_x, cam_z)
    in world units (pos_q16 / 65536)."""
    st = [0, 0, 0, 0]
    path = []
    for ax, az in inputs:
        step_state(st, ax, az)
        path.append((st[0] / Q, st[1] / Q))
    return path


def _demo_search():
    """Fixed, hand-designed 32-frame input script (the 'search' that
    rewarded wall-pinned static frames is gone): forward, left, right,
    forward with 2-frame idle gaps — every position advances each frame
    (the coast gaps decay velocity smoothly instead of pinning on clamps).
    Returns (inputs, path)."""
    inp = ([(0, 1)] * 6 + [(0, 0)] * 2            # walk in
           + [(-1, 0)] * 6 + [(0, 0)] * 2         # strafe left
           + [(1, 0)] * 6 + [(0, 0)] * 2          # strafe right
           + [(0, 1)] * 6 + [(0, 0)] * 2)         # walk in again
    return inp, script_path(inp)


def demo_script():
    """(inputs, path) for the 32-frame demo — the search runs once."""
    global _SCRIPT_CACHE
    if _SCRIPT_CACHE is None:
        _SCRIPT_CACHE = _demo_search()
    return _SCRIPT_CACHE


# --------------------------------------------------------------- selftest ---
def _selftest():
    # f2q vs Python float quantization over a Q16-representable sweep
    for v in [0.0, 1.0, 0.5, 0.25, 0.75, -0.5, -1.0, -1.96875,
              0.05, -0.05, 1.99609375, -1.99609375, 0.9609375,
              0.001, -0.001, 3.0, 3.25, 2.0, 0.49609375]:
        q = int(round(v * Q))
        target = q / Q                # f2q quantizes to Q16 FIRST
        bits = f2q(q)
        import struct
        fl = struct.unpack("<f", struct.pack("<I", bits))[0]
        # round-half-up at bit23 == round-to-nearest; compare against the
        # EXACT Q16 value q/Q within 1 fp32 ulp at that exponent
        e = 0 if fl == 0 else math.floor(math.log2(abs(fl)))
        ulp = math.ldexp(1.0, e - 23)
        assert abs(fl - target) <= max(ulp, 1e-12), (v, hex(bits), fl)
    # exact bit cases (hand-computed)
    assert f2q(Q) == 0x3F800000, hex(f2q(Q))              # 1.0
    assert f2q(2 * Q) == 0x40000000, hex(f2q(2 * Q))      # 2.0
    assert f2q(0) == 0
    assert f2q(-Q) == (0x80000000 | 0x3F800000)           # -1.0
    assert f2q(3 * Q + 16384) == 0x40500000               # 3.25
    # physics: idle decay (32 frames -> pos_z ~0), forward accel saturates
    st = [0, 0, 0, 0]
    for _ in range(32):
        step_state(st, 0, 0)
    assert st == [0, 0, 0, 0], st
    # forward accel: decay = |v|/16 per frame, terminal speed 0.4*in u/frame;
    # after 16 frames at in=1 the z velocity reaches ~0.24 units/frame
    st = [0, 0, 0, 0]
    for _ in range(16):
        step_state(st, 0, 1)
    assert st[3] > 0.2 * Q, st                             # z vel > 0.2
    # wall clamps engage
    st = [0, 0, 0, 0]
    for _ in range(64):
        step_state(st, 4, 1)
    assert st[1] == PZ and st[0] == PX, st                 # pinned on walls
    # demo script produces non-degenerate motion
    inp, path = demo_script()
    xs = [p[0] for p in path]
    zs = [p[1] for p in path]
    assert (max(xs) - min(xs)) >= 0.4, xs                  # real sway
    assert max(zs) > 0.9, zs                               # into the temple
    print("gamestate golden selftest PASS")


if __name__ == "__main__":
    _selftest()
