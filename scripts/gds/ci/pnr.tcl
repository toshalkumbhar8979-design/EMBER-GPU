# pnr.tcl -- staged place/route for the three un-hardened Ember blocks.
#
# Why this file exists: harden_block.sh runs synth + P&R + Magic in one process
# with a 12-24 h timebox. That cannot run on a GitHub-hosted runner (6 h job
# cap), and when it is cut off it leaves nothing usable behind. This script runs
# ONE stage, writes a checkpoint, and exits, so each stage is its own CI job:
#
#   CI_STAGE=place  synth.v      -> placed.odb, placed.def
#   CI_STAGE=grt    placed.odb   -> grt.odb, global_route.def
#   CI_STAGE=drt    grt.odb      -> final.odb, final.def
#
# The recipe (PDN, probe purge, pin padding, layer tilt, DRT iteration count) is
# copied verbatim from scripts/gds/harden_block.sh ON PURPOSE: that script is
# the reference for the nine blocks that are already signed off (with zero
# routing and Magic DRC), and the instruction is not to disturb them. Keep the
# two in sync when the recipe changes.
#
# Environment:
#   CI_BLOCK, CI_TOP, CI_STAGE, GDS_ROOT, GDS_PDK
#   GDS_UTIL, GDS_PL_DENSITY, GDS_PL_PAD, GDS_GRT_TILT, GDS_DRT_ITER
#   GDS_THREADS, GDS_REPAIR_TIMING, GDS_TIMING_PASSES, GDS_REPAIR_TNS

proc envdef {name fallback} {
  if {[info exists ::env($name)] && $::env($name) ne ""} {
    return $::env($name)
  }
  return $fallback
}

set block  $::env(CI_BLOCK)
set top    $::env(CI_TOP)
set stage  [envdef CI_STAGE all]
set root   [envdef GDS_ROOT /work]
set pdk    $::env(GDS_PDK)
set out    "$root/build/gds/$block"
set lib    "$pdk/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__tt_025C_1v80.lib"
set techlef "$pdk/libs.ref/sky130_fd_sc_hd/techlef/sky130_fd_sc_hd__nom.tlef"
set celllef "$pdk/libs.ref/sky130_fd_sc_hd/lef/sky130_fd_sc_hd.lef"

set util     [envdef GDS_UTIL 20]
set density  [envdef GDS_PL_DENSITY 0.30]
set pad      [envdef GDS_PL_PAD 0]
set tilt     [envdef GDS_GRT_TILT ""]
set drt_iter [envdef GDS_DRT_ITER 20]
set threads  [envdef GDS_THREADS 4]
set do_timing [envdef GDS_REPAIR_TIMING 1]
set tpasses  [envdef GDS_TIMING_PASSES 2]
set rtns     [envdef GDS_REPAIR_TNS 10]

cd $out
read_liberty $lib
read_lef $techlef
read_lef $celllef
set_thread_count $threads

# ---------------------------------------------------------------- resume ----
# ODB checkpoints keep placement, CTS results, PDN shapes and the tech together.
# Liberty is not stored in an ODB, so it is re-read above for every stage.
if {$stage eq "grt" || $stage eq "drt"} {
  set prev [expr {$stage eq "grt" ? "placed.odb" : "grt.odb"}]
  if {![file exists $prev]} {
    puts "MISSING_CHECKPOINT: $out/$prev"
    exit 3
  }
  puts "RESUME: reading $prev"
  read_db $prev
  # These are OpenROAD tool state, not database state; re-apply them so a
  # resumed stage routes on exactly the same layers as a one-shot run.
  set_routing_layers -signal met2-met5 -clock met2-met5
  set_dont_use {sky130_fd_sc_hd__probe_p_8 sky130_fd_sc_hd__probec_p_8}
  set_wire_rc -signal -layer met2
  set_wire_rc -clock -layer met3
  if {![catch {get_ports clk}]} { create_clock -name clk -period 20.0 [get_ports clk] }
}

