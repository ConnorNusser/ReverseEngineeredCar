#include ReverseCarMain.cpp

// Pin Set up on Arduino
#define AIN1 12
#define AIN2 8
#define PWMA 13

#define B1N1 22
#define B1N2 24
#define PWMB 28

#define STBY 10

#define triggerPin 11
#define echoPin 12

Motor motorBack = Motor(AIN1, AIN2, PWMA, STBY);
Motor motorFront = Motor(B1N1, B1N2, PWMB, STBY);

SonicSensor frontSensor = SonicSensor(triggerPin,echoPin);
void setup()
{
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);
}


void loop()
{
    motorBack.executeSensor();
}