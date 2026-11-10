#pragma once

#include "Creatures/Mosquito.h"
#include "Humans/Commuter.h"
#include "Humans/Driver.h"
#include "Humans/Person.h"
#include "Humans/Student.h"
#include "Humans/Subcomponents/Address.h"
#include "Places/Apartment.h"
#include "Places/BusStation.h"
#include "Vehicles/Bus.h"
#include "Vehicles/Car.h"

#include <vector>

namespace CityOps
{
    // Task 1: Start a bus engine
    bool startBusEngine(Bus& bus);

    // Task 2: How many commuters/passengers are in a bus / busStation
    size_t getBusCommuterCount(const Bus& bus);
    size_t getStationCommuterCount(const BusStation& station);

    // Task 3: What are the buses stopping in some busStation
    const std::vector<Bus*>& getBusesStoppingAt(const BusStation& station);

    // Task 4: What are the stations a bus will stop in
    const std::vector<BusStation*>& getStationsForBus(const Bus& bus);

    // Task 5: Move an apartment from a person to a student
    bool moveApartment(Person* fromPerson, Student* toStudent);

    // Task 6: Add a student to a busStation, bus and car
    bool addStudentToBusStation(BusStation& station, Student* student);
    bool addStudentToBus(Bus& bus, Student* student);
    bool addStudentToCar(Car& car, Student* student);

    // Task 7: Move a mosquito from an apartment to a bus or to a car
    bool moveMosquitoFromApartmentToBus(Apartment& apt, Bus& bus, Mosquito* mosquito);
    bool moveMosquitoFromApartmentToCar(Apartment& apt, Car& car, Mosquito* mosquito);

    // Task 8: Is a specific mosquito in a specific bus, car or apartment?
    bool isMosquitoInApartment(const Apartment& apt, const Mosquito* mosquito);
    bool isMosquitoInBus(const Bus& bus, const Mosquito* mosquito);
    bool isMosquitoInCar(const Car& car, const Mosquito* mosquito);

    // Task 9: Find a student based on address and check if on a bus driven by a specific driver
    Student* findStudentByAddress(const std::vector<Student*>& students, const Address& address);
    bool isStudentOnBusDrivenBy(const Student* student, const Bus& bus, const Driver* driver);
}
