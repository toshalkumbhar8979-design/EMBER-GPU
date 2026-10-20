"""
Golden rasterizer for the Ember GPU — integer-exact reference model.

Purpose: independent Python implementation of the Phase-2 RTR behavior that the
RTL is verified against. THE RTL MUST MATCH THIS BIT-FOR-BIT (all integer math).

Pipeline contract (matches ember_rtr.sv):
  * Q10.22 fixed point (fits s32 command words, ±2048 px range): coords/u/v
    arrive as (value << 22). inv_w is (1/w) << 22.
  * Plane eval:  val = ((A * x + B * y) >> 22) + C, all Q10.22.
  * Edge rule:   CCW front faces; pixel inside iff E01>0 AND E12>0 AND E20>0,
                 evaluated at pixel centers (N + 0.5). Centers exactly on an
                 edge are OUT (strict >). RTL uses identical strict compare.
  * Depth:       16-bit Z, LESS-THAN passes (smaller = closer). The Z plane
                 interpolates RAW 16-bit depth (no Q4.28 scaling).
  * Framebuffer: RGB565, byte-packed (pixel i at bytes 2i..2i+1). VRAM map:
      FB0 @ 0x000000 (153600 B), Z @ 0x025800, TEX @ 0x04B000
      (64 KB: 256 CLUT pages x 256 entries; v=página, u=entry),
      CMDBUF @ 0x05B000, scratch to 0x080000.
      v1 uses a single framebuffer (FB1 reappears with bigger VRAM in v2).
"""

from dataclasses import dataclass
from typing import Tuple

# ---------------------------------------------------------------- VRAM map --
FB_STRIDE = 320 * 2
FB0_BASE = 0x000000
ZBUF_BASE = FB0_BASE + FB_STRIDE * 240         # 0x025800
TEX_BASE = ZBUF_BASE + FB_STRIDE * 240         # 0x04B000
CMDBUF_BASE = TEX_BASE + 64 * 1024             # 0x05B000
VRAM_BYTES = 512 * 1024

Q = 22
SCR_W = 320
SCR_H = 240


class Vram:
    """512 KB flat byte-addressable memory."""

    def __init__(self):
        self.mem = bytearray(VRAM_BYTES)

    def w8(self, addr: int, val: int):
        self.mem[addr & (VRAM_BYTES - 1)] = val & 0xFF

    def r8(self, addr: int) -> int:
        return self.mem[addr & (VRAM_BYTES - 1)]

    def w16(self, addr: int, val: int):
        self.w8(addr, val & 0xFF)
        self.w8(addr + 1, (val >> 8) & 0xFF)

    def r16(self, addr: int) -> int:
        return self.r8(addr) | (self.r8(addr + 1) << 8)


# ------------------------------------------------------------- triangle IR --

@dataclass
class Vtx:
    x: int          # screen space, Q10.22
    y: int          # screen space, Q10.22
    z: int          # 0..0xFFFF depth (raw 16-bit value)
    r: int          # 0..255
    g: int
    b: int
    u: int = 0      # texture coord, Q10.22
    v: int = 0
    tex_en: int = 0


@dataclass
class Tri:
    v0: Vtx
    v1: Vtx
    v2: Vtx
    texture: int = 0   # CLUT page index


@dataclass
class RtrCmd:
    """Draw command (FIFO format matches RTL CMD RTR_CMDQ_BASE)."""
    tri: Tri
    blend: int = 0       # 0=none 1=50% average
    ztest: int = 0       # 0=off 1=on
    dbg_dither: int = 0  # RTL CMDX bit4: +/-1 checkerboard
    dbg_rgbmap: int = 0  # RTL CMDX bit5: R<->B channel swap


# ------------------------------------------------------------ plane setup --

def tdiv(num: int, den: int) -> int:
    """Truncate-toward-zero division — matches Verilog signed '/' semantics.
    (Python's // floors, which diverges for negative numerators.)"""
    q = abs(num) // abs(den)
    return q if (num >= 0) == (den >= 0) else -q


