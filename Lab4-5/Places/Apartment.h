#pragma once

#include "../Humans/Subcomponents/Address.h"
#include <string>
#include <vector>

class Person;
class Mosquito;

class Apartment
{
  public:
    explicit Apartment(const Address& address = Address(), unsigned int rooms = 1,
                       double area = 0.0);
    ~Apartment();

    void setAddress(const Address& address);
    void setRooms(unsigned int rooms);
    void setArea(double area);
    void setOwner(Person* owner);

    [[nodiscard]] const Address& getAddress() const;
    [[nodiscard]] unsigned int getRooms() const;
    [[nodiscard]] double getArea() const;
    [[nodiscard]] Person* getOwner() const;

    // Mosquitoes
    void addMosquito(Mosquito* mosquito);
    bool removeMosquito(Mosquito* mosquito);
    [[nodiscard]] bool hasMosquito(const Mosquito* mosquito) const;
    [[nodiscard]] const std::vector<Mosquito*>& getMosquitoes() const;
    [[nodiscard]] size_t getMosquitoCount() const;

    void printApartmentInfo() const;

  private:
    Address m_address;
    unsigned int m_rooms;
    double m_area;
    Person* m_owner{nullptr};
    std::vector<Mosquito*> m_mosquitoes;
};
