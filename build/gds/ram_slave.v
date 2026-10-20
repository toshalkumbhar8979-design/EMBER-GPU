module ember_ram_slave (
	clk,
	rst_n,
	s_aw,
	s_awvalid,
	s_awready,
	s_w,
	s_wvalid,
	s_wready,
	s_b,
	s_bvalid,
	s_bready,
	s_ar,
	s_arvalid,
	s_arready,
	s_r,
	s_rvalid,
	s_rready,
	reg_addr,
	reg_be,
	reg_wdata,
	reg_wr_en,
	rd_addr,
	rd_data
);
	input wire clk;
	input wire rst_n;
	localparam [31:0] ember_pkg_AXI_ADDR_W = 32;
	input wire [34:0] s_aw;
	input wire s_awvalid;
	output wire s_awready;
	localparam [31:0] ember_pkg_AXI_DATA_W = 32;
	localparam [31:0] ember_pkg_AXI_STRB_W = 4;
	input wire [(ember_pkg_AXI_DATA_W + ember_pkg_AXI_STRB_W) - 1:0] s_w;
	input wire s_wvalid;
	output wire s_wready;
	output reg [1:0] s_b;
	output reg s_bvalid;
	input wire s_bready;
	input wire [34:0] s_ar;
	input wire s_arvalid;
	output wire s_arready;
	output reg [33:0] s_r;
	output wire s_rvalid;
	input wire s_rready;
	output reg [11:0] reg_addr;
	output reg [3:0] reg_be;
	output reg [31:0] reg_wdata;
	output reg reg_wr_en;
	output wire [11:0] rd_addr;
	input wire [31:0] rd_data;
	reg aw_v;
	reg w_v;
	reg [34:0] aw_q;
	reg [(ember_pkg_AXI_DATA_W + ember_pkg_AXI_STRB_W) - 1:0] w_q;
	wire wr_fire = (aw_v && w_v) && (!s_bvalid || s_bready);
	always @(posedge clk or negedge rst_n)
		if (!rst_n) begin
			aw_v <= 1'b0;
			aw_q <= 1'sb0;
		end
		else if (s_awvalid && s_awready) begin
			aw_v <= 1'b1;
			aw_q <= s_aw;
		end
		else if (wr_fire)
			aw_v <= 1'b0;
	always @(posedge clk or negedge rst_n)
		if (!rst_n) begin
			w_v <= 1'b0;
			w_q <= 1'sb0;
		end
		else if (s_wvalid && s_wready) begin
			w_v <= 1'b1;
			w_q <= s_w;
		end
		else if (wr_fire)
			w_v <= 1'b0;
	assign s_awready = !aw_v || wr_fire;
	assign s_wready = !w_v || wr_fire;
	always @(posedge clk)
		if (wr_fire) begin
			reg_wr_en <= 1'b1;
			reg_addr <= aw_q[14:3];
			reg_be <= w_q[3-:ember_pkg_AXI_STRB_W];
			reg_wdata <= w_q[35-:32];
		end
		else
			reg_wr_en <= 1'b0;
	localparam [1:0] ember_pkg_RESP_OKAY = 2'b00;
	always @(posedge clk or negedge rst_n)
		if (!rst_n) begin
			s_bvalid <= 1'b0;
			s_b[1-:2] <= ember_pkg_RESP_OKAY;
		end
		else if (wr_fire) begin
			s_bvalid <= 1'b1;
			s_b[1-:2] <= ember_pkg_RESP_OKAY;
		end
		else if (s_bvalid && s_bready)
			s_bvalid <= 1'b0;
	reg ar_v;
	wire ar_accept = s_arvalid && s_arready;
	always @(posedge clk or negedge rst_n)
		if (!rst_n)
			ar_v <= 1'b0;
		else if (ar_accept)
			ar_v <= 1'b1;
		else if (s_rvalid && s_rready)
			ar_v <= 1'b0;
	assign rd_addr = (ar_accept ? s_ar[14:3] : 12'h000);
	always @(posedge clk)
		if (ar_accept) begin
			s_r[33-:32] <= rd_data;
			s_r[1-:2] <= ember_pkg_RESP_OKAY;
		end
	assign s_arready = !ar_v || (s_rvalid && s_rready);
	assign s_rvalid = ar_v;
endmodule