#pragma once
#include "tuple_base.hpp"

namespace lite
{
    // std::tuple
#ifndef ARRAY_STD_TUPLE
#  define ARRAY_STD_TUPLE(z, n, _) \
    template<typename F, BOOST_PP_REPEAT_FROM_TO_Z(z, 0, n, BOOST_PP_TYPENAME, T)> \
    inline auto apply(F&& f, std::tuple<BOOST_PP_REPEAT_FROM_TO_Z(z, 0, n, BOOST_PP_TYPE, T)>&& tuple_) \
        ->RESULT_OF_T(F(BOOST_PP_REPEAT_FROM_TO_Z(z, 0, n, BOOST_PP_TYPE, T))) \
    { \
        return f(BOOST_PP_REPEAT_FROM_TO_Z(z, 0, n, APPLY_STD_GET, tuple_)); \
    }
    BOOST_PP_REPEAT_FROM_TO(4, 10, ARRAY_STD_TUPLE, _)
#endif
}

