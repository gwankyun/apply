#pragma once
#include "common.hpp"

#if HAS_INCLUDE(tuple)
#  include <tuple> // std::tuple std::make_tuple std::get
#endif // HAS_INCLUDE(tuple)

namespace lite
{
#if APPLY_HAS_CXX_11
    // std::tuple
#  ifndef APPLY_STD_GET
#    define APPLY_STD_GET(z, n, x) BOOST_PP_COMMA_IF(n) std::get<n>(x)
#  endif // !APPLY_STD_GET

    template<typename F, typename T0>
    inline auto apply(F&& f, std::tuple<T0>&& tuple_)
        -> ENABLE_IF_T(
            !IS_SAME_V(RESULT_OF_T(F(T0)), VOID_T),
            RESULT_OF_T(F(T0))
        )
    {
        return f(std::get<0>(tuple_));
    }

    template<typename F, typename T0>
    inline auto apply(F&& f, std::tuple<T0>&& tuple_)
        -> ENABLE_IF_T(
            IS_SAME_V(RESULT_OF_T(F(T0)), VOID_T),
            VOID_T
        )
    {
        f(std::get<0>(tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(2, BOOST_PP_TYPENAME, T)>
    inline auto apply(F&& f, std::tuple<BOOST_PP_REPEAT(2, BOOST_PP_TYPE, T)>&& tuple_)
        -> ENABLE_IF_T(
            !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(2, BOOST_PP_TYPE, T))), VOID_T),
            RESULT_OF_T(F(BOOST_PP_REPEAT(2, BOOST_PP_TYPE, T)))
        )
    {
        return f(BOOST_PP_REPEAT(2, APPLY_STD_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(2, BOOST_PP_TYPENAME, T)>
    inline auto apply(F&& f, std::tuple<BOOST_PP_REPEAT(2, BOOST_PP_TYPE, T)>&& tuple_)
        -> ENABLE_IF_T(
            IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(2, BOOST_PP_TYPE, T))), VOID_T),
            VOID_T
        )
    {
        f(BOOST_PP_REPEAT(2, APPLY_STD_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(3, BOOST_PP_TYPENAME, T)>
    inline auto apply(F&& f, std::tuple<BOOST_PP_REPEAT(3, BOOST_PP_TYPE, T)>&& tuple_)
        -> ENABLE_IF_T(
            !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(3, BOOST_PP_TYPE, T))), VOID_T),
            RESULT_OF_T(F(BOOST_PP_REPEAT(3, BOOST_PP_TYPE, T)))
        )
    {
        return f(BOOST_PP_REPEAT(3, APPLY_STD_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(3, BOOST_PP_TYPENAME, T)>
    inline auto apply(F&& f, std::tuple<BOOST_PP_REPEAT(3, BOOST_PP_TYPE, T)>&& tuple_)
        -> ENABLE_IF_T(
            IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(3, BOOST_PP_TYPE, T))), VOID_T),
            VOID_T
        )
    {
        f(BOOST_PP_REPEAT(3, APPLY_STD_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(4, BOOST_PP_TYPENAME, T)>
    inline auto apply(F&& f, std::tuple<BOOST_PP_REPEAT(4, BOOST_PP_TYPE, T)>&& tuple_)
        -> ENABLE_IF_T(
            !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(4, BOOST_PP_TYPE, T))), VOID_T),
            RESULT_OF_T(F(BOOST_PP_REPEAT(4, BOOST_PP_TYPE, T)))
        )
    {
        return f(BOOST_PP_REPEAT(4, APPLY_STD_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(4, BOOST_PP_TYPENAME, T)>
    inline auto apply(F&& f, std::tuple<BOOST_PP_REPEAT(4, BOOST_PP_TYPE, T)>&& tuple_)
        -> ENABLE_IF_T(
            IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(4, BOOST_PP_TYPE, T))), VOID_T),
            VOID_T
        )
    {
        f(BOOST_PP_REPEAT(4, APPLY_STD_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(5, BOOST_PP_TYPENAME, T)>
    inline auto apply(F&& f, std::tuple<BOOST_PP_REPEAT(5, BOOST_PP_TYPE, T)>&& tuple_)
        -> ENABLE_IF_T(
            !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(5, BOOST_PP_TYPE, T))), VOID_T),
            RESULT_OF_T(F(BOOST_PP_REPEAT(5, BOOST_PP_TYPE, T)))
        )
    {
        return f(BOOST_PP_REPEAT(5, APPLY_STD_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(5, BOOST_PP_TYPENAME, T)>
    inline auto apply(F&& f, std::tuple<BOOST_PP_REPEAT(5, BOOST_PP_TYPE, T)>&& tuple_)
        -> ENABLE_IF_T(
            IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(5, BOOST_PP_TYPE, T))), VOID_T),
            VOID_T
        )
    {
        f(BOOST_PP_REPEAT(5, APPLY_STD_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(6, BOOST_PP_TYPENAME, T)>
    inline auto apply(F&& f, std::tuple<BOOST_PP_REPEAT(6, BOOST_PP_TYPE, T)>&& tuple_)
        -> ENABLE_IF_T(
            !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(6, BOOST_PP_TYPE, T))), VOID_T),
            RESULT_OF_T(F(BOOST_PP_REPEAT(6, BOOST_PP_TYPE, T)))
        )
    {
        return f(BOOST_PP_REPEAT(6, APPLY_STD_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(6, BOOST_PP_TYPENAME, T)>
    inline auto apply(F&& f, std::tuple<BOOST_PP_REPEAT(6, BOOST_PP_TYPE, T)>&& tuple_)
        -> ENABLE_IF_T(
            IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(6, BOOST_PP_TYPE, T))), VOID_T),
            VOID_T
        )
    {
        f(BOOST_PP_REPEAT(6, APPLY_STD_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(7, BOOST_PP_TYPENAME, T)>
    inline auto apply(F&& f, std::tuple<BOOST_PP_REPEAT(7, BOOST_PP_TYPE, T)>&& tuple_)
        -> ENABLE_IF_T(
            !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(7, BOOST_PP_TYPE, T))), VOID_T),
            RESULT_OF_T(F(BOOST_PP_REPEAT(7, BOOST_PP_TYPE, T)))
        )
    {
        return f(BOOST_PP_REPEAT(7, APPLY_STD_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(7, BOOST_PP_TYPENAME, T)>
    inline auto apply(F&& f, std::tuple<BOOST_PP_REPEAT(7, BOOST_PP_TYPE, T)>&& tuple_)
        -> ENABLE_IF_T(
            IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(7, BOOST_PP_TYPE, T))), VOID_T),
            VOID_T
        )
    {
        f(BOOST_PP_REPEAT(7, APPLY_STD_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(8, BOOST_PP_TYPENAME, T)>
    inline auto apply(F&& f, std::tuple<BOOST_PP_REPEAT(8, BOOST_PP_TYPE, T)>&& tuple_)
        -> ENABLE_IF_T(
            !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(8, BOOST_PP_TYPE, T))), VOID_T),
            RESULT_OF_T(F(BOOST_PP_REPEAT(8, BOOST_PP_TYPE, T)))
        )
    {
        return f(BOOST_PP_REPEAT(8, APPLY_STD_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(8, BOOST_PP_TYPENAME, T)>
    inline auto apply(F&& f, std::tuple<BOOST_PP_REPEAT(8, BOOST_PP_TYPE, T)>&& tuple_)
        -> ENABLE_IF_T(
            IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(8, BOOST_PP_TYPE, T))), VOID_T),
            VOID_T
        )
    {
        f(BOOST_PP_REPEAT(8, APPLY_STD_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(9, BOOST_PP_TYPENAME, T)>
    inline auto apply(F&& f, std::tuple<BOOST_PP_REPEAT(9, BOOST_PP_TYPE, T)>&& tuple_)
        -> ENABLE_IF_T(
            !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(9, BOOST_PP_TYPE, T))), VOID_T),
            RESULT_OF_T(F(BOOST_PP_REPEAT(9, BOOST_PP_TYPE, T)))
        )
    {
        return f(BOOST_PP_REPEAT(9, APPLY_STD_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(9, BOOST_PP_TYPENAME, T)>
    inline auto apply(F&& f, std::tuple<BOOST_PP_REPEAT(9, BOOST_PP_TYPE, T)>&& tuple_)
        -> ENABLE_IF_T(
            IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(9, BOOST_PP_TYPE, T))), VOID_T),
            VOID_T
        )
    {
        f(BOOST_PP_REPEAT(9, APPLY_STD_GET, tuple_));
    }
#endif // APPLY_HAS_CXX_11
}
