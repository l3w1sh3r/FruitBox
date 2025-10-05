#include "gameboard.h"
#include <iostream>

GameBoard::GameBoard(Graphics &graphics) : graphics(graphics)
{
    background = graphics.loadTexture("assets/images/FruitBoxBackground.png");
    apple = graphics.loadTexture("assets/images/appleWithoutLeaf.png");
    if (!apple || !background)
    {
        std::cerr << "Failed to load apple texture for GameBoard!" << std::endl;
    }
}

GameBoard::~GameBoard()
{
    if (apple)
    {
        SDL_DestroyTexture(apple);
        apple = nullptr;
    }
}

void GameBoard::render()
{
    SDL_RenderCopy(graphics.getRenderer(), background, nullptr, nullptr);

    for (int row = 0; row < BOARD_ROWS; ++row)
    {
        for (int col = 0; col < BOARD_COLS; ++col)
        {
            SDL_Rect cellRect = {
                col * CELL_SIZE,
                row * CELL_SIZE,
                CELL_SIZE,
                CELL_SIZE};
            SDL_RenderCopy(graphics.getRenderer(), apple, nullptr, &cellRect);
        }
    }
}