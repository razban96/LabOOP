#include "complexNumber.h"
#include <cmath>
#include <iostream>

complexNumber::complexNumber(double const real, const double imaginary) {
    this->realPart = real;
    this->imaginaryPart = imaginary;
}

void complexNumber::printComplexNumber() const {
    std::cout << this->realPart << " + " << this->imaginaryPart << "i" << '\n';
}

double complexNumber::absoluteValue() const {
    return sqrt(this->realPart * this->realPart + this->imaginaryPart * this->imaginaryPart);
}

float complexNumber::absoluteValue(float const &x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

complexNumber complexNumber::sumOfComplexNumbers(complexNumber const &c1, complexNumber const &c2) {
    return complexNumber(c1.realPart + c2.realPart, c1.imaginaryPart + c2.imaginaryPart);
}

complexNumber complexNumber::productOfComplexNumbers(complexNumber const &c1, complexNumber const &c2) {
    return complexNumber(c1.realPart * c2.realPart - c1.imaginaryPart * c2.imaginaryPart,
                         c1.realPart * c2.imaginaryPart + c1.imaginaryPart * c2.realPart);
}

int main() {
    float realNum = -4.5f;
    std::cout << "Abs of real: " << complexNumber::absoluteValue(realNum) << '\n';

    complexNumber num(3.0, 4.0);
    complexNumber num2(4.0, 6.0);
    std::cout << "Abs of complex: " << num.absoluteValue() << '\n';

    complexNumber sum = complexNumber::sumOfComplexNumbers(num, num2);
    complexNumber product = complexNumber::productOfComplexNumbers(num, num2);

    std::cout << "Product of complex: ";
    sum.printComplexNumber();
    std::cout << "Abs of complex: ";
    product.printComplexNumber();

    return 0;
}
