# cmake最低版本
cmake_minimum_required(VERSION 3.19)

# 項目名
set(project apply)
project(${project})

# 包含模塊
set(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH}
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake
  ${CMAKE_CURRENT_SOURCE_DIR}/third_party)
include(CMakePrintHelpers)

# 啟用IDE目錄功能
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# 輸出目錄
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

set(apply_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
find_package(apply REQUIRED)

# 編譯器選項
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/W4;/MP;/Zc:__cplusplus;>")

add_compile_definitions("APPLY_HAS_CXX_11=1;")

set(apply apply)
add_executable(${apply})
target_sources(${apply} PRIVATE
  src/main.cpp
  include/apply.hpp
  include/apply/tuple.hpp
  include/apply/msgpack_tuple.hpp
  include/apply/boost_tuple.hpp
  include/apply/boost_array.hpp
  cmake/Findapply.cmake)
target_link_libraries(${apply} PUBLIC apply::apply)

# 如果找到Catch2就添加測試
find_package(Catch2 CONFIG)
cmake_print_variables(Catch2_FOUND)

if(Catch2_FOUND)
  set(test test)
  add_executable(${test})
  target_sources(${test}
    PRIVATE src/test.cpp)
  target_link_libraries(${test} PUBLIC
    Catch2::Catch2 apply::apply)
  target_compile_features(${test} PRIVATE cxx_std_17)
endif()
