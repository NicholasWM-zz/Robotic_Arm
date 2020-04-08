#include "Arduino.h"
#include "RoboticArm.h"
#include "Servo.h"
RoboticArm::RoboticArm(){}
void RoboticArm::move(Servo servo, int angle){
  int valAngle = map(angle, 0, 180, 0, 1023);
  int currentAngle = map(servo.read(), 0, 180, 0, 1023);
  int val=0;

  if(currentAngle > valAngle){
    for (int i = currentAngle; i >= valAngle; i--)
    {
        val = map(i, 0, 1023, 0, 180);
        servo.write(val);                  
        delay(2);  
        Serial.println(val);
    }
  }
  else{
    for (int i = currentAngle; i <= valAngle; i++)
    {
      val = map(i, 0, 1023, 0, 180);     
      servo.write(val);                  
      delay(2);
      Serial.println(val);
    }
  }
}
void RoboticArm::setup(int base, int mid,int extension,int claw){
    _arm_base.attach(base);
    _arm_mid.attach(mid);
    _arm_extension.attach(extension);
    _arm_claw.attach(claw);
}
void RoboticArm::moveBase(int angle){
    move(_arm_base, angle);
}
void RoboticArm::moveClaw(int angle){
    move(_arm_claw, angle);
}
void RoboticArm::moveExtension(int angle){
    move(_arm_extension, angle);
}
void RoboticArm::moveMid(int angle){
    move(_arm_mid, angle);
}
