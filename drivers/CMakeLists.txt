set(SOURCES 
	cli_driver.cpp
	)

add_executable(cli_driver ${SOURCES})

target_include_directories(cli_driver PUBLIC
    ${xo_app_SOURCE_DIR}/src
    )

target_link_libraries(cli_driver xo_app)
