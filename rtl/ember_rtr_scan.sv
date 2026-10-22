// ember_rtr_scan.sv — RTR scan engine (correctness-first, golden-exact).
//
// Per pixel: edges computed DIRECTLY from (cx,cy) — no incremental stepping
// (matches tools/golden/raster.py exactly):
//   e01 = dx01*(cy-y0) - dy01*(cx-x0);  inside iff e01>0 && e12>0 && e20>0
// Pixel centers: cx = (x_lo_i<<22) + 0.5<<22 + (ix-x_lo_i)<<22, cy likewise.
// Plane evals: ((A*cx + B*cy) >>> 22) + C.
// Perspective: u_fin = (u_raw <<< 22) / inv_w (signed '/' truncates toward
// zero, same as golden tdiv; inv_w==0 -> 0, same as golden).
// Z compare: z_v < zold (zero-extended 16b) passes; write z_v[15:0].
// FB/Z PIXEL LAYOUT: byte-packed at 2*(y*320+x) — a pixel lands in the LOW
// halfword of its 32-bit word when x is even, HIGH when odd (w={odd,even}).
// All FB/Z accesses use the WORD address with correct byte lanes.
// Texel: TEX_BASE + (v8<<8) + u8; u8 picks the byte lane. Two resolutions
// of that byte:
//   * t_texpal = 0 (v1 default): GRAY expand, cr=cg=cb=byte — bit-for-bit
//     what the pre-palette RTL did.
//   * t_texpal = 1: the byte indexes the 256-entry CLUT at PAL_BASE
//     (VRAM, {8'h0,b,g,r} per entry), read on the same fpa2 port — the
//     texel byte is registered while the palette word is in flight.
// ROP order (== golden): clamp/texel -> [rgbmap swap] -> [blend 50%] ->
// [dither +/-1] -> pack RGB565. Implemented as combinational muxes on the
// registered color so one cycle performs dither+pack coherently.
// VRAM timing: pixel-port reads have 1-cycle latency. Requests are REGISTERED
// one state before the data is consumed:
//   z-read  fired in S_PIX  -> data consumed in S_ZRD (2 states later)
//   tex-read fired in S_TRQ -> data consumed in S_TRC
//   fb-read fired in S_FRQ  -> data consumed in S_FRC
// FSM rule: a registered value is consumed no earlier than the NEXT state.

