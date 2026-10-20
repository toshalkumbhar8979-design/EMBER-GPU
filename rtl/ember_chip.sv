// ember_chip.sv — Ember chip top level: die + external memory controller +
// pad ring.
//
//   +---------------------------------------------------------------+
//   |                    PAD RING (sky130_fd_io)                    |
//   |  +----------- ember_die -----------+  +----- ember_memif -----+|
//   |  | cores, engines, xbar, CP,       |  | 3-ch SRAM controller  ||
//   |  | display (hardened macro)        |  | broadcast write bus   ||
//   |  +---- external VRAM bundle ------+  +---- memory pins ------+|
//   +---------------------------------------------------------------+
//
// The die's raw external VRAM bundle (v_*/fpa*/fpa2*/fpa3*/gxa*/cxa*/ixa*/
// tua*) is wired on-chip to ember_memif, which drives the real external
// SRAM interface. Chip pin names match scripts/gds/pinout.csv exactly;
// scripts/gds/make_pad_ring.py --check verifies that.
//
// Pad wrappers (rtl/pad_models.sv for sim/lint,
// build/gds/chip/pad_cells_physical.v for the physical flow) use fixed
// directions — no tristates — because every pin has a fixed direction in
// the pinout. Power/ground/corner pads carry no logic and are placed
// physically by the ring generator (docs/chip_pinout.md, "Power plan").
//
// The VRAM debug sidecar (dbg_*) is a testbench artifact and is NOT bonded
// out: it is tied off here. Host access to VRAM goes through the h_* AXI
// port exactly as real software would use it.

