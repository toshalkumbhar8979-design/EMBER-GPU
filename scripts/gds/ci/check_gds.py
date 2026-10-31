#!/usr/bin/env python3
"""Stream a GDS file and prove it is structurally complete.

`klayout Layout.read()` on a routed core needs several GB just to hold the
polygons, and the finalize rewrite that used to do this was OOM-killed on a
16 GB runner (2026-10-31). Truncation is the failure mode that actually bit us
(KLayout DEF->GDS died at 254 MB and `Layout.read` then raised
"Unexpected end-of-file"), and that can be detected without loading geometry:
walk the GDSII record stream with a small sliding buffer and require it to end
with ENDLIB.

The verdict is always written to the JSON file, because the shell gate greps
it: a nonzero exit status is not trustworthy everywhere (the local WSL
interpreter returns 0 even for sys.exit(3)).

Usage: check_gds.py <file.gds> [out.json]
"""
import json
import os
import sys

HEADER, ENDLIB = 0x00, 0x04
CHUNK = 1 << 20


def scan(path):
    """Return (records, endlib_offset) or raise ValueError on a bad stream."""
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
                    raise ValueError(f"bad record length {length} at {pos + i}")
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
        raise ValueError(f"TRUNCATED: {len(buf)} byte(s) of a partial record at {pos}")
    if records == 0 or first != HEADER:
        raise ValueError("not a GDSII stream (no HEADER record)")
    if endlib_at is None:
        raise ValueError("TRUNCATED: no ENDLIB record")
    return records, endlib_at


def main():
    path = sys.argv[1]
    out = sys.argv[2] if len(sys.argv) > 2 else ""
    info = {"file": os.path.basename(path), "bytes": os.path.getsize(path)}
    try:
        records, endlib_at = scan(path)
    except (ValueError, OSError) as exc:
        info.update({"complete": False, "error": str(exc)})
        status = f"GDS REJECTED: {exc}"
        rc = 1
    else:
        info.update({"records": records, "endlib_offset": endlib_at,
                     "complete": True})
        status = (f"GDS complete: {info['file']} {info['bytes']} bytes, "
                  f"{records} records")
        rc = 0
    if out:
        with open(out, "w") as fh:
            json.dump(info, fh, indent=2)
    print(status, file=sys.stdout if rc == 0 else sys.stderr)
    return rc


if __name__ == "__main__":
    sys.exit(main())
