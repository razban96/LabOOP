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

class Commuter : public Person
{
  public:
    // constructors & destructors
    explicit Commuter(unsigned int age = 18, const std::string& name = "Unknown",
                      bool isAllergicToMosquitoes = false, bool isAlive = true,
                      const Address& address = Address(), bool hasTicket = false,
                      bool hasSubscription = false,
                      const std::string& destination = "Facultatea de Hoti si Sarlatani 46")
        : Person(age, name, isAllergicToMosquitoes, address, isAlive), m_hasTicket(hasTicket),
          m_hasSubscription(hasSubscription), m_destination(destination)
    {
    }
    ~Commuter() override = default;

    // setters & getters
    void buyTicket();

    void buySubscription();

    void setDestination(const std::string& destination);

    [[nodiscard]] bool hasTicket() const;

    [[nodiscard]] bool hasSubscription() const;

    [[nodiscard]] const std::string& getDestination() const;


    // Other
    void printStandardInfo() const override;
  private:
    bool m_hasTicket;
    bool m_hasSubscription;
    std::string m_destination;
};
