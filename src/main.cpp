#include <Arduino.h>
#include <RoboticArm/RoboticArm.h>
RoboticArm arm;
void setup() {
  arm.setup(2,3,4,5);
}
void loop() {
  arm.moveBase(180);
  delay(200);
  arm.moveBase(0);
  delay(200);
  arm.moveExtension(10);
  delay(200);
  arm.moveExtension(180);
  delay(200);
  arm.moveExtension(40);
  delay(200);
}
