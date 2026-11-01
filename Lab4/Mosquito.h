#pragma once
#include "Person.h"
class Mosquito
{
  public:
    explicit Mosquito(bool isDeadly = false) : m_isDeadly(isDeadly) {}
    ~Mosquito() = default;

    [[nodiscard]] bool isDeadly() const;
    void bite(Person& p) const;

  private:
    const bool m_isDeadly;
};