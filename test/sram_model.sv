// sram_model.sv — behavioral external memory for the chip memory interface.
//
// Models the board-mounted 128K x 32 simple-dual-port SRAM channel:
//   * combinational (async) read: data valid within the request cycle,
//     matching the EMC's fixed 1-cycle capture contract
//   * write committed at the rising edge with byte enables
//   * a read of an address being written in the same cycle returns the OLD
//     value (ember_vram nonblocking semantics)

module sram_model
(
  input  logic        clk,
  input  logic [16:0] raddr,
  input  logic        re_n,
  output logic [31:0] rdata,
  input  logic [16:0] waddr,
  input  logic [31:0] wdata,
  input  logic [3:0]  wbe_n,
  input  logic        we_n
);

  logic [31:0] mem [0:(1<<17)-1];

  assign rdata = mem[raddr];   // async read

  always_ff @(posedge clk) begin
    if (!we_n) begin
      if (!wbe_n[0]) mem[waddr][7:0]   <= wdata[7:0];
      if (!wbe_n[1]) mem[waddr][15:8]  <= wdata[15:8];
      if (!wbe_n[2]) mem[waddr][23:16] <= wdata[23:16];
      if (!wbe_n[3]) mem[waddr][31:24] <= wdata[31:24];
    end
  end

  wire _unused = re_n;   // read enable is a pin-level qualifier only

endmodule : sram_model
