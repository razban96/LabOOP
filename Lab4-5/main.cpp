#include "CityOperations.h"
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
#include "Vehicles/Subcomponents/Engine.h"

#include <cassert>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

static int getIntInput(const std::string& prompt)
{
    int value = 0;
    while (true)
    {
        std::cout << prompt;
        if (std::cin >> value)
        {
            return value;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter an integer.\n";
    }
}

static std::string getStringInput(const std::string& prompt)
{
    std::cout << prompt;
    std::string val;
    std::cin >> std::ws;
    std::getline(std::cin, val);
    return val;
}

void runAutomatedTests()
{
    std::cout << "=== Running Automated Tests for All Lab 4-5 Classes and Tasks ===\n";

    // 1. Address
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

    Address addressCopy("Liberty Street", "Bucharest", 25);
    assert(address == addressCopy);

    // 2. Person
    Person person(30, "Alice", true, address, true);
    assert(person.getAge() == 30);
    assert(person.getName() == "Alice");
    assert(person.getAddress().getCity() == "Bucharest");
    assert(person.getIsAllergicToMosquitoes());
    assert(person.getIsAlive());

    // 3. Commuter
    Commuter commuter(20, "Bob", true, true, address);
    assert(!commuter.hasTicket());
    assert(!commuter.hasSubscription());
    commuter.buyTicket();
    assert(commuter.hasTicket());
    commuter.setDestination("University");
    assert(commuter.getDestination() == "University");

    Commuter subscriber(22, "Charlie", false, true, address);
    subscriber.buySubscription();
    assert(subscriber.hasSubscription());

    // 4. Driver
    Driver driver(45, "Daniel", false, true, address, 15, true);
    assert(driver.getYearsOfExperience() == 15);
    assert(driver.hasLicenseValid());

    // 5. Student
    Student student("Elena", 21, 9.85, address, false, true);
    assert(student.getName() == "Elena");
    assert(student.getAge() == 21);
    assert(student.getAverageGrade() == 9.85);

    // 6. Mosquito
    Mosquito harmlessMosquito(false, "Culex");
    Mosquito deadlyMosquito(true, "Anopheles");
    assert(!harmlessMosquito.isDeadly());
    assert(deadlyMosquito.isDeadly());
    harmlessMosquito.bite(person);
    assert(person.getIsAlive());

    Person allergicPerson(25, "Eve", true, address, true);
    deadlyMosquito.bite(allergicPerson);
    assert(!allergicPerson.getIsAlive());

    // 7. Bus & Engine (Task 1 & Task 2)
    Bus bus("Line 42", 2);
    assert(bus.getBusLine() == "Line 42");
    assert(bus.getMaxCapacity() == 2);
    assert(bus.getDriver() == nullptr);
    assert(bus.getIsStationary());
    bus.startBus();
    assert(bus.getIsStationary()); // cannot start without driver

    bus.setDriver(&driver);
    assert(CityOps::startBusEngine(bus)); // Task 1 verified
    assert(!bus.getIsStationary());
    bus.stopBus();
    assert(bus.getIsStationary());

    assert(bus.boardPassenger(&commuter));
    assert(bus.boardPassenger(&subscriber));
    assert(CityOps::getBusCommuterCount(bus) == 2); // Task 2 verified

    // 8. BusStation
    BusStation station1("Central Station");
    BusStation station2("University Station");
    assert(station1.getWaitingPassengerCount() == 0);

    // 9. Route synchronization (Task 3 & Task 4)
    bus.addStationToRoute(&station1);
    bus.addStationToRoute(&station2);
    assert(bus.stopsAt(&station1));
    assert(bus.stopsAt(&station2));
    assert(station1.hasBus(&bus)); // two-way sync verified
    assert(station2.hasBus(&bus));
    assert(CityOps::getBusesStoppingAt(station1).size() == 1); // Task 3 verified
    assert(CityOps::getStationsForBus(bus).size() == 2);       // Task 4 verified

    // 10. Apartment with Address composition & Moving apartment (Task 5)
    Apartment apartment(address, 3, 75.5);
    assert(apartment.getAddress() == address);
    assert(apartment.getRooms() == 3);
    assert(apartment.getArea() == 75.5);

    person.setApartment(&apartment);
    apartment.setOwner(&person);
    assert(person.getApartment() == &apartment);
    assert(apartment.getOwner() == &person);

    assert(CityOps::moveApartment(&person, &student)); // Task 5 verified
    assert(person.getApartment() == nullptr);
    assert(student.getApartment() == &apartment);
    assert(apartment.getOwner() == &student);

    // 11. Add student to BusStation, Bus, Car (Task 6)
    Car car(4, &driver);
    assert(CityOps::addStudentToBusStation(station1, &student)); // Task 6 verified
    assert(station1.hasPassenger(&student));

    bus.setMaxCapacity(5);
    assert(CityOps::addStudentToBus(bus, &student));
    assert(bus.hasPassenger(&student));

    assert(CityOps::addStudentToCar(car, &student));
    assert(car.hasPassenger(&student));

    // 12. Move mosquito from apartment to bus/car (Task 7)
    Mosquito bug(true, "Aedes");
    apartment.addMosquito(&bug);
    assert(apartment.hasMosquito(&bug));

    assert(CityOps::moveMosquitoFromApartmentToBus(apartment, bus, &bug)); // Task 7 verified
    assert(!apartment.hasMosquito(&bug));
    assert(bus.hasMosquito(&bug));

    // 13. Is mosquito in apartment, bus, or car (Task 8)
    assert(CityOps::isMosquitoInBus(bus, &bug)); // Task 8 verified
    assert(!CityOps::isMosquitoInCar(car, &bug));
    assert(!CityOps::isMosquitoInApartment(apartment, &bug));

    // 14. Find student by address and check if on bus driven by driver (Task 9)
    std::vector<Student*> students = {&student};
    Student* found = CityOps::findStudentByAddress(students, address);
    assert(found == &student);
    assert(CityOps::isStudentOnBusDrivenBy(found, bus, &driver)); // Task 9 verified

    Driver otherDriver(50, "Mihai", false, true, address, 20, true);
    assert(!CityOps::isStudentOnBusDrivenBy(found, bus, &otherDriver));

    std::cout << "All automated tests passed successfully!\n\n";
}

int main()
{
    // Run automated verification tests initially
    runAutomatedTests();

    // Default simulation state that the user can manipulate or inspect
    Address defaultAddress("Calea Victoriei", "Bucharest", 42);
    Person person(35, "Ion Popescu", true, defaultAddress, true);
    Student student("Maria Ionescu", 20, 9.75, defaultAddress, false, true);
    Driver driver(48, "Vasile Soferu", false, true, defaultAddress, 18, true);
    Commuter commuter(24, "Andrei Calator", false, true, defaultAddress, true, false, "Centru");

    Apartment apartment(defaultAddress, 2, 60.0);
    person.setApartment(&apartment);
    apartment.setOwner(&person);

    Bus bus("Linia 100", 30, &driver);
    Car car(4, &driver);
    BusStation stationA("Gara de Nord");
    BusStation stationB("Piata Romana");

    Mosquito harmlessBug(false, "Culex");
    Mosquito deadlyBug(true, "Tigru Asiatic");

    std::vector<Student*> studentDirectory = {&student};

    bool running = true;
    while (running)
    {
        std::cout << "\n=================== Interactive Menu ===================\n"
                  << " [1] Inspect / Test Person, Commuter, Driver, Student\n"
                  << " [2] Inspect / Test Apartment (Address Composition)\n"
                  << " [3] Inspect / Test Car & Engine (Vericu Tuning)\n"
                  << " [4] Inspect / Test Mosquito (Bite Mechanics)\n"
                  << " --- TASKS 1 TO 9 ---\n"
                  << " [5] Task 1: Start Bus Engine (with / without driver)\n"
                  << " [6] Task 2: Count Commuters in Bus & BusStation\n"
                  << " [7] Task 3: Query Buses Stopping at a BusStation\n"
                  << " [8] Task 4: Query Stations Along a Bus Route\n"
                  << " [9] Task 5: Move Apartment from Person to Student\n"
                  << " [10] Task 6: Add Student to BusStation, Bus, and Car\n"
                  << " [11] Task 7: Move Mosquito from Apartment to Bus or Car\n"
                  << " [12] Task 8: Check if Specific Mosquito is in Bus, Car, or Apartment\n"
                  << " [13] Task 9: Find Student by Address & Check Bus Driver\n"
                  << " [14] Simulate Bus Mosquito Attack\n"
                  << " [15] Re-run All Automated Tests\n"
                  << " [0] Exit\n"
                  << "========================================================\n";

        int choice = getIntInput("Choose an option: ");
        std::cout << "\n";

        switch (choice)
        {
        case 1:
        {
            std::cout << "-- Person Info --\n";
            person.printStandardInfo();
            std::cout << "\n-- Student Info --\n";
            student.printStandardInfo();
            std::cout << "Average Grade: " << student.getAverageGrade() << "\n";
            std::cout << "\n-- Driver Info --\n";
            driver.printStandardInfo();
            std::cout << "\n-- Commuter Info --\n";
            commuter.printStandardInfo();
            break;
        }

        case 2:
        {
            std::cout << "-- Current Apartment Info --\n";
            apartment.printApartmentInfo();

            std::cout << "\nModify apartment address? (1 = Yes, 0 = No): ";
            int mod = getIntInput("");
            if (mod == 1)
            {
                std::string street = getStringInput("Enter new street: ");
                std::string city = getStringInput("Enter new city: ");
                int number = getIntInput("Enter street number: ");
                apartment.setAddress(Address(street, city, number));
                std::cout << "Updated apartment address successfully!\n";
                apartment.printApartmentInfo();
            }
            break;
        }

        case 3:
        {
            std::cout << "-- Car Info --\n";
            car.printVehicleInfo();
            std::cout << "Current Engine HP: " << car.getEngine().getHorsePower() << "\n";

            std::cout << "\nApply tuning? (1 = Stage 1, 2 = Stage 2, 3 = Stage 3, 0 = Skip): ";
            int stageChoice = getIntInput("");
            if (stageChoice == 1)
                car.getEngine().callVericuSoft(Engine::Stages::Stage1);
            else if (stageChoice == 2)
                car.getEngine().callVericuSoft(Engine::Stages::Stage2);
            else if (stageChoice == 3)
                car.getEngine().callVericuSoft(Engine::Stages::Stage3);

            car.getEngine().printEngineInfo();
            break;
        }

        case 4:
        {
            std::cout << "-- Mosquito Tests --\n"
                      << "1. Harmless mosquito (" << harmlessBug.getSpecies() << ")\n"
                      << "2. Deadly mosquito (" << deadlyBug.getSpecies() << ")\n";

            int bugChoice = getIntInput("Select mosquito to bite Person (1 or 2): ");
            Mosquito& selectedBug = (bugChoice == 2) ? deadlyBug : harmlessBug;

            std::cout << "Person before bite alive: " << (person.getIsAlive() ? "Yes" : "No") << "\n";
            selectedBug.bite(person);
            std::cout << "Person after bite alive: " << (person.getIsAlive() ? "Yes" : "No") << "\n";
            break;
        }

        case 5: // Task 1: Start Bus Engine
        {
            std::cout << "Task 1: Starting Bus Engine for " << bus.getBusLine() << "...\n";
            std::cout << "Driver currently assigned: "
                      << (bus.getDriver() != nullptr ? bus.getDriver()->getName() : "None") << "\n";

            int sub = getIntInput("Options: (1 = Start Bus, 2 = Stop Bus, 3 = Remove Driver & Try Start): ");
            if (sub == 1)
            {
                CityOps::startBusEngine(bus);
                std::cout << "Bus stationary status: " << (bus.getIsStationary() ? "Stationary" : "Moving") << "\n";
            }
            else if (sub == 2)
            {
                bus.stopBus();
                std::cout << "Bus stopped. Stationary: " << (bus.getIsStationary() ? "Yes" : "No") << "\n";
            }
            else if (sub == 3)
            {
                bus.setDriver(nullptr);
                CityOps::startBusEngine(bus);
                bus.setDriver(&driver); // restore driver
            }
            break;
        }

        case 6: // Task 2: Count commuters
        {
            std::cout << "Task 2: Commuter / Passenger Counts:\n"
                      << "  Passengers in Bus (" << bus.getBusLine() << "): "
                      << CityOps::getBusCommuterCount(bus) << "\n"
                      << "  Waiting at Station (" << stationA.getName() << "): "
                      << CityOps::getStationCommuterCount(stationA) << "\n";
            break;
        }

        case 7: // Task 3: Query buses stopping at a station
        {
            std::cout << "Task 3: Buses stopping at " << stationA.getName() << ":\n";
            stationA.printServicingBuses();

            std::cout << "Connect bus " << bus.getBusLine() << " to this station? (1 = Yes, 0 = No): ";
            int conn = getIntInput("");
            if (conn == 1)
            {
                stationA.addServicingBus(&bus);
                std::cout << "Connected! Re-checking station:\n";
                stationA.printServicingBuses();
            }
            break;
        }

        case 8: // Task 4: Query stations along bus route
        {
            std::cout << "Task 4: Stations where bus " << bus.getBusLine() << " will stop:\n";
            bus.printRoute();

            std::cout << "Add " << stationB.getName() << " to route? (1 = Yes, 0 = No): ";
            int conn = getIntInput("");
            if (conn == 1)
            {
                bus.addStationToRoute(&stationB);
                std::cout << "Added! Re-checking bus route:\n";
                bus.printRoute();
                std::cout << "Verified two-way sync at " << stationB.getName() << ":\n";
                stationB.printServicingBuses();
            }
            break;
        }

        case 9: // Task 5: Move apartment from Person to Student
        {
            std::cout << "Task 5: Moving Apartment from Person (" << person.getName()
                      << ") to Student (" << student.getName() << ")...\n";
            std::cout << "Before transfer:\n"
                      << "  Person owns: " << (person.getApartment() ? "Apartment present" : "None") << "\n"
                      << "  Student owns: " << (student.getApartment() ? "Apartment present" : "None") << "\n";

            bool ok = CityOps::moveApartment(&person, &student);
            std::cout << "Transfer result: " << (ok ? "Success!" : "Failed (Person had no apartment)") << "\n";
            std::cout << "After transfer:\n"
                      << "  Person owns: " << (person.getApartment() ? "Apartment present" : "None") << "\n"
                      << "  Student owns: " << (student.getApartment() ? "Apartment present" : "None") << "\n"
                      << "  Apartment owner pointer: "
                      << (apartment.getOwner() ? apartment.getOwner()->getName() : "None") << "\n";
            break;
        }

        case 10: // Task 6: Add Student to BusStation, Bus, Car
        {
            std::cout << "Task 6: Adding Student (" << student.getName() << ") to Station, Bus, and Car...\n";
            CityOps::addStudentToBusStation(stationA, &student);
            CityOps::addStudentToBus(bus, &student);
            CityOps::addStudentToCar(car, &student);

            std::cout << "Verification:\n"
                      << "  Station has student: " << (stationA.hasPassenger(&student) ? "Yes" : "No") << "\n"
                      << "  Bus has student: " << (bus.hasPassenger(&student) ? "Yes" : "No") << "\n"
                      << "  Car has student: " << (car.hasPassenger(&student) ? "Yes" : "No") << "\n";
            break;
        }

        case 11: // Task 7: Move Mosquito from Apartment to Bus or Car
        {
            std::cout << "Task 7: Move mosquito from Apartment to Bus or Car...\n";
            apartment.addMosquito(&deadlyBug);
            std::cout << "Added " << deadlyBug.getSpecies() << " to apartment.\n"
                      << "Apartment mosquito count: " << apartment.getMosquitoCount() << "\n";

            int dest = getIntInput("Move to where? (1 = Bus, 2 = Car): ");
            if (dest == 1)
            {
                bool ok = CityOps::moveMosquitoFromApartmentToBus(apartment, bus, &deadlyBug);
                std::cout << "Moved to bus: " << (ok ? "Yes" : "No") << "\n"
                          << "Apartment count: " << apartment.getMosquitoCount() << "\n"
                          << "Bus count: " << bus.getMosquitoCount() << "\n";
            }
            else
            {
                bool ok = CityOps::moveMosquitoFromApartmentToCar(apartment, car, &deadlyBug);
                std::cout << "Moved to car: " << (ok ? "Yes" : "No") << "\n"
                          << "Apartment count: " << apartment.getMosquitoCount() << "\n"
                          << "Car count: " << car.getMosquitoCount() << "\n";
            }
            break;
        }

        case 12: // Task 8: Is specific mosquito in Bus, Car, or Apartment
        {
            std::cout << "Task 8: Checking presence of mosquito (" << deadlyBug.getSpecies() << "):\n"
                      << "  In Apartment: " << (CityOps::isMosquitoInApartment(apartment, &deadlyBug) ? "Yes" : "No") << "\n"
                      << "  In Bus: " << (CityOps::isMosquitoInBus(bus, &deadlyBug) ? "Yes" : "No") << "\n"
                      << "  In Car: " << (CityOps::isMosquitoInCar(car, &deadlyBug) ? "Yes" : "No") << "\n";
            break;
        }

        case 13: // Task 9: Find Student by Address and check Bus Driver
        {
            std::cout << "Task 9: Searching for student living at: "
                      << defaultAddress.getStreet() << " " << defaultAddress.getStreetNumber() << "\n";

            Student* foundStudent = CityOps::findStudentByAddress(studentDirectory, defaultAddress);
            if (foundStudent != nullptr)
            {
                std::cout << "Found student: " << foundStudent->getName() << "\n";
                bool onBus = CityOps::isStudentOnBusDrivenBy(foundStudent, bus, &driver);
                std::cout << "Is student on bus driven by " << driver.getName() << "? "
                          << (onBus ? "YES" : "NO") << "\n";
            }
            else
            {
                std::cout << "No student found at that address.\n";
            }
            break;
        }

        case 14: // Mosquito attack simulation
        {
            std::cout << "Simulating mosquito attack inside bus " << bus.getBusLine() << "...\n";
            bus.mosquitoAttack(deadlyBug);
            break;
        }

        case 15: // Re-run tests
        {
            runAutomatedTests();
            break;
        }

        case 0:
            std::cout << "Exiting. Goodbye!\n";
            running = false;
            break;

        default:
            std::cout << "Unknown option: " << choice << ". Please select a valid number from the menu.\n";
            break;
        }
    }

    return 0;
}