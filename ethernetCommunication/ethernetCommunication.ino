#include <Ethernet.h> //Load Ethernet Library
#include <EthernetUdp.h> //Load the Udp Library
#include <SPI.h> //Load SPI Library

#include "Wire.h" //imports the wire library

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEE}; //Assign mac address
IPAddress ip(169, 254, 0, 1); //Assign the IP Adress
unsigned int localPort = 6789; // Assign a port to talk over
IPAddress remote(169,254,120,29);

char packetBuffer[UDP_TX_PACKET_MAX_SIZE]; //dimensian a char array to hold our data packet
EthernetUDP Udp; // Create a UDP Object

void setup() {
  Serial.begin(9600); //Initialize Serial Port
  Serial.println("Setting up...");

  Ethernet.begin( mac, ip); //Inialize the Ethernet
  Udp.begin(localPort); //Initialize Udp
  delay(1500); //delay

  Serial.println("Ready!");
}

void loop() {
    Serial.println(millis());

    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());

    Udp.write("hello");

    Udp.endPacket();
}
