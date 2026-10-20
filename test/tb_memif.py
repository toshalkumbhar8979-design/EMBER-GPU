"""
tb_memif.py — cocotb testbench for the chip external memory controller
(rtl/ember_memif.sv) against behavioral external SRAMs (test/memif_tb.sv).

Covers the physical memory interface contract:
  1. AXI write is broadcast to all three SRAMs — every fast port sees it
  2. Same-cycle reads on CH0+CH1+CH2 (fpa3 + cxa + ixa) all return correct data
  3. Same-cycle read-during-write returns OLD data (ember_vram semantics)
  4. Engine writes win the broadcast write bus; the AXI write waits in the
     skid and completes afterwards (B response included)
  5. AXI reads stall legally behind same-cycle ixa fetches, then complete
  6. Byte enables

Run:  make -f Makefile.memif test   (from test/)
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge

CLK_NS = 10  # 100 MHz

VRAM_BASE = 0x1000


def waddr(byte_off):
    """VRAM word index for a byte offset within VRAM."""
    return (byte_off >> 2) & 0x1FFFF


class AxiLiteDriver:
    """Minimal AXI4-Lite master on the v_* flat port."""

    def __init__(self, dut):
        self.dut = dut

    async def write(self, addr, data, strb=0xF):
        d = self.dut
        d.v_awaddr.value = addr
        d.v_awvalid.value = 1
        d.v_wdata.value = data
        d.v_wstrb.value = strb
        d.v_wvalid.value = 1
        aw_done = w_done = False
        while not (aw_done and w_done):
            await RisingEdge(d.clk)
            if d.v_awready.value == 1 and d.v_awvalid.value == 1:
                aw_done = True
                d.v_awvalid.value = 0
            if d.v_wready.value == 1 and d.v_wvalid.value == 1:
                w_done = True
                d.v_wvalid.value = 0
        d.v_bready.value = 1
        while True:
            await RisingEdge(d.clk)
            if d.v_bvalid.value == 1:
                resp = int(d.v_bresp.value)
                break
        d.v_bready.value = 0
        assert resp == 0, f"AXI write resp {resp} at {addr:#x}"

    async def read(self, addr):
        d = self.dut
        d.v_araddr.value = addr
        d.v_arvalid.value = 1
        while True:
            await RisingEdge(d.clk)
            if d.v_arready.value == 1 and d.v_arvalid.value == 1:
                d.v_arvalid.value = 0
                break
        d.v_rready.value = 1
        while True:
            await RisingEdge(d.clk)
            if d.v_rvalid.value == 1:
                data = int(d.v_rdata.value)
                resp = int(d.v_rresp.value)
                break
        d.v_rready.value = 0
        assert resp == 0, f"AXI read resp {resp} at {addr:#x}"
        return data


class MemifTB:
    """Fast-port helpers. Contract: req high during cycle N -> rdata valid
    during N+1. Drive right after edge k (request in cycle k), clear after
    edge k+1 (the capture edge), sample after edge k+2 (value during N+1)."""

    PORTS = ("fpa", "fpa2", "fpa3", "gxa", "cxa", "ixa", "tua")

    def __init__(self, dut):
        self.dut = dut
        self.axi = AxiLiteDriver(dut)

    async def reset(self):
        d = self.dut
        d.rst_n.value = 0
        for p in self.PORTS:
            getattr(d, f"{p}_req").value = 0
            getattr(d, f"{p}_addr").value = 0
        for p in ("fpa", "fpa2", "gxa", "cxa", "tua"):
            getattr(d, f"{p}_we").value = 0
            getattr(d, f"{p}_wdata").value = 0
            getattr(d, f"{p}_be").value = 0
        d.v_awvalid.value = 0
        d.v_wvalid.value = 0
        d.v_arvalid.value = 0
        d.v_bready.value = 0
        d.v_rready.value = 0
        await RisingEdge(d.clk)
        await RisingEdge(d.clk)
        d.rst_n.value = 1
        await RisingEdge(d.clk)

    async def fast_write(self, port, addr, data, be=0xF):
        """One-cycle engine write on a fast port (commits at the capture edge)."""
        d = self.dut
        await RisingEdge(d.clk)
        getattr(d, f"{port}_addr").value = addr
        getattr(d, f"{port}_wdata").value = data
        getattr(d, f"{port}_be").value = be
        getattr(d, f"{port}_we").value = 1
        await RisingEdge(d.clk)
        getattr(d, f"{port}_we").value = 0

    async def fast_read(self, port, addr):
        """Fire a one-cycle read and return the data (1-cycle latency)."""
        d = self.dut
        await RisingEdge(d.clk)
        getattr(d, f"{port}_addr").value = addr
        getattr(d, f"{port}_req").value = 1
        await RisingEdge(d.clk)          # capture edge
        getattr(d, f"{port}_req").value = 0
        await RisingEdge(d.clk)          # rdata valid during the ended cycle
        return int(getattr(d, f"{port}_rdata").value)


@cocotb.test()
async def test_broadcast_write_all_ports(dut):
    """A write on the broadcast bus is visible from every fast port."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = MemifTB(dut)
    await tb.reset()

    await tb.axi.write(VRAM_BASE + 0x100, 0xCAFEF00D)

    for port in MemifTB.PORTS:
        val = await tb.fast_read(port, VRAM_BASE + 0x100)
        assert val == 0xCAFEF00D, f"{port} got {val:#x}, expected 0xcafef00d"

    # engine writes are broadcast too (cxa -> CH0 read via fpa3)
    await tb.fast_write("cxa", VRAM_BASE + 0x200, 0x13579BDF)
    val = await tb.fast_read("fpa3", VRAM_BASE + 0x200)
    assert val == 0x13579BDF, f"fpa3 got {val:#x} after cxa write"


