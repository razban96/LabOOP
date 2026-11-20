#include <iostream>
#include "ComplexNumber.h"
#include "MinElement.h"

int main() {
    ComplexNumber c1(3.0, 4.0);  // Modul 5
    ComplexNumber c2(1.0, 1.0);  // Modul 1.41

    MinElement<ComplexNumber> helper(c1, c2);
    ComplexNumber minVal = helper.getMin();

    std::cout << "Numarul mai apropiat de origine este: ";
    minVal.display();
    std::cout << std::endl;

    return 0;
}