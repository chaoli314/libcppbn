include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicBNTests
        basic_check.cpp
        bn007_check.cpp
        typedefs_check.cpp
        sorted_set_check.cpp var_check.cpp HuginFormatFile_check.cpp)

target_link_libraries(runBasicBNTests gtest gtest_main)
target_link_libraries(runBasicBNTests bn)


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
    target_link_libraries(runBasicBNTests ${Boost_LIBRARIES})
endif()