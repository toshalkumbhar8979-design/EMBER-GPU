# Ember chip — pinout & external memory interface

This document specifies the chip-level I/O: the real pad ring, the physical
pinout, and the real external memory interface. It is derived from
[`scripts/gds/pinout.csv`](../scripts/gds/pinout.csv) (single source of truth)
and generated artifacts; `python3 scripts/gds/make_pad_ring.py --check`
verifies that the pinout, the ring generator, and
[`rtl/ember_chip.sv`](../rtl/ember_chip.sv) all agree.

## Chip architecture

```
   +-------------------------------------------------------------------+
   |                       PAD RING (sky130_fd_io)                     |
   |                                                                   |
   |   +---------------- ember_die (hardened) -------------------+     |
   |   |  24 cores + xbar + CP + RTR + GSX + TU + display        |     |
   |   +------- raw external VRAM bundle (v_*, fpa*, ixa, ...) --+     |
   |                            |                                     |
   |                   +--------v---------+                           |
   |                   |   ember_memif    |  3-ch SRAM controller     |
   |                   | broadcast writes |                           |
   |                   +--------+---------+                           |
   |                            |  real SRAM pins                     |
   +-------------------------------------------------------------------+
```

* [`rtl/ember_chip.sv`](../rtl/ember_chip.sv) — chip top: pad ring + die +
  memory controller. Port names == pinout.csv signal names.
* [`rtl/ember_memif.sv`](../rtl/ember_memif.sv) — external memory controller
  (EMC): converts the die's raw multiport VRAM bundle into the physical
  SRAM interface below.
* [`rtl/pad_models.sv`](../rtl/pad_models.sv) — behavioral pad wrappers for
  simulation/lint; the physical flow swaps in
  `build/gds/chip/pad_cells_physical.v` (real `sky130_fd_io__top_gpiov2` /
  `__top_xres4v2` cells, generated). Same module names, so `ember_chip.sv`
  is identical in both flows.
* The VRAM debug sidecar (`dbg_*`) is a testbench artifact and is **not
  bonded out** — it is tied off inside the chip. Real host access to VRAM
  goes through the `h_*` AXI4-Lite port.

## External memory interface

The die's VRAM was hardened off-die as a raw port bundle (one AXI4-Lite port
plus seven fixed-latency "fast" ports). No real memory device looks like
that. The EMC provides the physical interface:

**3 read channels + 1 broadcast write bus. Each channel is the read port of
one external 128K x 32 simple-dual-port SRAM; the write bus drives all
three simultaneously (replicated memory — the standard construction for
multiport access).** Each SRAM holds the full 512 KiB VRAM map
(`VRAM_BYTES`); the three read ports see identical data at all times.

| pins | width | dir | function |
|---|---|---|---|
| `mem_waddr[16:0]` | 17 | out | write address (word index `addr[18:2]`, base-stripped) |
| `mem_wdata[31:0]` | 32 | out | write data |
| `mem_wbe_n[3:0]` | 4 | out | byte enables, active low |
| `mem_we_n` | 1 | out | write enable, active low (commits at the rising edge) |
| `mem{0,1,2}_raddr[16:0]` | 17 | out | per-channel read address |
| `mem{0,1,2}_rdata[31:0]` | 32 | in | per-channel read data (async: valid within the request cycle) |
| `mem{0,1,2}_re_n` | 1 | out | per-channel read enable, active low |

Timing contract — identical to the on-die `ember_vram` it replaces, so every
master in the die works unchanged:

* **read**: request + address during cycle N → data valid during N+1
* **write**: commits at the edge ending the request cycle
* **same-cycle read-during-write of one address returns the OLD value**
  (device must be "read-old-data", as the behavioral model in
  [`test/memif_tb.sv`](../test/memif_tb.sv) is)

```
cycle:        N          N+1         N+2
raddr  ------< A >----------------------
re_n   ------< 0 >----------------------
rdata  -------------------< data(A) >---   (captured at edge N+1)
waddr  ------< B >----------------------
we_n   ------< 0 >----------------------
                ^ write commits here
```

### Channel map (why 3)

| ch | served | why |
|---|---|---|
| CH0 | `fpa3` (display scan) | fires every visible cycle; never stalls |
| CH1 | `fpa`, `fpa2`, `gxa`, `cxa`, `tua` | engine traffic; mutually exclusive by the CP one-engine-at-a-time contract (the die already assumes this for its rtr/blit `fpa` ownership mux), and `fpa`/`fpa2` never fire in the same rtr_scan FSM cycle |
| CH2 | `ixa` (core fetch) + AXI4-Lite (`v_*`) | `ixa` has fixed latency and wins conflicts; AXI-Lite is the only port in the bundle that legally stalls (`v_arready`/`v_awready` drop) |

