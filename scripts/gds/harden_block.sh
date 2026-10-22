#!/usr/bin/env bash
# harden_block.sh <name> <top> <verilog-files...>
# Real ASIC hardening of one Ember block through the classic open flow:
#   Yosys (synth to sky130) -> OpenROAD (floorplan/place/CTS/route)
#   -> Magic (DRC + extract) -> KLayout (final GDS)
# Run INSIDE the openlane2 container (tools + PDK live there).
set -o pipefail
NAME=$1; TOP=$2; shift 2
# resolve to ABSOLUTE paths before cd (yosys runs from $OUT)
FILES=""
for f in "$@"; do case "$f" in /*) FILES="$FILES $f";; *) FILES="$FILES /work/$f";; esac; done
OUT=/work/build/gds/$NAME
# resolve the version glob ONCE (yosys/abc need a literal path)
PDK=$(ls -d $HOME/.volare/volare/sky130/versions/*/sky130A 2>/dev/null | head -1)
[ -n "$PDK" ] || { echo "PDK NOT FOUND"; exit 3; }
LIB=$PDK/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
mkdir -p "$OUT"
cd "$OUT"
# Stale artifacts from an earlier killed attempt must never leak into this
# run's fallback decisions (e.g. an old global_route.def looking like this
# run's route output). synth.v/.synthkey are deliberately NOT touched: they
# are the synth cache.
if [ "${GDS_SYNTH_ONLY:-0}" != 1 ]; then
  rm -f final.def global_route.def route_drc.rpt flow.txt "$NAME.gds" \
        "${NAME}_final.gds" openroad.log magic.log klayout_def.log klayout.log
fi

echo "== [$NAME] 1/4 Yosys synthesis =="
# synth cache: synthesis is the expensive step; the key is the SOURCE hash +
# flow tag, so editing the shell logic does not force a re-synth.
SRCH=$(md5sum $FILES | md5sum | cut -d' ' -f1)
SH="${GDS_FLOW_TAG:-h1}-$SRCH"
SYNTH_COMMAND="synth -top $TOP -noalumacc"
case "$NAME" in
  rtr_setup|rtr_scan|rtr_top)
    python3 /work/scripts/gds/make_ripple_map.py || exit 1
    # yosys 0.46: synth-internal passes + the later techmap/proc choke on the
    # raw async-reset FSM process ("Multiple edge sensitive events"); converting
    # processes BEFORE synth fixes it (validated 2026-10-04: RC=0, 509,562 cells
    # on the hierarchical rtr_scan netlist, down from 1,416,166 flat).
    SYNTH_COMMAND="hierarchy -check -top $TOP; proc; synth -top $TOP -noalumacc -run begin:coarse; opt -fast -full; memory_map; opt -full; techmap -autoproc -map /work/build/gds/ripple_techmap.v; proc; opt -fast; techmap -autoproc -map /work/build/gds/ripple_techmap.v; proc; opt -fast; hierarchy -check; check"
    SH="$SH-mapped-v2-ripple-$(md5sum /work/scripts/gds/ripple_lcu.v /work/scripts/gds/divmod_u.v | md5sum | cut -d' ' -f1)"
    ;;
esac
if [ -f synth.v ] && [ "$(cat .synthkey 2>/dev/null)" = "$SH" ]; then
  echo "   (cached synth.v)"
