#include "gameapplication.h"

#include <iostream>
#include "magic.h"
#include <algorithm>

GameApplication::GameApplication()
{
    // init global data
    magic::generateWinPositions();
}

void GameApplication::init()
{

}

void GameApplication::debugPrint(GAME_INDEX index)
{
    manager_.getGame(index).debugPrint();
}

GAME_INDEX GameApplication::createNewGame()
{
    return manager_.createNewGame();
}

void GameApplication::setNewMove(GAME_INDEX index, Player player, const Coordinates &coords)
{
    manager_.getGame(index).setNewMove(player, coords);
}

void GameApplication::releaseGame(GAME_INDEX index)
{
    manager_.deleteGame(index);
}

void GameApplication::finalize()
{

}

bool GameApplication::finished(GAME_INDEX index)
{
    return manager_.getGame(index).isFinished();
}

bool GameApplication::started(GAME_INDEX index)
{
    return manager_.getGame(index).isInProcess();
}

uint8_t GameApplication::result(GAME_INDEX index)
{
    return manager_.getGame(index).result();
}

std::string GameApplication::getMoves(GAME_INDEX index)
{
    std::string line;
    auto moves = manager_.getGame(index).getMoves();
    for (auto move : moves)
    {
        line += std::to_string(move.square_);
        line += std::to_string(move.vertical_);
        line += std::to_string(move.horizontal_);
    }
    return line;
}

std::string GameApplication::getWinCoords(GAME_INDEX index)
{
    std::string line;
    auto coords = manager_.getGame(index).getWinCoords();
    for (auto coord : coords)
    {
        line += std::to_string(coord.square_);
        line += std::to_string(coord.vertical_);
        line += std::to_string(coord.horizontal_);
    }
    return line;
}

bool GameApplication::exist(GAME_INDEX index)
{
    try {
          manager_.getGame(index);
    }  catch (std::out_of_range& exp) {
        return false;
    }
    return true;
}

Player GameApplication::getPlayerToMove(GAME_INDEX index)
{
    return manager_.getGame(index).getPlayerToMove();
}

std::string GameApplication::getBoard(GAME_INDEX index)
{
    auto arrayBoard = manager_.getGame(index).getBoard();
    std::string result;
    std::copy(std::cbegin(arrayBoard), std::cend(arrayBoard), std::back_inserter(result));
    return result;
}
