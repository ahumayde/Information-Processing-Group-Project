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
  // Serial.print("pin 23: ")
  // Serial.print(digitalRead(23));
  // Serial.print("\t pin 19: ")
  // Serial.println(digitalRead(19));
  short x = 0;
  int top_x = 0;
  short y = 0;
  int top_y = 0;

  while( slave.available() )
  {
    x = (spi_slave_rx_buf[3]);
    top_x = (spi_slave_rx_buf[2] & 1);
    x = (top_x) ? (x | 0xff00) : x;

    y = spi_slave_rx_buf[2] >> 1;
    y = ((spi_slave_rx_buf[1] & 1) << 7) | y;
    top_y = (spi_slave_rx_buf[1] & 2);
    y = (top_y) ? (y | 0xff00) : y;

    // std::cout <<  " buff[0]: "<< (int)spi_slave_rx_buf[0] <<  " buff[1]: "<< (int)spi_slave_rx_buf[1] << " buff[2]: "<< (int)spi_slave_rx_buf[2] << std::endl;
    std::cout << "y: "<< y << std::endl;
    slave.pop();
  }

}