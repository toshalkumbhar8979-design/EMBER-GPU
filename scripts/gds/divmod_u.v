// Replacement for Yosys $__div_mod_u. Restoring long division with WIDTH+1
// remainder and bitwise ripple subtractors. No clocks or RTL interface changes.
module \$__div_mod_u (A, B, Y, R);
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
