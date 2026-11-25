#include "Car.h"
#include <iostream>

Car::Car(const std::string& name) : Vehicle(name) {}

void Car::start() {
    std::cout << "start " << name << " car" << std::endl;
}