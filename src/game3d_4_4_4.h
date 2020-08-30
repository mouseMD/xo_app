#ifndef GAME3D_4_4_4_H
#define GAME3D_4_4_4_H

#include <vector>

#include "common_types.h"
#include "game_types.h"
#include "board_4_4_4.h"

class Game3D_4_4_4
{
public:
    explicit Game3D_4_4_4(GAME_INDEX index);
    void setNewMove(Player player, const Coordinates& coords);
    void reset();
    bool isFinished() const;
    Result result() const;
    bool isNew() const;
    bool isInProcess() const;
    const std::array<Coordinates, 4> getWinCoords() const;
    const std::vector<Coordinates> &getMoves() const;
    void debugPrint();
    Player getPlayerToMove() const;
    std::array<Player, 64> getBoard() const;
private:
    const GAME_INDEX index_;
    GameStatus status_;
    Board_4_4_4 board_;
    Player player_to_move_;
    Result result_;
    std::vector<Coordinates> moves_;
};

#endif // GAME3D_4_4_4_H
