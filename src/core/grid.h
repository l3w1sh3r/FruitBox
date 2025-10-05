// grid management

#ifndef GRID_H
#define GRID_H

#include <vector>
#include "apple.h"
#include <SDL.h>
#include <SDL_ttf.h>

class Grid
{
private:
    int rows, cols;
    int cellSize;
    int offsetX, offsetY;

    SDL_Renderer *renderer;
    SDL_Texture *appleTexture;
    TTF_Font *font;

    std::vector<std::vector<Apple *>> apples; // 2D grid of apples
public:
    Grid(SDL_Renderer *renderer, SDL_Texture *appleTexture, TTF_Font *font);
    ~Grid();

    void generateApples();
    void render();

    Apple *getApple(int row, int col);
};

#endif // GRID_H