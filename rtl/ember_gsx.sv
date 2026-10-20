// ember_gsx.sv — Phase-4b Geometry & Setup engine (GSX).
//
// Transforms one 3-vertex triangle through a 4x4 fp32 MVP matrix (via the
// embedded ember_fpu4 soft-float lanes), culls w<=0 (near plane), converts
// to the RTR setup format (Q10.22 screen coords, u16 raw z) and appends a
// 19-word command-queue triangle to VRAM at RTR_CMDQ_BASE +
// tri_count*76 bytes. Software folds projection + viewport INTO the matrix
// (GSX performs only the fp32 perspective divide), so no viewport unit.
//
// Vertices are homogeneous (x,y,z,1) — the implicit 1.0 supplies the w term.
// ALL 16 matrix words are used as loaded: row 3 of M produces the clip-space
// w (software puts its perspective row, e.g. (0,0,-1,near), there). Identity
// matrix => w=1.0 => straight passthrough.
//
// CSR interface (decoded by ember_cp, same pattern as the blit CSR):
//   csr_addr 00=MATA: 4x4 matrix word, auto-inc write pointer (16 words),
//                     row-major y' = M * v, v = (x,y,z,1)
//   csr_addr 01=VTX:  15 words auto-inc, per vertex x,y,z,u,v (f32;
//                     u/v = texture coords, Q10.22-divided by w on emit)
//   csr_addr 10=COL:  3 words auto-inc: {b,g,r,x} byte-packed per vertex
//   csr_addr 11=CFG:  two write forms:
//             bit31=1: [7:0] = gsx_tri_count write (cmdq write pointer,
//                      unit = triangle slots)
//             bit31=0: [24]= ztest_en  [26]= blend_en  [27]= tex_en
//                      [23:16]= texpage (w0 [15:8])
//                      [29]= overw (overwrite mode: rewrite the slot at the
//                      current tri_count each kick and do NOT advance the
//                      pointer or append the 0-terminator — animation loops)
//   kick (CP_GSX_GO): transform + emit one triangle
//
// Output command word layout per ember_pkg (19 words):
//   w0     = tri_valid | blend<<1 | ztest<<2 | tex_en<<3 | texpage<<8
//   w1..6  = vx0..vy2 (s32 Q10.22)   w7..9 = z0..z2 (u16 raw depth)
//   w10..12= {b,g,r,x} per vertex    w13..18 = u0,v0..u2,v2 (s32 Q10.22,
//            PRE-DIVIDED by w — the RTR interpolates u/w and divides by
//            the interpolated 1/w for perspective-correct texturing;
//            zeros when the texture path is off)
//
// Timing: 8 fpu ops/vertex (4 MUL + 4 ADD, 8 edges each) + 4 parallel DIVs
// -> ~74 cycles/vertex, ~240 cycles/triangle including emit.
// Conversions (combinational, mirrored bit-exactly in tools/golden/cube.py):
//   fp_to_q22: q22 = 1.m * 2^(e-128)  (value*2^22), trunc, saturate e>=136
//   fp_to_z16: z16 = (1.m * 65535) >> (150-e), saturate e>=127, neg->0

