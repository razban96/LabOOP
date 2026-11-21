#include "Rocket.h"
#include <iostream>

Rocket::Rocket(const std::string& name) : Vehicle(name) {}

void Rocket::start() {
    std::cout << "start " << name << " rocket" << std::endl;
}