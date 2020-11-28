#pragma once
#include <utility>
#include <boost/utility/result_of.hpp>
#include "apply/preprocessor.hpp" // BOOST_PP_*

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

#ifndef APPLY_USE_MSGPACK_TUPLE
#  define APPLY_USE_MSGPACK_TUPLE 1
#endif // !APPLY_USE_MSGPACK_TUPLE

#ifndef APPLY_USE_BOOST_TUPLE
#  define APPLY_USE_BOOST_TUPLE 1
#endif // !APPLY_USE_BOOST_TUPLE


#if APPLY_USE_MSGPACK_TUPLE

#  include <msgpack.hpp> // msgpack::type::*

#  ifndef APPLY_MSGPACK_GET
#    define APPLY_MSGPACK_GET(_, n, x) x##n x##n##_(msgpack::type::get<n>(tuple_)); // T0 T0_(msgpack::type::get<0>(tpl));
#  endif // !APPLY_MSGPACK_GET

#  ifndef APPLY_MSGPACK_TUPLE
#    define APPLY_MSGPACK_TUPLE(z, n, _) \
    template< \
        typename F BOOST_PP_COMMA_IF(n) \
        BOOST_PP_REPEAT_TYPENAME(z, n, T)> \
    inline typename boost::result_of<F(BOOST_PP_REPEAT_TYPE(z, n, T))>::type apply(\
        F f BOOST_PP_COMMA_IF(n) \
        msgpack::type::tuple<BOOST_PP_REPEAT_TYPE(z, n, T)> tuple_) \
    { \
        BOOST_PP_REPEAT_Z(z, n, APPLY_MSGPACK_GET, T) \
        return f(BOOST_PP_REPEAT_ARGUMENT(z, n, T)); \
    }
#  endif // !APPLY_MSGPACK_TUPLE

#endif // APPLY_USE_MSGPACK_TUPLE


#if APPLY_USE_BOOST_TUPLE

#  include <boost/tuple/tuple.hpp> // boost::tuple boost::make_tuple boost::get

#  ifndef APPLY_BOOST_GET_TUPLE
#    define APPLY_BOOST_GET_TUPLE(_, n, x) x##n x##n##_(boost::get<n>(tuple_)); // T0 T0_(boost::get<0>(tuple_));
#  endif // !APPLY_BOOST_GET_TUPLE

#  ifndef APPLY_BOOST_TUPLE
#    define APPLY_BOOST_TUPLE(z, n, _) \
    template< \
        typename F BOOST_PP_COMMA_IF(n) \
        BOOST_PP_REPEAT_TYPENAME(z, n, T)> \
    inline typename boost::result_of<F(BOOST_PP_REPEAT_TYPE(z, n, T))>::type apply(\
        F f BOOST_PP_COMMA_IF(n) \
        boost::tuple<BOOST_PP_REPEAT_TYPE(z, n, T)> tuple_) \
    { \
        BOOST_PP_REPEAT_Z(z, n, APPLY_BOOST_GET_TUPLE, T) \
        return f(BOOST_PP_REPEAT_ARGUMENT(z, n, T)); \
    }
#  endif // !APPLY_BOOST_TUPLE

#endif // APPLY_USE_BOOST_TUPLE


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
#  ifndef APPLY_STD_TUPLE
#    define APPLY_STD_TUPLE(z, n, _) \
    template< \
        typename F BOOST_PP_COMMA_IF(n) \
        BOOST_PP_REPEAT_TYPENAME(z, n, T)> \
    inline auto apply(\
        F&& f BOOST_PP_COMMA_IF(n) \
        std::tuple<BOOST_PP_REPEAT_TYPE(z, n, T)>&& tuple_) -> typename boost::result_of<F(BOOST_PP_REPEAT_TYPE(z, n, T))>::type \
    { \
        BOOST_PP_REPEAT_Z(z, n, APPLY_STD_GET_TUPLE, T) \
        return f(BOOST_PP_REPEAT_ARGUMENT(z, n, T)); \
    }
#  endif

#  ifndef APPLY_ARRAY
#  define APPLY_ARRAY(z, n, _) \
    template<typename F, typename T, std::size_t N> \
    inline auto apply(\
        F&& f, std::array<T, N>& array_) -> typename boost::result_of<F(BOOST_PP_REPEAT_Z(z, n, ARRAY_TYPE, T))>::type \
    { \
        BOOST_PP_REPEAT_Z(z, n, APPLY_STD_GET_ARRAY, T) \
        return f(BOOST_PP_REPEAT_ARGUMENT(z, n, T)); \
    } \
    template<typename F, typename T, std::size_t N> \
    inline auto apply(\
        F&& f, const std::array<T, N>& array_) -> typename boost::result_of<F(BOOST_PP_REPEAT_Z(z, n, ARRAY_TYPE, T))>::type \
    { \
        BOOST_PP_REPEAT_Z(z, n, APPLY_STD_GET_ARRAY, T) \
        return f(BOOST_PP_REPEAT_ARGUMENT(z, n, T)); \
    } \
    template<typename F, typename T, std::size_t N> \
    inline auto apply(\
        F&& f, std::array<T, N>&& array_) -> typename boost::result_of<F(BOOST_PP_REPEAT_Z(z, n, ARRAY_TYPE, T))>::type \
    { \
        BOOST_PP_REPEAT_Z(z, n, APPLY_STD_GET_ARRAY, T) \
        return f(BOOST_PP_REPEAT_ARGUMENT(z, n, T)); \
    } \
    template<typename F, typename T, std::size_t N> \
    inline auto apply(\
        F&& f, const std::array<T, N>&& array_) -> typename boost::result_of<F(BOOST_PP_REPEAT_Z(z, n, ARRAY_TYPE, T))>::type \
    { \
        BOOST_PP_REPEAT_Z(z, n, APPLY_STD_GET_ARRAY, T) \
        return f(BOOST_PP_REPEAT_ARGUMENT(z, n, T)); \
    }
#  endif // !APPLY_ARRAY

#endif // APPLY_HAS_CXX_11


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

#if APPLY_USE_MSGPACK_TUPLE
    BOOST_PP_REPEAT_FROM_TO(1, 10, APPLY_MSGPACK_TUPLE, _)
#endif // APPLY_USE_MSGPACK_TUPLE

#if APPLY_USE_BOOST_TUPLE
    BOOST_PP_REPEAT_FROM_TO(1, 10, APPLY_BOOST_TUPLE, _)
#endif // APPLY_USE_BOOST_TUPLE

#if APPLY_HAS_CXX_11
    template<typename F, typename T1, typename T2>
    inline auto apply(
        F&& f,
        std::pair<T1, T2>&& pr) -> decltype(f(pr.first, pr.second))
    {
        return f(pr.first, pr.second);
    }
    BOOST_PP_REPEAT_FROM_TO(1, 10, APPLY_ARRAY, _)
    BOOST_PP_REPEAT_FROM_TO(1, 10, APPLY_STD_TUPLE, _)
#else
    template<typename F, typename T1, typename T2>
    inline typename boost::result_of<F(T1, T2)>::type apply(F f, std::pair<T1, T2> pr)
    {
        return f(pr.first, pr.second);
    }
#endif // APPLY_HAS_CXX_11
}
