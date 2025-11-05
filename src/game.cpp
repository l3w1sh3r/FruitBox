#include "game.h"
#include <iostream>
#include "utils/config.h"
#include "core/gameLogic.h"

using namespace std;

Game::Game() : isRunning(false), window(nullptr), renderer(nullptr), currentState(GameState::MENU) {}
Game::~Game()
{
    clean();
}

GameLogic *gameLogic = nullptr;

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

    if (TTF_Init() == -1)
    {
        cerr << "TTF could not initialize! TTF_Error: " << TTF_GetError() << endl;
        return false;
    }

    gameLogic = new GameLogic();
    // load apple image
    SDL_Surface *tempSurface = IMG_Load(IMAGES_PATH "/appleWithoutLeaf.png");
    if (!tempSurface)
    {
        cerr << "Failed to load apple image! IMG_Error: " << IMG_GetError() << endl;
        return false;
    }
    appleTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    // load font
    font = TTF_OpenFont((FONTS_PATH "arial.ttf"), 24);
    if (!font)
    {
        cerr << "Failed to load font! TTF_Error: " << TTF_GetError() << endl;
        return false;
    }

    // Create grid: 8x8, each cell 64px, start drawing from (100,100)
    grid = new Grid(renderer, appleTexture, font);

    inputManager = new InputManager();

    selectionBox = new SelectionBox(renderer);

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
        if (inputManager)
        {
            inputManager->handleEvent(event);
        }

        if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
        {
            selectionBox->startSelection(Vector2D((float)event.button.x, (float)event.button.y));
        }
        else if (event.type == SDL_MOUSEMOTION)
        {
            selectionBox->updateSelection(Vector2D((float)event.motion.x, (float)event.motion.y));
        }
        else if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT)
        {
            selectionBox->endSelection();

            // Get selected apples
            if (currentState == GameState::PLAYING)
            {
                auto selectedApples = selectionBox->getSelectedApples(grid);
                int sum = selectionBox->calculateSelectedSum(selectedApples);

                if (gameLogic->validateSelection(sum))
                {
                    gameLogic->clearApples(selectedApples);
                    gameLogic->addScore((int)selectedApples.size());
                    gameLogic->refillGrid(*grid);
                }
                else
                {
                    cout << "Invalid selection. Sum: " << sum << endl;
                }
            }
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
    {
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Green

        if (grid)
        {
            grid->render();
        }
        if (selectionBox)
        {
            selectionBox->render();
        }
        break;
    }
    case GameState::GAME_OVER:
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red
        break;
    case GameState::WIN:
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); // Yellow
        break;
    }

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
    if (testApple)
    {
        delete testApple;
        testApple = nullptr;
    }
    if (appleTexture)
    {
        SDL_DestroyTexture(appleTexture);
        appleTexture = nullptr;
    }
    if (font)
    {
        TTF_CloseFont(font);
        font = nullptr;
    }
    if (grid)
    {
        delete grid;
        grid = nullptr;
    }
    if (inputManager)
    {
        delete inputManager;
        inputManager = nullptr;
    }
    if (selectionBox)
    {
        delete selectionBox;
        selectionBox = nullptr;
    }
    if (gameLogic)
    {
        delete gameLogic;
        gameLogic = nullptr;
    }
    TTF_Quit();
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