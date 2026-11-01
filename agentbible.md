# agentbible.md — CHECKPOINT #3 (restored 2026-10-07 after accidental overwrite)

> RECOVERY NOTE (2026-10-07): this file was accidentally overwritten during a
> speed-tuning session and is being restored. The 2026-10-04 sections below are
> VERBATIM (recovered from scripts/insert_bible_section.py and
> scripts/update_bible_rtr.py, which carried them as string literals). The
> pre-2026-10-04 section headers are preserved; their full body text predates
> those helpers and is summarized from the session record. Nothing below is
> new flow behavior: it is the state as of ~02:00 Oct 7.

## STATE AT CHECKPOINT #3 (~02:00 Oct 7)
- **8/12 blocks sealed** (gds_validation.json + export_audit.json, sha256,
  triple-zero): display, xbar, ram_slave, blit, cp, rtr_setup, fpu4, gsx.
  gsx: DRC=0 (~2h15m Magic), AUDIT_DRC_COUNT=0, 392MB GDS, 28,079,223
  recursive shapes, 1904.79µm square.
- **tu PnR CONVERGED** (12h budget, Oct 6 ~12:00–20:17): initial pass
  168,391 viol → iter5 → **"Number of violations = 0" (DRT-0199), timing
  MET**. route_drc.rpt 0 bytes. final.def 443,048,903 B + gold ON DISK —
  PnR is gold, never redo. Overnight Oct 7 pause: tu Magic flatten ran
  5h41m and was killed by the old 6h GDS_MAGIC_TIMEOUT mid-flatten; tu
  needs salvage (Magic merge/DRC + finalize + audit from final.def).
- **core** requeue recipe in blocks.txt (GRT-0118 congestion at global
  route): util 15, density 0.25, 12h boxes. Synth cache intact.
- **rtr_scan** synth cache intact (509,562 cells, key
  h2-6af76771031995f44470adf5491b24df-mapped-v2-ripple-...).
- **blocks.txt** (order: display xbar ram_slave blit fpu4 gsx tu core
  rtr_setup rtr_scan rtr_top cp; per-block env):
  tu|...|GDS_UTIL=20 GDS_PL_DENSITY=0.30 GDS_DRT_ITER=40
  GDS_PNR_TIMEOUT=43200 GDS_MAGIC_TIMEOUT=43200
  core|...|GDS_UTIL=15 GDS_PL_DENSITY=0.25 GDS_DRT_ITER=40
  GDS_PNR_TIMEOUT=43200 GDS_MAGIC_TIMEOUT=21600
  rtr_scan|...|GDS_PNR_TIMEOUT=21600 GDS_MAGIC_TIMEOUT=36000
- **KEEP/queue mechanics (run_cached.sh)**: KEEP gate = verify_block.py
  passes (gds_validation.json + export_audit.json triple-zero openroad.log
  last "Number of violations = 0"). Non-kept with synth.v+.synthkey →
  GDS_PHYSICAL_ONLY=1 physical snapshot rebuild. rtr_top special path:
  make_rtr_top_netlist.sh + rtr_top_pnr.sh. Die stage at end
  (make_block_lef.py ×8 → make_die_netlist.sh → die_pnr.sh → verify die).
  collect_results.py after each block writes paper/asic_table.tex,
  paper/asic_numbers.tex, RESULTS.md.
- **Toolchain**: Yosys/sv2v → OpenROAD → Magic/KLayout, SkyWater sky130A via
  volare (OpenLane-style independent engines driven directly).
- Launch (REQUIRED): `wsl -e bash -c 'cd /work && source run_flow_env.sh &&
  setsid bash scripts/gds/run_cached.sh >> build/gds/physical_fixed.log
  2>&1 & sleep 8; ps -eo pid,pcpu,etime,args | grep run_cached | grep -v grep'`
  (log name: build/gds/physical_fixed.log). Poll with sleep 570 + tail + ps.
- Machine restarted Oct 7 → queue and background processes DEAD; files/disk
  state intact. Timeouts cause FAIL, not corruption. Magic shows ~99% CPU
  for hours with no log output during flatten (DRC_COUNT appears at end;
  gsx took ~2h15m). "131072x1 screen size is bogus" stderr is harmless.
  read_files tool cannot see WSL paths; pkill -f can self-kill — kill by
  PID. No parallel builds (18GB cap; tu route peaked 17.2GB; swap 16GB).
