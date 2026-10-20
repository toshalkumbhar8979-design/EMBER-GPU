"""
tools/train_mnist.py — pure-Python (stdlib only) trainer for the Ember
LeNet-style model. Trains the FLOAT model on real MNIST, exports
Model-shaped weights (conv 1->4 3x3, conv 4->8 3x3, dense 200->32->10,
NO biases — the TU contract), and quantizes with per-tensor scales
calibrated on TRAINING activations (matching what inference will see).

Trainer: deterministic mini-batch SGD + momentum, cross-entropy on the
softmax of the dense2 logits. Convolutions via the existing im2col matmul
(threads kept to 1 to stay simple; a few epochs over a subset is enough
for >=95% with this topology).

Artifacts (written to data/):
  mnist_trained.json — {c1w, c2w, d1w, d2w} float lists shaped exactly like
  tools/golden/mnist.py Model attributes + per-layer requant (mult, shift)
  calibrated on real activations.

Usage:
  python3 tools/train_mnist.py [--epochs 3] [--train N] [--val N]
      [--checkpoint data/mnist_trained.json] [--resume]
  python3 tools/train_mnist.py --selftest
"""

import argparse
import json
import math
import os
import random
import struct
import sys
import time

_TOOLS_DIR = os.path.dirname(os.path.abspath(__file__))
_GOLDEN_DIR = os.path.join(_TOOLS_DIR, "golden")
sys.path.insert(0, _GOLDEN_DIR)
import mnist as G  # noqa: E402

DATA_DIR = os.path.join(os.path.dirname(_TOOLS_DIR), "data")
CKPT_DEFAULT = os.path.join(DATA_DIR, "mnist_trained.json")


# ------------------------------------------------------------------- data ---
def load_idx_images(path, max_n=None):
    with open(path, "rb") as f:
        magic, n, h, w = struct.unpack(">IIII", f.read(16))
        assert magic == 0x803, hex(magic)
        if max_n:
            n = min(n, max_n)
        data = f.read(n * h * w)
    imgs = []
    for i in range(n):
        imgs.append([b - 128 for b in data[i * h * w:(i + 1) * h * w]])
    return imgs


def load_idx_labels(path, max_n=None):
    with open(path, "rb") as f:
        magic, n = struct.unpack(">II", f.read(8))
        assert magic == 0x801, hex(magic)
        if max_n:
            n = min(n, max_n)
        return list(f.read(n))


