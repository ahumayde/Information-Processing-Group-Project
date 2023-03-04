
module esp32SPIHardware (
	accelerometer_spi_I2C_SDAT,
	accelerometer_spi_I2C_SCLK,
	accelerometer_spi_G_SENSOR_CS_N,
	accelerometer_spi_G_SENSOR_INT,
	clk_clk,
	dram_addr,
	dram_ba,
	dram_cas_n,
	dram_cke,
	dram_cs_n,
	dram_dq,
	dram_dqm,
	dram_ras_n,
	dram_we_n,
	esp32_spi_MISO,
	esp32_spi_MOSI,
	esp32_spi_SCLK,
	esp32_spi_SS_n,
	reset_reset_n,
	sdram_clk_clk,
	button_export);	

	inout		accelerometer_spi_I2C_SDAT;
	output		accelerometer_spi_I2C_SCLK;
	output		accelerometer_spi_G_SENSOR_CS_N;
	input		accelerometer_spi_G_SENSOR_INT;
	input		clk_clk;
	output	[12:0]	dram_addr;
	output	[1:0]	dram_ba;
	output		dram_cas_n;
	output		dram_cke;
	output		dram_cs_n;
	inout	[15:0]	dram_dq;
	output	[1:0]	dram_dqm;
	output		dram_ras_n;
	output		dram_we_n;
	input		esp32_spi_MISO;
	output		esp32_spi_MOSI;
	output		esp32_spi_SCLK;
	output		esp32_spi_SS_n;
	input		reset_reset_n;
	output		sdram_clk_clk;
	input	[1:0]	button_export;
endmodule
