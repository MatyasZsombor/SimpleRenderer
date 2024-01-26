#include "header_files/all_headers.h"


State state;

Wall map[MAP_WIDTH][MAP_HEIGHT];
uint32_t oldTime, curTime;

void init()
{
    parse_map();

    state.window = SDL_CreateWindow("DEMO",SDL_WINDOWPOS_CENTERED_DISPLAY(0),SDL_WINDOWPOS_CENTERED_DISPLAY(0),SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_ALLOW_HIGHDPI);
    state.renderer = SDL_CreateRenderer(state.window, -1, SDL_RENDERER_PRESENTVSYNC);
    state.texture = SDL_CreateTexture(state.renderer,SDL_PIXELFORMAT_ABGR8888,SDL_TEXTUREACCESS_STREAMING,SCREEN_WIDTH,SCREEN_HEIGHT);

    state.rotSpeed = 3.0f * 0.016f;
    state.moveSpeed = 3.0f * 0.016f;

    state.player = Player(22, 12, 0, -1.0f, 0.1f);
    state.plane = Vector(0, 0.66f, 0);
    normalize(state.player.dir);
}

void end()
{
    SDL_DestroyTexture(state.texture);
    SDL_DestroyRenderer(state.renderer);
    SDL_DestroyWindow(state.window);
}

int main()
{
    init();

    while (!state.quit) {
        SDL_Event ev;
        while (SDL_PollEvent(&ev))
        {
            switch (ev.type)
            {
                case SDL_QUIT:
                    state.quit = true;
                    break;
            }
        }

        oldTime = curTime;
        curTime = SDL_GetTicks();
        double frameTime = (curTime - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
        std::cout << (1.0 / frameTime) << "\n";
        state.moveSpeed = frameTime * 5.0;
        state.rotSpeed = frameTime * 3.0;
        if(handle_input())
        {
            break;
        }
        memset(state.pixels, 0, sizeof(state.pixels));
        cast_rays();

        SDL_UpdateTexture(state.texture, nullptr, state.pixels, SCREEN_WIDTH * 4);
        SDL_RenderCopyEx(state.renderer,state.texture,nullptr,nullptr,0.0,nullptr,SDL_FLIP_VERTICAL);
        SDL_RenderPresent(state.renderer);
    }
    end();
    return 0;
}