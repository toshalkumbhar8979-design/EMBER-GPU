"""Placeholder die/block images (replaced by real GDS renders later)."""
import sys

sys.path.insert(0, "tools/fig")
import ppm2png  # noqa: E402


def make(path, w, h, label):
    buf = bytearray(w * h * 3)
    for y in range(h):
        for x in range(w):
            o = (y * w + x) * 3
            edge = 6 < x < w - 6 and 6 < y < h - 6
            if edge and (x // 24 + y // 24) % 2 == 0:
                buf[o : o + 3] = bytes((52, 58, 74))
            elif edge:
                buf[o : o + 3] = bytes((38, 42, 54))
            else:
                buf[o : o + 3] = bytes((18, 20, 28))
    ppm2png.write_png(path, w, h, bytes(buf))
    print("placeholder:", path, label)


make("paper/figures/die_shot.png", 640, 640, "die")
make("paper/figures/gds_block.png", 640, 480, "block")
