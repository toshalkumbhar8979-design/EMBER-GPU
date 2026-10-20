// ember_display.sv — Phase-3 display controller (line-buffered VGA).
//
// Timing: 640x480@60 (800x525 total). v1 scans FB0 in 320x240 double-scan
// mode: each VRAM pixel (byte-packed RGB565) is emitted 2x horizontally and
// 2x vertically (2x2 nearest-neighbor upscale, PS1 style).
//
// Fetch pipeline (uniform per OUTPUT pixel — trivially correct):
//   stage 0 (cycle C, output pixel C): register the word request for the
//          VRAM pixel under (vcnt>>1, hcnt>>1). Even/odd output pixels of a
//          320-pair share a word, so words are fetched twice — redundant but
//          always aligned (v2 replaces this with a real line buffer).
//   stage 1: fpa3_req high; VRAM samples at end of cycle.
//   stage 2: fpa3_rdata valid.
//   stage 3/4: word_q1/word_q2 pipeline; pixel presented from word_q2 with
//          de/odd delayed the same 4 cycles -> data and coordinates re-meet.
//
// vid_hs/vid_vs/vid_de/vid_pixel are ALL delayed by VID_LAT so the TB (and
// later the DAC) samples a consistent, aligned video stream.

`include "ember_pkg.sv"
import ember_pkg::*;

module ember_display
(
  input  logic        clk,
  input  logic        rst_n,

  input  logic [1:0]  fb_select,     // v1: only 0 (FB0); reserved for flip

  // fpa3: dedicated display read port (1-cycle latency, bus addresses)
  output logic        fpa3_req,
  output logic [31:0] fpa3_addr,
  input  logic [31:0] fpa3_rdata,

  // Aligned video outputs (all delayed by VID_LAT together)
  output logic        vid_hs,
  output logic        vid_vs,
  output logic        vid_de,        // visible pixel valid
  output logic [15:0] vid_pixel      // RGB565 (valid when vid_de=1)
);

  // ------------------------------------------------------------------
  // Timing constants (640x480@60)
  // ------------------------------------------------------------------
  localparam int unsigned H_VISIBLE = 640;
  localparam int unsigned H_FP      = 16;
  localparam int unsigned H_SYNC    = 96;
  localparam int unsigned H_BP      = 48;
  localparam int unsigned H_TOTAL   = H_VISIBLE + H_FP + H_SYNC + H_BP; // 800

  localparam int unsigned V_VISIBLE = 480;
  localparam int unsigned V_FP      = 10;
  localparam int unsigned V_SYNC    = 2;
  localparam int unsigned V_BP      = 33;
  localparam int unsigned V_TOTAL   = V_VISIBLE + V_FP + V_SYNC + V_BP; // 525

  localparam int unsigned VID_LAT   = 4;    // pipeline depth (see header)

  // FB0 as a BUS address (fpa3 uses ember_vram.addr2word semantics)
  localparam logic [31:0] FB_BUS = VRAM_BASE + FB0_BASE;

  // ------------------------------------------------------------------
  // Counters
  // ------------------------------------------------------------------
  logic [10:0] hcnt;      // 0..799
  logic [10:0] vcnt;      // 0..524

  wire h_visible = (hcnt < 11'(H_VISIBLE));
  wire v_visible = (vcnt < 11'(V_VISIBLE));
  wire de_now    = h_visible && v_visible;

  wire hs_now = (hcnt >= 11'(H_VISIBLE + H_FP)) &&
                (hcnt <  11'(H_VISIBLE + H_FP + H_SYNC));
  wire vs_now = (vcnt >= 11'(V_VISIBLE + V_FP)) &&
                (vcnt <  11'(V_VISIBLE + V_FP + V_SYNC));

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      hcnt <= '0;
      vcnt <= '0;
    end else begin
      if (hcnt == 11'(H_TOTAL - 1)) begin
        hcnt <= '0;
        vcnt <= (vcnt == 11'(V_TOTAL - 1)) ? '0 : vcnt + 11'(1);
      end else begin
        hcnt <= hcnt + 11'(1);
      end
    end
  end

  // ------------------------------------------------------------------
  // FB addressing (320x240 double-scan): VRAM pixel = (vcnt>>1, hcnt>>1).
  // Word byte address = FB_BUS + 2*(vrow*320 + vcol_even), vcol_even = even
  // member of the output pair = hcnt>>1 with bit0 cleared.
  // ------------------------------------------------------------------
  wire [9:0]  vrow    = vcnt[10:1];
  wire [9:0]  vcol    = hcnt[10:1];
  wire        odd_x   = vcol[0];          // pixel in HIGH halfword

  // byte address of the WORD containing this pixel:
  wire [31:0] word_byte_off = 32'(vrow) * 32'd640
                            + 32'({vcol[9:1], 1'b0}) * 32'd2;

  // ------------------------------------------------------------------
  // Stage 0: register the request (every visible pixel; words refetched)
  // ------------------------------------------------------------------
  logic        req_q;
  logic [31:0] addr_q;

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      req_q  <= 1'b0;
      addr_q <= '0;
    end else begin
      req_q <= de_now;
      if (de_now) addr_q <= FB_BUS + word_byte_off;
    end
  end

  assign fpa3_req  = req_q;
  assign fpa3_addr = addr_q;

  // ------------------------------------------------------------------
  // Stages 2..4: capture rdata, present with 4-cycle-delayed coordinates
  // ------------------------------------------------------------------
  logic [31:0] word_q1, word_q2;
  logic        de_d1, de_d2, de_d3, de_d4;
  logic        hs_d1, hs_d2, hs_d3, hs_d4;
  logic        vs_d1, vs_d2, vs_d3, vs_d4;
  logic        odd_d1, odd_d2, odd_d3, odd_d4;

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      word_q1 <= '0; word_q2 <= '0;
      de_d1 <= 1'b0; de_d2 <= 1'b0; de_d3 <= 1'b0; de_d4 <= 1'b0;
      hs_d1 <= 1'b0; hs_d2 <= 1'b0; hs_d3 <= 1'b0; hs_d4 <= 1'b0;
      vs_d1 <= 1'b0; vs_d2 <= 1'b0; vs_d3 <= 1'b0; vs_d4 <= 1'b0;
      odd_d1 <= 1'b0; odd_d2 <= 1'b0; odd_d3 <= 1'b0; odd_d4 <= 1'b0;
    end else begin
      word_q1 <= fpa3_rdata;
      word_q2 <= word_q1;
      de_d1 <= de_now; de_d2 <= de_d1; de_d3 <= de_d2; de_d4 <= de_d3;
      hs_d1 <= hs_now; hs_d2 <= hs_d1; hs_d3 <= hs_d2; hs_d4 <= hs_d3;
      vs_d1 <= vs_now; vs_d2 <= vs_d1; vs_d3 <= vs_d2; vs_d4 <= vs_d3;
      odd_d1 <= odd_x; odd_d2 <= odd_d1; odd_d3 <= odd_d2; odd_d4 <= odd_d3;
    end
  end

  assign vid_de    = de_d4;
  assign vid_hs    = hs_d4;
  assign vid_vs    = vs_d4;
  assign vid_pixel = de_d4 ? (odd_d4 ? word_q2[31:16] : word_q2[15:0]) : 16'h0;

  wire _unused = |fb_select;   // v1: FB0 only (flip arrives with v2 memory plan)

endmodule : ember_display
