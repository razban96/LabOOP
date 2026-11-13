#include "Car.h"
#include "../CarDriver/Driver.h"
#include <utility>

Car::Car(std::string model) : m_model{std::move(model)} {}
void Car::setDriver(Driver* driver)
{
    if (m_driver == driver)
        return;
    m_driver = driver;

    if (m_driver != nullptr)
        m_driver->setCar(this);
}
Driver* Car::getDriver() const { return m_driver; }

const std::string& Car::getModel() const { return m_model; }
