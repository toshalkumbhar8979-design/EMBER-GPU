# Ember GPU — Decision Log (ADR-style)

Each decision: context → choice → consequences. New decisions get appended; superseded
ones are marked ~~strikethrough~~ with a pointer to the replacement.

---

## D1 — Goal changed: "teaching GPU" → "real GPU" (2026-09-25)
**Context:** Original goal was a tiny-gpu-style educational design. User clarified:
"We need real gpu so we can run basic ai models and basic games."
**Choice:** Redefine Ember as a *real* accelerator: fixed-function 3D/2D graphics pipe +
int8 tensor unit + SIMT compute cluster, host on a RISC-V SoC, target real FPGA hardware.
**Consequences:** This invalidates the 8-bit tiny design. Data paths are now 32-bit,
ISA is 32-bit, memory is 512 KB BRAM (not 256 bytes), and we add fp32 math. Scope grew
~10×; the roadmap is now phased so we still ship value early.

## D2 — Graphics strategy: PS1-class fixed-function, not shaders (2026-09-25)
**Context:** Real games need real fill rate. Full shader GPUs (RasterIX-class or
beyond) are a huge undertaking; PS1-era hardware ran real shipped games.
**Choice:** Fixed-function pipeline: vector FPU geometry → setup → 1 px/clock
coverage/interp/texel/shade/ROP. RGB565 + 16-bit Z. Affine textures, CLUT palettes,
dithering. No programmable shaders in v1.
**Consequences:** We can hit 50 Mpix/s on a 50 MHz FPGA — 650× the PS1's ~77 Mpix/s
effective ceiling in raw fill terms is wrong; PS1 was ~1.5 Mpix/s effective; we are
~33× that. Games at PS1 fidelity are easily achievable. Shaders become a v3 topic.
Trade-off: modern-style art (per-pixel lighting) is off the table; PS1-style is the art
direction, by design.

## D3 — AI strategy: int8 systolic tensor unit, weight-stationary (2026-09-25)
**Context:** "Basic AI models" = MNIST, LeNet, MobileNet-0.25, small transformer
inference. All of these run fine int8 with int32 accumulators.
**Choice:** 16×16 int8 MAC systolic array (25.6 GOPS @ 50 MHz), weight-stationary
dataflow, double-buffered weights, memory-mapped from CP *and* reachable from cores.
**Consequences:** We avoid fp32 tensor hardware entirely (way too big for v1).
Quantization becomes a first-class software concern (converter tool in `tools/`).
Training is explicitly out of scope for v1.

## D4 — Shared memory system, AXI4-Lite fabric (2026-09-25)
**Context:** Graphics and compute both need bandwidth; duplicating memory is wasteful
on FPGA (BRAM is scarce), and a unified address space simplifies software.
**Choice:** Single VRAM pool (512 KB on-chip BRAM in v1), all initiators behind one
AXI4-Lite interconnect with round-robin + RTR-priority arbitration.
**Consequences:** Simpler mental model, one DMA path, one debug view. Risk: contention
between ROP writes and tensor unit reads; mitigated by RTR priority + tile FIFOs.

## D5 — 32-bit ISA (Ember-ISA v2), 16 GPRs/thread (2026-09-25)
**Context:** The earlier 16-bit ISA (tiny-gpu style) cannot address 512 KB, encode
tensor ops, or hold fp32.
**Choice:** 32-bit fixed-width encoding, 16 GPRs + 3 read-only (blockIdx, blockDim,
threadIdx), plus TLD/TST/TEXEC/TWAIT for tensor ops and VOP prefix for vector FPU.
**Consequences:** More decode logic than 16-bit, but dramatically more capable.
Assembly syntax stays tiny-gpu-like so kernels remain readable.

## D6 — Host CPU: NEORV32 RISC-V SoC (2026-09-25)
**Context:** A real GPU needs a driver CPU to set up command buffers, upload weights,
and flip frames. Options: open RISC-V softcore, hard ARM on Zynq, or no CPU (PC host
over UART/USB).
**Choice:** NEORV32 as the host SoC for v1 FPGA bring-up; the CP's MMIO interface is
CPU-agnostic so we can later swap in a PC-over-UART host or a bigger core.
**Consequences:** Self-contained console-like bring-up is possible on a cheap board.
C compiler toolchain (riscv-none-elf-gcc) becomes part of the stack. NEORV32 is VHDL —
acceptable; it integrates at the bus boundary, no HDL mixing inside Ember itself.

## D7 — Verification: cocotb + Verilator + Python golden model (2026-09-25)
**Context:** Complex GPU behavior (raster, tensor, memory races) is only trustworthy
if checked against an independent model.
**Choice:** Every block gets a cocotb testbench; every algorithm block (raster, TU,
GSX setup) gets a Python golden model compared cycle-accurately or end-of-frame.
**Consequences:** Slower to write tests, but debug happens in Python where iteration
is fast. This is how we avoid "simulated for weeks then broken on hardware."

