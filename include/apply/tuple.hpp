#pragma once
// #if !defined(APPLY_HAS_BOOST_PREPROCESSOR) || !APPLY_HAS_BOOST_PREPROCESSOR
#if !defined(APPLY_PREPROCESSOR) || !APPLY_PREPROCESSOR
#  include "detail/tuple_base.hpp"
#else
#  include "detail/tuple_ext.hpp"
#endif
