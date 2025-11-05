#include "gameLogic.h"
#include <iostream>

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
            apple->collect();
        }
    }
}

void GameLogic::addScore(int points)
{
    score += points;
}