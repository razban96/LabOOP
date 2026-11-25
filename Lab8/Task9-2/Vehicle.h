#pragma once
#include <string>

class Vehicle {
protected:
    std::string name;

public:
    Vehicle(std::string  vehicleName);
    virtual void start() = 0;
    virtual ~Vehicle() = default;
};