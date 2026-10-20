#!/usr/bin/env python3
"""ember_top -> ember_die: remove the on-chip flop-array VRAM and promote every
VRAM-facing net to a top-level port, so the integrated die is the GPU logic
with an external SRAM memory interface (a 512 KiB flop array cannot be mapped
to std cells; real implementations use SRAM macros).

Transformations (exact-match, fail loudly):
  1. module/endmodule rename ember_top -> ember_die
  2. dbg_rdata becomes an input (VRAM drove it)
  3. VRAM-facing nets added to the port list
  4. `ember_vram u_vram (...)` instance deleted
  5. duplicate internal declarations of promoted nets deleted
"""
from pathlib import Path

src = Path('rtl/ember_top.sv').read_text()

# 1. rename module
assert 'module ember_top' in src and 'endmodule : ember_top' in src
src = src.replace('module ember_top', 'module ember_die', 1)
src = src.replace('endmodule : ember_top', 'endmodule : ember_die', 1)

# 2. dbg_rdata: was output (driven by u_vram), now input at the die boundary
old = '  output logic [31:0]        dbg_rdata,'
assert old in src
src = src.replace(old, '  input  logic [31:0]        dbg_rdata,', 1)

# 3. add VRAM-interface ports at the end of the port list
ports = '''  output logic [15:0]        vid_pixel,

  // ------------------------------------------------------------------
  // External VRAM interface (on-chip flop array moved off die; pin-out
  // identical to the u_vram instance it replaces)
  // ------------------------------------------------------------------
  output axil_aw_t           v_aw,  output logic v_awvalid, input  logic v_awready,
  output axil_w_t            v_w,   output logic v_wvalid,  input  logic v_wready,
  input  axil_b_t            v_b,   input  logic v_bvalid,  output logic v_bready,
  output axil_ar_t           v_ar,  output logic v_arvalid, input  logic v_arready,
  input  axil_r_t            v_r,   input  logic v_rvalid,  output logic v_rready,
  output logic               fpa_we,
  output logic [31:0]        fpa_addr, fpa_wdata,
  output logic [3:0]         fpa_be,
  output logic               fpa_req,
  input  logic [31:0]        fpa_rdata,
  output logic               fpa2_we,
  output logic [31:0]        fpa2_addr, fpa2_wdata,
  output logic [3:0]         fpa2_be,
  output logic               fpa2_req,
  input  logic [31:0]        fpa2_rdata,
  output logic               fpa3_req,
  output logic [31:0]        fpa3_addr,
  input  logic [31:0]        fpa3_rdata,
  output logic               gxa_we,
  output logic [31:0]        gxa_addr, gxa_wdata,
  output logic [3:0]         gxa_be,
  output logic               gxa_req,
  input  logic [31:0]        gxa_rdata,
  output logic               cxa_we,
  output logic [31:0]        cxa_addr, cxa_wdata,
  output logic [3:0]         cxa_be,
  output logic               cxa_req,
  input  logic [31:0]        cxa_rdata,
  output logic               ixa_req,
  output logic [31:0]        ixa_addr,
  input  logic [31:0]        ixa_rdata,
  output logic               tua_we,
  output logic [31:0]        tua_addr, tua_wdata,
  output logic [3:0]         tua_be,
  output logic               tua_req,
  input  logic [31:0]        tua_rdata
);'''
old = '  output logic [15:0]        vid_pixel\n);'
assert old in src
src = src.replace(old, ports, 1)

# delete the u_vram instance
i = src.find('  ember_vram u_vram (')
assert i > 0, 'u_vram instance not found'
j = src.find('  );', i)
assert j > 0
src = src[:i] + src[j + len('  );\n'):]

# 5. drop internal declarations that are now ports
for decl in (
    '  axil_aw_t  v_aw;  logic v_awvalid, v_awready;\n'
    '  axil_w_t   v_w;   logic v_wvalid,  v_wready;\n'
    '  axil_b_t   v_b;   logic v_bvalid,  v_bready;\n'
    '  axil_ar_t  v_ar;  logic v_arvalid, v_arready;\n'
    '  axil_r_t   v_r;   logic v_rvalid,  v_rready;\n',
    '  logic        fpa_we;\n'
    '  logic [31:0] fpa_addr, fpa_wdata;\n'
    '  logic [3:0]  fpa_be;\n'
    '  logic        fpa_req;\n'
    '  logic [31:0] fpa_rdata;\n',
    '  logic        fpa2_we;\n'
    '  logic [31:0] fpa2_addr, fpa2_wdata;\n'
    '  logic [3:0]  fpa2_be;\n'
    '  logic        fpa2_req;\n'
    '  logic [31:0] fpa2_rdata;  logic        fpa3_req;\n'
    '  logic [31:0] fpa3_addr;\n'
    '  logic [31:0] fpa3_rdata;\n',
    '  logic        gsx_gxa_we;\n'
    '  logic [31:0] gsx_gxa_addr, gsx_gxa_wdata;\n'
    '  logic [3:0]  gsx_gxa_be;\n'
    '  logic        gsx_gxa_req;\n'
    '  logic [31:0] gsx_gxa_rdata;\n',
    '  logic        core_cxa_we;\n'
    '  logic [31:0] core_cxa_addr, core_cxa_wdata;\n'
    '  logic [3:0]  core_cxa_be;\n'
    '  logic        core_cxa_req;\n'
    '  logic [31:0] core_cxa_rdata;\n',
    '  logic        core_ixa_req;\n'
    '  logic [31:0] core_ixa_addr;\n'
    '  logic [31:0] core_ixa_rdata;\n',
    '  logic        tu_tua_we;\n'
    '  logic [31:0] tu_tua_addr, tu_tua_wdata;\n'
    '  logic [3:0]  tu_tua_be;\n'
    '  logic        tu_tua_req;\n'
    '  logic [31:0] tu_tua_rdata;\n',
):
    assert decl in src, f'declaration block not found:\n{decl}'
    src = src.replace(decl, '', 1)

# Redirect accelerator-side memory nets to their promoted die ports. Without
# this mapping, implicit gsx_/core_/tu_ nets leave the memory interface floating.
for old_name, port_name in (
    ('gsx_gxa', 'gxa'), ('core_cxa', 'cxa'),
    ('core_ixa', 'ixa'), ('tu_tua', 'tua'),
):
    src = src.replace(old_name + '_', port_name + '_')
src = src.replace('module ember_die', '`default_nettype none\nmodule ember_die', 1)
src += '\n`default_nettype wire\n'
Path('rtl/ember_die.sv').write_text(src)
print('rtl/ember_die.sv written:', len(src), 'bytes')