@cocotb.test()
async def test_same_cycle_three_channels(dut):
    """Worst-case concurrency: display + core data + core fetch in the same
    cycle (CH0 + CH1 + CH2) must all return correct data."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = MemifTB(dut)
    await tb.reset()

    await tb.axi.write(VRAM_BASE + 0x000, 0x11112222)
    await tb.axi.write(VRAM_BASE + 0x004, 0x33334444)
    await tb.axi.write(VRAM_BASE + 0x008, 0x55556666)

    d = dut
    await RisingEdge(d.clk)
    d.fpa3_addr.value = VRAM_BASE + 0x000
    d.fpa3_req.value = 1
    d.cxa_addr.value = VRAM_BASE + 0x004
    d.cxa_req.value = 1
    d.ixa_addr.value = VRAM_BASE + 0x008
    d.ixa_req.value = 1
    await RisingEdge(d.clk)              # capture edge: all three fire
    d.fpa3_req.value = 0
    d.cxa_req.value = 0
    d.ixa_req.value = 0
    await RisingEdge(d.clk)
    assert int(d.fpa3_rdata.value) == 0x11112222, f"CH0 {int(d.fpa3_rdata.value):#x}"
    assert int(d.cxa_rdata.value) == 0x33334444, f"CH1 {int(d.cxa_rdata.value):#x}"
    assert int(d.ixa_rdata.value) == 0x55556666, f"CH2 {int(d.ixa_rdata.value):#x}"


@cocotb.test()
async def test_read_old_data_on_collision(dut):
    """Same-cycle write+read to the same address returns the OLD value
    (nonblocking semantics of the on-die ember_vram this replaces)."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = MemifTB(dut)
    await tb.reset()

    await tb.axi.write(VRAM_BASE + 0x40, 0xAAAA5555)

    d = dut
    await RisingEdge(d.clk)
    d.cxa_addr.value = VRAM_BASE + 0x40
    d.cxa_wdata.value = 0x000000FF
    d.cxa_be.value = 0xF
    d.cxa_we.value = 1
    d.fpa3_addr.value = VRAM_BASE + 0x40
    d.fpa3_req.value = 1
    await RisingEdge(d.clk)              # write commits here
    d.cxa_we.value = 0
    d.fpa3_req.value = 0
    await RisingEdge(d.clk)
    assert int(d.fpa3_rdata.value) == 0xAAAA5555, \
        f"read-during-write must return old data, got {int(d.fpa3_rdata.value):#x}"

    val = await tb.fast_read("fpa3", VRAM_BASE + 0x40)
    assert val == 0x000000FF, f"write must be visible next cycle, got {val:#x}"


