//
// Created by poci on 12/27/23.
//
#include "all_headers.h"
#ifndef RENDERER_PLAYER_H
#define RENDERER_PLAYER_H
struct Player{
public:
    Vector pos;
    double angle;
    explicit Player(double x = 0, double y = 0, double z = 0, double a = 0)
    {
        pos = Vector(x, y, z);
        angle = a;
    }
};
#endif //RENDERER_PLAYER_H
