"""
tb_tu.py — Phase-6 cocotb testbench: Ember-TU vs tools/golden/tu.py.

Drives the REAL software path: DMA int8 tensors to VRAM, program the TU
CSRs (A/W/C base, CFG2 dims/quant forms), kick, poll STATUS.tu_busy (bit 10),
read C through the dbg sidecar, compare bit-exact against the golden.

Tests:
  * test_tu_small    — 5x20x13 (multi-tile K and N, zero-weight rows),
                       mult=1/shift=0 identity quant; every C byte checked.
  * test_tu_quant    — 4x8x4 with mult=128, shift=7 (scale 1.0): exercises
                       the round-half-up requant against the golden.
  * test_tu_256      — 256x256x256 gate: full golden compare + sustained
                       GOPS estimate (256 MACs/cycle while streaming).

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
import tu as golden  # noqa: E402
from cocotb.utils import get_sim_time  # noqa: E402

# ---------------------------------------------------------------- constants --
CP_ID, CP_STATUS, CP_CTRL, CP_FENCE = 0x00, 0x04, 0x08, 0x0C
CP_FIFOD, CP_DMA_DST, CP_DMA_LEN, CP_CMDX = 0x10, 0x14, 0x18, 0x1C
CP_TU_A, CP_TU_W, CP_TU_C, CP_TU_CFG2, CP_TU_KICK = 0x58, 0x5C, 0x60, 0x64, 0x68

VRAM_BASE = 0x1000
# Non-overlapping scratch regions (256-cube: A/W/C each need 64 KiB+)
A_OFF, W_OFF, C_OFF = 0x20000, 0x45000, 0x6A000

FENCE_TENS = 8
M32 = 0xFFFFFFFF


def s8(x):
    """int -> int8 two's complement byte value."""
    return ((x & 0xFF) - 256) if (x & 0xFF) >= 128 else (x & 0xFF)


