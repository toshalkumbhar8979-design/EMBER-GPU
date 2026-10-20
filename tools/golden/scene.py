"""
tools/golden/scene.py — Phase-7c "temple" scene builder (golden side).

The first real GAME-CLASS frame: multiple textured quads at different depths,
one MVP, one texture page, real per-pixel Z (LESS test) — the Phase-7
"games" showcase.

Design notes (v1 contracts):
  * The RTR ignores texpage (one 64 KB CLUT page) — variety comes from UV
    WINDOWS cut out of the single brick page (wall / floor / pillars).
  * Quads reuse cube.CUBE_FACES corner lists (winding pre-validated:
    inside-CCW, so nothing culls; the Z-BUFFER does the sorting — like a
    real scene, draw order is irrelevant).
  * scene MVP (mvp_scene_words): perspective + viewport folded into one
    matrix like mvp_cube_words, but with the screen offset applied BEFORE
    the divide (clip_x = 160*w + Sx*x) so the scene is CENTERED, and a
    depth row that makes z_ndc positive and monotone in distance
    (fp_to_z16 then yields real, distinct 16-bit depths — the cube demo's
    z_ndc went negative and degenerated every fragment to z=0; the scene
    fixes that).
  * Affine v1 texturing: interpolated u/v stay inside the corner UV window
    (an affine function is a convex combination on interior pixels) — no
    wrap/negative texel addresses.

scene_build() returns BOTH the 19-word golden commands AND the per-triangle
15-word fp32 vertex inputs — the SAME numbers feed tb_scene.py's RTL GSX
(single source of truth).
"""

import math

import fpu
import cube
import raster
import tex


# ------------------------------------------------------------------ MVP ----
def mvp_scene_words():
    """Scene camera: perspective + viewport folded in (GSX divides by w).

    screen_x = (Sx*x + 160*w) / w = 160 + Sx*x/w   (centered!)
    screen_y = 120 - Sy*y/w                         (y flip, centered)
    z_ndc    = (-0.5*z + 1) / w   — positive, DECREASING in z' =>
    increasing with distance (w = 3 - z), so fp_to_z16 gives a real
    monotone 16-bit depth. w = -z + 3 > 0 for the whole scene.
    """
    f = 1.14
    sx = 160.0 * f / (4.0 / 3.0)          # 136.8
    sy = 120.0 * f                        # 136.8
    M = [
        [sx,  0.0, -160.0, 480.0],
        [0.0, -sy, -120.0, 360.0],
        [0.0,  0.0,  -0.5,   1.0],
        [0.0,  0.0,  -1.0,   3.0],
    ]
    return cube.f32m(M)


CFG_SCENE = (1 << 27) | (1 << 24)         # tex_en + ztest

# Viewport-fold constant shared with tb_input: the fly camera's
# row0[3] = 480 - SX*cam_x (480 = 3*160 screen cols, SX = the 136.8
# screen-x scale; same expression as inside the mvp builders).
SX = 160.0 * 1.14 / (4.0 / 3.0)

# (CUBE_FACES quad pair index, scale xyz, translate xyz, uv window u0,v0,u1,v1)
SCENE_OBJECTS = [
    (0,  (2.3, 1.6, 1.0), (0.0,  0.05, -0.9), (0, 0, 255, 255)),      # back wall
    (6,  (2.3, 1.0, 2.0), (0.0, -0.6,   0.0), (0, 0, 127, 127)),      # floor
    (8,  (1.0, 1.0, 1.0), (-1.5, 0.0, -0.1), (128, 128, 255, 255)),   # left pillar
    (10, (1.0, 1.0, 1.0), (1.5,  0.0, -0.1), (128, 0, 255, 127)),     # right pillar
]


# --------------------------------------------------------------- texture ----
def brick_texture():
    """256x256 CLUT page: running-bond brick wall in gray tones."""
    page = bytearray(65536)
    for v in range(256):
        for u in range(256):
            course = v >> 5                    # 32-px courses
            off = (course & 1) << 4            # half-brick offset per course
            bu = (u + off) >> 6                # 64-px bricks
            mortar = ((v & 31) == 31) or (((u + off) & 63) == 63)
            if mortar:
                c = 70
            else:
                c = 150 + ((bu * 37 + course * 17) % 60)
            page[(v << 8) | u] = c & 0xFF
    return page


