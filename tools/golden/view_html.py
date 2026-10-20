"""
tools/golden/view_html.py — wrap a PNG in a minimal HTML viewer page.

Generated demo artifacts (like the PPM frames) are hard to eyeball on
Windows; this embeds the PNG as a base64 data URI so the Preview tab can
display it. Pure stdlib.

CLI: python3 view_html.py frame.png [page.html]
"""

import base64
import sys


def make_html(png_path: str, title: str) -> str:
    with open(png_path, "rb") as fh:
        b64 = base64.b64encode(fh.read()).decode("ascii")
    return f"""<!DOCTYPE html>
<html><head><meta charset="utf-8"><title>{title}</title>
<style>
  body {{ margin:0; background:#181818; color:#ddd; font-family:monospace;
         display:flex; flex-direction:column; align-items:center; }}
  h1 {{ font-size:14px; margin:12px; }}
  img {{ image-rendering:pixelated; width:640px; max-width:96vw;
        border:1px solid #444; margin-bottom:12px; }}
</style></head>
<body>
<h1>{title}</h1>
<img src="data:image/png;base64,{b64}" alt="{title}">
</body></html>
"""


if __name__ == "__main__":
    png = sys.argv[1] if len(sys.argv) > 1 else "test/scene_golden.png"
    out = sys.argv[2] if len(sys.argv) > 2 else png.rsplit(".", 1)[0] + ".html"
    with open(out, "w") as fh:
        fh.write(make_html(png, png))
    print(f"{png} -> {out}")