def setup_coeffs(v0: Vtx, v1: Vtx, v2: Vtx,
                 val0: int, val1: int, val2: int):
    """
    Solve val(x,y) = A*x + B*y + C through three vertices (all Q10.22).
    A/B are produced in Q10.22: numerator(Q10.44) << Q / denom(Q10.44),
    truncating toward zero exactly like the RTL divider.
    """
    x0, y0, x1, y1, x2, y2 = v0.x, v0.y, v1.x, v1.y, v2.x, v2.y
    denom = (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0)
    if denom == 0:
        denom = 1  # degenerate: culled later; keep math total
    A = tdiv(((val1 - val0) * (y2 - y0) - (val2 - val0) * (y1 - y0)) << Q, denom)
    B = tdiv(((val2 - val0) * (x1 - x0) - (val1 - val0) * (x2 - x0)) << Q, denom)
    C = val0 - ((A * x0 + B * y0) >> Q)
    return A, B, C


def eval_plane(A: int, B: int, C: int, x: int, y: int) -> int:
    """val = ((A*x + B*y) >> Q) + C   (matches RTL exactly, Q10.22)."""
    return ((A * x + B * y) >> Q) + C


# --------------------------------------------------------------- rasterize --

def rasterize_triangle(vram: Vram, cmd: RtrCmd):
    """Reference implementation of one RTR triangle (all integer math)."""
    v0, v1, v2 = cmd.tri.v0, cmd.tri.v1, cmd.tri.v2
    tex_any = v0.tex_en or v1.tex_en or v2.tex_en

    # Backface cull: signed area (2D cross). CCW front = positive.
    area = ((v1.x - v0.x) * (v2.y - v0.y) -
            (v1.y - v0.y) * (v2.x - v0.x))
    if area <= 0:
        return

    fb_base = FB0_BASE
    z_base = ZBUF_BASE

    # ---------------- plane coefficients (Q10.22) ----------------
    iw_A, iw_B, iw_C = setup_coeffs(v0, v1, v2, 1 << Q, 1 << Q, 1 << Q)
    r_A, r_B, r_C = setup_coeffs(v0, v1, v2, v0.r << Q, v1.r << Q, v2.r << Q)
    g_A, g_B, g_C = setup_coeffs(v0, v1, v2, v0.g << Q, v1.g << Q, v2.g << Q)
    b_A, b_B, b_C = setup_coeffs(v0, v1, v2, v0.b << Q, v1.b << Q, v2.b << Q)
    # Z plane uses RAW 16-bit depth values (0..65535) — NOT Q10.22 — so the
    # interpolated z compares directly against the 16-bit Z-buffer.
    z_A, z_B, z_C = setup_coeffs(v0, v1, v2, v0.z, v1.z, v2.z)
    if tex_any:
        u_A, u_B, u_C = setup_coeffs(v0, v1, v2, v0.u, v1.u, v2.u)
        vv_A, vv_B, vv_C = setup_coeffs(v0, v1, v2, v0.v, v1.v, v2.v)

    # ---------------- edge coefficients ----------------
    # E01(p) = (x1-x0)*(y-y0) - (y1-y0)*(x-x0);  inside = all edges > 0 (CCW)
    # E is in Q10.44 units (Q10.22 * Q10.22), so the per-pixel steps are
    #   step_x = -(dy << Q), step_y = +(dx << Q)   -- scaled to Q8.56!
    dx01, dy01 = v1.x - v0.x, v1.y - v0.y
    dx12, dy12 = v2.x - v1.x, v2.y - v1.y
    dx20, dy20 = v0.x - v2.x, v0.y - v2.y
    sx01, sy01 = -(dy01 << Q), (dx01 << Q)
    sx12, sy12 = -(dy12 << Q), (dx12 << Q)
    sx20, sy20 = -(dy20 << Q), (dx20 << Q)

    # ---------------- bounding box (pixel centers at N+0.5, Q10.22) ----------
    x_lo = max(min(v0.x, v1.x, v2.x), 0)
    x_hi = min(max(v0.x, v1.x, v2.x), (SCR_W - 1) << Q)
    y_lo = max(min(v0.y, v1.y, v2.y), 0)
    y_hi = min(max(v0.y, v1.y, v2.y), (SCR_H - 1) << Q)

    px0 = ((x_lo >> Q) << Q) + (1 << (Q - 1))   # center of first column
    py0 = ((y_lo >> Q) << Q) + (1 << (Q - 1))   # center of first row

    HALF = 1 << (Q - 1)

    for iy in range(y_lo >> Q, (y_hi >> Q) + 1):
        cy = py0 + (iy - (y_lo >> Q)) * (1 << Q)   # center of row iy
        cx = px0
        e01 = dx01 * (cy - v0.y) - dy01 * (cx - v0.x)
        e12 = dx12 * (cy - v1.y) - dy12 * (cx - v1.x)
        e20 = dx20 * (cy - v2.y) - dy20 * (cx - v2.x)

        for ix in range(x_lo >> Q, (x_hi >> Q) + 1):
            if e01 > 0 and e12 > 0 and e20 > 0:
                # interpolate
                inv_w = eval_plane(iw_A, iw_B, iw_C, cx, cy)
                r = eval_plane(r_A, r_B, r_C, cx, cy)
                g = eval_plane(g_A, g_B, g_C, cx, cy)
                b = eval_plane(b_A, b_B, b_C, cx, cy)
                z = eval_plane(z_A, z_B, z_C, cx, cy)
                if tex_any:
                    u_raw = eval_plane(u_A, u_B, u_C, cx, cy)
                    v_raw = eval_plane(vv_A, vv_B, vv_C, cx, cy)
                    # u = (u/w) << Q / inv_w  (Q10.22 divide, truncate)
                    u_final = tdiv(u_raw << Q, inv_w) if inv_w != 0 else 0
                    v_final = tdiv(v_raw << Q, inv_w) if inv_w != 0 else 0

                addr = fb_base + (iy * SCR_W + ix) * 2
                zaddr = z_base + (iy * SCR_W + ix) * 2

                # depth test (LESS passes)
                if cmd.ztest:
                    if z >= vram.r16(zaddr):
                        pass_skip = True
                    else:
                        pass_skip = False
                else:
                    pass_skip = False

                if not pass_skip:
                    if cmd.ztest:
                        vram.w16(zaddr, z & 0xFFFF)

                    if tex_any:
                        # TEX layout: 256 pages x 256 entries (64 KB).
                        # v selects the page, u selects the entry.
                        u8 = (u_final >> Q) & 0xFF
                        v8 = (v_final >> Q) & 0xFF
                        color = vram.r8(TEX_BASE + (v8 << 8) + u8)
                        pr, pg, pb = color, color, color
                    else:
                        pr, pg, pb = r >> Q, g >> Q, b >> Q

                    pr = max(0, min(255, pr))
                    pg = max(0, min(255, pg))
                    pb = max(0, min(255, pb))

                    if cmd.dbg_rgbmap:
                        pr, pb = pb, pr

                    if cmd.blend:
                        old = vram.r16(addr)
                        orr = ((old >> 11) & 0x1F) << 3
                        ogg = ((old >> 5) & 0x3F) << 2
                        obb = (old & 0x1F) << 3
                        pr = (pr + orr) >> 1
                        pg = (pg + ogg) >> 1
                        pb = (pb + obb) >> 1

                    if cmd.dbg_dither:
                        if (ix + iy) & 1:
                            pr = min(255, pr + 1)
                            pg = min(255, pg + 1)
                            pb = min(255, pb + 1)
                        else:
                            pr = max(0, pr - 1)
                            pg = max(0, pg - 1)
                            pb = max(0, pb - 1)

                    px565 = ((((pr >> 3) & 0x1F) << 11) |
                             (((pg >> 2) & 0x3F) << 5) |
                             ((pb >> 3) & 0x1F))
                    vram.w16(addr, px565)

            # advance one pixel: edges + position (steps in Q10.22 deltas)
            e01 += sx01
            e12 += sx12
            e20 += sx20
            cx += 1 << Q


# ------------------------------------------------------------------ utils --

def rgb565_to_ppm(vram: Vram, fb_base: int = FB0_BASE) -> str:
    """Convert the framebuffer to a PPM string for eyeballing/CI diffs."""
    lines = ["P3", f"{SCR_W} {SCR_H}", "255"]
    for y in range(SCR_H):
        row = []
        for x in range(SCR_W):
            p = vram.r16(fb_base + (y * SCR_W + x) * 2)
            r = ((p >> 11) & 0x1F) << 3
            g = ((p >> 5) & 0x3F) << 2
            b = (p & 0x1F) << 3
            row.append(f"{r} {g} {b}")
        lines.append(" ".join(row))
    return "\n".join(lines) + "\n"


def rgb565_unpack(p: int) -> Tuple[int, int, int]:
    return (((p >> 11) & 0x1F) << 3, ((p >> 5) & 0x3F) << 2, (p & 0x1F) << 3)