# ------------------------------------------------------- floorplan + place ---
if {$stage eq "place" || $stage eq "all"} {
  read_verilog synth.v
  link_design $top

  # PPL-0024 guard: place_pins needs ~1 um of perimeter per IO bit.
  set npins 0
  set blk [ord::get_db_block]
  foreach bterm [$blk getBTerms] { incr npins }
  set min_side [expr {$npins / 4.0 + 30.0}]
  initialize_floorplan -utilization $util -aspect_ratio 1.0 -core_space 10 -site unithd
  set diebox [$blk getDieArea]
  set dw [expr {[$diebox dx] / 1000}]
  set dh [expr {[$diebox dy] / 1000}]
  if {$dw < $min_side || $dh < $min_side} {
    initialize_floorplan -die_area [list 0 0 $min_side $min_side] \
      -core_area [list 10 10 [expr {$min_side - 10}] [expr {$min_side - 10}]] -site unithd
  }
  make_tracks
  # met1 is pin-access only; signal routing lives on met2..met5.
  set_routing_layers -signal met2-met5 -clock met2-met5
  place_pins -random -hor_layers met1 -ver_layers met2
  if {![catch {get_ports clk}]} { create_clock -name clk -period 20.0 [get_ports clk] }
  set_wire_rc -signal -layer met2
  set_wire_rc -clock -layer met3
  # Probe masters carry met4/met5 pads that collide with PDN stripes.
  set_dont_use {sky130_fd_sc_hd__probe_p_8 sky130_fd_sc_hd__probec_p_8}

  global_placement -routability_driven -density $density
  if {$pad > 0} {
    set_placement_padding -global -left $pad -right $pad
    puts "PL_PAD: $pad site(s) left/right per cell"
  }
  estimate_parasitics -placement
  repair_design
  detailed_placement
  clock_tree_synthesis
  estimate_parasitics -placement
  # repair_timing is the stage that sat for 30+ minutes on core in the local
  # run; CI turns it off by default (GDS_REPAIR_TIMING=0) because timing
  # closure is explicitly out of scope for this evaluation flow.
  if {$do_timing == 1} {
    repair_timing -max_passes $tpasses -repair_tns $rtns
  } else {
    puts "REPAIR_TIMING: skipped (GDS_REPAIR_TIMING=0)"
  }
  if {[catch {tapcell -distance 14 -tapcell_master sky130_fd_sc_hd__tapvpwrvgnd_1} tmsg]} {
    puts "TAPCELL_WARN: $tmsg"
  }
  detailed_placement

  # PDN. Without this every cell's rails float and TritonRoute shorts against
  # them (cp: 7416 met1 shorts at iteration 0, one per cell).
  add_global_connection -net VPWR -inst_pattern .* -pin_pattern ^VPWR$ -power
  add_global_connection -net VPWR -inst_pattern .* -pin_pattern ^VPB$ -power
  add_global_connection -net VGND -inst_pattern .* -pin_pattern ^VGND$ -ground
  add_global_connection -net VGND -inst_pattern .* -pin_pattern ^VNB$ -ground
  global_connect
  set_voltage_domain -name CORE -power VPWR -ground VGND
  define_pdn_grid -name stdcell -voltage_domains CORE
  add_pdn_stripe -grid stdcell -layer met1 -width 0.48 -followpins
  add_pdn_stripe -grid stdcell -layer met4 -width 1.6 -pitch 27.14 -offset 13.57
  add_pdn_stripe -grid stdcell -layer met5 -width 1.6 -pitch 27.2 -offset 13.6
  add_pdn_connect -grid stdcell -layers {met1 met4}
  add_pdn_connect -grid stdcell -layers {met4 met5} -cut_pitch 1.3
  pdngen

  # Delete any probe-family instance the resizer inserted (no logical function,
  # but its landing pads violate met4/via4 spacing next to the PDN).
  set purged 0
  set pb [ord::get_db_block]
  foreach inst [$pb getInsts] {
    if {[string first "probe" [[$inst getMaster] getName]] >= 0} {
      odb::dbInst_destroy $inst
      incr purged
    }
  }
  puts "PROBE_PURGE: removed $purged probe-family instances before route"

  write_db placed.odb
  write_def placed.def
  if {$stage eq "place"} {
    puts "STAGE_PLACE_CHECKPOINT: $out/placed.odb"
    exit 0
  }
}

# ------------------------------------------------------------ global route --
if {$stage eq "grt" || $stage eq "all"} {
  if {$tilt ne ""} {
    set_global_routing_layer_adjustment met2 $tilt
    puts "GRT_TILT: met2 capacity reduced by $tilt"
  }
  global_route
  write_def global_route.def
  write_db grt.odb
  if {$stage eq "grt"} {
    puts "STAGE_GRT_CHECKPOINT: $out/grt.odb"
    exit 0
  }
}

# ---------------------------------------------------------- detailed route --
if {$stage eq "drt" || $stage eq "all"} {
  if {![file exists grt.odb] && $stage eq "drt"} {
    puts "MISSING_CHECKPOINT: $out/grt.odb"
    exit 3
  }
  detailed_route -bottom_routing_layer met1 -top_routing_layer met5 \
    -output_drc route_drc.rpt -drc_report_iter_step 2 \
    -droute_end_iter $drt_iter -verbose 1

  # Filler AFTER route: fillers have no pins, so placing them earlier only
  # steals routing whitespace.
  if {[catch {filler_placement {sky130_fd_sc_hd__fill_1 sky130_fd_sc_hd__fill_2 sky130_fd_sc_hd__fill_4 sky130_fd_sc_hd__fill_8}} fmsg]} {
    puts "FILLER_WARN: $fmsg"
  }
  if {[envdef GDS_WRITE_FINAL_ODB 1] == 1} { write_db final.odb }
  write_def final.def
  write_verilog final_nl.v
  report_design_area
  # report_design_area only prints; compute the core area for the CI metrics.
  set _blk [ord::get_db_block]
  set _ca [$_blk getCoreArea]
  puts [format "CORE_AREA_UM2=%.1f" [expr {double([$_ca dx]) * double([$_ca dy]) / 1e6}]]
  if {![catch {get_ports clk}]} {
    create_clock -name clk -period 20.0 [get_ports clk]
  }
  report_wns
  report_tns
}

puts "STAGE_DONE: block=$block stage=$stage"
