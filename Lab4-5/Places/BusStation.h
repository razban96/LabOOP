/*
* Naming Conventions:
 * - Classes / Structs  : PascalCase (Person, BusStation)
 * - Methods / Functions: camelCase  (getAge, setAddress)
 * - Member Data        : m_variableName (m_age, m_address)
 * - Static Data        : s_variableName (s_instanceCount)
 * - Global Data        : g_variableName (g_debugMode)
 * - Pointers           : p_variableName / ptr_variableName
 * - Constants          : c_variableName / kVariableName
 */
#pragma once
#include "../Vehicles/Bus.h"
#include "../Humans/Commuter.h"
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
