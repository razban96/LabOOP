#pragma once

class complexNumber {
private:
    double realPart{};
    double imaginaryPart{};
public:
    explicit complexNumber(double real = 0, double imaginary = 0);
    ~complexNumber() = default;

    void printComplexNumber() const;
    double absoluteValue() const;
    static float absoluteValue(float const &x);
    static complexNumber sumOfComplexNumbers(complexNumber const &c1, complexNumber const &c2);
    static complexNumber productOfComplexNumbers(complexNumber const &c1, complexNumber const &c2);
};
