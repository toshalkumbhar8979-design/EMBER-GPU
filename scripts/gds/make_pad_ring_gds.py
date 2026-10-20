#!/usr/bin/env python3
"""make_pad_ring_gds.py -- compose the chip pad-ring GDS.

Reads build/gds/chip/pad_ring_placement.csv (from make_pad_ring.py) and the
real sky130_fd_io pad-cell GDS from the PDK, places every pad/corner cell at
its planned spot, and writes build/gds/chip/pad_ring.gds.

Optionally merges hardened macros inside the ring and writes
build/gds/chip/chip.gds with top ember_chip:
  --die   build/gds/die/die.gds     (ember_die, the 8-block GPU die)
  --memif build/gds/memif/memif.gds (ember_memif, external-memory controller)
Macros are laid out left-to-right (die, memif) as a centered group with a
--chan um channel between them, each vertically centered -- the ember_chip.sv
topology (die left, memory controller right, pad ring around both).

Placement convention: rows carry the pad FOOTPRINT CENTER and an orientation
(R0/R90/R180/R270). Pads are placed so their nominal LEF-size box (the
PAD_W width x 200 um pitch box used by the ring planner) maps onto the
planned slot; the sky130 cells' tiny drawn overhang (~0.7 um abutment
artifact) is ignored, exactly as LEF abutment does. Corner cells are placed
by origin at the four die corners.

Run (emberbin python3 has the pya module):
  $HOME/.local/emberbin/python3 scripts/gds/make_pad_ring_gds.py
  $HOME/.local/emberbin/python3 scripts/gds/make_pad_ring_gds.py \\
      --die build/gds/die/die.gds
  $HOME/.local/emberbin/python3 scripts/gds/make_pad_ring_gds.py \\
      --die build/gds/die/die.gds --memif build/gds/memif/memif.gds \\
      --out build/gds/chip/chip.gds --top ember_chip
"""

import argparse
import csv
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import make_pad_ring as mpr  # noqa: E402  (PAD_W + GDS_ALIAS single source)

import pya  # KLayout module (emberbin python3)

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
PDK = os.environ.get("PDK") or (
    os.path.expanduser("~/.volare/volare/sky130/versions")
)
if not os.environ.get("PDK"):
    cands = sorted(os.listdir(PDK)) if os.path.isdir(PDK) else []
    PDK = os.path.join(PDK, cands[0], "sky130A") if cands else ""
IO_GDS = os.path.join(PDK, "libs.ref", "sky130_fd_io", "gds",
                      "sky130_fd_io.gds")

ROT = {"R0": 0, "R90": 1, "R180": 2, "R270": 3}
BBOX_TOL_UM = 5.0        # drawn overhang of abutting pads


