"""
tb_doom.py — a real Doom E1M1 frame rasterized by the Ember RTL.

The path is the one a game would take on the chip, minus the CPU:
  1. DMA each frame batch's 64 KB texture atlas into TEX_BASE.
  2. DMA the Doom PLAYPAL into the CLUT at PAL_BASE.
  3. DMA the frame's 19-word GSX triangles straight into the command queue
     at CMDBUF_BASE, terminate the list with a tri_valid=0 word, kick the RTR.
  4. Read the RGB565 framebuffer back over the debug port and compare it
     BIT-EXACT against tools/golden/raster.py.

Everything visual comes from data/doom1.wad: real BSP segs/sectors, real
composed wall textures and flats, real COLORMAP light rows.

Env knobs (for a quick smoke run before the full frame):
  DOOM_RTL_BATCHES=N   only render the first N batches (default: all)
  DOOM_RTL_TRI=N       cap triangles per kick (default 1000)
"""
import os
import sys

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge

CLK_NS = 10

_HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.abspath(os.path.join(_HERE, "..", "tools", "golden")))
import doom_real as R        # noqa: E402
import raster                # noqa: E402
import ppm_png               # noqa: E402

# ---------------------------------------------------------------- registers --
CP_STATUS = 0x04
CP_FIFOD, CP_DMA_DST, CP_DMA_LEN, CP_CMDX = 0x10, 0x14, 0x18, 0x1C
CP_RTR_KICK = 0x20

FB0_BASE = raster.FB0_BASE
ZBUF_BASE = raster.ZBUF_BASE
TEX_BASE = raster.TEX_BASE
CMDBUF = raster.CMDBUF_BASE
PAL_BASE = raster.PAL_BASE

SCR_W, SCR_H = raster.SCR_W, raster.SCR_H
FB_BYTES = SCR_W * SCR_H * 2
Z_BYTES = FB_BYTES
TEX_BYTES = 64 * 1024
M32 = 0xFFFFFFFF


