#include "ComplexNumber.h"
#include <iostream>
#include <cmath>

ComplexNumber::ComplexNumber(const double r, const double i)
    : m_real(r), m_imag(i) {}

double ComplexNumber::getReal() const { return m_real; }
double ComplexNumber::getImag() const { return m_imag; }

double ComplexNumber::getModule() const {
    return std::sqrt(m_real * m_real + m_imag * m_imag);
}

// module
double ComplexNumber::operator~() const {
    return getModule();
}

// add to
ComplexNumber& ComplexNumber::operator+=(const ComplexNumber& other)
{
    m_real += other.m_real;
    m_imag += other.m_imag;
    return *this;
}

// add two
ComplexNumber ComplexNumber::operator+(ComplexNumber& other) const {
    other += *this;
    return other;
}

// power
ComplexNumber ComplexNumber::operator^(const int power) const {
    if (power == 2) {
        // (a + bi)^2 = (a^2 - b^2) + (2ab)i
        return ComplexNumber(m_real * m_real - m_imag * m_imag, 2 * m_real * m_imag);
    }

    return *this;
}

// module comparison
bool ComplexNumber::operator>(const ComplexNumber& other) const {
    return getModule() > other.getModule();
}
bool ComplexNumber::operator<(const ComplexNumber& other) const {
    return getModule() < other.getModule();
}

void ComplexNumber::display() const {
    std::cout << m_real << " + " << m_imag << "i";
}