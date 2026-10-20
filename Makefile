# Ember GPU — Phase 1 build/test
#
# Targets:
#   make lint  — Verilator lint of all RTL
#   make test  — cocotb (Verilator) run of test/tb_memory.py
#   make clean

TOP       := ember_top
VERILATOR := verilator
RTL := rtl/ember_pkg.sv rtl/ember_vram.sv rtl/ember_ram_slave.sv \
       rtl/ember_xbar.sv rtl/ember_cp.sv rtl/ember_fpu4.sv rtl/ember_gsx.sv \
       rtl/ember_core.sv rtl/ember_tu.sv rtl/ember_top.sv

.PHONY: lint test clean

lint:
	$(VERILATOR) --lint-only -Wall -Wno-fatal -Irtl \
	  --top-module $(TOP) $(RTL)

test:
	$(MAKE) -C test test

clean:
	$(MAKE) -C test clean
	rm -rf sim_build
