// ember_blit.sv — Phase-3 blitter: rect copy + key transparency + 1x/2x.
//
// Contract (== tools/golden/blit.py, all integer math):
//   * Source: compact W x H bitmap at src_off (VRAM byte offset), stride W,
//     byte-packed RGB565: pixel (sx,sy) at bytes src_off + 2*(W*sy+sx).
//   * Dest:   FB-strided (320 px), corner at dst_off (pixel-aligned byte
//     offset; dstX0/dstY0 are baked into it): source pixel (sx,sy) lands at
//     dst_off + 2*((by+ry)*320 + (bx+rx)), with
//       1x : bx = sx,       by = sy,      (rx,ry) = (0,0)
//       2x : bx = sx*2,     by = sy*2,    rx,ry in {0,1}
//   * key_en: source pixel == key_color -> pixel skipped (no writes).
//   * Pixel-port protocol: issue state registers the request (req HIGH in
//     the NEXT cycle, VRAM samples at its end), data consumed in the state
//     after that — the same issue/wait/consume pattern as the RTR scan FSM.
//   * W/H are 1..256 (stored as u8, 0 means... nothing: SW passes w-1/h-1?
//     NO — SW passes W and H directly; 0 treated as 1 by clamping in SW).
//     CSR words (VRAM byte offsets/values):
//       0: {en, scale2, key_en, 13'b0, key_color[15:0]}
//       1: dst_off (byte offset of dest corner INSIDE FB0)
//       2: src_off (byte offset of the compact source bitmap)
//       3: {8'b0, h[7:0], 8'b0, w[7:0]}
//   * kick pulse starts one blit; busy until the last write commits.

