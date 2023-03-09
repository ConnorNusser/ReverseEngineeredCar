#pragma once
#ifndef SonicSensor_h
#define SonicSensor_h

class SonicSensor
{
  private:
	  int Trigger, Echo, Distance;
  public:
    SonicSensor();
    SonicSensor(int triggerPin, int echoPin);
    void create(int triggerPin, int echoPin);
    float readData();
    float readDataStream100();
	

};

#endif