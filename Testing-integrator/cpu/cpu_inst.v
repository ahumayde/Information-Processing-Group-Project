	cpu u0 (
		.clk_clk                                              (<connected-to-clk_clk>),                                              //                                    clk.clk
		.reset_reset_n                                        (<connected-to-reset_reset_n>),                                        //                                  reset.reset_n
		.new_sdram_controller_0_wire_addr                     (<connected-to-new_sdram_controller_0_wire_addr>),                     //            new_sdram_controller_0_wire.addr
		.new_sdram_controller_0_wire_ba                       (<connected-to-new_sdram_controller_0_wire_ba>),                       //                                       .ba
		.new_sdram_controller_0_wire_cas_n                    (<connected-to-new_sdram_controller_0_wire_cas_n>),                    //                                       .cas_n
		.new_sdram_controller_0_wire_cke                      (<connected-to-new_sdram_controller_0_wire_cke>),                      //                                       .cke
		.new_sdram_controller_0_wire_cs_n                     (<connected-to-new_sdram_controller_0_wire_cs_n>),                     //                                       .cs_n
		.new_sdram_controller_0_wire_dq                       (<connected-to-new_sdram_controller_0_wire_dq>),                       //                                       .dq
		.new_sdram_controller_0_wire_dqm                      (<connected-to-new_sdram_controller_0_wire_dqm>),                      //                                       .dqm
		.new_sdram_controller_0_wire_ras_n                    (<connected-to-new_sdram_controller_0_wire_ras_n>),                    //                                       .ras_n
		.new_sdram_controller_0_wire_we_n                     (<connected-to-new_sdram_controller_0_wire_we_n>),                     //                                       .we_n
		.sys_sdram_pll_0_sdram_clk_clk                        (<connected-to-sys_sdram_pll_0_sdram_clk_clk>),                        //              sys_sdram_pll_0_sdram_clk.clk
		.accelerometer_spi_0_external_interface_I2C_SDAT      (<connected-to-accelerometer_spi_0_external_interface_I2C_SDAT>),      // accelerometer_spi_0_external_interface.I2C_SDAT
		.accelerometer_spi_0_external_interface_I2C_SCLK      (<connected-to-accelerometer_spi_0_external_interface_I2C_SCLK>),      //                                       .I2C_SCLK
		.accelerometer_spi_0_external_interface_G_SENSOR_CS_N (<connected-to-accelerometer_spi_0_external_interface_G_SENSOR_CS_N>), //                                       .G_SENSOR_CS_N
		.accelerometer_spi_0_external_interface_G_SENSOR_INT  (<connected-to-accelerometer_spi_0_external_interface_G_SENSOR_INT>)   //                                       .G_SENSOR_INT
	);

