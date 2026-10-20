module ember_display (
	clk,
	rst_n,
	fb_select,
	fpa3_req,
	fpa3_addr,
	fpa3_rdata,
	vid_hs,
	vid_vs,
	vid_de,
	vid_pixel
);
	input wire clk;
	input wire rst_n;
	input wire [1:0] fb_select;
	output wire fpa3_req;
	output wire [31:0] fpa3_addr;
	input wire [31:0] fpa3_rdata;
	output wire vid_hs;
	output wire vid_vs;
	output wire vid_de;
	output wire [15:0] vid_pixel;
	localparam [31:0] H_VISIBLE = 640;
	localparam [31:0] H_FP = 16;
	localparam [31:0] H_SYNC = 96;
	localparam [31:0] H_BP = 48;
	localparam [31:0] H_TOTAL = ((H_VISIBLE + H_FP) + H_SYNC) + H_BP;
	localparam [31:0] V_VISIBLE = 480;
	localparam [31:0] V_FP = 10;
	localparam [31:0] V_SYNC = 2;
	localparam [31:0] V_BP = 33;
	localparam [31:0] V_TOTAL = ((V_VISIBLE + V_FP) + V_SYNC) + V_BP;
	localparam [31:0] VID_LAT = 4;
	localparam [31:0] ember_pkg_FB0_BASE = 32'h00000000;
	localparam [31:0] ember_pkg_CP_BASE = 32'h00000000;
	localparam [31:0] ember_pkg_CP_WINDOW_BYTES = 4096;
	localparam [31:0] ember_pkg_VRAM_BASE = ember_pkg_CP_BASE + ember_pkg_CP_WINDOW_BYTES;
	localparam [31:0] FB_BUS = ember_pkg_VRAM_BASE + ember_pkg_FB0_BASE;
	reg [10:0] hcnt;
	reg [10:0] vcnt;
	function automatic [10:0] sv2v_cast_11;
		input reg [10:0] inp;
		sv2v_cast_11 = inp;
	endfunction
	wire h_visible = hcnt < sv2v_cast_11(H_VISIBLE);
	wire v_visible = vcnt < sv2v_cast_11(V_VISIBLE);
	wire de_now = h_visible && v_visible;
	wire hs_now = (hcnt >= sv2v_cast_11(H_VISIBLE + H_FP)) && (hcnt < sv2v_cast_11((H_VISIBLE + H_FP) + H_SYNC));
	wire vs_now = (vcnt >= sv2v_cast_11(V_VISIBLE + V_FP)) && (vcnt < sv2v_cast_11((V_VISIBLE + V_FP) + V_SYNC));
	always @(posedge clk or negedge rst_n)
		if (!rst_n) begin
			hcnt <= 1'sb0;
			vcnt <= 1'sb0;
		end
		else if (hcnt == sv2v_cast_11(H_TOTAL - 1)) begin
			hcnt <= 1'sb0;
			vcnt <= (vcnt == sv2v_cast_11(V_TOTAL - 1) ? {11 {1'sb0}} : vcnt + 11'sd1);
		end
		else
			hcnt <= hcnt + 11'sd1;
	wire [9:0] vrow = vcnt[10:1];
	wire [9:0] vcol = hcnt[10:1];
	wire odd_x = vcol[0];
	function automatic [31:0] sv2v_cast_32;
		input reg [31:0] inp;
		sv2v_cast_32 = inp;
	endfunction
	wire [31:0] word_byte_off = (sv2v_cast_32(vrow) * 32'd640) + (sv2v_cast_32({vcol[9:1], 1'b0}) * 32'd2);
	reg req_q;
	reg [31:0] addr_q;
	always @(posedge clk or negedge rst_n)
		if (!rst_n) begin
			req_q <= 1'b0;
			addr_q <= 1'sb0;
		end
		else begin
			req_q <= de_now;
			if (de_now)
				addr_q <= FB_BUS + word_byte_off;
		end
	assign fpa3_req = req_q;
	assign fpa3_addr = addr_q;
	reg [31:0] word_q1;
	reg [31:0] word_q2;
	reg de_d1;
	reg de_d2;
	reg de_d3;
	reg de_d4;
	reg hs_d1;
	reg hs_d2;
	reg hs_d3;
	reg hs_d4;
	reg vs_d1;
	reg vs_d2;
	reg vs_d3;
	reg vs_d4;
	reg odd_d1;
	reg odd_d2;
	reg odd_d3;
	reg odd_d4;
	always @(posedge clk or negedge rst_n)
		if (!rst_n) begin
			word_q1 <= 1'sb0;
			word_q2 <= 1'sb0;
			de_d1 <= 1'b0;
			de_d2 <= 1'b0;
			de_d3 <= 1'b0;
			de_d4 <= 1'b0;
			hs_d1 <= 1'b0;
			hs_d2 <= 1'b0;
			hs_d3 <= 1'b0;
			hs_d4 <= 1'b0;
			vs_d1 <= 1'b0;
			vs_d2 <= 1'b0;
			vs_d3 <= 1'b0;
			vs_d4 <= 1'b0;
			odd_d1 <= 1'b0;
			odd_d2 <= 1'b0;
			odd_d3 <= 1'b0;
			odd_d4 <= 1'b0;
		end
		else begin
			word_q1 <= fpa3_rdata;
			word_q2 <= word_q1;
			de_d1 <= de_now;
			de_d2 <= de_d1;
			de_d3 <= de_d2;
			de_d4 <= de_d3;
			hs_d1 <= hs_now;
			hs_d2 <= hs_d1;
			hs_d3 <= hs_d2;
			hs_d4 <= hs_d3;
			vs_d1 <= vs_now;
			vs_d2 <= vs_d1;
			vs_d3 <= vs_d2;
			vs_d4 <= vs_d3;
			odd_d1 <= odd_x;
			odd_d2 <= odd_d1;
			odd_d3 <= odd_d2;
			odd_d4 <= odd_d3;
		end
	assign vid_de = de_d4;
	assign vid_hs = hs_d4;
	assign vid_vs = vs_d4;
	assign vid_pixel = (de_d4 ? (odd_d4 ? word_q2[31:16] : word_q2[15:0]) : 16'h0000);
	wire _unused = |fb_select;
endmodule