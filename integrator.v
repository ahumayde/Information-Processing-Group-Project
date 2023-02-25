module integrator #( 
    CLOCK_SPEED = 50000000
)(
    input         clk, 
    input         clk_en,
    input         start,
    input         reset,
    input  [31:0] dataA, // Accelerometer
    input  [31:0] dataB, // OLD SUM
    output        done,
    output [31:0] result // NEW SUM
);

    wire [31:0] TIME_PERIOD = 1 / CLOCK_SPEED;
    wire [31:0] dataA_old;
    wire done;
    wire count;

if (start == 1) begin 
    done = 0;
    count = 0;
end

always @(posedge clk ) begin
    if (count == 0)
        dataA_old = dataA;
    else begin
        result = dataB + TIME_PERIOD * ((dataA + dataA_old)/2);
        done = 1;
    end
    count += 1;
end     

endmodule 
