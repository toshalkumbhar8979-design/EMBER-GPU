// ember_core.sv — Phase-5 compute core (v1: ONE core, 4 threads, SPMD).
//
// Calling convention (set at block start):
//   %r12 = param base (VRAM byte offset = CMDBUF_BASE; kernel loads its
//          pointer words from there), %r13 = blockIdx, %r14 = blockDim,
//   %r15 = threadIdx. Other GPRs are NOT cleared. Threads end with `halt`.
//
// ISA (encoding [31:24] op [23:20] rd [19:16] ra [15:12] rb [11:0] imm —
// see tools/assembler.py; branches are next-relative; ONLY CMP sets nzp):
//   ALU int : ADD SUB MUL DIV AND OR XOR SHL SHR CMP MIN MAXC
//   ALU fp  : FADD FSUB FMUL FDIV (op[1:0] = fpu4 op; lane0, serialized)
//   IMM     : LI/LIU rd, imm16        -> rd = {imm[15:12], imm[11:0]}
//   MEM     : LD/ST rd, [ra + off12]  (VRAM via cxa)  LDS/STS/ATOMIC_* (smem)
//   BR      : BRNZP nzp, label        (9-bit signed, next-relative)
//   JUMP    : JAL rd, label / JR ra / CALL label / RET / BAR / HALT / NOP
//
// Microarchitecture (v1, correctness-first):
//   * Per-thread fetch PCs (fpc) and PER-THREAD one-word instruction
//     buffers. A stalled thread (LD/fp wait, barrier) holds only its own
//     buffer — other threads keep fetching/executing. A SINGLE shared
//     buffer DEADLOCKS on barriers (proved by trace: thread 0 reaches bar
//     first, its next word wedges the buffer, threads 1..3 never run).
//   * SEPARATE VRAM channels: ixa = instruction fetch (read-only), cxa =
//     data LD/ST. Sharing one channel deadlocks (fetch occupies it while
//     a load-waiting thread holds the only buffer).
//   * Branches redirect fpc and squash the thread's in-flight fetch.
//   * smem = 1024-word block-scoped scratch (not auto-cleared).
//   * BAR: count-up barrier over 4 threads; release is same-edge.
//   * Budget counter forces block end after ~1M cycles (deadlock guard).
//
// CSR (decoded by ember_cp): 00=CODE (kernel entry, VRAM byte offset),
// 01=NBLK (block count), kick = launch.

