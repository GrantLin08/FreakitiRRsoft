#include<MotorDriver.h>
#include <Arduino.h>

MotorDriver::MotorDriver(int LmotorP, int LmotorN, int RmotorP, int RmotorN) {
    LmotorP = LmotorP;
    LmotorN = LmotorN;
    RmotorP = RmotorP;
    RmotorN = RmotorN;
    cancel = false;
    pinMode(LmotorP, OUTPUT);
    pinMode(LmotorN, OUTPUT);
    pinMode(RmotorP, OUTPUT);
    pinMode(RmotorN, OUTPUT);
}

void MotorDriver::moveForward(int pow, bool highPriority) {
    analogWrite(LmotorP, pow);
    analogWrite(LmotorN, 0);
    analogWrite(RmotorP, pow);
    analogWrite(RmotorN, 0);
}

void MotorDriver::moveBackward(int pow, bool highPriority) {
    analogWrite(LmotorP, 0);
    analogWrite(LmotorN, pow);
    analogWrite(RmotorP, 0);
    analogWrite(RmotorN, pow);
}

void MotorDriver::rotate(int l, int r, bool highPriority) {
    analogWrite(LmotorP, l > 0 ? l : 0);
    analogWrite(LmotorN, l < 0 ? l : 0);
    analogWrite(RmotorP, r > 0 ? r : 0);
    analogWrite(RmotorN, r < 0 ? -r : 0);
}

void MotorDriver::stop() {
    analogWrite(LmotorP, 0);
    analogWrite(LmotorN, 0);
    analogWrite(RmotorP, 0);
    analogWrite(RmotorN, 0);
}

