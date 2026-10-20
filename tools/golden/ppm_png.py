"""
tools/golden/ppm_png.py — PPM (P3) -> PNG converter, pure Python + zlib.

No PIL/numpy in the WSL env; PNG encoding is ~40 lines with zlib. Used to
eyeball rendered frames in a browser (PPM viewers are rare, PNG opens
anywhere) and as a CI artifact step.

CLI: python3 ppm_png.py frame.ppm [frame.png]
     (PNG path optional -> defaults to the PPM path with .png)
"""

import struct
import sys
import zlib


def _chunk(typ: bytes, data: bytes) -> bytes:
    return (struct.pack(">I", len(data)) + typ + data
            + struct.pack(">I", zlib.crc32(typ + data) & 0xFFFFFFFF))


def ppm_p3_to_png_bytes(ppm_text: str) -> bytes:
    """Convert P3 text (one 'r g b' pixel-triplet per screen pixel, any
    whitespace layout with the header on its own lines) to PNG bytes."""
    tokens = ppm_text.split()
    assert tokens[0] == "P3", f"not a P3 ppm: {tokens[0]!r}"
    w, h, maxv = int(tokens[1]), int(tokens[2]), int(tokens[3])
    vals = [int(t) for t in tokens[4:]]
    assert len(vals) == w * h * 3, f"{len(vals)} != {w}*{h}*3"
    assert maxv == 255, f"only maxval 255 supported, got {maxv}"
    raw = bytearray()
    for y in range(h):
        raw.append(0)                       # filter: none
        row = vals[(y * w) * 3:(y + 1) * w * 3]
        raw += bytes(row)
    ihdr = struct.pack(">IIBBBBB", w, h, 8, 2, 0, 0, 0)  # 8-bit RGB
    png = (b"\x89PNG\r\n\x1a\n" + _chunk(b"IHDR", ihdr)
           + _chunk(b"IDAT", zlib.compress(bytes(raw), 9)) + _chunk(b"IEND", b""))
    return png


def convert(ppm_path: str, png_path: str):
    with open(ppm_path, "r") as fh:
        txt = fh.read()
    with open(png_path, "wb") as fh:
        fh.write(ppm_p3_to_png_bytes(txt))
    print(f"{ppm_path} -> {png_path}")


if __name__ == "__main__":
    src = sys.argv[1] if len(sys.argv) > 1 else "test/scene_golden.ppm"
    dst = sys.argv[2] if len(sys.argv) > 2 else src.rsplit(".", 1)[0] + ".png"
    convert(src, dst)
