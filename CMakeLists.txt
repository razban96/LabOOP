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

add_executable(task4_2
        Lab4/Address.h
        Lab4/Address.cpp
        Lab4/Person.h
        Lab4/Person.cpp
        Lab4/Driver.cpp
        Lab4/Driver.h
        Lab4/Commuter.cpp
        Lab4/Commuter.h
        Lab4/Mosquito.cpp
        Lab4/Mosquito.h
        Lab4/Bus.cpp
        Lab4/Bus.h
        Lab4/main.cpp
        Lab4/BusStation.cpp
        Lab4/BusStation.h
)
target_include_directories(task4_2 PRIVATE Lab4)