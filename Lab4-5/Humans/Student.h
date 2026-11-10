#pragma once

#include "Person.h"

#include <string>

class Student : public Person
{
  public:
    explicit Student(const std::string& name = "Unknown", unsigned int age = 18,
                     double averageGrade = 0.0);
    virtual ~Student();

    void setAverageGrade(double averageGrade);

    [[nodiscard]] double getAverageGrade() const;

  private:
    double m_averageGrade;
};
