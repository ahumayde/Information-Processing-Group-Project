module integrator(input  wire  clk,
	         input  wire  clk_en,
			 input  wire  reset,
			 input  wire  start,
			 output reg   done,
			 input  wire  [31:0] dataa,
			 input  wire  [31:0] datab,
			 output reg   [31:0] result);
    
  reg count;
  initial count = 0;
  wire [31 : 0] TIME_PERIOD;
  assign TIME_PERIOD = 1 / 5000000;
  reg [31 : 0] dataa_old;

  always @(posedge clk or posedge reset)
  begin
    if (reset) 
    begin
      count <= 1'h0;	
      done <= 1'b0;
    end
    else begin
	  done <= 1'b0;
	  if (clk_en & start & (count == 0))
	      begin
            dataa_old <= dataa;
            count <= count + 1;
            done <= 1'b0;
          end
      else if (clk_en & start & (count == 1))
          begin
            result <= datab + TIME_PERIOD * ((dataa + dataa_old)/2);
            done <= 1'b1;
          end
      end
    end

endmodule
