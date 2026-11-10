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
#include <string>

class Mosquito
{
  public:
    explicit Mosquito(bool isDeadly = false, const std::string& species = "Culex")
        : m_isDeadly(isDeadly), m_species(species)
    {
    }
    ~Mosquito() = default;

    [[nodiscard]] bool isDeadly() const;
    [[nodiscard]] const std::string& getSpecies() const;
    void bite(Person& p) const;

  private:
    const bool m_isDeadly;
    std::string m_species;
};