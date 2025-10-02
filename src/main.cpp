#include <SDL.h>
#include <iostream>
#include "graphics.h"
#include "logic.h"
#include "defs.h"

int main(int argc, char *argv[])
{
    Graphics graphics;
    if (!graphics.init("FruitBox", SCREEN_HEIGHT, SCREEN_WIDTH))
    {
        return 1;
    }

    Logic logic;
    bool quit = false;
    SDL_Event e;

    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
            logic.handleEvent(e);
        }

        logic.update();

        graphics.clear();
        graphics.drawBoard();
        graphics.present();
    }

    graphics.shutdown();
    return 0;
}