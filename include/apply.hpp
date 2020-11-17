#pragma once
#include <utility>
#include <boost/utility/result_of.hpp>

#ifndef APPLY_HAS_CXX_11
#  if __cplusplus >= 201103L || (defined(__cpp_variadic_templates) && defined(__cpp_rvalue_references))
#    define APPLY_HAS_CXX_11 1
#  else
#    define APPLY_HAS_CXX_11 0
#  endif // __cplusplus >= 201103L || (defined(__cpp_variadic_templates) && defined(__cpp_rvalue_references))
#endif // !APPLY_HAS_CXX_11

#if APPLY_HAS_CXX_11
#  include <tuple> // std::tuple std::make_tuple std::get
#  include <functional> // std::function
#  include <array> // std::array
#endif // APPLY_HAS_CXX_11

#ifndef RVALUE_REF
#  if __cpp_rvalue_references
#    define RVALUE_REF(x) x &&
#  else
#    define RVALUE_REF(x) x
#  endif // __cpp_rvalue_references
#endif // !RVALUE_REF

#include <msgpack.hpp> // msgpack::type::*
#include <boost/function.hpp> // boost::function
#include <boost/tuple/tuple.hpp> // boost::tuple boost::make_tuple boost::get
#include "apply/preprocessor.hpp" // BOOST_PP_*

#ifndef APPLY_MSGPACK_GET
#  define APPLY_MSGPACK_GET(_, n, x) x##n x##n##_(msgpack::type::get<n>(tpl)); // T0 T0_(msgpack::type::get<0>(tpl));
#endif // !APPLY_MSGPACK_GET

#ifndef APPLY_BOOST_GET_TUPLE
#  define APPLY_BOOST_GET_TUPLE(_, n, x) x##n x##n##_(boost::get<n>(tuple_)); // T0 T0_(boost::get<0>(tuple_));
#endif // !APPLY_BOOST_GET_TUPLE

#if APPLY_HAS_CXX_11
#  ifndef APPLY_STD_GET_TUPLE
#    define APPLY_STD_GET_TUPLE(_, n, x) x##n x##n##_(std::get<n>(tuple_)); // T0 T0_(std::get<0>(tuple_));
#  endif // !APPLY_STD_GET_TUPLE
#  ifndef ARRAY_TYPE
#    define ARRAY_TYPE(z, n, T) BOOST_PP_COMMA_IF(n) T // , T
#  endif // !ARRAY_TYPE
#  ifndef APPLY_STD_GET_ARRAY
#    define APPLY_STD_GET_ARRAY(_, n, x) x x##n##_(std::get<n>(array_)); // T T0_(std::get<0>(array_));
#  endif // !APPLY_STD_GET_ARRAY
#endif // APPLY_HAS_CXX_11

#ifndef APPLY_MSGPACK_TUPLE
#  define APPLY_MSGPACK_TUPLE(z, n, _) \
    template< \
        typename R BOOST_PP_COMMA_IF(n) \
        BOOST_PP_REPEAT_TYPENAME(z, n, T)> \
    inline R apply(\
        R(*func)(BOOST_PP_REPEAT_TYPE(z, n, T)) BOOST_PP_COMMA_IF(n) \
        msgpack::type::tuple<BOOST_PP_REPEAT_TYPE(z, n, T)> tpl) \
    { \
        BOOST_PP_REPEAT_Z(z, n, APPLY_MSGPACK_GET, T) \
        return func(BOOST_PP_REPEAT_ARGUMENT(z, n, T)); \
    } \
    template< \
        typename R BOOST_PP_COMMA_IF(n) \
        BOOST_PP_REPEAT_TYPENAME(z, n, T)> \
    inline R apply(\
        boost::function<R(BOOST_PP_REPEAT_TYPE(z, n, T))> func BOOST_PP_COMMA_IF(n) \
        msgpack::type::tuple<BOOST_PP_REPEAT_TYPE(z, n, T)> tpl) \
    { \
        BOOST_PP_REPEAT_Z(z, n, APPLY_MSGPACK_GET, T) \
        return func(BOOST_PP_REPEAT_ARGUMENT(z, n, T)); \
    }