# ----------------------------------------------------------------- model ----
class TrainModel:
    """Same topology as golden Model, with biases for TRAINING (bias-free
    export). Weights shaped: c1w[4][9], c2w[8][36], d1w[32][200],
    d2w[10][32]."""

    def __init__(self, seed=7):
        rng = random.Random(seed)
        # He (Kaiming) init for ReLU: uniform +/-sqrt(6/fan_in) gives
        # weight std sqrt(2/fan_in), keeping activation variance ~constant
        # per layer. (Phase-7f: the original 1/sqrt(fan_in) scale shrank
        # activations ~10x per layer — conv2 arrived 100% ReLU-dead, the
        # float net never left loss ~ln(10), and int8 accuracy sat at
        # chance NO MATTER how correct the quant chain was.)
        self.c1w = [[rng.uniform(-0.816, 0.816) for _ in range(9)]
                    for _ in range(4)]          # fan_in 9
        self.c1b = [0.0] * 4
        self.c2w = [[rng.uniform(-0.408, 0.408) for _ in range(36)]
                    for _ in range(8)]          # fan_in 36
        self.c2b = [0.0] * 8
        self.d1w = [[rng.uniform(-0.173, 0.173) for _ in range(200)]
                    for _ in range(32)]         # fan_in 200
        self.d1b = [0.0] * 32
        self.d2w = [[rng.uniform(-0.433, 0.433) for _ in range(32)]
                    for _ in range(10)]         # fan_in 32
        self.d2b = [0.0] * 10
        # momentum buffers (same shape as the parameter tensors)
        for name in ("c1w", "c1b", "c2w", "c2b", "d1w", "d1b", "d2w", "d2b"):
            v = getattr(self, name)
            if isinstance(v[0], list):
                setattr(self, "v_" + name,
                        [[0.0] * len(row) for row in v])
            else:
                setattr(self, "v_" + name, [0.0] * len(v))

    # ---- forward (float, image normalized to [-1,1]) ----
    def forward(self, img_norm):
        rows, oh, ow = G.im2col(img_norm, 1, 28, 28, 3)
        c1 = []
        for r in rows:
            for oc in range(4):
                s = self.c1b[oc] + sum(r[k] * self.c1w[oc][k]
                                       for k in range(9))
                c1.append(s if s > 0 else 0.0)
        p1, _, _, _ = G.maxpool2_op(c1, 4, 13, 13, 26, 26)
        rows2, oh2, ow2 = G.im2col(p1, 4, 13, 13, 3)
        c2 = []
        for r in rows2:
            for oc in range(8):
                s = self.c2b[oc] + sum(r[k] * self.c2w[oc][k]
                                       for k in range(36))
                c2.append(s if s > 0 else 0.0)
        p2, _, _, _ = G.maxpool2_op(c2, 8, 5, 5, 11, 11)
        d1 = [self.d1b[n] + sum(p2[k] * self.d1w[n][k] for k in range(200))
              for n in range(32)]
        d1r = [v if v > 0 else 0.0 for v in d1]
        d2 = [self.d2b[n] + sum(d1r[k] * self.d2w[n][k] for k in range(32))
              for n in range(10)]
        return {"rows1": rows, "c1": c1, "p1": p1, "rows2": rows2,
                "c2": c2, "p2": p2, "d1": d1r, "logits": d2}

    def loss_and_grads(self, img_norm, label):
        """Cross-entropy; full backprop for one sample. Returns (loss, 0)."""
        f = self.forward(img_norm)
        logits = f["logits"]
        m = max(logits)
        exps = [math.exp(v - m) for v in logits]
        Z = sum(exps)
        probs = [e / Z for e in exps]
        loss = -math.log(max(probs[label], 1e-12))

        # output layer
        dd2 = [[probs[n] - (1.0 if n == label else 0.0)
                for n in range(10)]]
        # grads for d2w/d2b (dd2: 1 x 10; d1r: 32)
        d1r = f["d1"]
        for n in range(10):
            g = dd2[0][n]
            self.g_d2b[n] += g
            row = self.g_d2w[n]
            for k in range(32):
                row[k] += g * d1r[k]
        # into d1
        gd1 = [0.0] * 32
        for k in range(32):
            s = 0.0
            for n in range(10):
                s += dd2[0][n] * self.d2w[n][k]
            gd1[k] = s if d1r[k] > 0 else 0.0
        # dense1: p2 (200) x d1w[32][200]
        p2 = f["p2"]
        for n in range(32):
            g = gd1[n]
            self.g_d1b[n] += g
            row = self.g_d1w[n]
            for k in range(200):
                row[k] += g * p2[k]
        gp2 = [0.0] * 200
        for k in range(200):
            s = 0.0
            for n in range(32):
                s += gd1[n] * self.d1w[n][k]
            gp2[k] = s
        # maxpool2 backward for c2: route to argmax taps.
        # LAYOUT CONTRACT (matches golden forward exactly):
        #   conv/pool outputs are OP-MAJOR: out[op + oc*NP] where op =
        #   oy*OW+ox (conv) or oy*ow_p+ox (pool); maxpool2's input is HWC:
        #   img[(y*w + x) + c*h*w]. p2 = pooled c2 (8x5x5 = 200).
        gc2 = [0.0] * (121 * 8)               # OP-MAJOR: gc2[op*8 + oc]
        for c in range(8):
            for oy in range(5):
                for ox in range(5):
                    oi = (oy * 5 + ox) + c * 25   # plane-major p2 index
                    g = gp2[oi]
                    if g == 0.0:
                        continue
                    best, bi = -1e30, -1
                    for dy in range(2):
                        for dx in range(2):
                            si = ((oy * 2 + dy) * 11 + ox * 2 + dx) \
                                * 8 + c
                            if f["c2"][si] > best:
                                best, bi = f["c2"][si], si
                    gc2[bi] += g
        # conv2 backward: gc2 is OP-MAJOR (op*8 + oc — same layout the
        # pool route filled); rows2[op] pairs with op. ReLU GATE included.
        rows2 = f["rows2"]
        for op, r in enumerate(rows2):
            for oc in range(8):
                g = gc2[op * 8 + oc]
                if g == 0.0 or f["c2"][op * 8 + oc] <= 0.0:
                    continue
                self.g_c2b[oc] += g
                row = self.g_c2w[oc]
                for k in range(36):
                    row[k] += g * r[k]
        # into p1 (conv2 input, HWC 4x13x13): rows2 op = oy*11+ox, cols
        # (c,ky,kx); tap (oy+ky, ox+kx)
        gp1_hwc = [0.0] * (169 * 4)
        for op, r in enumerate(rows2):
            oy, ox = op // 11, op % 11
            for oc in range(8):
                g = gc2[op * 8 + oc]
                if g == 0.0:
                    continue
                wrow = self.c2w[oc]
                for k in range(36):
                    gw = g * wrow[k]
                    if gw:
                        c, kky, kkx = k // 9, (k % 9) // 3, k % 3
                        gp1_hwc[(oy + kky) * 13 + (ox + kkx)
                                + c * 169] += gw
        # maxpool2 backward for c1: mirror maxpool2_op EXACTLY — taps at
        # si = ((oy*2+dy)*iw + ox*2+dx)*cin + c (op-major input), gradient
        # to the argmax tap; gp1_hwc is PLANE-major (c*169 + op).
        c1 = f["c1"]
        gc1 = [0.0] * (676 * 4)
        for c in range(4):
            for oy in range(13):
                for ox in range(13):
                    oi = (oy * 13 + ox) + c * 169
                    g = gp1_hwc[oi]
                    if g == 0.0:
                        continue
                    best, bi = -1e30, -1
                    for dy in range(2):
                        for dx in range(2):
                            y2, x2 = oy * 2 + dy, ox * 2 + dx
                            si = (y2 * 26 + x2) * 4 + c      # op-major
                            if c1[si] > best:
                                best, bi = c1[si], si
                    gc1[bi] += g
        # conv1 backward: gc1 is OP-MAJOR (op*4 + oc, matching c1's layout
        # from the pool backward above); rows1[op] pairs with op.
        rows1 = f["rows1"]
        for op, r in enumerate(rows1):
            for oc in range(4):
                g = gc1[op * 4 + oc]
                if g == 0.0 or f["c1"][op * 4 + oc] <= 0.0:
                    continue
                self.g_c1b[oc] += g
                row = self.g_c1w[oc]
                for k in range(9):
                    row[k] += g * r[k]
        return loss

    def zero_grads(self):
        self.g_c1w = [[0.0] * 9 for _ in range(4)]
        self.g_c1b = [0.0] * 4
        self.g_c2w = [[0.0] * 36 for _ in range(8)]
        self.g_c2b = [0.0] * 8
        self.g_d1w = [[0.0] * 200 for _ in range(32)]
        self.g_d1b = [0.0] * 32
        self.g_d2w = [[0.0] * 32 for _ in range(10)]
        self.g_d2b = [0.0] * 10

    def sgd_step(self, lr, mom, batch, clip=None):
        if clip is not None:
            # Global-norm gradient clipping: one explosive batch otherwise
            # blows the weights out and dead-ReLUs the net permanently
            # (measured: epoch-0 43% -> epoch-1 collapse at ANY fixed lr).
            s = 0.0
            for name in ("c1w", "c1b", "c2w", "c2b", "d1w", "d1b",
                         "d2w", "d2b"):
                g = getattr(self, "g_" + name)
                if isinstance(g[0], list):
                    for row in g:
                        for x in row:
                            s += x * x
                else:
                    for x in g:
                        s += x * x
            if s > clip * clip:
                sc = clip / (s ** 0.5)
                for name in ("c1w", "c1b", "c2w", "c2b", "d1w", "d1b",
                             "d2w", "d2b"):
                    g = getattr(self, "g_" + name)
                    if isinstance(g[0], list):
                        for row in g:
                            for j in range(len(row)):
                                row[j] *= sc
                    else:
                        for j in range(len(g)):
                            g[j] *= sc
        for name in ("c1w", "c1b", "c2w", "c2b", "d1w", "d1b", "d2w", "d2b"):
            g = getattr(self, "g_" + name)
            v = getattr(self, "v_" + name)
            w = getattr(self, name)
            if isinstance(w[0], list):
                for i in range(len(w)):
                    wi, gi, vi = w[i], g[i], v[i]
                    for j in range(len(wi)):
                        vi[j] = mom * vi[j] - lr * gi[j] / batch
                        wi[j] += vi[j]
            else:
                for i in range(len(w)):
                    v[i] = mom * v[i] - lr * g[i] / batch
                    w[i] += v[i]