`include "ember_pkg.sv"
import ember_pkg::*;

module ember_blit
(
  input  logic        clk,
  input  logic        rst_n,

  // CSR write strobes (from CP decode, 1-cycle pulses)
  input  logic        csr_we,
  input  logic [1:0]  csr_addr,
  input  logic [31:0] csr_wdata,
  input  logic        kick,           // 1-cycle pulse

  // fpa pixel port (bus addresses)
  output logic        fpa_we,
  output logic [31:0] fpa_addr,
  output logic [31:0] fpa_wdata,
  output logic [3:0]  fpa_be,
  output logic        fpa_req,
  input  logic [31:0] fpa_rdata,

  output logic        busy,
  output logic        done            // 1-cycle pulse at completion
);

  localparam logic [31:0] FB_BUS = VRAM_BASE + FB0_BASE;

  // ------------------------------------------------------------------
  // CSRs
  // ------------------------------------------------------------------
  logic        scale2_q, key_en_q;
  logic [15:0] key_color_q;
  logic [31:0] dst_off_q, src_off_q;
  logic [7:0]  w_q, h_q;

  logic        done_q;

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      scale2_q <= 1'b0; key_en_q <= 1'b0;
      key_color_q <= 16'h0; dst_off_q <= '0; src_off_q <= '0;
      w_q <= 8'd0; h_q <= 8'd0;
      done_q <= 1'b0;
    end else begin
      done_q <= 1'b0;
      if (csr_we) begin
        case (csr_addr)
          2'd0: begin
            scale2_q    <= csr_wdata[30];
            key_en_q    <= csr_wdata[29];
            key_color_q <= csr_wdata[15:0];
          end
          2'd1: dst_off_q <= csr_wdata;
          2'd2: src_off_q <= csr_wdata;
          2'd3: begin
            w_q <= csr_wdata[7:0];
            h_q <= csr_wdata[23:16];
          end
        endcase
      end
    end
  end

  // ------------------------------------------------------------------
  // FSM
  // ------------------------------------------------------------------
  typedef enum logic [3:0] { B_IDLE, B_REQ, B_RD, B_USE, B_WR2, B_WR3,
                             B_WR4, B_NEXT, B_DONE } bstate_e;
  bstate_e st;

  // key-color test on the CURRENTLY-ARRIVING read data (combinational)
  wire [15:0] rdata_lane = lane_get(fpa_rdata, saddr_q[1]);
  wire        skip_c     = key_en_q && (rdata_lane == key_color_q);

  logic [7:0]  sx, sy;        // source pixel coords
  logic [16:0] bx, by;        // dest block origin (pixels)
  logic [31:0] saddr_q;       // source byte addr of the pixel being read
  logic [15:0] pix;
  logic        skip;

  // dest byte address of block origin (bx,by): 2*(by*320 + bx)
  // 2x block = 4 writes: (by,bx) (by,bx+1) (by+1,bx) (by+1,bx+1)
  wire [31:0] daddr0 = FB_BUS + dst_off_q
                     + 32'(by) * 32'd640
                     + 32'({15'b0, bx[8:0]}) * 32'd2;
  wire [31:0] daddr1 = daddr0 + 32'd2;      // +1 column
  wire [31:0] daddr2 = daddr0 + 32'd640;    // +1 row, same column
  wire [31:0] daddr3 = daddr0 + 32'd642;    // +1 row, +1 column

  assign busy = (st != B_IDLE);

  // halfword-lane extraction: byte offset bit[1] selects the halfword
  function automatic logic [15:0] lane_get(input logic [31:0] w,
                                           input logic hi);
    lane_get = hi ? w[31:16] : w[15:0];
  endfunction

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      st <= B_IDLE;
      sx <= '0; sy <= '0; bx <= '0; by <= '0;
      saddr_q <= '0; pix <= '0; skip <= 1'b0;
      fpa_req <= 1'b0; fpa_addr <= '0;
      fpa_we <= 1'b0; fpa_wdata <= '0; fpa_be <= '0;
    end else begin
      fpa_req <= 1'b0;
      fpa_we  <= 1'b0;

      case (st)
        B_IDLE: begin
          if (kick) begin
            sx <= '0; sy <= '0; bx <= '0; by <= '0;
            skip <= 1'b0;
            st   <= B_REQ;
          end
        end

        // issue source read for (sx, sy)
        B_REQ: begin
          saddr_q  <= VRAM_BASE + src_off_q
                    + 32'(sy) * 32'({24'b0, w_q}) * 32'd2
                    + 32'({24'b0, sx}) * 32'd2;
          fpa_req  <= 1'b1;
          fpa_addr <= (VRAM_BASE + src_off_q
                       + 32'(sy) * 32'({24'b0, w_q}) * 32'd2
                       + 32'({24'b0, sx}) * 32'd2) & 32'hFFFF_FFFC;
          st       <= B_RD;
        end

        // fpa_req is HIGH this cycle; VRAM samples at the end of it
        B_RD: begin
          st <= B_USE;
        end

        // read data valid NOW: capture, register first write
        // (skip test is combinational on the arriving data)
        B_USE: begin
          pix       <= rdata_lane;
          skip      <= skip_c;
          fpa_we    <= !skip_c;
          fpa_addr  <= daddr0 & 32'hFFFF_FFFC;
          fpa_be    <= daddr0[1] ? 4'b1100 : 4'b0011;
          fpa_wdata <= {2{rdata_lane}};
          st        <= scale2_q ? B_WR2 : B_NEXT;
        end

        // 2x: second write (same row, next column; write#1 commits now)
        B_WR2: begin
          if (!skip) begin
            fpa_we    <= 1'b1;
            fpa_addr  <= daddr1 & 32'hFFFF_FFFC;
            fpa_be    <= daddr1[1] ? 4'b1100 : 4'b0011;
            fpa_wdata <= {2{pix}};
          end
          st <= B_WR3;
        end

        // 2x: third write (next row, first column)
        B_WR3: begin
          if (!skip) begin
            fpa_we    <= 1'b1;
            fpa_addr  <= daddr2 & 32'hFFFF_FFFC;
            fpa_be    <= daddr2[1] ? 4'b1100 : 4'b0011;
            fpa_wdata <= {2{pix}};
          end
          st <= B_WR4;
        end

        // 2x: fourth write (next row, second column)
        B_WR4: begin
          if (!skip) begin
            fpa_we    <= 1'b1;
            fpa_addr  <= daddr3 & 32'hFFFF_FFFC;
            fpa_be    <= daddr3[1] ? 4'b1100 : 4'b0011;
            fpa_wdata <= {2{pix}};
          end
          st <= B_NEXT;
        end

        // advance source pixel / dest block origin
        B_NEXT: begin
          if (sx == w_q - 8'd1) begin
            sx <= '0;
            if (sy == h_q - 8'd1) begin
              done_q <= 1'b1;
              st     <= B_DONE;
            end else begin
              sy <= sy + 8'd1;
              by <= scale2_q ? by + 17'd2 : by + 17'd1;
              bx <= '0;
              st <= B_REQ;
            end
          end else begin
            sx <= sx + 8'd1;
            bx <= scale2_q ? bx + 17'd2 : bx + 17'd1;
            st <= B_REQ;
          end
        end

        B_DONE: begin
          st <= B_IDLE;
        end

        default: st <= B_IDLE;
      endcase
    end
  end

  assign done = done_q;

endmodule : ember_blit
