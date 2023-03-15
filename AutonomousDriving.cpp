#include "AutonomousCar.h"
#include "SonicSensor.h"
// Distances in feet
#define OBSTACLE_DISTANCE_THRESHOLD 10
#define ARRIVAL_DISTANCE 1.5
AutonomousCar::AutonomousCar(Motor& backMotor, Motor& frontMotor, SonicSensor& frontSensor, SonicSensor& rearSensor)
    : backMotor_(frontMotor), frontMotor_(backMotor), frontSensor_(frontSensor), rearSensor_(rearSensor)
{
    // Initialize internal variables
    // MaxSpeed is 255
    currentSpeed_ = 0;
    currentDirection_ = 0;
    currentLatitude_ = 0;
    currentLongitude_ = 0
    isNavigating_ = false;
    isDrivingForward = true;
}

AutonomousCar::~AutonomousCar()
{
    // Cleanup any resources here
}

void AutonomousCar::setDestination(float latitude, float longitude)
{
    // Set the destination coordinates for navigation
    currentLatitude_ = latitude;
    currentLongitude_ = longitude;
}

void AutonomousCar::followPath(std::vector<Point> path)
{
    // Implement path following algorithm here
}

void AutonomousCar::stopNavigation()
{
    // Stop the navigation algorithm and clear the destination
    currentLatitude_ = 0.0f;
    currentLongitude_ = 0.0f;
    isNavigating_ = false;
}

float AutonomousCar::getDistanceFromObstacle()
{
    // Read the front or rear sonic sensor and return the distance
    float distance = 0.0f;
    if (isObstacleDetected()) {
        distance = frontSensor_.getDistance();
    } else {
        distance = rearSensor_.getDistance();
    }
    return distance;
}

bool AutonomousCar::getArrivalDistance(){
    float distanceFront = frontSensor_.getDistance();
    float distanceBack = backSensor_.getDistance();
    if distanceFront < ARRIVAL_DISTANCE {
        return true;
    }
    return false;
}

bool AutonomousCar::isLaneDepartureDetected()
{
    // Implement lane departure detection algorithm here
    return false;
}

bool AutonomousCar::isObstacleDetected()
{
    // Check the front or rear sonic sensor for an obstacle
    bool isObstacle = false;
    if (frontSensor_.getDistance() < OBSTACLE_DISTANCE_THRESHOLD || rearSensor_.getDistance() < OBSTACLE_DISTANCE_THRESHOLD) {
        isObstacle = true;
    }
    return isObstacle;
}


void AutonomousCar::accelerate(float speed)
{
    // Set the speed of the left and right motors
    //backMotor_.setSpeed(speed);
    currentSpeed_ = speed;
}
void AutonomousCar::drive()
{
    //0 - 255
    int speed = 255 / 4
    backMotor_.drive(speed, 1000);
}

void AutonomousCar::brake()
{
    // Stop the left and right motors
    frontMotor_.brake();
    backMotor_.brake();
    currentSpeed_ = 0.0f;
}

void AutonomousCar::turnLeft()
{
    // Turn the car left by setting the speed of the right motor to zero
    backMotor_.drive(currentSpeed_);
    frontMotor_.left();
    currentDirection_ -= TURN_ANGLE;
}

void AutonomousCar::turnRight()
{
    // Turn the car right by setting the speed of the left motor to zero
    backMotor_.drive(currentSpeed_);
    frontMotor_.right();
    currentDirection_ += TURN_ANGLE;
}
void AutonomousCar::turnLeft(int amt)
{
    // Turn the car left by setting the speed of the right motor to zero
    backMotor_.drive(currentSpeed_);
    frontMotor_.left(amt);
    currentDirection_ -= TURN_ANGLE;
}

void AutonomousCar::turnRight(int amt)
{
    // Turn the car right by setting the speed of the left motor to zero
    backMotor_.drive(currentSpeed_);
    frontMotor_.right(amt);
    currentDirection_ += TURN_ANGLE;
}
void AutonomousCar::rotate(){
    //-255 to 255
    int speed = 255 / 4;
    frontMotor_.drive(speed, 250);
    backMotor_.drive(speed * - 1, 1000);
}
void AutonomousCar::autoDrive()
{
    //auto drive simulation 1
    while(true)
    {
     //we drive :D
     //we check distance if
     this->drive();
     bool isArrived = this->getArrivalDistance();
     if (isArrived){
        this->brake();
        this->rotate();
     }  
    }
}
