#ifndef AUTONOMOUS_CAR_H
#define AUTONOMOUS_CAR_H

#include <vector>
#include "ReverseCarMain.h"
#include "SonicSensor.h"

class AutonomousCar {
public:
    AutonomousCar(Motor& frontMotor, Motor& backMotor, SonicSensor& frontSensor, SonicSensor& rearSensor);
    ~AutonomousCar();

    // Navigation functions
    void setDestination(float latitude, float longitude);
    void followPath(std::vector<Point> path);
    void stopNavigation();

    // Sensor functions
    float getDistanceFromObstacle();
    bool isLaneDepartureDetected();
    bool isObstacleDetected();

    // Control functions
    void accelerate(float speed);
    void brake();
    void turnLeft();
    void turnRight();
    void turnLeft(int amt);
    void turnRight(int amt);

    // Communication functions
    void sendTelemetry();
    void receiveCommands();

private:
    // Internal variables
    int currentSpeed_;
    int currentDirection_;
    float currentLatitude_;
    float currentLongitude_;
    bool isNavigating_;

    // Hardware components
    Motor& frontMotor_;
    Motor& backMotor_;
    SonicSensor& frontSensor_;
    SonicSensor& rearSensor_;
};

#endif // AUTONOMOUS_CAR_H