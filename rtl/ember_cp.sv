// ember_cp.sv — Ember GPU Command Processor: control/status regs, upload FIFO,
// DMA engine (FIFO->VRAM and VRAM->FIFO), fence counter.
//
// Register interface (ember_ram_slave, 4 KB window, byte offsets):
//   0x00 CP_ID      RO  0xEB22_0002
//   0x04 CP_STATUS  RO  [0]=dma_busy [1]=rtr_busy [2]=rb_empty [6:3]=rb_count (0..8)
//   0x08 CP_CTRL    W1P [0]=sw_reset (flush FIFOs, abort DMA, clear fence)
//   0x0C CP_FENCE   RO  fence id of last completed DMA
//   0x10 CP_FIFOD   W:  push upload FIFO / R: pop readback FIFO (0 if empty)
//   0x14 CP_DMA_DST RW  VRAM byte offset (word aligned)
//   0x18 CP_DMA_LEN RW  length in bytes (word multiple); readback = remaining
//   0x1C CP_CMDX    W1P [0]=dir (0=FIFO->VRAM, 1=VRAM->FIFO), [15:8]=fence id
//   0x20 CP_RTR_KICK W1P [0]=1 kick RTR command queue (pulse to rtr_kick)
//
// Contract:
//   * DMA master: one outstanding AW+W, one outstanding AR, bready/rready=1.
//   * Upload: engine pops the upload FIFO one word per VRAM write; stalls when
//     FIFO is empty (software pre-fills the FIFO, then kicks — console style).
//     A popped word is safe: it is captured into the W register before the
//     FIFO pointer advances.
//   * Readback: words are pushed into an 8-deep FIFO on the R handshake cycle
//     (same edge — data is valid exactly then). Drop-on-overflow.
//   * Zero-length DMA: completes immediately, fence still updates.
//   * sw_reset: flush both FIFOs, engine to idle, clear fence. Params kept.

