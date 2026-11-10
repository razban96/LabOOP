#include "Student.h"

Student::Student(const std::string& name, unsigned int age, double averageGrade)
    : /*Person(name, age),*/ m_averageGrade(averageGrade)
{
}

Student::~Student() = default;

void Student::setAverageGrade(double averageGrade) { m_averageGrade = averageGrade; }

double Student::getAverageGrade() const { return m_averageGrade; }
