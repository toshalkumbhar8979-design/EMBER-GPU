# Hierarchical raw GDS parser v2: pruned recursive expansion attributing
# via4/met4/met5 shapes near the DRC sites to instance paths.
import struct
from collections import defaultdict

PATH = '/work/build/gds/fpu4/fpu4.gds'
TARGETS = {(71, 44): 'via4', (71, 20): 'met4', (72, 20): 'met5'}
WIN = {
 'SITE_V': (197_000, 960_000, 203_500, 965_500),
 'SITE_M': (1579_000, 568_500, 1591_000, 582_000),
}
PRUNE = 400_000   # 400um origin-distance prune for child instances

def rec_iter(buf):
    i, n = 0, len(buf)
    while i + 4 <= n:
        ln = struct.unpack('>H', buf[i:i+2])[0]
        if ln == 0: break
        typ = struct.unpack('>H', buf[i+2:i+4])[0]
        yield typ, buf[i+4:i+ln]
        i += ln

buf = open(PATH, 'rb').read()
cells = {}
cur = None
elem = None

def fin_elem():
    global elem
    if elem is None: return
    k = elem[0]
    if k == 'B':
        pts = elem[3]
        if pts:
            xs = [p[0] for p in pts]; ys = [p[1] for p in pts]
            cells[cur]['shapes'][(elem[1], elem[2])].append((min(xs), min(ys), max(xs), max(ys)))
    elif k == 'S' and elem[1]:
        cells[cur]['srefs'].append((elem[1], elem[2][0][0], elem[2][0][1], elem[3], elem[4]))
    elif k == 'A' and elem[1] and elem[5]:
        pts = elem[2]
        if len(pts) >= 3:
            cells[cur]['arefs'].append((elem[1], pts[0], pts[1], pts[2], elem[3], elem[4], elem[5]))
    elem = None

strname = None
for typ, data in rec_iter(buf):
    if typ == 0x0606:
        strname = data.rstrip(b'\x00').decode('ascii', 'replace')
        cells[strname] = {'shapes': defaultdict(list), 'srefs': [], 'arefs': []}
        cur = strname
    elif typ == 0x0700:
        cur = None
    elif cur is None:
        continue
    elif typ == 0x0800:
        fin_elem(); elem = ['B', None, None, []]
    elif typ == 0x0A00:
        fin_elem(); elem = ['S', None, [], False, 0.0]
    elif typ == 0x0B00:
        fin_elem(); elem = ['A', None, [], False, 0.0, None]
    elif typ == 0x1206 and elem is not None:
        elem[1] = data.rstrip(b'\x00').decode('ascii', 'replace')
    elif typ == 0x0D02 and elem is not None and elem[0] == 'B':
        elem[1] = struct.unpack('>h', data[:2])[0]
    elif typ == 0x0E02 and elem is not None and elem[0] == 'B':
        elem[2] = struct.unpack('>h', data[:2])[0]
    elif typ == 0x1A01 and elem is not None and elem[0] in ('S', 'A'):
        elem[3] = bool(struct.unpack('>H', data[:2])[0] & 0x8000)
    elif typ == 0x1C05 and elem is not None and elem[0] in ('S', 'A'):
        elem[4] = struct.unpack('>d', data)[0]
    elif typ == 0x1302 and elem is not None and elem[0] == 'A':
        elem[5] = struct.unpack('>2h', data[:4])
    elif typ == 0x1003 and elem is not None:
        vals = struct.unpack(f'>{len(data)//4}i', data)
        pts = list(zip(vals[0::2], vals[1::2]))
        if elem[0] == 'B':
            elem[3] = pts
        else:
            elem[2] = pts
    elif typ == 0x1100:
        fin_elem()

print(f'cells parsed: {len(cells)}')

def xf(px, py, refl, ang):
    if refl: py = -py
    a = int(round(ang)) % 360
    if a == 90:  px, py = -py, px
    elif a == 180: px, py = -px, -py
    elif a == 270: px, py = py, -px
    return px, py

