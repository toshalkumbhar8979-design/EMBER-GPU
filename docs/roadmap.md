# Ember GPU — Build Roadmap

Phased plan. Every phase ends in a **demo you can run** — no "trust me, the RTL is
done" phases. Acceptance criteria are hard gates.

Legend: ✅ done · 🔨 in progress · ⬜ not started

---

## Phase 0 — Foundations ✅
Deliverable: repo skeleton + tooling that can lint and simulate.
- [x] `agentbible.md`, docs/ set (spec, decisions, roadmap, research)
- [x] `rtl/` directory + `ember_pkg.sv` (all global parameters, map, opcodes)
- [x] Makefile / cocotb harness that lints all RTL with Verilator
- [ ] Python golden-model skeleton (`tools/golden/`) for raster + tensor (moved into Phase 2)
- [ ] Assembler skeleton (`tools/assembler.py`) for Ember-ISA v2 (moved into Phase 5)
- **Gate: PASSED** — `verilator --lint-only` clean on all RTL; cocotb runs under Verilator 5.046.

## Phase 1 — Memory system + Command Processor ✅
Deliverable: VRAM you can read/write from a testbench, CP with DMA + fence.
- [x] `ember_xbar` (round-robin arbiter, lock-based forwarding, decode)
- [x] `ember_vram` (512 KB, byte-strobed AXI-Lite slave + dbg sidecar)
- [x] `ember_cp` (regs, upload/readback FIFOs, DMA engine, FENCE)
- [x] `ember_top` + `test/tb_memory.py` (4/4 tests PASS, incl. DMA round trip)
- **Gate: PASSED** — cocotb test uploads a pattern via CP DMA and reads it back
  through the dbg port; readback round trip verified; fence counter works.

## Phase 2 — Raster / Texture / ROP (the heart of "games") ✅
Deliverable: golden-exact pixel pipeline with Z-test and CLUT textures.
- [x] `ember_rtr_setup.sv` — combinational Cramer triangle setup (planes for
      1/w, r/g/b, z, u/v; cull; bbox). Coefficients verified bit-exact vs golden.
- [x] `ember_rtr_scan.sv` — per-pixel scan FSM: direct edge eval, plane eval,
      perspective divide (tdiv-exact), z-test (LESS), CLUT texel fetch, full ROP
      (clamp → rgbmap → blend 50% → dither ±1 → RGB565 pack).
- [x] `ember_rtr_top.sv` — triangle command-queue fetcher (0-terminated queue
      in VRAM at RTR_CMDQ_BASE, 19 words/tri) + fpa port mux.
- [x] CP integration: `CP_RTR_KICK` (0x20) register, `CP_STATUS[1]=rtr_busy`.
- [x] `test/tb_rtr.py` — 4 tests PASS driving the REAL software path (DMA
      upload → kick → busy-poll → dbg-port FB dump): gradient, perspective-
      correct textured quad, z-ordering, full-ROP chain — all bit-exact vs
      `tools/golden/raster.py` (per-pixel 320×240 compare).
- **Gate: PASSED** (correctness variant) — bit-exact golden match on all four
  RTR scenarios end-to-end through CP DMA. Throughput gate moved to Phase 3
  (perf pass: edge stepping + tighter FSM once display timing exists).

## Phase 3 — Blitter + Display Controller ✅
Deliverable: something appears on a screen (or in a saved PPM in sim).
- [x] `ember_blit.sv` — rect copy, key-color transparency, 1×/2× scale;
      CSR regs (CFG/DST/SRC/SIZE/KICK @0x24..0x34) decoded by the CP,
      shares the RTR's fpa port (RTR priority). `tools/golden/blit.py` reference.
- [x] `ember_display.sv` — 640×480@60 timing, 320×240 double-scan (2×2 NN
      upscale), uniform 4-stage per-pixel fetch pipeline on a dedicated fpa3
      VRAM read port; aligned vid_hs/vs/de/pixel outputs. (Double-buffer flip
      deferred to v2 memory plan; FB1 returns then.)
- [x] `test/tb_display.py` — composite frame (gradient + RTR tri) streamed by
      the display: every 2×2 output block verified == FB pixel; writes
      `test/display_frame.ppm`.
- [x] `test/tb_blit.py` — 1x copy / key transparency / 2x scale, full-FB
      bit-exact vs golden blit model.
- **Gate: PASSED** — sim renders a static image → PPM matches golden
  reference (per-pixel, not just eyeball).

