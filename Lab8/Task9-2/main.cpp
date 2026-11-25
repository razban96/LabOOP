#include <vector>
#include "Car.h"
#include "Rocket.h"

int main() {
    std::vector<Vehicle*> vehicles;

    vehicles.push_back(new Car("red"));
    vehicles.push_back(new Car("awesome"));
    vehicles.push_back(new Rocket("NASA"));

    for (auto v : vehicles) {
        v->start();
    }

    for (auto v : vehicles) {
        delete v;
    }

    return 0;
}