"""
tb_display.py — Phase-3 cocotb testbench: display controller + frame capture.

Flow (full software path, like a real console):
  1. Fill FB0 with a gradient via CP DMA.
  2. Draw the golden RTR triangle on top (RTR path from Phase 2).
  3. The display controller free-runs: capture exactly one 640x480@60 frame
     from vid_de/vid_pixel after a vsync edge.
  4. Verify EVERY output pixel: out(X,Y) == FB(Y>>1, X>>1) (2x2 double-scan).
  5. Verify the downsampled framebuffer ALSO matches the golden rasterizer
     per-pixel (re-uses the Phase-2 bit-exact check on the composite frame).
  6. Write captured frames to display_frame.ppm for eyeballing.

Sim cost note: one full frame is 800*525 = 420k cycles (~15 s wall in this
environment). We capture ONE frame per test.
"""

import os
import sys

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge

CLK_NS = 10

_GOLDEN_DIR = os.path.join(os.path.dirname(__file__), "..", "tools", "golden")
sys.path.insert(0, os.path.abspath(_GOLDEN_DIR))
import raster as golden  # noqa: E402

# CP register offsets (mirror tb_memory)
CP_ID, CP_STATUS, CP_FENCE = 0x00, 0x04, 0x0C
CP_FIFOD, CP_DMA_DST, CP_DMA_LEN, CP_CMDX = 0x10, 0x14, 0x18, 0x1C
CP_RTR_KICK = 0x20

VRAM_BASE = 0x1000
FB0_BASE = golden.FB0_BASE
SCR_W, SCR_H = golden.SCR_W, golden.SCR_H
FB_BYTES = SCR_W * SCR_H * 2
OUT_W, OUT_H = 640, 480

RTR_CMD_WORDS = 19
FENCE_TEX, FENCE_CMD = 3, 4


class AxiLiteDriver:
    def __init__(self, dut):
        self.dut = dut

    async def write(self, addr, data, strb=0xF):
        d = self.dut
        d.h_awaddr.value = addr
        d.h_awvalid.value = 1
        d.h_wdata.value = data
        d.h_wstrb.value = strb
        d.h_wvalid.value = 1
        aw_done = w_done = False
        while not (aw_done and w_done):
            await RisingEdge(d.clk)
            if d.h_awready.value == 1 and d.h_awvalid.value == 1:
                aw_done = True
                d.h_awvalid.value = 0
            if d.h_wready.value == 1 and d.h_wvalid.value == 1:
                w_done = True
                d.h_wvalid.value = 0
        d.h_bready.value = 1
        while True:
            await RisingEdge(d.clk)
            if d.h_bvalid.value == 1:
                resp = int(d.h_bresp.value)
                break
        d.h_bready.value = 0
        assert resp == 0, f"AXI write resp {resp} at {addr:#x}"

    async def read(self, addr):
        d = self.dut
        d.h_araddr.value = addr
        d.h_arvalid.value = 1
        while True:
            await RisingEdge(d.clk)
            if d.h_arready.value == 1 and d.h_arvalid.value == 1:
                d.h_arvalid.value = 0
                break
        d.h_rready.value = 1
        while True:
            await RisingEdge(d.clk)
            if d.h_rvalid.value == 1:
                data = int(d.h_rdata.value)
                resp = int(d.h_rresp.value)
                break
        d.h_rready.value = 0
        assert resp == 0, f"AXI read resp {resp} at {addr:#x}"
        return data


