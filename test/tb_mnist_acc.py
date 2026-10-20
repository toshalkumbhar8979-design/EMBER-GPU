"""
tb_mnist_acc.py — Phase-7f ACCURACY gate: real TRAINED weights, 100 t10k
images through the FULL RTL chain (TB-side im2col packing -> TU convs and
denses -> RTL core pools -> TB relu), digit = argmax of the VRAM logits.
Gate: accuracy >= 95/100.

Weights: data/mnist_trained.json (tools/train_mnist.py), loaded via
T.load_trained_model(). Requant params: per-layer mult/shift from the
checkpoint's activation calibration (act * s_w * 4096, shift 12) —
matches tb_mnist_e2e's chain exactly.

Phase-7f semantics note (the channel-scramble fix): the TU's C is
row-major = OP-MAJOR (op*Np + oc). Pooling must use maxpool2_op and the
opmaj_to_chw_words converter — plain maxpool2 / the old chw_to_words
read the op-major array plane-major and silently scrambled channels
(bit-exact vs the same-wrong golden with random weights; accuracy-fatal
with trained ones).

ocotb 2.1 note: use int(sig.value) and d.<sig>.value = x (no setattr).
"""
import json
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
import train_mnist as T  # noqa: E402

# ---------------------------------------------------------------- constants --
CP_STATUS = 0x04
CP_FIFOD, CP_DMA_DST, CP_DMA_LEN, CP_CMDX = 0x10, 0x14, 0x18, 0x1C
CP_TU_A, CP_TU_W, CP_TU_C, CP_TU_CFG2, CP_TU_KICK = 0x58, 0x5C, 0x60, 0x64, 0x68
CP_CORE_CODE, CP_CORE_NBLK, CP_CORE_KICK = 0x4C, 0x50, 0x54

A_OFF, W_OFF, C_OFF = 0x20000, 0x45000, 0x6A000
CORE_A, CORE_O = 0x25000, 0x28000   # CORE_A needs 2704 words; NO overlap
CMDBUF_OFF = 0x5B000
CODEBUF_OFF = CMDBUF_OFF + 0x400

FENCE_TENS, FENCE_POOL, FENCE_CODE = 9, 5, 7
M32 = 0xFFFFFFFF
KICK_TIMEOUT = 8_000_000

CKPT = os.environ.get(
    "ACC_CKPT",
    os.path.join(os.path.dirname(__file__), "..", "data",
                 "mnist_trained.json"))

