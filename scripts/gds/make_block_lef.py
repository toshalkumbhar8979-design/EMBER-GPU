#!/usr/bin/env python3
"""Generate a hard-macro LEF abstract for a hardened block from its final.def.

Run INSIDE the container:  openroad -python -no_init -exit make_block_lef.py <name>

Proven odb recipe (this build):
  * odb.dbLib.create(db, name, tech); odb.dbMaster.create(lib, name)
  * master.setType("BLOCK"), setWidth/setHeight (DBU)
  * odb.dbMTerm.create(master, pin, "INPUT", "SIGNAL")  -- strings work
  * odb.dbMPin.create(mterm); odb.dbBox.create(mpin, layer, x1,y1,x2,y2)
  * master-level dbBox  -> OBS section
  * odb.write_macro_lef(lib, out) -> macro LEF

Power: block DEFs carry no VPWR/VGND PINS -- power lives in SPECIALNETS and
stops at the core boundary (10 um floorplan margin). We expose 2 um pin stubs
at the core boundary where rails/straps reach it; the top-level PDN straps
reach them through the empty floorplan margin ring (pdngen ignores signal
OBS). Stub layers: met1 rails (left/right), met4 straps (top/bottom),
met5 stripes (left/right). Signal OBS covers li1..met5 minus pin shapes.
"""
import sys
from pathlib import Path

import odb

NAME = sys.argv[1]
OUT = f"/work/build/gds/{NAME}/{NAME}.lef"
PDK = str(Path.home()) + "/.volare/volare/sky130/versions/fa87f8f4bbcc7255b6f0c0fb506960f531ae2392/sky130A"
STUB = 1000   # 1 um pin stub in DBU
BAND = 2000   # 2 um pin band along the core boundary
EDGE = 11000  # core boundary: shapes reaching within 11 um of the die edge

db = odb.dbDatabase.create()
odb.read_lef(db, PDK + "/libs.ref/sky130_fd_sc_hd/techlef/sky130_fd_sc_hd__nom.tlef")
odb.read_lef(db, PDK + "/libs.ref/sky130_fd_sc_hd/lef/sky130_fd_sc_hd.lef")
# Hierarchical rasterizer DEF references child macros as well as std cells.
if NAME == 'rtr_top':
    for child in ('rtr_setup', 'rtr_scan'):
        child_lef = Path(f'/work/build/gds/{child}/{child}.lef')
        if not child_lef.is_file():
            raise SystemExit(f'Missing child macro abstract: {child_lef}')
        odb.read_lef(db, str(child_lef))
odb.read_def(db.getTech(), f"/work/build/gds/{NAME}/final.def")
block = db.getChip().getBlock()
tech = db.getTech()
dbu = tech.getDbUnitsPerMicron()

bb = block.getBBox()
dx1, dy1, dx2, dy2 = bb.xMin(), bb.yMin(), bb.xMax(), bb.yMax()
W, H = dx2 - dx1, dy2 - dy1
print(f"{NAME}: die {W/dbu} x {H/dbu} um")

ROUTING_LAYERS = ["li1", "met1", "met2", "met3", "met4", "met5"]

# ---- signal pins (from DEF PINS) -------------------------------------------
pin_boxes = {}  # layer -> [(x1,y1,x2,y2), ...] (block-local DBU)
npins = 0


def add_pin_box(layer_name, rect):
    x1, y1, x2, y2 = rect
    x1, y1 = max(x1, 0), max(y1, 0)
    x2, y2 = min(x2, W), min(y2, H)
    if x2 > x1 and y2 > y1:
        pin_boxes.setdefault(layer_name, []).append((x1, y1, x2, y2))


for bt in block.getBTerms():
    npins += 1
    for bp in bt.getBPins():
        for box in bp.getBoxes():
            ly = box.getTechLayer().getName()
            if ly in ROUTING_LAYERS:
                add_pin_box(ly, (box.xMin() - dx1, box.yMin() - dy1,
                                 box.xMax() - dx1, box.yMax() - dy1))
print(f"signal pins: {npins}", flush=True)

