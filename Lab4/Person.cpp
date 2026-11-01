#include "Person.h"

// constructors & destructors
Person::Person() = default;
Person::Person(unsigned int age, const std::string& name, const Address& address)
    : m_age(age), m_name(name), m_address(address)
{
}

Person::~Person() = default;

// setters & getters
void Person::setAge(unsigned int age) { m_age = age; }
void Person::setName(const std::string& name) { m_name = name; }
void Person::setAddress(const Address& address) { m_address = address; }
unsigned int Person::getAge() const { return m_age; }
std::string Person::getName() const { return m_name; }
const Address& Person::getAddress() const { return m_address; }

// Other
void Person::printInfo() const
{
    std::cout << "Name: " << m_name << ", Age: " << m_age << std::endl;
    std::cout << "Address: " << m_address.getStreet() << " " << m_address.getStreetNumber() << ", "
              << m_address.getCity() << std::endl;
}
