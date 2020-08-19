#include "gamemanager.h"

GameManager::GameManager():currentMaxIndex_(0)
{

}

GAME_INDEX GameManager::createNewGame()
{
    currentMaxIndex_++; // Game indexes start from 1
    games.emplace(currentMaxIndex_, currentMaxIndex_);  // implicit construction std::pair<GAME_INDEX, Game3D_4_4_4>
    return currentMaxIndex_;
}

void GameManager::deleteGame(GAME_INDEX index)
{
    games.erase(index);
}

Game3D_4_4_4 &GameManager::getGame(GAME_INDEX index)
{
    return games.at(index);
}
