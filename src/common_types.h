#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H

#include <cstdint>

using COORD_INDEX = uint8_t;
using GAME_INDEX = uint64_t;

struct Coordinates
{
    COORD_INDEX square_;
    COORD_INDEX vertical_;
    COORD_INDEX horizontal_;
};

enum Player
{
    X_Player,
    O_Player,
    None
};

#endif // COMMON_TYPES_H