`include "ember_pkg.sv"
import ember_pkg::*;

module ember_core
(
  input  logic        clk,
  input  logic        rst_n,

  // CSR from CP
  input  logic        csr_we,
  input  logic [1:0]  csr_addr,      // 00=CODE 01=NBLK
  input  logic [31:0] csr_wdata,
  input  logic        kick,

  // Dedicated VRAM data port (BUS addresses)
  output logic        cxa_we,
  output logic [31:0] cxa_addr,
  output logic [31:0] cxa_wdata,
  output logic [3:0]  cxa_be,
  output logic        cxa_req,
  input  logic [31:0] cxa_rdata,

  // Dedicated VRAM fetch port (read-only)
  output logic        ixa_req,
  output logic [31:0] ixa_addr,
  input  logic [31:0] ixa_rdata,

  output logic        busy
);

  localparam int unsigned NT  = 4;
  localparam int unsigned SAW = 10;               // smem: 2^10 words

  // ==================================================================
  // CSR state
  // ==================================================================
  logic [31:0] code_base_q;                       // VRAM byte offset
  logic [7:0]  nblk_q;

  wire csr_code_we = csr_we && (csr_addr == 2'd0);
  wire csr_nblk_we = csr_we && (csr_addr == 2'd1);

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      code_base_q <= 32'h0;
      nblk_q      <= 8'd1;
    end else begin
      if (csr_code_we) code_base_q <= {csr_wdata[31:2], 2'b00};
      if (csr_nblk_we && csr_wdata[7:0] != 8'd0) nblk_q <= csr_wdata[7:0];
    end
  end

  // ==================================================================
  // Thread state
  // ==================================================================
  typedef struct packed {
    logic       halt;
    logic [2:0] nzp;                              // {n, z, p}
  } tstate_t;

  tstate_t     T [NT];
  logic [7:0]  fpc [NT];                          // fetch PC (word index)
                                                  // Phase-7d fix: was 5 bits
                                                  // (32 words) — pool2d's 56
                                                  // words aliased PCs 32..55
                                                  // back to 0..23 and the
                                                  // kernel restarted forever.
  logic [31:0] gpr [NT][16];
  logic [NT-1:0] waitv;                           // stalled on LD / fp
  logic [NT-1:0] barv;                            // waiting at barrier

  // per-thread one-word instruction buffers
  logic [NT-1:0] ibuf_v;
  logic [31:0]   ibuf_w [NT];

  logic [31:0] smem [1 << SAW];                   // block-scoped scratch

  // ==================================================================
  // Scalar fp lane (FADD/FSUB/FMUL/FDIV via fpu4 lane0)
  // ==================================================================
  logic [3:0]  f_lane_en;
  logic [3:0]  f_op;
  logic [31:0] f_a0, f_b0, f_a1, f_b1, f_a2, f_b2, f_a3, f_b3;
  logic        f_go;
  logic [31:0] f_y0, f_y1, f_y2, f_y3;
  logic        f_busy, f_done;

  ember_fpu4 u_fpu (
    .clk(clk), .rst_n(rst_n),
    .lane_en(f_lane_en), .op(f_op),
    .a0(f_a0), .b0(f_b0),
    .a1(f_a1), .b1(f_b1), .a2(f_a2), .b2(f_b2),
    .a3(f_a3), .b3(f_b3),
    .go(f_go),
    .y0(f_y0), .y1(f_y1), .y2(f_y2), .y3(f_y3),
    .busy(f_busy), .done(f_done)
  );

  // ==================================================================
  // FSM + issue machinery
  // ==================================================================
  typedef enum logic [1:0] { C_IDLE, C_EXEC, C_BEND, C_DONE } cstate_e;
  cstate_e st;
  logic        running;
  assign busy = running;
  logic [7:0]  blk;
  logic [19:0] budget;                            // deadlock guard

  // fetch channel (ixa): one outstanding fetch
  logic        ix_pend, ix_req_cyc;
  logic [1:0]  ix_tid;
  logic        flush_req;                         // squash in-flight fetch
  logic [1:0]  flush_tid;

  // data channel (cxa): LD request -> data regs -> consume
  logic        ld_pend;
  logic [31:0] ld_addr_q;
  logic [1:0]  ld_tid_q;
  logic [3:0]  ld_rd_q;
  logic        cx_pend, cx_req_cyc;
  logic        dr_valid;
  logic [1:0]  dr_tid;
  logic [3:0]  dr_rd;
  logic [31:0] dr_word;

  // fp op in flight
  logic        fp_pend;
  logic [1:0]  fp_tid;
  logic [3:0]  fp_rd;

  logic [1:0]  bar_count;

  // ------------------------------------------------------------------
  // Execute picker: lowest thread with a buffered word AND runnable.
  // ------------------------------------------------------------------
  logic       exec_en;
  logic [1:0] exec_tid;
  always_comb begin
    exec_en  = 1'b0;
    exec_tid = 2'd0;
    for (int t = NT - 1; t >= 0; t--)
      if (st == C_EXEC && ibuf_v[t] && !waitv[t] && !barv[t]) begin
        exec_en  = 1'b1;
        exec_tid = t[1:0];
      end
  end

  // Fetch picker: lowest thread that can accept a fetch into its buffer
  // (not halted; stalled threads MAY prefetch their next word).
  logic [1:0] pick_tid;
  logic       pick_en;
  always_comb begin
    pick_en  = 1'b0;
    pick_tid = 2'd0;
    for (int t = NT - 1; t >= 0; t--)
      if (st == C_EXEC && !T[t].halt && !ibuf_v[t]) begin
        pick_en  = 1'b1;
        pick_tid = t[1:0];
      end
  end

  // ------------------------------------------------------------------
  // Decode fields (from the selected buffer)
  // ------------------------------------------------------------------
  wire [7:0]  i_op   = ibuf_w[exec_tid][31:24];
  wire [3:0]  i_rd   = ibuf_w[exec_tid][23:20];
  wire [3:0]  i_ra   = ibuf_w[exec_tid][19:16];
  wire [3:0]  i_rb   = ibuf_w[exec_tid][15:12];
  wire [11:0] i_imm  = ibuf_w[exec_tid][11:0];
  wire signed [31:0] i_sx12 = {{20{i_imm[11]}}, i_imm};
  wire signed [8:0]  i_sx9  = i_imm[8:0];        // 9-bit signed
  wire signed [10:0] i_sx11 = i_imm[10:0];       // 11-bit signed

  wire [31:0] rav = gpr[exec_tid][i_ra];
  wire [31:0] rbv = gpr[exec_tid][i_rb];

  // block/thread init
  task automatic init_block(input logic [7:0] b);
    for (int t = 0; t < NT; t++) begin
      T[t].halt  <= 1'b0;
      T[t].nzp   <= 3'b000;
      fpc[t]     <= 8'd0;
      gpr[t][12] <= CMDBUF_BASE;                  // param base (VRAM offset)
      gpr[t][13] <= {24'h0, b};                   // blockIdx
      gpr[t][14] <= {24'h0, nblk_q};              // blockDim
      gpr[t][15] <= {30'h0, t[1:0]};              // threadIdx
    end
    ibuf_v    <= '0;
    waitv     <= '0;
    barv      <= '0;
    bar_count <= 2'd0;
    budget    <= '0;
  endtask

  // ------------------------------------------------------------------
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      st        <= C_IDLE;
      running   <= 1'b0;
      blk       <= 8'd0;
      ibuf_v    <= '0;
      ix_pend   <= 1'b0;
      ix_req_cyc<= 1'b0;
      ix_tid    <= 2'd0;
      flush_req <= 1'b0;
      flush_tid <= 2'd0;
      ld_pend   <= 1'b0;
      ld_addr_q <= 32'h0;
      ld_tid_q  <= 2'd0;
      ld_rd_q   <= 4'd0;
      cx_pend   <= 1'b0;
      cx_req_cyc<= 1'b0;
      dr_valid  <= 1'b0;
      dr_tid    <= 2'd0;
      dr_rd     <= 4'd0;
      dr_word   <= 32'h0;
      fp_pend   <= 1'b0;
      fp_tid    <= 2'd0;
      fp_rd     <= 4'd0;
      bar_count <= 2'd0;
      budget    <= '0;
      f_lane_en <= 4'h0;
      f_go      <= 1'b0;
      f_op      <= 4'h0;
      f_a0 <= '0; f_b0 <= '0; f_a1 <= '0; f_b1 <= '0;
      f_a2 <= '0; f_b2 <= '0; f_a3 <= '0; f_b3 <= '0;
      cxa_we    <= 1'b0;
      cxa_addr  <= 32'h0;
      cxa_wdata <= 32'h0;
      cxa_be    <= 4'h0;
      cxa_req   <= 1'b0;
      ixa_req   <= 1'b0;
      ixa_addr  <= 32'h0;
      waitv     <= 4'h0;
      barv      <= 4'h0;
      for (int t = 0; t < NT; t++) begin
        T[t] <= '0;
        fpc[t] <= 8'd0;
        ibuf_w[t] <= 32'h0;
        for (int r = 0; r < 16; r++) gpr[t][r] <= 32'h0;
      end
    end else begin
      cxa_we  <= 1'b0;                            // defaults: idle this cycle
      cxa_req <= 1'b0;
      ixa_req <= 1'b0;
      f_go    <= 1'b0;

      // ---- fetch capture: ixa data valid the cycle after the req edge.
      // Write DIRECTLY into the fetching thread's own buffer. ----
      if (ix_pend && !ix_req_cyc) begin
        ix_pend <= 1'b0;
        if (flush_req && (ix_tid == flush_tid)) begin
          flush_req <= 1'b0;                      // squashed fall-through
        end else begin
          ibuf_v[ix_tid] <= 1'b1;
          ibuf_w[ix_tid] <= ixa_rdata;
        end
      end else if (flush_req) begin
        flush_req <= 1'b0;                        // expire unmatched flush
      end
      if (ix_req_cyc) ix_req_cyc <= 1'b0;

      // ---- data capture: cxa read data valid the cycle after req ----
      if (cx_pend && !cx_req_cyc) begin
        cx_pend <= 1'b0;
        dr_valid <= 1'b1;
        dr_tid   <= ld_tid_q;
        dr_rd    <= ld_rd_q;
        dr_word  <= cxa_rdata;
      end
      if (cx_req_cyc) cx_req_cyc <= 1'b0;

      // ---- data consume -> register write ----
      if (dr_valid) begin
        dr_valid <= 1'b0;
        gpr[dr_tid][dr_rd] <= dr_word;
        waitv[dr_tid]      <= 1'b0;
      end

      // ---- fp completion ----
      if (fp_pend && f_done) begin
        gpr[fp_tid][fp_rd] <= f_y0;
        waitv[fp_tid]      <= 1'b0;
        fp_pend            <= 1'b0;
      end

      case (st)
        // ----------------------------------------------------------
        C_IDLE: begin
          running <= 1'b0;
          if (kick) begin
            running <= 1'b1;
            blk     <= 8'd0;
            init_block(8'd0);
            st      <= C_EXEC;
          end
        end
        // ----------------------------------------------------------
        C_EXEC: begin
          budget <= budget + 20'd1;

          if (budget == 20'hF_FFFF) begin
            for (int t = 0; t < NT; t++) T[t].halt <= 1'b1;
            st <= C_BEND;
          end else begin
            // ============ EXECUTE the selected buffered word ============
            if (exec_en) begin
              ibuf_v[exec_tid] <= 1'b0;
              if (T[exec_tid].halt) begin
                // stale word for a retired thread: drop, no side effects
              end else begin
                case (i_op)
                  // ---- ALU int ----
                  8'h01: gpr[exec_tid][i_rd] <= rav + rbv;    // ADD
                  8'h02: gpr[exec_tid][i_rd] <= rav - rbv;    // SUB
                  8'h03: gpr[exec_tid][i_rd] <= $signed(rav)
                                                * $signed(rbv);
                  8'h04: gpr[exec_tid][i_rd] <= (rbv == 32'h0) ? 32'h0
                                              : ($signed(rav)
                                                 / $signed(rbv));
                  8'h05: gpr[exec_tid][i_rd] <= rav & rbv;
                  8'h06: gpr[exec_tid][i_rd] <= rav | rbv;
                  8'h07: gpr[exec_tid][i_rd] <= rav ^ rbv;
                  8'h08: gpr[exec_tid][i_rd] <= rav << rbv[4:0];
                  8'h09: gpr[exec_tid][i_rd] <= rav >> rbv[4:0];
                  8'h0A: begin                   // CMP -> nzp
                    logic [31:0] d;
                    d = rav - rbv;
                    T[exec_tid].nzp <= {d[31], (d == 32'h0),
                                        !d[31] && (d != 32'h0)};
                  end
                  8'h0B: gpr[exec_tid][i_rd] <= ($signed(rav)
                                                 < $signed(rbv))
                                              ? rav : rbv;
                  8'h0C: gpr[exec_tid][i_rd] <= ($signed(rav)
                                                 > $signed(rbv))
                                              ? rav : rbv;
                  8'h0D, 8'h0E:                  // LI / LIU
                    gpr[exec_tid][i_rd] <= {16'h0, i_ra, i_imm};
                  // ---- ALU fp (lane0, serialized) ----
                  8'h40, 8'h41, 8'h42, 8'h43: begin
                    f_lane_en       <= 4'b0001;
                    f_op            <= {2'b00, i_op[1:0]};
                    f_a0            <= rav;
                    f_b0            <= rbv;
                    f_go            <= 1'b1;
                    fp_pend         <= 1'b1;
                    fp_tid          <= exec_tid;
                    fp_rd           <= i_rd;
                    waitv[exec_tid] <= 1'b1;
                  end
                  // ---- memory: VRAM data ----
                  8'h10: begin                   // LD
                    ld_pend         <= 1'b1;
                    ld_addr_q       <= 32'(VRAM_BASE + (rav + i_sx12));
                    ld_tid_q        <= exec_tid;
                    ld_rd_q         <= i_rd;
                    waitv[exec_tid] <= 1'b1;
                  end
                  8'h11: begin                   // ST
                    cxa_we    <= 1'b1;
                    cxa_be    <= 4'hF;
                    cxa_addr  <= 32'(VRAM_BASE + (rav + i_sx12));
                    cxa_wdata <= gpr[exec_tid][i_rd];
                  end
                  // ---- memory: smem ----
                  8'h12:                         // LDS
                    gpr[exec_tid][i_rd] <= smem[(rav + i_sx12)
                                                & ((1 << SAW) - 1)];
                  8'h13:                         // STS
                    smem[(rav + i_sx12) & ((1 << SAW) - 1)]
                      <= gpr[exec_tid][i_rd];
                  8'h14:                         // ATOMIC_ADD (1 core)
                    smem[(rav + i_sx12) & ((1 << SAW) - 1)]
                      <= smem[(rav + i_sx12) & ((1 << SAW) - 1)]
                         + gpr[exec_tid][i_rd];
                  8'h15:                         // ATOMIC_MAX
                    if ($signed(gpr[exec_tid][i_rd])
                        > $signed(smem[(rav + i_sx12)
                                       & ((1 << SAW) - 1)]))
                      smem[(rav + i_sx12) & ((1 << SAW) - 1)]
                        <= gpr[exec_tid][i_rd];
                  // ---- control ----
                  8'h20: begin                   // BRNZP
                    if ((T[exec_tid].nzp & i_rd[2:0]) != 3'b000) begin
                      fpc[exec_tid] <= 8'(fpc[exec_tid] + i_sx9);
                      flush_req     <= 1'b1;
                      flush_tid     <= exec_tid;
                    end
                  end
                  8'h21, 8'h24: begin            // JAL / CALL
                    gpr[exec_tid][(i_op == 8'h21) ? i_rd : 4'd15]
                      <= {24'h0, fpc[exec_tid]}; // link = Wpc+1 = fpc
                    fpc[exec_tid] <= 8'(fpc[exec_tid] + i_sx11);
                    flush_req     <= 1'b1;
                    flush_tid     <= exec_tid;
                  end
                  8'h22: begin                   // JR
                    fpc[exec_tid] <= gpr[exec_tid][i_ra][7:0];
                    flush_req     <= 1'b1;
                    flush_tid     <= exec_tid;
                  end
                  8'h23: begin                   // RET
                    fpc[exec_tid] <= gpr[exec_tid][15][7:0];
                    flush_req     <= 1'b1;
                    flush_tid     <= exec_tid;
                  end
                  8'h25: begin                   // BAR
                    barv[exec_tid] <= 1'b1;
                    bar_count      <= bar_count + 2'd1;
                    if (bar_count == 2'd3) begin
                      barv      <= 4'h0;         // all arrived: release
                      bar_count <= 2'd0;
                    end
                  end
                  8'hFF:                         // HALT
                    T[exec_tid].halt <= 1'b1;
                  default: ;                     // NOP / reserved
                endcase
              end
            end

            // ---- data-request issue (cxa): pending LD first ----
            if (ld_pend && !cx_pend) begin
              ld_pend    <= 1'b0;
              cx_pend    <= 1'b1;
              cx_req_cyc <= 1'b1;
              cxa_req    <= 1'b1;
              cxa_addr   <= ld_addr_q;
            end

            // ---- fetch issue (ixa): one outstanding; the picked
            // thread must not have just redirected its fpc ----
            if (!ix_pend && pick_en
                && !(flush_req && (flush_tid == pick_tid))) begin
              ix_pend    <= 1'b1;
              ix_req_cyc <= 1'b1;
              ix_tid     <= pick_tid;
              ixa_req    <= 1'b1;
              ixa_addr   <= (VRAM_BASE + code_base_q)
                            + {22'h0, fpc[pick_tid], 2'b00};  // 22+8+2 = 32
              fpc[pick_tid] <= fpc[pick_tid] + 5'd1;
            end

            // ---- block end: fully quiescent ----
            // (no word will execute or be fetched this/next cycles)
            if (!exec_en && !pick_en && !ix_pend && !cx_pend && !dr_valid
                && !fp_pend && !ld_pend && (waitv == '0) && (barv == '0)) begin
              st <= C_BEND;
            end
          end
        end
        // ----------------------------------------------------------
        C_BEND: begin
          if (blk + 8'd1 >= nblk_q) begin
            running <= 1'b0;
            st      <= C_DONE;
          end else begin
            blk <= blk + 8'd1;
            init_block(blk + 8'd1);
            st  <= C_EXEC;
          end
        end
        // ----------------------------------------------------------
        C_DONE: begin
          running <= 1'b0;
          st      <= C_IDLE;
        end
        default: st <= C_IDLE;
      endcase
    end
  end

  // fpu lanes 1..3 unused in the core
  wire _unused = ^{f_y1, f_y2, f_y3, f_busy};

endmodule : ember_core
