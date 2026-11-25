#include "Vehicle.h"

#include <utility>

Vehicle::Vehicle(std::string  vehicleName) : name(std::move(vehicleName)) {}