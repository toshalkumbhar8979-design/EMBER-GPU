#!/usr/bin/env bash
# pnr_env.sh — run the block flow natively in WSL with the nix toolchain.
#
# The openlane container in this VM has no PDK mount (/home/toshal does not
# exist inside it), but the host has both the tools (in /nix/store) and the
# sky130 PDK (~/.volare). So the flow runs here, natively, exactly as
# ember_autostart.sh used to set it up.
#
#   bash test/pnr_env.sh <name> <top> <verilog...>
set -eu
OPENROAD=$(ls -d /nix/store/*-openroad/bin 2>/dev/null | head -1)
MAGIC=$(ls -d /nix/store/*-magic-vlsi/bin 2>/dev/null | head -1)
KLAYOUT=$(ls -d /nix/store/*-klayout/bin 2>/dev/null | head -1)
[ -n "$OPENROAD" ] && [ -n "$MAGIC" ] || { echo "TOOLS NOT FOUND in /nix/store"; exit 3; }

export HOME=/home/toshal
export PATH="$OPENROAD:$MAGIC:$KLAYOUT:/usr/local/bin:/usr/bin:/bin"
export PDK_ROOT="$HOME/.volare/volare"
export OPENROAD_EXE="$OPENROAD/openroad"

cd /work
echo "== tools: openroad=$OPENROAD magic=$MAGIC"
echo "== pdk:   $(ls -d "$PDK_ROOT"/sky130/versions/*/sky130A | head -1)"
exec bash /work/scripts/gds/harden_block.sh "$@"
