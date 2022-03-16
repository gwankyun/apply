#pragma once
#include "common.hpp"
#include <cstddef> // std::size_t
#include <boost/array.hpp>

namespace lite
{
    // boost::array
    template<typename F, typename T, std::size_t N>
    inline RESULT_OF_T(F(T)) apply(F f, boost::array<T, N>& array_)
    {
        return f(boost::get<0>(array_));
    }

    template<typename F, typename T, std::size_t N>
    inline RESULT_OF_T(F(T)) apply(F f, const boost::array<T, N>& array_)
    {
        return f(boost::get<0>(array_));
    }

    template<typename F, typename T, std::size_t N>
    inline RESULT_OF_T(F(T, T)) apply(F f, const boost::array<T, N>& array_)
    {
        return f(boost::get<0>(array_), boost::get<1>(array_));
    }

    template<typename F, typename T, std::size_t N>
    inline RESULT_OF_T(F(T, T, T)) apply(F f, const boost::array<T, N>& array_)
    {
        return f(boost::get<0>(array_), boost::get<1>(array_), boost::get<2>(array_));
    }
}
