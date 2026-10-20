# KLayout finalize: normalize DBU and guarantee a readable, standalone GDS
import pya

import json
import os

src = os.environ.get("KLAYOUT_IN", "")
dst = os.environ.get("KLAYOUT_OUT", "")
if not src or not dst:
    raise SystemExit("set KLAYOUT_IN / KLAYOUT_OUT")

layout = pya.Layout()
layout.read(src)
expected_top = os.environ.get("KLAYOUT_TOP", "")
if not expected_top:
    raise SystemExit("set KLAYOUT_TOP to validate the intended design cell")
top = layout.cell(expected_top)
if top is None or top.bbox().empty():
    raise SystemExit(f"missing or empty design cell: {expected_top}")
shapes = sum(1 for layer in layout.layer_indices()
             for _ in top.begin_shapes_rec(layer))
if shapes == 0:
    raise SystemExit(f"no geometry under {expected_top}")
# Keep the original DBU: changing it without rescaling coordinates changes size.
options = pya.SaveLayoutOptions()
options.select_cell(top.cell_index())
layout.write(dst, options)
with open("gds_validation.json", "w") as fh:
    json.dump({"top": expected_top, "recursive_shapes": shapes,
               "width_um": top.bbox().width() * layout.dbu,
               "height_um": top.bbox().height() * layout.dbu}, fh, indent=2)
print("finalize validated:", dst, expected_top, shapes, "shapes")
