#include "BooleanSensor.h"
#include <Arduino.h>
BooleanSensor::BooleanSensor(int p) {
    pin = p;
    triggered = false;
    for (int i = 0; i < 6; i++) {
        BooleanSensor *b = &BScollection[i]; 
        if (b == nullptr) {
            BScollection[i] = *this;
            break;
        }


    }


}

void BooleanSensor::updateAll() {
    for (int i = 0; i < sizeof(BScollection) / sizeof(BScollection[0]); i++) {
        BooleanSensor b = BScollection[i];
        b.setTriggered(digitalRead(b.getPin()) == HIGH);
    }
}

bool BooleanSensor::readSensor() {
    return   triggered;
}

