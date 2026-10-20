# Complete dump of met4 (71/20), met4pin (71/44), met5 (72/20), met5pin
# (72/44) shapes around both violation sites, NO truncation.
import pya

ly = pya.Layout()
ly.read('/work/build/gds/fpu4/fpu4.gds')
top = ly.top_cell()
dbu = ly.dbu

WIN = [
  ('VIA4.2 site', (197.5, 960.0, 203.0, 965.0)),
  ('MET4.2 site', (1582.0, 571.5, 1588.0, 579.0)),
]
LAYERS = [(71, 20), (71, 44), (72, 20), (72, 44), (71, 5), (72, 5), (94, 20), (235, 4)]

for tag, (x1, y1, x2, y2) in WIN:
    print(f'== {tag} ==')
    box = pya.Box(int(x1 / dbu), int(y1 / dbu), int(x2 / dbu), int(y2 / dbu))
    for lnum, dt in LAYERS:
        idx = ly.find_layer(pya.LayerInfo(lnum, dt))
        if idx is None:
            continue
        it = top.begin_shapes_rec(idx)
        hits = []
        while not it.at_end():
            sh = it.shape()
            if not sh.is_text():
                r = sh.bbox()
                if r.overlaps(box):
                    um = pya.Box(r.left * dbu, r.bottom * dbu, r.right * dbu, r.top * dbu)
                    hits.append(f'{lnum}/{dt} ({um.left:.3f},{um.bottom:.3f})-({um.right:.3f},{um.top:.3f}) {um.width():.3f}x{um.height():.3f}')
            it.next()
        print(f'  layer {lnum}/{dt}: {len(hits)} shapes')
        for h in hits:
            print('   ', h)
print('PROBE_DONE')
