#include "AutonomousCar.h"
#include "SonicSensor.h"
// Distances is in inches
#define OBSTACLE_DISTANCE_THRESHOLD 2
AutonomousCar::AutonomousCar(Motor& leftMotor, Motor& rightMotor, SonicSensor& frontSensor, SonicSensor& rearSensor)
    : leftMotor_(leftMotor), rightMotor_(rightMotor), frontSensor_(frontSensor), rearSensor_(rearSensor)
{
    // Initialize internal variables
    // MaxSpeed is 255
    currentSpeed_ = 0;
    currentDirection_ = 0;
    currentLatitude_ = 0;
    currentLongitude_ = 0
    isNavigating_ = false;
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
    leftMotor_.setSpeed(speed);
    rightMotor_.setSpeed(speed);
    currentSpeed_ = speed;
}

void AutonomousCar::brake()
{
    // Stop the left and right motors
    leftMotor_.stop();
    rightMotor_.stop();
    currentSpeed_ = 0.0f;
}

void AutonomousCar::turnLeft()
{
    // Turn the car left by setting the speed of the right motor to zero
    leftMotor_.setSpeed(currentSpeed_);
    rightMotor_.setSpeed(0.0f);
    currentDirection_ -= TURN_ANGLE;
}

void AutonomousCar::turnRight()
{
    // Turn the car right by setting the speed of the left motor to zero
    leftMotor_.setSpeed(0.0f);
    rightMotor_.setSpeed(currentSpeed_);
    currentDirection_ += TURN_ANGLE;
}

void AutonomousCar::park()
{
    // Implement parking algorithm here
}

void AutonomousCar::sendTelemetry()
{
    // Send telemetry data to a remote server
}

void AutonomousCar::receiveCommands()
{
    // Receive commands from a remote server and execute them
}