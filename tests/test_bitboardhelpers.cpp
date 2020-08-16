#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include <iostream>

#include <bitset>
#include "bitboardhelpers.h"

using namespace std;

TEST_CASE( "A simple test", "[bitboardhelpers]" )
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

TEST_CASE("Test getBoardFromCoordinates", "[bitboardhelpers]")
{
    REQUIRE(2 == 2);
}


TEST_CASE("Test getCoordinatesFromBoard", "[bitboardhelpers]")
{
    REQUIRE(1 == 2);
}
