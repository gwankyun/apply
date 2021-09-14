#pragma once
#include "common.hpp"
#include <boost/tuple/tuple.hpp> // boost::tuple boost::get

namespace lite
{
    // boost::tuple
#ifndef APPLY_BOOST_GET
#  define APPLY_BOOST_GET(z, n, x) BOOST_PP_COMMA_IF(n) boost::get<n>(x)
#endif // !APPLY_BOOST_GET

    template<typename F, typename T0>
    inline RESULT_OF_T(F(T0)) apply(F f, boost::tuple<T0>& tuple_)
    {
        return f(boost::get<0>(tuple_));
    }

    template<typename F, typename T0>
    inline RESULT_OF_T(F(T0)) apply(F f, const boost::tuple<T0>& tuple_)
    {
        return f(boost::get<0>(tuple_));
    }

#ifndef APPLY_BOOST_TUPLE
#  define APPLY_BOOST_TUPLE(z, n, _) \
    template<typename F, BOOST_PP_REPEAT_Z(z, n, BOOST_PP_TYPENAME, T)> \
    inline RESULT_OF_T(F(BOOST_PP_REPEAT_Z(z, n, BOOST_PP_TYPE, T))) apply(F f, boost::tuple<BOOST_PP_REPEAT_Z(z, n, BOOST_PP_TYPE, T)> tuple_) \
    { \
        return f(BOOST_PP_REPEAT_Z(z, n, APPLY_BOOST_GET, tuple_)); \
    }
    BOOST_PP_REPEAT_FROM_TO(2, 10, APPLY_BOOST_TUPLE, _)
#endif
}
