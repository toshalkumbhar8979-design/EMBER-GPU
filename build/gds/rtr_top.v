module ember_rtr_setup (
	x0,
	y0,
	x1,
	y1,
	x2,
	y2,
	u0,
	v0,
	u1,
	v1,
	u2,
	v2,
	z0,
	z1,
	z2,
	r0,
	g0,
	b0,
	r1,
	g1,
	b1,
	r2,
	g2,
	b2,
	cull,
	area,
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
	dx01,
	dy01,
	dx12,
	dy12,
	dx20,
	dy20
);
	input wire signed [31:0] x0;
	input wire signed [31:0] y0;
	input wire signed [31:0] x1;
	input wire signed [31:0] y1;
	input wire signed [31:0] x2;
	input wire signed [31:0] y2;
	input wire signed [31:0] u0;
	input wire signed [31:0] v0;
	input wire signed [31:0] u1;
	input wire signed [31:0] v1;
	input wire signed [31:0] u2;
	input wire signed [31:0] v2;
	input wire [15:0] z0;
	input wire [15:0] z1;
	input wire [15:0] z2;
	input wire [7:0] r0;
	input wire [7:0] g0;
	input wire [7:0] b0;
	input wire [7:0] r1;
	input wire [7:0] g1;
	input wire [7:0] b1;
	input wire [7:0] r2;
	input wire [7:0] g2;
	input wire [7:0] b2;
	output wire cull;
	output wire signed [66:0] area;
	output wire signed [63:0] iwA;
	output wire signed [63:0] iwB;
	output wire signed [63:0] iwC;
	output wire signed [63:0] rA;
	output wire signed [63:0] rB;
	output wire signed [63:0] rC;
	output wire signed [63:0] gA;
	output wire signed [63:0] gB;
	output wire signed [63:0] gC;
	output wire signed [63:0] bA;
	output wire signed [63:0] bB;
	output wire signed [63:0] bC;
	output wire signed [63:0] zA;
	output wire signed [63:0] zB;
	output wire signed [63:0] zC;
	output wire signed [63:0] uA;
	output wire signed [63:0] uB;
	output wire signed [63:0] uC;
	output wire signed [63:0] vA;
	output wire signed [63:0] vB;
	output wire signed [63:0] vC;
	output wire [15:0] x_lo_i;
	output wire [15:0] x_hi_i;
	output wire [15:0] y_lo_i;
	output wire [15:0] y_hi_i;
	output wire signed [32:0] dx01;
	output wire signed [32:0] dy01;
	output wire signed [32:0] dx12;
	output wire signed [32:0] dy12;
	output wire signed [32:0] dx20;
	output wire signed [32:0] dy20;
	localparam signed [63:0] ONE_Q = 64'sd4194304;
	wire signed [32:0] dy10_;
	wire signed [32:0] dy20_;
	wire signed [32:0] dx10_;
	wire signed [32:0] dx20_;
	assign dy10_ = y1 - y0;
	assign dy20_ = y2 - y0;
	assign dx10_ = x1 - x0;
	assign dx20_ = x2 - x0;
	assign dx01 = x1 - x0;
	assign dy01 = y1 - y0;
	assign dx12 = x2 - x1;
	assign dy12 = y2 - y1;
	assign dx20 = x0 - x2;
	assign dy20 = y0 - y2;
	wire signed [65:0] p1;
	wire signed [65:0] p2;
	assign p1 = dx10_ * dy20_;
	assign p2 = dy10_ * dx20_;
	assign area = p1 - p2;
	assign cull = area <= 0;
	wire signed [66:0] den;
	assign den = (area == 0 ? 67'sd1 : area);
	function automatic signed [63:0] coef_a;
		input reg signed [95:0] dv10;
		input reg signed [95:0] dv20;
		input reg signed [32:0] dy20_;
		input reg signed [32:0] dy10_;
		input reg signed [66:0] den_;
		reg signed [95:0] num;
		reg signed [117:0] num_sh;
		reg signed [117:0] den_x;
		reg signed [117:0] q;
		begin
			num = (dv10 * dy20_) - (dv20 * dy10_);
			num_sh = num <<< 22;
			den_x = {{51 {den_[66]}}, den_};
			q = num_sh / den_x;
			coef_a = q[63:0];
		end
	endfunction
	function automatic signed [63:0] coef_b;
		input reg signed [95:0] dv20;
		input reg signed [95:0] dv10;
		input reg signed [32:0] dx10_;
		input reg signed [32:0] dx20_;
		input reg signed [66:0] den_;
		reg signed [95:0] num;
		reg signed [117:0] num_sh;
		reg signed [117:0] den_x;
		reg signed [117:0] q;
		begin
			num = (dv20 * dx10_) - (dv10 * dx20_);
			num_sh = num <<< 22;
			den_x = {{51 {den_[66]}}, den_};
			q = num_sh / den_x;
			coef_b = q[63:0];
		end
	endfunction
	function automatic signed [63:0] coef_c;
		input reg signed [63:0] A;
		input reg signed [63:0] B;
		input reg signed [31:0] x0_;
		input reg signed [31:0] y0_;
		input reg signed [95:0] val0;
		reg signed [95:0] ax;
		reg signed [95:0] by;
		reg signed [95:0] sub;
		reg signed [95:0] c_res;
		begin
			ax = A * x0_;
			by = B * y0_;
			sub = (ax + by) >>> 22;
			c_res = val0 - sub;
			coef_c = c_res[63:0];
		end
	endfunction
	wire signed [95:0] r0e;
	wire signed [95:0] r1e;
	wire signed [95:0] r2e;
	wire signed [95:0] g0e;
	wire signed [95:0] g1e;
	wire signed [95:0] g2e;
	wire signed [95:0] b0e;
	wire signed [95:0] b1e;
	wire signed [95:0] b2e;
	wire signed [95:0] z0e;
	wire signed [95:0] z1e;
	wire signed [95:0] z2e;
	wire signed [95:0] u0e;
	wire signed [95:0] u1e;
	wire signed [95:0] u2e;
	wire signed [95:0] v0e;
	wire signed [95:0] v1e;
	wire signed [95:0] v2e;
	assign r0e = {66'b000000000000000000000000000000000000000000000000000000000000000000, r0, 22'b0000000000000000000000};
	assign r1e = {66'b000000000000000000000000000000000000000000000000000000000000000000, r1, 22'b0000000000000000000000};
	assign r2e = {66'b000000000000000000000000000000000000000000000000000000000000000000, r2, 22'b0000000000000000000000};
	assign g0e = {66'b000000000000000000000000000000000000000000000000000000000000000000, g0, 22'b0000000000000000000000};
	assign g1e = {66'b000000000000000000000000000000000000000000000000000000000000000000, g1, 22'b0000000000000000000000};
	assign g2e = {66'b000000000000000000000000000000000000000000000000000000000000000000, g2, 22'b0000000000000000000000};
	assign b0e = {66'b000000000000000000000000000000000000000000000000000000000000000000, b0, 22'b0000000000000000000000};
	assign b1e = {66'b000000000000000000000000000000000000000000000000000000000000000000, b1, 22'b0000000000000000000000};
	assign b2e = {66'b000000000000000000000000000000000000000000000000000000000000000000, b2, 22'b0000000000000000000000};
	assign z0e = {80'b00000000000000000000000000000000000000000000000000000000000000000000000000000000, z0};
	assign z1e = {80'b00000000000000000000000000000000000000000000000000000000000000000000000000000000, z1};
	assign z2e = {80'b00000000000000000000000000000000000000000000000000000000000000000000000000000000, z2};
	assign u0e = {{64 {u0[31]}}, u0};
	assign u1e = {{64 {u1[31]}}, u1};
	assign u2e = {{64 {u2[31]}}, u2};
	assign v0e = {{64 {v0[31]}}, v0};
	assign v1e = {{64 {v1[31]}}, v1};
	assign v2e = {{64 {v2[31]}}, v2};
	wire signed [95:0] r10;
	wire signed [95:0] r20;
	wire signed [95:0] g10;
	wire signed [95:0] g20;
	wire signed [95:0] b10;
	wire signed [95:0] b20;
	wire signed [95:0] z10;
	wire signed [95:0] z20;
	wire signed [95:0] u10;
	wire signed [95:0] u20;
	wire signed [95:0] v10;
	wire signed [95:0] v20;
	assign r10 = r1e - r0e;
	assign r20 = r2e - r0e;
	assign g10 = g1e - g0e;
	assign g20 = g2e - g0e;
	assign b10 = b1e - b0e;
	assign b20 = b2e - b0e;
	assign z10 = z1e - z0e;
	assign z20 = z2e - z0e;
	assign u10 = u1e - u0e;
	assign u20 = u2e - u0e;
	assign v10 = v1e - v0e;
	assign v20 = v2e - v0e;
	wire signed [95:0] one0;
	assign one0 = {{32 {ONE_Q[63]}}, ONE_Q};
	wire signed [95:0] zero96;
	assign zero96 = 1'sb0;
	assign iwA = coef_a(zero96, zero96, dy20_, dy10_, den);
	assign iwB = coef_b(zero96, zero96, dx10_, dx20_, den);
	assign iwC = coef_c(iwA, iwB, x0, y0, one0);
	assign rA = coef_a(r10, r20, dy20_, dy10_, den);
	assign rB = coef_b(r20, r10, dx10_, dx20_, den);
	assign rC = coef_c(rA, rB, x0, y0, r0e);
	assign gA = coef_a(g10, g20, dy20_, dy10_, den);
	assign gB = coef_b(g20, g10, dx10_, dx20_, den);
	assign gC = coef_c(gA, gB, x0, y0, g0e);
	assign bA = coef_a(b10, b20, dy20_, dy10_, den);
	assign bB = coef_b(b20, b10, dx10_, dx20_, den);
	assign bC = coef_c(bA, bB, x0, y0, b0e);
	assign zA = coef_a(z10, z20, dy20_, dy10_, den);
	assign zB = coef_b(z20, z10, dx10_, dx20_, den);
	assign zC = coef_c(zA, zB, x0, y0, z0e);
	assign uA = coef_a(u10, u20, dy20_, dy10_, den);
	assign uB = coef_b(u20, u10, dx10_, dx20_, den);
	assign uC = coef_c(uA, uB, x0, y0, u0e);
	assign vA = coef_a(v10, v20, dy20_, dy10_, den);
	assign vB = coef_b(v20, v10, dx10_, dx20_, den);
	assign vC = coef_c(vA, vB, x0, y0, v0e);
	function automatic [15:0] clamp_lo;
		input reg signed [31:0] v;
		input reg signed [31:0] lim;
		reg signed [31:0] c;
		reg signed [31:0] f;
		begin
			c = (v < 0 ? 32'sd0 : (v > lim ? lim : v));
			f = c >>> 22;
			if (f < 0)
				clamp_lo = 16'd0;
			else
				clamp_lo = f[15:0];
		end
	endfunction
	function automatic [15:0] clamp_hi;
		input reg signed [31:0] v;
		input reg signed [31:0] lim;
		reg signed [31:0] c;
		reg signed [31:0] f;
		begin
			c = (v < 0 ? 32'sd0 : (v > lim ? lim : v));
			f = c >>> 22;
			if (f > lim[31:22])
				clamp_hi = lim[15:0];
			else if (f < 0)
				clamp_hi = 16'd0;
			else
				clamp_hi = f[15:0];
		end
	endfunction
	wire signed [31:0] xmin;
	wire signed [31:0] xmax;
	wire signed [31:0] ymin;
	wire signed [31:0] ymax;
	assign xmin = (x0 < x1 ? (x0 < x2 ? x0 : x2) : (x1 < x2 ? x1 : x2));
	assign xmax = (x0 > x1 ? (x0 > x2 ? x0 : x2) : (x1 > x2 ? x1 : x2));
	assign ymin = (y0 < y1 ? (y0 < y2 ? y0 : y2) : (y1 < y2 ? y1 : y2));
	assign ymax = (y0 > y1 ? (y0 > y2 ? y0 : y2) : (y1 > y2 ? y1 : y2));
	localparam signed [31:0] XMAX_Q = 32'sd319 << 22;
	localparam signed [31:0] YMAX_Q = 32'sd239 << 22;
	assign x_lo_i = clamp_lo(xmin, XMAX_Q);
	assign x_hi_i = clamp_hi(xmax, XMAX_Q);
	assign y_lo_i = clamp_lo(ymin, YMAX_Q);
	assign y_hi_i = clamp_hi(ymax, YMAX_Q);
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
	reg [3:0] st;
	assign busy = st != 4'd0;
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
	function automatic signed [95:0] peval;
		input reg signed [63:0] A;
		input reg signed [63:0] B;
		input reg signed [63:0] C;
		input reg signed [63:0] px;
		input reg signed [63:0] py;
		reg signed [95:0] s;
		reg signed [95:0] sh;
		begin
			s = (A * px) + (B * py);
			sh = s >>> 22;
			peval = sh + {{32 {C[63]}}, C};
		end
	endfunction
	function automatic signed [95:0] pdiv;
		input reg signed [95:0] num;
		input reg signed [95:0] den;
		reg signed [191:0] n;
		reg signed [191:0] d;
		reg signed [191:0] q;
		if (den == 0)
			pdiv = 0;
		else begin
			n = {{96 {num[95]}}, num};
			d = {{96 {den[95]}}, den};
			q = $signed(n <<< 22) / $signed(d);
			pdiv = q[95:0];
		end
	endfunction
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
	wire [7:0] src_r = (t_blend ? mr : cr);
	wire [7:0] src_g = (t_blend ? mg : cg);
	wire [7:0] src_b = (t_blend ? mb : cb);
	wire dith_up = (ix[0] ^ iy[0]) == 1'b1;
	wire [7:0] dmr = (!t_dither ? src_r : (dith_up ? (src_r == 8'hff ? 8'hff : src_r + 8'd1) : (src_r == 8'h00 ? 8'h00 : src_r - 8'd1)));
	wire [7:0] dmg = (!t_dither ? src_g : (dith_up ? (src_g == 8'hff ? 8'hff : src_g + 8'd1) : (src_g == 8'h00 ? 8'h00 : src_g - 8'd1)));
	wire [7:0] dmb = (!t_dither ? src_b : (dith_up ? (src_b == 8'hff ? 8'hff : src_b + 8'd1) : (src_b == 8'h00 ? 8'h00 : src_b - 8'd1)));
	always @(posedge clk or negedge rst_n)
		if (!rst_n) begin
			st <= 4'd0;
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
				4'd0:
					if (start) begin
						ix <= x_lo_i;
						iy <= y_lo_i;
						cx <= ({{48 {x_lo_i[15]}}, x_lo_i} <<< 22) + HALF_Q;
						cy <= ({{48 {y_lo_i[15]}}, y_lo_i} <<< 22) + HALF_Q;
						st <= 4'd1;
					end
				4'd1: begin
					e01 <= ({{63 {dx01[32]}}, dx01} * ({{32 {cy[63]}}, cy} - {{64 {y0[31]}}, y0})) - ({{63 {dy01[32]}}, dy01} * ({{32 {cx[63]}}, cx} - {{64 {x0[31]}}, x0}));
					e12 <= ({{63 {dx12[32]}}, dx12} * ({{32 {cy[63]}}, cy} - {{64 {y1[31]}}, y1})) - ({{63 {dy12[32]}}, dy12} * ({{32 {cx[63]}}, cx} - {{64 {x1[31]}}, x1}));
					e20 <= ({{63 {dx20[32]}}, dx20} * ({{32 {cy[63]}}, cy} - {{64 {y2[31]}}, y2})) - ({{63 {dy20[32]}}, dy20} * ({{32 {cx[63]}}, cx} - {{64 {x2[31]}}, x2}));
					if (t_ztest) begin
						fpa_req <= 1'b1;
						fpa_addr <= ZB + pix_word_off;
					end
					st <= 4'd2;
				end
				4'd2:
					if (((e01 > 0) && (e12 > 0)) && (e20 > 0)) begin
						zaddr <= ZB + pix_word_off;
						faddr <= FB0 + pix_word_off;
						inv_w_v <= peval(iwA, iwB, iwC, cx, cy);
						r_v <= peval(rA, rB, rC, cx, cy);
						g_v <= peval(gA, gB, gC, cx, cy);
						b_v <= peval(bA, bB, bC, cx, cy);
						z_v <= peval(zA, zB, zC, cx, cy);
						u_raw <= peval(uA, uB, uC, cx, cy);
						v_raw <= peval(vA, vB, vC, cx, cy);
						if (t_ztest)
							st <= 4'd3;
						else
							st <= 4'd4;
					end
					else
						st <= 4'd13;
				4'd3: begin
					z_pass <= z_v < $signed({{80 {1'b0}}, half_get(fpa_rdata, odd_x)});
					if (!(z_v < $signed({{80 {1'b0}}, half_get(fpa_rdata, odd_x)})))
						st <= 4'd13;
					else
						st <= 4'd4;
				end
				4'd4: begin
					u_fin <= pdiv(u_raw, inv_w_v);
					v_fin <= pdiv(v_raw, inv_w_v);
					if (t_tex)
						st <= 4'd5;
					else begin
						cr <= clamp8(r_v);
						cg <= clamp8(g_v);
						cb <= clamp8(b_v);
						st <= (t_blend ? 4'd8 : 4'd11);
					end
				end
				4'd5: begin
					fpa2_req <= 1'b1;
					fpa2_addr <= tex_addr;
					st <= 4'd6;
				end
				4'd6: st <= 4'd7;
				4'd7: begin
					cr <= texel_byte;
					cg <= texel_byte;
					cb <= texel_byte;
					st <= (t_blend ? 4'd8 : 4'd11);
				end
				4'd8: begin
					fpa_req <= 1'b1;
					fpa_addr <= faddr;
					st <= 4'd9;
				end
				4'd9: st <= 4'd10;
				4'd10: begin
					mr <= avg2(cr, expand565_r(half_get(fpa_rdata, odd_x)));
					mg <= avg2(cg, expand565_g(half_get(fpa_rdata, odd_x)));
					mb <= avg2(cb, expand565_b(half_get(fpa_rdata, odd_x)));
					st <= 4'd11;
				end
				4'd11: begin
					fpa_we <= 1'b1;
					fpa_addr <= faddr;
					fpa_be <= (odd_x ? 4'b1100 : 4'b0011);
					if (t_rgbmap)
						fpa_wdata <= {dmb[7:3], dmg[7:2], dmr[7:3], dmb[7:3], dmg[7:2], dmr[7:3]};
					else
						fpa_wdata <= {dmr[7:3], dmg[7:2], dmb[7:3], dmr[7:3], dmg[7:2], dmb[7:3]};
					st <= (t_ztest && z_pass ? 4'd12 : 4'd13);
				end
				4'd12: begin
					fpa_we <= 1'b1;
					fpa_addr <= zaddr;
					fpa_be <= (odd_x ? 4'b1100 : 4'b0011);
					fpa_wdata <= {z_v[15:0], z_v[15:0]};
					st <= 4'd13;
				end
				4'd13:
					if (ix == x_hi_i) begin
						if (iy == y_hi_i) begin
							done <= 1'b1;
							st <= 4'd0;
						end
						else begin
							ix <= x_lo_i;
							iy <= iy + 16'd1;
							cx <= ({{48 {x_lo_i[15]}}, x_lo_i} <<< 22) + HALF_Q;
							cy <= (cy + HALF_Q) + HALF_Q;
							st <= 4'd1;
						end
					end
					else begin
						ix <= ix + 16'd1;
						cx <= (cx + HALF_Q) + HALF_Q;
						st <= 4'd1;
					end
				default: st <= 4'd0;
			endcase
		end
	wire _unused = |t_texpage;
endmodule
module ember_rtr_top (
	clk,
	rst_n,
	kick,
	fpa_we,
	fpa_addr,
	fpa_wdata,
	fpa_be,
	fpa_req,
	fpa_rdata,
	fpa2_req,
	fpa2_addr,
	fpa2_rdata,
	busy
);
	input wire clk;
	input wire rst_n;
	input wire kick;
	output wire fpa_we;
	output wire [31:0] fpa_addr;
	output wire [31:0] fpa_wdata;
	output wire [3:0] fpa_be;
	output wire fpa_req;
	input wire [31:0] fpa_rdata;
	output wire fpa2_req;
	output wire [31:0] fpa2_addr;
	input wire [31:0] fpa2_rdata;
	output wire busy;
	reg [2:0] fst;
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
	localparam [31:0] CMDQ_BUS = ember_pkg_VRAM_BASE + ember_pkg_RTR_CMDQ_BASE;
	localparam [31:0] ember_pkg_RTR_CMD_WORDS = 19;
	localparam [31:0] CMD_STRIDE = 76;
	reg [31:0] cursor;
	reg [4:0] fidx;
	reg [31:0] cmd_q [0:18];
	reg fetch_req;
	reg [31:0] fetch_addr;
	reg scan_start;
	wire scan_busy;
	wire scan_done;
	assign busy = (fst != 3'd0) || scan_busy;
	wire cull;
	always @(posedge clk or negedge rst_n)
		if (!rst_n) begin
			fst <= 3'd0;
			cursor <= CMDQ_BUS;
			fidx <= 5'd0;
			fetch_req <= 1'b0;
			scan_start <= 1'b0;
		end
		else begin
			fetch_req <= 1'b0;
			scan_start <= 1'b0;
			case (fst)
				3'd0:
					if (kick) begin
						cursor <= CMDQ_BUS;
						fidx <= 5'd0;
						fetch_req <= 1'b1;
						fetch_addr <= CMDQ_BUS;
						fst <= 3'd1;
					end
				3'd1: fst <= 3'd2;
				3'd2: begin
					cmd_q[fidx] <= fpa_rdata;
					if ((fidx == 5'd0) && !fpa_rdata[0])
						fst <= 3'd0;
					else if (fidx == 5'd18)
						fst <= 3'd3;
					else begin
						fidx <= fidx + 5'd1;
						fetch_req <= 1'b1;
						fetch_addr <= (cursor + {25'b0000000000000000000000000, fidx, 2'b00}) + 32'd4;
						fst <= 3'd1;
					end
				end
				3'd3:
					if (cull)
						fst <= 3'd5;
					else begin
						scan_start <= 1'b1;
						fst <= 3'd4;
					end
				3'd4:
					if (scan_done)
						fst <= 3'd5;
				3'd5: begin
					cursor <= cursor + CMD_STRIDE;
					fidx <= 5'd0;
					fetch_req <= 1'b1;
					fetch_addr <= cursor + CMD_STRIDE;
					fst <= 3'd1;
				end
				default: fst <= 3'd0;
			endcase
		end
	wire signed [31:0] vx0;
	wire signed [31:0] vy0;
	wire signed [31:0] vx1;
	wire signed [31:0] vy1;
	wire signed [31:0] vx2;
	wire signed [31:0] vy2;
	wire signed [31:0] vu0;
	wire signed [31:0] vv0;
	wire signed [31:0] vu1;
	wire signed [31:0] vv1;
	wire signed [31:0] vu2;
	wire signed [31:0] vv2;
	wire [15:0] vz0;
	wire [15:0] vz1;
	wire [15:0] vz2;
	wire [7:0] vr0;
	wire [7:0] vg0;
	wire [7:0] vb0;
	wire [7:0] vr1;
	wire [7:0] vg1;
	wire [7:0] vb1;
	wire [7:0] vr2;
	wire [7:0] vg2;
	wire [7:0] vb2;
	assign vx0 = $signed(cmd_q[1]);
	assign vy0 = $signed(cmd_q[2]);
	assign vx1 = $signed(cmd_q[3]);
	assign vy1 = $signed(cmd_q[4]);
	assign vx2 = $signed(cmd_q[5]);
	assign vy2 = $signed(cmd_q[6]);
	assign vz0 = cmd_q[7][15:0];
	assign vz1 = cmd_q[8][15:0];
	assign vz2 = cmd_q[9][15:0];
	assign {vb0, vg0, vr0} = cmd_q[10][23:0];
	assign {vb1, vg1, vr1} = cmd_q[11][23:0];
	assign {vb2, vg2, vr2} = cmd_q[12][23:0];
	assign vu0 = $signed(cmd_q[13]);
	assign vv0 = $signed(cmd_q[14]);
	assign vu1 = $signed(cmd_q[15]);
	assign vv1 = $signed(cmd_q[16]);
	assign vu2 = $signed(cmd_q[17]);
	assign vv2 = $signed(cmd_q[18]);
	wire signed [63:0] iwA;
	wire signed [63:0] iwB;
	wire signed [63:0] iwC;
	wire signed [63:0] rA;
	wire signed [63:0] rB;
	wire signed [63:0] rC;
	wire signed [63:0] gA;
	wire signed [63:0] gB;
	wire signed [63:0] gC;
	wire signed [63:0] bA;
	wire signed [63:0] bB;
	wire signed [63:0] bC;
	wire signed [63:0] zA;
	wire signed [63:0] zB;
	wire signed [63:0] zC;
	wire signed [63:0] uA;
	wire signed [63:0] uB;
	wire signed [63:0] uC;
	wire signed [63:0] vA;
	wire signed [63:0] vB;
	wire signed [63:0] vC;
	wire [15:0] x_lo_i;
	wire [15:0] x_hi_i;
	wire [15:0] y_lo_i;
	wire [15:0] y_hi_i;
	wire signed [32:0] dx01;
	wire signed [32:0] dy01;
	wire signed [32:0] dx12;
	wire signed [32:0] dy12;
	wire signed [32:0] dx20;
	wire signed [32:0] dy20;
	ember_rtr_setup u_setup(
		.x0(vx0),
		.y0(vy0),
		.x1(vx1),
		.y1(vy1),
		.x2(vx2),
		.y2(vy2),
		.u0(vu0),
		.v0(vv0),
		.u1(vu1),
		.v1(vv1),
		.u2(vu2),
		.v2(vv2),
		.z0(vz0),
		.z1(vz1),
		.z2(vz2),
		.r0(vr0),
		.g0(vg0),
		.b0(vb0),
		.r1(vr1),
		.g1(vg1),
		.b1(vb1),
		.r2(vr2),
		.g2(vg2),
		.b2(vb2),
		.cull(cull),
		.area(),
		.iwA(iwA),
		.iwB(iwB),
		.iwC(iwC),
		.rA(rA),
		.rB(rB),
		.rC(rC),
		.gA(gA),
		.gB(gB),
		.gC(gC),
		.bA(bA),
		.bB(bB),
		.bC(bC),
		.zA(zA),
		.zB(zB),
		.zC(zC),
		.uA(uA),
		.uB(uB),
		.uC(uC),
		.vA(vA),
		.vB(vB),
		.vC(vC),
		.x_lo_i(x_lo_i),
		.x_hi_i(x_hi_i),
		.y_lo_i(y_lo_i),
		.y_hi_i(y_hi_i),
		.dx01(dx01),
		.dy01(dy01),
		.dx12(dx12),
		.dy12(dy12),
		.dx20(dx20),
		.dy20(dy20)
	);
	wire scan_fpa_we;
	wire [31:0] scan_fpa_addr;
	wire [31:0] scan_fpa_wdata;
	wire [3:0] scan_fpa_be;
	wire scan_fpa_req;
	ember_rtr_scan u_scan(
		.clk(clk),
		.rst_n(rst_n),
		.start(scan_start),
		.t_blend(cmd_q[0][1]),
		.t_ztest(cmd_q[0][2]),
		.t_tex(cmd_q[0][3]),
		.t_dither(cmd_q[0][4]),
		.t_rgbmap(cmd_q[0][5]),
		.t_texpage(cmd_q[0][15:8]),
		.iwA(iwA),
		.iwB(iwB),
		.iwC(iwC),
		.rA(rA),
		.rB(rB),
		.rC(rC),
		.gA(gA),
		.gB(gB),
		.gC(gC),
		.bA(bA),
		.bB(bB),
		.bC(bC),
		.zA(zA),
		.zB(zB),
		.zC(zC),
		.uA(uA),
		.uB(uB),
		.uC(uC),
		.vA(vA),
		.vB(vB),
		.vC(vC),
		.x_lo_i(x_lo_i),
		.x_hi_i(x_hi_i),
		.y_lo_i(y_lo_i),
		.y_hi_i(y_hi_i),
		.x0(vx0),
		.y0(vy0),
		.x1(vx1),
		.y1(vy1),
		.x2(vx2),
		.y2(vy2),
		.dx01(dx01),
		.dy01(dy01),
		.dx12(dx12),
		.dy12(dy12),
		.dx20(dx20),
		.dy20(dy20),
		.fpa_we(scan_fpa_we),
		.fpa_addr(scan_fpa_addr),
		.fpa_wdata(scan_fpa_wdata),
		.fpa_be(scan_fpa_be),
		.fpa_req(scan_fpa_req),
		.fpa_rdata(fpa_rdata),
		.fpa2_req(fpa2_req),
		.fpa2_addr(fpa2_addr),
		.fpa2_rdata(fpa2_rdata),
		.busy(scan_busy),
		.done(scan_done)
	);
	wire in_fetch = (fst == 3'd1) || (fst == 3'd2);
	assign fpa_req = (in_fetch ? fetch_req : scan_fpa_req);
	assign fpa_we = (in_fetch ? 1'b0 : scan_fpa_we);
	assign fpa_addr = (in_fetch ? fetch_addr : scan_fpa_addr);
	assign fpa_wdata = (in_fetch ? 32'h00000000 : scan_fpa_wdata);
	assign fpa_be = (in_fetch ? 4'hf : scan_fpa_be);
endmodule