#pragma once
#include "Vehicle.h"

class Rocket : public Vehicle {
public:
    explicit Rocket(const std::string& name);
    void start() override;
};