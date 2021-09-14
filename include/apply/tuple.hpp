#pragma once
#include "common.hpp"

#if HAS_INCLUDE(tuple)
#  include <tuple> // std::tuple std::make_tuple std::get
#endif

namespace lite
{
    // std::tuple
#  ifndef APPLY_STD_GET
#    define APPLY_STD_GET(z, n, x) BOOST_PP_COMMA_IF(n) std::get<n>(x)
#  endif

    template<typename F, typename T0>
    inline auto apply(F&& f, std::tuple<T0>&& tuple_)
        ->RESULT_OF_T(F(T0))
    {
        return f(std::get<0>(tuple_));
    }

#ifndef ARRAY_STD_TUPLE
#  define ARRAY_STD_TUPLE(z, n, _) \
    template<typename F, BOOST_PP_REPEAT_Z(z, n, BOOST_PP_TYPENAME, T)> \
    inline auto apply(F&& f, std::tuple<BOOST_PP_REPEAT_Z(z, n, BOOST_PP_TYPE, T)>&& tuple_) \
        ->RESULT_OF_T(F(BOOST_PP_REPEAT_Z(z, n, BOOST_PP_TYPE, T))) \
    { \
        return f(BOOST_PP_REPEAT_Z(z, n, APPLY_STD_GET, tuple_)); \
    }
    BOOST_PP_REPEAT_FROM_TO(2, 10, ARRAY_STD_TUPLE, _)
#endif
}
