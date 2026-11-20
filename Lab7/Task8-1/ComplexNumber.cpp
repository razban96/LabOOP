#include "ComplexNumber.h"
#include <cmath>
#include <complex>
#include <iostream>

ComplexNumber::ComplexNumber(const double r, const double i) : m_real(r), m_imag(i) {}

double ComplexNumber::getModule() const {
    return std::sqrt(m_real * m_real + m_imag * m_imag);
}

bool ComplexNumber::operator>(const ComplexNumber& other) const {
    return getModule() > other.getModule();
}

void ComplexNumber::display() const {
    std::cout << m_real << " + " << m_imag << "i";
}