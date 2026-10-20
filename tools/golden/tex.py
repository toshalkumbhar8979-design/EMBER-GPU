"""
tools/golden/tex.py — Golden textured-triangle support (Phase 7).

Mirrors the GSX texture path bit-exactly. IMPORTANT CONTRACT NOTE: the v1
RTR's inv_w plane is CONSTANT (setup takes no per-vertex w), so command
words 13..18 are AFFINE texcoords — GSX emits fp_to_q22(u), fp_to_q22(v)
WITHOUT the divide (pre-dividing would be divided again by 1/w==1... a
no-op — the real reason: the RTR's u_final = u_raw<<Q / inv_w simplifies
to u_raw when inv_w == 1<<Q). Perspective-correct texturing needs the v2
RTR change (per-vertex 1/w into setup) and is NOT in v1.

Provides the CLUT texture generator and textured quad/cube commands for
the Phase 7 scene demo, reusing cube.py geometry.
"""

import fpu
import cube
import raster


def gsx_tex_cmd_words(mata, v15, col3, cfg):
    """Full GSX triangle WITH texture: v15 = 15 words
    (x0,y0,z0,u0,v0, x1,y1,z1,u1,v1, x2,y2,z2,u2,v2).

    cfg bit27 = tex_en, [23:16] = texpage. Returns None if culled.
    """
    words = [0] * 19
    xy = []
    zs = []
    uw = []
    vw = []
    for i in range(3):
        # transform (reuse cube.gsx_transform for x/y/z)
        t = cube.gsx_transform(mata, v15[5 * i:5 * i + 3])
        if t is None:
            return None
        xy += [t[0], t[1]]
        zs.append(t[2])

        w = cube._clip_w(mata, v15[5 * i:5 * i + 3])
        if (w >> 31) or (w & 0x7FFFFFFF) == 0:
            return None                       # cull (transform passed but
                                              # w<=0 is checked again here)
        # v1 affine contract: RAW u,v converted, NO divide
        uw.append(cube.fp_to_q22(v15[5 * i + 3]))
        vw.append(cube.fp_to_q22(v15[5 * i + 4]))

    ztest = (cfg >> 24) & 1
    blend = (cfg >> 26) & 1
    texen = (cfg >> 27) & 1
    page = (cfg >> 16) & 0xFF
    words[0] = 1 | (blend << 1) | (ztest << 2) | (texen << 3) | (page << 8)
    for i in range(6):
        words[1 + i] = cube._to_signed(xy[i]) & 0xFFFFFFFF
    for i in range(3):
        words[7 + i] = zs[i] & 0xFFFF
    for i in range(3):
        words[10 + i] = col3[i] & ((1 << 24) - 1)
    uv = uw[0:1] + vw[0:1] + uw[1:2] + vw[1:2] + uw[2:3] + vw[2:3]
    for i in range(6):
        words[13 + i] = uv[i] & 0xFFFFFFFF
    return words


def words_to_rtrcmd(words):
    """Unpack a 19-word GSX command (textured) into the rasterizer IR."""
    f = words[0]
    tri = raster.Tri(
        raster.Vtx(x=cube._to_signed(words[1]), y=cube._to_signed(words[2]),
                   z=words[7] & 0xFFFF, r=words[10] & 0xFF,
                   g=(words[10] >> 8) & 0xFF, b=(words[10] >> 16) & 0xFF,
                   u=cube._to_signed(words[13]),
                   v=cube._to_signed(words[14]), tex_en=(f >> 3) & 1),
        raster.Vtx(x=cube._to_signed(words[3]), y=cube._to_signed(words[4]),
                   z=words[8] & 0xFFFF, r=words[11] & 0xFF,
                   g=(words[11] >> 8) & 0xFF, b=(words[11] >> 16) & 0xFF,
                   u=cube._to_signed(words[15]),
                   v=cube._to_signed(words[16]), tex_en=(f >> 3) & 1),
        raster.Vtx(x=cube._to_signed(words[5]), y=cube._to_signed(words[6]),
                   z=words[9] & 0xFFFF, r=words[12] & 0xFF,
                   g=(words[12] >> 8) & 0xFF, b=(words[12] >> 16) & 0xFF,
                   u=cube._to_signed(words[17]),
                   v=cube._to_signed(words[18]), tex_en=(f >> 3) & 1),
    )
    return raster.RtrCmd(tri=tri, blend=(f >> 1) & 1, ztest=(f >> 2) & 1)


def checker_texture():
    """256x256 CLUT page: 16x16 checkerboard of gray shades (u -> col)."""
    page = bytearray(65536)
    for v in range(256):
        for u in range(256):
            page[(v << 8) | u] = ((u >> 4) + (v >> 4)) & 1 and 0xFF or 0x40
    return page


def ramp_texture():
    """256x256 CLUT page: diagonal gray ramp (matches tb_rtr's generator)."""
    return bytearray(min(255, ((t & 0xFF) + (t >> 8)) // 2)
                     for t in range(65536))


def textured_quad_cmds(page=0):
    """One perspective-friendly textured quad (two tris) in screen space
    through the identity MVP: tex coords sweep the full page across the
    quad (p-/q-ratio exercise via differing vertex depths)."""
    f2b = fpu.f2b
    # identity matrix
    mata = [f2b(1.0) if i % 5 == 0 else 0 for i in range(16)]
    v = []
    # (x, y, z, u, v) — screen-space x/y, z in [0..1], u/v full page
    # varying z per vertex => w varies => perspective split of the quad
    verts = [(60.0, 60.0, 0.25, 0.0, 0.0),
             (260.0, 60.0, 0.75, 255.0, 0.0),
             (260.0, 220.0, 0.75, 255.0, 255.0),
             (60.0, 220.0, 0.25, 0.0, 255.0)]
    order = (0, 1, 2), (0, 2, 3)
    cmds = []
    for tri in order:
        v = []
        for idx in tri:
            x, y, z, u, vv = verts[idx]
            v += [f2b(x), f2b(y), f2b(z), f2b(u), f2b(vv)]
        cfg = (1 << 27) | ((page & 0xFF) << 16)   # tex_en + texpage
        w = gsx_tex_cmd_words(mata, v, [0] * 3, cfg)
        if w is not None:
            cmds.append(w)
    return cmds


def textured_cube_face_cmds(face_idx, page=0):
    """Textured version of cube face `face_idx` (rotated MVP, page 0..8).
    Face-local UVs map the full texture page onto each face."""
    mata = cube.mvp_cube_words()
    idxs, _rgb = cube.CUBE_FACES[face_idx]
    # face-corner UVs (consistent winding with the face index list)
    uvtab = [(0.0, 0.0), (255.0, 0.0), (255.0, 255.0), (0.0, 255.0)]
    cmds = []
    for tri in (0, 1):
        # faces are two triangles of the 4 corner indices
        corners = (0, 1, 2) if tri == 0 else (0, 2, 3)
        v = []
        for k in corners:
            x, y, z = cube.CUBE_VERTS[idxs[k]]
            u, vv = uvtab[k]
            v += [fpu.f2b(float(x)), fpu.f2b(float(y)), fpu.f2b(float(z)),
                  fpu.f2b(u), fpu.f2b(vv)]
        cfg = (1 << 27) | ((page & 0xFF) << 16)
        w = gsx_tex_cmd_words(mata, v, [0x004080C0] * 3, cfg)
        if w is not None:
            cmds.append(w)
    return cmds
