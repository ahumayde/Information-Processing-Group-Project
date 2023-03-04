#include <Arduino.h>
#include <SPI.h>
#include <ESP32SPISlave.h>
#include <bitset>
#include <type_traits>
#include <iostream>


ESP32SPISlave slave;

uint8_t spi_slave_tx_buf[32];
uint8_t spi_slave_rx_buf[32];

void setup()
{

  slave.setDataMode(SPI_MODE0);
  slave.begin(VSPI);
  Serial.begin(115200);
}


void loop()
{ 
  slave.wait(spi_slave_rx_buf, spi_slave_tx_buf, 32);

  short x = 0;
  int top_x = 0;
  short y = 0;
  int top_y = 0;
  int buttons = 0;

  /*
    SPI is MSB first, thus the data recieved is reversed:
    BUFF[31:0], spi_slave_rx_buf[location][bitnumber]
    Buttons: BUFF[25] + BUFF[24] :: spi_slave_rx_buf[0][1:0] 
    Y-axis acceleration = BUFF[17:9] :: spi_slave_rx_buf[1][1:0] + spi_slave_rx_buf[2][7:1]
    X-axis acceleration = BUFFP[8:0] :: spi_slave_rx_buf[2][0] + spi_slave_rx_buf[3]
  */
  
  while( slave.available() )
  {
    // bit manipulation fo x 
    x = (spi_slave_rx_buf[3]);
    top_x = (spi_slave_rx_buf[2] & 1);
    x = (top_x) ? (x | 0xff00) : x;

    // bit manipulation to get y
    y = spi_slave_rx_buf[2] >> 1;
    y = ((spi_slave_rx_buf[1] & 1) << 7) | y;
    top_y = (spi_slave_rx_buf[1] & 2);
    y = (top_y) ? (y | 0xff00) : y;

    // bit manipulation to get buttons
    buttons = spi_slave_rx_buf[0];

    // std::cout <<  " buff[0]: "<< (int)spi_slave_rx_buf[0] <<  " buff[1]: "<< (int)spi_slave_rx_buf[1] << " buff[2]: "<< (int)spi_slave_rx_buf[2] << std::endl;
    // std::cout << "y: "<< y << std::endl;
    slave.pop();
  }

}