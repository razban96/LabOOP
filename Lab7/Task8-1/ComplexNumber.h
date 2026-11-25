#pragma once

class ComplexNumber {

public:
    explicit ComplexNumber(double r = 0.0, double i = 0.0);

    // Getters
    [[nodiscard]] double getReal() const;
    [[nodiscard]] double getImag() const;
    [[nodiscard]] double getModule() const;

    // module
    double operator~() const;

    // arithmetic
    ComplexNumber& operator+=(const ComplexNumber& other);
    ComplexNumber operator+(ComplexNumber& other) const;
    ComplexNumber operator^(int power) const;

    // compare
    bool operator>(const ComplexNumber& other) const;
    bool operator<(const ComplexNumber& other) const;

    void display() const;

private:
    double m_real;
    double m_imag;

};