#endif // !APPLY_MSGPACK_TUPLE

#if APPLY_HAS_CXX_11
#  ifndef APPLY_STD_TUPLE
#    define APPLY_STD_TUPLE(z, n, _) \
    template< \
        typename R BOOST_PP_COMMA_IF(n) \
        BOOST_PP_REPEAT_TYPENAME(z, n, T)> \
    inline R apply(\
        R(*func)(BOOST_PP_REPEAT_TYPE(z, n, T)) BOOST_PP_COMMA_IF(n) \
        std::tuple<BOOST_PP_REPEAT_TYPE(z, n, T)>& tuple_) \
    { \
        BOOST_PP_REPEAT_Z(z, n, APPLY_STD_GET_TUPLE, T) \
        return func(BOOST_PP_REPEAT_ARGUMENT(z, n, T)); \
    } \
    template< \
        typename R BOOST_PP_COMMA_IF(n) /* typename R, */ \
        BOOST_PP_REPEAT_TYPENAME(z, n, T)> /* typename T0, typename T1 ... */ \
    inline R apply(\
        R(*func)(BOOST_PP_REPEAT_TYPE(z, n, T)) BOOST_PP_COMMA_IF(n) /* R(*func)(T0, T1 ...) */ \
        const std::tuple<BOOST_PP_REPEAT_TYPE(z, n, T)>& tuple_) /* std::tuple<T0, T1 ...)> tpl */ \
    { \
        BOOST_PP_REPEAT_Z(z, n, APPLY_STD_GET_TUPLE, T) \
        return func(BOOST_PP_REPEAT_ARGUMENT(z, n, T)); /* return func(T0_, T1_ ...); */ \
    } \
    template< \
        typename R BOOST_PP_COMMA_IF(n) /* typename R, */ \
        BOOST_PP_REPEAT_TYPENAME(z, n, T)> /* typename T0, typename T1 ... */ \
    inline R apply(\
        R(*func)(BOOST_PP_REPEAT_TYPE(z, n, T)) BOOST_PP_COMMA_IF(n) /* R(*func)(T0, T1 ...) */ \
        std::tuple<BOOST_PP_REPEAT_TYPE(z, n, T)>&& tuple_) /* std::tuple<T0, T1 ...)> tpl */ \
    { \
        BOOST_PP_REPEAT_Z(z, n, APPLY_STD_GET_TUPLE, T) \
        return func(BOOST_PP_REPEAT_ARGUMENT(z, n, T)); /* return func(T0_, T1_ ...); */ \
    } \
    template< \
        typename R BOOST_PP_COMMA_IF(n) /* typename R, */ \
        BOOST_PP_REPEAT_TYPENAME(z, n, T)> /* typename T0, typename T1 ... */ \
    inline R apply(\
        R(*func)(BOOST_PP_REPEAT_TYPE(z, n, T)) BOOST_PP_COMMA_IF(n) /* R(*func)(T0, T1 ...) */ \
        const std::tuple<BOOST_PP_REPEAT_TYPE(z, n, T)>&& tuple_) /* std::tuple<T0, T1 ...)> tpl */ \
    { \
        BOOST_PP_REPEAT_Z(z, n, APPLY_STD_GET_TUPLE, T) \
        return func(BOOST_PP_REPEAT_ARGUMENT(z, n, T)); /* return func(T0_, T1_ ...); */ \
    } \
    template< \
        typename R BOOST_PP_COMMA_IF(n) /* typename R, */ \
        BOOST_PP_REPEAT_TYPENAME(z, n, T)> /* typename T0, typename T1 ... */ \
    inline R apply(\
        std::function<R(BOOST_PP_REPEAT_TYPE(z, n, T))> func BOOST_PP_COMMA_IF(n) \
        /* std::function<R(T0, T1 ...)> function, */ \
        std::tuple<BOOST_PP_REPEAT_TYPE(z, n, T)>&& tuple_) \
        /* std::tuple<T0, T1 ...)> tpl */ \
    { \
        BOOST_PP_REPEAT_Z(z, n, APPLY_STD_GET_TUPLE, T) \
        return func(BOOST_PP_REPEAT_ARGUMENT(z, n, T)); /* return func(T0_, T1_ ...); */ \
    }
