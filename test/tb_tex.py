"""
tb_tex.py — Phase-7 textured-scene testbench: GSX texture path end-to-end.

Real software path:
  1. Upload the checker CLUT page to TEX_BASE via DMA.
  2. GSX: identity MVP, tex_en CFG + texpage, textured quad (2 tris with
     per-vertex u/v covering the full page; affine v1 contract).
  3. RTR sweep; compare the framebuffer BIT-EXACT against the golden model
     (tex.textured_quad_cmds -> tex.words_to_rtrcmd -> raster.rasterize).

cocotb 2.1 note: use int(sig.value) and d.<sig>.value = x (no setattr).
"""
import os
import sys

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge

CLK_NS = 10

_GOLDEN_DIR = os.path.join(os.path.dirname(__file__), "..", "tools", "golden")
sys.path.insert(0, os.path.abspath(_GOLDEN_DIR))
import tex      # noqa: E402
import raster   # noqa: E402

# ---------------------------------------------------------------- constants --
CP_ID, CP_STATUS, CP_CTRL, CP_FENCE = 0x00, 0x04, 0x08, 0x0C
CP_FIFOD, CP_DMA_DST, CP_DMA_LEN, CP_CMDX = 0x10, 0x14, 0x18, 0x1C
CP_RTR_KICK = 0x20
CP_GSX_MATA, CP_GSX_VTX, CP_GSX_COL = 0x38, 0x3C, 0x40
CP_GSX_GO, CP_GSX_CFG = 0x44, 0x48

VRAM_BASE = 0x1000
FB0_BASE = raster.FB0_BASE
ZBUF_BASE = raster.ZBUF_BASE
TEX_BASE = raster.TEX_BASE
CMDQ_OFF = raster.CMDBUF_BASE

SCR_W, SCR_H = raster.SCR_W, raster.SCR_H
FB_BYTES = SCR_W * SCR_H * 2
Z_BYTES = FB_BYTES
TEX_BYTES = 64 * 1024
RTR_CMD_WORDS = 19
FENCE_TEX = 3
M32 = 0xFFFFFFFF


