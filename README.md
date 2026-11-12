# EMBER GPU

**A from-scratch GPU with an integrated Int8 tensor unit — games and AI on one
chip.** Independent project: RTL, software, golden models, verification, and a
full open-source silicon flow (sv2v → Yosys → OpenROAD → Magic → KLayout on
SkyWater sky130), all built by one person.

> 📄 **[Read the paper — paper/ember_paper.pdf](paper/ember_paper.pdf)**
> *EMBER: A From-Scratch GPU with an Integrated Int8 Tensor Unit* (IEEE-style,
> ~9 pages: architecture, simulation results, per-block sky130 hardening
> results). Sources in [`paper/ember_paper.tex`](paper/ember_paper.tex).

---

## What this is

A real GPU, not a toy datapath:

| Subsystem | Block | What it does |
|---|---|---|
| Host interface | `ember_cp` | Command processor: MMIO registers, DMA upload/readback, fences, kernel dispatch |
| Geometry | `ember_gsx` + `ember_fpu4` | 4×4 fp32 MVP per vertex, 4 parallel perspective divides, near-cull; 4 independent IEEE-754 fp32 lanes (6-cycle latency, RNE) |
| Raster | `ember_rtr_setup` / `ember_rtr_scan` / `ember_rtr_top` | Cramer triangle setup → per-pixel scan: plane eval, perspective-correct texturing, Z-test, CLUT, full ROP (clamp → rgbmap → blend → dither → RGB565) |
| 2D | `ember_blit` | Rect copy, key-color transparency, 1×/2× scale |
| Video | `ember_display` | 640×480@60 timing, 320×240 double-scan 2×2 NN upscale |
| Compute | `ember_core` | 4-thread SPMD SIMT core: shared memory, atomics, barriers, branch divergence by per-thread PCs |
| AI | `ember_tu` | 16×16 int8 weight-stationary systolic array — 256 MACs/cycle, per-tensor requant |
| Memory | `ember_xbar` + `ember_vram` + `ember_ram_slave` | Round-robin arbiter, 512 KB VRAM with 4 ports, AXI4-Lite slave |
| Silicon | `ember_die` + `ember_chip` | Logic die with the 8 hardened blocks as routed macros + pad ring (373 signal pads) |

Three demos run **end-to-end through the real RTL** (CP DMA → accelerators →
readback), each bit-exact against Python golden models:

- **Doom** — E1M1 rasterized from `data/doom1.wad`: real BSP geometry, composed
  wall textures and flats, COLORMAP light levels, CLUT, perspective-correct UVs
  and the full Z-buffered ROP. **10,774 textured GSX triangles** streamed into
  the RTL command queue; the framebuffer out of `ember_rtr_top` in Verilator is
  **bit-identical to the golden rasterizer — 76,800 of 76,800 pixels**
  (`test/tb_doom.py`, 68.4 M ns simulated).
- **Game** — a textured 3D temple scene with real per-pixel Z-sorting,
  input-driven camera (game-state physics runs *as a kernel on the compute
  core*), HUD via the blitter. Worst frame **6.15 ms = 18.6% of the
  33 ms / 30 fps budget** at 50 MHz. A NEORV32 bare-metal C firmware
  (`sw/ember_demo.c`) drives the identical register map.
- **AI** — full MNIST inference: quantized image → tensor unit (conv1) →
  compute-core pooling kernels → TU (conv2) → core pool → TU (dense) → argmax,
  with trained int8 weights: **98/100 = 98.0% accuracy on the RTL chain**,
  bit-for-bit equal to the software mirror.

Verification: **31/31 cocotb tests PASS**, per-pixel / per-byte golden
comparison throughout (not eyeball checks).

---

## Simulation outputs