def rot_box(b, dx, dy, refl, ang):
    x1, y1, x2, y2 = b
    if refl: y1, y2 = -y2, -y1
    a = int(round(ang)) % 360
    if a == 90:   cs = [(-y1, x1), (-y2, x1), (-y2, x2), (-y1, x2)]
    elif a == 180: cs = [(-x1, -y1), (-x2, -y1), (-x2, -y2), (-x1, -y2)]
    elif a == 270: cs = [(y1, -x1), (y2, -x1), (y2, -x2), (y1, -x2)]
    else:          cs = [(x1, y1), (x2, y1), (x2, y2), (x1, y2)]
    xs = [c[0] + dx for c in cs]; ys = [c[1] + dy for c in cs]
    return (min(xs), min(ys), max(xs), max(ys))

referenced = set()
for c in cells.values():
    for s in c['srefs']: referenced.add(s[0])
    for a in c['arefs']: referenced.add(a[0])

def expand(site, wx1, wy1, wx2, wy2):
    cxw, cyw = (wx1+wx2)//2, (wy1+wy2)//2
    found = []
    def visit(cname, dx, dy, refl, ang, path, depth):
        if depth > 10 or cname not in cells: return
        c = cells[cname]
        for (L, dtc), boxes in c['shapes'].items():
            if (L, dtc) not in TARGETS: continue
            for b in boxes:
                rb = rot_box(b, dx, dy, refl, ang)
                if rb[0] <= wx2 and rb[2] >= wx1 and rb[1] <= wy2 and rb[3] >= wy1:
                    found.append((TARGETS[(L, dtc)], rb, path))
        for (sname, sx, sy, srefl, sang) in c['srefs']:
            px, py = xf(sx, sy, refl, ang)
            gx, gy = dx + px, dy + py
            if abs(gx - cxw) > PRUNE or abs(gy - cyw) > PRUNE: continue
            r2 = srefl != refl
            a2 = (ang + (sang if not refl else -sang)) % 360
            visit(sname, gx, gy, r2, a2, path + '/' + sname, depth + 1)
        for (sname, p0, p1, p2, srefl, sang, colrow) in c['arefs']:
            ncols, nrows = colrow
            q0 = xf(p0[0], p0[1], refl, ang)
            q1 = xf(p1[0], p1[1], refl, ang)
            q2 = xf(p2[0], p2[1], refl, ang)
            col_step = ((q1[0]-q0[0])//max(ncols,1), (q1[1]-q0[1])//max(ncols,1))
            row_step = ((q2[0]-q0[0])//max(nrows,1), (q2[1]-q0[1])//max(nrows,1))
            for i in range(ncols):
                for j in range(nrows):
                    gx = dx + q0[0] + col_step[0]*i + row_step[0]*j
                    gy = dy + q0[1] + col_step[1]*i + row_step[1]*j
                    if abs(gx - cxw) > PRUNE or abs(gy - cyw) > PRUNE: continue
                    r2 = srefl != refl
                    a2 = (ang + (sang if not refl else -sang)) % 360
                    visit(sname, gx, gy, r2, a2, f'{path}/A:{sname}[{i},{j}]', depth + 1)
    for name in cells:
        if name not in referenced:
            visit(name, 0, 0, False, 0.0, name, 0)
    return found

for site, (wx1, wy1, wx2, wy2) in WIN.items():
    found = expand(site, wx1, wy1, wx2, wy2)
    print(f'== {site}: {len(found)} in-window target shapes ==')
    for (lay, (x1, y1, x2, y2), path) in sorted(found, key=lambda t: (t[0], t[1][0])):
        print(f'  {lay} ({x1/1000:.3f},{y1/1000:.3f})-({x2/1000:.3f},{y2/1000:.3f}) {(x2-x1)/1000:.3f}x{(y2-y1)/1000:.3f} | {path}')
print('HIER2_DONE')
