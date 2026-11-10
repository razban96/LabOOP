#pragma once

#include <string>
#include <vector>

class Person;
class Mosquito;

class Apartment
{
  public:
    explicit Apartment(const std::string& address = "Unknown", unsigned int rooms = 1,
                       double area = 0.0);
    virtual ~Apartment();

    void setAddress(const std::string& address);
    void setRooms(unsigned int rooms);
    void setArea(double area);
    void setOwner(Person* owner);

    [[nodiscard]] const std::string& getAddress() const;
    [[nodiscard]] unsigned int getRooms() const;
    [[nodiscard]] double getArea() const;
    [[nodiscard]] Person* getOwner() const;

    // Mosquitoes
    void addMosquito(Mosquito* mosquito);
    bool removeMosquito(Mosquito* mosquito);
    [[nodiscard]] bool hasMosquito(const Mosquito* mosquito) const;
    [[nodiscard]] const std::vector<Mosquito*>& getMosquitoes() const;
    [[nodiscard]] size_t getMosquitoCount() const;

  private:
    std::string m_address;
    unsigned int m_rooms;
    double m_area;
    Person* m_owner{nullptr};
    std::vector<Mosquito*> m_mosquitoes;
};
