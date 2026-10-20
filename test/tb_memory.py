"""
tb_memory.py — cocotb testbench for Ember GPU Phase 1 (memory system + CP).

Covers:
  1. CP register smoke (ID, status)
  2. VRAM write/read via host bus
  3. DMA upload: FIFO push -> VRAM (verify via dbg port)
  4. DMA readback: VRAM -> FIFO (verify data + fence)
  5. Zero-length DMA completes immediately

Run: make test (from repo root)
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly, Timer

CLK_NS = 10  # 100 MHz

# CP register offsets
CP_ID, CP_STATUS, CP_CTRL, CP_FENCE = 0x00, 0x04, 0x08, 0x0C
CP_FIFOD, CP_DMA_DST, CP_DMA_LEN, CP_CMDX = 0x10, 0x14, 0x18, 0x1C

VRAM_BASE = 0x1000


class AxiLiteDriver:
    """Minimal AXI4-Lite master: one transaction at a time, full handshake."""

    def __init__(self, dut):
        self.dut = dut

    async def write(self, addr, data, strb=0xF):
        d = self.dut
        d.h_awaddr.value  = addr
        d.h_awvalid.value = 1
        d.h_wdata.value   = data
        d.h_wstrb.value   = strb
        d.h_wvalid.value  = 1
        # wait for both handshakes (can complete on different cycles)
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
        d.h_araddr.value  = addr
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

    async def wait_fence(self, fence_id, timeout=500):
        for _ in range(timeout):
            await RisingEdge(self.dut.clk)
            if await self.reg_read(CP_FENCE) == fence_id:
                return
        raise AssertionError(f"fence {fence_id} never reached")


@cocotb.test()
async def test_cp_regs(dut):
    """CP ID and STATUS reset values"""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = EmberTB(dut)
    await tb.reset()

    val = await tb.reg_read(CP_ID)
    assert val == 0xEB220002, f"CP_ID mismatch: {val:#x}"

    status = await tb.reg_read(CP_STATUS)
    assert status & 1 == 0, "dma_busy should be 0 after reset"


@cocotb.test()
async def test_vram_bus_rw(dut):
    """VRAM write/read through the host bus"""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = EmberTB(dut)
    await tb.reset()

    await tb.reg_write(VRAM_BASE + 0x40, 0xDEADBEEF)
    await tb.reg_write(VRAM_BASE + 0x44, 0x12345678)
    v0 = await tb.reg_read(VRAM_BASE + 0x40)
    v1 = await tb.reg_read(VRAM_BASE + 0x44)
    assert v0 == 0xDEADBEEF, f"VRAM readback mismatch: {v0:#x}"
    assert v1 == 0x12345678, f"VRAM readback mismatch: {v1:#x}"


@cocotb.test()
async def test_dma_upload_readback(dut):
    """DMA: FIFO -> VRAM -> FIFO round trip with fence"""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = EmberTB(dut)
    await tb.reset()

    DST = 0x400                   # VRAM byte OFFSET (CP adds VRAM_BASE itself)
    N = 8

    pattern = [(0x11111111 * (i + 1)) & 0xFFFFFFFF for i in range(N)]
    for w in pattern:
        await tb.reg_write(CP_FIFOD, w)

    # upload: dir=0, fence=7
    await tb.reg_write(CP_DMA_DST, DST)
    await tb.reg_write(CP_DMA_LEN, N * 4)
    await tb.reg_write(CP_CMDX, (7 << 8) | 0)
    await tb.wait_fence(7)

    # verify via dbg port: word addr = DST / 4
    for i in range(N):
        word = await tb.dbg_read(DST // 4 + i)
        assert word == pattern[i], f"VRAM[{i}]={word:#x} want {pattern[i]:#x}"

    # readback: dir=1, fence=9
    await tb.reg_write(CP_DMA_DST, DST)
    await tb.reg_write(CP_DMA_LEN, N * 4)
    await tb.reg_write(CP_CMDX, (9 << 8) | 1)
    await tb.wait_fence(9)

    for i in range(N):
        val = await tb.reg_read(CP_FIFOD)
        assert val == pattern[i], f"FIFO[{i}]={val:#x} want {pattern[i]:#x}"


@cocotb.test()
async def test_zero_len_dma(dut):
    """Zero-length DMA completes immediately and updates fence"""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = EmberTB(dut)
    await tb.reset()

    await tb.reg_write(CP_DMA_LEN, 0)
    await tb.reg_write(CP_CMDX, (0x42 << 8) | 0)
    await tb.reg_read(CP_STATUS)  # small settle
    fence = await tb.reg_read(CP_FENCE)
    assert fence == 0x42, f"fence should be 0x42, got {fence:#x}"
