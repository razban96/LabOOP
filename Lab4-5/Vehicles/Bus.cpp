#include "Bus.h"
#include "../Places/BusStation.h"
#include <algorithm>
#include <iostream>
#include <random>

unsigned int Bus::getMaxCapacity() const { return m_maxCapacity; }

std::string Bus::getBusLine() const { return m_busLine; }

unsigned int Bus::getCommuterCount() const
{
    return static_cast<unsigned int>(m_passengers.size());
}

size_t Bus::getPassengerCount() const
{
    return m_passengers.size();
}

void Bus::setMaxCapacity(unsigned int maxCapacity) { m_maxCapacity = maxCapacity; }

bool Bus::boardPassenger(Person* person)
{
    if (person == nullptr)
        return false;
    if (m_passengers.size() >= m_maxCapacity)
    {
        std::cout << "Bus line " << m_busLine << " is full." << std::endl;
        return false;
    }
    m_passengers.push_back(person);
    return true;
}

bool Bus::boardCommuter(Person* person)
{
    return boardPassenger(person);
}

bool Bus::removePassenger(const Person* person)
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

bool Bus::hasPassenger(const Person* person) const
{
    for (const auto* p : m_passengers)
    {
        if (p == person)
            return true;
    }
    return false;
}

const std::vector<Person*>& Bus::getPassengers() const
{
    return m_passengers;
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

void Bus::addStationToRoute(BusStation* station)
{
    if (station == nullptr)
        return;

    for (const auto* s : m_routeStations)
    {
        if (s == station)
            return; // already present
    }

    m_routeStations.push_back(station);
    station->addServicingBus(this); // synchronize between instances of bus and bus station
}

void Bus::removeStationFromRoute(BusStation* station)
{
    if (station == nullptr)
        return;

    auto it = std::find(m_routeStations.begin(), m_routeStations.end(), station);
    if (it != m_routeStations.end())
    {
        m_routeStations.erase(it);
        station->removeServicingBus(this); // synchronize between instances of bus and bus station
    }
}

const std::vector<BusStation*>& Bus::getRouteStations() const
{
    return m_routeStations;
}

bool Bus::stopsAt(const BusStation* station) const
{
    for (const auto* s : m_routeStations)
    {
        if (s == station)
            return true;
    }
    return false;
}

void Bus::printRoute() const
{
    std::cout << "Route for Bus Line " << m_busLine << " (" << m_routeStations.size() << " stops):\n";
    for (size_t i = 0; i < m_routeStations.size(); ++i)
    {
        if (m_routeStations[i] != nullptr)
        {
            std::cout << "  " << (i + 1) << ". " << m_routeStations[i]->getName() << "\n";
        }
    }
}

void Bus::printVehicleInfo() const
{
    Vehicle::printVehicleInfo();
    std::cout << "Bus line: " << m_busLine << std::endl
              << "Max capacity: " << m_maxCapacity << std::endl
              << "No. of passengers: " << m_passengers.size() << std::endl
              << "No. of route stops: " << m_routeStations.size() << std::endl
              << "No. of mosquitoes: " << m_mosquitoes.size() << std::endl;
}

void Bus::addMosquito(Mosquito* mosquito)
{
    if (mosquito != nullptr)
        m_mosquitoes.push_back(mosquito);
}

bool Bus::removeMosquito(Mosquito* mosquito)
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

bool Bus::hasMosquito(const Mosquito* mosquito) const
{
    for (const auto* m : m_mosquitoes)
    {
        if (m == mosquito)
            return true;
    }
    return false;
}

const std::vector<Mosquito*>& Bus::getMosquitoes() const
{
    return m_mosquitoes;
}

size_t Bus::getMosquitoCount() const
{
    return m_mosquitoes.size();
}

void Bus::mosquitoAttack(const Mosquito& mosquito)
{
    std::vector<Person*> targets;

    if (m_driver != nullptr && m_driver->getIsAlive())
    {
        targets.push_back(m_driver);
    }
    for (const auto& passenger : m_passengers)
    {
        if (passenger != nullptr && passenger->getIsAlive())
        {
            targets.push_back(passenger);
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