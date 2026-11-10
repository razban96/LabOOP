#pragma once

#include <string>

class Apartment
{
  public:
    explicit Apartment(const std::string& address = "Unknown", unsigned int rooms = 1,
                       double area = 0.0);
    virtual ~Apartment();

    void setAddress(const std::string& address);
    void setRooms(unsigned int rooms);
    void setArea(double area);

    [[nodiscard]] const std::string& getAddress() const;
    [[nodiscard]] unsigned int getRooms() const;
    [[nodiscard]] double getArea() const;

  private:
    std::string m_address;
    unsigned int m_rooms;
    double m_area;
};
