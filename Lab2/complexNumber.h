#pragma once
struct complexNumber {
    double realPart{};
    double imaginaryPart{};
};

float absoluteValue(complexNumber const& nrcomplex);
float absoluteValue(float const & x);