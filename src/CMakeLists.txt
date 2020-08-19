set(SOURCES
    game3d_4_4_4.cpp
    board_4_4_4.cpp
    winchecker.cpp
    bitboardhelpers.cpp
    gamemanager.cpp
    gameapplication.cpp
    magic.cpp
    )
set(HEADERS
    game3d_4_4_4.h
    board_4_4_4.h
    winchecker.h
    board_types.h
    bitboardhelpers.h
    gamemanager.h
    game_types.h
    common_types.h
    gameapplication.h
    magic.h
    )

add_library(xo_app ${SOURCES} ${HEADERS})


set_target_properties(xo_app PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    )