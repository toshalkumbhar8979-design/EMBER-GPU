"""
tools/gds/collect_results.py: turn the 12 hardening runs into the paper's
ASIC results table.

Reads (inside the container filesystem, mirrored under the repo when copied):
    build/gds/<block>/synth_stat.txt   Yosys cell-count report
    build/gds/<block>/openroad.log     OpenROAD floorplan/place/route log
    build/gds/<block>/magic.log        DRC count
    build/gds/<block>/<block>.gds      final GDS
and writes:
    paper/asic_table.tex   a booktabs table for the IEEE paper
    build/gds/RESULTS.md   a human-readable summary

Usage (in the container or WSL with the tree copied):
    python3 tools/gds/collect_results.py [root]
"""
import hashlib
import json
import os
from pathlib import Path
import re
import sys

BLOCKS = [
    ("rtr_scan", "Raster scan FSM (RTR pixel pipeline)"),
    ("rtr_setup", "Cramer triangle setup"),
    ("rtr_top", "RTR top (cmdq fetch + scan + setup)"),
    ("fpu4", "4-lane fp32 vector FPU"),
    ("gsx", "Geometry engine (MVP + clip + cmdq emit)"),
    ("blit", "Blitter (key + 2x scale)"),
    ("display", "Video timing / framebuffer fetch"),
    ("cp", "Command processor (DMA + fences)"),
    ("xbar", "AXI4-Lite interconnect"),
    ("ram_slave", "Register-file AXI slave"),
    ("core", "4-thread SPMD compute core"),
    ("tu", "16x16 int8 tensor unit"),
]


def parse_block(root, name):
    d = os.path.join(root, name)
    out = {"name": name, "cells": None, "area": None, "gds_kb": None,
           "drc": None, "route_drc": None, "synthesized": False,
           "audit_verified": False,
           "wns": None, "wirelen": None, "flow": "not run"}
    if not os.path.isdir(d):
        return out

    # Cache marker is only written following successful synthesis.
    out["synthesized"] = (os.path.isfile(os.path.join(d, ".synthkey"))
                          and os.path.isfile(os.path.join(d, "synth.v"))
                          and os.path.getsize(os.path.join(d, "synth.v")) > 0)
    sp = os.path.join(d, "synth_stat.txt")
    if not os.path.exists(sp):
        sp = os.path.join(d, "yosys.log")
    if out["synthesized"] and os.path.exists(sp):
        txt = Path(sp).read_text(encoding='utf-8', errors='ignore')
        counts = re.findall(r"Number of cells\s*:?\s+(\d+)", txt)
        if counts:
            out["cells"] = int(counts[-1])
    if out["synthesized"]:
        out["flow"] = "synthesized"

    fl = os.path.join(d, "flow.txt")
    if os.path.exists(fl):
        out["flow"] = Path(fl).read_text(encoding='utf-8', errors='ignore').strip()

    ol = os.path.join(d, "openroad.log")
    if os.path.exists(ol):
        txt = Path(ol).read_text(encoding='utf-8', errors='ignore')
        if out["flow"] == "not run":
            if "detailed_route" in txt:
                out["flow"] = "detailed-route"
            elif "global_route" in txt:
                out["flow"] = "global-route"
            elif "global_placement" in txt:
                out["flow"] = "placed"
        m = re.search(r"Design area\s+([\d.]+)\s*u\^2\s+([\d.]+)%", txt)
        if m:
            out["area"] = float(m.group(1))
        slacks = re.findall(r"(?:WNS=|^wns\s+)(-?[\d.]+)", txt, re.MULTILINE)
        if slacks:
            out["wns"] = float(slacks[-1])
        lengths = re.findall(r"Total wire length\s*[:=]?\s*([\d.]+)", txt)
        if lengths:
            out["wirelen"] = float(lengths[-1])
        counts = re.findall(r"Number of violations = (\d+)", txt)
        if counts:
            out["route_drc"] = int(counts[-1])
            out["flow"] = "routing attempted (not validated)"

    ml = os.path.join(d, "magic.log")
    if os.path.exists(ml):
        m = re.search(r"DRC_COUNT=(\d+)", Path(ml).read_text(encoding='utf-8', errors='ignore'))
        if m:
            out["drc"] = int(m.group(1))

    # Only accept exported-layout audit evidence matching this exact GDS.
    # Old logs may describe a different streamout/grid and must not override it.
    audit = os.path.join(d, "export_audit.json")
    gds_path = os.path.join(d, f"{name}.gds")
    if os.path.exists(audit) and os.path.exists(gds_path):
        try:
            evidence = json.loads(Path(audit).read_text(encoding='utf-8'))
            stat = os.stat(gds_path)
            if (evidence.get("gds_mtime_ns") == stat.st_mtime_ns
                    and evidence.get("gds_bytes") == stat.st_size
                    and evidence.get("top") == "ember_" + name
                    and evidence.get("rules_suppressed") is False
                    and evidence.get("gds_sha256") == hashlib.sha256(
                        Path(gds_path).read_bytes()).hexdigest()):
                out["drc"] = evidence["whole_layout_flattened_drc"]
                out["audit_verified"] = True
        except (ValueError, OSError, KeyError):
            pass

    g = os.path.join(d, f"{name}.gds")
    validation = os.path.join(d, "gds_validation.json")
    if os.path.exists(g):
        out["gds_kb"] = round(os.path.getsize(g) / 1024, 1)
        out["flow"] = "GDS present (unvalidated)"
        if os.path.exists(validation) and os.path.getmtime(validation) >= os.path.getmtime(g) - 2:
            try:
                evidence = json.loads(Path(validation).read_text(encoding='utf-8'))
                if evidence.get("top") == "ember_" + name and evidence.get("recursive_shapes", 0) > 0:
                    out["flow"] = "GDS validated; checks incomplete"
                    if out["audit_verified"] and out["route_drc"] == 0 and out["drc"] == 0:
                        out["flow"] = "GDS; routing/Magic DRC zero (LVS pending)"
            except (ValueError, OSError):
                pass

    return out