@cocotb.test()
async def test_engine_write_wins_broadcast_bus(dut):
    """Engine writes cannot stall -> they own the write bus; a concurrent AXI
    write waits in the skid and completes with its B response afterwards."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = MemifTB(dut)
    await tb.reset()

    d = dut
    # present an AXI write and stream engine writes for 4 cycles
    d.v_awaddr.value = VRAM_BASE + 0x300
    d.v_awvalid.value = 1
    d.v_wdata.value = 0xABCDEF01
    d.v_wstrb.value = 0xF
    d.v_wvalid.value = 1
    d.v_bready.value = 1

    await RisingEdge(d.clk)
    for i in range(4):
        d.cxa_addr.value = VRAM_BASE + 0x400 + 4 * i
        d.cxa_wdata.value = 0x100 + i
        d.cxa_be.value = 0xF
        d.cxa_we.value = 1
        await RisingEdge(d.clk)
        assert int(d.v_bvalid.value) == 0, \
            "AXI write must not commit while engine writes own the bus"
    d.cxa_we.value = 0

    # AXI write completes now
    for _ in range(10):
        await RisingEdge(d.clk)
        if int(d.v_bvalid.value) == 1:
            break
    else:
        raise AssertionError("AXI write B response never arrived")
    assert int(d.v_bresp.value) == 0

    # both sets of writes landed, uncorrupted
    for i in range(4):
        val = await tb.fast_read("fpa3", VRAM_BASE + 0x400 + 4 * i)
        assert val == 0x100 + i, f"engine write {i} corrupted: {val:#x}"
    val = await tb.fast_read("ixa", VRAM_BASE + 0x300)
    assert val == 0xABCDEF01, f"AXI write corrupted: {val:#x}"


@cocotb.test()
async def test_axi_stalls_behind_ixa(dut):
    """CH2 is shared: same-cycle conflicts go to ixa (fixed latency), the AXI
    read waits legally on arready, then completes with correct data."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = MemifTB(dut)
    await tb.reset()

    await tb.axi.write(VRAM_BASE + 0x500, 0x0BADC0DE)
    await tb.axi.write(VRAM_BASE + 0x504, 0x0DEAD001)

    d = dut
    # stream ixa fetches; present an AXI read at the same time
    await RisingEdge(d.clk)
    d.ixa_addr.value = VRAM_BASE + 0x500
    d.ixa_req.value = 1
    d.v_araddr.value = VRAM_BASE + 0x504
    d.v_arvalid.value = 1
    d.v_rready.value = 1

    for i in range(4):
        await RisingEdge(d.clk)
        assert int(d.v_arready.value) == 0, "AXI AR must stall behind ixa"
        assert int(d.v_rvalid.value) == 0, "no AXI read can be in flight"
    d.ixa_req.value = 0

    data = None
    for _ in range(10):
        await RisingEdge(d.clk)
        if int(d.v_rvalid.value) == 1 and int(d.v_rready.value) == 1:
            data = int(d.v_rdata.value)
            d.v_arvalid.value = 0
            break
    assert data == 0x0DEAD001, f"AXI read after ixa stream: {data:#x}"


@cocotb.test()
async def test_byte_enables(dut):
    """wbe_n lanes write only the enabled bytes."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = MemifTB(dut)
    await tb.reset()

    await tb.axi.write(VRAM_BASE + 0x600, 0xFFFFFFFF)
    await tb.axi.write(VRAM_BASE + 0x600, 0x11223344, strb=0x3)
    val = await tb.fast_read("fpa", VRAM_BASE + 0x600)
    assert val == 0xFFFF3344, f"strb=0x3 write got {val:#x}"

    await tb.fast_write("tua", VRAM_BASE + 0x600, 0x00000000, be=0x4)
    val = await tb.fast_read("fpa", VRAM_BASE + 0x600)
    assert val == 0xFF003344, f"be=0x4 engine write got {val:#x}"
