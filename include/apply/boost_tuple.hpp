#pragma once
// #if !defined(APPLY_HAS_BOOST_PREPROCESSOR) || !APPLY_HAS_BOOST_PREPROCESSOR
#if !defined(APPLY_PREPROCESSOR) || !APPLY_PREPROCESSOR
#  include "detail/boost_tuple_base.hpp"
#else
#  include "detail/boost_tuple_ext.hpp"
#endif
