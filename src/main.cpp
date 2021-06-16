#include <iostream>
#include "Conway.hpp"
#include "SDL_Handler.hpp"
int main()
{
    int gameSize = 100;
    ///WINDOW settings
    int tile_width = 5;
    int tile_height = 5;
    Conway *game;
    game = new Conway(gameSize);


    SDL_Handler handler(gameSize, tile_width, tile_height, false);

    //To store the event
    SDL_Event event;

    bool running_auto = true;

    const Uint8 *currentKeyStates;

    while (true) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return -1;
            }
            currentKeyStates = SDL_GetKeyboardState(NULL);
            if (currentKeyStates[SDL_SCANCODE_SPACE]) {
                if (event.type == SDL_KEYDOWN) {
                    running_auto = !running_auto;
                }
            }
            if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
                if (event.type == SDL_KEYDOWN && !running_auto) {
                    handler.drawField(game, gameSize, tile_width, tile_height);
                    game->upate();
                }
            }
            if (currentKeyStates[SDL_SCANCODE_C]) {
                //Clear Board
                if (event.type == SDL_KEYDOWN) {
                    game->clearField();
                }
            }
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                //Position of Mouse
                int x;
                int y;
                SDL_GetMouseState(&x, &y);

                //Calc tile pos
                x = x / tile_width;
                y = y / tile_height;

                game->changeState(x, y);
                handler.drawField(game, gameSize, tile_width, tile_height);
            }
            if (currentKeyStates[SDL_SCANCODE_ESCAPE]) {
                return -1;
            }
        }
        if (running_auto) {
            handler.drawField(game, gameSize, tile_width, tile_height);
            game->upate();
        }
        SDL_Delay(10);
    }
}