## Phase 4 — Geometry & Setup Engine ✅
Deliverable: 3D triangles flow end-to-end.
- [x] `ember_fpu4.sv` — 4 independent fp32 lanes (ADD/SUB/MUL/DIV, op[1:0]),
      pure-RTL IEEE-754: RNE, FTZ subnormals, NaN/Inf specials, 6-cycle fixed
      latency (go pulse → 6 RisingEdges → sample y; y holds until next go).
      Bit-exact vs `tools/golden/fpu.py`: 6,720 comparisons / 0 mismatches
      (tb_fpu 2/2 PASS) + Verilator C++ probe `tools/fpu_chk` 8/8.
- [x] `ember_gsx.sv` — embedded fpu4, 4×4 fp32 MVP per vertex (MUL pass → ADD
      pass per matrix column, one row per lane), 4 parallel fp32 divides
      (x/w y/w z/w 1/w), near-cull w≤0, fp32→Q10.22 + ndc-z→u16 conversions,
      19-word cmdq emit on a dedicated gxa VRAM port. CSR via CP passthrough
      (MATA/VTX/COL auto-inc, CFG, GO; STATUS bit8 = gsx_busy).
- [x] `tools/golden/cube.py` — bit-exact GSX mirror + spinning-cube geometry
      (viewport y-flip folded into M; faces wound to survive CCW-front cull).
- [x] `test/tb_gsx.py` — 3/3 PASS: identity word-exact, near-cull queue
      intact, full 12-tri spinning-cube frame per-pixel bit-exact vs golden
      (GSX + RTR end to end, real software path; writes `cube_rtl.ppm`).
- **Gate: PASSED (correctness)** — spinning cube in sim, per-pixel golden
  match. Perf gate (setup throughput) deferred with the RTR perf pass
  (correct geometry first; ~240 cycles/triangle at v1 is fine for demos).
  Texture path through GSX (u/v words are zeros today) is the next graphics
  increment, not a gate.

## Phase 5 — Compute Cluster ✅
Deliverable: SIMT cores run real kernels.
- [x] `tools/assembler.py` — Ember-ISA v2 two-pass assembler (labels, data
      directives, pc-relative branches, LI/LIU, fp ops). `--selftest` PASS.
- [x] `ember_core.sv` — v1 core: 4-thread SPMD, per-thread PCs + per-thread
      one-word instruction buffers, separate fetch (ixa) / data (cxa) VRAM
      channels, 1024-word smem with LDS/STS/ATOMIC_ADD/MAX, count-up BAR,
      CMP-set nzp + BRNZP/JAL/JR/RET/CALL, fpu4 lane0 for FADD/FSUB/FMUL/FDIV,
      ~1M-cycle deadlock budget. CP dispatch regs (CODE/NBLK/KICK @0x4C..0x54,
      STATUS bit 9 = core_busy).
- [x] `kernels/` + `test/tb_core.py` — 4/4 PASS through the real software
      path (assemble → DMA → dispatch → poll → dbg readback): matadd
      (4×32 elems), matmul (C=A·B, row-per-thread), divergent (tid-dependent
      trip count, thread 0 skips the loop), barrier (smem atomics + broadcast).
- **Gate: PASSED** — matadd + matmul in sim; divergent-branch kernel passes;
  barrier test with HW deadlock-timeout guard. (Reconvergence stack not
  needed for the v1 SPMD model: per-thread PCs diverge/rejoin by construction.)

## Phase 6 — Tensor Unit ✅
Deliverable: real AI math.
- [x] `tools/golden/tu.py` — golden int8 matmul + per-tensor requant
      (round-half-up); tile-emulation proven equal to the straight
      reference over 50 randomized shape trials (incl. multi-tile K/N).
- [x] `ember_tu.sv` — 16×16 int8 WEIGHT-STATIONARY outer-product array with
      per-column 16-input adder trees (256 MACs/cycle datapath), blocked-M
      controller (n-tile outer / 16-row M-block / k-tile inner),
      per-block-row accumulators, per-tensor requant (mult/shift),
      dedicated `tua` VRAM port, CP CSR (TUA/TUW/TUC/CFG2/KICK @0x58..0x68,
      STATUS bit 10 = tu_busy). Contract: K/N multiples of 16 (SW zero-pads,
      TPU-style), M 12-bit. (Post-gate fixes: the C-write row counter
      `cw_row` was 8-bit — C aliased once M > 256; now 12-bit. Caught by
      tb_mnist conv1 M=688.)
