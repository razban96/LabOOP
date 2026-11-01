#pragma once
#include "Bus.h"
#include "Commuter.h"
#include <iostream>
#include <string>
#include <vector>

class BusStation
{
  public:
    // constructors & destructors
    explicit BusStation(const std::string& name = "Central Station")
        : m_name(name), m_dockedBus(nullptr)
    {
    }
    ~BusStation() = default;

    // getters
    [[nodiscard]] std::string getName() const { return m_name; }
    [[nodiscard]] size_t getWaitingPassengerCount() const { return m_waitingCommuters.size(); }
    [[nodiscard]] bool isOccupied() const { return m_dockedBus != nullptr; }

    // management
    void addPassenger(Commuter* commuter);
    void busArrives(Bus* bus);
    void busDeparts();
    void boardPassengers();

  private:
    std::string m_name;
    std::vector<Commuter*> m_waitingCommuters;
    Bus* m_dockedBus;
};
