#include "inputManager.h"

using namespace std;

InputManager::InputManager() : mouseX(0), mouseY(0), mousePressed(false) {}

void InputManager::handleEvent(const SDL_Event &e)
{
    switch (e.type)
    {
    case SDL_MOUSEBUTTONDOWN:
        if (e.button.button == SDL_BUTTON_LEFT)
        {
            mousePressed = true;
            mouseX = e.button.x;
            mouseY = e.button.y;
            cout << "Mouse Down at (" << mouseX << ", " << mouseY << ")\n";
        }
        break;

    case SDL_MOUSEBUTTONUP:
        if (e.button.button == SDL_BUTTON_LEFT)
        {
            mousePressed = false;
            mouseX = e.button.x;
            mouseY = e.button.y;
            cout << "Mouse Up at (" << mouseX << ", " << mouseY << ")\n";
        }
        break;

    case SDL_MOUSEMOTION:
        mouseX = e.motion.x;
        mouseY = e.motion.y;
        if (mousePressed)
        {
            cout << "Mouse Move at (" << mouseX << ", " << mouseY << ")\n";
        }
        break;

    default:
        break;
    }
}

void InputManager::update()
{
    // updating
}