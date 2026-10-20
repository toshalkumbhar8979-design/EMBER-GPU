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