`include "ember_pkg.sv"
import ember_pkg::*;

module ember_chip
(
  // ---- west side: clock / reset ----
  input  logic        clk,
  input  logic        reset_n,

  // ---- north side: host AXI4-Lite write channels ----
  input  logic [31:0] h_awaddr,
  input  logic        h_awvalid,
  output logic        h_awready,
  input  logic [31:0] h_wdata,
  input  logic [3:0]  h_wstrb,
  input  logic        h_wvalid,
  output logic        h_wready,
  output logic [1:0]  h_bresp,
  output logic        h_bvalid,
  input  logic        h_bready,

  // ---- south side: host AXI4-Lite read channels + display + mode ----
  input  logic [31:0] h_araddr,
  input  logic        h_arvalid,
  output logic        h_arready,
  output logic [31:0] h_rdata,
  output logic [1:0]  h_rresp,
  output logic        h_rvalid,
  input  logic        h_rready,
  input  logic [1:0]  fb_select,
  output logic        vid_hs,
  output logic        vid_vs,
  output logic        vid_de,
  output logic [15:0] vid_pixel,

  // ---- east side: memory write bus + CH0 (display) ----
  output logic [16:0] mem_waddr,
  output logic [31:0] mem_wdata,
  output logic [3:0]  mem_wbe_n,
  output logic        mem_we_n,
  output logic [16:0] mem0_raddr,
  input  logic [31:0] mem0_rdata,
  output logic        mem0_re_n,

  // ---- west side: CH1 (engine) + CH2 (core fetch / host) ----
  output logic [16:0] mem1_raddr,
  input  logic [31:0] mem1_rdata,
  output logic        mem1_re_n,
  output logic [16:0] mem2_raddr,
  input  logic [31:0] mem2_rdata,
  output logic        mem2_re_n
);

  // ------------------------------------------------------------------
  // Core-side (post-pad) signals
  // ------------------------------------------------------------------
  logic        clk_i, rst_n_i;
  logic [31:0] h_awaddr_i, h_wdata_i, h_araddr_i, h_rdata_i;
  logic [3:0]  h_wstrb_i;
  logic [1:0]  h_bresp_i, h_rresp_i;
  logic        h_awvalid_i, h_awready_i, h_wvalid_i, h_wready_i;
  logic        h_bvalid_i, h_bready_i, h_arvalid_i, h_arready_i;
  logic        h_rvalid_i, h_rready_i;
  logic [1:0]  fb_select_i;
  logic        vid_hs_i, vid_vs_i, vid_de_i;
  logic [15:0] vid_pixel_i;
  logic [16:0] mem_waddr_i, mem0_raddr_i, mem1_raddr_i, mem2_raddr_i;
  logic [31:0] mem_wdata_i, mem0_rdata_i, mem1_rdata_i, mem2_rdata_i;
  logic [3:0]  mem_wbe_n_i;
  logic        mem_we_n_i, mem0_re_n_i, mem1_re_n_i, mem2_re_n_i;

  // ------------------------------------------------------------------
  // Pad ring — signal pads (generate loop per signal; instance names
  // g_<signal>[bit].u_pad are what the ring placement refers to)
  // ------------------------------------------------------------------
  genvar gi;

  // west: clock and reset
  generate
    begin : g_clk
      pad_in u_pad (.PAD(clk), .IN(clk_i));
    end
    begin : g_reset_n
      pad_xres u_pad (.PAD(reset_n), .XRES_H_N(rst_n_i));
    end

    // north: host write channels
    for (gi = 0; gi < 32; gi++) begin : g_h_awaddr
      pad_in u_pad (.PAD(h_awaddr[gi]), .IN(h_awaddr_i[gi]));
    end
    begin : g_h_awvalid
      pad_in u_pad (.PAD(h_awvalid), .IN(h_awvalid_i));
    end
    begin : g_h_awready
      pad_out u_pad (.PAD(h_awready), .OUT(h_awready_i));
    end
    for (gi = 0; gi < 32; gi++) begin : g_h_wdata
      pad_in u_pad (.PAD(h_wdata[gi]), .IN(h_wdata_i[gi]));
    end
    for (gi = 0; gi < 4; gi++) begin : g_h_wstrb
      pad_in u_pad (.PAD(h_wstrb[gi]), .IN(h_wstrb_i[gi]));
    end
    begin : g_h_wvalid
      pad_in u_pad (.PAD(h_wvalid), .IN(h_wvalid_i));
    end
    begin : g_h_wready
      pad_out u_pad (.PAD(h_wready), .OUT(h_wready_i));
    end
    for (gi = 0; gi < 2; gi++) begin : g_h_bresp
      pad_out u_pad (.PAD(h_bresp[gi]), .OUT(h_bresp_i[gi]));
    end
    begin : g_h_bvalid
      pad_out u_pad (.PAD(h_bvalid), .OUT(h_bvalid_i));
    end
    begin : g_h_bready
      pad_in u_pad (.PAD(h_bready), .IN(h_bready_i));
    end

    // south: host read channels, mode pins, display
    for (gi = 0; gi < 32; gi++) begin : g_h_araddr
      pad_in u_pad (.PAD(h_araddr[gi]), .IN(h_araddr_i[gi]));
    end
    begin : g_h_arvalid
      pad_in u_pad (.PAD(h_arvalid), .IN(h_arvalid_i));
    end
    begin : g_h_arready
      pad_out u_pad (.PAD(h_arready), .OUT(h_arready_i));
    end
    for (gi = 0; gi < 32; gi++) begin : g_h_rdata
      pad_out u_pad (.PAD(h_rdata[gi]), .OUT(h_rdata_i[gi]));
    end
    for (gi = 0; gi < 2; gi++) begin : g_h_rresp
      pad_out u_pad (.PAD(h_rresp[gi]), .OUT(h_rresp_i[gi]));
    end
    begin : g_h_rvalid
      pad_out u_pad (.PAD(h_rvalid), .OUT(h_rvalid_i));
    end
    begin : g_h_rready
      pad_in u_pad (.PAD(h_rready), .IN(h_rready_i));
    end
    for (gi = 0; gi < 2; gi++) begin : g_fb_select
      pad_in u_pad (.PAD(fb_select[gi]), .IN(fb_select_i[gi]));
    end
    begin : g_vid_hs
      pad_out u_pad (.PAD(vid_hs), .OUT(vid_hs_i));
    end
    begin : g_vid_vs
      pad_out u_pad (.PAD(vid_vs), .OUT(vid_vs_i));
    end
    begin : g_vid_de
      pad_out u_pad (.PAD(vid_de), .OUT(vid_de_i));
    end
    for (gi = 0; gi < 16; gi++) begin : g_vid_pixel
      pad_out u_pad (.PAD(vid_pixel[gi]), .OUT(vid_pixel_i[gi]));
    end

    // east: memory write bus + CH0
    for (gi = 0; gi < 17; gi++) begin : g_mem_waddr
      pad_out u_pad (.PAD(mem_waddr[gi]), .OUT(mem_waddr_i[gi]));
    end
    for (gi = 0; gi < 32; gi++) begin : g_mem_wdata
      pad_out u_pad (.PAD(mem_wdata[gi]), .OUT(mem_wdata_i[gi]));
    end
    for (gi = 0; gi < 4; gi++) begin : g_mem_wbe_n
      pad_out u_pad (.PAD(mem_wbe_n[gi]), .OUT(mem_wbe_n_i[gi]));
    end
    begin : g_mem_we_n
      pad_out u_pad (.PAD(mem_we_n), .OUT(mem_we_n_i));
    end
    for (gi = 0; gi < 17; gi++) begin : g_mem0_raddr
      pad_out u_pad (.PAD(mem0_raddr[gi]), .OUT(mem0_raddr_i[gi]));
    end
    for (gi = 0; gi < 32; gi++) begin : g_mem0_rdata
      pad_in u_pad (.PAD(mem0_rdata[gi]), .IN(mem0_rdata_i[gi]));
    end
    begin : g_mem0_re_n
      pad_out u_pad (.PAD(mem0_re_n), .OUT(mem0_re_n_i));
    end

    // west: CH1 + CH2
    for (gi = 0; gi < 17; gi++) begin : g_mem1_raddr
      pad_out u_pad (.PAD(mem1_raddr[gi]), .OUT(mem1_raddr_i[gi]));
    end
    for (gi = 0; gi < 32; gi++) begin : g_mem1_rdata
      pad_in u_pad (.PAD(mem1_rdata[gi]), .IN(mem1_rdata_i[gi]));
    end
    begin : g_mem1_re_n
      pad_out u_pad (.PAD(mem1_re_n), .OUT(mem1_re_n_i));
    end
    for (gi = 0; gi < 17; gi++) begin : g_mem2_raddr
      pad_out u_pad (.PAD(mem2_raddr[gi]), .OUT(mem2_raddr_i[gi]));
    end
    for (gi = 0; gi < 32; gi++) begin : g_mem2_rdata
      pad_in u_pad (.PAD(mem2_rdata[gi]), .IN(mem2_rdata_i[gi]));
    end
    begin : g_mem2_re_n
      pad_out u_pad (.PAD(mem2_re_n), .OUT(mem2_re_n_i));
    end
  endgenerate

  // ------------------------------------------------------------------
  // Die: raw external VRAM bundle (internal wires, no pads)
  // ------------------------------------------------------------------
  axil_aw_t v_aw;   logic v_awvalid, v_awready;
  axil_w_t  v_w;    logic v_wvalid,  v_wready;
  axil_b_t  v_b;    logic v_bvalid,  v_bready;
  axil_ar_t v_ar;   logic v_arvalid, v_arready;
  axil_r_t  v_r;    logic v_rvalid,  v_rready;

  logic        fpa_we,   fpa_req;    logic [31:0] fpa_addr,  fpa_wdata,  fpa_rdata;
  logic [3:0]  fpa_be;
  logic        fpa2_we,  fpa2_req;   logic [31:0] fpa2_addr, fpa2_wdata, fpa2_rdata;
  logic [3:0]  fpa2_be;
  logic        fpa3_req;             logic [31:0] fpa3_addr, fpa3_rdata;
  logic        gxa_we,   gxa_req;    logic [31:0] gxa_addr,  gxa_wdata,  gxa_rdata;
  logic [3:0]  gxa_be;
  logic        cxa_we,   cxa_req;    logic [31:0] cxa_addr,  cxa_wdata,  cxa_rdata;
  logic [3:0]  cxa_be;
  logic        ixa_req;              logic [31:0] ixa_addr,  ixa_rdata;
  logic        tua_we,   tua_req;    logic [31:0] tua_addr,  tua_wdata,  tua_rdata;
  logic [3:0]  tua_be;

  ember_die u_die
  (
    .clk(clk_i), .rst_n(rst_n_i),

    .h_awaddr(h_awaddr_i), .h_awvalid(h_awvalid_i), .h_awready(h_awready_i),
    .h_wdata(h_wdata_i), .h_wstrb(h_wstrb_i), .h_wvalid(h_wvalid_i),
    .h_wready(h_wready_i),
    .h_bresp(h_bresp_i), .h_bvalid(h_bvalid_i), .h_bready(h_bready_i),
    .h_araddr(h_araddr_i), .h_arvalid(h_arvalid_i), .h_arready(h_arready_i),
    .h_rdata(h_rdata_i), .h_rresp(h_rresp_i), .h_rvalid(h_rvalid_i),
    .h_rready(h_rready_i),

    // debug sidecar: not bonded out (testbench artifact)
    .dbg_en(1'b0), .dbg_addr('0), .dbg_rdata('0), .dbg_wdata('0), .dbg_be('0),

    .fb_select(fb_select_i),
    .vid_hs(vid_hs_i), .vid_vs(vid_vs_i), .vid_de(vid_de_i),
    .vid_pixel(vid_pixel_i),

    .v_aw(v_aw), .v_awvalid(v_awvalid), .v_awready(v_awready),
    .v_w(v_w), .v_wvalid(v_wvalid), .v_wready(v_wready),
    .v_b(v_b), .v_bvalid(v_bvalid), .v_bready(v_bready),
    .v_ar(v_ar), .v_arvalid(v_arvalid), .v_arready(v_arready),
    .v_r(v_r), .v_rvalid(v_rvalid), .v_rready(v_rready),

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
    .tua_be(tua_be), .tua_req(tua_req), .tua_rdata(tua_rdata)
  );

  // ------------------------------------------------------------------
  // External memory controller: VRAM bundle -> real SRAM pins
  // ------------------------------------------------------------------
  ember_memif u_memif
  (
    .clk(clk_i), .rst_n(rst_n_i),

    .v_aw(v_aw), .v_awvalid(v_awvalid), .v_awready(v_awready),
    .v_w(v_w), .v_wvalid(v_wvalid), .v_wready(v_wready),
    .v_b(v_b), .v_bvalid(v_bvalid), .v_bready(v_bready),
    .v_ar(v_ar), .v_arvalid(v_arvalid), .v_arready(v_arready),
    .v_r(v_r), .v_rvalid(v_rvalid), .v_rready(v_rready),

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

    .mem_waddr(mem_waddr_i), .mem_wdata(mem_wdata_i),
    .mem_wbe_n(mem_wbe_n_i), .mem_we_n(mem_we_n_i),
    .mem0_raddr(mem0_raddr_i), .mem0_rdata(mem0_rdata_i),
    .mem0_re_n(mem0_re_n_i),
    .mem1_raddr(mem1_raddr_i), .mem1_rdata(mem1_rdata_i),
    .mem1_re_n(mem1_re_n_i),
    .mem2_raddr(mem2_raddr_i), .mem2_rdata(mem2_rdata_i),
    .mem2_re_n(mem2_re_n_i)
  );

endmodule : ember_chip
