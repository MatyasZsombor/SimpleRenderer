//
// Created by poci on 12/27/23.
//
#include "all_headers.h"
#ifndef RENDERER_PLAYER_H
#define RENDERER_PLAYER_H
struct Player{
public:
    Vector pos;
    float angle;
    explicit Player(float x = 0, float y = 0, float z = 0, float a = 0)
    {
        pos = Vector(x, y, z);
        angle = a;
    }
};
#endif //RENDERER_PLAYER_H
