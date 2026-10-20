# Dump dbViaParams (cut size/spacing/counts) for the two PDN via defs of
# interest + tally VPWR/VGND via usage. This settles the via4.2 question.
read_db /work/build/gds/fpu4/final.odb
set block [ord::get_db_block]

puts "== VIA PARAMS =="
foreach name {via5_6_1600_1600_1_1_1300_1300 via4_5_1600_480_1_4_400_400} {
  set bv [$block findVia $name]
  if {$bv == "NULL"} { puts "$name NOT FOUND"; continue }
  puts "VIA $name bottom=[[$bv getBottomLayer] getName] top=[[$bv getTopLayer] getName]"
  set p [$bv getViaParams]
  puts "  cutSize=[$p getXCutSize]x[$p getYCutSize] spacing=[$p getXCutSpacing]x[$p getYCutSpacing] rows=[$p getNumCutRows] cols=[$p getNumCutCols]"
  puts "  encBottom=[$p getXBottomEnclosure]x[$p getYBottomEnclosure] encTop=[$p getXTopEnclosure]x[$p getYTopEnclosure]"
  foreach b [$bv getBoxes] {
    puts "  box [[$b getTechLayer] getName] [$b xMin] [$b yMin] [$b xMax] [$b yMax]"
  }
}

puts "== VPWR/VGND via tally =="
array set cnt {}
foreach net [$block getNets] {
  set nn [$net getName]
  if {$nn ne "VPWR" && $nn ne "VGND"} { continue }
  foreach sw [$net getSWires] {
    foreach w [$sw getWires] {
      if {![$w isVia]} { continue }
      set n "anon"
      catch {
        set bt [$w getBlockVia]
        if {$bt != "NULL"} { set n [$bt getName] }
      }
      set key "$nn $n"
      if {[info exists cnt($key)]} { incr cnt($key) } else { set cnt($key) 1 }
    }
  }
}
foreach k [array names cnt] { puts "  $k x$cnt($k)" }
puts "PROBE_DONE"
