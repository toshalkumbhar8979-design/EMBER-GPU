"""
tb_rtr.py — Phase-2 cocotb testbench: RTR pixel pipe vs golden model.

Drives the REAL software path end to end:
  1. Build command words from the golden model's triangle IR (same objects the
     golden rasterizer consumes -> one source of truth).
  2. Upload texture + z-clear + command queue through the CP (DMA + FIFO).
  3. Kick the RTR via CP_RTR_KICK, wait for CP_STATUS.rtr_busy=0.
  4. Dump FB0 through the dbg sidecar and compare per-pixel, bit-exact,
     against tools/golden/raster.py.

Covers: solid Gouraud gradient, z-test ordering, texture mapping, and the
full ROP chain (blend 50% + dither + rgbmap) — the same four golden smoke
scenarios.
"""

import os
import sys

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge

CLK_NS = 10

# golden model import (repo-relative)
_GOLDEN_DIR = os.path.join(os.path.dirname(__file__), "..", "tools", "golden")
sys.path.insert(0, os.path.abspath(_GOLDEN_DIR))
import raster as golden  # noqa: E402  (path set above)

# ---------------------------------------------------------------- constants --
CP_ID, CP_STATUS, CP_CTRL, CP_FENCE = 0x00, 0x04, 0x08, 0x0C
CP_FIFOD, CP_DMA_DST, CP_DMA_LEN, CP_CMDX = 0x10, 0x14, 0x18, 0x1C
CP_RTR_KICK = 0x20

VRAM_BASE = 0x1000                      # bus base of the VRAM window
FB0_BASE  = golden.FB0_BASE             # 0x000000 (VRAM offset)
ZBUF_BASE = golden.ZBUF_BASE            # 0x025800
TEX_BASE  = golden.TEX_BASE             # 0x038400
CMDQ_OFF  = golden.CMDBUF_BASE          # 0x048400

SCR_W, SCR_H = golden.SCR_W, golden.SCR_H
FB_BYTES = SCR_W * SCR_H * 2
Z_BYTES = FB_BYTES
TEX_BYTES = 64 * 1024

