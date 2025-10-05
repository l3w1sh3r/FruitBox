// apple management

#ifndef APPLE_H
#define APPLE_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class Apple
{
private:
    int value;     // number contained in the apple
    int row, col;  // position in the grid
    float x, y;    // position on screen
    bool isActive; // false if collected

    SDL_Texture *texture;   // apple image
    TTF_Font *font;         // font for number
    SDL_Renderer *renderer; // SDL renderer

public:
    Apple(int value, int row, int col, float px, float py,
          SDL_Renderer *renderer, SDL_Texture *appleTexture, TTF_Font *font);
    ~Apple();

    void render();
    void collect() { isActive = false; } // mark as collected
    bool getIsActive() const { return isActive; }
    int getValue() const { return value; }
    int getRow() const { return row; }
    int getCol() const { return col; }
};

#endif // APPLE_H