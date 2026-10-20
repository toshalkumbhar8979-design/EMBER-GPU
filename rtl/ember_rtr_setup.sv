// ember_rtr_setup.sv — combinational triangle setup for the RTR (Q10.22).
//
// Matches tools/golden/raster.py bit-for-bit:
//   * coords/u/v: s32 Q10.22 (1.0 = 22'sh400000); 1/w plane value = ONE_Q
//   * z plane: RAW 16-bit depth (no Q scaling)
//   * denom (signed area) = dx01*dy20 - dy01*dx20, Q10.44 in s67
//   * A = ((dv10*dy20 - dv20*dy10) <<< 22) / den   (truncate toward zero —
//     Verilog signed '/' truncates, same as golden tdiv)
//   * C = val0 - ((A*x0 >>> 22) + (B*y0 >>> 22))
//   * cull iff area <= 0 (CCW front)
//   * bbox = vertex extent clamped to screen (320x240)
//
// NOTE (synthesis): the seven '/' dividers are combinational. Simulation-
// friendly; pipeline or share them for FPGA in Phase 3+.

`include "ember_pkg.sv"
import ember_pkg::*;

module ember_rtr_setup
(
  input  logic signed [31:0] x0, y0, x1, y1, x2, y2,   // Q10.22
  input  logic signed [31:0] u0, v0, u1, v1, u2, v2,   // Q10.22
  input  logic [15:0]        z0, z1, z2,               // raw depth
  input  logic [7:0]         r0, g0, b0, r1, g1, b1, r2, g2, b2,

  output logic               cull,
  output logic signed [66:0] area,

  output logic signed [63:0] iwA, iwB, iwC,
  output logic signed [63:0] rA, rB, rC,
  output logic signed [63:0] gA, gB, gC,
  output logic signed [63:0] bA, bB, bC,
  output logic signed [63:0] zA, zB, zC,
  output logic signed [63:0] uA, uB, uC,
  output logic signed [63:0] vA, vB, vC,

  output logic [15:0] x_lo_i, x_hi_i, y_lo_i, y_hi_i,  // integer pixel bounds
  output logic signed [32:0] dx01, dy01, dx12, dy12, dx20, dy20
);

  localparam logic signed [63:0] ONE_Q = 64'sd4194304;   // 1.0 in Q10.22

  // ------------------------------------------------------------------
  // Cramer deltas (from v0): s33
  // ------------------------------------------------------------------
  logic signed [32:0] dy10_, dy20_, dx10_, dx20_;
  assign dy10_ = y1 - y0;
  assign dy20_ = y2 - y0;
  assign dx10_ = x1 - x0;
  assign dx20_ = x2 - x0;

  // ------------------------------------------------------------------
  // Edge deltas for scan stepping (s33)
  // ------------------------------------------------------------------
  assign dx01 = x1 - x0;
  assign dy01 = y1 - y0;
  assign dx12 = x2 - x1;
  assign dy12 = y2 - y1;
  assign dx20 = x0 - x2;
  assign dy20 = y0 - y2;

  // ------------------------------------------------------------------
  // Signed area (s67): dx10*dy20 - dy10*dx20 (golden formula)
  // ------------------------------------------------------------------
  logic signed [65:0] p1, p2;
  assign p1   = dx10_ * dy20_;
  assign p2   = dy10_ * dx20_;
  assign area = p1 - p2;
  assign cull = (area <= 0);

  logic signed [66:0] den;
  assign den = (area == 0) ? 67'sd1 : area;

  // ------------------------------------------------------------------
  // Coefficient helpers. num = dv10*dy20 - dv20*dy10 (s96 covers all
  // planes: z dv is s17, delta s33 -> s50, minus s51, <<22 -> s73; s96 safe)
  // ------------------------------------------------------------------
  function automatic logic signed [63:0] coef_a(
    input logic signed [95:0] dv10, dv20,
    input logic signed [32:0] dy20_, dy10_,
    input logic signed [66:0] den_);
    logic signed [95:0] num;
    logic signed [117:0] num_sh;
    logic signed [117:0] den_x;
    logic signed [117:0] q;
    begin
      num    = dv10 * dy20_ - dv20 * dy10_;
      num_sh = num <<< 22;
      den_x  = {{51{den_[66]}}, den_};   // sign-extend to match num_sh
      q      = num_sh / den_x;
      coef_a = q[63:0];   // truncation safe: |A| << 2^63 for screen-size tris
    end
  endfunction

  function automatic logic signed [63:0] coef_b(
    input logic signed [95:0] dv20, dv10,
    input logic signed [32:0] dx10_, dx20_,
    input logic signed [66:0] den_);
    logic signed [95:0] num;
    logic signed [117:0] num_sh;
    logic signed [117:0] den_x;
    logic signed [117:0] q;
    begin
      num    = dv20 * dx10_ - dv10 * dx20_;
      num_sh = num <<< 22;
      den_x  = {{51{den_[66]}}, den_};
      q      = num_sh / den_x;
      coef_b = q[63:0];
    end
  endfunction

  function automatic logic signed [63:0] coef_c(
    input logic signed [63:0] A, B,
    input logic signed [31:0] x0_, y0_,
    input logic signed [95:0] val0);
    logic signed [95:0] ax, by, sub;
    logic signed [95:0] c_res;
    begin
      ax  = A * x0_;
      by  = B * y0_;
      sub = (ax + by) >>> 22;   // shift the SUM once (matches golden)
      c_res = val0 - sub;
      coef_c = c_res[63:0];     // safe: |C| fits s64 for screen tris
    end
  endfunction

  // Vertex values as s96 for the coef functions, in the GOLDEN domains:
  //   colors: unsigned u8 scaled into Q10.22 (golden: v0.r << Q)
  //   depth:  RAW u16, NO Q scaling (golden passes v0.z unchanged)
  //   u/v:    already s32 Q10.22 — sign-extended only
  // (Two earlier bugs lived here: sign-extending unsigned u8/u16 made
  // 255 look negative, and dropping the <<22 made every color plane ~0.)
  logic signed [95:0] r0e, r1e, r2e, g0e, g1e, g2e, b0e, b1e, b2e;
  logic signed [95:0] z0e, z1e, z2e, u0e, u1e, u2e, v0e, v1e, v2e;
  assign r0e = {66'b0, r0, 22'b0};
  assign r1e = {66'b0, r1, 22'b0};
  assign r2e = {66'b0, r2, 22'b0};
  assign g0e = {66'b0, g0, 22'b0};
  assign g1e = {66'b0, g1, 22'b0};
  assign g2e = {66'b0, g2, 22'b0};
  assign b0e = {66'b0, b0, 22'b0};
  assign b1e = {66'b0, b1, 22'b0};
  assign b2e = {66'b0, b2, 22'b0};
  assign z0e = {80'b0, z0};
  assign z1e = {80'b0, z1};
  assign z2e = {80'b0, z2};
  assign u0e = {{64{u0[31]}}, u0};
  assign u1e = {{64{u1[31]}}, u1};
  assign u2e = {{64{u2[31]}}, u2};
  assign v0e = {{64{v0[31]}}, v0};
  assign v1e = {{64{v1[31]}}, v1};
  assign v2e = {{64{v2[31]}}, v2};
  logic signed [95:0] r10, r20, g10, g20, b10, b20, z10, z20;
  logic signed [95:0] u10, u20, v10, v20;
  assign r10 = r1e - r0e;
  assign r20 = r2e - r0e;
  assign g10 = g1e - g0e;
  assign g20 = g2e - g0e;
  assign b10 = b1e - b0e;
  assign b20 = b2e - b0e;
  assign z10 = z1e - z0e;
  assign z20 = z2e - z0e;
  assign u10 = u1e - u0e;
  assign u20 = u2e - u0e;
  assign v10 = v1e - v0e;
  assign v20 = v2e - v0e;

  logic signed [95:0] one0;   // 1/w plane: all three vertex values = ONE_Q
  assign one0 = {{32{ONE_Q[63]}}, ONE_Q};
  logic signed [95:0] zero96; // 1/w is CONSTANT -> vertex DELTAS are zero
  assign zero96 = '0;

  // ------------------------------------------------------------------
  // 1/w plane (constant 1.0 -> A=B=0, C=ONE_Q). NOTE: coef_a/coef_b take
  // vertex DELTAS; passing the VALUE one0 here instead of zero deltas was
  // the Phase-2 texel-coordinate bug (spurious inv_w gradient).
  // ------------------------------------------------------------------
  assign iwA = coef_a(zero96, zero96, dy20_, dy10_, den);
  assign iwB = coef_b(zero96, zero96, dx10_, dx20_, den);
  assign iwC = coef_c(iwA, iwB, x0, y0, one0);

  // color planes
  assign rA = coef_a(r10, r20, dy20_, dy10_, den);
  assign rB = coef_b(r20, r10, dx10_, dx20_, den);
  assign rC = coef_c(rA, rB, x0, y0, r0e);

  assign gA = coef_a(g10, g20, dy20_, dy10_, den);
  assign gB = coef_b(g20, g10, dx10_, dx20_, den);
  assign gC = coef_c(gA, gB, x0, y0, g0e);

  assign bA = coef_a(b10, b20, dy20_, dy10_, den);
  assign bB = coef_b(b20, b10, dx10_, dx20_, den);
  assign bC = coef_c(bA, bB, x0, y0, b0e);

  // z plane (raw depth)
  assign zA = coef_a(z10, z20, dy20_, dy10_, den);
  assign zB = coef_b(z20, z10, dx10_, dx20_, den);
  assign zC = coef_c(zA, zB, x0, y0, z0e);

  // uv planes
  assign uA = coef_a(u10, u20, dy20_, dy10_, den);
  assign uB = coef_b(u20, u10, dx10_, dx20_, den);
  assign uC = coef_c(uA, uB, x0, y0, u0e);

  assign vA = coef_a(v10, v20, dy20_, dy10_, den);
  assign vB = coef_b(v20, v10, dx10_, dx20_, den);
  assign vC = coef_c(vA, vB, x0, y0, v0e);

  // ------------------------------------------------------------------
  // Bounding box: CLAMP vertex extents to the screen FIRST, then FLOOR to
  // integer pixels (golden: x_lo = max(min(vs),0), x_hi = min(max(vs),319<<Q)
  // then iterate x_lo>>Q .. x_hi>>Q). Flooring after clamping is what makes
  // an xmax of 319.75 cover pixel column 319 like the golden model does.
  // ------------------------------------------------------------------
  function automatic logic [15:0] clamp_lo(input logic signed [31:0] v,
                                           input logic signed [31:0] lim);
    logic signed [31:0] c;
    logic signed [31:0] f;
    begin
      c = (v < 0) ? 32'sd0 : ((v > lim) ? lim : v);
      f = c >>> 22;                     // floor (arithmetic shift)
      if (f < 0)             clamp_lo = 16'd0;
      else                   clamp_lo = f[15:0];
    end
  endfunction

  function automatic logic [15:0] clamp_hi(input logic signed [31:0] v,
                                           input logic signed [31:0] lim);
    logic signed [31:0] c;
    logic signed [31:0] f;
    begin
      c = (v < 0) ? 32'sd0 : ((v > lim) ? lim : v);
      f = c >>> 22;
      if (f > lim[31:22])    clamp_hi = lim[15:0];   // > screen max
      else if (f < 0)        clamp_hi = 16'd0;
      else                   clamp_hi = f[15:0];
    end
  endfunction

  logic signed [31:0] xmin, xmax, ymin, ymax;
  assign xmin = (x0 < x1) ? ((x0 < x2) ? x0 : x2) : ((x1 < x2) ? x1 : x2);
  assign xmax = (x0 > x1) ? ((x0 > x2) ? x0 : x2) : ((x1 > x2) ? x1 : x2);
  assign ymin = (y0 < y1) ? ((y0 < y2) ? y0 : y2) : ((y1 < y2) ? y1 : y2);
  assign ymax = (y0 > y1) ? ((y0 > y2) ? y0 : y2) : ((y1 > y2) ? y1 : y2);

  localparam logic signed [31:0] XMAX_Q = 32'sd319 << 22;   // 319 in Q10.22
  localparam logic signed [31:0] YMAX_Q = 32'sd239 << 22;   // 239 in Q10.22

  assign x_lo_i = clamp_lo(xmin, XMAX_Q);
  assign x_hi_i = clamp_hi(xmax, XMAX_Q);
  assign y_lo_i = clamp_lo(ymin, YMAX_Q);
  assign y_hi_i = clamp_hi(ymax, YMAX_Q);

endmodule : ember_rtr_setup
