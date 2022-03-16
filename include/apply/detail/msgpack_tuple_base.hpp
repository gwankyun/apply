#pragma once
#include "common.hpp"
#include <msgpack.hpp> // msgpack::type::tuple msgpack::type::get

namespace lite
{
    template<typename F, typename T0>
    inline RESULT_OF_T(F(T0)) apply(F f, const msgpack::type::tuple<T0>& tuple_)
    {
        return f(msgpack::type::get<0>(tuple_));
    }

    template<typename F, typename T0, typename T1>
    inline RESULT_OF_T(F(T0, T1)) apply(F f, const msgpack::type::tuple<T0, T1>& tuple_)
    {
        return f(msgpack::type::get<0>(tuple_), msgpack::type::get<1>(tuple_));
    }

    template<typename F, typename T0, typename T1, typename T2>
    inline RESULT_OF_T(F(T0, T1, T2)) apply(F f, const msgpack::type::tuple<T0, T1, T2>& tuple_)
    {
        return f(msgpack::type::get<0>(tuple_), msgpack::type::get<1>(tuple_), msgpack::type::get<2>(tuple_));
    }
}
