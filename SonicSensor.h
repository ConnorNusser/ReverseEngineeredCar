#pragma once
#ifndef SonicSensor_h
#define SonicSensor_h




class SonicSensor
{
  public:
    SonicSensor(int triggerPin, int echoPin) :{Create(triggerPin, echoPin)};  
    void Create(int triggerPin, int echoPin);
    float readData();
	
  private:
	int Trigger, int Echo
};

#endif