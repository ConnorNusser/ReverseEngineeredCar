#include "ReverseCarMain.h"
#include "SonicSensor.h"
#define triggerPin 11
#define echoPin 12
#include <Arduino.h>

Motor::Motor(int In1pin, int In2pin, int PWMpin, int STBYpin)
{
  In1 = In1pin;
  In2 = In2pin;
  PWM = PWMpin;
  Standby = STBYpin;
  frontSensor.create(triggerPin, echoPin);
  backSensor.create(triggerPin, echoPin);
  
  //forward rotation motor
  pinMode(In1, OUTPUT);
  //reverse rotation motor
  pinMode(In2, OUTPUT);
  pinMode(PWM, OUTPUT);
  pinMode(Standby, OUTPUT);
  
}
float Motor::executeBackSensor(){
    return backSensor.readDataStream100();
}
float Motor::executeFrontSensor(){
  return frontSensor.readDataStream100();
}
void Motor::drive(int speed)
{
  digitalWrite(Standby, HIGH);
  if (speed>=0) fwd(speed);
  else rev(speed);
}
void Motor::drive(int speed, int duration)
{
  drive(speed);
  delay(duration);
}

void Motor::fwd(int speed)
{
   digitalWrite(In1, HIGH);
   digitalWrite(In2, LOW);
   analogWrite(PWM, speed);

}

void Motor::rev(int speed)
{
   int speed1 = speed * -1;
   digitalWrite(In1, LOW);
   digitalWrite(In2, HIGH);
   Serial.println(speed);
   analogWrite(PWM, speed1);
}
void Motor::back()
{
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  analogWrite(PWM, -DEFAULTSPEED);
}
void Motor::brake()
{
   digitalWrite(In1, HIGH);
   digitalWrite(In2, HIGH);
   analogWrite(PWM,0);
}

void Motor::standby()
{
   digitalWrite(Standby, LOW);
}

void forward(Motor motor1, int speed)
{
	motor1.drive(speed);
}
void forward(Motor motor1)
{
	motor1.drive(DEFAULTSPEED);
}


void back(Motor motor1, int speed)
{
	motor1.drive(-speed);
}
void back(Motor motor1)
{
	motor1.drive(-DEFAULTSPEED);
}
void left(Motor left,int speed)
{
	int temp = abs(speed)/2;
	left.drive(-temp);
	
}

void right(Motor left, int speed)
{
	int temp = abs(speed)/2;
	left.drive(temp);
	
}
void motor(Motor left, Motor right)
{
   //pass
}

void brake(Motor motor1)
{
	motor1.brake();
}
void spinCircles(Motor left, Motor right, int speed) {
  int duration = 500; // milliseconds
  int num_spins = 3; // number of circles to spin
  for (int i = 0; i < num_spins * 2; i++) {
    if (i % 2 == 0) {
      left.drive(-speed);
      right.drive(speed);
    } else {
      left.drive(speed);
      right.drive(-speed);
    }
    delay(duration);
  }
  left.brake();
  right.brake();
}

void progressiveDrive(Motor Motor1, int speed, int duration, int delta) {
  int currentSpeed = 0;
  int increment = delta;

  if (speed < 0) {
    increment = -increment;
  }

  // Gradually increase/decrease the speed until we reach the desired value
  while (abs(currentSpeed - speed) > abs(increment)) {
    currentSpeed += increment;
    Motor1.drive(currentSpeed);
    delay(duration);
  }

  // Set the final speed
  Motor1.drive(speed);
}

void rotate180(Motor m1, Motor m2)
{
  int SLOWSPEED = 124;
  int TURNSPEED = 255 / 4;
  int ROTATION_DELAY_MS = 1000;
  // Set motors to go backwards at a slow speed
  back(m1, SLOWSPEED);
  back(m2, SLOWSPEED);

  // Wait for the car to come to a stop
  delay(ROTATION_DELAY_MS);

  // Turn the car to the right until it's facing the opposite direction

  right(m1, TURNSPEED);
  left(m2, -TURNSPEED);


  // Stop the motors
  m1.brake();
  m2.brake();
}

