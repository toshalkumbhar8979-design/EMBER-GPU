# Resume points — Ember GPU only (verified numbers, ready to lift)

> Every number below exists on disk (paper, RESULTS tables, flow logs). Use
> the bullets as written — don't pad, the specificity *is* the strength.
> Weak claims cost interviews; every line here survives a follow-up question.

---

## 1. The five strongest bullets (lift straight into the resume)

- **Designed a complete GPU SoC from scratch in SystemVerilog** — PS1-era
  rasterizer (Z-buffer, CLUT textures, alpha blending, dithering) driven by a
  multi-cycle **FSM**, a 4-lane **IEEE-754 fp32 FPU** (round-to-nearest-even,
  subnormals, NaN handling), a 16×16 int8 systolic tensor array (TPU-v1
  weight-stationary dataflow), and a 4-thread compute core with a custom
  32-bit ISA and self-written assembler — integrated over a self-built
  **AMBA AXI4-Lite** fabric with 512 KB unified memory and a DMA command
  processor.

- **Verified bit-exact against independent Python golden models**: 31/31
  cocotb tests where every truncation and rounding step is modelled in a
  different language from the RTL. Caught real bugs this way — e.g. the
  tensor unit's row counter being eight bits wide when a 688-row convolution
  needs twelve. Trained LeNet CNN at **98% MNIST accuracy through the real
  RTL data path**, byte-for-byte identical to the software mirror; FPU
  validated with **6,720 comparisons, 0 mismatches**.

- **Scripted the complete ASIC back-end in Tcl** — OpenROAD floorplan,
  placement, CTS, global/detailed routing driven by my Tcl scripts with SDC
  clock constraints; exported GDS validated by independent Magic DRC audits:
  **designing blocks at 0 DRC violations, timing MET** (non-negative STA
  slack); **2.27M standard cells** mapped across 11 blocks on SkyWater
  sky130, all open-source tooling (Yosys, OpenROAD, Magic, KLayout).

- **Performed quantitative performance diagnosis, not just measurement**:
  tensor unit sustains 1.57 GOPS against a 51.2 GOPS array peak at 100 MHz;
  traced the 3% efficiency to a streaming-bound address controller that never
  double-buffers operands — quantified headroom, named the fix (streaming
  controller with operand double-buffering), didn't claim peak numbers.

- **Made a deliberate verified-simplification trade: single clock domain**.
  Kept the whole SoC on one clock to eliminate **clock-domain-crossing (CDC)**
  bugs entirely, knowing the synchroniser theory (two-flop, grey-coded
  pointers, handshakes) would be needed only on a genuinely multi-domain
  chip — a scoping decision, not an avoidance.

Supporting bullets (use if space allows):

- Game physics runs *on the GPU itself*: a 112-instruction Q16.16 kernel on
  the compute core integrates the walking camera every frame, bit-exact vs
  the Python mirror over all 32 demo frames.
- Structured-assert philosophy for full scenes: tests assert properties a
  broken renderer can't satisfy (≥12 colours, ≥20k non-background pixels,
  ≥50 depth values, frame-to-frame change) and fail loudly if the golden
  model is degenerate — after a texture test passed for a whole phase
  because black equaled black.
- Demo: real 3D game loop + trained CNN inference; final host frame matches
  the testbench on 10,316/10,316 pixels.

---

## 2. The keyword gaps — how to present each one

These eight keywords are what screeners look for in RTL/SoC roles. Where the
project supplies real hands-on evidence, the keyword goes in the resume as
done. Where it's theory-level, present it as *named, qualified* — that is
defensible; pretending is not.

| Keyword | Your evidence | How to write it |
|---|---|---|
| **AXI / AHB / APB (AMBA)** | Wrote the entire chip's AXI4-Lite fabric yourself | "Self-built **AXI4-Lite (AMBA)** system fabric" — *resume-ready* |
| **STA / SDC / timing constraints** | SDC create_clock at 100 MHz; slack reports read after CTS/route; blocks closed "timing MET" | "SDC-constrained **STA**; closed blocks at 0 DRC with positive slack" — *resume-ready* |
| **Tcl** | Every OpenROAD step is your Tcl script; the heredoc dollar-escape war story is yours | "Scripted OpenROAD/Vivado-style flows in **Tcl**" — *resume-ready* |
| **FSM / FIFO / lint** | Rasterizer multi-cycle FSM; per-thread FIFOs are the deadlock fix; Verilator lint gate on every regression, one documented waiver | "*"Multi-cycle FSM/FIFO** datapath design; Verilator **lint** gate (1 documented waiver)" — *resume-ready* |
| **CDC** | Clipped theory; the deliberate single-clock design | "Single-clock-domain SoC by design (CDC risk avoided); two-flop synchroniser/grey-pointer theory known" — *qualified* |
| **UVM / functional coverage / constrained-random** | Golden-model + cocotb scoreboard discipline; no UVM/coverage closure | "**UVM (methodology familiar)** — independent scoreboards, agents, coverage-driven closure concepts; hands-on equivalent built in cocotb" — *qualified only; never claim hands-on* |
| **SVA (SystemVerilog Assertions)** | Your barrier deadlock is the killer example of what SVA would have caught | Not on the resume as used; in interviews: "one property — buffer can't stay occupied >N cycles — would have caught my barrier deadlock in sim 1" |
| **ModelSim / Questa / VCS** | Verilator + cocotb only | Leave off the resume; interview line: "my simulators are Verilog/cocotb by choice of open tooling; a clocking block or coverage bin means the same thing in Questa" |

The one honest pattern for every gap: *name the adjacent thing you built →
name exactly what the missing tool adds → lead with the concrete bug where
it would have helped.* That beats pretending every time.

---

## 3. Ready-to-paste skills lines for the CV

**Languages:** Python, C++, Embedded C, Verilog HDL, SystemVerilog, Tcl
**Hardware/VLSI:** RTL design (FSM/FIFO), AMBA AXI4-Lite, SDC + STA timing
closure, Verilator lint, UVM methodology (familiar), SVA (concepts)
**EDA tools:** Yosys, OpenROAD, OpenLane 2, Magic, KLayout, Vivado, Verilator,
cocotb, MATLAB

---

## 4. Numbers you may quote, verbatim

| Claim | Value |
|---|---|
| Verification | 31/31 cocotb tests, bit-exact vs golden models |
| FPU | 6,720 comparisons, 0 mismatches |
| MNIST through RTL | 98/100, byte-identical to software mirror |
| Block DRC | 0 violations (audited independent of the flow that made them) |
| Standard cells mapped | 2,266,911 across 11 blocks |
| Tensor sustained vs peak | 1.57 GOPS vs 51.2 GOPS @ 100 MHz (3% — diagnosed, not excused) |
| Worst frame | ~615k cycles → 6.15 ms @ 100 MHz, 12.3 ms @ 50 MHz |
| Physics kernel | 112 instructions, Q16.16, bit-exact over 32 frames |
| Final demo frame | 10,316/10,316 pixels match testbench |

One caution: the core block's physical run is **still in progress** — never
say "whole chip taped out" or "sign-off complete." The sealed claims are:
verified bit-exact RTL, multiple blocks at 0 DRC, timing-MET routing.
