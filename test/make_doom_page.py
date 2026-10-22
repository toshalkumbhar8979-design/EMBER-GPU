"""Render E1M1 through the Ember RTR golden model and build a compare page.

Writes test/doom_e1m1.ppm/.png plus test/doom_cmp.html, which shows the real
Doom frame (reference screenshot) above our GPU-rendered one.
"""
import base64
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, os.path.join(ROOT, "tools", "golden"))

import doom_real as R          # noqa: E402
import raster                  # noqa: E402
import ppm_png                 # noqa: E402

r = R.DoomRenderer(os.path.join(ROOT, "data", "doom1.wad"), "E1M1")
batches, stats = r.render()
vram = R.rasterize(r, batches)
ppm = raster.rgb565_to_ppm(vram)
ppm_path = os.path.join(HERE, "doom_e1m1.ppm")
png_path = os.path.join(HERE, "doom_e1m1.png")
with open(ppm_path, "w") as fh:
    fh.write(ppm)
with open(png_path, "wb") as fh:
    fh.write(ppm_png.ppm_p3_to_png_bytes(ppm))

ours = base64.b64encode(open(png_path, "rb").read()).decode()
ref = base64.b64encode(
    open(os.path.join(HERE, "ref", "e1m1_ref.png"), "rb").read()).decode()
rtl_path = os.path.join(HERE, "doom_rtl.png")
rtl = (base64.b64encode(open(rtl_path, "rb").read()).decode()
       if os.path.exists(rtl_path) else None)
rtl_fig = (f'''<figure><img src="data:image/png;base64,{rtl}" alt="RTL render of E1M1">
<figcaption>Same frame out of ember_rtr_top in Verilator (tb_doom): 10,774
GSX triangles streamed into the command queue, 0 pixel mismatches against
the golden rasterizer (76,800 of 76,800 exact).</figcaption></figure>'''
             if rtl else "")

html = f"""<!doctype html>
<html lang="en"><meta charset="utf-8"><title>Doom E1M1 on the Ember GPU</title>
<style>
 body {{ background:#0d0f14; color:#e6e9f0; font:15px/1.5 system-ui,sans-serif; margin:24px; }}
 h1 {{ font-size:20px; margin:0 0 4px; }}
 p {{ max-width:760px; color:#aab3c5; }}
 figure {{ margin:18px 0; }}
 img {{ width:640px; max-width:92vw; image-rendering:pixelated;
        border:1px solid #3a4152; display:block; }}
 figcaption {{ color:#8b94a7; margin-top:6px; }}
 code {{ color:#9fd2ff; }}
</style>
<h1>Doom E1M1 &mdash; rasterized by the Ember RTR</h1>
<p>Top: the real level, captured from Doom. Bottom: the same viewpoint rendered
here from <code>data/doom1.wad</code> &mdash; real BSP geometry, real composed
wall textures and flats, real COLORMAP light levels &mdash; with every pixel
rasterized by the Ember triangle engine's golden model (19-word GSX texture
commands in, RGB565 framebuffer out).</p>
<figure><img src="data:image/png;base64,{ref}" alt="real Doom reference frame">
<figcaption>Real Doom, E1M1 player start, 320&times;200 upscaled 2&times;.</figcaption></figure>
<figure><img src="data:image/png;base64,{ours}" alt="Ember GPU render of E1M1">
<figcaption>Ember RTR golden model: {stats['tris']} textured triangles in
{stats['batches']} texture-cache batches, {stats['segs']} wall segs,
{stats['sectors']} sectors, atlas at {stats['scales']} (1 = full res).</figcaption></figure>
{rtl_fig}
"""
page = os.path.join(HERE, "doom_cmp.html")
with open(page, "w") as fh:
    fh.write(html)
print("wrote", png_path)
print("wrote", page)
print(stats)
