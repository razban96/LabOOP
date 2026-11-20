#include "Student.h"

#include <utility>

Student::Student(std::string name, const int grade) : m_name(std::move(name)), m_grade(grade) {}

std::string Student::getName() const { return m_name; }

int Student::getGrade() const { return m_grade; }

bool Student::operator<(const Student& other) const { return m_grade < other.m_grade; }