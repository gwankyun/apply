#pragma once
#include <utility>
#include "apply/common.hpp"

#if APPLY_HAS_CXX_11
#  include "apply/tuple.hpp"
#  include "apply/array.hpp"
#endif

#if APPLY_ENABLE_MSGPACK_TUPLE
#  include "apply/msgpack_tuple.hpp"
#endif

#if APPLY_ENABLE_BOOST_TUPLE
#  include "apply/boost_tuple.hpp"
#endif

#if APPLY_ENABLE_BOOST_ARRAY
#  include "apply/boost_array.hpp"
#endif

#ifndef RVALUE_REF
#  if __cpp_rvalue_references
#    define RVALUE_REF(x) x &&
#  else
#    define RVALUE_REF(x) x
#  endif
#endif

namespace lite
{
    template<typename T>
    struct rvalue_ref
    {
#if __cpp_rvalue_references
        using type = T&&;
#else
        typedef T type;
#endif
    };

#if APPLY_HAS_CXX_11
    template<typename F, typename T1, typename T2>
    inline auto apply(
        F&& f,
        std::pair<T1, T2>&& pr) -> decltype(f(pr.first, pr.second))
    {
        return f(pr.first, pr.second);
    }
#else
    template<typename F, typename T1, typename T2>
    inline typename boost::result_of<F(T1, T2)>::type apply(F f, std::pair<T1, T2> pr)
    {
        return f(pr.first, pr.second);
    }
#endif
}
