/*
* Pin layout should be as follows (on Arduino Uno - Velleman VMA405):
* MOSI: ICSP-4 (middle-out)
* MISO: ICSP-1 (top-in)
* SCK: ISCP-3  (middle-in)
* NSS: Pin 10
* RST: Pin 9
* VCC: 3.3V (DO NOT USE 5V, VMA405 WILL BE DAMAGED IF YOU DO SO)
* GND: GND
* IRQ: not used
*/
// Import needed Libraries
#include <SPI.h>
#include <RFID.h>
#include <Servo.h>
// Define used pins
#define SS_PIN      10
#define RST_PIN      9
#define BLUE_PIN     7
#define RED_PIN      6
#define YELLOW_PIN   5
#define GREEN_PIN    4
// Costruct an RFID reader object
RFID rfid(SS_PIN, RST_PIN);
// Construct Servo objects
Servo
  blue,
  red,
  yellow,
  green;
// All the following arrays are parallel
// Array of allowed serial numbers
unsigned char allowedUsers[][5] = {
  {229, 137,  26, 188, 202},
  {224, 195,  29,  24,  38},
  {147, 244, 128, 203,  44}
};
// Array of allowed medicines for each serial number
// {blue, red, green, yellow}
bool medicines[][4] = {
  { true, false, false, false},
  { true, false,  true, false},
  {false,  true,  true,  true}
};
// Output the contents of a serial number
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
// Check whether or not given serial number is in the database
int authenticate(unsigned char serNum[5]) {
  bool allowed = true;
  for(int user = 0; user < sizeof(allowedUsers)/5; user++) {
    allowed = true;
    for(int serial = 0; serial < 5; serial++) {
      if(rfid.serNum[serial] != allowedUsers[user][serial]) allowed = false;
    }
    if(allowed) return user;
  }
  return -1;
}
// Initialize
void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.init();
  blue.attach(BLUE_PIN);
  red.attach(RED_PIN);
  yellow.attach(YELLOW_PIN);
  green.attach(GREEN_PIN);
}
// Main loop
void loop() {
  // If there's a card detected, and that card is allowed:
  if (rfid.isCard() && rfid.readCardSerial()){
    int user = authenticate(rfid.serNum);
    if (user != -1) {
      if (medicines[user][0]) {
        Serial.println("Dispensing Blue Panadol...");
        blue.write(180);
        delay(2000);
        blue.write(90);
      }
      if (medicines[user][1]) {
        Serial.println("Dispensing Red Panadol...");
        red.write(180);
        delay(2000);
        red.write(90);
      }
      if (medicines[user][2]) {
        Serial.println("Dispensing Green Panadol...");
        green.write(180);
        delay(2000);
        green.write(90);
      }
      if (medicines[user][3]) {
        Serial.println("Dispensing Yellow Panadol...");
        yellow.write(180);
        delay(2000);
        yellow.write(180);
      }
    } else {
      Serial.println("User is not in database!");
    }
  }
  rfid.halt();
}