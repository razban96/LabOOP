#include "Car.h"

void Car::startEngine()
{
    if (getDriver() == nullptr)
    {
        std::cout << "No driver in the car, can't start." << std::endl;
        return;
    }
    else
    {
        m_engine.startEngine();
        setIsStationary(false);
        std::cout << "Engine started." << std::endl;
        std::cout << "Driver: " << getDriver()->getName() << " is your driver." << std::endl;
    }
}