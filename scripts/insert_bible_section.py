#!/usr/bin/env python3
"""Insert the 2026-10-04 checkpoint section into agentbible.md (native copy),
then the caller mirrors the file back to /mnt/c."""
import re
import sys

SECTION = """
### probe_p_8 ROOT CAUSE + rtr_scan RTL restructure (2026-10-04 early AM)
- **fpu4/gsx Magic DRC root cause SOLVED**: DRC_COUNT=3 (2x via4.2 + 1x met4.2)
  was NOT pdngen pitch. Evidence chain: DRC lambda boxes (x0.005 -> um) sit on
  VPWR met4 x met5 stripe crossings; a raw GDS record parser + hierarchical
  attribution (scripts/gds/parse_gds_hier.py; NOTE pya readings proved
  unreliable on this file: one run read the stripe 1.0um wide, raw bytes + ODB
  both say 1.6um) showed the colliding shapes belong to
  sky130_fd_sc_hd__probe_p_8 instances = OpenROAD repair_design
  load_slew*/max_cap* measurement cells (37 in fpu4). The master carries
  met4/met5 PAD geometry and has NO OBS in LEF -> invisible to pdngen; probe
  pad landed 0.11um from the VPWR stripe (<0.3um met4.2). Synthesis NEVER
  emits this master (0 hits in every synth cache).
- **FIX (harden_block.sh, in effect)**: set_dont_use
  {sky130_fd_sc_hd__probe_p_8} right after set_wire_rc, before
  repair_design/CTS. Salvage alternative abandoned: ODB swapMaster
  (probe->decap_12, footprint-identical 5.52x2.72 PG-only fill) SEGFAULTS in
  this openroad build; textual DEF master-rename patch worked (37 swaps) but
  the fpu4 rescue died because the doomed gsx attempt clobbered fpu4's
  openroad.log (route evidence unrecoverable -> honest queue rebuild instead).
- **THREE nearly-fatal process lessons** (all fixed): (1) ALWAYS tr-sync
  /mnt/c -> /work after editing flow scripts - run_cached's
  prepare_cached_flow.py reads the NATIVE harden_block.sh; a stale snapshot
  silently re-created probe cells and forced a gsx restart. (2) Flows MUST
  launch via /work/run_flow_env.sh wrapper (emberbin PATH first:
  openroad/yosys/magic/klayout + python3-with-pya+psutil); bare setsid lost
  PATH and the queue burned through blocks in minutes ("openroad: No such
  file", ModuleNotFoundError psutil). (3) run_cached.sh DELETES block-dir
  artifacts on rebuild - never park backups inside build/gds/<name>/
  (final.def.preprobe etc. were wiped).
- **cocotb NATIVE regression operational**: venv ~/.venvs/cocotb2 (nix py3.11
  base), LIBPYTHON_LOC=/nix/store/7hnr99nxrd2aw6lghybqdmkckq60j6l9-python3-3.11.9/lib/libpython3.11.so.1.0,
  runner /work/test/run_cocotb.sh, test/Makefile carries -Wno-WIDTHEXPAND
  (verilator 5.046 stricter; ember_core.sv:475 benign const-width). Baseline
  AND post-restructure: TESTS=4 PASS=4 FAIL=0.
- **rtr_scan hierarchical-synthesis restructure LANDED, bit-exact proven**:
  rtl/ember_rtr_scan.sv now has _rtr_smul96 (20 instances: 6 edge + 14
  plane-eval) and _rtr_sdiv96 (2 instances) as synthesis roots; peval/pdiv
  functions replaced by module-scope fabrics (SV forbids instances inside
  functions; operands/timing unchanged - same registered inputs). Traps
  re-learned: >>> must stay isolated in its own assignment (a concat sibling
  forces unsigned context -> logical shift -> solid_gradient 27k pixel
  mismatches until fixed); pdiv always_comb needs unconditional defaults
  (Verilator LATCH). TODO before queue reaches rtr_scan: regen
  build/gds/rtr_scan.v with ~/bin/sv2v (original flat kept as
  rtr_scan.v.orig_flat; flat synth cache is stale the moment rtr_scan.v
  changes - validate_synth will force resynth, which is why the hierarchical
  rtr_top-pattern plan for rtr_scan/siblings is still the endgame).
- **Queue state after this session**: fpu4 + gsx lines ACTIVE in blocks.txt;
  queue relaunched via run_flow_env.sh with the fixed snapshot; fpu4
  rebuilding first (intact synth cache 101,131 cells reused; PnR fresh with
  no probe cells possible). Expect Magic DRC_COUNT=0 this time; gsx rebuild
  follows (same fix); then tu, core, rtr_setup/cp KEEP, die stage.
"""

ANCHOR = '### Freebuff/WSL restart recovery + parallel fpu4-salvage/gsx (2026-10-03 morning)'
path = '/work/agentbible.md'
text = open(path).read()
assert ANCHOR in text, 'anchor missing'
assert 'probe_p_8 ROOT CAUSE' not in text, 'section already present'
text = text.replace(ANCHOR, SECTION.strip('\n') + '\n\n' + ANCHOR, 1)
open(path, 'w').write(text)
print('INSERTED at anchor; new size:', len(text))
