#include <SDL.h>
#include <iostream>
#include "utils/config.h"
#include "utils/timer.h"
#include "game.h"

int main(int argc, char *argv[])
{
    Game game;

    if (!game.init("Fruit Box", 800, 600))
    {
        return -1;
    }

    game.run();
    return 0;
}