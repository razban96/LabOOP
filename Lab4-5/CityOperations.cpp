#include "CityOperations.h"

namespace CityOps
{
    // Task 1: Start a bus engine
    bool startBusEngine(Bus& bus)
    {
        bus.startBus();
        return !bus.isStationary();
    }

    // Task 2: Commuter counts
    size_t getBusCommuterCount(const Bus& bus)
    {
        return bus.getPassengerCount();
    }

    size_t getStationCommuterCount(const BusStation& station)
    {
        return station.getWaitingPassengerCount();
    }

    // Task 3: Buses stopping at a station
    const std::vector<Bus*>& getBusesStoppingAt(const BusStation& station)
    {
        return station.getServicingBuses();
    }

    // Task 4: Stations a bus will stop in
    const std::vector<BusStation*>& getStationsForBus(const Bus& bus)
    {
        return bus.getRouteStations();
    }

    // Task 5: Move apartment from Person to Student
    bool moveApartment(Person* fromPerson, Student* toStudent)
    {
        if (fromPerson == nullptr || toStudent == nullptr)
            return false;

        Apartment* apt = fromPerson->getApartment();
        if (apt == nullptr)
            return false;

        fromPerson->setApartment(nullptr);
        toStudent->setApartment(apt);
        apt->setOwner(toStudent);
        return true;
    }

    // Task 6: Add student to station, bus, and car
    bool addStudentToBusStation(BusStation& station, Student* student)
    {
        if (student == nullptr)
            return false;
        station.addPassenger(student);
        return true;
    }

    bool addStudentToBus(Bus& bus, Student* student)
    {
        if (student == nullptr)
            return false;
        return bus.boardPassenger(student);
    }

    bool addStudentToCar(Car& car, Student* student)
    {
        if (student == nullptr)
            return false;
        return car.boardPassenger(student);
    }

    // Task 7: Move mosquito from apartment to bus or car
    bool moveMosquitoFromApartmentToBus(Apartment& apt, Bus& bus, Mosquito* mosquito)
    {
        if (mosquito == nullptr)
            return false;
        if (apt.removeMosquito(mosquito))
        {
            bus.addMosquito(mosquito);
            return true;
        }
        return false;
    }

    bool moveMosquitoFromApartmentToCar(Apartment& apt, Car& car, Mosquito* mosquito)
    {
        if (mosquito == nullptr)
            return false;
        if (apt.removeMosquito(mosquito))
        {
            car.addMosquito(mosquito);
            return true;
        }
        return false;
    }

    // Task 8: Check if mosquito is in a specific location
    bool isMosquitoInApartment(const Apartment& apt, const Mosquito* mosquito)
    {
        return apt.hasMosquito(mosquito);
    }

    bool isMosquitoInBus(const Bus& bus, const Mosquito* mosquito)
    {
        return bus.hasMosquito(mosquito);
    }

    bool isMosquitoInCar(const Car& car, const Mosquito* mosquito)
    {
        return car.hasMosquito(mosquito);
    }

    // Task 9: Find student by address and check if on bus driven by driver
    Student* findStudentByAddress(const std::vector<Student*>& students, const Address& address)
    {
        for (Student* s : students)
        {
            if (s != nullptr && s->getAddress() == address)
            {
                return s;
            }
        }
        return nullptr;
    }

    bool isStudentOnBusDrivenBy(const Student* student, const Bus& bus, const Driver* driver)
    {
        if (student == nullptr || driver == nullptr)
            return false;
        return (bus.getDriver() == driver) && bus.hasPassenger(student);
    }
}
