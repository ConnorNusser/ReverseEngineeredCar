#pragma once
#include "ReverseCarMain.h"

// Pin Set up on Arduino
#define AN1 
#define AN2 28
#define PWMA 30

//changed pinout names from AINx to ANx and B1Nx to BNx to reflect pinout on new chip

#define BN1 36
#define BN2 38
#define PWMB 
//deleted port assignment for PWMB

#define STBY 34

#define triggerPin 11
#define echoPin 12
Motor motorBack = Motor(AN1, AN2, PWMA, STBY);
Motor motorFront = Motor(BN2, BN2, PWMB, STBY);

void setup() {
  pinMode(triggerPin, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);      // Sets the echoPin as an Input
}


void loop() {
  progressiveDrive(motorBack, 255, 100000, 1);
}