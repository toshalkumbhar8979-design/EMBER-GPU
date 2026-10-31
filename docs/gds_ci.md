# GDS on GitHub Actions

[`.github/workflows/gds.yml`](../.github/workflows/gds.yml) runs the remaining
block hardening on GitHub-hosted runners, so the place-and-route does not have
to occupy the local machine for a night.

It builds **only the three blocks that are not signed off**:

| block | cells (approx.) | state |
|---|---|---|
| `core` | 347 k | no routed DEF yet; this is the long pole |
| `rtr_scan` | 1.42 M flat / 510 k hierarchical | synth cached, no routed DEF |
| `rtr_top` | hierarchical | synth cached, no routed DEF |

The nine finished blocks (`display`, `xbar`, `ram_slave`, `blit`, `fpu4`,
`gsx`, `rtr_setup`, `cp`, `tu`) are **not** in the workflow. Their committed
GDS files and zero-DRC audits are left exactly as they are, and none of their
scripts changed.

## Why six jobs instead of one

GitHub-hosted runners are killed at 6 h. `core`'s local P&R ran far longer
than that, and a kill used to lose the whole attempt. The flow is therefore
split into stages that each write a checkpoint and exit:

```
synth  : build/gds/<block>.v   -> synth.v (+ .synthkey)
place  : synth.v               -> placed.odb, placed.def
grt    : placed.odb            -> grt.odb, global_route.def
drt    : grt.odb               -> final.def, final.nv, openroad.log
gds    : final.def             -> <block>.gds, gds_validation.json
drc    : <block>.gds           -> export_audit.json (whole-layout flattened DRC)
```

`gds` and `drc` are separate steps for a specific reason: Magic's flatten of a
347 k-cell block is the most expensive operation in the flow and it breached
the 6 h cap on 2026-10-30 (4 h 20 m in one Magic script, killed before it had
written any GDS). Export is now KLayout's LEF/DEF importer, which resolves each
standard cell against the real PDK GDS masters and writes the hierarchy in
minutes; the flat Magic DRC keeps its own job and its own timeout, so running
out of time marks the block **unverified** instead of destroying the GDS.

Each stage is its own job and hands the next one an artifact. A timeout costs
one stage, not the run. `scripts/gds/ci/run_stage.sh` is the container entry
point; `scripts/gds/ci/pnr.tcl` is the stage-aware P&R recipe (copied from
`harden_block.sh`, which stays the local reference and is untouched).

## Running it

From the Actions tab: **GDS → Run workflow**. Or:

```bash
gh workflow run gds.yml -f target=core
gh run watch
```

Inputs:

| input | meaning |
|---|---|
| `target` | `core`, `rtr_scan`, `rtr_top`, or `remaining` (all three) |
| `start_stage` | begin at this stage; earlier checkpoints come from artifacts |
| `resume_run_id` | pull missing checkpoints from an earlier run id |
| `util`, `density`, `pad`, `tilt`, `drt_iters` | blank = the per-block value in `scripts/gds/blocks.txt` |
| `repair_timing` | off by default; this flow does not claim timing closure |

`core` defaults from `blocks.txt` are util 12 %, density 0.18, two sites of
pin padding, met2 tilt 0.25 and 60 detailed-route iterations — the recipe that
was staged for the pin-access problem, not a generic default.

To continue a run that timed out:

```bash
gh workflow run gds.yml -f target=core -f start_stage=drt -f resume_run_id=<run-id>
```

## What to expect on a hosted runner

- **synth** — cached RTL conversion (`build/gds/<block>.v` is tracked), Yosys
  with `-noalumacc` and `abc -fast`. Fits comfortably; the job allows 350 min.
- **place / grt / drt** — 4 vCPU, 16 GB RAM, plus 4 GB of swap the workflow
  adds. Placement on `core` is minutes; global and detailed routing are the
  ones that can exhaust the job. `repair_timing` is skipped (that was the stage
  that sat silently for half an hour locally), and the final routed ODB is not
  written during CI to save disk.
- **gds** — KLayout DEF→GDS against the real PDK cell masters (78 s on
  `core`, ~93 MB compressed artifact), then a streaming GDSII record walk
  (`scripts/gds/ci/check_gds.py`) that fails on truncation. The old finalize
  pass re-read the whole layout and was OOM-killed on 2026-10-31; nothing in
  this stage loads more than 1 MB of the file at a time now.
- **drc** — Magic flatten + full-rule DRC on the exported GDS, plus a routing
  violation check read from the route log. This is the long one on `core`; it
  gets 5 h 50 m and its failure leaves the GDS artifact untouched.

If a stage does not fit, artifacts from the completed stages are kept, and the
next attempt can start from that stage. For heavier work, point the jobs at a
larger runner by changing `runs-on` (GitHub larger runners are a paid feature);
nothing else in the workflow needs to change.

## Environment the jobs create

- Container: `efabless/openlane:latest` (OpenROAD, Yosys, Magic, KLayout;
  verified versions: OpenROAD `b16bda7`, Yosys 0.38, Magic 8.3.483,
  KLayout 0.29.1).
- PDK: `sky130A` build `fa87f8f4…` installed with `volare` and cached between
  runs (`scripts/gds/ci/pdk.sh`). The OpenLane image does not bundle a PDK.
- `scripts/gds/ci/pystub/psutil.py` gives the synthesis RSS guard the two
  psutil calls it needs, because the container's Python has neither psutil nor
  pip.

## Running a stage locally

The same staged commands work on the local WSL checkout, which is useful for a
quick sanity check before spending CI minutes:

```bash
GDS_PDK=$HOME/.volare/volare/sky130/versions/fa87f8f4bbcc7255b6f0c0fb506960f531ae2392/sky130A \
  bash scripts/gds/ci/run_stage.sh core place
```

Use a scratch block name and `GDS_ROOT` if you do not want to overwrite a real
block's checkpoint.
