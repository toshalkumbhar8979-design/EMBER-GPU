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
module ember_vram (
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
	dbg_en,
	dbg_addr,
	dbg_rdata,
	dbg_wdata,
	dbg_be,
	fpa_we,
	fpa_addr,
	fpa_wdata,
	fpa_be,
	fpa_req,
	fpa_rdata,
	fpa2_we,
	fpa2_addr,
	fpa2_wdata,
	fpa2_be,
	fpa2_req,
	fpa2_rdata,
	fpa3_req,
	fpa3_addr,
	fpa3_rdata,
	gxa_we,
	gxa_addr,
	gxa_wdata,
	gxa_be,
	gxa_req,
	gxa_rdata,
	cxa_we,
	cxa_addr,
	cxa_wdata,
	cxa_be,
	cxa_req,
	cxa_rdata,
	ixa_req,
	ixa_addr,
	ixa_rdata,
	tua_we,
	tua_addr,
	tua_wdata,
	tua_be,
	tua_req,
	tua_rdata
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
	output wire [33:0] s_r;
	output wire s_rvalid;
	input wire s_rready;
	input wire dbg_en;
	localparam [31:0] ember_pkg_VRAM_BYTES = 524288;
	localparam [31:0] ember_pkg_VRAM_AW = 19;
	input wire [16:0] dbg_addr;
	output wire [31:0] dbg_rdata;
	input wire [31:0] dbg_wdata;
	input wire [3:0] dbg_be;
	input wire fpa_we;
	input wire [31:0] fpa_addr;
	input wire [31:0] fpa_wdata;
	input wire [3:0] fpa_be;
	input wire fpa_req;
	output wire [31:0] fpa_rdata;
	input wire fpa2_we;
	input wire [31:0] fpa2_addr;
	input wire [31:0] fpa2_wdata;
	input wire [3:0] fpa2_be;
	input wire fpa2_req;
	output wire [31:0] fpa2_rdata;
	input wire fpa3_req;
	input wire [31:0] fpa3_addr;
	output wire [31:0] fpa3_rdata;
	input wire gxa_we;
	input wire [31:0] gxa_addr;
	input wire [31:0] gxa_wdata;
	input wire [3:0] gxa_be;
	input wire gxa_req;
	output wire [31:0] gxa_rdata;
	input wire cxa_we;
	input wire [31:0] cxa_addr;
	input wire [31:0] cxa_wdata;
	input wire [3:0] cxa_be;
	input wire cxa_req;
	output wire [31:0] cxa_rdata;
	input wire ixa_req;
	input wire [31:0] ixa_addr;
	output wire [31:0] ixa_rdata;
	input wire tua_we;
	input wire [31:0] tua_addr;
	input wire [31:0] tua_wdata;
	input wire [3:0] tua_be;
	input wire tua_req;
	output wire [31:0] tua_rdata;
	localparam [31:0] RAM_WORDS = 131072;
	reg [31:0] ram [0:131071];
	localparam [31:0] ember_pkg_CP_BASE = 32'h00000000;
	localparam [31:0] ember_pkg_CP_WINDOW_BYTES = 4096;
	localparam [31:0] ember_pkg_VRAM_BASE = ember_pkg_CP_BASE + ember_pkg_CP_WINDOW_BYTES;
	function automatic [16:0] addr2word;
		input reg [31:0] a;
		reg [31:0] off;
		begin
			off = a - ember_pkg_VRAM_BASE;
			addr2word = off[18:2];
		end
	endfunction
	reg [34:0] aw_q;
	reg aw_v;
	reg [(ember_pkg_AXI_DATA_W + ember_pkg_AXI_STRB_W) - 1:0] w_q;
	reg w_v;
	wire wr_fire = (aw_v && w_v) && (!s_bvalid || s_bready);
	always @(posedge clk or negedge rst_n)
		if (!rst_n) begin
			aw_q <= 1'sb0;
			aw_v <= 1'b0;
		end
		else if (s_awvalid && s_awready) begin
			aw_q <= s_aw;
			aw_v <= 1'b1;
		end
		else if (wr_fire)
			aw_v <= 1'b0;
	always @(posedge clk or negedge rst_n)
		if (!rst_n) begin
			w_q <= 1'sb0;
			w_v <= 1'b0;
		end
		else if (s_wvalid && s_wready) begin
			w_q <= s_w;
			w_v <= 1'b1;
		end
		else if (wr_fire)
			w_v <= 1'b0;
	assign s_awready = !aw_v || wr_fire;
	assign s_wready = !w_v || wr_fire;
	always @(posedge clk)
		if (wr_fire) begin
			if (w_q[0])
				ram[addr2word(aw_q[34-:32])][7:0] <= w_q[11:4];
			if (w_q[1])
				ram[addr2word(aw_q[34-:32])][15:8] <= w_q[19:12];
			if (w_q[2])
				ram[addr2word(aw_q[34-:32])][23:16] <= w_q[27:20];
			if (w_q[3])
				ram[addr2word(aw_q[34-:32])][31:24] <= w_q[35:28];
		end
	always @(posedge clk)
		if (dbg_en && |dbg_be) begin
			if (dbg_be[0])
				ram[dbg_addr][7:0] <= dbg_wdata[7:0];
			if (dbg_be[1])
				ram[dbg_addr][15:8] <= dbg_wdata[15:8];
			if (dbg_be[2])
				ram[dbg_addr][23:16] <= dbg_wdata[23:16];
			if (dbg_be[3])
				ram[dbg_addr][31:24] <= dbg_wdata[31:24];
		end
	wire [16:0] fpa_widx = addr2word(fpa_addr);
	wire [16:0] fpa2_widx = addr2word(fpa2_addr);
	always @(posedge clk)
		if (fpa_we) begin
			if (fpa_be[0])
				ram[fpa_widx][7:0] <= fpa_wdata[7:0];
			if (fpa_be[1])
				ram[fpa_widx][15:8] <= fpa_wdata[15:8];
			if (fpa_be[2])
				ram[fpa_widx][23:16] <= fpa_wdata[23:16];
			if (fpa_be[3])
				ram[fpa_widx][31:24] <= fpa_wdata[31:24];
		end
	reg [31:0] fpa_rdata_q;
	always @(posedge clk)
		if (fpa_req)
			fpa_rdata_q <= ram[fpa_widx];
	assign fpa_rdata = fpa_rdata_q;
	reg [31:0] fpa2_rdata_q;
	always @(posedge clk)
		if (fpa2_req)
			fpa2_rdata_q <= ram[fpa2_widx];
	assign fpa2_rdata = fpa2_rdata_q;
	wire [16:0] fpa3_widx = addr2word(fpa3_addr);
	reg [31:0] fpa3_rdata_q;
	always @(posedge clk)
		if (fpa3_req)
			fpa3_rdata_q <= ram[fpa3_widx];
	assign fpa3_rdata = fpa3_rdata_q;
	wire [16:0] gxa_widx = addr2word(gxa_addr);
	always @(posedge clk)
		if (gxa_we) begin
			if (gxa_be[0])
				ram[gxa_widx][7:0] <= gxa_wdata[7:0];
			if (gxa_be[1])
				ram[gxa_widx][15:8] <= gxa_wdata[15:8];
			if (gxa_be[2])
				ram[gxa_widx][23:16] <= gxa_wdata[23:16];
			if (gxa_be[3])
				ram[gxa_widx][31:24] <= gxa_wdata[31:24];
		end
	reg [31:0] gxa_rdata_q;
	always @(posedge clk)
		if (gxa_req)
			gxa_rdata_q <= ram[gxa_widx];
	assign gxa_rdata = gxa_rdata_q;
	wire [16:0] cxa_widx = addr2word(cxa_addr);
	always @(posedge clk)
		if (cxa_we) begin
			if (cxa_be[0])
				ram[cxa_widx][7:0] <= cxa_wdata[7:0];
			if (cxa_be[1])
				ram[cxa_widx][15:8] <= cxa_wdata[15:8];
			if (cxa_be[2])
				ram[cxa_widx][23:16] <= cxa_wdata[23:16];
			if (cxa_be[3])
				ram[cxa_widx][31:24] <= cxa_wdata[31:24];
		end
	reg [31:0] cxa_rdata_q;
	always @(posedge clk)
		if (cxa_req)
			cxa_rdata_q <= ram[cxa_widx];
	assign cxa_rdata = cxa_rdata_q;
	wire [16:0] ixa_widx = addr2word(ixa_addr);
	reg [31:0] ixa_rdata_q;
	always @(posedge clk)
		if (ixa_req)
			ixa_rdata_q <= ram[ixa_widx];
	assign ixa_rdata = ixa_rdata_q;
	wire [16:0] tua_widx = addr2word(tua_addr);
	always @(posedge clk)
		if (tua_we) begin
			if (tua_be[0])
				ram[tua_widx][7:0] <= tua_wdata[7:0];
			if (tua_be[1])
				ram[tua_widx][15:8] <= tua_wdata[15:8];
			if (tua_be[2])
				ram[tua_widx][23:16] <= tua_wdata[23:16];
			if (tua_be[3])
				ram[tua_widx][31:24] <= tua_wdata[31:24];
		end
	reg [31:0] tua_rdata_q;
	always @(posedge clk)
		if (tua_req)
			tua_rdata_q <= ram[tua_widx];
	assign tua_rdata = tua_rdata_q;
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
	assign s_arready = !ar_v || (s_rvalid && s_rready);
	reg [31:0] rdata_q;
	always @(posedge clk)
		if (ar_accept)
			rdata_q <= ram[addr2word(s_ar[34-:32])];
	assign s_r[33-:32] = rdata_q;
	assign s_r[1-:2] = ember_pkg_RESP_OKAY;
	assign s_rvalid = ar_v;
	reg [31:0] dbg_rdata_q;
	always @(posedge clk)
		if (dbg_en)
			dbg_rdata_q <= ram[dbg_addr];
	assign dbg_rdata = dbg_rdata_q;
endmodule
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
module ember_cp (
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
	m_aw,
	m_awvalid,
	m_awready,
	m_w,
	m_wvalid,
	m_wready,
	m_b,
	m_bvalid,
	m_bready,
	m_ar,
	m_arvalid,
	m_arready,
	m_r,
	m_rvalid,
	m_rready,
	rtr_kick,
	rtr_busy,
	blit_csr_we,
	blit_csr_addr,
	blit_csr_wdata,
	blit_kick,
	blit_busy,
	gsx_csr_we,
	gsx_csr_addr,
	gsx_csr_wdata,
	gsx_kick,
	gsx_busy,
	core_csr_we,
	core_csr_addr,
	core_csr_wdata,
	core_kick,
	core_busy,
	tu_csr_we,
	tu_csr_addr,
	tu_csr_wdata,
	tu_kick,
	tu_busy
);
	reg _sv2v_0;
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
	output wire [1:0] s_b;
	output wire s_bvalid;
	input wire s_bready;
	input wire [34:0] s_ar;
	input wire s_arvalid;
	output wire s_arready;
	output wire [33:0] s_r;
	output wire s_rvalid;
	input wire s_rready;
	output reg [34:0] m_aw;
	output reg m_awvalid;
	input wire m_awready;
	output reg [(ember_pkg_AXI_DATA_W + ember_pkg_AXI_STRB_W) - 1:0] m_w;
	output reg m_wvalid;
	input wire m_wready;
	input wire [1:0] m_b;
	input wire m_bvalid;
	output wire m_bready;
	output reg [34:0] m_ar;
	output reg m_arvalid;
	input wire m_arready;
	input wire [33:0] m_r;
	input wire m_rvalid;
	output wire m_rready;
	output wire rtr_kick;
	input wire rtr_busy;
	output wire blit_csr_we;
	output wire [1:0] blit_csr_addr;
	output wire [31:0] blit_csr_wdata;
	output wire blit_kick;
	input wire blit_busy;
	output wire gsx_csr_we;
	output wire [1:0] gsx_csr_addr;
	output wire [31:0] gsx_csr_wdata;
	output wire gsx_kick;
	input wire gsx_busy;
	output wire core_csr_we;
	output wire [1:0] core_csr_addr;
	output wire [31:0] core_csr_wdata;
	output wire core_kick;
	input wire core_busy;
	output wire tu_csr_we;
	output wire [1:0] tu_csr_addr;
	output wire [31:0] tu_csr_wdata;
	output wire tu_kick;
	input wire tu_busy;
	wire [11:0] reg_addr;
	wire [3:0] reg_be;
	wire [31:0] reg_wdata;
	wire reg_wr_en;
	wire [11:0] rd_addr;
	reg [31:0] dma_dst_q;
	reg [31:0] dma_len_q;
	reg [7:0] fence_pend_q;
	reg [7:0] fence_done_q;
	reg dma_busy_q;
	localparam [11:0] ember_pkg_CP_CMDX = 12'h01c;
	localparam [11:0] ember_pkg_CP_DMA_DST = 12'h014;
	localparam [11:0] ember_pkg_CP_DMA_LEN = 12'h018;
	always @(posedge clk or negedge rst_n)
		if (!rst_n) begin
			dma_dst_q <= 32'h00000000;
			dma_len_q <= 32'h00000000;
			fence_pend_q <= 8'h00;
			fence_done_q <= 8'h00;
			dma_busy_q <= 1'b0;
		end
		else if (reg_wr_en) begin
			if (reg_be[0])
				case (reg_addr)
					ember_pkg_CP_DMA_DST: dma_dst_q <= reg_wdata;
					ember_pkg_CP_DMA_LEN: dma_len_q <= reg_wdata;
					ember_pkg_CP_CMDX: fence_pend_q <= reg_wdata[15:8];
					default:
						;
				endcase
		end
	localparam [31:0] UP_DEPTH = 64;
	localparam [31:0] UP_AW = 6;
	reg [31:0] up_mem [0:63];
	reg [UP_AW:0] up_wp;
	reg [UP_AW:0] up_rp;
	wire up_full = (up_wp[UP_AW] != up_rp[UP_AW]) && (up_wp[5:0] == up_rp[5:0]);
	wire up_empty = up_wp == up_rp;
	localparam [11:0] ember_pkg_CP_FIFOD = 12'h010;
	wire up_push = (reg_wr_en && (reg_addr == ember_pkg_CP_FIFOD)) && reg_be[0];
	reg up_pop;
	wire [31:0] up_front = up_mem[up_rp[5:0]];
	always @(posedge clk or negedge rst_n)
		if (!rst_n)
			up_wp <= 1'sb0;
		else if (up_push && !up_full) begin
			up_mem[up_wp[5:0]] <= reg_wdata;
			up_wp <= up_wp + 1'b1;
		end
	always @(posedge clk or negedge rst_n)
		if (!rst_n)
			up_rp <= 1'sb0;
		else if (up_pop)
			up_rp <= up_rp + 1'b1;
	localparam [31:0] RB_DEPTH = 8;
	localparam [31:0] RB_AW = 3;
	reg [31:0] rb_mem [0:7];
	reg [RB_AW:0] rb_wp;
	reg [RB_AW:0] rb_rp;
	wire rb_full = (rb_wp[RB_AW] != rb_rp[RB_AW]) && (rb_wp[2:0] == rb_rp[2:0]);
	wire rb_empty = rb_wp == rb_rp;
	wire rb_push = m_rvalid;
	wire [31:0] rb_data_in = m_r[33-:32];
	always @(posedge clk or negedge rst_n)
		if (!rst_n)
			rb_wp <= 1'sb0;
		else if (rb_push && !rb_full) begin
			rb_mem[rb_wp[2:0]] <= rb_data_in;
			rb_wp <= rb_wp + 1'b1;
		end
	wire rb_pop = (s_arvalid && s_arready) && (s_ar[14:3] == ember_pkg_CP_FIFOD);
	always @(posedge clk or negedge rst_n)
		if (!rst_n)
			rb_rp <= 1'sb0;
		else if (rb_pop && !rb_empty)
			rb_rp <= rb_rp + 1'b1;
	reg [1:0] dstate;
	reg [31:0] dma_addr_q;
	reg [31:0] dma_left_q;
	reg r_pend_q;
	reg w_busy_q;
	localparam [11:0] ember_pkg_CP_CTRL = 12'h008;
	localparam [31:0] ember_pkg_CP_BASE = 32'h00000000;
	localparam [31:0] ember_pkg_CP_WINDOW_BYTES = 4096;
	localparam [31:0] ember_pkg_VRAM_BASE = ember_pkg_CP_BASE + ember_pkg_CP_WINDOW_BYTES;
	always @(posedge clk or negedge rst_n)
		if (!rst_n) begin
			dstate <= 2'd0;
			dma_addr_q <= 32'h00000000;
			dma_left_q <= 32'h00000000;
			dma_busy_q <= 1'b0;
			fence_done_q <= 8'h00;
			r_pend_q <= 1'b0;
			w_busy_q <= 1'b0;
			up_pop <= 1'b0;
			m_awvalid <= 1'b0;
			m_wvalid <= 1'b0;
			m_arvalid <= 1'b0;
			m_aw <= 1'sb0;
			m_w <= 1'sb0;
			m_ar <= 1'sb0;
		end
		else begin
			up_pop <= 1'b0;
			case (dstate)
				2'd0:
					if ((reg_wr_en && reg_be[0]) && (reg_addr == ember_pkg_CP_CMDX)) begin
						dma_addr_q <= dma_dst_q;
						dma_left_q <= dma_len_q;
						dma_busy_q <= 1'b1;
						if (dma_len_q == 32'h00000000) begin
							dma_busy_q <= 1'b0;
							fence_done_q <= reg_wdata[15:8];
						end
						else
							dstate <= (reg_wdata[0] ? 2'd3 : 2'd1);
					end
				2'd1: begin
					if ((!up_empty && !m_awvalid) && !w_busy_q) begin
						m_awvalid <= 1'b1;
						m_wvalid <= 1'b1;
						w_busy_q <= 1'b1;
						m_aw[34-:32] <= ember_pkg_VRAM_BASE + dma_addr_q;
						m_aw[2-:3] <= 1'sb0;
						m_w[35-:32] <= up_front;
						m_w[3-:ember_pkg_AXI_STRB_W] <= 4'hf;
						up_pop <= 1'b1;
					end
					if (m_awvalid && m_awready)
						m_awvalid <= 1'b0;
					if (m_wvalid && m_wready) begin
						m_wvalid <= 1'b0;
						w_busy_q <= 1'b0;
						dma_addr_q <= dma_addr_q + 4;
						if (dma_left_q <= 4) begin
							dstate <= (m_awvalid ? 2'd2 : 2'd0);
							if (!m_awvalid) begin
								dma_busy_q <= 1'b0;
								fence_done_q <= fence_pend_q;
							end
						end
						else
							dma_left_q <= dma_left_q - 4;
					end
				end
				2'd2:
					if (!m_awvalid) begin
						dstate <= 2'd0;
						dma_busy_q <= 1'b0;
						fence_done_q <= fence_pend_q;
					end
				2'd3: begin
					if (m_rvalid) begin
						dma_addr_q <= dma_addr_q + 4;
						r_pend_q <= 1'b0;
						if (dma_left_q <= 4) begin
							dstate <= 2'd0;
							dma_busy_q <= 1'b0;
							fence_done_q <= fence_pend_q;
						end
						else
							dma_left_q <= dma_left_q - 4;
					end
					if (((!m_arvalid && !r_pend_q) && !m_rvalid) && (dma_left_q > 0)) begin
						m_arvalid <= 1'b1;
						m_ar[34-:32] <= ember_pkg_VRAM_BASE + dma_addr_q;
						m_ar[2-:3] <= 1'sb0;
					end
					if (m_arvalid && m_arready) begin
						m_arvalid <= 1'b0;
						r_pend_q <= 1'b1;
					end
				end
				default: dstate <= 2'd0;
			endcase
			if ((reg_wr_en && (reg_addr == ember_pkg_CP_CTRL)) && reg_wdata[0]) begin
				dstate <= 2'd0;
				dma_busy_q <= 1'b0;
				fence_done_q <= 8'h00;
				up_rp <= up_wp;
				rb_wp <= 1'sb0;
				rb_rp <= 1'sb0;
				r_pend_q <= 1'b0;
				w_busy_q <= 1'b0;
				m_awvalid <= 1'b0;
				m_wvalid <= 1'b0;
				m_arvalid <= 1'b0;
			end
		end
	reg [31:0] rd_data;
	wire [3:0] rb_count;
	assign rb_count = rb_wp[2:0] - rb_rp[2:0];
	localparam [11:0] ember_pkg_CP_FENCE = 12'h00c;
	localparam [11:0] ember_pkg_CP_ID = 12'h000;
	localparam [11:0] ember_pkg_CP_STATUS = 12'h004;
	always @(*) begin
		if (_sv2v_0)
			;
		case (rd_addr)
			ember_pkg_CP_ID: rd_data = 32'heb220002;
			ember_pkg_CP_STATUS: rd_data = {21'h000000, tu_busy, core_busy, gsx_busy, blit_busy, rb_count, rb_empty, rtr_busy, dma_busy_q};
			ember_pkg_CP_FENCE: rd_data = {24'h000000, fence_done_q};
			ember_pkg_CP_FIFOD: rd_data = (rb_empty ? 32'h00000000 : rb_mem[rb_rp[2:0]]);
			ember_pkg_CP_DMA_DST: rd_data = dma_dst_q;
			ember_pkg_CP_DMA_LEN: rd_data = dma_len_q;
			default: rd_data = 32'h00000000;
		endcase
	end
	ember_ram_slave u_regs(
		.clk(clk),
		.rst_n(rst_n),
		.s_aw(s_aw),
		.s_awvalid(s_awvalid),
		.s_awready(s_awready),
		.s_w(s_w),
		.s_wvalid(s_wvalid),
		.s_wready(s_wready),
		.s_b(s_b),
		.s_bvalid(s_bvalid),
		.s_bready(s_bready),
		.s_ar(s_ar),
		.s_arvalid(s_arvalid),
		.s_arready(s_arready),
		.s_r(s_r),
		.s_rvalid(s_rvalid),
		.s_rready(s_rready),
		.reg_addr(reg_addr),
		.reg_be(reg_be),
		.reg_wdata(reg_wdata),
		.reg_wr_en(reg_wr_en),
		.rd_addr(rd_addr),
		.rd_data(rd_data)
	);
	assign m_bready = 1'b1;
	assign m_rready = 1'b1;
	localparam [11:0] ember_pkg_CP_RTR_KICK = 12'h020;
	assign rtr_kick = ((reg_wr_en && reg_be[0]) && (reg_addr == ember_pkg_CP_RTR_KICK)) && reg_wdata[0];
	wire blit_csr_zone;
	localparam [11:0] ember_pkg_CP_BLIT_CFG = 12'h024;
	localparam [11:0] ember_pkg_CP_BLIT_DST = 12'h028;
	localparam [11:0] ember_pkg_CP_BLIT_SIZE = 12'h030;
	localparam [11:0] ember_pkg_CP_BLIT_SRC = 12'h02c;
	assign blit_csr_zone = (((reg_addr == ember_pkg_CP_BLIT_CFG) || (reg_addr == ember_pkg_CP_BLIT_DST)) || (reg_addr == ember_pkg_CP_BLIT_SRC)) || (reg_addr == ember_pkg_CP_BLIT_SIZE);
	assign blit_csr_we = (reg_wr_en && reg_be[0]) && blit_csr_zone;
	assign blit_csr_addr[0] = (reg_addr == ember_pkg_CP_BLIT_DST) || (reg_addr == ember_pkg_CP_BLIT_SIZE);
	assign blit_csr_addr[1] = (reg_addr == ember_pkg_CP_BLIT_SRC) || (reg_addr == ember_pkg_CP_BLIT_SIZE);
	assign blit_csr_wdata = reg_wdata;
	localparam [11:0] ember_pkg_CP_BLIT_KICK = 12'h034;
	assign blit_kick = ((reg_wr_en && reg_be[0]) && (reg_addr == ember_pkg_CP_BLIT_KICK)) && reg_wdata[0];
	wire gsx_csr_zone;
	localparam [11:0] ember_pkg_CP_GSX_CFG = 12'h048;
	localparam [11:0] ember_pkg_CP_GSX_COL = 12'h040;
	localparam [11:0] ember_pkg_CP_GSX_MATA = 12'h038;
	localparam [11:0] ember_pkg_CP_GSX_VTX = 12'h03c;
	assign gsx_csr_zone = (((reg_addr == ember_pkg_CP_GSX_MATA) || (reg_addr == ember_pkg_CP_GSX_VTX)) || (reg_addr == ember_pkg_CP_GSX_COL)) || (reg_addr == ember_pkg_CP_GSX_CFG);
	assign gsx_csr_we = (reg_wr_en && reg_be[0]) && gsx_csr_zone;
	assign gsx_csr_addr[0] = (reg_addr == ember_pkg_CP_GSX_VTX) || (reg_addr == ember_pkg_CP_GSX_CFG);
	assign gsx_csr_addr[1] = (reg_addr == ember_pkg_CP_GSX_COL) || (reg_addr == ember_pkg_CP_GSX_CFG);
	assign gsx_csr_wdata = reg_wdata;
	localparam [11:0] ember_pkg_CP_GSX_GO = 12'h044;
	assign gsx_kick = ((reg_wr_en && reg_be[0]) && (reg_addr == ember_pkg_CP_GSX_GO)) && reg_wdata[0];
	wire core_csr_zone;
	localparam [11:0] ember_pkg_CP_CORE_CODE = 12'h04c;
	localparam [11:0] ember_pkg_CP_CORE_NBLK = 12'h050;
	assign core_csr_zone = (reg_addr == ember_pkg_CP_CORE_CODE) || (reg_addr == ember_pkg_CP_CORE_NBLK);
	assign core_csr_we = (reg_wr_en && reg_be[0]) && core_csr_zone;
	assign core_csr_addr[0] = reg_addr == ember_pkg_CP_CORE_NBLK;
	assign core_csr_addr[1] = 1'b0;
	assign core_csr_wdata = reg_wdata;
	localparam [11:0] ember_pkg_CP_CORE_KICK = 12'h054;
	assign core_kick = ((reg_wr_en && reg_be[0]) && (reg_addr == ember_pkg_CP_CORE_KICK)) && reg_wdata[0];
	wire tu_csr_zone;
	localparam [11:0] ember_pkg_CP_TU_A = 12'h058;
	localparam [11:0] ember_pkg_CP_TU_C = 12'h060;
	localparam [11:0] ember_pkg_CP_TU_CFG2 = 12'h064;
	localparam [11:0] ember_pkg_CP_TU_W = 12'h05c;
	assign tu_csr_zone = (((reg_addr == ember_pkg_CP_TU_A) || (reg_addr == ember_pkg_CP_TU_W)) || (reg_addr == ember_pkg_CP_TU_C)) || (reg_addr == ember_pkg_CP_TU_CFG2);
	assign tu_csr_we = (reg_wr_en && reg_be[0]) && tu_csr_zone;
	assign tu_csr_addr[0] = (reg_addr == ember_pkg_CP_TU_W) || (reg_addr == ember_pkg_CP_TU_CFG2);
	assign tu_csr_addr[1] = (reg_addr == ember_pkg_CP_TU_C) || (reg_addr == ember_pkg_CP_TU_CFG2);
	assign tu_csr_wdata = reg_wdata;
	localparam [11:0] ember_pkg_CP_TU_KICK = 12'h068;
	assign tu_kick = ((reg_wr_en && reg_be[0]) && (reg_addr == ember_pkg_CP_TU_KICK)) && reg_wdata[0];
	wire _unused = up_full | rb_full;
	initial _sv2v_0 = 0;
endmodule
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
		.t_texpal(cmd_q[0][6]),
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
module ember_blit (
	clk,
	rst_n,
	csr_we,
	csr_addr,
	csr_wdata,
	kick,
	fpa_we,
	fpa_addr,
	fpa_wdata,
	fpa_be,
	fpa_req,
	fpa_rdata,
	busy,
	done
);
	input wire clk;
	input wire rst_n;
	input wire csr_we;
	input wire [1:0] csr_addr;
	input wire [31:0] csr_wdata;
	input wire kick;
	output reg fpa_we;
	output reg [31:0] fpa_addr;
	output reg [31:0] fpa_wdata;
	output reg [3:0] fpa_be;
	output reg fpa_req;
	input wire [31:0] fpa_rdata;
	output wire busy;
	output wire done;
	localparam [31:0] ember_pkg_FB0_BASE = 32'h00000000;
	localparam [31:0] ember_pkg_CP_BASE = 32'h00000000;
	localparam [31:0] ember_pkg_CP_WINDOW_BYTES = 4096;
	localparam [31:0] ember_pkg_VRAM_BASE = ember_pkg_CP_BASE + ember_pkg_CP_WINDOW_BYTES;
	localparam [31:0] FB_BUS = ember_pkg_VRAM_BASE + ember_pkg_FB0_BASE;
	reg scale2_q;
	reg key_en_q;
	reg [15:0] key_color_q;
	reg [31:0] dst_off_q;
	reg [31:0] src_off_q;
	reg [7:0] w_q;
	reg [7:0] h_q;
	reg done_q;
	always @(posedge clk or negedge rst_n)
		if (!rst_n) begin
			scale2_q <= 1'b0;
			key_en_q <= 1'b0;
			key_color_q <= 16'h0000;
			dst_off_q <= 1'sb0;
			src_off_q <= 1'sb0;
			w_q <= 8'd0;
			h_q <= 8'd0;
			done_q <= 1'b0;
		end
		else begin
			done_q <= 1'b0;
			if (csr_we)
				case (csr_addr)
					2'd0: begin
						scale2_q <= csr_wdata[30];
						key_en_q <= csr_wdata[29];
						key_color_q <= csr_wdata[15:0];
					end
					2'd1: dst_off_q <= csr_wdata;
					2'd2: src_off_q <= csr_wdata;
					2'd3: begin
						w_q <= csr_wdata[7:0];
						h_q <= csr_wdata[23:16];
					end
				endcase
		end
	reg [3:0] st;
	function automatic [15:0] lane_get;
		input reg [31:0] w;
		input reg hi;
		lane_get = (hi ? w[31:16] : w[15:0]);
	endfunction
	reg [31:0] saddr_q;
	wire [15:0] rdata_lane = lane_get(fpa_rdata, saddr_q[1]);
	wire skip_c = key_en_q && (rdata_lane == key_color_q);
	reg [7:0] sx;
	reg [7:0] sy;
	reg [16:0] bx;
	reg [16:0] by;
	reg [15:0] pix;
	reg skip;
	function automatic [31:0] sv2v_cast_32;
		input reg [31:0] inp;
		sv2v_cast_32 = inp;
	endfunction
	wire [31:0] daddr0 = ((FB_BUS + dst_off_q) + (sv2v_cast_32(by) * 32'd640)) + (sv2v_cast_32({15'b000000000000000, bx[8:0]}) * 32'd2);
	wire [31:0] daddr1 = daddr0 + 32'd2;
	wire [31:0] daddr2 = daddr0 + 32'd640;
	wire [31:0] daddr3 = daddr0 + 32'd642;
	assign busy = st != 4'd0;
	always @(posedge clk or negedge rst_n)
		if (!rst_n) begin
			st <= 4'd0;
			sx <= 1'sb0;
			sy <= 1'sb0;
			bx <= 1'sb0;
			by <= 1'sb0;
			saddr_q <= 1'sb0;
			pix <= 1'sb0;
			skip <= 1'b0;
			fpa_req <= 1'b0;
			fpa_addr <= 1'sb0;
			fpa_we <= 1'b0;
			fpa_wdata <= 1'sb0;
			fpa_be <= 1'sb0;
		end
		else begin
			fpa_req <= 1'b0;
			fpa_we <= 1'b0;
			case (st)
				4'd0:
					if (kick) begin
						sx <= 1'sb0;
						sy <= 1'sb0;
						bx <= 1'sb0;
						by <= 1'sb0;
						skip <= 1'b0;
						st <= 4'd1;
					end
				4'd1: begin
					saddr_q <= ((ember_pkg_VRAM_BASE + src_off_q) + ((sv2v_cast_32(sy) * sv2v_cast_32({24'b000000000000000000000000, w_q})) * 32'd2)) + (sv2v_cast_32({24'b000000000000000000000000, sx}) * 32'd2);
					fpa_req <= 1'b1;
					fpa_addr <= (((ember_pkg_VRAM_BASE + src_off_q) + ((sv2v_cast_32(sy) * sv2v_cast_32({24'b000000000000000000000000, w_q})) * 32'd2)) + (sv2v_cast_32({24'b000000000000000000000000, sx}) * 32'd2)) & 32'hfffffffc;
					st <= 4'd2;
				end
				4'd2: st <= 4'd3;
				4'd3: begin
					pix <= rdata_lane;
					skip <= skip_c;
					fpa_we <= !skip_c;
					fpa_addr <= daddr0 & 32'hfffffffc;
					fpa_be <= (daddr0[1] ? 4'b1100 : 4'b0011);
					fpa_wdata <= {2 {rdata_lane}};
					st <= (scale2_q ? 4'd4 : 4'd7);
				end
				4'd4: begin
					if (!skip) begin
						fpa_we <= 1'b1;
						fpa_addr <= daddr1 & 32'hfffffffc;
						fpa_be <= (daddr1[1] ? 4'b1100 : 4'b0011);
						fpa_wdata <= {2 {pix}};
					end
					st <= 4'd5;
				end
				4'd5: begin
					if (!skip) begin
						fpa_we <= 1'b1;
						fpa_addr <= daddr2 & 32'hfffffffc;
						fpa_be <= (daddr2[1] ? 4'b1100 : 4'b0011);
						fpa_wdata <= {2 {pix}};
					end
					st <= 4'd6;
				end
				4'd6: begin
					if (!skip) begin
						fpa_we <= 1'b1;
						fpa_addr <= daddr3 & 32'hfffffffc;
						fpa_be <= (daddr3[1] ? 4'b1100 : 4'b0011);
						fpa_wdata <= {2 {pix}};
					end
					st <= 4'd7;
				end
				4'd7:
					if (sx == (w_q - 8'd1)) begin
						sx <= 1'sb0;
						if (sy == (h_q - 8'd1)) begin
							done_q <= 1'b1;
							st <= 4'd8;
						end
						else begin
							sy <= sy + 8'd1;
							by <= (scale2_q ? by + 17'd2 : by + 17'd1);
							bx <= 1'sb0;
							st <= 4'd1;
						end
					end
					else begin
						sx <= sx + 8'd1;
						bx <= (scale2_q ? bx + 17'd2 : bx + 17'd1);
						st <= 4'd1;
					end
				4'd8: st <= 4'd0;
				default: st <= 4'd0;
			endcase
		end
	assign done = done_q;
endmodule
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
	reg cfg_pal;
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
			cfg_pal <= 1'b0;
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
				cfg_pal <= csr_wdata[25];
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
					gxa_wdata <= {16'h0000, cfg_page, 1'b0, cfg_pal, 2'b00, cfg_tex, cfg_ztest, cfg_blend, 1'b1};
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
module ember_core (
	clk,
	rst_n,
	csr_we,
	csr_addr,
	csr_wdata,
	kick,
	cxa_we,
	cxa_addr,
	cxa_wdata,
	cxa_be,
	cxa_req,
	cxa_rdata,
	ixa_req,
	ixa_addr,
	ixa_rdata,
	busy
);
	reg _sv2v_0;
	input wire clk;
	input wire rst_n;
	input wire csr_we;
	input wire [1:0] csr_addr;
	input wire [31:0] csr_wdata;
	input wire kick;
	output reg cxa_we;
	output reg [31:0] cxa_addr;
	output reg [31:0] cxa_wdata;
	output reg [3:0] cxa_be;
	output reg cxa_req;
	input wire [31:0] cxa_rdata;
	output reg ixa_req;
	output reg [31:0] ixa_addr;
	input wire [31:0] ixa_rdata;
	output wire busy;
	localparam [31:0] NT = 4;
	localparam [31:0] SAW = 10;
	reg [31:0] code_base_q;
	reg [7:0] nblk_q;
	wire csr_code_we = csr_we && (csr_addr == 2'd0);
	wire csr_nblk_we = csr_we && (csr_addr == 2'd1);
	always @(posedge clk or negedge rst_n)
		if (!rst_n) begin
			code_base_q <= 32'h00000000;
			nblk_q <= 8'd1;
		end
		else begin
			if (csr_code_we)
				code_base_q <= {csr_wdata[31:2], 2'b00};
			if (csr_nblk_we && (csr_wdata[7:0] != 8'd0))
				nblk_q <= csr_wdata[7:0];
		end
	reg [3:0] T [0:3];
	reg [7:0] fpc [0:3];
	reg [31:0] gpr [0:3][0:15];
	reg [3:0] waitv;
	reg [3:0] barv;
	reg [3:0] ibuf_v;
	reg [31:0] ibuf_w [0:3];
	reg [31:0] smem [0:1023];
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
	ember_fpu4 u_fpu(
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
	reg [1:0] st;
	reg running;
	assign busy = running;
	reg [7:0] blk;
	reg [19:0] budget;
	reg ix_pend;
	reg ix_req_cyc;
	reg [1:0] ix_tid;
	reg flush_req;
	reg [1:0] flush_tid;
	reg ld_pend;
	reg [31:0] ld_addr_q;
	reg [1:0] ld_tid_q;
	reg [3:0] ld_rd_q;
	reg cx_pend;
	reg cx_req_cyc;
	reg dr_valid;
	reg [1:0] dr_tid;
	reg [3:0] dr_rd;
	reg [31:0] dr_word;
	reg fp_pend;
	reg [1:0] fp_tid;
	reg [3:0] fp_rd;
	reg [1:0] bar_count;
	reg exec_en;
	reg [1:0] exec_tid;
	always @(*) begin
		if (_sv2v_0)
			;
		exec_en = 1'b0;
		exec_tid = 2'd0;
		begin : sv2v_autoblock_1
			reg signed [31:0] t;
			for (t = 3; t >= 0; t = t - 1)
				if ((((st == 2'd1) && ibuf_v[t]) && !waitv[t]) && !barv[t]) begin
					exec_en = 1'b1;
					exec_tid = t[1:0];
				end
		end
	end
	reg [1:0] pick_tid;
	reg pick_en;
	always @(*) begin
		if (_sv2v_0)
			;
		pick_en = 1'b0;
		pick_tid = 2'd0;
		begin : sv2v_autoblock_2
			reg signed [31:0] t;
			for (t = 3; t >= 0; t = t - 1)
				if (((st == 2'd1) && !T[t][3]) && !ibuf_v[t]) begin
					pick_en = 1'b1;
					pick_tid = t[1:0];
				end
		end
	end
	wire [7:0] i_op = ibuf_w[exec_tid][31:24];
	wire [3:0] i_rd = ibuf_w[exec_tid][23:20];
	wire [3:0] i_ra = ibuf_w[exec_tid][19:16];
	wire [3:0] i_rb = ibuf_w[exec_tid][15:12];
	wire [11:0] i_imm = ibuf_w[exec_tid][11:0];
	wire signed [31:0] i_sx12 = {{20 {i_imm[11]}}, i_imm};
	wire signed [8:0] i_sx9 = i_imm[8:0];
	wire signed [10:0] i_sx11 = i_imm[10:0];
	wire [31:0] rav = gpr[exec_tid][i_ra];
	wire [31:0] rbv = gpr[exec_tid][i_rb];
	localparam [31:0] ember_pkg_FRAME_H_PX = 240;
	localparam [31:0] ember_pkg_FRAME_W_PX = 320;
	localparam [31:0] ember_pkg_FB0_BASE = 32'h00000000;
	localparam [31:0] ember_pkg_FB_STRIDE = 640;
	localparam [31:0] ember_pkg_ZBUF_BASE = ember_pkg_FB0_BASE + (ember_pkg_FB_STRIDE * ember_pkg_FRAME_H_PX);
	localparam [31:0] ember_pkg_TEX_BASE = ember_pkg_ZBUF_BASE + ((ember_pkg_FRAME_W_PX * ember_pkg_FRAME_H_PX) * 2);
	localparam [31:0] ember_pkg_TEX_BYTES = 65536;
	localparam [31:0] ember_pkg_CMDBUF_BASE = ember_pkg_TEX_BASE + ember_pkg_TEX_BYTES;
	task automatic init_block;
		input reg [7:0] b;
		begin
			begin : sv2v_autoblock_3
				reg signed [31:0] t;
				for (t = 0; t < NT; t = t + 1)
					begin
						T[t][3] <= 1'b0;
						T[t][2-:3] <= 3'b000;
						fpc[t] <= 8'd0;
						gpr[t][12] <= ember_pkg_CMDBUF_BASE;
						gpr[t][13] <= {24'h000000, b};
						gpr[t][14] <= {24'h000000, nblk_q};
						gpr[t][15] <= {30'h00000000, t[1:0]};
					end
			end
			ibuf_v <= 1'sb0;
			waitv <= 1'sb0;
			barv <= 1'sb0;
			bar_count <= 2'd0;
			budget <= 1'sb0;
		end
	endtask
	localparam [31:0] ember_pkg_CP_BASE = 32'h00000000;
	localparam [31:0] ember_pkg_CP_WINDOW_BYTES = 4096;
	localparam [31:0] ember_pkg_VRAM_BASE = ember_pkg_CP_BASE + ember_pkg_CP_WINDOW_BYTES;
	function automatic [31:0] sv2v_cast_32;
		input reg [31:0] inp;
		sv2v_cast_32 = inp;
	endfunction
	function automatic [7:0] sv2v_cast_8;
		input reg [7:0] inp;
		sv2v_cast_8 = inp;
	endfunction
	always @(posedge clk or negedge rst_n)
		if (!rst_n) begin
			st <= 2'd0;
			running <= 1'b0;
			blk <= 8'd0;
			ibuf_v <= 1'sb0;
			ix_pend <= 1'b0;
			ix_req_cyc <= 1'b0;
			ix_tid <= 2'd0;
			flush_req <= 1'b0;
			flush_tid <= 2'd0;
			ld_pend <= 1'b0;
			ld_addr_q <= 32'h00000000;
			ld_tid_q <= 2'd0;
			ld_rd_q <= 4'd0;
			cx_pend <= 1'b0;
			cx_req_cyc <= 1'b0;
			dr_valid <= 1'b0;
			dr_tid <= 2'd0;
			dr_rd <= 4'd0;
			dr_word <= 32'h00000000;
			fp_pend <= 1'b0;
			fp_tid <= 2'd0;
			fp_rd <= 4'd0;
			bar_count <= 2'd0;
			budget <= 1'sb0;
			f_lane_en <= 4'h0;
			f_go <= 1'b0;
			f_op <= 4'h0;
			f_a0 <= 1'sb0;
			f_b0 <= 1'sb0;
			f_a1 <= 1'sb0;
			f_b1 <= 1'sb0;
			f_a2 <= 1'sb0;
			f_b2 <= 1'sb0;
			f_a3 <= 1'sb0;
			f_b3 <= 1'sb0;
			cxa_we <= 1'b0;
			cxa_addr <= 32'h00000000;
			cxa_wdata <= 32'h00000000;
			cxa_be <= 4'h0;
			cxa_req <= 1'b0;
			ixa_req <= 1'b0;
			ixa_addr <= 32'h00000000;
			waitv <= 4'h0;
			barv <= 4'h0;
			begin : sv2v_autoblock_4
				reg signed [31:0] t;
				for (t = 0; t < NT; t = t + 1)
					begin
						T[t] <= 1'sb0;
						fpc[t] <= 8'd0;
						ibuf_w[t] <= 32'h00000000;
						begin : sv2v_autoblock_5
							reg signed [31:0] r;
							for (r = 0; r < 16; r = r + 1)
								gpr[t][r] <= 32'h00000000;
						end
					end
			end
		end
		else begin
			cxa_we <= 1'b0;
			cxa_req <= 1'b0;
			ixa_req <= 1'b0;
			f_go <= 1'b0;
			if (ix_pend && !ix_req_cyc) begin
				ix_pend <= 1'b0;
				if (flush_req && (ix_tid == flush_tid))
					flush_req <= 1'b0;
				else begin
					ibuf_v[ix_tid] <= 1'b1;
					ibuf_w[ix_tid] <= ixa_rdata;
				end
			end
			else if (flush_req)
				flush_req <= 1'b0;
			if (ix_req_cyc)
				ix_req_cyc <= 1'b0;
			if (cx_pend && !cx_req_cyc) begin
				cx_pend <= 1'b0;
				dr_valid <= 1'b1;
				dr_tid <= ld_tid_q;
				dr_rd <= ld_rd_q;
				dr_word <= cxa_rdata;
			end
			if (cx_req_cyc)
				cx_req_cyc <= 1'b0;
			if (dr_valid) begin
				dr_valid <= 1'b0;
				gpr[dr_tid][dr_rd] <= dr_word;
				waitv[dr_tid] <= 1'b0;
			end
			if (fp_pend && f_done) begin
				gpr[fp_tid][fp_rd] <= f_y0;
				waitv[fp_tid] <= 1'b0;
				fp_pend <= 1'b0;
			end
			case (st)
				2'd0: begin
					running <= 1'b0;
					if (kick) begin
						running <= 1'b1;
						blk <= 8'd0;
						init_block(8'd0);
						st <= 2'd1;
					end
				end
				2'd1: begin
					budget <= budget + 20'd1;
					if (budget == 20'hfffff) begin
						begin : sv2v_autoblock_6
							reg signed [31:0] t;
							for (t = 0; t < NT; t = t + 1)
								T[t][3] <= 1'b1;
						end
						st <= 2'd2;
					end
					else begin
						if (exec_en) begin
							ibuf_v[exec_tid] <= 1'b0;
							if (T[exec_tid][3])
								;
							else
								case (i_op)
									8'h01: gpr[exec_tid][i_rd] <= rav + rbv;
									8'h02: gpr[exec_tid][i_rd] <= rav - rbv;
									8'h03: gpr[exec_tid][i_rd] <= $signed(rav) * $signed(rbv);
									8'h04: gpr[exec_tid][i_rd] <= (rbv == 32'h00000000 ? 32'h00000000 : $signed(rav) / $signed(rbv));
									8'h05: gpr[exec_tid][i_rd] <= rav & rbv;
									8'h06: gpr[exec_tid][i_rd] <= rav | rbv;
									8'h07: gpr[exec_tid][i_rd] <= rav ^ rbv;
									8'h08: gpr[exec_tid][i_rd] <= rav << rbv[4:0];
									8'h09: gpr[exec_tid][i_rd] <= rav >> rbv[4:0];
									8'h0a: begin : sv2v_autoblock_7
										reg [31:0] d;
										d = rav - rbv;
										T[exec_tid][2-:3] <= {d[31], d == 32'h00000000, !d[31] && (d != 32'h00000000)};
									end
									8'h0b: gpr[exec_tid][i_rd] <= ($signed(rav) < $signed(rbv) ? rav : rbv);
									8'h0c: gpr[exec_tid][i_rd] <= ($signed(rav) > $signed(rbv) ? rav : rbv);
									8'h0d, 8'h0e: gpr[exec_tid][i_rd] <= {16'h0000, i_ra, i_imm};
									8'h40, 8'h41, 8'h42, 8'h43: begin
										f_lane_en <= 4'b0001;
										f_op <= {2'b00, i_op[1:0]};
										f_a0 <= rav;
										f_b0 <= rbv;
										f_go <= 1'b1;
										fp_pend <= 1'b1;
										fp_tid <= exec_tid;
										fp_rd <= i_rd;
										waitv[exec_tid] <= 1'b1;
									end
									8'h10: begin
										ld_pend <= 1'b1;
										ld_addr_q <= sv2v_cast_32(ember_pkg_VRAM_BASE + (rav + i_sx12));
										ld_tid_q <= exec_tid;
										ld_rd_q <= i_rd;
										waitv[exec_tid] <= 1'b1;
									end
									8'h11: begin
										cxa_we <= 1'b1;
										cxa_be <= 4'hf;
										cxa_addr <= sv2v_cast_32(ember_pkg_VRAM_BASE + (rav + i_sx12));
										cxa_wdata <= gpr[exec_tid][i_rd];
									end
									8'h12: gpr[exec_tid][i_rd] <= smem[(rav + i_sx12) & 1023];
									8'h13: smem[(rav + i_sx12) & 1023] <= gpr[exec_tid][i_rd];
									8'h14: smem[(rav + i_sx12) & 1023] <= smem[(rav + i_sx12) & 1023] + gpr[exec_tid][i_rd];
									8'h15:
										if ($signed(gpr[exec_tid][i_rd]) > $signed(smem[(rav + i_sx12) & 1023]))
											smem[(rav + i_sx12) & 1023] <= gpr[exec_tid][i_rd];
									8'h20:
										if ((T[exec_tid][2-:3] & i_rd[2:0]) != 3'b000) begin
											fpc[exec_tid] <= sv2v_cast_8(fpc[exec_tid] + i_sx9);
											flush_req <= 1'b1;
											flush_tid <= exec_tid;
										end
									8'h21, 8'h24: begin
										gpr[exec_tid][(i_op == 8'h21 ? i_rd : 4'd15)] <= {24'h000000, fpc[exec_tid]};
										fpc[exec_tid] <= sv2v_cast_8(fpc[exec_tid] + i_sx11);
										flush_req <= 1'b1;
										flush_tid <= exec_tid;
									end
									8'h22: begin
										fpc[exec_tid] <= gpr[exec_tid][i_ra][7:0];
										flush_req <= 1'b1;
										flush_tid <= exec_tid;
									end
									8'h23: begin
										fpc[exec_tid] <= gpr[exec_tid][15][7:0];
										flush_req <= 1'b1;
										flush_tid <= exec_tid;
									end
									8'h25: begin
										barv[exec_tid] <= 1'b1;
										bar_count <= bar_count + 2'd1;
										if (bar_count == 2'd3) begin
											barv <= 4'h0;
											bar_count <= 2'd0;
										end
									end
									8'hff: T[exec_tid][3] <= 1'b1;
									default:
										;
								endcase
						end
						if (ld_pend && !cx_pend) begin
							ld_pend <= 1'b0;
							cx_pend <= 1'b1;
							cx_req_cyc <= 1'b1;
							cxa_req <= 1'b1;
							cxa_addr <= ld_addr_q;
						end
						if ((!ix_pend && pick_en) && !(flush_req && (flush_tid == pick_tid))) begin
							ix_pend <= 1'b1;
							ix_req_cyc <= 1'b1;
							ix_tid <= pick_tid;
							ixa_req <= 1'b1;
							ixa_addr <= (ember_pkg_VRAM_BASE + code_base_q) + {22'h000000, fpc[pick_tid], 2'b00};
							fpc[pick_tid] <= fpc[pick_tid] + 5'd1;
						end
						if ((((((((!exec_en && !pick_en) && !ix_pend) && !cx_pend) && !dr_valid) && !fp_pend) && !ld_pend) && (waitv == {4 {1'sb0}})) && (barv == {4 {1'sb0}}))
							st <= 2'd2;
					end
				end
				2'd2:
					if ((blk + 8'd1) >= nblk_q) begin
						running <= 1'b0;
						st <= 2'd3;
					end
					else begin
						blk <= blk + 8'd1;
						init_block(blk + 8'd1);
						st <= 2'd1;
					end
				2'd3: begin
					running <= 1'b0;
					st <= 2'd0;
				end
				default: st <= 2'd0;
			endcase
		end
	wire _unused = ^{f_y1, f_y2, f_y3, f_busy};
	initial _sv2v_0 = 0;
endmodule
module ember_tu (
	clk,
	rst_n,
	csr_we,
	csr_addr,
	csr_wdata,
	kick,
	tua_we,
	tua_addr,
	tua_wdata,
	tua_be,
	tua_req,
	tua_rdata,
	busy
);
	input wire clk;
	input wire rst_n;
	input wire csr_we;
	input wire [1:0] csr_addr;
	input wire [31:0] csr_wdata;
	input wire kick;
	output reg tua_we;
	output reg [31:0] tua_addr;
	output reg [31:0] tua_wdata;
	output reg [3:0] tua_be;
	output reg tua_req;
	input wire [31:0] tua_rdata;
	output wire busy;
	localparam [31:0] N16 = 16;
	reg [31:0] a_base_q;
	reg [31:0] w_base_q;
	reg [31:0] c_base_q;
	reg [15:0] req_mult;
	reg [3:0] req_shift;
	reg [11:0] dim_n;
	reg [11:0] dim_k;
	reg [11:0] dim_m;
	wire cfg2_dim_we = (csr_we && (csr_addr == 2'd3)) && (csr_wdata[31:30] == 2'b00);
	wire cfg2_m_we = (csr_we && (csr_addr == 2'd3)) && (csr_wdata[31:30] == 2'b01);
	wire cfg2_q_we = (csr_we && (csr_addr == 2'd3)) && (csr_wdata[31:30] == 2'b10);
	always @(posedge clk or negedge rst_n)
		if (!rst_n) begin
			a_base_q <= 32'h00000000;
			w_base_q <= 32'h00000000;
			c_base_q <= 32'h00000000;
			req_mult <= 16'd1;
			req_shift <= 4'd0;
			dim_n <= 12'd0;
			dim_k <= 12'd0;
			dim_m <= 12'd0;
		end
		else begin
			if (csr_we)
				case (csr_addr)
					2'd0: a_base_q <= {csr_wdata[31:2], 2'b00};
					2'd1: w_base_q <= {csr_wdata[31:2], 2'b00};
					2'd2: c_base_q <= {csr_wdata[31:2], 2'b00};
					default:
						;
				endcase
			if (cfg2_dim_we) begin
				dim_n <= csr_wdata[11:0];
				dim_k <= csr_wdata[27:16];
			end
			if (cfg2_m_we)
				dim_m <= csr_wdata[11:0];
			if (cfg2_q_we) begin
				req_mult <= csr_wdata[15:0];
				req_shift <= csr_wdata[23:20];
			end
		end
	wire [31:0] kdim = {20'h00000, dim_k};
	wire [31:0] ndim = {20'h00000, dim_n};
	wire [31:0] mdim = {20'h00000, dim_m};
	reg [31:0] wrowbuf [0:3];
	reg [31:0] abuf_q [0:3];
	wire [7:0] wbyte [0:15];
	genvar _gv_gwb_1;
	generate
		for (_gv_gwb_1 = 0; _gv_gwb_1 < N16; _gv_gwb_1 = _gv_gwb_1 + 1) begin : g_wbyte
			localparam gwb = _gv_gwb_1;
			assign wbyte[gwb] = wrowbuf[gwb[3:2]][gwb[1:0] * 8+:8];
		end
	endgenerate
	reg [15:0] w_ld;
	reg [7:0] w_regs [0:15][0:15];
	wire [7:0] a_row_byte [0:15];
	always @(posedge clk) begin : sv2v_autoblock_1
		reg signed [31:0] r;
		for (r = 0; r < N16; r = r + 1)
			if (w_ld[r]) begin : sv2v_autoblock_2
				reg signed [31:0] c;
				for (c = 0; c < N16; c = c + 1)
					w_regs[r][c] <= wbyte[c];
			end
	end
	genvar _gv_gr_1;
	genvar _gv_gc_1;
	generate
		for (_gv_gr_1 = 0; _gv_gr_1 < N16; _gv_gr_1 = _gv_gr_1 + 1) begin : g_ab
			localparam gr = _gv_gr_1;
			assign a_row_byte[gr] = abuf_q[gr[3:2]][gr[1:0] * 8+:8];
		end
	endgenerate
	wire signed [31:0] prod [0:15][0:15];
	function automatic signed [31:0] sv2v_cast_32_signed;
		input reg signed [31:0] inp;
		sv2v_cast_32_signed = inp;
	endfunction
	generate
		for (_gv_gr_1 = 0; _gv_gr_1 < N16; _gv_gr_1 = _gv_gr_1 + 1) begin : g_prod
			localparam gr = _gv_gr_1;
			for (_gv_gc_1 = 0; _gv_gc_1 < N16; _gv_gc_1 = _gv_gc_1 + 1) begin : g_pc
				localparam gc = _gv_gc_1;
				assign prod[gr][gc] = sv2v_cast_32_signed($signed(w_regs[gr][gc])) * sv2v_cast_32_signed($signed(a_row_byte[gr]));
			end
		end
	endgenerate
	wire signed [31:0] lv1 [0:15][0:7];
	wire signed [31:0] lv2 [0:15][0:3];
	wire signed [31:0] lv3 [0:15][0:1];
	wire signed [31:0] tree [0:15];
	genvar _gv_gt_1;
	genvar _gv_trow_1;
	generate
		for (_gv_gt_1 = 0; _gv_gt_1 < N16; _gv_gt_1 = _gv_gt_1 + 1) begin : g_tree
			localparam gt = _gv_gt_1;
			for (_gv_trow_1 = 0; _gv_trow_1 < 8; _gv_trow_1 = _gv_trow_1 + 1) begin : genblk1
				localparam trow = _gv_trow_1;
				assign lv1[gt][trow] = prod[2 * trow][gt] + prod[(2 * trow) + 1][gt];
			end
			for (_gv_trow_1 = 8; _gv_trow_1 < 12; _gv_trow_1 = _gv_trow_1 + 1) begin : genblk2
				localparam trow = _gv_trow_1;
				assign lv2[gt][trow - 8] = lv1[gt][2 * (trow - 8)] + lv1[gt][(2 * (trow - 8)) + 1];
			end
			for (_gv_trow_1 = 12; _gv_trow_1 < 14; _gv_trow_1 = _gv_trow_1 + 1) begin : genblk3
				localparam trow = _gv_trow_1;
				assign lv3[gt][trow - 12] = lv2[gt][2 * (trow - 12)] + lv2[gt][(2 * (trow - 12)) + 1];
			end
			assign tree[gt] = lv3[gt][0] + lv3[gt][1];
		end
	endgenerate
	reg signed [31:0] acc [0:15][0:15];
	reg [3:0] st;
	reg running;
	assign busy = running;
	reg [31:0] k0;
	reg [31:0] n0;
	reg [31:0] m0;
	reg [4:0] wrow;
	reg [1:0] wgrp;
	reg [3:0] mrow;
	reg [3:0] fcnt;
	reg mac_pend;
	reg rq_pend;
	reg rq_req_cyc;
	reg [31:0] rq_addr_q;
	reg rq_dst_w;
	reg [1:0] rq_aw;
	reg [11:0] cw_row;
	reg [3:0] cw_rblk;
	reg [1:0] cw_word;
	reg [7:0] cw_byte0;
	reg [7:0] cw_byte1;
	reg [7:0] cw_byte2;
	reg [7:0] cw_byte3;
	function automatic [7:0] requant8;
		input reg signed [31:0] c32;
		input reg [15:0] mult;
		input reg [3:0] shift;
		reg signed [47:0] full;
		reg signed [47:0] half;
		reg signed [47:0] res;
		begin
			full = $signed(c32) * $signed({32'h00000000, mult});
			if (shift == 4'd0)
				res = full;
			else begin
				half = 48'd1 << (shift - 4'd1);
				res = (full + half) >>> shift;
			end
			requant8 = res[7:0];
		end
	endfunction
	task automatic reset_acc;
		reg signed [31:0] r;
		for (r = 0; r < N16; r = r + 1)
			begin : sv2v_autoblock_3
				reg signed [31:0] c;
				for (c = 0; c < N16; c = c + 1)
					acc[r][c] <= 32'sd0;
			end
	endtask
	localparam [31:0] ember_pkg_CP_BASE = 32'h00000000;
	localparam [31:0] ember_pkg_CP_WINDOW_BYTES = 4096;
	localparam [31:0] ember_pkg_VRAM_BASE = ember_pkg_CP_BASE + ember_pkg_CP_WINDOW_BYTES;
	function automatic [31:0] sv2v_cast_32;
		input reg [31:0] inp;
		sv2v_cast_32 = inp;
	endfunction
	always @(posedge clk or negedge rst_n)
		if (!rst_n) begin
			st <= 4'd0;
			running <= 1'b0;
			k0 <= 32'd0;
			n0 <= 32'd0;
			m0 <= 32'd0;
			wrow <= 5'd0;
			wgrp <= 2'd0;
			mrow <= 4'd0;
			fcnt <= 4'd0;
			mac_pend <= 1'b0;
			rq_pend <= 1'b0;
			rq_req_cyc <= 1'b0;
			rq_addr_q <= 32'h00000000;
			rq_dst_w <= 1'b0;
			rq_aw <= 2'd0;
			tua_we <= 1'b0;
			tua_addr <= 32'h00000000;
			tua_wdata <= 32'h00000000;
			tua_be <= 4'h0;
			tua_req <= 1'b0;
			w_ld <= 1'sb0;
			cw_row <= 12'd0;
			cw_rblk <= 4'd0;
			cw_word <= 2'd0;
			cw_byte0 <= 8'd0;
			cw_byte1 <= 8'd0;
			cw_byte2 <= 8'd0;
			cw_byte3 <= 8'd0;
			begin : sv2v_autoblock_4
				reg signed [31:0] r;
				for (r = 0; r < N16; r = r + 1)
					begin : sv2v_autoblock_5
						reg signed [31:0] c;
						for (c = 0; c < N16; c = c + 1)
							acc[r][c] <= 32'sd0;
					end
			end
		end
		else begin
			tua_we <= 1'b0;
			tua_req <= 1'b0;
			w_ld <= 1'sb0;
			if (rq_pend && !rq_req_cyc) begin
				rq_pend <= 1'b0;
				if (rq_dst_w)
					abuf_q[rq_aw] <= tua_rdata;
				else
					wrowbuf[rq_aw] <= tua_rdata;
			end
			if (rq_req_cyc)
				rq_req_cyc <= 1'b0;
			if (mac_pend) begin
				mac_pend <= 1'b0;
				begin : sv2v_autoblock_6
					reg signed [31:0] c;
					for (c = 0; c < N16; c = c + 1)
						acc[mrow][c] <= acc[mrow][c] + tree[c];
				end
			end
			case (st)
				4'd0: begin
					running <= 1'b0;
					if (kick) begin
						running <= 1'b1;
						n0 <= 32'd0;
						m0 <= 32'd0;
						k0 <= 32'd0;
						wrow <= 5'd0;
						wgrp <= 2'd0;
						reset_acc;
						st <= 4'd1;
					end
				end
				4'd1:
					if (!rq_pend) begin
						rq_pend <= 1'b1;
						rq_req_cyc <= 1'b1;
						rq_dst_w <= 1'b0;
						rq_aw <= wgrp;
						tua_req <= 1'b1;
						tua_addr <= (((ember_pkg_VRAM_BASE + w_base_q) + ((k0 + sv2v_cast_32(wrow)) * ndim)) + n0) + {28'h0000000, wgrp, 2'b00};
						rq_addr_q <= (((ember_pkg_VRAM_BASE + w_base_q) + ((k0 + sv2v_cast_32(wrow)) * ndim)) + n0) + {28'h0000000, wgrp, 2'b00};
						st <= 4'd2;
					end
				4'd2:
					if (!rq_pend && !rq_req_cyc) begin
						if (wgrp == 2'd3)
							st <= 4'd3;
						else begin
							wgrp <= wgrp + 2'd1;
							st <= 4'd1;
						end
					end
				4'd3: begin
					w_ld[wrow[3:0]] <= 1'b1;
					if (wrow == 5'd15) begin
						wrow <= 5'd0;
						mrow <= 4'd0;
						fcnt <= 4'd0;
						st <= 4'd4;
					end
					else begin
						wrow <= wrow + 5'd1;
						wgrp <= 2'd0;
						st <= 4'd1;
					end
				end
				4'd4:
					if (!rq_pend) begin
						rq_pend <= 1'b1;
						rq_req_cyc <= 1'b1;
						rq_dst_w <= 1'b1;
						rq_aw <= fcnt[1:0];
						tua_req <= 1'b1;
						tua_addr <= (((ember_pkg_VRAM_BASE + a_base_q) + ((m0 + sv2v_cast_32(mrow)) * kdim)) + k0) + {28'h0000000, fcnt[1:0], 2'b00};
						rq_addr_q <= (((ember_pkg_VRAM_BASE + a_base_q) + ((m0 + sv2v_cast_32(mrow)) * kdim)) + k0) + {28'h0000000, fcnt[1:0], 2'b00};
						if (fcnt[1:0] == 2'd3)
							st <= 4'd5;
						fcnt <= fcnt + 4'd1;
					end
				4'd5:
					if (!rq_pend && !rq_req_cyc) begin
						mac_pend <= 1'b1;
						st <= 4'd6;
					end
				4'd6:
					if (!mac_pend) begin
						if (mrow == 4'd15)
							st <= 4'd7;
						else begin
							mrow <= mrow + 4'd1;
							fcnt <= 4'd0;
							st <= 4'd4;
						end
					end
				4'd7:
					if ((k0 + 32'd16) >= kdim) begin
						cw_rblk <= 4'd0;
						cw_word <= 2'd0;
						cw_row <= m0[11:0];
						st <= 4'd8;
					end
					else begin
						k0 <= k0 + 32'd16;
						wrow <= 5'd0;
						wgrp <= 2'd0;
						st <= 4'd1;
					end
				4'd8: begin
					cw_byte0 <= requant8(acc[cw_rblk][(cw_word * 4) + 0], req_mult, req_shift);
					cw_byte1 <= requant8(acc[cw_rblk][(cw_word * 4) + 1], req_mult, req_shift);
					cw_byte2 <= requant8(acc[cw_rblk][(cw_word * 4) + 2], req_mult, req_shift);
					cw_byte3 <= requant8(acc[cw_rblk][(cw_word * 4) + 3], req_mult, req_shift);
					st <= 4'd9;
				end
				4'd9: begin
					tua_we <= 1'b1;
					tua_be <= 4'hf;
					tua_addr <= (((ember_pkg_VRAM_BASE + c_base_q) + (sv2v_cast_32(cw_row) * ndim)) + n0) + {28'h0000000, cw_word, 2'b00};
					tua_wdata <= {cw_byte3, cw_byte2, cw_byte1, cw_byte0};
					if (cw_word == 2'd3) begin
						cw_word <= 2'd0;
						if (cw_rblk == 4'd15)
							st <= 4'd10;
						else begin
							cw_rblk <= cw_rblk + 4'd1;
							cw_row <= cw_row + 12'd1;
							st <= 4'd8;
						end
					end
					else begin
						cw_word <= cw_word + 2'd1;
						st <= 4'd8;
					end
				end
				4'd10:
					if ((m0 + 32'd16) >= mdim) begin
						if ((n0 + 32'd16) >= ndim) begin
							running <= 1'b0;
							st <= 4'd11;
						end
						else begin
							n0 <= n0 + 32'd16;
							m0 <= 32'd0;
							k0 <= 32'd0;
							wrow <= 5'd0;
							wgrp <= 2'd0;
							reset_acc;
							st <= 4'd1;
						end
					end
					else begin
						m0 <= m0 + 32'd16;
						k0 <= 32'd0;
						wrow <= 5'd0;
						wgrp <= 2'd0;
						reset_acc;
						st <= 4'd1;
					end
				4'd11: begin
					running <= 1'b0;
					st <= 4'd0;
				end
				default: st <= 4'd0;
			endcase
		end
endmodule
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
module ember_top (
	clk,
	rst_n,
	h_awaddr,
	h_awvalid,
	h_awready,
	h_wdata,
	h_wstrb,
	h_wvalid,
	h_wready,
	h_bresp,
	h_bvalid,
	h_bready,
	h_araddr,
	h_arvalid,
	h_arready,
	h_rdata,
	h_rresp,
	h_rvalid,
	h_rready,
	dbg_en,
	dbg_addr,
	dbg_rdata,
	dbg_wdata,
	dbg_be,
	fb_select,
	vid_hs,
	vid_vs,
	vid_de,
	vid_pixel
);
	input wire clk;
	input wire rst_n;
	input wire [31:0] h_awaddr;
	input wire h_awvalid;
	output wire h_awready;
	input wire [31:0] h_wdata;
	input wire [3:0] h_wstrb;
	input wire h_wvalid;
	output wire h_wready;
	output wire [1:0] h_bresp;
	output wire h_bvalid;
	input wire h_bready;
	input wire [31:0] h_araddr;
	input wire h_arvalid;
	output wire h_arready;
	output wire [31:0] h_rdata;
	output wire [1:0] h_rresp;
	output wire h_rvalid;
	input wire h_rready;
	input wire dbg_en;
	localparam [31:0] ember_pkg_VRAM_BYTES = 524288;
	localparam [31:0] ember_pkg_VRAM_AW = 19;
	input wire [16:0] dbg_addr;
	output wire [31:0] dbg_rdata;
	input wire [31:0] dbg_wdata;
	input wire [3:0] dbg_be;
	input wire [1:0] fb_select;
	output wire vid_hs;
	output wire vid_vs;
	output wire vid_de;
	output wire [15:0] vid_pixel;
	localparam [31:0] ember_pkg_AXI_ADDR_W = 32;
	wire [34:0] h_aw_s;
	localparam [31:0] ember_pkg_AXI_DATA_W = 32;
	localparam [31:0] ember_pkg_AXI_STRB_W = 4;
	wire [(ember_pkg_AXI_DATA_W + ember_pkg_AXI_STRB_W) - 1:0] h_w_s;
	wire [1:0] h_b_s;
	wire [34:0] h_ar_s;
	wire [33:0] h_r_s;
	function automatic [31:0] sv2v_cast_C3924;
		input reg [31:0] inp;
		sv2v_cast_C3924 = inp;
	endfunction
	function automatic [34:0] sv2v_cast_3A02E;
		input reg [34:0] inp;
		sv2v_cast_3A02E = inp;
	endfunction
	assign h_aw_s = sv2v_cast_3A02E({sv2v_cast_C3924(h_awaddr), 3'b000});
	function automatic [31:0] sv2v_cast_615A7;
		input reg [31:0] inp;
		sv2v_cast_615A7 = inp;
	endfunction
	function automatic [3:0] sv2v_cast_44660;
		input reg [3:0] inp;
		sv2v_cast_44660 = inp;
	endfunction
	function automatic [(ember_pkg_AXI_DATA_W + ember_pkg_AXI_STRB_W) - 1:0] sv2v_cast_822A2;
		input reg [(ember_pkg_AXI_DATA_W + ember_pkg_AXI_STRB_W) - 1:0] inp;
		sv2v_cast_822A2 = inp;
	endfunction
	assign h_w_s = sv2v_cast_822A2({sv2v_cast_615A7(h_wdata), sv2v_cast_44660(h_wstrb)});
	assign h_ar_s = sv2v_cast_3A02E({sv2v_cast_C3924(h_araddr), 3'b000});
	assign h_bresp = h_b_s[1-:2];
	assign h_rresp = h_r_s[1-:2];
	wire [34:0] c_aw;
	wire c_awvalid;
	wire c_awready;
	wire [(ember_pkg_AXI_DATA_W + ember_pkg_AXI_STRB_W) - 1:0] c_w;
	wire c_wvalid;
	wire c_wready;
	wire [1:0] c_b;
	wire c_bvalid;
	wire c_bready;
	wire [34:0] c_ar;
	wire c_arvalid;
	wire c_arready;
	wire [33:0] c_r;
	wire c_rvalid;
	wire c_rready;
	wire [34:0] d_aw;
	wire d_awvalid;
	wire d_awready;
	wire [(ember_pkg_AXI_DATA_W + ember_pkg_AXI_STRB_W) - 1:0] d_w;
	wire d_wvalid;
	wire d_wready;
	wire [1:0] d_b;
	wire d_bvalid;
	wire d_bready;
	wire [34:0] d_ar;
	wire d_arvalid;
	wire d_arready;
	wire [33:0] d_r;
	wire d_rvalid;
	wire d_rready;
	wire [34:0] v_aw;
	wire v_awvalid;
	wire v_awready;
	wire [(ember_pkg_AXI_DATA_W + ember_pkg_AXI_STRB_W) - 1:0] v_w;
	wire v_wvalid;
	wire v_wready;
	wire [1:0] v_b;
	wire v_bvalid;
	wire v_bready;
	wire [34:0] v_ar;
	wire v_arvalid;
	wire v_arready;
	wire [33:0] v_r;
	wire v_rvalid;
	wire v_rready;
	ember_xbar u_xbar(
		.clk(clk),
		.rst_n(rst_n),
		.h_aw(h_aw_s),
		.h_awvalid(h_awvalid),
		.h_awready(h_awready),
		.h_w(h_w_s),
		.h_wvalid(h_wvalid),
		.h_wready(h_wready),
		.h_b(h_b_s),
		.h_bvalid(h_bvalid),
		.h_bready(h_bready),
		.h_ar(h_ar_s),
		.h_arvalid(h_arvalid),
		.h_arready(h_arready),
		.h_r(h_r_s),
		.h_rvalid(h_rvalid),
		.h_rready(h_rready),
		.d_aw(d_aw),
		.d_awvalid(d_awvalid),
		.d_awready(d_awready),
		.d_w(d_w),
		.d_wvalid(d_wvalid),
		.d_wready(d_wready),
		.d_b(d_b),
		.d_bvalid(d_bvalid),
		.d_bready(d_bready),
		.d_ar(d_ar),
		.d_arvalid(d_arvalid),
		.d_arready(d_arready),
		.d_r(d_r),
		.d_rvalid(d_rvalid),
		.d_rready(d_rready),
		.c_aw(c_aw),
		.c_awvalid(c_awvalid),
		.c_awready(c_awready),
		.c_w(c_w),
		.c_wvalid(c_wvalid),
		.c_wready(c_wready),
		.c_b(c_b),
		.c_bvalid(c_bvalid),
		.c_bready(c_bready),
		.c_ar(c_ar),
		.c_arvalid(c_arvalid),
		.c_arready(c_arready),
		.c_r(c_r),
		.c_rvalid(c_rvalid),
		.c_rready(c_rready),
		.v_aw(v_aw),
		.v_awvalid(v_awvalid),
		.v_awready(v_awready),
		.v_w(v_w),
		.v_wvalid(v_wvalid),
		.v_wready(v_wready),
		.v_b(v_b),
		.v_bvalid(v_bvalid),
		.v_bready(v_bready),
		.v_ar(v_ar),
		.v_arvalid(v_arvalid),
		.v_arready(v_arready),
		.v_r(v_r),
		.v_rvalid(v_rvalid),
		.v_rready(v_rready)
	);
	assign h_rdata = h_r_s[33-:32];
	wire fpa_we;
	wire [31:0] fpa_addr;
	wire [31:0] fpa_wdata;
	wire [3:0] fpa_be;
	wire fpa_req;
	wire [31:0] fpa_rdata;
	wire fpa2_we;
	wire [31:0] fpa2_addr;
	wire [31:0] fpa2_wdata;
	wire [3:0] fpa2_be;
	wire fpa2_req;
	wire [31:0] fpa2_rdata;
	wire fpa3_req;
	wire [31:0] fpa3_addr;
	wire [31:0] fpa3_rdata;
	wire rtr_kick;
	wire rtr_busy;
	wire blit_csr_we;
	wire blit_kick;
	wire blit_busy;
	wire [1:0] blit_csr_addr;
	wire [31:0] blit_csr_wdata;
	wire blit_fpa_we;
	wire [31:0] blit_fpa_addr;
	wire [31:0] blit_fpa_wdata;
	wire [3:0] blit_fpa_be;
	wire blit_fpa_req;
	wire gsx_csr_we;
	wire gsx_kick;
	wire gsx_busy;
	wire [1:0] gsx_csr_addr;
	wire [31:0] gsx_csr_wdata;
	wire gsx_gxa_we;
	wire [31:0] gsx_gxa_addr;
	wire [31:0] gsx_gxa_wdata;
	wire [3:0] gsx_gxa_be;
	wire gsx_gxa_req;
	wire [31:0] gsx_gxa_rdata;
	wire core_csr_we;
	wire core_kick;
	wire core_busy;
	wire [1:0] core_csr_addr;
	wire [31:0] core_csr_wdata;
	wire core_cxa_we;
	wire [31:0] core_cxa_addr;
	wire [31:0] core_cxa_wdata;
	wire [3:0] core_cxa_be;
	wire core_cxa_req;
	wire [31:0] core_cxa_rdata;
	wire core_ixa_req;
	wire [31:0] core_ixa_addr;
	wire [31:0] core_ixa_rdata;
	wire tu_csr_we;
	wire tu_kick;
	wire tu_busy;
	wire [1:0] tu_csr_addr;
	wire [31:0] tu_csr_wdata;
	wire tu_tua_we;
	wire [31:0] tu_tua_addr;
	wire [31:0] tu_tua_wdata;
	wire [3:0] tu_tua_be;
	wire tu_tua_req;
	wire [31:0] tu_tua_rdata;
	wire rtr_fpa_we;
	wire [31:0] rtr_fpa_addr;
	wire [31:0] rtr_fpa_wdata;
	wire [3:0] rtr_fpa_be;
	wire rtr_fpa_req;
	ember_cp u_cp(
		.clk(clk),
		.rst_n(rst_n),
		.s_aw(c_aw),
		.s_awvalid(c_awvalid),
		.s_awready(c_awready),
		.s_w(c_w),
		.s_wvalid(c_wvalid),
		.s_wready(c_wready),
		.s_b(c_b),
		.s_bvalid(c_bvalid),
		.s_bready(c_bready),
		.s_ar(c_ar),
		.s_arvalid(c_arvalid),
		.s_arready(c_arready),
		.s_r(c_r),
		.s_rvalid(c_rvalid),
		.s_rready(c_rready),
		.m_aw(d_aw),
		.m_awvalid(d_awvalid),
		.m_awready(d_awready),
		.m_w(d_w),
		.m_wvalid(d_wvalid),
		.m_wready(d_wready),
		.m_b(d_b),
		.m_bvalid(d_bvalid),
		.m_bready(d_bready),
		.m_ar(d_ar),
		.m_arvalid(d_arvalid),
		.m_arready(d_arready),
		.m_r(d_r),
		.m_rvalid(d_rvalid),
		.m_rready(d_rready),
		.rtr_kick(rtr_kick),
		.rtr_busy(rtr_busy),
		.blit_csr_we(blit_csr_we),
		.blit_csr_addr(blit_csr_addr),
		.blit_csr_wdata(blit_csr_wdata),
		.blit_kick(blit_kick),
		.blit_busy(blit_busy),
		.gsx_csr_we(gsx_csr_we),
		.gsx_csr_addr(gsx_csr_addr),
		.gsx_csr_wdata(gsx_csr_wdata),
		.gsx_kick(gsx_kick),
		.gsx_busy(gsx_busy),
		.core_csr_we(core_csr_we),
		.core_csr_addr(core_csr_addr),
		.core_csr_wdata(core_csr_wdata),
		.core_kick(core_kick),
		.core_busy(core_busy),
		.tu_csr_we(tu_csr_we),
		.tu_csr_addr(tu_csr_addr),
		.tu_csr_wdata(tu_csr_wdata),
		.tu_kick(tu_kick),
		.tu_busy(tu_busy)
	);
	ember_tu u_tu(
		.clk(clk),
		.rst_n(rst_n),
		.csr_we(tu_csr_we),
		.csr_addr(tu_csr_addr),
		.csr_wdata(tu_csr_wdata),
		.kick(tu_kick),
		.tua_we(tu_tua_we),
		.tua_addr(tu_tua_addr),
		.tua_wdata(tu_tua_wdata),
		.tua_be(tu_tua_be),
		.tua_req(tu_tua_req),
		.tua_rdata(tu_tua_rdata),
		.busy(tu_busy)
	);
	ember_core u_core(
		.clk(clk),
		.rst_n(rst_n),
		.csr_we(core_csr_we),
		.csr_addr(core_csr_addr),
		.csr_wdata(core_csr_wdata),
		.kick(core_kick),
		.cxa_we(core_cxa_we),
		.cxa_addr(core_cxa_addr),
		.cxa_wdata(core_cxa_wdata),
		.cxa_be(core_cxa_be),
		.cxa_req(core_cxa_req),
		.cxa_rdata(core_cxa_rdata),
		.ixa_req(core_ixa_req),
		.ixa_addr(core_ixa_addr),
		.ixa_rdata(core_ixa_rdata),
		.busy(core_busy)
	);
	ember_gsx u_gsx(
		.clk(clk),
		.rst_n(rst_n),
		.csr_we(gsx_csr_we),
		.csr_addr(gsx_csr_addr),
		.csr_wdata(gsx_csr_wdata),
		.kick(gsx_kick),
		.gxa_we(gsx_gxa_we),
		.gxa_addr(gsx_gxa_addr),
		.gxa_wdata(gsx_gxa_wdata),
		.gxa_be(gsx_gxa_be),
		.gxa_req(gsx_gxa_req),
		.gxa_rdata(gsx_gxa_rdata),
		.busy(gsx_busy)
	);
	ember_blit u_blit(
		.clk(clk),
		.rst_n(rst_n),
		.csr_we(blit_csr_we),
		.csr_addr(blit_csr_addr),
		.csr_wdata(blit_csr_wdata),
		.kick(blit_kick),
		.fpa_we(blit_fpa_we),
		.fpa_addr(blit_fpa_addr),
		.fpa_wdata(blit_fpa_wdata),
		.fpa_be(blit_fpa_be),
		.fpa_req(blit_fpa_req),
		.fpa_rdata(fpa_rdata),
		.busy(blit_busy),
		.done()
	);
	wire rtr_own = rtr_busy;
	wire blit_own = ~rtr_busy & blit_busy;
	assign fpa_we = (rtr_own ? rtr_fpa_we : (blit_own ? blit_fpa_we : 1'b0));
	assign fpa_addr = (rtr_own ? rtr_fpa_addr : (blit_own ? blit_fpa_addr : 32'h00000000));
	assign fpa_wdata = (rtr_own ? rtr_fpa_wdata : (blit_own ? blit_fpa_wdata : 32'h00000000));
	assign fpa_be = (rtr_own ? rtr_fpa_be : (blit_own ? blit_fpa_be : 4'h0));
	assign fpa_req = (rtr_own ? rtr_fpa_req : (blit_own ? blit_fpa_req : 1'b0));
	ember_rtr_top u_rtr(
		.clk(clk),
		.rst_n(rst_n),
		.kick(rtr_kick),
		.fpa_we(rtr_fpa_we),
		.fpa_addr(rtr_fpa_addr),
		.fpa_wdata(rtr_fpa_wdata),
		.fpa_be(rtr_fpa_be),
		.fpa_req(rtr_fpa_req),
		.fpa_rdata(fpa_rdata),
		.fpa2_req(fpa2_req),
		.fpa2_addr(fpa2_addr),
		.fpa2_rdata(fpa2_rdata),
		.busy(rtr_busy)
	);
	assign fpa2_we = 1'b0;
	assign fpa2_wdata = 32'h00000000;
	assign fpa2_be = 4'h0;
	ember_display u_disp(
		.clk(clk),
		.rst_n(rst_n),
		.fb_select(fb_select),
		.fpa3_req(fpa3_req),
		.fpa3_addr(fpa3_addr),
		.fpa3_rdata(fpa3_rdata),
		.vid_hs(vid_hs),
		.vid_vs(vid_vs),
		.vid_de(vid_de),
		.vid_pixel(vid_pixel)
	);
	ember_vram u_vram(
		.clk(clk),
		.rst_n(rst_n),
		.s_aw(v_aw),
		.s_awvalid(v_awvalid),
		.s_awready(v_awready),
		.s_w(v_w),
		.s_wvalid(v_wvalid),
		.s_wready(v_wready),
		.s_b(v_b),
		.s_bvalid(v_bvalid),
		.s_bready(v_bready),
		.s_ar(v_ar),
		.s_arvalid(v_arvalid),
		.s_arready(v_arready),
		.s_r(v_r),
		.s_rvalid(v_rvalid),
		.s_rready(v_rready),
		.dbg_en(dbg_en),
		.dbg_addr(dbg_addr),
		.dbg_rdata(dbg_rdata),
		.dbg_wdata(dbg_wdata),
		.dbg_be(dbg_be),
		.fpa_we(fpa_we),
		.fpa_addr(fpa_addr),
		.fpa_wdata(fpa_wdata),
		.fpa_be(fpa_be),
		.fpa_req(fpa_req),
		.fpa_rdata(fpa_rdata),
		.fpa2_we(fpa2_we),
		.fpa2_addr(fpa2_addr),
		.fpa2_wdata(fpa2_wdata),
		.fpa2_be(fpa2_be),
		.fpa2_req(fpa2_req),
		.fpa2_rdata(fpa2_rdata),
		.fpa3_req(fpa3_req),
		.fpa3_addr(fpa3_addr),
		.fpa3_rdata(fpa3_rdata),
		.gxa_we(gsx_gxa_we),
		.gxa_addr(gsx_gxa_addr),
		.gxa_wdata(gsx_gxa_wdata),
		.gxa_be(gsx_gxa_be),
		.gxa_req(gsx_gxa_req),
		.gxa_rdata(gsx_gxa_rdata),
		.cxa_we(core_cxa_we),
		.cxa_addr(core_cxa_addr),
		.cxa_wdata(core_cxa_wdata),
		.cxa_be(core_cxa_be),
		.cxa_req(core_cxa_req),
		.cxa_rdata(core_cxa_rdata),
		.ixa_req(core_ixa_req),
		.ixa_addr(core_ixa_addr),
		.ixa_rdata(core_ixa_rdata),
		.tua_we(tu_tua_we),
		.tua_addr(tu_tua_addr),
		.tua_wdata(tu_tua_wdata),
		.tua_be(tu_tua_be),
		.tua_req(tu_tua_req),
		.tua_rdata(tu_tua_rdata)
	);
endmodule