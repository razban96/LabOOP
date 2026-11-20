#pragma once
#include <string>

class Student
{

  public:
    explicit Student(std::string name = "", int grade = 0);

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] int getGrade() const;

    bool operator<(const Student& other) const;

  private:
    std::string m_name;
    int m_grade;
};