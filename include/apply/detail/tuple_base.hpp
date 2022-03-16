#pragma once
#include "common.hpp"

#if HAS_INCLUDE(tuple)
#  include <tuple> // std::tuple std::make_tuple std::get
#endif

namespace lite
{
    template<typename F, typename T0>
    inline auto apply(F&& f, std::tuple<T0>&& tuple_)
        ->RESULT_OF_T(F(T0))
    {
        return f(std::get<0>(tuple_));
    }

    template<typename F, typename T0, typename T1>
    inline auto apply(F&& f, std::tuple<T0, T1>&& tuple_)
        ->RESULT_OF_T(F(T0, T1))
    {
        return f(std::get<0>(tuple_), std::get<1>(tuple_));
    }

    template<typename F, typename T0, typename T1, typename T2>
    inline auto apply(F&& f, std::tuple<T0, T1, T2>&& tuple_)
        ->RESULT_OF_T(F(T0, T1, T2))
    {
        return f(std::get<0>(tuple_), std::get<1>(tuple_), std::get<2>(tuple_));
    }
}
