#include "CompareNumbers.h"
#include "../Task8-1/ComplexNumber.h"
#include <iostream>

int main() {
    ComplexNumber c(3.0, 4.0);
    float val = 4.2f;

    const CompareNumbers<ComplexNumber, float> comp(c, val);

    if (comp.isComplexModuleGreater()) {
        std::cout << "Modulul complex (" << comp.getComplexModule() 
                  << ") este mai mare decat " << val << std::endl;
    } else {
        std::cout << "Valoarea float este mai mare sau egala" << std::endl;
    }

    return 0;
}