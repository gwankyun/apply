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
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(T0)), VOID_T),
        RESULT_OF_T(F(T0))
    ) apply(F f, boost::tuple<T0>& tuple_)
    {
        return f(boost::get<0>(tuple_));
    }

    template<typename F, typename T0>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(T0)), VOID_T),
        RESULT_OF_T(F(T0))
    ) apply(F f, const boost::tuple<T0>& tuple_)
    {
        return f(boost::get<0>(tuple_));
    }

    template<typename F, typename T0>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(T0)), VOID_T),
        VOID_T
    ) apply(F f, boost::tuple<T0>& tuple_)
    {
        f(boost::get<0>(tuple_));
    }

    template<typename F, typename T0>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(T0)), VOID_T),
        VOID_T
    ) apply(F f, const boost::tuple<T0>& tuple_)
    {
        f(boost::get<0>(tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(2, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(2, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(2, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        boost::tuple<BOOST_PP_REPEAT(2, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(2, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(2, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(2, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(2, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        const boost::tuple<BOOST_PP_REPEAT(2, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(2, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(2, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(2, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        boost::tuple<BOOST_PP_REPEAT(2, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(2, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(2, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(2, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        const boost::tuple<BOOST_PP_REPEAT(2, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(2, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(3, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(3, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(3, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        boost::tuple<BOOST_PP_REPEAT(3, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(3, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(3, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(3, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(3, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        const boost::tuple<BOOST_PP_REPEAT(3, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(3, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(3, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(3, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        boost::tuple<BOOST_PP_REPEAT(3, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(3, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(3, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(3, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        const boost::tuple<BOOST_PP_REPEAT(3, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(3, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(4, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(4, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(4, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        boost::tuple<BOOST_PP_REPEAT(4, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(4, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(4, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(4, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(4, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        const boost::tuple<BOOST_PP_REPEAT(4, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(4, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(4, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(4, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        boost::tuple<BOOST_PP_REPEAT(4, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(4, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(4, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(4, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        const boost::tuple<BOOST_PP_REPEAT(4, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(4, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(5, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(5, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(5, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        boost::tuple<BOOST_PP_REPEAT(5, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(5, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(5, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(5, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(5, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        const boost::tuple<BOOST_PP_REPEAT(5, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(5, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(5, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(5, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        boost::tuple<BOOST_PP_REPEAT(5, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(5, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(5, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(5, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        const boost::tuple<BOOST_PP_REPEAT(5, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(5, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(6, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(6, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(6, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        boost::tuple<BOOST_PP_REPEAT(6, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(6, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(6, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(6, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(6, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        const boost::tuple<BOOST_PP_REPEAT(6, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(6, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(6, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(6, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        boost::tuple<BOOST_PP_REPEAT(6, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(6, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(6, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(6, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        const boost::tuple<BOOST_PP_REPEAT(6, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(6, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(7, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(7, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(7, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        boost::tuple<BOOST_PP_REPEAT(7, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(7, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(7, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(7, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(7, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        const boost::tuple<BOOST_PP_REPEAT(7, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(7, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(7, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(7, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        boost::tuple<BOOST_PP_REPEAT(7, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(7, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(7, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(7, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        const boost::tuple<BOOST_PP_REPEAT(7, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(7, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(8, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(8, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(8, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        boost::tuple<BOOST_PP_REPEAT(8, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(8, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(8, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(8, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(8, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        const boost::tuple<BOOST_PP_REPEAT(8, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(8, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(8, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(8, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        boost::tuple<BOOST_PP_REPEAT(8, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(8, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(8, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(8, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        const boost::tuple<BOOST_PP_REPEAT(8, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(8, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(9, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(9, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(9, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        boost::tuple<BOOST_PP_REPEAT(9, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(9, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(9, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(9, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(9, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        const boost::tuple<BOOST_PP_REPEAT(9, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(9, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(9, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(9, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        boost::tuple<BOOST_PP_REPEAT(9, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(9, APPLY_BOOST_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(9, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(9, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        const boost::tuple<BOOST_PP_REPEAT(9, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(9, APPLY_BOOST_GET, tuple_));
    }
}
