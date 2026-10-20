# Raw shape dump on via4 (71/44) and met4/met5 near SITE V: polygon points
# reveal whether the 1x1um "cut" is actually a union of two offset squares.
import pya

ly = pya.Layout()
ly.read('/work/build/gds/fpu4/fpu4.gds')
top = ly.top_cell()
dbu = ly.dbu

for L, D in [(71, 44), (71, 20), (72, 20)]:
    idx = ly.find_layer(pya.LayerInfo(L, D))
    if idx is None:
        continue
    it = top.begin_shapes_rec(idx)
    print(f'== layer {L}/{D} shapes overlapping SITE V (197.5..203, 960..965) ==')
    box = pya.Box(int(197.5 / dbu), int(960 / dbu), int(203 / dbu), int(965 / dbu))
    while not it.at_end():
        sh = it.shape()
        if not sh.is_text():
            r = sh.bbox()
            if r.overlaps(box):
                print(f'  shape: poly={sh.is_polygon()} simple={sh.is_simple_polygon()} box=({r.left*dbu:.3f},{r.bottom*dbu:.3f})-({r.right*dbu:.3f},{r.top*dbu:.3f})')
                try:
                    if sh.is_polygon():
                        for pt in sh.polygon.each_point_hull():
                            print(f'    pt ({pt.x*dbu:.3f},{pt.y*dbu:.3f})')
                    elif sh.is_simple_polygon():
                        for pt in sh.simple_polygon.each_point_hull():
                            print(f'    pt ({pt.x*dbu:.3f},{pt.y*dbu:.3f})')
                    elif sh.is_box():
                        b = sh.box
                        print(f'    box ({b.left*dbu:.3f},{b.bottom*dbu:.3f})-({b.right*dbu:.3f},{b.top*dbu:.3f})')
                    elif sh.is_path():
                        print(f'    path width={sh.path.width*dbu}')
                except Exception as e:
                    print('    (pt dump failed:', e, ')')
        it.next()
print('DONE')
