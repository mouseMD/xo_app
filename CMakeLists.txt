cmake_minimum_required(VERSION 3.5)

project(xo_app LANGUAGES CXX)

include(CTest)

add_subdirectory(src)

enable_testing()

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
