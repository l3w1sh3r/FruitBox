#ifndef MENU_H
#define MENU_H

#include <SDL.h>
#include "graphics.h"

class Menu
{
public:
    Menu(Graphics &graphics);

    // Handle input (e.g. clicks)
    bool handleEvent(SDL_Event &e);

    // Render menu
    void render();

private:
    Graphics &graphics;
    SDL_Texture *background;
    SDL_Texture *playButton;
    SDL_Rect playRect; // Button position & size
};

#endif // MENU_H