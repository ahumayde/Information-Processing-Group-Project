
module cpu (
	clk_clk,
	reset_reset_n,
	new_sdram_controller_0_wire_addr,
	new_sdram_controller_0_wire_ba,
	new_sdram_controller_0_wire_cas_n,
	new_sdram_controller_0_wire_cke,
	new_sdram_controller_0_wire_cs_n,
	new_sdram_controller_0_wire_dq,
	new_sdram_controller_0_wire_dqm,
	new_sdram_controller_0_wire_ras_n,
	new_sdram_controller_0_wire_we_n,
	sys_sdram_pll_0_sdram_clk_clk,
	accelerometer_spi_0_external_interface_I2C_SDAT,
	accelerometer_spi_0_external_interface_I2C_SCLK,
	accelerometer_spi_0_external_interface_G_SENSOR_CS_N,
	accelerometer_spi_0_external_interface_G_SENSOR_INT);	

	input		clk_clk;
	input		reset_reset_n;
	output	[12:0]	new_sdram_controller_0_wire_addr;
	output	[1:0]	new_sdram_controller_0_wire_ba;
	output		new_sdram_controller_0_wire_cas_n;
	output		new_sdram_controller_0_wire_cke;
	output		new_sdram_controller_0_wire_cs_n;
	inout	[15:0]	new_sdram_controller_0_wire_dq;
	output	[1:0]	new_sdram_controller_0_wire_dqm;
	output		new_sdram_controller_0_wire_ras_n;
	output		new_sdram_controller_0_wire_we_n;
	output		sys_sdram_pll_0_sdram_clk_clk;
	inout		accelerometer_spi_0_external_interface_I2C_SDAT;
	output		accelerometer_spi_0_external_interface_I2C_SCLK;
	output		accelerometer_spi_0_external_interface_G_SENSOR_CS_N;
	input		accelerometer_spi_0_external_interface_G_SENSOR_INT;
endmodule
