"""
tb_chip.py — cocotb testbench for the FULL Ember chip (rtl/ember_chip.sv) on
a simulated board (test/chip_tb.sv): pad ring + die + ember_memif + three
board-mounted SRAMs.

Everything happens through the physical chip pins — the debug sidecar is not
bonded out on this chip, so all readback goes through the host AXI pads like
real software would:

  1. Reset through the xres pad; CP ID/STATUS through host pads
  2. VRAM write/read round trip through pads + external SRAM channels
  3. Real workload: matadd kernel via CP DMA + core kick while the display
     free-runs — CH0 (scanout), CH1 (core stores), CH2 (fetch + host) all
     active against the external memory pins at once
  4. Video pads: capture the first active pixels of a frame from
     vid_hs/vid_vs/vid_de/vid_pixel and verify the 2x2 double-scan mapping

Run:  make -f Makefile.chip test   (from test/, with run_cocotb.sh's env)
"""

import os
import sys

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge

CLK_NS = 10  # 100 MHz

_TOOLS_DIR = os.path.join(os.path.dirname(__file__), "..", "tools")
sys.path.insert(0, os.path.abspath(_TOOLS_DIR))
import assembler  # noqa: E402

# CP register offsets (mirror tb_memory/tb_core)
CP_ID, CP_STATUS, CP_CTRL, CP_FENCE = 0x00, 0x04, 0x08, 0x0C
CP_FIFOD, CP_DMA_DST, CP_DMA_LEN, CP_CMDX = 0x10, 0x14, 0x18, 0x1C
CP_RTR_KICK = 0x20
CP_CORE_CODE, CP_CORE_NBLK, CP_CORE_KICK = 0x4C, 0x50, 0x54

VRAM_BASE = 0x1000
CMDBUF_OFF = 0x5B000
CODEBUF_OFF = CMDBUF_OFF + 0x400

NT = 4
FENCE_PARAMS, FENCE_CODE = 6, 7
KICK_TIMEOUT = 8_000_000
M32 = 0xFFFFFFFF


class AxiLiteDriver:
    """Minimal AXI4-Lite master on the chip's host pads."""

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


class ChipTB:
    def __init__(self, dut):
        self.dut = dut
        self.axi = AxiLiteDriver(dut)

    async def reset(self):
        """Reset through the chip's xres pad (reset_n pin)."""
        d = self.dut
        d.reset_n.value = 0
        d.fb_select.value = 0
        d.h_awvalid.value = 0
        d.h_wvalid.value = 0
        d.h_arvalid.value = 0
        d.h_bready.value = 0
        d.h_rready.value = 0
        await RisingEdge(d.clk)
        await RisingEdge(d.clk)
        d.reset_n.value = 1
        await RisingEdge(d.clk)

    async def reg_write(self, addr, data, strb=0xF):
        await self.axi.write(addr, data, strb=strb)

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

    async def read_words_bus(self, byte_off, nwords):
        """Readback through the host pads (no debug sidecar on this chip)."""
        return [await self.reg_read(VRAM_BASE + byte_off + 4 * i) & M32
                for i in range(nwords)]

    async def run_kernel(self, asm_path, nblk=1, params=None):
        with open(asm_path) as fh:
            words = assembler.run_assembler(fh.read())
        if params is None:
            params = []
        await self.upload_words_dma(CMDBUF_OFF, params, FENCE_PARAMS)
        await self.upload_words_dma(CODEBUF_OFF, words, FENCE_CODE)
        await self.reg_write(CP_CORE_CODE, CODEBUF_OFF)
        await self.reg_write(CP_CORE_NBLK, nblk)
        await self.reg_write(CP_CORE_KICK, 1)
        for _ in range(KICK_TIMEOUT):
            await RisingEdge(self.dut.clk)
            if ((await self.reg_read(CP_STATUS)) >> 9) & 1 == 0:
                return words
        raise AssertionError(f"core_busy stuck high for {asm_path}")


