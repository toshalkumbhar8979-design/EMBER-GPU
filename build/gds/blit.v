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