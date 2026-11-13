#include "Car.h"
#include "Driver.h"
#include <iostream>
#include <vector>

class RentalManagement
{
  public:
    RentalManagement() = default;
    ~RentalManagement() = default;

    void addPair(Car* car, Driver* driver)
    {
        if (car && driver)
        {
            car->setDriver(driver);
            m_cars.emplace_back(car);
            m_drivers.emplace_back(driver);
        }
    }

    void addCar(Car* car)
    {
        if (car)
        {
            m_cars.emplace_back(car);
        }
    }

    void displayAll() const
    {
        std::cout << "Total Cars Managed: " << m_cars.size() << "\n";
        for (const Car* car : m_cars)
        {
            std::cout << "Car: " << car->getModel();
            if (car->getDriver() != nullptr)
            {
                std::cout << " driven by " << car->getDriver()->getName();
            }
            else
            {
                std::cout << " has no driver";
            }
            std::cout << "\n";
        }
    }

  private:
    std::vector<Car*> m_cars{};
    std::vector<Driver*> m_drivers{};
};

int main()
{
    Car c1("BMW Seria 1");
    Car c2("Passerati");
    Car c3("Dacia Golan");

    Driver d1("Cristi Popesco");
    Driver d2("Emma Sturbare");

    RentalManagement rental;

    rental.addPair(&c1, &d1);
    rental.addPair(&c2, &d2);
    rental.addCar(&c3);

    rental.displayAll();

    return 0;
}