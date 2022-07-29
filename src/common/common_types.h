#ifndef COMMON_COMMON_TYPES_H
#define COMMON_COMMON_TYPES_H

#include <array>
#include <cstdint>

namespace xo_3d_4
{
using COORD_INDEX = uint8_t;
using GAME_INDEX = uint64_t;

struct Coordinates
{
  COORD_INDEX square_ = 0;
  COORD_INDEX vertical_ = 0;
  COORD_INDEX horizontal_ = 0;
  Coordinates() {}
  Coordinates(COORD_INDEX sq, COORD_INDEX ver, COORD_INDEX hor)
  {
    square_ = sq;
    vertical_ = ver;
    horizontal_ = hor;
  }
  bool operator==(const Coordinates& rhs)
  {
    return (this->square_ == rhs.square_) &&
           (this->vertical_ == rhs.vertical_) &&
           (this->horizontal_ == rhs.horizontal_);
  }
};

using BOARD_LINE = std::array<Coordinates, 4>;

enum Player
{
  X_Player,
  O_Player,
  None
};

using BOARD_VIEW = std::array<Player, 64>;
}  // namespace xo_3d_4

#endif  // COMMON_COMMON_TYPES_H