#  endif // !APPLY_STD_TUPLE

#  ifndef APPLY_ARRAY
#    define APPLY_ARRAY(z, n, _) \
    template<typename R, typename T, std::size_t N> \
    inline R apply(\
        R(*func)(BOOST_PP_REPEAT_Z(z, n, ARRAY_TYPE, T)), /* R(*func)(T, T ...), */ \
        std::array<T, N>& array_) \
    { \
        BOOST_PP_REPEAT_Z(z, n, APPLY_STD_GET_ARRAY, T) \
        return func(BOOST_PP_REPEAT_ARGUMENT(z, n, T)); /* return func(T0_, T1_ ...); */ \
    } \
    template<typename R, typename T, std::size_t N> \
    inline R apply(\
        R(*func)(BOOST_PP_REPEAT_Z(z, n, ARRAY_TYPE, T)), /* R(*func)(T, T ...), */ \
        const std::array<T, N>& array_) \
    { \
        BOOST_PP_REPEAT_Z(z, n, APPLY_STD_GET_ARRAY, T) \
        return func(BOOST_PP_REPEAT_ARGUMENT(z, n, T)); /* return func(T0_, T1_ ...); */ \
    } \
    template<typename R, typename T, std::size_t N> \
    inline R apply(\
        R(*func)(BOOST_PP_REPEAT_Z(z, n, ARRAY_TYPE, T)), /* R(*func)(T, T ...), */ \
        std::array<T, N>&& array_) \
    { \
        BOOST_PP_REPEAT_Z(z, n, APPLY_STD_GET_ARRAY, T) \
        return func(BOOST_PP_REPEAT_ARGUMENT(z, n, T)); /* return func(T0_, T1_ ...); */ \
    } \
    template<typename R, typename T, std::size_t N> \
    inline R apply(\
        R(*func)(BOOST_PP_REPEAT_Z(z, n, ARRAY_TYPE, T)), /* R(*func)(T, T ...), */ \
        const std::array<T, N>&& array_) \
    { \
        BOOST_PP_REPEAT_Z(z, n, APPLY_STD_GET_ARRAY, T) \
        return func(BOOST_PP_REPEAT_ARGUMENT(z, n, T)); /* return func(T0_, T1_ ...); */ \
    } \
    template<typename R, typename T, std::size_t N> \
    inline R apply(\
        std::function<R(BOOST_PP_REPEAT_Z(z, n, ARRAY_TYPE, T))>&& func, /* std::function<R(T, T ...)> func, */ \
        std::array<T, N>& array_) \
    { \
        BOOST_PP_REPEAT_Z(z, n, APPLY_STD_GET_ARRAY, T) \
        return func(BOOST_PP_REPEAT_ARGUMENT(z, n, T)); /* return func(T0_, T1_ ...); */ \
    } \
    template<typename R, typename T, std::size_t N> \
    inline R apply(\
        std::function<R(BOOST_PP_REPEAT_Z(z, n, ARRAY_TYPE, T))>&& func, /* std::function<R(T, T ...)> func, */ \
        const std::array<T, N>& array_) \
    { \
        BOOST_PP_REPEAT_Z(z, n, APPLY_STD_GET_ARRAY, T) \
        return func(BOOST_PP_REPEAT_ARGUMENT(z, n, T)); /* return func(T0_, T1_ ...); */ \
    } \
    template<typename R, typename T, std::size_t N> \
    inline R apply(\
        std::function<R(BOOST_PP_REPEAT_Z(z, n, ARRAY_TYPE, T))>&& func, /* std::function<R(T, T ...)> func, */ \
        std::array<T, N>&& array_) \
    { \
        BOOST_PP_REPEAT_Z(z, n, APPLY_STD_GET_ARRAY, T) \
        return func(BOOST_PP_REPEAT_ARGUMENT(z, n, T)); /* return func(T0_, T1_ ...); */ \
    } \
    template<typename R, typename T, std::size_t N> \
    inline R apply(\
        std::function<R(BOOST_PP_REPEAT_Z(z, n, ARRAY_TYPE, T))>&& func, /* std::function<R(T, T ...)> func, */ \
        const std::array<T, N>&& array_) \
    { \
        BOOST_PP_REPEAT_Z(z, n, APPLY_STD_GET_ARRAY, T) \
        return func(BOOST_PP_REPEAT_ARGUMENT(z, n, T)); /* return func(T0_, T1_ ...); */ \
    }