## D8 — HDMI display target 640×480@60 (2026-09-25)
**Context:** Game consoles need video out. Project F's HDMI/VGA designs are proven
open references on cheap boards.
**Choice:** v1 targets 640×480@60 (with 320×240 letterboxed as a "PS1 mode"); the
Display Controller reads the framebuffer and drives VGA/HDMI depending on board.
**Consequences:** Pixel clock is 25.175 MHz (VGA) or ~25 MHz TMDS-friendly; our 50 MHz
system clock is 2× pixel clock, which lines up nicely with a 1-pixel/clock RTR.

## D9 — Build order: memory-first, graphics-pipe-second, tensor-third (2026-09-25)
**Context:** Everything else depends on working VRAM + interconnect.
**Choice:** Phase order in `roadmap.md`: AXI fabric + VRAM + CP → RTR (with golden
model) → Blitter + Display → GSX → Compute cores → Tensor Unit → integrate demos.
**Consequences:** Each phase ends with a demo you can see or measure (framebuffer
pattern → triangle → textured cube → MNIST inference). No phase depends on unfinished
later phases.

## D10 — Open-source toolchain only (2026-09-25)
**Choice:** Verilator, cocotb, Yosys/nextpnr (ECP5/iCE40), sv2v where needed; no
vendor-locked tools for the core design flow. Vendor tools allowed only for board
programming (e.g. openFPGALoader preferred).
**Consequences:** Slightly narrower FPGA target list up front; guarantees the project
stays reproducible and free forever.

## D11 — Core rebuild recipe: buy routing room with area, not iterations (2026-10-22)
**Context:** ember_core is the biggest block in the flow (609,288 placed
instances, 389,498 nets). Every rebuild opened detailed routing with hundreds of
thousands of violations and climbed from there (477K at iteration 0 on the first
attempt, 4M-class reports on the way), then plateaued at 105 residual DRCs. The
plateau was 67 met1 shorts + 31 met1 spacings — pin access, not long-wire
congestion: sky130 hd cells put their inputs on met1, and with cells abutted
row-wide every escape competes for the same few tracks.
**Choice:** for the next core rebuild, spend area up front instead of router
hours: GDS_UTIL=12 and GDS_PL_DENSITY=0.18 (25% more area than the previous
15/0.25 recipe), GDS_PL_PAD=2 (two unithd sites of left/right padding per cell,
i.e. a met1 escape corridor per cell), GDS_GRT_TILT=0.25 (met2 loses 25% of its
capacity so bulk wire climbs to met3/met4 and met2 stays free for the escapes),
60 DRT iterations and -drc_report_iter_step 2 so the violation count is visible
while it moves instead of only at the end.
Both new knobs are off by default, so proven blocks keep their exact recipe.
**Consequences:** the core die grows by roughly 12% per side, which this flow can
afford; violations should start in the hundreds rather than the hundreds of
thousands, and no rebuild can burn its whole timebox before the first count is
reported. Blocks are only signed off on zero routing violations plus zero
whole-layout Magic DRC, so a lower plateau is progress, not sign-off.

**Update 2026-10-23 (why it never finished):** the residual 105 violations were
all met1 (67 shorts + 31 spacings) even though `set_routing_layers -signal
met2-met5` reserves met1 for pin access — the `detailed_route
-bottom_routing_layer met1` argument handed it back to the router. **Rejected:**
GDS_DRT_BOTTOM=met2, because global route still emits met1 guide segments at the
pins and DRT then aborts with `DRT-0155 Guide in net _000_ uses layer met1 ...
outside allowed range`. met1 stays the bottom layer; the levers are whitespace
and per-cell padding, not layer bans.

**Update 2026-10-23 (the rebuild never even started):** three independent
failures made `core_rebuild.sh` burn its ladder in 48 s without routing once.
(1) `build/gds/core.v` had been regenerated without `rtl/ember_fpu4.sv`, which
`ember_core` instantiates — Yosys stopped at `Module \ember_fpu4 ... is not part
of the design`. (2) `harden_block.sh`'s synthesis RSS watchdog imports psutil,
which the login-shell python3 does not have, so yosys was reported as failed
before it ran. (3) The stall watchdog watched `rebuild_rN.log`, which only
receives stage headers, and killed a healthy rung whose OpenROAD had been at
300% CPU for 16 minutes with an idle log. Fixes: fpu4 added to the sv2v source
list (`sv2vall.sh`, `blocks.txt`), the flow's venv put on PATH, and the watchdog
now measures CPU time of the process tree from `/proc` (stdlib only) and kills
only when that stops advancing — covered by `test/watch_stall_test.sh`.

On top of that, scripts/gds/core_rebuild.sh replaces the single 12-hour gamble:
it walks a parameter ladder (util / density / padding / tilt), kills an attempt
whose log stops growing (GRT once sat 4 h at 13.6 GB without printing), keeps
the best routed DEF and escalates when a rung comes back worse than
GDS_MAX_VIOL (default 1000). Its decision logic is covered by --self-test, and
it refuses to start when the toolchain or PDK is not reachable instead of
hanging.
