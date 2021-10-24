#ifndef BOARD_I_BOARD_H
#define BOARD_I_BOARD_H

#include <array>

#include "common_types.h"

namespace xo_3d_4
{
class IBoard
{
 public:
  virtual void clear() = 0;
  virtual void setMark(Player player, const Coordinates& coord) = 0;
  virtual bool checkWin(Player player) const = 0;
  virtual bool checkDraw() const = 0;
  virtual BOARD_LINE getWinCoords() const = 0;
  virtual void debugPrint() = 0;
  virtual BOARD_VIEW getBoard() const = 0;
  virtual ~IBoard();
};
}  // namespace xo_3d_4

#endif  // BOARD_I_BOARD_H