<div>
<table>
  <tr>
    <td align="center"><img src="paper/figures/doom_ref.png" width="260"><br><sub>Doom E1M1 — real engine, player start (reference)</sub></td>
    <td align="center"><img src="paper/figures/doom_golden.png" width="260"><br><sub>Doom E1M1 — golden rasterizer, 10,774 triangles</sub></td>
    <td align="center"><img src="paper/figures/doom_rtl.png" width="260"><br><sub>Doom E1M1 — out of <code>ember_rtr_top</code>, 76,800/76,800 px exact</sub></td>
  </tr>
  <tr>
    <td align="center"><img src="paper/figures/cube_rtl.png" width="260"><br><sub>Spinning cube — GSX + RTR end-to-end (tb_gsx)</sub></td>
    <td align="center"><img src="paper/figures/orbit_f0.png" width="260"><br><sub>Temple scene, orbit frame 0° (tb_anim)</sub></td>
    <td align="center"><img src="paper/figures/orbit_f3.png" width="260"><br><sub>Temple scene, orbit frame 45° (tb_anim)</sub></td>
  </tr>
  <tr>
    <td align="center"><img src="paper/figures/fly_f0.png" width="260"><br><sub>Camera fly-through + HUD blit (tb_fly)</sub></td>
    <td align="center"><img src="paper/figures/input_f0.png" width="260"><br><sub>Input-driven game loop, frame 0 (tb_input)</sub></td>
    <td align="center"><img src="paper/figures/input_f10.png" width="260"><br><sub>Input-driven game loop, frame 10</sub></td>
  </tr>
  <tr>
    <td align="center"><img src="paper/figures/input_f24.png" width="260"><br><sub>Input-driven game loop, frame 24</sub></td>
    <td align="center"><img src="paper/figures/input_f30.png" width="260"><br><sub>Input-driven game loop, frame 30</sub></td>
    <td align="center"><img src="paper/figures/display_frame.png" width="260"><br><sub>Display controller output frame (tb_display)</sub></td>
  </tr>
  <tr>
    <td align="center"><img src="paper/figures/mnist_montage.png" width="260"><br><sub>MNIST inference on the RTL TU + cores — 98%</sub></td>
    <td align="center"><img src="test/scene_golden.png" width="260"><br><sub>Golden model reference scene</sub></td>
    <td align="center"><img src="test/scene_rtl.png" width="260"><br><sub>RTL-rendered scene (bit-exact vs golden)</sub></td>
  </tr>
</table>
</div>

## Play it: a continuous Doom session

The Doom demo is a *session*, not just one still frame: 20 frames of E1M1
rendered back to back through `ember_rtr_top`, starting at the player start and
walking out into the courtyard. Every frame below came out of the RTL in
Verilator (CP DMA → RTR → RGB565 framebuffer → display), and the corner of each
frame shows the frame rate that frame actually achieved.

[![Doom E1M1 running continuously on the EMBER RTL](docs/media/doom_ember.gif)](docs/media/doom_ember.mp4)

*(GIF above · [5 s MP4](docs/media/doom_ember.mp4))*

| Measured on the RTL — 50 MHz, 320×240 | Value |
|---|---|
| Mean frame time | **62.6 ms → 15.97 fps** |
| Frame time (best / worst) | 57.8 ms (17.32 fps) / 70.1 ms (14.27 fps) |
| Geometry per frame | ~9,600 textured triangles (192,050 total) |
| Cycles per frame | 6,262,826 @ 50 MHz |
| Throughput | 153,325 triangles/s · 1,226,283 px/s |
| Host capture | 0.8 ms/frame debug-port readback, not counted above |

Reproduce it:

```bash
cd test && make MODULE=tb_doom_demo                    # build once
DOOM_FRAMES=20 DOOM_WORKERS=5 bash doom_session.sh      # play 20 frames
python doom_video.py --session demo_frames              # -> docs/media/doom_ember.mp4
python doom_player.py                                   # play it in a window
```

Frames are independent (each one clears FB and Z first), so `doom_session.sh`
splits the session across parallel simulator processes and `tb_doom_demo.py`
writes `metrics.json` with every frame's pose, triangle count, cycles, ms and
fps. Verilator runs this design at ~0.065% of real time, so this is a rendered
session rather than a live keyboard-driven game; the input path is exercised
separately by `tb_input`/`tb_fly`, where game state runs as a kernel on the
compute core.

## Architecture & silicon

<div>
<table>
  <tr>
    <td align="center"><img src="paper/figures/architecture.png" width="260"><br><sub>EMBER architecture</sub></td>
    <td align="center"><img src="paper/figures/gds_block.png" width="260"><br><sub>Hardened block GDS</sub></td>
    <td align="center"><img src="paper/figures/gds_cp.png" width="260"><br><sub>Command processor GDS</sub></td>
  </tr>
