#ifndef MASK_H
#define MASK_H

#include <array>
#include <vector>
#include <stdexcept>
#include <functional>
#include <type_traits>

template<size_t N>
class Mask
{
private:
    std::array<bool, N> maskData;

public:
    Mask(std::initializer_list<bool> maskList);

    size_t size() const;

    bool at(size_t index) const;

    template<typename Container>
    void slice(Container& container) const;

    template<typename Container, typename Func>
    Container transform(const Container& container, Func func) const;

    template<typename Container, typename Func>
    auto slice_and_transform(const Container& container, Func func) const;
};

#include "Mask.tpp"

#endif