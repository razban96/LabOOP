#pragma once

#include <string>

class Student
{
  public:
    explicit Student(const std::string& name = "Unknown", unsigned int age = 18,
                     double averageGrade = 0.0);
    virtual ~Student();

    void setName(const std::string& name);
    void setAge(unsigned int age);
    void setAverageGrade(double averageGrade);

    [[nodiscard]] const std::string& getName() const;
    [[nodiscard]] unsigned int getAge() const;
    [[nodiscard]] double getAverageGrade() const;

  private:
    std::string m_name;
    unsigned int m_age;
    double m_averageGrade;
};
