#ifndef BITBOARDS_BITBOARDHELPERS_H
#define BITBOARDS_BITBOARDHELPERS_H

#include <array>

#include "common/board_types.h"
#include "common/common_types.h"

namespace xo_3d_4
{
BITBOARD getBoardFromCoordinates(const Coordinates& coord);
Coordinates getCoordinatesFromBoard(BITBOARD board);

std::array<Coordinates, 4> getWinCoordsFromBoard(BITBOARD board);
}  // namespace xo_3d_4

#endif  // BITBOARDS_BITBOARDHELPERS_H
