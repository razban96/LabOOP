#pragma once
#include "Vehicle.h"

class Car : public Vehicle {
public:
    explicit Car(const std::string& name);
    void start() override;
};