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
#include "../Humans/Person.h"
#include <iostream>
#include <string>
#include <vector>

class Bus;

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
    [[nodiscard]] size_t getWaitingPassengerCount() const { return m_waitingPassengers.size(); }
    [[nodiscard]] const std::vector<Person*>& getWaitingPassengers() const;
    [[nodiscard]] Bus* getDockedBus() const;
    [[nodiscard]] bool isOccupied() const { return m_dockedBus != nullptr; }

    // management
    void addPassenger(Person* person);
    bool removePassenger(Person* person);
    [[nodiscard]] bool hasPassenger(const Person* person) const;
    void busArrives(Bus* bus);
    void busDeparts();
    void boardPassengers();
    void printWaitingCommuters() const;
    void printBusStationInfo() const;

    // Servicing buses (Tasks 3 & 4)
    void addServicingBus(Bus* bus);
    void removeServicingBus(Bus* bus);
    [[nodiscard]] const std::vector<Bus*>& getServicingBuses() const;
    [[nodiscard]] bool hasBus(const Bus* bus) const;
    void printServicingBuses() const;

  private:
    std::string m_name;
    std::vector<Person*> m_waitingPassengers;
    Bus* m_dockedBus{nullptr};
    std::vector<Bus*> m_servicingBuses;
};
