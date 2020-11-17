#pragma once
#include <boost/preprocessor.hpp> // BOOST_PP_*

#ifndef BOOST_PP_TYPENAME
#  define BOOST_PP_TYPENAME(_, n, x) BOOST_PP_COMMA_IF(n) typename x##n
#endif // !BOOST_PP_TYPENAME

#ifndef BOOST_PP_TYPE
#  define BOOST_PP_TYPE(_, n, x) BOOST_PP_COMMA_IF(n) x##n // , T0
#endif // !BOOST_PP_TYPE

#ifndef BOOST_PP_PARAMETER
#  define BOOST_PP_PARAMETER(_, n, x) BOOST_PP_COMMA_IF(n) x##n x##n##_ // , T0 T0_
#endif // !BOOST_PP_PARAMETER

#ifndef BOOST_PP_ARGUMENT
#  define BOOST_PP_ARGUMENT(_, n, x) BOOST_PP_COMMA_IF(n) x##n##_ // , T0_
#endif // !BOOST_PP_ARGUMENT

#ifndef BOOST_PP_REPEAT_Z
#  define BOOST_PP_REPEAT_Z(z, n, f, x)  BOOST_PP_REPEAT_##z(n, f, x)
#endif // !BOOST_PP_REPEAT_Z

#ifndef BOOST_PP_REPEAT_TYPENAME
#  define BOOST_PP_REPEAT_TYPENAME(z, n, T) BOOST_PP_REPEAT_Z(z, n, BOOST_PP_TYPENAME, T)
#endif // !BOOST_PP_REPEAT_TYPENAME

#ifndef BOOST_PP_REPEAT_TYPE
#  define BOOST_PP_REPEAT_TYPE(z, n, T) BOOST_PP_REPEAT_Z(z, n, BOOST_PP_TYPE, T)
#endif // !BOOST_PP_REPEAT_TYPE

#ifndef BOOST_PP_REPEAT_PARAMETER
#  define BOOST_PP_REPEAT_PARAMETER(z, n, T) BOOST_PP_REPEAT_Z(z, n, BOOST_PP_PARAMETER, T)
#endif // !BOOST_PP_REPEAT_PARAMETER

#ifndef BOOST_PP_REPEAT_ARGUMENT
#  define BOOST_PP_REPEAT_ARGUMENT(z, n, T) BOOST_PP_REPEAT_Z(z, n, BOOST_PP_ARGUMENT, T)
#endif // !BOOST_PP_REPEAT_ARGUMENT
