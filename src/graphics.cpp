#include "graphics.h"
#include "defs.h"

Graphics::Graphics() : window(nullptr), renderer(nullptr) {}
Graphics::~Graphics()
{
    shutdown();
}

bool Graphics::init(const string &title, int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        return false;
    }
    window = SDL_CreateWindow(title.c_str(),
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              width, height, SDL_WINDOW_SHOWN);

    if (!window)
    {
        cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << endl;
        return false;
    }

    return true;
}

void Graphics::clear()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set draw color to black
    SDL_RenderClear(renderer);                      // Clear the screen
}

void Graphics::present()
{
    SDL_RenderPresent(renderer); // Update the window with the rendered content
}

void Graphics::shutdown()
{
    if (renderer)
    {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
    if (window)
    {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    SDL_Quit();
}

void Graphics::drawBoard()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white

    // vertical lines
    for (int i = 0; i <= BOARD_COLS; i++)
    {
        int x = BOARD_X + i * CELL_SIZE;

        SDL_RenderDrawLine(renderer, x, BOARD_Y, x, BOARD_Y + BOARD_HEIGHT);
    }

    // horizontal lines
    for (int i = 0; i <= BOARD_ROWS; i++)
    {
        int y = BOARD_Y + i * CELL_SIZE;

        SDL_RenderDrawLine(renderer, BOARD_X, y, BOARD_X + BOARD_WIDTH, y);
    }
}