</table>
</div>

---

## Silicon status (sky130)

Real hardening through the open-source flow — 12 block targets, per-block
results auto-collected in [`paper/asic_table.tex`](paper/asic_table.tex):

| Metric | Value |
|---|---|
| Total mapped standard cells | 2,266,911 |
| Blocks hardened | 11 of 12 |
| Blocks with verified GDS | 6 (xbar, display, ram_slave, blit, rtr_setup, cp) |
| Largest block | `rtr_scan` — 1,416,166 cells (hierarchical synth) |
| Clean blocks | routing violations 0, full-layout Magic DRC 0, exported-audit DRC 0 |
| Clock target | 20 ns (50 MHz) |

The unfinished blocks (`core`, `rtr_scan`, `rtr_top`) are rebuilt on GitHub
Actions in staged, checkpointed jobs — see
[`docs/gds_ci.md`](docs/gds_ci.md) and
[`.github/workflows/gds.yml`](.github/workflows/gds.yml). Remaining after
them: die + pad-ring chip assembly. LVS and chip-level timing sign-off are open and
reported as such — see [`docs/roadmap.md`](docs/roadmap.md) Phase 8 for the
exact evidence bar.

---

## Verification highlights

- **Doom** — E1M1 from the shareware IWAD, 10,774 triangles: RTL framebuffer vs
  golden rasterizer, **0 mismatches of 76,800 pixels** (texture atlas, CLUT and
  triangles all DMA'd through the CP into the real RTL)
- **FPU** — 6,720 comparisons / 0 mismatches vs `tools/golden/fpu.py`
- **Raster** — 320×240 per-pixel bit-exact on gradient, perspective-correct
  textured quad, Z-ordering, full ROP chain
- **Tensor unit** — 256×256×256 int8 matmul bit-exact (multi-tile), requant
  path, MNIST conv/dense layers each golden-equal
- **Compute core** — matadd/matmul/divergent/barrier kernels through the real
  software path (assemble → DMA → dispatch → poll → readback)
- **Host firmware** — NEORV32 bare-metal demo matches TB frame 30 on
  10,316/10,316 scene pixels

---

## Repository layout

| Path | Contents |
|---|---|
| [`rtl/`](rtl/) | SystemVerilog RTL — all blocks, package, pad models |
| [`test/`](test/) | cocotb testbenches + Makefiles + golden artifacts |
| [`scripts/`](scripts/) | Build + GDS flow scripts (sv2v/Yosys/OpenROAD/Magic/KLayout) |
| [`tools/`](tools/) | Golden models, assembler, trainer, audits |
| [`build/`](build/) | Flow outputs: block GDS, logs, DRC/audit reports |
| [`checkpoint/`](checkpoint/) | Routed resume checkpoint (`final.odb` / `final.def`) |
| [`paper/`](paper/) | **[ember_paper.pdf](paper/ember_paper.pdf)**, LaTeX sources, figures |
| [`docs/`](docs/) | [Design spec](docs/design-spec.md), [roadmap](docs/roadmap.md), [pinout](docs/chip_pinout.md), [decisions](docs/decisions.md) |
| [`sw/`](sw/) | NEORV32 host firmware (`ember_demo.c`, `cp_driver.h`) |
| [`kernels/`](kernels/) | Compute-core assembly kernels (matmul, pool2d, gamestate, …) |
| [`data/`](data/) | MNIST dataset + trained weights |

---

## Build & test

```bash
# RTL lint (Verilator)
make lint

# Full simulation suite (cocotb + Verilator)
cd test && make

# Individual demos
cd test && make tb_scene   # textured temple scene
cd test && make tb_mnist   # MNIST inference on TU + cores
```

Silicon flow scripts live in `scripts/gds/` and run inside the OpenLane2
container with the volare sky130A PDK.

---

## Author

**Toshal Kumbhar** — RTL, software, verification, golden models, and silicon
flow. See [`paper/ember_paper.pdf`](paper/ember_paper.pdf) for the full write-up.
