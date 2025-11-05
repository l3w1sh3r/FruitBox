#include "selectionBox.h"
#include "apple.h"
#include "grid.h"
#include "../utils/config.h"
#include <iostream>

using namespace std;

SelectionBox::SelectionBox(SDL_Renderer *renderer)
    : startPoint(0, 0), endPoint(0, 0), isSelecting(false), renderer(renderer) {}

void SelectionBox::startSelection(const Vector2D &pos)
{
    startPoint = pos;
    endPoint = pos;
    isSelecting = true;
}

void SelectionBox::updateSelection(const Vector2D &pos)
{
    if (isSelecting)
    {
        endPoint = pos;
    }
}

void SelectionBox::endSelection()
{
    isSelecting = false;
}

void SelectionBox::render()
{
    if (!isSelecting)
        return;

    SDL_Rect rect;
    rect.x = static_cast<int>(getLeft());
    rect.y = static_cast<int>(getTop());
    rect.w = static_cast<int>(getRight() - getLeft());
    rect.h = static_cast<int>(getBottom() - getTop());

    // Draw outline in red
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &rect);
}

vector<Apple *> SelectionBox::getSelectedApples(Grid *grid)
{
    vector<Apple *> selectedApples;
    if (!grid)
        return selectedApples;

    float left = getLeft();
    float right = getRight();
    float top = getTop();
    float bottom = getBottom();

    for (int row = 0; row < GRID_SIZE; row++)
    {
        for (int col = 0; col < GRID_SIZE; col++)
        {
            Apple *apple = grid->getApple(row, col);
            if (apple && apple->getIsActive())
            {
                Vector2D applePos(apple->getX() + APPLE_SIZE / 2.0f,
                                  apple->getY() + APPLE_SIZE / 2.0f);
                if (applePos.x >= left && applePos.x <= right &&
                    applePos.y >= top && applePos.y <= bottom)
                {
                    selectedApples.push_back(apple);
                }
            }
        }
    }

    return selectedApples;
}

int SelectionBox::calculateSelectedSum(const vector<Apple *> &selectedApples)
{
    int sum = 0;
    for (auto &apple : selectedApples)
    {
        if (apple && apple->getIsActive())
        {
            sum += apple->getValue();
        }
    }
    return sum;
}
