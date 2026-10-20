"""
tb_gsx.py — Phase-4b cocotb testbench: GSX geometry engine vs golden model.

Drives the REAL software path end to end:
  1. Load the 4x4 fp32 MVP matrix + 9 vertex words + 3 color words through
     the CP GSX CSR window (MATA/VTX/COL auto-inc pointers, CFG, GO).
  2. Poll STATUS.gsx_busy (bit 8) for completion.
  3a. test_gsx_identity: w=1.0 matrix, screen-space coords in, bit-exact
      Q10.22 passthrough words out (transform + emit check).
  3b. test_gsx_cull: matrix m33=-1 -> every w<0 -> triangle dropped, queue
      untouched (terminator word intact).
  3c. test_gsx_cube: full spinning-cube frame — 12 MVP triangles through
      GSX + RTR, framebuffer bit-exact vs tools/golden/cube.py + raster.py.

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
import fpu     # noqa: E402
import cube    # noqa: E402
import raster  # noqa: E402

# ---------------------------------------------------------------- constants --
CP_ID, CP_STATUS, CP_CTRL, CP_FENCE = 0x00, 0x04, 0x08, 0x0C
CP_FIFOD, CP_DMA_DST, CP_DMA_LEN, CP_CMDX = 0x10, 0x14, 0x18, 0x1C
CP_RTR_KICK = 0x20
CP_GSX_MATA, CP_GSX_VTX, CP_GSX_COL = 0x38, 0x3C, 0x40
CP_GSX_GO, CP_GSX_CFG = 0x44, 0x48

VRAM_BASE = 0x1000
FB0_BASE = raster.FB0_BASE
ZBUF_BASE = raster.ZBUF_BASE
CMDQ_OFF = raster.CMDBUF_BASE

SCR_W, SCR_H = raster.SCR_W, raster.SCR_H
FB_BYTES = SCR_W * SCR_H * 2
Z_BYTES = FB_BYTES
RTR_CMD_WORDS = 19
FENCE_TEX = 3

M32 = 0xFFFFFFFF


# ------------------------------------------------------------------- driver --
class AxiLiteDriver:
    """Minimal AXI4-Lite master: one transaction at a time, full handshake."""

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
                await self.reg_write(CP_FIFOD, w)
            await self.reg_write(CP_DMA_DST, off)
            await self.reg_write(CP_DMA_LEN, len(part) * 4)
            await self.reg_write(CP_CMDX, (fence << 8) | 0)
            await self.wait_dma_idle()
            off += len(part) * 4

    async def kick_and_wait(self, bit, timeout=4_000_000):
        """Kick the RTR (CP_RTR_KICK) and poll STATUS bit `bit` to 0."""
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

    # ------------------------------------------------------------- GSX path --
    async def gsx_setup(self, mode_bits, tri_count=0):
        """CFG mode form (ztest/blend/tex/overw bits) + tri_count write."""
        await self.reg_write(CP_GSX_CFG, mode_bits & 0x7FFFFFFF)
        await self.reg_write(CP_GSX_CFG, 0x80000000 | (tri_count & 0xFF))

    async def gsx_load_matrix(self, mata_words):
        for w in mata_words:
            await self.reg_write(CP_GSX_MATA, w & M32)

    async def gsx_load_vertex(self, v9, col_word):
        """One triangle: 9 xyz words (+6 zero u/v words — the VTX window is
        15 words: x,y,z,u,v per vertex) + 3 identical color words."""
        v15 = []
        for i in range(3):
            v15 += [v9[3 * i], v9[3 * i + 1], v9[3 * i + 2], 0, 0]
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

    async def read_cmd_words(self, nwords):
        raw = await self.dbg_read_region(CMDQ_OFF, nwords * 4)
        return [int.from_bytes(raw[4 * i:4 * i + 4], "little")
                for i in range(nwords)]


# ------------------------------------------------------------------ tests --
@cocotb.test()
async def test_gsx_identity(dut):
    """w=1.0 matrix: screen-space in -> bit-exact passthrough cmd words."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = EmberTB(dut)
    await tb.reset()
    await tb.gsx_setup(0)

    ident = [fpu.f2b(1.0) if i % 5 == 0 else 0 for i in range(16)]
    await tb.gsx_load_matrix(ident)

    xs = [fpu.f2b(30.0), fpu.f2b(150.0), fpu.f2b(72.0)]
    ys = [fpu.f2b(50.0), fpu.f2b(100.0), fpu.f2b(90.0)]
    zs = [fpu.f2b(0.25)] * 3
    v9 = [xs[0], ys[0], zs[0], xs[1], ys[1], zs[1], xs[2], ys[2], zs[2]]
    col = (5 << 16) | (100 << 8) | 200          # {b,g,r,x}
    await tb.gsx_load_vertex(v9, col)
    await tb.gsx_kick_wait()

    words = await tb.read_cmd_words(RTR_CMD_WORDS + 1)
    exp = cube.gsx_cmd_words(ident, v9, [col] * 3, 0)
    assert exp is not None, "golden identity tri unexpectedly culled"
    for i in range(RTR_CMD_WORDS):
        assert words[i] == (exp[i] & M32), \
            f"word {i}: rtl={words[i]:#010x} golden={exp[i] & M32:#010x}"
    assert words[RTR_CMD_WORDS] == 0, "terminator missing"


