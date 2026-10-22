#!/usr/bin/env bash
# Render one Doom frame through the Ember GPU golden model and convert to PNG.
set -u
cd "$(dirname "$0")/.." || exit 1
out="${1:-test/new.ppm}"
png="${2:-test/new.png}"
time python3 tools/golden/doom_real.py --shot "$out"
python3 tools/golden/ppm_png.py "$out" "$png"
