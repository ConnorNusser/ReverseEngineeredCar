#pragma once
#ifndef ReverseCarMain_h
#define ReverseCarMain_h

#include <Arduino.h>
#include "SonicSensor.h"
#define DEFAULTSPEED 255  



class Motor
{
  public:
    Motor(int In1pin, int In2pin, int PWMpin, int STBYpin);      

    void drive(int speed);  
	
    void drive(int speed, int duration);  
    void brake(); 
	
    void standby();	
    void back();
    void right();
    void left();
    void right(int speed);
    void left(int speed);
    float executeBackSensor();
    float executeFrontSensor();
	
  private:
	int In1, In2, PWM,Standby;
  SonicSensor frontSensor, backSensor;

	
	void fwd(int speed);
	void rev(int speed);


};
void rotate180(Motor left, Motor right);
void forward(Motor motor1, int speed);
void forward(Motor motor1);

void back(Motor motor1, int speed);
void back(Motor motor1);
void left(Motor left, int speed);
void right(Motor left, int speed);
void progressiveDrive(Motor Motor1, int speed, int duration, int delta);
void brake(Motor motor1);



#endif