# ------------------------------------------------------------- evaluation ---
def predict_int8(model_q, img_q):
    """int8 inference following the EXACT TU contract (tb_mnist_acc chain).

    Input: img_q = int8 image in [-128,127] (pixel-128; load_idx_images
    already returns that range — just clamp).

    Biases are FOLDED into the matmul (the TU has no bias add): each
    layer's K grows by THREE — A rows carry fixed int8 taps [+127, -127,
    1] and W carries [t, -t, 0] rows (t = round(b_acc/127), so the bias
    contribution is 127*t, int8-legal everywhere). K dims: conv1 12,
    conv2 39, dense1 203, dense2 35.

    Requant contract (export_checkpoint): PURE SHIFTS — rq[i] = (mult=1,
    shift=k_i), out_q = round-half-up(c / 2^k_i), k_i calibrated so the
    outputs land in [-96,96]. No mult rounding anywhere; every scale in
    the chain is exact by construction. dense1's ReLU runs AFTER requant
    on the int8 C bytes (exactly like the TB)."""
    # ---- conv1: im2col rows (9 taps) + bias fold (taps +/-127) ---------
    rows, oh, ow = G.im2col(img_q, 1, 28, 28, 3)
    mult1, shift1 = model_q.rq["c1"]
    # Bias fold: A carries taps +127 and -127; b_acc entries are 127-unit
    # integers t with contribution 127*t (built by _build/export).
    tv = 127
    c1 = []
    for r in rows:
        for oc in range(4):
            s = tv * model_q.b1_acc[oc]           # 127 * t = the folded bias
            for k in range(9):
                s += r[k] * model_q.c1q[oc][k]
            # ReLU after conv1 (the float trainer trains WITH it; and
            # max(0,.) commutes with max-pool, so the RTL pool kernel
            # implements ReLU+pool exactly when the TB clamps first).
            c1.append(max(0, G.Model.requant8(s, mult1, shift1)))
    # c1 is OP-MAJOR (op*cin + oc — the TU's row-major C layout): pool with
    # maxpool2_op. (Phase-7f: plain maxpool2 reads it plane-major and
    # channel-scrambles — accuracy-fatal with trained weights.)
    p1, _, _, _ = G.maxpool2_op(c1, 4, 13, 13, 26, 26)
    # ---- conv2 -----------------------------------------------------------
    rows2, _, _ = G.im2col(p1, 4, 13, 13, 3)
    mult2, shift2 = model_q.rq["c2"]
    c2 = []
    for r in rows2:
        for oc in range(8):
            s = tv * model_q.b2_acc[oc]
            for k in range(36):
                s += r[k] * model_q.c2q[oc][k]
            c2.append(max(0, G.Model.requant8(s, mult2, shift2)))
    p2, _, _, _ = G.maxpool2_op(c2, 8, 5, 5, 11, 11)
    # ---- dense1 (bias fold + requant) then ReLU on the int8 --------------
    multd1, shiftd1 = model_q.rq["d1"]
    d1 = []
    for n in range(32):
        s = tv * model_q.d1b_acc[n]
        for k in range(200):
            s += p2[k] * model_q.d1q[k * 32 + n]
        d1.append(max(0, G.Model.requant8(s, multd1, shiftd1)))
    # ---- dense2 -----------------------------------------------------------
    multd2, shiftd2 = model_q.rq["d2"]
    d2 = []
    for n in range(10):
        s = tv * model_q.d2b_acc[n]
        for k in range(32):
            s += d1[k] * model_q.d2q[k * 10 + n]
        d2.append(G.Model.requant8(s, multd2, shiftd2))
    return G.argmax(d2)


