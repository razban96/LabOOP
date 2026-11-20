#pragma once

template <typename C, typename F>
class CompareNumbers {

public:
    CompareNumbers(C complexNr, F floatNr)
        : m_complex(complexNr), m_float(floatNr) {}

    [[nodiscard]] bool isComplexModuleGreater() const {
        return m_complex.getModule() > m_float;
    }

    [[nodiscard]] double getComplexModule() const {
        return m_complex.getModule();
    }

private:
    C m_complex;
    F m_float;

};