`include "ember_pkg.sv"
import ember_pkg::*;

// ----------------------------------------------------------------------
// Hierarchical-synthesis assist modules (Phase 8 rtr_scan GDS).
//
// Monolithic synthesis of ember_rtr_scan explodes: 1,416,166 cells / ~90GB
// peak (ABC OOM even at 27GB on related rtr_top AIGs). The mass is 20
// shift-add multipliers + two combinational 96/96 dividers. These two
// tiny modules give the GDS flow stable synthesis roots so they can be
// hardened as separate macros (same pattern as rtr_top/rtr_setup).
//
// BIT-EXACTNESS: each module body performs the identical operator sequence
// the original inline expressions used (products truncate in s96 context,
// self-determined >>>22, signed '/' truncation). tb_rtr (bit-exact vs
// golden raster) validates the restructure end to end.
// ----------------------------------------------------------------------
module _rtr_smul96 (
  input  logic signed [95:0] a,
  input  logic signed [95:0] b,
  output logic signed [95:0] q
);
  // product truncating to s96, exactly like the original inline (a * b)
  // assigned into an s96 lvalue
  assign q = a * b;
endmodule

module _rtr_sdiv96 (
  input  logic signed [95:0] num,
  input  logic signed [95:0] den,
  output logic signed [95:0] q
);
  // Continuous-assign form only: no always blocks. sv2v's conversion of an
  // always_comb here trips yosys PROC_DFF ("Multiple edge sensitive events").
  // Widths are self-determined per wire, matching the original inline
  // pdiv() bit-for-bit: sign-extend, shift left 22, signed '/' truncates
  // toward zero, result truncated to s96, den==0 -> 0 (golden rule).
  wire signed [191:0] n  = {{96{num[95]}}, num};
  wire signed [191:0] d  = {{96{den[95]}}, den};
  wire signed [191:0] qq = $signed(n <<< 22) / $signed(d);
  assign q = (den == 0) ? 96'sd0 : qq[95:0];
endmodule

module ember_rtr_scan
(
  input  logic        clk,
  input  logic        rst_n,

  input  logic               start,
  input  logic               t_blend, t_ztest, t_tex, t_dither, t_rgbmap,
  input  logic               t_texpal,
  input  logic [7:0]         t_texpage,          // reserved in v1 (unused)
  input  logic signed [63:0] iwA, iwB, iwC,
  input  logic signed [63:0] rA, rB, rC,
  input  logic signed [63:0] gA, gB, gC,
  input  logic signed [63:0] bA, bB, bC,
  input  logic signed [63:0] zA, zB, zC,
  input  logic signed [63:0] uA, uB, uC,
  input  logic signed [63:0] vA, vB, vC,
  input  logic [15:0]        x_lo_i, x_hi_i, y_lo_i, y_hi_i,
  input  logic signed [31:0] x0, y0, x1, y1, x2, y2,
  input  logic signed [32:0] dx01, dy01, dx12, dy12, dx20, dy20,

  output logic               fpa_we,
  output logic [31:0]        fpa_addr,
  output logic [31:0]        fpa_wdata,
  output logic [3:0]         fpa_be,
  output logic               fpa_req,
  input  logic [31:0]        fpa_rdata,

  output logic               fpa2_req,
  output logic [31:0]        fpa2_addr,
  input  logic [31:0]        fpa2_rdata,

  output logic               busy,
  output logic               done
);

  localparam logic signed [63:0] HALF_Q = 64'sd2097152;   // 0.5 in Q10.22
  // fpa/fpa2 ports take BUS addresses (ember_vram.addr2word strips VRAM_BASE)
  localparam logic [31:0] FB0 = VRAM_BASE + FB0_BASE;
  localparam logic [31:0] ZB  = VRAM_BASE + ZBUF_BASE;
  localparam logic [31:0] PAL = VRAM_BASE + PAL_BASE;

  // 17 states: 4 bits no longer hold them (palette mode added PRQ/PRD/PRC)
  typedef enum logic [4:0] {
    S_IDLE, S_PIX, S_EVAL, S_ZRD, S_ATR, S_TRQ, S_TRD, S_TRC,
    S_PRQ, S_PRD, S_PRC, S_FRQ, S_FRD, S_FRC, S_WR, S_WRZ, S_NEXT
  } state_e;
  state_e st;

  assign busy = (st != S_IDLE);

  logic [15:0] ix, iy;
  logic signed [63:0] cx, cy;

  logic signed [95:0] e01, e12, e20;

  // attribute registers (valid the state AFTER S_EVAL)
  logic signed [95:0] r_v, g_v, b_v, z_v, u_raw, v_raw, inv_w_v;
  logic signed [95:0] u_fin, v_fin;      // perspective-corrected (S_ATR+1)

  logic        z_pass;
  logic [7:0]  cr, cg, cb, mr, mg, mb;
  logic [31:0] zaddr, faddr;

  // packed-data helpers: extract/insert pixel in the correct halfword lane
  function automatic logic [15:0] half_get(input logic [31:0] w, input logic hi);
    half_get = hi ? w[31:16] : w[15:0];
  endfunction

  // RGB565 channel expand (zero-fill LSBs, matching golden's <<3/<<2/<<3)
  function automatic logic [7:0] expand565_r(input logic [15:0] p);
    expand565_r = {p[15:11], 3'b000};
  endfunction
  function automatic logic [7:0] expand565_g(input logic [15:0] p);
    expand565_g = {p[10:5], 2'b00};
  endfunction
  function automatic logic [7:0] expand565_b(input logic [15:0] p);
    expand565_b = {p[4:0], 3'b000};
  endfunction

  // texel byte address from perspective-corrected coords (valid in S_TRQ).
  // Golden: TEX_BASE + (v8 << 8) + u8, u8/v8 = (u_final >> 22) & 0xFF.
  // (BUS address: VRAM_BASE + offset, decoded by ember_vram.addr2word.)
  wire [95:0] u8w = (u_fin >>> 22);
  wire [95:0] v8w = (v_fin >>> 22);
  wire [31:0] tex_addr = VRAM_BASE + TEX_BASE + {16'b0, v8w[7:0], 8'h00}
                                     + {24'b0, u8w[7:0]};
  // texel byte from fpa2_rdata (word containing byte offset tex_addr[1:0])
  wire [31:0] texel_shift = fpa2_rdata >> {tex_addr[1:0], 3'b000};
  wire [7:0]  texel_byte  = texel_shift[7:0];

  wire [31:0] pix_xy  = ({{16{1'b0}}, iy} * 32'd320) + {{16{1'b0}}, ix};
  wire [31:0] pix_off = pix_xy * 2;
  wire        odd_x   = pix_off[1];              // pixel in HIGH halfword
  // word containing the pixel (byte-packed FB: word = 4-aligned part of off)
  wire [31:0] pix_word_off = {pix_off[31:2], 2'b00};

  // Plane evals became the module-scope PEVAL FABRIC below (same operator
  // order: (A*px + B*py) -> >>>22 -> +C; instances give synthesis roots).

  // perspective divide with explicit widths (s192 covers s96<<<22 / s96)
  // Perspective divide became the module-scope PDIV FABRIC below
  // (_rtr_sdiv96: sign-extend, <<<22, signed '/' truncation, /0 -> 0).

  function automatic logic [7:0] clamp8(input logic signed [95:0] v);
    logic signed [95:0] t;
    begin
      t = v >>> 22;
      if      (t < 0)    clamp8 = 8'h00;
      else if (t > 255)  clamp8 = 8'hFF;
      else               clamp8 = t[7:0];
    end
  endfunction

  function automatic logic [7:0] avg2(input logic [7:0] a, b);
    logic [8:0] s;
    begin
      s = {1'b0, a} + {1'b0, b};
      avg2 = s[8:1];
    end
  endfunction

  // ==================================================================
  // EDGE FABRIC: 6x 33x64 -> s96 multipliers (_rtr_smul96) - hierarchical
  // synthesis roots for the GDS flow (identical truncation semantics)
  // ==================================================================
  // Edge operands: identical sign-extends/subtracts as the original inline
  // expressions (delta s33 -> s96, vertex s32 -> s96, cx/cy s64 -> s96).
  logic signed [95:0] p01a, p01b, p12a, p12b, p20a, p20b;
  logic signed [95:0] e01x, e01y, e12x, e12y, e20x, e20y;
  logic signed [95:0] cxx0, cxx1, cxx2, cyy0, cyy1, cyy2;
  assign e01x = {{63{dx01[32]}}, dx01};
  assign e01y = {{63{dy01[32]}}, dy01};
  assign e12x = {{63{dx12[32]}}, dx12};
  assign e12y = {{63{dy12[32]}}, dy12};
  assign e20x = {{63{dx20[32]}}, dx20};
  assign e20y = {{63{dy20[32]}}, dy20};
  assign cyy0 = {{32{cy[63]}}, cy} - {{64{y0[31]}}, y0};
  assign cxx0 = {{32{cx[63]}}, cx} - {{64{x0[31]}}, x0};
  assign cyy1 = {{32{cy[63]}}, cy} - {{64{y1[31]}}, y1};
  assign cxx1 = {{32{cx[63]}}, cx} - {{64{x1[31]}}, x1};
  assign cyy2 = {{32{cy[63]}}, cy} - {{64{y2[31]}}, y2};
  assign cxx2 = {{32{cx[63]}}, cx} - {{64{x2[31]}}, x2};
  _rtr_smul96 u_m01 (.a(e01x), .b(cyy0), .q(p01a));
  _rtr_smul96 u_m02 (.a(e01y), .b(cxx0), .q(p01b));
  _rtr_smul96 u_m03 (.a(e12x), .b(cyy1), .q(p12a));
  _rtr_smul96 u_m04 (.a(e12y), .b(cxx1), .q(p12b));
  _rtr_smul96 u_m05 (.a(e20x), .b(cyy2), .q(p20a));
  _rtr_smul96 u_m06 (.a(e20y), .b(cxx2), .q(p20b));

  // ==================================================================
  // PEVAL FABRIC: 7 attributes x (A*cx + B*cy), then (s >>> 22) + C.
  logic signed [95:0] iw_p, iw_q, r_p, r_q, g_p, g_q, b_p, b_q;
  logic signed [95:0] z_p, z_q, u_p, u_q, v_p, v_q;
  logic signed [95:0] iw_s, r_s, g_s, b_s, z_s, u_s, v_s;
  _rtr_smul96 u_pe_iw_a (.a(iwA), .b(cx), .q(iw_p));
  _rtr_smul96 u_pe_iw_b (.a(iwB), .b(cy), .q(iw_q));
  _rtr_smul96 u_pe_r_a  (.a(rA),  .b(cx), .q(r_p));
  _rtr_smul96 u_pe_r_b  (.a(rB),  .b(cy), .q(r_q));
  _rtr_smul96 u_pe_g_a  (.a(gA),  .b(cx), .q(g_p));
  _rtr_smul96 u_pe_g_b  (.a(gB),  .b(cy), .q(g_q));
  _rtr_smul96 u_pe_b_a  (.a(bA),  .b(cx), .q(b_p));
  _rtr_smul96 u_pe_b_b  (.a(bB),  .b(cy), .q(b_q));
  _rtr_smul96 u_pe_z_a  (.a(zA),  .b(cx), .q(z_p));
  _rtr_smul96 u_pe_z_b  (.a(zB),  .b(cy), .q(z_q));
  _rtr_smul96 u_pe_u_a  (.a(uA),  .b(cx), .q(u_p));
  _rtr_smul96 u_pe_u_b  (.a(uB),  .b(cy), .q(u_q));
  _rtr_smul96 u_pe_v_a  (.a(vA),  .b(cx), .q(v_p));
  _rtr_smul96 u_pe_v_b  (.a(vB),  .b(cy), .q(v_q));
  assign iw_s = iw_p + iw_q;
  assign r_s  = r_p  + r_q;
  assign g_s  = g_p  + g_q;
  assign b_s  = b_p  + b_q;
  assign z_s  = z_p  + z_q;
  assign u_s  = u_p  + u_q;
  assign v_s  = v_p  + v_q;
  // >>> MUST stay ISOLATED in its own assignment (self-determined signed
  // context -> arithmetic shift). A concat sibling in the same expression
  // forces unsigned context and silently degrades >>> to a logical shift
  // (this is the original peval() comment's trap -- tb_rtr caught it).
  wire signed [95:0] iw_sh = iw_s >>> 22;
  wire signed [95:0] r_sh  = r_s  >>> 22;
  wire signed [95:0] g_sh  = g_s  >>> 22;
  wire signed [95:0] b_sh  = b_s  >>> 22;
  wire signed [95:0] z_sh  = z_s  >>> 22;
  wire signed [95:0] u_sh  = u_s  >>> 22;
  wire signed [95:0] v_sh  = v_s  >>> 22;
  wire signed [95:0] iw_ev = iw_sh + {{32{iwC[63]}}, iwC};
  wire signed [95:0] r_ev  = r_sh  + {{32{rC[63]}},  rC};
  wire signed [95:0] g_ev  = g_sh  + {{32{gC[63]}},  gC};
  wire signed [95:0] b_ev  = b_sh  + {{32{bC[63]}},  bC};
  wire signed [95:0] z_ev  = z_sh  + {{32{zC[63]}},  zC};
  wire signed [95:0] u_ev  = u_sh  + {{32{uC[63]}},  uC};
  wire signed [95:0] v_ev  = v_sh  + {{32{vC[63]}},  vC};

  // ==================================================================
  // PDIV FABRIC: 2x combinational 96/96 (_rtr_sdiv96) - registered inputs
  // (u_raw/v_raw/inv_w_v valid since S_EVAL, consumed in S_ATR: same
  // timing as the original function calls).
  // ==================================================================
  logic signed [95:0] u_fin_w, v_fin_w;
  _rtr_sdiv96 u_pdiv_u (.num(u_raw), .den(inv_w_v), .q(u_fin_w));
  _rtr_sdiv96 u_pdiv_v (.num(v_raw), .den(inv_w_v), .q(v_fin_w));

  // ---- combinational final color: source mux -> dither -> pack ----
  wire [7:0] src_r = t_blend ? mr : cr;
  wire [7:0] src_g = t_blend ? mg : cg;
  wire [7:0] src_b = t_blend ? mb : cb;

  wire        dith_up = (ix[0] ^ iy[0]) == 1'b1;
  wire [7:0] dmr = !t_dither ? src_r :
                    dith_up   ? ((src_r == 8'hFF) ? 8'hFF : src_r + 8'd1) :
                                ((src_r == 8'h00) ? 8'h00 : src_r - 8'd1);
  wire [7:0] dmg = !t_dither ? src_g :
                    dith_up   ? ((src_g == 8'hFF) ? 8'hFF : src_g + 8'd1) :
                                ((src_g == 8'h00) ? 8'h00 : src_g - 8'd1);
  wire [7:0] dmb = !t_dither ? src_b :
                    dith_up   ? ((src_b == 8'hFF) ? 8'hFF : src_b + 8'd1) :
                                ((src_b == 8'h00) ? 8'h00 : src_b - 8'd1);

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      st <= S_IDLE;
      done <= 1'b0;
      ix <= '0; iy <= '0; cx <= '0; cy <= '0;
      fpa_req <= 1'b0; fpa_we <= 1'b0; fpa_addr <= '0;
      fpa_wdata <= '0; fpa_be <= '0;
      fpa2_req <= 1'b0; fpa2_addr <= '0;
      e01 <= '0; e12 <= '0; e20 <= '0;
      r_v <= '0; g_v <= '0; b_v <= '0; z_v <= '0;
      u_raw <= '0; v_raw <= '0; inv_w_v <= '0;
      u_fin <= '0; v_fin <= '0;
      z_pass <= 1'b0;
      cr <= '0; cg <= '0; cb <= '0; mr <= '0; mg <= '0; mb <= '0;
      zaddr <= '0; faddr <= '0;
    end else begin
      done    <= 1'b0;
      fpa_req <= 1'b0;
      fpa_we  <= 1'b0;
      fpa2_req <= 1'b0;

      case (st)
        // ------------------------------------------------------------
        S_IDLE: begin
          if (start) begin
            ix <= x_lo_i;
            iy <= y_lo_i;
            cx <= ({{48{x_lo_i[15]}}, x_lo_i} <<< 22) + HALF_Q;
            cy <= ({{48{y_lo_i[15]}}, y_lo_i} <<< 22) + HALF_Q;
            st <= S_PIX;
          end
        end

        // ------------------------------------------------------------
        // Edges at current center (direct computation). All leaf operands
        // explicitly s96 (cx/cy s64 + vertex s32 sign-extended, deltas s33
        // sign-extended) so the s96 context needs no implicit widening.
        // Z-read fired here (if ztest): fpa_req high during S_EVAL, VRAM
        // captures at end of S_EVAL, data consumed in S_ZRD.
        // ----------------------------------------------------------
        S_PIX: begin
          e01 <= p01a - p01b;
          e12 <= p12a - p12b;
          e20 <= p20a - p20b;
          if (t_ztest) begin
            fpa_req  <= 1'b1;
            fpa_addr <= ZB + pix_word_off;    // data consumed in S_ZRD
          end
          st <= S_EVAL;
        end

        // ------------------------------------------------------------
        // Inside test; register attributes (valid in S_ZRD/S_ATR)
        // ------------------------------------------------------------
        S_EVAL: begin
          if ((e01 > 0) && (e12 > 0) && (e20 > 0)) begin
            zaddr   <= ZB + pix_word_off;
            faddr   <= FB0 + pix_word_off;
            inv_w_v <= iw_ev;
            r_v     <= r_ev;
            g_v     <= g_ev;
            b_v     <= b_ev;
            z_v     <= z_ev;
            u_raw   <= u_ev;
            v_raw   <= v_ev;
            if (t_ztest) begin
              st <= S_ZRD;              // z data inbound (fired in S_PIX)
            end else begin
              st <= S_ATR;
            end
          end else begin
            st <= S_NEXT;
          end
        end

        // ------------------------------------------------------------
        // Z data arrived; z_v/u_raw/... valid (registered in S_EVAL)
        // ------------------------------------------------------------
        S_ZRD: begin
          // $signed: unsigned concat sibling would force an unsigned compare
          z_pass <= (z_v < $signed({{80{1'b0}}, half_get(fpa_rdata, odd_x)}));
          if (!(z_v < $signed({{80{1'b0}}, half_get(fpa_rdata, odd_x)}))) begin
            st <= S_NEXT;                 // z fail: skip pixel
          end else begin
            st <= S_ATR;
          end
        end

        // ------------------------------------------------------------
        // Perspective divide; tex request goes out NEXT state (S_TRQ)
        // so tex_addr can use freshly-registered u_fin/v_fin.
        // ------------------------------------------------------------
        S_ATR: begin
          u_fin <= u_fin_w;
          v_fin <= v_fin_w;
          if (t_tex) begin
            st <= S_TRQ;
          end else begin
            cr <= clamp8(r_v);
            cg <= clamp8(g_v);
            cb <= clamp8(b_v);
            st <= t_blend ? S_FRQ : S_WR;
          end
        end

        // ------------------------------------------------------------
        // Texel request using this pixel's corrected coords
        // ------------------------------------------------------------
        S_TRQ: begin
          fpa2_req  <= 1'b1;
          fpa2_addr <= tex_addr;
          st        <= S_TRD;
        end

        // ------------------------------------------------------------
        // fpa2_req high this cycle; VRAM captures at end of cycle
        // ------------------------------------------------------------
        S_TRD: begin
          st <= S_TRC;
        end

        // ------------------------------------------------------------
        // Texel byte arrived (low lane)
        // ------------------------------------------------------------
        S_TRC: begin
          if (t_texpal) begin
            // palette mode: latch the byte, then read CLUT[byte] (fpa2 is
            // idle again next cycle; the texel word is already consumed)
            fpa2_req  <= 1'b1;
            fpa2_addr <= PAL + {22'b0, texel_byte, 2'b00};
            st        <= S_PRD;
          end else begin
            // gray expand of the texel byte (u8 picks the byte lane)
            cr <= texel_byte;
            cg <= texel_byte;
            cb <= texel_byte;
            st <= t_blend ? S_FRQ : S_WR;
          end
        end

        // ------------------------------------------------------------
        // CLUT read in flight (fpa2_req fired in S_TRC)
        // ------------------------------------------------------------
        S_PRD: begin
          st <= S_PRC;
        end

        // ------------------------------------------------------------
        // Palette word arrived: {8'h0, b, g, r}
        // ------------------------------------------------------------
        S_PRC: begin
          cr <= fpa2_rdata[7:0];
          cg <= fpa2_rdata[15:8];
          cb <= fpa2_rdata[23:16];
          st <= t_blend ? S_FRQ : S_WR;
        end

        // ------------------------------------------------------------
        // FB read request for blending
        // ------------------------------------------------------------
        S_FRQ: begin
          fpa_req  <= 1'b1;
          fpa_addr <= faddr;               // data consumed in S_FRC
          st       <= S_FRD;
        end

        // ------------------------------------------------------------
        // fpa_req high this cycle; VRAM captures at end of cycle
        // ------------------------------------------------------------
        S_FRD: begin
          st <= S_FRC;
        end

        // ------------------------------------------------------------
        S_FRC: begin
          mr <= avg2(cr, expand565_r(half_get(fpa_rdata, odd_x)));
          mg <= avg2(cg, expand565_g(half_get(fpa_rdata, odd_x)));
          mb <= avg2(cb, expand565_b(half_get(fpa_rdata, odd_x)));
          st <= S_WR;
        end

        // ------------------------------------------------------------
        // FB write: dithered/packed color, pixel in its halfword lane
        // ------------------------------------------------------------
        S_WR: begin
          fpa_we    <= 1'b1;
          fpa_addr  <= faddr;
          // write ONLY this pixel's halfword (neighbor must survive)
          fpa_be    <= odd_x ? 4'b1100 : 4'b0011;
          if (t_rgbmap) begin
            fpa_wdata <= {dmb[7:3], dmg[7:2], dmr[7:3], dmb[7:3], dmg[7:2], dmr[7:3]};
          end else begin
            fpa_wdata <= {dmr[7:3], dmg[7:2], dmb[7:3], dmr[7:3], dmg[7:2], dmb[7:3]};
          end
          st <= (t_ztest && z_pass) ? S_WRZ : S_NEXT;
        end

        // ------------------------------------------------------------
        // Z write (z pixel in its halfword lane, same read-modify rule)
        // ------------------------------------------------------------
        S_WRZ: begin
          fpa_we    <= 1'b1;
          fpa_addr  <= zaddr;
          fpa_be    <= odd_x ? 4'b1100 : 4'b0011;
          fpa_wdata <= {z_v[15:0], z_v[15:0]};
          st        <= S_NEXT;
        end

        // ------------------------------------------------------------
        // Advance to next pixel
        // ------------------------------------------------------------
        S_NEXT: begin
          if (ix == x_hi_i) begin
            if (iy == y_hi_i) begin
              done <= 1'b1;
              st   <= S_IDLE;
            end else begin
              ix <= x_lo_i;
              iy <= iy + 16'd1;
              cx <= ({{48{x_lo_i[15]}}, x_lo_i} <<< 22) + HALF_Q;
              cy <= cy + HALF_Q + HALF_Q;           // +1.0 (Q10.22)
              st <= S_PIX;
            end
          end else begin
            ix <= ix + 16'd1;
            cx <= cx + HALF_Q + HALF_Q;             // +1.0 (Q10.22)
            st <= S_PIX;
          end
        end

        default: st <= S_IDLE;
      endcase
    end
  end

  wire _unused = |t_texpage;

endmodule : ember_rtr_scan
