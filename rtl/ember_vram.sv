// ember_vram.sv — Ember GPU VRAM: AXI4-Lite slave over 512 KiB on-chip memory.
//
// Contract:
//   * AXI4-Lite slave; full VALID/READY handshake on all five channels.
//   * Write latency: 1 cycle after AW+W both held. Read latency: 1 cycle after AR.
//   * Byte strobes honored via per-byte write enables (32-bit words internally).
//   * Word addresses wrap (bits [VRAM_AW-1:2]) — no OOR error by design.
//   * AW and W may arrive in any order; each is captured into a one-entry skid.
//   * At most one outstanding B and one outstanding R (back-pressure via ready).
//   * dbg_* sidecar port bypasses AXI for testbench golden checks. Do not use
//     dbg writes and AXI writes to the same word in the same cycle (undefined).

`include "ember_pkg.sv"
import ember_pkg::*;

module ember_vram
(
  input  logic               clk,
  input  logic               rst_n,

  // AXI4-Lite slave interface
  input  axil_aw_t           s_aw,
  input  logic               s_awvalid,
  output logic               s_awready,
  input  axil_w_t            s_w,
  input  logic               s_wvalid,
  output logic               s_wready,
  output axil_b_t            s_b,
  output logic               s_bvalid,
  input  logic               s_bready,
  input  axil_ar_t           s_ar,
  input  logic               s_arvalid,
  output logic               s_arready,
  output axil_r_t            s_r,
  output logic               s_rvalid,
  input  logic               s_rready,

  // Sidecar debug port
  input  logic               dbg_en,
  input  logic [VRAM_AW-3:0] dbg_addr,     // word address (2^17 words)
  output logic [31:0]        dbg_rdata,
  input  logic [31:0]        dbg_wdata,
  input  logic [3:0]         dbg_be,

  // RTR pixel ports (bus addresses, byte-addressed; same decode as AXI port)
  input  logic               fpa_we,
  input  logic [31:0]        fpa_addr,
  input  logic [31:0]        fpa_wdata,
  input  logic [3:0]         fpa_be,
  input  logic               fpa_req,
  output logic [31:0]        fpa_rdata,
  input  logic               fpa2_we,
  input  logic [31:0]        fpa2_addr,
  input  logic [31:0]        fpa2_wdata,
  input  logic [3:0]         fpa2_be,
  input  logic               fpa2_req,
  output logic [31:0]        fpa2_rdata,

  // fpa3: display fetch port (read-only, dedicated to ember_display)
  input  logic               fpa3_req,
  input  logic [31:0]        fpa3_addr,
  output logic [31:0]        fpa3_rdata,

  // gxa: GSX command-queue emit port (write-only use, dedicated to ember_gsx)
  input  logic               gxa_we,
  input  logic [31:0]        gxa_addr,
  input  logic [31:0]        gxa_wdata,
  input  logic [3:0]         gxa_be,
  input  logic               gxa_req,
  output logic [31:0]        gxa_rdata,

  // cxa: compute-core port (LD/ST data, dedicated to ember_core)
  input  logic               cxa_we,
  input  logic [31:0]        cxa_addr,
  input  logic [31:0]        cxa_wdata,
  input  logic [3:0]         cxa_be,
  input  logic               cxa_req,
  output logic [31:0]        cxa_rdata,

  // ixa: compute-core fetch port (read-only, dedicated to ember_core)
  input  logic               ixa_req,
  input  logic [31:0]        ixa_addr,
  output logic [31:0]        ixa_rdata,

  // tua: tensor-unit port (A/W/C tile traffic, dedicated to ember_tu)
  input  logic               tua_we,
  input  logic [31:0]        tua_addr,
  input  logic [31:0]        tua_wdata,
  input  logic [3:0]         tua_be,
  input  logic               tua_req,
  output logic [31:0]        tua_rdata
);

  // ------------------------------------------------------------------
  // Storage: 128K words x 32b
  // ------------------------------------------------------------------
  localparam int unsigned RAM_WORDS = VRAM_BYTES / 4;   // 131072
  logic [31:0] ram [RAM_WORDS];

  // Bus address -> word index. The VRAM window starts at VRAM_BASE on the bus,
  // so strip the base before indexing (offset 0 = first VRAM word).
  function automatic logic [VRAM_AW-3:0] addr2word(input logic [AXI_ADDR_W-1:0] a);
    logic [AXI_ADDR_W-1:0] off;
    off = a - VRAM_BASE;
    return off[VRAM_AW-1:2];   // word index: offset[18:2]
  endfunction

  // ------------------------------------------------------------------
  // AW / W skid capture (one entry each)
  // ------------------------------------------------------------------
  axil_aw_t aw_q;  logic aw_v;
  axil_w_t  w_q;   logic w_v;

  // Write commits only when B channel is free-or-completing this cycle
  wire wr_fire = aw_v && w_v && (!s_bvalid || s_bready);

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      aw_q <= '0; aw_v <= 1'b0;
    end else if (s_awvalid && s_awready) begin
      aw_q <= s_aw;          // capture wins over consume (pipeline advance)
      aw_v <= 1'b1;
    end else if (wr_fire) begin
      aw_v <= 1'b0;          // consumed, nothing new arrived
    end
  end

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      w_q <= '0; w_v <= 1'b0;
    end else if (s_wvalid && s_wready) begin
      w_q <= s_w;
      w_v <= 1'b1;
    end else if (wr_fire) begin
      w_v <= 1'b0;
    end
  end

  // Ready when skid entry is free, or is being consumed this cycle
  assign s_awready = !aw_v || wr_fire;
  assign s_wready  = !w_v  || wr_fire;

  // ------------------------------------------------------------------
  // RAM write (byte lanes)
  // ------------------------------------------------------------------
  always_ff @(posedge clk) begin
    if (wr_fire) begin
      if (w_q.strb[0]) ram[addr2word(aw_q.addr)][7:0]   <= w_q.data[7:0];
      if (w_q.strb[1]) ram[addr2word(aw_q.addr)][15:8]  <= w_q.data[15:8];
      if (w_q.strb[2]) ram[addr2word(aw_q.addr)][23:16] <= w_q.data[23:16];
      if (w_q.strb[3]) ram[addr2word(aw_q.addr)][31:24] <= w_q.data[31:24];
    end
  end

  // Debug sidecar write
  always_ff @(posedge clk) begin
    if (dbg_en && (|dbg_be)) begin
      if (dbg_be[0]) ram[dbg_addr][7:0]   <= dbg_wdata[7:0];
      if (dbg_be[1]) ram[dbg_addr][15:8]  <= dbg_wdata[15:8];
      if (dbg_be[2]) ram[dbg_addr][23:16] <= dbg_wdata[23:16];
      if (dbg_be[3]) ram[dbg_addr][31:24] <= dbg_wdata[31:24];
    end
  end

  // ------------------------------------------------------------------
  // RTR pixel ports (true dual-port: independent of AXI port traffic)
  // Address decode matches the AXI path: same VRAM_BASE strip + word index.
  // fpa: reads+writes (z-read, fb-read/write). fpa2: TEX byte fetch (read-only).
  // ------------------------------------------------------------------
  wire [VRAM_AW-3:0] fpa_widx  = addr2word(fpa_addr);
  wire [VRAM_AW-3:0] fpa2_widx = addr2word(fpa2_addr);

  // fpa write
  always_ff @(posedge clk) begin
    if (fpa_we) begin
      if (fpa_be[0]) ram[fpa_widx][7:0]   <= fpa_wdata[7:0];
      if (fpa_be[1]) ram[fpa_widx][15:8]  <= fpa_wdata[15:8];
      if (fpa_be[2]) ram[fpa_widx][23:16] <= fpa_wdata[23:16];
      if (fpa_be[3]) ram[fpa_widx][31:24] <= fpa_wdata[31:24];
    end
  end

  // fpa read (1-cycle)
  logic [31:0] fpa_rdata_q;
  always_ff @(posedge clk) begin
    if (fpa_req) fpa_rdata_q <= ram[fpa_widx];
  end
  assign fpa_rdata = fpa_rdata_q;

  // fpa2 read (1-cycle, used for texel bytes)
  logic [31:0] fpa2_rdata_q;
  always_ff @(posedge clk) begin
    if (fpa2_req) fpa2_rdata_q <= ram[fpa2_widx];
  end
  assign fpa2_rdata = fpa2_rdata_q;

  // fpa3 read (1-cycle, display fetch)
  wire [VRAM_AW-3:0] fpa3_widx = addr2word(fpa3_addr);
  logic [31:0] fpa3_rdata_q;
  always_ff @(posedge clk) begin
    if (fpa3_req) fpa3_rdata_q <= ram[fpa3_widx];
  end
  assign fpa3_rdata = fpa3_rdata_q;

  // gxa write (GSX cmdq emit; immediate commit, same as fpa writes)
  // and read (1-cycle, unused by GSX v1 but kept for symmetry)
  wire [VRAM_AW-3:0] gxa_widx = addr2word(gxa_addr);
  always_ff @(posedge clk) begin
    if (gxa_we) begin
      if (gxa_be[0]) ram[gxa_widx][7:0]   <= gxa_wdata[7:0];
      if (gxa_be[1]) ram[gxa_widx][15:8]  <= gxa_wdata[15:8];
      if (gxa_be[2]) ram[gxa_widx][23:16] <= gxa_wdata[23:16];
      if (gxa_be[3]) ram[gxa_widx][31:24] <= gxa_wdata[31:24];
    end
  end

  logic [31:0] gxa_rdata_q;
  always_ff @(posedge clk) begin
    if (gxa_req) gxa_rdata_q <= ram[gxa_widx];
  end
  assign gxa_rdata = gxa_rdata_q;

  // cxa write + 1-cycle read (compute core: fetch and LD share the channel)
  wire [VRAM_AW-3:0] cxa_widx = addr2word(cxa_addr);
  always_ff @(posedge clk) begin
    if (cxa_we) begin
      if (cxa_be[0]) ram[cxa_widx][7:0]   <= cxa_wdata[7:0];
      if (cxa_be[1]) ram[cxa_widx][15:8]  <= cxa_wdata[15:8];
      if (cxa_be[2]) ram[cxa_widx][23:16] <= cxa_wdata[23:16];
      if (cxa_be[3]) ram[cxa_widx][31:24] <= cxa_wdata[31:24];
    end
  end

  logic [31:0] cxa_rdata_q;
  always_ff @(posedge clk) begin
    if (cxa_req) cxa_rdata_q <= ram[cxa_widx];
  end
  assign cxa_rdata = cxa_rdata_q;

  // ixa fetch read (1-cycle)
  wire [VRAM_AW-3:0] ixa_widx = addr2word(ixa_addr);
  logic [31:0] ixa_rdata_q;
  always_ff @(posedge clk) begin
    if (ixa_req) ixa_rdata_q <= ram[ixa_widx];
  end
  assign ixa_rdata = ixa_rdata_q;

  // tua write + 1-cycle read (tensor unit tile traffic)
  wire [VRAM_AW-3:0] tua_widx = addr2word(tua_addr);
  always_ff @(posedge clk) begin
    if (tua_we) begin
      if (tua_be[0]) ram[tua_widx][7:0]   <= tua_wdata[7:0];
      if (tua_be[1]) ram[tua_widx][15:8]  <= tua_wdata[15:8];
      if (tua_be[2]) ram[tua_widx][23:16] <= tua_wdata[23:16];
      if (tua_be[3]) ram[tua_widx][31:24] <= tua_wdata[31:24];
    end
  end

  logic [31:0] tua_rdata_q;
  always_ff @(posedge clk) begin
    if (tua_req) tua_rdata_q <= ram[tua_widx];
  end
  assign tua_rdata = tua_rdata_q;

  // ------------------------------------------------------------------
  // B channel: single outstanding response
  // ------------------------------------------------------------------
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      s_bvalid <= 1'b0;
      s_b.resp <= RESP_OKAY;
    end else if (wr_fire) begin
      s_bvalid <= 1'b1;
      s_b.resp <= RESP_OKAY;
    end else if (s_bvalid && s_bready) begin
      s_bvalid <= 1'b0;
    end
  end

  // ------------------------------------------------------------------
  // Read engine: capture AR, respond next cycle
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

  // AR accepted while an R is completing this same cycle: ar_v stays set via
  // the capture branch (order matters: capture branch takes priority).

  assign s_arready = !ar_v || (s_rvalid && s_rready);

  logic [31:0] rdata_q;
  always_ff @(posedge clk) begin
    if (ar_accept) rdata_q <= ram[addr2word(s_ar.addr)];
  end

  assign s_r.data  = rdata_q;
  assign s_r.resp  = RESP_OKAY;
  assign s_rvalid  = ar_v;

  // ------------------------------------------------------------------
  // Debug sidecar read
  // ------------------------------------------------------------------
  logic [31:0] dbg_rdata_q;
  always_ff @(posedge clk) begin
    if (dbg_en) dbg_rdata_q <= ram[dbg_addr];
  end
  assign dbg_rdata = dbg_rdata_q;

endmodule : ember_vram
