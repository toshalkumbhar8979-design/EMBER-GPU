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
