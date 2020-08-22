#include "gameapplication.h"
#include <iostream>

int main()
{
    GameApplication ga;
    auto index = ga.createNewGame();
    bool notFinished = true;
    auto player = Player::X_Player;
    ga.debugPrint(index);
    while (notFinished)
    {
        int i1, i2, i3;
        std::cout << "It's your move:\n";
        std::cin >> i1 >> i2 >> i3;
        ga.setNewMove(index, player, {static_cast<COORD_INDEX>(i1),
                                                static_cast<COORD_INDEX>(i2),
                                                static_cast<COORD_INDEX>(i3)});
        ga.debugPrint(index);
        player = (player == Player::X_Player) ? Player::O_Player : Player::X_Player;
        std::cout  << "Exists: " << ga.exist(index) << "\n";
        std::cout  << "Started: " << ga.started(index) << "\n";
        std::cout  << "Finished: " << ga.finished(index) << "\n";
        std::cout  << "Result: " << ga.result(index) << "\n";
        std::cout  << "Moves: " << ga.getMoves(index) << "\n";
        std::cout  << "Win coords: " << ga.getWinCoords(index) << "\n";

        if (ga.finished(index))
        {
            notFinished = false;
            ga.releaseGame(index);
        }
    }
}

