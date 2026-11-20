#pragma once
#include <cstddef>

template <typename T> T getMaximumElement(const T elementsList[], const size_t n)
{
    if (n == 0)
    {
        return T();
    }
    T selectedElement = elementsList[0];

    for (size_t i = 1; i < n; ++i)
    {
        if (selectedElement < elementsList[i])
        {
            selectedElement = elementsList[i];
        }
    }
    return selectedElement;
}