// selection box management

#ifndef SELECTIONBOX_H
#define SELECTIONBOX_H

#include <SDL.h>
#include <algorithm>
#include "../utils/vector2d.h"
#include "grid.h"

using namespace std;

class Apple; // forward declaration

class SelectionBox
{
private:
    Vector2D startPoint;
    Vector2D endPoint;
    bool isSelecting;

    SDL_Renderer *renderer;

public:
    SelectionBox(SDL_Renderer *renderer);

    void startSelection(const Vector2D &pos);
    void updateSelection(const Vector2D &pos);
    void endSelection();

    void render();

    bool getIsSelecting() const { return isSelecting; }

    // get selected rectangle
    float getLeft() const { return min(startPoint.x, endPoint.x); }
    float getRight() const { return max(startPoint.x, endPoint.x); }
    float getTop() const { return min(startPoint.y, endPoint.y); }
    float getBottom() const { return max(startPoint.y, endPoint.y); }

    vector<Apple *> getSelectedApples(Grid *grid);

    int calculateSelectedSum(const vector<Apple *> &selectedApples);
};

#endif // SELECTIONBOX_H