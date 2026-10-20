#!/usr/bin/env python3
"""Ember chip pad-ring generator (plan for the chip-level assembly).

Single source of truth: scripts/gds/pinout.csv.

What it does:
  * bit-blasts the pinout into physical pads (one sky130_fd_io pad per pin)
  * inserts power/ground pads (VDDIO/VSSIO/VCCD/VSSD) to reach a sane power
    density AND to balance the opposite ring sides to a common die dimension
  * computes pad placement (x, y, orientation, cell) for a four-sided ring
  * emits:
      build/gds/chip/pad_ring_placement.csv   -- instance, cell, x, y, orient
      build/gds/chip/pad_ring_report.txt      -- budget, die size, per-side pitch
      build/gds/chip/pad_cells_physical.v     -- pad_in/pad_out/pad_xres wrappers
                                                built from real sky130_fd_io cells
  * --check: verifies pinout.csv against rtl/ember_chip.sv (name, width, dir)

Run from anywhere (paths are repo-relative):
  python3 scripts/gds/make_pad_ring.py            # generate
  python3 scripts/gds/make_pad_ring.py --check    # consistency check

Geometry conventions:
  * origin = die bottom-left; units = um; x/y in the CSV is the pad CENTER
    of its ring footprint.
  * ring order is counter-clockwise: south row L->R (R0), east column B->T
    (R90), north row R->L (R180), west column T->B (R270).
  * signal pads keep their pinout.csv order along each side; power/ground
    pads are inserted after the signal pads of each side (a physical flow can
    redistribute them along the edge without changing counts or die size).
  * pad widths: gpiov2 80um, xres4v2 / power / ground 75um, corner 200um.
"""

import csv
import os
import re
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
PINOUT = os.path.join(ROOT, "scripts", "gds", "pinout.csv")
CHIP_SV = os.path.join(ROOT, "rtl", "ember_chip.sv")
OUTDIR = os.path.join(ROOT, "build", "gds", "chip")

PAD_W = {
    "sky130_fd_io__top_gpiov2": 80,
    "sky130_fd_io__top_xres4v2": 75,
    "sky130_fd_io__top_power_hvc_wpad": 75,
    "sky130_fd_io__top_power_lvc_wpad": 75,
    "sky130_fd_io__top_ground_hvc_wpad": 75,
    "sky130_fd_io__top_ground_lvc_wpad": 75,
    "sky130_fd_io__corner_bus_overlay": 200,
}

# LEF name -> GDS cell name. The sky130 PDK ships one cell under a different
# name in GDS than in LEF (power_hvc_wpad LEF / power_hvc_wpadv2 GDS); the
# GDS composer (make_pad_ring_gds.py) resolves through this alias map.
GDS_ALIAS = {
    "sky130_fd_io__top_power_hvc_wpad": "sky130_fd_io__top_power_hvc_wpadv2",
}
PAD_H = 200          # ring band depth (corner cell is 203.665 tall)
CORNER_W = 200

# power/ground pad cycle: VDDIO, VSSIO, VCCD, VSSD
PWR_CYCLE = [
    ("sky130_fd_io__top_power_hvc_wpad", "VDDIO"),
    ("sky130_fd_io__top_ground_hvc_wpad", "VSSIO"),
    ("sky130_fd_io__top_power_lvc_wpad", "VCCD"),
    ("sky130_fd_io__top_ground_lvc_wpad", "VSSD"),
]

SIDES = ["S", "E", "N", "W"]   # counter-clockwise ring walk
ORIENT = {"S": "R0", "E": "R90", "N": "R180", "W": "R270"}


def read_pinout():
    """Return list of bit-blasted pads: dicts with side, group, signal, bit,
    width, dir, pad_cell, net_class.

    CSV columns: signal,dir,width,pad_cell,side,group (file order = ring
    order within each side)."""
    pads = []
    seq = 0
    with open(PINOUT, newline="") as f:
        for row in csv.reader(f):
            if not row or row[0].lstrip().startswith("#"):
                continue
            if row[0] == "signal":
                continue
            signal, direction, width, cell, side, group = [
                v.strip() for v in row[:6]
            ]
            width = int(width)
            seq += 1
            net_class = {"host": "host", "mem": "memory", "video": "video",
                         "sys": "sys"}.get(group.split("_")[0], group)
            for bit in range(width):
                pads.append({
                    "side": side,
                    "index": seq,
                    "group": group,
                    "signal": signal,
                    "bit": bit,
                    "width": width,
                    "dir": direction,
                    "pad_cell": cell,
                    "net_class": net_class,
                })
    return pads