- [x] `test/tb_tu.py` — 3/3 PASS through the real software path: tu_small
      (5×20×13 multi-tile, every C byte bit-exact), tu_quant (mult=128/
      shift=7 requant path), tu_256 (256×256×256 full golden compare).
- **Gate: PASSED (correctness)** — 256×256 int8 matmul bit-exact vs golden
  (vs the Python golden, not NumPy — no numpy in this WSL env; the golden
  itself is cross-checked by construction). Throughput: the datapath is
  25.6-GOPS-capable; the v1 load-serialized controller measures ~14 GOPS
  @100MHz sim. Streaming (double-buffered A + load/MAC overlap) is the
  v2 item to close the gap to ≥20 GOPS.

## Phase 7 — Integration demos 🔨
Deliverable: the two promises, kept.
- [x] **GSX texture path** (the last graphics gap): per-vertex u/v through
      the 15-word VTX window, texpage in CFG→w0[15:8], affine v1 contract
      (words 13–18 = converted raw u/v; perspective-correct = v2 RTR).
      `tools/golden/tex.py` + `test/tb_tex.py` 1/1 PASS bit-exact end-to-end
      (checker page through GSX-texture→RTR).
- [x] **AI demo step 1 — MNIST layers on the RTL TU** (`tools/golden/mnist.py`
      + `test/tb_mnist.py`, 1/1 PASS): LeNet-style conv1/conv2/dense1/dense2
      each run bit-exact through ember_tu (im2col rows → padded TU dims →
      kick → requant vs golden mirror). Remaining
      for the demo: full-image inference through CP DMA → TU → readback with
      real weights, ≥ 95% on 100 test images.
- [x] **Game demo step 1 — textured 3D scene** (`tools/golden/scene.py` +
      `test/tb_scene.py`, 1/1 PASS): the temple frame — back wall, floor,
      two flanking pillars, 8 textured triangles, one MVP, one CLUT page,
      REAL per-pixel Z sorting (the scene MVP fixes the cube demo's
      degenerate z). Bit-exact vs golden in tex+ztest, tex, and ztest
      modes. Caught + fixed a latent GSX bug on the way: w0 emitted the
      tex-enable at bit4 (dither) instead of bit3 — invisible until a test
      textured BOTH sides (tb_tex golden now loads its own page too).
      Suite now **25/25 PASS**.
- [x] **AI demo step 2 — MNIST end-to-end on silicon** (`test/tb_mnist_e2e.py`,
      1/1 PASS): quantized image → CP DMA → TU(conv1) → **compute core pool**
      (kernels/pool2d.asm, MAXC signed-byte trick) → TU(conv2) → core pool →
      TU(dense1) → relu → TU(dense2) → digit read from VRAM; logits bit-exact
      vs the same-arithmetic golden chain. Found + fixed a REAL core bug on
      the way: the fetch PC was 5-bit (32-word kernels aliased); now 8-bit.
      Suite now **26/26 PASS**. Remaining for the accuracy gate: TRAINED
      weights + 100-image run (data/artifact task, not RTL).
- [x] **AI demo step 3 — MNIST ACCURACY GATE** (`tools/train_mnist.py` +
      `test/tb_mnist_acc.py`, 1/1 PASS): trained float weights (pure-Python
      trainer: He init, lr 0.0015, global-norm clip 400, 5 epochs over 4k–16k
      train images → 96% float / 95.7% int8 val on 300 images) → checkpoint
      export with an RTL-exact quant contract (per-layer PURE-SHIFT requant
      (1, k_i) calibrated on raw accumulator maxima; biases folded into the
      matmul as A taps +127/−127 × W rows r1/r2 with r1−r2 = t = b_acc/127 —
      both operands int8-legal) → **98/100 = 98.0% on the RTL chain** (100
      t10k images through CP DMA → TU → core pools → TU → argmax), bit-for-bit
      equal to the in-process software mirror. Suite now **29/29 PASS**.
      Debug story (all caught by staged numeric probes): maxpool2 read the
      TU's op-major C plane-major (channel scramble), double pixel-128 input
      shift, n-major dense flatten (K-major contract), missing conv ReLUs
      (fold into the pool via max(0,·) commuting with maxpool), 1/sqrt(fan-in)
      init (ReLU underflow → dead net), lr explosions (fix: grad clipping),
      and two bias-fold traps (raw b_acc truncates in W bytes; a single tap
      177 is not int8 — byte 0xB1 sign-flips in the TU).
