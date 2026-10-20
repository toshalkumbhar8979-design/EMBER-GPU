module ember_xbar (
	clk,
	rst_n,
	h_aw,
	h_awvalid,
	h_awready,
	h_w,
	h_wvalid,
	h_wready,
	h_b,
	h_bvalid,
	h_bready,
	h_ar,
	h_arvalid,
	h_arready,
	h_r,
	h_rvalid,
	h_rready,
	d_aw,
	d_awvalid,
	d_awready,
	d_w,
	d_wvalid,
	d_wready,
	d_b,
	d_bvalid,
	d_bready,
	d_ar,
	d_arvalid,
	d_arready,
	d_r,
	d_rvalid,
	d_rready,
	c_aw,
	c_awvalid,
	c_awready,
	c_w,
	c_wvalid,
	c_wready,
	c_b,
	c_bvalid,
	c_bready,
	c_ar,
	c_arvalid,
	c_arready,
	c_r,
	c_rvalid,
	c_rready,
	v_aw,
	v_awvalid,
	v_awready,
	v_w,
	v_wvalid,
	v_wready,
	v_b,
	v_bvalid,
	v_bready,
	v_ar,
	v_arvalid,
	v_arready,
	v_r,
	v_rvalid,
	v_rready
);
	input wire clk;
	input wire rst_n;
	localparam [31:0] ember_pkg_AXI_ADDR_W = 32;
	input wire [34:0] h_aw;
	input wire h_awvalid;
	output wire h_awready;
	localparam [31:0] ember_pkg_AXI_DATA_W = 32;
	localparam [31:0] ember_pkg_AXI_STRB_W = 4;
	input wire [(ember_pkg_AXI_DATA_W + ember_pkg_AXI_STRB_W) - 1:0] h_w;
	input wire h_wvalid;
	output wire h_wready;
	output wire [1:0] h_b;
	output wire h_bvalid;
	input wire h_bready;
	input wire [34:0] h_ar;
	input wire h_arvalid;
	output wire h_arready;
	output wire [33:0] h_r;
	output wire h_rvalid;
	input wire h_rready;
	input wire [34:0] d_aw;
	input wire d_awvalid;
	output wire d_awready;
	input wire [(ember_pkg_AXI_DATA_W + ember_pkg_AXI_STRB_W) - 1:0] d_w;
	input wire d_wvalid;
	output wire d_wready;
	output wire [1:0] d_b;
	output wire d_bvalid;
	input wire d_bready;
	input wire [34:0] d_ar;
	input wire d_arvalid;
	output wire d_arready;
	output wire [33:0] d_r;
	output wire d_rvalid;
	input wire d_rready;
	output wire [34:0] c_aw;
	output wire c_awvalid;
	input wire c_awready;
	output wire [(ember_pkg_AXI_DATA_W + ember_pkg_AXI_STRB_W) - 1:0] c_w;
	output wire c_wvalid;
	input wire c_wready;
	input wire [1:0] c_b;
	input wire c_bvalid;
	output wire c_bready;
	output wire [34:0] c_ar;
	output wire c_arvalid;
	input wire c_arready;
	input wire [33:0] c_r;
	input wire c_rvalid;
	output wire c_rready;
	output wire [34:0] v_aw;
	output wire v_awvalid;
	input wire v_awready;
	output wire [(ember_pkg_AXI_DATA_W + ember_pkg_AXI_STRB_W) - 1:0] v_w;
	output wire v_wvalid;
	input wire v_wready;
	input wire [1:0] v_b;
	input wire v_bvalid;
	output wire v_bready;
	output wire [34:0] v_ar;
	output wire v_arvalid;
	input wire v_arready;
	input wire [33:0] v_r;
	input wire v_rvalid;
	output wire v_rready;
	wire h_aw_is_cp = h_aw[34:15] == 20'h00000;
	wire h_ar_is_cp = h_ar[34:15] == 20'h00000;
	wire h_req_v_w = h_awvalid && !h_aw_is_cp;
	wire h_req_v_r = h_arvalid && !h_ar_is_cp;
	wire d_req_v_w = d_awvalid;
	wire d_req_v_r = d_arvalid;
	reg [1:0] wstate;
	always @(posedge clk or negedge rst_n)
		if (!rst_n)
			wstate <= 2'd0;
		else
			case (wstate)
				2'd0:
					if (h_req_v_w)
						wstate <= 2'd1;
					else if (d_req_v_w)
						wstate <= 2'd2;
				2'd1, 2'd2:
					if (v_bvalid && v_bready)
						wstate <= 2'd0;
				default: wstate <= 2'd0;
			endcase
	reg w_favor_d;
	always @(posedge clk or negedge rst_n)
		if (!rst_n)
			w_favor_d <= 1'b0;
		else if (wstate == 2'd1)
			w_favor_d <= 1'b1;
		else if (wstate == 2'd2)
			w_favor_d <= 1'b0;
		else if (((wstate == 2'd0) && h_req_v_w) && d_req_v_w)
			w_favor_d <= ~w_favor_d;
	wire w_fwd_h = ((wstate == 2'd0) && h_req_v_w) && (!d_req_v_w || !w_favor_d);
	wire w_fwd_d = ((wstate == 2'd0) && d_req_v_w) && (!h_req_v_w || w_favor_d);
	assign v_aw = (w_fwd_h ? h_aw : d_aw);
	assign v_awvalid = w_fwd_h || w_fwd_d;
	assign v_w = (w_fwd_h ? h_w : d_w);
	assign v_wvalid = (w_fwd_h && h_wvalid) || (w_fwd_d && d_wvalid);
	assign h_awready = (h_aw_is_cp ? c_awready : w_fwd_h && v_awready);
	assign h_wready = (h_aw_is_cp ? c_wready : w_fwd_h && v_wready);
	assign d_awready = w_fwd_d && v_awready;
	assign d_wready = w_fwd_d && v_wready;
	assign c_aw = h_aw;
	assign c_awvalid = h_awvalid && h_aw_is_cp;
	assign c_w = h_w;
	assign c_wvalid = h_wvalid && h_aw_is_cp;
	assign h_bvalid = (wstate == 2'd1 ? v_bvalid : c_bvalid);
	assign h_b = (wstate == 2'd1 ? v_b : c_b);
	assign c_bready = (wstate == 2'd1 ? 1'b0 : h_bready);
	assign v_bready = (wstate == 2'd1 ? h_bready : (wstate == 2'd2 ? d_bready : 1'b0));
	assign d_bvalid = (wstate == 2'd2 ? v_bvalid : 1'b0);
	assign d_b = v_b;
	reg [1:0] rstate;
	always @(posedge clk or negedge rst_n)
		if (!rst_n)
			rstate <= 2'd0;
		else
			case (rstate)
				2'd0:
					if (h_req_v_r)
						rstate <= 2'd1;
					else if (d_req_v_r)
						rstate <= 2'd2;
				2'd1, 2'd2:
					if (v_rvalid && v_rready)
						rstate <= 2'd0;
				default: rstate <= 2'd0;
			endcase
	reg r_favor_d;
	always @(posedge clk or negedge rst_n)
		if (!rst_n)
			r_favor_d <= 1'b0;
		else if (rstate == 2'd1)
			r_favor_d <= 1'b1;
		else if (rstate == 2'd2)
			r_favor_d <= 1'b0;
		else if (((rstate == 2'd0) && h_req_v_r) && d_req_v_r)
			r_favor_d <= ~r_favor_d;
	wire r_fwd_h = ((rstate == 2'd0) && h_req_v_r) && (!d_req_v_r || !r_favor_d);
	wire r_fwd_d = ((rstate == 2'd0) && d_req_v_r) && (!h_req_v_r || r_favor_d);
	assign v_ar = (r_fwd_h ? h_ar : d_ar);
	assign v_arvalid = r_fwd_h || r_fwd_d;
	assign h_arready = (h_ar_is_cp ? c_arready : r_fwd_h && v_arready);
	assign d_arready = r_fwd_d && v_arready;
	assign c_ar = h_ar;
	assign c_arvalid = h_arvalid && h_ar_is_cp;
	assign h_rvalid = (rstate == 2'd1 ? v_rvalid : c_rvalid);
	assign h_r = (rstate == 2'd1 ? v_r : c_r);
	assign c_rready = (rstate == 2'd1 ? 1'b0 : h_rready);
	assign v_rready = (rstate == 2'd1 ? h_rready : (rstate == 2'd2 ? d_rready : 1'b0));
	assign d_rvalid = (rstate == 2'd2 ? v_rvalid : 1'b0);
	assign d_r = v_r;
	wire _unused_dma_rdy = d_bready && d_rready;
endmodule