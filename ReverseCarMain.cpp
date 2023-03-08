
#include "sketch_mar7a.h"
Motor::Motor(int In1pin, int In2pin, int PWMpin, int offset, int STBYpin)
{
  In1 = In1pin;
  In2 = In2pin;
  PWM = PWMpin;
  Standby = STBYpin;
  Offset = offset;
  
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(PWM, OUTPUT);
  pinMode(Standby, OUTPUT);
}

void Motor::drive(int speed)
{
  digitalWrite(Standby, HIGH);
  speed = speed * Offset;
  if (speed>=0) fwd(speed);
  else rev(-speed);
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
   digitalWrite(In1, LOW);
   digitalWrite(In2, HIGH);
   analogWrite(PWM, speed);
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
	int temp = abs(speed);
	motor1.drive(-temp);
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
void brake(Motor motor1)
{
	motor1.brake();
}


#define AIN1 12
#define AIN2 11
#define STBY 10
#define PWMA 13

#define B1N1 22
#define B1N2 24
#define STBY 10
#define PWMB 28

const int offsetA = 1;
const int offsetB = 1;
Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor2 = Motor(B1N1, B1N2, PWMB, offsetB, STBY);

void setup()
{
 //Nothing here
}


void loop()
{
   motor2.drive(255,1000);
   motor2.drive(-255,1000);
   motor2.brake();
   motor1.drive(255,1000);
   motor1.drive(-255,1000);
   motor1.brake();
   delay(1000);
   
   
   forward(motor2, 150);
   delay(1000);
   
   back(motor2, -150);
   delay(1000);
   
   brake(motor2);
   delay(1000);
   
   left(motor2, 100);
   delay(1000);
   right(motor2,100);
   delay(1000);
   forward(motor1, 150);
   brake(motor2);
   delay(1000);
   
   
}