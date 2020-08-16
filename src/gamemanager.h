#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <unordered_map>

#include "common_types.h"
#include "game_types.h"
#include "game3d_4_4_4.h"

// Manages registry of games
class GameManager
{
public:
    GameManager();
    GAME_INDEX createNewGame();
    void deleteGame(GAME_INDEX index);
    Game3D_4_4_4& getGame(GAME_INDEX index);
private:
    std::unordered_map<GAME_INDEX, Game3D_4_4_4> games;
};

#endif // GAMEMANAGER_H
