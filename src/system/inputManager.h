// handle mouse and keyboard input

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SDL.h>
#include <iostream>

class InputManager
{
private:
    int mouseX, mouseY;
    bool mousePressed;

public:
    InputManager();

    void handleEvent(const SDL_Event &e);
    void update();

    int getMouseX() const { return mouseX; }
    int getMouseY() const { return mouseY; }
    bool isMousePressed() const { return mousePressed; }
};

#endif // INPUTMANAGER_H