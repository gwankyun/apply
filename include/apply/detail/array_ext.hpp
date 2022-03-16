#pragma once
#include "array_base.hpp"

namespace lite
{
#ifndef ARRAY_STD_ARRAY
#  define ARRAY_STD_ARRAY(z, n, _) \
    template<typename F, typename T, std::size_t N> \
    inline auto apply(F&& f, std::array<T, N>& array_) -> RESULT_OF_T(F(BOOST_PP_ENUM(n, APPLY_ARRAY_TYPE, T))) \
    { \
        return f(BOOST_PP_REPEAT_Z(z, n, APPLY_STD_GET, array_)); \
    }
    BOOST_PP_REPEAT_FROM_TO(4, 10, ARRAY_STD_ARRAY, _)
#endif
}
