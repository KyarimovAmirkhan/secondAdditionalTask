#ifndef MASK_TPP
#define MASK_TPP

#include "Mask.h"
#include <algorithm>

template<size_t N>
template<typename Container>
void Mask<N>::slice(Container& container) const
{
    using ValueType = typename Container::value_type;
    std::vector<ValueType> result;

    size_t containerSize = container.size();

    for (size_t i = 0; i < containerSize; ++i)
    {
        if (maskData[i % N])
        {
            result.push_back(container.at(i));
        }
    }

    container.clear();
    for (const auto& val : result)
    {
        container.push_back(val);
    }
}

template<size_t N>
template<typename Container, typename Func>
Container Mask<N>::transform(const Container& container, Func func) const
{
    Container result;

    size_t containerSize = container.size();

    for (size_t i = 0; i < containerSize; ++i)
    {
        if (maskData[i % N])
        {
            result.push_back(func(container.at(i)));
        }
        else
        {
            result.push_back(container.at(i));
        }
    }
    return result;
}

template<size_t N>
template<typename Container, typename Func>
auto Mask<N>::slice_and_transform(const Container& container, Func func) const
{
    using ValueType = typename Container::value_type;
    using ResultType = decltype(func(std::declval<ValueType>()));
    std::vector<ResultType> result;

    size_t containerSize = container.size();

    for (size_t i = 0; i < containerSize; ++i)
    {
        if (maskData[i % N])
        {
            result.push_back(func(container.at(i)));
        }
    }
    return result;
}

#endif