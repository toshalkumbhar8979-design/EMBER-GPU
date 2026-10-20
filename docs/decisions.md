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
