#include <Arduino.h>
#include <SPI.h>
#include <ESP32SPISlave.h>
#include <bitset>
#include <type_traits>
#include <iostream>
#include <WiFi.h>

// esp32 slave stuff
ESP32SPISlave slave;
uint8_t spi_slave_tx_buf[4];
uint8_t spi_slave_rx_buf[4];

// esp32 wifi stuff
WiFiClient client;
const char *host = "192.168.218.152";
const int port = 10000;
bool validConnection = 0;

// readings
short x = 0;
int top_x = 0;
short y = 0;
int top_y = 0;
int buttons = 0;


void setup()
{
  // starting wifi
  WiFi.begin("Bruh", "qurs1567");
  while ( WiFi.status() != WL_CONNECTED ) 
  {
    Serial.println("Establishing connection to WiFi..");
    delay(1000);
  }

  // starting slave
  slave.setDataMode(SPI_MODE0);
  slave.begin(VSPI);
  Serial.begin(115200);
  Serial.println("Connected to network");
  

  validConnection = client.connect(host, port);
}

void sendData(){
  while ( !validConnection ) {
    validConnection = client.connect(host, port);
    Serial.println("connection failed");
  }
  std::string tmp = "," + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(buttons);
  client.print(tmp.c_str());
  std::cout << "x: " << x << " y: " << y << " buttons: " << buttons << std::endl;
}


void loop()
{ 
  slave.wait(spi_slave_rx_buf, spi_slave_tx_buf, 32);
  // spi_slave_tx_buf[4] = 0x00;
  // spi_slave_tx_buf[3] = 4;
  // spi_slave_tx_buf[2] = 0x00;
  // spi_slave_tx_buf[1] = 0x00;
  // spi_slave_tx_buf[0] = 0x00;

  /*
    SPI is MSB first, thus the data recieved is reversed:
    BUFF[31:0], spi_slave_rx_buf[location][bitnumber]
    Buttons: BUFF[25] + BUFF[24] :: spi_slave_rx_buf[0][1:0] 
    Y-axis acceleration = BUFF[17:9] :: spi_slave_rx_buf[1][1:0] + spi_slave_rx_buf[2][7:1]
    X-axis acceleration = BUFFP[8:0] :: spi_slave_rx_buf[2][0] + spi_slave_rx_buf[3]
  */

  std::cout << (int)spi_slave_tx_buf[0] << (int)spi_slave_tx_buf[1] << (int)spi_slave_tx_buf[2] << (int)spi_slave_tx_buf[3] << std::endl;
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
    sendData();
    delay(1000);
    slave.pop();
    // delay(100);
  }

}