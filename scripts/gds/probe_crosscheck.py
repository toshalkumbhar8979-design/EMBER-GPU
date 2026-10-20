# Decisive cross-check: read fpu4.gds twice (fresh Layout each), run both
# probe logics, and print iterator transform + owning cell for every shape.
import pya

PATH = '/work/build/gds/fpu4/fpu4.gds'

def probe_a(tag):
    ly = pya.Layout(); ly.read(PATH)
    top = ly.top_cell(); dbu = ly.dbu
    print(f'[{tag}] top={top.name} dbu={dbu}')
    idx = ly.find_layer(pya.LayerInfo(71, 20))
    it = top.begin_shapes_rec(idx)
    box = pya.Box(int(197.5/dbu), int(960/dbu), int(203/dbu), int(965/dbu))
    n = 0
    while not it.at_end():
        sh = it.shape()
        if not sh.is_text():
            r = sh.bbox()
            if r.overlaps(box):
                try:
                    trans = it.trans()
                    disp = trans.disp
                    print(f'[{tag}] A-shape cell_offset=({disp.x*dbu:.3f},{disp.y*dbu:.3f}) abs=({r.left*dbu:.3f},{r.bottom*dbu:.3f})-({r.right*dbu:.3f},{r.top*dbu:.3f})')
                except Exception as e:
                    print(f'[{tag}] A-shape (no trans: {e}) abs=({r.left*dbu:.3f},{r.bottom*dbu:.3f})-({r.right*dbu:.3f},{r.top*dbu:.3f})')
                n += 1
                if n > 6: break
        it.next()
    if n == 0:
        print(f'[{tag}] A: no hits')

def probe_b(tag):
    ly = pya.Layout(); ly.read(PATH)
    top = ly.top_cell(); dbu = ly.dbu
    print(f'[{tag}] top={top.name} dbu={dbu}')
    idx = ly.find_layer(pya.LayerInfo(71, 20))
    it = top.begin_shapes_rec(idx)
    box = pya.Box(int(197.5/dbu), int(960/dbu), int(203/dbu), int(965/dbu))
    n = 0
    while not it.at_end():
        sh = it.shape()
        if not sh.is_text():
            r = sh.bbox()
            if r.overlaps(box):
                try:
                    trans = it.trans()
                    disp = trans.disp
                    print(f'[{tag}] B-shape cell_offset=({disp.x*dbu:.3f},{disp.y*dbu:.3f}) abs=({r.left*dbu:.3f},{r.bottom*dbu:.3f})-({r.right*dbu:.3f},{r.top*dbu:.3f})')
                except Exception as e:
                    print(f'[{tag}] B-shape (no trans: {e}) abs=({r.left*dbu:.3f},{r.bottom*dbu:.3f})-({r.right*dbu:.3f},{r.top*dbu:.3f})')
                n += 1
                if n > 6: break
        it.next()
    if n == 0:
        print(f'[{tag}] B: no hits')

probe_a('pass1')
probe_b('pass2')
print('CROSSCHECK_DONE')
