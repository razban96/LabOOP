# Lab 4-5: City Simulation (C++ OOP)

An object-oriented city simulation in C++20 that models people, vehicles, places and mosquitoes, and the relationships between them.

## About

This lab demonstrates core OOP concepts: inheritance, composition, aggregation, encapsulation, and two-way associations between objects. The model contains people (`Person`, `Student`, `Driver`, `Commuter`), vehicles (`Vehicle`, `Bus`, `Car`, `Engine`), places (`Apartment`, `BusStation`), and `Mosquito` creatures that can bite people. Nine tasks are implemented as free functions in the `CityOps` namespace and can be exercised through an interactive console menu.

## Getting Started

### Prerequisites

- A C++20 compiler (GCC, Clang or MSVC)
- CMake >= 3.28

### Build

From the repository root (`LabOOP`), the lab is the `task4-5_2` target:

```bash
cmake -S . -B cmake-build-debug
cmake --build cmake-build-debug --target task4-5_2
```

### Run

```bash
./cmake-build-debug/task4-5_2        # Linux / macOS
.\cmake-build-debug\task4-5_2.exe    # Windows
```

## Usage

On start-up the program runs the automated assertion tests (`runAutomatedTests`), prints a success message, and then opens an interactive menu:

```
[1]  Inspect / Test Person, Commuter, Driver, Student
[2]  Inspect / Test Apartment (Address composition)
[3]  Inspect / Test Car & Engine (Vericu tuning)
[4]  Inspect / Test Mosquito (bite mechanics)
[5]  Task 1: Start Bus Engine
...
[13] Task 9: Find Student by Address & Check Bus Driver
[14] Simulate Bus Mosquito Attack
[15] Re-run All Automated Tests
[0]  Exit
```

Enter the number of an option and press Enter. Invalid input is rejected and re-prompted.

## Tasks

All tasks are declared in `CityOperations.h` and implemented in `CityOperations.cpp`.

| # | Description | Functions |
|---|-------------|-----------|
| 1 | Start a bus engine | `startBusEngine` |
| 2 | Count commuters in a bus / bus station | `getBusCommuterCount`, `getStationCommuterCount` |
| 3 | Buses stopping at a bus station | `getBusesStoppingAt` |
| 4 | Stations a bus will stop at | `getStationsForBus` |
| 5 | Move an apartment from a person to a student | `moveApartment` |
| 6 | Add a student to a bus station, bus and car | `addStudentToBusStation`, `addStudentToBus`, `addStudentToCar` |
| 7 | Move a mosquito from an apartment to a bus or car | `moveMosquitoFromApartmentToBus`, `moveMosquitoFromApartmentToCar` |
| 8 | Is a specific mosquito in a bus, car or apartment | `isMosquitoInApartment`, `isMosquitoInBus`, `isMosquitoInCar` |
| 9 | Find a student by address and check whether they are on a bus driven by a given driver | `findStudentByAddress`, `isStudentOnBusDrivenBy` |

## Project Structure

```
Lab4-5/
├── main.cpp                  # Automated tests + interactive menu
├── CityOperations.h/.cpp     # Tasks 1-9 (namespace CityOps)
├── Creatures/
│   └── Mosquito              # Species, deadly flag, bite(Person&)
├── Humans/
│   ├── Person                # Base class: age, name, address, apartment, alive state
│   ├── Student               # Person + average grade
│   ├── Driver                # Person + years of experience, license
│   ├── Commuter              # Person + ticket / subscription / destination
│   └── Subcomponents/
│       └── Address           # Street, city, street number
├── Places/
│   ├── Apartment             # Address, rooms, area, owner, mosquitoes
│   └── BusStation            # Waiting passengers, servicing buses
└── Vehicles/
    ├── Vehicle               # Base class for vehicles
    ├── Bus                   # Line, capacity, driver, passengers, route
    ├── Car                   # Seats, driver, passengers
    └── Subcomponents/
        └── Engine            # Horse power, tuning stages
```

## Key Design Notes

- **Composition:** `Person` and `Apartment` own an `Address`; `Car` owns an `Engine`.
- **Inheritance:** `Student`, `Driver` and `Commuter` extend `Person`; `Bus` and `Car` extend `Vehicle`.
- **Two-way association:** adding a station to a bus route (`Bus::addStationToRoute`) also registers the bus at that station, so both sides stay consistent.
- **Engine tuning:** `Engine::callVericuSoft` accepts `Engine::Stages::Stage1`, `Stage2` or `Stage3` to raise horse power.
- **Mosquitoes:** a deadly mosquito kills an allergic person on `bite`; a harmless one does not.

## Testing

Tests are plain `assert` checks in `runAutomatedTests()` covering every class and each of the nine tasks. They run automatically on every launch, or via menu option `[15]`. Build in a configuration where `NDEBUG` is not defined (e.g. Debug) so the assertions are active.
