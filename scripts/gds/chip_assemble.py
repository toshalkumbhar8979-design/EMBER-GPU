#!/usr/bin/env python3
"""chip_assemble.py -- chip-level floorplan: pad ring around the hardened die.

Links the two flows:
  * pad ring  : scripts/gds/pinout.csv -> make_pad_ring.py (die + pad spots)
  * die macro : build/gds/die/die_plan.json (die flow: 8 hardened blocks)

Emits the chip assembly plan:
  build/gds/chip/chip_assembly.json  (areas, macro placement, pad count)
  build/gds/chip/chip_assembly.tcl   (OpenROAD: floorplan, die macro centered
                                      inside the ring, pads placed FIRM from
                                      the pad_ring_placement.csv spots)

Checks the hardened die FITS inside the pad ring interior
(chip die minus the 200 um ring band) and fails loudly if not.

Run (after the die flow produced die_plan.json):
  python3 scripts/gds/chip_assemble.py
  python3 scripts/gds/chip_assemble.py --die-plan path/to/die_plan.json
"""

import argparse
import csv
import json
import os
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import make_pad_ring as mpr  # noqa: E402  (single source of pinout truth)

OUTDIR = os.path.join(ROOT, "build", "gds", "chip")


def load_die_plan(path):
    with open(path) as f:
        plan = json.load(f)
    die = plan["die"]
    return float(die["w"]), float(die["h"]), plan


def load_placement(path):
    """pad_ring_placement.csv -> list of dicts (signal pads + power + corners)."""
    rows = []
    with open(path, newline="") as f:
        for r in csv.DictReader(f):
            r["x_um"] = float(r["x_um"])
            r["y_um"] = float(r["y_um"])
            rows.append(r)
    return rows


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--die-plan",
                    default=os.path.join(ROOT, "build", "gds", "die",
                                         "die_plan.json"),
                    help="die flow plan JSON (die.w/die.h in um)")
    ap.add_argument("--clearance", type=float, default=40.0,
                    help="min macro-to-ring-band clearance per side (um)")
    ap.add_argument("--margin", type=float, default=100.0,
                    help="macro edge to chip die edge target (um)")
    args = ap.parse_args()

    # ---- pad ring side (regenerate from pinout.csv, single source of truth)
    pads = mpr.read_pinout()
    ordered, corners, chip_w, chip_h, total_len, min_per_side = mpr.build_ring(pads)
    ring_depth = mpr.PAD_H                       # 200 um band
    place_csv = os.path.join(OUTDIR, "pad_ring_placement.csv")
    if not os.path.exists(place_csv):
        raise SystemExit("run make_pad_ring.py first (missing %s)" % place_csv)
    placed = load_placement(place_csv)

    # ---- die macro side
    if not os.path.exists(args.die_plan):
        raise SystemExit(
            "missing %s -- run the die flow (die_plan.py) first, or pass "
            "--die-plan" % args.die_plan)
    die_w, die_h, plan = load_die_plan(args.die_plan)

    # ---- fit check: die macro inside the ring interior
    inner_w = chip_w - 2 * ring_depth
    inner_h = chip_h - 2 * ring_depth
    ok = (die_w + 2 * args.clearance <= inner_w
          and die_h + 2 * args.clearance <= inner_h)
    print("chip die (ring) : %.1f x %.1f um" % (chip_w, chip_h))
    print("ring interior   : %.1f x %.1f um" % (inner_w, inner_h))
    print("die macro       : %.1f x %.1f um (%.2f mm^2)"
          % (die_w, die_h, die_w * die_h / 1e6))
    if not ok:
        print("FIT CHECK FAILED: die macro + %.0f um clearance exceeds the "
              "ring interior" % args.clearance)
        raise SystemExit(1)
    print("fit check       : OK (>= %.0f um clearance all sides)"
          % args.clearance)

    # ---- center the die macro in the ring interior
    mx = round((chip_w - die_w) / 2.0, 3)
    my = round((chip_h - die_h) / 2.0, 3)
    clr_actual = min(mx - ring_depth, my - ring_depth,
                     (chip_w - die_w) / 2.0 - ring_depth,
                     (chip_h - die_h) / 2.0 - ring_depth)
    print("macro placement : (%.1f, %.1f) R0, actual clearance %.1f um"
          % (mx, my, clr_actual))

    n_sig = len([p for p in placed if p["net_class"] not in ("power", "ground")
                 and p["signal"] != "corner"])
    n_pwr = len(placed) - n_sig - 4

    os.makedirs(OUTDIR, exist_ok=True)
    out_json = os.path.join(OUTDIR, "chip_assembly.json")
    asm = {
        "chip_die_um": {"w": chip_w, "h": chip_h},
        "ring_band_um": ring_depth,
        "die_macro_um": {"w": die_w, "h": die_h, "x": mx, "y": my,
                         "orient": "R0"},
        "clearance_um": round(clr_actual, 3),
        "pads": {"signal": n_sig, "power_ground": n_pwr, "corner": 4,
                 "total": len(placed)},
        "die_plan": os.path.relpath(args.die_plan, ROOT),
    }
    with open(out_json, "w") as f:
        json.dump(asm, f, indent=1)

    out_tcl = os.path.join(OUTDIR, "chip_assembly.tcl")
    with open(out_tcl, "w") as f:
        f.write(TCL_HEADER.format(chip_w=chip_w, chip_h=chip_h,
                                  ring=ring_depth,
                                  core_w=chip_w - 2 * ring_depth,
                                  core_h=chip_h - 2 * ring_depth))
        f.write("place_ember_macro u_die %.3f %.3f R0\n" % (mx, my))
        f.write("\n# pads (from pad_ring_placement.csv)\n")
        for r in placed:
            f.write("place_ember_macro %s %.3f %.3f %s\n"
                    % (r["instance"], r["x_um"], r["y_um"], r["orient"]))
        f.write("\n# power/ground pads and corner cells are placed as listed;\n"
                "# supply routing ties them to VPWR/VGND domains in the "
                "assembly flow.\n")

    print("wrote:")
    print("  " + out_json)
    print("  " + out_tcl)


TCL_HEADER = """\
# generated by chip_assemble.py -- do not edit
# chip assembly: hardened die macro + pad ring ({chip_w:.0f} x {chip_h:.0f} um)
initialize_floorplan -die_area {{0 0 {chip_w:.3f} {chip_h:.3f}}} \\
    -core_area {{{ring:.0f} {ring:.0f} {core_w:.3f} {core_h:.3f}}} -site unithd
make_tracks
proc place_ember_macro {{inst_name x y orient}} {{
  set block [ord::get_db_block]
  set inst [$block findInst $inst_name]
  if {{$inst == "NULL"}} {{ error "instance $inst_name not found" }}
  $inst setOrient $orient
  $inst setOrigin [expr int(round($x * 1000))] [expr int(round($y * 1000))]
  $inst setPlacementStatus FIRM
}}
"""


if __name__ == "__main__":
    main()
