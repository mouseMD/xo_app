#include <bitset>
#include <iostream>

#include "bitboardhelpers.h"
#include "catch.hpp"

using namespace std;

TEST_CASE("Test getBoardFromCoordinates", "[bitboardhelpers]")
{
  SECTION("0 0 0 -> 1")
  {
    Coordinates coords(0, 0, 0);
    BITBOARD bb = getBoardFromCoordinates(coords);
    REQUIRE(bb == 1);
  }
  SECTION("0 0 3 -> 2^3")
  {
    Coordinates coords(0, 0, 3);
    BITBOARD bb = getBoardFromCoordinates(coords);
    REQUIRE(bb == 8);
  }
  SECTION("1 0 0 -> 2^16")
  {
    Coordinates coords(1, 0, 0);
    BITBOARD bb = getBoardFromCoordinates(coords);
    REQUIRE(bb == (1ull << 16));
  }
}

TEST_CASE("Test getCoordinatesFromBoard", "[bitboardhelpers]")
{
  BITBOARD bb = 2;
  Coordinates coord = getCoordinatesFromBoard(bb);
  REQUIRE(coord.square_ == 0);
  REQUIRE(coord.vertical_ == 0);
  REQUIRE(coord.horizontal_ == 1);
}

TEST_CASE("From coords to coords", "[bitboardhelpers]")
{
  for (uint8_t i = 0; i < 4; ++i)
  {
    for (uint8_t j = 0; j < 4; ++j)
    {
      for (uint8_t k = 0; k < 4; ++k)
      {
        Coordinates coords(i, j, k);
        BITBOARD bb = getBoardFromCoordinates(coords);
        Coordinates coords2 = getCoordinatesFromBoard(bb);
        REQUIRE(coords.square_ == coords2.square_);
        REQUIRE(coords.vertical_ == coords2.vertical_);
        REQUIRE(coords.horizontal_ == coords2.horizontal_);
      }
    }
  }
}

TEST_CASE("Test getWinCoordsFromBoard", "[bitboardhelpers]")
{
  SECTION("000 -- 333")
  {
    BITBOARD bb1 = getBoardFromCoordinates(Coordinates(0, 0, 0)),
             bb2 = getBoardFromCoordinates(Coordinates(1, 1, 1)),
             bb3 = getBoardFromCoordinates(Coordinates(2, 2, 2)),
             bb4 = getBoardFromCoordinates(Coordinates(3, 3, 3));

    BITBOARD win = bb1 | bb2 | bb3 | bb4;
    auto winCoords = getWinCoordsFromBoard(win);
    REQUIRE(winCoords[0].square_ == 0);
    REQUIRE(winCoords[0].vertical_ == 0);
    REQUIRE(winCoords[0].horizontal_ == 0);
    REQUIRE(winCoords[1].square_ == 1);
    REQUIRE(winCoords[1].vertical_ == 1);
    REQUIRE(winCoords[1].horizontal_ == 1);
    REQUIRE(winCoords[2].square_ == 2);
    REQUIRE(winCoords[2].vertical_ == 2);
    REQUIRE(winCoords[2].horizontal_ == 2);
    REQUIRE(winCoords[3].square_ == 3);
    REQUIRE(winCoords[3].vertical_ == 3);
    REQUIRE(winCoords[3].horizontal_ == 3);
  }

  SECTION("021 -- 321")
  {
    BITBOARD bb1 = getBoardFromCoordinates(Coordinates(0, 2, 1)),
             bb2 = getBoardFromCoordinates(Coordinates(1, 2, 1)),
             bb3 = getBoardFromCoordinates(Coordinates(2, 2, 1)),
             bb4 = getBoardFromCoordinates(Coordinates(3, 2, 1));

    BITBOARD win = bb1 | bb2 | bb3 | bb4;
    auto winCoords = getWinCoordsFromBoard(win);
    REQUIRE(winCoords[0].square_ == 0);
    REQUIRE(winCoords[0].vertical_ == 2);
    REQUIRE(winCoords[0].horizontal_ == 1);
    REQUIRE(winCoords[1].square_ == 1);
    REQUIRE(winCoords[1].vertical_ == 2);
    REQUIRE(winCoords[1].horizontal_ == 1);
    REQUIRE(winCoords[2].square_ == 2);
    REQUIRE(winCoords[2].vertical_ == 2);
    REQUIRE(winCoords[2].horizontal_ == 1);
    REQUIRE(winCoords[3].square_ == 3);
    REQUIRE(winCoords[3].vertical_ == 2);
    REQUIRE(winCoords[3].horizontal_ == 1);
  }
}
