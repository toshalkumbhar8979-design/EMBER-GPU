"""Publish the three Doom figures used in README's simulation grid.

Sources (all produced by the real flow, not mock-ups):
  test/ref/e1m1_ref.png   real Doom engine screenshot at the E1M1 player start
                          (320x200, stored here at 2x)
  test/doom_e1m1.png      Ember RTR golden model  (test/make_doom_page.py)
  test/doom_rtl.png       same frame out of ember_rtr_top in Verilator
                          (test/tb_doom.py)

Writes paper/figures/doom_{ref,golden,rtl}.png as 320x240 frames so the three
cells line up in the README table (the reference is letterboxed to 240 rows
because Doom renders 320x200).

Run with Pillow available (Windows python or the cocotb venv):
    python test/make_doom_figs.py
"""
import os
import sys

from PIL import Image, ImageChops

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
FIG = os.path.join(ROOT, "paper", "figures")

W, H = 320, 240


def save(im, name):
    path = os.path.join(FIG, name)
    im.save(path, optimize=True)
    print("wrote", os.path.relpath(path, ROOT), im.size)


def main():
    ref = Image.open(os.path.join(HERE, "ref", "e1m1_ref.png")).convert("RGB")
    golden = Image.open(os.path.join(HERE, "doom_e1m1.png")).convert("RGB")
    rtl = Image.open(os.path.join(HERE, "doom_rtl.png")).convert("RGB")

    # Doom's frame is 320x200: shrink the 2x reference and letterbox it.
    ref = ref.resize((W, 200), Image.NEAREST)
    framed = Image.new("RGB", (W, H), (0, 0, 0))
    framed.paste(ref, (0, 0))

    # The whole point of the demo: RTL == golden model, pixel for pixel.
    diff = ImageChops.difference(golden, rtl)
    npx = W * H - diff.convert("L").histogram()[0]
    if npx:
        raise SystemExit(f"{npx} pixels differ between RTL and golden — not publishing")

    save(framed, "doom_ref.png")
    save(golden, "doom_golden.png")
    save(rtl, "doom_rtl.png")
    print("bit-exact:", W * H, "of", W * H, "pixels")


if __name__ == "__main__":
    sys.exit(main())
