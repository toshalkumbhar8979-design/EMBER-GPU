"""
tools/golden/tu.py — Golden Ember-TU reference (Phase 6).

Models the 16x16 weight-stationary systolic array EXACTLY as the RTL moves
data (TPU-v1 style):
  * Weights enter from the NORTH, row r gets W[r][c] (chain south on per-row
    ld pulses).
  * Activations enter from the WEST, column c gets A[i][c] (chain east).
  * Each cell: psum_out = psum_in + w * a. psums flow NORTH->SOUTH; after N
    cycles, row S leaves carrying C[i][s] = sum_k A[i][k] * W[k][s].
  * Requant: C_int32 -> round(scale * C + zp) -> int8 (round-half-away).

The array-level `tu_matmul` walks MxK and KxN in Kx16 / 16x16 tiles exactly
like the planned RTL controller, so tile boundaries, zero-padding, and
accumulation across tiles are verified before any RTL exists.
"""

import math
import struct


def q8(x):
    """int32 -> int8 with wraparound (matches two's-complement truncation)."""
    x &= 0xFF
    return x - 256 if x >= 128 else x


def requant_row(vals, scale, zp=0):
    """Per-tensor requant: round(scale*c + zp) -> int8.
    Rounding = floor(v + 0.5) (round-half-UP) — matches the RTL
    '(x + half) >>> shift' idiom exactly for both signs."""
    out = []
    for c in vals:
        v = c * scale + zp
        out.append(q8(math.floor(v + 0.5)))
    return out


def tu_matmul(A, W, scale=1.0, zp=0):
    """MxK @ KxN int8 matmul through the 16x16 weight-stationary array.

    Returns (C_int32 flat list [M*N] pre-requant, C_int8 flat list).
    Emulates the RTL tiling: for each K-tile (16 deep), load weights into
    the array, then stream M-rows x 16-col activation tiles; psum rows exit
    the SOUTH carrying C += A_tile @ W_tile.
    """
    M, K = len(A), len(A[0])
    K2, N = len(W), len(W[0])
    assert K == K2, "shape mismatch"

    C32 = [0] * (M * N)

    for k0 in range(0, K, 16):
        for n0 in range(0, N, 16):
            nsz = min(16, N - n0)
            # ---- weight load: cell (dr, dc) holds W[k0+dr][n0+dc]
            # (dr = k within tile, dc = output column within tile),
            # zero-padded to 16x16 ----
            wbuf = [[q8(W[k0 + dr][n0 + dc])
                     if (k0 + dr) < K and dc < nsz else 0
                     for dc in range(16)] for dr in range(16)]
            # ---- compute: activation x[dc] = A[i][k0+dc] streams along row
            # dc; each cell multiplies; psums accumulate down column dc and
            # exit SOUTH as C[i][n0+dc] += sum_dc x[dc]*wbuf[dc][j]. All
            # int32-exact, so this direct MAC form is bit-identical to the
            # pipelined version.
            for i in range(M):
                acc = [0] * nsz
                for dc in range(16):
                    a = q8(A[i][k0 + dc]) if (k0 + dc) < K else 0
                    if a == 0:
                        continue
                    for j in range(nsz):
                        acc[j] += a * wbuf[dc][j]
                for j in range(nsz):
                    C32[i * N + n0 + j] += acc[j]

    C8 = requant_row(C32, scale, zp) if scale != 1.0 or zp != 0 else \
        [q8(c) for c in C32]
    return C32, C8


def tu_matmul_ref(A, W, scale=1.0, zp=0):
    """Straight reference matmul (independent of the tile emulation)."""
    M, K, N = len(A), len(W), len(W[0])
    C32 = [sum(q8(A[i][k]) * q8(W[k][j]) for k in range(K))
           for i in range(M) for j in range(N)]
    C8 = requant_row(C32, scale, zp) if scale != 1.0 or zp != 0 else \
        [q8(c) for c in C32]
    return C32, C8


def selftest():
    import random
    rng = random.Random(20260927)

    # golden tile-emulation must equal the straight reference
    for trial in range(50):
        M = rng.randint(1, 37)
        K = rng.randint(1, 67)          # crosses tile boundaries
        N = rng.randint(1, 40)
        A = [[rng.randint(-128, 127) for _ in range(K)] for _ in range(M)]
        W = [[rng.randint(-128, 127) for _ in range(N)] for _ in range(K)]
        c1, _ = tu_matmul(A, W)
        c2, _ = tu_matmul_ref(A, W)
        assert c1 == c2, f"tile emulation mismatch at trial {trial}"

    # requant sanity: scale 1/zp 0 identity; scale/rounding checks
    _, c8 = tu_matmul_ref([[100], [-100]], [[2]], scale=0.5)
    assert c8[0] == q8(100) and c8[1] == q8(-100)
    _, c8 = tu_matmul_ref([[127]], [[127]], scale=1.0)
    assert c8[0] == q8(127 * 127)               # saturating wrap to int8
    _, c8 = tu_matmul_ref([[3]], [[3]], scale=1.0, zp=1)
    assert c8[0] == q8(10)                      # 9*1+1 = 10
    # round-half-up contract: 2.5 -> 3, -2.5 -> -2 (floor(v+0.5))
    assert requant_row([5], 0.5) == [3]         # 5*0.5=2.5 -> 3
    assert requant_row([-5], 0.5) == [-2]       # -2.5 -> floor(-2.0) = -2

    print("TU GOLDEN SELFTEST PASS (50 randomized shape trials)")
    return True


if __name__ == "__main__":
    selftest()
