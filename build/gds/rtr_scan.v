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