def pad16(flat, rows, cols):
    """Zero-pad a row-major int8 matrix so BOTH dims are multiples of 16
    (TU v1 contract: the array streams full 16-byte tiles in K and N;
    padding adds zero to real outputs). Returns (flat_padded, r16, c16)."""
    r16 = ((rows + 15) // 16) * 16
    c16 = ((cols + 15) // 16) * 16
    out = []
    for r in range(r16):
        row = flat[r * cols:(r + 1) * cols] if r < rows else []
        out += row + [0] * (c16 - len(row))
    return out, r16, c16


def pack_words(flat_ints):
    """int8 values -> 32-bit little-endian-packed VRAM words."""
    raw = bytes((v & 0xFF) for v in flat_ints)
    words = []
    for i in range(0, len(raw), 4):
        chunk = raw[i:i + 4]
        chunk += b"\\x00" * (4 - len(chunk))
        words.append(int.from_bytes(chunk, "little"))
    return words


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

    async def run_matmul(self, m, k, n, mult=1, shift=0, timeout=120_000_000):
        await self.reg_write(CP_TU_A, A_OFF)
        await self.reg_write(CP_TU_W, W_OFF)
        await self.reg_write(CP_TU_C, C_OFF)
        await self.reg_write(CP_TU_CFG2, (0 << 30) | ((k & 0xFFF) << 16)
                             | (n & 0xFFF))          # form 00: N, K
        await self.reg_write(CP_TU_CFG2, (1 << 30) | (m & 0xFFF))  # M (12b)
        await self.reg_write(CP_TU_CFG2, (2 << 30) | ((shift & 0xF) << 20)
                             | (mult & 0xFFFF))
        await self.reg_write(CP_TU_KICK, 1)
        for _ in range(timeout):
            await RisingEdge(self.dut.clk)
            if ((await self.reg_read(CP_STATUS)) >> 10) & 1 == 0:
                return
        raise AssertionError("tu_busy stuck high")

    async def read_c(self, nbytes):
        out = bytearray()
        for w in range((nbytes + 3) // 4):
            out += (await self.dbg_read((C_OFF >> 2) + w)).to_bytes(4, "little")
        return list(out[:nbytes])


# ------------------------------------------------------------------- tests --
def _golden_bytes(c8):
    return [v & 0xFF for v in c8]


@cocotb.test()
async def test_tu_small(dut):
    """5x20x13 identity-quant matmul, bit-exact vs golden."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = EmberTB(dut)
    await tb.reset()

    import random
    rng = random.Random(7)
    M, K, N = 5, 20, 13
    A = [[rng.randint(-128, 127) for _ in range(K)] for _ in range(M)]
    W = [[rng.randint(-128, 127) for _ in range(N)] for _ in range(K)]
    flat_a = [A[i][j] for i in range(M) for j in range(K)]
    flat_w = [W[i][j] for i in range(K) for j in range(N)]
    pa, _, K16 = pad16(flat_a, M, K)
    pw, K16w, N16 = pad16(flat_w, K, N)
    assert K16w == K16, "K padding mismatch between A and W"

    await tb.upload_words_dma(A_OFF, pack_words(pa), FENCE_TENS)
    await tb.upload_words_dma(W_OFF, pack_words(pw), FENCE_TENS)

    await tb.run_matmul(M, K16, N16)

    c32, c8 = golden.tu_matmul_ref(A, W, scale=1.0, zp=0)
    got = await tb.read_c(M * N16)
    want = _golden_bytes(c8)
    bad = []
    for i in range(M):
        for j in range(N):
            if got[i * N16 + j] != want[i * N + j]:
                bad.append((i * N + j, got[i * N16 + j], want[i * N + j]))
    assert not bad, f"{len(bad)} TU mismatches: {bad[:8]}"


@cocotb.test()
async def test_tu_quant(dut):
    """4x8x4 with mult=128/shift=7: requant path vs golden."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = EmberTB(dut)
    await tb.reset()

    import random
    rng = random.Random(11)
    M, K, N = 4, 8, 4
    A = [[rng.randint(-128, 127) for _ in range(K)] for _ in range(M)]
    W = [[rng.randint(-40, 40) for _ in range(N)] for _ in range(K)]
    flat_a = [A[i][j] for i in range(M) for j in range(K)]
    flat_w = [W[i][j] for i in range(K) for j in range(N)]
    pa, _, K16 = pad16(flat_a, M, K)
    pw, _, N16 = pad16(flat_w, K, N)

    await tb.upload_words_dma(A_OFF, pack_words(pa), FENCE_TENS)
    await tb.upload_words_dma(W_OFF, pack_words(pw), FENCE_TENS)

    await tb.run_matmul(M, K16, N16, mult=128, shift=7)

    c32, c8 = golden.tu_matmul_ref(A, W, scale=128 / 128.0, zp=0)
    got = await tb.read_c(M * N16)
    want = _golden_bytes(c8)
    bad = []
    for i in range(M):
        for j in range(N):
            if got[i * N16 + j] != want[i * N + j]:
                bad.append((i * N + j, got[i * N16 + j], want[i * N + j]))
    assert not bad, f"{len(bad)} TU quant mismatches: {bad[:8]}"


@cocotb.test()
async def test_tu_256(dut):
    """256-cube gate: full golden compare + sustained GOPS estimate."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = EmberTB(dut)
    await tb.reset()

    import random
    rng = random.Random(2026)
    M, K, N = 256, 256, 256
    A = [[rng.randint(-127, 127) for _ in range(K)] for _ in range(M)]
    W = [[rng.randint(-127, 127) for _ in range(N)] for _ in range(K)]
    flat_a = [A[i][j] for i in range(M) for j in range(K)]
    flat_w = [W[i][j] for i in range(K) for j in range(N)]

    await tb.upload_words_dma(A_OFF, pack_words(flat_a), FENCE_TENS)
    await tb.upload_words_dma(W_OFF, pack_words(flat_w), FENCE_TENS)

    t0 = get_sim_time("ns")
    await tb.run_matmul(M, K, N)
    t1 = get_sim_time("ns")

    c32, c8 = golden.tu_matmul_ref(A, W, scale=1.0, zp=0)
    got = await tb.read_c(M * N)
    want = _golden_bytes(c8)
    bad = [(i, got[i], want[i]) for i in range(M * N) if got[i] != want[i]]
    assert not bad, f"{len(bad)} TU 256-cube mismatches: {bad[:8]}"

    # MEASURED throughput (256 MACs/cycle in the array; the v1 serial
    # controller amortizes it down — streaming controller is the v2 note)
    cycles = (t1 - t0) / CLK_NS
    gops = (M * K * N * 2) / cycles / 10.0
    print(f"TU 256^3: {cycles:.0f} cycles, {gops:.2f} GOPS @ "
          f"{1000 / CLK_NS:.0f} MHz")
    assert gops >= 0.5, "TU throughput unexpectedly low (controller bug?)"
