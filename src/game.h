// game loop and state management
#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <string>

enum class GameState
{
    MENU,
    PLAYING,
    GAME_OVER,
    WIN
};

class Game
{
private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    GameState currentState;

public:
    Game();
    ~Game();

    void run();                                                 // main game loop
    bool init(const std::string &title, int width, int height); // initialize game
    void handleEvents();                                        // process input
    void update();                                              // update game state
    void render();                                              // render to screen
    void clean();                                               // clean up resources

    // state management
    void switchState(GameState newState);
    GameState getCurrentState() const { return currentState; };
};

#endif // GAME_H