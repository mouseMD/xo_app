#ifndef BOARD_BOARD_H
#define BOARD_BOARD_H

#include "board/i_board.h"
#include "common/board_types.h"

namespace xo_3d_4
{
class Board : public IBoard
{
 public:
  Board();
  void clear() override;
  void setMark(Player player, const Coordinates& coord) override;
  bool checkWin(Player player) const override;
  bool checkDraw() const override;
  BOARD_LINE getWinCoords() const override;
  void debugPrint() override;
  BOARD_VIEW getBoard() const override;

  bool isEmpty() const;

 private:
  BITBOARD xs_;
  BITBOARD os_;
  mutable BITBOARD win_;
};
}  // namespace xo_3d_4

#endif  // BOARD_BOARD_H
