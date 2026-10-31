#!/usr/bin/env python3
"""Stream a GDS file and prove it is structurally complete.

`klayout Layout.read()` on a routed core needs several GB just to hold the
polygons, and the finalize rewrite that used to do this was OOM-killed on a
16 GB runner (2026-10-31). Truncation is the failure mode that actually bit us
(KLayout DEF->GDS died at 254 MB and `Layout.read` then raised
"Unexpected end-of-file"), and that can be detected without loading geometry:
walk the GDSII record stream with a small sliding buffer and require it to end
with ENDLIB.

Usage: check_gds.py <file.gds> [out.json]
Exits 1 on a truncated or non-GDSII stream.
"""
import json
import os
import sys

path = sys.argv[1]
out = sys.argv[2] if len(sys.argv) > 2 else ""
HEADER, ENDLIB = 0x00, 0x04
CHUNK = 1 << 20

buf = b""
records = 0
first = None
endlib_at = None
pos = 0  # absolute offset of buf[0]

with open(path, "rb") as fh:
    while True:
        chunk = fh.read(CHUNK)
        if not chunk:
            break
        buf += chunk
        i = 0
        while True:
            if len(buf) - i < 4:
                break
            length = (buf[i] << 8) | buf[i + 1]
            if length < 4:
                raise SystemExit(f"bad record length {length} at {pos + i}")
            if len(buf) - i < length:
                break
            rtype = buf[i + 2]
            if first is None:
                first = rtype
            records += 1
            if rtype == ENDLIB:
                endlib_at = pos + i
            i += length
        buf = buf[i:]
        pos += i

if buf:
    raise SystemExit(f"TRUNCATED: {len(buf)} byte(s) of a partial record at {pos}")
if records == 0 or first != HEADER:
    raise SystemExit("not a GDSII stream (no HEADER record)")
if endlib_at is None:
    raise SystemExit("TRUNCATED: no ENDLIB record")

info = {
    "file": os.path.basename(path),
    "bytes": os.path.getsize(path),
    "records": records,
    "endlib_offset": endlib_at,
    "complete": True,
}
print("GDS complete:", info["file"], info["bytes"], "bytes,", records, "records")
if out:
    with open(out, "w") as fh:
        json.dump(info, fh, indent=2)