class EmberTB:
    def __init__(self, dut):
        self.dut = dut
        self.axi = AxiLiteDriver(dut)

    async def reset(self):
        d = self.dut
        d.rst_n.value = 0
        d.dbg_en.value = 0
        d.dbg_addr.value = 0
        d.dbg_wdata.value = 0
        d.dbg_be.value = 0
        d.h_awvalid.value = 0
        d.h_wvalid.value = 0
        d.h_arvalid.value = 0
        d.h_bready.value = 0
        d.h_rready.value = 0
        d.fb_select.value = 0
        await RisingEdge(d.clk)
        await RisingEdge(d.clk)
        d.rst_n.value = 1
        await RisingEdge(d.clk)

    async def reg_write(self, addr, data):
        await self.axi.write(addr, data)

    async def reg_read(self, addr):
        return await self.axi.read(addr)

    async def dbg_read(self, word_addr):
        d = self.dut
        d.dbg_en.value = 1
        d.dbg_addr.value = word_addr
        d.dbg_be.value = 0
        await RisingEdge(d.clk)
        await RisingEdge(d.clk)
        val = int(d.dbg_rdata.value)
        d.dbg_en.value = 0
        return val

    async def wait_dma_idle(self, timeout=100000):
        for _ in range(timeout):
            await RisingEdge(self.dut.clk)
            if (int(await self.reg_read(CP_STATUS)) & 1) == 0:
                return
        raise AssertionError("DMA never went idle")

    async def upload_words_dma(self, byte_off, words, fence, chunk=60):
        off = byte_off
        for i in range(0, len(words), chunk):
            part = words[i:i + chunk]
            for w in part:
                await self.reg_write(CP_FIFOD, w)
            await self.reg_write(CP_DMA_DST, off)
            await self.reg_write(CP_DMA_LEN, len(part) * 4)
            await self.reg_write(CP_CMDX, (fence << 8) | 0)
            await self.wait_dma_idle()
            off += len(part) * 4

    async def kick_and_wait(self, timeout=4_000_000):
        await self.reg_write(CP_RTR_KICK, 1)
        for _ in range(timeout):
            await RisingEdge(self.dut.clk)
            if ((int(await self.reg_read(CP_STATUS)) >> 1) & 1) == 0:
                return
        raise AssertionError("RTR never went idle")

    async def read_fb_pixels(self):
        out = bytearray()
        for w in range(FB_BYTES // 4):
            out += (await self.dbg_read((FB0_BASE >> 2) + w)).to_bytes(
                4, "little")
        return [out[i] | (out[i + 1] << 8) for i in range(0, len(out), 2)]


def halfword_words(pix, npix):
    words = []
    for wi in range(npix // 2):
        words.append((pix[2 * wi + 1] << 16) | pix[2 * wi])
    return words


def tri_cmd_words(cmd):
    tri = cmd.tri
    tex_any = tri.v0.tex_en or tri.v1.tex_en or tri.v2.tex_en
    w = [0] * RTR_CMD_WORDS
    w[0] = (1
            | ((cmd.blend & 1) << 1)
            | ((cmd.ztest & 1) << 2)
            | ((1 if tex_any else 0) << 3)
            | ((cmd.dbg_dither & 1) << 4)
            | ((cmd.dbg_rgbmap & 1) << 5))
    coords = (tri.v0.x, tri.v0.y, tri.v1.x, tri.v1.y, tri.v2.x, tri.v2.y)
    for i, c in enumerate(coords):
        w[1 + i] = c & 0xFFFFFFFF
    w[7], w[8], w[9] = tri.v0.z & 0xFFFF, tri.v1.z & 0xFFFF, tri.v2.z & 0xFFFF
    for i, vt in enumerate((tri.v0, tri.v1, tri.v2)):
        w[10 + i] = ((vt.b & 0xFF) << 16) | ((vt.g & 0xFF) << 8) | (vt.r & 0xFF)
    for i, vt in enumerate((tri.v0, tri.v1, tri.v2)):
        w[13 + 2 * i] = vt.u & 0xFFFFFFFF
        w[14 + 2 * i] = vt.v & 0xFFFFFFFF
    return w


def write_ppm(path, frame):
    """frame: list of rows, each row a list of (r,g,b)."""
    lines = ["P3", f"{OUT_W} {OUT_H}", "255"]
    for row in frame:
        lines.append(" ".join(f"{r} {g} {b}" for (r, g, b) in row))
    with open(path, "w") as f:
        f.write("\n".join(lines) + "\n")


def rgb565_unpack(p):
    return (((p >> 11) & 0x1F) << 3, ((p >> 5) & 0x3F) << 2, (p & 0x1F) << 3)


async def capture_frame(dut, max_cycles=800 * 525 + 4000):
    """Capture one full 640x480 frame after a vsync edge.

    Returns frame as a flat list of RGB565 pixels, index Y*640+X.
    """
    # wait for vsync assert edge, then deassert: start of visible region
    saw_vs = False
    await RisingEdge(dut.vid_vs)
    for _ in range(2000):
        await RisingEdge(dut.clk)
        if int(dut.vid_vs.value) == 0:
            break
    frame = [0] * (OUT_W * OUT_H)
    idx = 0
    for _ in range(max_cycles):
        await FallingEdge(dut.clk)          # sample outputs settled
        de = int(dut.vid_de.value)
        if de:
            frame[idx] = int(dut.vid_pixel.value)
            idx += 1
        elif idx >= OUT_W * OUT_H:
            break
        saw_vs = saw_vs or int(dut.vid_vs.value)
    assert idx == OUT_W * OUT_H, f"captured {idx} pixels, want {OUT_W*OUT_H}"
    return frame


@cocotb.test()
async def test_display_composite_frame(dut):
    """Gradient + RTR triangle streamed by the display controller."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = EmberTB(dut)
    await tb.reset()

    # 1. golden composite: gradient FB + triangle (bit-exact reference)
    q = 22
    cmd = golden.RtrCmd(tri=golden.Tri(
        golden.Vtx(x=(20 << q), y=(20 << q), z=1000, r=255, g=0, b=0),
        golden.Vtx(x=(300 << q), y=(40 << q), z=1000, r=0, g=255, b=0),
        golden.Vtx(x=(100 << q), y=(220 << q), z=1000, r=0, g=0, b=255)))
    g = golden.Vram()
    for i in range(SCR_W * SCR_H):        # gradient background
        g.w16(FB0_BASE + i * 2, ((i // SCR_W) & 0x1F) << 11)
    golden.rasterize_triangle(g, cmd)

    # 2. RTL: gradient via DMA, triangle via RTR
    grad = [((i // SCR_W) & 0x1F) << 11 for i in range(SCR_W * SCR_H)]
    await tb.upload_words_dma(FB0_BASE, halfword_words(grad, SCR_W * SCR_H),
                              FENCE_TEX)
    words = tri_cmd_words(cmd) + [0]
    await tb.upload_words_dma(0x05B000, words, FENCE_CMD)
    await tb.kick_and_wait()

    # 3. framebuffer itself must match golden (Phase-2 invariant)
    fb = await tb.read_fb_pixels()
    mism = sum(1 for i in range(SCR_W * SCR_H)
               if fb[i] != g.r16(FB0_BASE + i * 2))
    assert mism == 0, f"FB mismatch vs golden: {mism} pixels"

    # 4. capture one display frame and verify 2x2 double-scan mapping
    frame = await capture_frame(dut)
    bad = 0
    for Y in range(0, OUT_H, 2):          # sample 2x2 blocks
        for X in range(0, OUT_W, 2):
            want = fb[(Y >> 1) * SCR_W + (X >> 1)]
            got00 = frame[Y * OUT_W + X]
            got01 = frame[Y * OUT_W + X + 1]
            got10 = frame[(Y + 1) * OUT_W + X]
            got11 = frame[(Y + 1) * OUT_W + X + 1]
            if not (got00 == got01 == got10 == got11 == want):
                bad += 1
                if bad <= 5:
                    print(f"DSMISMATCH ({X},{Y}) want={want:#06x} "
                          f"got={got00:#06x}/{got01:#06x}/"
                          f"{got10:#06x}/{got11:#06x}")
    assert bad == 0, f"{bad} 2x2 blocks mismatch"

    # 5. eyeball frames (CI artifacts)
    rows = [rgb565_unpack(frame[Y * OUT_W + X])
            for Y in range(OUT_H) for X in range(OUT_W)]
    write_ppm(os.path.join(os.path.dirname(__file__),
                           "display_frame.ppm"),
              [rows[Y * OUT_W:(Y + 1) * OUT_W] for Y in range(OUT_H)])
    print("OK — display_frame.ppm written, all 2x2 blocks verified")
