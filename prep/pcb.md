# Ember GPU — carrier PCB build guide

How to build the board that hosts the Ember sky130 chip and turns it into a
working GPU: power, external SRAMs, host interface, video out, clock/reset,
and a bring-up plan. All chip-side facts come from
[`docs/chip_pinout.md`](../docs/chip_pinout.md) and
[`scripts/gds/pinout.csv`](../scripts/gds/pinout.csv) (single source of
truth — regenerate any table here from that CSV before layout).

**Chip at a glance**

| property | value |
|---|---|
| Process | SkyWater sky130 (130 nm) |
| Die size | 8280 x 9455 µm (8.3 x 9.5 mm, 78.3 mm²), pad-limited |
| Pads | 430 total: 373 signal + 53 power/ground + 4 corner cells |
| Pad pitch | 80 µm (`sky130_fd_io__top_gpiov2`), reset on `__top_xres4v2` |
| Clock | single `clk`, 50 MHz nominal (20 ns cycle) |
| I/O voltage | 3.3 V (all signal pads are VDDIO-domain LVCMOS) |
| Core voltage | 1.8 V |
| Host port | full parallel AXI4-Lite, 146 pins (no serial debug port bonded out) |
| Video | RGB565 + HSYNC/VSYNC/DE, 20 pads |
| External memory | 3x 128K x 32 simple-dual-port async SRAM (10–15 ns) |

---

## 1. System block diagram

```
                 +---------------------------+
   5V/12V in --> | power tree: 3.3V + 1.8V   |
                 +------------+--------------+
                              |
   +-----------+   clk 50MHz |   +---------------------------+
   | oscillator|--------------+-->|                           |
   +-----------+              |   |      EMBER CHIP          |
   +-----------+   reset_n    |   |   (wirebonded die,       |
   | supervisor|-------------->   |    8.3 x 9.5 mm)         |
   | + button  |              |   |                           |
   +-----------+              |   |  N: host AXI4-Lite wr    |
                              |   |  S: host AXI4-Lite rd    |
   +-----------+  146-sig bus |   |      + video + straps    |
   |  HOST FPGA|<============>+   |  E: mem write bus + CH0  |
   | (AXI-Lite)|              |   |  W: clk/reset + CH1/CH2  |
   +-----------+              |   +--+-----+-----+----------+
        ^                     |      |     |     |
        | USB/UART/ETH        |   CH0|  CH1|  CH2|  mem write bus
        v                     |      v     v     v  (broadcast)
   +-----------+           +--+---------------------------+
   |  PC host  |           |  3x 128Kx32 SDP SRAM          |
   +-----------+           |  (each = 2x 128Kx16 in        |
                           |   parallel, 10 ns class)      |
                           +-----------------------------+
   +-----------+
   | VGA DAC   |<-- RGB565 + HS/VS/DE (from S edge)
   +-----------+
```

Three board partitions follow the pad ring edges — **floorplan the board like
the die**:

| board region | chip edge | contents |
|---|---|---|
| north side of package | N (76 pads) | host AXI write channel routing to FPGA |
| south side | S (91 pads) | host read channel + `fb_select` straps + VGA connector |
| east side | E (104 pads) | broadcast write bus + CH0 SRAM |
| west side | W (102 pads) | clock/reset + CH1/CH2 SRAMs |

---

## 2. The die-to-board problem (read this first)

The die has **430 wires at 80 µm pitch**. This is not solderable — it needs
gold wirebonding:

* **Recommended: chip-on-board (COB), thermosonic gold wedge, 25 µm Au wire,
  direct bond to PCB.** PCB bond pads: ENIG (or ENEPIG) gold, 100 x 150 µm
  pads on ~120–150 µm pitch fanning out from the die pad frame. Pick a PCB
  house + assembly house that quote "fine-pitch COB / gold wirebond on FR4";
  80 µm die pitch expanded to ~130 µm board pitch is standard capability.
  Cover the die + wires with a glob-top or dam-and-fill encapsulant.
* **Alternative: laminate BGA substrate** (HDI, 2+2+2 or better) wirebonded
  at an OSAT, then the board solders a 430-ball BGA. Better for repeat
  builds, ~10x the NRE.
* Do **not** attempt a socket or bare-die clamp for this pad count.

PCB consequences: keep-out under and around the die (no top-side traces or
vias in the bond area), die attach pad (grounded copper pour with an
adhesive pocket), and the bond fanout lives on the top layer immediately
around the die. Plan ~15 mm x 17 mm minimum for the die + fanout field.

**Also required for fabrication:** the chip itself must be taped out first
(sky130 shuttle / chipIgnite-class run) and the die sawn and delivered. The
PCB can be designed and ordered in parallel — just don't release assembly
until known-good die exist (or accept the risk on a multi-die order).

---

## 3. Power tree

