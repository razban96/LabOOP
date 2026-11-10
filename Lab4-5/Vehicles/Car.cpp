#include "Car.h"
#include <iostream>

Car::Car()
    : Vehicle()
{
}

void Car::startEngine()
{
    if (getDriver() == nullptr)
    {
        std::cout << "No driver in the car, can't start." << std::endl;
        return;
    }
    m_engine.startEngine();
    setIsStationary(false);
    std::cout << "Engine started." << std::endl;
    std::cout << "Driver: " << getDriver()->getName() << " is your driver." << std::endl;
}

void Car::stopEngine()
{
    m_engine.stopEngine();
    setIsStationary(true);
}

void Car::printVehicleInfo() const
{
    Vehicle::printVehicleInfo();
    std::cout << "Vehicle type: Car" << std::endl;
}