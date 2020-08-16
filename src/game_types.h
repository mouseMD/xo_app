#ifndef GAME_TYPES_H
#define GAME_TYPES_H

#include <cstdint>

enum GameStatus
{
    NEW_GAME,
    IN_PROCESS,
    FINISHED
};

enum Result
{
    FIRST_WIN,
    SECOND_WIN,
    DRAW,
    NONE
};

#endif // GAME_TYPES_H
