"""
tb_fly.py — Phase-7g INTERACTIVE GAME LOOP: scripted camera fly-through
with a blitter HUD sprite, structural asserts (no golden pixel compares),
and a measured frame time vs the 33-ms / 30-fps budget.

Per frame (all on RTL):
  clear FB+Z -> gsx_setup (tri_count reset EVERY frame) -> load MVP ->
  8 textured tris -> one RTR sweep -> structural checks on the FB ->
  blit the HUD sprite (key transparency) -> sprite checks.

Structural asserts (the "no golden" contract — checks that any REAL
rendered game frame must pass):
  * >= 12 distinct RGB565 colors (the temple renders brick tones, not
    flat/black; the Phase-7c "black==black" lesson),
  * >= 20k non-background pixels (the scene actually covers the screen),
  * >= 100 distinct Z values (real depth, the 7c camera lesson),
  * every frame differs from the previous one (the camera MOVED),
  * after the HUD blit: the sprite region shows sprite colors and the
    key-colored pixels show background through (transparency worked).

Timing: cycle counts around the RTR sweep and around the HUD blit via
get_sim_time() deltas; frame budget = 33 ms at 50 MHz = 1.65M cycles
(the sim clock is 10 ns so ns/10 = cycles). PASS prints the measured
budget utilization.

Artifacts: fly_rtl_f<i>.ppm per frame + fly_html.py contact sheet.
"""
import os
import sys

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge
from cocotb.utils import get_sim_time

CLK_NS = 10
FRAME_BUDGET_PS = 33_000_000_000         # 33 ms at 30 fps, in PICOSECONDS
# (cocotb 2.1 get_sim_time() returns the simulator's raw time unit —
# VERILATOR'S PS. Measured: the RTR sweep delta was 6.131e9 ps = 613k
# cycles x 10 ns exactly. All timing math below is in ps.)

_GOLDEN_DIR = os.path.join(os.path.dirname(__file__), "..", "tools", "golden")
sys.path.insert(0, os.path.abspath(_GOLDEN_DIR))
import tex      # noqa: E402
import raster   # noqa: E402
import scene    # noqa: E402
import blit as gblit  # noqa: E402

CP_STATUS = 0x04
CP_FIFOD, CP_DMA_DST, CP_DMA_LEN, CP_CMDX = 0x10, 0x14, 0x18, 0x1C
CP_RTR_KICK = 0x20
CP_BLIT_CFG, CP_BLIT_DST, CP_BLIT_SRC, CP_BLIT_SIZE, CP_BLIT_KICK = \
    0x24, 0x28, 0x2C, 0x30, 0x34
CP_GSX_MATA, CP_GSX_VTX, CP_GSX_COL = 0x38, 0x3C, 0x40
CP_GSX_GO, CP_GSX_CFG = 0x44, 0x48

FB0_BASE = raster.FB0_BASE
ZBUF_BASE = raster.ZBUF_BASE
TEX_BASE = raster.TEX_BASE
SCR_W, SCR_H = raster.SCR_W, raster.SCR_H
FB_BYTES = SCR_W * SCR_H * 2
Z_BYTES = FB_BYTES
TEX_BYTES = 64 * 1024
FENCE_FLY = 8
M32 = 0xFFFFFFFF

SPRITE_OFF = 0x070000
# HUD slot sits ON THE BACK WALL (the wall spans ~x 100..235, y 54..186
# across the whole fly path) so the key-glass pixels show BRICK through —
# on the empty sky a transparency bug would be invisible (key 0x0000 ==
# background black).
HUD_X, HUD_Y = 128, 96
HUD_W, HUD_H = 32, 16


