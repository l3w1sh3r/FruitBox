#include "gameLogic.h"
#include <iostream>
#include "grid.h"
#include "../utils/config.h"
#include <ctime>
#include <cstdlib>

using namespace std;

GameLogic::GameLogic() : score(0) {}

bool GameLogic::validateSelection(int sum) const
{
    return sum == 10;
}

void GameLogic::clearApples(vector<Apple *> &apples)
{
    for (Apple *apple : apples)
    {
        if (apple && apple->getIsActive())
        {
            apple->setActive(false);
        }
    }
}

void GameLogic::addScore(int points)
{
    score += points;
}

void GameLogic::refillGrid(Grid &grid)
{
    srand(static_cast<unsigned int>(time(nullptr)));

    for (int row = 0; row < GRID_SIZE; row++)
    {
        for (int col = 0; col < GRID_SIZE; col++)
        {
            Apple *apple = grid.getApple(row, col);
            if (apple && !apple->getIsActive())
            {
                // generate new apple value
                int val = APPLE_MIN_VALUE + rand() % (APPLE_MAX_VALUE - APPLE_MIN_VALUE + 1);
                // refill apple
                apple->setValue(val);
                apple->setActive(true);
            }
        }
    }
}