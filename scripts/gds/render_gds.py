# render_gds.py — rasterize a GDS-II layout into a PPM "die shot".
#
# Runs INSIDE the openlane2 container:
#   KLAYOUT_GDS=/path/x.gds KLAYOUT_PPM=/work/paper/figures/x.ppm \
#     klayout -b -r /work/scripts/gds/render_gds.py
#
# KLayout's pya does the GDS parsing (including hierarchy); we flatten the top
# cell and rasterize the metal/diff layers ourselves. No GUI, no display.
import os
import sys

import pya

GDS = os.environ["KLAYOUT_GDS"]
OUT = os.environ["KLAYOUT_PPM"]
MAXPX = int(os.environ.get("KLAYOUT_MAXPX", "1400"))

# sky130 layer/datatype -> colour. Ordered: lower layers drawn first.
LAYER_COLORS = {
    (64, 20): (34, 38, 48),     # nwell / substrate base
    (65, 20): (120, 110, 60),   # diff
    (65, 44): (140, 128, 70),   # tap
    (66, 20): (150, 70, 70),    # poly
    (67, 20): (86, 150, 150),   # li1
    (67, 44): (96, 165, 165),   # mcon
    (68, 20): (90, 130, 210),   # met1
    (68, 44): (110, 150, 225),  # via
    (69, 20): (120, 190, 120),  # met2
    (69, 44): (140, 205, 140),  # via2
    (70, 20): (220, 180, 90),   # met3
    (71, 20): (220, 120, 170),  # met4
    (72, 20): (180, 140, 230),  # met5
}
CELL_BORDER = (255, 255, 255)


def main():
    layout = pya.Layout()
    layout.read(GDS)
    top_name = os.environ.get("KLAYOUT_TOP", "")
    top = layout.cell(top_name) if top_name else layout.top_cell()
    if top is None:
        print("no top cell")
        return 1
    # flatten so every polygon is in one cell (geometry only, skip properties)
    top.flatten(True)

    bbox = top.bbox()
    if bbox.width() == 0 or bbox.height() == 0:
        print("empty layout")
        return 1

    dbu = layout.dbu
    w_um = bbox.width() * dbu
    h_um = bbox.height() * dbu
    scale = MAXPX / max(w_um, h_um)
    W = max(64, int(w_um * scale))
    H = max(64, int(h_um * scale))
    print(f"layout {w_um:.1f} x {h_um:.1f} um -> {W} x {H} px")

    buf = bytearray(W * H * 3)
    for i in range(0, len(buf), 3):
        buf[i : i + 3] = bytes((12, 14, 20))

    x0, y0 = bbox.left, bbox.bottom

    def poly_color_mask(layer, datatype):
        return LAYER_COLORS.get((layer, datatype)) or LAYER_COLORS.get((layer, 20))

    drawn = 0
    for li in layout.layer_indices():
        info = layout.get_info(li)
        col = poly_color_mask(info.layer, info.datatype)
        if col is None:
            continue
        it = top.begin_shapes_rec(li)
        while not it.at_end():
            sh = it.shape()
            poly = None
            if sh.is_path():
                if sh.path is not None:
                    poly = sh.path.polygon()
            elif sh.is_polygon() or sh.is_box():
                poly = sh.polygon      # pya converts Box -> Polygon here
            if poly is None or poly.is_empty():
                it.next()
                continue
            if True:
                # rasterize with an even-odd scanline fill
                pts = [(p.x, p.y) for p in poly.each_point_hull()]
                xs = [int((px - x0) * dbu * scale) for px, _ in pts]
                ys = [H - 1 - int((py - y0) * dbu * scale) for _, py in pts]
                ymin, ymax = max(0, min(ys)), min(H - 1, max(ys))
                n = len(pts)
                for py in range(ymin, ymax + 1):
                    yc = py + 0.5
                    cross = []
                    for k in range(n):
                        ax = (xs[k]) 
                        ay = (ys[k])
                        bx = (xs[(k + 1) % n])
                        by = (ys[(k + 1) % n])
                        if (ay <= yc < by) or (by <= yc < ay):
                            t = (yc - ay) / (by - ay)
                            cross.append(ax + t * (bx - ax))
                    if not cross:
                        continue
                    cross.sort()
                    for k in range(0, len(cross) - 1, 2):
                        xa = max(0, int(cross[k] + 0.5))
                        xb = min(W - 1, int(cross[k + 1] - 0.5))
                        if xb < xa:
                            continue
                        row = (py * W + xa) * 3
                        for _ in range(xb - xa + 1):
                            buf[row : row + 3] = bytes(col)
                            row += 3
                drawn += 1
            it.next()

    print(f"drew {drawn} polygons")

    # submit bounding frame
    for x in range(W):
        for y in (0, H - 1):
            o = (y * W + x) * 3
            buf[o : o + 3] = bytes(CELL_BORDER)
    for y in range(H):
        for x in (0, W - 1):
            o = (y * W + x) * 3
            buf[o : o + 3] = bytes(CELL_BORDER)

    if OUT.lower().endswith(".png"):
        import struct
        import zlib
        def chunk(kind, data):
            return (struct.pack(">I", len(data)) + kind + data
                    + struct.pack(">I", zlib.crc32(kind + data) & 0xffffffff))
        rows = b"".join(b"\x00" + bytes(buf[y*W*3:(y+1)*W*3]) for y in range(H))
        with open(OUT, "wb") as f:
            f.write(b"\x89PNG\r\n\x1a\n")
            f.write(chunk(b"IHDR", struct.pack(">IIBBBBB", W, H, 8, 2, 0, 0, 0)))
            f.write(chunk(b"IDAT", zlib.compress(rows)))
            f.write(chunk(b"IEND", b""))
    else:
        with open(OUT, "wb") as f:
            f.write(b"P6\n%d %d\n255\n" % (W, H))
            f.write(bytes(buf))
    print("wrote", OUT)
    return 0


sys.exit(main())
