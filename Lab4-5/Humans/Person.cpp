#include "Person.h"

Person::Person(unsigned int age, const std::string& name,
               bool isAllergicToMosquitoes, const Address& address, bool isAlive)
    : m_age(age), m_name(name), m_address(address),
      m_isAllergicToMosquitoes(isAllergicToMosquitoes), m_isAlive(isAlive)
{
}

// setters & getters
void Person::setAge(unsigned int age) { m_age = age; }

void Person::setName(const std::string& name) { m_name = name; }

void Person::setIsAllergicToMosquitoes(bool isAllergicToMosquitoes)
{
    m_isAllergicToMosquitoes = isAllergicToMosquitoes;
}
void Person::setAddress(const Address& address) { m_address = address; }
void Person::setApartment(Apartment* apartment) { m_apartment = apartment; }

unsigned int Person::getAge() const { return m_age; }

const std::string& Person::getName() const { return m_name; }

const Address& Person::getAddress() const { return m_address; }

bool Person::getIsAllergicToMosquitoes() const { return m_isAllergicToMosquitoes; }

bool Person::getIsAlive() const { return m_isAlive; }

Apartment* Person::getApartment() const { return m_apartment; }

// Other
void Person::printStandardInfo() const
{
    std::cout << "Name: " << m_name << ", Age: " << m_age << std::endl;
    std::cout << "Address: " << m_address.getStreet() << " " << m_address.getStreetNumber() << ", "
              << m_address.getCity() << std::endl;
    if (getIsAlive())
    {
        std::cout << "Status: Alive" << std::endl;
    }
    else
    {
        std::cout << "Status: Deceased" << std::endl;
    }
}
void Person::receiveBite()
{
        m_isAlive = false;
}
