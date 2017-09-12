cmake_minimum_required(VERSION 3.9)
PROJECT(Function_differential_lib)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set (CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS "-std=gnu++11")
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(test)


