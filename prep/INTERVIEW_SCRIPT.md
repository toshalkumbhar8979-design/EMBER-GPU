# Interview script — Ember GPU (first person)

> How to use this: these are **your** words, written as a spoken script. Read it
> once, then throw it away and talk from the shape of it. Interviewers can tell
> when something is memorised; they cannot tell when something is understood.
>
> The numbers are real — if you're asked to go deeper on any of them, the
> follow-up sections give you the honest answer.

---

## 1. The 30-second version

> "I built a GPU from scratch — the whole thing. Geometry engine, rasterizer with
> a Z-buffer and texturing, a four-lane IEEE-754 FPU I wrote from the gates up,
> a 16×16 int8 systolic tensor array, a four-thread compute core with my own
> 32-bit ISA and assembler, a command processor with DMA, and 512 KB of unified
> memory behind an AXI4-Lite fabric.
>
> Then I verified every block against an independent Python golden model —
> bit-exact, 31 out of 31 tests passing. I'm also taking individual blocks through
> synthesis, placement, clock trees, routing and DRC on SkyWater 130nm. Four
> exported block layouts have passed independent full-layout DRC; full-chip
> integration, LVS, timing closure and physical memory remain unfinished.
>
> The two demos are a real 3D game loop with a walking camera whose physics runs
> as a kernel on the GPU itself, and a trained CNN doing MNIST inference at 98%
> through the real RTL data path."

**Why this works:** it's specific, it's ordered (architecture → verification →
physical), and it ends on the demos, which is where the interest always lands.

---

## 2. The two-minute version (the one you'll actually use)

> "I'd read a lot about GPU architecture and I wanted to stop reading and start
> knowing, so I set a constraint: build one that can run both a basic AI model
> and a basic game, on open-source tooling only. 'From scratch' became the hard
> part — I wrote the FPU, the rasterizer, the tensor array, the ISA, the
> assembler, the golden models, the C driver and the place-and-route flow.
>
> Architecturally it's one memory system and two accelerators. The host is a RISC-V
> soft core that only ever talks to a command processor, which owns DMA and
> fences and kicks everything else. The graphics path is a geometry engine that
> does the MVP transform on a four-lane fp32 FPU and emits triangle packets into
> VRAM, and a rasterizer that walks a bounding box through a multi-cycle FSM:
> coverage, plane interpolation, Z-test, textured lookup, blending, dither,
> RGB565 output. The AI path is a weight-stationary 16×16 int8 array with adder
> trees and a requantization stage. And there's a four-thread compute core in the
> middle that runs kernels from my own ISA.
>
> The verification philosophy was: never trust the RTL against itself. Every
> block has an independent Python model — written in a different language, with
> every truncation and rounding step modelled explicitly — and the test requires
> bit-exact equality. That's how I caught things like the tensor unit's row
> counter being eight bits wide when a 688-row convolution needs twelve.
>
> For the demos, the pixel-exact approach doesn't scale to a whole scene with a
> HUD, so those tests assert structural properties instead — colour counts,
> coverage, distinct depth values, frame-to-frame change, and that the HUD's
> transparent pixels show the pre-blit scene.
>
> Then I took it to silicon geometry: sv2v to convert my SystemVerilog, Yosys and
> ABC to synthesize to sky130 standard cells, OpenROAD for floorplan, placement,
> CTS and routing, Magic for DRC, KLayout for the final GDS.
>
> Measured results: worst frame about 615,000 cycles: 6.15 milliseconds at an assumed
> 100 MHz, or 12.3 milliseconds at 50 MHz; 98% MNIST accuracy through the RTL with a software mirror
> that agrees exactly; and 1.57 GOPS sustained on the tensor unit — which is the
> honest weakness of the design, because the array's peak is much higher and the
> v1 controller is streaming-bound."

---

## 3. Deep-dive: the five questions they always ask

### "What was the hardest bug?"

> "The barrier deadlock. I had one shared instruction buffer for all four
> threads. Thread 0 hits the barrier first, its *next* fetched instruction
> wedges the only buffer, so the buffer never frees, so threads 1 through 3
> never arrive at the barrier. The core looks completely alive — it's executing,
> it's fetching, nothing is erroring — it just never finishes.
>
> The fix is per-thread instruction buffers. And I found a second instance of the
> same shape immediately after: if fetch and load share a memory port, a thread
> waiting on a load holds the buffer while the fetch that would unblock it can't
> get the port. Same circular wait, one level down. Separate ports.
>
> The lesson I take from it is that in a parallel machine, the bugs aren't in the
> logic, they're in *who is allowed to block whom*."

