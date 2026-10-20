# Smoke-test battery

Fast checks to run before/after any RTL or flow change. Everything here is
seconds-to-minutes; the full cocotb suites and GDS audits are the deep tier.
All commands run from WSL with the project at `/work` (sync first:
`cp /mnt/c/Users/tosha/Downloads/GPU/<changed files> /work/...`).

## Tier 0 — golden model self-checks (seconds, no RTL)

| Command | Checks | Last verified |
|---|---|---|
| `python3 tools/golden/fpu_smoke.py` | fp32 golden vs struct-based FPU math | PASS (exit 0) |
| `python3 tools/golden/test_raster_golden.py` | golden rasterizer smoke | PASS (exit 0) |
| `python3 tools/golden/scene_selftest.py` | golden scene/frame self-test | PASS (exit 0) |

## Tier 1 — RTL simulation (cocotb 2.x + Verilator, `test/run_cocotb.sh`)

`bash test/run_cocotb.sh <module>` runs one bench with the pinned env
(venv `cocotb2`, native WSL2 Verilator). Minimum battery:

* `tb_memory` — VRAM/AXI slave round-trip (the "does the core bus work" smoke)
* `tb_fpu` via `cd test && make -f Makefile.fpu` — Phase-4 FPU
* `tb_rtr` (default module) — raster/ROP chain golden smokes

Deep tier: `cd test && make` runs all 17 `tb_*` modules of the Phase-1
suite; `make -f Makefile.chip` (4/4 passing) and `make -f Makefile.memif`
(6/6 passing) cover the chip through the pads and the memory controller.

## Tier 2 — GDS flow audits (after physical changes)

| Command | Checks |
|---|---|
| `python3 scripts/gds/verify_block.py <block>` | content audit: zero-routing/DRC GDS |
| `python3 scripts/gds/make_pad_ring.py --check` | pinout vs RTL cross-check |
| `python3 scripts/gds/check_macro_interfaces.py ...` | macro pin interfaces vs wrapper |

Block audits pass only on content-checked artifacts — a build that is still
computing is reported FAIL/incomplete, never silently skipped.