Worst case is display + core load + core fetch firing together
(`fpa3` + `cxa` + `ixa`) = exactly three simultaneous non-stallable
accesses. Write bus arbitration: engine writes cannot stall (priority
`fpa > fpa2 > cxa > tua > gxa`), AXI writes wait in the skid. The
one-engine-at-a-time contract is checked by a simulation assertion in the
EMC.

Real parts: 3x 128Kx32 simple-dual-port SRAM (separate read port + write
port, e.g. dual-port SRAM families such as IDT7005/Cypress CY7C131-class, or
modern SDP SRAM), ~10-15 ns async-read access — comfortably inside the
chip's 20 ns cycle at the die's 50 MHz. The write bus is wired to all three
devices' write ports.

## Pinout

373 signal pads + 53 power/ground pads + 4 corner cells = **430 pads**.
Die **8280 x 9455 µm (78.3 mm², pad-limited)** — ring band depth 200 µm,
`sky130_fd_io__top_gpiov2` pads (80 µm pitch), `__top_xres4v2` reset pad
(75 µm). Full machine-readable pinout: [`scripts/gds/pinout.csv`](../scripts/gds/pinout.csv);
generated pad-by-pad placement: `build/gds/chip/pad_ring_placement.csv`.

Ring order is counter-clockwise: south row L→R (R0), east column B→T (R90),
north row R→L (R180), west column T→B (R270).

### North (top) — host AXI4-Lite write channels (76 pins)

| signal | width | dir | notes |
|---|---|---|---|
| `h_awaddr` | 32 | in | write address |
| `h_awvalid` | 1 | in | |
| `h_awready` | 1 | out | |
| `h_wdata` | 32 | in | |
| `h_wstrb` | 4 | in | byte enables |
| `h_wvalid` | 1 | in | |
| `h_wready` | 1 | out | |
| `h_bresp` | 2 | out | |
| `h_bvalid` | 1 | out | |
| `h_bready` | 1 | in | |

### South (bottom) — host AXI4-Lite read channels, mode, display (91 pins)

| signal | width | dir | notes |
|---|---|---|---|
| `h_araddr` | 32 | in | read address |
| `h_arvalid` | 1 | in | |
| `h_arready` | 1 | out | |
| `h_rdata` | 32 | out | |
| `h_rresp` | 2 | out | |
| `h_rvalid` | 1 | out | |
| `h_rready` | 1 | in | |
| `fb_select` | 2 | in | framebuffer select strap |
| `vid_hs` | 1 | out | display HSYNC |
| `vid_vs` | 1 | out | display VSYNC |
| `vid_de` | 1 | out | display data enable |
| `vid_pixel` | 16 | out | RGB565 pixel stream |

### East (right) — memory write bus + CH0 display (104 pins)

| signal | width | dir | notes |
|---|---|---|---|
| `mem_waddr` | 17 | out | broadcast write address |
| `mem_wdata` | 32 | out | broadcast write data |
| `mem_wbe_n` | 4 | out | byte enables (neg.) |
| `mem_we_n` | 1 | out | write enable (neg.) |
| `mem0_raddr` | 17 | out | CH0 read address |
| `mem0_rdata` | 32 | in | CH0 read data |
| `mem0_re_n` | 1 | out | CH0 read enable (neg.) |

### West (left) — clock/reset + CH1/CH2 (102 pins)

| signal | width | dir | notes |
|---|---|---|---|
| `clk` | 1 | in | system clock (50 MHz nominal) |
| `reset_n` | 1 | in | external reset, **xres4v2 pad** |
| `mem1_raddr` | 17 | out | CH1 read address |
| `mem1_rdata` | 32 | in | CH1 read data |
| `mem1_re_n` | 1 | out | CH1 read enable (neg.) |
| `mem2_raddr` | 17 | out | CH2 read address |
| `mem2_rdata` | 32 | in | CH2 read data |
| `mem2_re_n` | 1 | out | CH2 read enable (neg.) |

## Power plan

Power/ground pads (generated by `make_pad_ring.py`, physically distributed
along each edge by the chip-assembly flow):

| rail | supply | pad cell |
|---|---|---|
| VDDIO | 3.3 V I/O | `sky130_fd_io__top_power_hvc_wpad` |
| VSSIO | 3.3 V I/O ground | `sky130_fd_io__top_ground_hvc_wpad` |
| VCCD | 1.8 V core | `sky130_fd_io__top_power_lvc_wpad` |
| VSSD | 1.8 V core ground | `sky130_fd_io__top_ground_lvc_wpad` |
| VDDA / VSSA | analog taps | tied to VDDIO / VSSIO (no analog function) |

53 power/ground pads ≈ 1 per 7 signal pads; 24 of them balance the north row
to the die width. The four corners use `sky130_fd_io__top_corner_bus_overlay`
cells to close the ring bus.

## Chip-level verification (through the pads)

