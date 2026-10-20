// memif_tb.sv — testbench wrapper for ember_memif.
//
// Wraps the external memory controller with three behavioral SRAM models
// (async read / sync write = the "read-old-data" simple-dual-port device the
// EMC requires; see sram_model.sv) and flattens the struct AXI port for
// cocotb, exactly like ember_die does for its host port.

`include "ember_pkg.sv"
import ember_pkg::*;

module memif_tb
(
  input  logic        clk,
  input  logic        rst_n,

  // AXI4-Lite (flat)
  input  logic [31:0] v_awaddr,
  input  logic        v_awvalid,
  output logic        v_awready,
  input  logic [31:0] v_wdata,
  input  logic [3:0]  v_wstrb,
  input  logic        v_wvalid,
  output logic        v_wready,
  output logic [1:0]  v_bresp,
  output logic        v_bvalid,
  input  logic        v_bready,
  input  logic [31:0] v_araddr,
  input  logic        v_arvalid,
  output logic        v_arready,
  output logic [31:0] v_rdata,
  output logic [1:0]  v_rresp,
  output logic        v_rvalid,
  input  logic        v_rready,

  // fast ports (fixed 1-cycle read latency)
  input  logic        fpa_we,
  input  logic [31:0] fpa_addr, fpa_wdata,
  input  logic [3:0]  fpa_be,
  input  logic        fpa_req,
  output logic [31:0] fpa_rdata,
  input  logic        fpa2_we,
  input  logic [31:0] fpa2_addr, fpa2_wdata,
  input  logic [3:0]  fpa2_be,
  input  logic        fpa2_req,
  output logic [31:0] fpa2_rdata,
  input  logic        fpa3_req,
  input  logic [31:0] fpa3_addr,
  output logic [31:0] fpa3_rdata,
  input  logic        gxa_we,
  input  logic [31:0] gxa_addr, gxa_wdata,
  input  logic [3:0]  gxa_be,
  input  logic        gxa_req,
  output logic [31:0] gxa_rdata,
  input  logic        cxa_we,
  input  logic [31:0] cxa_addr, cxa_wdata,
  input  logic [3:0]  cxa_be,
  input  logic        cxa_req,
  output logic [31:0] cxa_rdata,
  input  logic        ixa_req,
  input  logic [31:0] ixa_addr,
  output logic [31:0] ixa_rdata,
  input  logic        tua_we,
  input  logic [31:0] tua_addr, tua_wdata,
  input  logic [3:0]  tua_be,
  input  logic        tua_req,
  output logic [31:0] tua_rdata
);

  // flat -> struct (same adapter style as ember_die's host port)
  axil_aw_t v_aw_s;  axil_w_t v_w_s;
  axil_b_t  v_b_s;   axil_ar_t v_ar_s;  axil_r_t v_r_s;

  assign v_aw_s  = axil_aw_t'{addr: v_awaddr, prot: 3'b000};
  assign v_w_s   = axil_w_t'{data: v_wdata,  strb: v_wstrb};
  assign v_ar_s  = axil_ar_t'{addr: v_araddr, prot: 3'b000};
  assign v_bresp = v_b_s.resp;
  assign v_rdata = v_r_s.data;
  assign v_rresp = v_r_s.resp;

  logic v_awvalid_i, v_awready_i, v_wvalid_i, v_wready_i;
  logic v_bvalid_i, v_bready_i, v_arvalid_i, v_arready_i;
  logic v_rvalid_i, v_rready_i;
  assign v_awvalid_i = v_awvalid;  assign v_awready = v_awready_i;
  assign v_wvalid_i  = v_wvalid;   assign v_wready  = v_wready_i;
  assign v_bvalid    = v_bvalid_i; assign v_bready_i = v_bready;
  assign v_arvalid_i = v_arvalid;  assign v_arready = v_arready_i;
  assign v_rvalid    = v_rvalid_i; assign v_rready_i = v_rready;

  // memory-side nets
  logic [16:0] mem_waddr;
  logic [31:0] mem_wdata;
  logic [3:0]  mem_wbe_n;
  logic        mem_we_n;
  logic [16:0] mem0_raddr, mem1_raddr, mem2_raddr;
  logic [31:0] mem0_rdata, mem1_rdata, mem2_rdata;
  logic        mem0_re_n,  mem1_re_n,  mem2_re_n;

  ember_memif u_emc
  (
    .clk(clk), .rst_n(rst_n),
    .v_aw(v_aw_s), .v_awvalid(v_awvalid_i), .v_awready(v_awready_i),
    .v_w(v_w_s), .v_wvalid(v_wvalid_i), .v_wready(v_wready_i),
    .v_b(v_b_s), .v_bvalid(v_bvalid_i), .v_bready(v_bready_i),
    .v_ar(v_ar_s), .v_arvalid(v_arvalid_i), .v_arready(v_arready_i),
    .v_r(v_r_s), .v_rvalid(v_rvalid_i), .v_rready(v_rready_i),
    .fpa_we(fpa_we), .fpa_addr(fpa_addr), .fpa_wdata(fpa_wdata),
    .fpa_be(fpa_be), .fpa_req(fpa_req), .fpa_rdata(fpa_rdata),
    .fpa2_we(fpa2_we), .fpa2_addr(fpa2_addr), .fpa2_wdata(fpa2_wdata),
    .fpa2_be(fpa2_be), .fpa2_req(fpa2_req), .fpa2_rdata(fpa2_rdata),
    .fpa3_req(fpa3_req), .fpa3_addr(fpa3_addr), .fpa3_rdata(fpa3_rdata),
    .gxa_we(gxa_we), .gxa_addr(gxa_addr), .gxa_wdata(gxa_wdata),
    .gxa_be(gxa_be), .gxa_req(gxa_req), .gxa_rdata(gxa_rdata),
    .cxa_we(cxa_we), .cxa_addr(cxa_addr), .cxa_wdata(cxa_wdata),
    .cxa_be(cxa_be), .cxa_req(cxa_req), .cxa_rdata(cxa_rdata),
    .ixa_req(ixa_req), .ixa_addr(ixa_addr), .ixa_rdata(ixa_rdata),
    .tua_we(tua_we), .tua_addr(tua_addr), .tua_wdata(tua_wdata),
    .tua_be(tua_be), .tua_req(tua_req), .tua_rdata(tua_rdata),
    .mem_waddr(mem_waddr), .mem_wdata(mem_wdata),
    .mem_wbe_n(mem_wbe_n), .mem_we_n(mem_we_n),
    .mem0_raddr(mem0_raddr), .mem0_rdata(mem0_rdata), .mem0_re_n(mem0_re_n),
    .mem1_raddr(mem1_raddr), .mem1_rdata(mem1_rdata), .mem1_re_n(mem1_re_n),
    .mem2_raddr(mem2_raddr), .mem2_rdata(mem2_rdata), .mem2_re_n(mem2_re_n)
  );

  // 3 x 128K x 32 simple-dual-port SRAM (async read, sync write -> returns
  // OLD data on same-cycle read-during-write, matching ember_vram semantics)
  sram_model u_mem0 (.clk(clk),
    .raddr(mem0_raddr), .re_n(mem0_re_n), .rdata(mem0_rdata),
    .waddr(mem_waddr), .wdata(mem_wdata), .wbe_n(mem_wbe_n), .we_n(mem_we_n));
  sram_model u_mem1 (.clk(clk),
    .raddr(mem1_raddr), .re_n(mem1_re_n), .rdata(mem1_rdata),
    .waddr(mem_waddr), .wdata(mem_wdata), .wbe_n(mem_wbe_n), .we_n(mem_we_n));
  sram_model u_mem2 (.clk(clk),
    .raddr(mem2_raddr), .re_n(mem2_re_n), .rdata(mem2_rdata),
    .waddr(mem_waddr), .wdata(mem_wdata), .wbe_n(mem_wbe_n), .we_n(mem_we_n));

endmodule : memif_tb

// external memory model lives in sram_model.sv (shared with chip_tb)
