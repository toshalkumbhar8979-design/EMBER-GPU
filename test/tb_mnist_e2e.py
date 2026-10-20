"""
tb_mnist_e2e.py — Phase-7d MNIST END-TO-END on Ember silicon (no golden
compute in the loop).

Pipeline, every stage on RTL:
  1. 28x28 int8 image -> CP DMA -> VRAM scratch.
  2. conv1: im2col (TB-side packing) -> TU @ c1w (K-major).
  3. pool1: RTL COMPUTE CORE, kernels/pool2d.asm (MAXC, CHW 1px/word).
  4. conv2 via TU, pool2 via the core.
  5. dense1/dense2 via TU (dense1 raw -> relu in TB (v1; note), dense2
     requantized on-TU).
  6. Digit = argmax of the 10 requantized logits read from VRAM.

The layer arithmetic is verified bit-exact against the golden mirrors by
tb_mnist.py; THIS test asserts the END-TO-END dataflow: the digit computed
from VRAM equals the golden model's prediction for the same image, and the
TU/core exchange formats (CHW 1px/word planes) round-trip correctly.

NOTE (v1): the TU's requant8 wraps to int8; dense1's accumulator can exceed
the wrap range, so dense1 is read RAW (mult=1, shift=0) and ReLU'd in the
TB — exactly like tb_mnist.py. Moving the ReLU on-core is a v2 item.

cocotb 2.1 note: use int(sig.value) and d.<sig>.value = x (no setattr).
"""
import os
import sys

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

# ---------------------------------------------------------------- constants --
CP_STATUS = 0x04
CP_FIFOD, CP_DMA_DST, CP_DMA_LEN, CP_CMDX = 0x10, 0x14, 0x18, 0x1C
CP_TU_A, CP_TU_W, CP_TU_C, CP_TU_CFG2, CP_TU_KICK = 0x58, 0x5C, 0x60, 0x64, 0x68
CP_CORE_CODE, CP_CORE_NBLK, CP_CORE_KICK = 0x4C, 0x50, 0x54

A_OFF, W_OFF, C_OFF = 0x20000, 0x45000, 0x6A000
IMG_OFF, P1_OFF, P2_OFF = 0x21000, 0x23000, 0x24400
CORE_A, CORE_O = 0x25000, 0x28000   # CORE_A needs 2704 words; NO overlap
CMDBUF_OFF = 0x5B000
CODEBUF_OFF = CMDBUF_OFF + 0x400
POOL_OUT_OFF = 0x24700

FENCE_TENS, FENCE_POOL, FENCE_CODE = 9, 5, 7
M32 = 0xFFFFFFFF
KICK_TIMEOUT = 8_000_000