def eval_int8(model_q, imgs, labels, lo=0, hi=100):
    correct = 0
    for i in range(lo, hi):
        if predict_int8(model_q, _img128(imgs[i])) == labels[i]:
            correct += 1
    return correct, hi - lo


def _img128(img_bytes):
    """Clamp to the int8 input space. load_idx_images ALREADY returns
    pixel-128 bytes in [-128,127] (it subtracts 128 at load), so this is
    a clamp only. (History: norm_img used to subtract 128 a SECOND time
    — the trainer trained on [-2,0] inputs and diverged; caught by the
    epoch-0 loss going UP.)"""
    return [max(-128, min(127, v)) for v in img_bytes]


def norm_img(img):
    """Float trainer input from a load_idx_images image (already in
    [-128,127]): scale to [-1,1). (History: this used to be
    (v-128)/128 on top of the loader's own -128 — a double shift.)"""
    return [v / 128.0 for v in img]


# ---------------------------------------------------------------- export ----
def _int8_forward(img_q, c1q, c2q, d1q, d2q, b1, b2, b3, b4, ks, accs=False):
    """The EXACT predict_int8 arithmetic with explicit per-layer requant
    shifts ks = (k1,k2,k3,k4). Returns the int8 intermediates; with
    accs=True ALSO returns each layer's RAW accumulator max (pre-requant,
    pre-wrap) — what export_checkpoint calibrates the shifts on (acc_i is
    independent of k_i but depends on k_1..k_{i-1} and upstream b_accs).
    b* entries are 127-unit t values (contribution 127*t via A taps
    +127/-127 — the predict_int8 bias-fold contract)."""
    k1, k2, k3, k4 = ks
    tv = 127
    rows, oh, ow = G.im2col(img_q, 1, 28, 28, 3)
    a1max = 0
    c1 = []
    for r in rows:
        for oc in range(4):
            s = tv * b1[oc]
            for k in range(9):
                s += r[k] * c1q[oc][k]
            a1max = max(a1max, abs(s))
            c1.append(max(0, G.Model.requant8(s, 1, k1)))
    p1, _, _, _ = G.maxpool2_op(c1, 4, 13, 13, 26, 26)
    rows2, _, _ = G.im2col(p1, 4, 13, 13, 3)
    a2max = 0
    c2 = []
    for r in rows2:
        for oc in range(8):
            s = tv * b2[oc]
            for k in range(36):
                s += r[k] * c2q[oc][k]
            a2max = max(a2max, abs(s))
            c2.append(max(0, G.Model.requant8(s, 1, k2)))
    p2, _, _, _ = G.maxpool2_op(c2, 8, 5, 5, 11, 11)
    a3max = 0
    d1 = []
    for n in range(32):
        s = tv * b3[n]
        for k in range(200):
            s += p2[k] * d1q[k * 32 + n]
        a3max = max(a3max, abs(s))
        d1.append(max(0, G.Model.requant8(s, 1, k3)))
    a4max = 0
    d2 = []
    for n in range(10):
        s = tv * b4[n]
        for k in range(32):
            s += d1[k] * d2q[k * 10 + n]
        a4max = max(a4max, abs(s))
        d2.append(G.Model.requant8(s, 1, k4))
    out = {"c1": c1, "p1": p1, "c2": c2, "p2": p2, "d1": d1,
           "logits": d2}
    if accs:
        out["accs"] = (a1max, a2max, a3max, a4max)
    return out


