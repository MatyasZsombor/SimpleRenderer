//
// Created by poci on 12/29/23.
//

#ifndef RENDERER_STATE_H
#define RENDERER_STATE_H
#include "all_headers.h"
struct State{
    SDL_Window *window{};
    SDL_Texture *texture{};
    SDL_Renderer *renderer{};
    uint pixels[SCREEN_WIDTH * SCREEN_HEIGHT]{};
    bool quit{};
    Player player;
    Vector plane;
};
#endif //RENDERER_STATE_H
