#pragma once
#include "common.hpp"
#include <cstddef>

#if HAS_INCLUDE(array)
#  include <array> // std::array
#endif // HAS_INCLUDE(array)

namespace lite
{
#if APPLY_HAS_CXX_11
    // std::array
#  ifndef APPLY_ARRAY_TYPE
#    define APPLY_ARRAY_TYPE(z, n, x) x
#  endif // !APPLY_ARRAY_TYPE

    template<typename F, typename T, std::size_t N>
    inline auto apply(F&& f, std::array<T, N>&& array_)
        -> ENABLE_IF_T(
            !IS_SAME_V(RESULT_OF_T(F(T)), VOID_T),
            RESULT_OF_T(F(T))
        )
    {
        return f(std::get<0>(array_));
    }

    template<typename F, typename T, std::size_t N>
    inline auto apply(F&& f, std::array<T, N>& array_) -> typename boost::result_of<F(T)>::type
    {
        return f(std::get<0>(array_));
    }

    template<typename F, typename T, std::size_t N>
    inline auto apply(F&& f, std::array<T, N>&& array_) -> typename boost::result_of<F(BOOST_PP_ENUM(2, APPLY_ARRAY_TYPE, T))>::type
    {
        return f(BOOST_PP_REPEAT(2, APPLY_STD_GET, array_));
    }

    template<typename F, typename T, std::size_t N>
    inline auto apply(F&& f, std::array<T, N>& array_) -> typename boost::result_of<F(BOOST_PP_ENUM(2, APPLY_ARRAY_TYPE, T))>::type
    {
        return f(BOOST_PP_REPEAT(2, APPLY_STD_GET, array_));
    }

    template<typename F, typename T, std::size_t N>
    inline auto apply(F&& f, std::array<T, N>&& array_) -> typename boost::result_of<F(BOOST_PP_ENUM(3, APPLY_ARRAY_TYPE, T))>::type
    {
        return f(BOOST_PP_REPEAT(3, APPLY_STD_GET, array_));
    }

    template<typename F, typename T, std::size_t N>
    inline auto apply(F&& f, std::array<T, N>& array_) -> typename boost::result_of<F(BOOST_PP_ENUM(3, APPLY_ARRAY_TYPE, T))>::type
    {
        return f(BOOST_PP_REPEAT(3, APPLY_STD_GET, array_));
    }

    template<typename F, typename T, std::size_t N>
    inline auto apply(F&& f, std::array<T, N>&& array_) -> typename boost::result_of<F(BOOST_PP_ENUM(4, APPLY_ARRAY_TYPE, T))>::type
    {
        return f(BOOST_PP_REPEAT(4, APPLY_STD_GET, array_));
    }

    template<typename F, typename T, std::size_t N>
    inline auto apply(F&& f, std::array<T, N>& array_) -> typename boost::result_of<F(BOOST_PP_ENUM(4, APPLY_ARRAY_TYPE, T))>::type
    {
        return f(BOOST_PP_REPEAT(4, APPLY_STD_GET, array_));
    }

    template<typename F, typename T, std::size_t N>
    inline auto apply(F&& f, std::array<T, N>&& array_) -> typename boost::result_of<F(BOOST_PP_ENUM(5, APPLY_ARRAY_TYPE, T))>::type
    {
        return f(BOOST_PP_REPEAT(5, APPLY_STD_GET, array_));
    }

    template<typename F, typename T, std::size_t N>
    inline auto apply(F&& f, std::array<T, N>& array_) -> typename boost::result_of<F(BOOST_PP_ENUM(5, APPLY_ARRAY_TYPE, T))>::type
    {
        return f(BOOST_PP_REPEAT(5, APPLY_STD_GET, array_));
    }

    template<typename F, typename T, std::size_t N>
    inline auto apply(F&& f, std::array<T, N>&& array_) -> typename boost::result_of<F(BOOST_PP_ENUM(6, APPLY_ARRAY_TYPE, T))>::type
    {
        return f(BOOST_PP_REPEAT(6, APPLY_STD_GET, array_));
    }

    template<typename F, typename T, std::size_t N>
    inline auto apply(F&& f, std::array<T, N>& array_) -> typename boost::result_of<F(BOOST_PP_ENUM(6, APPLY_ARRAY_TYPE, T))>::type
    {
        return f(BOOST_PP_REPEAT(6, APPLY_STD_GET, array_));
    }

    template<typename F, typename T, std::size_t N>
    inline auto apply(F&& f, std::array<T, N>&& array_) -> typename boost::result_of<F(BOOST_PP_ENUM(7, APPLY_ARRAY_TYPE, T))>::type
    {
        return f(BOOST_PP_REPEAT(7, APPLY_STD_GET, array_));
    }

    template<typename F, typename T, std::size_t N>
    inline auto apply(F&& f, std::array<T, N>& array_) -> typename boost::result_of<F(BOOST_PP_ENUM(7, APPLY_ARRAY_TYPE, T))>::type
    {
        return f(BOOST_PP_REPEAT(7, APPLY_STD_GET, array_));
    }

    template<typename F, typename T, std::size_t N>
    inline auto apply(F&& f, std::array<T, N>&& array_) -> typename boost::result_of<F(BOOST_PP_ENUM(8, APPLY_ARRAY_TYPE, T))>::type
    {
        return f(BOOST_PP_REPEAT(8, APPLY_STD_GET, array_));
    }

    template<typename F, typename T, std::size_t N>
    inline auto apply(F&& f, std::array<T, N>& array_) -> typename boost::result_of<F(BOOST_PP_ENUM(8, APPLY_ARRAY_TYPE, T))>::type
    {
        return f(BOOST_PP_REPEAT(8, APPLY_STD_GET, array_));
    }

    template<typename F, typename T, std::size_t N>
    inline auto apply(F&& f, std::array<T, N>&& array_) -> typename boost::result_of<F(BOOST_PP_ENUM(9, APPLY_ARRAY_TYPE, T))>::type
    {
        return f(BOOST_PP_REPEAT(9, APPLY_STD_GET, array_));
    }

    template<typename F, typename T, std::size_t N>
    inline auto apply(F&& f, std::array<T, N>& array_) -> typename boost::result_of<F(BOOST_PP_ENUM(9, APPLY_ARRAY_TYPE, T))>::type
    {
        return f(BOOST_PP_REPEAT(9, APPLY_STD_GET, array_));
    }
#endif // APPLY_HAS_CXX_11
}
