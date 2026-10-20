"""
tb_anim.py — Phase-7e scene ANIMATION: the first real "game loop".

4 orbit frames (camera rotating about the temple in 15 deg steps), each
frame driven through the full RTL pipe:
  clear FB+Z -> GSX load matrix + 8 textured tris -> one RTR sweep ->
  bit-exact compare vs the golden frame.

Artifacts: anim_rtl_f<i>.ppm per frame (PPM->PNG->HTML via
tools/golden/ppm_png.py for eyeballing).

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
import scene    # noqa: E402

CP_STATUS = 0x04
CP_FIFOD, CP_DMA_DST, CP_DMA_LEN, CP_CMDX = 0x10, 0x14, 0x18, 0x1C
CP_RTR_KICK = 0x20
CP_GSX_MATA, CP_GSX_VTX, CP_GSX_COL = 0x38, 0x3C, 0x40
CP_GSX_GO, CP_GSX_CFG = 0x44, 0x48

FB0_BASE = raster.FB0_BASE
ZBUF_BASE = raster.ZBUF_BASE
TEX_BASE = raster.TEX_BASE
SCR_W, SCR_H = raster.SCR_W, raster.SCR_H
FB_BYTES = SCR_W * SCR_H * 2
Z_BYTES = FB_BYTES
TEX_BYTES = 64 * 1024
FENCE_AN = 8
M32 = 0xFFFFFFFF


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

    async def dbg_read_region(self, byte_off, nbytes):
        out = bytearray()
        for w in range(nbytes // 4):
            out += (await self.dbg_read((byte_off >> 2) + w)).to_bytes(
                4, "little")
        return out

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

    async def kick_and_wait(self, bit, timeout=8_000_000):
        await self.reg_write(CP_RTR_KICK, 1)
        for _ in range(timeout):
            await RisingEdge(self.dut.clk)
            status = await self.reg_read(CP_STATUS)
            if (status >> bit) & 1 == 0:
                return
        raise AssertionError(f"STATUS bit {bit} never went idle")

    async def gsx_setup(self, mode_bits):
        await self.reg_write(CP_GSX_CFG, mode_bits & 0x7FFFFFFF)
        await self.reg_write(CP_GSX_CFG, 0x80000000)     # append mode

    async def gsx_load_matrix(self, mata_words):
        for w in mata_words:
            await self.reg_write(CP_GSX_MATA, w & M32)

    async def gsx_load_vertex15(self, v15, col_word):
        for w in v15:
            await self.reg_write(CP_GSX_VTX, w & M32)
        for _ in range(3):
            await self.reg_write(CP_GSX_COL, col_word & 0x00FFFFFF)

    async def gsx_kick_wait(self, timeout=40000):
        await self.reg_write(CP_GSX_GO, 1)
        for _ in range(timeout):
            await RisingEdge(self.dut.clk)
            if (await self.reg_read(CP_STATUS) >> 8) & 1 == 0:
                return
        raise AssertionError("gsx_busy stuck high")


@cocotb.test()
async def test_anim_frames(dut):
    """4 orbit frames through GSX+RTR, each bit-exact vs golden."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = EmberTB(dut)
    await tb.reset()

    # texture page once
    page = scene.brick_texture()
    words = []
    for wi in range(TEX_BYTES // 4):
        words.append(page[4 * wi] | (page[4 * wi + 1] << 8)
                     | (page[4 * wi + 2] << 16) | (page[4 * wi + 3] << 24))
    await tb.upload_words_dma(TEX_BASE, words, FENCE_AN)

    # NOTE: gsx_setup is called PER FRAME below — it resets tri_count to 0
    # (append-at-slot-0). Called once here, frame 2's emits would append at
    # slot 8 and the RTR would sweep BOTH frames' triangles (frame 1 fails
    # with stale-geometry mismatches — exactly what the first run showed).

    frames = scene.spin_frame_set(4)
    for fi, (mata, cmds, v15s) in enumerate(frames):
        assert len(cmds) == 8, f"frame {fi}: culled tris"

        g = raster.Vram()
        scene.scene_frame(g, mata)               # golden frame (same inputs)

        await tb.upload_words_dma(ZBUF_BASE, [0xFFFFFFFF] * (Z_BYTES // 4),
                                  FENCE_AN)
        await tb.upload_words_dma(FB0_BASE, [0] * (FB_BYTES // 4), FENCE_AN)

        await tb.gsx_setup(scene.CFG_SCENE)      # per frame: reset tri_count
        await tb.gsx_load_matrix(mata)
        for v15 in v15s:
            await tb.gsx_load_vertex15(v15, 0)
            await tb.gsx_kick_wait()
        await tb.kick_and_wait(1)

        rtl_raw = await tb.dbg_read_region(FB0_BASE, FB_BYTES)
        mism = []
        for i in range(SCR_W * SCR_H):
            rtl_px = int.from_bytes(rtl_raw[2 * i:2 * i + 2], "little")
            gold_px = g.r16(FB0_BASE + i * 2)
            if rtl_px != gold_px:
                mism.append((i % SCR_W, i // SCR_W, rtl_px, gold_px))
        print(f"frame {fi}: {len(mism)} mismatches")
        assert not mism, f"frame {fi}: {len(mism)} pixel mismatches: " + \
            ", ".join(f"({x},{y}) rtl={a:#06x} gold={b:#06x}"
                      for x, y, a, b in mism[:6])

        # artifact
        lines = ["P3", f"{SCR_W} {SCR_H}", "255"]
        for y in range(SCR_H):
            row = []
            for x in range(SCR_W):
                p = int.from_bytes(rtl_raw[2 * (y * SCR_W + x):
                                           2 * (y * SCR_W + x) + 2], "little")
                row.append(f"{((p >> 11) & 0x1F) << 3} "
                           f"{((p >> 5) & 0x3F) << 2} {(p & 0x1F) << 3}")
            lines.append(" ".join(row))
        with open(f"anim_rtl_f{fi}.ppm", "w") as fh:
            fh.write("\n".join(lines) + "\n")

    print("ANIM PASS: 4 orbit frames, all bit-exact (game loop proven)")
