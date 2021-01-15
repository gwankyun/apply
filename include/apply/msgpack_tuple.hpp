#pragma once
#include "common.hpp"
#include <msgpack.hpp> // msgpack::type::tuple msgpack::type::get

namespace lite
{
    // msgpack::type::tuple
#ifndef APPLY_MSGPACK_GET
#  define APPLY_MSGPACK_GET(z, n, x) BOOST_PP_COMMA_IF(n) msgpack::type::get<n>(x)
#endif // !APPLY_MSGPACK_GET

    template<typename F, typename T0>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(T0)), VOID_T),
        RESULT_OF_T(F(T0))
    ) apply(F f, msgpack::type::tuple<T0>& tuple_)
    {
        return f(msgpack::type::get<0>(tuple_));
    }

    template<typename F, typename T0>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(T0)), VOID_T),
        RESULT_OF_T(F(T0))
    ) apply(F f, const msgpack::type::tuple<T0>& tuple_)
    {
        return f(msgpack::type::get<0>(tuple_));
    }

    template<typename F, typename T0>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(T0)), VOID_T),
        VOID_T
    ) apply(F f, msgpack::type::tuple<T0>& tuple_)
    {
        f(msgpack::type::get<0>(tuple_));
    }

    template<typename F, typename T0>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(T0)), VOID_T),
        VOID_T
    ) apply(F f, const msgpack::type::tuple<T0>& tuple_)
    {
        f(msgpack::type::get<0>(tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(2, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(2, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(2, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        msgpack::type::tuple<BOOST_PP_REPEAT(2, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(2, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(2, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(2, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(2, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        const msgpack::type::tuple<BOOST_PP_REPEAT(2, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(2, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(2, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(2, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        msgpack::type::tuple<BOOST_PP_REPEAT(2, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(2, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(2, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(2, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        const msgpack::type::tuple<BOOST_PP_REPEAT(2, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(2, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(3, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(3, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(3, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        msgpack::type::tuple<BOOST_PP_REPEAT(3, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(3, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(3, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(3, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(3, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        const msgpack::type::tuple<BOOST_PP_REPEAT(3, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(3, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(3, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(3, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        msgpack::type::tuple<BOOST_PP_REPEAT(3, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(3, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(3, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(3, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        const msgpack::type::tuple<BOOST_PP_REPEAT(3, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(3, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(4, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(4, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(4, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        msgpack::type::tuple<BOOST_PP_REPEAT(4, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(4, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(4, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(4, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(4, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        const msgpack::type::tuple<BOOST_PP_REPEAT(4, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(4, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(4, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(4, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        msgpack::type::tuple<BOOST_PP_REPEAT(4, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(4, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(4, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(4, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        const msgpack::type::tuple<BOOST_PP_REPEAT(4, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(4, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(5, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(5, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(5, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        msgpack::type::tuple<BOOST_PP_REPEAT(5, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(5, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(5, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(5, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(5, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        const msgpack::type::tuple<BOOST_PP_REPEAT(5, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(5, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(5, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(5, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        msgpack::type::tuple<BOOST_PP_REPEAT(5, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(5, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(5, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(5, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        const msgpack::type::tuple<BOOST_PP_REPEAT(5, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(5, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(6, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(6, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(6, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        msgpack::type::tuple<BOOST_PP_REPEAT(6, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(6, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(6, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(6, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(6, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        const msgpack::type::tuple<BOOST_PP_REPEAT(6, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(6, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(6, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(6, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        msgpack::type::tuple<BOOST_PP_REPEAT(6, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(6, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(6, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(6, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        const msgpack::type::tuple<BOOST_PP_REPEAT(6, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(6, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(7, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(7, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(7, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        msgpack::type::tuple<BOOST_PP_REPEAT(7, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(7, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(7, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(7, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(7, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        const msgpack::type::tuple<BOOST_PP_REPEAT(7, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(7, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(7, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(7, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        msgpack::type::tuple<BOOST_PP_REPEAT(7, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(7, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(7, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(7, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        const msgpack::type::tuple<BOOST_PP_REPEAT(7, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(7, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(8, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(8, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(8, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        msgpack::type::tuple<BOOST_PP_REPEAT(8, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(8, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(8, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(8, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(8, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        const msgpack::type::tuple<BOOST_PP_REPEAT(8, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(8, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(8, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(8, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        msgpack::type::tuple<BOOST_PP_REPEAT(8, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(8, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(8, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(8, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        const msgpack::type::tuple<BOOST_PP_REPEAT(8, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(8, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(9, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(9, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(9, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        msgpack::type::tuple<BOOST_PP_REPEAT(9, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(9, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(9, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        !IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(9, BOOST_PP_TYPE, T))), VOID_T),
        RESULT_OF_T(F(BOOST_PP_REPEAT(9, BOOST_PP_TYPE, T)))
    ) apply(
        F f,
        const msgpack::type::tuple<BOOST_PP_REPEAT(9, BOOST_PP_TYPE, T)>& tuple_)
    {
        return f(BOOST_PP_REPEAT(9, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(9, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(9, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        msgpack::type::tuple<BOOST_PP_REPEAT(9, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(9, APPLY_MSGPACK_GET, tuple_));
    }

    template<typename F, BOOST_PP_REPEAT(9, BOOST_PP_TYPENAME, T)>
    inline ENABLE_IF_T(
        IS_SAME_V(RESULT_OF_T(F(BOOST_PP_REPEAT(9, BOOST_PP_TYPE, T))), VOID_T),
        VOID_T
    ) apply(
        F f,
        const msgpack::type::tuple<BOOST_PP_REPEAT(9, BOOST_PP_TYPE, T)>& tuple_)
    {
        f(BOOST_PP_REPEAT(9, APPLY_MSGPACK_GET, tuple_));
    }
}
