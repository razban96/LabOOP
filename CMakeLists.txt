cmake_minimum_required(VERSION 3.28)
project(LabOOP C CXX)

# Language Standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Strict Compiler Warnings
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic -Wshadow)
endif()

# ==========================================
# Target: Lab 1
# ==========================================
add_executable(Lab1
        Lab1/main.c
        Lab1/temp.c
        Lab1/temp.h
        Lab1/header1.h
        Lab1/header2.h
)
# Allows #include "header1.h" directly inside Lab1 files
target_include_directories(Lab1 PRIVATE Lab1)

# ==========================================
# Target: Lab 2
# ==========================================
# Target for Task 2.1/3.1 Rectangle
add_executable(task_2_1 Lab2_3/rectangle.cpp Lab2_3/rectangle.h)
target_include_directories(task_2_1 PRIVATE Lab2_3)
# Target for Task 2.2/3.5 ComplexNumber
add_executable(task_2_2 Lab2_3/complexNumber.cpp Lab2_3/complexNumber.h)
target_include_directories(task_2_2 PRIVATE Lab2_3)

add_executable(task4-5_2
        Lab4-5/Humans/Subcomponents/Address.h
        Lab4-5/Humans/Subcomponents/Address.cpp
        Lab4-5/Humans/Person.h
        Lab4-5/Humans/Person.cpp
        Lab4-5/Humans/Driver.cpp
        Lab4-5/Humans/Driver.h
        Lab4-5/Humans/Commuter.cpp
        Lab4-5/Humans/Commuter.h
        Lab4-5/Creatures/Mosquito.cpp
        Lab4-5/Creatures/Mosquito.h
        Lab4-5/Vehicles/Bus.cpp
        Lab4-5/Vehicles/Bus.h
        Lab4-5/main.cpp
        Lab4-5/Places/BusStation.cpp
        Lab4-5/Places/BusStation.h
        Lab4-5/Vehicles/Subcomponents/Engine.cpp
        Lab4-5/Vehicles/Subcomponents/Engine.h
        Lab4-5/Vehicles/Vehicle.cpp
        Lab4-5/Vehicles/Vehicle.h
        Lab4-5/Vehicles/Car.cpp
        Lab4-5/Vehicles/Car.h
        Lab4-5/Places/Apartment.cpp
        Lab4-5/Places/Apartment.h
        Lab4-5/Humans/Student.cpp
        Lab4-5/Humans/Student.h
        Lab4-5/CityOperations.cpp
        Lab4-5/CityOperations.h
)
target_include_directories(task4-5_2 PRIVATE Lab4-5)

add_executable(task6_1 Lab6/Group/Group.cpp Lab6/Group/Group.h
        Lab6/Group/main.cpp)
target_include_directories(task6_1 PRIVATE Lab6)
add_executable(task6_2 Lab6/CarDriver/Driver.cpp Lab6/CarDriver/Driver.h
        Lab6/CarDriver/Car.cpp
        Lab6/CarDriver/Car.h
        Lab6/CarDriver/RentalManagement.cpp)
