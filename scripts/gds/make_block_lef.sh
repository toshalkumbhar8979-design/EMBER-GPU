#!/usr/bin/env bash
# make_block_lef.sh <name> -- abstract a hardened block's final.def into a
# macro LEF (CLASS BLOCK + PINS) for top-level die integration.
# Run INSIDE the openlane2 container. Reads the block's own final.def so the
# LEF pin geometry matches the routed block exactly.
set -o pipefail
NAME=$1
PDK=$(ls -d $HOME/.volare/volare/sky130/versions/*/sky130A 2>/dev/null | head -1)
[ -n "$PDK" ] || { echo "PDK NOT FOUND"; exit 3; }
OUT=/work/build/gds/$NAME
[ -f "$OUT/final.def" ] || { echo "no final.def for $NAME"; exit 1; }
TECH=$PDK/libs.ref/sky130_fd_sc_hd/techlef/sky130_fd_sc_hd__nom.tlef
STDLIB=$PDK/libs.ref/sky130_fd_sc_hd/lef/sky130_fd_sc_hd.lef

openroad -no_init -exit <<EOF > "$OUT/lef.log" 2>&1
read_lef $TECH
read_lef $STDLIB
read_def $OUT/final.def
write_lef $OUT/$NAME.lef
EOF
RC=$?
if [ $RC -ne 0 ] || [ ! -s "$OUT/$NAME.lef" ]; then
  echo "LEF FAIL $NAME"; tail -5 "$OUT/lef.log"; exit 1
fi
echo "LEF OK $NAME ($(stat -c %s $OUT/$NAME.lef) bytes)"
