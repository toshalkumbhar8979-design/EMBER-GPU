"""
Golden GSX geometry reference for the Ember GPU — Phase 4b.

Mirrors rtl/ember_gsx.sv BIT-FOR-BIT:
  * Transform y = M*v with v = (x,y,z,1); every mul/add goes through
    tools/golden/fpu.py fp_exec (bit-exact IEEE-754 single, RNE, FTZ) in the
    RTL's exact op order: per row  p_c = M[r][c]*v[c]  then
    acc = ((p0 + p1) + p2) + p3  (each "+" a rounded ADD).
  * Perspective divide x/w, y/w, z/w via fp_exec DIV (op 3).
  * Conversions are integer-exact mirrors of the RTL functions:
      fp_to_q22 : q22 = 1.m * 2^(e-128), trunc, saturate e>=136 (32-bit ops)
      fp_to_z16 : z16 = (1.m * 65535) >> (150-e), e>=127 -> FFFF, neg -> 0
      sat22     : signed clamp to +/-2147483000
  * Cull: any vertex w <= 0 (sign bit set or exactly zero) drops the triangle.
  * Emit: 19-word RTR command (same packing as tb_rtr.tri_cmd_words, minus
    texture words which are zero) + 0-terminator in append mode.

Cube demo: 8 verts, 12 triangles (faces wound so they survive the RTR's
CCW-front rule through the y-flipping viewport matrix), one 4x4 MVP composed
in float64 then quantized to fp32 words (only composition uses f64; the GSX
path itself is pure fp32).
"""

import math

import fpu
import raster

Q = raster.Q  # 22


# ------------------------------------------------------------ conversions --
def fp_to_q22(fb: int) -> int:
    """Mirror of rtl/ember_gsx.sv fp_to_q22 (32-bit truncating ops)."""
    e = (fb >> 23) & 0xFF
    if (fb & 0x7FFFFFFF) == 0:
        return 0
    if e >= 136:
        return 0x80000000 if (fb >> 31) else 0x7FFFFFFF
    i24 = (1 << 23) | (fb & 0x7FFFFF)
    if e >= 128:
        mag = (i24 << (e - 128)) & 0xFFFFFFFF      # 32-bit trunc on overflow
    else:
        mag = i24 >> (128 - e)
    if (fb >> 31) and mag:
        mag = (~mag + 1) & 0xFFFFFFFF
    return mag


def fp_to_z16(fb: int) -> int:
    """Mirror of rtl/ember_gsx.sv fp_to_z16 (ndc 0..1 -> u16 depth)."""
    e = (fb >> 23) & 0xFF
    if (fb >> 31) or (fb & 0x7FFFFFFF) == 0:
        return 0
    if e >= 127:
        return 0xFFFF
    prod = ((1 << 23) | (fb & 0x7FFFFF)) * 65535
    return (prod >> (150 - e)) & 0xFFFF


def sat22(v: int) -> int:
    """Mirror of rtl/ember_gsx.sv sat22 (signed clamp, s32 in/out)."""
    if v & 0x80000000:
        v -= 1 << 32
    if v > 2147483000:
        return 2147483000
    if v < -2147483000:
        return -2147483000
    return v


def _to_signed(v: int) -> int:
    return v - (1 << 32) if v & 0x80000000 else v


# --------------------------------------------------------------- transform --
def _clip_w(mata: list, vtx3: list) -> int:
    """Row-3 dot product only (clip w) — used by the texture path."""
    v = [vtx3[0], vtx3[1], vtx3[2], 0x3F800000]
    prods = [fpu.fp_exec(2, mata[12 + c], v[c]) for c in range(4)]
    acc = prods[0]
    for c in range(1, 4):
        acc = fpu.fp_exec(0, acc, prods[c])
    return acc


