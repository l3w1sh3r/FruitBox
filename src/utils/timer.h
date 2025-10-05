// time management

#ifndef TIMER_H
#define TIMER_H

#include <SDL.h>

class Timer
{
private:
    Uint32 lastTick;
    float deltaTime;   // time difference between frames in seconds
    float elapsedTime; // total accumulated time since start in seconds
public:
    Timer();

    void reset();  // reset timer
    void update(); // update delta time each frame

    float getDeltaTime() const;
    float getElapsedTime() const;
};

#endif // TIMER_H