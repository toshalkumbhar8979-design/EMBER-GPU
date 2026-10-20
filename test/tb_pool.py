"""
tb_pool.py — Phase-7d isolation test: the pool2d KERNEL alone on the core.

Feeds random SIGNED planes (bytes incl. negatives) at both 4x26x26 and
8x11x11 shapes and compares word-for-word against the golden maxpool2.
Isolates kernel bugs from the tb_mnist_e2e integration.
"""
import os
import sys
import random

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge

CLK_NS = 10

_TOOLS_DIR = os.path.join(os.path.dirname(__file__), "..", "tools")
_GOLDEN_DIR = os.path.join(_TOOLS_DIR, "golden")
sys.path.insert(0, os.path.abspath(_TOOLS_DIR))
sys.path.insert(0, os.path.abspath(_GOLDEN_DIR))
import assembler  # noqa: E402
import mnist as G  # noqa: E402

CP_STATUS = 0x04
CP_FIFOD, CP_DMA_DST, CP_DMA_LEN, CP_CMDX = 0x10, 0x14, 0x18, 0x1C
CP_CORE_CODE, CP_CORE_NBLK, CP_CORE_KICK = 0x4C, 0x50, 0x54

CMDBUF_OFF = 0x5B000
CODEBUF_OFF = CMDBUF_OFF + 0x400
CORE_A, CORE_O = 0x25000, 0x28000   # no overlap: 4x26x26 needs 2704 words
FENCE_POOL, FENCE_CODE = 5, 7
M32 = 0xFFFFFFFF
KICK_TIMEOUT = 8_000_000
KERNEL = os.path.join(os.path.dirname(__file__), "..", "kernels",
                      "pool2d.asm")


def pack_words(flat):
    raw = bytes((v & 0xFF) for v in flat)
    words = []
    for i in range(0, len(raw), 4):
        chunk = raw[i:i + 4]
        chunk += b"\x00" * (4 - len(chunk))
        words.append(int.from_bytes(chunk, "little"))
    return words


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
                await self.reg_write(CP_FIFOD, w & M32)
            await self.reg_write(CP_DMA_DST, off)
            await self.reg_write(CP_DMA_LEN, len(part) * 4)
            await self.reg_write(CP_CMDX, (fence << 8) | 0)
            await self.wait_dma_idle()
            off += len(part) * 4

    async def run_kernel(self, nblk, params):
        with open(KERNEL) as fh:
            words = assembler.run_assembler(fh.read())
        await self.upload_words_dma(CMDBUF_OFF, params, FENCE_POOL)
        await self.upload_words_dma(CODEBUF_OFF, words, FENCE_CODE)
        await self.reg_write(CP_CORE_CODE, CODEBUF_OFF)
        await self.reg_write(CP_CORE_NBLK, nblk)
        await self.reg_write(CP_CORE_KICK, 1)
        for _ in range(KICK_TIMEOUT):
            await RisingEdge(self.dut.clk)
            if ((await self.reg_read(CP_STATUS)) >> 9) & 1 == 0:
                return
        raise AssertionError("core_busy stuck high (pool2d)")


@cocotb.test()
async def test_pool_shapes(dut):
    """pool2d kernel vs golden on two shapes with signed byte planes."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = EmberTB(dut)
    await tb.reset()

    rng = random.Random(777)
    # ws4 = 4 * INPUT row width (inh), NOT the pooled output width!
    for cin, inh, opx, ow_, ws4, tag in ((4, 26, 169, 13, 4 * 26, "pool1"),
                                         (8, 11, 25, 5, 4 * 11, "pool2")):
        flat = [rng.randint(-128, 127) for _ in range(cin * inh * inh)]
        # kernel contract: ONE pixel byte per 32-bit word (CHW planes)
        a_words = [v & 0xFF for v in flat]
        await tb.upload_words_dma(CORE_A, a_words, FENCE_POOL)
        params = [CORE_A, CORE_O, opx, ow_, cin, ws4, inh * inh]
        await tb.run_kernel(1, params)
        got = await tb.dbg_read_words(CORE_O, opx * cin)
        # kernel output bytes are SIGNED int8 (conv outputs) — read back as
        # signed or every negative max shows as its two's-complement byte
        got_b = [(((w & 0xFF) - 256) if (w & 0xFF) >= 128 else (w & 0xFF))
                 for w in got]
        gold, _, _, _ = G.maxpool2(flat, cin, inh, inh)
        bad = [(i, got_b[i], gold[i]) for i in range(opx * cin)
               if got_b[i] != gold[i]]
        assert not bad, f"{tag}: {len(bad)} mismatches: {bad[:8]}"
        print(f"{tag}: {opx*cin} outputs bit-exact (signed bytes OK)")
    print("POOL KERNEL PASS")
