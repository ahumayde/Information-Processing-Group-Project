	cpu u0 (
		.accelerometer_I2C_SDAT      (<connected-to-accelerometer_I2C_SDAT>),      // accelerometer.I2C_SDAT
		.accelerometer_I2C_SCLK      (<connected-to-accelerometer_I2C_SCLK>),      //              .I2C_SCLK
		.accelerometer_G_SENSOR_CS_N (<connected-to-accelerometer_G_SENSOR_CS_N>), //              .G_SENSOR_CS_N
		.accelerometer_G_SENSOR_INT  (<connected-to-accelerometer_G_SENSOR_INT>),  //              .G_SENSOR_INT
		.clk_clk                     (<connected-to-clk_clk>),                     //           clk.clk
		.dram_addr                   (<connected-to-dram_addr>),                   //          dram.addr
		.dram_ba                     (<connected-to-dram_ba>),                     //              .ba
		.dram_cas_n                  (<connected-to-dram_cas_n>),                  //              .cas_n
		.dram_cke                    (<connected-to-dram_cke>),                    //              .cke
		.dram_cs_n                   (<connected-to-dram_cs_n>),                   //              .cs_n
		.dram_dq                     (<connected-to-dram_dq>),                     //              .dq
		.dram_dqm                    (<connected-to-dram_dqm>),                    //              .dqm
		.dram_ras_n                  (<connected-to-dram_ras_n>),                  //              .ras_n
		.dram_we_n                   (<connected-to-dram_we_n>),                   //              .we_n
		.reset_reset_n               (<connected-to-reset_reset_n>),               //         reset.reset_n
		.sdram_clk_clk               (<connected-to-sdram_clk_clk>)                //     sdram_clk.clk
	);

