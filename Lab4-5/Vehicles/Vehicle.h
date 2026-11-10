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
#include "Subcomponents/Engine.h"
class Vehicle
{
  public:
    explicit Vehicle(const Engine& engine = Engine(), Driver* driver = nullptr);
    virtual ~Vehicle();

    // getters
    [[nodiscard]] const Engine& getEngine() const;
    [[nodiscard]] Engine& getEngine(); //for-tuning overloaded func
    [[nodiscard]] Driver* getDriver() const;
    [[nodiscard]] bool isStationary() const;

    // setters
    void setEngine(const Engine& engine);
    void setDriver(Driver* driver);
    void setIsStationary(bool isStationary);


    // pure virtual, makes the Vehicle class abstract, an interface
    virtual void startEngine() = 0;

  protected:
    Engine m_engine;
    Driver* m_driver{nullptr};
    bool m_isStationary{true};
};