def up16(x):
    return ((x + 15) // 16) * 16


def pack_words(flat):
    raw = bytes((v & 0xFF) for v in flat)
    words = []
    for i in range(0, len(raw), 4):
        chunk = raw[i:i + 4]
        chunk += b"\x00" * (4 - len(chunk))
        words.append(int.from_bytes(chunk, "little"))
    return words


def opmaj_to_chw_words(flat_op, c, h, w):
    """TU conv output, OP-MAJOR (flat[op*c + ch], op = y*w + x) -> CHW
    one-pixel-per-word raw-byte words (the pool kernel's VRAM contract).
    Phase-7f: the previous helper read the op-major array as plane-major
    and silently channel-scrambled the planes — bit-exact against the
    same-wrong golden mirror with random weights, accuracy-fatal with
    trained weights."""
    out = [0] * (c * h * w)
    for op in range(h * w):
        y, x = op // w, op % w
        for ch in range(c):
            out[ch * h * w + y * w + x] = flat_op[op * c + ch] & 0xFF
    return out


def s8(x):
    return ((x & 0xFF) - 256) if (x & 0xFF) >= 128 else (x & 0xFF)


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

    async def tu_matmul(self, m, k, n, mult=1, shift=0):
        await self.reg_write(CP_TU_A, A_OFF)
        await self.reg_write(CP_TU_W, W_OFF)
        await self.reg_write(CP_TU_C, C_OFF)
        await self.reg_write(CP_TU_CFG2, (0 << 30) | ((k & 0xFFF) << 16)
                             | (n & 0xFFF))
        await self.reg_write(CP_TU_CFG2, (1 << 30) | (m & 0xFFF))
        await self.reg_write(CP_TU_CFG2, (2 << 30) | ((shift & 0xF) << 20)
                             | (mult & 0xFFFF))
        await self.reg_write(CP_TU_KICK, 1)
        for _ in range(KICK_TIMEOUT):
            await RisingEdge(self.dut.clk)
            if ((await self.reg_read(CP_STATUS)) >> 10) & 1 == 0:
                return
        raise AssertionError("tu_busy stuck high")

    async def read_c(self, nbytes):
        out = bytearray()
        for w in range((nbytes + 3) // 4):
            out += (await self.dbg_read((C_OFF >> 2) + w)).to_bytes(4, "little")
        return [s8(b) for b in out[:nbytes]]

    async def run_kernel(self, asm_path, nblk, params):
        with open(asm_path) as fh:
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
        raise AssertionError(f"core_busy stuck high for {asm_path}")

    async def tu_layer(self, a_flat, m_real, k_real, Wk, Wn, Wq, mult, shift):
        Kp, Np, Mp = up16(k_real), up16(Wn), up16(m_real)
        Ap, Mpa, Kpa = pad_w(a_flat, m_real, k_real)
        assert Kpa == Kp and Mpa == Mp
        Wp, Kwp, Nwp = pad_w(Wq, Wk, Wn)
        assert Kwp == Kp and Nwp == Np
        await self.upload_words_dma(W_OFF, pack_words(Wp), FENCE_TENS)
        await self.upload_words_dma(A_OFF, pack_words(Ap), FENCE_TENS)
        await self.tu_matmul(Mp, Kp, Np, mult, shift)
        return await self.read_c(Mp * Np), Np


def pad_w(flat, rows, cols):
    kp, np_ = up16(rows), up16(cols)
    out = []
    for r in range(kp):
        row = flat[r * cols:(r + 1) * cols] if r < rows else []
        out += row + [0] * (np_ - len(row))
    return out, kp, np_


def quant_act(values, scale):
    return [max(-128, min(127, round(v / scale))) for v in values]


KERNEL_DIR = os.path.join(os.path.dirname(__file__), "..", "kernels")


# ------------------------------------------------------------------- test --
@cocotb.test()
async def test_mnist_e2e(dut):
    """Image -> TU(conv) -> CORE(pool) -> TU(dense) -> digit, all RTL."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = EmberTB(dut)
    await tb.reset()

    model = G.Model(seed=20260927).quantize()
    import random
    rng = random.Random(4242)
    img_f = [rng.uniform(-1.0, 1.0) for _ in range(28 * 28)]
    img_q = quant_act(img_f, model.c1s)

    # ---- 1) image -> VRAM ------------------------------------------------
    await tb.upload_words_dma(IMG_OFF, pack_words(img_q), FENCE_TENS)

    # ---- 2) conv1 on TU --------------------------------------------------
    rows1, oh1, ow1 = G.im2col(img_q, 1, 28, 28, 3)
    W1 = [model.c1q[oc][k] for k in range(9) for oc in range(4)]
    mult1, shift1 = model.rq["c1"]
    c1_flat, Np1 = await tb.tu_layer([v for r in rows1 for v in r],
                                     len(rows1), 9, 9, 4, W1, mult1, shift1)
    c1 = [c1_flat[(i // 4) * Np1 + i % 4] for i in range(oh1 * ow1 * 4)]
    # Phase-7f: ReLU after conv (the trained net has it; max(0,.) commutes
    # with max-pool so the pool kernel implements ReLU+pool unchanged).
    c1 = [v if v > 0 else 0 for v in c1]

    # ---- 3) pool1 on the RTL CORE ----------------------------------------
    # CHW, ONE PIXEL PER WORD (the kernel contract): 4ch x 676px = 2704 words
    a_words = opmaj_to_chw_words(c1, 4, 26, 26)
    await tb.upload_words_dma(CORE_A, a_words, FENCE_POOL)
    # ws4 = 4 * INPUT row width (26), NOT the pooled 13!
    params = [CORE_A, CORE_O, 169, 13, 4, 4 * 26, 676]
    await tb.run_kernel(os.path.join(KERNEL_DIR, "pool2d.asm"),
                        nblk=1, params=params)
    got = await tb.dbg_read_words(CORE_O, 169 * 4)
    # kernel output bytes are SIGNED int8 — read as signed (conv outputs)
    p1_rtl = [(((w & 0xFF) - 256) if (w & 0xFF) >= 128 else (w & 0xFF))
              for w in got]
    p1_gold, _, _, _ = G.maxpool2_op(c1, 4, 13, 13, 26, 26)
    bad = [(i, p1_rtl[i], p1_gold[i]) for i in range(169 * 4)
           if p1_rtl[i] != p1_gold[i]]
    assert not bad, f"pool1 RTL: {len(bad)} mismatches: {bad[:8]}"

    # ---- 4) conv2 on TU + pool2 on the CORE -------------------------------
    rows2, oh2, ow2 = G.im2col(p1_rtl, 4, 13, 13, 3)
    W2 = [model.c2q[oc][k] for k in range(36) for oc in range(8)]
    mult2, shift2 = model.rq["c2"]
    c2_flat, Np2 = await tb.tu_layer([v for r in rows2 for v in r],
                                     len(rows2), 36, 36, 8, W2, mult2, shift2)
    c2 = [c2_flat[(i // 8) * Np2 + i % 8] for i in range(oh2 * ow2 * 8)]
    c2 = [v if v > 0 else 0 for v in c2]

    a_words = opmaj_to_chw_words(c2, 8, 11, 11)   # CHW 1px/word: 8x121 = 968
    await tb.upload_words_dma(CORE_A, a_words, FENCE_POOL)
    params = [CORE_A, CORE_O, 25, 5, 8, 4 * 11, 121]   # 11 = input width
    await tb.run_kernel(os.path.join(KERNEL_DIR, "pool2d.asm"),
                        nblk=1, params=params)
    got = await tb.dbg_read_words(CORE_O, 25 * 8)
    p2_rtl = [(((w & 0xFF) - 256) if (w & 0xFF) >= 128 else (w & 0xFF))
              for w in got]
    p2_gold, _, _, _ = G.maxpool2_op(c2, 8, 5, 5, 11, 11)
    bad = [(i, p2_rtl[i], p2_gold[i]) for i in range(25 * 8)
           if p2_rtl[i] != p2_gold[i]]
    assert not bad, f"pool2 RTL: {len(bad)} mismatches: {bad[:8]}"

    # ---- 5) dense1 on TU (REAL requant: the TU always wraps to int8, so
    # the golden chain below requantizes dense1 identically) + relu in TB --
    multd1, shiftd1 = model.rq["d1"]
    d1_flat, _ = await tb.tu_layer(p2_rtl, 1, 200, 200, 32, model.d1q,
                                   multd1, shiftd1)
    d1r = [max(0, v) for v in d1_flat[:32]]

    # ---- 6) dense2 on TU -> requantized logits -----------------------------
    multd2, shiftd2 = model.rq["d2"]
    d2_flat, _ = await tb.tu_layer(d1r, 1, 32, 32, 10, model.d2q,
                                   multd2, shiftd2)
    logits_rtl = d2_flat[:10]
    digit = max(range(10), key=lambda i: logits_rtl[i])

    # golden: the SAME chain (p2 -> dense1 requant -> relu -> dense2 requant)
    gd1 = []
    for n in range(32):
        s = sum(p2_rtl[k] * model.d1q[k * 32 + n] for k in range(200))
        gd1.append(model.requant8(s, multd1, shiftd1))
    d1r_gold = [max(0, v) for v in gd1]
    gd2 = []
    for n in range(10):
        s = sum(d1r_gold[k] * model.d2q[k * 10 + n] for k in range(32))
        gd2.append(model.requant8(s, multd2, shiftd2))

    bad = [(i, logits_rtl[i], gd2[i]) for i in range(10)
           if logits_rtl[i] != gd2[i]]
    assert not bad, f"e2e logits: {len(bad)} mismatches: {bad}"
    print(f"E2E: rtl logits={logits_rtl} digit={digit}")
    print(f"E2E: golden logits={gd2} digit={G.argmax(gd2)}")
    assert digit == G.argmax(gd2), \
        f"digit {digit} != golden prediction {G.argmax(gd2)}"
    print("MNIST E2E PASS: image -> TU(conv) -> CORE(pool) -> TU(dense) "
          "-> digit (logits bit-exact)")