# ------------------------------------------------------------------- driver --
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
        await RisingEdge(d.clk)
        await RisingEdge(d.clk)
        d.rst_n.value = 1
        await RisingEdge(d.clk)

    async def reg_write(self, addr, data):
        await self.axi.write(addr, data)

    async def reg_read(self, addr):
        return await self.axi.read(addr)

    async def wait_dma_idle(self, timeout=100000):
        for _ in range(timeout):
            await RisingEdge(self.dut.clk)
            if (await self.reg_read(CP_STATUS) & 1) == 0:
                return
        raise AssertionError("DMA never went idle")

    async def upload_words_dma(self, byte_off, words, fence, chunk=60):
        off = byte_off
        for i in range(0, len(words), chunk):
            part = words[i:i + chunk]
            for w in part:
                await self.reg_write(CP_FIFOD, w & M32)
            await self.reg_write(CP_DMA_DST, off)
            await self.reg_write(CP_DMA_LEN, len(part) * 4)
            await self.reg_write(CP_CMDX, (fence << 8) | 0)
            await self.wait_dma_idle()
            off += len(part) * 4

    async def kick_and_wait(self, bit, timeout=4_000_000):
        await self.reg_write(CP_RTR_KICK, 1)
        for _ in range(timeout):
            await RisingEdge(self.dut.clk)
            status = await self.reg_read(CP_STATUS)
            if (status >> bit) & 1 == 0:
                return
        raise AssertionError(f"STATUS bit {bit} never went idle")

    async def dbg_read_region(self, byte_off, nbytes):
        out = bytearray()
        for w in range(nbytes // 4):
            out += (await self.dbg_read((byte_off >> 2) + w)).to_bytes(
                4, "little")
        return out

    async def dbg_read(self, word_addr):
        d = self.dut
        d.dbg_en.value = 1
        d.dbg_addr.value = word_addr
        d.dbg_be.value = 0
        await RisingEdge(d.clk)
        await RisingEdge(d.clk)  # 1-cycle RAM latency
        val = int(d.dbg_rdata.value)
        d.dbg_en.value = 0
        return val

    # ------------------------------------------------------------- GSX path --
    async def gsx_setup(self, mode_bits, tri_count=0):
        await self.reg_write(CP_GSX_CFG, mode_bits & 0x7FFFFFFF)
        await self.reg_write(CP_GSX_CFG, 0x80000000 | (tri_count & 0xFF))

    async def gsx_load_matrix(self, mata_words):
        for w in mata_words:
            await self.reg_write(CP_GSX_MATA, w & M32)

    async def gsx_load_vertex15(self, v15, col_word):
        """One triangle: 15 words (x,y,z,u,v x3) + 3 identical colors."""
        for w in v15:
            await self.reg_write(CP_GSX_VTX, w & M32)
        for _ in range(3):
            await self.reg_write(CP_GSX_COL, col_word & 0x00FFFFFF)

    async def gsx_kick_wait(self, timeout=20000):
        await self.reg_write(CP_GSX_GO, 1)
        for _ in range(timeout):
            await RisingEdge(self.dut.clk)
            if (await self.reg_read(CP_STATUS) >> 8) & 1 == 0:
                return
        raise AssertionError("gsx_busy stuck high")


# ------------------------------------------------------------------- test --
@cocotb.test()
async def test_tex_quad(dut):
    """Textured quad through GSX (tex_en + texpage) + RTR vs golden."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = EmberTB(dut)
    await tb.reset()

    # texture page 0: checkerboard
    page = tex.checker_texture()
    words = []
    for wi in range(TEX_BYTES // 4):
        words.append(page[4 * wi] | (page[4 * wi + 1] << 8)
                     | (page[4 * wi + 2] << 16) | (page[4 * wi + 3] << 24))
    await tb.upload_words_dma(TEX_BASE, words, FENCE_TEX)

    # golden command stream (single source of truth)
    cmds = tex.textured_quad_cmds(page=0)
    assert len(cmds) == 2

    # golden frame (the golden side MUST texture its own Vram — otherwise
    # golden renders black, a flag-bit bug on the RTL side renders black
    # too, and black==black fakes a pass. Phase-7c: exactly this gap hid a
    # GSX w0 bit-position bug through 24/24 'green'.)
    g = raster.Vram()
    for i in range(65536):
        g.w8(TEX_BASE + i, page[i])
    for i in range(SCR_W * SCR_H):
        g.w16(ZBUF_BASE + i * 2, 0xFFFF)
    for w in cmds:
        raster.rasterize_triangle(g, tex.words_to_rtrcmd(w))

    # RTL frame
    await tb.upload_words_dma(ZBUF_BASE, [0xFFFFFFFF] * (Z_BYTES // 4),
                              FENCE_TEX)
    await tb.upload_words_dma(FB0_BASE, [0] * (FB_BYTES // 4), FENCE_TEX)

    await tb.gsx_setup((1 << 27))               # tex_en, page 0
    mata = [0x3F800000 if i % 5 == 0 else 0 for i in range(16)]
    await tb.gsx_load_matrix(mata)

    # per-triangle 15-word vertex sets (regenerate from the golden inputs)
    f2b = __import__("fpu").f2b
    verts = [(60.0, 60.0, 0.25, 0.0, 0.0),
             (260.0, 60.0, 0.75, 255.0, 0.0),
             (260.0, 220.0, 0.75, 255.0, 255.0),
             (60.0, 220.0, 0.25, 0.0, 255.0)]
    for tri in ((0, 1, 2), (0, 2, 3)):
        v15 = []
        for idx in tri:
            x, y, z, u, vv = verts[idx]
            v15 += [f2b(x), f2b(y), f2b(z), f2b(u), f2b(vv)]
        await tb.gsx_load_vertex15(v15, 0)
        await tb.gsx_kick_wait()

    await tb.kick_and_wait(1)                   # rtr_busy

    print(f"DIAG: RTL cmdq[0]={await tb.dbg_read(CMDQ_OFF >> 2):#010x} "
          f"golden words[0]={cmds[0][0] & 0xFFFFFFFF:#010x}")

    rtl_raw = await tb.dbg_read_region(FB0_BASE, FB_BYTES)
    mism = []
    for i in range(SCR_W * SCR_H):
        rtl_px = int.from_bytes(rtl_raw[2 * i:2 * i + 2], "little")
        gold_px = g.r16(FB0_BASE + i * 2)
        if rtl_px != gold_px:
            mism.append((i % SCR_W, i // SCR_W, rtl_px, gold_px))
    assert not mism, f"{len(mism)} pixel mismatches: " + ", ".join(
        f"({x},{y}) rtl={a:#06x} gold={b:#06x}" for x, y, a, b in mism[:8])
