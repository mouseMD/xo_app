#ifndef GAMEAPPLICATION_H
#define GAMEAPPLICATION_H

#include "common_types.h"
#include "gamemanager.h"

class GameApplication
{
public:
    GameApplication();
    void init();
    void debugPrint(GAME_INDEX index);      // Only for debug

    // commands
    GAME_INDEX createNewGame();
    void setNewMove(GAME_INDEX index, Player player, const Coordinates& coords);
    void releaseGame(GAME_INDEX index);
    void finalize();

    // queries
    bool finished(GAME_INDEX index);
    bool started(GAME_INDEX index);
    uint8_t result(GAME_INDEX index);
    std::string getMoves(GAME_INDEX index);
    std::string getWinCoords(GAME_INDEX index);
    bool exist(GAME_INDEX index);
private:
    GameManager manager_;   // now only one manager
};

#endif // GAMEAPPLICATION_H
