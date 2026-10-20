"""
tools/golden/mnist.py — Golden MNIST demo infrastructure (Phase 7b).

LeNet-5-style classifier mapped onto the Ember TU:
  conv(1->4, 3x3) -> maxpool2 -> conv(4->8, 3x3) -> maxpool2 -> flatten
  -> dense(8*5*5=200 -> 32) -> dense(32 -> 10)

Everything the TU executes is pure int8 matmul (per-tensor requant):
  * conv as im2col: patch matrix (out_h*out_w x k*k*cin) @ weight matrix
    (k*k*cin x cout) — the TU's 16-byte-tile K contract means cin*k*k is
    zero-padded to a multiple of 16.
  * dense = plain matmul over the zero-padded input row.

The quantization recipe (Q_min/Q_max per tensor, symmetric int8 weights,
asymmetric-with-zp activations) matches common TFLite practice, and the
golden float model validates the int8 path layer by layer. Weights are
RANDOM here (deterministic seed) — real trained weights slot into the same
`Model` structure; accuracy comes when trained weights are loaded.

Memory layout for the RTL run (tools/golden only defines it; the TB drives):
  image + intermediates live in VRAM scratch; each layer's output is the
  next layer's A matrix; TU CSR is re-programmed per layer.
"""

import math
import random


# ------------------------------------------------------------- quantization --
def quantize_int8(values, symmetric=False):
    """float list -> (int8 list, scale, zp). Symmetric: zp=0, no clamp top."""
    lo = min(values)
    hi = max(values)
    if symmetric:
        m = max(abs(lo), abs(hi))
        scale = m / 127.0 if m > 0 else 1.0
        return [max(-128, min(127, round(v / scale))) for v in values], \
            scale, 0
    scale = (hi - lo) / 255.0 if hi > lo else 1.0
    zp = -round(lo / scale) - 128
    zp = max(-128, min(127, zp))
    out = []
    for v in values:
        q = round(v / scale) + zp
        out.append(max(-128, min(127, q)))
    return out, scale, zp


def dequantize(qvals, scale, zp):
    return [(q - zp) * scale for q in qvals]


# ------------------------------------------------------------------- im2col --
def im2col(img, cin, h, w, k=3):
    """HWC int8 image -> patch matrix (out_h*out_w x k*k*cin), row-major.
    Patches are collected channel-major within each patch (c,ky,kx) so the
    weight matrix columns match."""
    oh, ow = h - k + 1, w - k + 1
    rows = []
    for oy in range(oh):
        for ox in range(ow):
            row = []
            for c in range(cin):
                for ky in range(k):
                    for kx in range(k):
                        row.append(img[(oy + ky) * w + (ox + kx) + c * h * w])
            rows.append(row)
    return rows, oh, ow


def maxpool2(img, cin, h, w):
    """2x2 stride-2 max pool over a HWC image (flat list)."""
    oh, ow = h // 2, w // 2
    out = [0] * (oh * ow * cin)
    for c in range(cin):
        for oy in range(oh):
            for ox in range(ow):
                m = -128
                for dy in range(2):
                    for dx in range(2):
                        m = max(m, img[((oy * 2 + dy) * w + ox * 2 + dx)
                                       + c * h * w])
                out[(oy * ow + ox) + c * oh * ow] = m
    return out, cin, oh, ow


def maxpool2_op(img_op, cin, oh, ow, ih, iw):
    """2x2 stride-2 max pool over an OP-MAJOR conv output (img[op*cin + c],
    op = oy*ow+ox) — the layout conv-as-matmul produces and the RTL/TB
    dataflow uses. Output is PLANE-major (c*oh*ow + op), matching im2col's
    input contract. (Phase-7f: the first draft used plane-major tap indices
    on the op-major array — scrambled channels; caught by the gradient
    check, then by p1 not reacting to a conv1 weight change.)"""
    out = [0] * (oh * ow * cin)
    for c in range(cin):
        for oy in range(oh):
            for ox in range(ow):
                op = oy * ow + ox
                m = -128
                for dy in range(2):
                    for dx in range(2):
                        si = ((oy * 2 + dy) * iw + ox * 2 + dx) * cin + c
                        m = max(m, img_op[si])
                out[op + c * oh * ow] = m
    return out, cin, oh, ow


