#ifndef MAGIC_H
#define MAGIC_H

#include <array>

#include "common/board_types.h"

namespace magic
{
extern std::array<BITBOARD, 76> winPositions;

void generateWinPositions();

}  // namespace magic
#endif  // MAGIC_H
