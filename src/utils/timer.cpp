#include "Timer.h"

Timer::Timer()
{
    reset();
}

void Timer::reset()
{
    lastTick = SDL_GetTicks(); // get current ticks
    deltaTime = 0.0f;
    elapsedTime = 0.0f;
}

void Timer::update()
{
    Uint32 currentTick = SDL_GetTicks();
    deltaTime = (currentTick - lastTick) / 1000.0f; // convert ms to seconds
    elapsedTime += deltaTime;
    lastTick = currentTick;
}

float Timer::getDeltaTime() const
{
    return deltaTime;
}

float Timer::getElapsedTime() const
{
    return elapsedTime;
}