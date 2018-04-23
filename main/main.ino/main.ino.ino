
/*
* edited by Velleman / Patrick De Coninck
* Read a card using a mfrc522 reader on your SPI interface
* Pin layout should be as follows (on Arduino Uno - Velleman VMA100):
* MOSI: Pin 11 / ICSP-4
* MISO: Pin 12 / ICSP-1
* SCK: Pin 13 / ISCP-3
* SS/SDA (MSS on Velleman VMA405) : Pin 10
* RST: Pin 9
* VCC: 3,3V (DO NOT USE 5V, VMA405 WILL BE DAMAGED IF YOU DO SO)
* GND: GND on Arduino UNO / Velleman VMA100
* IRQ: not used
*/

#include <SPI.h>
#include <RFID.h>
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 9

RFID rfid(SS_PIN,RST_PIN);

void setup(){

    Serial.begin(9600);
    SPI.begin();
    rfid.init();
/*
* define VMA100 (UNO) pins 7 & 8 as outputs and put them LOW
*/
   
}

void loop(){
    
    if(rfid.isCard()){
    
        if(rfid.readCardSerial()){
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
    }
    rfid.halt();

}

