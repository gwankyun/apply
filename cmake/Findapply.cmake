﻿if(apply_ROOT)
    set(apply_INCLUDE_DIRS ${apply_ROOT}/include)
    set(any_FOUND TRUE)
    find_package(msgpack REQUIRED)
    find_package(Boost REQUIRED)
    if(NOT preprocessor_ROOT)
      message(FATAL_ERROR "must set preprocessor_ROOT")
    endif()
    if(NOT has_include_ROOT)
      message(FATAL_ERROR "must set has_include_ROOT")
    endif()
    find_package(preprocessor REQUIRED)
    find_package(has_include REQUIRED)
    if(NOT TARGET apply::apply)
      add_library(apply_header_only INTERFACE)
      add_library(apply::apply ALIAS apply_header_only)
      set(apply_LIBRARIES msgpackc Boost::headers preprocessor::preprocessor has_include::has_include)
      set_target_properties(apply_header_only PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${apply_INCLUDE_DIRS}"
        INTERFACE_LINK_LIBRARIES "${apply_LIBRARIES}"
      )
      set(apply_VERSION "1.0")
      include(FindPackageHandleStandardArgs)
      find_package_handle_standard_args(apply
        FOUND_VAR apply_FOUND
        REQUIRED_VARS apply_INCLUDE_DIRS
        VERSION_VAR apply_VERSION
      )
      set(Any_VERSION_STRING ${apply_VERSION})
    endif()
endif()
