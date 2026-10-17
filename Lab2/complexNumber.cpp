#include "complexNumber.h"
#include <cmath>
#include <iostream>

float absoluteValue(complexNumber const& nrcomplex) {
    return sqrt(nrcomplex.realPart * nrcomplex.realPart + nrcomplex.imaginaryPart * nrcomplex.imaginaryPart);
}
float absoluteValue(float const &x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

int main() {
    float realNum = -4.5f;
    std::cout << "Abs of real: " << absoluteValue(realNum) << '\n';

    complexNumber num{3.0, 4.0};
    std::cout << "Abs of complex: " << absoluteValue(num) << '\n';

    return 0;
}