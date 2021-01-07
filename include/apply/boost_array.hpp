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

    template<typename F, typename T, std::size_t N>
    inline typename boost::result_of<F(BOOST_PP_ENUM(2, APPLY_ARRAY_TYPE, T))>::type apply(F f, boost::array<T, N>& array_)
    {
        return f(BOOST_PP_REPEAT(2, APPLY_BOOST_GET, array_));
    }

    template<typename F, typename T, std::size_t N>
    inline typename boost::result_of<F(BOOST_PP_ENUM(2, APPLY_ARRAY_TYPE, T))>::type apply(F f, const boost::array<T, N>& array_)
    {
        return f(BOOST_PP_REPEAT(2, APPLY_BOOST_GET, array_));
    }

    template<typename F, typename T, std::size_t N>
    inline typename boost::result_of<F(BOOST_PP_ENUM(3, APPLY_ARRAY_TYPE, T))>::type apply(F f, boost::array<T, N>& array_)
    {
        return f(BOOST_PP_REPEAT(3, APPLY_BOOST_GET, array_));
    }

    template<typename F, typename T, std::size_t N>
    inline typename boost::result_of<F(BOOST_PP_ENUM(3, APPLY_ARRAY_TYPE, T))>::type apply(F f, const boost::array<T, N>& array_)
    {
        return f(BOOST_PP_REPEAT(3, APPLY_BOOST_GET, array_));
    }

    template<typename F, typename T, std::size_t N>
    inline typename boost::result_of<F(BOOST_PP_ENUM(4, APPLY_ARRAY_TYPE, T))>::type apply(F f, boost::array<T, N>& array_)
    {
        return f(BOOST_PP_REPEAT(4, APPLY_BOOST_GET, array_));
    }

    template<typename F, typename T, std::size_t N>
    inline typename boost::result_of<F(BOOST_PP_ENUM(4, APPLY_ARRAY_TYPE, T))>::type apply(F f, const boost::array<T, N>& array_)
    {
        return f(BOOST_PP_REPEAT(4, APPLY_BOOST_GET, array_));
    }

    template<typename F, typename T, std::size_t N>
    inline typename boost::result_of<F(BOOST_PP_ENUM(5, APPLY_ARRAY_TYPE, T))>::type apply(F f, boost::array<T, N>& array_)
    {
        return f(BOOST_PP_REPEAT(5, APPLY_BOOST_GET, array_));
    }

    template<typename F, typename T, std::size_t N>
    inline typename boost::result_of<F(BOOST_PP_ENUM(5, APPLY_ARRAY_TYPE, T))>::type apply(F f, const boost::array<T, N>& array_)
    {
        return f(BOOST_PP_REPEAT(5, APPLY_BOOST_GET, array_));
    }

    template<typename F, typename T, std::size_t N>
    inline typename boost::result_of<F(BOOST_PP_ENUM(6, APPLY_ARRAY_TYPE, T))>::type apply(F f, boost::array<T, N>& array_)
    {
        return f(BOOST_PP_REPEAT(6, APPLY_BOOST_GET, array_));
    }

    template<typename F, typename T, std::size_t N>
    inline typename boost::result_of<F(BOOST_PP_ENUM(6, APPLY_ARRAY_TYPE, T))>::type apply(F f, const boost::array<T, N>& array_)
    {
        return f(BOOST_PP_REPEAT(6, APPLY_BOOST_GET, array_));
    }

    template<typename F, typename T, std::size_t N>
    inline typename boost::result_of<F(BOOST_PP_ENUM(7, APPLY_ARRAY_TYPE, T))>::type apply(F f, boost::array<T, N>& array_)
    {
        return f(BOOST_PP_REPEAT(7, APPLY_BOOST_GET, array_));
    }

    template<typename F, typename T, std::size_t N>
    inline typename boost::result_of<F(BOOST_PP_ENUM(7, APPLY_ARRAY_TYPE, T))>::type apply(F f, const boost::array<T, N>& array_)
    {
        return f(BOOST_PP_REPEAT(7, APPLY_BOOST_GET, array_));
    }

    template<typename F, typename T, std::size_t N>
    inline typename boost::result_of<F(BOOST_PP_ENUM(8, APPLY_ARRAY_TYPE, T))>::type apply(F f, boost::array<T, N>& array_)
    {
        return f(BOOST_PP_REPEAT(8, APPLY_BOOST_GET, array_));
    }

    template<typename F, typename T, std::size_t N>
    inline typename boost::result_of<F(BOOST_PP_ENUM(8, APPLY_ARRAY_TYPE, T))>::type apply(F f, const boost::array<T, N>& array_)
    {
        return f(BOOST_PP_REPEAT(8, APPLY_BOOST_GET, array_));
    }

    template<typename F, typename T, std::size_t N>
    inline typename boost::result_of<F(BOOST_PP_ENUM(9, APPLY_ARRAY_TYPE, T))>::type apply(F f, boost::array<T, N>& array_)
    {
        return f(BOOST_PP_REPEAT(9, APPLY_BOOST_GET, array_));
    }

    template<typename F, typename T, std::size_t N>
    inline typename boost::result_of<F(BOOST_PP_ENUM(9, APPLY_ARRAY_TYPE, T))>::type apply(F f, const boost::array<T, N>& array_)
    {
        return f(BOOST_PP_REPEAT(9, APPLY_BOOST_GET, array_));
    }
}