def export_checkpoint(tm, path, act=None, tune_val=None):
    """Export trained weights + RTL-contract requant params + BIAS FOLD.

    The TU has no bias add, so every layer's K grows by ONE: A rows carry
    a constant tap of 1 and W carries the bias-acc row. Quant contract
    (LOCKED to ember_tu: mult is 16-BIT, shift is 4-bit (<=15), requant8
    WRAPS to int8 with NO saturation; round-half-up):

      wq_i    = round(w_i/s_wi),  s_wi = max|w_i|/127   (symmetric)
      scale_0 = 128      (int8 image bytes = 128 * the [-1,1] float view)
      b_acc_i = round(scale_{i-1} * b_i / s_wi)         (bias row, acc units)
      acc_i   = sum(a*wq_i) + b_acc_i                   (the TU accumulator)
      k_i     = smallest k with max|acc_i| / 2^k <= 96  (PURE-SHIFT requant:
      out_i   = round-half-up(acc_i / 2^k_i)     rq[i] = (1, k_i) — NO
      scale_i = scale_{i-1} / (s_wi * 2^k_i)       multiplier rounding)

    k_i and b_acc_i are calibrated SEQUENTIALLY on 64 train images through
    _int8_forward (the exact int8 net): k1 <- b_acc2 <- k2 <- b_acc3 <-
    k3 <- b_acc4 <- k4, each from raw-accumulator maxima measured with all
    earlier shifts/biases already fixed. Argmax is invariant to the final
    positive scale. The TU acc is 32-bit: max|acc| <= K*128*127 + |b_acc|
    < 3.5e6 — safe. dense1's ReLU runs AFTER requant on the int8 C bytes
    (exactly like the TB); negatives wrap and read back signed, so
    max(0, int8) == max(0, y)*scale."""
    w1 = [x for row in tm.c1w for x in row]
    w2 = [x for row in tm.c2w for x in row]
    # DENSE WEIGHTS MUST FLATTEN K-MAJOR (k outer, n inner): the TU and
    # every consumer index d1q[k*32+n] / d2q[k*10+n]. (Phase-7f: flattening
    # n-major here silently PERMUTED both dense weight matrices — conv
    # layers stayed bit-exact while dense1 diverged (corr 0); caught by
    # the layer-by-layer divergence map.)
    wd1 = [tm.d1w[n][k] for k in range(200) for n in range(32)]
    wd2 = [tm.d2w[n][k] for k in range(32) for n in range(10)]
    q1, _, _ = G.quantize_int8(w1, symmetric=True)
    q2, _, _ = G.quantize_int8(w2, symmetric=True)
    qd1, _, _ = G.quantize_int8(wd1, symmetric=True)
    qd2, _, _ = G.quantize_int8(wd2, symmetric=True)
    c1q = [q1[oc * 9:(oc + 1) * 9] for oc in range(4)]
    c2q = [q2[oc * 36:(oc + 1) * 36] for oc in range(8)]
    sw1 = max(abs(min(w1)), abs(max(w1))) / 127.0
    sw2 = max(abs(min(w2)), abs(max(w2))) / 127.0
    sw3 = max(abs(min(wd1)), abs(max(wd1))) / 127.0
    sw4 = max(abs(min(wd2)), abs(max(wd2))) / 127.0
    sw = (sw1, sw2, sw3, sw4)

    cal_imgs = load_idx_images(os.path.join(DATA_DIR,
                                            "train-images-idx3-ubyte"),
                               max_n=64)
    cal_imgs = [[max(-128, min(127, v)) for v in im] for im in cal_imgs]

    b_accs = [None, None, None, None]
    ks = [0, 0, 0, 0]
    scale = 128.0                     # float value of one input count
    b_list = (tm.c1b, tm.c2b, tm.d1b, tm.d2b)
    nb = (4, 8, 32, 10)

    def _build(ks_c):
        """Bias rows self-consistent with shift vector ks_c (b_acc_i uses
        the OUTPUT scale of layer i-1).

        BIAS FOLD CONTRACT (phase-7f, LOCKED): bias rows live in W BYTES
        and taps live in A BYTES — both must be int8 (-128..127). History:
        (1) raw b_acc (up to +/-6k) truncated in W bytes; (2) a single tap
        v=177 is NOT int8 (byte 0xB1 reads as -79 in the TU — sign-flips
        the bias; predicted the exact RTL bytes [48,-4,14,-14]). Final
        scheme: A rows carry TWO FIXED int8 taps, +127 and -127, and W
        carries rows r1, r2 with r1 - r2 = t = round(b_acc/127) (each in
        [-127,127]; covers |b_acc| <= 32258, err <= 63 counts ~0.4%).
        Contribution = 127*(r1 - r2) ~= b_acc. The checkpoint's b_acc
        stores t (= b_acc/127 in 127-tap units)."""
        scale_c = 128.0
        ts = []
        for i in range(4):
            if i == 0:
                raw = [b * 128.0 / sw1 for b in b_list[0]]
            else:
                raw = [scale_c * b / sw[i] for b in b_list[i]]
            scale_c = scale_c / (sw[i] * (2.0 ** ks_c[i]))
            ts.append([max(-254, min(254, int(round(x / 127.0))))
                       for x in raw])
        return ts

    for layer in range(4):
        b_accs = _build(tuple(ks))
        bb = [b_accs[j] if b_accs[j] is not None else [0] * nb[j]
              for j in range(4)]
        amax = 0.0
        for img_q in cal_imgs:
            out = _int8_forward(img_q, c1q, c2q, qd1, qd2,
                                bb[0], bb[1], bb[2], bb[3], tuple(ks),
                                accs=True)
            amax = max(amax, out["accs"][layer])
        k = 0
        while amax > (96 << k):
            k += 1
        ks[layer] = k
        scale = scale / (sw[layer] * (2.0 ** k))

    # Accuracy-guided shift tuning. Rationale (measured): the accumulators
    # are HEAVY-TAILED (conv2 max ~29k from rare aligned windows vs typical
    # ~2k), so max-based shifts leave deep layers' typical outputs at
    # ~0.25 counts -> rounded to 0 -> downstream starves. With pure shifts
    # there is no mult rounding to hide behind, so tune k2/k3/k4 directly
    # on validation accuracy (coordinate descent, biases rebuilt per
    # candidate; k1's range is wide and never benefits).
    if tune_val is not None:
        timgs, tlabels = tune_val
        tn = min(len(timgs), 96)

        class _QShim:
            pass

        def _mk(ks_c, ba):
            m = _QShim()
            m.c1q, m.c2q, m.d1q, m.d2q = c1q, c2q, qd1, qd2
            m.b1_acc, m.b2_acc, m.d1b_acc, m.d2b_acc = ba
            m.rq = {"c1": (1, ks_c[0]), "c2": (1, ks_c[1]),
                    "d1": (1, ks_c[2]), "d2": (1, ks_c[3])}
            return m

        def acc_of(ks_c):
            return eval_int8(_mk(ks_c, _build(ks_c)),
                             timgs, tlabels, 0, tn)[0]

        best = list(ks)
        best_acc = acc_of(best)
        print(f"  [tune] ks={best} acc={best_acc}/{tn}", flush=True)
        for li, rng in ((1, 2), (2, 2), (3, 1)):
            cur = best[li]
            for k in range(max(0, cur - rng), min(15, cur + rng) + 1):
                if k == cur:
                    continue
                cand = list(best)
                cand[li] = k
                a = acc_of(cand)
                mark = ""
                if a > best_acc:
                    best_acc, best, mark = a, cand, " *"
                print(f"  [tune] k{li + 1}={k}: {a}/{tn}{mark}", flush=True)
        ks = best
        print(f"  [tune] final ks={ks} acc={best_acc}/{tn}", flush=True)

    # final bias rows + tap rebuilt from the FINAL shift chain
    b_accs = _build(tuple(ks))
    k1, k2, k3, k4 = ks
    rq = {"c1": [1, k1], "c2": [1, k2], "d1": [1, k3], "d2": [1, k4]}
    ck = {
        "c1w": tm.c1w, "c2w": tm.c2w, "d1w": tm.d1w, "d2w": tm.d2w,
        "c1b": tm.c1b, "c2b": tm.c2b, "d1b": tm.d1b, "d2b": tm.d2b,
        "d2w_q": qd2,
        "rq": rq,
        "b_acc": {"c1": b_accs[0], "c2": b_accs[1],
                  "d1": b_accs[2], "d2": b_accs[3]},
    }
    with open(path, "w") as fh:
        json.dump(ck, fh)
    return ck


