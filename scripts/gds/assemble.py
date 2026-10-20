# assemble.py — chip-level assembly of the hardened Ember blocks into one die.
#
# Runs inside the container:
#   KLAYOUT_OUT=/work/paper/figures/ember_chip.gds \
#     klayout -b -r /work/scripts/gds/assemble.py
#
# Reads build/gds/<block>/<block>.gds for every block that exists and places
# them on a common die (shelf packing, largest first), preserving hierarchy:
# each block is instantiated as a cell, and the sky130 standard cells merge
# by name across blocks so the file stays small. A labelled region for the
# 512KB unified memory is added: the v1 VRAM is a behavioural array that
# cannot be standard-cell mapped, so on the assembled die it is drawn as a
# macro region (exactly how an SRAM macro would sit) — documented honestly in
# the paper rather than pretended away.
import os

import pya

OUT = os.environ.get("KLAYOUT_OUT", "/work/paper/figures/ember_chip.gds")
ROOT = os.environ.get("GDS_ROOT", "/work/build/gds")

BLOCKS = ["core", "tu", "gsx", "fpu4", "rtr_top", "rtr_scan", "rtr_setup",
          "blit", "cp", "xbar", "ram_slave", "display"]

layout = pya.Layout()
layout.dbu = 0.001

# ---- import every available block GDS; find each block's top cell ----
placed = []
for name in BLOCKS:
    path = os.path.join(ROOT, name, f"{name}.gds")
    if not os.path.exists(path):
        print("skip (no GDS yet):", name)
        continue
    layout.read(path)
    cell = layout.cell("ember_" + name)
    if cell is None:
        raise SystemExit("Missing intended top cell for " + name)
    b = cell.bbox()
    if b.width() == 0 or b.height() == 0:
        print("skip (empty):", name)
        continue
    placed.append((name, cell, b))
    print(f"imported {name:10s} top={cell.name:20s} "
          f"{b.width()/1000:7.1f} x {b.height()/1000:7.1f} um")

if not placed:
    raise SystemExit("no block GDS found under " + ROOT)

# largest blocks first so the shelf packing stays tight
placed.sort(key=lambda t: t[2].width() * t[2].height(), reverse=True)

GAP = 20_000      # 20 um between blocks
MARGIN = 40_000   # 40 um die margin

top = layout.create_cell("ember_die")

# ---- shelf packing ----
x, y, row_h, col = MARGIN, MARGIN, 0, 0
target_w = int(sum(t[2].width() * t[2].height() for t in placed) ** 0.5 * 1.6)
xs = {}
max_right = MARGIN
for name, cell, b in placed:
    w, h = b.width(), b.height()
    if x + w + MARGIN > max(target_w, MARGIN + w) and col > 0:
        x = MARGIN
        y += row_h + GAP
        row_h = 0
        col = 0
    xs[name] = (x, y, w, h, cell)
    top.insert(pya.CellInstArray(cell.cell_index(),
                                 pya.Trans(pya.Vector(x - b.left, y - b.bottom))))
    col += 1
    max_right = max(max_right, x + w)
    x += w + GAP
    row_h = max(row_h, h)

blocks_bottom = y + row_h

# ---- VRAM macro region: honest treatment of the 512KB array ----
# 512KB = 4.19Mbit; sky130 hd SRAM density ~ 0.35 um^2/bit would need ~1.5mm^2.
# Draw a dedicated macro strip under the standard-cell area at that scale.
vram_bits = 512 * 1024 * 8
# Illustrative reservation ONLY: no SRAM macro has been selected or built.
# Convert the assumed square-micrometre area to square DBU before packing.
vram_area = int(vram_bits * 0.35 / layout.dbu ** 2)
vram_w = max(600_000, int((vram_area / 0.45) ** 0.5))
vram_h = max(120_000, int(vram_area / vram_w))
vram_y = blocks_bottom + GAP
die_w = max(max_right + MARGIN, vram_w + 2 * MARGIN)
die_h = vram_y + vram_h + MARGIN

frame = layout.layer(200, 0)
label = layout.layer(201, 0)
mem = layout.layer(202, 0)

mx = (die_w - vram_w) // 2
top.shapes(mem).insert(pya.Box(mx, vram_y, mx + vram_w, vram_y + vram_h))
top.shapes(label).insert(pya.Text(
    "VRAM 512KB: illustrative reservation; no physical SRAM macro",
    pya.Trans(pya.Vector(mx + 4000, vram_y + vram_h // 2))))

# ---- die frame + block outlines + labels ----
top.shapes(frame).insert(pya.Box(0, 0, die_w, die_h))
for name, (px, py, w, h, _c) in xs.items():
    top.shapes(frame).insert(pya.Box(px, py, px + w, py + h))
    top.shapes(label).insert(pya.Text(name, pya.Trans(pya.Vector(px + 2000, py + h // 2))))

top.shapes(label).insert(pya.Text(
    "BLOCK GALLERY ONLY: no inter-block routing; not an integrated GPU layout",
    pya.Trans(pya.Vector(MARGIN, die_h - MARGIN // 2))))
options = pya.SaveLayoutOptions()
options.select_cell(top.cell_index())
layout.write(OUT, options)
print(f"assembled {len(xs)} blocks -> {OUT}")
print(f"die: {die_w/1000:.1f} x {die_h/1000:.1f} um "
      f"({die_w*die_h*layout.dbu**2/1e6:.2f} mm^2), VRAM region {vram_w/1000:.0f} x {vram_h/1000:.0f} um")
