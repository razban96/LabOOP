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
#include "Person.h"
class Mosquito
{
  public:
    explicit Mosquito(bool isDeadly = false) : m_isDeadly(isDeadly) {}
    ~Mosquito() = default;

    [[nodiscard]] bool isDeadly() const;
    void bite(Person& p) const;

  private:
    const bool m_isDeadly;
};