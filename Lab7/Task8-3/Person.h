#pragma once

class Person {
public:
    explicit Person(int age = 0);
    [[nodiscard]] int getAge() const;

private:
    int m_age;
};