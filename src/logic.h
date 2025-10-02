#ifndef LOGIC_H
#define LOGIC_H

#include <SDL.h>

class Logic
{
public:
    Logic();
    ~Logic();

    void handleEvent(const SDL_Event &e);
    void update();
};

#endif // LOGIC_H