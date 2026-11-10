#include "Commuter.h"

void Commuter::buyTicket()
{
    if (!hasSubscription() && !hasTicket())
    {
        m_hasTicket = true;
    }
    else
        std::cout << "Already have a ticket/subscription\n";
}

void Commuter::buySubscription()
{
    if (!hasSubscription() && !hasTicket())
    {
        m_hasSubscription = true;
    }
    else
        std::cout << "Already have a ticket/subscription\n";
}

void Commuter::setDestination(const std::string& destination) { m_destination = destination; }

bool Commuter::hasTicket() const { return m_hasTicket; }

bool Commuter::hasSubscription() const { return m_hasSubscription; }

const std::string& Commuter::getDestination() const { return m_destination; }

void Commuter::printStandardInfo() const
{
    Person::printStandardInfo();
    if (hasSubscription())
    {
        std::cout << "Has subscription" << std::endl;
    }
    if (hasTicket())
    {
        std::cout << "Has ticket" << std::endl;
    }
    std::cout << "Destination: " << getDestination() << std::endl;
}
