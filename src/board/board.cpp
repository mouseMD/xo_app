#include "board/board.h"

#include <iostream>
#include <string>

#include "bitboards/bitboardhelpers.h"
#include "bitboards/winchecker.h"

namespace xo_3d_4
{
Board::Board()
{
  xs_ = 0;
  os_ = 0;
  win_ = 0;
}

void Board::clear()
{
  xs_ = 0;
  os_ = 0;
  win_ = 0;
}

void Board::setMark(Player player, const Coordinates &coord)
{
  BITBOARD new_move = getBoardFromCoordinates(coord);
  if (player == X_Player)
  {
    if (!(new_move & os_))
    {
      xs_ |= new_move;
    }
  }
  else if (player == O_Player)
  {
    if (!(new_move & xs_))
    {
      os_ |= new_move;
    }
  }
}

bool Board::checkWin(Player player) const
{
  if (player == X_Player)
  {
    return checkWin_4_4_4(xs_, win_);
  }
  else if (player == O_Player)
  {
    return checkWin_4_4_4(os_, win_);
  }
  else
    return false;
}

bool Board::checkDraw() const { return ~(xs_ | os_) == 0; }

BOARD_LINE Board::getWinCoords() const
{
  if (win_)
    return getWinCoordsFromBoard(win_);
  else
    return {};
}

void Board::debugPrint()
{
  std::cout << "*" << std::endl;
  for (uint8_t i = 0; i < 4; ++i)
  {
    std::string line;
    for (uint8_t j = 0; j < 4; ++j)
    {
      for (uint8_t k = 0; k < 4; ++k)
      {
        BITBOARD bb = getBoardFromCoordinates(Coordinates(j, k, i));
        if (bb & xs_)
        {
          line += "X";
        }
        else if (bb & os_)
        {
          line += "O";
        }
        else
        {
          line += ".";
        }
      }
      line += "    ";
    }
    std::cout << line << std::endl;
  }
}

BOARD_VIEW Board::getBoard() const
{
  BOARD_VIEW result;

  for (std::size_t i = 0; i < 64; ++i)
  {
    BITBOARD mask = 1ull << i;
    if (xs_ & mask)
    {
      result[i] = Player::X_Player;
    }
    else if (os_ & mask)
    {
      result[i] = Player::O_Player;
    }
    else
    {
      result[i] = Player::None;
    }
  }
  return result;
}

bool Board::isEmpty() const { return (xs_ == 0) && (os_ == 0) && (win_ == 0); }

}  // namespace xo_3d_4
