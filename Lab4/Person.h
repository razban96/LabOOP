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
#include "Address.h"
#include <iostream>
#include <string>

class Person
{
  public:
    // constructor, destructor
    Person();
    Person(unsigned int age, const std::string& name, const Address& address);
    virtual ~Person();

    // setters & getters
    void setAge(unsigned int age);
    void setName(const std::string& name);
    void setAddress(const Address& address);
    [[nodiscard]] unsigned int getAge() const;
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] const Address& getAddress() const;

    void printInfo() const;

  private:
    unsigned int m_age;
    std::string m_name;
    Address m_address;
};