- [x] **Game demo step 2 — scene animation** (`tools/golden/scene.py`
      spin frames + `test/tb_anim.py`, 1/1 PASS): 4 orbit frames (15°
      steps) through GSX→RTR, per-frame bit-exact vs golden; PPM contact
      sheet via `tools/golden/anim_html.py`. Game loop proven. Gotcha
      locked in: gsx_setup (tri_count reset) must be re-written EVERY
      frame or emits append across frames.
- [x] **Game demo step 3 — interactive game loop** (`tools/golden/scene.py`
      `mvp_fly_words`/`fly_frame_set` + `test/tb_fly.py`, 1/1 PASS): scripted
      camera fly-through through the temple (walk + sway, no new culls —
      w = 3+cam_z−z > 0 across the path), HUD sprite via the real blitter
      (key transparency verified per-frame against the pre-blit frame),
      structural asserts only (≥12 colors, ≥20k non-bg px, ≥100 Z values,
      frames differ) — no golden pixel compares. **Measured frame time:
      6.15 ms worst = 18.6% of the 33-ms/30-fps budget** (RTR sweep 613k
      cycles ≈ 8 cyc/px; HUD blit 2067 cycles ≈ 4 cyc/px at 50 MHz).
      Artifacts: fly_rtl_f<i>.ppm + fly_rtl.html contact sheet. Suite now
      **30/30 PASS**.
- [x] **Game demo step 4 — INPUT-DRIVEN camera (game state on the core)**
      (`kernels/gamestate.asm` + `tools/golden/gamestate.py` +
      `test/tb_input.py`, 1/1 PASS): the per-frame game loop runs as a
      KERNEL on the compute core — Q16 physics (accel, magnitude-form
      decay |v|>>4, VMAX/PX/PZ clamps), exact Q16→fp32 bit conversion
      (round-half-up), cookie-echo handshake — fed only by a 2-word
      input stream (ax, az) per frame. TB asserts kernel state bit-exact
      vs the golden mirror every frame, patches the MVP with the
      KERNEL's fp32 words (row3[3] on-core; row0[3] host-side — the Q16
      product needs 37 bits, kernel MUL truncates at 32), renders 16 of
      32 frames through GSX→RTR + HUD blit with structural asserts.
      Suite now **31/31 PASS**.
- [x] **NEORV32 sim-side host gate** (`sw/cp_driver.h` + `sw/ember_demo.c`
      + `tools/neo_chk/`): the COMPLETE 32-frame game demo written as
      bare-metal host C over the real CP register map (polling MMIO, no
      libc), compiled with the verilator harness as a "firmware" TU
      (`-Dmain=demo_main`, MMIO hooked to a cycle-accurate AXI4-Lite
      master model) and executed against the full `ember_top`. The demo
      uploads texture/HUD/kernel/scene once, then per frame: 2 input
      words → kernel kick → state readback (cookie handshake) → MVP
      patch → GSX 8 tris → RTR sweep → HUD blit → TU matmul (AI path
      exercised in the same loop). Final rendered frame matches
      tb_input's frame 30 on **10316/10316 scene pixels** (diffs = the
      HUD, which the TB artifact draws pre-blit). This is the exact
      firmware shape that runs unmodified on the NEORV32 on the board.
      Harness lessons locked in: sample AXI handshakes PRE-posedge (the
      ram_slave drops arready on the accept edge — post-edge sampling
      deadlocks and a tolerant retry double-pops the destructive FIFOD
      read register); CP_ID reads 0xEB22_0002 (id code in the HIGH
      halfword); kernel params stage at CMDBUF=0x5B000 = cmdq slot 0
      words 0-2 — benign between frames, GSX re-emits before each sweep.
- [ ] Optional: tiny int8 LLM (TinyStories-class) token-by-token inference.
- **Gate (HARDWARE, PARKED — no FPGA board available):** both demos run from
  the NEORV32 host on a real FPGA board (Colorlight i9 or similar), video out
  over HDMI/VGA. Sim-side prep is DONE: the C firmware exists and drives the
  real RTL through the same register map (`sw/ember_demo.c` + `tools/neo_chk`).
  Board bring-up = clone NEORV32, wire its AXI4-Lite master to `ember_top`'s
  flat host port, run `sw/ember_demo.c` as firmware. Everything short of
  owning the board is complete (2026-10-01).

