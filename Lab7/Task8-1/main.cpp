#include <iostream>
#include "ComplexNumber.h"

int main() {
    ComplexNumber c1(3.0, 4.0);
    ComplexNumber c2(1.0, 2.0);

    ComplexNumber sum = c1 + c2;
    std::cout << "Suma (c1 + c2): ";
    sum.display();
    std::cout << std::endl;

    std::cout << "Modulul lui c1 (~c1): " << ~c1 << std::endl;

    ComplexNumber squared = c1 ^ 2;
    std::cout << "(c1 ^ 2): ";
    squared.display();
    std::cout << std::endl;

    if (c2 < c1) {
        std::cout << "c2 are modulul mai mic decat c1" << std::endl;
    }

    return 0;
}