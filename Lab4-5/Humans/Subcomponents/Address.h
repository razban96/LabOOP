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
#include <string>
class Address
{
  public:
    // constructors & destructors
    explicit Address(const std::string& street = "Calea Smecherilor",
                     const std::string& city = "Craiova", unsigned int streetNumber = 69)
        : m_street(street), m_city(city), m_streetNumber(streetNumber)
    {
    }
    ~Address() = default;

    // setters & getters
    void setStreet(const std::string& street);
    void setCity(const std::string& city);
    void setStreetNumber(unsigned int streetNumber);
    [[nodiscard]] const std::string& getStreet() const;
    [[nodiscard]] const std::string& getCity() const;
    [[nodiscard]] unsigned int getStreetNumber() const;

    bool operator==(const Address& other) const;
    bool operator!=(const Address& other) const;

  private:
    std::string m_street;
    std::string m_city;
    unsigned int m_streetNumber;
};
