#pragma once
#include <string>

// forward declaration
class Car;

class Driver {
public:
    explicit Driver(std::string  name = "");
    ~Driver() = default;

    void setCar(Car* car);
    [[nodiscard]] Car* getCar() const;
    [[nodiscard]] const std::string& getName() const;

private:
    std::string m_name;
    Car* m_car{nullptr};
};