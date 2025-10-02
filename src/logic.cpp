#include "logic.h"
#include <iostream>

using namespace std;

Logic::Logic() {}
Logic::~Logic() {}

void Logic::handleEvent(const SDL_Event &e)
{
    if (e.type == SDL_KEYDOWN)
    {
        cout << "Key pressed: " << SDL_GetKeyName(e.key.keysym.sym) << endl;
    }
}

void Logic::update()
{
}