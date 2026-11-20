#pragma once

template <typename T>
class MinElement {
public:
    MinElement(T first, T second) : m_a(first), m_b(second) {}

    T getMin() {
        return m_a > m_b ? m_b : m_a;
    }
private:
    T m_a;
    T m_b;
};