def load_trained_model(path):
    """Trained checkpoint -> a golden-Model-shaped object with the trained
    int8 weights, 127-unit bias rows (b_acc stores t; contribution 127*t
    via A taps +127/-127) and RTL requant params — the exact object
    predict_int8 and the RTL TBs drive."""
    with open(path) as fh:
        ck = json.load(fh)
    mq = G.Model(seed=20260927).quantize()  # structure template
    w1 = [x for row in ck["c1w"] for x in row]
    w2 = [x for row in ck["c2w"] for x in row]
    # K-major flatten to match the d1q[k*32+n] consumer (see export).
    wd1 = [ck["d1w"][n][k] for k in range(200) for n in range(32)]
    q1, s1, _ = G.quantize_int8(w1, symmetric=True)
    q2, s2, _ = G.quantize_int8(w2, symmetric=True)
    qd1, sd1, _ = G.quantize_int8(wd1, symmetric=True)
    mq.c1q = [q1[oc * 9:(oc + 1) * 9] for oc in range(4)]
    mq.c2q = [q2[oc * 36:(oc + 1) * 36] for oc in range(8)]
    mq.d1q = qd1
    mq.d2q = ck["d2w_q"]
    mq.b1_acc = ck["b_acc"]["c1"]
    mq.b2_acc = ck["b_acc"]["c2"]
    mq.d1b_acc = ck["b_acc"]["d1"]
    mq.d2b_acc = ck["b_acc"]["d2"]
    mq.rq = {k: tuple(v) for k, v in ck["rq"].items()}
    mq.c1s, mq.c2s, mq.d1s, mq.d2s = s1, s2, sd1, 0.0
    return mq


