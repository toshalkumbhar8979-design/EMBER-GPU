# Ember GPU — Research Notes (living document)

Condensed findings from deep research. Every major claim carries a source. Update this file
whenever we research something new — it is the project's shared library.

---

## 1. What "basic games" actually requires — the PS1 reality check

The PlayStation 1 is the honest baseline for "basic games," and it is shockingly modest:

- **Geometry:** a 33 MHz MIPS R3000 + GTE coprocessor produced roughly **90k textured
  polygons/sec** and **360k flat/sec**. Vertex math was *software*, on the CPU.
  Source: David Colson, "Building a PS1 style retro 3D renderer" —
  https://www.david-colson.com/2021/11/30/ps1-style-renderer.html
- **Raster:** the PS1 GPU is a pure raster engine fed by pre-transformed vertex draw
  commands over a GP0 FIFO. Copetti's console analysis and the pikuma article both
  describe the GPU as receiving *already-transformed* primitives.
  https://www.copetti.org/writings/consoles/playstation/ ,
  https://pikuma.com/blog/how-to-make-ps1-graphics
- **No Z-buffer.** PS1 used a per-primitive **ordering table** (sorted linked lists) to
  handle depth ordering, which is why it *could* be this small.
- **Texturing:** CLUT (4/8-bit palettized) and 15-bit direct textures, **affine** mapping
  (no perspective correction — the infamous texture warping), dithering instead of true
  alpha blending in many games. Reddit/EmuDev writeup:
  https://www.reddit.com/r/EmuDev/comments/fmhtcn/article_the_ps1_gpu_texture_pipeline_and_how_to/
- **Display:** 320×240-ish 15-bit framebuffer to a video encoder. PS1 tech specs:
  https://en.wikipedia.org/wiki/PlayStation_technical_specifications

**Budget math we adopt:** a 1-pixel/clock raster path at 50 MHz = 50 Mpix/s ≈
650 complete 320×240 frames/s of pure fill. Even at 10% efficiency that is ~65 fps of
overdraw-2 scenes — exactly PS1-class headroom. PS1-class games also expect *worse*
than this; we have margin.

## 2. What a rasterizer block looks like in hardware

