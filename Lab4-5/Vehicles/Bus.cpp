#include "Bus.h"
#include <iostream>
#include <random>

unsigned int Bus::getMaxCapacity() const { return m_maxCapacity; }

std::string Bus::getBusLine() const { return m_busLine; }

void Bus::setMaxCapacity(unsigned int maxCapacity) { m_maxCapacity = maxCapacity; }

bool Bus::boardCommuter(Commuter* commuter)
{
    if (commuter == nullptr)
        return false;
    if (m_commuters.size() >= m_maxCapacity)
    {
        std::cout << "Bus line " << m_busLine << " is full." << std::endl;
        return false;
    }
    m_commuters.push_back(commuter);
    return true;
}

void Bus::startEngine()
{
    if (getDriver() == nullptr)
    {
        std::cout << "No driver in the bus, can't start." << std::endl;
        return;
    }

    m_engine.startEngine();
    setIsStationary(false);
}

void Bus::stopEngine()
{
    m_engine.stopEngine();
    setIsStationary(true);
}

void Bus::startBus() { startEngine(); }
void Bus::stopBus() { stopEngine(); }

void Bus::printVehicleInfo() const
{
    Vehicle::printVehicleInfo();
    std::cout << "Bus line: " << m_busLine << std::endl
              << "Max capacity: " << m_maxCapacity << std::endl
              << "No. of commuters: " << m_commuters.size() << std::endl;
}

void Bus::mosquitoAttack(const Mosquito& mosquito)
{
    std::vector<Person*> targets;

    if (m_driver != nullptr && m_driver->getIsAlive())
    {
        targets.push_back(m_driver);
    }
    for (const auto& commuter : m_commuters)
    {
        if (commuter != nullptr && commuter->getIsAlive())
        {
            targets.push_back(commuter);
        }
    }

    if (!targets.empty())
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<size_t> dist(0, targets.size() - 1);

        size_t randomIndex = dist(gen);
        Person* target = targets[randomIndex];

        mosquito.bite(*target);

        if (target->getIsAlive())
        {
            std::cout << "The mosquito bit " << target->getName() << ", but they survived!\n";
        }
        else
        {
            if (target == m_driver)
            {
                std::cout << "CRASH! Driver " << target->getName() << " was killed by a mosquito! Emergency stop!\n";
                stopBus();
            }
            else
            {
                std::cout << "Passenger " << target->getName() << " was killed by the mosquito.\n";
            }
        }
    }
}