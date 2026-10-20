// ember_top.sv — Ember GPU top level.
//
// External host interface: FLAT AXI4-Lite signals (cocotb/synthesis friendly).
// Internal interconnect: struct-based (ember_pkg types).
//
// Host map:
//   0x0000_0000..0x0000_0FFF : CP registers (kick RTR via CP_RTR_KICK)
//   0x0000_1000..            : VRAM (low VRAM_AW bits, flat)
//
// RTR traffic (triangle queue fetch, z/texel/fb pixel port) is INTERNAL — the
// testbench drives it exactly like real software: upload command queue via CP
// DMA, clear z-buffer via bus, write CP_RTR_KICK, poll CP_STATUS.rtr_busy.
//
// dbg_* : testbench-only sidecar into VRAM (golden checks without bus traffic).

`include "ember_pkg.sv"
import ember_pkg::*;

`default_nettype none
module ember_die
(
  input  logic        clk,
  input  logic        rst_n,

  // Host AXI4-Lite master port (flat)
  input  logic [31:0] h_awaddr,   input  logic h_awvalid,  output logic h_awready,
  input  logic [31:0] h_wdata,
  input  logic [3:0]  h_wstrb,    input  logic h_wvalid,   output logic h_wready,
  output logic [1:0]  h_bresp,    output logic h_bvalid,   input  logic h_bready,
  input  logic [31:0] h_araddr,   input  logic h_arvalid,  output logic h_arready,
  output logic [31:0] h_rdata,
  output logic [1:0]  h_rresp,    output logic h_rvalid,   input  logic h_rready,

  // VRAM debug sidecar
  input  logic               dbg_en,
  input  logic [VRAM_AW-3:0] dbg_addr,   // word address (2^17 words)
  input  logic [31:0]        dbg_rdata,
  input  logic [31:0]        dbg_wdata,
  input  logic [3:0]         dbg_be,

  // Display port (Phase 3) — frame stream for the testbench/DAC
  input  logic [1:0]         fb_select,
  output logic               vid_hs,
  output logic               vid_vs,
  output logic               vid_de,
  output logic [15:0]        vid_pixel,

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
);

  // ------------------------------------------------------------------
  // Flat <-> struct adapters for the host port
  // ------------------------------------------------------------------
  axil_aw_t h_aw_s;  axil_w_t h_w_s;
  axil_b_t  h_b_s;   axil_ar_t h_ar_s;  axil_r_t h_r_s;

  assign h_aw_s = axil_aw_t'{addr: h_awaddr, prot: 3'b000};
  assign h_w_s  = axil_w_t'{data: h_wdata,  strb: h_wstrb};
  assign h_ar_s = axil_ar_t'{addr: h_araddr, prot: 3'b000};
  assign h_bresp = h_b_s.resp;
  assign h_rresp = h_r_s.resp;

  // ------------------------------------------------------------------
  // Xbar <-> CP (struct channels)
  // ------------------------------------------------------------------
  axil_aw_t  c_aw;  logic c_awvalid, c_awready;
  axil_w_t   c_w;   logic c_wvalid,  c_wready;
  axil_b_t   c_b;   logic c_bvalid,  c_bready;
  axil_ar_t  c_ar;  logic c_arvalid, c_arready;
  axil_r_t   c_r;   logic c_rvalid,  c_rready;

  // CP -> xbar (DMA master)
  axil_aw_t  d_aw;  logic d_awvalid, d_awready;
  axil_w_t   d_w;   logic d_wvalid,  d_wready;
  axil_b_t   d_b;   logic d_bvalid,  d_bready;
  axil_ar_t  d_ar;  logic d_arvalid, d_arready;
  axil_r_t   d_r;   logic d_rvalid,  d_rready;

  // Xbar -> VRAM

  // ------------------------------------------------------------------
  // Interconnect
  // ------------------------------------------------------------------
  ember_xbar u_xbar (
    .clk(clk), .rst_n(rst_n),

    .h_aw(h_aw_s), .h_awvalid(h_awvalid), .h_awready(h_awready),
    .h_w (h_w_s),  .h_wvalid (h_wvalid),  .h_wready (h_wready),
    .h_b (h_b_s),  .h_bvalid (h_bvalid),  .h_bready (h_bready),
    .h_ar(h_ar_s), .h_arvalid(h_arvalid), .h_arready(h_arready),
    .h_r (h_r_s),  .h_rvalid (h_rvalid),  .h_rready (h_rready),

    .d_aw(d_aw), .d_awvalid(d_awvalid), .d_awready(d_awready),
    .d_w (d_w),  .d_wvalid (d_wvalid),  .d_wready (d_wready),
    .d_b (d_b),  .d_bvalid (d_bvalid),  .d_bready (d_bready),
    .d_ar(d_ar), .d_arvalid(d_arvalid), .d_arready(d_arready),
    .d_r (d_r),  .d_rvalid (d_rvalid),  .d_rready (d_rready),

    .c_aw(c_aw), .c_awvalid(c_awvalid), .c_awready(c_awready),
    .c_w (c_w),  .c_wvalid (c_wvalid),  .c_wready (c_wready),
    .c_b (c_b),  .c_bvalid (c_bvalid),  .c_bready (c_bready),
    .c_ar(c_ar), .c_arvalid(c_arvalid), .c_arready(c_arready),
    .c_r (c_r),  .c_rvalid (c_rvalid),  .c_rready (c_rready),

    .v_aw(v_aw), .v_awvalid(v_awvalid), .v_awready(v_awready),
    .v_w (v_w),  .v_wvalid (v_wvalid),  .v_wready (v_wready),
    .v_b (v_b),  .v_bvalid (v_bvalid),  .v_bready (v_bready),
    .v_ar(v_ar), .v_arvalid(v_arvalid), .v_arready(v_arready),
    .v_r (v_r),  .v_rvalid (v_rvalid),  .v_rready (v_rready)
  );

  // Host read data path
  assign h_rdata = h_r_s.data;

  // ------------------------------------------------------------------
  // RTR pixel ports (internal: scan/fetch <-> VRAM)
  // ------------------------------------------------------------------


  logic        rtr_kick, rtr_busy;

  // Blitter
  logic        blit_csr_we, blit_kick, blit_busy;
  logic [1:0]  blit_csr_addr;
  logic [31:0] blit_csr_wdata;
  logic        blit_fpa_we;
  logic [31:0] blit_fpa_addr, blit_fpa_wdata;
  logic [3:0]  blit_fpa_be;
  logic        blit_fpa_req;

  // GSX (geometry) — dedicated gxa VRAM port for cmdq emits
  logic        gsx_csr_we, gsx_kick, gsx_busy;
  logic [1:0]  gsx_csr_addr;
  logic [31:0] gsx_csr_wdata;

  // Compute core — dedicated cxa (data) + ixa (fetch) VRAM ports
  logic        core_csr_we, core_kick, core_busy;
  logic [1:0]  core_csr_addr;
  logic [31:0] core_csr_wdata;

  // Tensor unit — dedicated tua VRAM port (tile traffic)
  logic        tu_csr_we, tu_kick, tu_busy;
  logic [1:0]  tu_csr_addr;
  logic [31:0] tu_csr_wdata;

  // RTR-side fpa outputs (before the ownership mux)
  logic        rtr_fpa_we;
  logic [31:0] rtr_fpa_addr, rtr_fpa_wdata;
  logic [3:0]  rtr_fpa_be;
  logic        rtr_fpa_req;

  // ------------------------------------------------------------------
  // Command Processor
  // ------------------------------------------------------------------
  ember_cp u_cp (
    .clk(clk), .rst_n(rst_n),

    .s_aw(c_aw), .s_awvalid(c_awvalid), .s_awready(c_awready),
    .s_w (c_w),  .s_wvalid (c_wvalid),  .s_wready (c_wready),
    .s_b (c_b),  .s_bvalid (c_bvalid),  .s_bready (c_bready),
    .s_ar(c_ar), .s_arvalid(c_arvalid), .s_arready(c_arready),
    .s_r (c_r),  .s_rvalid (c_rvalid),  .s_rready (c_rready),

    .m_aw(d_aw), .m_awvalid(d_awvalid), .m_awready(d_awready),
    .m_w (d_w),  .m_wvalid (d_wvalid),  .m_wready (d_wready),
    .m_b (d_b),  .m_bvalid (d_bvalid),  .m_bready (d_bready),
    .m_ar(d_ar), .m_arvalid(d_arvalid), .m_arready(d_arready),
    .m_r (d_r),  .m_rvalid (d_rvalid),  .m_rready (d_rready),

    .rtr_kick(rtr_kick), .rtr_busy(rtr_busy),

    .blit_csr_we(blit_csr_we), .blit_csr_addr(blit_csr_addr),
    .blit_csr_wdata(blit_csr_wdata), .blit_kick(blit_kick),
    .blit_busy(blit_busy),

    .gsx_csr_we(gsx_csr_we), .gsx_csr_addr(gsx_csr_addr),
    .gsx_csr_wdata(gsx_csr_wdata), .gsx_kick(gsx_kick),
    .gsx_busy(gsx_busy),

    .core_csr_we(core_csr_we), .core_csr_addr(core_csr_addr),
    .core_csr_wdata(core_csr_wdata), .core_kick(core_kick),
    .core_busy(core_busy),

    .tu_csr_we(tu_csr_we), .tu_csr_addr(tu_csr_addr),
    .tu_csr_wdata(tu_csr_wdata), .tu_kick(tu_kick),
    .tu_busy(tu_busy)
  );

  // ------------------------------------------------------------------
  // Tensor unit (Phase 6): 16x16 int8 weight-stationary matmul
  // ------------------------------------------------------------------
  ember_tu u_tu (
    .clk(clk), .rst_n(rst_n),
    .csr_we(tu_csr_we), .csr_addr(tu_csr_addr),
    .csr_wdata(tu_csr_wdata), .kick(tu_kick),
    .tua_we(tua_we), .tua_addr(tua_addr),
    .tua_wdata(tua_wdata), .tua_be(tua_be),
    .tua_req(tua_req), .tua_rdata(tua_rdata),
    .busy(tu_busy)
  );

  // ------------------------------------------------------------------
  // Compute core (Phase 5): 4-thread SPMD kernel execution
  // ------------------------------------------------------------------
  ember_core u_core (
    .clk(clk), .rst_n(rst_n),
    .csr_we(core_csr_we), .csr_addr(core_csr_addr),
    .csr_wdata(core_csr_wdata), .kick(core_kick),
    .cxa_we(cxa_we), .cxa_addr(cxa_addr),
    .cxa_wdata(cxa_wdata), .cxa_be(cxa_be),
    .cxa_req(cxa_req), .cxa_rdata(cxa_rdata),
    .ixa_req(ixa_req), .ixa_addr(ixa_addr),
    .ixa_rdata(ixa_rdata),
    .busy(core_busy)
  );

  // ------------------------------------------------------------------
  // GSX: geometry & setup (transform + near-cull + cmdq emit)
  // ------------------------------------------------------------------
  ember_gsx u_gsx (
    .clk(clk), .rst_n(rst_n),
    .csr_we(gsx_csr_we), .csr_addr(gsx_csr_addr),
    .csr_wdata(gsx_csr_wdata), .kick(gsx_kick),
    .gxa_we(gxa_we), .gxa_addr(gxa_addr),
    .gxa_wdata(gxa_wdata), .gxa_be(gxa_be),
    .gxa_req(gxa_req), .gxa_rdata(gxa_rdata),
    .busy(gsx_busy)
  );

  // ------------------------------------------------------------------
  // Blitter (shares the RTR's fpa port: RTR wins when both want it —
  // software never runs both against the same FB region simultaneously)
  // ------------------------------------------------------------------
  ember_blit u_blit (
    .clk(clk), .rst_n(rst_n),
    .csr_we(blit_csr_we), .csr_addr(blit_csr_addr),
    .csr_wdata(blit_csr_wdata), .kick(blit_kick),
    .fpa_we(blit_fpa_we), .fpa_addr(blit_fpa_addr),
    .fpa_wdata(blit_fpa_wdata), .fpa_be(blit_fpa_be),
    .fpa_req(blit_fpa_req), .fpa_rdata(fpa_rdata),
    .busy(blit_busy), .done()
  );

  // fpa ownership: RTR first (u_rtr while busy), then blitter. The RTR's
  // outputs are registered in its FSM, so they hold one cycle after done;
  // the blitter only ever sees the port when the RTR is idle.
  wire rtr_own = rtr_busy;
  wire blit_own = ~rtr_busy & blit_busy;
  assign fpa_we     = rtr_own ? rtr_fpa_we     : (blit_own ? blit_fpa_we     : 1'b0);
  assign fpa_addr   = rtr_own ? rtr_fpa_addr   : (blit_own ? blit_fpa_addr   : 32'h0);
  assign fpa_wdata  = rtr_own ? rtr_fpa_wdata  : (blit_own ? blit_fpa_wdata  : 32'h0);
  assign fpa_be     = rtr_own ? rtr_fpa_be     : (blit_own ? blit_fpa_be     : 4'h0);
  assign fpa_req    = rtr_own ? rtr_fpa_req    : (blit_own ? blit_fpa_req    : 1'b0);

  // ------------------------------------------------------------------
  // RTR: command-queue fetch + setup + scan (golden-exact pixel pipe)
  // ------------------------------------------------------------------
  ember_rtr_top u_rtr (
    .clk(clk), .rst_n(rst_n),
    .kick(rtr_kick),
    .fpa_we(rtr_fpa_we), .fpa_addr(rtr_fpa_addr), .fpa_wdata(rtr_fpa_wdata),
    .fpa_be(rtr_fpa_be), .fpa_req(rtr_fpa_req), .fpa_rdata(fpa_rdata),
    .fpa2_req(fpa2_req), .fpa2_addr(fpa2_addr), .fpa2_rdata(fpa2_rdata),
    .busy(rtr_busy)
  );

  // Texel port is read-only in v1: never writes VRAM.
  assign fpa2_we    = 1'b0;
  assign fpa2_wdata = 32'h0;
  assign fpa2_be    = 4'h0;

  // ------------------------------------------------------------------
  // Display controller (320x240 double-scan over 640x480@60)
  // ------------------------------------------------------------------
  ember_display u_disp (
    .clk(clk), .rst_n(rst_n),
    .fb_select(fb_select),
    .fpa3_req(fpa3_req), .fpa3_addr(fpa3_addr), .fpa3_rdata(fpa3_rdata),
    .vid_hs(vid_hs), .vid_vs(vid_vs), .vid_de(vid_de),
    .vid_pixel(vid_pixel)
  );

  // ------------------------------------------------------------------
  // VRAM
  // ------------------------------------------------------------------

endmodule : ember_die

`default_nettype wire