#  endif // !APPLY_ARRAY

#endif // APPLY_HAS_CXX_11

#ifndef APPLY_BOOST_TUPLE
#  define APPLY_BOOST_TUPLE(z, n, _) \
    template< \
        typename R BOOST_PP_COMMA_IF(n) \
        BOOST_PP_REPEAT_TYPENAME(z, n, T)> \
    inline R apply(\
        R(*func)(BOOST_PP_REPEAT_TYPE(z, n, T)) BOOST_PP_COMMA_IF(n) \
        boost::tuple<BOOST_PP_REPEAT_TYPE(z, n, T)> tuple_) \
    { \
        BOOST_PP_REPEAT_Z(z, n, APPLY_BOOST_GET_TUPLE, T) \
        return func(BOOST_PP_REPEAT_ARGUMENT(z, n, T)); \
    } \
    template< \
        typename R BOOST_PP_COMMA_IF(n) \
        BOOST_PP_REPEAT_TYPENAME(z, n, T)> \
    inline R apply(\
        boost::function<R(BOOST_PP_REPEAT_TYPE(z, n, T))> func BOOST_PP_COMMA_IF(n) \
        boost::tuple<BOOST_PP_REPEAT_TYPE(z, n, T)> tuple_) \
    { \
        BOOST_PP_REPEAT_Z(z, n, APPLY_BOOST_GET_TUPLE, T) \
        return func(BOOST_PP_REPEAT_ARGUMENT(z, n, T)); \
    }
#endif // !APPLY_BOOST_TUPLE

namespace lite
{
    template<typename T>
    struct rvalue_ref
    {
#if __cpp_rvalue_references
        using type = T&&;
#else
        typedef T type;
#endif // __cpp_rvalue_references
    };

    template<typename R, typename T1, typename T2>
    inline R apply(R(*func)(T1, T2), std::pair<T1, T2> pr)
    {
        return func(pr.first, pr.second);
    }

    template<typename R, typename T1, typename T2>
    inline R apply(boost::function<R(T1, T2)> func, std::pair<T1, T2> pr)
    {
        return func(pr.first, pr.second);
    }

    BOOST_PP_REPEAT_FROM_TO(1, 10, APPLY_MSGPACK_TUPLE, _)
    BOOST_PP_REPEAT_FROM_TO(1, 10, APPLY_BOOST_TUPLE, _)
#if APPLY_HAS_CXX_11
    template<typename R, typename T1, typename T2>
    inline R apply(
        std::function<R(T1, T2)>&& func,
        std::pair<T1, T2>&& pr)
    {
        return func(pr.first, pr.second);
    }
    BOOST_PP_REPEAT_FROM_TO(1, 10, APPLY_STD_TUPLE, _)
    BOOST_PP_REPEAT_FROM_TO(1, 10, APPLY_ARRAY, _)
#endif // APPLY_HAS_CXX_11
}

