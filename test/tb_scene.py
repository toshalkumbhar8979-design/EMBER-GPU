"""
tb_scene.py — Phase-7c textured 3D scene testbench: the "games" showcase.

Real software path (the full v1 graphics pipe):
  1. Upload the brick CLUT page to TEX_BASE via CP DMA.
  2. GSX: scene MVP, tex_en+ztest CFG, 8 textured triangles (back wall,
     floor, two flanking blocks — real per-pixel Z sorting, affine v1
     texturing), one kick per triangle, queue append mode.
  3. One RTR sweep over the emitted command queue.
  4. Compare the framebuffer BIT-EXACT against the golden frame from the
     SAME inputs (tools/golden/scene.py -> raster.rasterize_triangle).

Also writes scene_rtl.ppm (and PNG/HTML via the converter when run outside
cocotb) for eyeballing.

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

# ---------------------------------------------------------------- constants --
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
FENCE_SC = 4
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

    # ------------------------------------------------------------- GSX path --
    async def gsx_setup(self, mode_bits, tri_count=0):
        await self.reg_write(CP_GSX_CFG, mode_bits & 0x7FFFFFFF)
        await self.reg_write(CP_GSX_CFG, 0x80000000 | (tri_count & 0xFF))

    async def gsx_load_matrix(self, mata_words):
        for w in mata_words:
            await self.reg_write(CP_GSX_MATA, w & M32)

    async def gsx_load_vertex15(self, v15, col_word):
        """One textured triangle: 15 words (x,y,z,u,v x3) + 3 colors."""
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


# ------------------------------------------------------------------- test --
@cocotb.test()
async def test_scene_frame(dut):
    """Temple scene: 8 textured tris through GSX+RTR (real Z) vs golden.

    Runs the frame three times (tex+ztest / tex / ztest) — differential
    attribution if a flag combination breaks the pipe.
    """
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = EmberTB(dut)
    await tb.reset()

    mata = scene.mvp_scene_words()
    cmds, v15s = scene.scene_build(mata)
    assert len(cmds) == 8, f"golden culled tris: {len(cmds)} != 8"

    # texture page once (VRAM persists inside this test)
    page = scene.brick_texture()
    words = []
    for wi in range(TEX_BYTES // 4):
        words.append(page[4 * wi] | (page[4 * wi + 1] << 8)
                     | (page[4 * wi + 2] << 16) | (page[4 * wi + 3] << 24))
    await tb.upload_words_dma(TEX_BASE, words, FENCE_SC)
    # texture landed? sample 4 corners of the page
    t00 = await tb.dbg_read(TEX_BASE >> 2)
    t0f = await tb.dbg_read((TEX_BASE + 0x3FFC) >> 2)
    tf0 = await tb.dbg_read((TEX_BASE + 0xFF00) >> 2)
    tff = await tb.dbg_read((TEX_BASE + 0xFFFC) >> 2)
    print(f"DIAG: tex[0]={t00:#010x} tex[FFFC]={t0f:#010x} "
          f"tex[FF00]={tf0:#010x} tex[FFFC]={tff:#010x}")
    print(f"DIAG: golden tex[0]={words[0]:#010x} tex[FFFC]={words[0x3FFF]:#010x}")

    modes = (("tex+ztest", scene.CFG_SCENE),
             ("tex", 1 << 27),
             ("ztest", 1 << 24))
    for name, mode in modes:
        # golden frame for THIS mode (cmd word0 bits drive the golden ROP)
        g = raster.Vram()
        scene.scene_frame(g, mata, cfg=mode)

        await tb.upload_words_dma(ZBUF_BASE, [0xFFFFFFFF] * (Z_BYTES // 4),
                                  FENCE_SC)
        await tb.upload_words_dma(FB0_BASE, [0] * (FB_BYTES // 4), FENCE_SC)

        await tb.gsx_setup(mode)
        await tb.gsx_load_matrix(mata)
        for v15 in v15s:
            await tb.gsx_load_vertex15(v15, 0)
            await tb.gsx_kick_wait()
        await tb.kick_and_wait(1)                # rtr_busy = STATUS bit 1

        # emitted UV words vs golden (tri 0)
        cmdb = raster.CMDBUF_BASE
        rtl13 = await tb.dbg_read((cmdb + 13 * 4) >> 2)
        rtl14 = await tb.dbg_read((cmdb + 14 * 4) >> 2)
        rtl15 = await tb.dbg_read((cmdb + 15 * 4) >> 2)
        print(f"DIAG[{name}]: rtl uv13..15={rtl13:#010x},{rtl14:#010x},"
              f"{rtl15:#010x}  golden={cmds[0][13] & M32:#010x},"
              f"{cmds[0][14] & M32:#010x},{cmds[0][15] & M32:#010x}")

        rtl_raw = await tb.dbg_read_region(FB0_BASE, FB_BYTES)
        mism = []
        nnz = 0
        for i in range(SCR_W * SCR_H):
            rtl_px = int.from_bytes(rtl_raw[2 * i:2 * i + 2], "little")
            gold_px = g.r16(FB0_BASE + i * 2)
            if rtl_px:
                nnz += 1
            if rtl_px != gold_px:
                mism.append((i % SCR_W, i // SCR_W, rtl_px, gold_px))
        print(f"MODE {name:9s}: rtl_nonzero={nnz:6d} "
              f"mismatches={len(mism):6d}  ex={mism[:3]}")

        if name == "tex+ztest":
            # dump the TEX frame's queue for the C++ probe (BEFORE the
            # later modes overwrite it — the ztest frame has UVs=0!)
            cmdb = raster.CMDBUF_BASE
            qwords = [(await tb.dbg_read((cmdb + 4 * i) >> 2))
                      for i in range(8 * 19 + 1)]
            with open("scene_cmdq.txt", "w") as fh:
                for w in qwords:
                    fh.write(f"{w:08x}\n")
            print(f"DIAG: TEX-frame queue dumped ({len(qwords)} words), "
                  f"w0={qwords[0]:#010x} uv13={qwords[13]:#010x}")

        if name == "tex+ztest":
            # CI eyeball artifact from the FULL-config frame
            lines = ["P3", f"{SCR_W} {SCR_H}", "255"]
            for y in range(SCR_H):
                row = []
                for x in range(SCR_W):
                    p = int.from_bytes(
                        rtl_raw[2 * (y * SCR_W + x):
                                2 * (y * SCR_W + x) + 2], "little")
                    row.append(f"{((p >> 11) & 0x1F) << 3} "
                               f"{((p >> 5) & 0x3F) << 2} {(p & 0x1F) << 3}")
                lines.append(" ".join(row))
            with open("scene_rtl.ppm", "w") as fh:
                fh.write("\n".join(lines) + "\n")
            full_mism = mism

    # tex page dump for the C++ probe
    with open("scene_tex.txt", "w") as fh:
        for b in page:
            fh.write(f"{b:02x}\n")
    print(f"DIAG: tex page -> scene_tex.txt")

    # assert AFTER all modes ran + dumps landed (differential evidence first)
    assert not full_mism, f"{len(full_mism)} pixel mismatches: " + ", ".join(
        f"({x},{y}) rtl={a:#06x} gold={b:#06x}"
        for x, y, a, b in full_mism[:8])

    print("SCENE FRAME PASS: 8 textured tris, Z-sorted, bit-exact")
