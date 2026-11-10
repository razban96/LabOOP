#include "BusStation.h"

const std::vector<Commuter*>& BusStation::getWaitingCommuters() const
{
    return m_waitingCommuters;
}

Bus* BusStation::getDockedBus() const
{
    return m_dockedBus;
}

void BusStation::addPassenger(Commuter* commuter)
{
    if (commuter != nullptr)
    {
        m_waitingCommuters.push_back(commuter);
    }
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

    while (!m_waitingCommuters.empty())
    {
        Commuter* commuter = m_waitingCommuters.back();

        // Try boarding the commuter onto the docked bus
        if (m_dockedBus->boardCommuter(commuter))
        {
            m_waitingCommuters.pop_back(); // remove from platform
        }
        else
        {
            std::cout << "Bus is full. Remaining passengers wait at station.\n";
            break; // Stop
        }
    }
}

void BusStation::printWaitingCommuters() const
{
    std::cout << "Waiting commuters: " << m_waitingCommuters.size() << std::endl;
    for (size_t index = 0; index < m_waitingCommuters.size(); ++index)
    {
        const Commuter* commuter = m_waitingCommuters[index];
        if (commuter == nullptr)
        {
            std::cout << index + 1 << ". None" << std::endl;
            continue;
        }

        std::cout << index + 1 << ". " << commuter->getName() << std::endl;
    }
}

void BusStation::printBusStationInfo() const
{
    std::cout << "Bus station: " << m_name << std::endl
              << "Occupied: " << (isOccupied() ? "Yes" : "No") << std::endl;

    printWaitingCommuters();

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