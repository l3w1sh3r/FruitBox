#include "Grid.h"
#include "../utils/Config.h"
#include <cstdlib>
#include <ctime>

Grid::Grid(SDL_Renderer *renderer, SDL_Texture *appleTexture, TTF_Font *font)
    : rows(GRID_SIZE), cols(GRID_SIZE),
      cellSize(APPLE_SIZE),
      offsetX(GRID_OFFSET_X), offsetY(GRID_OFFSET_Y),
      renderer(renderer), appleTexture(appleTexture), font(font)
{
    srand(static_cast<unsigned int>(time(nullptr)));

    apples.resize(rows, std::vector<Apple *>(cols, nullptr));
    generateApples();
}

Grid::~Grid()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            delete apples[i][j];
        }
    }
}

void Grid::generateApples()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (apples[i][j])
            {
                delete apples[i][j];
            }
            int val = APPLE_MIN_VALUE + rand() % (APPLE_MAX_VALUE - APPLE_MIN_VALUE + 1);
            float x = offsetX + j * cellSize;
            float y = offsetY + i * cellSize;

            apples[i][j] = new Apple(val, i, j, x, y,
                                     renderer, appleTexture, font);
        }
    }
}

void Grid::render()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (apples[i][j] && apples[i][j]->getIsActive())
            {
                apples[i][j]->render();
            }
        }
    }
}

Apple *Grid::getApple(int row, int col)
{
    if (row >= 0 && row < rows && col >= 0 && col < cols)
    {
        return apples[row][col];
    }
    return nullptr;
}