# ------------------------------------------------------------ geometry ------
def scene_build(mata, cfg=CFG_SCENE):
    """Golden GSX over every scene triangle.

    Returns (cmds, v15s): the 19-word golden commands AND the matching
    15-word fp32 vertex inputs (x,y,z,u,v x3) for the RTL testbench.
    """
    cmds = []
    v15s = []
    for face_pair, scale, trans, (u0, v0u, u1, v1u) in SCENE_OBJECTS:
        uvtab = [(u0, v0u), (u1, v0u), (u1, v1u), (u0, v1u)]
        for entry in (cube.CUBE_FACES[face_pair],
                      cube.CUBE_FACES[face_pair + 1]):
            idxs, _rgb = entry
            v = []
            for k, i in enumerate(idxs):
                x, y, z = cube.CUBE_VERTS[i]
                v += [fpu.f2b(x * scale[0] + trans[0]),
                      fpu.f2b(y * scale[1] + trans[1]),
                      fpu.f2b(z * scale[2] + trans[2]),
                      fpu.f2b(float(uvtab[k][0])),
                      fpu.f2b(float(uvtab[k][1]))]
            w = tex.gsx_tex_cmd_words(mata, v, [0] * 3, cfg)
            if w is None:
                continue
            cmds.append(w)
            v15s.append(v)
    return cmds, v15s


def scene_frame(vram, mata, cfg=CFG_SCENE, page=None):
    """Golden frame: load the CLUT page, clear FB+Z, rasterize all cmds.

    Returns tri count. (The texture MUST be in vram or every texel reads 0
    and the frame 'renders' as all-black — scene_selftest caught that.)
    """
    if page is None:
        page = brick_texture()
    for i in range(65536):
        vram.w8(raster.TEX_BASE + i, page[i])
    for i in range(raster.SCR_W * raster.SCR_H):
        vram.w16(raster.FB0_BASE + i * 2, 0)
        vram.w16(raster.ZBUF_BASE + i * 2, 0xFFFF)
    cmds, _ = scene_build(mata, cfg)
    for w in cmds:
        raster.rasterize_triangle(vram, tex.words_to_rtrcmd(w))
    return len(cmds)


# --------------------------------------------------------- animation (7e) ---
def mvp_spin_words(angle_z):
    """Scene MVP pre-multiplied by a world rotation about Z (the camera
    orbits the temple). Composed in float64 like mvp_cube_words, then
    quantized to fp32 words — the GSX path itself stays pure fp32."""
    f = 1.14
    sx = 160.0 * f / (4.0 / 3.0)
    sy = 120.0 * f
    Rz = cube.rot_z(angle_z)
    base = [
        [sx,  0.0, -160.0, 480.0],
        [0.0, -sy, -120.0, 360.0],
        [0.0,  0.0,  -0.5,   1.0],
        [0.0,  0.0,  -1.0,   3.0],
    ]
    M = cube.mat_mul(base, Rz)
    # keep row3 EXACTLY the camera row (rotation must not touch w):
    # rot_z's row3 is [0,0,0,1] so mat_mul preserves it, but re-assert to
    # document the invariant w = -z + 3.
    M[3] = [0.0, 0.0, -1.0, 3.0]
    return cube.f32m(M)


def spin_frame_set(nframes=4, base_deg=15.0):
    """nframes (mata, cmds, v15s) tuples at increasing orbit angles."""
    frames = []
    for i in range(nframes):
        mata = mvp_spin_words(math.radians(base_deg * i))
        cmds, v15s = scene_build(mata)
        frames.append((mata, cmds, v15s))
    return frames


# -------------------------------------------------------- fly-through (7g) ---
def mvp_fly_words(cam_x, cam_z):
    """Scene MVP with the CAMERA translated by (cam_x, 0, cam_z) — the
    player walks forward and sways sideways. Composed in float64 exactly
    like mvp_spin_words (translate pre-multiplied, then quantize).

    Translating the WORLD by (-cam_x, 0, -cam_z): w = -(z - cam_z) + 3
    = (3 + cam_z) - z. For cam_z in [0, 1] every scene vertex keeps
    w >= 3 - 1 = 2 > 0 (floor's far edge is the nearest geometry), so NO
    new culls; row2 is untouched so the depth order (farther = larger
    z16) is preserved. screen_x gains the parallax term -sx*cam_x/w
    through row0[3] = 480 - sx*cam_x (offset applied BEFORE the divide
    keeps the projection centered, same convention as mvp_scene_words).
    """
    f = 1.14
    sx = 160.0 * f / (4.0 / 3.0)
    sy = 120.0 * f
    M = [
        [sx,  0.0, -160.0, 480.0 - sx * cam_x],
        [0.0, -sy, -120.0, 360.0],
        [0.0,  0.0,  -0.5,   1.0],
        [0.0,  0.0,  -1.0,   3.0 + cam_z],
    ]
    return cube.f32m(M)


def fly_frame_set(nframes=4):
    """Walk-forward + sway path: cam_z advances 0.25/frame, cam_x sways
    0.3*sin(pi*t/4). Returns [(mata, cmds, v15s, (cam_x, cam_z))]."""
    frames = []
    for t in range(nframes):
        cam_z = 0.25 * t
        cam_x = 0.3 * math.sin(math.pi * t / 4.0)
        mata = mvp_fly_words(cam_x, cam_z)
        cmds, v15s = scene_build(mata)
        assert len(cmds) == 8, f"fly frame {t}: {8 - len(cmds)} tris culled"
        frames.append((mata, cmds, v15s, (cam_x, cam_z)))
    return frames
