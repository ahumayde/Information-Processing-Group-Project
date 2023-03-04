/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */

#include <stdio.h>
#include <altera_up_avalon_accelerometer_spi.h>
#include "system.h"
#include <unistd.h>

int main()
{
  alt_32 xRead, zRead, yRead;
  alt_up_accelerometer_spi_dev *accDev;
  accDev = alt_up_accelerometer_spi_open_dev(ACCELEROMETER_NAME);

  if ( accDev == NULL )
  {
    return 1;
  }

  while ( 1 )
  {
    alt_up_accelerometer_spi_read_x_axis(accDev, &xRead);
    usleep(10);
    alt_up_accelerometer_spi_read_y_axis(accDev, &yRead);
    usleep(10);
    alt_up_accelerometer_spi_read_z_axis(accDev, &zRead);
    usleep(10);
    printf("sent: %ld, %ld, %ld\n", xRead, yRead, zRead);
  }


  return 0;
}

