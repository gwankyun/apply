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
#  endif // __cplusplus >= 201103L || (defined(__cpp_variadic_templates) && defined(__cpp_rvalue_references))
#endif // !APPLY_HAS_CXX_11

#ifndef APPLY_ENABLE_MSGPACK_TUPLE
#  define APPLY_ENABLE_MSGPACK_TUPLE 1
#endif // !APPLY_ENABLE_MSGPACK_TUPLE

#ifndef APPLY_ENABLE_BOOST_TUPLE
#  define APPLY_ENABLE_BOOST_TUPLE 1
#endif // !APPLY_ENABLE_BOOST_TUPLE

#ifndef APPLY_ENABLE_BOOST_ARRAY
#  define APPLY_ENABLE_BOOST_ARRAY 1
#endif // !APPLY_ENABLE_BOOST_ARRAY

#ifndef RESULT_OF_T
#  define RESULT_OF_T(f) typename typename boost::result_of<f>::type
#endif // !RESULT_OF_T 

namespace lite
{
    struct void_t
    {
        typedef void type;
    };
}

#ifndef VOID_T
#  define VOID_T typename void_t::type
#endif // !VOID_T

#ifndef ENABLE_IF_T
#  define ENABLE_IF_T(c, t) typename boost::enable_if_<c, t>::type
#endif // !ENABLE_IF_T

#ifndef IS_SAME_V
#  define IS_SAME_V(a, b) boost::is_same<a, b>::value
#endif // !IS_SAME_V
