// ember_memif.sv — Ember chip external memory controller (EMC).
//
// Purpose: the die exposes its VRAM as a raw multiport bundle (AXI4-Lite plus
// seven fixed-latency "fast" ports). No real memory device looks like that.
// The EMC converts the bundle into the chip's physical memory interface:
//
//   * 3 read channels (mem0/mem1/mem2): each is the read port of one external
//     128K x 32 simple-dual-port SRAM (512 KiB, the whole VRAM map).
//   * 1 broadcast write bus (mem_w*): every write is presented to all three
//     SRAMs at once, so the three read ports see identical data. This is
//     memory replication for multiport access — the standard construction
//     when several masters need same-cycle reads of one address space.
//
// Channel map (why 3):
//   CH0: fpa3   display scan — fires EVERY visible cycle, never stalls.
//   CH1: fpa / fpa2 / gxa / cxa / tua — engine traffic. The CP software
//        contract is one engine at a time (the die ALREADY assumes this for
//        the rtr/blit fpa ownership mux), and fpa/fpa2 never fire in the same
//        cycle inside ember_rtr_scan's FSM.
//   CH2: ixa (core fetch) + the AXI4-Lite port (host + CP DMA).
//        ixa wins same-cycle conflicts; the AXI port legally stalls
//        (v_arready/v_awready drop) — AXI-Lite is the only port in the whole
//        bundle that has wait states.
//   Worst case simultaneous non-stallable traffic: fpa3 + cxa + ixa
//   (display + core load + core fetch) = exactly 3 channels.
//
// Timing contract — IDENTICAL to ember_vram (masters cannot wait):
//   * read : request + address during cycle N -> read data valid during N+1.
//   * write: commits at the edge ending the request cycle; a same-cycle read
//     of the same address returns the OLD value (nonblocking semantics of
//     ember_vram). External memory must be "read-old-data" on read-during-
//     write; the SRAM behavioral model in test/ matches this.
//
// Write bus arbitration (broadcast = one write per cycle system-wide):
//   engine writes cannot stall -> fixed priority fpa > fpa2 > cxa > tua > gxa;
//   the AXI write fires only when no engine write is present (it waits in the
//   ember_vram-style AW/W skid).
//
// Contract assumption (same as the die's fpa mux): at most one engine is
// active at a time. A SIM_ASSERT below flags violations in simulation.

