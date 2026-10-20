# Ember GPU — Architecture Design Specification v2.0

A real, open-source GPU: **games + AI on one chip.**

```
                    ┌─────────────────────────────────────────────────────────┐
                    │                      EMBER GPU                            │
   Host CPU ───────►│  ┌──────────────┐        ┌──────────────────────────┐   │
   (RISC-V, MMIO    │  │  Command     │        │  Compute Cluster          │   │
    registers)      │  │  Processor   │        │  ┌────────┐  ┌────────┐  │   │
                    │  │  (CP)        │        │  │ Core 0 │  │ Core 1 │  │   │
                    │  └──────┬───────┘        │  └───┬────┘  └───┬────┘  │   │
                    │         │                │  ┌───▼───────────▼───┐   │   │
                    │  ┌──────▼───────┐        │  │ Tensor Unit       │   │   │
                    │  │ Geometry &   │        │  │ 16×16 int8 MAC    │   │   │
                    │  │ Setup Engine │        │  │ (systolic)        │   │   │
                    │  └──────┬───────┘        │  └───┬───────────┬───┘   │   │
                    │         │                └──────┼───────────┼───────┘   │
                    │  ┌──────▼───────────────────────▼───┐       │           │
                    │  │  Raster / Texture / ROP (1 px/c) │       │           │
                    │  └──────┬───────────────────────────┘       │           │
                    │         │                                    │           │
                    │  ┌──────▼────────────────────────────────────▼───────┐  │
                    │  │        Memory Subsystem (AXI4-Lite fabric)         │  │
                    │  │  L0: per-block shared SRAM (4 KB)                  │  │
                    │  │  L1: Framebuffer/VRAM 512 KB dual-port BRAM        │  │
                    │  │  L2: external DDR3 (v2) or larger BRAM (v1)        │  │
                    │  └──────┬─────────────────────────────────────────────┘  │
                    │         │                                                 │
                    │  ┌──────▼──────┐  ┌─────────┐  ┌────────────────────┐   │
                    │  │ CRT/Display │  │ Blitter │  │ Debug / Trace       │   │
                    │  │ (HDMI out)  │  │ (2D)    │  │ (perf counters)    │   │
                    │  └─────────────┘  └─────────┘  └────────────────────┘   │
                    └─────────────────────────────────────────────────────────┘
```

## 1. Design philosophy

1. **One chip, two accelerators.** Compute cores (for AI kernels) and a fixed-function
   graphics pipe (for games) share the same memory system. Neither blocks the other.
2. **int8 where possible, fp32 where needed.** AI runs int8 through the Tensor Unit;
   graphics vertex math and any scalar glue run fp32 on a small vector FPU.
3. **PS1-class raster is the floor, not the ceiling.** 1 pixel/clock, fixed-function,
   no shaders — but with clean tile boundaries so a v2 tiled deferred path can slot in.
4. **Everything behind AXI4-Lite.** Any block can be memory-mapped, driven from
   software, or swapped out. This is what makes the project growable.
5. **Simulate everything before hardware.** Every block gets a cocotb testbench; the
   whole chip boots in Verilator before it touches an FPGA.

## 2. Subsystem specification

### 2.1 Command Processor (CP)
- MMIO register file at base `0x0000`.
- Host pushes **command buffers** (list of 32-bit words) into VRAM; CP fetches and fans
  them out: geometry commands → Geometry Engine, compute dispatches → Compute Cluster,
  blit commands → Blitter, register writes → target block.
- Includes a **DMA engine** for host→VRAM uploads (textures, weights, frames) and
  back (readbacks, AI results).
- Semaphores/fences: a `FENCE` command writes a monotonic counter the host can poll.

### 2.2 Geometry & Setup Engine (GSX)
- **Vector FPU:** 4-lane fp32 FMA unit + divide/sqrt (for normalize & dot products).
- **Vertex pipeline:** input vertex streams in VRAM → VS: MVP transform, optional
  lighting (directional Gouraud) → clip to the near plane + view-frustum reject →
  perspective divide → viewport transform → screen-space triangles.
- **Setup unit:** for each triangle, computes plane-equation coefficients
  `A·x + B·y + C` for x, y, 1/w, u/w, v/w, r/g/b (the classic 7-channel setup);
  feeds the rasterizer. Handles top-left fill rule, backface culling, and scissor.
- **Throughput target:** 1 triangle setup every 2 cycles @ 50 MHz = 25 Mtri/s setup.
  This is ~250× PS1's 90k tri/s and well past anything "basic games" needs.

### 2.3 Raster / Texture / ROP (RTR) — the pixel pipeline
One pixel per clock, 5-deep pipeline:

```
 [1] COVERAGE:  edge functions from setup → in/out, plus 1/w
 [2] INTERP:    incremental plane-eval for u/w, v/w, r, g, b
 [3] TEXEL:     affine texel fetch (u/w·w = u for affine mode) from CLUT/15-bit
                textures; 4-bit / 8-bit palettes; nearest for v1
 [4] SHADE:     modulate texel × Gouraud color; optional alpha; dither
 [5] DEPTH/ROP: z-test (16-bit Z-buffer) → read-modify-write RGB565
                blending: none / 50% / src-alpha (v1)
```
- Framebuffer formats: **RGB565** (primary) + **16-bit depth**. Double-buffered via
  a register flip.
- Fill rate: 50 Mpix/s @ 50 MHz. A full 320×240 overdraw-2 scene costs
  ~10 Mpix → ~5 ms → 200 fps ceiling. Real scenes with 30 fps target have huge margin.
