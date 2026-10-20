lef read /root/.volare/volare/sky130/versions/fa87f8f4bbcc7255b6f0c0fb506960f531ae2392/sky130A/libs.ref/sky130_fd_sc_hd/techlef/sky130_fd_sc_hd__nom.tlef
# Full masters FIRST: load the entire standard-cell GDS into memory so every
# child of the DEF is a FULL view. (LEF abstracts + addpath were not enough:
# 'load -dereference' still left fill_8 abstract and the GDS writer refused
# with 'Cell ... is an abstract view; cannot write GDS'.) The cell LEF is not
# read at all: DEF read instantiates the GDS-loaded masters directly.
gds read /root/.volare/volare/sky130/versions/fa87f8f4bbcc7255b6f0c0fb506960f531ae2392/sky130A/libs.ref/sky130_fd_sc_hd/gds/sky130_fd_sc_hd.gds
def read final.def
load ember_display -dereference
# NOTE: no 'property LEFview NoPinLabels' here -- applied to the just-loaded
# TOP cell it marks the whole design as an abstract view and the GDS writer
# refuses (the display test run produced a 66-byte empty GDS that way).
# Comments inside an unquoted heredoc must never contain backticks: bash runs
# them as command substitutions.
gds write display.gds
# Check a flattened COPY of the placed design: sky130 tapless cell masters
# fail well-tap rules in isolation even though neighbouring tap cells satisfy
# them in the actual layout. Streamout above keeps the original hierarchy.
flatten ember_display_drc_flat
load ember_display_drc_flat
select top cell
box select
drc on
drc style drc(full)
drc check
drc catchup
set drcerr [drc list count total]
puts "DRC_DETAILS=[drc listall why]"
puts "DRC_COUNT=$drcerr"
