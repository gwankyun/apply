#pragma once
#include "common.hpp"
#include <cstddef>

#if HAS_INCLUDE(array)
#  include <array> // std::array
#endif

namespace lite
{
    // std::array
    template<typename F, typename T, std::size_t N>
    inline auto apply(F&& f, std::array<T, N>&& array_)->RESULT_OF_T(F(T))
    {
        return f(std::get<0>(array_));
    }

    template<typename F, typename T, std::size_t N>
    inline auto apply(F&& f, std::array<T, N>& array_)->RESULT_OF_T(F(T))
    {
        return f(std::get<0>(array_));
    }

    template<typename F, typename T, std::size_t N>
    inline auto apply(F&& f, std::array<T, N>& array_)->RESULT_OF_T(F(T, T))
    {
        return f(std::get<0>(array_), std::get<1>(array_));
    }

    template<typename F, typename T, std::size_t N>
    inline auto apply(F&& f, std::array<T, N>& array_)->RESULT_OF_T(F(T, T, T))
    {
        return f(std::get<0>(array_), std::get<1>(array_), std::get<2>(array_));
    }
}
