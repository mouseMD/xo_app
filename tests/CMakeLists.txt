cmake_minimum_required(VERSION 3.5)

project(tests)

set(SOURCES
	test_main.cpp 
    test_bitboardhelpers.cpp
    ../src/bitboardhelpers.cpp
    )

add_executable(tests ${SOURCES})

target_include_directories(tests PRIVATE
    ../external/catch2
    ../src
    )

