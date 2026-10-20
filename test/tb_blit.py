"""
tb_blit.py — Phase-3 cocotb testbench: blitter vs golden model.

Three scenarios, all via the real CP register path (CFG/DST/SRC/SIZE + KICK,
poll STATUS[blit_busy]):
  1. plain 1x rect copy of a 5x4 sprite onto a patterned background
  2. key-color transparency: background must show through key pixels
  3. 2x scale: 3x2 sprite becomes a 6x4 block
Full-FB per-pixel compare vs tools/golden/blit.py + raster.py Vram.
"""

import os
import sys

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge

CLK_NS = 10

_GOLDEN_DIR = os.path.join(os.path.dirname(__file__), "..", "tools", "golden")
sys.path.insert(0, os.path.abspath(_GOLDEN_DIR))
import raster as golden   # noqa: E402
import blit as gblit      # noqa: E402

CP_STATUS = 0x04
CP_FIFOD, CP_DMA_DST, CP_DMA_LEN, CP_CMDX = 0x10, 0x14, 0x18, 0x1C
CP_BLIT_CFG, CP_BLIT_DST, CP_BLIT_SRC, CP_BLIT_SIZE, CP_BLIT_KICK = \
    0x24, 0x28, 0x2C, 0x30, 0x34

VRAM_BASE = 0x1000
FB0_BASE = golden.FB0_BASE
SPRITE_OFF = 0x070000            # scratch area (well clear of FB/TEX/CMDQ)
SCR_W, SCR_H = golden.SCR_W, golden.SCR_H
FB_BYTES = SCR_W * SCR_H * 2

FENCE_TEX = 3


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

    async def wait_blit_done(self, timeout=100000):
        # CP_STATUS: [0]=dma_busy [1]=rtr_busy [2]=rb_empty [6:3]=rb_count
        #            [7]=blit_busy
        for _ in range(timeout):
            await RisingEdge(self.dut.clk)
            if ((int(await self.reg_read(CP_STATUS)) >> 7) & 1) == 0:
                return
        raise AssertionError("blit never finished")

    async def read_fb_pixels(self):
        out = bytearray()
        for w in range(FB_BYTES // 4):
            out += (await self.dbg_read((FB0_BASE >> 2) + w)).to_bytes(
                4, "little")
        return [out[i] | (out[i + 1] << 8) for i in range(0, len(out), 2)]

    async def blit(self, dst_off, src_off, w, h, key_en=0, key_color=0,
                   scale2=0):
        await self.blit_probe_setup(dst_off, src_off, w, h,
                                    key_en, key_color, scale2)
        await self.wait_blit_done()

    async def blit_probe_setup(self, dst_off, src_off, w, h, key_en=0,
                               key_color=0, scale2=0):
        await self.reg_write(CP_BLIT_CFG,
                             ((scale2 & 1) << 30) | ((key_en & 1) << 29)
                             | (key_color & 0xFFFF))
        await self.reg_write(CP_BLIT_DST, dst_off)
        await self.reg_write(CP_BLIT_SRC, src_off)
        await self.reg_write(CP_BLIT_SIZE, ((h & 0xFF) << 16) | (w & 0xFF))
        await self.reg_write(CP_BLIT_KICK, 1)


def halfword_words(pix, npix):
    words = []
    for wi in range(npix // 2):
        words.append((pix[2 * wi + 1] << 16) | pix[2 * wi])
    return words


def bg_pixels():
    """Checkerboard background over the whole FB."""
    return [0x39E7 if ((x >> 2) + (y >> 2)) & 1 else 0x0421
            for y in range(SCR_H) for x in range(SCR_W)]


def make_sprite():
    """5x4 sprite with distinct colors; color 0x0000 used as key."""
    cols = [0x0000, 0x07E0, 0x001F, 0xF800, 0xFFE0,
            0x07FF, 0xF81F, 0xFFE0, 0x0000, 0x041F,
            0x8410, 0x9B6D, 0x528A, 0xFFFF, 0x0000,
            0x0123, 0x4567, 0x89AB, 0xCDEF, 0x0000]
    w, h = 5, 4
    return w, h, cols


async def setup_bg_and_sprite(tb, g):
    """Fill FB with bg + upload sprite, in BOTH golden vram and RTL."""
    bg = bg_pixels()
    _, _, cols = make_sprite()
    # golden side
    for i, p in enumerate(bg):
        g.w16(FB0_BASE + i * 2, p)
    # sprite goes into a compact area of golden vram too (same bytes)
    w, h = make_sprite()[0], make_sprite()[1]
    for sy in range(h):
        for sx in range(w):
            g.w16(SPRITE_OFF + 2 * (w * sy + sx), cols[w * sy + sx])
    # RTL side: bg via DMA, sprite via DMA
    words = halfword_words(bg, SCR_W * SCR_H)
    await tb.upload_words_dma(FB0_BASE, words, FENCE_TEX)
    sw = []
    for i in range(w * h // 2):
        sw.append(cols[2 * i] | (cols[2 * i + 1] << 16))
    if (w * h) % 2:
        sw.append(cols[w * h - 1])
    await tb.upload_words_dma(SPRITE_OFF, sw, FENCE_TEX)


async def compare_fb(tb, g, name):
    rtl_px = await tb.read_fb_pixels()
    mism = []
    for i in range(SCR_W * SCR_H):
        gp = g.r16(FB0_BASE + i * 2)
        if rtl_px[i] != gp:
            mism.append((i % SCR_W, i // SCR_W, rtl_px[i], gp))
    assert not mism, (f"{name}: {len(mism)} mismatches; " +
                      "; ".join(f"({x},{y}) rtl={r:#06x} gld={gp:#06x}"
                                for (x, y, r, gp) in mism[:8]))


@cocotb.test()
async def test_blit_copy_1x(dut):
    """Plain 1x copy of a 5x4 sprite onto a patterned background."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = EmberTB(dut)
    await tb.reset()

    g = golden.Vram()
    await setup_bg_and_sprite(tb, g)

    w, h, _ = make_sprite()
    dst = 2 * (40 * SCR_W + 60)          # pixel (60,40)
    gblit.blit(g, dst, SPRITE_OFF, w, h)
    await tb.blit(dst, SPRITE_OFF, w, h)

    await compare_fb(tb, g, "blit_copy_1x")


@cocotb.test()
async def test_blit_key_transparency(dut):
    """key_en=1: background shows through key-colored sprite pixels."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = EmberTB(dut)
    await tb.reset()

    g = golden.Vram()
    await setup_bg_and_sprite(tb, g)

    w, h, _ = make_sprite()
    dst = 2 * (100 * SCR_W + 30)         # pixel (30,100) — odd column too
    gblit.blit(g, dst, SPRITE_OFF, w, h, key_en=1, key_color=0x0000)
    await tb.blit(dst, SPRITE_OFF, w, h, key_en=1, key_color=0x0000)

    await compare_fb(tb, g, "blit_key_transparency")


@cocotb.test()
async def test_blit_scale2(dut):
    """2x scale: each source pixel becomes a 2x2 block."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = EmberTB(dut)
    await tb.reset()

    g = golden.Vram()
    await setup_bg_and_sprite(tb, g)

    w, h, _ = make_sprite()
    dst = 2 * (120 * SCR_W + 20)         # pixel (20,120)
    gblit.blit(g, dst, SPRITE_OFF, w, h, key_en=1, key_color=0x0000, scale2=1)
    await tb.blit(dst, SPRITE_OFF, w, h, key_en=1, key_color=0x0000, scale2=1)

    await compare_fb(tb, g, "blit_scale2")
