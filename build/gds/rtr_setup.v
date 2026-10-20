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