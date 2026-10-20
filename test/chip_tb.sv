// chip_tb.sv — board-level testbench for the full Ember chip.
//
//   +-------- ember_chip (pad ring + die + ember_memif) --------+
//   |  clk/reset_n pads | host AXI pads | video pads | SRAM pads |
//   +-----------------------------------------------------------+
//         |                  |               |            |
//      clock gen         cocotb AXI      cocotb      3x sram_model
//                                                (board-mounted SRAMs)
//
// Every transaction crosses the REAL pad ring (rtl/pad_models.sv wrappers)
// and the REAL external memory controller: this is the chip powered up on a
// board, with the three SRAM channels soldered to the mem*_ pads.

module chip_tb
(
  input  logic        clk,
  input  logic        reset_n,       // xres pad

  // host AXI4-Lite pads
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
  input  logic [31:0] h_araddr,
  input  logic        h_arvalid,
  output logic        h_arready,
  output logic [31:0] h_rdata,
  output logic [1:0]  h_rresp,
  output logic        h_rvalid,
  input  logic        h_rready,

  // mode + display pads
  input  logic [1:0]  fb_select,
  output logic        vid_hs,
  output logic        vid_vs,
  output logic        vid_de,
  output logic [15:0] vid_pixel
);

  // memory pads (wired to the on-board SRAMs below)
  logic [16:0] mem_waddr;
  logic [31:0] mem_wdata;
  logic [3:0]  mem_wbe_n;
  logic        mem_we_n;
  logic [16:0] mem0_raddr, mem1_raddr, mem2_raddr;
  logic [31:0] mem0_rdata, mem1_rdata, mem2_rdata;
  logic        mem0_re_n,  mem1_re_n,  mem2_re_n;

  ember_chip u_chip
  (
    .clk(clk), .reset_n(reset_n),
    .h_awaddr(h_awaddr), .h_awvalid(h_awvalid), .h_awready(h_awready),
    .h_wdata(h_wdata), .h_wstrb(h_wstrb), .h_wvalid(h_wvalid),
    .h_wready(h_wready),
    .h_bresp(h_bresp), .h_bvalid(h_bvalid), .h_bready(h_bready),
    .h_araddr(h_araddr), .h_arvalid(h_arvalid), .h_arready(h_arready),
    .h_rdata(h_rdata), .h_rresp(h_rresp), .h_rvalid(h_rvalid),
    .h_rready(h_rready),
    .fb_select(fb_select),
    .vid_hs(vid_hs), .vid_vs(vid_vs), .vid_de(vid_de),
    .vid_pixel(vid_pixel),
    .mem_waddr(mem_waddr), .mem_wdata(mem_wdata),
    .mem_wbe_n(mem_wbe_n), .mem_we_n(mem_we_n),
    .mem0_raddr(mem0_raddr), .mem0_rdata(mem0_rdata), .mem0_re_n(mem0_re_n),
    .mem1_raddr(mem1_raddr), .mem1_rdata(mem1_rdata), .mem1_re_n(mem1_re_n),
    .mem2_raddr(mem2_raddr), .mem2_rdata(mem2_rdata), .mem2_re_n(mem2_re_n)
  );

  // 3x 128K x 32 board-mounted SRAM channels
  sram_model u_mem0 (.clk(clk),
    .raddr(mem0_raddr), .re_n(mem0_re_n), .rdata(mem0_rdata),
    .waddr(mem_waddr), .wdata(mem_wdata), .wbe_n(mem_wbe_n), .we_n(mem_we_n));
  sram_model u_mem1 (.clk(clk),
    .raddr(mem1_raddr), .re_n(mem1_re_n), .rdata(mem1_rdata),
    .waddr(mem_waddr), .wdata(mem_wdata), .wbe_n(mem_wbe_n), .we_n(mem_we_n));
  sram_model u_mem2 (.clk(clk),
    .raddr(mem2_raddr), .re_n(mem2_re_n), .rdata(mem2_rdata),
    .waddr(mem_waddr), .wdata(mem_wdata), .wbe_n(mem_wbe_n), .we_n(mem_we_n));

endmodule : chip_tb
