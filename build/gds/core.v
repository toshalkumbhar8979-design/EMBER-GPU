module ember_fpu4 (
	clk,
	rst_n,
	lane_en,
	op,
	a0,
	b0,
	a1,
	b1,
	a2,
	b2,
	a3,
	b3,
	go,
	y0,
	y1,
	y2,
	y3,
	busy,
	done
);
	input wire clk;
	input wire rst_n;
	input wire [3:0] lane_en;
	input wire [3:0] op;
	input wire [31:0] a0;
	input wire [31:0] b0;
	input wire [31:0] a1;
	input wire [31:0] b1;
	input wire [31:0] a2;
	input wire [31:0] b2;
	input wire [31:0] a3;
	input wire [31:0] b3;
	input wire go;
	output wire [31:0] y0;
	output wire [31:0] y1;
	output wire [31:0] y2;
	output wire [31:0] y3;
	output wire busy;
	output wire done;
	localparam [1:0] FOP_ADD = 2'd0;
	localparam [1:0] FOP_SUB = 2'd1;
	localparam [1:0] FOP_MUL = 2'd2;
	localparam [1:0] FOP_DIV = 2'd3;
	localparam [31:0] AW = 34;
	function automatic [5:0] msb_idx34;
		input reg [33:0] v;
		reg [5:0] r;
		begin
			r = 6'd0;
			begin : sv2v_autoblock_1
				reg signed [31:0] i;
				for (i = 0; i < AW; i = i + 1)
					if (v[i])
						r = i[5:0];
			end
			msb_idx34 = r;
		end
	endfunction
	function automatic [31:0] fpu_add;
		input reg [31:0] av;
		input reg [31:0] bv;
		input reg sub_op;
		reg sa;
		reg sb;
		reg sbs;
		reg big_a;
		reg sign_r;
		reg [7:0] ea;
		reg [7:0] eb;
		reg [7:0] big_e;
		reg [7:0] delta;
		reg [22:0] fa;
		reg [22:0] fb;
		reg [22:0] fr;
		reg a_nan;
		reg b_nan;
		reg a_inf;
		reg b_inf;
		reg a_z;
		reg b_z;
		reg [33:0] fa_w;
		reg [33:0] fb_w;
		reg [33:0] norm;
		reg [AW:0] fsum;
		reg [5:0] top;
		reg [15:0] sh_l;
		reg [10:0] e9;
		reg g;
		reg s;
		reg inc;
		reg fc;
		reg [0:1] _sv2v_jump;
		begin
			_sv2v_jump = 2'b00;
			sa = av[31];
			ea = av[30:23];
			fa = av[22:0];
			sb = bv[31];
			eb = bv[30:23];
			fb = bv[22:0];
			sbs = sb ^ sub_op;
			a_nan = (ea == 8'hff) && (fa != 23'd0);
			b_nan = (eb == 8'hff) && (fb != 23'd0);
			a_inf = (ea == 8'hff) && (fa == 23'd0);
			b_inf = (eb == 8'hff) && (fb == 23'd0);
			a_z = (ea == 8'h00) && (fa == 23'd0);
			b_z = (eb == 8'h00) && (fb == 23'd0);
			if (a_nan) begin
				fpu_add = av;
				_sv2v_jump = 2'b11;
			end
			if (_sv2v_jump == 2'b00) begin
				if (b_nan) begin
					fpu_add = bv;
					_sv2v_jump = 2'b11;
				end
				if (_sv2v_jump == 2'b00) begin
					if ((a_inf && b_inf) && (sa != sbs)) begin
						fpu_add = 32'h7fc00000;
						_sv2v_jump = 2'b11;
					end
					if (_sv2v_jump == 2'b00) begin
						if (a_inf) begin
							fpu_add = av;
							_sv2v_jump = 2'b11;
						end
						if (_sv2v_jump == 2'b00) begin
							if (b_inf) begin
								fpu_add = {sbs, 31'h7f800000};
								_sv2v_jump = 2'b11;
							end
							if (_sv2v_jump == 2'b00) begin
								if (a_z && b_z) begin
									fpu_add = 32'h00000000;
									_sv2v_jump = 2'b11;
								end
								if (_sv2v_jump == 2'b00) begin
									if (a_z) begin
										fpu_add = {sbs, eb, fb};
										_sv2v_jump = 2'b11;
									end
									if (_sv2v_jump == 2'b00) begin
										if (b_z) begin
											fpu_add = av;
											_sv2v_jump = 2'b11;
										end
										if (_sv2v_jump == 2'b00) begin
											big_a = (ea > eb) || ((ea == eb) && (fa >= fb));
											big_e = (big_a ? ea : eb);
											fa_w = {1'b1, fa, 10'd0};
											fb_w = {1'b1, fb, 10'd0};
											delta = (big_a ? ea - eb : eb - ea);
											if (delta != 8'd0) begin
												if (delta >= 8'd34) begin
													if (big_a)
														fb_w = 34'h000000001;
													else
														fa_w = 34'h000000001;
												end
												else begin
													sh_l = 16'd34 - {8'd0, delta};
													if (big_a)
														fb_w = (fb_w >> delta) | {33'd0, |(fb_w << sh_l)};
													else
														fa_w = (fa_w >> delta) | {33'd0, |(fa_w << sh_l)};
												end
											end
											if (sa == sbs) begin
												fsum = {1'b0, fa_w} + {1'b0, fb_w};
												sign_r = sa;
											end
											else if (big_a) begin
												fsum = {1'b0, fa_w} - {1'b0, fb_w};
												sign_r = sa;
											end
											else begin
												fsum = {1'b0, fb_w} - {1'b0, fa_w};
												sign_r = sbs;
											end
											if (fsum == {35 {1'sb0}}) begin
												fpu_add = 32'h00000000;
												_sv2v_jump = 2'b11;
											end
											if (_sv2v_jump == 2'b00) begin
												if (fsum[AW]) begin
													norm = fsum[AW:1];
													e9 = {3'b000, big_e} + 11'd1;
													s = fsum[0] || |norm[8:0];
												end
												else begin
													top = msb_idx34(fsum[33:0]);
													norm = fsum[33:0] << (6'd33 - top);
													e9 = ({3'b000, big_e} + {5'b00000, top}) - 11'd33;
													s = |norm[8:0];
												end
												fr = norm[32:10];
												g = norm[9];
												inc = g && (s || fr[0]);
												fc = inc && (fr == 23'h7fffff);
												if (inc)
													fr = fr + 23'd1;
												if (fc)
													e9 = e9 + 11'd1;
												if (e9 >= 11'd512) begin
													fpu_add = {sign_r, 31'd0};
													_sv2v_jump = 2'b11;
												end
												if (_sv2v_jump == 2'b00) begin
													if (e9 >= 11'd255) begin
														fpu_add = {sign_r, 31'h7f800000};
														_sv2v_jump = 2'b11;
													end
													if (_sv2v_jump == 2'b00) begin
														if (e9 == 11'd0) begin
															fpu_add = {sign_r, 31'd0};
															_sv2v_jump = 2'b11;
														end
														if (_sv2v_jump == 2'b00) begin
															fpu_add = {sign_r, e9[7:0], fr};
															_sv2v_jump = 2'b11;
														end
													end
												end
											end
										end
									end
								end
							end
						end
					end
				end
			end
		end
	endfunction
	function automatic [31:0] fpu_mul;
		input reg [31:0] av;
		input reg [31:0] bv;
		reg sa;
		reg sb;
		reg sg;
		reg [7:0] ea;
		reg [7:0] eb;
		reg [22:0] fa;
		reg [22:0] fb;
		reg [22:0] fr;
		reg a_nan;
		reg b_nan;
		reg a_inf;
		reg b_inf;
		reg a_z;
		reg b_z;
		reg [47:0] prod;
		reg [23:0] f24;
		reg [10:0] e9;
		reg g;
		reg s;
		reg inc;
		reg fc;
		reg [0:1] _sv2v_jump;
		begin
			_sv2v_jump = 2'b00;
			sa = av[31];
			ea = av[30:23];
			fa = av[22:0];
			sb = bv[31];
			eb = bv[30:23];
			fb = bv[22:0];
			a_nan = (ea == 8'hff) && (fa != 23'd0);
			b_nan = (eb == 8'hff) && (fb != 23'd0);
			a_inf = (ea == 8'hff) && (fa == 23'd0);
			b_inf = (eb == 8'hff) && (fb == 23'd0);
			a_z = (ea == 8'h00) && (fa == 23'd0);
			b_z = (eb == 8'h00) && (fb == 23'd0);
			if (a_nan) begin
				fpu_mul = av;
				_sv2v_jump = 2'b11;
			end
			if (_sv2v_jump == 2'b00) begin
				if (b_nan) begin
					fpu_mul = bv;
					_sv2v_jump = 2'b11;
				end
				if (_sv2v_jump == 2'b00) begin
					sg = sa ^ sb;
					if (a_inf || b_inf) begin
						if (a_z || b_z) begin
							fpu_mul = {sg, 31'h7fc00000};
							_sv2v_jump = 2'b11;
						end
						if (_sv2v_jump == 2'b00) begin
							fpu_mul = {sg, 31'h7f800000};
							_sv2v_jump = 2'b11;
						end
					end
					if (_sv2v_jump == 2'b00) begin
						if (a_z || b_z) begin
							fpu_mul = {sg, 31'd0};
							_sv2v_jump = 2'b11;
						end
						if (_sv2v_jump == 2'b00) begin
							prod = {1'b1, fa} * {1'b1, fb};
							if (prod[47]) begin
								f24 = {prod[47], prod[46:24]};
								g = prod[23];
								s = |prod[22:0];
								e9 = ({3'b000, ea} + {3'b000, eb}) - 11'd126;
							end
							else begin
								f24 = {prod[46], prod[45:23]};
								g = prod[22];
								s = |prod[21:0];
								e9 = ({3'b000, ea} + {3'b000, eb}) - 11'd127;
							end
							fr = f24[22:0];
							inc = g && (s || fr[0]);
							fc = inc && (fr == 23'h7fffff);
							if (inc)
								fr = fr + 23'd1;
							if (fc)
								e9 = e9 + 11'd1;
							if (e9 >= 11'd512) begin
								fpu_mul = {sg, 31'd0};
								_sv2v_jump = 2'b11;
							end
							if (_sv2v_jump == 2'b00) begin
								if (e9 >= 11'd255) begin
									fpu_mul = {sg, 31'h7f800000};
									_sv2v_jump = 2'b11;
								end
								if (_sv2v_jump == 2'b00) begin
									if (e9 == 11'd0) begin
										fpu_mul = {sg, 31'd0};
										_sv2v_jump = 2'b11;
									end
									if (_sv2v_jump == 2'b00) begin
										fpu_mul = {sg, e9[7:0], fr};
										_sv2v_jump = 2'b11;
									end
								end
							end
						end
					end
				end
			end
		end
	endfunction
	function automatic [31:0] fpu_div;
		input reg [31:0] av;
		input reg [31:0] bv;
		reg sa;
		reg sb;
		reg sg;
		reg [7:0] ea;
		reg [7:0] eb;
		reg [22:0] fa;
		reg [22:0] fb;
		reg [22:0] fr;
		reg a_nan;
		reg b_nan;
		reg a_inf;
		reg b_inf;
		reg a_z;
		reg b_z;
		reg [63:0] num;
		reg [63:0] den;
		reg [63:0] rem;
		reg [63:0] q;
		reg [23:0] f24;
		reg [10:0] e9;
		reg g;
		reg s;
		reg inc;
		reg fc;
		reg [0:1] _sv2v_jump;
		begin
			_sv2v_jump = 2'b00;
			sa = av[31];
			ea = av[30:23];
			fa = av[22:0];
			sb = bv[31];
			eb = bv[30:23];
			fb = bv[22:0];
			a_nan = (ea == 8'hff) && (fa != 23'd0);
			b_nan = (eb == 8'hff) && (fb != 23'd0);
			a_inf = (ea == 8'hff) && (fa == 23'd0);
			b_inf = (eb == 8'hff) && (fb == 23'd0);
			a_z = (ea == 8'h00) && (fa == 23'd0);
			b_z = (eb == 8'h00) && (fb == 23'd0);
			if (a_nan) begin
				fpu_div = av;
				_sv2v_jump = 2'b11;
			end
			if (_sv2v_jump == 2'b00) begin
				if (b_nan) begin
					fpu_div = bv;
					_sv2v_jump = 2'b11;
				end
				if (_sv2v_jump == 2'b00) begin
					sg = sa ^ sb;
					if (a_inf && b_inf) begin
						fpu_div = 32'h7fc00000;
						_sv2v_jump = 2'b11;
					end
					if (_sv2v_jump == 2'b00) begin
						if (a_inf) begin
							fpu_div = {sg, 31'h7f800000};
							_sv2v_jump = 2'b11;
						end
						if (_sv2v_jump == 2'b00) begin
							if (b_inf) begin
								fpu_div = {sg, 31'd0};
								_sv2v_jump = 2'b11;
							end
							if (_sv2v_jump == 2'b00) begin
								if (b_z) begin
									if (a_z) begin
										fpu_div = 32'h7fc00000;
										_sv2v_jump = 2'b11;
									end
									if (_sv2v_jump == 2'b00) begin
										fpu_div = {sg, 31'h7f800000};
										_sv2v_jump = 2'b11;
									end
								end
								if (_sv2v_jump == 2'b00) begin
									if (a_z) begin
										fpu_div = {sg, 31'd0};
										_sv2v_jump = 2'b11;
									end
									if (_sv2v_jump == 2'b00) begin
										num = {15'h0001, fa, 26'd0};
										den = {41'h00000000001, fb};
										rem = 64'd0;
										q = 64'd0;
										begin : sv2v_autoblock_2
											reg signed [31:0] i;
											for (i = 63; i >= 0; i = i - 1)
												begin
													rem = (rem << 1) | {63'd0, num[i]};
													if (rem >= den) begin
														rem = rem - den;
														q[i] = 1'b1;
													end
												end
										end
										if (q[26]) begin
											f24 = q[26:3];
											g = q[2];
											s = (q[1] || q[0]) || (rem != 64'd0);
											e9 = ({3'b000, ea} - {3'b000, eb}) + 11'd127;
										end
										else begin
											f24 = q[25:2];
											g = q[1];
											s = q[0] || (rem != 64'd0);
											e9 = ({3'b000, ea} - {3'b000, eb}) + 11'd126;
										end
										fr = f24[22:0];
										inc = g && (s || fr[0]);
										fc = inc && (fr == 23'h7fffff);
										if (inc)
											fr = fr + 23'd1;
										if (fc)
											e9 = e9 + 11'd1;
										if (e9 >= 11'd512) begin
											fpu_div = {sg, 31'd0};
											_sv2v_jump = 2'b11;
										end
										if (_sv2v_jump == 2'b00) begin
											if (e9 >= 11'd255) begin
												fpu_div = {sg, 31'h7f800000};
												_sv2v_jump = 2'b11;
											end
											if (_sv2v_jump == 2'b00) begin
												if (e9 == 11'd0) begin
													fpu_div = {sg, 31'd0};
													_sv2v_jump = 2'b11;
												end
												if (_sv2v_jump == 2'b00) begin
													fpu_div = {sg, e9[7:0], fr};
													_sv2v_jump = 2'b11;
												end
											end
										end
									end
								end
							end
						end
					end
				end
			end
		end
	endfunction
	function automatic [31:0] fpu_exec;
		input reg [1:0] opc;
		input reg [31:0] av;
		input reg [31:0] bv;
		case (opc)
			FOP_ADD: fpu_exec = fpu_add(av, bv, 1'b0);
			FOP_SUB: fpu_exec = fpu_add(av, bv, 1'b1);
			FOP_MUL: fpu_exec = fpu_mul(av, bv);
			default: fpu_exec = fpu_div(av, bv);
		endcase
	endfunction
	reg [102:0] s0;
	reg [102:0] s1;
	reg [102:0] s2;
	reg [102:0] s3;
	always @(posedge clk or negedge rst_n)
		if (!rst_n)
			s0 <= 1'sb0;
		else begin
			s0[101] <= 1'b0;
			if (go && lane_en[0]) begin
				s0[102] <= 1'b1;
				s0[98-:3] <= 3'd0;
				s0[100-:2] <= op[1:0];
				s0[95-:32] <= a0;
				s0[63-:32] <= b0;
				s0[31-:32] <= 32'h00000000;
			end
			else if (s0[102]) begin
				if (s0[98-:3] == 3'd4) begin
					s0[102] <= 1'b0;
					s0[101] <= 1'b1;
					s0[31-:32] <= fpu_exec(s0[100-:2], s0[95-:32], s0[63-:32]);
				end
				else
					s0[98-:3] <= s0[98-:3] + 3'd1;
			end
		end
	always @(posedge clk or negedge rst_n)
		if (!rst_n)
			s1 <= 1'sb0;
		else begin
			s1[101] <= 1'b0;
			if (go && lane_en[1]) begin
				s1[102] <= 1'b1;
				s1[98-:3] <= 3'd0;
				s1[100-:2] <= op[1:0];
				s1[95-:32] <= a1;
				s1[63-:32] <= b1;
				s1[31-:32] <= 32'h00000000;
			end
			else if (s1[102]) begin
				if (s1[98-:3] == 3'd4) begin
					s1[102] <= 1'b0;
					s1[101] <= 1'b1;
					s1[31-:32] <= fpu_exec(s1[100-:2], s1[95-:32], s1[63-:32]);
				end
				else
					s1[98-:3] <= s1[98-:3] + 3'd1;
			end
		end
	always @(posedge clk or negedge rst_n)
		if (!rst_n)
			s2 <= 1'sb0;
		else begin
			s2[101] <= 1'b0;
			if (go && lane_en[2]) begin
				s2[102] <= 1'b1;
				s2[98-:3] <= 3'd0;
				s2[100-:2] <= op[1:0];
				s2[95-:32] <= a2;
				s2[63-:32] <= b2;
				s2[31-:32] <= 32'h00000000;
			end
			else if (s2[102]) begin
				if (s2[98-:3] == 3'd4) begin
					s2[102] <= 1'b0;
					s2[101] <= 1'b1;
					s2[31-:32] <= fpu_exec(s2[100-:2], s2[95-:32], s2[63-:32]);
				end
				else
					s2[98-:3] <= s2[98-:3] + 3'd1;
			end
		end
	always @(posedge clk or negedge rst_n)
		if (!rst_n)
			s3 <= 1'sb0;
		else begin
			s3[101] <= 1'b0;
			if (go && lane_en[3]) begin
				s3[102] <= 1'b1;
				s3[98-:3] <= 3'd0;
				s3[100-:2] <= op[1:0];
				s3[95-:32] <= a3;
				s3[63-:32] <= b3;
				s3[31-:32] <= 32'h00000000;
			end
			else if (s3[102]) begin
				if (s3[98-:3] == 3'd4) begin
					s3[102] <= 1'b0;
					s3[101] <= 1'b1;
					s3[31-:32] <= fpu_exec(s3[100-:2], s3[95-:32], s3[63-:32]);
				end
				else
					s3[98-:3] <= s3[98-:3] + 3'd1;
			end
		end
	assign y0 = s0[31-:32];
	assign y1 = s1[31-:32];
	assign y2 = s2[31-:32];
	assign y3 = s3[31-:32];
	assign busy = ((s0[102] || s1[102]) || s2[102]) || s3[102];
	assign done = ((s0[101] || s1[101]) || s2[101]) || s3[101];
endmodule
module ember_core (
	clk,
	rst_n,
	csr_we,
	csr_addr,
	csr_wdata,
	kick,
	cxa_we,
	cxa_addr,
	cxa_wdata,
	cxa_be,
	cxa_req,
	cxa_rdata,
	ixa_req,
	ixa_addr,
	ixa_rdata,
	busy
);
	reg _sv2v_0;
	input wire clk;
	input wire rst_n;
	input wire csr_we;
	input wire [1:0] csr_addr;
	input wire [31:0] csr_wdata;
	input wire kick;
	output reg cxa_we;
	output reg [31:0] cxa_addr;
	output reg [31:0] cxa_wdata;
	output reg [3:0] cxa_be;
	output reg cxa_req;
	input wire [31:0] cxa_rdata;
	output reg ixa_req;
	output reg [31:0] ixa_addr;
	input wire [31:0] ixa_rdata;
	output wire busy;
	localparam [31:0] NT = 4;
	localparam [31:0] SAW = 10;
	reg [31:0] code_base_q;
	reg [7:0] nblk_q;
	wire csr_code_we = csr_we && (csr_addr == 2'd0);
	wire csr_nblk_we = csr_we && (csr_addr == 2'd1);
	always @(posedge clk or negedge rst_n)
		if (!rst_n) begin
			code_base_q <= 32'h00000000;
			nblk_q <= 8'd1;
		end
		else begin
			if (csr_code_we)
				code_base_q <= {csr_wdata[31:2], 2'b00};
			if (csr_nblk_we && (csr_wdata[7:0] != 8'd0))
				nblk_q <= csr_wdata[7:0];
		end
	reg [3:0] T [0:3];
	reg [7:0] fpc [0:3];
	reg [31:0] gpr [0:3][0:15];
	reg [3:0] waitv;
	reg [3:0] barv;
	reg [3:0] ibuf_v;
	reg [31:0] ibuf_w [0:3];
	reg [31:0] smem [0:1023];
	reg [3:0] f_lane_en;
	reg [3:0] f_op;
	reg [31:0] f_a0;
	reg [31:0] f_b0;
	reg [31:0] f_a1;
	reg [31:0] f_b1;
	reg [31:0] f_a2;
	reg [31:0] f_b2;
	reg [31:0] f_a3;
	reg [31:0] f_b3;
	reg f_go;
	wire [31:0] f_y0;
	wire [31:0] f_y1;
	wire [31:0] f_y2;
	wire [31:0] f_y3;
	wire f_busy;
	wire f_done;
	ember_fpu4 u_fpu(
		.clk(clk),
		.rst_n(rst_n),
		.lane_en(f_lane_en),
		.op(f_op),
		.a0(f_a0),
		.b0(f_b0),
		.a1(f_a1),
		.b1(f_b1),
		.a2(f_a2),
		.b2(f_b2),
		.a3(f_a3),
		.b3(f_b3),
		.go(f_go),
		.y0(f_y0),
		.y1(f_y1),
		.y2(f_y2),
		.y3(f_y3),
		.busy(f_busy),
		.done(f_done)
	);
	reg [1:0] st;
	reg running;
	assign busy = running;
	reg [7:0] blk;
	reg [19:0] budget;
	reg ix_pend;
	reg ix_req_cyc;
	reg [1:0] ix_tid;
	reg flush_req;
	reg [1:0] flush_tid;
	reg ld_pend;
	reg [31:0] ld_addr_q;
	reg [1:0] ld_tid_q;
	reg [3:0] ld_rd_q;
	reg cx_pend;
	reg cx_req_cyc;
	reg dr_valid;
	reg [1:0] dr_tid;
	reg [3:0] dr_rd;
	reg [31:0] dr_word;
	reg fp_pend;
	reg [1:0] fp_tid;
	reg [3:0] fp_rd;
	reg [1:0] bar_count;
	reg exec_en;
	reg [1:0] exec_tid;
	always @(*) begin
		if (_sv2v_0)
			;
		exec_en = 1'b0;
		exec_tid = 2'd0;
		begin : sv2v_autoblock_1
			reg signed [31:0] t;
			for (t = 3; t >= 0; t = t - 1)
				if ((((st == 2'd1) && ibuf_v[t]) && !waitv[t]) && !barv[t]) begin
					exec_en = 1'b1;
					exec_tid = t[1:0];
				end
		end
	end
	reg [1:0] pick_tid;
	reg pick_en;
	always @(*) begin
		if (_sv2v_0)
			;
		pick_en = 1'b0;
		pick_tid = 2'd0;
		begin : sv2v_autoblock_2
			reg signed [31:0] t;
			for (t = 3; t >= 0; t = t - 1)
				if (((st == 2'd1) && !T[t][3]) && !ibuf_v[t]) begin
					pick_en = 1'b1;
					pick_tid = t[1:0];
				end
		end
	end
	wire [7:0] i_op = ibuf_w[exec_tid][31:24];
	wire [3:0] i_rd = ibuf_w[exec_tid][23:20];
	wire [3:0] i_ra = ibuf_w[exec_tid][19:16];
	wire [3:0] i_rb = ibuf_w[exec_tid][15:12];
	wire [11:0] i_imm = ibuf_w[exec_tid][11:0];
	wire signed [31:0] i_sx12 = {{20 {i_imm[11]}}, i_imm};
	wire signed [8:0] i_sx9 = i_imm[8:0];
	wire signed [10:0] i_sx11 = i_imm[10:0];
	wire [31:0] rav = gpr[exec_tid][i_ra];
	wire [31:0] rbv = gpr[exec_tid][i_rb];
	localparam [31:0] ember_pkg_FRAME_H_PX = 240;
	localparam [31:0] ember_pkg_FRAME_W_PX = 320;
	localparam [31:0] ember_pkg_FB0_BASE = 32'h00000000;
	localparam [31:0] ember_pkg_FB_STRIDE = 640;
	localparam [31:0] ember_pkg_ZBUF_BASE = ember_pkg_FB0_BASE + (ember_pkg_FB_STRIDE * ember_pkg_FRAME_H_PX);
	localparam [31:0] ember_pkg_TEX_BASE = ember_pkg_ZBUF_BASE + ((ember_pkg_FRAME_W_PX * ember_pkg_FRAME_H_PX) * 2);
	localparam [31:0] ember_pkg_TEX_BYTES = 65536;
	localparam [31:0] ember_pkg_CMDBUF_BASE = ember_pkg_TEX_BASE + ember_pkg_TEX_BYTES;
	task automatic init_block;
		input reg [7:0] b;
		begin
			begin : sv2v_autoblock_3
				reg signed [31:0] t;
				for (t = 0; t < NT; t = t + 1)
					begin
						T[t][3] <= 1'b0;
						T[t][2-:3] <= 3'b000;
						fpc[t] <= 8'd0;
						gpr[t][12] <= ember_pkg_CMDBUF_BASE;
						gpr[t][13] <= {24'h000000, b};
						gpr[t][14] <= {24'h000000, nblk_q};
						gpr[t][15] <= {30'h00000000, t[1:0]};
					end
			end
			ibuf_v <= 1'sb0;
			waitv <= 1'sb0;
			barv <= 1'sb0;
			bar_count <= 2'd0;
			budget <= 1'sb0;
		end
	endtask
	localparam [31:0] ember_pkg_CP_BASE = 32'h00000000;
	localparam [31:0] ember_pkg_CP_WINDOW_BYTES = 4096;
	localparam [31:0] ember_pkg_VRAM_BASE = ember_pkg_CP_BASE + ember_pkg_CP_WINDOW_BYTES;
	function automatic [31:0] sv2v_cast_32;
		input reg [31:0] inp;
		sv2v_cast_32 = inp;
	endfunction
	function automatic [7:0] sv2v_cast_8;
		input reg [7:0] inp;
		sv2v_cast_8 = inp;
	endfunction
	always @(posedge clk or negedge rst_n)
		if (!rst_n) begin
			st <= 2'd0;
			running <= 1'b0;
			blk <= 8'd0;
			ibuf_v <= 1'sb0;
			ix_pend <= 1'b0;
			ix_req_cyc <= 1'b0;
			ix_tid <= 2'd0;
			flush_req <= 1'b0;
			flush_tid <= 2'd0;
			ld_pend <= 1'b0;
			ld_addr_q <= 32'h00000000;
			ld_tid_q <= 2'd0;
			ld_rd_q <= 4'd0;
			cx_pend <= 1'b0;
			cx_req_cyc <= 1'b0;
			dr_valid <= 1'b0;
			dr_tid <= 2'd0;
			dr_rd <= 4'd0;
			dr_word <= 32'h00000000;
			fp_pend <= 1'b0;
			fp_tid <= 2'd0;
			fp_rd <= 4'd0;
			bar_count <= 2'd0;
			budget <= 1'sb0;
			f_lane_en <= 4'h0;
			f_go <= 1'b0;
			f_op <= 4'h0;
			f_a0 <= 1'sb0;
			f_b0 <= 1'sb0;
			f_a1 <= 1'sb0;
			f_b1 <= 1'sb0;
			f_a2 <= 1'sb0;
			f_b2 <= 1'sb0;
			f_a3 <= 1'sb0;
			f_b3 <= 1'sb0;
			cxa_we <= 1'b0;
			cxa_addr <= 32'h00000000;
			cxa_wdata <= 32'h00000000;
			cxa_be <= 4'h0;
			cxa_req <= 1'b0;
			ixa_req <= 1'b0;
			ixa_addr <= 32'h00000000;
			waitv <= 4'h0;
			barv <= 4'h0;
			begin : sv2v_autoblock_4
				reg signed [31:0] t;
				for (t = 0; t < NT; t = t + 1)
					begin
						T[t] <= 1'sb0;
						fpc[t] <= 8'd0;
						ibuf_w[t] <= 32'h00000000;
						begin : sv2v_autoblock_5
							reg signed [31:0] r;
							for (r = 0; r < 16; r = r + 1)
								gpr[t][r] <= 32'h00000000;
						end
					end
			end
		end
		else begin
			cxa_we <= 1'b0;
			cxa_req <= 1'b0;
			ixa_req <= 1'b0;
			f_go <= 1'b0;
			if (ix_pend && !ix_req_cyc) begin
				ix_pend <= 1'b0;
				if (flush_req && (ix_tid == flush_tid))
					flush_req <= 1'b0;
				else begin
					ibuf_v[ix_tid] <= 1'b1;
					ibuf_w[ix_tid] <= ixa_rdata;
				end
			end
			else if (flush_req)
				flush_req <= 1'b0;
			if (ix_req_cyc)
				ix_req_cyc <= 1'b0;
			if (cx_pend && !cx_req_cyc) begin
				cx_pend <= 1'b0;
				dr_valid <= 1'b1;
				dr_tid <= ld_tid_q;
				dr_rd <= ld_rd_q;
				dr_word <= cxa_rdata;
			end
			if (cx_req_cyc)
				cx_req_cyc <= 1'b0;
			if (dr_valid) begin
				dr_valid <= 1'b0;
				gpr[dr_tid][dr_rd] <= dr_word;
				waitv[dr_tid] <= 1'b0;
			end
			if (fp_pend && f_done) begin
				gpr[fp_tid][fp_rd] <= f_y0;
				waitv[fp_tid] <= 1'b0;
				fp_pend <= 1'b0;
			end
			case (st)
				2'd0: begin
					running <= 1'b0;
					if (kick) begin
						running <= 1'b1;
						blk <= 8'd0;
						init_block(8'd0);
						st <= 2'd1;
					end
				end
				2'd1: begin
					budget <= budget + 20'd1;
					if (budget == 20'hfffff) begin
						begin : sv2v_autoblock_6
							reg signed [31:0] t;
							for (t = 0; t < NT; t = t + 1)
								T[t][3] <= 1'b1;
						end
						st <= 2'd2;
					end
					else begin
						if (exec_en) begin
							ibuf_v[exec_tid] <= 1'b0;
							if (T[exec_tid][3])
								;
							else
								case (i_op)
									8'h01: gpr[exec_tid][i_rd] <= rav + rbv;
									8'h02: gpr[exec_tid][i_rd] <= rav - rbv;
									8'h03: gpr[exec_tid][i_rd] <= $signed(rav) * $signed(rbv);
									8'h04: gpr[exec_tid][i_rd] <= (rbv == 32'h00000000 ? 32'h00000000 : $signed(rav) / $signed(rbv));
									8'h05: gpr[exec_tid][i_rd] <= rav & rbv;
									8'h06: gpr[exec_tid][i_rd] <= rav | rbv;
									8'h07: gpr[exec_tid][i_rd] <= rav ^ rbv;
									8'h08: gpr[exec_tid][i_rd] <= rav << rbv[4:0];
									8'h09: gpr[exec_tid][i_rd] <= rav >> rbv[4:0];
									8'h0a: begin : sv2v_autoblock_7
										reg [31:0] d;
										d = rav - rbv;
										T[exec_tid][2-:3] <= {d[31], d == 32'h00000000, !d[31] && (d != 32'h00000000)};
									end
									8'h0b: gpr[exec_tid][i_rd] <= ($signed(rav) < $signed(rbv) ? rav : rbv);
									8'h0c: gpr[exec_tid][i_rd] <= ($signed(rav) > $signed(rbv) ? rav : rbv);
									8'h0d, 8'h0e: gpr[exec_tid][i_rd] <= {16'h0000, i_ra, i_imm};
									8'h40, 8'h41, 8'h42, 8'h43: begin
										f_lane_en <= 4'b0001;
										f_op <= {2'b00, i_op[1:0]};
										f_a0 <= rav;
										f_b0 <= rbv;
										f_go <= 1'b1;
										fp_pend <= 1'b1;
										fp_tid <= exec_tid;
										fp_rd <= i_rd;
										waitv[exec_tid] <= 1'b1;
									end
									8'h10: begin
										ld_pend <= 1'b1;
										ld_addr_q <= sv2v_cast_32(ember_pkg_VRAM_BASE + (rav + i_sx12));
										ld_tid_q <= exec_tid;
										ld_rd_q <= i_rd;
										waitv[exec_tid] <= 1'b1;
									end
									8'h11: begin
										cxa_we <= 1'b1;
										cxa_be <= 4'hf;
										cxa_addr <= sv2v_cast_32(ember_pkg_VRAM_BASE + (rav + i_sx12));
										cxa_wdata <= gpr[exec_tid][i_rd];
									end
									8'h12: gpr[exec_tid][i_rd] <= smem[(rav + i_sx12) & 1023];
									8'h13: smem[(rav + i_sx12) & 1023] <= gpr[exec_tid][i_rd];
									8'h14: smem[(rav + i_sx12) & 1023] <= smem[(rav + i_sx12) & 1023] + gpr[exec_tid][i_rd];
									8'h15:
										if ($signed(gpr[exec_tid][i_rd]) > $signed(smem[(rav + i_sx12) & 1023]))
											smem[(rav + i_sx12) & 1023] <= gpr[exec_tid][i_rd];
									8'h20:
										if ((T[exec_tid][2-:3] & i_rd[2:0]) != 3'b000) begin
											fpc[exec_tid] <= sv2v_cast_8(fpc[exec_tid] + i_sx9);
											flush_req <= 1'b1;
											flush_tid <= exec_tid;
										end
									8'h21, 8'h24: begin
										gpr[exec_tid][(i_op == 8'h21 ? i_rd : 4'd15)] <= {24'h000000, fpc[exec_tid]};
										fpc[exec_tid] <= sv2v_cast_8(fpc[exec_tid] + i_sx11);
										flush_req <= 1'b1;
										flush_tid <= exec_tid;
									end
									8'h22: begin
										fpc[exec_tid] <= gpr[exec_tid][i_ra][7:0];
										flush_req <= 1'b1;
										flush_tid <= exec_tid;
									end
									8'h23: begin
										fpc[exec_tid] <= gpr[exec_tid][15][7:0];
										flush_req <= 1'b1;
										flush_tid <= exec_tid;
									end
									8'h25: begin
										barv[exec_tid] <= 1'b1;
										bar_count <= bar_count + 2'd1;
										if (bar_count == 2'd3) begin
											barv <= 4'h0;
											bar_count <= 2'd0;
										end
									end
									8'hff: T[exec_tid][3] <= 1'b1;
									default:
										;
								endcase
						end
						if (ld_pend && !cx_pend) begin
							ld_pend <= 1'b0;
							cx_pend <= 1'b1;
							cx_req_cyc <= 1'b1;
							cxa_req <= 1'b1;
							cxa_addr <= ld_addr_q;
						end
						if ((!ix_pend && pick_en) && !(flush_req && (flush_tid == pick_tid))) begin
							ix_pend <= 1'b1;
							ix_req_cyc <= 1'b1;
							ix_tid <= pick_tid;
							ixa_req <= 1'b1;
							ixa_addr <= (ember_pkg_VRAM_BASE + code_base_q) + {22'h000000, fpc[pick_tid], 2'b00};
							fpc[pick_tid] <= fpc[pick_tid] + 5'd1;
						end
						if ((((((((!exec_en && !pick_en) && !ix_pend) && !cx_pend) && !dr_valid) && !fp_pend) && !ld_pend) && (waitv == {4 {1'sb0}})) && (barv == {4 {1'sb0}}))
							st <= 2'd2;
					end
				end
				2'd2:
					if ((blk + 8'd1) >= nblk_q) begin
						running <= 1'b0;
						st <= 2'd3;
					end
					else begin
						blk <= blk + 8'd1;
						init_block(blk + 8'd1);
						st <= 2'd1;
					end
				2'd3: begin
					running <= 1'b0;
					st <= 2'd0;
				end
				default: st <= 2'd0;
			endcase
		end
	wire _unused = ^{f_y1, f_y2, f_y3, f_busy};
	initial _sv2v_0 = 0;
endmodule