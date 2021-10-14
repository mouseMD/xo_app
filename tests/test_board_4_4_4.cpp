#include "board_4_4_4.h"
#include "catch.hpp"
#include "magic.h"

TEST_CASE("Empty field", "[board]")
{
  Board_4_4_4 board;
  board.debugPrint();
  REQUIRE(1 == 1);
}

TEST_CASE("Some moves", "[board]")
{
  Board_4_4_4 board;
  board.setMark(X_Player, Coordinates(0, 0, 0));
  board.setMark(O_Player, Coordinates(0, 1, 1));
  board.setMark(X_Player, Coordinates(0, 2, 2));
  board.setMark(O_Player, Coordinates(0, 3, 3));

  board.debugPrint();
  REQUIRE(1 == 1);
}

TEST_CASE("Clear field", "[board]")
{
  Board_4_4_4 board;
  board.setMark(X_Player, Coordinates(0, 0, 0));
  board.setMark(O_Player, Coordinates(0, 1, 1));
  board.setMark(X_Player, Coordinates(0, 2, 2));
  board.setMark(O_Player, Coordinates(0, 3, 3));
  board.clear();

  board.debugPrint();
  REQUIRE(1 == 1);
}

TEST_CASE("The same square", "[board]")
{
  Board_4_4_4 board;
  board.setMark(X_Player, Coordinates(1, 1, 1));
  board.setMark(O_Player, Coordinates(1, 1, 1));

  board.debugPrint();
  REQUIRE(1 == 1);
}

TEST_CASE("CheckWin on empty board", "[board]")
{
  magic::generateWinPositions();
  Board_4_4_4 board;
  REQUIRE(board.checkWin(X_Player) == false);
}
