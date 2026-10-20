"""
tools/fig/arch_diagram.py — the Ember GPU architecture diagram as a PNG.

Zero dependencies: draws boxes/lines/5x7-font text into an RGB buffer and
writes PNG via ppm2png. The layout mirrors the real chip:
  host (NEORV32) -> AXI-Lite fabric (xbar) -> CP | VRAM
  CP drives GSX (geometry) / RTR (raster) / BLIT / CORE (compute) / TU (tensor)
  VRAM feeds RTR/BLIT/DISPLAY over dedicated pixel ports; DISPLAY -> HDMI.

Usage: python3 tools/fig/arch_diagram.py [out.png]
"""
import sys

sys.path.insert(0, "tools/fig")
import ppm2png  # noqa: E402

# 5x7 font for a subset of characters we need (upper + digits + some punct)
FONT = {
    "A": ["01110", "10001", "10001", "11111", "10001", "10001", "10001"],
    "B": ["11110", "10001", "10001", "11110", "10001", "10001", "11110"],
    "C": ["01110", "10001", "10000", "10000", "10000", "10001", "01110"],
    "D": ["11110", "10001", "10001", "10001", "10001", "10001", "11110"],
    "E": ["11111", "10000", "10000", "11110", "10000", "10000", "11111"],
    "F": ["11111", "10000", "10000", "11110", "10000", "10000", "10000"],
    "G": ["01110", "10001", "10000", "10111", "10001", "10001", "01111"],
    "H": ["10001", "10001", "10001", "11111", "10001", "10001", "10001"],
    "I": ["01110", "00100", "00100", "00100", "00100", "00100", "01110"],
    "K": ["10001", "10010", "10100", "11000", "10100", "10010", "10001"],
    "L": ["10000", "10000", "10000", "10000", "10000", "10000", "11111"],
    "M": ["10001", "11011", "10101", "10101", "10001", "10001", "10001"],
    "N": ["10001", "11001", "10101", "10011", "10001", "10001", "10001"],
    "O": ["01110", "10001", "10001", "10001", "10001", "10001", "01110"],
    "P": ["11110", "10001", "10001", "11110", "10000", "10000", "10000"],
    "Q": ["01110", "10001", "10001", "10001", "10101", "10010", "01101"],
    "R": ["11110", "10001", "10001", "11110", "10100", "10010", "10001"],
    "S": ["01111", "10000", "10000", "01110", "00001", "00001", "11110"],
    "T": ["11111", "00100", "00100", "00100", "00100", "00100", "00100"],
    "U": ["10001", "10001", "10001", "10001", "10001", "10001", "01110"],
    "V": ["10001", "10001", "10001", "10001", "10001", "01010", "00100"],
    "W": ["10001", "10001", "10001", "10101", "10101", "11011", "10001"],
    "X": ["10001", "10001", "01010", "00100", "01010", "10001", "10001"],
    "Y": ["10001", "10001", "01010", "00100", "00100", "00100", "00100"],
    "Z": ["11111", "00001", "00010", "00100", "01000", "10000", "11111"],
    "0": ["01110", "10001", "10011", "10101", "11001", "10001", "01110"],
    "1": ["00100", "01100", "00100", "00100", "00100", "00100", "01110"],
    "2": ["01110", "10001", "00001", "00010", "00100", "01000", "11111"],
    "3": ["11111", "00010", "00100", "00010", "00001", "10001", "01110"],
    "4": ["00010", "00110", "01010", "10010", "11111", "00010", "00010"],
    "5": ["11111", "10000", "11110", "00001", "00001", "10001", "01110"],
    "6": ["00110", "01000", "10000", "11110", "10001", "10001", "01110"],
    "7": ["11111", "00001", "00010", "00100", "01000", "01000", "01000"],
    "8": ["01110", "10001", "10001", "01110", "10001", "10001", "01110"],
    "9": ["01110", "10001", "10001", "01111", "00001", "00010", "01100"],
    " ": ["00000", "00000", "00000", "00000", "00000", "00000", "00000"],
    "-": ["00000", "00000", "00000", "11111", "00000", "00000", "00000"],
    "=": ["00000", "00000", "11111", "00000", "11111", "00000", "00000"],
    ">": ["01000", "00100", "00010", "00001", "00010", "00100", "01000"],
    "<": ["00010", "00100", "01000", "10000", "01000", "00100", "00010"],
    "/": ["00001", "00010", "00010", "00100", "01000", "01000", "10000"],
    "(": ["00010", "00100", "01000", "01000", "01000", "00100", "00010"],
    ")": ["01000", "00100", "00010", "00010", "00010", "00100", "01000"],
    ".": ["00000", "00000", "00000", "00000", "00000", "01100", "01100"],
    ",": ["00000", "00000", "00000", "00000", "01100", "00100", "01000"],
    ":": ["00000", "01100", "01100", "00000", "01100", "01100", "00000"],
    "+": ["00000", "00100", "00100", "11111", "00100", "00100", "00000"],
    "x": ["00000", "10001", "01010", "00100", "01010", "10001", "00000"],
    "8x": None,
}