class TB:
    def __init__(self, dut):
        self.dut = dut

    # ---- AXI-Lite host port (same driver contract as tb_tex/tb_scene) ----
    async def wr(self, addr, data, strb=0xF):
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

    async def rd(self, addr):
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

    async def dma(self, byte_off, words, chunk=60):
        off = byte_off
        for i in range(0, len(words), chunk):
            part = words[i:i + chunk]
            for w in part:
                await self.wr(CP_FIFOD, w & M32)
            await self.wr(CP_DMA_DST, off)
            await self.wr(CP_DMA_LEN, len(part) * 4)
            await self.wr(CP_CMDX, 0)
            for _ in range(4000):
                await RisingEdge(self.dut.clk)
                if (await self.rd(CP_STATUS) & 1) == 0:
                    break
            else:
                raise AssertionError("DMA never went idle")
            off += len(part) * 4

    async def kick_and_wait(self, step=500, timeout=2_000_000):
        await self.wr(CP_RTR_KICK, 1)
        waited = 0
        while waited < timeout:
            for _ in range(step):
                await RisingEdge(self.dut.clk)
            waited += step
            if (await self.rd(CP_STATUS) >> 1) & 1 == 0:
                return
        raise AssertionError("rtr_busy stuck high")

    async def dbg_word(self, word_addr):
        d = self.dut
        d.dbg_en.value = 1
        d.dbg_addr.value = word_addr
        d.dbg_be.value = 0
        await RisingEdge(d.clk)
        await RisingEdge(d.clk)
        val = int(d.dbg_rdata.value)
        d.dbg_en.value = 0
        return val

    async def read_region(self, byte_off, nbytes):
        out = bytearray()
        base = byte_off >> 2
        for w in range(nbytes // 4):
            out += (await self.dbg_word(base + w)).to_bytes(4, "little")
        return bytes(out)


def _words(byte_seq):
    return [byte_seq[4 * i] | (byte_seq[4 * i + 1] << 8)
            | (byte_seq[4 * i + 2] << 16) | (byte_seq[4 * i + 3] << 24)
            for i in range(len(byte_seq) // 4)]


@cocotb.test()
async def test_doom_e1m1(dut):
    """Full E1M1 frame through the RTL, compared bit-exact to the golden model."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = TB(dut)

    wad = os.path.abspath(os.path.join(_HERE, "..", "data", "doom1.wad"))
    if not os.path.exists(wad):
        cocotb.skip("data/doom1.wad not present (shareware IWAD is not in git)")
    rend = R.DoomRenderer(wad, "E1M1")
    batches, stats = rend.render()
    print(f"DOOM golden: {stats}")

    # Compare against only the batches the RTL is given: a partial run must
    # not be judged against a full frame (that would just report the missing
    # walls as mismatches).
    nb = int(os.environ.get("DOOM_RTL_BATCHES", len(batches)))
    group = int(os.environ.get("DOOM_RTL_TRI", 1000))
    golden = R.rasterize(rend, batches[:nb])
    with open(os.path.join(_HERE, "doom_golden_check.ppm"), "w") as fh:
        fh.write(raster.rgb565_to_ppm(golden))

    await tb.reset()

    # CLUT: Doom's PLAYPAL, one {8'h0,b,g,r} word per entry (tex_pal mode).
    pal = [(b << 16) | (g << 8) | r for (r, g, b) in rend.pal]
    await tb.dma(PAL_BASE, pal)
    # framebuffer zero, z-buffer far
    await tb.dma(FB0_BASE, [0] * (FB_BYTES // 4))
    await tb.dma(ZBUF_BASE, [0xFFFFFFFF] * (Z_BYTES // 4))

    total = 0
    for bi, (atlas, cmds) in enumerate(batches[:nb]):
        await tb.dma(TEX_BASE, _words(atlas))
        for gi in range(0, len(cmds), group):
            part = cmds[gi:gi + group]
            words = []
            for c in part:
                words += [w & M32 for w in c]
            words.append(0)                    # tri_valid=0: end of queue
            await tb.dma(CMDBUF, words)
            await tb.kick_and_wait()
            total += len(part)
        print(f"DOOM batch {bi}: {len(cmds)} tris, atlas {len(atlas)} B, "
              f"running total {total}")

    raw = await tb.read_region(FB0_BASE, FB_BYTES)
    # rebuild a PPM straight from the RTL bytes
    lines = ["P3", f"{SCR_W} {SCR_H}", "255"]
    for y in range(SCR_H):
        row = []
        for x in range(SCR_W):
            i = (y * SCR_W + x) * 2
            p = raw[i] | (raw[i + 1] << 8)
            r, g, b = raster.rgb565_unpack(p)
            row.append(f"{r} {g} {b}")
        lines.append(" ".join(row))
    rtl_ppm = "\n".join(lines) + "\n"
    with open(os.path.join(_HERE, "doom_rtl.ppm"), "w") as fh:
        fh.write(rtl_ppm)
    with open(os.path.join(_HERE, "doom_rtl.png"), "wb") as fh:
        fh.write(ppm_png.ppm_p3_to_png_bytes(rtl_ppm))

    mism = []
    for i in range(SCR_W * SCR_H):
        rtl_px = raw[2 * i] | (raw[2 * i + 1] << 8)
        gold_px = golden.r16(FB0_BASE + i * 2)
        if rtl_px != gold_px:
            mism.append((i % SCR_W, i // SCR_W, rtl_px, gold_px))
    print(f"DOOM RTL: {total} triangles, {len(mism)} pixel mismatches "
          f"of {SCR_W * SCR_H}")
    assert not mism, f"{len(mism)} pixel mismatches: " + ", ".join(
        f"({x},{y}) rtl={a:#06x} gold={b:#06x}" for x, y, a, b in mism[:8])
