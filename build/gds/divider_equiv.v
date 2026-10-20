module gold (A, B, Y, R);
	parameter WIDTH = 1;

	(* force_downto *)
	input [WIDTH-1:0] A, B;
	(* force_downto *)
	output [WIDTH-1:0] Y, R;

	(* force_downto *)
	wire [WIDTH*WIDTH-1:0] chaindata;
	assign R = chaindata[WIDTH*WIDTH-1:WIDTH*(WIDTH-1)];

	genvar i;
	generate begin
		for (i = 0; i < WIDTH; i=i+1) begin:stage
			(* force_downto *)
			wire [WIDTH-1:0] stage_in;

			if (i == 0) begin:cp
				assign stage_in = A;
			end else begin:cp
				assign stage_in = chaindata[i*WIDTH-1:(i-1)*WIDTH];
			end

			assign Y[WIDTH-(i+1)] = stage_in >= {B, {WIDTH-(i+1){1'b0}}};
			assign chaindata[(i+1)*WIDTH-1:i*WIDTH] = Y[WIDTH-(i+1)] ? stage_in - {B, {WIDTH-(i+1){1'b0}}} : stage_in;
		end
	end endgenerate
endmodule
// Replacement for Yosys $__div_mod_u. Restoring long division with WIDTH+1
// remainder and bitwise ripple subtractors. No clocks or RTL interface changes.
module gate (A, B, Y, R);
  parameter WIDTH = 1;
  input [WIDTH-1:0] A, B;
  output [WIDTH-1:0] Y, R;
  wire [WIDTH:0] rem [0:WIDTH];
  assign rem[0] = {(WIDTH+1){1'b0}};
  genvar i, j;
  generate for (i = 0; i < WIDTH; i = i + 1) begin: stage
    wire [WIDTH:0] shifted;
    wire [WIDTH:0] diff;
    wire [WIDTH+1:0] borrow;
    assign shifted = {rem[i][WIDTH-1:0], A[WIDTH-1-i]};
    assign borrow[0] = 1'b0;
    for (j = 0; j <= WIDTH; j = j + 1) begin: subtract
      wire divisor_bit;
      if (j == WIDTH) assign divisor_bit = 1'b0;
      else assign divisor_bit = B[j];
      assign diff[j] = shifted[j] ^ divisor_bit ^ borrow[j];
      assign borrow[j+1] = (~shifted[j] & (divisor_bit | borrow[j]))
                        | (divisor_bit & borrow[j]);
    end
    assign Y[WIDTH-1-i] = ~borrow[WIDTH+1];
    assign rem[i+1] = borrow[WIDTH+1] ? shifted : diff;
  end endgenerate
  assign R = rem[WIDTH][WIDTH-1:0];
endmodule