class Canvas:
    def __init__(self, w, h, bg):
        self.w = w
        self.h = h
        self.buf = bytearray(w * h * 3)
        for o in range(0, len(self.buf), 3):
            self.buf[o : o + 3] = bytes(bg)

    def rect(self, x, y, w, h, color, filled=True):
        for yy in range(y, y + h):
            for xx in range(x, x + w):
                if 0 <= xx < self.w and 0 <= yy < self.h:
                    o = (yy * self.w + xx) * 3
                    if filled or yy in (y, y + h - 1) or xx in (x, x + w - 1):
                        self.buf[o : o + 3] = bytes(color)

    def text(self, x, y, s, scale=2, color=(240, 240, 240)):
        cx = x
        for ch in s.upper() if s.upper() in ("",) else s:
            glyph = FONT.get(ch) or (FONT[ch.upper()] if ch.upper() in FONT else FONT[" "])
            for gy, row in enumerate(glyph):
                for gx, c in enumerate(row):
                    if c == "1":
                        self.rect(cx + gx * scale, y + gy * scale, scale, scale, color)
            cx += 6 * scale

    def line(self, x0, y0, x1, y1, color, dash=0):
        dx = abs(x1 - x0)
        dy = abs(y1 - y0)
        sx = 1 if x0 < x1 else -1
        sy = 1 if y0 < y1 else -1
        err = dx - dy
        n = 0
        while True:
            if dash == 0 or (n // dash) % 2 == 0:
                for off in range(-1, 2):
                    xx, yy = x0, y0
                    if dy >= dx:
                        xx += off
                    else:
                        yy += off
                    if 0 <= xx < self.w and 0 <= yy < self.h:
                        o = (yy * self.w + xx) * 3
                        self.buf[o : o + 3] = bytes(color)
            if x0 == x1 and y0 == y1:
                break
            e2 = 2 * err
            if e2 > -dy:
                err -= dy
                x0 += sx
            if e2 < dx:
                err += dx
                y0 += sy
            n += 1

    def arrow(self, x0, y0, x1, y1, color, dash=0):
        self.line(x0, y0, x1, y1, color, dash)
        # arrowhead at (x1,y1)
        import math

        ang = math.atan2(y1 - y0, x1 - x0)
        for k in (0.4,):
            for t in (-0.5, 0.5):
                ex = int(x1 - 10 * k * math.cos(ang + t))
                ey = int(y1 - 10 * k * math.sin(ang + t))
                self.line(x1, y1, ex, ey, color)

    def write(self, path):
        ppm2png.write_png(path, self.w, self.h, bytes(self.buf))


def main(argv):
    out = argv[0] if argv else "paper/figures/architecture.png"
    SC = 2
    W, H = 1400 * SC, 900 * SC
    c = Canvas(W, H, (18, 20, 28))

    INK = (235, 235, 235)
    HOST = (70, 130, 180)
    FAB = (120, 120, 140)
    MEM = (170, 120, 60)
    GFX = (60, 160, 90)
    AIC = (150, 80, 170)
    DSP = (200, 140, 40)

    def box(x, y, w, h, title, sub=None, color=GFX, tscale=3 * SC, sscale=2 * SC):
        c.rect(x, y, w, h, (36, 40, 52))
        c.rect(x, y, w, h, color, filled=False)
        c.rect(x, y, w, 6, color)  # top accent
        tw = len(title) * 6 * tscale
        c.text(x + (w - tw) // 2, y + h // 2 - (7 * tscale if sub else 7 * tscale // 2), title, tscale, (250, 250, 250))
        if sub:
            sw = len(sub) * 6 * sscale
            c.text(x + (w - sw) // 2, y + h // 2 + 7 * tscale // 2 + 2 * SC, sub, sscale, (200, 205, 215))

    ts = 3 * SC
    c.text(W // 2 - len("EMBER GPU - FULL-CHIP ARCHITECTURE (V1 SILICON-VERIFIED)") * 6 * ts // 2, 24 * SC,
           "EMBER GPU - FULL-CHIP ARCHITECTURE (V1 SILICON-VERIFIED)", ts, (255, 255, 255))

    # Host
    box(30 * SC, 120 * SC, 200 * SC, 110 * SC, "NEORV32", "RISC-V HOST (FPGA)", HOST)
    # Fabric
    box(300 * SC, 120 * SC, 200 * SC, 110 * SC, "AXI-LITE XBAR", "ARBITER + DECODE", FAB)
    # CP
    box(570 * SC, 60 * SC, 220 * SC, 100 * SC, "CP", "CMD PROC / DMA / FENCE", FAB)
    # VRAM
    box(570 * SC, 210 * SC, 220 * SC, 110 * SC, "VRAM 512KB", "FB / Z / TEX / CMDQ / CODE", MEM)

    # Graphics row
    box(860 * SC, 40 * SC, 180 * SC, 90 * SC, "GSX", "4-LANE FP32 MVP", GFX)
    box(860 * SC, 160 * SC, 180 * SC, 90 * SC, "RTR", "1 PIX/CLK RASTER", GFX)
    box(860 * SC, 280 * SC, 180 * SC, 90 * SC, "BLIT", "SPRITE / HUD", GFX)
    # AI row
    box(1080 * SC, 100 * SC, 180 * SC, 100 * SC, "TU 16x16", "INT8 TPU 25.6 GOPS", AIC)
    box(1080 * SC, 240 * SC, 180 * SC, 100 * SC, "CORE x1", "4-THREAD SPMD", AIC)
    # Display
    box(300 * SC, 320 * SC, 200 * SC, 100 * SC, "DISPLAY", "640x480@60 / VGA", DSP)

    # arrows host->xbar->cp, xbar->vram
    c.arrow(230 * SC, 175 * SC, 300 * SC, 175 * SC, INK)
    c.arrow(500 * SC, 150 * SC, 570 * SC, 105 * SC, INK)
    c.arrow(500 * SC, 200 * SC, 570 * SC, 255 * SC, INK)
    # CP <-> VRAM (DMA)
    c.arrow(680 * SC, 160 * SC, 680 * SC, 210 * SC, INK, dash=4 * SC)
    # CP kicks to engines
    c.arrow(790 * SC, 85 * SC, 860 * SC, 85 * SC, INK)
    c.arrow(790 * SC, 205 * SC, 860 * SC, 205 * SC, INK)
    c.arrow(790 * SC, 325 * SC, 860 * SC, 325 * SC, INK)
    c.arrow(790 * SC, 150 * SC, 1080 * SC, 150 * SC, INK)
    c.arrow(790 * SC, 290 * SC, 1080 * SC, 290 * SC, INK)
    # VRAM pixel ports to RTR/BLIT/DISPLAY
    c.line(680 * SC, 320 * SC, 680 * SC, 400 * SC, INK)
    c.line(680 * SC, 400 * SC, 1050 * SC, 400 * SC, INK)
    c.arrow(680 * SC, 400 * SC, 860 * SC, 250 * SC, INK, dash=3 * SC)
    c.arrow(680 * SC, 400 * SC, 500 * SC, 370 * SC, INK, dash=3 * SC)
    # GSX -> RTR (cmdq via VRAM)
    c.arrow(950 * SC, 130 * SC, 950 * SC, 160 * SC, INK, dash=3 * SC)
    # TU <-> CORE (tensor pipelines through VRAM too)
    c.arrow(1170 * SC, 200 * SC, 1170 * SC, 240 * SC, INK, dash=3 * SC)
    # legend
    c.text(30 * SC, 480 * SC, "SOLID: REGISTER/COMMAND PATH   DASHED: VRAM DATA PATH", 2 * SC, (160, 165, 175))
    c.text(30 * SC, 496 * SC, "ALL ENGINES BIT-EXACT VS PYTHON GOLDEN MODELS - 31/31 COCOTB SUITE", 2 * SC, (160, 165, 175))

    c.write(out)
    print(f"wrote {out} ({W}x{H})")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
