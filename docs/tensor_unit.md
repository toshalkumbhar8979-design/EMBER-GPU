# Tensor Unit (TU) — Architecture

The TU is Ember's AI math block: an int8 matrix-multiply engine that turns
`C = requant(A × W)` layer math into VRAM-to-VRAM jobs kicked from the CP.
It is what runs MNIST end-to-end on the chip (conv1/conv2/dense1/dense2 all
execute on this block). RTL: [`rtl/ember_tu.sv`](../rtl/ember_tu.sv).
Golden model: `tools/golden/tu.py`. Decision record: D3 in
[decisions.md](decisions.md) (int8, weight-stationary, 2026-09-25).

## At a glance

| Property | Value |
|---|---|
| Precision | int8 operands, int32 accumulate, int8 output |
| Array | 16×16 weight-stationary cells (256 MAC/cycle datapath) |
| Dataflow | Weight-stationary outer-product with per-column adder trees |
| Loop order | n-tile outer → M-block (16 rows) → k-tile inner |
| Requant | per-tensor `((c*mult + half) >>> shift)` rounded half-up, wraps to int8 |
| VRAM port | dedicated `tua` (1-cycle req/rdata reads, C writes at job end) |
| Control | CP CSR block `TUA/TUW/TUC/CFG2/KICK` @ 0x58–0x68, `STATUS[10]=tu_busy` |
| Throughput | 25.6 GOPS-capable datapath @ 100 MHz; ~14 GOPS measured (v1 controller) |
| Verified | `test/tb_tu.py` 3/3, `tb_mnist_acc.py` 98/100 images bit-exact vs golden |

## Datapath

```
              wrowbuf[4]  (16B staged weight row, 4 words)
                    │ wbyte[0..15]
        ┌───────────▼───────────┐
        │  w_regs[16][16] int8  │  weight-stationary cells
        │  load pulse w_ld[r]   │  cell (r,c) = W[k0+r][n0+c]
        └───────────┬───────────┘
 a_row_byte[r] ──► prod[r][c] = w[r][c] * a[r]      (256 int8×int8)
                    │
        per-column 16-input adder tree (8→4→2→1)
                    │
              tree[c] = Σ_r prod[r][c]   (int32)
                    │
        acc[mrow][c] += tree[c]          (int32, per-row accumulator set)
                    │
        requant8(acc, mult, shift) → C bytes (4 per VRAM word)
```

- **Weight load.** A 16×16 weight tile is fetched 4 words (16 B) at a time into
  `wrowbuf`, then latched into one cell row with a single `w_ld[r]` pulse.
  One load pulse per row, 16 rows per tile.
- **Activation broadcast.** Per output row `r`, the byte
  `a[r] = A[m][k0+r]` is broadcast combinationally to row `r`; each cell
  multiplies its held weight by it. Column sums go through 16-input trees
  (3 adder levels).
- **Accumulators.** `acc[16][16]` holds **one accumulator set per row of the
  M-block** and accumulates across the k-loop. (A single shared acc set is
  wrong — every row's MACs would smear into the same registers; proved by
  `tools/tu_chk` zero-C smear test.)
- **Requant.** `out = ((c*mult + half) >>> shift)` wrapped to int8,
  round-half-up; `shift=0` is identity. 4 bytes packed per VRAM word.

## Tile controller (FSM)

States: `IDLE → WFETCH → WLOAD → WLATCH → AFETCH → MAC → RNEXT → KNEXT →
CREQ → CWRITE → MNEXT → DONE`.

Nested loops, outermost first:

1. **n-tile** (16 columns of C): loads a 16×16 W tile
   `W[k0..k0+15][n0..n0+15]` — W row stride is **N**, not K.
2. **M-block** (16 rows of C): for each row `m0+mrow`, fetch the 4 A words
   `A[m][k0..k0+15]` and apply one MAC pass (adds `tree[c]` into
   `acc[mrow][c]`).
3. **k-tile** (inner): `k0 += 16`, keep `acc`, reload the W tile for the new
   k-range. When `k0 + 16 >= K`, the block is complete.
4. **C write:** 16 rows × 4 words, each byte requantized from `acc`, written
   to `C[cw_row][n0..]`. Then next M-block (acc reset) or next n-tile.

VRAM reads use a single-outstanding-request engine (`rq_pend`/`rq_req_cyc`,
data valid the cycle after the request edge). C writes are 4-byte stores with
byte enables 0xF.

