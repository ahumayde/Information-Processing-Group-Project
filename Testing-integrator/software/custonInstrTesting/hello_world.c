#include <stdio.h>
#include "altera_up_avalon_accelerometer_spi.h"
#include "system.h"
#include "altera_avalon_timer.h"
#include "sys/alt_irq.h"
#include <stdlib.h>

int main()
{
  // printf("Hello from Nios II!\n");
  alt_32 x = 0;
  alt_up_accelerometer_spi_dev *acc_dev = NULL;
  acc_dev = alt_up_accelerometer_spi_open_dev("/dev/accelerometer");

  if ( acc_dev == NULL ) 
  {
    printf("fuck");
    return 1;
  }

  int sum = 0;

  while ( 1 )
  {
    alt_up_accelerometer_spi_read_x_axis(acc_dev, &x);
    sum = ALT_CI_INTEGRATOR_2_0(x, sum);
    printf("data: %d\n", sum);

  }
  //
  return 0;
}
