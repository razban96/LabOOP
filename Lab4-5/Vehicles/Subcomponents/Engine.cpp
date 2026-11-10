#include "Engine.h"
#include <iostream>

Engine::Engine(unsigned int horsePower /* =0 */, unsigned int newtonMeters /*=0*/,
               unsigned int rpm /*=0*/, bool hasCheckEngine /*=false*/)
    : m_horsePower(horsePower), m_newtonMeters(newtonMeters), m_rpm(rpm), m_isRunning(false),
      m_hasCheckEngine(hasCheckEngine)
{
}
Engine::~Engine() = default;



unsigned int Engine::getHorsePower() const { return m_horsePower; }
unsigned int Engine::getNewtonMeters() const { return m_newtonMeters; }
unsigned int Engine::getRpm() const { return m_rpm; }
Engine::Stages Engine::getCurrentStage() const { return m_currentStage; }

bool Engine::isRunning() const { return m_isRunning; }
bool Engine::hasCheckEngine() const { return m_hasCheckEngine; }

void Engine::startEngine() { m_isRunning = true; }
void Engine::stopEngine() { m_isRunning = false; }

struct StageBoost
{
    unsigned int hpUpgrade{0};
    unsigned int nmUpgrade{0};
};
static StageBoost getStageUpgrade(const Engine::Stages& stage)
{
    switch (stage)
    {
    case Engine::Stages::Stage1:
        return {20, 30};
    case Engine::Stages::Stage2:
        return {40, 50};
    case Engine::Stages::Stage3:
        return {60, 70};
    default:
        return {0, 0};
    }
}
void Engine::callVericuSoft(const Stages& stage)
{
    if (m_currentStage == stage)
    {
        std::cout << "Vericule deja ai stageul pe ea" << std::endl;
        return;
    }

    // store old boost and new boost
    const StageBoost oldBoost = getStageUpgrade(m_currentStage);
    const StageBoost newBoost = getStageUpgrade(stage);

    // first delete old boost then update new boost so it doesn't underflow unsigned int
    m_horsePower = (m_horsePower - oldBoost.hpUpgrade) +  newBoost.hpUpgrade ;
    m_newtonMeters = (m_newtonMeters - oldBoost.nmUpgrade) + newBoost.nmUpgrade;
    // update current stage and upgrade stats
    m_currentStage = stage;

    // check engine for stage3, duuh
    if (m_currentStage == Stages::Stage3)
        m_hasCheckEngine = true;

    std::cout << "Gata vericule ai soft pe ea, poti sa distrugi CB ul" << std::endl;
}