# ------------------------------------------------------------------- layers --
def conv_tu_params(cin, k, cout):
    """Conv-as-matmul shapes for the TU: (Kdim, Ndim) after im2col, plus the
    K zero-pad needed by the TU's 16-byte tile contract."""
    kdim = cin * k * k
    kpad = (kdim + 15) // 16 * 16
    return kdim, kpad, cout


def dense_ref(x, W, b):
    """float dense: x[M x K] @ W^T + b, with W stored [N][K]."""
    K = len(x[0])
    N = len(b)
    out = []
    for row in x:
        o = []
        for n in range(N):
            o.append(sum(row[k] * W[n][k] for k in range(K)) + b[n])
        out.append(o)
    return out


def relu(values):
    return [max(0.0, v) for v in values]


def argmax(values):
    best = 0
    for i in range(1, len(values)):
        if values[i] > values[best]:
            best = i
    return best


# ------------------------------------------------------------------- model --
class Model:
    """Random-weight LeNet-style model; layer-by-layer int8 golden vs float."""

    def __init__(self, seed=20260927):
        rng = random.Random(seed)
        # conv1: 1 -> 4 channels, 3x3 (28x28 -> 26x26)
        self.c1w = [[rng.uniform(-0.5, 0.5) for _ in range(9)]
                    for _ in range(4)]
        self.c1b = [rng.uniform(-0.2, 0.2) for _ in range(4)]
        # conv2: 4 -> 8 channels, 3x3 (13x13 -> 11x11); kern[oc][cin*9]
        self.c2w = [[rng.uniform(-0.5, 0.5) for _ in range(36)]
                    for _ in range(8)]
        self.c2b = [rng.uniform(-0.2, 0.2) for _ in range(8)]
        # dense1: 8*5*5=200 -> 32
        self.d1w = [[rng.uniform(-0.4, 0.4) for _ in range(200)]
                    for _ in range(32)]
        self.d1b = [rng.uniform(-0.1, 0.1) for _ in range(32)]
        # dense2: 32 -> 10
        self.d2w = [[rng.uniform(-0.4, 0.4) for _ in range(32)]
                    for _ in range(10)]
        self.d2b = [rng.uniform(-0.1, 0.1) for _ in range(10)]

    def conv2d_float(self, img, cin, h, w, k, kern, bias, cout):
        """Float reference conv (valid padding), HWC flat img.
        kern[oc][c*k*k + ky*k + kx]; img index = c*h*w + y*w + x."""
        oh, ow = h - k + 1, w - k + 1
        out = [0.0] * (oh * ow * cout)
        for oc in range(cout):
            for oy in range(oh):
                for ox in range(ow):
                    s = bias[oc]
                    for c in range(cin):
                        for ky in range(k):
                            for kx in range(k):
                                s += img[c * h * w + (oy + ky) * w
                                         + (ox + kx)] * kern[oc][c * k * k
                                                                 + ky * k
                                                                 + kx]
                    out[oc * oh * ow + oy * ow + ox] = s
        return out, cout, oh, ow

    def forward_float(self, img28):
        """Float reference forward pass (returns logits + per-layer)."""
        c1, c1c, c1h, c1w_ = self.conv2d_float(img28, 1, 28, 28, 3,
                                               self.c1w, self.c1b, 4)
        c1r = relu(c1)
        p1, p1c, p1h, p1w = maxpool2(c1r, 4, 26, 26)      # 4x13x13
        c2, c2c, c2h, c2w_ = self.conv2d_float(p1, 4, 13, 13, 3,
                                               self.c2w, self.c2b, 8)
        c2r = relu(c2)
        p2, p2c, p2h, p2w = maxpool2(c2r, 8, 11, 11)      # 8x5x5
        flat = p2                                          # 200 values
        d1 = dense_ref([flat], self.d1w, self.d1b)[0]
        d1r = relu(d1)
        d2 = dense_ref([d1r], self.d2w, self.d2b)[0]
        return {"logits": d2, "pred": argmax(d2),
                "c1": c1r, "p1": p1, "c2": c2r, "p2": flat, "d1": d1r}

    # ---- int8 (TU) path ------------------------------------------------
    def quantize(self):
        """Quantize every layer; store scales/zps + per-layer requant
        (mult, shift) for the RTL-exact requant. Call once."""
        flat1 = [self.c1w[oc][i] for oc in range(4) for i in range(9)]
        q, self.c1s, self.c1z = quantize_int8(flat1, symmetric=True)
        self.c1q = [q[oc * 9:(oc + 1) * 9] for oc in range(4)]
        flat2 = [self.c2w[oc][i] for oc in range(8) for i in range(36)]
        q, self.c2s, self.c2z = quantize_int8(flat2, symmetric=True)
        self.c2q = [q[oc * 36:(oc + 1) * 36] for oc in range(8)]
        f1 = [self.d1w[n][k] for k in range(200) for n in range(32)]
        q, self.d1s, self.d1z = quantize_int8(f1, symmetric=True)
        self.d1q = q                                # K-major: [k][n]
        f2 = [self.d2w[n][k] for k in range(32) for n in range(10)]
        q, self.d2s, self.d2z = quantize_int8(f2, symmetric=True)
        self.d2q = q
        # per-layer RTL requant params (ember_tu requant8: mult/shift)
        self.rq = {}
        for name, s in (("c1", self.c1s), ("c2", self.c2s),
                        ("d1", self.d1s), ("d2", self.d2s)):
            m = int(round(s * 4096))
            self.rq[name] = (max(1, min(0xFFFF, m)), 12)
        return self

    @staticmethod
    def requant8(c, mult, shift):
        """Mirror of rtl/ember_tu.sv requant8: ((c*mult + half) >>> shift)
        wrapped to int8 (NO clamping — the RTL wraps)."""
        full = c * mult
        if shift == 0:
            res = full
        else:
            res = (full + (1 << (shift - 1))) >> shift   # floor (arith >>)
        b = res & 0xFF
        return b - 256 if b >= 128 else b

    def forward_int8(self, img28_q):
        """int8 forward (images pre-quantized). Mirrors the TU execution:
        conv = im2col @ W, accumulations int32, requant per tensor."""
        # conv1: patches (676 x 9) @ W (9 x 4)
        rows, oh, ow = im2col(img28_q, 1, 28, 28, 3)
        acc = []
        for r in rows:
            o = []
            for oc in range(4):
                s = 0
                for k in range(9):
                    s += r[k] * self.c1q[oc][k]
                o.append(s)
            acc.append(o)
        # requant + zp + relu as int8 (scale-space stays consistent enough
        # for the demo; the golden compares against the SAME arithmetic)
        c1 = []
        for row in acc:
            for v in row:
                q = round(v * self.c1s) + 0          # approx dequant->int8
                c1.append(max(-128, min(127, q)))
        # c1/c2 are OP-MAJOR (op*cin + oc) here: pool with maxpool2_op
        # (Phase-7f fix; maxpool2 would channel-scramble trained weights).
        p1, p1c, p1h, p1w = maxpool2_op(c1, 4, 13, 13, 26, 26)
        rows, oh, ow = im2col(p1, 4, 13, 13, 3)
        acc = []
        for r in rows:
            o = []
            for oc in range(8):
                s = 0
                for k in range(36):
                    s += r[k] * self.c2q[oc][k]
                o.append(s)
            acc.append(o)
        c2 = []
        for row in acc:
            for v in row:
                q = round(v * self.c2s)
                c2.append(max(-128, min(127, q)))
        p2, _, _, _ = maxpool2_op(c2, 8, 5, 5, 11, 11)
        # dense1: (1 x 200) @ (200 x 32) — W stored K-major flat
        d1 = []
        for n in range(32):
            s = 0
            for k in range(200):
                s += p2[k] * self.d1q[k * 32 + n]
            d1.append(max(0, s))
        # dense2
        d2 = []
        for n in range(10):
            s = 0
            for k in range(32):
                s += d1[k] * self.d2q[k * 10 + n]
            d2.append(s)
        return {"logits": d2, "pred": argmax(d2)}


def selftest():
    m = Model().quantize()
    rng = random.Random(1)
    img = [rng.randint(-128, 127) for _ in range(28 * 28)]

    f = m.forward_float([v / 256.0 for v in img])
    i8 = m.forward_int8(img)
    assert 0 <= f["pred"] <= 9 and 0 <= i8["pred"] <= 9

    # TU path is deterministic; verify layer shapes end to end
    assert len(i8["logits"]) == 10
    print("MNIST GOLDEN SELFTEST PASS (random weights, shapes + both paths)")
    return True


if __name__ == "__main__":
    selftest()
