#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H

#include <cstdint>

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

enum Player
{
  X_Player,
  O_Player,
  None
};

#endif  // COMMON_TYPES_H
