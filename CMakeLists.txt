cmake_minimum_required(VERSION 3.6)
project(libcppbn)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp)

include_directories(bn)

add_executable(libcppbn ${SOURCE_FILES} )

add_subdirectory(bn)
add_subdirectory(bn_tests)
target_link_libraries(libcppbn bn)


#set(Boost_USE_STATIC_LIBS        ON) # only find static libs (archive)
#set(Boost_USE_STATIC_RUNTIME    OFF)
#set(Boost_USE_MULTITHREADED      ON)
find_package(Boost
        1.61.0                  # Minimum or EXACT version
        COMPONENTS
        timer date_time filesystem system # required libraries
        )
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(libcppbn ${Boost_LIBRARIES})
endif()