@cocotb.test()
async def test_gsx_cull(dut):
    """m33=-1 -> w'=-1 <0 on every vertex: triangle dropped, queue intact.

    VRAM persists across tests in one sim build, so the terminator is checked
    at a FRESH slot (count=40): it must still be 0 after the culled kick.
    """
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = EmberTB(dut)
    await tb.reset()
    await tb.gsx_setup(0, tri_count=40)

    m = [0] * 16
    m[15] = fpu.f2b(-1.0)                        # w' = -1 -> cull
    await tb.gsx_load_matrix(m)

    xs = [fpu.f2b(160.0), fpu.f2b(150.0), fpu.f2b(170.0)]
    ys = [fpu.f2b(120.0), fpu.f2b(100.0), fpu.f2b(140.0)]
    zs = [fpu.f2b(0.5), fpu.f2b(0.25), fpu.f2b(0.25)]
    v9 = [xs[0], ys[0], zs[0], xs[1], ys[1], zs[1], xs[2], ys[2], zs[2]]
    await tb.gsx_load_vertex(v9, 0x00102030)
    await tb.gsx_kick_wait()

    term = await tb.dbg_read((CMDQ_OFF + 40 * 76) >> 2)
    assert term == 0, f"culled triangle wrote to the queue: {term:#010x}"


# ------------------------------------------------------- cube frame helpers --
def cube_tri_inputs():
    """Per-face (v9 words, col word) inputs from the shared cube geometry."""
    tris = []
    for idxs, rgb in cube.CUBE_FACES:
        v9 = []
        for i in idxs:
            x, y, z = cube.CUBE_VERTS[i]
            v9 += cube._vword(x, y, z)
        tris.append((v9, cube._colword(rgb)))
    return tris


@cocotb.test()
async def test_gsx_cube(dut):
    """Full spinning-cube frame: 12 MVP tris through GSX+RTR vs golden."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = EmberTB(dut)
    await tb.reset()
    await tb.gsx_setup(1 << 24)                  # ztest enabled

    mata = cube.mvp_cube_words()
    await tb.gsx_load_matrix(mata)
    tris = cube_tri_inputs()

    # golden frame from the SAME GSX command stream (single source of truth)
    cmds = cube.cube_cmds(mata, 0, ztest=1)
    assert len(cmds) == 12, f"golden culled {12 - len(cmds)} cube tris"
    g = raster.Vram()
    for i in range(SCR_W * SCR_H):
        g.w16(ZBUF_BASE + i * 2, 0xFFFF)
    for words in cmds:
        raster.rasterize_triangle(g, cube._words_to_rtrcmd(words))

    # RTL frame: FB+Z pre-clear via DMA (VRAM persists across tests in one
    # sim build), 12 GSX kicks, one RTR sweep
    await tb.upload_words_dma(ZBUF_BASE, [0xFFFFFFFF] * (Z_BYTES // 4),
                              FENCE_TEX)
    await tb.upload_words_dma(FB0_BASE, [0] * (FB_BYTES // 4), FENCE_TEX)

    for v9, col in tris:
        await tb.gsx_load_vertex(v9, col)
        await tb.gsx_kick_wait()
    await tb.kick_and_wait(1)                    # rtr_busy = STATUS bit 1

    rtl_raw = await tb.dbg_read_region(FB0_BASE, FB_BYTES)
    mism = []
    for i in range(SCR_W * SCR_H):
        rtl_px = int.from_bytes(rtl_raw[2 * i:2 * i + 2], "little")
        gold_px = g.r16(FB0_BASE + i * 2)
        if rtl_px != gold_px:
            mism.append((i % SCR_W, i // SCR_W, rtl_px, gold_px))
    assert not mism, f"{len(mism)} pixel mismatches: " + ", ".join(
        f"({x},{y}) rtl={a:#06x} gold={b:#06x}" for x, y, a, b in mism[:8])

    # CI eyeball artifact: the RTL-rendered spinning cube
    lines = ["P3", f"{SCR_W} {SCR_H}", "255"]
    for y in range(SCR_H):
        row = []
        for x in range(SCR_W):
            p = int.from_bytes(rtl_raw[2 * (y * SCR_W + x):
                                       2 * (y * SCR_W + x) + 2], "little")
            row.append(f"{((p >> 11) & 0x1F) << 3} "
                       f"{((p >> 5) & 0x3F) << 2} {(p & 0x1F) << 3}")
        lines.append(" ".join(row))
    with open("cube_rtl.ppm", "w") as fh:
        fh.write("\n".join(lines) + "\n")
