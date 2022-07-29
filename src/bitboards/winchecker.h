#ifndef BITBOARDS_WINCHECKER_H
#define BITBOARDS_WINCHECKER_H

#include "common/board_types.h"
namespace xo_3d_4
{
bool checkWin_4_4_4(BITBOARD candidate, BITBOARD& winBoard);
}  // namespace xo_3d_4
#endif  // BITBOARDS_WINCHECKER_H
