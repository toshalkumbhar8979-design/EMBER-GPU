// Equivalent carry recurrence for Yosys $lcu; slower than Brent-Kung but
// substantially smaller mapping templates for the very wide RTR dividers.
(* techmap_celltype = "$lcu" *)
module ember_ripple_lcu #(parameter WIDTH = 2)
(
  input [WIDTH-1:0] P, G,
  input CI,
  output [WIDTH-1:0] CO
);
  wire [WIDTH:0] carry;
  assign carry[0] = CI;
  genvar i;
  generate for (i = 0; i < WIDTH; i = i + 1) begin: bit_carry
    assign carry[i+1] = G[i] | (P[i] & carry[i]);
    assign CO[i] = carry[i+1];
  end endgenerate
endmodule