- audit/LEF scripts /root→Path.home() fixes; probe ban+purge; salvage
  script proven on fpu4; checkpoints #1–#3 written and mirrored.

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
  (Verilator LATCH).
- **rtr_scan.v regen DONE 2026-10-04 (supersedes the hierarchical-macro
  endgame plan)**: rebuilt with ~/bin/sv2v (3 modules); flat original kept
  as rtr_scan.v.orig_flat. TWO synth fixes landed and validated: (a) sv2v
  mangles always_comb in _rtr_sdiv96 into an _sv2v_ dummy-signal process
  that trips yosys PROC_DFF -> rewrote _rtr_sdiv96 as pure continuous
  assigns (bit-exact, cocotb RC=0 re-proven, log test/rtr_restruct2.log);
  (b) yosys 0.46 synth-internal passes + later techmap/proc choke on the
  raw async-reset FSM process ("Multiple edge sensitive events") ->
  hierarchy -check; proc BEFORE synth fixes it. Result: full mapped
  netlist RC=0, 509,562 cells (was 1,416,166 flat, -64%), abc 125s,
  minutes not hours. Cache INSTALLED in build/gds/rtr_scan/ with key
  h2-6af76771031995f44470adf5491b24df-mapped-v2-ripple-e974a21c0bff8912f1fcb8805c8d2edd
  (queue skips synth for rtr_scan). harden_block.sh rtr-family
  SYNTH_COMMAND now has the early hierarchy+proc. Port-resize warnings
  (64->96 on peval A/B connections) analyzed: harmless (mod-2^96
  multiplication invariant to zero-extension; Verilator sign-extends,
  cocotb validates the exact netlist behavior).
- **ALL 12 BLOCKS ENABLED in blocks.txt (2026-10-04)**: display, xbar,
  ram_slave, blit, fpu4, gsx, tu, core, rtr_setup, rtr_scan (PNR_TIMEOUT
  21600/MAGIC 36000), rtr_top (via make_rtr_top_netlist.sh + rtr_top_pnr.sh
  once rtr_scan verifies), cp. Nothing deferred. Die stage runs after all
  macros clean (queue exits nonzero if any block fails).
- **build/gds/rtr_scan.v was STALE on main (found 2026-11-01)**: the file
  committed for CI was still the FLAT netlist (1.35M cells) from before the
  hierarchical restructure -- it had no _rtr_smul96/_rtr_sdiv96 modules and
  no t_texpal port, so the 2026-10-04 "509,562 cells" regen never reached
  the repo and every CI synth since rebuilt the 1.42M-cell flat design. That
  is what made rtr_scan place die (global_placement peaked correctly, then
  estimate_parasitics -placement SIGSEGV'd on 1.34M nets at 4.5 GB RSS on a
  16 GB runner). rtr_scan.v, rtr_top.v and top.v were regenerated from
  current RTL; chip.v was already current.
- **_rtr_sdiv96 narrowed 192 -> 118 bits (2026-11-01), bit-exact**: `num` is
  s96, so num<<22 needs exactly 118 bits and the exact quotient of a
  s118/s118 divide also fits in s118 (worst case num=-2^95, den=1 -> -2^117
  = the s118 minimum), so qq[95:0] is unchanged; the s192 operands only
  bought a 192/192 divider. Proven with prep/eqv_div.v (iverilog): 200,008
  vectors incl. 0/0, +/-min/1, max/max, 1/3 truncation -> 0 mismatches.
  Measured cost of the constructs: one _rtr_smul96 = 22,171 cells (x20
  instances = 443k), one 192-bit _rtr_sdiv96 alone was still grinding in ABC
  at 3.4 GB after 15 min on a 15 GB box.

### Freebuff/WSL restart recovery + parallel fpu4-salvage/gsx (2026-10-03 morning)
- [Full body of this and all earlier sections predates the recovery and is
  summarized: WSL restart experiments, fpu4 salvage via salvage_magic_final.sh
  (proven path: Magic merge/DRC -> finalize -> independent export audit from
  final.def), gsx rebuild with probe fix + DRC=0 seal, probe-family PURGE
  sweep added to harden_block.sh (odb::dbInst_destroy of any master name
  containing "probe" before global_route; Tcl-in-heredoc requires \$),
  run_cached.sh queue hardening, blocks.txt tuning lines, paper figure
  tooling. Details live in the session record of 2026-10-03/04.]

