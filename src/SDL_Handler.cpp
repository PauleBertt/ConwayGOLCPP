#include "SDL_Handler.hpp"

SDL_Handler::SDL_Handler(int size, int tile_width, int tile_height, bool gitter)
{
    int width;
    int height;
    if (gitter) {
        line_width = 1;
        width = size * (tile_width + line_width);
        height = size * (tile_height + line_width);
    } else {
        width = size * tile_width;
        height = size * tile_height;
    }
    //Init
    if (SDL_Init(SDL_INIT_VIDEO)) {
        printf("%s", SDL_GetError());
    }
    window = SDL_CreateWindow("Conways-Game", 0, 0, width, height, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("%s", SDL_GetError());
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        printf("%s", SDL_GetError());
    }
    //Background
    background.h = height;
    background.w = width;
    background.x = 0;
    background.y = 0;
}

void SDL_Handler::drawField(Conway *game, int size, int tile_width, int tile_height)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &background);
    SDL_Rect tile;
    tile.w = tile_width;
    tile.h = tile_height;
    tile.x = 0;
    tile.y = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            tile.x = j * (tile_width + line_width);
            tile.y = i * (tile_height + line_width);
            if (game->is_alive(j, i)) {
                //whatever
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            } else {
                //black
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            }
            SDL_RenderFillRect(renderer, &tile);
        }
    }
    if (m_gitter) {
        drawGitter(size, tile_width, tile_height);
    }
    SDL_RenderPresent(renderer);
}

void SDL_Handler::drawGitter(int size, int tile_width, int tile_height)
{
    //Every Tile Grey Gitter
    for (int i = 0; i < size; i++) {
        //left -> right
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderDrawLine(renderer, 0, i * (tile_width + line_width), size * (tile_width + line_width),
                           i * (tile_width + line_width));
        //top -> down
        SDL_RenderDrawLine(renderer, i * (tile_width + line_width), 0, i * (tile_width + line_width),
                           size * (tile_width + line_width));
    }
    this->line_width = 1;
}
