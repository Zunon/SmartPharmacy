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

RFID rfid(SS_PIN, RST_PIN);

unsigned char allowedUsers[][5] = {
  {229, 137, 26, 188, 202},
  {224, 195, 29, 24, 38},
  {147, 244, 128, 203, 44}
};

void outputSerNum(unsigned char serNum[5]) {
  Serial.print(serNum[0]);
  Serial.print(" ");
  Serial.print(serNum[1]);
  Serial.print(" ");
  Serial.print(serNum[2]);
  Serial.print(" ");
  Serial.print(serNum[3]);
  Serial.print(" ");
  Serial.print(serNum[4]);
  Serial.println("");
}

bool authenticate(unsigned char serNum[5]) {
  bool allowed = true;
  for (int i = 0; i < 2; i++) {
    allowed = true;
      for (int j = 0; j < 5; j++) {
        if (rfid.serNum[j] != allowedUsers[i][j]) {
          allowed = false;
        }
      }
      if (allowed) return true;
    }
  return false;
}

void setup(){

  Serial.begin(9600);
  SPI.begin();
  rfid.init();

}

  void loop(){

  if (rfid.isCard() && rfid.readCardSerial()){
    outputSerNum(rfid.serNum);
  }
  rfid.halt();

}

