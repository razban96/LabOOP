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

class Car : public Vehicle
{
  public:
    explicit Car();
    ~Car() override = default;

    void startEngine() override;
    void stopEngine() override;
    void printVehicleInfo() const override;

  private:
    unsigned int m_maxCapacity{0};
    // Mosquito* mosquito_;
};
