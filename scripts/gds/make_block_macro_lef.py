#!/usr/bin/env python3
"""Macro-LEF generator for hierarchical blocks (generalized make_block_lef).

Usage: openroad -python -no_init -exit make_block_macro_lef.py <def> <topname> <out.lef>
Generates a hard-macro LEF abstract from a routed DEF: signal pins from DEF
PINS, power stubs at the core boundary from SPECIALNETS, OBS = die minus pins.
"""
import sys

import odb

deff, topname, OUT = sys.argv[1], sys.argv[2], sys.argv[3]
PDK = str(Path.home()) + "/.volare/volare/sky130/versions/fa87f8f4bbcc7255b6f0c0fb506960f531ae2392/sky130A"
STUB = 1000
BAND = 2000
EDGE = 11000

db = odb.dbDatabase.create()
odb.read_lef(db, PDK + "/libs.ref/sky130_fd_sc_hd/techlef/sky130_fd_sc_hd__nom.tlef")
odb.read_lef(db, PDK + "/libs.ref/sky130_fd_sc_hd/lef/sky130_fd_sc_hd.lef")
odb.read_def(db.getTech(), deff)
block = db.getChip().getBlock()
tech = db.getTech()

bb = block.getBBox()
dx1, dy1, dx2, dy2 = bb.xMin(), bb.yMin(), bb.xMax(), bb.yMax()
W, H = dx2 - dx1, dy2 - dy1
print(f"{topname}: die {W/1000} x {H/1000} um", flush=True)

ROUTING_LAYERS = ["li1", "met1", "met2", "met3", "met4", "met5"]
pin_boxes = {}


def add_pin_box(layer_name, rect):
    x1, y1, x2, y2 = rect
    x1, y1 = max(x1, 0), max(y1, 0)
    x2, y2 = min(x2, W), min(y2, H)
    if x2 - x1 >= 10 and y2 - y1 >= 10:
        pin_boxes.setdefault(layer_name, []).append((x1, y1, x2, y2))


for bt in block.getBTerms():
    for bp in bt.getBPins():
        for box in bp.getBoxes():
            ly = box.getTechLayer().getName()
            if ly in ROUTING_LAYERS:
                add_pin_box(ly, (box.xMin() - dx1, box.yMin() - dy1,
                                 box.xMax() - dx1, box.yMax() - dy1))
print(f"signal pins: {len(block.getBTerms())}", flush=True)

power_pins = []
for net in block.getNets():
    sig = net.getSigType()
    if sig not in ("POWER", "GROUND"):
        continue
    for swire in net.getSWires():
        for sbox in swire.getWires():
            tly = sbox.getTechLayer()
            if tly is None:
                continue
            ly = tly.getName()
            if ly not in ROUTING_LAYERS:
                continue
            x1, y1 = sbox.xMin() - dx1, sbox.yMin() - dy1
            x2, y2 = sbox.xMax() - dx1, sbox.yMax() - dy1
            stubs = []
            if x1 <= EDGE:
                stubs.append((x1, y1, min(x1 + BAND, x2), y2))
            if x2 >= W - EDGE:
                stubs.append((max(x2 - BAND, x1), y1, x2, y2))
            if y1 <= EDGE:
                stubs.append((x1, y1, x2, min(y1 + BAND, y2)))
            if y2 >= H - EDGE:
                stubs.append((x1, max(y2 - BAND, y1), x2, y2))
            for r in stubs:
                power_pins.append((net.getName(), ly, sig, r))
print(f"boundary power stubs: {len(power_pins)}", flush=True)

lib = odb.dbLib.create(db, "ember_macros", tech)
master = odb.dbMaster.create(lib, topname)
master.setType("BLOCK")
master.setWidth(W)
master.setHeight(H)
master.setSymmetryY()

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

by_net = {}
for (net, ly, sig, r) in power_pins:
    by_net.setdefault(net, (sig, {}))[1].setdefault(ly, []).append(r)
for net, (sig, per_layer) in by_net.items():
    try:
        mt = odb.dbMTerm.create(master, net, "INOUT", sig)
    except Exception as e:
        print(f"  power pin {net}: {e}")
        continue
    for lname, rects in per_layer.items():
        ly = tech.findLayer(lname)
        for r in rects:
            x1, y1, x2, y2 = r
            r = (max(x1, 0), max(y1, 0), min(x2, W), min(y2, H))
            if r[2] - r[0] < 10 or r[3] - r[1] < 10:
                continue
            add_pin_box(lname, r)
            mp = odb.dbMPin.create(mt)
            odb.dbBox.create(mp, ly, *r)
print("power mterms done", flush=True)


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
if rc != 1:
    print(f"write_macro_lef rc={rc}")
    sys.exit(1)
print(f"LEF written: {OUT}", flush=True)
