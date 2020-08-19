set(SOURCES
	test_main.cpp 
    	test_bitboardhelpers.cpp
	test_board_4_4_4.cpp
        test_magic.cpp
    )

add_executable(tests_xo_app ${SOURCES})

target_include_directories(tests_xo_app PUBLIC
    ${xo_app_SOURCE_DIR}/external/catch2
    ${xo_app_SOURCE_DIR}/src
    )
target_link_libraries(tests_xo_app xo_app)

add_test(NAME MyTest COMMAND tests_xo_app)
