"""Export a routed hierarchy using real GDS masters, never LEF blockages.

Defaults to ember_die. KLAYOUT_BLOCKS, KLAYOUT_DEF and KLAYOUT_TOP also allow
this exporter to implement the hierarchical rasterizer top.
"""
import os
from pathlib import Path
import xml.etree.ElementTree as ET

import pya

pdk = Path(os.environ['PDK'])
out = os.environ['KLAYOUT_OUT']
deff = os.environ.get('KLAYOUT_DEF', '/work/build/gds/die/final.def')
top_name = os.environ.get('KLAYOUT_TOP', 'ember_die')
macros = os.environ.get('KLAYOUT_BLOCKS', 'core tu gsx blit rtr_top xbar display cp').split()
tech_lef = pdk / 'libs.ref/sky130_fd_sc_hd/techlef/sky130_fd_sc_hd__nom.tlef'
cell_lef = pdk / 'libs.ref/sky130_fd_sc_hd/lef/sky130_fd_sc_hd.lef'
cell_gds = pdk / 'libs.ref/sky130_fd_sc_hd/gds/sky130_fd_sc_hd.gds'

# The shipped .lyt has an EMPTY LEF/DEF map. Derive actual GDS purposes from
# the PDK .lyp, rather than silently exporting arbitrary numbered layers.
properties = ET.parse(pdk / 'libs.tech/klayout/tech/sky130A.lyp')
layer_map = pya.LayerMap()
for index, prop in enumerate(properties.iter('properties')):
    name = (prop.findtext('name') or '').split(' - ')[0]
    source = (prop.findtext('source') or '').split('@')[0]
    if name and '/' in source:
        layer_map.map(f'"{name}": {source}', index)

masters = pya.Layout()
masters.read(str(cell_gds))
for name in macros:
    path = Path('/work/build/gds') / name / (name + '.gds')
    masters.read(str(path))
    cell = masters.cell('ember_' + name)
    if cell is None or cell.bbox().empty():
        raise SystemExit(f'Missing real macro geometry: {name}')

options = pya.LoadLayoutOptions()
config = options.lefdef_config
config.lef_files = [str(tech_lef), str(cell_lef)] + [
    f'/work/build/gds/{name}/{name}.lef' for name in macros]
config.macro_resolution_mode = 2  # never produce LEF abstract geometry
config.macro_layouts = [masters]
config.layer_map = layer_map
config.create_other_layers = False
config.routing_suffix = '.drawing'
config.special_routing_suffix = '.drawing'
config.via_geometry_suffix = '.drawing'
config.pins_suffix = '.pin'
config.labels_suffix = '.label'
config.produce_obstructions = False
config.produce_cell_outlines = False
options.lefdef_config = config
layout = pya.Layout()
layout.read(deff, options)
top = layout.cell(top_name)
if top is None or top.bbox().empty():
    raise SystemExit(f'Missing routed top geometry: {top_name}')
instances = list(top.each_inst())
for name in macros:
    matching = [inst for inst in instances if inst.cell.name == 'ember_' + name]
    if len(matching) != 1 or matching[0].cell.bbox().empty():
        raise SystemExit(f'Expected exactly one real macro instance: {name}')
    if not any(True for _ in matching[0].cell.each_inst()):
        raise SystemExit(f'Macro resolved to an abstract instead of placed cells: {name}')

# Copy only the connected hierarchy, not unrelated top-level library cells.
export = pya.Layout()
export.dbu = layout.dbu
export_top = export.create_cell(top_name)
export_top.copy_tree(top)
export.write(out)
print('Wrote routed hierarchy with real GDS macro substitution:', out)
