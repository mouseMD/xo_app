#include "game/game3d_4_4_4.h"

#include <iostream>

namespace xo_3d_4
{
Game3D_4_4_4::Game3D_4_4_4(GAME_INDEX index)
    : index_(index),
      status_(GameStatus::NEW_GAME),
      player_to_move_(Player::X_Player),
      result_(NONE)
{
}

void Game3D_4_4_4::setNewMove(Player player, const Coordinates &coords)
{
  if (status_ == GameStatus::NEW_GAME)
  {
    status_ = GameStatus::IN_PROCESS;
  }

  if (status_ != GameStatus::FINISHED)
  {
    board_.setMark(player, coords);
    player_to_move_ =
        (player == Player::X_Player) ? Player::O_Player : Player::X_Player;
    if (board_.checkWin(player))
    {
      status_ = GameStatus::FINISHED;
      result_ =
          (player == Player::X_Player) ? Result::FIRST_WIN : Result::SECOND_WIN;
    }
    else if (board_.checkDraw())
    {
      status_ = GameStatus::FINISHED;
      result_ = Result::DRAW;
    }
  }
  moves_.push_back(coords);
}

void Game3D_4_4_4::reset()
{
  status_ = GameStatus::NEW_GAME;
  board_.clear();
  result_ = Result::NONE;
  player_to_move_ = Player::X_Player;
  moves_.clear();
}

bool Game3D_4_4_4::isFinished() const
{
  return (status_ == GameStatus::FINISHED);
}

Result Game3D_4_4_4::result() const { return result_; }

bool Game3D_4_4_4::isNew() const { return (status_ == GameStatus::NEW_GAME); }

bool Game3D_4_4_4::isInProcess() const
{
  return (status_ == GameStatus::IN_PROCESS);
}

const std::array<Coordinates, 4> Game3D_4_4_4::getWinCoords() const
{
  return board_.getWinCoords();
}

const std::vector<Coordinates> &Game3D_4_4_4::getMoves() const
{
  return moves_;
}

void Game3D_4_4_4::debugPrint()
{
  std::cout << "Game index: " << index_ << "\n";
  std::cout << "Game status: " << status_ << "\n";
  std::cout << "Player to move: " << player_to_move_ << "\n";
  std::cout << "Result: " << result_ << "\n";
  std::cout << "Moves: ";
  for (const auto &move : moves_)
  {
    std::cout << static_cast<int>(move.square_)
              << static_cast<int>(move.vertical_)
              << static_cast<int>(move.horizontal_);
  }
  std::cout << "\n";
  board_.debugPrint();
  std::cout << std::endl;
}

Player Game3D_4_4_4::getPlayerToMove() const { return player_to_move_; }

std::array<Player, 64> Game3D_4_4_4::getBoard() const
{
  return board_.getBoard();
}
}  // namespace xo_3d_4
