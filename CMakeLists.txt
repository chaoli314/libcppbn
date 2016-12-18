cmake_minimum_required(VERSION 3.6.2)
project(libcppbn)

add_definitions(-std=c++14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp)
add_executable(libcppbn_run ${SOURCE_FILES})

include_directories(bn) # include
target_link_libraries(libcppbn_run bn) # link

add_subdirectory(bn)
add_subdirectory(bn_tests)

##### boost lib #####
find_package(Boost
        1.62.0
        COMPONENTS
        timer date_time filesystem system # required libraries
        )
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) # include
    target_link_libraries(libcppbn_run ${Boost_LIBRARIES}) # link
endif()