def hud_sprite():
    """32x16 RGB565 HUD panel: border + 3 'health' pips + key holes.
    Key color 0x0000 = transparent (background shows through)."""
    px = []
    for y in range(HUD_H):
        for x in range(HUD_W):
            edge = x in (0, HUD_W - 1) or y in (0, HUD_H - 1)
            pip = (6 <= y < 10 and (x - 3) % 10 < 7 and x < 30)
            if edge:
                px.append(0xFFFF)             # white frame
            elif pip:
                px.append(0x07E0)             # green pips
            else:
                px.append(0x0000)             # key: transparent glass
    return px


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

    async def blit(self, dst_off, src_off, w, h, key_en=0, key_color=0,
                   scale2=0):
        await self.reg_write(CP_BLIT_CFG,
                             ((scale2 & 1) << 30) | ((key_en & 1) << 29)
                             | (key_color & 0xFFFF))
        await self.reg_write(CP_BLIT_DST, dst_off)
        await self.reg_write(CP_BLIT_SRC, src_off)
        await self.reg_write(CP_BLIT_SIZE, ((h & 0xFF) << 16) | (w & 0xFF))
        await self.reg_write(CP_BLIT_KICK, 1)
        for _ in range(100000):
            await RisingEdge(self.dut.clk)
            if ((int(await self.reg_read(CP_STATUS)) >> 7) & 1) == 0:
                return
        raise AssertionError("blit never finished")


