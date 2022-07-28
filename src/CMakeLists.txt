set(SOURCES
    game3d_4_4_4.cpp
    winchecker.cpp
    bitboardhelpers.cpp
    magic.cpp
    board/board.cpp
    )
set(HEADERS
    game3d_4_4_4.h
    winchecker.h
    common/board_types.h
    bitboardhelpers.h
    game_types.h
    common/common_types.h
    magic.h
    board/i_board.h
    board/board.h
    )

add_library(xo_app ${SOURCES} ${HEADERS})

target_include_directories(xo_app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(xo_app PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    )
