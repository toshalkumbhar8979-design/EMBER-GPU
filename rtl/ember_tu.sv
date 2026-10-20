// ember_tu.sv — Phase-6 Tensor Unit v1: 16x16 int8 WEIGHT-STATIONARY
// outer-product array, BLOCKED-M tile controller, per-tensor requant.
//
// Architecture (bit-exact vs tools/golden/tu.py):
//   * Cell (r,c) holds W[k0+r][n0+c] (weight stationary). Weight words are
//     staged 4-at-a-time into a row buffer; one load pulse per row.
//   * Per output row, the activation vector a[r] = A[m][k0+r] is broadcast
//     to row r combinationally; cell products w(r,c)*a(r) sum through
//     per-column 16-input trees.
//   * LOOP ORDER: n-tile OUTER, M-block (16 rows) MIDDLE, k-tile INNER.
//     acc[16][16] holds one accumulator SET PER ROW OF THE M-BLOCK and
//     accumulates across the k-loop; C is requantized+written per M-block.
//     (A single shared acc set is WRONG — every row's MAC would add into
//     the same registers; proved by tools/tu_chk zero-C smear.)
//   * Requant: out = ((c*mult + half) >>> shift) wrapped to int8
//     (round-half-up; shift=0 -> identity), 4 bytes per word.
//   * v1 constraints: K and N MULTIPLES OF 16 (the array streams full
//     16-byte W/A row tiles; software zero-pads matrices to whole tiles —
//     TPU-style). M is 12-bit, rounded up to whole 16-row blocks by the
//     controller (tail rows read zero-padded A; ALL block/row counters are
//     12-bit — an 8-bit cw_row aliased C writes once M > 256). Systolic psum-chain
//     streaming variant is the v2 upgrade behind the same CSR interface.
//
// CSR (decoded by ember_cp):
//   00=TUA   A base, VRAM byte offset (M x K int8, row stride K)
//   01=TUW   W base (K x N int8, row stride N)
//   10=TUC   C base (M x N int8 out, row stride N)
//   11=CFG2  form-tagged writes ([31:30]):
//             00 -> dims:  [11:0]=N [27:16]=K   (12-bit each: K up to 4095
//                          — MNIST FC1 needs K=1152)
//             01 -> [11:0]=M (12-bit; M=256 must NOT truncate!)
//             10 -> quant: [15:0] mult [23:20] shift
//   kick     start (TUKICK, W1P)
//
// VRAM port: dedicated tua (1-cycle req/rdata reads; end-of-job C writes).

