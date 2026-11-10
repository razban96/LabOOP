#include "Apartment.h"
#include "../Humans/Person.h"
#include <iostream>

Apartment::Apartment(const Address& address, unsigned int rooms, double area)
    : m_address(address), m_rooms(rooms), m_area(area)
{
}

Apartment::~Apartment() = default;

void Apartment::setAddress(const Address& address) { m_address = address; }

void Apartment::setRooms(unsigned int rooms) { m_rooms = rooms; }

void Apartment::setArea(double area) { m_area = area; }

const Address& Apartment::getAddress() const { return m_address; }

unsigned int Apartment::getRooms() const { return m_rooms; }

double Apartment::getArea() const { return m_area; }

void Apartment::setOwner(Person* owner) { m_owner = owner; }

Person* Apartment::getOwner() const { return m_owner; }

void Apartment::printApartmentInfo() const
{
    std::cout << "Apartment Info:\n"
              << "  Address: " << m_address.getStreet() << " " << m_address.getStreetNumber()
              << ", " << m_address.getCity() << "\n"
              << "  Rooms: " << m_rooms << "\n"
              << "  Area: " << m_area << " m^2\n"
              << "  Owner: " << (m_owner != nullptr ? m_owner->getName() : "None") << "\n"
              << "  Mosquitoes: " << m_mosquitoes.size() << "\n";
}

void Apartment::addMosquito(Mosquito* mosquito)
{
    if (mosquito != nullptr)
    {
        m_mosquitoes.push_back(mosquito);
    }
}

bool Apartment::removeMosquito(Mosquito* mosquito)
{
    for (auto it = m_mosquitoes.begin(); it != m_mosquitoes.end(); ++it)
    {
        if (*it == mosquito)
        {
            m_mosquitoes.erase(it);
            return true;
        }
    }
    return false;
}

bool Apartment::hasMosquito(const Mosquito* mosquito) const
{
    for (const auto* m : m_mosquitoes)
    {
        if (m == mosquito)
        {
            return true;
        }
    }
    return false;
}

const std::vector<Mosquito*>& Apartment::getMosquitoes() const { return m_mosquitoes; }

size_t Apartment::getMosquitoCount() const { return m_mosquitoes.size(); }