### "How do you know the RTL is actually correct?"

> "Two mechanisms. First, independent golden models: for each block I wrote a
> Python model that mirrors the hardware's arithmetic exactly — including
> truncation and rounding — and the test demands bit-exact equality. Not
> approximate. For the FPU that's 6,720 comparisons with zero mismatches. For
> the rasterizer it's per-pixel frame equality including depth.
>
> Second, for the demo scenes — 3D plus a blitted HUD — pixel equality isn't
> practical, so I assert structural properties that a broken renderer can't
> satisfy: at least twelve distinct colours, at least twenty thousand
> non-background pixels, at least fifty distinct depth values, consecutive frames
> that differ, and the HUD's transparent pixels showing the pre-blit background.
>
> The reason I'm careful about that: I once had a texture test pass for a whole
> phase because the golden model rendered black — it had never loaded its own
> checkerboard — and the RTL rendered black too, because it had lost a single
> enable bit. Black equalled black. Now every demo test fails loudly if the
> golden side is degenerate."

### "What's the tensor unit actually doing, and why is it only 1.57 GOPS?"

> "It's a weight-stationary systolic array — weights stay resident in the PEs
> and activations stream through, 16×16 int8 multipliers with per-column adder
> trees, int32 accumulation, then a requantization stage that rounds half-up
> back to int8 with a per-tensor scale. That's the classic TPU-v1 dataflow.
>
> The 1.57 GOPS number is sustained on a 256-cubed multiplication, at 100 MHz.
> The array itself can do far more — the peak works out to 25.6 GOPS at 50 MHz —
> At the same 100 MHz frequency, peak is 51.2 GOPS, so sustained is about 3.1% of peak. That's not a multiplier problem, it's a controller
> problem: my v1 address generator issues a tile, waits for it, issues the next,
> and never double-buffers operands, so the array spends most of its time
> waiting on memory. I deliberately left it that way for v1 rather than claim
> peak numbers — the fix is a streaming controller with operand double
> buffering, and it's the single biggest performance opportunity in the design.
>
> What I *am* proud of is that the accuracy is real: a trained LeNet-class CNN
> with int8 weights, run end to end through the RTL, 98 out of 100 test images
> correct, and the RTL output is byte-for-byte identical to the software mirror.
> Getting there was mostly quantization engineering — folding the biases into
> the adder taps as 127-unit rows, choosing pure-shift requantization so there's
> no multiplier rounding anywhere, and calibrating shifts from measured
> accumulator maxima rather than theory."

### "How does the game loop work — is the physics faked?"

> "No, it runs on the chip. There's a kernel in my ISA — about 112 instructions —
> that runs on thread 0 of the compute core, once per frame. It takes input
> words, applies acceleration with inertia, does velocity clamping, integrates
> position, clamps the camera to the walk path, and converts the result to
> IEEE-754 fp32 bit patterns so the host can patch the MVP matrix. Then it echoes
> a cookie so the host knows it finished.
>
> The physics is bit-exact against the Python mirror on all 32 frames of the
> demo. The one word I *can't* compute on-chip is the screen-offset term in the
> top row of the matrix, because that product needs 37 bits and the core's
> multiplier truncates at 32 — so the host does that one fold. I think that kind
> of honest boundary is more interesting to talk about than pretending
> everything is on-chip."

### "What did the ASIC flow teach you?"

> "That the gap between 'my RTL works' and 'real geometry' is enormous, and that
> most of it is tooling discipline.
>
> Two concrete things. First, my SystemVerilog uses packages and packed structs,
> which Yosys's frontend rejects — so sv2v is the front door, converting to
> Verilog-2005. Second, and much more painfully: flattening is a trap. With
> flatten enabled, my scan unit's multiplier templates expanded to 963,224 gates
> before ABC ever ran and synthesis effectively never finished. Hierarchical
> synthesis maps per-module, and OpenROAD links the hierarchy happily. The other
> one was the accumulator pass — carry-lookahead expansion turned every adder
> into Brent-Kung templates and ate 20 GB of RAM on a single block. Turning that
> off and letting ABC map ripple-carry logic was fine for an evaluation flow.
>
> The results are area, routing, timing and DRC per block, and a chip-level GDS
> assembly. And I'm explicit about what it is *not*: no pad ring, no SRAM macros
> for the 512 KB, no sign-off. It's a set of routed block layouts, with the complete physical implementation
> still in progress — not an integrated GPU ASIC or manufacturing-ready tapeout — and
> saying that clearly is part of the engineering."

