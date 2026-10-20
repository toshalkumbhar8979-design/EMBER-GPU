`default_nettype none
module ember_die (
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
	vid_pixel,
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
	tua_rdata
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
	input wire [31:0] dbg_rdata;
	input wire [31:0] dbg_wdata;
	input wire [3:0] dbg_be;
	input wire [1:0] fb_select;
	output wire vid_hs;
	output wire vid_vs;
	output wire vid_de;
	output wire [15:0] vid_pixel;
	localparam [31:0] ember_pkg_AXI_ADDR_W = 32;
	output wire [34:0] v_aw;
	output wire v_awvalid;
	input wire v_awready;
	localparam [31:0] ember_pkg_AXI_DATA_W = 32;
	localparam [31:0] ember_pkg_AXI_STRB_W = 4;
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
	output wire fpa_we;
	output wire [31:0] fpa_addr;
	output wire [31:0] fpa_wdata;
	output wire [3:0] fpa_be;
	output wire fpa_req;
	input wire [31:0] fpa_rdata;
	output wire fpa2_we;
	output wire [31:0] fpa2_addr;
	output wire [31:0] fpa2_wdata;
	output wire [3:0] fpa2_be;
	output wire fpa2_req;
	input wire [31:0] fpa2_rdata;
	output wire fpa3_req;
	output wire [31:0] fpa3_addr;
	input wire [31:0] fpa3_rdata;
	output wire gxa_we;
	output wire [31:0] gxa_addr;
	output wire [31:0] gxa_wdata;
	output wire [3:0] gxa_be;
	output wire gxa_req;
	input wire [31:0] gxa_rdata;
	output wire cxa_we;
	output wire [31:0] cxa_addr;
	output wire [31:0] cxa_wdata;
	output wire [3:0] cxa_be;
	output wire cxa_req;
	input wire [31:0] cxa_rdata;
	output wire ixa_req;
	output wire [31:0] ixa_addr;
	input wire [31:0] ixa_rdata;
	output wire tua_we;
	output wire [31:0] tua_addr;
	output wire [31:0] tua_wdata;
	output wire [3:0] tua_be;
	output wire tua_req;
	input wire [31:0] tua_rdata;
	wire [34:0] h_aw_s;
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
	wire core_csr_we;
	wire core_kick;
	wire core_busy;
	wire [1:0] core_csr_addr;
	wire [31:0] core_csr_wdata;
	wire tu_csr_we;
	wire tu_kick;
	wire tu_busy;
	wire [1:0] tu_csr_addr;
	wire [31:0] tu_csr_wdata;
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
		.tua_we(tua_we),
		.tua_addr(tua_addr),
		.tua_wdata(tua_wdata),
		.tua_be(tua_be),
		.tua_req(tua_req),
		.tua_rdata(tua_rdata),
		.busy(tu_busy)
	);
	ember_core u_core(
		.clk(clk),
		.rst_n(rst_n),
		.csr_we(core_csr_we),
		.csr_addr(core_csr_addr),
		.csr_wdata(core_csr_wdata),
		.kick(core_kick),
		.cxa_we(cxa_we),
		.cxa_addr(cxa_addr),
		.cxa_wdata(cxa_wdata),
		.cxa_be(cxa_be),
		.cxa_req(cxa_req),
		.cxa_rdata(cxa_rdata),
		.ixa_req(ixa_req),
		.ixa_addr(ixa_addr),
		.ixa_rdata(ixa_rdata),
		.busy(core_busy)
	);
	ember_gsx u_gsx(
		.clk(clk),
		.rst_n(rst_n),
		.csr_we(gsx_csr_we),
		.csr_addr(gsx_csr_addr),
		.csr_wdata(gsx_csr_wdata),
		.kick(gsx_kick),
		.gxa_we(gxa_we),
		.gxa_addr(gxa_addr),
		.gxa_wdata(gxa_wdata),
		.gxa_be(gxa_be),
		.gxa_req(gxa_req),
		.gxa_rdata(gxa_rdata),
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
endmodule
`default_nettype wire