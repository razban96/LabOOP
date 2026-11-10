#include "Student.h"

Student::Student(const std::string& name, const unsigned int age, const double averageGrade,
                 const Address& address, const bool isAllergicToMosquitoes, const bool isAlive)
    : Person(age, name, isAllergicToMosquitoes, address, isAlive),
      m_averageGrade(averageGrade)
{
}

Student::~Student() = default;

void Student::setAverageGrade(double averageGrade) { m_averageGrade = averageGrade; }

double Student::getAverageGrade() const { return m_averageGrade; }