[`test/tb_chip.py`](../test/tb_chip.py) + [`test/chip_tb.sv`](../test/chip_tb.sv)
power the whole chip up on a simulated board — pad ring + die + EMC + three
board-mounted SRAMs — and drive it **only through the physical chip pins**
(the debug sidecar is not bonded out, so all readback uses the host AXI pads,
like real software):

| test | what it proves |
|---|---|
| `test_chip_reset_and_id` | reset through the xres pad; CP identity through host pads |
| `test_chip_vram_roundtrip` | VRAM R/W through pads + external SRAMs; byte strobes |
| `test_chip_core_kernel` | matadd via CP DMA + core kick while display free-runs: CH0 scanout + CH1 core stores + CH2 fetch/host hit the memory pins concurrently |
| `test_chip_video_pads` | DMA an FB pattern, capture `vid_de`/`vid_pixel` and verify the 2x2 double-scan mapping on the video pads |

Run: `cd test && make -f Makefile.chip` (with `run_cocotb.sh`'s env).

## Chip GDS (pad ring real cells)

[`scripts/gds/make_pad_ring_gds.py`](../scripts/gds/make_pad_ring_gds.py)
composes the pad-ring GDS from the real `sky130_fd_io` cells at every
`pad_ring_placement.csv` spot:

* `build/gds/chip/pad_ring.gds` — top `ember_pad_ring`, **430 instances**
  (373 signal + 53 power/ground + 4 `sky130_fd_io__corner_bus_overlay`),
  verified bbox (0,0;8280,9455) with all 426 pad centers checked against the
  placement plan.
* `--die build/gds/die/die.gds` additionally merges the hardened die macro
  at the ring center and writes `chip.gds` (top `ember_chip`); verified with
  a die fixture: 431 instances, die centered at (1140, 1227.5).
* `--memif build/gds/memif/memif.gds` merges `ember_memif` beside the die
  (die left, memif right, 40 um channel, both vertically centered — the
  `ember_chip.sv` topology). Verified with the **real** `memif.gds` + die
  fixture: 432 instances, die at (980.25, 1227.5), memif at
  (7020.25, 4587.75), both >= 40 um clear of the pad band.

Final chip composition (once every block GDS + the die are hardened and
`verify_block.py` passes for all of them):

```
$HOME/.local/emberbin/python3 scripts/gds/make_pad_ring_gds.py \
    --die build/gds/die/die.gds --memif build/gds/memif/memif.gds \
    --out build/gds/chip/chip.gds --top ember_chip
```

The composer self-verifies after writing: instance count, chip bbox
(0,0;8280,9455) um, all 426 pad centers, macro positions and macro-to-pad-
band clearance.

Note: the PDK ships one pad cell under two names — LEF
`sky130_fd_io__top_power_hvc_wpad` = GDS
`sky130_fd_io__top_power_hvc_wpadv2` (mapped via `GDS_ALIAS` in
[`make_pad_ring.py`](../scripts/gds/make_pad_ring.py)); the corner cell is
`sky130_fd_io__corner_bus_overlay` (no `top_` prefix).

`ember_memif` is hardened as a normal hard macro through the block flow
(`harden_block.sh memif ember_memif build/gds/memif.v`), the same
synthesis -> OpenROAD -> Magic -> KLayout path as the die blocks.

## Chip assembly (die macro + pad ring)

[`scripts/gds/chip_assemble.py`](../scripts/gds/chip_assemble.py) joins the
pad-ring flow with the die-macro flow once the die hardening finishes
(`build/gds/die/die_plan.json`): it verifies the hardened die fits inside the
ring interior (7880 x 9055 um) with >= 40 um clearance, centers it, and emits
`build/gds/chip/chip_assembly.json` + `chip_assembly.tcl` (OpenROAD
floorplan: die macro FIRM at center, all 430 pads FIRM at their
`pad_ring_placement.csv` spots).

## Notes / future work

* The host interface is bonded as a full parallel AXI4-Lite (146 pins). A
  production part would serialize this (SPI/UART host), which alone would
  shrink the die from pad-limited to core-limited (~4x). Kept parallel here
  because it matches the hardened die's port exactly.
* Side slack in the ring (sub-µm per pad) is absorbed as extra inter-pad
  pitch; exact abutment and per-edge power-pad distribution are a
  chip-assembly refinement in the physical flow.
* Verification: `test/tb_memif.py` (6/6 passing) covers broadcast writes,
  same-cycle 3-channel reads, read-old-data collision semantics, engine-write
  priority over AXI, AXI stalling behind `ixa`, and byte enables;
  `test/tb_chip.py` (4/4 passing) covers the full chip through the pads.
  `make_pad_ring.py --check` cross-checks pinout vs RTL.
  Runs: `cd test && make -f Makefile.memif` / `make -f Makefile.chip`
  (with `run_cocotb.sh`'s env).
