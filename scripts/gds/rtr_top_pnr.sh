#!/usr/bin/env bash
# rtr_top_pnr.sh -- hierarchical physical implementation of ember_rtr_top.
#
# Monolithic synthesis/ABC of the concatenated setup+scan+top file OOM-kills
# even at 27 GB (RAM+swap), so the block is built hierarchically: the hardened
# ember_rtr_setup and ember_rtr_scan netlists enter as hard macros (their
# audited GDS + macro LEF abstracts); the top FSM glue (2,144 cells) is placed
# around them and every inter-macro net is routed met1-met5.
#
# Prereqs: rtr_setup + rtr_scan hardened (GDS + audit), make_rtr_top_netlist.sh
# Run INSIDE the container.
set -o pipefail
PDK=$(ls -d $HOME/.volare/volare/sky130/versions/*/sky130A 2>/dev/null | head -1)
[ -n "$PDK" ] || { echo "PDK NOT FOUND"; exit 3; }
LIB=$PDK/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
OUT=/work/build/gds/rtr_top
cd "$OUT" || exit 1
TOP=ember_rtr_top

# ---- 0/4 prerequisites -------------------------------------------------------
for m in rtr_setup rtr_scan; do
  python3 /work/scripts/gds/verify_block.py "$m" || exit 1
done
[ -f synth.v ] || { echo "missing synth.v (run make_rtr_top_netlist.sh)"; exit 1; }
rm -f final.def global_route.def route_drc.rpt openroad.log magic.log "rtr_top.gds"

# ---- macro LEF abstracts from the two hardened blocks ------------------------
for m in rtr_setup rtr_scan; do
  openroad -python -no_init -exit \
    /work/scripts/gds/make_block_macro_lef.py \
    "/work/build/gds/$m/final.def" "ember_$m" "/work/build/gds/$m/$m.lef" \
    > "lef_$m.log" 2>&1 || { echo "LEF FAIL $m"; tail -5 "lef_$m.log"; exit 1; }
done

python3 /work/scripts/gds/check_macro_interfaces.py synth.json ember_rtr_top \
  rtr_setup rtr_scan || exit 1

# ---- 1/4 OpenROAD: floorplan, macro placement, glue PnR, PDN, route ----------
# Macro geometry from the LEFs; setup 130x130, scan ~300x180 estimated here
# from their gds_validation.json at generation time. Grid: setup left, scan
# right, glue band below; channels 40 um.
cat > pnr.tcl <<EOF
read_liberty $LIB
read_lef $PDK/libs.ref/sky130_fd_sc_hd/techlef/sky130_fd_sc_hd__nom.tlef
read_lef $PDK/libs.ref/sky130_fd_sc_hd/lef/sky130_fd_sc_hd.lef
read_lef /work/build/gds/rtr_setup/rtr_setup.lef
read_lef /work/build/gds/rtr_scan/rtr_scan.lef
read_verilog /work/build/gds/rtr_top/synth.v
link_design $TOP

# die: sum of macro extents + channels + glue band + margins (auto-sized below
# from the actual macro LEF sizes read from the DB).
set dbu 1000
set su_master [[ord::get_db] findMaster ember_rtr_setup]
set sc_master [[ord::get_db] findMaster ember_rtr_scan]
set su_w [expr {[\$su_master getWidth] / double(\$dbu)}]
set su_h [expr {[\$su_master getHeight] / double(\$dbu)}]
set sc_w [expr {[\$sc_master getWidth] / double(\$dbu)}]
set sc_h [expr {[\$sc_master getHeight] / double(\$dbu)}]
set band_h [expr {\$su_h > \$sc_h ? \$su_h : \$sc_h}]
set die_w [expr {25 + \$su_w + 40 + \$sc_w + 25}]
set die_h [expr {25 + \$band_h + 40 + 120 + 25}]
initialize_floorplan -die_area [list 0 0 \$die_w \$die_h] \
    -core_area [list 25 [expr {25 + \$band_h + 40}] [expr {\$die_w - 25}] [expr {\$die_h - 25}]] -site unithd
make_tracks
proc place_ember_macro {inst_name x y} {
  set block [ord::get_db_block]
  set inst [\$block findInst \$inst_name]
  if {\$inst == "NULL"} { error "macro instance \$inst_name not found" }
  \$inst setOrient R0
  \$inst setOrigin [expr int(round(\$x * 1000))] [expr int(round(\$y * 1000))]
  \$inst setPlacementStatus FIRM
  puts "placed \$inst_name at (\$x, \$y)"
}
place_ember_macro u_setup 25 25
place_ember_macro u_scan [expr {25 + \$su_w + 40}] 25

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
define_pdn_grid -name macros -macro -cells {ember_rtr_setup ember_rtr_scan} -pins {met1 met4 met5}
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

# ---- 2/4 Magic DRC (macros as LEF abstracts; glue + routing checked) ---------
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
lef read /work/build/gds/rtr_setup/rtr_setup.lef
lef read /work/build/gds/rtr_scan/rtr_scan.lef
def read $DEF
load $TOP -dereference
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
EOFMAG
timeout 2700 magic -rcfile .magicrc -dnull -noconsole magic.tcl > magic.log 2>&1 \
  || echo "MAGIC FAIL (KLayout merge still runs; audit decides)"
grep -m1 DRC_COUNT magic.log || echo "DRC_COUNT=?"


# ---- 3/4 KLayout merged GDS: real setup/scan geometry inside the block -------
PDK="$PDK" KLAYOUT_BLOCKS="rtr_setup rtr_scan" KLAYOUT_TOP="$TOP" \
KLAYOUT_DEF="$OUT/$DEF" KLAYOUT_OUT="$OUT/rtr_top.gds" \
  klayout -b -r /work/scripts/gds/die_def2gds.py > klayout_def.log 2>&1 \
  || { echo "KLAYOUT MERGE FAIL"; tail -12 klayout_def.log; exit 2; }
KLAYOUT_IN="rtr_top.gds" KLAYOUT_OUT="rtr_top_final.gds" KLAYOUT_TOP=$TOP \
  klayout -b -r /work/scripts/gds/finalize.py > klayout.log 2>&1 \
  || { echo "GDS VALIDATION FAILED"; tail -10 klayout.log; exit 2; }
mv "rtr_top_final.gds" "rtr_top.gds"
ls -la "rtr_top.gds"

# ---- 4/4 independent zero-DRC audit of the merged GDS ------------------------
python3 /work/scripts/gds/audit_export.py rtr_top > export_audit_run.log 2>&1 \
  || { echo "EXPORTED GDS AUDIT FAILED"; tail -10 export_audit_run.log; exit 4; }
EDRC=$(python3 -c 'import json; print(json.load(open("export_audit.json"))["whole_layout_flattened_drc"])')
MDRC=$(grep '^DRC_COUNT=' magic.log | tail -1)
RDRC=$(grep 'Number of violations =' openroad.log | tail -1)
if [[ "$RDRC" != *'= 0.'* ]] || [ "$MDRC" != 'DRC_COUNT=0' ] || [ "$EDRC" != 0 ]; then
  echo "RTR_TOP GDS GENERATED, CHECKS NOT CLEAN: routing=[$RDRC] magic=[$MDRC] audit=$EDRC"
  exit 4
fi
echo "== [ember_rtr_top] DONE (validated merged GDS, routing and Magic DRC zero) =="
