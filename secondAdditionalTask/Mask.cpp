#include "Mask.h"
#include <algorithm>


template<size_t N>
Mask<N>::Mask(std::initializer_list<bool> maskList)
{
    if (maskList.size() != N)
    {
        throw std::invalid_argument("Несоответствие размера маски");
    }

    std::copy(maskList.begin(), maskList.end(), maskData.begin());

    for (bool val : maskData)
    {
        if (val != 0 && val != 1)
        {
            throw std::invalid_argument("Маска может содержать только 0 и 1");
        }
    }
}


template<size_t N>
size_t Mask<N>::size() const
{
    return N;
}

template<size_t N>
bool Mask<N>::at(size_t index) const
{
    if (index >= N)
    {
        throw std::out_of_range("Индекс маски выходит за пределы допустимого диапазона");
    }
    return maskData[index];
}

template class Mask<3>;
template class Mask<4>;
template class Mask<2>;