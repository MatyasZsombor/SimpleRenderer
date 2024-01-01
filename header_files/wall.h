//
// Created by poci on 1/1/24.
//

#ifndef RENDERER_WALL_H
#define RENDERER_WALL_H
#include "all_headers.h"

struct Wall{
public:
    int t;
    RGB c;
    float h;

    explicit Wall(int type = 0, RGB color = RGB(0,0,0), float height = 1)
    {
        t = type;
        c = color;
        h = height;
    }
};


#endif //RENDERER_WALL_H
