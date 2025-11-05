// game logic, scoring

#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <SDL.h>
#include <vector>
#include "apple.h"

using namespace std;

class GameLogic
{
private:
    int score;

public:
    GameLogic();

    bool validateSelection(int sum) const;     // true if sum == 10
    void clearApples(vector<Apple *> &apples); // clear selected apples if sum == 10
    void addScore(int points);
    int getScore() const { return score; }
    void refillGrid(class Grid &grid); // refill grid after clearing apples
};

#endif // GAMELOGIC_H