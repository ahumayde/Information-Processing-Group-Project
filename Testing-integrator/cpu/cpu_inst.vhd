	component cpu is
		port (
			accelerometer_I2C_SDAT      : inout std_logic                     := 'X';             -- I2C_SDAT
			accelerometer_I2C_SCLK      : out   std_logic;                                        -- I2C_SCLK
			accelerometer_G_SENSOR_CS_N : out   std_logic;                                        -- G_SENSOR_CS_N
			accelerometer_G_SENSOR_INT  : in    std_logic                     := 'X';             -- G_SENSOR_INT
			clk_clk                     : in    std_logic                     := 'X';             -- clk
			dram_addr                   : out   std_logic_vector(12 downto 0);                    -- addr
			dram_ba                     : out   std_logic_vector(1 downto 0);                     -- ba
			dram_cas_n                  : out   std_logic;                                        -- cas_n
			dram_cke                    : out   std_logic;                                        -- cke
			dram_cs_n                   : out   std_logic;                                        -- cs_n
			dram_dq                     : inout std_logic_vector(15 downto 0) := (others => 'X'); -- dq
			dram_dqm                    : out   std_logic_vector(1 downto 0);                     -- dqm
			dram_ras_n                  : out   std_logic;                                        -- ras_n
			dram_we_n                   : out   std_logic;                                        -- we_n
			reset_reset_n               : in    std_logic                     := 'X';             -- reset_n
			sdram_clk_clk               : out   std_logic                                         -- clk
		);
	end component cpu;

	u0 : component cpu
		port map (
			accelerometer_I2C_SDAT      => CONNECTED_TO_accelerometer_I2C_SDAT,      -- accelerometer.I2C_SDAT
			accelerometer_I2C_SCLK      => CONNECTED_TO_accelerometer_I2C_SCLK,      --              .I2C_SCLK
			accelerometer_G_SENSOR_CS_N => CONNECTED_TO_accelerometer_G_SENSOR_CS_N, --              .G_SENSOR_CS_N
			accelerometer_G_SENSOR_INT  => CONNECTED_TO_accelerometer_G_SENSOR_INT,  --              .G_SENSOR_INT
			clk_clk                     => CONNECTED_TO_clk_clk,                     --           clk.clk
			dram_addr                   => CONNECTED_TO_dram_addr,                   --          dram.addr
			dram_ba                     => CONNECTED_TO_dram_ba,                     --              .ba
			dram_cas_n                  => CONNECTED_TO_dram_cas_n,                  --              .cas_n
			dram_cke                    => CONNECTED_TO_dram_cke,                    --              .cke
			dram_cs_n                   => CONNECTED_TO_dram_cs_n,                   --              .cs_n
			dram_dq                     => CONNECTED_TO_dram_dq,                     --              .dq
			dram_dqm                    => CONNECTED_TO_dram_dqm,                    --              .dqm
			dram_ras_n                  => CONNECTED_TO_dram_ras_n,                  --              .ras_n
			dram_we_n                   => CONNECTED_TO_dram_we_n,                   --              .we_n
			reset_reset_n               => CONNECTED_TO_reset_reset_n,               --         reset.reset_n
			sdram_clk_clk               => CONNECTED_TO_sdram_clk_clk                --     sdram_clk.clk
		);

