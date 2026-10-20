# CLOUD HANDOFF — finish `ember_core` routing + GDS (resume-only, NO rebuild)

Audience: a fresh Freebuff session (this handoff is small on purpose — the
previous session failed to move to Cloud because its context was too large).

## Mission

1. Resume **detailed routing** of `ember_core` from the routed checkpoint in
   `checkpoint/` until violations reach 0 (or report honestly).
2. Run the **GDS tail** (Magic merge + flattened DRC, KLayout finalize,
   export audit, `verify_block.py core`) to produce a verified `core.gds`.
3. Deliver `core.gds` back to the user's system.

**HARD RULE (user policy, repeated many times): NEVER rebuild.** No
re-synthesis, no floorplan, no placement. Only resume routing from
`checkpoint/final.odb` (or `final.def` as fallback). If a resume cannot make
progress, stop and report — do not rebuild.

## What travels with the project

| file | size (bytes) | role |
|---|---|---|
| `checkpoint/final.odb` | 1,243,186,052 | routed checkpoint (OpenROAD DB) — **resume source of truth** |
| `checkpoint/final.def` | 682,834,397 | DEF fallback of the same routed state |
| `checkpoint/openroad.log` | 12,600 | cumulative routing log (gate decisions read it) |
| `checkpoint/PRE_SHUTDOWN_STATUS.log` | 2,728 | seeded violation count = 152 |
| `checkpoint/route_resume.tcl` | 1,130 | resume script used on the laptop (paths are LOCAL — regenerate) |

Verify the two big files by size after any transfer before deleting local
copies. The checkpoint state is ≈154 DRC violations (a plateau of 105 was
reached once in RAM only and is **not** in the checkpoint).

## Environment setup (cloud Linux)

Tools needed: `openroad`, `magic`, `klayout`, `python3` (+`psutil` optional).
Install via conda/mamba (`conda install -c litex-hub openroad magic klayout`)
or a prebuilt OpenROAD-flow-scripts bundle.

PDK: sky130A via volare —
`pip install volare && volare enable --pdk sky130 fa87f8f4bbcc7255b6f0c0fb506960f531ae2392`
(the exact version the checkpoint was routed against).

**Path adaptation required:** `checkpoint/route_resume.tcl` and
`scripts/gds/*.sh` hardcode `/work/...` and
`/home/toshal/.volare/volare/sky130/versions/<hash>/sky130A/...`. Either
create matching symlinks (`ln -s <project> /work`, PDK at the same path) or
regenerate the TCL with the cloud paths. The `read_db` / `detailed_route`
calls themselves need no changes.

## Step 1 — resume routing (resume-only)

Put `checkpoint/final.odb` + `final.def` in the routing work dir
(`build/gds/core/`), regenerate `route_resume.tcl` (copy from `checkpoint/`,
fix PDK path), then:

```
openroad -no_init -exit route_resume.tcl > openroad_resume_1.log 2>&1
```

The TCL: `read_db final.odb` (log must show `RESUME_SOURCE=final.odb` —
**that line proves no rebuild**), `set_thread_count <n>`, `detailed_route
-bottom_routing_layer met1 -top_routing_layer met5 -output_drc
route_drc_resume.rpt -droute_end_iter 60 -verbose 1`, then writes
`final_new.odb` / `final_new.def` / `final_nl.v`. On success rename
`final_new.*` over `final.*` and repeat rounds until violations = 0.

Fallback path in the TCL (`read_verilog synth.v; link_design ember_core;
read_def final.def`) **cannot be used** — `synth.v` is not in the checkpoint.
`final.odb` must load.

Historical timing for expectations: laptop took ~2.5 h for 154→105, then the
tail stalled >6 h at 105 on 8 threads / 16 GB. Cloud with more RAM/cores
should do better; memory needs are ~15 GB RSS + ~15 GB swap — size the VM
with ≥32 GB total memory or the OOM killer will strike (it did, twice, on
the laptop).

## Step 2 — GDS tail (identical to `finish_core_from_routed.sh` /
`auto_core_master.sh` step 4)

1. Magic: `.magicrc` (PDK tech + scalegrid 1 2 + drc euclidean on); magic
   script: lef-read techlef, gds-read stdcell GDS, `def read final.def`,
   `load ember_core -dereference`, `gds write core.gds`, then flatten
   `${TOP}_drc_flat` + `drc check` → capture `DRC_COUNT`.
2. KLayout: `scripts/gds/finalize.py` with `KLAYOUT_IN=core.gds
   KLAYOUT_OUT=core_final.gds KLAYOUT_TOP=ember_core`, then rename over
   `core.gds`.
3. Audit: `python3 scripts/gds/audit_export.py core` → `export_audit.json`
   (`whole_layout_flattened_drc`).
4. Gate: `python3 scripts/gds/verify_block.py core` must pass.

These Python scripts live in `scripts/gds/` (travels with the project) but
assume `/work/...` paths — adjust or symlink.

## Step 3 — deliver to the user

Copy the verified `core.gds` to the workspace root (or `deliverables/`) and
report its path + size + DRC counts (routing / magic / exported audit) so the
user can take it to their system. Keep `openroad_resume_*.log`,
`magic.log`, `export_audit.json` as evidence.

## Acceptance criteria

- [ ] Log shows `RESUME_SOURCE=final.odb` (never a rebuild)
- [ ] Violations trend recorded per round; final count reported honestly
- [ ] `core.gds` produced, `verify_block.py core` passes
- [ ] `core.gds` placed where the user can copy it; path + size reported
