# cocotb 2.x runner flow for the Ember Phase-1 testbench
TOPLEVEL_LANG    := verilog
SIM              := verilator
COMPILE_ARGS     += --timing -I../rtl
# Verilator 5.046 (native WSL2) promotes WIDTHEXPAND to fatal; the single
# instance (ember_core.sv constant add) is benign and was clean on the old tool.
COMPILE_ARGS     += -Wno-WIDTHEXPAND
TOPLEVEL         := ember_top
MODULE           := tb_memory,tb_rtr,tb_display,tb_blit,tb_gsx,tb_core,tb_tu,tb_tex,tb_mnist,tb_scene,tb_mnist_e2e,tb_pool,tb_anim,tb_mnist_acc,tb_fly,tb_input,tb_doom
VERILOG_SOURCES  := ../rtl/ember_pkg.sv ../rtl/ember_vram.sv ../rtl/ember_ram_slave.sv \
                    ../rtl/ember_xbar.sv ../rtl/ember_cp.sv ../rtl/ember_fpu4.sv \
                    ../rtl/ember_gsx.sv ../rtl/ember_core.sv ../rtl/ember_tu.sv \
                    ../rtl/ember_rtr_setup.sv \
                    ../rtl/ember_rtr_scan.sv ../rtl/ember_rtr_top.sv ../rtl/ember_display.sv \
                    ../rtl/ember_blit.sv ../rtl/ember_top.sv

include $(shell cocotb-config --makefiles)/Makefile.sim
