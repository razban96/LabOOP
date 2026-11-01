#pragma once
#include "Person.h"

class Commuter : public Person
{
  public:
    // constructors & destructors
    explicit Commuter(unsigned int age, const std::string& name, bool isAllergicToMosquitoes,
                      bool isAlive, const Address& address, bool hasTicket = false, bool hasSubscription = false,
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
