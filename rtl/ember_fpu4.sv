// ember_fpu4.sv - Phase-4 geometry FPU: 4 independent fp32 lanes.
//
// Pure-RTL IEEE-754 single precision soft float (round-to-nearest-even).
// Subnormal results flush to zero (FTZ); NaN/Inf propagate per IEEE-754.
//
// Contract:
//   * op[1:0]: 0=ADD 1=SUB 2=MUL 3=DIV (shared by all lanes); lane_en[i]=1
//     executes lane i on (a_i, b_i).
//   * go (1-cycle pulse) starts the enabled lanes; done is a 1-cycle pulse
//     when y* are valid (6 cycles after the go edge); busy covers the op.
//   * y* hold their values until the next go.
//
// Implementation notes (bit-exact vs tools/golden/fpu.py):
//   * ADD/SUB: operands aligned into a 34-bit unsigned field (hidden bit at
//     bit 33 + 23 fraction + 10 guard/sticky bits); smaller magnitude is
//     right-shifted with sticky-OR; 34-bit add/sub; normalize + RNE.
//   * MUL: 24x24 -> exact 48-bit product, single RNE from 2 guard bits.
//   * DIV: 64-bit restoring division (num = fraction << 26), quotient has
//     2 guard bits + exact remainder for sticky -> exact RNE.
//   * Exponent arithmetic in 10 bits; wrapped negatives land >= 512
//     (disjoint from genuine [0..385]) -> underflow FTZ; >=255 -> Inf.

