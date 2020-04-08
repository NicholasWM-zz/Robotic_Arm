#ifndef RoboticArm_h
#define RoboticArm_h

#include "Arduino.h"
#include "Servo.h"
class RoboticArm
{
private:
public:
    Servo _arm_base;
    Servo _arm_mid;
    Servo _arm_extension;
    Servo _arm_claw;
    void move(Servo servo, int angle);
    RoboticArm();
    // void setup(int port);
    void setup(int base, int mid,int extension,int claw);
    void moveBase(int angle);
    void moveMid(int angle);
    void moveExtension(int angle);
    void moveClaw(int angle);
};

#endif
