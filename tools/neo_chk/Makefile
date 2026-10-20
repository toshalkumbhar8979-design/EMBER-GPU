# neo_chk — NEORV32 sim-side gate: run sw/ember_demo.c (bare-metal host
# code over cp_driver.h) against the full ember_top through an AXI-Lite
# master model in C++. Same Verilator probe pattern as tools/pool_chk.
RTL_DIR   := ../../rtl
SW_DIR    := ../../sw
TOP       := ember_top

VERILATOR := verilator

VSRCS := $(RTL_DIR)/ember_pkg.sv $(RTL_DIR)/ember_vram.sv \
         $(RTL_DIR)/ember_ram_slave.sv $(RTL_DIR)/ember_xbar.sv \
         $(RTL_DIR)/ember_cp.sv $(RTL_DIR)/ember_fpu4.sv \
         $(RTL_DIR)/ember_gsx.sv $(RTL_DIR)/ember_core.sv \
         $(RTL_DIR)/ember_tu.sv $(RTL_DIR)/ember_rtr_setup.sv \
         $(RTL_DIR)/ember_rtr_scan.sv $(RTL_DIR)/ember_rtr_top.sv \
         $(RTL_DIR)/ember_display.sv $(RTL_DIR)/ember_blit.sv \
         $(RTL_DIR)/ember_top.sv

# The demo is compiled as the "firmware": main->demo_main, MMIO hooked.
DEMO_CFLAGS := -I../../../sw -Dmain=demo_main \
               -Dcp_mmio_write=ember_register_write \
               -Dcp_mmio_read=ember_register_read \
               -Wno-unknown-pragmas

all: obj_dir/V$(TOP)

obj_dir/V$(TOP): $(VSRCS) $(SW_DIR)/ember_demo.c $(SW_DIR)/cp_driver.h \
                 $(SW_DIR)/scene_data.h $(SW_DIR)/gamestate_words.h \
                 $(SW_DIR)/demo_inputs.h $(SW_DIR)/mvp_base.h main.cpp
	$(VERILATOR) --cc --exe --build -j 4 --timing -O2 \
	  --top-module $(TOP) -Wno-fatal -I$(RTL_DIR) \
	  $(VSRCS) \
	  --CFLAGS "$(DEMO_CFLAGS)" \
	  $(SW_DIR)/ember_demo.c main.cpp

run: obj_dir/V$(TOP)
	./obj_dir/V$(TOP)

clean:
	rm -rf obj_dir neo_frame_*.ppm

.PHONY: all run clean
