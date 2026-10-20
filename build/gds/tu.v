module ember_tu (
	clk,
	rst_n,
	csr_we,
	csr_addr,
	csr_wdata,
	kick,
	tua_we,
	tua_addr,
	tua_wdata,
	tua_be,
	tua_req,
	tua_rdata,
	busy
);
	input wire clk;
	input wire rst_n;
	input wire csr_we;
	input wire [1:0] csr_addr;
	input wire [31:0] csr_wdata;
	input wire kick;
	output reg tua_we;
	output reg [31:0] tua_addr;
	output reg [31:0] tua_wdata;
	output reg [3:0] tua_be;
	output reg tua_req;
	input wire [31:0] tua_rdata;
	output wire busy;
	localparam [31:0] N16 = 16;
	reg [31:0] a_base_q;
	reg [31:0] w_base_q;
	reg [31:0] c_base_q;
	reg [15:0] req_mult;
	reg [3:0] req_shift;
	reg [11:0] dim_n;
	reg [11:0] dim_k;
	reg [11:0] dim_m;
	wire cfg2_dim_we = (csr_we && (csr_addr == 2'd3)) && (csr_wdata[31:30] == 2'b00);
	wire cfg2_m_we = (csr_we && (csr_addr == 2'd3)) && (csr_wdata[31:30] == 2'b01);
	wire cfg2_q_we = (csr_we && (csr_addr == 2'd3)) && (csr_wdata[31:30] == 2'b10);
	always @(posedge clk or negedge rst_n)
		if (!rst_n) begin
			a_base_q <= 32'h00000000;
			w_base_q <= 32'h00000000;
			c_base_q <= 32'h00000000;
			req_mult <= 16'd1;
			req_shift <= 4'd0;
			dim_n <= 12'd0;
			dim_k <= 12'd0;
			dim_m <= 12'd0;
		end
		else begin
			if (csr_we)
				case (csr_addr)
					2'd0: a_base_q <= {csr_wdata[31:2], 2'b00};
					2'd1: w_base_q <= {csr_wdata[31:2], 2'b00};
					2'd2: c_base_q <= {csr_wdata[31:2], 2'b00};
					default:
						;
				endcase
			if (cfg2_dim_we) begin
				dim_n <= csr_wdata[11:0];
				dim_k <= csr_wdata[27:16];
			end
			if (cfg2_m_we)
				dim_m <= csr_wdata[11:0];
			if (cfg2_q_we) begin
				req_mult <= csr_wdata[15:0];
				req_shift <= csr_wdata[23:20];
			end
		end
	wire [31:0] kdim = {20'h00000, dim_k};
	wire [31:0] ndim = {20'h00000, dim_n};
	wire [31:0] mdim = {20'h00000, dim_m};
	reg [31:0] wrowbuf [0:3];
	reg [31:0] abuf_q [0:3];
	wire [7:0] wbyte [0:15];
	genvar _gv_gwb_1;
	generate
		for (_gv_gwb_1 = 0; _gv_gwb_1 < N16; _gv_gwb_1 = _gv_gwb_1 + 1) begin : g_wbyte
			localparam gwb = _gv_gwb_1;
			assign wbyte[gwb] = wrowbuf[gwb[3:2]][gwb[1:0] * 8+:8];
		end
	endgenerate
	reg [15:0] w_ld;
	reg [7:0] w_regs [0:15][0:15];
	wire [7:0] a_row_byte [0:15];
	always @(posedge clk) begin : sv2v_autoblock_1
		reg signed [31:0] r;
		for (r = 0; r < N16; r = r + 1)
			if (w_ld[r]) begin : sv2v_autoblock_2
				reg signed [31:0] c;
				for (c = 0; c < N16; c = c + 1)
					w_regs[r][c] <= wbyte[c];
			end
	end
	genvar _gv_gr_1;
	genvar _gv_gc_1;
	generate
		for (_gv_gr_1 = 0; _gv_gr_1 < N16; _gv_gr_1 = _gv_gr_1 + 1) begin : g_ab
			localparam gr = _gv_gr_1;
			assign a_row_byte[gr] = abuf_q[gr[3:2]][gr[1:0] * 8+:8];
		end
	endgenerate
	wire signed [31:0] prod [0:15][0:15];
	function automatic signed [31:0] sv2v_cast_32_signed;
		input reg signed [31:0] inp;
		sv2v_cast_32_signed = inp;
	endfunction
	generate
		for (_gv_gr_1 = 0; _gv_gr_1 < N16; _gv_gr_1 = _gv_gr_1 + 1) begin : g_prod
			localparam gr = _gv_gr_1;
			for (_gv_gc_1 = 0; _gv_gc_1 < N16; _gv_gc_1 = _gv_gc_1 + 1) begin : g_pc
				localparam gc = _gv_gc_1;
				assign prod[gr][gc] = sv2v_cast_32_signed($signed(w_regs[gr][gc])) * sv2v_cast_32_signed($signed(a_row_byte[gr]));
			end
		end
	endgenerate
	wire signed [31:0] lv1 [0:15][0:7];
	wire signed [31:0] lv2 [0:15][0:3];
	wire signed [31:0] lv3 [0:15][0:1];
	wire signed [31:0] tree [0:15];
	genvar _gv_gt_1;
	genvar _gv_trow_1;
	generate
		for (_gv_gt_1 = 0; _gv_gt_1 < N16; _gv_gt_1 = _gv_gt_1 + 1) begin : g_tree
			localparam gt = _gv_gt_1;
			for (_gv_trow_1 = 0; _gv_trow_1 < 8; _gv_trow_1 = _gv_trow_1 + 1) begin : genblk1
				localparam trow = _gv_trow_1;
				assign lv1[gt][trow] = prod[2 * trow][gt] + prod[(2 * trow) + 1][gt];
			end
			for (_gv_trow_1 = 8; _gv_trow_1 < 12; _gv_trow_1 = _gv_trow_1 + 1) begin : genblk2
				localparam trow = _gv_trow_1;
				assign lv2[gt][trow - 8] = lv1[gt][2 * (trow - 8)] + lv1[gt][(2 * (trow - 8)) + 1];
			end
			for (_gv_trow_1 = 12; _gv_trow_1 < 14; _gv_trow_1 = _gv_trow_1 + 1) begin : genblk3
				localparam trow = _gv_trow_1;
				assign lv3[gt][trow - 12] = lv2[gt][2 * (trow - 12)] + lv2[gt][(2 * (trow - 12)) + 1];
			end
			assign tree[gt] = lv3[gt][0] + lv3[gt][1];
		end
	endgenerate
	reg signed [31:0] acc [0:15][0:15];
	reg [3:0] st;
	reg running;
	assign busy = running;
	reg [31:0] k0;
	reg [31:0] n0;
	reg [31:0] m0;
	reg [4:0] wrow;
	reg [1:0] wgrp;
	reg [3:0] mrow;
	reg [3:0] fcnt;
	reg mac_pend;
	reg rq_pend;
	reg rq_req_cyc;
	reg [31:0] rq_addr_q;
	reg rq_dst_w;
	reg [1:0] rq_aw;
	reg [11:0] cw_row;
	reg [3:0] cw_rblk;
	reg [1:0] cw_word;
	reg [7:0] cw_byte0;
	reg [7:0] cw_byte1;
	reg [7:0] cw_byte2;
	reg [7:0] cw_byte3;
	function automatic [7:0] requant8;
		input reg signed [31:0] c32;
		input reg [15:0] mult;
		input reg [3:0] shift;
		reg signed [47:0] full;
		reg signed [47:0] half;
		reg signed [47:0] res;
		begin
			full = $signed(c32) * $signed({32'h00000000, mult});
			if (shift == 4'd0)
				res = full;
			else begin
				half = 48'd1 << (shift - 4'd1);
				res = (full + half) >>> shift;
			end
			requant8 = res[7:0];
		end
	endfunction
	task automatic reset_acc;
		reg signed [31:0] r;
		for (r = 0; r < N16; r = r + 1)
			begin : sv2v_autoblock_3
				reg signed [31:0] c;
				for (c = 0; c < N16; c = c + 1)
					acc[r][c] <= 32'sd0;
			end
	endtask
	localparam [31:0] ember_pkg_CP_BASE = 32'h00000000;
	localparam [31:0] ember_pkg_CP_WINDOW_BYTES = 4096;
	localparam [31:0] ember_pkg_VRAM_BASE = ember_pkg_CP_BASE + ember_pkg_CP_WINDOW_BYTES;
	function automatic [31:0] sv2v_cast_32;
		input reg [31:0] inp;
		sv2v_cast_32 = inp;
	endfunction
	always @(posedge clk or negedge rst_n)
		if (!rst_n) begin
			st <= 4'd0;
			running <= 1'b0;
			k0 <= 32'd0;
			n0 <= 32'd0;
			m0 <= 32'd0;
			wrow <= 5'd0;
			wgrp <= 2'd0;
			mrow <= 4'd0;
			fcnt <= 4'd0;
			mac_pend <= 1'b0;
			rq_pend <= 1'b0;
			rq_req_cyc <= 1'b0;
			rq_addr_q <= 32'h00000000;
			rq_dst_w <= 1'b0;
			rq_aw <= 2'd0;
			tua_we <= 1'b0;
			tua_addr <= 32'h00000000;
			tua_wdata <= 32'h00000000;
			tua_be <= 4'h0;
			tua_req <= 1'b0;
			w_ld <= 1'sb0;
			cw_row <= 12'd0;
			cw_rblk <= 4'd0;
			cw_word <= 2'd0;
			cw_byte0 <= 8'd0;
			cw_byte1 <= 8'd0;
			cw_byte2 <= 8'd0;
			cw_byte3 <= 8'd0;
			begin : sv2v_autoblock_4
				reg signed [31:0] r;
				for (r = 0; r < N16; r = r + 1)
					begin : sv2v_autoblock_5
						reg signed [31:0] c;
						for (c = 0; c < N16; c = c + 1)
							acc[r][c] <= 32'sd0;
					end
			end
		end
		else begin
			tua_we <= 1'b0;
			tua_req <= 1'b0;
			w_ld <= 1'sb0;
			if (rq_pend && !rq_req_cyc) begin
				rq_pend <= 1'b0;
				if (rq_dst_w)
					abuf_q[rq_aw] <= tua_rdata;
				else
					wrowbuf[rq_aw] <= tua_rdata;
			end
			if (rq_req_cyc)
				rq_req_cyc <= 1'b0;
			if (mac_pend) begin
				mac_pend <= 1'b0;
				begin : sv2v_autoblock_6
					reg signed [31:0] c;
					for (c = 0; c < N16; c = c + 1)
						acc[mrow][c] <= acc[mrow][c] + tree[c];
				end
			end
			case (st)
				4'd0: begin
					running <= 1'b0;
					if (kick) begin
						running <= 1'b1;
						n0 <= 32'd0;
						m0 <= 32'd0;
						k0 <= 32'd0;
						wrow <= 5'd0;
						wgrp <= 2'd0;
						reset_acc;
						st <= 4'd1;
					end
				end
				4'd1:
					if (!rq_pend) begin
						rq_pend <= 1'b1;
						rq_req_cyc <= 1'b1;
						rq_dst_w <= 1'b0;
						rq_aw <= wgrp;
						tua_req <= 1'b1;
						tua_addr <= (((ember_pkg_VRAM_BASE + w_base_q) + ((k0 + sv2v_cast_32(wrow)) * ndim)) + n0) + {28'h0000000, wgrp, 2'b00};
						rq_addr_q <= (((ember_pkg_VRAM_BASE + w_base_q) + ((k0 + sv2v_cast_32(wrow)) * ndim)) + n0) + {28'h0000000, wgrp, 2'b00};
						st <= 4'd2;
					end
				4'd2:
					if (!rq_pend && !rq_req_cyc) begin
						if (wgrp == 2'd3)
							st <= 4'd3;
						else begin
							wgrp <= wgrp + 2'd1;
							st <= 4'd1;
						end
					end
				4'd3: begin
					w_ld[wrow[3:0]] <= 1'b1;
					if (wrow == 5'd15) begin
						wrow <= 5'd0;
						mrow <= 4'd0;
						fcnt <= 4'd0;
						st <= 4'd4;
					end
					else begin
						wrow <= wrow + 5'd1;
						wgrp <= 2'd0;
						st <= 4'd1;
					end
				end
				4'd4:
					if (!rq_pend) begin
						rq_pend <= 1'b1;
						rq_req_cyc <= 1'b1;
						rq_dst_w <= 1'b1;
						rq_aw <= fcnt[1:0];
						tua_req <= 1'b1;
						tua_addr <= (((ember_pkg_VRAM_BASE + a_base_q) + ((m0 + sv2v_cast_32(mrow)) * kdim)) + k0) + {28'h0000000, fcnt[1:0], 2'b00};
						rq_addr_q <= (((ember_pkg_VRAM_BASE + a_base_q) + ((m0 + sv2v_cast_32(mrow)) * kdim)) + k0) + {28'h0000000, fcnt[1:0], 2'b00};
						if (fcnt[1:0] == 2'd3)
							st <= 4'd5;
						fcnt <= fcnt + 4'd1;
					end
				4'd5:
					if (!rq_pend && !rq_req_cyc) begin
						mac_pend <= 1'b1;
						st <= 4'd6;
					end
				4'd6:
					if (!mac_pend) begin
						if (mrow == 4'd15)
							st <= 4'd7;
						else begin
							mrow <= mrow + 4'd1;
							fcnt <= 4'd0;
							st <= 4'd4;
						end
					end
				4'd7:
					if ((k0 + 32'd16) >= kdim) begin
						cw_rblk <= 4'd0;
						cw_word <= 2'd0;
						cw_row <= m0[11:0];
						st <= 4'd8;
					end
					else begin
						k0 <= k0 + 32'd16;
						wrow <= 5'd0;
						wgrp <= 2'd0;
						st <= 4'd1;
					end
				4'd8: begin
					cw_byte0 <= requant8(acc[cw_rblk][(cw_word * 4) + 0], req_mult, req_shift);
					cw_byte1 <= requant8(acc[cw_rblk][(cw_word * 4) + 1], req_mult, req_shift);
					cw_byte2 <= requant8(acc[cw_rblk][(cw_word * 4) + 2], req_mult, req_shift);
					cw_byte3 <= requant8(acc[cw_rblk][(cw_word * 4) + 3], req_mult, req_shift);
					st <= 4'd9;
				end
				4'd9: begin
					tua_we <= 1'b1;
					tua_be <= 4'hf;
					tua_addr <= (((ember_pkg_VRAM_BASE + c_base_q) + (sv2v_cast_32(cw_row) * ndim)) + n0) + {28'h0000000, cw_word, 2'b00};
					tua_wdata <= {cw_byte3, cw_byte2, cw_byte1, cw_byte0};
					if (cw_word == 2'd3) begin
						cw_word <= 2'd0;
						if (cw_rblk == 4'd15)
							st <= 4'd10;
						else begin
							cw_rblk <= cw_rblk + 4'd1;
							cw_row <= cw_row + 12'd1;
							st <= 4'd8;
						end
					end
					else begin
						cw_word <= cw_word + 2'd1;
						st <= 4'd8;
					end
				end
				4'd10:
					if ((m0 + 32'd16) >= mdim) begin
						if ((n0 + 32'd16) >= ndim) begin
							running <= 1'b0;
							st <= 4'd11;
						end
						else begin
							n0 <= n0 + 32'd16;
							m0 <= 32'd0;
							k0 <= 32'd0;
							wrow <= 5'd0;
							wgrp <= 2'd0;
							reset_acc;
							st <= 4'd1;
						end
					end
					else begin
						m0 <= m0 + 32'd16;
						k0 <= 32'd0;
						wrow <= 5'd0;
						wgrp <= 2'd0;
						reset_acc;
						st <= 4'd1;
					end
				4'd11: begin
					running <= 1'b0;
					st <= 4'd0;
				end
				default: st <= 4'd0;
			endcase
		end
endmodule