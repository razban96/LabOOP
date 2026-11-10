#include "Address.h"

// setters & getters
void Address::setStreet(const std::string& street) { m_street = street; }

void Address::setCity(const std::string& city) { m_city = city; }

void Address::setStreetNumber(unsigned int streetNumber) { m_streetNumber = streetNumber; }

const std::string& Address::getStreet() const { return m_street; }

const std::string& Address::getCity() const { return m_city; }

unsigned int Address::getStreetNumber() const { return m_streetNumber; }
