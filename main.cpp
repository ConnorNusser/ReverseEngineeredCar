#pragma once
#include "ReverseCarMain.h"
#include "AutonomousDriving.h"
#include "SonicSensor.h"

// Pin Set up on Arduino
#define AN1 24
#define AN2 28
#define PWMA 30

//changed pinout names from AINx to ANx and B1Nx to BNx to reflect pinout on new chip

#define BN1 36
#define BN2 38
#define PWMB 36
//deleted port assignment for PWMB

#define STBY 34

#define triggerPinFront 11
#define echoPinFront 12

#define triggerPinBack 14
#define echoPinBack 14

SonicSensor frontSensor = SonicSensor(triggerPinFront, echoPinFront);
SonicSensor rearSensor = SonicSensor(triggerPinBack, echoPinBack);
Motor motorBack = Motor(AN1, AN2, PWMA, STBY);
Motor motorFront = Motor(BN2, BN2, PWMB, STBY);
AutonomousCar simul = AutonomousCar(motorFront, motorBack, frontSensor, rearSensor);

void setup() {
  pinMode(triggerPinFront, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPinFront, INPUT);
  pinMode(triggerPinBack, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPinBack, INPUT);
  pinMode(AN1, OUTPUT);
  pinMode(AN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
}


void loop() {
  simul.autoDrive();
}