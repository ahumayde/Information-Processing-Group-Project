/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_cpu' in SOPC Builder design 'esp32SPIHardware'
 * SOPC Builder design path: ../../esp32SPIHardware.sopcinfo
 *
 * Generated: Thu Mar 02 20:49:10 GMT 2023
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_gen2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x08000820
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 100000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "fast"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1c
#define ALT_CPU_DCACHE_BYPASS_MASK 0x80000000
#define ALT_CPU_DCACHE_LINE_SIZE 32
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_DCACHE_SIZE 2048
#define ALT_CPU_EXCEPTION_ADDR 0x04000020
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 100000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 1
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_EXTRA_EXCEPTION_INFO
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 2048
#define ALT_CPU_INITDA_SUPPORTED
#define ALT_CPU_INST_ADDR_WIDTH 0x1c
#define ALT_CPU_NAME "nios2_cpu"
#define ALT_CPU_NUM_OF_SHADOW_REG_SETS 0
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_RESET_ADDR 0x04000000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x08000820
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 100000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "fast"
#define NIOS2_DATA_ADDR_WIDTH 0x1c
#define NIOS2_DCACHE_BYPASS_MASK 0x80000000
#define NIOS2_DCACHE_LINE_SIZE 32
#define NIOS2_DCACHE_LINE_SIZE_LOG2 5
#define NIOS2_DCACHE_SIZE 2048
#define NIOS2_EXCEPTION_ADDR 0x04000020
#define NIOS2_FLASH_ACCELERATOR_LINES 0
#define NIOS2_FLASH_ACCELERATOR_LINE_SIZE 0
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 1
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_EXTRA_EXCEPTION_INFO
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 2048
#define NIOS2_INITDA_SUPPORTED
#define NIOS2_INST_ADDR_WIDTH 0x1c
#define NIOS2_NUM_OF_SHADOW_REG_SETS 0
#define NIOS2_OCI_VERSION 1
#define NIOS2_RESET_ADDR 0x04000000


/*
 * Custom instruction macros
 *
 */

#define ALT_CI_NIOS_CUSTOM_INSTR_FLOATING_POINT_0(n,A,B) __builtin_custom_inii(ALT_CI_NIOS_CUSTOM_INSTR_FLOATING_POINT_0_N+(n&ALT_CI_NIOS_CUSTOM_INSTR_FLOATING_POINT_0_N_MASK),(A),(B))
#define ALT_CI_NIOS_CUSTOM_INSTR_FLOATING_POINT_0_N 0xfc
#define ALT_CI_NIOS_CUSTOM_INSTR_FLOATING_POINT_0_N_MASK ((1<<2)-1)


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_NEW_SDRAM_CONTROLLER
#define __ALTERA_AVALON_SPI
#define __ALTERA_AVALON_TIMER
#define __ALTERA_NIOS2_GEN2
#define __ALTERA_NIOS_CUSTOM_INSTR_FLOATING_POINT
#define __ALTERA_UP_AVALON_ACCELEROMETER_SPI


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "MAX 10"
#define ALT_IRQ_BASE NULL
#define ALT_LEGACY_INTERRUPT_API_PRESENT
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag"
#define ALT_STDERR_BASE 0x8001080
#define ALT_STDERR_DEV jtag
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag"
#define ALT_STDIN_BASE 0x8001080
#define ALT_STDIN_DEV jtag
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag"
#define ALT_STDOUT_BASE 0x8001080
#define ALT_STDOUT_DEV jtag
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "esp32SPIHardware"


/*
 * accelerometer configuration
 *
 */

#define ACCELEROMETER_BASE 0x8001088
#define ACCELEROMETER_IRQ 5
#define ACCELEROMETER_IRQ_INTERRUPT_CONTROLLER_ID 0
#define ACCELEROMETER_NAME "/dev/accelerometer"
#define ACCELEROMETER_SPAN 2
#define ACCELEROMETER_TYPE "altera_up_avalon_accelerometer_spi"
#define ALT_MODULE_CLASS_accelerometer altera_up_avalon_accelerometer_spi


/*
 * dram_controller configuration
 *
 */

#define ALT_MODULE_CLASS_dram_controller altera_avalon_new_sdram_controller
#define DRAM_CONTROLLER_BASE 0x4000000
#define DRAM_CONTROLLER_CAS_LATENCY 3
#define DRAM_CONTROLLER_CONTENTS_INFO
#define DRAM_CONTROLLER_INIT_NOP_DELAY 0.0
#define DRAM_CONTROLLER_INIT_REFRESH_COMMANDS 2
#define DRAM_CONTROLLER_IRQ -1
#define DRAM_CONTROLLER_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DRAM_CONTROLLER_IS_INITIALIZED 1
#define DRAM_CONTROLLER_NAME "/dev/dram_controller"
#define DRAM_CONTROLLER_POWERUP_DELAY 100.0
#define DRAM_CONTROLLER_REFRESH_PERIOD 15.625
#define DRAM_CONTROLLER_REGISTER_DATA_IN 1
#define DRAM_CONTROLLER_SDRAM_ADDR_WIDTH 0x19
#define DRAM_CONTROLLER_SDRAM_BANK_WIDTH 2
#define DRAM_CONTROLLER_SDRAM_COL_WIDTH 10
#define DRAM_CONTROLLER_SDRAM_DATA_WIDTH 16
#define DRAM_CONTROLLER_SDRAM_NUM_BANKS 4
#define DRAM_CONTROLLER_SDRAM_NUM_CHIPSELECTS 1
#define DRAM_CONTROLLER_SDRAM_ROW_WIDTH 13
#define DRAM_CONTROLLER_SHARED_DATA 0
#define DRAM_CONTROLLER_SIM_MODEL_BASE 0
#define DRAM_CONTROLLER_SPAN 67108864
#define DRAM_CONTROLLER_STARVATION_INDICATOR 0
#define DRAM_CONTROLLER_TRISTATE_BRIDGE_SLAVE ""
#define DRAM_CONTROLLER_TYPE "altera_avalon_new_sdram_controller"
#define DRAM_CONTROLLER_T_AC 5.5
#define DRAM_CONTROLLER_T_MRD 3
#define DRAM_CONTROLLER_T_RCD 20.0
#define DRAM_CONTROLLER_T_RFC 70.0
#define DRAM_CONTROLLER_T_RP 20.0
#define DRAM_CONTROLLER_T_WR 14.0


