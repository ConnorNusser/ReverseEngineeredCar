#define MAX_DISTANCE 400
#include <Arduino.h>
#include <stdlib.h>
#include "SonicSensor.h"
SonicSensor::SonicSensor(){
        this->Trigger = 0
        this->Echo = 0
        this->Distance = 0;
};      
SonicSensor::Create(int triggerPin, int echoPin){
  this->Trigger = triggerPin;
  this->Echo = echoPin;
  this->Distance = MAX_DISTANCE;
}

float SonicSensor::readData()
{
    digitalWrite(this->Trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(this->Trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(this->Trigger, LOW);

    float duration = pulseIn(this->Echo, HIGH);
    float distance = (duration*.0343)/2;
    float distanceFT = distance * 0.0328084;
    return distanceFT;
};  
	