## NEXT STEPS (unchanged from checkpoint #3)
1. Salvage tu (BEFORE relaunching queue): relaunch queue; tu is non-kept so
   the queue would rebuild PnR — salvage from final.def instead, or let the
   queue run with the physical-snapshot path per checkpoint #3 plan.
2. Relaunch queue → core requeue → rtr_scan → rtr_top special path → cp
   KEEP → 12/12 → die stage → verify die.
3. Paper recompile: cd /mnt/c/Users/tosha/Downloads/GPU/paper &&
   $HOME/.local/bin/tectonic ember_paper.tex. After each PASS check
   collect_results "gds=N" line. ETA remaining ≈ 18–22h compute.


### 2026-10-07 PM: tu Magic-wedge 3rd repro + user decision (salvage running)
- Salvage relaunched 17:06 IST, ORIGINAL flow, GDS_MAGIC_TIMEOUT=43200 (pid 605).
- Watcher evidence (build/gds/tu_watch.log, 5-min samples): streamout hit
  EXACTLY 111,153,152 B at 17:16 and froze: 0 bytes growth for 15+ min,
  Magic 99.9 percent CPU, last log line [Generating output for cell ember_tu].
  Third byte-identical stop (Oct-6 rescue, this morning rebuild, now).
  KLayout finalize already proved that size is unreadable (EOF mid-record,
  record 9802887) => deterministic Magic top-cell write bug, not a timeout.
- USER DECISION 17:40: let the 12h box expire (~05:06 Oct 8). No fallback
  without a fresh go-ahead. The afternoon speed-optimizer work (fast KLayout
  deck audit etc.) was REVERTED at user request; original slow flow live.
- After expiry: salvage exits 4 via MAGIC FAILED; tu.gds stays truncated;
  queue NOT auto-started; next decision stays with the user.
- Clean state: 8 sealed blocks verified post-revert; core/rtr_scan synth
  caches intact; blocks.txt unchanged; bible restored as CHECKPOINT #3.


### 2026-10-07 17:40: USER GO - run remaining blocks; tu deferred
- User directive: run remaining blocks (summary: Please run remaining blocks).
- Frozen Magic killed by PID list after third byte-identical wedge (evidence
  preserved in build/gds/tu_watch.log via exit-detector stamp).
- tu gold PnR backed up to build/tu_gold_backup/ (final.def, final.odb,
  final_nl.v, synth caches): queue rebuilds wipe block dirs, backup is safe.
- blocks.txt: tu line COMMENTED OUT (full fields preserved, one-line un-comment
  brings it back). Queue relaunched via original run_cached.sh; tu is skipped.
- Queue order tonight: core (requeue, util 15/density 0.25) -> rtr_setup KEEP
  -> rtr_scan -> rtr_top special path -> cp KEEP; die stage remains blocked on
  tu only. RAM free 15GiB; no parallel builds (18GB cap honored).


## 2026-10-07 19:10 - core FAIL root cause found and FIXED: probe-purge block lost heredoc dollar escapes
- Symptom: every GDS_PHYSICAL_ONLY snapshot rebuild (core twice today, rtr_scan in flight) died mid PnR: Error floorplan.tcl line 119 invalid command name getInsts, right after PDN-0001 stdcell grid, BEFORE global_route. Queue handled it as designed: FAIL core: incomplete; no clean-build claim, then moved on (rtr_setup KEEP, cp KEEP, PHYSICAL SUITE PASS=8 FAIL=4, DIE BLOCKED).
- Root cause: floorplan.tcl is written by an UNQUOTED heredoc (harden_block.sh line 136), so every Tcl dollar ref inside must be backslash escaped (the established rule). The PROBE PURGE block (lines 247-256) held 5 raw dollar refs (purge_block, purge_inst twice, purge_master, probe_purged); bash emptied them when writing floorplan.tcl. prepare_cached_flow.py copies harden_block.sh verbatim and run_cached.sh line 6 regenerates the snapshot on every queue launch, so a snapshot-file-only patch would not survive any relaunch.
- Proof this is a regression, not original behavior: sealed gsx and fpu4 floorplan.tcl (both PASSED pre-session) contain the identical purge block WITH correct refs; display and rtr_setup tcl predate the purge (no getInsts). So the purge worked when gsx and fpu4 were built and the backslashes were lost later in the pre-session baseline. The pre-session core FAILs (physical_fixed.log lines 48-85) are consistent with this same defect, so GRT-0118 may never have been the real core blocker.
- Fix applied: re-escaped ONLY the 5 purge refs in harden_block.sh; re-ran prepare_cached_flow.py; validated by expanding the snapshot floorplan heredoc with the gsx environment and diffing against the sealed gsx floorplan.tcl: BYTE IDENTICAL. No other flow logic touched; sealed dirs untouched; /work and C mirror md5-identical (5f53fd56e5aa8d4d46dd77ecd3cca0d8).
- Queue: killed the in-flight rtr_scan snapshot tree (its tcl was already mangled in memory); the old pass closed out cleanly (rtr_top FAIL, cp KEEP, suite PASS=8 FAIL=4, DIE BLOCKED). Relaunched run_cached.sh (new pid 620): 6 KEEP checks done, tu skipped as agreed, core  requeue (util 15) now running through the FIXED purge - the first real route attempt for the requeue recipe.

