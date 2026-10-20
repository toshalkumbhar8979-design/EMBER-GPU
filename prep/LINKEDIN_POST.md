# LinkedIn post — Ember GPU

> Post this as **text + images** (not an article). LinkedIn's algorithm favours
> native images over links; put the repo link in the **first comment**, not the
> body. Suggested posting time: weekday morning, your local 8–10am.

---

## Post body (copy from here)

I built a GPU from scratch. Not a simulation of a GPU — an actual chip design:
my own rasterizer, my own floating-point unit, my own instruction set, my own
tensor core. The RTL runs graphics and inference demos in simulation, and
several blocks now have routed, DRC-checked GDS layouts.

One Windows/WSL machine and an open-source toolchain.

Here's what "from scratch" ended up meaning:

→ A command processor with DMA and fences, driving everything through one
AXI4-Lite bus.

→ A multi-cycle rasterizer with a Z-buffer, CLUT textures,
alpha blending and dithering — the whole PS1-era output stage, in logic.

→ A 4-lane IEEE-754 fp32 vector FPU written from the gates up: round-to-nearest-
even, subnormals, NaN handling. Getting the rounding modes right cost me two
weeks and taught me more about floating point than any course did.

→ A 16×16 int8 systolic tensor array that runs a real CNN. Not "a matmul
benchmark" — a trained LeNet that reads an actual MNIST digit and names it,
98% accuracy, with the RTL byte-for-byte identical to the software model.

→ A 4-thread compute core with its own 32-bit ISA and assembler, which runs the
game's physics: the camera you see walking through the temple is being
integrated every frame by instructions the GPU executes itself.

→ Verification I actually trust: 31/31 tests passing against independent Python
golden models, bit-exact — every pixel, every byte of every layer.

Then the part I'd never done before: taking RTL and turning it into *geometry*.
sv2v → Yosys → OpenROAD → Magic → KLayout, on the open SkyWater 130nm process.
Floorplan, placement, clock tree, detailed routing, DRC, GDS-II. Real polygons
that a foundry tool could open.

The thing nobody tells you: almost none of the bugs were in the clever parts.
The multiplier array worked. The rasterizer worked. What broke was the
*interfaces* — a shared instruction buffer that deadlocked every barrier, a
fetch port that starved load-waiting threads, a counter that was eight bits wide
when it needed twelve, a logical right-shift that turned negative velocity into
a huge positive number. Every one of those cost a day or more. Every one of them
is now a paragraph in the paper I wrote about the project.

I'm preparing an IEEE-style paper covering the architecture, the
verification methodology, the layout results, and a section at the end listing
every bug that humbled me. Because the failures are the transferable part.

Next up: a Wolfenstein-style raycast renderer as a compute kernel, because the
sixty-year-old question of "can it run DOOM" deserves an honest answer.

If you're building hardware or learning it — the whole thing is open and
documented. Ask me anything in the comments.

---

## Image attachments (attach in this order)

LinkedIn supports 20 images max; use these 8, in this order — the first image is
the "hook" thumbnail:

| # | File | Why |
|---|------|-----|
| 1 | `paper/figures/gds_block.png` | Use only after replacing the placeholder with a validated block-layout render; not a whole-chip claim. |
| 2 | `paper/figures/input_f10.png` | The temple render — a 3D scene produced by RTL simulation, not fabricated silicon. |
| 3 | `paper/figures/mnist_montage.png` | Digits with predictions — the AI half, visually obvious in one glance. |
| 4 | `paper/figures/architecture.png` | The block diagram — for the engineers who want to see the structure. |
| 5 | `paper/figures/cube_rtl.png` | The first thing the rasterizer ever drew correctly. Sentimental but also: bit-exact vs golden. |
| 6 | `paper/figures/gds_block.png` | One block zoomed into — standard-cell rows and routing, so the GDS claim is visible. |
| 7 | `paper/figures/orbit_f3.png` | Second scene angle — shows it's a pipeline, not one hardcoded frame. |
| 8 | `paper/figures/fly_f0.png` | HUD over the scene, with key transparency — the game-loop frame. |

**Alt text** (accessibility + reach) — LinkedIn lets you add it per image:
1. "Routed layout of an individual Ember logic block on SkyWater 130nm; chip integration is unfinished."
2. "Frame from a textured 3D temple scene rendered by the custom GPU RTL."
3. "Ten handwritten digits with the predicted label from the GPU's int8 tensor core."
4. "Block diagram of the GPU: host, crossbar, command processor, VRAM, geometry engine, rasterizer, tensor unit, compute core."

---

## First comment (post immediately after publishing)

Full source, the paper PDF, and the layout scripts are here:
`<repo link>`

Everything is open-source: RTL, golden models, the assembler, the C driver, and
the ASIC flow. `make lint && cd test && make` reproduces the 31/31 verification
suite; `scripts/gds/run_all.sh` reproduces the layout.

---

## Hashtags (put at the very end of the post, not in the first comment)

#hardware #chipdesign #gpu #riscv #asic #sky130 #openlane #verification
#computerarchitecture #semiconductor #fpga

---

## Honesty checklist before you post

Do **not** claim any of these (they aren't true yet):
- not taped out at a foundry, no pad ring, no memory macros, no full sign-off;
- not faster than anything commercial (1.57 GOPS sustained on the tensor unit);
- not running on a physical FPGA board yet (the firmware and the sim-side host
  interface are done; the board is not in hand).

Do say: RTL demos verified in simulation; individual blocks routed and DRC
checked; physical implementation remains in progress. Do not post placeholder
layout images or claim all twelve blocks, LVS, timing closure, or chip integration
are finished. Confirm the latest counts in build/gds/RESULTS.md before posting.
