cmake_minimum_required(VERSION 3.8.2)
project(doctest_check LANGUAGES CXX)

add_library(doctest INTERFACE)
target_include_directories(doctest INTERFACE ${PROJECT_SOURCE_DIR}/external/doctest/doctest)

add_library(lib OBJECT lib.cpp)
target_link_libraries(lib PUBLIC doctest)

add_executable(testrunner testrunner.cpp)
target_link_libraries(testrunner PRIVATE lib)

# Executable that just uses the library.
add_executable(exec exec.cpp)
target_link_libraries(exec PRIVATE lib)
