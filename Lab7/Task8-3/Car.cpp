#include "Car.h"

Car::Car(const int age) : m_age(age) {}

int Car::getAge() const {
    return m_age;
}