- Tile-aware design: internal 32×32 tile FIFO so a v2 binned/deferred pipeline
  can reuse this block unchanged.

### 2.4 Compute Cluster
- **Cores:** 2–8 SIMT cores. Each core: 4 threads/block (upgradeable to 8), own
  program counter set, 16 GPRs/thread, NZP flags, branch-divergence reconvergence
  stack, block barrier (`BAR`).
- **Per-core shared memory:** 4 KB, 4-bank interleaved, shared by the block's
  threads (staging buffers for tiles, activation tiles, etc).
- **ISA:** Ember-ISA v2 (32-bit encoding this time, since we need more registers):
  - ALU: ADD/SUB/MUL/DIV (int), FADD/FSUB/FMUL/FDIV (fp32, on the vector FPU),
    AND/OR/XOR/SHL/SHR, CMP, MIN/MAX, MULHI (for requantization math)
  - Memory: LD/ST (global), LDS/STS (shared), ATOMIC_ADD/MAX (global, for histograms)
  - Control: BRnzp, JAL, JR, RET, CALL/RET (reconvergence stack), BAR
  - Tensor: `TLD`, `TST`, `TEXEC`, `TWAIT` (drive the Tensor Unit, see 2.5)
  - Simd: `VOP` prefix for vector-FPU ops (4-lane fp32)
- **Dispatch:** CP pushes block descriptors (base PC, thread count, arg pointer) to
  a free core; core returns a completion interrupt.

### 2.5 Tensor Unit (Ember-TU)
- **16×16 systolic array of int8 MACs** (weight-stationary, TPU-style).
- Per-PE: 8×8 multiply, 32-bit accumulator; weights stay resident, activations
  march left→right, results drain bottom.
- Double-buffered weight buffer (2 × 16 KB) + activation buffer (8 KB) so the
  array never starves during tile swaps.
- Drives 25.6 GOPS @ 50 MHz. Sized so MNIST MLP, LeNet-5, MobileNetV1-0.25 and
  ~10M-param int8 transformer inference are all tractable.
- Accessible two ways: (a) directly from cores via TLD/TST/TEXEC, or (b) memory-mapped
  from the host via CP command buffers (no core involvement) — pick whichever fits.

### 2.6 Memory Subsystem
- **L0 — per-block shared SRAM** (4 KB/core, 4-bank).
- **L1 — on-chip VRAM** 512 KB dual-port BRAM, split:
  - 256 KB framebuffer pair (2 × 320×240×2B = 150 KB) + Z-buffer (150 KB)
  - 128 KB textures/weights/vertex buffers (host-visible, CP-DMA'd)
  - 64 KB command buffers / stacks / scratch
- **L2 — v1: none.** v2: external DDR3 (128 MB+) via LiteDRAM, opening the door to
  real texture sets, big models, and 640×480 double-buffered.
- **Interconnect:** single AXI4-Lite fabric; every initiator (CP, GSX, RTR, cores,
  TU, Blitter, Debug) is a master; VRAM is the one slave. Arbitration: round-robin,
  with the RTR granted priority (real-time deadline) and cores/throttleable.

### 2.7 Display Controller
- Fetches from the active framebuffer at fixed 640×480@60 or 320×240@60 timing
  (Project F-style H/V counters), drives HDMI via an open-source encoder core
  (or VGA on boards that have it).
- Independent of the render path — it just reads; you flip a register to swap buffers.

### 2.8 Blitter (2D)
- Rectangle copy with: transparency key, CLUT translation, 1×/2× scale, simple
  alpha. Enough for tilemaps, sprites, UI, and fast VRAM clears. Runs as a CP
  command, not a CPU loop.

### 2.9 Debug & Trace
- Per-block perf counters (pixels drawn, texel fetches, MAC ops, memory stalls).
- A UART/console port from the CP so tests can print from RTL.

## 3. Software stack
- **Assembler + driver library** (Python host, C firmware on NEORV32).
- **Kernel toolchain:** Ember-ISA assembly now; LLVM backend is a v2+ stretch goal.
- **Model path:** PyTorch/TF → int8 quantize → custom converter → weight blob →
  CP DMA → TU. Ship MNIST + LeNet-5 demos first.
- **Game path:** meshes → offline transform check → vertex + index buffers →
  CP geometry commands → GSX → RTR. Ship: spinning cube, then textured Pong/Copy
  of a Breakout, then a PS1-style 3D maze.

## 4. Verification plan
1. Unit cocotb testbenches per block (ALU, regfile, LSU, TU PE/array, setup, raster).
2. Block integration tests (GSX→RTR end-to-end on a known triangle).
3. Chip-level tests: matmul via TU, CNN inference on MNIST, triangle + texture
   scene, blit + display timing.
4. **Golden-model checking:** a Python reference implementation of raster + TU,
   compared against RTL every test.
5. Verilator lint + cocotb in CI; waveforms saved on failure.

## 5. Roadmap linkage
See `docs/roadmap.md` for the phased build plan. This spec is the contract;
the roadmap is the schedule.

## 6. Open questions (track here)
- [ ] fp16 or fp32 for the vector FPU? (fp32 easier; fp16 doubles lanes)
- [ ] Blending: src-alpha needs a divider or a lookup — LUT first?
- [ ] Texture cache sizing (2-line direct-mapped vs 1 KB 2-way)
- [ ] Do we need an I-cache for cores, or is a 256-entry instruction BRAM enough at v1?
- [ ] DDR3 (LiteX) vs SDRAM (cheaper boards) for v2 board choice.