RTR_CMD_WORDS = 19
FENCE_TEX, FENCE_CMD = 3, 4


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

    async def dbg_write(self, word_addr, data):
        d = self.dut
        d.dbg_en.value = 1
        d.dbg_addr.value = word_addr
        d.dbg_wdata.value = data
        d.dbg_be.value = 0xF
        await RisingEdge(d.clk)
        d.dbg_en.value = 0

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

    async def wait_fence(self, fence_id, timeout=2000):
        for _ in range(timeout):
            await RisingEdge(self.dut.clk)
            if await self.reg_read(CP_FENCE) == fence_id:
                return
        raise AssertionError(f"fence {fence_id} never reached")

    async def wait_dma_idle(self, timeout=100000):
        """Wait until the CP DMA engine is idle (STATUS[0]==0).

        This is race-free for back-to-back DMAs; polling a REUSED fence id is
        NOT (the old fence value satisfies the poll before the new transfer
        even starts, letting the TB re-program the engine mid-flight).
        """
        for _ in range(timeout):
            await RisingEdge(self.dut.clk)
            status = await self.reg_read(CP_STATUS)
            if (status & 1) == 0:
                return
        raise AssertionError("DMA never went idle")

    # ------------------------------------------------------------ VRAM path --
    async def vram_word_write(self, byte_off, word):
        """32-bit bus write into VRAM (byte_off is a VRAM OFFSET, word aligned)."""
        await self.reg_write(VRAM_BASE + byte_off, word & 0xFFFFFFFF)

    async def upload_words_dma(self, byte_off, words, fence, chunk=60):
        """Bulk upload via the CP DMA engine (FIFO -> VRAM).

        The upload FIFO is only 64 deep and drops pushes while full, so bulk
        transfers are chunked: push <=60 words, DMA them, then continue.
        Completion is detected via STATUS.dma_busy (NOT a reused fence id —
        see wait_dma_idle).
        """
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
            status = await self.reg_read(CP_STATUS)
            if (status >> 1) & 1 == 0:      # rtr_busy bit
                return
        raise AssertionError("RTR never went idle (rtr_busy stuck high)")

    async def clear_fb(self):
        """Zero FB0 via DMA (each test starts from a black frame)."""
        await tb_upload_zero(self, FB0_BASE, FB_BYTES)

    async def dbg_read_region(self, byte_off, nbytes):
        out = bytearray()
        for w in range(nbytes // 4):
            out += (await self.dbg_read((byte_off >> 2) + w)).to_bytes(
                4, "little")
        return out

    async def read_fb_pixels(self):
        """Return FB0 as a list of 16-bit pixels, index = y*SCR_W + x."""
        raw = await self.dbg_read_region(FB0_BASE, FB_BYTES)
        return [raw[i] | (raw[i + 1] << 8) for i in range(0, len(raw), 2)]


# ------------------------------------------------------------- cmd packing --
def tri_cmd_words(cmd, texpage=0):
    """Pack a golden RtrCmd into the RTL 19-word command format."""
    tri = cmd.tri
    tex_any = tri.v0.tex_en or tri.v1.tex_en or tri.v2.tex_en
    assert (tri.v0.tex_en == tri.v1.tex_en == tri.v2.tex_en) or not tex_any, \
        "TB contract: all three vertices share tex_en (RTL flag is per-tri)"

    w = [0] * RTR_CMD_WORDS
    w[0] = (1
            | ((cmd.blend & 1) << 1)
            | ((cmd.ztest & 1) << 2)
            | ((1 if tex_any else 0) << 3)
            | ((cmd.dbg_dither & 1) << 4)
            | ((cmd.dbg_rgbmap & 1) << 5)
            | ((texpage & 0xFF) << 8))
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


async def load_texture(tb, ramp=None):
    """Upload the 64 KB CLUT texture (4 texel bytes per 32-bit word)."""
    if ramp is None:
        ramp = bytes(min(255, ((t & 0xFF) + (t >> 8)) // 2)
                     for t in range(TEX_BYTES))
    words = []
    for wi in range(TEX_BYTES // 4):
        words.append(ramp[4 * wi] | (ramp[4 * wi + 1] << 8)
                     | (ramp[4 * wi + 2] << 16) | (ramp[4 * wi + 3] << 24))
    await tb.upload_words_dma(TEX_BASE, words, FENCE_TEX)
    return ramp


def z_clear_words():
    """Z pre-clear pattern: 0xFFFF = farthest (LESS passes).
    Byte-packed pixels -> every halfword of every word is 0xFFFF."""
    return [0xFFFFFFFF] * (Z_BYTES // 4)


def zero_words(nbytes):
    return [0] * (nbytes // 4)


def halfword_words(pix, npix):
    """Pack a per-pixel 16-bit value into 32-bit words (byte-packed FB):
    word = {pixel(odd x), pixel(even x)} little-endian."""
    words = []
    for wi in range(npix // 2):
        words.append((pix[2 * wi + 1] << 16) | pix[2 * wi])
    return words


async def tb_upload_zero(tb, byte_off, nbytes):
    await tb.upload_words_dma(byte_off, zero_words(nbytes), FENCE_TEX)


async def run_commands(tb, cmds):
    """Upload a 0-terminated command queue, kick the RTR, wait for done."""
    words = []
    for c in cmds:
        words += tri_cmd_words(c)
    words.append(0)  # tri_valid=0 terminator
    await tb.upload_words_dma(CMDQ_OFF, words, FENCE_CMD)

    # verify the queue actually landed (dbg sidecar, independent of bus)
    w0 = await tb.dbg_read((CMDQ_OFF >> 2))
    term = await tb.dbg_read((CMDQ_OFF >> 2) + len(words) - 1)
    assert w0 & 1, f"cmd word0 in VRAM lacks tri_valid: {w0:#010x}"
    assert term == 0, f"cmd terminator wrong: {term:#010x}"

    await tb.kick_and_wait()


async def compare_fb(tb, golden_vram, name):
    """Per-pixel compare RTL FB0 vs golden; dump PPMs; report mismatches."""
    rtl_px = await tb.read_fb_pixels()
    mismatches = []
    for i in range(SCR_W * SCR_H):
        g = golden_vram.r16(FB0_BASE + i * 2)
        if rtl_px[i] != g:
            mismatches.append((i % SCR_W, i // SCR_W, rtl_px[i], g))
    if mismatches:
        lines = [f"{name}: {len(mismatches)} pixel mismatches"]
        for (x, y, r, g) in mismatches[:20]:
            lines.append(f"  ({x:3d},{y:3d}) rtl={r:#06x} golden={g:#06x}")
        raise AssertionError("\n".join(lines))


async def probe_rtr(dut):
    """Snapshot internal RTR state for debugging (public_flat_rw)."""
    u_rtr = dut.u_rtr
    u_scan = u_rtr.u_scan
    return {
        "fst": int(u_rtr.fst.value),
        "cursor": int(u_rtr.cursor.value),
        "fidx": int(u_rtr.fidx.value),
        "cmd0": int(u_rtr.cmd_q[0].value),
        "cmd1": int(u_rtr.cmd_q[1].value),
        "cmd19": int(u_rtr.cmd_q[18].value),
        "scan_st": int(u_scan.st.value),
        "scan_busy": int(u_scan.busy.value),
        "scan_done": int(u_scan.done.value),
        "cull": int(u_rtr.cull.value),
        "x_lo": int(u_rtr.x_lo_i.value),
        "x_hi": int(u_rtr.x_hi_i.value),
        "ix": int(u_scan.ix.value),
        "iy": int(u_scan.iy.value),
    }


async def probe_fpa_writes(dut, ncycles=6000):
    """Sample the scan engine cycle-by-cycle while busy: every fpa write it
    emits (first 12), plus a state histogram, busy count, and whether the
    write actually reaches the VRAM port (mux check)."""
    u_scan = dut.u_rtr.u_scan
    u_vram = dut.u_vram
    writes = []
    busy_cycles = 0
    st_hist = {}
    mux_mismatch = 0
    for _ in range(ncycles):
        await RisingEdge(dut.clk)
        st = int(u_scan.st.value)
        st_hist[st] = st_hist.get(st, 0) + 1
        if int(u_scan.busy.value):
            busy_cycles += 1
        we_s = int(u_scan.fpa_we.value)
        we_v = int(u_vram.fpa_we.value)
        if we_s != we_v:
            mux_mismatch += 1
        if we_s:
            def s96(name):
                v = int(getattr(u_scan, name).value)
                return (v - (1 << 96)) if v >= (1 << 95) else v
            writes.append((st, int(u_scan.fpa_addr.value),
                           int(u_scan.fpa_be.value),
                           int(u_scan.fpa_wdata.value) & 0xFFFF,
                           int(u_scan.ix.value), int(u_scan.iy.value),
                           int(u_scan.cr.value),
                           s96("r_v") >> 22, s96("g_v") >> 22,
                           s96("inv_w_v") >> 22))
            if len(writes) >= 40:
                break
    return writes, busy_cycles, st_hist, mux_mismatch


# ----------------------------------------------------------------- helpers --
def smoke_triangle1():
    v0 = golden.Vtx(x=(20 << 22), y=(20 << 22), z=1000, r=255, g=0, b=0)
    v1 = golden.Vtx(x=(300 << 22), y=(40 << 22), z=1000, r=0, g=255, b=0)
    v2 = golden.Vtx(x=(100 << 22), y=(220 << 22), z=1000, r=0, g=0, b=255)
    return golden.RtrCmd(tri=golden.Tri(v0, v1, v2))


def smoke_textured_quad():
    q = 22
    vt0 = golden.Vtx(x=(40 << q), y=(140 << q), z=500, r=0, g=0, b=0,
                     u=0, v=0, tex_en=1)
    vt1 = golden.Vtx(x=(120 << q), y=(140 << q), z=500, r=0, g=0, b=0,
                     u=(255 << q), v=0, tex_en=1)
    vt2 = golden.Vtx(x=(120 << q), y=(220 << q), z=500, r=0, g=0, b=0,
                     u=(255 << q), v=(255 << q), tex_en=1)
    vt3 = golden.Vtx(x=(40 << q), y=(220 << q), z=500, r=0, g=0, b=0,
                     u=0, v=(255 << q), tex_en=1)
    return (golden.RtrCmd(tri=golden.Tri(vt0, vt1, vt2)),
            golden.RtrCmd(tri=golden.Tri(vt0, vt2, vt3)))


def smoke_z_pair():
    far = golden.RtrCmd(tri=golden.Tri(
        golden.Vtx(x=(150 << 22), y=(20 << 22), z=200, r=255, g=0, b=255),
        golden.Vtx(x=(310 << 22), y=(20 << 22), z=200, r=255, g=0, b=255),
        golden.Vtx(x=(230 << 22), y=(200 << 22), z=200, r=255, g=0, b=255)),
        ztest=1)
    near = golden.RtrCmd(tri=golden.Tri(
        golden.Vtx(x=(150 << 22), y=(20 << 22), z=100, r=255, g=255, b=0),
        golden.Vtx(x=(310 << 22), y=(20 << 22), z=100, r=255, g=255, b=0),
        golden.Vtx(x=(230 << 22), y=(200 << 22), z=100, r=255, g=255, b=0)),
        ztest=1)
    return far, near


# ------------------------------------------------------------------ tests --
@cocotb.test()
async def test_rtr_solid_gradient(dut):
    """Golden tri 1: Gouraud gradient, no z, no tex."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = EmberTB(dut)
    await tb.reset()
    await tb.clear_fb()      # VRAM persists across tests in one sim build

    cmd = smoke_triangle1()
    g = golden.Vram()
    golden.rasterize_triangle(g, cmd)

    await run_commands(tb, [cmd])
    await compare_fb(tb, g, "solid_gradient")


@cocotb.test()
async def test_rtr_textured_quad(dut):
    """Golden tris 2+3: perspective-correct texture map over a quad."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = EmberTB(dut)
    await tb.reset()
    await tb.clear_fb()

    ramp = await load_texture(tb)
    cmd_t1, cmd_t2 = smoke_textured_quad()

    g = golden.Vram()
    for t in range(TEX_BYTES):
        g.w8(TEX_BASE + t, ramp[t])
    golden.rasterize_triangle(g, cmd_t1)
    golden.rasterize_triangle(g, cmd_t2)

    await run_commands(tb, [cmd_t1, cmd_t2])
    await compare_fb(tb, g, "textured_quad")


@cocotb.test()
async def test_rtr_ztest_ordering(dut):
    """Golden tris 4+5: near triangle must win through the z-buffer."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = EmberTB(dut)
    await tb.reset()
    await tb.clear_fb()

    far, near = smoke_z_pair()
    g = golden.Vram()
    # software convention: z pre-cleared to 0xFFFF so LESS passes everything
    for i in range(SCR_W * SCR_H):
        g.w16(ZBUF_BASE + i * 2, 0xFFFF)
    golden.rasterize_triangle(g, far)
    golden.rasterize_triangle(g, near)

    await tb.upload_words_dma(ZBUF_BASE, z_clear_words(), FENCE_TEX)
    await run_commands(tb, [far, near])
    await compare_fb(tb, g, "ztest_ordering")


@cocotb.test()
async def test_rtr_full_rop_chain(dut):
    """Blend + dither + rgbmap all enabled — full ROP ordering vs golden."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = EmberTB(dut)
    await tb.reset()
    await tb.clear_fb()

    base = smoke_triangle1()
    cmd = golden.RtrCmd(tri=base.tri, blend=1, ztest=0,
                        dbg_dither=1, dbg_rgbmap=1)

    g = golden.Vram()
    # golden blend averages against FB contents; pre-fill with a known pattern
    for i in range(SCR_W * SCR_H):
        g.w16(FB0_BASE + i * 2, 0x39E7)          # mid gray 0x73,0x79,0x73
    golden.rasterize_triangle(g, cmd)

    # RTL: pre-fill its FB with the same pattern via DMA
    pat = [0x39E7] * (SCR_W * SCR_H)
    await tb.upload_words_dma(FB0_BASE, halfword_words(pat, SCR_W * SCR_H),
                              FENCE_TEX)
    await run_commands(tb, [cmd])
    await compare_fb(tb, g, "full_rop_chain")
