#include <iostream>

#include "game/game3d_4_4_4.h"
#include "magic/magic.h"

Player reversePlayer(Player player)
{
    return (player == Player::X_Player) ? Player::O_Player : Player::X_Player;
}

template <typename T>
std::string convertCoordsToString(T coordsList)
{
    std::string line;
    for (auto coord : coordsList)
    {
      line += std::to_string(coord.square_);
      line += std::to_string(coord.vertical_);
      line += std::to_string(coord.horizontal_);
    }
    return line;
}

void playTestGame()
{
    Game3D_4_4_4 game(1);   // TODO make game default-constructible
    magic::generateWinPositions();  // TODO move this initialization to proper place
    auto player = Player::X_Player;
    game.debugPrint();
    while (!game.isFinished())
    {
        int i1, i2, i3;
        std::cout << "It's your move:\n";
        std::cin >> i1 >> i2 >> i3;
        game.setNewMove(player, {static_cast<COORD_INDEX>(i1),
                                 static_cast<COORD_INDEX>(i2),
                                 static_cast<COORD_INDEX>(i3)});
        game.debugPrint();
        player = reversePlayer(player);
        std::cout  << "Started: " << game.isInProcess() << "\n";
        std::cout  << "Finished: " << game.isFinished() << "\n";
        std::cout  << "Result: " << game.result() << "\n";
        std::cout  << "Moves: " << convertCoordsToString(game.getMoves()) << "\n";
        std::cout  << "Win coords: " << convertCoordsToString(game.getWinCoords()) << "\n";
    }
    std::cout << "The game is finished!" << std::endl;
}

int main()
{
    playTestGame();
}

