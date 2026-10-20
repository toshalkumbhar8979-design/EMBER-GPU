# Probe the merged fpu4 GDS at the exact Magic DRC marker boxes.
# Magic lambda -> um: x0.005. Print EVERY layer's shapes overlapping the
# marker windows (union of both marker boxes per violation).
import pya

ly = pya.Layout()
ly.read('/work/build/gds/fpu4/fpu4.gds')
top = ly.top_cell()
dbu = ly.dbu
print('top:', top.name, 'dbu:', dbu)

# via4.2 violation: Magic boxes (lambda): (39902,192458)-(40138,192524)
# met4.2 violation: Magic boxes (lambda): (316970,114896)-(317068,115252)
# windows in um with 0.6um margin
WIN = [
  ('VIA4.2 site', (199.51 - 1.2, 962.29 - 1.2, 200.69 + 1.2, 962.62 + 1.2)),
  ('MET4.2 site', (1584.85 - 1.2, 574.48 - 1.2, 1585.34 + 1.2, 576.26 + 1.2)),
]

for tag, (x1, y1, x2, y2) in WIN:
    print(f'== {tag}: um ({x1:.2f},{y1:.2f})-({x2:.2f},{y2:.2f}) ==')
    box = pya.Box(int(x1 / dbu), int(y1 / dbu), int(x2 / dbu), int(y2 / dbu))
    for li in ly.layer_indexes():
        info = ly.get_info(li)
        it = top.begin_shapes_rec(li)
        hits = []
        while not it.at_end():
            sh = it.shape()
            if not sh.is_text():
                r = sh.bbox()
                if r.overlaps(box):
                    um = pya.Box(r.left * dbu, r.bottom * dbu, r.right * dbu, r.top * dbu)
                    hits.append(f'{info.layer}/{info.datatype} ({um.left:.3f},{um.bottom:.3f})-({um.right:.3f},{um.top:.3f}) {um.width():.3f}x{um.height():.3f}')
            it.next()
        for h in hits[:14]:
            print('   ', h)
        if len(hits) > 14:
            print(f'    ... {len(hits)-14} more on {info.layer}/{info.datatype}')
print('PROBE_DONE')