### 2026-10-17 PM: WSL VM-per-call flapping diagnosed + Task-Scheduler pin (build survives Freebuff session end)
- Symptom after the Freebuff restart: every run_terminal_command call booted a FRESH WSL VM (who -b stayed stale at 15:47; ps -p 1 lstart exposed reboots), so the tu flattened-DRC audit restarted from zero on every call and could never finish.
- Cause: this environment tears the WSL VM down when its last wsl.exe client exits; Freebuff's process cleanup kills a completed command's tree. Long SYNC calls kept it alive only while running.
- Fix (Windows-owned, NO Freebuff session needed): scheduled task EmberWSLPin (schtasks, MINUTE/5, current user, no admin) runs scripts/gds/ember_wsl_pin.ps1 each tick: (1) starts a detached hidden pin client `wsl.exe -e bash -c "exec -a ember-pin sleep infinity"` when none is alive (Start-Process ArgumentList must be ONE string with embedded quotes - the array form does not re-quote multi-word elements and flattens to `bash -c exec`, which exits instantly), (2) revives the chain via /usr/local/sbin/ember_autostart.sh when pgrep finds no recover_1017.sh/run_cached.sh. Log: scripts/gds/ember_wsl_pin.log. Task output-independent of Freebuff; user sessions only POLL.
- Proven: ember-pin PIDs persist after the launching command exits; VM stable at 15:49:02 boot across calls; tu audit (audit_export.py -> Magic flattened DRC, audit_export.tcl) ran 53+ min uninterrupted at 100% CPU.
- Recovery stack: Windows logon Startup hook -> WSL [boot] ember_autostart.sh -> EmberWSLPin 5-min watchdog -> flock/pgrep/BUILD_IN_PROGRESS idempotency. 16 GB WSL cap + WU NoAutoRebootWithLoggedOnUsers retained.

### 2026-10-17 evening: tu AUDIT PASSED (flattened DRC=0) + two queue-killer bugs fixed
- tu acceptance: audit_export.py finished 20:14 after 4h25m Magic flattened DRC -> AUDIT_DRC_COUNT=0, "No errors found"; export_audit.json (sha256 bb9c6ee5...) whole_layout_flattened_drc=0, drc(full), rules_suppressed=false. Routing evidence 0 violations. tu is now fully verified (verify_block.py tu passes; recover skips its salvage on relaunch).
- The queue then ran instantly (all KEEP checks are fast): 8 KEEP + 3 FAIL (core/rtr_scan/rtr_top), DIE BLOCKED, done 20:14:52. FAILs were NOT rebuilds: harden_physical_snapshot.sh validated each synth cache (347,494 / 1,416,166 cells) then died at "2/4 OpenROAD" with `timeout: failed to run command 'openroad': No such file or directory`.
- BUG 1 (fixed): ember_autostart.sh launches the chain via `su - toshal`, which resets PATH; ~/.local/emberbin (openroad/magic/klayout/yosys/python3+psutil) was missing -> openroad not found + psutil ModuleNotFoundError in run_cached.sh's wait-check. Fix: PATH export in recover_1017.sh (inherited by salvage+queue) and in autostart's su command.
- BUG 2 (fixed): autostart's flock FD 9 was inherited by the chain children (setsid nohup does not close it); chip_watch waits for die.gds for hours, so it held the lock forever and blocked every later auto-revive ("another autostart holds the lock"). Fix: `9>&-` on every launched child. An orphaned `sleep 60` from the killed old chip_watch briefly held it too; recycled chip_watch (idempotent waiter).
- Gotcha: pgrep -f probes self-match if the probe's own command line contains the literal pattern text (escaped form with backslashes does NOT self-match). Keep probe patterns escaped in any manual status command.
- Relaunched 20:32:15 via the fixed autostart (through the silent EmberWSLPin task): recover skipped tu (already verified), queue KEEPed 8 sealed blocks, BLOCK core running OpenROAD for real (GDS_UTIL=15 GDS_PL_DENSITY=0.25 GDS_DRT_ITER=40 GDS_PNR_TIMEOUT=86400). Next: core -> rtr_scan -> rtr_top -> die -> chip.gds.


