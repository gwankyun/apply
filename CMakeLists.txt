# cmake最低版本
cmake_minimum_required(VERSION 3.21)

# 項目名
set(project apply)
project(${project})

# 包含模塊
set(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH}
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake
  ${CMAKE_CURRENT_SOURCE_DIR}/third_party)
include(CMakePrintHelpers)
include(GNUInstallDirs)
include(common)

# 啟用IDE目錄功能
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# 輸出目錄
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

# 編譯器選項
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/W4;/MP;/Zc:__cplusplus;>")

add_compile_definitions("APPLY_HAS_CXX_11=1;")

##
set(target apply)

add_library(${target} INTERFACE)

install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/apply" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/apply.hpp" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

target_include_directories(${target}
  INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

# set(Boost_ROOT "c:/Program Files/boost_1_81_0/")
find_package(Boost)

if(Boost_FOUND)
  find_package(msgpackc-cxx CONFIG)
endif()

if(NOT(TARGET has_include) AND (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/has_include))
  add_subdirectory(has_include)
endif()

if(NOT(TARGET preprocessor) AND (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/preprocessor))
  add_subdirectory(preprocessor)
endif()

target_link_libraries(${target} INTERFACE
  $<TARGET_NAME_IF_EXISTS:Boost::headers>
  $<TARGET_NAME_IF_EXISTS:has_include>
  $<TARGET_NAME_IF_EXISTS:preprocessor>
  $<TARGET_NAME_IF_EXISTS:msgpackc-cxx>
)

target_compile_definitions(${target} INTERFACE
  APPLY_HAS_INCLUDE=$<TARGET_EXISTS:has_include>
  APPLY_PREPROCESSOR=$<TARGET_EXISTS:preprocessor>
  APPLY_MSGPACKC_CXX=$<TARGET_EXISTS:msgpackc-cxx>
)

target_install(${target} "0.0.1")
##

string(COMPARE EQUAL ${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR} cmp)
if(cmp)
  set(apply apply_main)
  add_executable(${apply})
  target_sources(${apply} PRIVATE
    src/main.cpp
    include/apply.hpp
    include/apply/tuple.hpp
    include/apply/detail/tuple_base.hpp
    include/apply/detail/tuple_ext.hpp
    include/apply/msgpack_tuple.hpp
    include/apply/detail/msgpack_tuple_base.hpp
    include/apply/detail/msgpack_tuple_ext.hpp
    include/apply/boost_tuple.hpp
    include/apply/detail/boost_tuple_base.hpp
    include/apply/detail/boost_tuple_ext.hpp
    include/apply/boost_array.hpp
    include/apply/detail/boost_array_base.hpp
    include/apply/detail/boost_array_ext.hpp
    include/apply/array.hpp
    include/apply/common.hpp
    cmake/Findapply.cmake)
  target_link_libraries(${apply} PUBLIC apply
    $<TARGET_NAME_IF_EXISTS:has_include>
  )

  # 如果找到Catch2就添加測試
  find_package(Catch2 CONFIG)
  cmake_print_variables(Catch2_FOUND)

  if(Catch2_FOUND)
    set(test test)
    add_executable(${test})
    target_sources(${test}
      PRIVATE src/test.cpp)
    target_link_libraries(${test} PUBLIC
      Catch2::Catch2 apply)
    target_compile_features(${test} PRIVATE cxx_std_17)
  endif()
endif()
