// board, grid, apples
#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <SDL.h>
#include "graphics.h"
#include "defs.h"

class GameBoard
{
public:
    GameBoard(Graphics &graphics);
    ~GameBoard();

    void render();

private:
    Graphics &graphics;
    SDL_Texture *apple;
    SDL_Texture *background;
};

#endif // GAMEBOARD_H