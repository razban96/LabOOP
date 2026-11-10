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
#include "../Humans/Person.h"
#include "Vehicle.h"
#include <string>
#include <vector>

class BusStation;

class Bus : public Vehicle
{
  public:
    // constructors & destructors
    explicit Bus(const std::string& busLine = "Linia 69", const unsigned int maxCapacity = 30,
                 Driver* driver = nullptr, const bool isStationary = true)
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
    [[nodiscard]] size_t getPassengerCount() const;
    [[nodiscard]] bool getIsStationary() const { return isStationary(); }

    // Engine & Movement
    void startEngine() override;
    void stopEngine() override;
    void stopBus(); // calls stopEngine()
    void startBus(); // calls startEngine()

    // Passenger boarding (Person*)
    bool boardPassenger(Person* person);
    bool boardCommuter(Person* person);
    bool removePassenger(Person* person);
    [[nodiscard]] bool hasPassenger(const Person* person) const;
    [[nodiscard]] const std::vector<Person*>& getPassengers() const;

    // Routes (Tasks 3 & 4)
    void addStationToRoute(BusStation* station);
    void removeStationFromRoute(BusStation* station);
    [[nodiscard]] const std::vector<BusStation*>& getRouteStations() const;
    [[nodiscard]] bool stopsAt(const BusStation* station) const;
    void printRoute() const;

    // Printing
    void printVehicleInfo() const override;
    void printBusInfo() const { printVehicleInfo(); }

    // Mosquitoes (Tasks 7 & 8)
    void addMosquito(Mosquito* mosquito);
    bool removeMosquito(Mosquito* mosquito);
    [[nodiscard]] bool hasMosquito(const Mosquito* mosquito) const;
    [[nodiscard]] const std::vector<Mosquito*>& getMosquitoes() const;
    [[nodiscard]] size_t getMosquitoCount() const;
    void mosquitoAttack(const Mosquito& mosquito);

  private:
    std::string m_busLine;
    unsigned int m_maxCapacity;
    std::vector<Person*> m_passengers;
    std::vector<BusStation*> m_routeStations;
    std::vector<Mosquito*> m_mosquitoes;
};