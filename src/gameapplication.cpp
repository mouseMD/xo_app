#include "gameapplication.h"

#include <iostream>
#include "magic.h"

GameApplication::GameApplication()
{
    magic::generateWinPositions();
    std::cout << magic::winPositions[0] << std::endl;
}
