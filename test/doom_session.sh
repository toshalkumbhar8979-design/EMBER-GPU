#!/usr/bin/env bash
# test/doom_session.sh — play Doom on the Ember RTL, frame after frame.
#
#   DOOM_FRAMES=20 DOOM_WORKERS=5 bash test/doom_session.sh
#
# Every frame takes the full hardware path (CP DMA -> ember_rtr_top ->
# debug-port readback) and is timed on the sim clock. Frames are independent
# because each one clears FB and Z first, so the session is split into
# contiguous slices that run on DOOM_WORKERS simulator processes in parallel;
# the timings are merged into $DOOM_OUT/metrics.json at the end.
#
# Output: $DOOM_OUT/frames/doom_XXXX.ppm  +  $DOOM_OUT/metrics.json
# (encode it with:  python test/doom_video.py --session <that dir>)
#
# Needs one build first:  cd test && make MODULE=tb_doom_demo
set -u

HERE=$(cd "$(dirname "$0")" && pwd)
export WSLENV=
export PATH="$HOME/.venvs/cocotb2/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"
export LIBPYTHON_LOC=/nix/store/7hnr99nxrd2aw6lghybqdmkckq60j6l9-python3-3.11.9/lib/libpython3.11.so.1.0
export GPI_USERS="$LIBPYTHON_LOC;$HOME/.venvs/cocotb2/lib/python3.11/site-packages/cocotb/simulator.cpython-311-x86_64-linux-gnu.so,initialize"
export PYGPI_PYTHON_BIN="$HOME/.venvs/cocotb2/bin/python3"
export COCOTB_TEST_MODULES=tb_doom_demo
export COCOTB_TOPLEVEL=ember_top
export PYTHONPATH="$HERE"

FRAMES=${DOOM_FRAMES:-20}
WORKERS=${DOOM_WORKERS:-5}
STEP=${DOOM_STEP:-24}
OUT=${DOOM_OUT:-$HERE/demo_frames}
VTOP=$HERE/sim_build/Vtop

if [ ! -x "$VTOP" ]; then
  echo "no simulator at $VTOP -- build it once with:" >&2
  echo "    (cd $HERE && make MODULE=tb_doom_demo)" >&2
  exit 3
fi

rm -rf "$OUT"
mkdir -p "$OUT/frames"

per=$(( (FRAMES + WORKERS - 1) / WORKERS ))
echo "EMBER SESSION: $FRAMES frames of E1M1 on $WORKERS simulators -> $OUT"
t0=$(date +%s)
pids=""
for w in $(seq 0 $((WORKERS - 1))); do
  s=$(( w * per ))
  [ "$s" -ge "$FRAMES" ] && continue
  c=$per
  [ $(( s + c )) -gt "$FRAMES" ] && c=$(( FRAMES - s ))
  d="$OUT/w$w"
  mkdir -p "$d"
  (
    cd "$d" || exit 1
    DOOM_FRAMES=$FRAMES DOOM_STEP=$STEP DOOM_START=$s DOOM_COUNT=$c \
      DOOM_OUT=$OUT "$VTOP" > "$d/run.log" 2>&1
  ) &
  pids="$pids $!"
  echo "  worker $w -> frames $s..$(( s + c - 1 ))"
done

fail=0
for p in $pids; do
  wait "$p" || fail=1
done
wall=$(( $(date +%s) - t0 ))

if [ "$fail" != 0 ]; then
  echo "a simulator failed; see $OUT/w*/run.log" >&2
  tail -n 5 "$OUT"/w*/run.log 2>/dev/null | tail -40 >&2
  exit 1
fi

python3 - "$OUT" "$FRAMES" "$wall" <<'PY'
import glob
import json
import os
import sys

out, want, wall = sys.argv[1], int(sys.argv[2]), int(sys.argv[3])
frames = []
for p in sorted(glob.glob(os.path.join(out, "metrics_part_*.json"))):
    with open(p) as fh:
        frames += json.load(fh)["frames"]
frames.sort(key=lambda r: r["frame"])
got = [r["frame"] for r in frames]
if got != list(range(want)):
    sys.exit(f"session incomplete: {len(got)}/{want} frames")

ms = [r["gpu_ms"] for r in frames]
fps = [r["fps"] for r in frames]
tris = sum(r["tris"] for r in frames)
sim_ms = sum(r["gpu_ns"] for r in frames) / 1e6
summary = {
    "frames": len(frames),
    "mean_frame_ms": round(sim_ms / len(frames), 3),
    "min_frame_ms": round(min(ms), 3),
    "max_frame_ms": round(max(ms), 3),
    "mean_fps": round(len(frames) / (sim_ms / 1000.0), 2),
    "best_fps": round(max(fps), 2),
    "worst_fps": round(min(fps), 2),
    "mean_tris_per_frame": round(tris / len(frames), 1),
    "total_tris": tris,
    "tris_per_s": int(round(tris / (sim_ms / 1000.0))),
    "mean_cycles_per_frame": int(sum(r["cycles"] for r in frames) / len(frames)),
    "resolution": [320, 240],
    "pixels_per_frame": 320 * 240,
    "fill_px_per_s": int(round(320 * 240 * len(frames) / (sim_ms / 1000.0))),
    "session_sim_ms": round(sim_ms, 1),
    "session_wall_s": wall,
    "sim_realtime_factor": round(sim_ms / 1000.0 / wall, 5),
}
doc = {
    "gpu": {"name": "EMBER GPU (ember_rtr_top in Verilator)",
            "clock_mhz": 50.0, "resolution": [320, 240],
            "map": "E1M1", "wad": "data/doom1.wad",
            "pipeline": "CP DMA -> RTR -> RGB565 framebuffer"},
    "frames": frames,
    "summary": summary,
}
with open(os.path.join(out, "metrics.json"), "w") as fh:
    json.dump(doc, fh, indent=1)

s = summary
print(f"EMBER SESSION: {s['frames']} frames, "
      f"{s['mean_frame_ms']:.2f} ms/frame = {s['mean_fps']:.2f} fps "
      f"(best {s['best_fps']:.2f}, worst {s['worst_fps']:.2f})")
print(f"  {s['mean_tris_per_frame']:.0f} tris/frame, "
      f"{s['mean_cycles_per_frame']:,} cycles/frame @ 50 MHz, "
      f"{s['tris_per_s']:,} tris/s, {s['fill_px_per_s']:,} px/s")
print(f"  session sim {s['session_sim_ms'] / 1000:.2f} s in {wall} s wall "
      f"= {s['sim_realtime_factor'] * 100:.2f}% of real time")
print(f"  wrote {os.path.join(out, 'metrics.json')}")
PY