| rail | voltage | source | budget (est.) | notes |
|---|---|---|---|---|
| VDDIO / VDDA | 3.3 V | LDO or buck+LDO post-reg | ~800 mA peak | all 373 signal pads + 3 SRAMs + FPGA I/O banks on this rail |
| VSSIO / VSSA | 0 V | plane | — | VDDA/VSSA taps are tied to VDDIO/VSSIO on the die (no analog function) |
| VCCD | 1.8 V | dedicated LDO, low noise | ~1.5 A peak | core rail (~2.27M cells at 50 MHz — size for headroom, measure later) |
| VSSD | 0 V | plane | — | |

* **Decoupling:** the die has 53 power/ground pads distributed around the
  ring. From the top side you cannot reach all of them individually — the
  answer is planes: 4-layer minimum (**sig / GND / 3.3V / sig**), 6-layer
  better (**sig / GND / 3.3V / 1.8V / GND / sig**). Place 100 nF X7R within
  3 mm of every accessible power bond pad group (budget 40–60 caps), 1 µF
  every ~20 mm around the ring, 47 µF bulk per rail at the entry point.
* **Sequencing:** both rails must be monotonic; no strict order between
  VCCD and VDDIO is required by the I/O cells, but hold `reset_n` low until
  both rails are within ±5% and the clock has been stable for ≥ 1 ms. A
  3.3 V supervisor (TPS3809-class or similar) on `reset_n` + a manual
  push-button is the whole reset story.
* **SRAMs and the FPGA I/O banks run from 3.3 V** — the memory pads are
  VDDIO-domain; 3.3 V async SRAMs match natively.

---

## 4. External memory (the must-get-right interface)

3 read channels + 1 broadcast write bus; **each channel is the read port of
one 128K x 32 simple-dual-port SRAM, the write bus drives all three SRAMs'
write ports simultaneously** (replicated memory: all three hold the same
512 KiB VRAM image).

Practical part construction: **2x ISSI IS61WV12816 (128K x 16, 10 ns,
3.3 V, 44/48-TSOP) in parallel per channel = 128K x 32 → 6 SRAM chips
total.** Any 10–15 ns 3.3 V async SRAM of that geometry works; the two
device requirement per channel is just because native x32 async parts are
rare.

| bus | pads | width | direction | drive |
|---|---|---|---|---|
| `mem_waddr` / `mem_wdata` / `mem_wbe_n` / `mem_we_n` | E | 17 / 32 / 4 / 1 | chip → SRAMs | to **all 3** SRAMs' write side |
| `memN_raddr` / `memN_re_n` | CH0: E, CH1/2: W | 17 / 1 each | chip → SRAM N | to one SRAM pair |
| `memN_rdata` | CH0: E, CH1/2: W | 32 each | SRAM N → chip | from one SRAM pair |

Timing contract (matches the on-die SRAM the EMC replaces):

* read: address + `re_n` in cycle N → data valid in N+1 (SRAM access
  10–15 ns fits the 20 ns cycle with board delay ~1–2 ns to spare)
* write: commits at the edge ending the request cycle, `we_n` active low
* read-during-write same address returns OLD data — the SRAM must be a
  true SDP part (separate read/write ports), not a shared-bus TSOP
  configured as "read-old"

Layout rules for this bus (it is the largest and fastest on the board):

* keep each SRAM pair within ~50 mm of its chip edge (CH0 east, CH1/2 west)
* length-match within each channel group loosely (≤ 10 mm skew — 50 MHz is
  forgiving); series 22 Ω damping resistors at the chip end of every
  address/data line
* the broadcast write bus fans out to 3 loads: daisy-chain it E→W with
  stubs < 15 mm, or star it from the package with 33 Ω series at the source

---

## 5. Host interface (146 pins, parallel AXI4-Lite)

N edge = write channels (`h_aw*`, `h_w*`, `h_b*`), S edge = read channels
(`h_ar*`, `h_r*`). 32-bit address/data, 50 MHz — this is a large, slow,
easy bus. The chip has **no serial host port and no JTAG**: this bus is the
only way in, so the host must be real silicon (FPGA) or a very wide GPIO
machine.

Options, in order of sanity:

1. **On-board FPGA** (recommended): Artix-7 XC7A35T/100T-FGG484 (0.8 mm
   BGA, hand-reflow-able with a hot plate + stencil) or Lattice
   ECP5-45F-BG381. The FPGA implements an AXI4-Lite master + a USB/UART or
   Ethernet bridge to the PC. Needs ~150 user I/O — both candidates qualify.
2. **Mezzanine headers to an existing FPGA dev board**: two DIN 41612 or
   four 2x40 2.54 mm headers carrying the full bus. Cheap, debuggable,
   ugly; fine for rev 1.
3. Not possible: Raspberry Pi / MCU GPIO (not enough pins), USB bridge
   chips (the protocol is parallel AXI, not serial).

`fb_select[1:0]` (S edge) is a boot strap: 2x pull-up/pull-down resistors
selecting the active framebuffer. Pull both low for default, route them to
a DIP switch for convenience.

---

## 6. Clock, reset, video

* **Clock:** one 50 MHz LVCMOS oscillator (3.3 V — it feeds a VDDIO pad) on
  the west side, trace < 20 mm, 33 Ω series at the oscillator end, ground
  guard. No PLL on board; the chip is single-clock.
