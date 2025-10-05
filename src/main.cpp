#include <SDL.h>
#include <iostream>
#include "graphics.h"
#include "logic.h"
#include "defs.h"
#include "game.h"
#include "menu.h"
#include "gameboard.h"

int main(int argc, char *argv[])
{
    Graphics graphics;
    if (!graphics.init("FruitBox", SCREEN_HEIGHT, SCREEN_WIDTH))
    {
        cout << "Failed to initialize graphics!" << endl;
        return -1;
    }

    bool running = true;
    SDL_Event e;
    GameState state = GameState::MAIN_MENU;

    Menu menu(graphics);
    GameBoard board(graphics);

    while (running)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                running = false;
            }

            if (state == GameState::MAIN_MENU)
            {
                if (menu.handleEvent(e))
                {
                    state = GameState::PLAYING;
                }
            }
        }

        graphics.clear();

        if (state == GameState::MAIN_MENU)
        {
            menu.render();
        }
        else if (state == GameState::PLAYING)
        {
            board.render();
        }
        graphics.present();
    }

    graphics.shutdown();
    return 0;
}