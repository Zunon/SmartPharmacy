/*
* Read a card using a mfrc522 reader on your SPI interface
* Pin layout should be as follows (on Arduino Uno - Velleman VMA405):
* MOSI: ICSP-4
* MISO: ICSP-1
* SCK: ISCP-3
* NSS: Pin 10
* RST: Pin 9
* VCC: 3.3V (DO NOT USE 5V, VMA405 WILL BE DAMAGED IF YOU DO SO)
* GND: GND
* IRQ: not used
*/

#include <SPI.h>
#include <RFID.h>
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 9
#define BLUE_PIN 7
#define RED_PIN 6
#define YELLOW_PIN 5
#define GREEN_PIN 4

RFID rfid(SS_PIN,RST_PIN);

void setup(){

  Serial.begin(9600);
  SPI.begin();
  rfid.init();

}

  void loop(){

  if(rfid.isCard() && rfid.readCardSerial()){
    Serial.print(rfid.serNum[0]);
    Serial.print(" ");
    Serial.print(rfid.serNum[1]);
    Serial.print(" ");
    Serial.print(rfid.serNum[2]);
    Serial.print(" ");
    Serial.print(rfid.serNum[3]);
    Serial.print(" ");
    Serial.print(rfid.serNum[4]);
    Serial.println("");
  }
  rfid.halt();

}

