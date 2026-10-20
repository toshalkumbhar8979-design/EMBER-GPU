"""
Standalone smoke test for the golden rasterizer (no RTL involved).
Run: python3 tools/golden/test_raster_golden.py
"""
import sys, os
sys.path.insert(0, os.path.dirname(__file__))
from raster import (Vram, Vtx, Tri, RtrCmd, rasterize_triangle,
                    rgb565_to_ppm, FB0_BASE, TEX_BASE, ZBUF_BASE, Q)

vram = Vram()

# ---------------- Test 1: red/green/blue corner gradient triangle ----------
v0 = Vtx(x=(20 << Q), y=(20 << Q), z=1000, r=255, g=0, b=0)
v1 = Vtx(x=(300 << Q), y=(40 << Q), z=1000, r=0, g=255, b=0)
v2 = Vtx(x=(100 << Q), y=(220 << Q), z=1000, r=0, g=0, b=255)
cmd = RtrCmd(tri=Tri(v0, v1, v2), blend=0, ztest=0)
rasterize_triangle(vram, cmd)

# sample inside the triangle — should be a blend of the three vertex colors
p_mid = vram.r16(FB0_BASE + (100 * 320 + 100) * 2)
print(f"mid pixel: {p_mid:#06x}")

# area outside triangle must be untouched
p_out = vram.r16(FB0_BASE + (230 * 320 + 310) * 2)
assert p_out == 0, f"pixel outside triangle should be 0, got {p_out:#x}"

# ---------------- Test 2: textured quad via two triangles ------------------
# TEX layout: 256 pages x 256 entries; write a (u+v)/2 ramp so every lookup
# is defined and brightness grows toward the bottom-right corner.
for p in range(256):
    for u in range(256):
        vram.w8(TEX_BASE + (p << 8) + u, min(255, (u + p) // 2))

vt0 = Vtx(x=(40 << Q), y=(140 << Q), z=500, r=0, g=0, b=0,
          u=0, v=0, tex_en=1)
vt1 = Vtx(x=(120 << Q), y=(140 << Q), z=500, r=0, g=0, b=0,
          u=(255 << Q), v=0, tex_en=1)
vt2 = Vtx(x=(120 << Q), y=(220 << Q), z=500, r=0, g=0, b=0,
          u=(255 << Q), v=(255 << Q), tex_en=1)
vt3 = Vtx(x=(40 << Q), y=(220 << Q), z=500, r=0, g=0, b=0,
          u=0, v=(255 << Q), tex_en=1)
cmd_t1 = RtrCmd(tri=Tri(vt0, vt1, vt2, texture=0), ztest=0)
cmd_t2 = RtrCmd(tri=Tri(vt0, vt2, vt3, texture=0), ztest=0)
rasterize_triangle(vram, cmd_t1)
rasterize_triangle(vram, cmd_t2)

# top-left of textured quad should be dark (u,v near 0), bottom-right bright
# (quad spans x 40-120, y 140-220; sample solid interior points)
p_tl = vram.r16(FB0_BASE + (150 * 320 + 50) * 2)
p_br = vram.r16(FB0_BASE + (200 * 320 + 105) * 2)
print(f"tex TL: {p_tl:#06x}  tex BR: {p_br:#06x}")
assert p_tl == 0x0000, f"TL must be CLUT[~0] black (got {p_tl:#06x})"
assert p_br > 0x8410, f"BR must be bright CLUT[200+] gray-blue (got {p_br:#06x})"

# ---------------- Test 3: Z-test (two overlapping triangles) ---------------
# Software convention: clear Z to 0xFFFF (farthest) before the frame, so the
# LESS-THAN test passes for everything. (Matches RTL bring-up requirement.)
for i in range(320 * 240):
    vram.w16(ZBUF_BASE + i * 2, 0xFFFF)

vz0 = Vtx(x=(150 << Q), y=(20 << Q), z=100, r=255, g=255, b=0)
vz1 = Vtx(x=(310 << Q), y=(20 << Q), z=100, r=255, g=255, b=0)
vz2 = Vtx(x=(230 << Q), y=(200 << Q), z=100, r=255, g=255, b=0)
# far triangle first (z=200), then near triangle (z=100) → near must win
cmdz_far = RtrCmd(tri=Tri(
    Vtx(x=(150 << Q), y=(20 << Q), z=200, r=255, g=0, b=255),
    Vtx(x=(310 << Q), y=(20 << Q), z=200, r=255, g=0, b=255),
    Vtx(x=(230 << Q), y=(200 << Q), z=200, r=255, g=0, b=255)), ztest=1)
cmdz_near = RtrCmd(tri=Tri(vz0, vz1, vz2), ztest=1)
rasterize_triangle(vram, cmdz_far)
rasterize_triangle(vram, cmdz_near)
p_z = vram.r16(FB0_BASE + (100 * 320 + 230) * 2)
print(f"z-fight pixel: {p_z:#06x} (expect yellow 0xFFE0)")
assert p_z == 0xFFE0, f"near triangle must win the z-test, got {p_z:#06x}"

with open(os.path.join(os.path.dirname(__file__), "golden_smoke.ppm"), "w") as f:
    f.write(rgb565_to_ppm(vram))
print("OK — wrote golden_smoke.ppm")
