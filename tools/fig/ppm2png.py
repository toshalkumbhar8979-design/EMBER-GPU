"""
tools/fig/ppm2png.py — PPM (P6) -> PNG converter with ZERO dependencies.

We render every Ember demo frame as PPM from the RTL testbenches; LaTeX and
LinkedIn want PNG. This uses only zlib + struct (stdlib), so it runs anywhere
the project runs (WSL python 3.13, no PIL, no numpy).

Usage:
    python3 tools/fig/ppm2png.py in.ppm out.png
    python3 tools/fig/ppm2png.py --scale 2 in.ppm out.png   (nearest-neighbor upsample)
"""
import struct
import sys
import zlib


def read_ppm(path):
    with open(path, "rb") as f:
        data = f.read()
    # P3 (ASCII) -> convert to P6 semantics first
    if data.startswith(b"P3"):
        toks = data.split()
        w, h, maxval = int(toks[1]), int(toks[2]), int(toks[3])
        vals = toks[4:]
        raw = bytearray(w * h * 3)
        for i in range(w * h * 3):
            raw[i] = int(vals[i])
        return w, h, bytes(raw)
    # P6 header: magic, whitespace/comments, width, height, maxval, single ws, raw RGB
    if not data.startswith(b"P6"):
        raise ValueError(f"{path}: not a P3/P6 PPM")
    idx = 2
    fields = []
    while len(fields) < 3:
        while idx < len(data) and data[idx : idx + 1].isspace():
            idx += 1
        if data[idx : idx + 1] == b"#":
            while idx < len(data) and data[idx] != 0x0A:
                idx += 1
            continue
        start = idx
        while idx < len(data) and not data[idx : idx + 1].isspace():
            idx += 1
        fields.append(int(data[start:idx]))
    idx += 1  # single whitespace after maxval
    w, h, maxval = fields
    raw = data[idx : idx + w * h * 3]
    if len(raw) < w * h * 3:
        raise ValueError(f"{path}: truncated pixel data")
    return w, h, raw


def write_png(path, w, h, rgb):
    def chunk(tag, payload):
        c = struct.pack(">I", len(payload)) + tag + payload
        return c + struct.pack(">I", zlib.crc32(tag + payload) & 0xFFFFFFFF)

    ihdr = struct.pack(">IIBBBBB", w, h, 8, 2, 0, 0, 0)  # 8-bit RGB
    # filter 0 per scanline
    stride = w * 3
    rows = bytearray()
    for y in range(h):
        rows.append(0)
        rows += rgb[y * stride : (y + 1) * stride]
    idat = zlib.compress(bytes(rows), 9)
    png = (
        b"\x89PNG\r\n\x1a\n"
        + chunk(b"IHDR", ihdr)
        + chunk(b"IDAT", idat)
        + chunk(b"IEND", b"")
    )
    with open(path, "wb") as f:
        f.write(png)


def scale_rgb(raw, w, h, k):
    if k == 1:
        return raw, w, h
    ow, oh = w * k, h * k
    out = bytearray(ow * oh * 3)
    for y in range(oh):
        sy = y // k
        srow = sy * w * 3
        orow = y * ow * 3
        for x in range(ow):
            sx = x // k
            si = srow + sx * 3
            di = orow + x * 3
            out[di] = raw[si]
            out[di + 1] = raw[si + 1]
            out[di + 2] = raw[si + 2]
    return bytes(out), ow, oh


def main(argv):
    scale = 1
    args = []
    i = 0
    while i < len(argv):
        if argv[i] == "--scale":
            scale = int(argv[i + 1])
            i += 2
        else:
            args.append(argv[i])
            i += 1
    if len(args) != 2:
        print(__doc__)
        return 1
    src, dst = args
    w, h, rgb = read_ppm(src)
    rgb, w, h = scale_rgb(rgb, w, h, scale)
    write_png(dst, w, h, rgb)
    print(f"{dst}: {w}x{h}")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
