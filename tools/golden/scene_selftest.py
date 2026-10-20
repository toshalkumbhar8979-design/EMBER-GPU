"""Sanity-check tools/golden/scene.py without any HDL: build + render + stats."""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import raster
import scene

mata = scene.mvp_scene_words()
cmds, v15s = scene.scene_build(mata)
print(f"tris surviving cull: {len(cmds)} (want 8)")
assert len(cmds) == 8

g = raster.Vram()
n = scene.scene_frame(g, mata)
print(f"rasterized {n} tris")

# coverage stats
drawn = sum(1 for i in range(raster.SCR_W * raster.SCR_H)
            if g.r16(raster.FB0_BASE + i * 2) != 0)
print(f"nonzero pixels: {drawn} ({100.0 * drawn / (320 * 240):.1f}%)")
assert drawn > 20000, "scene barely covers the screen — geometry wrong?"

# depth sanity: z must vary across the frame (real Z-buffering)
zs = set()
for i in range(0, raster.SCR_W * raster.SCR_H, 7):
    zs.add(g.r16(raster.ZBUF_BASE + i * 2))
print(f"distinct Z values: {len(zs)}")
assert len(zs) > 4, "z degenerate — depth row wrong?"

with open("test/scene_golden.ppm", "w") as fh:
    fh.write(raster.rgb565_to_ppm(g))
print("scene_golden.ppm written")
print("SCENE SELFTEST PASS")
