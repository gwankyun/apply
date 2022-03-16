#pragma once
#include "boost_tuple_base.hpp"

namespace lite
{
    // boost::tuple
#ifndef APPLY_BOOST_GET
#  define APPLY_BOOST_GET(z, n, x) BOOST_PP_COMMA_IF(n) boost::get<n>(x)
#endif

#ifndef APPLY_BOOST_TUPLE
#  define APPLY_BOOST_TUPLE(z, n, _) \
    template<typename F, BOOST_PP_REPEAT_FROM_TO_Z(z, 0, n, BOOST_PP_TYPENAME, T)> \
    inline RESULT_OF_T(F(BOOST_PP_REPEAT_FROM_TO_Z(z, 0, n, BOOST_PP_TYPE, T))) apply(\
        F f, boost::tuple<BOOST_PP_REPEAT_FROM_TO_Z(z, 0, n, BOOST_PP_TYPE, T)> tuple_) \
    { \
        return f(BOOST_PP_REPEAT_FROM_TO_Z(z, 0, n, APPLY_BOOST_GET, tuple_)); \
    }
    BOOST_PP_REPEAT_FROM_TO(4, 10, APPLY_BOOST_TUPLE, _)
#endif
}
