#pragma once
#include <vector>

template <typename T> class AverageCalculator
{
  public:
    AverageCalculator(const std::vector<T>& elements) : m_elements(elements) {}

    [[nodiscard]] double computeAverage() const
    {
        if (m_elements.empty())
        {
            return 0.0;
        }

        double sum = 0.0;
        for (auto& element : m_elements)
        {
            sum += element.getAge();
        }
        return sum / m_elements.size();
    }

  private:
    std::vector<T> m_elements;
};