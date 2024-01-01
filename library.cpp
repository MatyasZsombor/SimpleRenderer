#include <iostream>
#include "header_files/all_headers.h"

#define min(a, b) ({ __typeof__(a) _a = (a), _b = (b); _a < _b ? _a : _b; })
#define max(a, b) ({ __typeof__(a) _a = (a), _b = (b); _a > _b ? _a : _b; })
#define sign(a) ({__typeof__(a) _a = (a); (__typeof__(a))(_a < 0 ? -1 : (_a > 0 ? 1 : 0));})

void cast_rays()
{
    Vector plane = state.plane;
    Player player = state.player;
    for (int x = 0; x < SCREEN_WIDTH; x++) 
    {
        float cameraX = (2 * (x / (float) (SCREEN_WIDTH))) - 1;
        Vector rayDirection = Vector(state.player.dir.x + plane.x * cameraX,state.player.dir.y + plane.y * cameraX);
        Vector mapPos = Vector((int) player.pos.x, (int) player.pos.y);
        Vector deltaDist = Vector(fabsf(rayDirection.x) < 1e-20 ? 1e30 : fabsf(1.0f / rayDirection.x), fabsf(rayDirection.y) < 1e-20 ? 1e30 : fabsf(1.0f / rayDirection.y));
        Vector sideDist = Vector(deltaDist.x * (rayDirection.x < 0 ? (player.pos.x - mapPos.x) : (mapPos.x + 1 - player.pos.x)), deltaDist.y * (rayDirection.y < 0 ? (player.pos.y - mapPos.y) : (mapPos.y + 1 - player.pos.y)));
        Vector step = Vector((int) sign(rayDirection.x), (int) sign(rayDirection.y));

        int side = 0;
        Wall wall = Wall();

        while (!wall.t) {
            if (sideDist.x < sideDist.y)
            {
                sideDist.x += deltaDist.x;
                mapPos.x += step.x;
                side = 0;
            }
            else
            {
                sideDist.y += deltaDist.y;
                mapPos.y += step.y;
                side = 1;
            }
            wall = map[int(mapPos.x)][int(mapPos.y)];
        }

        if (side == 1)
        {
            wall.c.divide(1.5);
        }

        float perpendicularDist = side == 0 ? (sideDist.x - deltaDist.x) : (sideDist.y - deltaDist.y);
        int lineH = (int) (SCREEN_HEIGHT / perpendicularDist),
        y0 = max((SCREEN_HEIGHT / 2) - (lineH / 2), 0),
        y1 = min((SCREEN_HEIGHT / 2) + (lineH / 2), SCREEN_HEIGHT - 1);

        vertical_line(x, 0, y0, 0xFF202020);
        vertical_line(x, y0, y1, wall.c.convert_to_hex());
        vertical_line(x, y1, SCREEN_HEIGHT - 1, 0xFF505050);
    }
}

void vertical_line(int x, int yS, int yE, u32 color)
{
    for (int y = yS; y <= yE; y++)
    {
        state.pixels[y * SCREEN_WIDTH + x] = color;
    }
}

void parse_map()
{
    int x = 0;
    std::ifstream file("/home/poci/Desktop/C++/renderer/map.txt");
    std::string line;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            int y = 0;
            boost::algorithm::trim(line);
            auto tokens = tokenize(line, ';', MAP_WIDTH);
            for (const std::string& wall : tokens)
            {
                Wall curWall;
                if(wall[0] == '0')
                {
                    curWall = Wall();
                }
                else
                {
                    auto properties = tokenize(wall, ',', 4);
                    RGB color = RGB(stoi(properties[1]), stoi(properties[2]), stoi(properties[3]));
                    curWall = Wall(1, color, stof(properties[0]));
                }
                map[x][y] = curWall;
                y++;
            }
            x++;
        }
        file.close();
    }
}

bool handle_input()
{
    const u8 *keyState = SDL_GetKeyboardState(nullptr);
    float rotSpeed = state.rotSpeed,
    moveSpeed = state.moveSpeed;

    if (keyState[SDL_SCANCODE_ESCAPE])
    {
        state.quit = true;
        return true;
    }
    if (keyState[SDL_SCANCODE_LEFT])
    {
        state.player.dir = rotate(state.player.dir, rotSpeed);
        state.plane = rotate(state.plane, rotSpeed);
    }
    if (keyState[SDL_SCANCODE_RIGHT])
    {
        state.player.dir = rotate(state.player.dir, -rotSpeed);
        state.plane = rotate(state.plane, -rotSpeed);
    }
    if (keyState[SDL_SCANCODE_UP])
    {
        if(map[int(state.player.pos.x + state.player.dir.x * moveSpeed)][int(state.player.pos.y)].t == false) { state.player.pos.x += state.player.dir.x * moveSpeed; }
        if(map[int(state.player.pos.x)][int(state.player.pos.y + state.player.dir.y * moveSpeed)].t == false) { state.player.pos.y += state.player.dir.y * moveSpeed; }
    }
    if (keyState[SDL_SCANCODE_DOWN])
    {
        if(map[int(state.player.pos.x - state.player.dir.x * moveSpeed)][int(state.player.pos.y)].t == false) { state.player.pos.x -= state.player.dir.x * moveSpeed; }
        if(map[int(state.player.pos.x)][int(state.player.pos.y - state.player.dir.y * moveSpeed)].t == false) { state.player.pos.y -= state.player.dir.y * moveSpeed; }
    }
    return false;
}

void fill_screen()
{
    for (int y = 0; y < SCREEN_HEIGHT; y++)
    {
        for (int x = 0; x < SCREEN_WIDTH; x++)
        {
            state.pixels[y * SCREEN_WIDTH + x] = 0xFF0000FF;
        }
    }
}