## Programming model (CP CSR)

| Reg | Addr | Meaning |
|---|---|---|
| `CP_TU_A` | 0x58 | A base, VRAM byte offset (M×K int8, row stride K) |
| `CP_TU_W` | 0x5C | W base (K×N int8, row stride N) |
| `CP_TU_C` | 0x60 | C base (M×N int8 out, row stride N) |
| `CP_TU_CFG2` | 0x64 | Form-tagged write, `[31:30]` selects: `00` dims `[11:0]=N, [27:16]=K`; `01` `[11:0]=M`; `10` quant `[15:0]=mult, [23:20]=shift` |
| `CP_TU_KICK` | 0x68 | W1P: write 1 to run the matmul |
| `CP_STATUS[10]` | — | `tu_busy` (job in flight) |

Bases are forced word-aligned (low 2 bits cleared on write). Decode lives in
[`rtl/ember_cp.sv`](../rtl/ember_cp.sv); addresses in
[`rtl/ember_pkg.sv`](../rtl/ember_pkg.sv).

Typical job: upload A/W to VRAM (CP DMA) → program A/W/C bases + CFG2 dims +
quant → KICK → poll `STATUS[10]` → read C back.

## Contracts and constraints (v1)

- **K and N are multiples of 16.** The array always streams full 16-byte
  W/A row tiles; software zero-pads matrices to whole tiles (TPU-style).
  This is the golden model's contract too — `tools/golden/tu.py` pads the
  same way, so RTL and golden agree bit-for-bit.
- **M is 12-bit** (up to 4095), rounded up to whole 16-row blocks by the
  controller; tail rows read zero-padded A. All block/row counters are
  12-bit — an 8-bit `cw_row` once aliased C writes for M > 256 (caught by
  `tb_mnist` conv1 with M=688; fixed).
- **Requant is per-tensor**, not per-channel. The MNIST accuracy gate uses
  pure-shift requant `(1, k_i)` calibrated on raw accumulator maxima; biases
  are folded into the matmul as A taps (+127/−127 × W rows) so they stay
  int8-legal.
- C plane layout is **row-major** (row stride N). maxpool2 reading it
  op-major caused a channel scramble in the MNIST chain — respect the
  contract.

## Verification

| Test | What it proves |
|---|---|
| `tools/golden/tu.py` | Tile emulation == straight reference over 50 randomized shapes (multi-tile K/N) |
| `test/tb_tu.py: tu_small` | 5×20×13 multi-tile job, every C byte bit-exact through the real CSR path |
| `test/tb_tu.py: tu_quant` | mult=128/shift=7 requant path |
| `test/tb_tu.py: tu_256` | 256×256×256 matmul, full golden compare |
| `test/tb_mnist.py` | LeNet conv1/conv2/dense1/dense2 each bit-exact through the TU (im2col → pad → kick → requant) |
| `test/tb_mnist_e2e.py` | Full chain: CP DMA → TU → core pool → TU → core pool → TU → relu → TU → argmax |
| `test/tb_mnist_acc.py` | **98/100 = 98.0%** with trained int8 weights on the RTL chain, bit-for-bit equal to the software mirror |

Run: `cd test && make` (cocotb + Verilator, `Makefile` includes `tb_tu`).

## Performance

- Datapath potential: 256 MAC/cycle = 25.6 GOPS @ 100 MHz.
- Measured v1: ~14 GOPS @ 100 MHz sim — the load-serialized controller
  fetches W and A tiles with the array idle during loads.
- **v2 upgrade path** (same CSR interface): streaming variant — double-
  buffered A tiles and load/MAC overlap (systolic psum-chain), targeting
  ≥ 20 GOPS. Also planned: per-channel requant and a 32×32 array option.

## Known bugs (fixed) — read before changing this block

1. `cw_row` 8-bit → C rows aliased for M > 256 (fix: 12-bit; tb_mnist M=688).
2. Shared accumulator set → zero-C smear across rows (fix: per-row acc sets;
   `tools/tu_chk`).
3. Software-side traps (not RTL): maxpool reading C op-major (channel
   scramble), n-major dense flatten vs the K-major contract, and a bias tap
   of 177 which is not int8 (byte 0xB1 sign-flips in the TU — taps must be
   ±127 or less).
