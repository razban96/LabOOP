#pragma once
#include <iostream>

// Interfata
class Shape {
public:
    virtual void draw() = 0; // Metoda virtuala pura
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "circle\n";
    }
};

class Triangle : public Shape {
public:
    void draw() override {
        std::cout << "triangle\n";
    }
};
