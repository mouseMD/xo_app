#ifndef WINCHECKER_H
#define WINCHECKER_H

#include <cstdint>

#include "board_types.h"

bool checkWin_4_4_4(BITBOARD candidate, BITBOARD adversary, BITBOARD& winBoard);



#endif // WINCHECKER_H
