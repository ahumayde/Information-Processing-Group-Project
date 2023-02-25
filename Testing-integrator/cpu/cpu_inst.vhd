	component cpu is
		port (
			clk_clk                                              : in    std_logic                     := 'X';             -- clk
			reset_reset_n                                        : in    std_logic                     := 'X';             -- reset_n
			new_sdram_controller_0_wire_addr                     : out   std_logic_vector(12 downto 0);                    -- addr
			new_sdram_controller_0_wire_ba                       : out   std_logic_vector(1 downto 0);                     -- ba
			new_sdram_controller_0_wire_cas_n                    : out   std_logic;                                        -- cas_n
			new_sdram_controller_0_wire_cke                      : out   std_logic;                                        -- cke
			new_sdram_controller_0_wire_cs_n                     : out   std_logic;                                        -- cs_n
			new_sdram_controller_0_wire_dq                       : inout std_logic_vector(15 downto 0) := (others => 'X'); -- dq
			new_sdram_controller_0_wire_dqm                      : out   std_logic_vector(1 downto 0);                     -- dqm
			new_sdram_controller_0_wire_ras_n                    : out   std_logic;                                        -- ras_n
			new_sdram_controller_0_wire_we_n                     : out   std_logic;                                        -- we_n
			sys_sdram_pll_0_sdram_clk_clk                        : out   std_logic;                                        -- clk
			accelerometer_spi_0_external_interface_I2C_SDAT      : inout std_logic                     := 'X';             -- I2C_SDAT
			accelerometer_spi_0_external_interface_I2C_SCLK      : out   std_logic;                                        -- I2C_SCLK
			accelerometer_spi_0_external_interface_G_SENSOR_CS_N : out   std_logic;                                        -- G_SENSOR_CS_N
			accelerometer_spi_0_external_interface_G_SENSOR_INT  : in    std_logic                     := 'X'              -- G_SENSOR_INT
		);
	end component cpu;

	u0 : component cpu
		port map (
			clk_clk                                              => CONNECTED_TO_clk_clk,                                              --                                    clk.clk
			reset_reset_n                                        => CONNECTED_TO_reset_reset_n,                                        --                                  reset.reset_n
			new_sdram_controller_0_wire_addr                     => CONNECTED_TO_new_sdram_controller_0_wire_addr,                     --            new_sdram_controller_0_wire.addr
			new_sdram_controller_0_wire_ba                       => CONNECTED_TO_new_sdram_controller_0_wire_ba,                       --                                       .ba
			new_sdram_controller_0_wire_cas_n                    => CONNECTED_TO_new_sdram_controller_0_wire_cas_n,                    --                                       .cas_n
			new_sdram_controller_0_wire_cke                      => CONNECTED_TO_new_sdram_controller_0_wire_cke,                      --                                       .cke
			new_sdram_controller_0_wire_cs_n                     => CONNECTED_TO_new_sdram_controller_0_wire_cs_n,                     --                                       .cs_n
			new_sdram_controller_0_wire_dq                       => CONNECTED_TO_new_sdram_controller_0_wire_dq,                       --                                       .dq
			new_sdram_controller_0_wire_dqm                      => CONNECTED_TO_new_sdram_controller_0_wire_dqm,                      --                                       .dqm
			new_sdram_controller_0_wire_ras_n                    => CONNECTED_TO_new_sdram_controller_0_wire_ras_n,                    --                                       .ras_n
			new_sdram_controller_0_wire_we_n                     => CONNECTED_TO_new_sdram_controller_0_wire_we_n,                     --                                       .we_n
			sys_sdram_pll_0_sdram_clk_clk                        => CONNECTED_TO_sys_sdram_pll_0_sdram_clk_clk,                        --              sys_sdram_pll_0_sdram_clk.clk
			accelerometer_spi_0_external_interface_I2C_SDAT      => CONNECTED_TO_accelerometer_spi_0_external_interface_I2C_SDAT,      -- accelerometer_spi_0_external_interface.I2C_SDAT
			accelerometer_spi_0_external_interface_I2C_SCLK      => CONNECTED_TO_accelerometer_spi_0_external_interface_I2C_SCLK,      --                                       .I2C_SCLK
			accelerometer_spi_0_external_interface_G_SENSOR_CS_N => CONNECTED_TO_accelerometer_spi_0_external_interface_G_SENSOR_CS_N, --                                       .G_SENSOR_CS_N
			accelerometer_spi_0_external_interface_G_SENSOR_INT  => CONNECTED_TO_accelerometer_spi_0_external_interface_G_SENSOR_INT   --                                       .G_SENSOR_INT
		);

