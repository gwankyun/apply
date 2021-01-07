#pragma once
#include <boost/utility/result_of.hpp> // boost::result_of
#include <preprocessor.hpp> // BOOST_PP_*
#include <has_include.hpp>

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
