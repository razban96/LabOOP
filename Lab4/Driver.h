#pragma once
#include "Person.h"
class Driver : public Person
{
  public:
    explicit Driver(unsigned int age, const std::string& name, bool isAllergicToMosquitoes, bool isAlive,
           const Address& address, unsigned int yearsOfExperience = 3, bool hasLicenseValid = true)
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
