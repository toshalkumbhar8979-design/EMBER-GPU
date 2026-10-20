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