`include "ember_pkg.sv"
import ember_pkg::*;

module ember_tu
(
  input  logic        clk,
  input  logic        rst_n,

  // CSR from CP
  input  logic        csr_we,
  input  logic [1:0]  csr_addr,      // 00=TUA 01=TUW 10=TUC 11=CFG2
  input  logic [31:0] csr_wdata,
  input  logic        kick,

  // Dedicated VRAM port (BUS addresses)
  output logic        tua_we,
  output logic [31:0] tua_addr,
  output logic [31:0] tua_wdata,
  output logic [3:0]  tua_be,
  output logic        tua_req,
  input  logic [31:0] tua_rdata,

  output logic        busy
);

  localparam int unsigned N16 = 16;              // array edge (and M-block)

  // ==================================================================
  // CSR state
  // ==================================================================
  logic [31:0] a_base_q, w_base_q, c_base_q;     // VRAM byte offsets
  logic [15:0] req_mult;
  logic [3:0]  req_shift;
  logic [11:0] dim_n, dim_k;                     // 12-bit: N, K up to 4095
  logic [11:0] dim_m;                            // 12-bit (M=256 truncates
                                                 // to 0 in 8 bits!)

  wire cfg2_dim_we = csr_we && (csr_addr == 2'd3) && (csr_wdata[31:30] == 2'b00);
  wire cfg2_m_we   = csr_we && (csr_addr == 2'd3) && (csr_wdata[31:30] == 2'b01);
  wire cfg2_q_we   = csr_we && (csr_addr == 2'd3) && (csr_wdata[31:30] == 2'b10);

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      a_base_q  <= 32'h0;
      w_base_q  <= 32'h0;
      c_base_q  <= 32'h0;
      req_mult  <= 16'd1;
      req_shift <= 4'd0;
      dim_n     <= 12'd0;
      dim_k     <= 12'd0;
      dim_m     <= 12'd0;
    end else begin
      if (csr_we) begin
        case (csr_addr)
          2'd0: a_base_q <= {csr_wdata[31:2], 2'b00};
          2'd1: w_base_q <= {csr_wdata[31:2], 2'b00};
          2'd2: c_base_q <= {csr_wdata[31:2], 2'b00};
          default: ;
        endcase
      end
      if (cfg2_dim_we) begin
        dim_n <= csr_wdata[11:0];
        dim_k <= csr_wdata[27:16];
      end
      if (cfg2_m_we) dim_m <= csr_wdata[11:0];
      if (cfg2_q_we) begin
        req_mult  <= csr_wdata[15:0];
        req_shift <= csr_wdata[23:20];
      end
    end
  end

  // ==================================================================
  // Geometry
  // ==================================================================
  wire [31:0] kdim = {20'h0, dim_k};             // A row stride / K in bytes
  wire [31:0] ndim = {20'h0, dim_n};             // W/C row stride / N
  wire [31:0] mdim = {20'h0, dim_m};

  // ==================================================================
  // Buffers (declared BEFORE the array: cells read them)
  // ==================================================================
  logic [31:0] wrowbuf [4];                      // staged weight row (16B)
  logic [31:0] abuf_q  [4];                      // activation row tile (16B)

  // weight byte bus: cell (r,c) takes byte c of the staged row
  logic [7:0] wbyte [N16];

  genvar gwb;
  generate
    for (gwb = 0; gwb < N16; gwb++) begin : g_wbyte
      assign wbyte[gwb] = wrowbuf[gwb[3:2]][gwb[1:0]*8 +: 8];
    end
  endgenerate

  // ==================================================================
  // Weight-stationary cells + per-column trees (flat arrays)
  // ==================================================================
  logic [N16-1:0] w_ld;                          // per-row load pulse
  logic [7:0] w_regs [N16][N16];
  logic [7:0] a_row_byte [N16];                  // broadcast per-row byte

  always_ff @(posedge clk) begin
    for (int r = 0; r < N16; r++)
      if (w_ld[r])
        for (int c = 0; c < N16; c++)
          w_regs[r][c] <= wbyte[c];
  end

  genvar gr, gc;
  generate
    for (gr = 0; gr < N16; gr++) begin : g_ab
      assign a_row_byte[gr] = abuf_q[gr[3:2]][gr[1:0]*8 +: 8];
    end
  endgenerate

  logic signed [31:0] prod [N16][N16];
  generate
    for (gr = 0; gr < N16; gr++) begin : g_prod
      for (gc = 0; gc < N16; gc++) begin : g_pc
        assign prod[gr][gc] = 32'($signed(w_regs[gr][gc]))
                            * 32'($signed(a_row_byte[gr]));
      end
    end
  endgenerate

  logic signed [31:0] lv1 [N16][8];
  logic signed [31:0] lv2 [N16][4];
  logic signed [31:0] lv3 [N16][2];
  logic signed [31:0] tree [N16];
  genvar gt, trow;
  generate
    for (gt = 0; gt < N16; gt++) begin : g_tree
      for (trow = 0; trow < 8; trow++)
        assign lv1[gt][trow] = prod[2*trow][gt] + prod[2*trow+1][gt];
      for (trow = 8; trow < 12; trow++)
        assign lv2[gt][trow-8] = lv1[gt][2*(trow-8)]
                               + lv1[gt][2*(trow-8)+1];
      for (trow = 12; trow < 14; trow++)
        assign lv3[gt][trow-12] = lv2[gt][2*(trow-12)]
                                + lv2[gt][2*(trow-12)+1];
      assign tree[gt] = lv3[gt][0] + lv3[gt][1];
    end
  endgenerate

  // PER-ROW accumulator block: acc[r][c] = C[m0+r][n0+c] partial (int32)
  logic signed [31:0] acc [N16][N16];

  // ==================================================================
  // Tile controller
  // ==================================================================
  typedef enum logic [3:0] {
    T_IDLE, T_WFETCH, T_WLOAD, T_WLATCH, T_AFETCH, T_MAC, T_RNEXT, T_KNEXT,
    T_CREQ, T_CWRITE, T_MNEXT, T_DONE
  } tstate_e;
  tstate_e st;

  logic        running;
  assign busy = running;

  logic [31:0] k0, n0, m0;             // tile origins (k rows, n bytes, m rows)
  logic [4:0]  wrow;                   // weight row being loaded (0..15)
  logic [1:0]  wgrp;                   // word group within row (0..3)
  logic [3:0]  mrow;                   // row within the M-block (0..15)
  logic [3:0]  fcnt;                   // A-word fetch counter (0..3)
  logic        mac_pend;               // MAC issued, applies next edge

  // VRAM read engine (one outstanding request, 2-cycle occupancy)
  logic        rq_pend, rq_req_cyc;
  logic [31:0] rq_addr_q;
  logic        rq_dst_w;               // 0: wrowbuf  1: abuf_q
  logic [1:0]  rq_aw;                  // target word index

  // C write state
  logic [11:0] cw_row;                 // absolute output row (12-bit: M>256)
  logic [3:0]  cw_rblk;                // row within block (0..15)
  logic [1:0]  cw_word;
  logic [7:0]  cw_byte0, cw_byte1, cw_byte2, cw_byte3;

  // requant (combinational): ((c*mult + half) >>> shift) wrap int8
  function automatic logic [7:0] requant8(input logic signed [31:0] c32,
                                          input logic [15:0] mult,
                                          input logic [3:0] shift);
    logic signed [47:0] full, half, res;
    begin
      full = $signed(c32) * $signed({32'h0, mult});
      if (shift == 4'd0) begin
        res = full;
      end else begin
        half = 48'd1 << (shift - 4'd1);
        res  = (full + half) >>> shift;
      end
      requant8 = res[7:0];
    end
  endfunction

  task automatic reset_acc;
    for (int r = 0; r < N16; r++)
      for (int c = 0; c < N16; c++)
        acc[r][c] <= 32'sd0;
  endtask

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      st        <= T_IDLE;
      running   <= 1'b0;
      k0        <= 32'd0;
      n0        <= 32'd0;
      m0        <= 32'd0;
      wrow      <= 5'd0;
      wgrp      <= 2'd0;
      mrow      <= 4'd0;
      fcnt      <= 4'd0;
      mac_pend  <= 1'b0;
      rq_pend   <= 1'b0;
      rq_req_cyc<= 1'b0;
      rq_addr_q <= 32'h0;
      rq_dst_w  <= 1'b0;
      rq_aw     <= 2'd0;
      tua_we    <= 1'b0;
      tua_addr  <= 32'h0;
      tua_wdata <= 32'h0;
      tua_be    <= 4'h0;
      tua_req   <= 1'b0;
      w_ld      <= '0;
      cw_row    <= 12'd0;
      cw_rblk   <= 4'd0;
      cw_word   <= 2'd0;
      cw_byte0  <= 8'd0; cw_byte1 <= 8'd0;
      cw_byte2  <= 8'd0; cw_byte3 <= 8'd0;
      for (int r = 0; r < N16; r++)
        for (int c = 0; c < N16; c++)
          acc[r][c] <= 32'sd0;
    end else begin
      tua_we  <= 1'b0;
      tua_req <= 1'b0;
      w_ld    <= '0;

      // ---- read capture: data valid the cycle after the req edge ----
      if (rq_pend && !rq_req_cyc) begin
        rq_pend <= 1'b0;
        if (rq_dst_w) abuf_q[rq_aw] <= tua_rdata;
        else          wrowbuf[rq_aw] <= tua_rdata;
      end
      if (rq_req_cyc) rq_req_cyc <= 1'b0;

      // ---- MAC apply: acc[mrow][c] += tree[c] (one adder pass/row) ----
      if (mac_pend) begin
        mac_pend <= 1'b0;
        for (int c = 0; c < N16; c++)
          acc[mrow][c] <= acc[mrow][c] + tree[c];
      end

      case (st)
        // ----------------------------------------------------------
        T_IDLE: begin
          running <= 1'b0;
          if (kick) begin
            running <= 1'b1;
            n0      <= 32'd0;
            m0      <= 32'd0;
            k0      <= 32'd0;
            wrow    <= 5'd0;
            wgrp    <= 2'd0;
            reset_acc();
            st      <= T_WFETCH;
          end
        end
        // ----------------------------------------------------------
        // Weight tile load: 16 rows x 4 words (staged via wrowbuf)
        // ----------------------------------------------------------
        T_WFETCH: begin
          if (!rq_pend) begin
            rq_pend    <= 1'b1;
            rq_req_cyc <= 1'b1;
            rq_dst_w   <= 1'b0;
            rq_aw      <= wgrp;
            tua_req    <= 1'b1;
            // W[(k0+wrow)][n0 + wgrp*4 .. +3]; W row stride = N (NOT K!)
            tua_addr   <= (VRAM_BASE + w_base_q) + (k0 + 32'(wrow))*ndim
                          + n0 + {28'h0, wgrp, 2'b00};      // 28+2+2 = 32
            rq_addr_q  <= (VRAM_BASE + w_base_q) + (k0 + 32'(wrow))*ndim
                          + n0 + {28'h0, wgrp, 2'b00};      // 28+2+2 = 32
            st         <= T_WLOAD;
          end
        end
        T_WLOAD: begin
          if (!rq_pend && !rq_req_cyc) begin  // word LANDED in wrowbuf
            if (wgrp == 2'd3) begin
              st <= T_WLATCH;                // row complete: latch to cells
            end else begin
              wgrp <= wgrp + 2'd1;
              st   <= T_WFETCH;
            end
          end
        end
        T_WLATCH: begin
          w_ld[wrow[3:0]] <= 1'b1;           // cells latch wbyte[0..15]
          if (wrow == 5'd15) begin
            wrow <= 5'd0;
            mrow <= 4'd0;
            fcnt <= 4'd0;
            st   <= T_AFETCH;
          end else begin
            wrow <= wrow + 5'd1;
            wgrp <= 2'd0;
            st   <= T_WFETCH;
          end
        end
        // ----------------------------------------------------------
        // Activation rows: fetch 4 words of A[m0+mrow][k0..k0+15], MAC
        // ----------------------------------------------------------
        T_AFETCH: begin
          if (!rq_pend) begin
            rq_pend    <= 1'b1;
            rq_req_cyc <= 1'b1;
            rq_dst_w   <= 1'b1;
            rq_aw      <= fcnt[1:0];
            tua_req    <= 1'b1;
            tua_addr   <= (VRAM_BASE + a_base_q) + (m0 + 32'(mrow))*kdim + k0
                          + {28'h0, fcnt[1:0], 2'b00};      // 28+2+2 = 32
            rq_addr_q  <= (VRAM_BASE + a_base_q) + (m0 + 32'(mrow))*kdim + k0
                          + {28'h0, fcnt[1:0], 2'b00};      // 28+2+2 = 32
            if (fcnt[1:0] == 2'd3) st <= T_MAC;
            fcnt <= fcnt + 4'd1;
          end
        end
        T_MAC: begin
          if (!rq_pend && !rq_req_cyc) begin // 4th word landed in abuf_q
            mac_pend <= 1'b1;
            st       <= T_RNEXT;
          end
        end
        T_RNEXT: begin
          if (!mac_pend) begin               // MAC applied
            if (mrow == 4'd15) begin
              st <= T_KNEXT;                 // M-block done for this k-tile
            end else begin
              mrow <= mrow + 4'd1;
              fcnt <= 4'd0;
              st   <= T_AFETCH;
            end
          end
        end
        // ----------------------------------------------------------
        // k-tile loop (acc KEPT — accumulates across k per M-block)
        // ----------------------------------------------------------
        T_KNEXT: begin
          if (k0 + 32'd16 >= kdim) begin
            cw_rblk <= 4'd0;
            cw_word <= 2'd0;
            cw_row  <= m0[11:0];
            st      <= T_CREQ;             // all k done: write C block
          end else begin
            k0   <= k0 + 32'd16;
            wrow <= 5'd0;
            wgrp <= 2'd0;
            st   <= T_WFETCH;
          end
        end
        // ----------------------------------------------------------
        // Write C block (16 rows x 4 words, requant)
        // ----------------------------------------------------------
        T_CREQ: begin
          cw_byte0 <= requant8(acc[cw_rblk][cw_word*4 + 0], req_mult,
                               req_shift);
          cw_byte1 <= requant8(acc[cw_rblk][cw_word*4 + 1], req_mult,
                               req_shift);
          cw_byte2 <= requant8(acc[cw_rblk][cw_word*4 + 2], req_mult,
                               req_shift);
          cw_byte3 <= requant8(acc[cw_rblk][cw_word*4 + 3], req_mult,
                               req_shift);
          st <= T_CWRITE;
        end
        T_CWRITE: begin
          tua_we    <= 1'b1;
          tua_be    <= 4'hF;
          tua_addr  <= (VRAM_BASE + c_base_q) + 32'(cw_row)*ndim + n0
                       + {28'h0, cw_word, 2'b00};        // 28+2+2 = 32
          tua_wdata <= {cw_byte3, cw_byte2, cw_byte1, cw_byte0};
          if (cw_word == 2'd3) begin
            cw_word <= 2'd0;
            if (cw_rblk == 4'd15) begin
              st <= T_MNEXT;
            end else begin
              cw_rblk <= cw_rblk + 4'd1;
              cw_row  <= cw_row + 12'd1;
              st      <= T_CREQ;
            end
          end else begin
            cw_word <= cw_word + 2'd1;
            st      <= T_CREQ;
          end
        end
        // ----------------------------------------------------------
        // M-block loop: next 16 rows (acc reset) or the n/m ends
        // ----------------------------------------------------------
        T_MNEXT: begin
          if (m0 + 32'd16 >= mdim) begin
            // M-block done: next n-tile or finish
            if (n0 + 32'd16 >= ndim) begin
              running <= 1'b0;
              st      <= T_DONE;
            end else begin
              n0  <= n0 + 32'd16;
              m0  <= 32'd0;
              k0  <= 32'd0;
              wrow <= 5'd0;
              wgrp <= 2'd0;
              reset_acc();
              st  <= T_WFETCH;
            end
          end else begin
            m0  <= m0 + 32'd16;
            k0  <= 32'd0;
            wrow <= 5'd0;
            wgrp <= 2'd0;
            reset_acc();
            st  <= T_WFETCH;
          end
        end
        T_DONE: begin
          running <= 1'b0;
          st      <= T_IDLE;
        end
        default: st <= T_IDLE;
      endcase
    end
  end

endmodule : ember_tu
