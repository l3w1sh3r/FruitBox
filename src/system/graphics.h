// screen rendering and drawing

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

class Graphics
{
public:
    Graphics();
    ~Graphics();

    bool init(const string &title, int width, int height); // initialize the graphics system

    void clear();     // clear the screen
    void present();   // update the window
    void drawBoard(); // draw the game board

    void shutdown(); // clean up resources

    SDL_Window *getWindow() const
    {
        return window;
    };
    SDL_Renderer *getRenderer() const
    {
        return renderer;
    };
    SDL_Texture *loadTexture(const string &filePath);

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
};

#endif // GRAPHICS_H