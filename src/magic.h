#ifndef MAGIC_H
#define MAGIC_H

#include <array>
#include "board_types.h"

namespace magic
{
    extern std::array<BITBOARD, 76> winPositions;

    void generateWinPositions();

}
#endif // MAGIC_H
