// ember_ram_slave.sv — Simple AXI4-Lite slave: 1 outstanding write, 1 outstanding read.
//
// Contract:
//   * Presents an internal single-port RAM interface:
//       wr_en/be/addr(w)/wdata  — commit on wr_en in the cycle it is high
//       rd_addr                 — sampled every rd_en cycle, rdata valid next cycle
//   * Handles all AXI handshake protocol itself (no skid buffers needed here).
//   * Used for the CP register block. VRAM uses ember_vram (bulk RAM, sidecar port).

`include "ember_pkg.sv"
import ember_pkg::*;

module ember_ram_slave
(
  input  logic        clk,
  input  logic        rst_n,

  // AXI4-Lite slave interface
  input  axil_aw_t    s_aw,      input  logic s_awvalid,  output logic s_awready,
  input  axil_w_t     s_w,       input  logic s_wvalid,   output logic s_wready,
  output axil_b_t     s_b,       output logic s_bvalid,   input  logic s_bready,
  input  axil_ar_t    s_ar,      input  logic s_arvalid,  output logic s_arready,
  output axil_r_t     s_r,       output logic s_rvalid,   input  logic s_rready,

  // Internal RAM-style control interface
  output logic [11:0] reg_addr,          // byte address within this block (4 KB)
  output logic [3:0]  reg_be,
  output logic [31:0] reg_wdata,
  output logic        reg_wr_en,
  output logic [11:0] rd_addr,           // byte address of read
  input  logic [31:0] rd_data            // combinational read data (regs are flop-based)
);

  // ------------------------------------------------------------------
  // Write path: capture AW and W (order-independent), then B response
  // ------------------------------------------------------------------
  logic        aw_v, w_v;
  axil_aw_t    aw_q;
  axil_w_t     w_q;

  wire wr_fire = aw_v && w_v && (!s_bvalid || s_bready);

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      aw_v <= 1'b0; aw_q <= '0;
    end else if (s_awvalid && s_awready) begin
      aw_v <= 1'b1; aw_q <= s_aw;
    end else if (wr_fire) begin
      aw_v <= 1'b0;
    end
  end

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      w_v <= 1'b0; w_q <= '0;
    end else if (s_wvalid && s_wready) begin
      w_v <= 1'b1; w_q <= s_w;
    end else if (wr_fire) begin
      w_v <= 1'b0;
    end
  end

  assign s_awready = !aw_v || wr_fire;
  assign s_wready  = !w_v  || wr_fire;

  always_ff @(posedge clk) begin
    if (wr_fire) begin
      reg_wr_en <= 1'b1;
      reg_addr  <= aw_q.addr[11:0];
      reg_be    <= w_q.strb;
      reg_wdata <= w_q.data;
    end else begin
      reg_wr_en <= 1'b0;
    end
  end

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      s_bvalid <= 1'b0; s_b.resp <= RESP_OKAY;
    end else if (wr_fire) begin
      s_bvalid <= 1'b1; s_b.resp <= RESP_OKAY;
    end else if (s_bvalid && s_bready) begin
      s_bvalid <= 1'b0;
    end
  end

  // ------------------------------------------------------------------
  // Read path: capture AR, mux reg data, one-cycle response
  // ------------------------------------------------------------------
  logic ar_v;

  wire ar_accept = s_arvalid && s_arready;

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      ar_v <= 1'b0;
    end else if (ar_accept) begin
      ar_v <= 1'b1;
    end else if (s_rvalid && s_rready) begin
      ar_v <= 1'b0;
    end
  end

  // Combinational read address: during an AR accept, the mux must reflect the
  // INCOMING address so s_r.data captures the correct register at that edge.
  assign rd_addr = ar_accept ? s_ar.addr[11:0] : 12'h0;

  always_ff @(posedge clk) begin
    if (ar_accept) begin
      s_r.data <= rd_data;   // capture mux output at end of AR-accept cycle
      s_r.resp <= RESP_OKAY;
    end
  end

  assign s_arready = !ar_v || (s_rvalid && s_rready);
  assign s_rvalid  = ar_v;

endmodule : ember_ram_slave
