#!/usr/bin/env python3
"""Update the 2026-10-04 agentbible section: rtr_scan synth breakthrough."""
path = '/work/agentbible.md'
text = open(path).read()

OLD = """TODO before queue reaches rtr_scan: regen
  build/gds/rtr_scan.v with ~/bin/sv2v (original flat kept as
  rtr_scan.v.orig_flat; flat synth cache is stale the moment rtr_scan.v
  changes - validate_synth will force resynth, which is why the hierarchical
  rtr_top-pattern plan for rtr_scan/siblings is still the endgame)."""
NEW = """DONE 2026-10-04 (supersedes the hierarchical-macro endgame plan):
  rtr_scan.v regenerated with ~/bin/sv2v (3 modules); flat original kept as
  rtr_scan.v.orig_flat. TWO synth fixes landed and validated:
  (a) sv2v mangles always_comb in _rtr_sdiv96 into an _sv2v_ dummy-signal
      process that trips yosys PROC_DFF -> rewrote _rtr_sdiv96 as pure
      continuous assigns (bit-exact, cocotb RC=0 re-proven, log
      test/rtr_restruct2.log);
  (b) yosys 0.46 synth-internal passes + later techmap/proc choke on the raw
      async-reset FSM process ("Multiple edge sensitive events") -> hierarchy
      -check; proc BEFORE synth fixes it. Result: full mapped netlist
      RC=0, 509,562 cells (was 1,416,166 flat, -64%), abc 125s, minutes not
      hours. Cache INSTALLED in build/gds/rtr_scan/ with key
      h2-6af76771031995f44470adf5491b24df-mapped-v2-ripple-e974a21c0bff8912f1fcb8805c8d2edd
      (queue skips synth for rtr_scan). harden_block.sh rtr-family
      SYNTH_COMMAND now has the early hierarchy+proc. Port-resize warnings
      (64->96 on peval A/B connections) analyzed: harmless (mod-2^96
      multiplication invariant to zero-extension; Verilator sign-extends,
      cocotb validates the exact netlist behavior)."""
assert OLD in text, 'old TODO text not found'
text = text.replace(OLD, NEW, 1)

OLDQ = "- **Queue state after this session**: fpu4 + gsx lines ACTIVE in blocks.txt;"
NEWQ = """- **ALL 12 BLOCKS ENABLED in blocks.txt (2026-10-04)**: display, xbar,
  ram_slave, blit, fpu4, gsx, tu, core, rtr_setup, rtr_scan (PNR_TIMEOUT
  21600/MAGIC 36000), rtr_top (via make_rtr_top_netlist.sh + rtr_top_pnr.sh
  once rtr_scan verifies), cp. Nothing deferred. Die stage runs after all
  macros clean (queue exits nonzero if any block fails).
- **Queue state**: fpu4 rebuilding first with probe fix (0 probe cells
  confirmed in new run);"""
assert OLDQ in text, 'queue-state anchor not found'
text = text.replace(OLDQ, NEWQ, 1)

open(path, 'w').write(text)
print('agentbible updated, size', len(text))
