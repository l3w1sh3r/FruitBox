#include "apple.h"
#include "../utils/config.h"
#include <iostream>

using namespace std;

Apple::Apple(int value, int row, int col, float px, float py,
             SDL_Renderer *renderer, SDL_Texture *appleTexture, TTF_Font *font)
    : value(value), row(row), col(col), x(px), y(py), isActive(true),
      renderer(renderer), texture(appleTexture), font(font)
{
    if (!texture)
    {
        cerr << "Failed to load apple texture!" << endl;
    }
    if (!font)
    {
        cerr << "Failed to load font for apple!" << endl;
    }
}

Apple::~Apple()
{
}

void Apple::render()
{
    if (!isActive)
        return; // don't render if collected

    // Render apple texture
    SDL_Rect destRect = {static_cast<int>(x), static_cast<int>(y), APPLE_SIZE, APPLE_SIZE};
    SDL_RenderCopy(renderer, texture, nullptr, &destRect);

    // Render number on apple
    string numStr = to_string(value);
    SDL_Color textColor = {255, 255, 255, 255}; // white color

    SDL_Surface *textSurface = TTF_RenderText_Solid(font, numStr.c_str(), textColor);
    if (!textSurface)
    {
        cerr << "Failed to create text surface! TTF_Error: " << TTF_GetError() << endl;
        return;
    }

    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);
    if (!textTexture)
    {
        cerr << "Failed to create text texture! SDL_Error: " << SDL_GetError() << endl;
        return;
    }

    // Center the text on the apple
    int textW, textH;
    SDL_QueryTexture(textTexture, nullptr, nullptr, &textW, &textH);
    SDL_Rect textRect = {static_cast<int>(x + APPLE_SIZE / 2 - textW / 2),
                         static_cast<int>(y + APPLE_SIZE / 2 - textH / 2), textW, textH};
    SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);

    SDL_DestroyTexture(textTexture);
}