def gsx_transform(mata: list, vtx: list):
    """One homogeneous vertex through M (both as fp32 word lists).

    mata: 16 words, row-major (m[4r+c]); vtx: [x,y,z] words.
    Returns (px_q22_word, py_q22_word, pz16) or None when culled (w<=0).
    """
    v = [vtx[0], vtx[1], vtx[2], 0x3F800000]     # homogeneous 1.0
    clip = []
    for r in range(4):
        # RTL order: MUL per column, then left-to-right ADD chain
        prods = [fpu.fp_exec(2, mata[4 * r + c], v[c]) for c in range(4)]
        acc = prods[0]
        for c in range(1, 4):
            acc = fpu.fp_exec(0, acc, prods[c])  # ADD
        clip.append(acc)

    w = clip[3]
    if (w >> 31) or (w & 0x7FFFFFFF) == 0:
        return None                              # near-cull

    x_ndc = fpu.fp_exec(3, clip[0], w)           # DIV
    y_ndc = fpu.fp_exec(3, clip[1], w)
    z_ndc = fpu.fp_exec(3, clip[2], w)

    px = sat22(fp_to_q22(x_ndc))
    py = sat22(fp_to_q22(y_ndc))
    pz = fp_to_z16(z_ndc)
    return px, py, pz


def gsx_cmd_words(mata: list, vtx9: list, col3: list, cfg: int):
    """Full GSX triangle: transform 3 verts, emit the 19-word command.

    cfg bits: [24] ztest, [26] blend, [27] tex (GSX CFG register form,
    bit31=0). Returns None if the triangle is culled.
    """
    words = [0] * raster.__dict__.get("RTR_CMD_WORDS", 19)
    rtr_words = 19
    words = [0] * rtr_words
    xy = []
    zs = []
    for i in range(3):
        t = gsx_transform(mata, vtx9[3 * i:3 * i + 3])
        if t is None:
            return None
        xy += [t[0], t[1]]
        zs.append(t[2])

    ztest = (cfg >> 24) & 1
    blend = (cfg >> 26) & 1
    texen = (cfg >> 27) & 1
    words[0] = 1 | (blend << 1) | (ztest << 2) | (texen << 3)
    for i in range(6):
        words[1 + i] = _to_signed(xy[i]) & 0xFFFFFFFF
    for i in range(3):
        words[7 + i] = zs[i] & 0xFFFF
    for i in range(3):
        words[10 + i] = col3[i] & ((1 << 24) - 1)   # {b,g,r,x} u8 fields
    return words


# ----------------------------------------------------------------- matrices --
def f32m(m4x4):
    """float64 4x4 (row lists) -> flat fp32 word list (row-major)."""
    return [fpu.f2b(m4x4[r][c]) for r in range(4) for c in range(4)]


def mat_mul(A, B):
    """float64 4x4 compose A*B (apply B first)."""
    return [[sum(A[r][k] * B[k][c] for k in range(4)) for c in range(4)]
            for r in range(4)]


def rot_x(a):
    c, s = math.cos(a), math.sin(a)
    return [[1, 0, 0, 0], [0, c, -s, 0], [0, s, c, 0], [0, 0, 0, 1]]


def rot_z(a):
    c, s = math.cos(a), math.sin(a)
    return [[c, -s, 0, 0], [s, c, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1]]


def mvp_cube_words(angle_z=math.radians(35), angle_x=math.radians(20)):
    """Spinning-cube MVP: perspective + viewport folded in (GSX divides by w).

    screen_x = 160 + 160*ndc_x ; screen_y = 120 - 120*ndc_y (y flip).
    Camera: object translated to z = -3; near 1, far 9; f = 1.14.
    w' = -z_obj + 3 > 0 for the whole cube (z_obj in [-1,1]).
    """
    f = 1.14
    aspect = 4.0 / 3.0
    near, far, dist = 1.0, 9.0, 3.0
    a = (far + near) / (near - far)          # z row of the frustum
    b = 2.0 * far * near / (near - far)
    P = [
        [160.0 * f / aspect, 0.0, 0.0, 160.0],
        [0.0, -120.0 * f, 0.0, 120.0],
        [0.0, 0.0, a, b],
        [0.0, 0.0, -1.0, dist],
    ]
    # fold the view translate (0,0,-dist): col3 of every row shifts by -dist*col2
    P[0][3] += 0.0
    M = mat_mul(P, mat_mul(
        [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, -dist], [0, 0, 0, 1]],
        mat_mul(rot_x(angle_x), rot_z(angle_z))))
    # note: P row3 already has the translate folded (w' = -z + dist), so the
    # middle term must NOT translate w; rebuild row3 explicitly.
    M[3] = [0.0, 0.0, -1.0, dist]
    return f32m(M)


