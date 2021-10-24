set(SOURCES
	test_main.cpp 
    	test_bitboardhelpers.cpp
        test_board.cpp
    )

add_executable(unit_tests ${SOURCES})

target_include_directories(unit_tests PUBLIC
    ${xo_app_SOURCE_DIR}/external/catch2
    ${xo_app_SOURCE_DIR}/src
    )
target_link_libraries(unit_tests xo_app)
