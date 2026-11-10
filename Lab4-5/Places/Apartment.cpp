#include "Apartment.h"

Apartment::Apartment(const std::string& address, unsigned int rooms, double area)
    : m_address(address), m_rooms(rooms), m_area(area)
{
}

Apartment::~Apartment() = default;

void Apartment::setAddress(const std::string& address) { m_address = address; }

void Apartment::setRooms(unsigned int rooms) { m_rooms = rooms; }

void Apartment::setArea(double area) { m_area = area; }

const std::string& Apartment::getAddress() const { return m_address; }

unsigned int Apartment::getRooms() const { return m_rooms; }

double Apartment::getArea() const { return m_area; }