- Triangle setup + edge-function coverage tests + per-pixel attribute interpolation via
  **plane equations** is the canonical structure (Fabian Giesen's pipeline series, part 6:
  https://fgiesen.wordpress.com/2011/07/06/a-trip-through-the-graphics-pipeline-2011-part-6/ ;
  scratchapixel's practical implementation:
  https://www.scratchapixel.com/lessons/3d-basic-rendering/rasterization-practical-implementation//rasterization-practical-implementation.html)
- A Columbia class project (DE1-SoC, 2026) built exactly this: edge functions, 2D
  bounding box, pixel pipeline — proof this fits a small FPGA comfortably.
  http://www.cs.columbia.edu/~sedwards/classes/2026/4840-spring/designs/3D-Hardware-Rasterizer.pdf
- Attribute interpolation = incremental plane-equation stepping per pixel
  (Kugler et al., "The Setup for Triangle Rasterization"):
  https://diglib.eg.org/bitstream/handle/10.2312/EGGH.EGGH96.049-058/049-058.pdf

## 3. Prior art: open FPGA graphics that *really work*

- **RasterIX** — OpenGL 1.x-class fixed-function rasterizer in Verilog for FPGAs (the
  closest existing thing to our 2D/3D pipe; study its ROP/blending design).
  https://github.com/ToNi3141/Rasterix
- **voodoo-fpga** — full SystemVerilog re-implementation of the 3dfx Voodoo pipeline;
  demonstrates the complete texel→blend→ framebuffer path at FPGA clock rates.
  https://github.com/victor-fisyuk/voodoo-fpga-public
- **Polyphony** (Kenji Ishimaru) — HW rasterizer + SW geometry engine + middleware.
  https://github.com/Kenji-Ishimaru/polyphony
- **Project F "Beginning FPGA Graphics"** — the best introductory material on framebuffers,
  H/V timing, sprite engines, and HDMI out. https://projectf.io/posts/fpga-graphics/
- Teaching-theory references for edge functions and barycentric interpolation:
  lisyarus blog part 2 — https://lisyarus.github.io/blog/posts/implementing-a-tiny-cpu-rasterizer-part-2.html

## 4. What "basic AI models" actually requires

- **int8 MAC systolic arrays are the proven design**: Google's first TPU v1 was a
  256×256 array of 8-bit MACs (65,536 ALUs) with weight-stationary dataflow.
  Google Cloud blog: https://cloud.google.com/blog/products/ai-machine-learning/an-in-depth-look-at-googles-first-tensor-processing-unit-tpu
  Chip Letter deep dive: https://thechipletter.substack.com/p/googles-first-tpu-architecture
- **Weight-stationary dataflow** (weights pre-loaded, activations march through the
  array) is the dataflow we will copy; telesens has the clearest walkthrough:
  https://telesens.co/2018/07/30/systolic-architectures/
- **Gemmini** (Berkeley) is the reference open-source systolic-array generator: supports
  both output-stationary and weight-stationary, int8 and fp32, DMA + scratchpads, and it
  actually works on FPGA via Chipyard. https://github.com/ucb-bar/gemmini ,
  https://arxiv.org/html/1911.09925v2
- Systolic arrays win because of **data reuse**: one weight feeds N activations (N
  computations per memory read), exactly what low-bandwidth FPGAs need
  (LinkedIn explainer + arXiv DiP paper):
  https://www.linkedin.com/posts/emi-andere_most-of-an-llms-compute-is-matrix-multiply-activity-7433949202898128896-hHuy ,
  https://arxiv.org/html/2412.09709v2
- Many small **FPGA CNN accelerators in plain Verilog exist** (MNIST/LeNet-class, int8
  systolic arrays) — confirming feasibility at our scale:
  https://github.com/topics/cnn-accelerator?l=verilog&o=desc&s=updated ,
  LeNet-5 demo achieving 98.2% on MNIST: https://www.reddit.com/r/FPGA/comments/1ti5jc4/lenet5_cnn_accelerator_demo/
- Quantization note: int8 activations/weights + int32 accumulator, requantize to int8
  (or fp16 for later) is the standard inference recipe on all these designs.

**Budget math we adopt:** a 16×16 int8 MAC array @ 50 MHz = 256 MACs × 2 ops × 50 M = **25.6 GOPS**.
MNIST MLP ≈ 100k MACs/inference → >100 inferences/s just from the array; a LeNet-class CNN
(~1M MACs) still runs realtime-ish. This is "basic AI models" territory, honestly.

## 5. The compute substrate: our SIMT core remains the glue

- Vortex (GaTech) is the most active open RISC-V GPGPU; its wspawn/tmc/split/join/bar
  instructions are the model for our divergence/barrier handling.
  https://github.com/vortexgpgpu/vortex ,
  ISA manual: https://github.com/vortexgpgpu/vortex-riscv-isa-manual/blob/main/main.tex
- MIAOW (UW–Madison) shows what a *full* GPGPU compute unit (AMD GCN-class) looks like
  in RTL — useful when we scale past teaching-grade cores.
  https://github.com/VerticalResearchGroup/miaow
- Nyuzi (Jeff Bush) — VLIW GPGPU with a full LLVM software stack; good model for how to
  structure kernel-side software. https://github.com/jbush001/NyuziProcessor
- tiny-gpu (adam-maj) remains our skeleton reference for dispatcher → cores → memory
  controllers. https://github.com/adam-maj/tiny-gpu
- tiny-gpu's "Advanced Functionality" list (pipelining, coalescing, divergence, barriers,
  shared memory) is precisely the phase-3 work for our compute cores.
- NVIDIA CUDA docs remain the vocabulary standard for SIMT/warp/memory-hierarchy terms:
  https://docs.nvidia.com/cuda/cuda-programming-guide/

## 6. Toolchain & platform reality

- **Verilator** (fast open simulator) + **cocotb** (Python testbenches) + **sv2v**
  (compat shims) is the standard open verification stack.
  https://www.veripool.org/verilator/ , https://www.cocotb.org/ , https://github.com/zachjs/sv2v
- **Yosys + nextpnr** support ECP5 and iCE40 fully open-source; ECP5 boards with HDMI
  (e.g. Colorlight i5/i9) are the cheap real-hardware path.
- **NEORV32** — complete, synthesis-friendly RISC-V SoC in VHDL with AXI4-lite-lite-style
  bus, timers, DMA, and good docs; our pick as the host CPU for the first real hardware
  bring-up. https://github.com/stnolting/neorv32
- **NVDLA** and **Tensil** are the two serious open NPU designs (bigger than we need, but
  study their DMA/tiling). NVDLA: http://nvdla.org/ ; Tensil: https://github.com/tensil-ai/tensil
- DRAM: for v2 boards, consider LiteX + LiteDRAM (https://github.com/enjoy-digital/litex)
  as a DDR3 controller donor; for v1 we stay on on-chip BRAM.

---

## 7. Honest scale statement (what Ember v1 can and cannot do)

CAN: MNIST/LeNet-class CNNs, small MLPs, tiny LLM inference (int8, ~10M params max),
2D games (sprites/tiles), PS1-class 3D games (flat/Gouraud/affine-textured triangles,
~320×240 @ 30+ fps), framebuffer compositing, video-out at 640×480@60 or 320×240@60.

CANNOT (yet): fp32 training, anything Modern-3D (shaders, perspective-correct blending
of complex scenes), large LLMs, high resolutions/3D at high fps. This is the v2/v3 ladder.