def instance_name(p):
    if p["width"] == 1:
        return "g_%s.u_pad" % p["signal"]
    return "g_%s[%d].u_pad" % (p["signal"], p["bit"])


def side_lists(pads):
    """Signal pads per side in ring order."""
    out = {s: [] for s in SIDES}
    for p in pads:
        out[p["side"]].append(p)
    for s in SIDES:
        out[s].sort(key=lambda p: (p["index"], p["bit"]))
    return out


def pad_width(p):
    return PAD_W[p["pad_cell"]]


def make_power_pads(n):
    """n power/ground pads cycling VDDIO/VSSIO/VCCD/VSSD."""
    pads = []
    for i in range(n):
        cell, rail = PWR_CYCLE[i % len(PWR_CYCLE)]
        pads.append({
            "side": None,
            "index": -1,
            "group": "power",
            "signal": "pwr_%s_%d" % (rail, i),
            "bit": 0,
            "width": 1,
            "dir": "pwr",
            "pad_cell": cell,
            "net_class": "power" if "power" in cell else "ground",
            "rail": rail,
        })
    return pads


def build_ring(pads):
    by_side = side_lists(pads)

    # minimum power density: ~1 power/ground pad per 12 signal pads, >= 2
    total_sig = sum(len(by_side[s]) for s in SIDES)
    min_pwr_total = max(8, (total_sig + 11) // 12)
    min_per_side = {s: max(2, (len(by_side[s]) + 11) // 12) for s in SIDES}
    scale = min_pwr_total / max(1, sum(min_per_side.values()))
    if scale > 1:
        for s in SIDES:
            min_per_side[s] = int(round(min_per_side[s] * scale))

    def sig_len(s):
        return sum(pad_width(p) for p in by_side[s])

    # balance opposite sides with power pads (75um units); then any residual
    # slack is spread as extra pitch on the shorter side.
    def balance(a, b):
        la, lb = sig_len(a), sig_len(b)
        na, nb = min_per_side[a], min_per_side[b]
        # pads added beyond the minimum go to the shorter side
        need = max(la + na * 75, lb + nb * 75)
        na = max(na, (need - la + 74) // 75)
        nb = max(nb, (need - lb + 74) // 75)
        return na, nb

    pwr_n, pwr_s = balance("N", "S")
    pwr_e, pwr_w = balance("E", "W")
    pwr_count = {"N": pwr_n, "S": pwr_s, "E": pwr_e, "W": pwr_w}

    for s in SIDES:
        by_side[s] = by_side[s] + make_power_pads(pwr_count[s])

    def total_len(s):
        return sum(pad_width(p) for p in by_side[s])

    die_w = 2 * CORNER_W + max(total_len("N"), total_len("S"))
    die_h = 2 * CORNER_W + max(total_len("E"), total_len("W"))

    # place: counter-clockwise S(L->R), E(B->T), N(R->L), W(T->B)
    def place(side, span, reverse, xy):
        pads_s = list(reversed(by_side[side])) if reverse else by_side[side]
        n = len(pads_s)
        slack = span - total_len(side)
        gap = slack / (n - 1) if n > 1 and slack > 0 else 0.0
        acc = slack / 2.0 if slack > 0 else 0.0
        for p in pads_s:
            w = pad_width(p)
            center = acc + w / 2.0
            p["x"], p["y"] = xy(center)
            p["orient"] = ORIENT[side]
            p["side_out"] = side
            acc += w + gap

    span_h = die_w - 2 * CORNER_W
    span_v = die_h - 2 * CORNER_W
    place("S", span_h, False, lambda c: (CORNER_W + c, PAD_H / 2))
    place("E", span_v, False, lambda c: (die_w - PAD_H / 2, CORNER_W + c))
    place("N", span_h, True,  lambda c: (die_w - CORNER_W - c, die_h - PAD_H / 2))
    place("W", span_v, True,  lambda c: (PAD_H / 2, die_h - CORNER_W - c))

    corners = [
        {"signal": "u_corner_sw", "x": CORNER_W / 2, "y": CORNER_W / 2, "orient": "R0"},
        {"signal": "u_corner_se", "x": die_w - CORNER_W / 2, "y": CORNER_W / 2, "orient": "R90"},
        {"signal": "u_corner_ne", "x": die_w - CORNER_W / 2, "y": die_h - CORNER_W / 2, "orient": "R180"},
        {"signal": "u_corner_nw", "x": CORNER_W / 2, "y": die_h - CORNER_W / 2, "orient": "R270"},
    ]

    ordered = []
    for s in SIDES:
        ordered += by_side[s]
    return ordered, corners, die_w, die_h, total_len, min_per_side


def write_outputs(pads, corners, die_w, die_h, total_len, min_per_side):
    os.makedirs(OUTDIR, exist_ok=True)

    place_csv = os.path.join(OUTDIR, "pad_ring_placement.csv")
    with open(place_csv, "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["instance", "cell", "side", "signal", "bit", "dir",
                    "net_class", "x_um", "y_um", "orient"])
        for p in pads:
            w.writerow([
                instance_name(p), p["pad_cell"], p["side_out"],
                p["signal"], p["bit"], p["dir"], p["net_class"],
                "%.3f" % p["x"], "%.3f" % p["y"], p["orient"],
            ])
        for c in corners:
            w.writerow([c["signal"], "sky130_fd_io__corner_bus_overlay",
                        "-", "corner", 0, "pwr", "power",
                        "%.3f" % c["x"], "%.3f" % c["y"], c["orient"]])

    sig_pads = [p for p in pads if p["group"] != "power"]
    pwr_pads = [p for p in pads if p["group"] == "power"]
    report = os.path.join(OUTDIR, "pad_ring_report.txt")
    with open(report, "w") as f:
        f.write("Ember chip pad ring report\n")
        f.write("source: scripts/gds/pinout.csv\n\n")
        f.write("signal pads      : %d (%d signal names)\n"
                % (len(sig_pads), len({(p['signal']) for p in sig_pads})))
        f.write("power/ground     : %d\n" % len(pwr_pads))
        f.write("corner cells     : 4\n")
        f.write("TOTAL pads       : %d\n\n" % (len(pads) + 4))
        f.write("die size         : %.1f x %.1f um  (%.2f mm^2 incl. pads)\n"
                % (die_w, die_h, die_w * die_h / 1e6))
        f.write("ring band depth  : %d um\n\n" % PAD_H)
        for s in SIDES:
            side_pads = [p for p in pads if p["side_out"] == s]
            nsig = len([p for p in side_pads if p["group"] != "power"])
            npwr = len([p for p in side_pads if p["group"] == "power"])
            span = die_w - 2 * CORNER_W if s in ("N", "S") else die_h - 2 * CORNER_W
            f.write("side %s: %3d signal + %2d power pads, span %7.1f um, "
                    "avg pitch %.2f um (min pwr/side %d)\n"
                    % (s, nsig, npwr, span,
                       span / len(side_pads), min_per_side[s]))
        f.write("\nby net class:\n")
        from collections import Counter
        cnt = Counter(p["net_class"] for p in sig_pads)
        for k in sorted(cnt):
            f.write("  %-8s %3d pins\n" % (k, cnt[k]))
        f.write("\nnotes:\n")
        f.write("  - x/y are pad footprint centers; ring order is "
                "counter-clockwise (S, E, N, W).\n")
        f.write("  - residual side slack is absorbed as extra inter-pad "
                "pitch (reported avg pitch);\n")
        f.write("    exact abutment is a chip-assembly refinement in the "
                "physical flow.\n")
        f.write("  - power/ground pads connect VDDIO/VSSIO/VCCD/VSSD "
                "(VDDA/VSSA tie to VDDIO/VSSIO analog taps);\n")
        f.write("    distribute evenly along each edge in the physical "
                "flow.\n")

    phys = os.path.join(OUTDIR, "pad_cells_physical.v")
    with open(phys, "w") as f:
        f.write(PHYSICAL_PAD_CELLS)
    return place_csv, report, phys


# ---------------------------------------------------------------------------
# Physical pad-cell wrappers (real sky130_fd_io cells). Same module names as
# rtl/pad_models.sv so the flow can swap files without touching ember_chip.sv.
# DM/OE_N/ENABLE settings follow the standard caravel pad configuration.
# ---------------------------------------------------------------------------
PHYSICAL_PAD_CELLS = r"""// pad_cells_physical.v -- GENERATED by scripts/gds/make_pad_ring.py
// Physical twins of rtl/pad_models.sv built from real sky130_fd_io cells.
// Supply pins connect to the chip-level rails; configuration follows the
// caravel standard pad settings.

module pad_in
(
  input  wire PAD,
  output wire IN
);
  sky130_fd_io__top_gpiov2 u_cell (
    .PAD(PAD), .PAD_A_NOESD_H(), .PAD_A_ESD_0_H(), .PAD_A_ESD_1_H(),
    .IN(IN), .IN_H(), .OUT(1'b0), .OE_N(1'b1),
    .DM(3'b001), .HLD_H_N(1'b1), .HLD_OVR(1'b0), .INP_DIS(1'b0),
    .VTRIP_SEL(1'b1), .SLOW(1'b0), .IB_MODE_SEL(1'b0),
    .ANALOG_EN(1'b0), .ANALOG_SEL(1'b0), .ANALOG_POL(1'b0),
    .ENABLE_H(1'b1), .ENABLE_INP_H(1'b1), .ENABLE_VDDIO(1'b1),
    .ENABLE_VDDA_H(1'b0), .ENABLE_VSWITCH_H(1'b0),
    .TIE_HI_ESD(1'b1), .TIE_LO_ESD(1'b0),
    .AMUXBUS_A(), .AMUXBUS_B(),
    .VCCD(vccd), .VCCHIB(vcchib), .VDDA(vdda), .VDDIO(vddio),
    .VDDIO_Q(vddio), .VSWITCH(vddio),
    .VSSA(vssa), .VSSD(vssd), .VSSIO(vssio), .VSSIO_Q(vssio));
endmodule

module pad_out
(
  output wire PAD,
  input  wire OUT
);
  sky130_fd_io__top_gpiov2 u_cell (
    .PAD(PAD), .PAD_A_NOESD_H(), .PAD_A_ESD_0_H(), .PAD_A_ESD_1_H(),
    .IN(), .IN_H(), .OUT(OUT), .OE_N(1'b0),
    .DM(3'b110), .HLD_H_N(1'b1), .HLD_OVR(1'b0), .INP_DIS(1'b0),
    .VTRIP_SEL(1'b1), .SLOW(1'b0), .IB_MODE_SEL(1'b0),
    .ANALOG_EN(1'b0), .ANALOG_SEL(1'b0), .ANALOG_POL(1'b0),
    .ENABLE_H(1'b1), .ENABLE_INP_H(1'b1), .ENABLE_VDDIO(1'b1),
    .ENABLE_VDDA_H(1'b0), .ENABLE_VSWITCH_H(1'b0),
    .TIE_HI_ESD(1'b1), .TIE_LO_ESD(1'b0),
    .AMUXBUS_A(), .AMUXBUS_B(),
    .VCCD(vccd), .VCCHIB(vcchib), .VDDA(vdda), .VDDIO(vddio),
    .VDDIO_Q(vddio), .VSWITCH(vddio),
    .VSSA(vssa), .VSSD(vssd), .VSSIO(vssio), .VSSIO_Q(vssio));
endmodule

module pad_xres
(
  input  wire PAD,
  output wire XRES_H_N
);
  sky130_fd_io__top_xres4v2 u_cell (
    .PAD_A_ESD_H(PAD), .XRES_H_N(XRES_H_N), .FILT_IN_H(PAD),
    .INP_SEL_H(1'b1), .PULLUP_H(1'b1), .DISABLE_PULLUP_H(1'b0),
    .TIE_WEAK_HI_H(1'b1), .EN_VDDIO_SIG_H(1'b1),
    .ENABLE_H(1'b1), .ENABLE_VDDIO(1'b1),
    .TIE_HI_ESD(1'b1), .TIE_LO_ESD(1'b0),
    .VCCHIB(vcchib), .VDDIO(vddio), .VDDIO_Q(vddio), .VSWITCH(vddio),
    .VSSD(vssd), .VSSIO(vssio), .VSSIO_Q(vssio));
endmodule

// Power / ground pads (placed by pad_ring_placement.csv; rails are chip-level
// supply nets driven through these pads).
module pad_power_hvc (inout wire PAD);
  sky130_fd_io__top_power_hvc_wpad u_cell (.P_PAD(PAD),
    .VCCD(vccd), .VCCHIB(vcchib), .VDDA(vdda), .VDDIO(vddio),
    .VDDIO_Q(vddio), .VSWITCH(vddio),
    .VSSA(vssa), .VSSD(vssd), .VSSIO(vssio), .VSSIO_Q(vssio));
endmodule
module pad_ground_hvc (inout wire PAD);
  sky130_fd_io__top_ground_hvc_wpad u_cell (.G_PAD(PAD),
    .VCCD(vccd), .VCCHIB(vcchib), .VDDA(vdda), .VDDIO(vddio),
    .VDDIO_Q(vddio), .VSWITCH(vddio),
    .VSSA(vssa), .VSSD(vssd), .VSSIO(vssio), .VSSIO_Q(vssio));
endmodule
module pad_power_lvc (inout wire PAD);
  sky130_fd_io__top_power_lvc_wpad u_cell (.P_PAD(PAD),
    .VCCD(vccd), .VCCHIB(vcchib), .VDDA(vdda), .VDDIO(vddio),
    .VDDIO_Q(vddio), .VSWITCH(vddio),
    .VSSA(vssa), .VSSD(vssd), .VSSIO(vssio), .VSSIO_Q(vssio));
endmodule
module pad_ground_lvc (inout wire PAD);
  sky130_fd_io__top_ground_lvc_wpad u_cell (.G_PAD(PAD),
    .VCCD(vccd), .VCCHIB(vcchib), .VDDA(vdda), .VDDIO(vddio),
    .VDDIO_Q(vddio), .VSWITCH(vddio),
    .VSSA(vssa), .VSSD(vssd), .VSSIO(vssio), .VSSIO_Q(vssio));
endmodule
"""


# ---------------------------------------------------------------------------
# --check: pinout.csv vs rtl/ember_chip.sv
# ---------------------------------------------------------------------------
PORT_RE = re.compile(
    r"^\s*(input|output|inout)\s+(?:logic\s+)?"
    r"(?:\[\s*(\d+)\s*:\s*(\d+)\s*\]\s*)?(\w+)\s*[,;)]?\s*$")


def read_chip_ports():
    ports = {}
    with open(CHIP_SV) as f:
        for line in f:
            m = PORT_RE.match(line)
            if m:
                direction, hi, lo, name = m.groups()
                width = 1 if hi is None else abs(int(hi) - int(lo)) + 1
                ports[name] = (direction, width)
    return ports


def check():
    pads = read_pinout()
    ports = read_chip_ports()
    errors = []

    sigs = {}
    for p in pads:
        sigs.setdefault(p["signal"], (p["dir"], p["width"]))

    for name, (direction, width) in sorted(sigs.items()):
        if name not in ports:
            errors.append("pinout signal '%s' has no port in ember_chip.sv" % name)
            continue
        pd, pw = ports[name]
        want = "input" if direction == "in" else "output"
        if pd != want:
            errors.append("%s: pinout dir=%s but port is %s" % (name, direction, pd))
        if pw != width:
            errors.append("%s: pinout width=%d but port is [%d]" % (name, width, pw))

    for name in sorted(ports):
        if name not in sigs:
            errors.append("ember_chip.sv port '%s' has no pin in pinout.csv" % name)

    if errors:
        print("PINOUT CHECK FAILED (%d errors):" % len(errors))
        for e in errors:
            print("  " + e)
        return 1
    print("PINOUT CHECK OK: %d signals (%d physical pins) match ember_chip.sv"
          % (len(sigs), len(pads)))
    return 0


def main():
    if "--check" in sys.argv:
        sys.exit(check())
    pads = read_pinout()
    ordered, corners, die_w, die_h, total_len, min_per_side = build_ring(pads)
    place_csv, report, phys = write_outputs(
        ordered, corners, die_w, die_h, total_len, min_per_side)
    print("pad ring generated:")
    print("  " + place_csv)
    print("  " + report)
    print("  " + phys)
    print("die: %.1f x %.1f um, %d pads incl. power/corner"
          % (die_w, die_h, len(ordered) + 4))


if __name__ == "__main__":
    main()
