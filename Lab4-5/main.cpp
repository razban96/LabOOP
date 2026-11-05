#include "Bus.h"
#include "BusStation.h"
#include "Mosquito.h"
#include "Commuter.h"
#include "Driver.h"

#include <cassert>
#include <iostream>

int main()
{
    std::cout << "Testing Address...\n";
    Address address("Independence Avenue", "Craiova", 10);
    assert(address.getStreet() == "Independence Avenue");
    assert(address.getCity() == "Craiova");
    assert(address.getStreetNumber() == 10);

    address.setStreet("Liberty Street");
    address.setCity("Bucharest");
    address.setStreetNumber(25);
    assert(address.getStreet() == "Liberty Street");
    assert(address.getCity() == "Bucharest");
    assert(address.getStreetNumber() == 25);

    std::cout << "Testing Person...\n";
    Person person(30, "Alice", true, address, true);
    assert(person.getAge() == 30);
    assert(person.getName() == "Alice");
    assert(person.getAddress().getCity() == "Bucharest");
    assert(person.getIsAllergicToMosquitoes());
    assert(person.getIsAlive());
    person.printStandardInfo();

    person.setAge(31);
    person.setName("Alicia");
    person.setIsAllergicToMosquitoes(false);
    Address secondAddress("Central Street", "Cluj", 5);
    person.setAddress(secondAddress);
    assert(person.getAge() == 31);
    assert(person.getName() == "Alicia");
    assert(!person.getIsAllergicToMosquitoes());
    assert(person.getAddress().getStreet() == "Central Street");

    std::cout << "Testing Commuter...\n";
    Commuter commuter(20, "Bob", true, true, address);
    assert(!commuter.hasTicket());
    assert(!commuter.hasSubscription());
    commuter.buyTicket();
    assert(commuter.hasTicket());
    commuter.buySubscription();
    assert(!commuter.hasSubscription());
    commuter.setDestination("University");
    assert(commuter.getDestination() == "University");
    commuter.printStandardInfo();

    Commuter subscriber(22, "Charlie", false, true, address);
    subscriber.buySubscription();
    assert(subscriber.hasSubscription());
    subscriber.buyTicket();
    assert(!subscriber.hasTicket());

    std::cout << "Testing Driver...\n";
    Driver driver(45, "Daniel", false, true, address, 15, true);
    assert(driver.getYearsOfExperience() == 15);
    assert(driver.hasLicenseValid());
    driver.printStandardInfo();

    std::cout << "Testing Mosquito...\n";
    Mosquito harmlessMosquito;
    Mosquito deadlyMosquito(true);
    assert(!harmlessMosquito.isDeadly());
    assert(deadlyMosquito.isDeadly());

    harmlessMosquito.bite(person);
    assert(person.getIsAlive());
    deadlyMosquito.bite(person);
    assert(person.getIsAlive());

    Person allergicPerson(25, "Eve", true, address, true);
    deadlyMosquito.bite(allergicPerson);
    assert(!allergicPerson.getIsAlive());

    std::cout << "Testing Bus...\n";
    Bus bus("Line 42", 2);
    assert(bus.getBusLine() == "Line 42");
    assert(bus.getMaxCapacity() == 2);
    assert(bus.getDriver() == nullptr);
    assert(bus.getIsStationary());
    bus.startBus();
    assert(bus.getIsStationary());

    bus.setDriver(&driver);
    assert(bus.getDriver() == &driver);
    bus.setMaxCapacity(2);
    assert(bus.getMaxCapacity() == 2);
    assert(!bus.boardCommuter(nullptr));
    assert(bus.boardCommuter(&commuter));
    assert(bus.boardCommuter(&subscriber));

    Commuter extraCommuter(19, "Frank", false, true, address);
    assert(!bus.boardCommuter(&extraCommuter));
    bus.setMaxCapacity(3);
    assert(bus.getMaxCapacity() == 3);
    assert(bus.boardCommuter(&extraCommuter));

    bus.startBus();
    assert(!bus.getIsStationary());
    bus.stopBus();
    assert(bus.getIsStationary());
    bus.printBusInfo();

    Mosquito nonDeadlyMosquito(false);
    bus.mosquitoAttack(nonDeadlyMosquito);
    assert(driver.getIsAlive());
    assert(commuter.getIsAlive());
    assert(subscriber.getIsAlive());

    std::cout << "Testing BusStation...\n";
    BusStation station("Central Station");
    assert(station.getName() == "Central Station");
    assert(station.getWaitingPassengerCount() == 0);
    assert(!station.isOccupied());

    station.boardPassengers();
    assert(station.getWaitingPassengerCount() == 0);

    Commuter stationPassenger1(28, "Grace", false, true, address);
    Commuter stationPassenger2(33, "Henry", true, true, address);
    Commuter stationPassenger3(24, "Iris", false, true, address);
    station.addPassenger(&stationPassenger1);
    station.addPassenger(&stationPassenger2);
    station.addPassenger(&stationPassenger3);
    assert(station.getWaitingPassengerCount() == 3);

    Bus stationBus("Station Line", 2, &driver);
    station.busArrives(&stationBus);
    assert(station.isOccupied());
    station.boardPassengers();
    assert(station.getWaitingPassengerCount() == 1);

    station.busDeparts();
    assert(!station.isOccupied());
    station.boardPassengers();
    assert(station.getWaitingPassengerCount() == 1);

    Bus replacementBus("Replacement Line", 3, &driver);
    station.busArrives(&replacementBus);
    station.boardPassengers();
    assert(station.getWaitingPassengerCount() == 0);
    assert(replacementBus.boardCommuter(nullptr) == false);

    std::cout << "All Lab4-5 tests passed.\n";

    return 0;
}