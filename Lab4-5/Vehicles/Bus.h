/*
* Naming Conventions:
 * - Classes / Structs  : PascalCase (Person, BusStation)
 * - Methods / Functions: camelCase  (getAge, setAddress)
 * - Member Data        : m_variableName (m_age, m_address)
 * - Static Data        : s_variableName (s_instanceCount)
 * - Global Data        : g_variableName (g_debugMode)
 * - Pointers           : p_variableName / ptr_variableName
 * - Constants          : c_variableName / kVariableName
 */
#pragma once
#include "../Creatures/Mosquito.h"
#include "../Humans/Driver.h"
#include "../Humans/Commuter.h"
#include <string>
#include <vector>
class Bus
{
  public:
    // constructors & destructors
    explicit Bus(const std::string& busLine = "Linia 69", unsigned int maxCapacity = 30,
                 Driver* driver = nullptr, bool isStationary = true)
        : m_busLine(busLine), m_maxCapacity(maxCapacity), m_driver(driver), m_isStationary(isStationary)
    {
    }

    ~Bus() = default;

    // getters & setters
    void setMaxCapacity(unsigned int maxCapacity);

    void setDriver(Driver* driver);

    bool boardCommuter(Commuter* commuter);

    [[nodiscard]] unsigned int getMaxCapacity() const;

    [[nodiscard]] std::string getBusLine() const;

    [[nodiscard]] Driver* getDriver() const;

    [[nodiscard]] bool getIsStationary() const;

    // other
    void stopBus();

    void startBus();

    void printBusInfo() const;

    void mosquitoAttack(const Mosquito& mosquito);
private:
    std::string m_busLine;
    unsigned int m_maxCapacity;
    Driver* m_driver;
    std::vector<Commuter*> m_commuters;
    bool m_isStationary;
};