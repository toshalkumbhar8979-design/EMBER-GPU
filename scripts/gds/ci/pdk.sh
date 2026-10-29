#!/usr/bin/env bash
# pdk.sh -- put sky130A where the flow expects it, on a GitHub runner.
#
# The OpenLane container ships OpenROAD/Yosys/Magic/KLayout but NOT a PDK, so
# the workflow installs it once with volare and caches ~/.volare between runs
# (1.1 GB). Pinned to the exact build this project's local runs used, so CI and
# local results are comparable.
set -euo pipefail
VERSION=${SKY130_VERSION:-fa87f8f4bbcc7255b6f0c0fb506960f531ae2392}
ROOT=${PDK_ROOT:-$HOME/.volare}
PDK_A="$ROOT/volare/sky130/versions/$VERSION/sky130A"

if [ -d "$PDK_A" ]; then
  echo "PDK cache hit: $PDK_A"
else
  echo "PDK not cached; installing sky130 $VERSION with volare"
  VENV="${RUNNER_TEMP:-/tmp}/volare-venv"
  python3 -m venv "$VENV"
  "$VENV/bin/pip" install --quiet --disable-pip-version-check volare
  TOKEN_ARGS=()
  [ -n "${GITHUB_TOKEN:-}" ] && TOKEN_ARGS=(-t "$GITHUB_TOKEN")
  "$VENV/bin/volare" enable --pdk sky130 --pdk-root "$ROOT" "${TOKEN_ARGS[@]}" "$VERSION"
fi

[ -d "$PDK_A" ] || { echo "PDK INSTALL FAILED: $PDK_A missing"; exit 1; }
echo "PDK ready: $PDK_A"
if [ -n "${GITHUB_ENV:-}" ]; then
  echo "GDS_PDK=$PDK_A" >> "$GITHUB_ENV"
fi
