// ember_xbar.sv — Ember GPU Phase-1 interconnect.
//
// Topology:
//   host master ──decode──► CP-reg slave (0x0000_0xxx, dedicated path)
//              └─(else)───► ┐
//   dma master ─────────────┤ VRAM write-arb ──► VRAM slave
//                          └ VRAM read-arb  ──►
//
// Contract:
//   * DMA master is hardwired to VRAM (its addr is already a VRAM offset).
//   * Host addr 0x0000_0000..0x0000_0FFF → CP regs; anything else → VRAM
//     (low VRAM_AW bits used, upper bits ignored — flat map, v1).
//   * VRAM port: at most one outstanding B and one outstanding R. The arbiter
//     forwards a request ONLY from idle, then LOCKS until that response
//     completes; nothing else is forwarded to VRAM while locked. This makes
//     response routing static and deadlock-free for one-outstanding masters.
//   * Host CP-reg path is independent and never blocked by VRAM locks.
//   * Arbitration: round-robin — on a simultaneous tie, the master that did
//     not win the previous arbitration wins.
//   * W routed with the same grant as AW (masters present AW+W together).

`include "ember_pkg.sv"
import ember_pkg::*;

module ember_xbar
(
  input  logic      clk,
  input  logic      rst_n,

  // Host master
  input  axil_aw_t  h_aw,  input  logic h_awvalid,  output logic h_awready,
  input  axil_w_t   h_w,   input  logic h_wvalid,   output logic h_wready,
  output axil_b_t   h_b,   output logic h_bvalid,   input  logic h_bready,
  input  axil_ar_t  h_ar,  input  logic h_arvalid,  output logic h_arready,
  output axil_r_t   h_r,   output logic h_rvalid,   input  logic h_rready,

  // DMA master (bready/rready must be tied high by the DMA engine)
  input  axil_aw_t  d_aw,  input  logic d_awvalid,  output logic d_awready,
  input  axil_w_t   d_w,   input  logic d_wvalid,   output logic d_wready,
  output axil_b_t   d_b,   output logic d_bvalid,   input  logic d_bready,
  input  axil_ar_t  d_ar,  input  logic d_arvalid,  output logic d_arready,
  output axil_r_t   d_r,   output logic d_rvalid,   input  logic d_rready,

  // CP-register slave (host-only)
  output axil_aw_t  c_aw,  output logic c_awvalid,  input  logic c_awready,
  output axil_w_t   c_w,   output logic c_wvalid,   input  logic c_wready,
  input  axil_b_t   c_b,   input  logic c_bvalid,   output logic c_bready,
  output axil_ar_t  c_ar,  output logic c_arvalid,  input  logic c_arready,
  input  axil_r_t   c_r,   input  logic c_rvalid,   output logic c_rready,

  // VRAM slave (shared)
  output axil_aw_t  v_aw,  output logic v_awvalid,  input  logic v_awready,
  output axil_w_t   v_w,   output logic v_wvalid,   input  logic v_wready,
  input  axil_b_t   v_b,   input  logic v_bvalid,   output logic v_bready,
  output axil_ar_t  v_ar,  output logic v_arvalid,  input  logic v_arready,
  input  axil_r_t   v_r,   input  logic v_rvalid,   output logic v_rready
);

  // ==================================================================
  // Decode
  // ==================================================================
  wire h_aw_is_cp = (h_aw.addr[31:12] == 20'h0_0000);
  wire h_ar_is_cp = (h_ar.addr[31:12] == 20'h0_0000);

  wire h_req_v_w = h_awvalid && !h_aw_is_cp;
  wire h_req_v_r = h_arvalid && !h_ar_is_cp;
  wire d_req_v_w = d_awvalid;
  wire d_req_v_r = d_arvalid;

  // ==================================================================
  // WRITE-side arbitration: forward only from W_IDLE, lock until B done
  // ==================================================================
  typedef enum logic [1:0] { W_IDLE, W_LOCK_H, W_LOCK_D } wstate_e;
  wstate_e wstate;

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      wstate <= W_IDLE;
    end else begin
      case (wstate)
        W_IDLE: begin
          if      (h_req_v_w) wstate <= W_LOCK_H;
          else if (d_req_v_w) wstate <= W_LOCK_D;
        end
        W_LOCK_H, W_LOCK_D: begin
          if (v_bvalid && v_bready) wstate <= W_IDLE;   // response completed
        end
        default: wstate <= W_IDLE;
      endcase
    end
  end

  // RR tie-breaker: loser of the last granted arbitration wins the next tie
  logic w_favor_d;
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n)            w_favor_d <= 1'b0;
    else if (wstate == W_LOCK_H) w_favor_d <= 1'b1;
    else if (wstate == W_LOCK_D) w_favor_d <= 1'b0;
    else if (wstate == W_IDLE && h_req_v_w && d_req_v_w) w_favor_d <= ~w_favor_d;
  end

  wire w_fwd_h = (wstate == W_IDLE) && h_req_v_w && (!d_req_v_w || !w_favor_d);
  wire w_fwd_d = (wstate == W_IDLE) && d_req_v_w && (!h_req_v_w ||  w_favor_d);

  assign v_aw      = w_fwd_h ? h_aw : d_aw;
  assign v_awvalid = w_fwd_h || w_fwd_d;
  assign v_w       = w_fwd_h ? h_w  : d_w;
  assign v_wvalid  = (w_fwd_h && h_wvalid) || (w_fwd_d && d_wvalid);

  assign h_awready = h_aw_is_cp ? c_awready : (w_fwd_h && v_awready);
  assign h_wready  = h_aw_is_cp ? c_wready  : (w_fwd_h && v_wready);
  assign d_awready = w_fwd_d && v_awready;
  assign d_wready  = w_fwd_d && v_wready;

  // Host writes to CP regs: dedicated, always forwarded
  assign c_aw      = h_aw;
  assign c_awvalid = h_awvalid && h_aw_is_cp;
  assign c_w       = h_w;
  assign c_wvalid  = h_wvalid && h_aw_is_cp;

  // B routing: static per lock state
  assign h_bvalid = (wstate == W_LOCK_H) ? v_bvalid : c_bvalid;
  assign h_b      = (wstate == W_LOCK_H) ? v_b      : c_b;
  assign c_bready = (wstate == W_LOCK_H) ? 1'b0 : h_bready;
  assign v_bready = (wstate == W_LOCK_H) ? h_bready :
                    (wstate == W_LOCK_D) ? d_bready : 1'b0;
  assign d_bvalid = (wstate == W_LOCK_D) ? v_bvalid : 1'b0;
  assign d_b      = v_b;

  // ==================================================================
  // READ-side arbitration: forward only from R_IDLE, lock until R done
  // ==================================================================
  typedef enum logic [1:0] { R_IDLE, R_LOCK_H, R_LOCK_D } rstate_e;
  rstate_e rstate;

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      rstate <= R_IDLE;
    end else begin
      case (rstate)
        R_IDLE: begin
          if      (h_req_v_r) rstate <= R_LOCK_H;
          else if (d_req_v_r) rstate <= R_LOCK_D;
        end
        R_LOCK_H, R_LOCK_D: begin
          if (v_rvalid && v_rready) rstate <= R_IDLE;   // response completed
        end
        default: rstate <= R_IDLE;
      endcase
    end
  end

  logic r_favor_d;
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n)            r_favor_d <= 1'b0;
    else if (rstate == R_LOCK_H) r_favor_d <= 1'b1;
    else if (rstate == R_LOCK_D) r_favor_d <= 1'b0;
    else if (rstate == R_IDLE && h_req_v_r && d_req_v_r) r_favor_d <= ~r_favor_d;
  end

  wire r_fwd_h = (rstate == R_IDLE) && h_req_v_r && (!d_req_v_r || !r_favor_d);
  wire r_fwd_d = (rstate == R_IDLE) && d_req_v_r && (!h_req_v_r ||  r_favor_d);

  assign v_ar      = r_fwd_h ? h_ar : d_ar;
  assign v_arvalid = r_fwd_h || r_fwd_d;
  assign h_arready = h_ar_is_cp ? c_arready : (r_fwd_h && v_arready);
  assign d_arready = r_fwd_d && v_arready;

  // Host reads to CP regs: dedicated, always forwarded
  assign c_ar      = h_ar;
  assign c_arvalid = h_arvalid && h_ar_is_cp;

  // R routing: static per lock state
  assign h_rvalid = (rstate == R_LOCK_H) ? v_rvalid : c_rvalid;
  assign h_r      = (rstate == R_LOCK_H) ? v_r      : c_r;
  assign c_rready = (rstate == R_LOCK_H) ? 1'b0 : h_rready;
  assign v_rready = (rstate == R_LOCK_H) ? h_rready :
                    (rstate == R_LOCK_D) ? d_rready : 1'b0;
  assign d_rvalid = (rstate == R_LOCK_D) ? v_rvalid : 1'b0;
  assign d_r      = v_r;

  // DMA always ready for responses (engine is its only flow control)
  wire _unused_dma_rdy = d_bready && d_rready;

endmodule : ember_xbar
