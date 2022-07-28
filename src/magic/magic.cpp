#include "magic/magic.h"

#include <algorithm>
#include <set>

#include "bitboards/bitboardhelpers.h"
#include "common/common_types.h"

namespace magic
{
std::array<BITBOARD, 76> winPositions;

enum IndexRange
{
  UP,
  _1,
  _2,
  _3,
  _4,
  DOWN
};

bool isValidIndexes(IndexRange i1, IndexRange i2, IndexRange i3)
{
  if ((i1 > IndexRange::UP && i1 < IndexRange::DOWN) &&
      (i2 > IndexRange::UP && i2 < IndexRange::DOWN) &&
      (i3 > IndexRange::UP && i3 < IndexRange::DOWN))
    return false;
  else
    return true;
}

BITBOARD getBitboardFromRanges(IndexRange i1, IndexRange i2, IndexRange i3)
{
  BITBOARD bb = 0;
  std::array<Coordinates, 4> winLine;

  // first index
  for (std::size_t i = 0; i < 4; ++i)
  {
    switch (i1)
    {
      case _1:
      case _2:
      case _3:
      case _4:
        winLine[i].square_ = static_cast<COORD_INDEX>(i1) - 1;
        break;
      case UP:
        winLine[i].square_ = static_cast<COORD_INDEX>(i);
        break;
      case DOWN:
        winLine[i].square_ = static_cast<COORD_INDEX>(3 - i);
        break;
    }
  }

  // second index
  for (std::size_t i = 0; i < 4; ++i)
  {
    switch (i2)
    {
      case UP:
        winLine[i].vertical_ = static_cast<COORD_INDEX>(i);
        break;
      case _1:
      case _2:
      case _3:
      case _4:
        winLine[i].vertical_ = static_cast<COORD_INDEX>(i2) - 1;
        break;
      case DOWN:
        winLine[i].vertical_ = static_cast<COORD_INDEX>(3 - i);
        break;
    }
  }

  // third index
  for (std::size_t i = 0; i < 4; ++i)
  {
    switch (i3)
    {
      case UP:
        winLine[i].horizontal_ = static_cast<COORD_INDEX>(i);
        break;
      case _1:
      case _2:
      case _3:
      case _4:
        winLine[i].horizontal_ = static_cast<COORD_INDEX>(i3) - 1;
        break;
      case DOWN:
        winLine[i].horizontal_ = static_cast<COORD_INDEX>(3 - i);
        break;
    }
  }

  for (std::size_t i = 0; i < 4; ++i)
  {
    bb |= getBoardFromCoordinates(winLine[i]);
  }

  return bb;
}

void generateWinPositions()
{
  std::set<BITBOARD> bbSet;

  for (int i = IndexRange::UP; i <= IndexRange::DOWN; ++i)
  {
    for (int j = IndexRange::UP; j <= IndexRange::DOWN; ++j)
    {
      for (int k = IndexRange::UP; k <= IndexRange::DOWN; ++k)
      {
        if (isValidIndexes(static_cast<IndexRange>(i),
                           static_cast<IndexRange>(j),
                           static_cast<IndexRange>(k)))
        {
          bbSet.insert(getBitboardFromRanges(static_cast<IndexRange>(i),
                                             static_cast<IndexRange>(j),
                                             static_cast<IndexRange>(k)));
        }
      }
    }
  }
  std::copy(std::begin(bbSet), std::end(bbSet), std::begin(winPositions));
}

}  // namespace magic
