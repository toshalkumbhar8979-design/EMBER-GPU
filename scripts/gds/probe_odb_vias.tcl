# Probe fpu4 final.odb for PDN via arrays / wires near DRC violation sites.
# Site V (via4.2): lambda (199.51..200.69, 962.29..962.62) um -> DBU x1e3
# Site M (met4.2): lambda (1584.85..1585.34, 574.48..576.26) um -> DBU x1e3
read_db /work/build/gds/fpu4/final.odb
set block [ord::get_db_block]
set dbu [$block getDefUnits]
puts "DBU=$dbu"

proc rect_hits {lay lo_x lo_y hi_x hi_y tag} {
  set block [ord::get_db_block]
  set n 0
  # Wires (PG + routing) on this layer
  foreach net [$block getNets] {
    foreach sw [$net getSWires] {
      foreach w [$sw getWires] {
        if {[$w isVia]} { continue }
        if {[$w getTechLayer] == "NULL"} { continue }
        if {[[$w getTechLayer] getName] ne $lay} { continue }
        set x1 [$w xMin]; set y1 [$w yMin]; set x2 [$w xMax]; set y2 [$w yMax]
        if {$x1 <= $hi_x && $x2 >= $lo_x && $y1 <= $hi_y && $y2 >= $lo_y} {
          puts "$tag WIRE [$net getName] $lay $x1 $y1 $x2 $y2"
          incr n
          if {$n > 40} { return }
        }
      }
    }
  }
}

# via arrays: dbVia + block obstructions not needed; scan sboxes incl vias
proc via_hits {lo_x lo_y hi_x hi_y tag} {
  set block [ord::get_db_block]
  foreach net [$block getNets] {
    foreach sw [$net getSWires] {
      foreach w [$sw getWires] {
        if {![$w isVia]} { continue }
        set x1 [$w xMin]; set y1 [$w yMin]; set x2 [$w xMax]; set y2 [$w yMax]
        if {$x1 <= $hi_x && $x2 >= $lo_x && $y1 <= $hi_y && $y2 >= $lo_y} {
          set bt [$w getBlockVia]
          set name "anon"
          if {$bt != "NULL" && $bt ne "NULL"} { set name [$bt getName] }
          puts "$tag VIA [$net getName] $name  $x1 $y1 $x2 $y2"
        }
      }
    }
  }
}

set V_LOX 199000; set V_LOY 961500; set V_HIX 201500; set V_HIY 963500
set M_LOX 1583000; set M_LOY 573500; set M_HIX 1587000; set M_HIY 577500

puts "== SITE V (via4) met4 wires =="
rect_hits met4 $V_LOX $V_LOY $V_HIX $V_HIY V
puts "== SITE V met5 wires =="
rect_hits met5 $V_LOX $V_LOY $V_HIX $V_HIY V
puts "== SITE V vias (all) =="
via_hits $V_LOX $V_LOY $V_HIX $V_HIY V
puts "== SITE M (met4) wires =="
rect_hits met4 $M_LOX $M_LOY $M_HIX $M_HIY M
puts "== SITE M met5 wires =="
rect_hits met5 $M_LOX $M_LOY $M_HIX $M_HIY M
puts "== SITE M vias (all) =="
via_hits $M_LOX $M_LOY $M_HIX $M_HIY M
puts "PROBE_DONE"
