# def2gds.py — KLayout fallback: LEF + DEF (+ sky130 cell GDS) -> GDS.
#
# Used only when Magic cannot produce a GDS for a routed block (the known
# deterministic top-cell streamout wedge). KLayout reads the tech LEF, the
# cell LEF, the routed DEF and the standard-cell geometry, then writes a
# standalone GDS. Same LEF/DEF import machinery as die_def2gds.py, proven on
# pya 0.29.4 (LoadLayoutOptions.lefdef_config; the earlier ad-hoc
# layout.read(deff, "lef_files=...") call never ran and is invalid).
#
# Env: PDK, KLAYOUT_DEF, KLAYOUT_TOP, KLAYOUT_OUT
import os
import xml.etree.ElementTree as ET

import pya

pdk = os.environ["PDK"]
deff = os.environ["KLAYOUT_DEF"]
top_name = os.environ.get("KLAYOUT_TOP", "")
out = os.environ["KLAYOUT_OUT"]

tech = os.path.join(pdk, "libs.ref/sky130_fd_sc_hd/techlef/sky130_fd_sc_hd__nom.tlef")
cell_lef = os.path.join(pdk, "libs.ref/sky130_fd_sc_hd/lef/sky130_fd_sc_hd.lef")
cell_gds = os.path.join(pdk, "libs.ref/sky130_fd_sc_hd/gds/sky130_fd_sc_hd.gds")

# The shipped .lyt has an EMPTY LEF/DEF map. Derive actual GDS purposes from
# the PDK .lyp so routing/pin layers land on the real sky130 layer/datatype
# numbers instead of silently exporting arbitrary numbered layers.
properties = ET.parse(os.path.join(pdk, "libs.tech/klayout/tech/sky130A.lyp"))
layer_map = pya.LayerMap()
for index, prop in enumerate(properties.iter("properties")):
    name = (prop.findtext("name") or "").split(" - ")[0]
    source = (prop.findtext("source") or "").split("@")[0]
    if name and "/" in source:
        layer_map.map(f'"{name}": {source}', index)

# Real standard-cell geometry, so DEF components resolve to full GDS masters
# instead of LEF abstracts.
masters = pya.Layout()
masters.read(cell_gds)
print("read cell GDS:", cell_gds)

options = pya.LoadLayoutOptions()
config = options.lefdef_config
config.lef_files = [tech, cell_lef]
config.macro_resolution_mode = 2  # never produce LEF abstract geometry
config.macro_layouts = [masters]
config.layer_map = layer_map
config.create_other_layers = False
config.routing_suffix = ".drawing"
config.special_routing_suffix = ".drawing"
config.via_geometry_suffix = ".drawing"
config.pins_suffix = ".pin"
config.labels_suffix = ".label"
config.produce_obstructions = False
config.produce_cell_outlines = False
options.lefdef_config = config

layout = pya.Layout()
layout.read(deff, options)
print("read DEF:", deff)

if not top_name:
    tops = layout.top_cells()
    if len(tops) != 1:
        raise SystemExit("KLAYOUT_TOP required: %d top cells" % len(tops))
    top_name = tops[0].name
top = layout.cell(top_name)
if top is None or top.bbox().empty():
    raise SystemExit("missing or empty top cell: %s" % top_name)

# Every placed master must be REAL geometry, not a LEF abstract. Standard
# cells must equal their GDS library master (bbox + shape count); cells not in
# the library are tech-LEF via cells and must carry their own real geometry.
def shape_count(cell):
    return sum(1 for li in cell.layout().layer_indices()
               for _ in cell.each_shape(li))

checked = 0
seen = set()
for inst in top.each_inst():
    name = inst.cell.name
    if name in seen:
        continue
    seen.add(name)
    a = inst.cell
    if shape_count(a) == 0 and not any(True for _ in a.each_inst()):
        raise SystemExit("master %s has no geometry (abstract?)" % name)
    lib = masters.cell(name)
    if lib is not None:
        if a.bbox() != lib.bbox() or shape_count(a) != shape_count(lib):
            raise SystemExit("master %s bbox/shapes != library master (abstract?)"
                             % name)
    checked += 1
print("verified %d distinct masters against real GDS geometry" % checked)

# Copy only the connected hierarchy, not unrelated library top cells.
export = pya.Layout()
export.dbu = layout.dbu
export_top = export.create_cell(top_name)
export_top.copy_tree(top)
export.write(out)
print("wrote", out)