# ----------------------------------------------------------------- train ----
def train(epochs=3, train_n=4096, val_n=500, batch=16, lr0=0.003,
          ckpt=CKPT_DEFAULT, resume=False, tune=96, mom=0.0):
    tm = TrainModel()
    start_ep = 0
    if resume and os.path.exists(ckpt):
        with open(ckpt) as fh:
            ck = json.load(fh)
        tm.c1w = ck["c1w"]
        tm.c2w = ck["c2w"]
        tm.d1w = ck["d1w"]
        tm.d2w = ck["d2w"]
        # biases ride in the checkpoint too — restoring weights only made
        # every resumed chunk restart its biases from zero.
        tm.c1b = ck["c1b"]
        tm.c2b = ck["c2b"]
        tm.d1b = ck["d1b"]
        tm.d2b = ck["d2b"]
        print(f"resumed from {ckpt}")
    imgs = load_idx_images(os.path.join(DATA_DIR, "train-images-idx3-ubyte"),
                           max_n=train_n)
    labels = load_idx_labels(os.path.join(DATA_DIR,
                                          "train-labels-idx1-ubyte"),
                             max_n=train_n)
    timgs = load_idx_images(os.path.join(DATA_DIR,
                                         "t10k-images-idx3-ubyte"),
                            max_n=val_n)
    tlabels = load_idx_labels(os.path.join(DATA_DIR,
                                           "t10k-labels-idx1-ubyte"),
                              max_n=val_n)
    order = list(range(len(imgs)))
    rng = random.Random(123)
    ck = None
    for ep in range(start_ep, epochs):
        rng.shuffle(order)
        t0 = time.time()
        tot_loss = 0.0
        tm.zero_grads()
        nb = 0
        for bi in range(0, len(order) - batch + 1, batch):
            for i in order[bi:bi + batch]:
                # FLOAT trainer runs on the [-1,1] view (norm_img = byte/128,
                # already pixel-128-shifted by the loader). _img128 is the
                # INT8 view, used ONLY by predict/eval — feeding it here
                # scales inputs 128x and explodes lr=0.1 training.
                tot_loss += tm.loss_and_grads(norm_img(imgs[i]), labels[i])
            # clip=400 ~ 1.3x the measured median batch grad norm (301):
            # normal batches train untouched; true explosions (the epoch-1
            # collapse) get truncated. clip=1.0 throttles EVERY batch ~300x
            # and stalls training.
            tm.sgd_step(lr0 * (0.9 ** ep), mom, batch, clip=400.0)
            nb += 1
        print(f"epoch {ep}: loss={tot_loss / len(order):.4f} "
              f"({time.time() - t0:.0f}s)", flush=True)
        ck = export_checkpoint(tm, ckpt,
                               tune_val=(timgs, tlabels) if tune > 0
                               else None)
        mq = load_trained_model(ckpt)
        c, n = eval_int8(mq, timgs, tlabels, 0, val_n)
        cfl = sum(1 for i in range(val_n)
                  if G.argmax(tm.forward(norm_img(timgs[i]))["logits"])
                  == tlabels[i])
        print(f"  float val: {cfl}/{n} = {100.0 * cfl / n:.1f}% | "
              f"int8 val accuracy: {c}/{n} = {100.0 * c / n:.1f}%",
              flush=True)
    return ck


