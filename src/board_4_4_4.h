#ifndef BOARD_4_4_4_H
#define BOARD_4_4_4_H

#include <array>

#include "common_types.h"
#include "board_types.h"

class Board_4_4_4
{
public:
    Board_4_4_4();
    void clear();
    void setMark(Player player, const Coordinates& coord);
    bool checkWin(Player player) const;
    std::array<Coordinates, 4> getWinCoords() const;
private:
    BITBOARD xs_;
    BITBOARD os_;
    mutable BITBOARD win_;
};

#endif // BOARD_4_4_4_H