module ember_fpu4
(
  input  logic        clk,
  input  logic        rst_n,

  input  logic [3:0]  lane_en,
  input  logic [3:0]  op,
  input  logic [31:0] a0, b0,
  input  logic [31:0] a1, b1,
  input  logic [31:0] a2, b2,
  input  logic [31:0] a3, b3,
  input  logic        go,

  output logic [31:0] y0, y1, y2, y3,
  output logic        busy,
  output logic        done
);

  localparam logic [1:0] FOP_ADD = 2'd0;
  localparam logic [1:0] FOP_SUB = 2'd1;
  localparam logic [1:0] FOP_MUL = 2'd2;
  localparam logic [1:0] FOP_DIV = 2'd3;

  localparam int unsigned AW = 34;

  // index of the highest set bit of a 34-bit value (0 if none).
  // ASCENDING loop: last assignment wins -> highest set bit.  (A descending
  // loop silently returns the LOWEST set bit — cost us a day.)
  function automatic logic [5:0] msb_idx34(input logic [AW-1:0] v);
    logic [5:0] r;
    begin
      r = 6'd0;
      for (int i = 0; i < AW; i++)
        if (v[i]) r = i[5:0];
      msb_idx34 = r;
    end
  endfunction

  // ================================================================
  // ADD/SUB
  // ================================================================
  function automatic logic [31:0] fpu_add(input logic [31:0] av,
                                          input logic [31:0] bv,
                                          input logic        sub_op);
    logic        sa, sb, sbs, big_a, sign_r;
    logic [7:0]  ea, eb, big_e, delta;
    logic [22:0] fa, fb, fr;
    logic        a_nan, b_nan, a_inf, b_inf, a_z, b_z;
    logic [AW-1:0] fa_w, fb_w, norm;
    logic [AW:0]   fsum;
    logic [5:0]    top;
    logic [15:0]   sh_l;
    logic [10:0]   e9;
    logic          g, s, inc, fc;
    begin
      sa = av[31];    ea = av[30:23]; fa = av[22:0];
      sb = bv[31];    eb = bv[30:23]; fb = bv[22:0];
      sbs = sb ^ sub_op;

      a_nan = (ea == 8'hFF) && (fa != 23'd0);
      b_nan = (eb == 8'hFF) && (fb != 23'd0);
      a_inf = (ea == 8'hFF) && (fa == 23'd0);
      b_inf = (eb == 8'hFF) && (fb == 23'd0);
      a_z   = (ea == 8'h00) && (fa == 23'd0);
      b_z   = (eb == 8'h00) && (fb == 23'd0);

      if (a_nan) return av;
      if (b_nan) return bv;
      if (a_inf && b_inf && (sa != sbs)) return 32'h7FC00000;
      if (a_inf) return av;
      if (b_inf) return {sbs, 8'hFF, 23'd0};
      if (a_z && b_z) return 32'h00000000;
      if (a_z) return {sbs, eb, fb};
      if (b_z) return av;

      big_a = (ea > eb) || ((ea == eb) && (fa >= fb));
      big_e = big_a ? ea : eb;

      fa_w = {1'b1, fa, 10'd0};
      fb_w = {1'b1, fb, 10'd0};
      delta = big_a ? (ea - eb) : (eb - ea);
      if (delta != 8'd0) begin
        if (delta >= 8'd34) begin
          if (big_a) fb_w = 34'h1;
          else       fa_w = 34'h1;
        end else begin
          sh_l = 16'd34 - {8'd0, delta};
          if (big_a)
            fb_w = (fb_w >> delta) | {33'd0, |(fb_w << sh_l)};
          else
            fa_w = (fa_w >> delta) | {33'd0, |(fa_w << sh_l)};
        end
      end

      if (sa == sbs) begin
        fsum   = {1'b0, fa_w} + {1'b0, fb_w};
        sign_r = sa;
      end else if (big_a) begin
        fsum   = {1'b0, fa_w} - {1'b0, fb_w};
        sign_r = sa;
      end else begin
        fsum   = {1'b0, fb_w} - {1'b0, fa_w};
        sign_r = sbs;
      end

      if (fsum == '0) return 32'h00000000;

      if (fsum[AW]) begin
        norm = fsum[AW:1];
        e9   = {3'b000, big_e} + 11'd1;
        s    = fsum[0] || (|norm[8:0]);
      end else begin
        top  = msb_idx34(fsum[AW-1:0]);
        norm = fsum[AW-1:0] << (6'd33 - top);
        e9   = {3'b000, big_e} + {5'b00000, top} - 11'd33;
        s    = |norm[8:0];
      end

      fr  = norm[32:10];
      g   = norm[9];
      inc = g && (s || fr[0]);
      fc  = inc && (fr == 23'h7FFFFF);
      if (inc) fr = fr + 23'd1;
      if (fc)  e9 = e9 + 11'd1;

      if (e9 >= 11'd512) return {sign_r, 31'd0};
      if (e9 >= 11'd255) return {sign_r, 8'hFF, 23'd0};
      if (e9 == 11'd0)   return {sign_r, 31'd0};
      return {sign_r, e9[7:0], fr};
    end
  endfunction

  // ================================================================
  // MUL
  // ================================================================
  function automatic logic [31:0] fpu_mul(input logic [31:0] av,
                                          input logic [31:0] bv);
    logic        sa, sb, sg;
    logic [7:0]  ea, eb;
    logic [22:0] fa, fb, fr;
    logic        a_nan, b_nan, a_inf, b_inf, a_z, b_z;
    logic [47:0] prod;
    logic [23:0] f24;
    logic [10:0] e9;
    logic        g, s, inc, fc;
    begin
      sa = av[31];    ea = av[30:23]; fa = av[22:0];
      sb = bv[31];    eb = bv[30:23]; fb = bv[22:0];

      a_nan = (ea == 8'hFF) && (fa != 23'd0);
      b_nan = (eb == 8'hFF) && (fb != 23'd0);
      a_inf = (ea == 8'hFF) && (fa == 23'd0);
      b_inf = (eb == 8'hFF) && (fb == 23'd0);
      a_z   = (ea == 8'h00) && (fa == 23'd0);
      b_z   = (eb == 8'h00) && (fb == 23'd0);

      if (a_nan) return av;
      if (b_nan) return bv;
      sg = sa ^ sb;
      if (a_inf || b_inf) begin
        if (a_z || b_z) return {sg, 8'hFF, 1'b1, 22'd0};
        return {sg, 8'hFF, 23'd0};
      end
      if (a_z || b_z) return {sg, 31'd0};

      prod = {1'b1, fa} * {1'b1, fb};
      if (prod[47]) begin
        f24 = {prod[47], prod[46:24]};
        g   = prod[23];
        s   = |prod[22:0];
        e9  = {3'b000, ea} + {3'b000, eb} - 11'd126;
      end else begin
        f24 = {prod[46], prod[45:23]};
        g   = prod[22];
        s   = |prod[21:0];
        e9  = {3'b000, ea} + {3'b000, eb} - 11'd127;
      end

      fr  = f24[22:0];
      inc = g && (s || fr[0]);
      fc  = inc && (fr == 23'h7FFFFF);
      if (inc) fr = fr + 23'd1;
      if (fc)  e9 = e9 + 11'd1;

      if (e9 >= 11'd512) return {sg, 31'd0};
      if (e9 >= 11'd255) return {sg, 8'hFF, 23'd0};
      if (e9 == 11'd0)   return {sg, 31'd0};
      return {sg, e9[7:0], fr};
    end
  endfunction

  // ================================================================
  // DIV (64-bit restoring division, 2 guard bits + exact sticky)
  // ================================================================
  function automatic logic [31:0] fpu_div(input logic [31:0] av,
                                          input logic [31:0] bv);
    logic        sa, sb, sg;
    logic [7:0]  ea, eb;
    logic [22:0] fa, fb, fr;
    logic        a_nan, b_nan, a_inf, b_inf, a_z, b_z;
    logic [63:0] num, den, rem, q;
    logic [23:0] f24;
    logic [10:0] e9;
    logic        g, s, inc, fc;
    begin
      sa = av[31];    ea = av[30:23]; fa = av[22:0];
      sb = bv[31];    eb = bv[30:23]; fb = bv[22:0];

      a_nan = (ea == 8'hFF) && (fa != 23'd0);
      b_nan = (eb == 8'hFF) && (fb != 23'd0);
      a_inf = (ea == 8'hFF) && (fa == 23'd0);
      b_inf = (eb == 8'hFF) && (fb == 23'd0);
      a_z   = (ea == 8'h00) && (fa == 23'd0);
      b_z   = (eb == 8'h00) && (fb == 23'd0);

      if (a_nan) return av;
      if (b_nan) return bv;
      sg = sa ^ sb;
      if (a_inf && b_inf) return 32'h7FC00000;
      if (a_inf) return {sg, 8'hFF, 23'd0};
      if (b_inf) return {sg, 31'd0};
      if (b_z) begin
        if (a_z) return 32'h7FC00000;
        return {sg, 8'hFF, 23'd0};
      end
      if (a_z) return {sg, 31'd0};

      num = {14'd0, 1'b1, fa, 26'd0};
      den = {40'd0, 1'b1, fb};
      rem = 64'd0;
      q   = 64'd0;
      for (int i = 63; i >= 0; i--) begin
        rem = (rem << 1) | {63'd0, num[i]};
        if (rem >= den) begin
          rem  = rem - den;
          q[i] = 1'b1;
        end
      end

      if (q[26]) begin
        f24 = q[26:3];
        g   = q[2];
        s   = q[1] || q[0] || (rem != 64'd0);
        e9  = {3'b000, ea} - {3'b000, eb} + 11'd127;
      end else begin
        f24 = q[25:2];
        g   = q[1];
        s   = q[0] || (rem != 64'd0);
        e9  = {3'b000, ea} - {3'b000, eb} + 11'd126;
      end

      fr  = f24[22:0];
      inc = g && (s || fr[0]);
      fc  = inc && (fr == 23'h7FFFFF);
      if (inc) fr = fr + 23'd1;
      if (fc)  e9 = e9 + 11'd1;

      if (e9 >= 11'd512) return {sg, 31'd0};
      if (e9 >= 11'd255) return {sg, 8'hFF, 23'd0};
      if (e9 == 11'd0)   return {sg, 31'd0};
      return {sg, e9[7:0], fr};
    end
  endfunction

  // ================================================================
  // Op dispatch
  // ================================================================
  function automatic logic [31:0] fpu_exec(input logic [1:0]  opc,
                                           input logic [31:0] av,
                                           input logic [31:0] bv);
    case (opc)
      FOP_ADD: fpu_exec = fpu_add(av, bv, 1'b0);
      FOP_SUB: fpu_exec = fpu_add(av, bv, 1'b1);
      FOP_MUL: fpu_exec = fpu_mul(av, bv);
      default: fpu_exec = fpu_div(av, bv);
    endcase
  endfunction

  // ================================================================
  // 4-lane control (uniform 6-cycle latency, done pulse at the end)
  // ================================================================
  typedef struct packed {
    logic        busy;
    logic        done;
    logic [1:0]  opc;
    logic [2:0]  cnt;
    logic [31:0] a;
    logic [31:0] b;
    logic [31:0] y;
  } lane_t;

  lane_t s0, s1, s2, s3;

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      s0 <= '0;
    end else begin
      s0.done <= 1'b0;
      if (go && lane_en[0]) begin
        s0.busy <= 1'b1;
        s0.cnt  <= 3'd0;
        s0.opc  <= op[1:0];
        s0.a    <= a0;
        s0.b    <= b0;
        s0.y    <= 32'h0;
      end else if (s0.busy) begin
        if (s0.cnt == 3'd4) begin
          s0.busy <= 1'b0;
          s0.done <= 1'b1;
          s0.y    <= fpu_exec(s0.opc, s0.a, s0.b);
        end else begin
          s0.cnt <= s0.cnt + 3'd1;
        end
      end
    end
  end

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      s1 <= '0;
    end else begin
      s1.done <= 1'b0;
      if (go && lane_en[1]) begin
        s1.busy <= 1'b1;
        s1.cnt  <= 3'd0;
        s1.opc  <= op[1:0];
        s1.a    <= a1;
        s1.b    <= b1;
        s1.y    <= 32'h0;
      end else if (s1.busy) begin
        if (s1.cnt == 3'd4) begin
          s1.busy <= 1'b0;
          s1.done <= 1'b1;
          s1.y    <= fpu_exec(s1.opc, s1.a, s1.b);
        end else begin
          s1.cnt <= s1.cnt + 3'd1;
        end
      end
    end
  end

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      s2 <= '0;
    end else begin
      s2.done <= 1'b0;
      if (go && lane_en[2]) begin
        s2.busy <= 1'b1;
        s2.cnt  <= 3'd0;
        s2.opc  <= op[1:0];
        s2.a    <= a2;
        s2.b    <= b2;
        s2.y    <= 32'h0;
      end else if (s2.busy) begin
        if (s2.cnt == 3'd4) begin
          s2.busy <= 1'b0;
          s2.done <= 1'b1;
          s2.y    <= fpu_exec(s2.opc, s2.a, s2.b);
        end else begin
          s2.cnt <= s2.cnt + 3'd1;
        end
      end
    end
  end

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      s3 <= '0;
    end else begin
      s3.done <= 1'b0;
      if (go && lane_en[3]) begin
        s3.busy <= 1'b1;
        s3.cnt  <= 3'd0;
        s3.opc  <= op[1:0];
        s3.a    <= a3;
        s3.b    <= b3;
        s3.y    <= 32'h0;
      end else if (s3.busy) begin
        if (s3.cnt == 3'd4) begin
          s3.busy <= 1'b0;
          s3.done <= 1'b1;
          s3.y    <= fpu_exec(s3.opc, s3.a, s3.b);
        end else begin
          s3.cnt <= s3.cnt + 3'd1;
        end
      end
    end
  end

  assign y0 = s0.y;
  assign y1 = s1.y;
  assign y2 = s2.y;
  assign y3 = s3.y;
  assign busy = s0.busy || s1.busy || s2.busy || s3.busy;
  assign done = s0.done || s1.done || s2.done || s3.done;

endmodule : ember_fpu4
