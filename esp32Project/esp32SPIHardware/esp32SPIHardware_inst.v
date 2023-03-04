	esp32SPIHardware u0 (
		.accelerometer_spi_I2C_SDAT      (<connected-to-accelerometer_spi_I2C_SDAT>),      // accelerometer_spi.I2C_SDAT
		.accelerometer_spi_I2C_SCLK      (<connected-to-accelerometer_spi_I2C_SCLK>),      //                  .I2C_SCLK
		.accelerometer_spi_G_SENSOR_CS_N (<connected-to-accelerometer_spi_G_SENSOR_CS_N>), //                  .G_SENSOR_CS_N
		.accelerometer_spi_G_SENSOR_INT  (<connected-to-accelerometer_spi_G_SENSOR_INT>),  //                  .G_SENSOR_INT
		.clk_clk                         (<connected-to-clk_clk>),                         //               clk.clk
		.dram_addr                       (<connected-to-dram_addr>),                       //              dram.addr
		.dram_ba                         (<connected-to-dram_ba>),                         //                  .ba
		.dram_cas_n                      (<connected-to-dram_cas_n>),                      //                  .cas_n
		.dram_cke                        (<connected-to-dram_cke>),                        //                  .cke
		.dram_cs_n                       (<connected-to-dram_cs_n>),                       //                  .cs_n
		.dram_dq                         (<connected-to-dram_dq>),                         //                  .dq
		.dram_dqm                        (<connected-to-dram_dqm>),                        //                  .dqm
		.dram_ras_n                      (<connected-to-dram_ras_n>),                      //                  .ras_n
		.dram_we_n                       (<connected-to-dram_we_n>),                       //                  .we_n
		.esp32_spi_MISO                  (<connected-to-esp32_spi_MISO>),                  //         esp32_spi.MISO
		.esp32_spi_MOSI                  (<connected-to-esp32_spi_MOSI>),                  //                  .MOSI
		.esp32_spi_SCLK                  (<connected-to-esp32_spi_SCLK>),                  //                  .SCLK
		.esp32_spi_SS_n                  (<connected-to-esp32_spi_SS_n>),                  //                  .SS_n
		.reset_reset_n                   (<connected-to-reset_reset_n>),                   //             reset.reset_n
		.sdram_clk_clk                   (<connected-to-sdram_clk_clk>)                    //         sdram_clk.clk
	);

