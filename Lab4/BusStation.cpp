#include "BusStation.h"

void BusStation::addPassenger(Commuter* commuter) {
    m_waitingCommuters.push_back(commuter);
}

void BusStation::busArrives(Bus* bus) {
    m_dockedBus = bus;
}

void BusStation::busDeparts() {
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