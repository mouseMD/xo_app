#include "bitboards/winchecker.h"

#include "magic/magic.h"

bool checkWin_4_4_4(BITBOARD candidate, BITBOARD &winBoard)
{
  for (auto bb : magic::winPositions)
  {
    if ((bb & candidate) == bb)
    {
      winBoard = bb;
      return true;
    }
  }
  return false;
}
