#include "board_4_4_4.h"

#include <iostream>
#include <string>

#include "winchecker.h"
#include "bitboardhelpers.h"

Board_4_4_4::Board_4_4_4()
{
    clear();
}

void Board_4_4_4::clear()
{
    xs_ = 0;
    os_ = 0;
    win_ = 0;
}

void Board_4_4_4::setMark(Player player, const Coordinates &coord)
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

bool Board_4_4_4::checkWin(Player player) const
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

std::array<Coordinates, 4> Board_4_4_4::getWinCoords() const
{
    if (win_)
        return getWinCoordsFromBoard(win_);
    else
        return {};
}

void Board_4_4_4::debugPrint()
{
    std::cout << "*" << std::endl;
    for (uint8_t i = 0; i<4; ++i)
    {
        std::string line;
        for (uint8_t j = 0; j<4; ++j)
        {
            for (uint8_t k = 0; k<4; ++k)
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