## Phase 8 — Silicon hardening: real GDS + IEEE paper + public prep 🔨
Deliverable: the GPU as actual ASIC geometry (GDS-II), a ~9-page IEEE-style
paper PDF, and a public-facing prep folder. Tools: the real open-source ASIC
flow — **sv2v → Yosys → OpenLane 2 (OpenROAD floorplan/place/CTS/route →
Magic DRC → KLayout) on the SkyWater sky130 PDK**, the same path used for
tinyTapeout/Efabless silicon.
- [x] Toolchain bring-up: Docker `ghcr.io/efabless/openlane2:2.3.10`
      (persistent container, project mounted at /work) + volare sky130A PDK
      (fa87f8f) + sv2v v0.0.13 in WSL. Yosys reads the real Ember RTL through
      the sv2v front door (proved on ember_rtr_scan).
- [ ] Synthesis + PnR for 12 block targets: cp, xbar, ram_slave, fpu4,
      blit, display, core, tu, gsx, rtr_setup, rtr_scan, rtr_top.
      **2026-10-02 evening update:** rtr_scan synthesis PASSES (1,416,166
      cells) after two root-caused fixes: (a) yosys 0.46 `synth -run
      begin:coarse` runs only hierarchy, so processes must be lowered with an
      explicit `proc` BEFORE `techmap -autoproc`; (b) default ABC OOM-kills on
      the multiplier-heavy AIG, so scripts/gds/abc_lean.script maps without
      the rewriting passes. rtr_top is synthesized hierarchically (setup+scan
      as blackboxes; 2,144-cell glue netlist) and will be built physically
      with setup/scan as hard macros (rtr_top_pnr.sh). Global route was
      packing ~50% of wirelength onto met1 at large scale (~28 shorts/mm);
      signals now route met2-met5 with met1 reserved for pin access (fpu4
      iter-0 violations dropped 95,684 -> 34,968, iter-1 11,768). WSL2/Docker
      capped at 16 GB per user request (WiFi stability).
      **2026-10-02 mapped-netlist audit:** **9 targets accepted; RTR retries**.
      Earlier 12/12 exit-success count was invalid: RTR outputs contained
      behavioral processes and generic gates skipped by ABC. Added post-map
      process lowering and explicit JSON mapped-cell validation; all three RTR
      targets now retry without trusting their former cache markers. Xbar, display, ram_slave and blit have
      independently reimported exported GDS with zero full-layout Magic DRC
      and zero routing violations (SHA-256-bound evidence). PDK grid scaling
      fixed conversion errors; assembled/flattened context includes nearby
      taps required by tapless cell masters. No rules disabled. Eight physical
      targets remain queued in physical_remaining.log; bounded timing repair
      does not waive residual timing violations. LVS is still pending.
- [ ] Chip integration: **integrated logic die flow now implemented** —
      ember_die instantiates the 8 hardened GPU blocks as hard macros with
      real routed inter-block wiring (AXI xbar buses, CSR bus, fpa ownership
      mux, video out) plus 632 glue std cells; scripts/gds/die_pnr.sh drives
      floorplan (band layout), macro PDN hookup, met2-met5 routing, Magic DRC,
      KLayout merged GDS and an independent zero-DRC audit. The 512 KB VRAM
      flop array is promoted to an external SRAM pin interface
      (rtl/ember_die.sv, make_die_top.py): a 4.2 Mbit flop array is not
      std-cell mappable, and no SRAM macro generator exists in this offline
      environment — the die is the GPU *logic* with an external memory bus.
      LVS and chip-level timing sign-off remain open and are reported as such.
- [ ] Paper: IEEEtran LaTeX, ~9 pages, all rendered frames (cube/orbit/
      temple/fly/input/MNIST), architecture diagram, measured results.
- [ ] `prep/`: LINKEDIN_POST.md + INTERVIEW_SCRIPT.md (first-person).
- **Gate:** all 12 target netlists verified; nonempty intended-top GDS;
  explicit whole-layout DRC and LVS evidence; integrated-chip claims only
  after actual inter-block wiring and SRAM implementation. Paper must clearly
  distinguish simulation results, block layouts and unimplemented integration.
  PDF compilation and prep files alone do not close silicon hardening.

---

## Risk register (top items)
| Risk | Mitigation |
|---|---|
| AXI fabric contention starves RTR | RTR priority + tile FIFO; measure in Phase 2 |
| Tensor unit verify (many PEs) | PE-level golden tests first, then array; random + structured patterns |
| fp32 FPU area blow-up | 4 lanes max, div/sqrt optional at build time |
| cocotb sim speed on big scenes | Verilator backend + frame-size knobs in tests |
| Host SW (NEORV32) learning curve | Keep CP MMIO interface dead simple; UART console early |
