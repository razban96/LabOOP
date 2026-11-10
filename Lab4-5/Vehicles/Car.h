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
#include "Vehicle.h"
#include <vector>

class Person;
class Mosquito;

class Car : public Vehicle
{
  public:
    explicit Car(unsigned int maxCapacity = 4, Driver* driver = nullptr);
    ~Car() override = default;

    void startEngine() override;
    void stopEngine() override;
    void printVehicleInfo() const override;

    // Capacity & Passengers (Person*)
    void setMaxCapacity(unsigned int maxCapacity);
    [[nodiscard]] unsigned int getMaxCapacity() const;
    [[nodiscard]] size_t getPassengerCount() const;
    bool boardPassenger(Person* person);
    bool removePassenger(Person* person);
    [[nodiscard]] bool hasPassenger(const Person* person) const;
    [[nodiscard]] const std::vector<Person*>& getPassengers() const;

    // Mosquitoes
    void addMosquito(Mosquito* mosquito);
    bool removeMosquito(Mosquito* mosquito);
    [[nodiscard]] bool hasMosquito(const Mosquito* mosquito) const;
    [[nodiscard]] const std::vector<Mosquito*>& getMosquitoes() const;
    [[nodiscard]] size_t getMosquitoCount() const;

  private:
    unsigned int m_maxCapacity{4};
    std::vector<Person*> m_passengers;
    std::vector<Mosquito*> m_mosquitoes;
};
