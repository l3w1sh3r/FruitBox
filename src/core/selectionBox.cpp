#include "selectionBox.h"

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
