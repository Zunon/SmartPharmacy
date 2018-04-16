#include <Servo.h>
// Connect the 4 servos for the medicine
Servo
  blueSpring;
int val = 0;
void setup() {
  blueSpring.attach(9);
  pinMode(10, INPUT);
  // Setup an output that we may use for debugging
  Serial.begin(9600);

  Serial.println("Initialized!");
  
}

void loop() {
  val = digitalRead(10);
  Serial.println(val);
  if(val == HIGH) {
    blueSpring.write(0);
    delay(2000);
    blueSpring.write(90);
  }
}