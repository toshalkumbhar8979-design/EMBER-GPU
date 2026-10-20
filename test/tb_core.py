"""
tb_core.py — Phase-5 cocotb testbench: compute core vs golden kernels.

Drives the REAL software path end to end:
  1. Assemble kernels/*.asm with tools/assembler.py (the production tool).
  2. Upload kernel words to CODEBUF (CMDBUF_BASE + 0x400) and param words to
     CMDBUF_BASE via the CP DMA engine.
  3. Program CP_CORE_CODE/NBLK, kick, poll STATUS.core_busy (bit 9).
  4. Read results through the dbg sidecar and compare against the golden
     expectations computed in Python.

Gate kernels (roadmap Phase 5):
  * matadd    — 4 threads x 32 VRAM elements: A[i] = A[i] + B[i]
  * divergent — tid-dependent trip count (thread 0 skips the loop), results
                through smem + BAR
  * barrier   — smem atomics + block-wide barrier + broadcast read (all
                threads must observe the full 60)

cocotb 2.1 note: use int(sig.value) and d.<sig>.value = x (no setattr).
"""
import os
import sys

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge

CLK_NS = 10

_TOOLS_DIR = os.path.join(os.path.dirname(__file__), "..", "tools")
sys.path.insert(0, os.path.abspath(_TOOLS_DIR))
import assembler  # noqa: E402

# ---------------------------------------------------------------- constants --
CP_ID, CP_STATUS, CP_CTRL, CP_FENCE = 0x00, 0x04, 0x08, 0x0C
CP_FIFOD, CP_DMA_DST, CP_DMA_LEN, CP_CMDX = 0x10, 0x14, 0x18, 0x1C
CP_RTR_KICK = 0x20
CP_CORE_CODE, CP_CORE_NBLK, CP_CORE_KICK = 0x4C, 0x50, 0x54

VRAM_BASE = 0x1000
CMDBUF_OFF = 0x5B000          # VRAM offset (params + outputs + code buffer)
CODEBUF_OFF = CMDBUF_OFF + 0x400

NT = 4
FENCE_PARAMS, FENCE_CODE = 6, 7
KICK_TIMEOUT = 8_000_000      # >> 1M-cycle/block HW budget


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

    async def dbg_read_words(self, byte_off, nwords):
        return [await self.dbg_read((byte_off >> 2) + i)
                for i in range(nwords)]

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
                await self.reg_write(CP_FIFOD, w & 0xFFFFFFFF)
            await self.reg_write(CP_DMA_DST, off)
            await self.reg_write(CP_DMA_LEN, len(part) * 4)
            await self.reg_write(CP_CMDX, (fence << 8) | 0)
            await self.wait_dma_idle()
            off += len(part) * 4

    async def run_kernel(self, asm_path, nblk=1, params=None):
        """Assemble + upload + kick + wait. Returns nothing; results land in
        VRAM (kernel-defined). params: list of 32-bit words at CMDBUF_OFF."""
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


M32 = 0xFFFFFFFF


# ------------------------------------------------------------------ tests --
@cocotb.test()
async def test_core_matadd(dut):
    """matadd: 4 threads x 32 elements; A[i] += B[i] in VRAM."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = EmberTB(dut)
    await tb.reset()

    n = NT * 32
    a_words = [i for i in range(n)]              # A[i] = i
    b_words = [2 * i for i in range(n)]          # B[i] = 2*i -> C[i] = 3*i
    a_off, b_off = 0x59000, 0x59800              # VRAM offsets (scratch)
    await tb.upload_words_dma(a_off, a_words, 4)
    await tb.upload_words_dma(b_off, b_words, 5)

    await tb.run_kernel(os.path.join(os.path.dirname(__file__),
                                     "..", "kernels", "matadd.asm"),
                        nblk=1, params=[a_off, b_off])

    got = await tb.dbg_read_words(a_off, n)
    bad = [(i, got[i] & M32, (3 * i) & M32)
           for i in range(n) if (got[i] & M32) != (3 * i) & M32]
    assert not bad, f"{len(bad)} matadd mismatches: {bad[:8]}"


@cocotb.test()
async def test_core_divergent(dut):
    """divergent: tid-dependent trip count (thread 0 skips the loop)."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = EmberTB(dut)
    await tb.reset()

    await tb.run_kernel(os.path.join(os.path.dirname(__file__),
                                     "..", "kernels", "divergent.asm"),
                        nblk=1)

    got = await tb.dbg_read_words(CMDBUF_OFF + 0x100, NT)
    for t in range(NT):
        # loop runs i = 0..tid inclusive: acc = sum(i*tid) = tid^2*(tid+1)/2
        want = (t * t * (t + 1) // 2) & M32
        assert (got[t] & M32) == want, \
            f"thread {t}: rtl={got[t] & M32:#x} golden={want:#x}"


@cocotb.test()
async def test_core_barrier(dut):
    """barrier: smem atomics + block barrier + broadcast read (all see 60)."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = EmberTB(dut)
    await tb.reset()

    await tb.run_kernel(os.path.join(os.path.dirname(__file__),
                                     "..", "kernels", "barrier.asm"),
                        nblk=1)

    got = await tb.dbg_read_words(CMDBUF_OFF + 0x140, NT)
    for t in range(NT):
        assert (got[t] & M32) == 60, \
            f"thread {t}: rtl={got[t] & M32:#x} golden=60"


@cocotb.test()
async def test_core_matmul(dut):
    """matmul: C[4][4] = A[4][4] * B[4][4], thread t computes row t."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = EmberTB(dut)
    await tb.reset()

    a = [i * 4 + j for i in range(4) for j in range(4)]
    b = [2 * (i * 4 + j) for i in range(4) for j in range(4)]
    a_off, b_off, c_off = 0x59000, 0x59800, 0x5A000
    await tb.upload_words_dma(a_off, a, 4)
    await tb.upload_words_dma(b_off, b, 5)

    await tb.run_kernel(os.path.join(os.path.dirname(__file__),
                                     "..", "kernels", "matmul.asm"),
                        nblk=1, params=[a_off, b_off, c_off])

    got = await tb.dbg_read_words(c_off, 16)
    bad = []
    for i in range(4):
        for j in range(4):
            want = sum(a[i * 4 + k] * b[k * 4 + j] for k in range(4)) & M32
            if (got[i * 4 + j] & M32) != want:
                bad.append((i, j, got[i * 4 + j] & M32, want))
    assert not bad, f"{len(bad)} matmul mismatches: {bad[:8]}"
