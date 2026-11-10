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
#include "Subcomponents/Address.h"
#include <iostream>
#include <string>

class Person
{
  public:
    // constructor, destructor
    explicit Person(unsigned int age /*=69*/, const std::string& name /*=Iancu Robila*/,
               bool isAllergicToMosquitoes /*=true*/, const Address& address, bool isAlive /*true*/)
    : m_age(age), m_name(name), m_address(address),
      m_isAllergicToMosquitoes(isAllergicToMosquitoes), m_isAlive(isAlive)
    {
    }
    virtual ~Person() = default;

    // setters & getters
    void setAge(unsigned int age);

    void setName(const std::string& name);

    void setIsAllergicToMosquitoes(bool isAllergicToMosquitoes);

    void setAddress(const Address& address);

    [[nodiscard]] unsigned int getAge() const;

    [[nodiscard]] const std::string& getName() const;

    [[nodiscard]] const Address& getAddress() const;

    [[nodiscard]] bool getIsAllergicToMosquitoes() const;

    [[nodiscard]] bool getIsAlive() const;

    // Other
    virtual void printStandardInfo() const;

    void receiveBite();


  private:
    unsigned int m_age;
    std::string m_name;
    Address m_address;
    bool m_isAllergicToMosquitoes;
    bool m_isAlive;
};