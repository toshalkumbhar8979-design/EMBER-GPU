module ember_memif (
	clk,
	rst_n,
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
	v_rready,
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
	tua_rdata,
	mem_waddr,
	mem_wdata,
	mem_wbe_n,
	mem_we_n,
	mem0_raddr,
	mem0_rdata,
	mem0_re_n,
	mem1_raddr,
	mem1_rdata,
	mem1_re_n,
	mem2_raddr,
	mem2_rdata,
	mem2_re_n
);
	reg _sv2v_0;
	input wire clk;
	input wire rst_n;
	localparam [31:0] ember_pkg_AXI_ADDR_W = 32;
	input wire [34:0] v_aw;
	input wire v_awvalid;
	output wire v_awready;
	localparam [31:0] ember_pkg_AXI_DATA_W = 32;
	localparam [31:0] ember_pkg_AXI_STRB_W = 4;
	input wire [(ember_pkg_AXI_DATA_W + ember_pkg_AXI_STRB_W) - 1:0] v_w;
	input wire v_wvalid;
	output wire v_wready;
	output reg [1:0] v_b;
	output reg v_bvalid;
	input wire v_bready;
	input wire [34:0] v_ar;
	input wire v_arvalid;
	output wire v_arready;
	output wire [33:0] v_r;
	output wire v_rvalid;
	input wire v_rready;
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
	output wire [16:0] mem_waddr;
	output wire [31:0] mem_wdata;
	output wire [3:0] mem_wbe_n;
	output wire mem_we_n;
	output wire [16:0] mem0_raddr;
	input wire [31:0] mem0_rdata;
	output wire mem0_re_n;
	output wire [16:0] mem1_raddr;
	input wire [31:0] mem1_rdata;
	output wire mem1_re_n;
	output wire [16:0] mem2_raddr;
	input wire [31:0] mem2_rdata;
	output wire mem2_re_n;
	localparam [31:0] ember_pkg_VRAM_BYTES = 524288;
	localparam [31:0] ember_pkg_VRAM_AW = 19;
	localparam [31:0] MEM_AW = 17;
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
	wire fpa_wr = fpa_we;
	wire fpa2_wr = fpa2_we;
	wire cxa_wr = cxa_we;
	wire tua_wr = tua_we;
	wire gxa_wr = gxa_we;
	wire eng_wr = (((fpa_wr | fpa2_wr) | cxa_wr) | tua_wr) | gxa_wr;
	reg [34:0] aw_q;
	reg aw_v;
	reg [(ember_pkg_AXI_DATA_W + ember_pkg_AXI_STRB_W) - 1:0] w_q;
	reg w_v;
	wire axi_wr = ((aw_v && w_v) && (!v_bvalid || v_bready)) && !eng_wr;
	wire wr_fire = eng_wr | axi_wr;
	always @(posedge clk or negedge rst_n)
		if (!rst_n) begin
			aw_q <= 1'sb0;
			aw_v <= 1'b0;
		end
		else if (v_awvalid && v_awready) begin
			aw_q <= v_aw;
			aw_v <= 1'b1;
		end
		else if (axi_wr)
			aw_v <= 1'b0;
	always @(posedge clk or negedge rst_n)
		if (!rst_n) begin
			w_q <= 1'sb0;
			w_v <= 1'b0;
		end
		else if (v_wvalid && v_wready) begin
			w_q <= v_w;
			w_v <= 1'b1;
		end
		else if (axi_wr)
			w_v <= 1'b0;
	assign v_awready = !aw_v || axi_wr;
	assign v_wready = !w_v || axi_wr;
	reg [31:0] wr_addr32;
	reg [31:0] wr_data;
	reg [3:0] wr_be;
	always @(*) begin
		if (_sv2v_0)
			;
		if (fpa_wr) begin
			wr_addr32 = fpa_addr;
			wr_data = fpa_wdata;
			wr_be = fpa_be;
		end
		else if (fpa2_wr) begin
			wr_addr32 = fpa2_addr;
			wr_data = fpa2_wdata;
			wr_be = fpa2_be;
		end
		else if (cxa_wr) begin
			wr_addr32 = cxa_addr;
			wr_data = cxa_wdata;
			wr_be = cxa_be;
		end
		else if (tua_wr) begin
			wr_addr32 = tua_addr;
			wr_data = tua_wdata;
			wr_be = tua_be;
		end
		else if (gxa_wr) begin
			wr_addr32 = gxa_addr;
			wr_data = gxa_wdata;
			wr_be = gxa_be;
		end
		else begin
			wr_addr32 = aw_q[34-:32];
			wr_data = w_q[35-:32];
			wr_be = w_q[3-:ember_pkg_AXI_STRB_W];
		end
	end
	assign mem_waddr = addr2word(wr_addr32);
	assign mem_wdata = wr_data;
	assign mem_wbe_n = ~wr_be;
	assign mem_we_n = ~wr_fire;
	localparam [1:0] ember_pkg_RESP_OKAY = 2'b00;
	always @(posedge clk or negedge rst_n)
		if (!rst_n) begin
			v_bvalid <= 1'b0;
			v_b[1-:2] <= ember_pkg_RESP_OKAY;
		end
		else if (axi_wr) begin
			v_bvalid <= 1'b1;
			v_b[1-:2] <= ember_pkg_RESP_OKAY;
		end
		else if (v_bvalid && v_bready)
			v_bvalid <= 1'b0;
	assign mem0_raddr = addr2word(fpa3_addr);
	assign mem0_re_n = ~fpa3_req;
	reg [31:0] fpa3_rdata_q;
	always @(posedge clk)
		if (fpa3_req)
			fpa3_rdata_q <= mem0_rdata;
	assign fpa3_rdata = fpa3_rdata_q;
	wire gnt_fpa = fpa_req;
	wire gnt_fpa2 = !fpa_req & fpa2_req;
	wire gnt_cxa = (!fpa_req & !fpa2_req) & cxa_req;
	wire gnt_tua = ((!fpa_req & !fpa2_req) & !cxa_req) & tua_req;
	wire gnt_gxa = (((!fpa_req & !fpa2_req) & !cxa_req) & !tua_req) & gxa_req;
	wire ch1_req = (((fpa_req | fpa2_req) | cxa_req) | tua_req) | gxa_req;
	reg [31:0] ch1_addr;
	always @(*) begin
		if (_sv2v_0)
			;
		if (gnt_fpa)
			ch1_addr = fpa_addr;
		else if (gnt_fpa2)
			ch1_addr = fpa2_addr;
		else if (gnt_cxa)
			ch1_addr = cxa_addr;
		else if (gnt_tua)
			ch1_addr = tua_addr;
		else
			ch1_addr = gxa_addr;
	end
	assign mem1_raddr = addr2word(ch1_addr);
	assign mem1_re_n = ~ch1_req;
	reg [31:0] fpa_rdata_q;
	reg [31:0] fpa2_rdata_q;
	reg [31:0] cxa_rdata_q;
	reg [31:0] tua_rdata_q;
	reg [31:0] gxa_rdata_q;
	always @(posedge clk) begin
		if (gnt_fpa)
			fpa_rdata_q <= mem1_rdata;
		if (gnt_fpa2)
			fpa2_rdata_q <= mem1_rdata;
		if (gnt_cxa)
			cxa_rdata_q <= mem1_rdata;
		if (gnt_tua)
			tua_rdata_q <= mem1_rdata;
		if (gnt_gxa)
			gxa_rdata_q <= mem1_rdata;
	end
	assign fpa_rdata = fpa_rdata_q;
	assign fpa2_rdata = fpa2_rdata_q;
	assign cxa_rdata = cxa_rdata_q;
	assign tua_rdata = tua_rdata_q;
	assign gxa_rdata = gxa_rdata_q;
	reg ar_v;
	wire ar_accept = v_arvalid && v_arready;
	assign v_arready = (!ar_v || (v_rvalid && v_rready)) && !ixa_req;
	assign mem2_raddr = addr2word((ixa_req ? ixa_addr : v_ar[34-:32]));
	assign mem2_re_n = ~(ixa_req | ar_accept);
	reg [31:0] ixa_rdata_q;
	reg [31:0] axi_rdata_q;
	always @(posedge clk) begin
		if (ixa_req)
			ixa_rdata_q <= mem2_rdata;
		if (ar_accept)
			axi_rdata_q <= mem2_rdata;
	end
	assign ixa_rdata = ixa_rdata_q;
	always @(posedge clk or negedge rst_n)
		if (!rst_n)
			ar_v <= 1'b0;
		else if (ar_accept)
			ar_v <= 1'b1;
		else if (v_rvalid && v_rready)
			ar_v <= 1'b0;
	assign v_r[33-:32] = axi_rdata_q;
	assign v_r[1-:2] = ember_pkg_RESP_OKAY;
	assign v_rvalid = ar_v;
	initial _sv2v_0 = 0;
endmodule