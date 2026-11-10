#include "Student.h"

Student::Student(const std::string& name, unsigned int age, double averageGrade)
    : m_name(name), m_age(age), m_averageGrade(averageGrade)
{
}

Student::~Student() = default;

void Student::setName(const std::string& name) { m_name = name; }

void Student::setAge(unsigned int age) { m_age = age; }

void Student::setAverageGrade(double averageGrade) { m_averageGrade = averageGrade; }

const std::string& Student::getName() const { return m_name; }

unsigned int Student::getAge() const { return m_age; }

double Student::getAverageGrade() const { return m_averageGrade; }
