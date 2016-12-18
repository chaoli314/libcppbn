include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicBNTests

        basic_check.cpp # toy test.
        basic_fixture_check.cpp # toy test.

        typedefs_check.cpp # cross-platform types.

        var_check.cc # basic discrete random variable.
        sorted_set_check.cpp # a set of variables, varset.
        HuginFormatFile_check.cpp # Hugin format.
        )

target_link_libraries(runBasicBNTests gtest gtest_main)
target_link_libraries(runBasicBNTests bn)

##### boost lib #####
find_package(Boost
        1.62.0
        COMPONENTS
        timer date_time filesystem system # required libraries
        )
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) # include
    target_link_libraries(runBasicBNTests ${Boost_LIBRARIES}) # link
endif()