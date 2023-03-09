#pragma once
#include "ReverseCarMain.h"

// Pin Set up on Arduino
#define AIN1 40
#define AIN2 36
#define PWMA 38

#define B1N1 32
#define B1N2 30
#define PWMB 28

#define STBY 34

#define triggerPin 11
#define echoPin 12
Motor motorBack = Motor(AIN1, AIN2, PWMA, STBY);

void setup() {
  pinMode(triggerPin, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);      // Sets the echoPin as an Input
}


void loop() {
  motorBack.drive(255);
}