N_EVAL = int(os.environ.get("ACC_N", "100"))
GATE = int(os.environ.get("ACC_GATE", "95"))


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
    one-pixel-per-word raw-byte words (the pool kernel's VRAM contract)."""
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


# ---- bias fold (the TU has no bias add): each layer's K grows by THREE ----
# A rows carry fixed int8 taps [+127, -127, 1] and W carries rows [t, -t, 0]
# (t from model.b*_acc; contribution 127*t — both operands int8-legal).
# t itself may reach +/-254, so the W rows are the SPLIT r1 = round(t/2),
# r2row = r1 - t (both provably in [-127,127]): 127*r1 - 127*r2row = 127*t.
# K dims: conv1 12, conv2 39, dense1 203, dense2 35.
def _bias_rows(t):
    t = max(-254, min(254, t))
    r1 = int(round(t / 2))
    r2 = r1 - t
    return r1, r2


def conv1_A(rows1):
    return [r + [127, -127, 1] for r in rows1]


def conv1_W(model):
    # W is ROW-major (row k = one entry per output channel!), so the bias
    # block must be emitted as rows [r1_*], [r2_*], [0,0,0,0] — NOT as
    # per-channel [r1, r2, 0] triples (that scrambles channels).
    W = []
    for k in range(9):
        W += [model.c1q[oc][k] for oc in range(4)]
    rows1, rows2 = zip(*(_bias_rows(t) for t in model.b1_acc))
    W += list(rows1)
    W += list(rows2)
    W += [0, 0, 0, 0]
    return W


def conv2_A(rows2):
    return [r + [127, -127, 1] for r in rows2]


def conv2_W(model):
    W = []
    for k in range(36):
        W += [model.c2q[oc][k] for oc in range(8)]
    rows1, rows2 = zip(*(_bias_rows(t) for t in model.b2_acc))
    W += list(rows1)
    W += list(rows2)
    W += [0] * 8
    return W


def dense1_A(p2):
    return list(p2) + [127, -127, 1]


def dense1_W(model):
    W = list(model.d1q)
    rows1, rows2 = zip(*(_bias_rows(t) for t in model.d1b_acc))
    W += list(rows1)
    W += list(rows2)
    W += [0] * 32
    return W


def dense2_A(d1r):
    return list(d1r) + [127, -127, 1]


def dense2_W(model):
    W = list(model.d2q)
    rows1, rows2 = zip(*(_bias_rows(t) for t in model.d2b_acc))
    W += list(rows1)
    W += list(rows2)
    W += [0] * 10
    return W


KERNEL_DIR = os.path.join(os.path.dirname(__file__), "..", "kernels")


# ------------------------------------------------------------------- test --
@cocotb.test()
async def test_mnist_acc(dut):
    """100 t10k images through the RTL chain with TRAINED weights; >=95%."""
    cocotb.start_soon(Clock(dut.clk, CLK_NS, unit="ns").start())
    tb = EmberTB(dut)
    await tb.reset()

    with open(CKPT) as fh:
        ck = json.load(fh)
    model = T.load_trained_model(CKPT)
    imgs = T.load_idx_images(
        os.path.join(T.DATA_DIR, "t10k-images-idx3-ubyte"), max_n=N_EVAL)
    labels = T.load_idx_labels(
        os.path.join(T.DATA_DIR, "t10k-labels-idx1-ubyte"), max_n=N_EVAL)
    assert len(imgs) == N_EVAL and len(labels) == N_EVAL

    mult1, shift1 = model.rq["c1"]
    mult2, shift2 = model.rq["c2"]
    multd1, shiftd1 = model.rq["d1"]
    multd2, shiftd2 = model.rq["d2"]

    # Pool kernel code is image-independent: upload ONCE (the per-image
    # kick only DMAs the 7-word params).
    with open(os.path.join(KERNEL_DIR, "pool2d.asm")) as fh:
        pool_words = assembler.run_assembler(fh.read())
    await tb.upload_words_dma(CODEBUF_OFF, pool_words, FENCE_CODE)

    per_digit_rtl = [0] * 10
    per_digit_sw = [0] * 10
    correct = 0
    mismatched = []
    for n in range(N_EVAL):
        # load_idx_images ALREADY returns pixel-128 bytes in [-128,127] —
        # feed them AS-IS. (Any extra rescale/shift here changes the input
        # distribution the quantized net was calibrated on; the old
        # round(v*127/255) formula additionally rescaled the shifted
        # bytes and would fail the RTL-vs-software mirror assert.)
        img_q = [max(-128, min(127, v)) for v in imgs[n]]

        # ---- conv1 on TU (bias fold: K = 12) ---------------------------
        rows1, oh1, ow1 = G.im2col(img_q, 1, 28, 28, 3)
        A1 = conv1_A(rows1)      # taps [+127, -127, 1] (see bias fold)
        c1_flat, Np1 = await tb.tu_layer([v for r in A1 for v in r],
                                         len(A1), 12, 12, 4, conv1_W(model),
                                         mult1, shift1)
        c1 = [c1_flat[(i // 4) * Np1 + i % 4] for i in range(oh1 * ow1 * 4)]
        # ReLU after conv1 (trained WITH it). max(0,.) commutes with
        # max-pool, so clamping HERE makes the untouched pool kernel
        # implement ReLU+pool exactly. Same after conv2 below.
        c1_pre = list(c1)
        c1 = [v if v > 0 else 0 for v in c1]
        if n < 3:
            # Operand forensics AT CONV1 TIME (later layers overwrite
            # A_OFF/W_OFF — readback must happen here): first W words,
            # first A words, and the raw C word 0.
            w1_rtl = await tb.dbg_read_words(W_OFF, 16)
            w1_exp = pack_words(pad_w(conv1_W(model), 12, 4)[0])[:16]
            a1_rtl = await tb.dbg_read_words(A_OFF, 8)
            a1_exp = pack_words(pad_w([v for r in A1 for v in r],
                                      len(A1), 12)[0])[:8]
            c0_rtl = await tb.dbg_read_words(C_OFF, 4)
            print(f"  OPS img{n}: W1 rtl ={[hex(w) for w in w1_rtl[:6]]}",
                  flush=True)
            print(f"  OPS img{n}: W1 exp ={[hex(w) for w in w1_exp[:6]]}",
                  flush=True)
            print(f"  OPS img{n}: W1 bad={sum(1 for r, e in zip(w1_rtl, w1_exp) if r != e)}/16",
                  flush=True)
            print(f"  OPS img{n}: A1 rtl ={[hex(w) for w in a1_rtl[:4]]}",
                  flush=True)
            print(f"  OPS img{n}: A1 exp ={[hex(w) for w in a1_exp[:4]]}",
                  flush=True)
            print(f"  OPS img{n}: A1 bad={sum(1 for r, e in zip(a1_rtl, a1_exp) if r != e)}/8",
                  flush=True)
            print(f"  OPS img{n}: C0 raw={[hex(w) for w in c0_rtl]}",
                  flush=True)
            print(f"  OPS img{n}: c1_pre[0:8]={c1_pre[:8]}", flush=True)

        # ---- pool1 on the RTL CORE (CHW 1px/word; ws4 = 4*26 INPUT) ----
        a_words = opmaj_to_chw_words(c1, 4, 26, 26)
        await tb.upload_words_dma(CORE_A, a_words, FENCE_POOL)
        params = [CORE_A, CORE_O, 169, 13, 4, 4 * 26, 676]
        await self_run_kernel(tb, nblk=1, params=params)
        got = await tb.dbg_read_words(CORE_O, 169 * 4)
        p1_rtl = [s8(w) for w in got]

        # ---- conv2 on TU (bias fold: K = 39) ---------------------------
        rows2, oh2, ow2 = G.im2col(p1_rtl, 4, 13, 13, 3)
        A2 = conv2_A(rows2)
        c2_flat, Np2 = await tb.tu_layer([v for r in A2 for v in r],
                                         len(A2), 39, 39, 8, conv2_W(model),
                                         mult2, shift2)
        c2 = [c2_flat[(i // 8) * Np2 + i % 8] for i in range(oh2 * ow2 * 8)]
        c2 = [v if v > 0 else 0 for v in c2]

        # ---- pool2 on the RTL CORE (ws4 = 4*11 INPUT width) ------------
        a_words = opmaj_to_chw_words(c2, 8, 11, 11)
        await tb.upload_words_dma(CORE_A, a_words, FENCE_POOL)
        params = [CORE_A, CORE_O, 25, 5, 8, 4 * 11, 121]
        await self_run_kernel(tb, nblk=1, params=params)
        got = await tb.dbg_read_words(CORE_O, 25 * 8)
        p2_rtl = [s8(w) for w in got]

        # ---- dense1 on TU (bias fold K = 203, REAL requant) + ReLU -----
        d1_flat, _ = await tb.tu_layer(dense1_A(p2_rtl), 1, 203,
                                       203, 32, dense1_W(model),
                                       multd1, shiftd1)
        d1r = [max(0, v) for v in d1_flat[:32]]

        # ---- dense2 on TU (bias fold K = 35) -> logits -> digit --------
        d2_flat, _ = await tb.tu_layer(dense2_A(d1r), 1, 35,
                                       35, 10, dense2_W(model),
                                       multd2, shiftd2)
        logits_rtl = d2_flat[:10]
        digit = max(range(10), key=lambda i: logits_rtl[i])

        # Software cross-check (SAME contract, run in-process).
        sw = T.predict_int8(model, img_q)

        # Stage-by-stage mirror (finds the FIRST diverging RTL stage when
        # the digit disagrees). Note p1/p2 mirror taps the pre-ReLU conv
        # outputs: max(0, max(taps)) == max(max(0, taps), taps).
        if digit != sw:
            ks = tuple(v[1] for v in model.rq.values())
            sout = T._int8_forward(img_q, model.c1q, model.c2q, model.d1q,
                                   model.d2q, model.b1_acc, model.b2_acc,
                                   model.d1b_acc, model.d2b_acc, ks)
            for sname, rtlv, golv in (("c1", c1, sout["c1"]),
                                      ("p1", p1_rtl, sout["p1"]),
                                      ("p2", p2_rtl, sout["p2"]),
                                      ("d1r", d1r, sout["d1"]),
                                      ("logits", logits_rtl, sout["logits"])):
                bad = [(i, r, g) for i, (r, g) in enumerate(zip(rtlv, golv))
                       if r != g]
                print(f"  DIAG img{n} {sname}: {len(bad)} mismatches "
                      f"{bad[:6]}", flush=True)
            # W1/A1 readback: are the TU's actual operands what we think?
            w1_rtl = await tb.dbg_read_words(W_OFF, 40)
            w1_exp = pack_words(pad_w(conv1_W(model), 10, 4)[0])[:40]
            wbad = [(i, r, e) for i, (r, e)
                    in enumerate(zip(w1_rtl, w1_exp)) if r != e]
            print(f"  DIAG img{n} W1: {len(wbad)} bad words {wbad[:4]}",
                  flush=True)
            a1_rtl = await tb.dbg_read_words(A_OFF, 40)
            a1_exp = pack_words(pad_w([v for r in A1 for v in r],
                                      len(A1), 12)[0])[:40]
            abad = [(i, r, e) for i, (r, e)
                    in enumerate(zip(a1_rtl, a1_exp)) if r != e]
            print(f"  DIAG img{n} A1: {len(abad)} bad words {abad[:4]}",
                  flush=True)

        lab = labels[n]
        if digit == lab:
            correct += 1
            per_digit_rtl[lab] += 1
        if sw == lab:
            per_digit_sw[lab] += 1
        if digit != sw:
            mismatched.append((n, digit, sw, lab))

        if (n + 1) % 10 == 0:
            print(f"[{n + 1:3d}/{N_EVAL}] acc so far "
                  f"{100.0 * correct / (n + 1):5.1f}% (sw "
                  f"{100.0 * (sum(per_digit_sw)) / (n + 1):5.1f}%)",
                  flush=True)

    acc = 100.0 * correct / N_EVAL
    acc_sw = 100.0 * sum(per_digit_sw) / N_EVAL
    print(f"RTL ACCURACY: {correct}/{N_EVAL} = {acc:.1f}%  "
          f"(software mirror: {acc_sw:.1f}%)")
    if mismatched:
        print(f"RTL-vs-software disagreements: {mismatched[:10]} "
              f"(total {len(mismatched)})")
    assert not mismatched, \
        f"RTL logits disagree with the software mirror on {len(mismatched)} images"
    assert acc >= GATE, f"accuracy {acc:.1f}% < {GATE}% gate"
    print(f"MNIST ACC PASS: {correct}/{N_EVAL} = {acc:.1f}% >= {GATE}% "
          "through the FULL RTL chain (trained weights)")


async def self_run_kernel(tb, nblk, params):
    """run_kernel variant that reuses the pre-uploaded pool kernel code
    (only the params DMAs are per-image)."""
    await tb.upload_words_dma(CMDBUF_OFF, params, FENCE_POOL)
    await tb.reg_write(CP_CORE_CODE, CODEBUF_OFF)
    await tb.reg_write(CP_CORE_NBLK, nblk)
    await tb.reg_write(CP_CORE_KICK, 1)
    for _ in range(KICK_TIMEOUT):
        await RisingEdge(tb.dut.clk)
        if ((await tb.reg_read(CP_STATUS)) >> 9) & 1 == 0:
            return
    raise AssertionError("core_busy stuck high (pool kernel)")
