#include "Car.h"
#include <iostream>

Car::Car(unsigned int maxCapacity, Driver* driver)
    : Vehicle(Engine(), driver), m_maxCapacity(maxCapacity)
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
    std::cout << "Vehicle type: Car" << std::endl
              << "Max capacity: " << m_maxCapacity << std::endl
              << "Passengers: " << m_passengers.size() << std::endl
              << "Mosquitoes: " << m_mosquitoes.size() << std::endl;
}

void Car::setMaxCapacity(unsigned int maxCapacity) { m_maxCapacity = maxCapacity; }
unsigned int Car::getMaxCapacity() const { return m_maxCapacity; }
size_t Car::getPassengerCount() const { return m_passengers.size(); }

bool Car::boardPassenger(Person* person)
{
    if (person == nullptr)
        return false;
    if (m_passengers.size() >= m_maxCapacity)
    {
        std::cout << "Car is full.\n";
        return false;
    }
    m_passengers.push_back(person);
    return true;
}

bool Car::removePassenger(Person* person)
{
    for (auto it = m_passengers.begin(); it != m_passengers.end(); ++it)
    {
        if (*it == person)
        {
            m_passengers.erase(it);
            return true;
        }
    }
    return false;
}

bool Car::hasPassenger(const Person* person) const
{
    for (const auto* p : m_passengers)
    {
        if (p == person)
            return true;
    }
    return false;
}

const std::vector<Person*>& Car::getPassengers() const { return m_passengers; }

void Car::addMosquito(Mosquito* mosquito)
{
    if (mosquito != nullptr)
        m_mosquitoes.push_back(mosquito);
}

bool Car::removeMosquito(Mosquito* mosquito)
{
    for (auto it = m_mosquitoes.begin(); it != m_mosquitoes.end(); ++it)
    {
        if (*it == mosquito)
        {
            m_mosquitoes.erase(it);
            return true;
        }
    }
    return false;
}

bool Car::hasMosquito(const Mosquito* mosquito) const
{
    for (const auto* m : m_mosquitoes)
    {
        if (m == mosquito)
            return true;
    }
    return false;
}

const std::vector<Mosquito*>& Car::getMosquitoes() const { return m_mosquitoes; }
size_t Car::getMosquitoCount() const { return m_mosquitoes.size(); }