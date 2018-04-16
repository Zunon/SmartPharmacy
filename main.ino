#include <Servo.h>
// Connect the 4 servos for the medicine
Servo
  blueSpring,
  redSpring,
  yellowSpring,
  greenSpring;

void setup() {
  blueSpring.attach();
  redSpring.attach();
  yellowSpring.attach();
  greenSpring.attach();
  // Setup an output that we may use for debugging
  Serial.begin(9600);

  Serial.println("Initialized!");
}

void loop() {

}

int identify() {
  return 0;
}