@cocotb.test()
async def test_chip_reset_and_id(dut):
    """Reset through the xres pad, CP identity through the host pads."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = ChipTB(dut)
    await tb.reset()

    val = await tb.reg_read(CP_ID)
    assert val == 0xEB220002, f"CP_ID mismatch through pads: {val:#x}"

    status = await tb.reg_read(CP_STATUS)
    assert status & 1 == 0, "dma_busy should be 0 after pad reset"
    assert (status >> 9) & 1 == 0, "core_busy should be 0 after pad reset"


@cocotb.test()
async def test_chip_vram_roundtrip(dut):
    """Host VRAM write/read through the pads and the external SRAM channels,
    including byte strobes and a window pattern."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = ChipTB(dut)
    await tb.reset()

    await tb.reg_write(VRAM_BASE + 0x40, 0xDEADBEEF)
    await tb.reg_write(VRAM_BASE + 0x44, 0x12345678)
    v0 = await tb.reg_read(VRAM_BASE + 0x40)
    v1 = await tb.reg_read(VRAM_BASE + 0x44)
    assert v0 == 0xDEADBEEF, f"VRAM roundtrip mismatch: {v0:#x}"
    assert v1 == 0x12345678, f"VRAM roundtrip mismatch: {v1:#x}"

    # byte strobes through the pad-level write bus: strb=0x3 enables byte
    # lanes 0..1 (low halfword), same semantics as tb_memif.test_byte_enables
    await tb.reg_write(VRAM_BASE + 0x40, 0xFFFFFFFF, strb=0x3)
    v = await tb.reg_read(VRAM_BASE + 0x40)
    assert v == 0xDEADFFFF, f"strb=0x3 write through pads got {v:#x}"
    await tb.reg_write(VRAM_BASE + 0x40, 0x11223344, strb=0xC)
    v = await tb.reg_read(VRAM_BASE + 0x40)
    assert v == 0x1122FFFF, f"strb=0xC write through pads got {v:#x}"

    # stride pattern over external SRAM words
    base = 0x2000
    for i in range(16):
        await tb.reg_write(VRAM_BASE + base + 4 * i, 0xA5000000 + i)
    got = await tb.read_words_bus(base, 16)
    bad = [i for i in range(16) if got[i] != 0xA5000000 + i]
    assert not bad, f"stride pattern mismatches at {bad}: {[hex(got[i]) for i in bad]}"


@cocotb.test()
async def test_chip_core_kernel(dut):
    """matadd through the real software path on real pins: DMA upload, core
    kick, results via host readback. The display free-runs throughout, so
    CH0 scanout + CH1 core stores + CH2 fetch/host traffic hit the external
    memory pins concurrently."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = ChipTB(dut)
    await tb.reset()

    n = NT * 32
    a_words = [i for i in range(n)]
    b_words = [2 * i for i in range(n)]
    a_off, b_off = 0x59000, 0x59800
    await tb.upload_words_dma(a_off, a_words, 4)
    await tb.upload_words_dma(b_off, b_words, 5)

    await tb.run_kernel(os.path.join(os.path.dirname(__file__),
                                     "..", "kernels", "matadd.asm"),
                        nblk=1, params=[a_off, b_off])

    got = await tb.read_words_bus(a_off, n)
    bad = [(i, got[i], (3 * i) & M32)
           for i in range(n) if got[i] != (3 * i) & M32]
    assert not bad, f"{len(bad)} matadd mismatches through pads: {bad[:8]}"


@cocotb.test()
async def test_chip_video_pads(dut):
    """Video output through the pads: DMA a known pattern into FB0, capture
    the first active pixels of the next frame from vid_de/vid_pixel and check
    the 2x2 double-scan mapping (output X,Y -> FB(Y>>1, X>>1))."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = ChipTB(dut)
    await tb.reset()

    # FB0 row 0 words 0..3 (byte offsets 0..15 in VRAM): distinct halfwords
    pattern = [0xBBBBAAAA, 0xDDDDCCCC, 0xFFFFEEEE, 0x11110000]
    for i, w in enumerate(pattern):
        await tb.reg_write(VRAM_BASE + 4 * i, w)

    d = dut
    # wait for the frame that contains the pattern (vsync pulse then active)
    await RisingEdge(d.vid_vs)
    for _ in range(2000):
        await RisingEdge(d.clk)
        if int(d.vid_vs.value) == 0:
            break

    # capture the first 8 active pixels of the first active line
    got = []
    for _ in range(800 * 525):
        await FallingEdge(d.clk)      # sample outputs settled
        if int(d.vid_de.value) == 1:
            got.append(int(d.vid_pixel.value))
            if len(got) == 8:
                break
    assert len(got) == 8, f"only captured {len(got)} active pixels"

    # output pixels 0..7 of line 0 -> FB(0, X>>1): each word's halfword
    # repeats twice (double scan in x): [lo, lo, hi, hi] per word
    want = []
    for w in pattern[:2]:
        want += [w & 0xFFFF, w & 0xFFFF, w >> 16, w >> 16]
    bad = [(i, got[i], want[i]) for i in range(8) if got[i] != want[i]]
    assert not bad, f"video pad mismatches: {bad}"

    # sync pads must carry the real 640x480@60 rhythm: hsync period = 800
    # pixel clocks. Measure two consecutive falling edges; the second gap is
    # a full line period regardless of where the first sample lands.
    async def hs_fall_cycles(max_cycles=2000):
        prev = int(d.vid_hs.value)
        for i in range(max_cycles):
            await RisingEdge(d.clk)
            hs = int(d.vid_hs.value)
            if prev == 1 and hs == 0:
                return i + 1
            prev = hs
        raise AssertionError("no vid_hs falling edge within %d cycles"
                             % max_cycles)

    await hs_fall_cycles()                 # land on an edge
    period = await hs_fall_cycles()
    assert period == 800, f"vid_hs period {period} pixel clocks, want 800"
