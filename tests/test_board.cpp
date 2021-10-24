#include "catch.hpp"

#include "board/board.h"

using namespace xo_3d_4;

TEST_CASE("When board is constructed Then board is empty", "[board]")
{
    Board board;

    REQUIRE(board.isEmpty());
}

TEST_CASE("Given empty board When mark is set Then board is not empty", "[board]")
{
    Board board;

    board.setMark(Player::X_Player, Coordinates(0,0,0));

    REQUIRE_FALSE(board.isEmpty());
}

TEST_CASE("Given not empty board When clear board Then board is empty", "[board]")
{
    Board board;
    board.setMark(Player::X_Player, Coordinates(0,0,0));

    board.clear();

    REQUIRE(board.isEmpty());
}
