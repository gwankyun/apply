#pragma once
#include <boost/utility/result_of.hpp> // boost::result_of
#include <preprocessor.hpp> // BOOST_PP_*
#include <has_include.hpp>
#include <boost/type_traits.hpp>

#ifndef APPLY_HAS_CXX_11
#  if __cplusplus >= 201103L || (defined(__cpp_variadic_templates) && defined(__cpp_rvalue_references))
#    define APPLY_HAS_CXX_11 1
#  else
#    define APPLY_HAS_CXX_11 0
#  endif
#endif

#ifndef APPLY_HAS_CXX_17
#  if APPLY_HAS_CXX_11 && (__cplusplus >= 201703L || (defined(__cpp_lib_type_trait_variable_templates)))
#    define APPLY_HAS_CXX_17 1
#  else
#    define APPLY_HAS_CXX_17 0
#  endif
#endif

#if APPLY_HAS_CXX_11
#  include <type_traits>
#endif

#ifndef APPLY_ENABLE_MSGPACK_TUPLE
#  define APPLY_ENABLE_MSGPACK_TUPLE 1
#endif

#ifndef APPLY_ENABLE_BOOST_TUPLE
#  define APPLY_ENABLE_BOOST_TUPLE 1
#endif

#ifndef APPLY_ENABLE_BOOST_ARRAY
#  define APPLY_ENABLE_BOOST_ARRAY 1
#endif

#ifndef RESULT_OF_T
#  define RESULT_OF_T(f) typename boost::result_of<f>::type
#endif

#  ifndef APPLY_STD_GET
#    define APPLY_STD_GET(z, n, x) BOOST_PP_COMMA_IF(n) std::get<n>(x)
#  endif

#  ifndef APPLY_ARRAY_TYPE
#    define APPLY_ARRAY_TYPE(z, n, x) x
#  endif

#ifndef BOOST_PP_REPEAT_FROM_TO_Z 
#  define BOOST_PP_REPEAT_FROM_TO_Z(z, first, last, macro, data) \
    BOOST_PP_CAT(BOOST_PP_REPEAT_FROM_TO_, z)(first, last, macro, data)
#endif

namespace lite
{
    struct void_t
    {
        typedef void type;
    };
}

#ifndef VOID_T
#  define VOID_T typename void_t::type
#endif

#ifndef ENABLE_IF_T
#  define ENABLE_IF_T(c, t) typename boost::enable_if_<c, t>::type
#endif

#ifndef IS_SAME_V
#  if APPLY_HAS_CXX_11
#    define IS_SAME_V(a, b) std::is_same<a, b>::value
#  else
#    define IS_SAME_V(a, b) boost::is_same<a, b>::value
#  endif
#endif
