#include "bitboardhelpers.h"
#include <bitset>

// Does not check validity of coords
BITBOARD getBoardFromCoordinates(const Coordinates &coord)
{
    std::bitset<64> bits;   // all zeroes
    std::size_t pos = coord.square_ * 16 + coord.vertical_ * 4 + coord.horizontal_;
    bits.set(pos);
    return bits.to_ullong();
}

// Bitboard must contain only ONE enabled bit
Coordinates getCoordinatesFromBoard(BITBOARD board)
{
    std::bitset<64> bits(board);
    std::size_t pos = bits._Find_first();
    return {static_cast<uint8_t>(pos / 16), static_cast<uint8_t>((pos % 16) / 4), static_cast<uint8_t>((pos % 16) % 4)};
}

// Four bits must be enabled
std::array<Coordinates, 4> getWinCoordsFromBoard(BITBOARD board)
{
    return {};
}
