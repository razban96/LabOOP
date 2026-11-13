#pragma once
#include <string>

// forward declaration
class Driver;

class Car {
public:
    explicit Car(std::string  model = "");
    ~Car() = default;

    void setDriver(Driver* driver);
    [[nodiscard]] Driver* getDriver() const;
    [[nodiscard]] const std::string& getModel() const;

private:
    std::string m_model;
    Driver* m_driver{nullptr};
};