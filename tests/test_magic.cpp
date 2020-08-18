#include "catch.hpp"

#include <iostream>

#include "magic.h"
#include "board_4_4_4.h"
#include "bitboardhelpers.h"

TEST_CASE("Test getBitboardFromRanges", "[magic]")
{
    Board_4_4_4 board;

    magic::generateWinPositions();

    for (int i =0 ; i< 76; i++)
    {
        auto winLine = getWinCoordsFromBoard(magic::winPositions[i]);

        for (auto coord : winLine)
        {
            board.setMark(X_Player, coord);
        }
        board.debugPrint();
        board.clear();

        REQUIRE(1 == 1);
    }
}