---

## 4. Numbers you should have at your fingertips

| Metric | Value |
|---|---|
| Verification | 31/31 cocotb tests, bit-exact vs golden models |
| FPU checks | 6,720 comparisons, 0 mismatches |
| Worst frame | ~615k cycles; 6.15 ms @ assumed 100 MHz, 12.3 ms @ 50 MHz |
| Rasterizer throughput | Multi-cycle FSM; ~613k raster cycles in measured worst frame |
| HUD blit | 2,067 cycles |
| MNIST accuracy | 98/100 = 98.0%, RTL == software mirror exactly |
| Tensor sustained | 1.57 GOPS @ 100 MHz (25.6 GOPS array peak @ 50 MHz) |
| Memory | 512 KB unified VRAM, one AXI4-Lite fabric |
| Core | 4 threads, 32-bit ISA, 256-word kernel space |
| Physics kernel | 112 instructions, Q16.16, bit-exact over 32 frames |
| Host demo | 32 frames, final frame matches the testbench on 10,316/10,316 pixels |
| Process | SkyWater sky130, Yosys + OpenROAD + Magic + KLayout, all open source |

---

## 5. The keyword gaps — the honest line on each

> Screeners look for specific vocabulary, and this project genuinely exercises
> some of it and deliberately skips the rest. This section is the honest
> sentence for each one, so a gap becomes a framing instead of a fumble.

### AXI / AHB / APB (AMBA)

> "Everything on my chip — the RISC-V host, the command processor, both
> accelerators and the 512 KB memory — hangs off one AXI4-Lite fabric I wrote
> myself. So the AMBA master/slave model, the valid/ready handshake and the
> register-access discipline are things I've implemented, not just read about.
> I chose AXI4-Lite over full AXI4 deliberately: there are no bursts worth the
> fabric complexity for a command-and-DMA SoC. I can talk through where AXI4's
> burst channels, AHB's simpler pipeline or APB's two-phase register protocol
> each fit, and expanding my fabric to those is a throughput-versus-complexity
> decision, not a new vocabulary."

### UVM, functional coverage, constrained-random

> "My verification methodology is cocotb: 31 bit-exact tests against
> independent Python golden models, with both directed and randomly driven
> stimulus. The scoreboard concept is exactly what I built — an independent
> reference checking every transaction, in a different language from the RTL.
> What I haven't used is UVM itself, and I'll say that plainly. What adopting
> it gives you is standardised agents — driver, monitor, sequencer — RAL for
> register access, and above all functional coverage with constrained-random
> stimulus, so test-plan closure is measured in coverage bins instead of
> counted in passing tests. That last piece is a genuine gap in my flow, and
> the class-library syntax is the learnable part; the reference-model
> discipline transfers one to one."

### SystemVerilog Assertions (SVA)

> "My assertions live in the testbench rather than the RTL, but I know exactly
> where SVA would have earned its keep: the barrier deadlock I described is
> precisely the bug class SVA exists for. One property written into the RTL —
> that a shared instruction buffer can never stay occupied more than N
> consecutive cycles, or a bounded-window assertion that every thread reaches
> the barrier — would have caught it in the first simulation that exercised
> it, instead of days of staring at waveforms. That's my honest argument for
> assertions in the design itself: they run on every simulation, forever."

### Clock domain crossing (CDC)

> "I made a deliberate decision to keep the whole SoC in a single clock
> domain, because I understood what CDC bugs cost and had no silicon debug
> budget to pay for one. The theory I know: two-flop synchronisers for level
> signals, grey-coded pointers for pointer-crossing FIFOs, handshakes for
> multi-word transfers, and why re-converging two synchronised signals is
> where the real bugs hide. What I haven't done is debug a live metastability
> failure in the lab — that gap only closes on a genuinely multi-domain
> chip."

### Static Timing Analysis (STA), SDC, timing constraints