def halfword_words(pix, npix):
    words = []
    for wi in range(npix // 2):
        words.append((pix[2 * wi + 1] << 16) | pix[2 * wi])
    if npix % 2:
        words.append(pix[npix - 1])
    return words


def fb_pixels(tb):
    raw = tb_last_fb
    return raw


tb_last_fb = None


@cocotb.test()
async def test_fly_through(dut):
    """Scripted fly-through + HUD sprite + frame-time measurement."""
    global tb_last_fb
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = EmberTB(dut)
    await tb.reset()

    def now():
        return int(get_sim_time())          # ns (clock 10 ns)

    # ---- one-time uploads: texture page + HUD sprite --------------------
    page = scene.brick_texture()
    words = []
    for wi in range(TEX_BYTES // 4):
        words.append(page[4 * wi] | (page[4 * wi + 1] << 8)
                     | (page[4 * wi + 2] << 16) | (page[4 * wi + 3] << 24))
    await tb.upload_words_dma(TEX_BASE, words, FENCE_FLY)

    sprite = hud_sprite()
    await tb.upload_words_dma(SPRITE_OFF, halfword_words(sprite,
                                                         HUD_W * HUD_H),
                              FENCE_FLY)

    frames = scene.fly_frame_set(4)
    prev_fb = None
    timings = []
    for fi, (mata, cmds, v15s, (cam_x, cam_z)) in enumerate(frames):
        assert len(cmds) == 8, f"frame {fi}: culled tris"

        # clear FB+Z (structural test: no golden needed, just a clean slate)
        await tb.upload_words_dma(ZBUF_BASE, [0xFFFFFFFF] * (Z_BYTES // 4),
                                  FENCE_FLY)
        await tb.upload_words_dma(FB0_BASE, [0] * (FB_BYTES // 4), FENCE_FLY)

        # ---- geometry: GSX transform all 8 tris -------------------------
        await tb.gsx_setup(scene.CFG_SCENE)      # per frame: reset tri_count
        await tb.gsx_load_matrix(mata)
        for v15 in v15s:
            await tb.gsx_load_vertex15(v15, 0)
            await tb.gsx_kick_wait()

        # ---- RTR sweep, timed -------------------------------------------
        t0 = now()
        await tb.kick_and_wait(1)
        t1 = now()
        rtr_ps = t1 - t0

        # ---- structural checks (no golden) ------------------------------
        raw = await tb.dbg_read_region(FB0_BASE, FB_BYTES)
        tb_last_fb = raw
        px = [int.from_bytes(raw[2 * i:2 * i + 2], "little")
              for i in range(SCR_W * SCR_H)]
        distinct = len(set(px))
        nonbg = sum(1 for p in px if p != 0)
        assert distinct >= 12, \
            f"frame {fi}: only {distinct} distinct colors (black frame?)"
        assert nonbg >= 20000, \
            f"frame {fi}: only {nonbg} non-bg pixels (scene missing?)"
        zraw = await tb.dbg_read_region(ZBUF_BASE, Z_BYTES)
        zvals = {int.from_bytes(zraw[2 * i:2 * i + 2], "little")
                 for i in range(SCR_W * SCR_H)}
        zvals.discard(0xFFFF)
        assert len(zvals) >= 100, \
            f"frame {fi}: only {len(zvals)} distinct Z values (no depth)"
        assert prev_fb is None or raw != prev_fb, \
            f"frame {fi}: identical to previous frame (camera did not move)"
        prev_fb = raw

        # ---- HUD sprite via the BLITTER, timed --------------------------
        dst = 2 * (HUD_Y * SCR_W + HUD_X)
        t2 = now()
        await tb.blit(dst, SPRITE_OFF, HUD_W, HUD_H, key_en=1, key_color=0)
        t3 = now()
        blit_ps = t3 - t2

        raw2 = await tb.dbg_read_region(FB0_BASE, FB_BYTES)
        px2 = [int.from_bytes(raw2[2 * i:2 * i + 2], "little")
               for i in range(SCR_W * SCR_H)]
        # sprite region must contain the sprite's border color AND the
        # background must show through the key holes
        region = [px2[(HUD_Y + sy) * SCR_W + HUD_X + sx]
                  for sy in range(HUD_H) for sx in range(HUD_W)]
        assert 0xFFFF in region, f"frame {fi}: HUD border missing"
        assert any(p != 0xFFFF and p != 0x0000 and p != 0x07E0
                   for p in region), \
            f"frame {fi}: HUD shows no scene-through-glass pixels"
        frame_px_before = px                        # pre-blit snapshot
        for sy in range(HUD_H):
            for sx in range(HUD_W):
                if sprite[HUD_W * sy + sx] == 0x0000:
                    bg_px = frame_px_before[(HUD_Y + sy) * SCR_W
                                            + HUD_X + sx]
                    got = px2[(HUD_Y + sy) * SCR_W + HUD_X + sx]
                    assert got == bg_px, \
                        (f"frame {fi}: key hole ({sx},{sy}) shows "
                         f"{got:#06x}, expected background {bg_px:#06x}")

        # ---- frame timing -----------------------------------------------
        frame_ps = rtr_ps + blit_ps        # geometry overlaps the sweep
        timings.append((fi, rtr_ps, blit_ps, frame_ps))
        print(f"frame {fi} cam=({cam_x:.3f},{cam_z:.2f}): "
              f"distinct={distinct} nonbg={nonbg} zvals={len(zvals)} | "
              f"rtr {rtr_ps / 1e6:.0f} us "
              f"({rtr_ps / 1e4 / 1000:.0f}k cycles), "
              f"blit {blit_ps / 1e6:.1f} us "
              f"({blit_ps / 1e4:.0f} cycles), "
              f"frame {frame_ps / 1e9:.3f} ms "
              f"({100.0 * frame_ps / FRAME_BUDGET_PS:.1f}% of budget)",
              flush=True)

        # artifact
        lines = ["P3", f"{SCR_W} {SCR_H}", "255"]
        for y in range(SCR_H):
            row = []
            for x in range(SCR_W):
                p = int.from_bytes(raw2[2 * (y * SCR_W + x):
                                        2 * (y * SCR_W + x) + 2], "little")
                row.append(f"{((p >> 11) & 0x1F) << 3} "
                           f"{((p >> 5) & 0x3F) << 2} {(p & 0x1F) << 3}")
            lines.append(" ".join(row))
        with open(f"fly_rtl_f{fi}.ppm", "w") as fh:
            fh.write("\n".join(lines) + "\n")

    worst = max(t for _, _, _, t in timings)
    print(f"FLY PASS: 4 frames, structural asserts OK; worst frame "
          f"{worst / 1e9:.3f} ms = {100.0 * worst / FRAME_BUDGET_PS:.1f}% "
          f"of the 33-ms/30-fps budget")
