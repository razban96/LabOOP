#include <iostream>
#include <vector>
#include "Person.h"
#include "Car.h"
#include "AverageCalculator.h"

int main() {
    std::vector<Person> people = { Person(25), Person(35), Person(45) };
    std::vector<Car> cars = { Car(3), Car(7), Car(10) };

    AverageCalculator<Person> personAvg(people);
    AverageCalculator<Car> carAvg(cars);

    std::cout << "Media varstei persoanelor: " << personAvg.computeAverage() << std::endl;
    std::cout << "Media vechimii masinilor: " << carAvg.computeAverage() << std::endl;

    return 0;
}