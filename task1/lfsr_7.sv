module lfsr_7 (
    input   logic       clk,
    input   logic       rst,
    input   logic       en,
    output  logic [6:0] data_out
);

logic [6:0] sreg;

always_ff @ (posedge clk, posedge rst)
    if (rst)
        sreg <= 7'b1;
    else if(en)
        sreg <= {sreg[5:0], sreg[6] ^ sreg[5]}

// x^7 + x^6 + 1
// x^7 + x^4 +1
// x^7 + x^3 + 1 (This is the one that is used in the labs)

assign data_out = sreg;


endmodule
