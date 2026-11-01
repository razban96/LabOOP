#include "Person.h"

// setters & getters
void Person::setAge(unsigned int age) { m_age = age; }

void Person::setName(const std::string& name) { m_name = name; }

void Person::setIsAllergicToMosquitoes(bool isAllergicToMosquitoes)
{
    m_isAllergicToMosquitoes = isAllergicToMosquitoes;
}
void Person::setAddress(const Address& address) { m_address = address; }

unsigned int Person::getAge() const { return m_age; }

const std::string& Person::getName() const { return m_name; }

const Address& Person::getAddress() const { return m_address; }

bool Person::getIsAllergicToMosquitoes() const { return m_isAllergicToMosquitoes; }

bool Person::getIsAlive() const { return m_isAlive; }

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