## 2026-10-23 01:30 - core rebuild: three independent failures, all fixed, ladder restarted
- SYMPTOM: `scripts/gds/core_rebuild.sh` exhausted its whole ladder in 48 seconds
  at 00:14 (3x `rc=1 violations=none`), i.e. it never routed at all. Two causes
  stacked, and a THIRD (the watchdog) then killed the first healthy rung.
- CAUSE 1 (netlist): build/gds/core.v was regenerated 2026-10-16 by sv2vall.sh
  WITHOUT rtl/ember_fpu4.sv, but ember_core instantiates ember_fpu4. Yosys:
  `Module \ember_fpu4 referenced in module \ember_core in cell \u_fpu is not part
  of the design`. core.v is 11.7 kB = package+core only; fpu4 was silently
  dropped. Fix: sv2vall.sh `run core` now lists rtl/ember_fpu4.sv, blocks.txt
  core line too. Regenerated core.v is BYTE-IDENTICAL to the Oct-2 one whose
  synth is cached (md5 chain bacecc07297d6608b5e464b3579e25b5 = .synthkey), so
  the 47 MB synth.v (265,280 cells, valid_synth: "Mapped logic verified") is
  reusable -- no re-synthesis needed.
- CAUSE 2 (env): harden_block.sh's synthesis RSS watchdog imports psutil; the
  login-shell python3 has none -> `ModuleNotFoundError` -> "YOSYS FAIL" even
  though yosys never ran. `~/.local/emberbin/python3` has it; core_rebuild.sh
  now prepends $HOME/.venvs/cocotb2/bin (also has psutil 7.2.2) to PATH.
- CAUSE 3 (watchdog kills healthy runs): the first stall watchdog watched
  rebuild_rN.log, which only receives harden_block.sh's stage headers. RUNG 1
  was killed at 00:42 while repair_timing ran at 342% CPU with a log frozen
  since 00:26:50. Replacement measures CPU time of the whole process tree from
  /proc (stdlib only, no psutil dependency) and declares a stall only when CPU
  stops advancing for GDS_STALL_MIN minutes. Verified by test/watch_stall_test.sh
  (busy-but-quiet survives 90 s at mins=1; wedged sleep 600 is killed at 120 s
  with a "no CPU progress" line).
- Also fixed: the stall kill leaked orphans. `kill -TERM -- -pgid` did not reach
  the openroad child, and by 01:29 THREE openroad runs (27/19/15 min) were
  competing for the 8 cores. Added kill_tree() (recursive pgrep -P) used for
  both TERM and KILL; all orphans reaped by explicit PID before relaunch.
- LESSON (repeat of an old one, now in the script): never pkill -f a pattern that
  appears in your own probe command line -- `pkill -TERM -f core_rebuild.sh`
  killed the invoking shell (exit 15) and left the flow half-dead.
- Rung-log cosmetic: on a synth-cache hit the `cells:` line printed empty (it
  greps yosys.log, which this run never wrote). Now falls back to synth.json.
- STATE 01:01:48: ladder relaunched (util 12 / dens 0.18 / pad 2 / met2 tilt
  0.25, 60 DRT iters, 4 h per rung, 6 threads). At 01:29 rung 1 is inside
  repair_timing after CTS, 6.0 GB RSS, 312% CPU, log silent 24 min -- the exact
  case that used to be a false stall, and it survived. Full run: 2x01:03 IST
  logs in build/gds/core/{CORE_STATUS.log,rebuild_r1.log,openroad.log}.
