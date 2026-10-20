"""
tb_mnist.py — Phase-7b cocotb testbench: the TU runs a quantized LeNet-style
network layer by layer.

Per layer: quantize input to int8, im2col if conv, pad the TU dims (K and N
MUST be multiples of 16 — W is zero-padded in both dims so the padded-k
products are exactly zero), upload, kick, poll tu_busy, read C (row stride
= Npadded), requant. Every layer's C is compared BIT-EXACT against the
golden arithmetic (tools/golden/mnist.py requant8 mirror).

Layers executed on the RTL TU:
  conv1 (im2col 676x9 @ 9x4)  -> pool1 (golden maxpool)
  conv2 (im2col 121x36 @ 36x8)-> pool2 (golden maxpool)
  dense1 (200x32)             -> relu (TB) -> dense2 (32x10)
(pool runs in the TB golden — a pooling unit is a v2 item; the TU matmul +
requant chain is all RTL.)

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
import mnist as G  # noqa: E402

# ---------------------------------------------------------------- constants --
CP_STATUS = 0x04
CP_FIFOD, CP_DMA_DST, CP_DMA_LEN, CP_CMDX = 0x10, 0x14, 0x18, 0x1C
CP_TU_A, CP_TU_W, CP_TU_C, CP_TU_CFG2, CP_TU_KICK = 0x58, 0x5C, 0x60, 0x64, 0x68

VRAM_BASE = 0x1000
A_OFF, W_OFF, C_OFF = 0x20000, 0x45000, 0x6A000

FENCE_TENS = 9
M32 = 0xFFFFFFFF


def s8(x):
    return ((x & 0xFF) - 256) if (x & 0xFF) >= 128 else (x & 0xFF)


def pack_words(flat):
    raw = bytes((v & 0xFF) for v in flat)
    words = []
    for i in range(0, len(raw), 4):
        chunk = raw[i:i + 4]
        chunk += b"\x00" * (4 - len(chunk))
        words.append(int.from_bytes(chunk, "little"))
    return words


def up16(x):
    return ((x + 15) // 16) * 16


def pad_w(flat, rows, cols):
    """Zero-pad a W matrix (K-major flat) in BOTH dims -> (flatp, Kp, Np)."""
    kp, np_ = up16(rows), up16(cols)
    out = []
    for r in range(kp):
        row = flat[r * cols:(r + 1) * cols] if r < rows else []
        out += row + [0] * (np_ - len(row))
    return out, kp, np_


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

    async def tu_matmul(self, m, k, n, mult=1, shift=0, timeout=30_000_000):
        await self.reg_write(CP_TU_A, A_OFF)
        await self.reg_write(CP_TU_W, W_OFF)
        await self.reg_write(CP_TU_C, C_OFF)
        await self.reg_write(CP_TU_CFG2, (0 << 30) | ((k & 0xFFF) << 16)
                             | (n & 0xFFF))
        await self.reg_write(CP_TU_CFG2, (1 << 30) | (m & 0xFFF))
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
        # VRAM holds raw int8 bytes; golden compares and downstream pooling
        # need SIGNED values (an unsigned compare reports -27 as 229).
        return [s8(b) for b in out[:nbytes]]

    async def tu_layer(self, a_flat, m_real, k_real, Wk, Wn, Wq, mult, shift):
        """One TU matmul: zero-pad A (row stride K->16) AND W (both dims),
        run with padded dims, return C (Mp x Np, row-stride Np) list."""
        Kp, Np, Mp = up16(k_real), up16(Wn), up16(m_real)
        Ap, Mpa, Kpa = pad_w(a_flat, m_real, k_real)
        assert Kpa == Kp and Mpa == Mp, (Kpa, Kp, Mpa, Mp)
        Wp, Kwp, Nwp = pad_w(Wq, Wk, Wn)
        assert Kwp == Kp and Nwp == Np
        await self.upload_words_dma(W_OFF, pack_words(Wp), FENCE_TENS)
        await self.upload_words_dma(A_OFF, pack_words(Ap), FENCE_TENS)
        await self.tu_matmul(Mp, Kp, Np, mult, shift)
        return await self.read_c(Mp * Np), Np


def quant_act(values, scale):
    return [max(-128, min(127, round(v / scale))) for v in values]


# ------------------------------------------------------------------- test --
@cocotb.test()
async def test_mnist_layers(dut):
    """Layer-by-layer LeNet through the RTL TU vs golden arithmetic."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = EmberTB(dut)
    await tb.reset()

    model = G.Model(seed=20260927).quantize()
    import random
    rng = random.Random(42)
    img_f = [rng.uniform(-1.0, 1.0) for _ in range(28 * 28)]
    img_q = quant_act(img_f, model.c1s)

    # ---------------- conv1: im2col(676x9) @ W(9x4), K->16, N->16 ---------
    rows, oh, ow = G.im2col(img_q, 1, 28, 28, 3)
    W1 = [model.c1q[oc][k] for k in range(9) for oc in range(4)]   # K-major
    mult, shift = model.rq["c1"]
    c1_flat, Np = await tb.tu_layer([v for r in rows for v in r],
                                    len(rows), 9, 9, 4, W1, mult, shift)
    g1 = []
    for r in rows:
        for oc in range(4):
            s = sum(r[k] * model.c1q[oc][k] for k in range(9))
            g1.append(model.requant8(s, mult, shift))
    bad = [(i, c1_flat[(i // 4) * Np + i % 4], g1[i])
           for i in range(len(g1))
           if c1_flat[(i // 4) * Np + i % 4] != g1[i]]
    assert not bad, f"conv1: {len(bad)} mismatches: {bad[:8]}"

    # ---------------- pool1 (golden) + conv2: (121x36) @ (36x8) -----------
    p1, _, _, _ = G.maxpool2([c1_flat[(i // 4) * Np + i % 4]
                              for i in range(oh * ow * 4)], 4, 26, 26)
    rows2, oh2, ow2 = G.im2col(p1, 4, 13, 13, 3)
    W2 = [model.c2q[oc][k] for k in range(36) for oc in range(8)]
    mult2, shift2 = model.rq["c2"]
    c2_flat, Np2 = await tb.tu_layer([v for r in rows2 for v in r],
                                     len(rows2), 36, 36, 8, W2, mult2, shift2)
    g2 = []
    for r in rows2:
        for oc in range(8):
            s = sum(r[k] * model.c2q[oc][k] for k in range(36))
            g2.append(model.requant8(s, mult2, shift2))
    bad = [(i, c2_flat[(i // 8) * Np2 + i % 8], g2[i])
           for i in range(len(g2))
           if c2_flat[(i // 8) * Np2 + i % 8] != g2[i]]
    assert not bad, f"conv2: {len(bad)} mismatches: {bad[:8]}"

    # ---------------- pool2 (golden) + dense1: (200) @ (200x32) -----------
    p2, _, _, _ = G.maxpool2([c2_flat[(i // 8) * Np2 + i % 8]
                              for i in range(oh2 * ow2 * 8)], 8, 11, 11)
    multd1, shiftd1 = model.rq["d1"]
    d1_flat, Npd1 = await tb.tu_layer(p2, 1, 200, 200, 32, model.d1q,
                                      multd1, shiftd1)
    gd1 = []
    for n in range(32):
        s = sum(p2[k] * model.d1q[k * 32 + n] for k in range(200))
        gd1.append(model.requant8(s, multd1, shiftd1))
    bad = [(i, d1_flat[i], gd1[i]) for i in range(32)
           if d1_flat[i] != gd1[i]]
    assert not bad, f"dense1: {len(bad)} mismatches: {bad[:8]}"

    # ---------------- relu + dense2: (32) @ (32x10) ------------------------
    d1r = [max(0, v) for v in gd1]
    multd2, shiftd2 = model.rq["d2"]
    d2_flat, Npd2 = await tb.tu_layer(d1r, 1, 32, 32, 10, model.d2q,
                                      multd2, shiftd2)
    gd2 = []
    for n in range(10):
        s = sum(d1r[k] * model.d2q[k * 10 + n] for k in range(32))
        gd2.append(model.requant8(s, multd2, shiftd2))
    gotd2 = [d2_flat[i] for i in range(10)]
    bad = [(i, gotd2[i], gd2[i]) for i in range(10)
           if gotd2[i] != gd2[i]]
    assert not bad, f"dense2: {len(bad)} mismatches: {bad[:8]}"

    pred = G.argmax(gd2)
    print(f"MNIST RTL RUN: logits={gd2} pred={pred}")
    print("MNIST LAYER TESTS PASS")
