#ifndef BOOLEANSENSOR_H
#define BOOLEANSENSOR_H

class BooleanSensor {
private:
    /*represensents sensor value*/
    static BooleanSensor BScollection[6];
    int pin;
    int value;
    bool triggered;
    //int ConcurrentReads;
    //const int Threshold;
    //const int Window;
public:
    
    int getPin() { return pin; }
    void setTriggered(bool t) { triggered = t; }
    BooleanSensor(int pin);
    static void updateAll();

    bool readSensor();

    
};

#endif