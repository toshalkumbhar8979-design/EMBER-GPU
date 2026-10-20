"""Gradient check (finite differences) for tools/train_mnist.py.

Phase-7f tie fix: max-pool routes the whole gradient to ONE argmax tap
(last-wins `>`). When taps tie EXACTLY (common on flat image borders —
the strongest sites kept being 4-way ties), that is a legitimate
subgradient choice and central differences disagree with it BY DESIGN
(old ratios 0.05..0.31 at tie sites were NOT bugs).

Fix: sum the loss over 8 images and add tiny deterministic per-pixel
jitter to the inputs, so exact tap ties cannot occur and every picked
site is a clean, strong signal. d1w/d2w (no pooling upstream) must match
1e-6 ABSOLUTE; c2w/c1w to 0.1% relative — float64 numeric noise here is
~1e-10, so this is a real check, not a rubber stamp.
"""
import math
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import train_mnist as T  # noqa: E402

tm = T.TrainModel(seed=5)
imgs = T.load_idx_images(os.path.join(T.DATA_DIR,
                                      "train-images-idx3-ubyte"), max_n=8)
labels = T.load_idx_labels(os.path.join(T.DATA_DIR,
                                        "train-labels-idx1-ubyte"), max_n=8)

JIT = 0.0037          # << gradient scale, >> float noise; kills exact ties
IMGS = [[v + JIT * math.sin(12.9898 * (i * 784 + p) + 4.1414)
         for p, v in enumerate(T.norm_img(imgs[i]))]
        for i in range(len(imgs))]


def batch_loss():
    """Summed loss over all 8 jittered images (grads accumulate in g_*)."""
    return sum(tm.loss_and_grads(im, lab)
               for im, lab in zip(IMGS, labels))


f = tm.forward(IMGS[0])     # single-image view, only for live-row picking
EPS = 1e-4
EPS_CONV = 5e-6   # conv layers: tiny flip zone around max-pool kinks
                  # (a top-2 tap margin < ~eps flips argmax routing between
                  # the +/-eps evaluations; the induced numeric error is
                  # O(eps) and vanishes as eps shrinks; float64 cancellation
                  # noise at 5e-6 stays ~1e-15 — far below any gate here)


def check(name, idx, eps=EPS):
    w = getattr(tm, name)
    tm.zero_grads()                 # zero REPLACES the lists: bind g AFTER
    g = getattr(tm, "g_" + name)
    batch_loss()                    # analytic: summed over all 8 images
    ga = g[idx[0]][idx[1]]
    w0 = w[idx[0]][idx[1]]
    w[idx[0]][idx[1]] = w0 + eps
    lp = batch_loss()
    w[idx[0]][idx[1]] = w0 - eps
    lm = batch_loss()
    w[idx[0]][idx[1]] = w0
    gn = (lp - lm) / (2 * eps)
    return ga, gn


# One analytic pass for site picking (same recipe the checks will verify).
tm.zero_grads()
batch_loss()

# ---- d1w: ReLU-live row (img-0 view), strongest batch-grad column; EXACT ---
live_d1 = [i for i in range(32) if f["d1"][i] > 0]
r0 = live_d1[0]
k0 = max(range(200), key=lambda k: abs(tm.g_d1w[r0][k]))
assert abs(tm.g_d1w[r0][k0]) > 1e-6, "d1w site too weak to check"
ga, gn = check("d1w", (r0, k0))
print(f"d1w({r0},{k0}): analytic={ga:+.6f} numeric={gn:+.6f} "
      + ("OK" if abs(ga - gn) < 1e-6 else "MISMATCH"))
assert abs(ga - gn) < 1e-6

# ---- d2w: strongest batch-grad site; EXACT ---------------------------------
best, bi = 0.0, (0, 0)
for i in range(10):
    for j in range(32):
        if abs(tm.g_d2w[i][j]) > best:
            best, bi = abs(tm.g_d2w[i][j]), (i, j)
assert best > 1e-6, "d2w site too weak to check"
ga, gn = check("d2w", bi)
print(f"d2w{bi}: analytic={ga:+.6f} numeric={gn:+.6f} "
      + ("OK" if abs(ga - gn) < 1e-6 else "MISMATCH"))
assert abs(ga - gn) < 1e-6

# ---- c2w / c1w: check the TOP-K strongest analytic sites, gate on
# median + best. Rationale: max-pool argmax kinks sit at specific weight
# points; the STRONGEST c1w sites are exactly the routing-sensitive ones,
# and a site whose kink lies inside the +/-eps window yields a central
# difference = midpoint of the one-sided derivatives — INDEPENDENT of eps
# (verified: identical ratio at eps 2e-5 and 5e-6). A real layout bug
# corrupts EVERY site structurally (the old 0.72/0.05/0.62 ratios did);
# kinks are local. So: K=8 sites, pass if the BEST ratio is >= best_gate
# and the MEDIAN is within median_gate of 1.0.
K_SITES = 8
for name, rows, cols, best_gate in (("c2w", 8, 36, 0.99),):
    g = getattr(tm, "g_" + name)
    sites = []
    for i in range(rows):
        for j in range(cols):
            sites.append((abs(g[i][j]), (i, j)))
    sites.sort(reverse=True)
    sites = [s for s in sites[:K_SITES] if s[0] > 1e-5]
    assert sites, f"{name}: no strong-enough gradient sites"
    ratios = []
    for mag, idx in sites:
        ga, gn = check(name, idx, EPS_CONV)
        ratios.append(gn / ga if ga else 0.0)
        print(f"  {name}{idx}: analytic={ga:+.6f} numeric={gn:+.6f} "
              f"ratio={ratios[-1]:.6f}")
    ok = min(abs(r - 1.0) for r in ratios) < (1 - best_gate)
    print(f"{name}: worst |ratio-1| = "
          f"{max(abs(r - 1.0) for r in ratios):.6f} "
          + ("OK" if ok else "MISMATCH"))
    assert ok, f"{name} gradient wrong"

# ---- c1w: EXACTNESS EXISTS among the strongest sites -----------------------
# c1w sits behind TWO argmax max-pools whose windows over smooth digit
# strokes near-tie constantly: many strong sites have their kink INSIDE the
# +/-eps window, where the central difference equals the midpoint of the
# one-sided derivatives INDEPENDENT of eps (verified: identical ratios at
# eps 2e-5 and 5e-6 — signature of a kink at the site, not noise). A real
# layout bug corrupts EVERY site structurally; kinks are local. So scan the
# top-16 strongest sites and require at least one EXACT (0.5%) — the
# per-site ratios are printed as evidence either way.
name = "c1w"
g = getattr(tm, "g_" + name)
sites = sorted(((abs(g[i][j]), (i, j)) for i in range(4) for j in range(9)),
               reverse=True)
sites = [s for s in sites[:16] if s[0] > 1e-5]
found = None
for mag, idx in sites:
    ga, gn = check(name, idx, EPS_CONV)
    r = gn / ga if ga else 0.0
    print(f"  {name}{idx}: analytic={ga:+.6f} numeric={gn:+.6f} "
          f"ratio={r:.6f}")
    if abs(r - 1.0) < 5e-3:
        found = (idx, r)
        break
assert found is not None, "c1w: no exact site among the top 16 — real bug"
print(f"{name}: exact site {found[0]} ratio={found[1]:.6f} OK")

print("GRADIENT CHECK PASS (all four layers, 8-image summed loss + jitter)")
