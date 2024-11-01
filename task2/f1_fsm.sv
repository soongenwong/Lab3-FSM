module f1_fsm (
    input   logic       rst,
    input   logic       en,
    input   logic       clk,
    output  logic [7:0] data_out
);

logic [7:0] sreg;

always_ff @ (posedge clk, posedge rst)
    if(rst)
        sreg <= 8'b00000001;
    else if(en)
        sreg <= {sreg[6:0], sreg[7] ^ sreg[5] ^ sreg[4] ^ sreg[3]};

assign data_out = sreg;

endmodule
