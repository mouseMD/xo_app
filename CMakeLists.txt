cmake_minimum_required(VERSION 3.5)

project(xo_app LANGUAGES CXX)

set(SOURCES
    src/main.cpp
    src/game3d_4_4_4.cpp
    src/board_4_4_4.cpp
    src/winchecker.cpp
    src/bitboardhelpers.cpp
    src/gamemanager.cpp
    src/gameapplication.cpp
    )
set(HEADERS
    src/game3d_4_4_4.h
    src/board_4_4_4.h
    src/winchecker.h
    src/board_types.h
    src/bitboardhelpers.h
    src/gamemanager.h
    src/game_types.h
    src/common_types.h
    src/gameapplication.h
    )

add_executable(xo_app ${SOURCES} ${HEADERS})


set_target_properties(xo_app PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    )