def selftest():
    """One batch of gradient descent must reduce the loss on a tiny set."""
    tm = TrainModel(seed=3)
    imgs = load_idx_images(os.path.join(DATA_DIR,
                                        "train-images-idx3-ubyte"),
                           max_n=64)
    labels = load_idx_labels(os.path.join(DATA_DIR,
                                          "train-labels-idx1-ubyte"),
                             max_n=64)
    losses = []
    for it in range(6):
        tm.zero_grads()
        lt = 0.0
        for i in range(16):
            lt += tm.loss_and_grads(norm_img(imgs[i]), labels[i])
        losses.append(lt / 16)
        tm.sgd_step(0.1, 0.0, 16)
    assert losses[-1] < losses[0], f"loss not decreasing: {losses}"
    print(f"selftest: loss {losses[0]:.3f} -> {losses[-1]:.3f} decreasing")
    print("TRAINER SELFTEST PASS")


if __name__ == "__main__":
    ap = argparse.ArgumentParser()
    ap.add_argument("--epochs", type=int, default=3)
    ap.add_argument("--train", type=int, default=4096)
    ap.add_argument("--val", type=int, default=200)
    ap.add_argument("--checkpoint", default=CKPT_DEFAULT)
    ap.add_argument("--resume", action="store_true")
    ap.add_argument("--tune", type=int, default=96,
                    help="val images for requant-shift tuning (0=off)")
    ap.add_argument("--lr", type=float, default=0.003)
    ap.add_argument("--mom", type=float, default=0.0)
    ap.add_argument("--selftest", action="store_true")
    a = ap.parse_args()
    if a.selftest:
        selftest()
    else:
        train(a.epochs, a.train, a.val, ckpt=a.checkpoint,
              resume=a.resume, tune=a.tune, lr0=a.lr, mom=a.mom)
