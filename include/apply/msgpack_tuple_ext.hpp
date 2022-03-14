#pragma once
#include "msgpack_tuple_base.hpp"

namespace lite
{
    // msgpack::type::tuple
#ifndef APPLY_MSGPACK_GET
#  define APPLY_MSGPACK_GET(z, n, x) BOOST_PP_COMMA_IF(n) msgpack::type::get<n>(x)
#endif

#ifndef APPLY_MSGPACK_TUPLE
#  define APPLY_MSGPACK_TUPLE(z, n, _) \
    template<typename F, BOOST_PP_REPEAT_FROM_TO_Z(z, 0, n, BOOST_PP_TYPENAME, T)> \
    inline RESULT_OF_T(F(BOOST_PP_REPEAT_FROM_TO_Z(z, 0, n, BOOST_PP_TYPE, T))) apply(\
        F f, const msgpack::type::tuple<BOOST_PP_REPEAT_FROM_TO_Z(z, 0, n, BOOST_PP_TYPE, T)>& tuple_) \
    { \
        return f(BOOST_PP_REPEAT_FROM_TO_Z(z, 0, n, APPLY_MSGPACK_GET, tuple_)); \
    }
    BOOST_PP_REPEAT_FROM_TO(4, 10, APPLY_MSGPACK_TUPLE, _)
#endif
}
