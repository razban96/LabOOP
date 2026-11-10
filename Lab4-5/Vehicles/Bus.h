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
#include "../Humans/Commuter.h"
#include "../Humans/Driver.h"
#include "Vehicle.h"
#include <string>
#include <vector>
class Bus : public Vehicle
{
  public:
    // constructors & destructors
    explicit Bus(const std::string& busLine = "Linia 69", unsigned int maxCapacity = 30,
                 Driver* driver = nullptr, bool isStationary = true)
        : Vehicle(Engine(), driver), m_busLine(busLine), m_maxCapacity(maxCapacity)
    {
        setIsStationary(isStationary);
    }

    ~Bus() override = default;

    // getters & setters
    void setMaxCapacity(unsigned int maxCapacity);

    [[nodiscard]] unsigned int getMaxCapacity() const;
    [[nodiscard]] std::string getBusLine() const;
    [[nodiscard]] unsigned int getCommuterCount() const;

    // Management
    void startEngine() override;
    void stopEngine() override;
    void stopBus();
    void startBus();

    bool boardCommuter(Commuter* commuter);
    void printVehicleInfo() const override;

    // Mosquito
    void mosquitoAttack(const Mosquito& mosquito);
private:
    std::string m_busLine;
    unsigned int m_maxCapacity;
    std::vector<Commuter*> m_commuters;
};