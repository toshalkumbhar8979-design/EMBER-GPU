"""
tools/golden/anim_html.py — stitch animation PPM frames into one HTML page.

Reads anim_rtl_f<i>.ppm (or scene_rtl.ppm style), converts each to PNG
bytes via ppm_png, and writes a contact-sheet HTML (frames side by side)
for the Preview tab. Pure stdlib.

CLI: python3 anim_html.py out.html f0.ppm f1.ppm [f2.ppm f3.ppm ...]
"""

import base64
import sys

import ppm_png


def ppm_to_png_b64(ppm_path):
    with open(ppm_path, "r") as fh:
        return base64.b64encode(
            ppm_png.ppm_p3_to_png_bytes(fh.read())).decode("ascii")


if __name__ == "__main__":
    out = sys.argv[1]
    frames = sys.argv[2:]
    assert frames, "need at least one ppm frame"
    imgs = []
    for f in frames:
        b64 = ppm_to_png_b64(f)
        imgs.append(f'<figure><img src="data:image/png;base64,{b64}">'
                    f'<figcaption>{f}</figcaption></figure>')
    html = f"""<!DOCTYPE html>
<html><head><meta charset="utf-8"><title>Ember animation</title>
<style>
  body {{ margin:0; background:#181818; color:#ddd; font-family:monospace;
         display:flex; flex-wrap:wrap; gap:12px; padding:12px; }}
  figure {{ margin:0; text-align:center; }}
  img {{ image-rendering:pixelated; width:320px; border:1px solid #444; }}
  figcaption {{ font-size:11px; margin-top:4px; }}
  h1 {{ width:100%; font-size:14px; margin:4px 0 12px; }}
</style></head>
<body>
<h1>Ember GPU — orbiting temple, {len(frames)} frames (RTL bit-exact vs golden)</h1>
{''.join(imgs)}
</body></html>
"""
    with open(out, "w") as fh:
        fh.write(html)
    print(f"{len(frames)} frames -> {out}")