* **Reset:** `reset_n` goes through the dedicated `sky130_fd_io__top_xres4v2`
  pad. Supervisor + button + 100 nF to ground. Never leave it floating.
* **Video:** `vid_pixel[15:0]` RGB565 + `vid_hs` / `vid_vs` / `vid_de` from
  the south edge. Cheapest real output: **passive resistor-ladder DAC** —
  R-2R style, 5 bits/49.9 Ω for red & blue, 6 bits/49.9 Ω for green →
  75 Ω VGA into a DE-15 connector, syncs direct (3.3 V LVCMOS is fine for
  VGA TTL sync inputs). Alternative: TFP410-class DVI transmitter fed by
  RGB565 (it accepts 565 with tied LSBs) if you want digital out.
* RGB565 at 50 MHz pixel clock class → VGA 640x480-class modes are the
  realistic target for rev 1.

---

## 7. Suggested BOM (core items)

| qty | item | notes |
|---|---|---|
| 1 | Ember die (wirebonded) | COB on board, glob-top |
| 6 | IS61WV12816BLL-10 (128Kx16, 10 ns, 3.3 V) | 2 per channel in parallel |
| 1 | 50 MHz LVCMOS oscillator, 3.3 V | west side |
| 1 | 3.3 V supervisor + reset button | `reset_n` |
| 1 | FPGA (XC7A35T-FGG484 or LFE5U-45F-BG381) + config flash | host bridge |
| 2 | 1.8 V LDO ≥ 2 A (core) + 3.3 V ≥ 1 A (I/O) | with LC filters |
| 1 | VGA DE-15 + 3x 5-bit/6-bit resistor ladders | video out |
| ~60 | 100 nF X7R 0402 + 10x 1 µF + 4x 47 µF | decoupling |
| 1 | USB/UART bridge (FTDI-class) | FPGA config + console |

Board size: ~120 x 100 mm, 4-layer (6 preferred), ENIG finish (required for
bond pads), 1 oz outer copper.

---

## 8. Bring-up plan (in order)

1. **Power only, no die current check** — if die is already bonded: verify
   3.3 V and 1.8 V at the bond pads, expect tens of mA idle core current.
2. **Clock + reset** — probe `clk` at the pad (ring oscillator-free, so a
   dead clock = dead chip), release `reset_n`, hold low ≥ 1 ms after rails.
3. **Host identity read** — the CP answers an identity read over AXI (see
   `test_chip_reset_and_id` in [`test/tb_chip.py`](../test/tb_chip.py));
   this one transaction proves power + clock + reset + all four host
   channels + the FPGA bridge in a single step.
4. **VRAM roundtrip** — read/write pattern through host pads into the 3
   SRAMs (`test_chip_vram_roundtrip`). If this fails per-channel, suspect
   that channel's SRAM pair or its bus.
5. **Kernel smoke test** — CP DMA + core kick of the matadd kernel
   (`test_chip_core_kernel`), display free-running.
6. **Video** — DMA a framebuffer pattern, capture `vid_de`/`vid_pixel`
   on a logic analyzer or scope, then connect VGA
   (`test_chip_video_pads` checks the 2x2 double-scan mapping).

The simulation tests in [`test/tb_chip.py`](../test/tb_chip.py) drive the
chip **only through its physical pins**, so every bring-up step has a
software twin — write the FPGA bridge firmware to run those same
transactions.

---

## 9. Pitfalls checklist

* [ ] Bond pads ENIG gold; HASL is not bondable
* [ ] No top-side copper in the die keep-out; grounded die-attach paddle
* [ ] Reset never floating; supervisor threshold ≤ 3.0 V
* [ ] SRAMs are **SDP** (separate read + write ports) and **async 10–15 ns**
* [ ] Write bus goes to all three SRAM pairs; read buses are 1:1 per channel
* [ ] Read-during-write returns old data (true SDP does this naturally)
* [ ] Both rails monotonic, 1.8 V LDO sized ≥ 2 A, local bulk at the die
* [ ] `fb_select` strapped (2 resistors), not floating
* [ ] ESD/TVS on VGA, USB, and any external header; series 22–33 Ω on all
      chip-bound buses
* [ ] Length: clock < 20 mm; memory channels matched ≤ 10 mm; host bus is
      slow — treat as lumped
* [ ] No JTAG: test points on `clk`, `reset_n`, `mem_we_n`, `vid_de` and
      one spare per bus for scope debugging

---

## 10. Rev-2 thoughts (not for rev 1)

* Serialize the host (SPI/UART bridge FPGA role moved on-chip) — would
  shrink the die from pad-limited to core-limited (~4x smaller) and cut the
  package from 430 to < 100 balls
* On-board HDMI encoder instead of VGA ladders
* Drop from 6 SRAMs to 3 by sourcing a native 128Kx32 SDP part
* Power telemetry (INA219-class shunt monitors per rail) — worth adding on
  rev 1 actually, it's 2 resistors and a bus