`include "ember_pkg.sv"
import ember_pkg::*;

module ember_gsx
(
  input  logic        clk,
  input  logic        rst_n,

  // CSR from CP (decoded like the blit CSR passthrough)
  input  logic        csr_we,
  input  logic [1:0]  csr_addr,
  input  logic [31:0] csr_wdata,
  input  logic        kick,

  // Dedicated VRAM port (write-only use; req/rdata unused)
  output logic        gxa_we,
  output logic [31:0] gxa_addr,
  output logic [31:0] gxa_wdata,
  output logic [3:0]  gxa_be,
  output logic        gxa_req,
  input  logic [31:0] gxa_rdata,

  output logic        busy
);

  // ==================================================================
  // CSR state
  // ==================================================================
  logic [31:0] mata [16];          // row-major 4x4, word m[4r+c]
  logic [31:0] vtx  [15];          // per vertex: x,y,z,u,v (f32)
  logic [31:0] col  [3];           // {b,g,r,x} byte-packed

  logic [3:0]  mata_ptr;           // 0..15, wraps
  logic [3:0]  vtx_ptr;            // 0..8, wraps
  logic [1:0]  col_ptr;            // 0..2, wraps

  logic [7:0]  tri_count;          // cmdq write pointer (triangle slots)
  logic        cfg_overw;          // overwrite mode (no advance/terminator)
  logic        cfg_blend, cfg_ztest, cfg_tex;
  logic [7:0]  cfg_page;           // texture page (w0 [15:8])

  // CSR write decode
  wire cfg_we      = csr_we && (csr_addr == 2'd3);
  wire cfg_cnt_we  = cfg_we && csr_wdata[31];
  wire cfg_mode_we = cfg_we && !csr_wdata[31];

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      mata_ptr <= 4'd0;
      vtx_ptr  <= 4'd0;
      col_ptr  <= 2'd0;
    end else if (csr_we) begin
      case (csr_addr)
        2'd0: mata_ptr <= mata_ptr + 4'd1;            // wraps 15 -> 0
        2'd1: vtx_ptr  <= (vtx_ptr == 4'd14) ? 4'd0 : vtx_ptr + 4'd1;
        2'd2: col_ptr  <= (col_ptr == 2'd2) ? 2'd0 : col_ptr + 2'd1;
        default: ;                                    // CFG: no pointers
      endcase
    end
  end

  always_ff @(posedge clk) begin
    if (csr_we) begin
      case (csr_addr)
        2'd0: mata[mata_ptr] <= csr_wdata;
        2'd1: vtx[vtx_ptr]   <= csr_wdata;
        2'd2: col[col_ptr]   <= csr_wdata;
        default: ;
      endcase
    end
  end

  // tri_count update: CFG sets it; each non-overwrite emit advances it.
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      tri_count <= 8'd0;
      cfg_overw <= 1'b0;
      cfg_blend <= 1'b0;
      cfg_ztest <= 1'b0;
      cfg_tex   <= 1'b0;
      cfg_page  <= 8'd0;
    end else begin
      if (cfg_cnt_we) begin
        tri_count <= csr_wdata[7:0];
      end else if (busy_r && (st == S_EMIT_W0) && !cfg_overw) begin
        tri_count <= tri_count + 8'd1;
      end
      if (cfg_mode_we) begin
        cfg_overw <= csr_wdata[29];
        cfg_blend <= csr_wdata[26];
        cfg_ztest <= csr_wdata[24];
        cfg_tex   <= csr_wdata[27];
        cfg_page  <= csr_wdata[23:16];
      end
    end
  end

  // Matrix reset value: identity (software rewrites all 16 words anyway)
  initial begin
    for (int r = 0; r < 4; r++)
      for (int c = 0; c < 4; c++)
        mata[4*r + c] = (r == c) ? 32'h3F800000 : 32'h0;
  end

  // cmdq byte offset of the current triangle slot
  wire [31:0] tri_off = {24'd0, tri_count} * (RTR_CMD_WORDS * 4);

  // ==================================================================
  // fpu4 instance (the GSX's private fp32 engine)
  // ==================================================================
  logic [3:0]  f_lane_en;
  logic [3:0]  f_op;
  logic [31:0] f_a0, f_b0, f_a1, f_b1, f_a2, f_b2, f_a3, f_b3;
  logic        f_go;
  logic [31:0] f_y0, f_y1, f_y2, f_y3;
  logic        f_busy, f_done;

  ember_fpu4 u_fpu4 (
    .clk(clk), .rst_n(rst_n),
    .lane_en(f_lane_en), .op(f_op),
    .a0(f_a0), .b0(f_b0), .a1(f_a1), .b1(f_b1),
    .a2(f_a2), .b2(f_b2), .a3(f_a3), .b3(f_b3),
    .go(f_go),
    .y0(f_y0), .y1(f_y1), .y2(f_y2), .y3(f_y3),
    .busy(f_busy), .done(f_done)
  );

  // ==================================================================
  // Conversion helpers (mirror EXACTLY in tools/golden/cube.py)
  // ==================================================================
  // fp32 -> Q10.22: q22 = 1.m * 2^(e-128) = value * 2^22, truncating.
  // Saturate at e >= 136 (|value|*2^22 >= 2^31). Negative: negate magnitude.
  function automatic logic [31:0] fp_to_q22(input logic [31:0] fb);
    logic [7:0]  e;
    logic [31:0] i24, sh;
    begin
      e   = fb[30:23];
      i24 = {8'd0, 1'b1, fb[22:0]};
      if (fb[30:0] == 31'h0) begin
        fp_to_q22 = 32'h0;
      end else if (e >= 8'd136) begin
        fp_to_q22 = fb[31] ? 32'h80000000 : 32'h7FFFFFFF;
      end else if (e >= 8'd128) begin
        sh = i24 << (e - 8'd128);
        fp_to_q22 = sh;
      end else begin
        sh = i24 >> (8'd128 - e);
        fp_to_q22 = sh;
      end
      if (fb[31] && |fp_to_q22) fp_to_q22 = ~fp_to_q22 + 32'd1;
    end
  endfunction

  // ndc z (0..1) -> u16 raw depth = z * 65535, saturating.
  // z16 = (1.m * 65535) >> (150 - e);  e >= 127 -> FFFF; negative -> 0.
  function automatic logic [15:0] fp_to_z16(input logic [31:0] fb);
    logic [7:0]  e;
    logic [39:0] prod;
    begin
      e = fb[30:23];
      if (fb[31] || (fb[30:0] == 31'h0)) begin
        fp_to_z16 = 16'h0;                     // negative ndc -> near plane
      end else if (e >= 8'd127) begin
        fp_to_z16 = 16'hFFFF;                  // >= 1.0: saturate far
      end else begin
        prod = {1'b1, fb[22:0]} * 16'd65535;   // 24x16 -> 40 bits
        fp_to_z16 = 16'(prod >> (8'd150 - e)); // e <= 126 -> shift >= 24
      end
    end
  endfunction

  // signed Q10.22 saturate to the safe s32 command range (tiny margin)
  function automatic logic [31:0] sat22(input logic signed [31:0] v);
    begin
      if (v > 32'sd2147483000)       sat22 = 32'sd2147483000;
      else if (v < -32'sd2147483000) sat22 = -32'sd2147483000;
      else                           sat22 = v;
    end
  endfunction

  // ==================================================================
  // Transform FSM
  // ==================================================================
  typedef enum logic [4:0] {
    S_IDLE, S_RUN, S_WAIT, S_DIVX, S_DIVW, S_CULL, S_EMIT_W0, S_EMIT, S_DONE
  } gsx_state_e;
  gsx_state_e st;

  logic        busy_r;
  assign busy = busy_r;

  logic [1:0]  vidx;        // 0..2 vertex index
  logic [1:0]  kstep;       // matrix column 0..3
  logic        phase;       // 0 = MUL pass, 1 = ADD pass
  logic [31:0] acc0, acc1, acc2, acc3;   // row dot-product accumulators
  logic [31:0] w_in;        // clip w of the current vertex (cull term)
  logic [4:0]  eidx;        // emit word index 0..18
  logic [31:0] emit_base;   // BUS byte address of the triangle slot

  logic [31:0] px [3];      // transformed screen x (Q10.22)
  logic [31:0] py [3];
  logic [15:0] pz [3];      // u16 raw depth
  logic [31:0] pc [3];      // captured color words
  logic [31:0] pu [3];      // u/w (Q10.22, pre-divided for the RTR)
  logic [31:0] pv [3];      // v/w

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      st        <= S_IDLE;
      busy_r    <= 1'b0;
      vidx      <= 2'd0;
      kstep     <= 2'd0;
      phase     <= 1'b0;
      w_in      <= 32'h3F800000;
      acc0      <= 32'h0; acc1 <= 32'h0; acc2 <= 32'h0; acc3 <= 32'h0;
      eidx      <= 5'd0;
      emit_base <= 32'h0;
      f_lane_en <= 4'h0;
      f_go      <= 1'b0;
      f_op      <= 4'h0;
      f_a0 <= 32'h0; f_b0 <= 32'h0; f_a1 <= 32'h0; f_b1 <= 32'h0;
      f_a2 <= 32'h0; f_b2 <= 32'h0; f_a3 <= 32'h0; f_b3 <= 32'h0;
      gxa_we    <= 1'b0;
      gxa_addr  <= 32'h0;
      gxa_wdata <= 32'h0;
      gxa_be    <= 4'h0;
      gxa_req   <= 1'b0;
      for (int i = 0; i < 3; i++) begin
        px[i] <= 32'h0; py[i] <= 32'h0; pz[i] <= 16'h0; pc[i] <= 32'h0;
      end
    end else begin
      f_go   <= 1'b0;             // default: no pulse this cycle
      gxa_we <= 1'b0;

      case (st)
        // ------------------------------------------------------------
        S_IDLE: begin
          busy_r <= 1'b0;
          if (kick) begin
            busy_r    <= 1'b1;
            vidx      <= 2'd0;
            kstep     <= 2'd0;
            phase     <= 1'b0;
            acc0      <= 32'h0; acc1 <= 32'h0; acc2 <= 32'h0; acc3 <= 32'h0;
            eidx      <= 5'd0;
            emit_base <= VRAM_BASE + RTR_CMDQ_BASE + tri_off;
            st        <= S_RUN;
          end
        end

        // ------------------------------------------------------------
        // RUN: issue one fpu op (MUL for phase 0, ADD for phase 1) on all
        // four lanes (one matrix row per lane).
        // ------------------------------------------------------------
        S_RUN: begin
          f_lane_en <= 4'hF;
          f_go      <= 1'b1;
          if (phase == 1'b0) begin
            f_op <= 4'd2;                        // MUL
            if (kstep == 2'd3) begin
              // homogeneous term: row_i[3] * 1.0
              f_a0 <= mata[3];  f_b0 <= 32'h3F800000;
              f_a1 <= mata[7];  f_b1 <= 32'h3F800000;
              f_a2 <= mata[11]; f_b2 <= 32'h3F800000;
              f_a3 <= mata[15]; f_b3 <= 32'h3F800000;
            end else begin
              // VTX stride is 5 words: x,y,z,u,v per vertex
              f_a0 <= mata[4*0 + kstep]; f_b0 <= vtx[5*vidx + kstep];
              f_a1 <= mata[4*1 + kstep]; f_b1 <= vtx[5*vidx + kstep];
              f_a2 <= mata[4*2 + kstep]; f_b2 <= vtx[5*vidx + kstep];
              f_a3 <= mata[4*3 + kstep]; f_b3 <= vtx[5*vidx + kstep];
            end
          end else begin
            // ADD pass: acc_i = acc_i + prod_i
            f_op <= 4'd0;                        // ADD
            f_a0 <= acc0; f_b0 <= f_y0;
            f_a1 <= acc1; f_b1 <= f_y1;
            f_a2 <= acc2; f_b2 <= f_y2;
            f_a3 <= acc3; f_b3 <= f_y3;
          end
          st <= S_WAIT;
        end

        S_WAIT: begin
          if (f_done) begin
            if (phase == 1'b0) begin
              // MUL done: products ride f_y* into the ADD operands
              // (fpu y holds until the next go) — do NOT touch acc here:
              // it still holds the running dot-product sum.
              phase <= 1'b1;
              st    <= S_RUN;
            end else begin
              // ADD done: one more term folded into the running sum
              acc0 <= f_y0; acc1 <= f_y1; acc2 <= f_y2; acc3 <= f_y3;
              if (kstep == 2'd3) begin
                st <= S_DIVX;                    // full dot products done
              end else begin
                kstep <= kstep + 2'd1;
                phase <= 1'b0;
                st    <= S_RUN;
              end
            end
          end
        end

        // ------------------------------------------------------------
        // DIVX: four parallel fp32 divides — x/w, y/w, z/w, 1/w
        // ------------------------------------------------------------
        S_DIVX: begin
          f_lane_en <= 4'hF;
          f_op      <= 4'd3;                     // DIV
          f_a0      <= acc0;  f_b0 <= acc3;      // clip x / w
          f_a1      <= acc1;  f_b1 <= acc3;      // clip y / w
          f_a2      <= acc2;  f_b2 <= acc3;      // clip z / w (ndc z)
          f_a3      <= 32'h3F800000; f_b3 <= acc3;   // 1/w (reserved)
          w_in      <= acc3;
          f_go      <= 1'b1;
          st        <= S_DIVW;
        end

        // DIVW: convert + store this vertex's results
        S_DIVW: begin
          if (f_done) begin
            px[vidx] <= sat22($signed(fp_to_q22(f_y0)));
            py[vidx] <= sat22($signed(fp_to_q22(f_y1)));
            pz[vidx] <= fp_to_z16(f_y2);
            pc[vidx] <= {1'b0, col[vidx][30:0]};   // ZERO-extend: {b,g,r,x}
                                                   // fields are u8, bit31 may be set
            // texture coords: converted RAW u,v (Q10.22). The v1 RTR's
            // inv_w plane is constant, so words 13..18 are AFFINE
            // texcoords — pre-dividing by w here would double-divide.
            // (True perspective-correct texturing = v2 RTR change.)
            pu[vidx] <= fp_to_q22(vtx[5*vidx + 3]);
            pv[vidx] <= fp_to_q22(vtx[5*vidx + 4]);
            st       <= S_CULL;
          end
        end

        // CULL: w <= 0 (negative or zero) drops the triangle
        S_CULL: begin
          if (w_in[31] || (w_in[30:0] == 31'h0)) begin
            st <= S_DONE;                      // culled
          end else if (vidx == 2'd2) begin
            st <= S_EMIT_W0;                   // all 3 vertices done
          end else begin
            vidx  <= vidx + 2'd1;
            kstep <= 2'd0;
            phase <= 1'b0;
            acc0  <= 32'h0; acc1 <= 32'h0; acc2 <= 32'h0; acc3 <= 32'h0;
            st    <= S_RUN;
          end
        end

        // ------------------------------------------------------------
        // EMIT: 19 words into VRAM via gxa (1 cycle/word, no handshake)
        // ------------------------------------------------------------
        S_EMIT_W0: begin
          gxa_we    <= 1'b1;
          gxa_be    <= 4'hF;
          gxa_addr  <= emit_base;
          // w0 (LSB->): valid | blend<<1 | ztest<<2 | tex<<3 | 0(dither)<<4
          //             | page<<8. Phase-7c fix: cfg_tex sat at bit4 (the
          //             RTR's DITHER bit) with a literal 0 on tex bit3 —
          //             textured tris rendered BLACK; latent because the
          //             tb_tex golden frame never textured its own side.
          gxa_wdata <= {16'h0, 3'h0, cfg_page, 1'b0, cfg_tex, cfg_ztest,
                        cfg_blend, 1'b1};   // w0: 16+3+8+1+1+1+1+1 = 32
          eidx      <= 5'd1;
          st        <= S_EMIT;
        end

        S_EMIT: begin
          gxa_we   <= 1'b1;
          gxa_be   <= 4'hF;
          gxa_addr <= emit_base + {25'h0, eidx, 2'b00};
          if (eidx <= 5'd6) begin
            // coords: vx0,vy0,vx1,vy1,vx2,vy2
            case (eidx)
              5'd1:    gxa_wdata <= px[0];
              5'd2:    gxa_wdata <= py[0];
              5'd3:    gxa_wdata <= px[1];
              5'd4:    gxa_wdata <= py[1];
              5'd5:    gxa_wdata <= px[2];
              default: gxa_wdata <= py[2];
            endcase
          end else if (eidx <= 5'd9) begin
            // z0..z2 as u16 in the low half
            case (eidx)
              5'd7:    gxa_wdata <= {16'h0, pz[0]};
              5'd8:    gxa_wdata <= {16'h0, pz[1]};
              default: gxa_wdata <= {16'h0, pz[2]};
            endcase
          end else if (eidx <= 5'd12) begin
            case (eidx)
              5'd10:   gxa_wdata <= pc[0];
              5'd11:   gxa_wdata <= pc[1];
              default: gxa_wdata <= pc[2];
            endcase
          end else if (cfg_tex) begin
            // u0,v0..u2,v2 (pre-divided Q10.22) when texture is on
            case (eidx)
              5'd13:   gxa_wdata <= pu[0];
              5'd14:   gxa_wdata <= pv[0];
              5'd15:   gxa_wdata <= pu[1];
              5'd16:   gxa_wdata <= pv[1];
              5'd17:   gxa_wdata <= pu[2];
              default: gxa_wdata <= pv[2];
            endcase
          end else begin
            gxa_wdata <= 32'h0;                // u/v words: no texture
          end

          if (eidx == 5'd18) begin
            eidx <= 5'd0;
            st   <= S_DONE;
          end else begin
            eidx <= eidx + 5'd1;
          end
        end

        // ------------------------------------------------------------
        S_DONE: begin
          if (cfg_overw) begin
            // overwrite mode: no terminator, pointer stays put
            busy_r <= 1'b0;
            st     <= S_IDLE;
          end else begin
            // append mode: write the 0 terminator after the triangle
            gxa_we    <= 1'b1;
            gxa_be    <= 4'hF;
            gxa_addr  <= emit_base + (RTR_CMD_WORDS * 4);
            gxa_wdata <= 32'h0;
            busy_r    <= 1'b0;
            st        <= S_IDLE;
          end
        end

        default: begin
          st     <= S_IDLE;
          busy_r <= 1'b0;
        end
      endcase
    end
  end

  // gxa_rdata/f_busy intentionally unused (write-only port use; latency is
  // fixed so busy is never polled)
  wire _unused = ^gxa_rdata | f_busy;

endmodule : ember_gsx
