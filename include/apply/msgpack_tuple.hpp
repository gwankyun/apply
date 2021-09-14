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
    inline RESULT_OF_T(F(T0)) apply(F f, msgpack::type::tuple<T0>& tuple_)
    {
        return f(msgpack::type::get<0>(tuple_));
    }

    template<typename F, typename T0>
    inline RESULT_OF_T(F(T0)) apply(F f, const msgpack::type::tuple<T0>& tuple_)
    {
        return f(msgpack::type::get<0>(tuple_));
    }

#ifndef APPLY_MSGPACK_TUPLE
#  define APPLY_MSGPACK_TUPLE(z, n, _) \
    template<typename F, BOOST_PP_REPEAT_Z(z, n, BOOST_PP_TYPENAME, T)> \
    inline RESULT_OF_T(F(BOOST_PP_REPEAT_Z(z, n, BOOST_PP_TYPE, T))) apply(F f, const msgpack::type::tuple<BOOST_PP_REPEAT_Z(z, n, BOOST_PP_TYPE, T)>& tuple_) \
    { \
        return f(BOOST_PP_REPEAT_Z(z, n, APPLY_MSGPACK_GET, tuple_)); \
    }
    BOOST_PP_REPEAT_FROM_TO(2, 10, APPLY_MSGPACK_TUPLE, _)
#endif
}
