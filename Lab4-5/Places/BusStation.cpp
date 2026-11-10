#include "BusStation.h"
#include "../Vehicles/Bus.h"
#include <algorithm>
#include <iostream>

const std::vector<Person*>& BusStation::getWaitingPassengers() const
{
    return m_waitingPassengers;
}

Bus* BusStation::getDockedBus() const
{
    return m_dockedBus;
}

void BusStation::addPassenger(Person* person)
{
    if (person != nullptr)
    {
        m_waitingPassengers.push_back(person);
    }
}

bool BusStation::removePassenger(Person* person)
{
    for (auto it = m_waitingPassengers.begin(); it != m_waitingPassengers.end(); ++it)
    {
        if (*it == person)
        {
            m_waitingPassengers.erase(it);
            return true;
        }
    }
    return false;
}

bool BusStation::hasPassenger(const Person* person) const
{
    for (const auto* p : m_waitingPassengers)
    {
        if (p == person)
            return true;
    }
    return false;
}

void BusStation::busArrives(Bus* bus)
{
    m_dockedBus = bus;
}

void BusStation::busDeparts()
{
    m_dockedBus = nullptr;
}

void BusStation::boardPassengers()
{
    if (m_dockedBus == nullptr)
    {
        std::cout << "No bus docked at " << m_name << std::endl;
        return;
    }

    while (!m_waitingPassengers.empty())
    {
        Person* passenger = m_waitingPassengers.back();

        // Try boarding the passenger onto the docked bus
        if (m_dockedBus->boardPassenger(passenger))
        {
            m_waitingPassengers.pop_back(); // remove from platform
        }
        else
        {
            std::cout << "Bus is full. Remaining passengers wait at station.\n";
            break; // Stop
        }
    }
}

void BusStation::addServicingBus(Bus* bus)
{
    if (bus == nullptr)
        return;

    for (const auto* b : m_servicingBuses)
    {
        if (b == bus)
            return; // already present
    }

    m_servicingBuses.push_back(bus);
    bus->addStationToRoute(this); // synchronize two-way
}

void BusStation::removeServicingBus(Bus* bus)
{
    if (bus == nullptr)
        return;

    auto it = std::find(m_servicingBuses.begin(), m_servicingBuses.end(), bus);
    if (it != m_servicingBuses.end())
    {
        m_servicingBuses.erase(it);
        bus->removeStationFromRoute(this); // synchronize two-way
    }
}

const std::vector<Bus*>& BusStation::getServicingBuses() const
{
    return m_servicingBuses;
}

bool BusStation::hasBus(const Bus* bus) const
{
    for (const auto* b : m_servicingBuses)
    {
        if (b == bus)
            return true;
    }
    return false;
}

void BusStation::printServicingBuses() const
{
    std::cout << "Buses servicing " << m_name << " (" << m_servicingBuses.size() << " lines):\n";
    for (size_t i = 0; i < m_servicingBuses.size(); ++i)
    {
        if (m_servicingBuses[i] != nullptr)
        {
            std::cout << "  " << (i + 1) << ". " << m_servicingBuses[i]->getBusLine() << "\n";
        }
    }
}

void BusStation::printWaitingCommuters() const
{
    std::cout << "Waiting passengers: " << m_waitingPassengers.size() << std::endl;
    for (size_t index = 0; index < m_waitingPassengers.size(); ++index)
    {
        const Person* passenger = m_waitingPassengers[index];
        if (passenger == nullptr)
        {
            std::cout << index + 1 << ". None" << std::endl;
            continue;
        }

        std::cout << index + 1 << ". " << passenger->getName() << std::endl;
    }
}

void BusStation::printBusStationInfo() const
{
    std::cout << "Bus station: " << m_name << std::endl
              << "Occupied: " << (isOccupied() ? "Yes" : "No") << std::endl;

    printWaitingCommuters();
    printServicingBuses();

    if (m_dockedBus != nullptr)
    {
        std::cout << "Docked bus:" << std::endl;
        m_dockedBus->printVehicleInfo();
    }
    else
    {
        std::cout << "Docked bus: None" << std::endl;
    }
}