#pragma once

class ComplexNumber {
public:
    explicit ComplexNumber(double r = 0.0, double i = 0.0);

    [[nodiscard]] double getModule() const;

    bool operator>(const ComplexNumber& other) const;

    void display() const;

private:
    double m_real;
    double m_imag;

};