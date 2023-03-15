#define MAX_DISTANCE 400
#include <Arduino.h>
#include <stdlib.h>
#include "SonicSensor.h"
SonicSensor::SonicSensor(){
        this->Trigger = 0;
        this->Echo = 0;
        this->Distance = 0;
};
SonicSensor::SonicSensor(int triggerPin, int echoPin){
      this->Trigger = triggerPin;
      this->Echo = echoPin;
      this->Distance = MAX_DISTANCE;
};      
void SonicSensor::create(int triggerPin, int echoPin){
  this->Trigger = triggerPin;
  this->Echo = echoPin;
  this->Distance = MAX_DISTANCE;
};

float SonicSensor::readData()
{
    digitalWrite(this->Trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(this->Trigger, HIGH);
    delayMicroseconds(2);
    digitalWrite(this->Trigger, LOW);

    float duration = pulseIn(this->Echo, HIGH);
    float distance = (duration*.0343)/2;
    float distanceFT = distance * 0.0328084;
    return distanceFT;
};

float SonicSensor::getDistance(){
  float total = 0;
  int badReadings = 0;
  float localNumber;
  for (int i = 0; i < 100; i++) {
    localNumber = this->readData();
    if (localNumber < 73.00){
      total = total + localNumber;
    }else{
      badReadings = badReadings + 1;
    }
  }
  return total / (100 - badReadings);
};




