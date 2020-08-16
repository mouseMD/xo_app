#ifndef GAME3D_4_4_4_H
#define GAME3D_4_4_4_H

#include <vector>

#include "common_types.h"
#include "game_types.h"
#include "board_4_4_4.h"

class Game3D_4_4_4
{
public:
    Game3D_4_4_4(GAME_INDEX index);
    void setNewMove(Player player, const Coordinates& coords);
    void reset();
    bool isFinished() const;
    Result result() const;
    bool isNew() const;
    bool isInProcess() const;
    std::array<Coordinates, 4>& getWinCoords() const;
    std::vector<Coordinates>& getMoves() const;
private:
    GAME_INDEX index_;
    GameStatus status_;
    Board_4_4_4 board_;
    Player player_to_move_;
    Result result_;
    std::vector<Coordinates> moves_;
};

#endif // GAME3D_4_4_4_H