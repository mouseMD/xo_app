#ifndef MAGIC_MAGIC_H
#define MAGIC_MAGIC_H

#include <array>

#include "common/board_types.h"

namespace xo_3d_4
{
namespace magic
{
extern std::array<BITBOARD, 76> winPositions;

void generateWinPositions();

}  // namespace magic
}  // namespace xo_3d_4
#endif  // MAGIC_MAGIC_H
