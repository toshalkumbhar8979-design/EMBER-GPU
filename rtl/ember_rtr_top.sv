// ember_rtr_top.sv — RTR top: triangle command queue fetch + setup + scan.
//
// Contract:
//   * Command queue lives in VRAM at RTR_CMDQ_BASE (= CMDBUF_BASE, a VRAM
//     byte offset). Format (ember_pkg): word0 flags [0]=tri_valid [1]=blend
//     [2]=ztest [3]=tex_en [4]=dither [5]=rgbmap [15:8]=texpage; words 1..6
//     vx0,vy0,vx1,vy1,vx2,vy2 (s32 Q10.22); 7..9 z0..z2 (u16 raw); 10..12
//     {r,g,b} per vertex (byte-packed {b,g,r,x}); 13..18 u0,v0..u2,v2
//     (s32 Q10.22). RTR_CMD_WORDS words per triangle.
//   * kick (1-cycle pulse): restart fetch from RTR_CMDQ_BASE. Queue ends at
//     the first word0 with tri_valid=0 (no length register needed).
//   * Fetch uses the fpa port (word reads); scan uses it for z/fb traffic.
//     The two never overlap in time (fetch only while scan idle), so the port
//     is a plain mux, no arbiter.
//   * fpa2 is the texel port, driven only by the scan engine.
//   * Degenerate/culled triangles: setup.cull -> skipped, fetch continues.
//
// Timing: fetch = 2 cycles/word (req, capture). Scan is the golden-exact FSM
// in ember_rtr_scan.sv. busy = fetch-or-scan active.

