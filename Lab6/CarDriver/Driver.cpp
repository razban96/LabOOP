#include "Driver.h"
#include "../CarDriver/Car.h"
#include <utility>

Driver::Driver(std::string name) : m_name{std::move(name)} {}

void Driver::setCar(Car* car)
{
    if (m_car == car)
        return;

    m_car = car;

    if (m_car != nullptr)
        m_car->setDriver(this);
}
Car* Driver::getCar() const { return m_car; }

const std::string& Driver::getName() const { return m_name; }