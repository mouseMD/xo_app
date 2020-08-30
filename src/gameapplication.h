#ifndef GAMEAPPLICATION_H
#define GAMEAPPLICATION_H

#include "common_types.h"
#include "gamemanager.h"

class GameApplication
{
public:
    GameApplication();
    void init();
    void finalize();
    void debugPrint(GAME_INDEX index);      // Only for debug

    // commands
    GAME_INDEX createNewGame();
    void setNewMove(GAME_INDEX index, Player player, const Coordinates& coords);
    void releaseGame(GAME_INDEX index);

    // queries
    bool finished(GAME_INDEX index) const;
    bool started(GAME_INDEX index) const;
    uint8_t result(GAME_INDEX index) const;
    std::string getMoves(GAME_INDEX index) const;
    std::string getWinCoords(GAME_INDEX index) const;
    bool exist(GAME_INDEX index) const;
    Player getPlayerToMove(GAME_INDEX index) const;
    std::string getBoard(GAME_INDEX index) const;
private:
    GameManager manager_;   // now only one manager
};

#endif // GAMEAPPLICATION_H
