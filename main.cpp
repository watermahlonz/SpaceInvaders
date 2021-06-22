#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include "Game.h"

int main()
{
    Game game;


    game.run();

    return 0;
    _CrtDumpMemoryLeaks();
}