#include "menu.h"
#include <iostream>

Menu::Menu(Graphics &graphics) : graphics(graphics)
{
    background = graphics.loadTexture("assets/images/menuBackground.png");
    playButton = graphics.loadTexture("assets/images/appleWithLeaf.png");

    if (!background || !playButton)
    {
        std::cerr << "Failed to load menu textures!" << std::endl;
    }

    playRect = {100, 200, 128, 128}; // Position of Play button
}

bool Menu::handleEvent(SDL_Event &e)
{
    if (e.type == SDL_MOUSEBUTTONDOWN)
    {
        int x = e.button.x;
        int y = e.button.y;

        if (x >= playRect.x && x <= playRect.x + playRect.w &&
            y >= playRect.y && y <= playRect.y + playRect.h)
        {
            return true; // Play button clicked
        }
    }
    return false;
}

void Menu::render()
{
    SDL_RenderCopy(graphics.getRenderer(), background, nullptr, nullptr);
    SDL_RenderCopy(graphics.getRenderer(), playButton, nullptr, &playRect);
}