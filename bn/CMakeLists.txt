cmake_minimum_required(VERSION 3.6)
project(bn)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(HEADER_FILES
    bn007.h
        typedefs.h)

set(SOURCE_FILES
bn007.cpp
        )

add_library(bn STATIC ${SOURCE_FILES} ${HEADER_FILES})
