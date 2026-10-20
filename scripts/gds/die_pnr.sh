#!/usr/bin/env bash
# die_pnr.sh -- physical implementation of the integrated GPU die (ember_die).
#
# The 8 hardened GPU blocks enter as hard macros (their audited LEF abstracts +
# GDS); the top-level glue netlist (253 std cells: fpa ownership mux, CSR bus,
# struct adapters, tie-offs) is placed in a dedicated core band; every
# inter-block net is routed met1-met5. Exports a merged ember_die.gds whose
# whole flattened layout must pass Magic DRC with zero violations.
#
# Prereqs: all 8 blocks hardened (gds + LEF), build/gds/die/top.v synthesized.
# Run INSIDE the container.
set -o pipefail
PDK=$(ls -d $HOME/.volare/volare/sky130/versions/*/sky130A 2>/dev/null | head -1)
[ -n "$PDK" ] || { echo "PDK NOT FOUND"; exit 3; }
LIB=$PDK/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
OUT=/work/build/gds/die
mkdir -p "$OUT"
cd "$OUT"

# ---- 0/4 prerequisites ------------------------------------------------------
for m in core tu gsx blit rtr_top xbar display cp; do
  [ -f "/work/build/gds/$m/$m.lef" ] || { echo "missing LEF: $m"; exit 1; }
  python3 /work/scripts/gds/verify_block.py "$m" || exit 1
done
[ -f top.v ] || { echo "missing die netlist (run make_die_netlist.sh)"; exit 1; }
python3 /work/scripts/gds/check_macro_interfaces.py top.json ember_die \
  core tu gsx blit rtr_top xbar display cp || exit 1
rm -f final.def global_route.def route_drc.rpt die.gds openroad.log magic.log

# ---- floorplan + macro placement plan ---------------------------------------
python3 /work/scripts/gds/die_plan.py || exit 1

# ---- 1/4 OpenROAD: floorplan, glue place, CTS, PDN, route --------------------
cat > pnr.tcl <<EOF
read_liberty $LIB
read_lef $PDK/libs.ref/sky130_fd_sc_hd/techlef/sky130_fd_sc_hd__nom.tlef
read_lef $PDK/libs.ref/sky130_fd_sc_hd/lef/sky130_fd_sc_hd.lef
read_lef /work/build/gds/core/core.lef
read_lef /work/build/gds/tu/tu.lef
read_lef /work/build/gds/gsx/gsx.lef
read_lef /work/build/gds/blit/blit.lef
read_lef /work/build/gds/rtr_top/rtr_top.lef
read_lef /work/build/gds/xbar/xbar.lef
read_lef /work/build/gds/display/display.lef
read_lef /work/build/gds/cp/cp.lef
read_verilog /work/build/gds/die/top.v
link_design ember_die

source /work/build/gds/die/die_plan.tcl

set_routing_layers -signal met2-met5 -clock met2-met5
place_pins -random -hor_layers met1 -ver_layers met2
if {![catch {get_ports clk}]} { create_clock -name clk -period 20.0 [get_ports clk] }
set_wire_rc -signal -layer met2
set_wire_rc -clock -layer met3

global_placement -density 0.30
estimate_parasitics -placement
repair_design
detailed_placement
clock_tree_synthesis
estimate_parasitics -placement
repair_timing -max_passes 2 -repair_tns 10
if {[catch {tapcell -distance 14 -tapcell_master sky130_fd_sc_hd__tapvpwrvgnd_1} tmsg]} {
  puts "TAPCELL_WARN: \$tmsg"
}
detailed_placement

# ---- power: std-cell grid + macro hookup ----
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
add_pdn_connect -grid stdcell -layers {met4 met5}
define_pdn_grid -name macros -macro -cells {ember_core ember_tu ember_gsx ember_blit ember_rtr_top ember_xbar ember_display ember_cp} -pins {met1 met4 met5}
add_pdn_connect -grid macros -layers {met1 met4}
add_pdn_connect -grid macros -layers {met4 met5}
pdngen
global_route
write_def global_route.def

detailed_route -bottom_routing_layer met1 -top_routing_layer met5 -output_drc route_drc.rpt -droute_end_iter 30 -verbose 1
if {[catch {filler_placement {sky130_fd_sc_hd__fill_1 sky130_fd_sc_hd__fill_2 sky130_fd_sc_hd__fill_4 sky130_fd_sc_hd__fill_8}} fmsg]} {
  puts "FILLER_WARN: \$fmsg"
}
write_db final.odb
write_def final.def
write_verilog final_nl.v
report_wns
report_tns
EOF
timeout 14400 openroad -no_init -exit pnr.tcl > openroad.log 2>&1 \
  || { echo "OPENROAD FAIL"; tail -25 openroad.log; exit 1; }
echo "   route ok"

# ---- 2/4 Magic DRC on the die view (glue + routing; macros as abstracts) ------
DEF=final.def; FLOWN=detailed-route
if [ ! -f final.def ]; then
  DEF=global_route.def; FLOWN=global-route
  [ -f global_route.def ] || { echo "NO DEF"; exit 1; }
fi
echo "$FLOWN" > flow.txt
cat > .magicrc <<EOFMAC
set PDKPATH $PDK
tech load \$PDKPATH/libs.tech/magic/sky130A.tech
scalegrid 1 2
addpath \$PDKPATH/libs.ref/sky130_fd_sc_hd/mag
addpath \$PDKPATH/libs.ref/sky130_fd_sc_hd/maglef
drc euclidean on
EOFMAC
cat > magic.tcl <<EOFMAG
lef read $PDK/libs.ref/sky130_fd_sc_hd/techlef/sky130_fd_sc_hd__nom.tlef
gds read $PDK/libs.ref/sky130_fd_sc_hd/gds/sky130_fd_sc_hd.gds
lef read /work/build/gds/core/core.lef
lef read /work/build/gds/tu/tu.lef
lef read /work/build/gds/gsx/gsx.lef
lef read /work/build/gds/blit/blit.lef
lef read /work/build/gds/rtr_top/rtr_top.lef
lef read /work/build/gds/xbar/xbar.lef
lef read /work/build/gds/display/display.lef
lef read /work/build/gds/cp/cp.lef
def read $DEF
load ember_die -dereference
flatten ember_die_drc_flat
load ember_die_drc_flat
select top cell
box select
drc on
drc style drc(full)
drc check
drc catchup
set drcerr [drc list count total]
puts "DRC_DETAILS=[drc listall why]"
puts "DRC_COUNT=\$drcerr"
EOFMAG
timeout 2700 magic -rcfile .magicrc -dnull -noconsole magic.tcl > magic.log 2>&1 \
  || echo "MAGIC FAIL (KLayout merge still runs; audit decides)"
grep -m1 DRC_COUNT magic.log || echo "DRC_COUNT=?"


# ---- 3/4 KLayout merged GDS (real macro geometry inside the die) -------------
PDK="$PDK" KLAYOUT_OUT="$OUT/die.gds" \
  klayout -b -r /work/scripts/gds/die_def2gds.py > klayout_def.log 2>&1 \
  || { echo "KLAYOUT MERGE FAIL"; tail -12 klayout_def.log; exit 2; }
KLAYOUT_IN=die.gds KLAYOUT_OUT=die_final.gds KLAYOUT_TOP=ember_die \
  klayout -b -r /work/scripts/gds/finalize.py > klayout.log 2>&1 \
  || { echo "GDS VALIDATION FAILED"; tail -10 klayout.log; exit 2; }
mv die_final.gds die.gds
ls -la die.gds

# ---- 4/4 independent zero-DRC audit of the merged GDS -------------------------
python3 /work/scripts/gds/audit_export.py die > export_audit_run.log 2>&1 \
  || { echo "EXPORTED GDS AUDIT FAILED"; tail -10 export_audit_run.log; exit 4; }
EDRC=$(python3 -c 'import json; print(json.load(open("export_audit.json"))["whole_layout_flattened_drc"])')
MDRC=$(grep '^DRC_COUNT=' magic.log | tail -1)
RDRC=$(grep 'Number of violations =' openroad.log | tail -1)
if [[ "$RDRC" != *'= 0.'* ]] || [ "$MDRC" != 'DRC_COUNT=0' ] || [ "$EDRC" != 0 ]; then
  echo "DIE GDS GENERATED, CHECKS NOT CLEAN: routing=[$RDRC] magic=[$MDRC] audit=$EDRC"
  exit 4
fi
echo "== [ember_die] DONE (validated merged GDS, routing and Magic DRC zero) =="
