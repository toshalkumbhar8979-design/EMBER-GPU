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