#!/usr/bin/env bash
# Native WSL2 cocotb runner (no Docker). Windows PATH is NOT imported.
export WSLENV=
export PATH="$HOME/.venvs/cocotb2/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"
export LIBPYTHON_LOC=/nix/store/7hnr99nxrd2aw6lghybqdmkckq60j6l9-python3-3.11.9/lib/libpython3.11.so.1.0
cd /work/test || exit 3
MODULE="${1:-tb_rtr}"
make "MODULE=$MODULE"
rc=$?
echo "RC=$rc"
exit $rc
