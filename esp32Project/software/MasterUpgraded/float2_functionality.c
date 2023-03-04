
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "system.h"
#include <altera_avalon_jtag_uart.h>
#include <altera_avalon_spi.h>
#include <altera_avalon_spi_regs.h>
#include <altera_up_avalon_accelerometer_spi.h>
#include <altera_up_avalon_accelerometer_spi_regs.h>
#include <sys/alt_irq.h>
#include <unistd.h>
#include <stdlib.h>

void sendReading ( alt_32 x ) 
{
  if ( IORD_ALTERA_AVALON_SPI_STATUS(ESP32_SPI_BASE) && 0b01000000 )
  {
    IOWR_ALTERA_AVALON_SPI_TXDATA(ESP32_SPI_BASE, (int) x);
    // printf("txreg: %d\n", IORD_ALTERA_AVALON_SPI_TXDATA(ESP32_SPI_BASE));
    // printf("data: %ld\n", (x & 0b111111111));
  }

}

int main()
{
  alt_32 x_read, y_read;
  alt_up_accelerometer_spi_dev *accDev;
  accDev = alt_up_accelerometer_spi_open_dev(ACCELEROMETER_NAME);

  if ( accDev == NULL )
  {
    return 1;
  } 

  while ( 1 )
  {
    alt_up_accelerometer_spi_read_x_axis(accDev, &x_read);
    alt_up_accelerometer_spi_read_y_axis(accDev, &y_read);
    // sendReading(x_ssread);
    printf("x: %ld, y: %ld\n", x_read, y_read);
    // printf("x: %d, y: %d\n", (int)(x_read & 0b111111111), (int)(y_read & 0b111111111));
    sendReading(((x_read & 0b1111111111) + ((y_read & 0b1111111111) << 9)));
    usleep(10);
  }
  printf("Hello from Nios II!\n");

  return 0;
}