def main(argv):
    root = argv[0] if argv else "build/gds"
    rows = [parse_block(root, n) for n, _ in BLOCKS]

    lines = []
    md = ["# Ember ASIC hardening results (sky130A, OpenLane 2 image, OpenROAD)\n",
          "| Block | Cells | Area (um^2) | Wire (um) | WNS (ns) | Magic DRC | GDS (KB) | Flow |",
          "|---|---|---|---|---|---|---|---|"]
    for (name, desc), r in zip(BLOCKS, rows):
        tex_name = name.replace("_", r"\_")
        def f(v, fmt="{:.0f}"):
            return "-" if v is None else fmt.format(v)
        lines.append(
            "\\texttt{%s} & %s & %s & %s & %s & %s & %s \\\\"
            % (tex_name, f(r["cells"]), f(r["area"]), f(r["wirelen"]),
               ("-" if r["wns"] is None else "%.2f" % r["wns"]),
               f(r["drc"]), f(r["gds_kb"], "{:.0f}"))
        )
        md.append("| `%s` | %s | %s | %s | %s | %s | %s | %s |"
                  % (name, f(r["cells"]), f(r["area"]), f(r["wirelen"]),
                     ("-" if r["wns"] is None else "%.2f" % r["wns"]),
                     f(r["drc"]), f(r["gds_kb"], "{:.0f}"), r["flow"]))

    os.makedirs("paper", exist_ok=True)
    # NOTE: emit a COMPLETE table float. \input-ing just the rows and following
    # it with \bottomrule makes LaTeX abort with "Misplaced \noalign" (the
    # \noalign in \bottomrule lands on a file boundary, which TeX rejects).
    table = [
        "% AUTO-GENERATED by tools/gds/collect_results.py: do not edit",
        "\\begin{table}[t]",
        "\\caption{SkyWater sky130 hardening results, per block. Cells are mapped "
        "standard cells after synthesis (hierarchical wrappers include macro instances); area and wire length "
        "are from the latest available physical run; DRC is the exported-layout audit "
        "count when verified, otherwise the available Magic count; missing entries "
        "are not completed results. WNS "
        "is worst negative slack against a 20\\,ns (50\\,MHz) target.}",
        "\\label{tab:asic}",
        "\\centering",
        "\\scriptsize",
        "\\begin{tabular}{@{}lrrrrrr@{}}",
        "\\toprule",
        "Block & Cells & Area & Wire & WNS & DRC & GDS \\\\",
        "      &       & ($\\mu m^2$) & ($\\mu m$) & (ns) & & (KB) \\\\",
        "\\midrule",
    ] + lines + [
        "\\bottomrule",
        "\\end{tabular}",
        "\\end{table}",
    ]
    with open("paper/asic_table.tex", "w") as fh:
        fh.write("\n".join(table) + "\n")
    with open(os.path.join(root, "RESULTS.md"), "w") as fh:
        fh.write("\n".join(md) + "\n")

    total_cells = sum(r["cells"] or 0 for r in rows)
    with open("paper/asic_numbers.tex", "w") as fh:
        fh.write("% AUTO-GENERATED by tools/gds/collect_results.py: do not edit\n")
        fh.write("\\newcommand{\\AsicTotalCells}{%d}\n" % total_cells)
        fh.write("\\newcommand{\\AsicBlocksDone}{%d}\n"
                 % sum(1 for r in rows if r["synthesized"]))
        fh.write("\\newcommand{\\AsicBlocksGds}{%d}\n"
                 % sum(1 for r in rows if r["flow"].startswith("GDS;")))
    print("wrote paper/asic_table.tex, paper/asic_numbers.tex, %s/RESULTS.md" % root)
    print("cells total=%d blocks=%d gds=%d"
          % (total_cells, sum(1 for r in rows if r["synthesized"]),
             sum(1 for r in rows if r["flow"].startswith("GDS;"))))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
