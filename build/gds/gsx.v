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
module ember_gsx (
	clk,
	rst_n,
	csr_we,
	csr_addr,
	csr_wdata,
	kick,
	gxa_we,
	gxa_addr,
	gxa_wdata,
	gxa_be,
	gxa_req,
	gxa_rdata,
	busy
);
	input wire clk;
	input wire rst_n;
	input wire csr_we;
	input wire [1:0] csr_addr;
	input wire [31:0] csr_wdata;
	input wire kick;
	output reg gxa_we;
	output reg [31:0] gxa_addr;
	output reg [31:0] gxa_wdata;
	output reg [3:0] gxa_be;
	output reg gxa_req;
	input wire [31:0] gxa_rdata;
	output wire busy;
	reg [31:0] mata [0:15];
	reg [31:0] vtx [0:14];
	reg [31:0] col [0:2];
	reg [3:0] mata_ptr;
	reg [3:0] vtx_ptr;
	reg [1:0] col_ptr;
	reg [7:0] tri_count;
	reg cfg_overw;
	reg cfg_blend;
	reg cfg_ztest;
	reg cfg_tex;
	reg [7:0] cfg_page;
	wire cfg_we = csr_we && (csr_addr == 2'd3);
	wire cfg_cnt_we = cfg_we && csr_wdata[31];
	wire cfg_mode_we = cfg_we && !csr_wdata[31];
	always @(posedge clk or negedge rst_n)
		if (!rst_n) begin
			mata_ptr <= 4'd0;
			vtx_ptr <= 4'd0;
			col_ptr <= 2'd0;
		end
		else if (csr_we)
			case (csr_addr)
				2'd0: mata_ptr <= mata_ptr + 4'd1;
				2'd1: vtx_ptr <= (vtx_ptr == 4'd14 ? 4'd0 : vtx_ptr + 4'd1);
				2'd2: col_ptr <= (col_ptr == 2'd2 ? 2'd0 : col_ptr + 2'd1);
				default:
					;
			endcase
	always @(posedge clk)
		if (csr_we)
			case (csr_addr)
				2'd0: mata[mata_ptr] <= csr_wdata;
				2'd1: vtx[vtx_ptr] <= csr_wdata;
				2'd2: col[col_ptr] <= csr_wdata;
				default:
					;
			endcase
	reg busy_r;
	reg [4:0] st;
	always @(posedge clk or negedge rst_n)
		if (!rst_n) begin
			tri_count <= 8'd0;
			cfg_overw <= 1'b0;
			cfg_blend <= 1'b0;
			cfg_ztest <= 1'b0;
			cfg_tex <= 1'b0;
			cfg_page <= 8'd0;
		end
		else begin
			if (cfg_cnt_we)
				tri_count <= csr_wdata[7:0];
			else if ((busy_r && (st == 5'd6)) && !cfg_overw)
				tri_count <= tri_count + 8'd1;
			if (cfg_mode_we) begin
				cfg_overw <= csr_wdata[29];
				cfg_blend <= csr_wdata[26];
				cfg_ztest <= csr_wdata[24];
				cfg_tex <= csr_wdata[27];
				cfg_page <= csr_wdata[23:16];
			end
		end
	initial begin : sv2v_autoblock_1
		reg signed [31:0] r;
		for (r = 0; r < 4; r = r + 1)
			begin : sv2v_autoblock_2
				reg signed [31:0] c;
				for (c = 0; c < 4; c = c + 1)
					mata[(4 * r) + c] = (r == c ? 32'h3f800000 : 32'h00000000);
			end
	end
	localparam [31:0] ember_pkg_RTR_CMD_WORDS = 19;
	wire [31:0] tri_off = {24'd0, tri_count} * 76;
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
	ember_fpu4 u_fpu4(
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
	function automatic [31:0] fp_to_q22;
		input reg [31:0] fb;
		reg [7:0] e;
		reg [31:0] i24;
		reg [31:0] sh;
		begin
			e = fb[30:23];
			i24 = {9'h001, fb[22:0]};
			if (fb[30:0] == 31'h00000000)
				fp_to_q22 = 32'h00000000;
			else if (e >= 8'd136)
				fp_to_q22 = (fb[31] ? 32'h80000000 : 32'h7fffffff);
			else if (e >= 8'd128) begin
				sh = i24 << (e - 8'd128);
				fp_to_q22 = sh;
			end
			else begin
				sh = i24 >> (8'd128 - e);
				fp_to_q22 = sh;
			end
			if (fb[31] && |fp_to_q22)
				fp_to_q22 = ~fp_to_q22 + 32'd1;
		end
	endfunction
	function automatic [15:0] sv2v_cast_16;
		input reg [15:0] inp;
		sv2v_cast_16 = inp;
	endfunction
	function automatic [15:0] fp_to_z16;
		input reg [31:0] fb;
		reg [7:0] e;
		reg [39:0] prod;
		begin
			e = fb[30:23];
			if (fb[31] || (fb[30:0] == 31'h00000000))
				fp_to_z16 = 16'h0000;
			else if (e >= 8'd127)
				fp_to_z16 = 16'hffff;
			else begin
				prod = {1'b1, fb[22:0]} * 16'd65535;
				fp_to_z16 = sv2v_cast_16(prod >> (8'd150 - e));
			end
		end
	endfunction
	function automatic [31:0] sat22;
		input reg signed [31:0] v;
		if (v > 32'sd2147483000)
			sat22 = 32'sd2147483000;
		else if (v < -32'sd2147483000)
			sat22 = -32'sd2147483000;
		else
			sat22 = v;
	endfunction
	assign busy = busy_r;
	reg [1:0] vidx;
	reg [1:0] kstep;
	reg phase;
	reg [31:0] acc0;
	reg [31:0] acc1;
	reg [31:0] acc2;
	reg [31:0] acc3;
	reg [31:0] w_in;
	reg [4:0] eidx;
	reg [31:0] emit_base;
	reg [31:0] px [0:2];
	reg [31:0] py [0:2];
	reg [15:0] pz [0:2];
	reg [31:0] pc [0:2];
	reg [31:0] pu [0:2];
	reg [31:0] pv [0:2];
	localparam [31:0] ember_pkg_FRAME_H_PX = 240;
	localparam [31:0] ember_pkg_FRAME_W_PX = 320;
	localparam [31:0] ember_pkg_FB0_BASE = 32'h00000000;
	localparam [31:0] ember_pkg_FB_STRIDE = 640;
	localparam [31:0] ember_pkg_ZBUF_BASE = ember_pkg_FB0_BASE + (ember_pkg_FB_STRIDE * ember_pkg_FRAME_H_PX);
	localparam [31:0] ember_pkg_TEX_BASE = ember_pkg_ZBUF_BASE + ((ember_pkg_FRAME_W_PX * ember_pkg_FRAME_H_PX) * 2);
	localparam [31:0] ember_pkg_TEX_BYTES = 65536;
	localparam [31:0] ember_pkg_CMDBUF_BASE = ember_pkg_TEX_BASE + ember_pkg_TEX_BYTES;
	localparam [31:0] ember_pkg_RTR_CMDQ_BASE = ember_pkg_CMDBUF_BASE;
	localparam [31:0] ember_pkg_CP_BASE = 32'h00000000;
	localparam [31:0] ember_pkg_CP_WINDOW_BYTES = 4096;
	localparam [31:0] ember_pkg_VRAM_BASE = ember_pkg_CP_BASE + ember_pkg_CP_WINDOW_BYTES;
	always @(posedge clk or negedge rst_n)
		if (!rst_n) begin
			st <= 5'd0;
			busy_r <= 1'b0;
			vidx <= 2'd0;
			kstep <= 2'd0;
			phase <= 1'b0;
			w_in <= 32'h3f800000;
			acc0 <= 32'h00000000;
			acc1 <= 32'h00000000;
			acc2 <= 32'h00000000;
			acc3 <= 32'h00000000;
			eidx <= 5'd0;
			emit_base <= 32'h00000000;
			f_lane_en <= 4'h0;
			f_go <= 1'b0;
			f_op <= 4'h0;
			f_a0 <= 32'h00000000;
			f_b0 <= 32'h00000000;
			f_a1 <= 32'h00000000;
			f_b1 <= 32'h00000000;
			f_a2 <= 32'h00000000;
			f_b2 <= 32'h00000000;
			f_a3 <= 32'h00000000;
			f_b3 <= 32'h00000000;
			gxa_we <= 1'b0;
			gxa_addr <= 32'h00000000;
			gxa_wdata <= 32'h00000000;
			gxa_be <= 4'h0;
			gxa_req <= 1'b0;
			begin : sv2v_autoblock_3
				reg signed [31:0] i;
				for (i = 0; i < 3; i = i + 1)
					begin
						px[i] <= 32'h00000000;
						py[i] <= 32'h00000000;
						pz[i] <= 16'h0000;
						pc[i] <= 32'h00000000;
					end
			end
		end
		else begin
			f_go <= 1'b0;
			gxa_we <= 1'b0;
			case (st)
				5'd0: begin
					busy_r <= 1'b0;
					if (kick) begin
						busy_r <= 1'b1;
						vidx <= 2'd0;
						kstep <= 2'd0;
						phase <= 1'b0;
						acc0 <= 32'h00000000;
						acc1 <= 32'h00000000;
						acc2 <= 32'h00000000;
						acc3 <= 32'h00000000;
						eidx <= 5'd0;
						emit_base <= (ember_pkg_VRAM_BASE + ember_pkg_RTR_CMDQ_BASE) + tri_off;
						st <= 5'd1;
					end
				end
				5'd1: begin
					f_lane_en <= 4'hf;
					f_go <= 1'b1;
					if (phase == 1'b0) begin
						f_op <= 4'd2;
						if (kstep == 2'd3) begin
							f_a0 <= mata[3];
							f_b0 <= 32'h3f800000;
							f_a1 <= mata[7];
							f_b1 <= 32'h3f800000;
							f_a2 <= mata[11];
							f_b2 <= 32'h3f800000;
							f_a3 <= mata[15];
							f_b3 <= 32'h3f800000;
						end
						else begin
							f_a0 <= mata[0 + kstep];
							f_b0 <= vtx[(5 * vidx) + kstep];
							f_a1 <= mata[4 + kstep];
							f_b1 <= vtx[(5 * vidx) + kstep];
							f_a2 <= mata[8 + kstep];
							f_b2 <= vtx[(5 * vidx) + kstep];
							f_a3 <= mata[12 + kstep];
							f_b3 <= vtx[(5 * vidx) + kstep];
						end
					end
					else begin
						f_op <= 4'd0;
						f_a0 <= acc0;
						f_b0 <= f_y0;
						f_a1 <= acc1;
						f_b1 <= f_y1;
						f_a2 <= acc2;
						f_b2 <= f_y2;
						f_a3 <= acc3;
						f_b3 <= f_y3;
					end
					st <= 5'd2;
				end
				5'd2:
					if (f_done) begin
						if (phase == 1'b0) begin
							phase <= 1'b1;
							st <= 5'd1;
						end
						else begin
							acc0 <= f_y0;
							acc1 <= f_y1;
							acc2 <= f_y2;
							acc3 <= f_y3;
							if (kstep == 2'd3)
								st <= 5'd3;
							else begin
								kstep <= kstep + 2'd1;
								phase <= 1'b0;
								st <= 5'd1;
							end
						end
					end
				5'd3: begin
					f_lane_en <= 4'hf;
					f_op <= 4'd3;
					f_a0 <= acc0;
					f_b0 <= acc3;
					f_a1 <= acc1;
					f_b1 <= acc3;
					f_a2 <= acc2;
					f_b2 <= acc3;
					f_a3 <= 32'h3f800000;
					f_b3 <= acc3;
					w_in <= acc3;
					f_go <= 1'b1;
					st <= 5'd4;
				end
				5'd4:
					if (f_done) begin
						px[vidx] <= sat22($signed(fp_to_q22(f_y0)));
						py[vidx] <= sat22($signed(fp_to_q22(f_y1)));
						pz[vidx] <= fp_to_z16(f_y2);
						pc[vidx] <= {1'b0, col[vidx][30:0]};
						pu[vidx] <= fp_to_q22(vtx[(5 * vidx) + 3]);
						pv[vidx] <= fp_to_q22(vtx[(5 * vidx) + 4]);
						st <= 5'd5;
					end
				5'd5:
					if (w_in[31] || (w_in[30:0] == 31'h00000000))
						st <= 5'd8;
					else if (vidx == 2'd2)
						st <= 5'd6;
					else begin
						vidx <= vidx + 2'd1;
						kstep <= 2'd0;
						phase <= 1'b0;
						acc0 <= 32'h00000000;
						acc1 <= 32'h00000000;
						acc2 <= 32'h00000000;
						acc3 <= 32'h00000000;
						st <= 5'd1;
					end
				5'd6: begin
					gxa_we <= 1'b1;
					gxa_be <= 4'hf;
					gxa_addr <= emit_base;
					gxa_wdata <= {19'h00000, cfg_page, 1'b0, cfg_tex, cfg_ztest, cfg_blend, 1'b1};
					eidx <= 5'd1;
					st <= 5'd7;
				end
				5'd7: begin
					gxa_we <= 1'b1;
					gxa_be <= 4'hf;
					gxa_addr <= emit_base + {25'h0000000, eidx, 2'b00};
					if (eidx <= 5'd6)
						case (eidx)
							5'd1: gxa_wdata <= px[0];
							5'd2: gxa_wdata <= py[0];
							5'd3: gxa_wdata <= px[1];
							5'd4: gxa_wdata <= py[1];
							5'd5: gxa_wdata <= px[2];
							default: gxa_wdata <= py[2];
						endcase
					else if (eidx <= 5'd9)
						case (eidx)
							5'd7: gxa_wdata <= {16'h0000, pz[0]};
							5'd8: gxa_wdata <= {16'h0000, pz[1]};
							default: gxa_wdata <= {16'h0000, pz[2]};
						endcase
					else if (eidx <= 5'd12)
						case (eidx)
							5'd10: gxa_wdata <= pc[0];
							5'd11: gxa_wdata <= pc[1];
							default: gxa_wdata <= pc[2];
						endcase
					else if (cfg_tex)
						case (eidx)
							5'd13: gxa_wdata <= pu[0];
							5'd14: gxa_wdata <= pv[0];
							5'd15: gxa_wdata <= pu[1];
							5'd16: gxa_wdata <= pv[1];
							5'd17: gxa_wdata <= pu[2];
							default: gxa_wdata <= pv[2];
						endcase
					else
						gxa_wdata <= 32'h00000000;
					if (eidx == 5'd18) begin
						eidx <= 5'd0;
						st <= 5'd8;
					end
					else
						eidx <= eidx + 5'd1;
				end
				5'd8:
					if (cfg_overw) begin
						busy_r <= 1'b0;
						st <= 5'd0;
					end
					else begin
						gxa_we <= 1'b1;
						gxa_be <= 4'hf;
						gxa_addr <= emit_base + 76;
						gxa_wdata <= 32'h00000000;
						busy_r <= 1'b0;
						st <= 5'd0;
					end
				default: begin
					st <= 5'd0;
					busy_r <= 1'b0;
				end
			endcase
		end
	wire _unused = ^gxa_rdata | f_busy;
endmodule