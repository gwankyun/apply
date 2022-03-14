#pragma once
#include "common.hpp"
#include <boost/tuple/tuple.hpp> // boost::tuple boost::get

namespace lite
{
    // boost::tuple
#ifndef APPLY_BOOST_GET
#  define APPLY_BOOST_GET(z, n, x) BOOST_PP_COMMA_IF(n) boost::get<n>(x)
#endif

    template<typename F, typename T0>
    inline RESULT_OF_T(F(T0)) apply(F f, const boost::tuple<T0>& tuple_)
    {
        return f(boost::get<0>(tuple_));
    }

    template<typename F, typename T0, typename T1>
    inline RESULT_OF_T(F(T0, T1)) apply(F f, const boost::tuple<T0, T1>& tuple_)
    {
        return f(boost::get<0>(tuple_), boost::get<1>(tuple_));
    }

    template<typename F, typename T0, typename T1, typename T2>
    inline RESULT_OF_T(F(T0, T1, T2)) apply(F f, const boost::tuple<T0, T1, T2>& tuple_)
    {
        return f(boost::get<0>(tuple_), boost::get<1>(tuple_), boost::get<2>(tuple_));
    }
}
