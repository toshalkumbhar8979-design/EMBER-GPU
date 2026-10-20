# Probe v2: identify Magic-DRC violation locations in fpu4.gds.
# Magic DRC reported (units unknown: nm or lambda=5nm):
#   met4 spacing < 0.3um  boxes near (316.97..317.07, 114.896..115.252)
#   via4 spacing < 0.42um boxes near (39.902..40.138, 192.458..192.524)
# Strategy: dump all layers; probe met4/via4-ish layers around BOTH unit
# interpretations of each violation.
import pya

ly = pya.Layout()
ly.read('/work/build/gds/fpu4/fpu4.gds')
top = ly.top_cell()
dbu = ly.dbu
print('top cell:', top.name, 'dbu:', dbu)
print('== all layers ==')
for i in ly.layer_indexes():
    info = ly.get_info(i)
    print(f'  {info.layer}/{info.datatype}')

def probe(tag, cx_um, cy_um, layers=((71, 20), (72, 20), (72, 44), (71, 44), (70, 44))):
    half = 5.0
    box = pya.Box((cx_um - half) / dbu, (cy_um - half) / dbu, (cx_um + half) / dbu, (cy_um + half) / dbu)
    print(f'== {tag}: window ({cx_um-half:.1f}..{cx_um+half:.1f}, {cy_um-half:.1f}..{cy_um+half:.1f}) um ==')
    for lnum, dt in layers:
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
                    hits.append(f'{lnum}/{dt} ({um.left:.2f},{um.bottom:.2f})-({um.right:.2f},{um.top:.2f}) {um.width():.2f}x{um.height():.2f}')
            it.next()
            if len(hits) >= 12:
                break
        for h in hits:
            print('   ', h)

# met4 violation, nm interpretation
probe('met4 viol @nm', 317.02, 115.05)
# met4 violation, lambda interpretation (x0.005)
probe('met4 viol @lambda', 317.02 * 0.005 * 1000, 115.05 * 0.005 * 1000)
# via4 violation, nm interpretation
probe('via4 viol @nm', 40.02, 192.49)
# via4 violation, lambda interpretation
probe('via4 viol @lambda', 40.02 * 0.005 * 1000, 192.49 * 0.005 * 1000)