else
# Two hard-won synthesis rules for this RTL:
#  1. NO flatten. Flattening rtr_scan expanded it to 963,224 gates and ABC
#     never finished; hierarchical synth maps per-module and OpenROAD links
#     the hierarchy without complaint.
#  2. -noalumacc. `synth`'s carry-lookahead accumulator pass turns every adder
#     into Brent-Kung LCU templates (205 distinct widths here) and ate ~20 GB
#     of RAM on rtr_scan alone. Ripple-carry + ABC mapping is far cheaper and
#     perfectly adequate for an evaluation flow. (This flag had silently
#     dropped out of the command -- rtr_setup's log was generating hundreds of
#     Brent-Kung LCU paramods when the daemon died. Restored: the 9 cached
#     blocks keep their synth.v; the RTR family synths with it.)
#  3. abc -fast: single-pass mapping (the default script ground >40 min with
#     zero output on the multiplier-heavy scan unit).
#  4. Each block is timeboxed so one monster cannot stall the other eleven.
# -noopt_purge: the extra `opt -purge` after synth const-folds the ALU netlist
# and is the real memory hog (12 GB+ RSS and climbing on the RTR blocks).
# `synth` already ends with its own opt passes.
#
# RSS WATCHDOG: the divider/multiplier-heavy blocks (Cramer setup, scan)
# expand into per-width Brent-Kung LCU chains and can reach ~20 GB, which
# starves the container and OOMs whatever else is running. Cap it: if RSS
# passes the limit, kill synthesis for THIS block and move on.
GDS_RSS_LIMIT_KB=${GDS_RSS_LIMIT_KB:-14000000}   # 14 GB
TMO=${GDS_SYNTH_TIMEOUT:-2700}
timeout "$TMO" yosys -p "
read_verilog $FILES
hierarchy -check -top $TOP
$SYNTH_COMMAND
dfflibmap -liberty $LIB
abc -fast -liberty $LIB
setundef -zero
# hilomap: turn constant nets into sky130 tie cells. Without this, setundef
# creates one big zero_ net and TritonRoute refuses it:
#   [ERROR DRT-0305] Net zero_ of signal type GROUND is not routable.
hilomap -hicell sky130_fd_sc_hd__conb_1 HI -locell sky130_fd_sc_hd__conb_1 LO
opt_clean -purge
splitnets -ports
write_verilog -noattr -noexpr -nodec synth.v
tee -o synth_stat.txt stat -liberty $LIB
write_json synth.json
" > yosys.log 2>&1 &
YPID=$!
(
  while kill -0 $YPID 2>/dev/null; do
    # YPID is timeout, not Yosys. Measure its entire descendant tree;
    # checking timeout's tiny RSS leaves the real synthesis unprotected.
    rss=$(python3 - "$YPID" <<'PY'
import sys
import psutil
try:
    parent = psutil.Process(int(sys.argv[1]))
    print(sum(p.memory_info().rss for p in [parent] + parent.children(recursive=True)
              if p.is_running() and p.status() != psutil.STATUS_ZOMBIE) // 1024)
except psutil.Error:
    print(0)
PY
)
    if [ -n "$rss" ] && [ "$rss" -gt "$GDS_RSS_LIMIT_KB" ]; then
      echo "RSS watchdog: synthesis tree at ${rss} kB > limit — terminating this block" >> yosys.log
      kill -TERM $YPID 2>/dev/null
      break
    fi
    sleep 15
  done
) &
WPID=$!
wait $YPID; RC=$?
kill $WPID 2>/dev/null
if [ $RC -ne 0 ] || [ ! -f synth.v ]; then
  echo "YOSYS FAIL (timeout / RSS limit / error)"; tail -12 yosys.log; exit 1
fi
python3 /work/scripts/gds/validate_synth.py synth.json "$TOP" \
  || { echo "SYNTHESIS NOT FULLY MAPPED"; exit 1; }
echo "$SH" > .synthkey
fi
# A synthesis-only run lets every netlist finish without waiting hours for P&R.
if [ "${GDS_SYNTH_ONLY:-0}" = 1 ]; then
  echo "== [$NAME] SYNTHESIS DONE =="
  exit 0
fi
# Container has no awk/sed: pure-bash parse. Keep the LAST "Number of cells"
# line -- yosys prints one stat per module and the top module's is last.
CELLS=$(grep "Number of cells" yosys.log); CELLS=${CELLS##* }
# Cache hit: this run never invoked yosys, so yosys.log holds an older run's
# output (or none) and the grep comes back empty. Read the count from the
# netlist JSON instead, so every rung log states the size it is routing.
if [ -z "$CELLS" ] && [ -f synth.json ]; then
  CELLS=$(python3 -c 'import json,sys; d=json.load(open("synth.json")); print(max(len(m["cells"]) for m in d["modules"].values()))' 2>/dev/null)
fi
echo "   cells: ${CELLS:-unknown}"

echo "== [$NAME] 2/4 OpenROAD floorplan/place/CTS/route =="
# (the die/core size is derived by initialize_floorplan from -utilization
# directly; a dead AREA estimate here was removed)
cat > floorplan.tcl <<EOF
read_liberty $LIB
read_lef $PDK/libs.ref/sky130_fd_sc_hd/techlef/sky130_fd_sc_hd__nom.tlef
read_lef $PDK/libs.ref/sky130_fd_sc_hd/lef/sky130_fd_sc_hd.lef
read_verilog synth.v
link_design $TOP
# PARALLELISM: this box has 24 cores but the flow was running the router on
# ONE of them (openroad pinned at ~100%% CPU for days). OpenROAD's documented
# control is set_thread_count (equivalent to launching openroad -threads N;
# ORFS passes NUM_CORES the same way). Applies to resizer/CTS/DRT workers.
# Kept an env override on purpose: DRT forks copy-on-write workers, so if RSS
# ever threatens the 18 GB cap, rerun with GDS_THREADS=4.
set_thread_count ${GDS_THREADS:-8}
# 30% (not 45%): at 45% TritonRoute could not converge on congested blocks
# (cp reached 11,841 violations and still climbing), because these blocks have
# no PDN and randomly placed pins. Whitespace is cheaper than a stuck router.
# PPL-0024 guard: the die must have perimeter room for every IO pin BIT.
# (xbar: 610 pin bits on a 111um-square utilization-derived die = impossible;
# place_pins aborted the whole block.) Measured from the PPL error: place_pins
# packs ~0.79um/pin on the perimeter; budget 1.0um/pin in micrometres and
# re-initialize with an explicit die when utilization alone made it too small.
set npins 0
set blk [ord::get_db_block]
foreach bterm [\$blk getBTerms] { incr npins }
set min_side [expr {\$npins / 4.0 + 30.0}]
initialize_floorplan -utilization ${GDS_UTIL:-30} -aspect_ratio 1.0 -core_space 10 -site unithd
set diebox [\$blk getDieArea]
set dw [expr {[\$diebox dx] / 1000}]
set dh [expr {[\$diebox dy] / 1000}]
if {\$dw < \$min_side || \$dh < \$min_side} {
  initialize_floorplan -die_area [list 0 0 \$min_side \$min_side] -core_area [list 10 10 [expr {\$min_side - 10}] [expr {\$min_side - 10}]] -site unithd
}
make_tracks
# sky130 li1 is local interconnect, not a general-purpose signal routing layer.
# Keep signal routes on met2..met5. met1 is RESERVED for pin access (DRT
# -bottom_routing_layer met1): at large scale the global router packed ~50% of
# total wirelength onto met1 and generated ~28 shorts per mm of met1 wire
# (fpu4: 1.88M um met1 -> 53K shorts it could never clean). With met1 signal
# routing removed the bulk moves to met2/met3.
set_routing_layers -signal met2-met5 -clock met2-met5
# OpenROAD's place_pins requires explicit pin layers (PPL-0017 otherwise) and
# it checks their PREFERRED DIRECTION against techlef (PPL-0045 if wrong).
# Verified from sky130_fd_sc_hd__nom.tlef: met1 HORIZONTAL, met2 VERTICAL,
# met3 HORIZONTAL.
place_pins -random -hor_layers met1 -ver_layers met2
if {![catch {get_ports clk}]} { create_clock -name clk -period 20.0 [get_ports clk] }
# Wire RC for parasitic estimation: without it repair_design/repair_timing see
# ZERO wire capacitance ([WARNING RSZ-0014]) and their buffer decisions are
# garbage -- useless buffers mean more congestion for the router.
set_wire_rc -signal -layer met2
set_wire_rc -clock -layer met3
# The sky130 unified LEF exposes sky130_fd_sc_hd__probe_p_8 (an analog probe
# cell carrying met4/met5 PAD geometry and no OBS blockage). OpenROAD's
# resizer picks it as load_slew*/max_cap* measurement stubs; its pads then
# land <0.3um from the met4 PDN stripes and Magic flags met4.2/via4.2
# spacing violations (fpu4: DRC_COUNT=3, all probe-pad vs stripe; gsx has
# the same exposure). Synthesis never emits this master (0 in every synth
# cache), so banning it costs nothing and forces ordinary buffers/inverters.
# Both probe masters carry stacked met1->met5 landing pads with no OBS in
# their LEF, so pdngen stripes land next to the pads and Magic DRC flags
# via/met spacing (fpu4: 120 violations, all probe-pad vs PDN geometry).
# Banning ONE master is not enough: when probe_p_8 was banned the resizer
# switched to its sibling probec_p_8 (34 inserted in the 2026-10-04 rebuild).
# Ban the whole probe family; the PROBE_PURGE sweep below catches any variant.
set_dont_use {sky130_fd_sc_hd__probe_p_8 sky130_fd_sc_hd__probec_p_8}
# DRC strategy: relax the placement density (routing needs whitespace), route,
# THEN place FILLER cells so the well/implant and poly rules are satisfied
# between standard-cell rows -- missing fillers are a classic source of
# thousands of "well spacing / min-area" style DRCs on sky130. Filler placement
# lives right after detailed_route below: fillers have no pins, so placing
# them before CTS/route only steals whitespace. (The original filler line here
# also leaked shell redirections into the Tcl and STA-0565-aborted every
# block in the first h2 run.)
global_placement -routability_driven -density ${GDS_PL_DENSITY:-0.45}
# PIN-ACCESS CORRIDORS (GDS_PL_PAD, default 0 = off so proven blocks keep
# their recipe). sky130 hd cells put their inputs on met1 and detailed routing
# has to escape them; with cells abutted row-wide every escape competes for the
# same few met1 tracks, which is exactly how core's first runs opened with
# 477K violations at iteration 0 and climbed from there. Padding every cell by
# N sites (2 = 0.92um on the unithd site) buys each cell a vertical escape
# channel and is the cheapest congestion fix there is: it costs area, which
# this flow has (GDS_UTIL is deliberately small), and buys routing room.
if {${GDS_PL_PAD:-0} > 0} {
  set_placement_padding -global -left ${GDS_PL_PAD} -right ${GDS_PL_PAD}
  puts "PL_PAD: ${GDS_PL_PAD} site(s) left/right per cell"
}
estimate_parasitics -placement
repair_design
detailed_placement
clock_tree_synthesis
estimate_parasitics -placement
# Bound optimizer effort; unresolved timing is reported, not waived as clean.
repair_timing -max_passes ${GDS_TIMING_PASSES:-2} -repair_tns ${GDS_REPAIR_TNS:-10}
# TAP cells: latchup rules want a well tap every ~14um (OpenLane's sky130
# distance). catch-wrapped so a tapcell problem can never kill the block.
if {[catch {tapcell -distance 14 -tapcell_master sky130_fd_sc_hd__tapvpwrvgnd_1} tmsg]} {
  puts "TAPCELL_WARN: \$tmsg"
}
detailed_placement
# ---- POWER DELIVERY: the missing stage that was breaking routing ----
# Yosys emits no power connections (synth.v has zero VPWR refs), so before this
# block every cell's VPWR/VGND/VPB/VNB rail geometry was floating. TritonRoute
# then shorted thousands of met1/li1 wires against those shapes -- cp showed
# 7416 met1 shorts + 3522 li1 shorts at optimization iteration 0, roughly ONE
# SHORT PER CELL, and the count only grew with more iterations. The fix is the
# standard sky130 recipe: global PG connections + met1 followpin rails +
# met4/met5 straps (numbers from the OpenROAD-flow-scripts sky130hd PDN).
# VPB/VNB are tied to the rails (OpenLane convention; hd cells carry internal
# well taps).
add_global_connection -net VPWR -inst_pattern .* -pin_pattern ^VPWR\$ -power
add_global_connection -net VPWR -inst_pattern .* -pin_pattern ^VPB\$ -power
add_global_connection -net VGND -inst_pattern .* -pin_pattern ^VGND\$ -ground
add_global_connection -net VGND -inst_pattern .* -pin_pattern ^VNB\$ -ground
global_connect
set_voltage_domain -name CORE -power VPWR -ground VGND
define_pdn_grid -name stdcell -voltage_domains CORE
add_pdn_stripe -grid stdcell -layer met1 -width 0.48 -followpins
add_pdn_stripe -grid stdcell -layer met4 -width 1.6 -pitch 27.14 -offset 13.57
add_pdn_stripe -grid stdcell -layer met5 -width 1.6 -pitch 27.2 -offset 13.6
add_pdn_connect -grid stdcell -layers {met1 met4}
# via4 arrays: sky130 via4.2 spacing (0.42um effective = 0.8 - 2*0.19 enclosure)
# is violated by pdngen's default ~1.0um pitch (0.2um gaps). A 1.3um pitch gives
# 0.5um cut spacing; fpu4's first route failed Magic DRC on exactly this rule.
add_pdn_connect -grid stdcell -layers {met4 met5} -cut_pitch 1.3
pdngen
# PROBE PURGE: delete any probe-family instance the repair stages inserted,
# right before routing so the router and the exported GDS never see their
# met4/met5 landing pads. They are passive measurement stubs with no logical
# function, so removal is electrically safe. (odb::dbInst_destroy verified
# live on fpu4 final.odb: 34->0 without errors.)
set _probe_purged 0
set _purge_block [ord::get_db_block]
foreach _purge_inst [\$_purge_block getInsts] {
  set _purge_master [[\$_purge_inst getMaster] getName]
  if {[string first "probe" \$_purge_master] >= 0} {
    odb::dbInst_destroy \$_purge_inst
    incr _probe_purged
  }
}
puts "PROBE_PURGE: removed \$_probe_purged probe-family instances before route"
# GLOBAL-ROUTE LAYER TILT (GDS_GRT_TILT, default off). The value is the
# capacity *reduction* fraction for met2, so 0.25 makes the bulk of the wire
# move up to met3/met4 and leaves met2 track for the met1 pin-access escapes
# and the short met2 jog every pin needs. core's plateau of 105 violations was
# 67 met1 shorts + 31 met1 spacings: pin access, not long-wire congestion.
if {[info exists ::env(GDS_GRT_TILT)] && \$::env(GDS_GRT_TILT) ne ""} {
  set_global_routing_layer_adjustment met2 \$::env(GDS_GRT_TILT)
  puts "GRT_TILT: met2 capacity reduced by \$::env(GDS_GRT_TILT)"
}
global_route
# Always keep a globally-routed DEF: if detailed routing cannot converge inside
# the timebox, this still gives a real GDS (labelled "global-route").
write_def global_route.def
if {[info exists ::env(GDS_SKIP_DRT)]} {
  puts "GDS_SKIP_DRT set: keeping the globally-routed DEF (flow label: global-route)"
} else {
  # More iterations = more chances to remove violations. The router reports
  # per-iteration DRC counts into route_drc.rpt; we keep the best DEF it reaches.
  # -drc_report_iter_step 2: write the violation count every other iteration.
  # Without it the report only lands at the end, so an exploding run burns its
  # whole timebox before anyone sees the number (core's 4M-violation surprise).
  # -bottom_routing_layer: met2 (GDS_DRT_BOTTOM) keeps DRT from ROUTING on
  # met1 — it still builds the met1 pin-access stubs every cell needs, but no
  # long met1 wire, so met1 can never short against the followpin rails or a
  # neighbour's pins. set_routing_layers already reserves met1 (signal met2..5),
  # and yet the core plateau was 67 met1 shorts + 31 met1 spacings: the DRT
  # argument was quietly handing met1 back to the router. Default stays met1 so
  # blocks with a proven zero-violation run keep their exact recipe.
  detailed_route -bottom_routing_layer ${GDS_DRT_BOTTOM:-met1} -top_routing_layer met5 -output_drc route_drc.rpt -drc_report_iter_step 2 -droute_end_iter ${GDS_DRT_ITER:-20} -verbose 1
}
# FILL AFTER ROUTE: the master list must be ONE braced Tcl list (unbraced
# args = [ERROR STA-0565] "filler_placement requires one positional argument",
# the bug that failed every block in the first h2 run). Masters verified
# against the PDK LEF: fill_1/2/4/8. catch-wrapped so a filler problem can
# never destroy an already-routed design. \$ is escaped for the shell heredoc.
if {[catch {filler_placement {sky130_fd_sc_hd__fill_1 sky130_fd_sc_hd__fill_2 sky130_fd_sc_hd__fill_4 sky130_fd_sc_hd__fill_8}} fmsg]} {
  puts "FILLER_WARN: \$fmsg"
}
# Retain a routed DB checkpoint even if later reporting/export fails.
write_db final.odb
write_def final.def
write_verilog final_nl.v
puts "DESIGN_AREA=[report_design_area]"
report_wns
report_tns
report_checks -path_delay max -group_count 5
EOF
timeout ${GDS_PNR_TIMEOUT:-5400} openroad -no_init -exit floorplan.tcl > openroad.log 2>&1 \
  || { echo "OPENROAD FAIL (or timeout)"; tail -25 openroad.log; exit 1; }
echo "   route ok"

echo "== [$NAME] 3/4 Magic GDS merge + DRC =="
# pick the best DEF that exists: detailed route if it converged, else global
DEF=final.def; FLOWN=detailed-route
if [ ! -f final.def ]; then
  if [ -f global_route.def ]; then DEF=global_route.def; FLOWN=global-route
  else echo "NO DEF (place/route failed)"; exit 1; fi
fi
echo "$FLOWN" > flow.txt
echo "   using DEF: $DEF ($FLOWN)"
# Magic auto-reads .magicrc from the cwd: it must load the sky130A TECH and
# put the FULL-cell .mag views on the search path (ahead of the LEF
# abstracts) -- otherwise Magic starts with its default tech, cannot map the
# LEF layers, and `load -dereference` yields no usable geometry.
cat > .magicrc <<EOF
set PDKPATH $PDK
tech load \$PDKPATH/libs.tech/magic/sky130A.tech
# PDK canonical half-lambda grid; avoids rounding DEF via enclosures.
scalegrid 1 2
# 'addpath' is Magic's canonical search-path command -- the PDK's own
# sky130A.magicrc uses it. The 'path cell/search' commands parsed fine but did
# NOT affect the load path, so every child stayed a LEF abstract and gds write
# refused (fill_8 was the first cell it named). Full .mag views go FIRST so
# they win over the LEF abstracts during 'load -dereference'.
addpath \$PDKPATH/libs.ref/sky130_fd_sc_hd/mag
addpath \$PDKPATH/libs.ref/sky130_fd_sc_hd/maglef
drc euclidean on
EOF
cat > magic.tcl <<EOF
lef read $PDK/libs.ref/sky130_fd_sc_hd/techlef/sky130_fd_sc_hd__nom.tlef
# Full masters FIRST: load the entire standard-cell GDS into memory so every
# child of the DEF is a FULL view. (LEF abstracts + addpath were not enough:
# 'load -dereference' still left fill_8 abstract and the GDS writer refused
# with 'Cell ... is an abstract view; cannot write GDS'.) The cell LEF is not
# read at all: DEF read instantiates the GDS-loaded masters directly.
gds read $PDK/libs.ref/sky130_fd_sc_hd/gds/sky130_fd_sc_hd.gds
def read $DEF
load $TOP -dereference
# NOTE: no 'property LEFview NoPinLabels' here -- applied to the just-loaded
# TOP cell it marks the whole design as an abstract view and the GDS writer
# refuses (the display test run produced a 66-byte empty GDS that way).
# Comments inside an unquoted heredoc must never contain backticks: bash runs
# them as command substitutions.
gds write $NAME.gds
# Check a flattened COPY of the placed design: sky130 tapless cell masters
# fail well-tap rules in isolation even though neighbouring tap cells satisfy
# them in the actual layout. Streamout above keeps the original hierarchy.
flatten ${TOP}_drc_flat
load ${TOP}_drc_flat
select top cell
box select
drc on
drc style drc(full)
drc check
drc catchup
set drcerr [drc list count total]
puts "DRC_DETAILS=[drc listall why]"
puts "DRC_COUNT=\$drcerr"
EOF
# 2700 s truncated fpu4's gds write mid-stream on 2026-10-03 after the whole
# 45 min box went into merging 101k cells; 3 h keeps dense blocks safe.
timeout ${GDS_MAGIC_TIMEOUT:-10800} magic -rcfile .magicrc -dnull -noconsole magic.tcl > magic.log 2>&1 \
  || echo "MAGIC FAIL (falling back to KLayout DEF->GDS)"
grep -m1 DRC_COUNT magic.log || echo "DRC_COUNT=?"

if [ ! -f $NAME.gds ]; then
  echo "   Magic produced no GDS -> KLayout DEF->GDS fallback"
  PDK="$PDK" KLAYOUT_DEF="$DEF" KLAYOUT_TOP=$TOP KLAYOUT_OUT=$NAME.gds \
    klayout -b -r /work/scripts/gds/def2gds.py > klayout_def.log 2>&1 || true
fi

echo "== [$NAME] 4/4 KLayout finalize =="
KLAYOUT_IN=$NAME.gds KLAYOUT_OUT=${NAME}_final.gds KLAYOUT_TOP=$TOP \
  klayout -b -r /work/scripts/gds/finalize.py > klayout.log 2>&1 \
  || { echo "GDS VALIDATION FAILED"; tail -10 klayout.log; exit 2; }
mv "${NAME}_final.gds" "$NAME.gds" || exit 2
ls -la "$NAME.gds"
python3 /work/scripts/gds/audit_export.py "$NAME" > export_audit_run.log 2>&1 \
  || { echo "EXPORTED GDS AUDIT FAILED"; tail -10 export_audit_run.log; exit 4; }
EDRC=$(python3 -c 'import json; print(json.load(open("export_audit.json"))["whole_layout_flattened_drc"])')
# A file existing is NOT sign-off. Both routing and full-layout DRC must be
# explicitly zero; a blank/missing count is unverified, never a pass.
RDRC=$(grep 'Number of violations =' openroad.log | tail -1)
MDRC=$(grep '^DRC_COUNT=' magic.log | tail -1)
if [[ "$RDRC" != *'= 0.'* ]] || [ "$MDRC" != 'DRC_COUNT=0' ] || [ "$EDRC" != 0 ]; then
  echo "GDS GENERATED, CHECKS NOT CLEAN: routing=[$RDRC] magic=[$MDRC]"
  exit 4
fi
echo "== [$NAME] DONE (validated GDS, routing and Magic DRC zero) =="
