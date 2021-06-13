#ifndef UNTITLED1_SDL_HANDLER_HPP
#define UNTITLED1_SDL_HANDLER_HPP


#include <SDL.h>
#include "Conway.hpp"

class SDL_Handler
{
public:
    SDL_Handler(int size, int tile_width, int tile_height, bool gitter);

    void drawField(Conway *game, int size, int tile_width, int tile_height);

private:
    SDL_Rect background;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *surface;
    ///DrawGitter
    int line_width = 0;
    bool m_gitter = false;

    void drawGitter(int size, int tile_width, int tile_height);

};


#endif //UNTITLED1_SDL_HANDLER_HPP
