cmake_minimum_required(VERSION 3.5)

project(tests)

set(SOURCES
	test_main.cpp 
    	test_bitboardhelpers.cpp
	test_board_4_4_4.cpp
        test_magic.cpp
    	../src/bitboardhelpers.cpp
	../src/board_4_4_4.cpp
	../src/winchecker.cpp
        ../src/magic.cpp
    )

add_executable(tests ${SOURCES})

target_include_directories(tests PRIVATE
    ../external/catch2
    ../src
    )