> "Timing I've closed through the OpenROAD flow: an SDC defines the clock —
> create_clock at the 100 MHz target — and after CTS and routing I read the
> setup/hold slack reports. My pass criteria are a zero-violations count with
> non-negative slack, and 'timing MET' at the end of a converged route; one
> block is closed that way and the big core is still iterating, which is the
> honest state. What a sign-off STA tool like PrimeTime adds beyond what I've
> done — multi-corner multi-mode analysis, derating, OCV — I know
> conceptually but haven't run."

### Tcl

> "Tcl is the scripting layer of my whole back-end: every OpenROAD step from
> floorplan to detailed route is a Tcl script I wrote, with the flow knobs as
> Tcl variables — the same language behind Vivado and OpenLane, so only the
> command names differ per tool. And my favourite war story is a pure Tcl
> lesson: heredocs substitute dollar-escapes silently, so one unescaped
> `$` block emptied five variables in my generated floorplan script, and
> every block behind it failed with an invalid-command error before routing
> ever started. The fix was re-escaping the dollar signs, verified by
> regenerating the script and diffing it byte-identical against a known-good
> one."

### FSM, FIFO, lint

> "The rasterizer is an explicit multi-cycle FSM — coverage, plane
> interpolation, Z-test, texture lookup, blending, dither — and both of my
> register-level discipline stories are FSM stories: a missing unconditional
> default in an always_comb that Verilator flagged as an inferred latch, and
> the barrier deadlock, which was never arithmetic — it was who was allowed
> to block whom. The datapath carries FIFOs wherever producer and consumer
> rates diverge; the per-thread instruction buffers are literally the
> deadlock fix. Lint is a hard gate in my flow: Verilator's warning set runs
> on every regression, there is exactly one documented waiver for a benign
> width expansion, and everything else is fixed or explained. I'd rather
> close warnings than collect them."

### ModelSim / Questa / VCS

> "My simulators are Verilator under cocotb — chosen because the whole project
> runs on open-source tooling and it fit the cycle counts I needed on the
> hardware I had. I have not driven Questa, ModelSim or VCS, and the honest
> framing is that what I'd be learning there is a tool UI — waveform viewers,
> debug windows, coverage databases — not concepts. A clocking block, an
> interface object, a coverage bin: those mean the same thing in any of
> them."

> The pattern in every answer above is deliberate: name the adjacent thing I
> actually built, name exactly what the missing tool would have added, and
> lead with the concrete bug or decision where it would have changed the
> outcome. It lands better than pretending a gap isn't there.

---

## 6. Questions you should ask *them*

Ask these — they signal seniority more than answers do:

- "How do you decide where to draw the line between golden-model verification
  and formal methods in your flow?"
- "When you take a design to silicon, who owns the interface between the RTL
  team and the physical design team — and how do you keep that from being a
  throwing-stuff-over-the-wall problem?"
- "What's the biggest performance cliff you've hit that turned out to be an
  interface or memory problem rather than a compute problem?"
- "How much of your verification is structural, like mine, versus exact? And how
  do you keep the structural tests from passing vacuously?"

---

## 7. Be ready for these two pushbacks

**"Isn't this just a toy compared to a real GPU?"**

> "It's a small GPU, and I'd rather say that plainly than oversell it. It draws
> at one pixel per clock and its tensor unit is streaming-limited. But it isn't
> a toy in the sense that matters: it's a complete system — memory, host
> interface, command processor, two accelerators, a compute core, verified
> bit-exact, and taken all the way to routed geometry. What a toy lacks is
> exactly what this has: coherence end to end, and honest measurement of where
> it's slow."

**"Why build something that already exists?"**

> "Because the alternative is to keep *reading* about GPUs. I now know things
> about rasterization, IEEE-754, systolic dataflow and physical design that I
> could not have learned any other way — and the parts that transferred most
> were the failures. Nobody writes papers about the day your barrier deadlocks
> because of a shared buffer, but that's the day I actually understood
> parallel correctness."

---

## 8. If they ask to see it

Show, in this order — the visual order matters:

1. A verified block-layout render — "this is one block's routed GDS, not an integrated chip." Do not show the die-shot placeholder as a result.
2. `paper/figures/input_f10.png` — "and this is a frame it drew."
3. `paper/figures/mnist_montage.png` — "and these are digits it classified."
4. `paper/figures/architecture.png` — "here's how those three connect."

Then say: "the paper is nine pages, and the last section is every bug that cost
me more than a day — that's the part I'd actually recommend reading."
