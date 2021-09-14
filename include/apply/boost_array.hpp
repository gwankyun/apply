#pragma once
#include "common.hpp"
#include <cstddef>
#include <boost/array.hpp>

namespace lite
{
    // boost::array
#ifndef APPLY_BOOST_GET
#  define APPLY_BOOST_GET(z, n, x) BOOST_PP_COMMA_IF(n) boost::get<n>(x)
#endif // !APPLY_BOOST_GET

    template<typename F, typename T, std::size_t N>
    inline typename boost::result_of<F(T)>::type apply(F f, boost::array<T, N>& array_)
    {
        return f(boost::get<0>(array_));
    }

    template<typename F, typename T, std::size_t N>
    inline typename boost::result_of<F(T)>::type apply(F f, const boost::array<T, N>& array_)
    {
        return f(boost::get<0>(array_));
    }

#ifndef ARRAY_BOOST_ARRAY
#  define ARRAY_BOOST_ARRAY(z, n, _) \
    template<typename F, typename T, std::size_t N> \
    inline typename boost::result_of<F(BOOST_PP_ENUM(n, APPLY_ARRAY_TYPE, T))>::type apply(F f, const boost::array<T, N>& array_) \
    { \
        return f(BOOST_PP_REPEAT_Z(z, n, APPLY_BOOST_GET, array_)); \
    }
    BOOST_PP_REPEAT_FROM_TO(2, 10, ARRAY_BOOST_ARRAY, _)
#endif
}
