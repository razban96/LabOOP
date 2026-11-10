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
class Driver : public Person
{
  public:
    explicit Driver(const unsigned int age = 30, const std::string& name = "Unknown",
                    const bool isAllergicToMosquitoes = false, const bool isAlive = true,
                    const Address& address = Address(), const unsigned int yearsOfExperience = 3,
                    const bool hasLicenseValid = true)
        : Person(age, name, isAllergicToMosquitoes, address, isAlive),
          m_yearsOfExperience(yearsOfExperience), m_hasLicenseValid(hasLicenseValid)
    {
    }
    ~Driver() override = default;

    [[nodiscard]] unsigned int getYearsOfExperience() const;

    [[nodiscard]] bool hasLicenseValid() const;

    void printStandardInfo() const override;
  private:
    unsigned m_yearsOfExperience;
    bool m_hasLicenseValid;
};
