#include "Vehicle.h"

Vehicle::Vehicle(const Engine& engine, Driver* driver)
    : m_engine(engine), m_driver(driver), m_isStationary(true)
{
}
Vehicle::~Vehicle() = default;


const Engine& Vehicle::getEngine() const { return m_engine; }
Engine& Vehicle::getEngine() {return m_engine;}
Driver* Vehicle::getDriver() const { return m_driver; }
bool Vehicle::isStationary() const { return m_isStationary; }

void Vehicle::setEngine(const Engine& engine) {m_engine = engine;}
void Vehicle::setDriver(Driver* driver) {m_driver = driver;}
void Vehicle::setIsStationary(bool isStationary) {m_isStationary = isStationary;}

