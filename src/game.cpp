#include "game.h"
#include <iostream>

using namespace std;

Game::Game() : isRunning(false), window(nullptr), renderer(nullptr), currentState(GameState::MENU) {}
Game::~Game()
{
    clean();
}

bool Game::init(const string &title, int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        return false;
    }

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
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

    isRunning = true;
    return true;
}

void Game::run()
{
    while (isRunning)
    {
        handleEvents();
        update();
        render();
        SDL_Delay(16); // 60 FPS
    }
}

void Game::handleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            isRunning = false;
        }
        // Handle other events based on current state
        else if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                isRunning = false;
                break;
            case SDLK_1:
                switchState(GameState::MENU);
                break;
            case SDLK_2:
                switchState(GameState::PLAYING);
                break;
            case SDLK_3:
                switchState(GameState::GAME_OVER);
                break;
            case SDLK_4:
                switchState(GameState::WIN);
                break;
            }
        }
    }
}

void Game::update()
{
    // Update game logic based on current state
    switch (currentState)
    {
    case GameState::MENU:
        // Update menu logic
        break;
    case GameState::PLAYING:
        // Update gameplay logic
        break;
    case GameState::GAME_OVER:
        // Update game over logic
        break;
    case GameState::WIN:
        // Update win logic
        break;
    }
}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
    SDL_RenderClear(renderer);

    // Render based on current state
    switch (currentState)
    {
    case GameState::MENU:
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue
        break;
    case GameState::PLAYING:
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Green
        break;
    case GameState::GAME_OVER:
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red
        break;
    case GameState::WIN:
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); // Yellow
        break;
    }

    SDL_Rect rect = {100, 100, 200, 200};
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer);
}

void Game::clean()
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

void Game::switchState(GameState newState)
{
    currentState = newState;
    cout << "Switched to state: ";
    switch (currentState)
    {
    case GameState::MENU:
        cout << "MENU" << endl;
        break;
    case GameState::PLAYING:
        cout << "PLAYING" << endl;
        break;
    case GameState::GAME_OVER:
        cout << "GAME_OVER" << endl;
        break;
    case GameState::WIN:
        cout << "WIN" << endl;
        break;
    }
}