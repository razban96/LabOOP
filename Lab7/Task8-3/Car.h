#pragma once

class Car
{
  public:
    explicit Car(int age = 0);
    [[nodiscard]] int getAge() const;

  private:
    int m_age;
};