# ---- power pins (boundary stubs from special nets) -------------------------
power_pins = []  # (net, layer, io, sig, rect)
nsp = 0
for net in block.getNets():
    sig = net.getSigType()
    if sig not in ("POWER", "GROUND"):
        continue
    for swire in net.getSWires():
        for sbox in swire.getWires():
            tly = sbox.getTechLayer()
            if tly is None:  # via shape -- interior only, skip for boundary stubs
                continue
            ly = tly.getName()
            if ly not in ROUTING_LAYERS:
                continue
            nsp += 1
            x1, y1 = sbox.xMin() - dx1, sbox.yMin() - dy1
            x2, y2 = sbox.xMax() - dx1, sbox.yMax() - dy1
            stubs = []
            if x1 <= EDGE:      # reaches left core boundary  -> met1 rails, met5 stripes
                stubs.append((x1, y1, min(x1 + BAND, x2), y2))
            if x2 >= W - EDGE:  # reaches right core boundary
                stubs.append((max(x2 - BAND, x1), y1, x2, y2))
            if y1 <= EDGE:      # reaches bottom core boundary -> met4 straps
                stubs.append((x1, y1, x2, min(y1 + BAND, y2)))
            if y2 >= H - EDGE:  # reaches top core boundary
                stubs.append((x1, max(y2 - BAND, y1), x2, y2))
            for r in stubs:
                power_pins.append((net.getName(), ly, sig, r))
print(f"special-net shapes: {nsp}, boundary power stubs: {len(power_pins)}")

lib = odb.dbLib.create(db, "ember_macros", tech)
master = odb.dbMaster.create(lib, f"ember_{NAME}")
master.setType("BLOCK")
master.setWidth(W)
master.setHeight(H)
master.setSymmetryY()

# signal MTerms
for bt in block.getBTerms():
    pname = bt.getName().replace("\\", "")
    try:
        mt = odb.dbMTerm.create(master, pname, bt.getIoType(), bt.getSigType())
    except Exception as e:
        print(f"  pin {pname}: {e}")
        continue
    for bp in bt.getBPins():
        for box in bp.getBoxes():
            ly = box.getTechLayer()
            if ly is None or ly.getName() not in ROUTING_LAYERS:
                continue
            mp = odb.dbMPin.create(mt)
            odb.dbBox.create(mp, ly,
                             box.xMin() - dx1, box.yMin() - dy1,
                             box.xMax() - dx1, box.yMax() - dy1)

# power MTerms: ONE MTerm per net, boxes across all stub layers
by_net = {}
for (net, ly, sig, r) in power_pins:
    by_net.setdefault(net, (sig, {}))[1].setdefault(ly, []).append(r)
def sanitize(r):
    x1, y1, x2, y2 = r
    x1, y1 = max(x1, 0), max(y1, 0)
    x2, y2 = min(x2, W), min(y2, H)
    return (x1, y1, x2, y2) if (x2 - x1 >= 10 and y2 - y1 >= 10) else None


for net, (sig, per_layer) in by_net.items():
    print(f'power mterm {net} {sig} layers={sorted(per_layer)}', flush=True)
    try:
        mt = odb.dbMTerm.create(master, net, "INOUT", sig)
    except Exception as e:
        print(f"  power pin {net}: {e}")
        continue
    for lname, rects in per_layer.items():
        ly = tech.findLayer(lname)
        n = 0
        for r in rects:
            r = sanitize(r)
            if r is None:
                continue
            mp = odb.dbMPin.create(mt)
            odb.dbBox.create(mp, ly, *r)
            add_pin_box(lname, r)
            n += 1
        print(f'  {net}/{lname}: {n} boxes', flush=True)
print('power mterms done', flush=True)

# ---- OBS: full die per routing layer minus pin boxes ------------------------
def subtract_rects(die, holes):
    events = sorted({h[1] for h in holes} | {h[3] for h in holes})
    y_bounds = [die[1]] + [y for y in events if die[1] < y < die[3]] + [die[3]]
    out = []
    for y1, y2 in zip(y_bounds, y_bounds[1:]):
        if y2 <= y1:
            continue
        xs = [(die[0], die[2])]
        for hx1, hy1, hx2, hy2 in holes:
            if hy1 <= y1 and hy2 >= y2:
                nxt = []
                for a, b in xs:
                    if hx2 <= a or hx1 >= b:
                        nxt.append((a, b))
                        continue
                    if hx1 > a:
                        nxt.append((a, hx1))
                    if hx2 < b:
                        nxt.append((hx2, b))
                xs = nxt
        for a, b in xs:
            out.append((a, y1, b, y2))
    return out


die = (0, 0, W, H)
for lname in ROUTING_LAYERS:
    ly = tech.findLayer(lname)
    if ly is None:
        continue
    for (x1, y1, x2, y2) in subtract_rects(die, pin_boxes.get(lname, [])):
        odb.dbBox.create(master, ly, x1, y1, x2, y2)

rc = odb.write_macro_lef(lib, OUT)
print('write_macro_lef rc:', rc, flush=True)
if rc != 1:
    print(f"write_macro_lef rc={rc}")
    sys.exit(1)
print(f"LEF written: {OUT}")
