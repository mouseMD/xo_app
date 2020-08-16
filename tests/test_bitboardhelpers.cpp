#include "catch.hpp"

#include <iostream>

#include <bitset>
#include "bitboardhelpers.h"

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


TEST_CASE( "From coords to coords", "[bitboardhelpers]" )
{
    for (uint8_t i = 0; i<4; ++i)
    {
        for (uint8_t j = 0; j<4; ++j)
        {
            for (uint8_t k=0; k<4; ++k)
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