`include "ember_pkg.sv"
import ember_pkg::*;

module ember_memif
(
  input  logic        clk,
  input  logic        rst_n,

  // ------------------------------------------------------------------
  // Die side — identical to ember_die's external VRAM bundle.
  // AXI4-Lite slave (driven by the die's xbar: host port + CP DMA).
  // ------------------------------------------------------------------
  input  axil_aw_t    v_aw,   input  logic v_awvalid, output logic v_awready,
  input  axil_w_t     v_w,    input  logic v_wvalid,  output logic v_wready,
  output axil_b_t     v_b,    output logic v_bvalid,  input  logic v_bready,
  input  axil_ar_t    v_ar,   input  logic v_arvalid, output logic v_arready,
  output axil_r_t     v_r,    output logic v_rvalid,  input  logic v_rready,

  // Fast ports (fixed 1-cycle read latency)
  input  logic        fpa_we,
  input  logic [31:0] fpa_addr, fpa_wdata,
  input  logic [3:0]  fpa_be,
  input  logic        fpa_req,
  output logic [31:0] fpa_rdata,
  input  logic        fpa2_we,
  input  logic [31:0] fpa2_addr, fpa2_wdata,
  input  logic [3:0]  fpa2_be,
  input  logic        fpa2_req,
  output logic [31:0] fpa2_rdata,
  input  logic        fpa3_req,
  input  logic [31:0] fpa3_addr,
  output logic [31:0] fpa3_rdata,
  input  logic        gxa_we,
  input  logic [31:0] gxa_addr, gxa_wdata,
  input  logic [3:0]  gxa_be,
  input  logic        gxa_req,
  output logic [31:0] gxa_rdata,
  input  logic        cxa_we,
  input  logic [31:0] cxa_addr, cxa_wdata,
  input  logic [3:0]  cxa_be,
  input  logic        cxa_req,
  output logic [31:0] cxa_rdata,
  input  logic        ixa_req,
  input  logic [31:0] ixa_addr,
  output logic [31:0] ixa_rdata,
  input  logic        tua_we,
  input  logic [31:0] tua_addr, tua_wdata,
  input  logic [3:0]  tua_be,
  input  logic        tua_req,
  output logic [31:0] tua_rdata,

  // ------------------------------------------------------------------
  // Memory side — physical SRAM interface (see docs/chip_pinout.md).
  // Word addresses: VRAM is 512 KiB = 128K x 32 -> 17-bit word address.
  // ------------------------------------------------------------------
  output logic [16:0] mem_waddr,
  output logic [31:0] mem_wdata,
  output logic [3:0]  mem_wbe_n,
  output logic        mem_we_n,
  output logic [16:0] mem0_raddr,
  input  logic [31:0] mem0_rdata,
  output logic        mem0_re_n,
  output logic [16:0] mem1_raddr,
  input  logic [31:0] mem1_rdata,
  output logic        mem1_re_n,
  output logic [16:0] mem2_raddr,
  input  logic [31:0] mem2_rdata,
  output logic        mem2_re_n
);

  localparam int unsigned MEM_AW = VRAM_AW - 2;   // 17: word address

  // Bus byte address -> VRAM word index (identical to ember_vram.addr2word).
  function automatic logic [MEM_AW-1:0] addr2word(input logic [AXI_ADDR_W-1:0] a);
    logic [AXI_ADDR_W-1:0] off;
    off = a - VRAM_BASE;
    return off[VRAM_AW-1:2];
  endfunction

  // ------------------------------------------------------------------
  // Write side: engine writes (priority) then the AXI skid.
  // ------------------------------------------------------------------
  wire fpa_wr  = fpa_we;
  wire fpa2_wr = fpa2_we;
  wire cxa_wr  = cxa_we;
  wire tua_wr  = tua_we;
  wire gxa_wr  = gxa_we;
  wire eng_wr  = fpa_wr | fpa2_wr | cxa_wr | tua_wr | gxa_wr;

  // AXI write (ember_vram skid semantics: AW+W both held, B free).
  axil_aw_t aw_q;  logic aw_v;
  axil_w_t  w_q;   logic w_v;

  wire axi_wr = aw_v && w_v && (!v_bvalid || v_bready) && !eng_wr;
  wire wr_fire = eng_wr | axi_wr;

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      aw_q <= '0; aw_v <= 1'b0;
    end else if (v_awvalid && v_awready) begin
      aw_q <= v_aw;          // capture wins over consume
      aw_v <= 1'b1;
    end else if (axi_wr) begin
      aw_v <= 1'b0;
    end
  end

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      w_q <= '0; w_v <= 1'b0;
    end else if (v_wvalid && v_wready) begin
      w_q <= v_w;  w_v <= 1'b1;
    end else if (axi_wr) begin
      w_v <= 1'b0;
    end
  end

  assign v_awready = !aw_v || axi_wr;
  assign v_wready  = !w_v  || axi_wr;

  // Broadcast write bus: fixed priority fpa > fpa2 > cxa > tua > gxa > axi.
  logic [31:0] wr_addr32, wr_data;
  logic [3:0]  wr_be;

  always_comb begin
    if (fpa_wr) begin
      wr_addr32 = fpa_addr;  wr_data = fpa_wdata;  wr_be = fpa_be;
    end else if (fpa2_wr) begin
      wr_addr32 = fpa2_addr; wr_data = fpa2_wdata; wr_be = fpa2_be;
    end else if (cxa_wr) begin
      wr_addr32 = cxa_addr;  wr_data = cxa_wdata;  wr_be = cxa_be;
    end else if (tua_wr) begin
      wr_addr32 = tua_addr;  wr_data = tua_wdata;  wr_be = tua_be;
    end else if (gxa_wr) begin
      wr_addr32 = gxa_addr;  wr_data = gxa_wdata;  wr_be = gxa_be;
    end else begin
      wr_addr32 = aw_q.addr; wr_data = w_q.data;   wr_be = w_q.strb;
    end
  end

  assign mem_waddr = addr2word(wr_addr32);
  assign mem_wdata = wr_data;
  assign mem_wbe_n = ~wr_be;
  assign mem_we_n  = ~wr_fire;

  // AXI write response (single outstanding B, as in ember_vram).
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      v_bvalid <= 1'b0;
      v_b.resp <= RESP_OKAY;
    end else if (axi_wr) begin
      v_bvalid <= 1'b1;
      v_b.resp <= RESP_OKAY;
    end else if (v_bvalid && v_bready) begin
      v_bvalid <= 1'b0;
    end
  end

  // ------------------------------------------------------------------
  // CH0: display scan (read-only).
  // ------------------------------------------------------------------
  assign mem0_raddr = addr2word(fpa3_addr);
  assign mem0_re_n  = ~fpa3_req;

  logic [31:0] fpa3_rdata_q;
  always_ff @(posedge clk) begin
    if (fpa3_req) fpa3_rdata_q <= mem0_rdata;
  end
  assign fpa3_rdata = fpa3_rdata_q;

  // ------------------------------------------------------------------
  // CH1: engine ports (mutually exclusive by contract; priority mux
  // fpa > fpa2 > cxa > tua > gxa degrades gracefully on violation).
  // ------------------------------------------------------------------
  wire gnt_fpa  = fpa_req;
  wire gnt_fpa2 = !fpa_req  & fpa2_req;
  wire gnt_cxa  = !fpa_req  & !fpa2_req & cxa_req;
  wire gnt_tua  = !fpa_req  & !fpa2_req & !cxa_req & tua_req;
  wire gnt_gxa  = !fpa_req  & !fpa2_req & !cxa_req & !tua_req & gxa_req;
  wire ch1_req  = fpa_req | fpa2_req | cxa_req | tua_req | gxa_req;

  logic [31:0] ch1_addr;
  always_comb begin
    if      (gnt_fpa)  ch1_addr = fpa_addr;
    else if (gnt_fpa2) ch1_addr = fpa2_addr;
    else if (gnt_cxa)  ch1_addr = cxa_addr;
    else if (gnt_tua)  ch1_addr = tua_addr;
    else               ch1_addr = gxa_addr;
  end

  assign mem1_raddr = addr2word(ch1_addr);
  assign mem1_re_n  = ~ch1_req;

  logic [31:0] fpa_rdata_q, fpa2_rdata_q, cxa_rdata_q, tua_rdata_q, gxa_rdata_q;
  always_ff @(posedge clk) begin
    if (gnt_fpa)  fpa_rdata_q  <= mem1_rdata;
    if (gnt_fpa2) fpa2_rdata_q <= mem1_rdata;
    if (gnt_cxa)  cxa_rdata_q  <= mem1_rdata;
    if (gnt_tua)  tua_rdata_q  <= mem1_rdata;
    if (gnt_gxa)  gxa_rdata_q  <= mem1_rdata;
  end
  assign fpa_rdata  = fpa_rdata_q;
  assign fpa2_rdata = fpa2_rdata_q;
  assign cxa_rdata  = cxa_rdata_q;
  assign tua_rdata  = tua_rdata_q;
  assign gxa_rdata  = gxa_rdata_q;

  // ------------------------------------------------------------------
  // CH2: core fetch (fixed latency) + AXI reads (stallable).
  // ------------------------------------------------------------------
  logic ar_v;

  wire ar_accept = v_arvalid && v_arready;

  // ixa owns the channel this cycle; the AXI port waits legally.
  assign v_arready = (!ar_v || (v_rvalid && v_rready)) && !ixa_req;

  assign mem2_raddr = addr2word(ixa_req ? ixa_addr : v_ar.addr);
  assign mem2_re_n  = ~(ixa_req | ar_accept);

  logic [31:0] ixa_rdata_q, axi_rdata_q;
  always_ff @(posedge clk) begin
    if (ixa_req)   ixa_rdata_q <= mem2_rdata;
    if (ar_accept) axi_rdata_q <= mem2_rdata;
  end
  assign ixa_rdata = ixa_rdata_q;

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      ar_v <= 1'b0;
    end else if (ar_accept) begin
      ar_v <= 1'b1;
    end else if (v_rvalid && v_rready) begin
      ar_v <= 1'b0;
    end
  end

  assign v_r.data  = axi_rdata_q;
  assign v_r.resp  = RESP_OKAY;
  assign v_rvalid  = ar_v;

`ifndef SYNTHESIS
  // One-engine-at-a-time contract: two CH1 requests in one cycle would give
  // the loser stale data. Flag loudly in simulation.
  wire [3:0] ch1_reqs = {3'b0, fpa_req} + {3'b0, fpa2_req} + {3'b0, cxa_req}
                        + {3'b0, tua_req} + {3'b0, gxa_req};
  always_ff @(posedge clk) begin
    if (rst_n && (ch1_reqs > 4'd1))
      $display("EMC ERROR t=%0t: CH1 collision (one-engine contract violated)", $time);
  end
`endif

endmodule : ember_memif
