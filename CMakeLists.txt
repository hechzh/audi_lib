cmake_minimum_required(VERSION 3.9)
PROJECT(Function_differential_lib)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set (CMAKE_CXX_STANDARD 11)
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(test)