`include "ember_pkg.sv"
import ember_pkg::*;

module ember_rtr_top
(
  input  logic        clk,
  input  logic        rst_n,

  input  logic        kick,          // 1-cycle pulse: (re)start command queue

  // fpa: FB/Z pixel port (fetch + scan, muxed)
  output logic        fpa_we,
  output logic [31:0] fpa_addr,
  output logic [31:0] fpa_wdata,
  output logic [3:0]  fpa_be,
  output logic        fpa_req,
  input  logic [31:0] fpa_rdata,

  // fpa2: texel port (scan only)
  output logic        fpa2_req,
  output logic [31:0] fpa2_addr,
  input  logic [31:0] fpa2_rdata,

  output logic        busy           // queue being processed
);

  // ==================================================================
  // Command queue fetch FSM
  // ==================================================================
  typedef enum logic [2:0] {
    F_IDLE, F_FETCH, F_WAIT, F_GO, F_RUN, F_ADV
  } fstate_e;
  fstate_e fst;

  // fpa ports take BUS addresses (ember_vram.addr2word strips VRAM_BASE).
  localparam logic [31:0] CMDQ_BUS   = VRAM_BASE + RTR_CMDQ_BASE;
  localparam logic [31:0] CMD_STRIDE = RTR_CMD_WORDS * 4;   // 76 B / triangle

  logic [31:0]  cursor;            // BUS byte address of next cmd word
  logic [4:0]   fidx;              // word index within triangle (0..18)

  logic [31:0]  cmd_q [RTR_CMD_WORDS];
  logic         fetch_req;
  logic [31:0]  fetch_addr;
  logic         scan_start;

  logic         scan_busy, scan_done;

  assign busy = (fst != F_IDLE) || scan_busy;

  // ------------------------------------------------------------------
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      fst        <= F_IDLE;
      cursor     <= CMDQ_BUS;
      fidx       <= 5'd0;
      fetch_req  <= 1'b0;
      scan_start <= 1'b0;
    end else begin
      fetch_req  <= 1'b0;
      scan_start <= 1'b0;

      case (fst)
        F_IDLE: begin
          if (kick) begin
            cursor    <= CMDQ_BUS;
            fidx      <= 5'd0;
            fetch_req <= 1'b1;
            fetch_addr<= CMDQ_BUS;
            fst       <= F_FETCH;
          end
        end

        F_FETCH: begin
          fst <= F_WAIT;             // fpa_rdata valid next cycle
        end

        F_WAIT: begin
          cmd_q[fidx] <= fpa_rdata;
          if (fidx == 5'd0 && !fpa_rdata[0]) begin
            fst <= F_IDLE;           // tri_valid=0: end of queue
          end else if (fidx == 5'd18) begin     // RTR_CMD_WORDS-1
            fst <= F_GO;             // full triangle captured
          end else begin
            fidx      <= fidx + 5'd1;
            fetch_req <= 1'b1;
            // next word address: cursor + (fidx+1)*4 (fidx is current index)
            fetch_addr<= cursor + {25'b0, fidx, 2'b00} + 32'd4;
            fst       <= F_FETCH;
          end
        end

        F_GO: begin
          if (cull) begin
            fst <= F_ADV;            // backface/degenerate: skip
          end else begin
            scan_start <= 1'b1;
            fst        <= F_RUN;
          end
        end

        F_RUN: begin
          if (scan_done) fst <= F_ADV;
        end

        F_ADV: begin
          cursor     <= cursor + CMD_STRIDE;
          fidx       <= 5'd0;
          fetch_req  <= 1'b1;
          fetch_addr <= cursor + CMD_STRIDE;
          fst        <= F_FETCH;
        end

        default: fst <= F_IDLE;
      endcase
    end
  end

  // ==================================================================
  // Command decode (combinational from captured words)
  // ==================================================================
  logic signed [31:0] vx0, vy0, vx1, vy1, vx2, vy2;
  logic signed [31:0] vu0, vv0, vu1, vv1, vu2, vv2;
  logic [15:0]        vz0, vz1, vz2;
  logic [7:0]         vr0, vg0, vb0, vr1, vg1, vb1, vr2, vg2, vb2;

  assign vx0 = signed'(cmd_q[1]);  assign vy0 = signed'(cmd_q[2]);
  assign vx1 = signed'(cmd_q[3]);  assign vy1 = signed'(cmd_q[4]);
  assign vx2 = signed'(cmd_q[5]);  assign vy2 = signed'(cmd_q[6]);
  assign vz0 = cmd_q[7][15:0];
  assign vz1 = cmd_q[8][15:0];
  assign vz2 = cmd_q[9][15:0];
  assign {vb0, vg0, vr0} = cmd_q[10][23:0];
  assign {vb1, vg1, vr1} = cmd_q[11][23:0];
  assign {vb2, vg2, vr2} = cmd_q[12][23:0];
  assign vu0 = signed'(cmd_q[13]); assign vv0 = signed'(cmd_q[14]);
  assign vu1 = signed'(cmd_q[15]); assign vv1 = signed'(cmd_q[16]);
  assign vu2 = signed'(cmd_q[17]); assign vv2 = signed'(cmd_q[18]);

  // ==================================================================
  // Setup (combinational Cramer solve)
  // ==================================================================
  logic               cull;
  logic signed [63:0] iwA, iwB, iwC, rA, rB, rC, gA, gB, gC;
  logic signed [63:0] bA, bB, bC, zA, zB, zC, uA, uB, uC, vA, vB, vC;
  logic [15:0]        x_lo_i, x_hi_i, y_lo_i, y_hi_i;
  logic signed [32:0] dx01, dy01, dx12, dy12, dx20, dy20;

  ember_rtr_setup u_setup (
    .x0(vx0), .y0(vy0), .x1(vx1), .y1(vy1), .x2(vx2), .y2(vy2),
    .u0(vu0), .v0(vv0), .u1(vu1), .v1(vv1), .u2(vu2), .v2(vv2),
    .z0(vz0), .z1(vz1), .z2(vz2),
    .r0(vr0), .g0(vg0), .b0(vb0),
    .r1(vr1), .g1(vg1), .b1(vb1),
    .r2(vr2), .g2(vg2), .b2(vb2),
    .cull(cull),
    .area(),
    .iwA(iwA), .iwB(iwB), .iwC(iwC),
    .rA(rA), .rB(rB), .rC(rC),
    .gA(gA), .gB(gB), .gC(gC),
    .bA(bA), .bB(bB), .bC(bC),
    .zA(zA), .zB(zB), .zC(zC),
    .uA(uA), .uB(uB), .uC(uC),
    .vA(vA), .vB(vB), .vC(vC),
    .x_lo_i(x_lo_i), .x_hi_i(x_hi_i), .y_lo_i(y_lo_i), .y_hi_i(y_hi_i),
    .dx01(dx01), .dy01(dy01), .dx12(dx12), .dy12(dy12),
    .dx20(dx20), .dy20(dy20)
  );

  // ==================================================================
  // Scan engine (golden-exact FSM)
  // ==================================================================
  logic        scan_fpa_we;
  logic [31:0] scan_fpa_addr, scan_fpa_wdata;
  logic [3:0]  scan_fpa_be;
  logic        scan_fpa_req;

  ember_rtr_scan u_scan (
    .clk(clk), .rst_n(rst_n),
    .start(scan_start),
    .t_blend(cmd_q[0][1]), .t_ztest(cmd_q[0][2]), .t_tex(cmd_q[0][3]),
    .t_dither(cmd_q[0][4]), .t_rgbmap(cmd_q[0][5]),
    .t_texpal(cmd_q[0][6]),
    .t_texpage(cmd_q[0][15:8]),
    .iwA(iwA), .iwB(iwB), .iwC(iwC),
    .rA(rA), .rB(rB), .rC(rC),
    .gA(gA), .gB(gB), .gC(gC),
    .bA(bA), .bB(bB), .bC(bC),
    .zA(zA), .zB(zB), .zC(zC),
    .uA(uA), .uB(uB), .uC(uC),
    .vA(vA), .vB(vB), .vC(vC),
    .x_lo_i(x_lo_i), .x_hi_i(x_hi_i), .y_lo_i(y_lo_i), .y_hi_i(y_hi_i),
    .x0(vx0), .y0(vy0), .x1(vx1), .y1(vy1), .x2(vx2), .y2(vy2),
    .dx01(dx01), .dy01(dy01), .dx12(dx12), .dy12(dy12),
    .dx20(dx20), .dy20(dy20),
    .fpa_we(scan_fpa_we), .fpa_addr(scan_fpa_addr), .fpa_wdata(scan_fpa_wdata),
    .fpa_be(scan_fpa_be), .fpa_req(scan_fpa_req), .fpa_rdata(fpa_rdata),
    .fpa2_req(fpa2_req), .fpa2_addr(fpa2_addr), .fpa2_rdata(fpa2_rdata),
    .busy(scan_busy), .done(scan_done)
  );

  // ==================================================================
  // fpa port mux: fetch (word reads) vs scan (z/fb traffic) — never both
  // ==================================================================
  wire in_fetch = (fst == F_FETCH) || (fst == F_WAIT);
  assign fpa_req   = in_fetch ? fetch_req  : scan_fpa_req;
  assign fpa_we    = in_fetch ? 1'b0        : scan_fpa_we;
  assign fpa_addr  = in_fetch ? fetch_addr  : scan_fpa_addr;
  assign fpa_wdata = in_fetch ? 32'h0       : scan_fpa_wdata;
  assign fpa_be    = in_fetch ? 4'hF        : scan_fpa_be;

endmodule : ember_rtr_top