/*
 * esp32_spi configuration
 *
 */

#define ALT_MODULE_CLASS_esp32_spi altera_avalon_spi
#define ESP32_SPI_BASE 0x8001000
#define ESP32_SPI_CLOCKMULT 1
#define ESP32_SPI_CLOCKPHASE 0
#define ESP32_SPI_CLOCKPOLARITY 0
#define ESP32_SPI_CLOCKUNITS "Hz"
#define ESP32_SPI_DATABITS 16
#define ESP32_SPI_DATAWIDTH 16
#define ESP32_SPI_DELAYMULT "1.0E-9"
#define ESP32_SPI_DELAYUNITS "ns"
#define ESP32_SPI_EXTRADELAY 0
#define ESP32_SPI_INSERT_SYNC 0
#define ESP32_SPI_IRQ 1
#define ESP32_SPI_IRQ_INTERRUPT_CONTROLLER_ID 0
#define ESP32_SPI_ISMASTER 1
#define ESP32_SPI_LSBFIRST 0
#define ESP32_SPI_NAME "/dev/esp32_spi"
#define ESP32_SPI_NUMSLAVES 1
#define ESP32_SPI_PREFIX "spi_"
#define ESP32_SPI_SPAN 32
#define ESP32_SPI_SYNC_REG_DEPTH 2
#define ESP32_SPI_TARGETCLOCK 40000000u
#define ESP32_SPI_TARGETSSDELAY "0.0"
#define ESP32_SPI_TYPE "altera_avalon_spi"


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 32
#define ALT_SYS_CLK TIMER_0
#define ALT_TIMESTAMP_CLK none


/*
 * jtag configuration
 *
 */

#define ALT_MODULE_CLASS_jtag altera_avalon_jtag_uart
#define JTAG_BASE 0x8001080
#define JTAG_IRQ 0
#define JTAG_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_NAME "/dev/jtag"
#define JTAG_READ_DEPTH 64
#define JTAG_READ_THRESHOLD 8
#define JTAG_SPAN 8
#define JTAG_TYPE "altera_avalon_jtag_uart"
#define JTAG_WRITE_DEPTH 64
#define JTAG_WRITE_THRESHOLD 8


/*
 * timer_0 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_0 altera_avalon_timer
#define TIMER_0_ALWAYS_RUN 0
#define TIMER_0_BASE 0x8001060
#define TIMER_0_COUNTER_SIZE 32
#define TIMER_0_FIXED_PERIOD 0
#define TIMER_0_FREQ 100000000
#define TIMER_0_IRQ 2
#define TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_0_LOAD_VALUE 99999
#define TIMER_0_MULT 0.001
#define TIMER_0_NAME "/dev/timer_0"
#define TIMER_0_PERIOD 1
#define TIMER_0_PERIOD_UNITS "ms"
#define TIMER_0_RESET_OUTPUT 0
#define TIMER_0_SNAPSHOT 1
#define TIMER_0_SPAN 32
#define TIMER_0_TICKS_PER_SEC 1000
#define TIMER_0_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_0_TYPE "altera_avalon_timer"


/*
 * timer_1 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_1 altera_avalon_timer
#define TIMER_1_ALWAYS_RUN 0
#define TIMER_1_BASE 0x8001040
#define TIMER_1_COUNTER_SIZE 32
#define TIMER_1_FIXED_PERIOD 0
#define TIMER_1_FREQ 100000000
#define TIMER_1_IRQ 3
#define TIMER_1_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_1_LOAD_VALUE 99999
#define TIMER_1_MULT 0.001
#define TIMER_1_NAME "/dev/timer_1"
#define TIMER_1_PERIOD 1
#define TIMER_1_PERIOD_UNITS "ms"
#define TIMER_1_RESET_OUTPUT 0
#define TIMER_1_SNAPSHOT 1
#define TIMER_1_SPAN 32
#define TIMER_1_TICKS_PER_SEC 1000
#define TIMER_1_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_1_TYPE "altera_avalon_timer"


/*
 * timer_2 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_2 altera_avalon_timer
#define TIMER_2_ALWAYS_RUN 0
#define TIMER_2_BASE 0x8001020
#define TIMER_2_COUNTER_SIZE 32
#define TIMER_2_FIXED_PERIOD 0
#define TIMER_2_FREQ 100000000
#define TIMER_2_IRQ 4
#define TIMER_2_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_2_LOAD_VALUE 99999
#define TIMER_2_MULT 0.001
#define TIMER_2_NAME "/dev/timer_2"
#define TIMER_2_PERIOD 1
#define TIMER_2_PERIOD_UNITS "ms"
#define TIMER_2_RESET_OUTPUT 0
#define TIMER_2_SNAPSHOT 1
#define TIMER_2_SPAN 32
#define TIMER_2_TICKS_PER_SEC 1000
#define TIMER_2_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_2_TYPE "altera_avalon_timer"

#endif /* __SYSTEM_H_ */
