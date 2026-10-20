"""
tools/fig/mnist_montage.py — a paper figure: real MNIST test digits with the
digit PREDICTED by the trained Ember int8 model (the exact weights the RTL
Tensor Unit runs), rendered as a PNG montage.

Pure stdlib: uses tools/train_mnist.py's loader/predictor and a 5x7 bitmap
font for the labels, then writes a PPM and converts with ppm2png.

Usage:  python3 tools/fig/mnist_montage.py [count] [out.ppm]
"""
import sys

sys.path.insert(0, "tools")
from train_mnist import load_idx_images, load_idx_labels, load_trained_model, predict_int8  # noqa: E402
import ppm2png  # noqa: E402

FONT = {
    "0": ["01110", "10001", "10011", "10101", "11001", "10001", "01110"],
    "1": ["00100", "01100", "00100", "00100", "00100", "00100", "01110"],
    "2": ["01110", "10001", "00001", "00010", "00100", "01000", "11111"],
    "3": ["11111", "00010", "00100", "00010", "00001", "10001", "01110"],
    "4": ["00010", "00110", "01010", "10010", "11111", "00010", "00010"],
    "5": ["11111", "10000", "11110", "00001", "00001", "10001", "01110"],
    "6": ["00110", "01000", "10000", "11110", "10001", "10001", "01110"],
    "7": ["11111", "00001", "00010", "00100", "01000", "01000", "01000"],
    "8": ["01110", "10001", "10001", "01110", "10001", "10001", "01110"],
    "9": ["01110", "10001", "10001", "01111", "00001", "00010", "01100"],
    "=": ["00000", "00000", "11111", "00000", "11111", "00000", "00000"],
    " ": ["00000", "00000", "00000", "00000", "00000", "00000", "00000"],
}


def draw_glyph(buf, W, x, y, ch, scale, color):
    glyph = FONT.get(ch, FONT[" "])
    for gy, row in enumerate(glyph):
        for gx, c in enumerate(row):
            if c == "1":
                for dy in range(scale):
                    for dx in range(scale):
                        px, py = x + gx * scale + dx, y + gy * scale + dy
                        if 0 <= px < W:
                            o = (py * W + px) * 3
                            buf[o : o + 3] = bytes(color)


def main(argv):
    count = int(argv[0]) if argv else 10
    out_ppm = argv[1] if len(argv) > 1 else "paper/figures/mnist_montage.ppm"

    images = load_idx_images("data/t10k-images-idx3-ubyte")
    labels = load_idx_labels("data/t10k-labels-idx1-ubyte")
    model = load_trained_model("data/mnist_trained.json")

    # pick the first `count` digits 0..9 in order (one of each digit class)
    picks = []
    want = list(range(10))[:count]
    for i, lab in enumerate(labels):
        if lab in want:
            picks.append(i)
            want.remove(lab)
        if not want:
            break

    DIG = 28
    K = 4                      # digit upscale
    CELL = DIG * K             # 112
    PAD = 12
    LBL_H = 7 * 3 + 2 * 4      # glyph 7 rows * scale 3 + margins
    W = count * (CELL + PAD) + PAD
    H = PAD + CELL + LBL_H + PAD
    buf = bytearray(W * H * 3)
    # background: dark navy
    for o in range(0, len(buf), 3):
        buf[o : o + 3] = bytes((16, 20, 32))

    n_ok = 0
    for ci, idx in enumerate(picks):
        img = images[idx]                      # 28x28, already pixel-128
        lab = labels[idx]
        pred = predict_int8(model, img)
        if pred == lab:
            n_ok += 1
        x0 = PAD + ci * (CELL + PAD)
        y0 = PAD
        for y in range(DIG):
            for x in range(DIG):
                v = img[y * DIG + x] + 128     # back to 0..255 for display
                v = 0 if v < 0 else (255 if v > 255 else v)
                for dy in range(K):
                    row_off = ((y0 + y * K + dy) * W + x0 + x * K) * 3
                    for dx in range(K):
                        o = row_off + dx * 3
                        buf[o : o + 3] = bytes((v, v, v))
        # label: "pred" (green if correct, red if wrong)
        color = (80, 220, 120) if pred == lab else (240, 90, 90)
        txt = str(pred)
        tx = x0 + (CELL - len(txt) * 4 * 3) // 2
        ty = y0 + CELL + 8
        for ch in txt:
            draw_glyph(buf, W, tx, ty, ch, 3, color)
            tx += 4 * 3

    ppm2png.write_png(out_ppm.rsplit(".", 1)[0] + ".png", W, H, bytes(buf))
    print(f"montage: {count} digits, {n_ok}/{count} correct -> {out_ppm.rsplit('.',1)[0]}.png")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
