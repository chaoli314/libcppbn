cmake_minimum_required(VERSION 3.6)
project(bn)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(HEADER_FILES
        Node.h
        BayesianNetwork.h

        bn007.h
        typedefs.h

        ad_tree.h
        contingency_table.h

        sorted_set.h
        var.h)

set(SOURCE_FILES
        bn007.cpp
        )

add_library(bn STATIC ${SOURCE_FILES} ${HEADER_FILES})