def load_rows(path):
    with open(path, newline="") as f:
        return list(csv.DictReader(f))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--placement",
                    default=os.path.join(ROOT, "build", "gds", "chip",
                                         "pad_ring_placement.csv"))
    ap.add_argument("--out",
                    default=os.path.join(ROOT, "build", "gds", "chip",
                                         "pad_ring.gds"))
    ap.add_argument("--top", default="ember_pad_ring")
    ap.add_argument("--die", default=None,
                    help="hardened die GDS to merge at the ring center")
    ap.add_argument("--die-top", default="ember_die")
    ap.add_argument("--memif", default=None,
                    help="hardened ember_memif GDS to merge beside the die")
    ap.add_argument("--memif-top", default="ember_memif")
    ap.add_argument("--chan", type=float, default=40.0,
                    help="die<->memif channel width (um)")
    ap.add_argument("--clearance", type=float, default=40.0,
                    help="min macro-to-pad-band clearance (um)")
    args = ap.parse_args()

    if not os.path.exists(IO_GDS):
        raise SystemExit("pad-cell GDS not found: %s" % IO_GDS)

    rows = load_rows(args.placement)
    if not rows:
        raise SystemExit("empty placement: %s" % args.placement)

    # die outline from the ring planner (same source as the CSV)
    pads = mpr.read_pinout()
    _, corners, chip_w, chip_h, _, _ = mpr.build_ring(pads)

    ly = pya.Layout()
    ly.read(IO_GDS)
    dbu = ly.dbu
    top = ly.create_cell(args.top)

    def um(v):
        return int(round(float(v) / dbu))

    n_placed = 0
    for r in rows:
        cell_name = r["cell"]
        gds_name = mpr.GDS_ALIAS.get(cell_name, cell_name)
        master = ly.cell(gds_name)
        if master is None:
            raise SystemExit("cell %s (GDS %s) missing from %s"
                             % (cell_name, gds_name, IO_GDS))
        rot = ROT[r["orient"]]
        x, y = float(r["x_um"]), float(r["y_um"])

        if cell_name == "sky130_fd_io__corner_bus_overlay":
            # corners close the ring at the die corners, placed by origin
            ox, oy = {
                "u_corner_sw": (0.0, 0.0),
                "u_corner_se": (chip_w, 0.0),
                "u_corner_ne": (chip_w, chip_h),
                "u_corner_nw": (0.0, chip_h),
            }[r["instance"]]
        else:
            # nominal pitch box (PAD_W x 200) center -> placement origin
            w = float(mpr.PAD_W[cell_name])
            h = float(mpr.PAD_H)
            c = pya.Trans(rot, False, 0, 0).trans(pya.Point(um(w / 2),
                                                            um(h / 2)))
            ox, oy = x - c.x * dbu, y - c.y * dbu

        t = pya.Trans(rot, False, um(ox), um(oy))
        top.insert(pya.CellInstArray(master.cell_index(), t))
        n_placed += 1

    # ---- interior macros: die (left) + memif (right), centered as a group
    macros = []      # (top_name, master_cell, master_bbox)
    for path, name in ((args.die, args.die_top), (args.memif, args.memif_top)):
        if not path:
            continue
        ly.read(path)
        master = ly.cell(name)
        if master is None:
            raise SystemExit("macro top %s missing from %s" % (name, path))
        macros.append((name, master, master.dbbox()))

    total_w = (sum(mbb.width() for _, _, mbb in macros)
               + args.chan * max(0, len(macros) - 1))
    if total_w > 0 and (total_w > chip_w - 2 * (mpr.PAD_H + args.clearance)
                        or max(mbb.height() for _, _, mbb in macros)
                        > chip_h - 2 * (mpr.PAD_H + args.clearance)):
        raise SystemExit("macros %.1f x %.1f um do not fit inside the pad "
                         "band with %.1f um clearance"
                         % (total_w,
                            max(mbb.height() for _, _, mbb in macros),
                            args.clearance))

    macro_pos = {}   # name -> expected placed dbbox lower-left (x, y)
    x0 = (chip_w - total_w) / 2.0
    for name, master, mbb in macros:
        mx, my = x0, (chip_h - mbb.height()) / 2.0
        top.insert(pya.CellInstArray(
            master.cell_index(),
            pya.Trans(ROT["R0"], False,
                      um(mx - mbb.left), um(my - mbb.bottom))))
        macro_pos[name] = (mx, my, mbb.width(), mbb.height())
        print("macro %s placed at (%.1f, %.1f) size %.1f x %.1f"
              % (name, mx, my, mbb.width(), mbb.height()))
        x0 += mbb.width() + args.chan

    opt = pya.SaveLayoutOptions()
    opt.set_format_from_filename(args.out)
    opt.select_all = False
    opt.add_cell(top.cell_index())
    ly.write(args.out, opt)

    # ---------------- verification (reopen the written GDS) ----------------
    vr = pya.Layout()
    vr.read(args.out)
    vt = vr.cell(args.top)
    errs = []
    insts = list(vt.each_inst())
    want = n_placed + len(macro_pos)
    if len(insts) != want:
        errs.append("instance count %d != %d" % (len(insts), want))
    bb = vt.dbbox()
    if (abs(bb.left) > BBOX_TOL_UM or abs(bb.bottom) > BBOX_TOL_UM
            or abs(bb.width() - chip_w) > BBOX_TOL_UM
            or abs(bb.height() - chip_h) > BBOX_TOL_UM):
        errs.append("bbox %s not within %.1f um of 0,0..%.0f,%.0f"
                    % (bb, BBOX_TOL_UM, chip_w, chip_h))

    # spot check: every placed instance's box center must land within
    # tolerance of a placement row of the same cell type
    # macro position + ring-band clearance checks
    for name, (ex, ey, ew, eh) in macro_pos.items():
        mi = [i for i in insts if vr.cell(i.cell_index).name == name]
        if len(mi) != 1:
            errs.append("macro %s: %d instances (want 1)" % (name, len(mi)))
            continue
        ib = mi[0].dbbox()
        if (abs(ib.left - ex) > 0.05 or abs(ib.bottom - ey) > 0.05
                or abs(ib.width() - ew) > 0.05
                or abs(ib.height() - eh) > 0.05):
            errs.append("macro %s bbox %s != expected (%.3f, %.3f) %.1f x %.1f"
                        % (name, ib, ex, ey, ew, eh))
        lo = mpr.PAD_H + args.clearance
        if (ib.left < lo or ib.bottom < lo
                or ib.right > chip_w - lo or ib.top > chip_h - lo):
            errs.append("macro %s bbox %s breaches pad band + %.1f um"
                        % (name, ib, args.clearance))

    checked = 0
    for inst in insts:
        mname = vr.cell(inst.cell_index).name
        if mname in (args.die_top, args.memif_top):
            continue
        if mname == "sky130_fd_io__corner_bus_overlay":
            continue    # corners placed by origin; ring closure is the bbox check
        ib = inst.dbbox()
        cx, cy = (ib.left + ib.right) / 2.0, (ib.bottom + ib.top) / 2.0
        best, bestd = None, 1e9
        for r in rows:
            gname = mpr.GDS_ALIAS.get(r["cell"], r["cell"])
            if gname != mname:
                continue
            d = (float(r["x_um"]) - cx) ** 2 + (float(r["y_um"]) - cy) ** 2
            if d < bestd:
                best, bestd = r, d
        if best is None or bestd > (BBOX_TOL_UM ** 2) * 2:
            errs.append("inst %s center (%.2f, %.2f) matches no placement row"
                        % (mname, cx, cy))
        checked += 1

    if errs:
        print("PAD RING GDS CHECK FAILED:")
        for e in errs[:12]:
            print("  " + e)
        raise SystemExit(1)
    print("PAD RING GDS OK: %d instances, bbox %s, %d centers verified"
          % (len(insts), bb, checked))
    print("wrote %s" % args.out)


if __name__ == "__main__":
    main()
