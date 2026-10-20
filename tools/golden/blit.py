"""
Golden blit for the Ember GPU — integer-exact reference model.

Contract (matches ember_blit.sv exactly):
  * Source:  a W x H image at src_off, stride = W (compact sprite bitmap,
    byte-packed RGB565: pixel (sx,sy) at bytes src_off + 2*(W*sy + sx)).
  * Dest:    FB-strided (stride 320), pixel (0,0) at dst_off; pixel (sx,sy)
    lands at dst_off + 2*((dst_y0 + sy*scale)*320 + dst_x0 + sx*scale).
    (dst_off IS the (0,0) destination corner, so no separate x0/y0 regs.)
  * key_en:  source pixels equal to key_color are skipped entirely (no
    writes) — transparency.
  * scale2:  each source pixel becomes a 2x2 dest block; each of the two
    rows is a separate word write with both halfwords = the pixel.
  * Overlap: v1 reads one pixel then writes it (no line buffer); software
    must keep source and dest rects non-overlapping (console convention).
"""

from raster import SCR_W  # FB stride in pixels


def blit(vram, dst_off: int, src_off: int, w: int, h: int,
         key_en: int = 0, key_color: int = 0, scale2: int = 0):
    """Reference implementation of one Ember blit (all integer math)."""
    scale = 2 if scale2 else 1
    for sy in range(h):
        for sx in range(w):
            sbyte = src_off + 2 * (w * sy + sx)
            px = vram.r16(sbyte)
            if key_en and px == (key_color & 0xFFFF):
                continue
            for ry in range(scale):
                for rx in range(scale):
                    dx = sx * scale + rx
                    dy = sy * scale + ry
                    daddr = dst_off + 2 * (dy * SCR_W + dx)
                    vram.w16(daddr, px)