`include "ember_pkg.sv"
import ember_pkg::*;

module ember_cp
(
  input  logic        clk,
  input  logic        rst_n,

  // Register-block slave port (from xbar, host-only)
  input  axil_aw_t    s_aw,      input  logic s_awvalid,  output logic s_awready,
  input  axil_w_t     s_w,       input  logic s_wvalid,   output logic s_wready,
  output axil_b_t     s_b,       output logic s_bvalid,   input  logic s_bready,
  input  axil_ar_t    s_ar,      input  logic s_arvalid,  output logic s_arready,
  output axil_r_t     s_r,       output logic s_rvalid,   input  logic s_rready,

  // DMA master port (to xbar -> VRAM)
  output axil_aw_t    m_aw,      output logic m_awvalid,  input  logic m_awready,
  output axil_w_t     m_w,       output logic m_wvalid,   input  logic m_wready,
  input  axil_b_t     m_b,       input  logic m_bvalid,   output logic m_bready,
  output axil_ar_t    m_ar,      output logic m_arvalid,  input  logic m_arready,
  input  axil_r_t     m_r,       input  logic m_rvalid,   output logic m_rready,

  // RTR command-queue kick (1-cycle pulse when host writes CP_RTR_KICK[0]=1)
  output logic        rtr_kick,
  // Level status: any DMA or RTR draw in flight (OR of the two busy bits)
  input  logic        rtr_busy,

  // Blitter CSR/kick decode (1-cycle pulses; blit_busy ORed into STATUS)
  output logic        blit_csr_we,
  output logic [1:0]  blit_csr_addr,
  output logic [31:0] blit_csr_wdata,
  output logic        blit_kick,
  input  logic        blit_busy,

  // GSX CSR/kick decode (same pattern; gsx_busy is STATUS bit 8)
  output logic        gsx_csr_we,
  output logic [1:0]  gsx_csr_addr,
  output logic [31:0] gsx_csr_wdata,
  output logic        gsx_kick,
  input  logic        gsx_busy,

  // Compute-core CSR decode (core_busy is STATUS bit 9)
  output logic        core_csr_we,
  output logic [1:0]  core_csr_addr,
  output logic [31:0] core_csr_wdata,
  output logic        core_kick,
  input  logic        core_busy,

  // Tensor-unit CSR decode (tu_busy is STATUS bit 10)
  output logic        tu_csr_we,
  output logic [1:0]  tu_csr_addr,
  output logic [31:0] tu_csr_wdata,
  output logic        tu_kick,
  input  logic        tu_busy
);

  // ==================================================================
  // Register block wires (via ember_ram_slave)
  // ==================================================================
  logic [11:0] reg_addr;      // write address (commit cycle)
  logic [3:0]  reg_be;
  logic [31:0] reg_wdata;
  logic        reg_wr_en;     // 1-cycle pulse
  logic [11:0] rd_addr;       // read mux select

  // ------------------------------------------------------------------
  // Software-visible state (ALL driven from the single FSM block below)
  // ------------------------------------------------------------------
  logic [31:0] dma_dst_q;     // configured VRAM byte offset
  logic [31:0] dma_len_q;     // configured length, bytes
  logic [7:0]  fence_pend_q;  // fence id latched from CMDX
  logic [7:0]  fence_done_q;  // last completed fence id
  logic        dma_busy_q;

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      dma_dst_q    <= 32'h0;
      dma_len_q    <= 32'h0;
      fence_pend_q <= 8'h0;
      fence_done_q <= 8'h0;
      dma_busy_q   <= 1'b0;
    end else if (reg_wr_en) begin
      if (reg_be[0]) begin
        case (reg_addr)
          CP_DMA_DST: dma_dst_q <= reg_wdata;
          CP_DMA_LEN: dma_len_q <= reg_wdata;
          CP_CMDX:    fence_pend_q <= reg_wdata[15:8];
          default: ;
        endcase
      end
    end
  end

  // ==================================================================
  // Upload FIFO (64 x 32b) — host pushes via CP_FIFOD writes
  // ==================================================================
  localparam int unsigned UP_DEPTH = 64;
  localparam int unsigned UP_AW    = $clog2(UP_DEPTH);   // 6

  logic [31:0] up_mem [UP_DEPTH];
  logic [UP_AW:0] up_wp, up_rp;

  wire up_full  = (up_wp[UP_AW] != up_rp[UP_AW]) &&
                  (up_wp[UP_AW-1:0] == up_rp[UP_AW-1:0]);
  wire up_empty = (up_wp == up_rp);

  wire up_push = reg_wr_en && (reg_addr == CP_FIFOD) && reg_be[0];

  logic        up_pop;
  wire [31:0]  up_front = up_mem[up_rp[UP_AW-1:0]];

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      up_wp <= '0;
    end else if (up_push && !up_full) begin
      up_mem[up_wp[UP_AW-1:0]] <= reg_wdata;
      up_wp <= up_wp + 1'b1;
    end
  end

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n)      up_rp <= '0;
    else if (up_pop) up_rp <= up_rp + 1'b1;
  end

  // ==================================================================
  // Readback FIFO (8 x 32b) — push same-edge with m_rvalid; host pops reads
  // ==================================================================
  localparam int unsigned RB_DEPTH = 8;
  localparam int unsigned RB_AW    = $clog2(RB_DEPTH);   // 3

  logic [31:0] rb_mem [RB_DEPTH];
  logic [RB_AW:0] rb_wp, rb_rp;

  wire rb_full  = (rb_wp[RB_AW] != rb_rp[RB_AW]) &&
                  (rb_wp[RB_AW-1:0] == rb_rp[RB_AW-1:0]);
  wire rb_empty = (rb_wp == rb_rp);

  wire rb_push = m_rvalid;                  // data valid exactly on this edge
  wire [31:0]  rb_data_in = m_r.data;

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      rb_wp <= '0;
    end else if (rb_push && !rb_full) begin
      rb_mem[rb_wp[RB_AW-1:0]] <= rb_data_in;
      rb_wp <= rb_wp + 1'b1;
    end
  end

  // host pops on CP_FIFOD AR accept (data captured by ram_slave on same edge)
  wire rb_pop = s_arvalid && s_arready && (s_ar.addr[11:0] == CP_FIFOD);

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n)       rb_rp <= '0;
    else if (rb_pop && !rb_empty) rb_rp <= rb_rp + 1'b1;
  end

  // ==================================================================
  // DMA engine FSM (single driver for bus master outputs)
  // ==================================================================
  typedef enum logic [1:0] { DMA_IDLE, DMA_WR, DMA_WR_WAIT, DMA_RD } dstate_e;
  dstate_e dstate;

  logic [31:0] dma_addr_q;   // running VRAM byte address (offset space)
  logic [31:0] dma_left_q;   // remaining bytes
  logic        r_pend_q;     // AR accepted, waiting for R
  logic        w_busy_q;     // W presented, awaiting handshake (skew guard)

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      dstate       <= DMA_IDLE;
      dma_addr_q   <= 32'h0;
      dma_left_q   <= 32'h0;
      dma_busy_q   <= 1'b0;
      fence_done_q <= 8'h0;
      r_pend_q     <= 1'b0;
      w_busy_q     <= 1'b0;
      up_pop       <= 1'b0;
      m_awvalid    <= 1'b0;
      m_wvalid     <= 1'b0;
      m_arvalid    <= 1'b0;
      m_aw         <= '0;
      m_w          <= '0;
      m_ar         <= '0;
    end else begin
      up_pop <= 1'b0;   // default: no FIFO pop this cycle

      case (dstate)
        // ------------------------------------------------------------
        DMA_IDLE: begin
          if (reg_wr_en && reg_be[0] && (reg_addr == CP_CMDX)) begin
            dma_addr_q <= dma_dst_q;
            dma_left_q <= dma_len_q;
            dma_busy_q <= 1'b1;
            if (dma_len_q == 32'h0) begin
              // zero-length: complete immediately, fence still updates
              dma_busy_q   <= 1'b0;
              fence_done_q <= reg_wdata[15:8];
            end else begin
              dstate <= reg_wdata[0] ? DMA_RD : DMA_WR;
            end
          end
        end

        // ------------------------------------------------------------
        // FIFO -> VRAM
        // ------------------------------------------------------------
        DMA_WR: begin
          // Present AW+W together only when both channels are fully idle.
          // w_busy_q guards the skew case where W is accepted before AW.
          if (!up_empty && !m_awvalid && !w_busy_q) begin
            m_awvalid  <= 1'b1;
            m_wvalid   <= 1'b1;
            w_busy_q   <= 1'b1;
            m_aw.addr  <= VRAM_BASE + dma_addr_q;   // VRAM offset -> bus addr
            m_aw.prot  <= '0;
            m_w.data   <= up_front;   // word captured; safe to pop
            m_w.strb   <= 4'hF;
            up_pop     <= 1'b1;
          end

          if (m_awvalid && m_awready) m_awvalid <= 1'b0;
          if (m_wvalid && m_wready) begin
            m_wvalid   <= 1'b0;
            w_busy_q   <= 1'b0;
            dma_addr_q <= dma_addr_q + 4;
            if (dma_left_q <= 4) begin
              // Last word: wait for a still-pending AW before fencing.
              dstate <= m_awvalid ? DMA_WR_WAIT : DMA_IDLE;
              if (!m_awvalid) begin
                dma_busy_q   <= 1'b0;
                fence_done_q <= fence_pend_q;
              end
            end else begin
              dma_left_q <= dma_left_q - 4;
            end
          end
        end

        // AW of the final word still in flight; fence when it lands.
        DMA_WR_WAIT: begin
          if (!m_awvalid) begin
            dstate       <= DMA_IDLE;
            dma_busy_q   <= 1'b0;
            fence_done_q <= fence_pend_q;
          end
        end

        // ------------------------------------------------------------
        // VRAM -> FIFO
        // ------------------------------------------------------------
        DMA_RD: begin
          // consume R (push happens same edge via rb_push wire)
          if (m_rvalid) begin
            dma_addr_q <= dma_addr_q + 4;
            r_pend_q   <= 1'b0;
            if (dma_left_q <= 4) begin
              dstate       <= DMA_IDLE;
              dma_busy_q   <= 1'b0;
              fence_done_q <= fence_pend_q;
            end else begin
              dma_left_q <= dma_left_q - 4;
            end
          end

          // issue next AR only when the read channel is fully idle
          if (!m_arvalid && !r_pend_q && !m_rvalid && dma_left_q > 0) begin
            m_arvalid  <= 1'b1;
            m_ar.addr  <= VRAM_BASE + dma_addr_q;   // VRAM offset -> bus addr
            m_ar.prot  <= '0;
          end

          if (m_arvalid && m_arready) begin
            m_arvalid <= 1'b0;
            r_pend_q  <= 1'b1;
          end
        end

        default: dstate <= DMA_IDLE;
      endcase

      // ------------------------------------------------------------
      // sw_reset (W1P on CP_CTRL): flush FIFOs, abort engine, clear fence
      // ------------------------------------------------------------
      if (reg_wr_en && (reg_addr == CP_CTRL) && reg_wdata[0]) begin
        dstate       <= DMA_IDLE;
        dma_busy_q   <= 1'b0;
        fence_done_q <= 8'h0;
        up_rp        <= up_wp;
        rb_wp        <= '0;
        rb_rp        <= '0;
        r_pend_q     <= 1'b0;
        w_busy_q     <= 1'b0;
        m_awvalid    <= 1'b0;
        m_wvalid     <= 1'b0;
        m_arvalid    <= 1'b0;
      end
    end
  end

  // ==================================================================
  // Read mux (combinational; ram_slave samples at AR accept)
  // ==================================================================
  logic [31:0] rd_data;
  logic [3:0]  rb_count;
  assign rb_count = rb_wp[RB_AW-1:0] - rb_rp[RB_AW-1:0];   // 0..8, wraps correctly
  always_comb begin
    case (rd_addr)
      CP_ID:      rd_data = 32'hEB22_0002;
      CP_STATUS:  rd_data = {21'h0, tu_busy, core_busy, gsx_busy, blit_busy,
                             rb_count, rb_empty, rtr_busy, dma_busy_q};
      CP_FENCE:   rd_data = {24'h0, fence_done_q};
      CP_FIFOD:   rd_data = rb_empty ? 32'h0 : rb_mem[rb_rp[RB_AW-1:0]];
      CP_DMA_DST: rd_data = dma_dst_q;
      CP_DMA_LEN: rd_data = dma_len_q;
      default:    rd_data = 32'h0;
    endcase
  end

  // ==================================================================
  // ember_ram_slave instantiation (AXI handshake for the reg window)
  // ==================================================================
  ember_ram_slave u_regs (
    .clk        (clk),
    .rst_n      (rst_n),
    .s_aw       (s_aw),  .s_awvalid (s_awvalid),  .s_awready (s_awready),
    .s_w        (s_w),   .s_wvalid  (s_wvalid),   .s_wready  (s_wready),
    .s_b        (s_b),   .s_bvalid  (s_bvalid),   .s_bready  (s_bready),
    .s_ar       (s_ar),  .s_arvalid (s_arvalid),  .s_arready (s_arready),
    .s_r        (s_r),   .s_rvalid  (s_rvalid),   .s_rready  (s_rready),
    .reg_addr   (reg_addr),
    .reg_be     (reg_be),
    .reg_wdata  (reg_wdata),
    .reg_wr_en  (reg_wr_en),
    .rd_addr    (rd_addr),
    .rd_data    (rd_data)
  );

  // DMA master port
  assign m_bready = 1'b1;
  assign m_rready = 1'b1;

  // RTR kick: W1P pulse when host writes CP_RTR_KICK with bit0 set.
  // Ignored by the RTR while a draw is in flight (sampled only when idle).
  assign rtr_kick = reg_wr_en && reg_be[0] && (reg_addr == CP_RTR_KICK) && reg_wdata[0];

  // Blitter decode: CFG/DST/SRC/SIZE are plain RW regs (pulse + addr),
  // CP_BLIT_KICK is W1P kick.
  logic blit_csr_zone;
  assign blit_csr_zone = (reg_addr == CP_BLIT_CFG) || (reg_addr == CP_BLIT_DST)
                       || (reg_addr == CP_BLIT_SRC) || (reg_addr == CP_BLIT_SIZE);
  assign blit_csr_we    = reg_wr_en && reg_be[0] && blit_csr_zone;
  // 00=CFG 01=DST 10=SRC 11=SIZE (bit0: DST|SIZE, bit1: SRC|SIZE)
  assign blit_csr_addr[0] = (reg_addr == CP_BLIT_DST) ||
                            (reg_addr == CP_BLIT_SIZE);
  assign blit_csr_addr[1] = (reg_addr == CP_BLIT_SRC) ||
                            (reg_addr == CP_BLIT_SIZE);
  assign blit_csr_wdata = reg_wdata;
  assign blit_kick = reg_wr_en && reg_be[0] && (reg_addr == CP_BLIT_KICK) && reg_wdata[0];

  // GSX decode: MATA/VTX/COL/CFG are plain RW regs (pulse + addr),
  // CP_GSX_GO is W1P kick. Same addr-bit folding as the blitter:
  // 00=MATA 01=VTX 10=COL 11=CFG (bit0: VTX|CFG, bit1: COL|CFG)
  logic gsx_csr_zone;
  assign gsx_csr_zone = (reg_addr == CP_GSX_MATA) || (reg_addr == CP_GSX_VTX)
                      || (reg_addr == CP_GSX_COL)  || (reg_addr == CP_GSX_CFG);
  assign gsx_csr_we    = reg_wr_en && reg_be[0] && gsx_csr_zone;
  assign gsx_csr_addr[0] = (reg_addr == CP_GSX_VTX) ||
                           (reg_addr == CP_GSX_CFG);
  assign gsx_csr_addr[1] = (reg_addr == CP_GSX_COL) ||
                           (reg_addr == CP_GSX_CFG);
  assign gsx_csr_wdata = reg_wdata;
  assign gsx_kick = reg_wr_en && reg_be[0] && (reg_addr == CP_GSX_GO) && reg_wdata[0];

  // Compute-core decode: CODE/NBLK are plain RW regs, CP_CORE_KICK is W1P.
  // 00=CODE 01=NBLK (bit0: NBLK; bit1 unused)
  logic core_csr_zone;
  assign core_csr_zone  = (reg_addr == CP_CORE_CODE) || (reg_addr == CP_CORE_NBLK);
  assign core_csr_we    = reg_wr_en && reg_be[0] && core_csr_zone;
  assign core_csr_addr[0] = (reg_addr == CP_CORE_NBLK);
  assign core_csr_addr[1] = 1'b0;
  assign core_csr_wdata = reg_wdata;
  assign core_kick = reg_wr_en && reg_be[0] && (reg_addr == CP_CORE_KICK) && reg_wdata[0];

  // Tensor-unit decode: TUA/TUW/TUC/CFG2 -> 2-bit addr (bit0: W|CFG2,
  // bit1: C|CFG2), CP_TU_KICK is W1P.
  logic tu_csr_zone;
  assign tu_csr_zone  = (reg_addr == CP_TU_A) || (reg_addr == CP_TU_W)
                      || (reg_addr == CP_TU_C) || (reg_addr == CP_TU_CFG2);
  assign tu_csr_we    = reg_wr_en && reg_be[0] && tu_csr_zone;
  assign tu_csr_addr[0] = (reg_addr == CP_TU_W) || (reg_addr == CP_TU_CFG2);
  assign tu_csr_addr[1] = (reg_addr == CP_TU_C) || (reg_addr == CP_TU_CFG2);
  assign tu_csr_wdata = reg_wdata;
  assign tu_kick = reg_wr_en && reg_be[0] && (reg_addr == CP_TU_KICK) && reg_wdata[0];

  wire _unused = up_full | rb_full;   // drop-on-overflow / stall-on-empty by design

endmodule : ember_cp
