# Ground-truth GDS record parser (no pya): walks raw records and prints
# every BOUNDARY on given (layer, datatype) whose bbox intersects the
# requested windows. Settles what the FILE actually contains.
import struct, sys

PATH = '/work/build/gds/fpu4/fpu4.gds'
TARGETS = {(71, 20): 'met4', (71, 44): 'via4', (72, 20): 'met5'}
WINDOWS = [
    ('SITE_V', 197_500, 960_000, 203_000, 965_000, 194_500, 957_000, 206_000, 968_000),
    ('SITE_M', 1582_000, 571_500, 1588_000, 579_000, 1579_000, 568_500, 1591_000, 582_000),
]

REC = {0x0002: 'HEADER', 0x0102: 'BGNLIB', 0x0206: 'LIBNAME', 0x0305: 'UNits',
       0x0400: 'ENDLIB', 0x0502: 'BGNSTR', 0x0606: 'STRNAME', 0x0700: 'ENDSTR',
       0x0800: 'BOUNDARY', 0x0900: 'PATH', 0x0B00: 'TEXT', 0x0C00: 'LAYER',
       0x0D02: 'DATATYPE', 0x0E03: 'WIDTH', 0x1003: 'XY', 0x1100: 'ENDEL',
       0x1206: 'SNAME', 0x1500: 'ENDS', 0x1606: 'COLROW', 0x1705: 'REFLIBS',
       0x1806: 'FONTS', 0x1906: 'PRESENTATION', 0x1c05: 'STRANS'}

def rec_iter(buf):
    i = 0
    n = len(buf)
    while i + 4 <= n:
        ln = struct.unpack('>H', buf[i:i+2])[0]
        if ln == 0:
            break
        typ = struct.unpack('>H', buf[i+2:i+4])[0]
        data = buf[i+4:i+ln]
        yield typ, data
        i += ln
    if i != n:
        print(f'WARN trailing {n-i} bytes', file=sys.stderr)

buf = open(PATH, 'rb').read()
print(f'file: {len(buf)} bytes')

cur_elem = None      # dict in progress
cur_str = '?'
layer = dt = None
counts = {}
hits = {'SITE_V': [], 'SITE_M': []}
in_windows = False

def try_finish(elem):
    for name, wx1, wy1, wx2, wy2, wx1b, wy1b, wx2b, wy2b in WINDOWS:
        box = elem
        if (box[0] <= wx2 and box[2] >= wx1 and box[1] <= wy2 and box[3] >= wy1) or \
           (box[0] <= wx2b and box[2] >= wx1b and box[1] <= wy2b and box[3] >= wy1b):
            hits[name].append(box)

for typ, data in rec_iter(buf):
    if typ == 0x0800:            # BOUNDARY
        cur_elem = {'pts': []}
        layer = dt = None
    elif typ == 0x0D02:          # LAYER (empirically: data-carrying, first)
        layer = struct.unpack('>h', data[:2])[0]
    elif typ == 0x0E02:          # DATATYPE
        dt = struct.unpack('>h', data[:2])[0]
    elif typ == 0x1003:          # XY
        if cur_elem is not None:
            vals = struct.unpack(f'>{len(data)//4}i', data)
            xs = vals[0::2]; ys = vals[1::2]
            cur_elem['pts'] = list(zip(xs, ys))
    elif typ == 0x1100:          # ENDEL
        if cur_elem is not None:
            key = (layer, dt)
            counts[key] = counts.get(key, 0) + 1
            if key in TARGETS and cur_elem['pts']:
                xs = [p[0] for p in cur_elem['pts']]
                ys = [p[1] for p in cur_elem['pts']]
                b = (min(xs), min(ys), max(xs), max(ys))
                try_finish(b)
        cur_elem = None
    elif typ == 0x0606:          # STRNAME
        pass

for k in sorted(counts, key=lambda t: (t[0], t[1])):
    print(f'count {k}: {counts[k]}')

for name in ('SITE_V', 'SITE_M'):
    print(f'== {name}: {len(hits[name])} matching boundaries ==')
    for b in hits[name][:20]:
        print(f'  ({b[0]/1000:.3f},{b[1]/1000:.3f})-({b[2]/1000:.3f},{b[3]/1000:.3f}) um  {(b[2]-b[0])/1000:.3f}x{(b[3]-b[1])/1000:.3f}')
print('PARSE_DONE')
