#include "Person.h"

Person::Person(const int age) : m_age(age) {}

int Person::getAge() const {
    return m_age;
}