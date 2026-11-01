module _rtr_smul96 (
	a,
	b,
	q
);
	input wire signed [95:0] a;
	input wire signed [95:0] b;
	output wire signed [95:0] q;
	assign q = a * b;
endmodule
module _rtr_sdiv96 (
	num,
	den,
	q
);
	input wire signed [95:0] num;
	input wire signed [95:0] den;
	output wire signed [95:0] q;
	wire signed [117:0] n = {{22 {num[95]}}, num};
	wire signed [117:0] d = {{22 {den[95]}}, den};
	wire signed [117:0] qq = $signed(n <<< 22) / $signed(d);
	assign q = (den == 0 ? 96'sd0 : qq[95:0]);
endmodule
module ember_rtr_scan (
	clk,
	rst_n,
	start,
	t_blend,
	t_ztest,
	t_tex,
	t_dither,
	t_rgbmap,
	t_texpal,
	t_texpage,
	iwA,
	iwB,
	iwC,
	rA,
	rB,
	rC,
	gA,
	gB,
	gC,
	bA,
	bB,
	bC,
	zA,
	zB,
	zC,
	uA,
	uB,
	uC,
	vA,
	vB,
	vC,
	x_lo_i,
	x_hi_i,
	y_lo_i,
	y_hi_i,
	x0,
	y0,
	x1,
	y1,
	x2,
	y2,
	dx01,
	dy01,
	dx12,
	dy12,
	dx20,
	dy20,
	fpa_we,
	fpa_addr,
	fpa_wdata,
	fpa_be,
	fpa_req,
	fpa_rdata,
	fpa2_req,
	fpa2_addr,
	fpa2_rdata,
	busy,
	done
);
	input wire clk;
	input wire rst_n;
	input wire start;
	input wire t_blend;
	input wire t_ztest;
	input wire t_tex;
	input wire t_dither;
	input wire t_rgbmap;
	input wire t_texpal;
	input wire [7:0] t_texpage;
	input wire signed [63:0] iwA;
	input wire signed [63:0] iwB;
	input wire signed [63:0] iwC;
	input wire signed [63:0] rA;
	input wire signed [63:0] rB;
	input wire signed [63:0] rC;
	input wire signed [63:0] gA;
	input wire signed [63:0] gB;
	input wire signed [63:0] gC;
	input wire signed [63:0] bA;
	input wire signed [63:0] bB;
	input wire signed [63:0] bC;
	input wire signed [63:0] zA;
	input wire signed [63:0] zB;
	input wire signed [63:0] zC;
	input wire signed [63:0] uA;
	input wire signed [63:0] uB;
	input wire signed [63:0] uC;
	input wire signed [63:0] vA;
	input wire signed [63:0] vB;
	input wire signed [63:0] vC;
	input wire [15:0] x_lo_i;
	input wire [15:0] x_hi_i;
	input wire [15:0] y_lo_i;
	input wire [15:0] y_hi_i;
	input wire signed [31:0] x0;
	input wire signed [31:0] y0;
	input wire signed [31:0] x1;
	input wire signed [31:0] y1;
	input wire signed [31:0] x2;
	input wire signed [31:0] y2;
	input wire signed [32:0] dx01;
	input wire signed [32:0] dy01;
	input wire signed [32:0] dx12;
	input wire signed [32:0] dy12;
	input wire signed [32:0] dx20;
	input wire signed [32:0] dy20;
	output reg fpa_we;
	output reg [31:0] fpa_addr;
	output reg [31:0] fpa_wdata;
	output reg [3:0] fpa_be;
	output reg fpa_req;
	input wire [31:0] fpa_rdata;
	output reg fpa2_req;
	output reg [31:0] fpa2_addr;
	input wire [31:0] fpa2_rdata;
	output wire busy;
	output reg done;
	localparam signed [63:0] HALF_Q = 64'sd2097152;
	localparam [31:0] ember_pkg_FB0_BASE = 32'h00000000;
	localparam [31:0] ember_pkg_CP_BASE = 32'h00000000;
	localparam [31:0] ember_pkg_CP_WINDOW_BYTES = 4096;
	localparam [31:0] ember_pkg_VRAM_BASE = ember_pkg_CP_BASE + ember_pkg_CP_WINDOW_BYTES;
	localparam [31:0] FB0 = ember_pkg_VRAM_BASE + ember_pkg_FB0_BASE;
	localparam [31:0] ember_pkg_FRAME_W_PX = 320;
	localparam [31:0] ember_pkg_FB_STRIDE = 640;
	localparam [31:0] ember_pkg_FRAME_H_PX = 240;
	localparam [31:0] ember_pkg_ZBUF_BASE = ember_pkg_FB0_BASE + (ember_pkg_FB_STRIDE * ember_pkg_FRAME_H_PX);
	localparam [31:0] ZB = ember_pkg_VRAM_BASE + ember_pkg_ZBUF_BASE;
	localparam [31:0] ember_pkg_PAL_BASE = 32'h00074000;
	localparam [31:0] PAL = ember_pkg_VRAM_BASE + ember_pkg_PAL_BASE;
	reg [4:0] st;
	assign busy = st != 5'd0;
	reg [15:0] ix;
	reg [15:0] iy;
	reg signed [63:0] cx;
	reg signed [63:0] cy;
	reg signed [95:0] e01;
	reg signed [95:0] e12;
	reg signed [95:0] e20;
	reg signed [95:0] r_v;
	reg signed [95:0] g_v;
	reg signed [95:0] b_v;
	reg signed [95:0] z_v;
	reg signed [95:0] u_raw;
	reg signed [95:0] v_raw;
	reg signed [95:0] inv_w_v;
	reg signed [95:0] u_fin;
	reg signed [95:0] v_fin;
	reg z_pass;
	reg [7:0] cr;
	reg [7:0] cg;
	reg [7:0] cb;
	reg [7:0] mr;
	reg [7:0] mg;
	reg [7:0] mb;
	reg [31:0] zaddr;
	reg [31:0] faddr;
	function automatic [15:0] half_get;
		input reg [31:0] w;
		input reg hi;
		half_get = (hi ? w[31:16] : w[15:0]);
	endfunction
	function automatic [7:0] expand565_r;
		input reg [15:0] p;
		expand565_r = {p[15:11], 3'b000};
	endfunction
	function automatic [7:0] expand565_g;
		input reg [15:0] p;
		expand565_g = {p[10:5], 2'b00};
	endfunction
	function automatic [7:0] expand565_b;
		input reg [15:0] p;
		expand565_b = {p[4:0], 3'b000};
	endfunction
	wire [95:0] u8w = u_fin >>> 22;
	wire [95:0] v8w = v_fin >>> 22;
	localparam [31:0] ember_pkg_TEX_BASE = ember_pkg_ZBUF_BASE + ((ember_pkg_FRAME_W_PX * ember_pkg_FRAME_H_PX) * 2);
	wire [31:0] tex_addr = ((ember_pkg_VRAM_BASE + ember_pkg_TEX_BASE) + {16'b0000000000000000, v8w[7:0], 8'h00}) + {24'b000000000000000000000000, u8w[7:0]};
	wire [31:0] texel_shift = fpa2_rdata >> {tex_addr[1:0], 3'b000};
	wire [7:0] texel_byte = texel_shift[7:0];
	wire [31:0] pix_xy = ({{16 {1'b0}}, iy} * 32'd320) + {{16 {1'b0}}, ix};
	wire [31:0] pix_off = pix_xy * 2;
	wire odd_x = pix_off[1];
	wire [31:0] pix_word_off = {pix_off[31:2], 2'b00};
	function automatic [7:0] clamp8;
		input reg signed [95:0] v;
		reg signed [95:0] t;
		begin
			t = v >>> 22;
			if (t < 0)
				clamp8 = 8'h00;
			else if (t > 255)
				clamp8 = 8'hff;
			else
				clamp8 = t[7:0];
		end
	endfunction
	function automatic [7:0] avg2;
		input reg [7:0] a;
		input reg [7:0] b;
		reg [8:0] s;
		begin
			s = {1'b0, a} + {1'b0, b};
			avg2 = s[8:1];
		end
	endfunction
	wire signed [95:0] p01a;
	wire signed [95:0] p01b;
	wire signed [95:0] p12a;
	wire signed [95:0] p12b;
	wire signed [95:0] p20a;
	wire signed [95:0] p20b;
	wire signed [95:0] e01x;
	wire signed [95:0] e01y;
	wire signed [95:0] e12x;
	wire signed [95:0] e12y;
	wire signed [95:0] e20x;
	wire signed [95:0] e20y;
	wire signed [95:0] cxx0;
	wire signed [95:0] cxx1;
	wire signed [95:0] cxx2;
	wire signed [95:0] cyy0;
	wire signed [95:0] cyy1;
	wire signed [95:0] cyy2;
	assign e01x = {{63 {dx01[32]}}, dx01};
	assign e01y = {{63 {dy01[32]}}, dy01};
	assign e12x = {{63 {dx12[32]}}, dx12};
	assign e12y = {{63 {dy12[32]}}, dy12};
	assign e20x = {{63 {dx20[32]}}, dx20};
	assign e20y = {{63 {dy20[32]}}, dy20};
	assign cyy0 = {{32 {cy[63]}}, cy} - {{64 {y0[31]}}, y0};
	assign cxx0 = {{32 {cx[63]}}, cx} - {{64 {x0[31]}}, x0};
	assign cyy1 = {{32 {cy[63]}}, cy} - {{64 {y1[31]}}, y1};
	assign cxx1 = {{32 {cx[63]}}, cx} - {{64 {x1[31]}}, x1};
	assign cyy2 = {{32 {cy[63]}}, cy} - {{64 {y2[31]}}, y2};
	assign cxx2 = {{32 {cx[63]}}, cx} - {{64 {x2[31]}}, x2};
	_rtr_smul96 u_m01(
		.a(e01x),
		.b(cyy0),
		.q(p01a)
	);
	_rtr_smul96 u_m02(
		.a(e01y),
		.b(cxx0),
		.q(p01b)
	);
	_rtr_smul96 u_m03(
		.a(e12x),
		.b(cyy1),
		.q(p12a)
	);
	_rtr_smul96 u_m04(
		.a(e12y),
		.b(cxx1),
		.q(p12b)
	);
	_rtr_smul96 u_m05(
		.a(e20x),
		.b(cyy2),
		.q(p20a)
	);
	_rtr_smul96 u_m06(
		.a(e20y),
		.b(cxx2),
		.q(p20b)
	);
	wire signed [95:0] iw_p;
	wire signed [95:0] iw_q;
	wire signed [95:0] r_p;
	wire signed [95:0] r_q;
	wire signed [95:0] g_p;
	wire signed [95:0] g_q;
	wire signed [95:0] b_p;
	wire signed [95:0] b_q;
	wire signed [95:0] z_p;
	wire signed [95:0] z_q;
	wire signed [95:0] u_p;
	wire signed [95:0] u_q;
	wire signed [95:0] v_p;
	wire signed [95:0] v_q;
	wire signed [95:0] iw_s;
	wire signed [95:0] r_s;
	wire signed [95:0] g_s;
	wire signed [95:0] b_s;
	wire signed [95:0] z_s;
	wire signed [95:0] u_s;
	wire signed [95:0] v_s;
	_rtr_smul96 u_pe_iw_a(
		.a(iwA),
		.b(cx),
		.q(iw_p)
	);
	_rtr_smul96 u_pe_iw_b(
		.a(iwB),
		.b(cy),
		.q(iw_q)
	);
	_rtr_smul96 u_pe_r_a(
		.a(rA),
		.b(cx),
		.q(r_p)
	);
	_rtr_smul96 u_pe_r_b(
		.a(rB),
		.b(cy),
		.q(r_q)
	);
	_rtr_smul96 u_pe_g_a(
		.a(gA),
		.b(cx),
		.q(g_p)
	);
	_rtr_smul96 u_pe_g_b(
		.a(gB),
		.b(cy),
		.q(g_q)
	);
	_rtr_smul96 u_pe_b_a(
		.a(bA),
		.b(cx),
		.q(b_p)
	);
	_rtr_smul96 u_pe_b_b(
		.a(bB),
		.b(cy),
		.q(b_q)
	);
	_rtr_smul96 u_pe_z_a(
		.a(zA),
		.b(cx),
		.q(z_p)
	);
	_rtr_smul96 u_pe_z_b(
		.a(zB),
		.b(cy),
		.q(z_q)
	);
	_rtr_smul96 u_pe_u_a(
		.a(uA),
		.b(cx),
		.q(u_p)
	);
	_rtr_smul96 u_pe_u_b(
		.a(uB),
		.b(cy),
		.q(u_q)
	);
	_rtr_smul96 u_pe_v_a(
		.a(vA),
		.b(cx),
		.q(v_p)
	);
	_rtr_smul96 u_pe_v_b(
		.a(vB),
		.b(cy),
		.q(v_q)
	);
	assign iw_s = iw_p + iw_q;
	assign r_s = r_p + r_q;
	assign g_s = g_p + g_q;
	assign b_s = b_p + b_q;
	assign z_s = z_p + z_q;
	assign u_s = u_p + u_q;
	assign v_s = v_p + v_q;
	wire signed [95:0] iw_sh = iw_s >>> 22;
	wire signed [95:0] r_sh = r_s >>> 22;
	wire signed [95:0] g_sh = g_s >>> 22;
	wire signed [95:0] b_sh = b_s >>> 22;
	wire signed [95:0] z_sh = z_s >>> 22;
	wire signed [95:0] u_sh = u_s >>> 22;
	wire signed [95:0] v_sh = v_s >>> 22;
	wire signed [95:0] iw_ev = iw_sh + {{32 {iwC[63]}}, iwC};
	wire signed [95:0] r_ev = r_sh + {{32 {rC[63]}}, rC};
	wire signed [95:0] g_ev = g_sh + {{32 {gC[63]}}, gC};
	wire signed [95:0] b_ev = b_sh + {{32 {bC[63]}}, bC};
	wire signed [95:0] z_ev = z_sh + {{32 {zC[63]}}, zC};
	wire signed [95:0] u_ev = u_sh + {{32 {uC[63]}}, uC};
	wire signed [95:0] v_ev = v_sh + {{32 {vC[63]}}, vC};
	wire signed [95:0] u_fin_w;
	wire signed [95:0] v_fin_w;
	_rtr_sdiv96 u_pdiv_u(
		.num(u_raw),
		.den(inv_w_v),
		.q(u_fin_w)
	);
	_rtr_sdiv96 u_pdiv_v(
		.num(v_raw),
		.den(inv_w_v),
		.q(v_fin_w)
	);
	wire [7:0] src_r = (t_blend ? mr : cr);
	wire [7:0] src_g = (t_blend ? mg : cg);
	wire [7:0] src_b = (t_blend ? mb : cb);
	wire dith_up = (ix[0] ^ iy[0]) == 1'b1;
	wire [7:0] dmr = (!t_dither ? src_r : (dith_up ? (src_r == 8'hff ? 8'hff : src_r + 8'd1) : (src_r == 8'h00 ? 8'h00 : src_r - 8'd1)));
	wire [7:0] dmg = (!t_dither ? src_g : (dith_up ? (src_g == 8'hff ? 8'hff : src_g + 8'd1) : (src_g == 8'h00 ? 8'h00 : src_g - 8'd1)));
	wire [7:0] dmb = (!t_dither ? src_b : (dith_up ? (src_b == 8'hff ? 8'hff : src_b + 8'd1) : (src_b == 8'h00 ? 8'h00 : src_b - 8'd1)));
	always @(posedge clk or negedge rst_n)
		if (!rst_n) begin
			st <= 5'd0;
			done <= 1'b0;
			ix <= 1'sb0;
			iy <= 1'sb0;
			cx <= 1'sb0;
			cy <= 1'sb0;
			fpa_req <= 1'b0;
			fpa_we <= 1'b0;
			fpa_addr <= 1'sb0;
			fpa_wdata <= 1'sb0;
			fpa_be <= 1'sb0;
			fpa2_req <= 1'b0;
			fpa2_addr <= 1'sb0;
			e01 <= 1'sb0;
			e12 <= 1'sb0;
			e20 <= 1'sb0;
			r_v <= 1'sb0;
			g_v <= 1'sb0;
			b_v <= 1'sb0;
			z_v <= 1'sb0;
			u_raw <= 1'sb0;
			v_raw <= 1'sb0;
			inv_w_v <= 1'sb0;
			u_fin <= 1'sb0;
			v_fin <= 1'sb0;
			z_pass <= 1'b0;
			cr <= 1'sb0;
			cg <= 1'sb0;
			cb <= 1'sb0;
			mr <= 1'sb0;
			mg <= 1'sb0;
			mb <= 1'sb0;
			zaddr <= 1'sb0;
			faddr <= 1'sb0;
		end
		else begin
			done <= 1'b0;
			fpa_req <= 1'b0;
			fpa_we <= 1'b0;
			fpa2_req <= 1'b0;
			case (st)
				5'd0:
					if (start) begin
						ix <= x_lo_i;
						iy <= y_lo_i;
						cx <= ({{48 {x_lo_i[15]}}, x_lo_i} <<< 22) + HALF_Q;
						cy <= ({{48 {y_lo_i[15]}}, y_lo_i} <<< 22) + HALF_Q;
						st <= 5'd1;
					end
				5'd1: begin
					e01 <= p01a - p01b;
					e12 <= p12a - p12b;
					e20 <= p20a - p20b;
					if (t_ztest) begin
						fpa_req <= 1'b1;
						fpa_addr <= ZB + pix_word_off;
					end
					st <= 5'd2;
				end
				5'd2:
					if (((e01 > 0) && (e12 > 0)) && (e20 > 0)) begin
						zaddr <= ZB + pix_word_off;
						faddr <= FB0 + pix_word_off;
						inv_w_v <= iw_ev;
						r_v <= r_ev;
						g_v <= g_ev;
						b_v <= b_ev;
						z_v <= z_ev;
						u_raw <= u_ev;
						v_raw <= v_ev;
						if (t_ztest)
							st <= 5'd3;
						else
							st <= 5'd4;
					end
					else
						st <= 5'd16;
				5'd3: begin
					z_pass <= z_v < $signed({{80 {1'b0}}, half_get(fpa_rdata, odd_x)});
					if (!(z_v < $signed({{80 {1'b0}}, half_get(fpa_rdata, odd_x)})))
						st <= 5'd16;
					else
						st <= 5'd4;
				end
				5'd4: begin
					u_fin <= u_fin_w;
					v_fin <= v_fin_w;
					if (t_tex)
						st <= 5'd5;
					else begin
						cr <= clamp8(r_v);
						cg <= clamp8(g_v);
						cb <= clamp8(b_v);
						st <= (t_blend ? 5'd11 : 5'd14);
					end
				end
				5'd5: begin
					fpa2_req <= 1'b1;
					fpa2_addr <= tex_addr;
					st <= 5'd6;
				end
				5'd6: st <= 5'd7;
				5'd7:
					if (t_texpal) begin
						fpa2_req <= 1'b1;
						fpa2_addr <= PAL + {22'b0000000000000000000000, texel_byte, 2'b00};
						st <= 5'd9;
					end
					else begin
						cr <= texel_byte;
						cg <= texel_byte;
						cb <= texel_byte;
						st <= (t_blend ? 5'd11 : 5'd14);
					end
				5'd9: st <= 5'd10;
				5'd10: begin
					cr <= fpa2_rdata[7:0];
					cg <= fpa2_rdata[15:8];
					cb <= fpa2_rdata[23:16];
					st <= (t_blend ? 5'd11 : 5'd14);
				end
				5'd11: begin
					fpa_req <= 1'b1;
					fpa_addr <= faddr;
					st <= 5'd12;
				end
				5'd12: st <= 5'd13;
				5'd13: begin
					mr <= avg2(cr, expand565_r(half_get(fpa_rdata, odd_x)));
					mg <= avg2(cg, expand565_g(half_get(fpa_rdata, odd_x)));
					mb <= avg2(cb, expand565_b(half_get(fpa_rdata, odd_x)));
					st <= 5'd14;
				end
				5'd14: begin
					fpa_we <= 1'b1;
					fpa_addr <= faddr;
					fpa_be <= (odd_x ? 4'b1100 : 4'b0011);
					if (t_rgbmap)
						fpa_wdata <= {dmb[7:3], dmg[7:2], dmr[7:3], dmb[7:3], dmg[7:2], dmr[7:3]};
					else
						fpa_wdata <= {dmr[7:3], dmg[7:2], dmb[7:3], dmr[7:3], dmg[7:2], dmb[7:3]};
					st <= (t_ztest && z_pass ? 5'd15 : 5'd16);
				end
				5'd15: begin
					fpa_we <= 1'b1;
					fpa_addr <= zaddr;
					fpa_be <= (odd_x ? 4'b1100 : 4'b0011);
					fpa_wdata <= {z_v[15:0], z_v[15:0]};
					st <= 5'd16;
				end
				5'd16:
					if (ix == x_hi_i) begin
						if (iy == y_hi_i) begin
							done <= 1'b1;
							st <= 5'd0;
						end
						else begin
							ix <= x_lo_i;
							iy <= iy + 16'd1;
							cx <= ({{48 {x_lo_i[15]}}, x_lo_i} <<< 22) + HALF_Q;
							cy <= (cy + HALF_Q) + HALF_Q;
							st <= 5'd1;
						end
					end
					else begin
						ix <= ix + 16'd1;
						cx <= (cx + HALF_Q) + HALF_Q;
						st <= 5'd1;
					end
				default: st <= 5'd0;
			endcase
		end
	wire _unused = |t_texpage;
endmodule