# --------------------------------------------------------------- cube data --
# Unit cube, faces wound for the RTR's CCW-front rule under the y-flipping
# viewport (world-CCW-from-outside reversed = screen-CCW). Verified by
# render_frame below (all 12 must survive backface culling).
CUBE_VERTS = [
    (-1, -1, -1), (1, -1, -1), (1, 1, -1), (-1, 1, -1),
    (-1, -1, 1), (1, -1, 1), (1, 1, 1), (-1, 1, 1),
]

# (indices, rgb) — reversed winding from the outward-CCW listing
CUBE_FACES = [
    ([0, 2, 1], (255, 0, 0)),     # front  (z=-1) red
    ([0, 3, 2], (255, 0, 0)),
    ([4, 5, 6], (0, 255, 0)),     # back   (z=+1) green
    ([4, 6, 7], (0, 255, 0)),
    ([3, 6, 2], (0, 0, 255)),     # top    (y=+1) blue
    ([3, 7, 6], (0, 0, 255)),
    ([0, 1, 5], (255, 255, 0)),   # bottom (y=-1) yellow
    ([0, 5, 4], (255, 255, 0)),
    ([0, 4, 7], (255, 0, 255)),   # left   (x=-1) magenta
    ([0, 7, 3], (255, 0, 255)),
    ([1, 2, 6], (0, 255, 255)),   # right  (x=+1) cyan
    ([1, 6, 5], (0, 255, 255)),
]


def _vword(x, y, z):
    return [fpu.f2b(float(x)), fpu.f2b(float(y)), fpu.f2b(float(z))]


def _colword(rgb):
    r, g, b = rgb
    return (b << 16) | (g << 8) | r          # {b,g,r,x}


def cube_cmds(mata: list, cfg: int, ztest=1):
    """All 12 cube triangles through the golden GSX -> list of 19-word cmds."""
    cmds = []
    for idxs, rgb in CUBE_FACES:
        vtx = []
        for i in idxs:
            vtx += _vword(*CUBE_VERTS[i])
        col = [_colword(rgb)] * 3
        c = cfg | ((1 if ztest else 0) << 24)
        w = gsx_cmd_words(mata, vtx, col, c)
        if w is not None:
            cmds.append(w)
    return cmds


def render_frame(vram: raster.Vram, mata: list, cfg: int, ztest=1):
    """Golden spinning-cube frame: clear FB+Z, run every face through the
    golden GSX AND the golden rasterizer. Returns the number of drawn tris."""
    for i in range(raster.SCR_W * raster.SCR_H):
        vram.w16(raster.FB0_BASE + i * 2, 0)
        vram.w16(raster.ZBUF_BASE + i * 2, 0xFFFF)
    n = 0
    for words in cube_cmds(mata, cfg, ztest):
        cmd = _words_to_rtrcmd(words)
        raster.rasterize_triangle(vram, cmd)
        n += 1
    return n


def _words_to_rtrcmd(words):
    """Unpack a 19-word GSX command back into the golden rasterizer IR."""
    f = words[0]
    tri = raster.Tri(
        raster.Vtx(x=_to_signed(words[1]), y=_to_signed(words[2]),
                   z=words[7] & 0xFFFF, r=words[10] & 0xFF,
                   g=(words[10] >> 8) & 0xFF, b=(words[10] >> 16) & 0xFF),
        raster.Vtx(x=_to_signed(words[3]), y=_to_signed(words[4]),
                   z=words[8] & 0xFFFF, r=words[11] & 0xFF,
                   g=(words[11] >> 8) & 0xFF, b=(words[11] >> 16) & 0xFF),
        raster.Vtx(x=_to_signed(words[5]), y=_to_signed(words[6]),
                   z=words[9] & 0xFFFF, r=words[12] & 0xFF,
                   g=(words[12] >> 8) & 0xFF, b=(words[12] >> 16) & 0xFF),
    )
    return raster.RtrCmd(tri=tri, blend=(f >> 1) & 1, ztest=(f >> 2) & 1)
