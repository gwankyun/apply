#pragma once
#include "boost_array_base.hpp"

namespace lite
{
    // boost::array
#ifndef APPLY_BOOST_GET
#  define APPLY_BOOST_GET(z, n, x) BOOST_PP_COMMA_IF(n) boost::get<n>(x)
#endif

#ifndef ARRAY_BOOST_ARRAY
#  define ARRAY_BOOST_ARRAY(z, n, _) \
    template<typename F, typename T, std::size_t N> \
    inline RESULT_OF_T(F(BOOST_PP_ENUM(n, APPLY_ARRAY_TYPE, T))) apply(F f, const boost::array<T, N>& array_) \
    { \
        return f(BOOST_PP_REPEAT_FROM_TO_Z(z, 0, n, APPLY_BOOST_GET, array_)); \
    }
BOOST_PP_REPEAT_FROM_TO(4, 10, ARRAY_BOOST_ARRAY, _)
#endif
}
