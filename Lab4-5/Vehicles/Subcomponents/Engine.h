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

class Engine
{
  public:
    // constructors & destructors
    // explicit Engine() = default;
    explicit Engine(unsigned int horsePower = 0, unsigned int newtonMeters = 0,
                    unsigned int rpm = 0, bool hasCheckEngine = false);
    ~Engine();


    // softuri
    enum class Stages
    {
        Stock = 0, Stage1, Stage2, Stage3
    };

    // getters
    [[nodiscard]] unsigned int getHorsePower() const;
    [[nodiscard]] unsigned int getNewtonMeters() const;
    [[nodiscard]] unsigned int getRpm() const;
    [[nodiscard]] Stages getCurrentStage() const;
    [[nodiscard]] bool isRunning() const;
    [[nodiscard]] bool hasCheckEngine() const;

    // setters
    void startEngine();
    void stopEngine();

    // other
    void printEngineInfo() const;
    // tuning (softuri arabesti)
    void callVericuSoft(const Stages& stage);

  private:
    // stats
    unsigned int m_horsePower{};
    unsigned int m_newtonMeters{};
    unsigned int m_rpm{};
    Stages m_currentStage{Stages::Stock};

    // state
    bool m_isRunning{};
    bool m_hasCheckEngine{};
};
