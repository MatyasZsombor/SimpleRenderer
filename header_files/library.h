#ifndef RENDERER_LIBRARY_H
#define RENDERER_LIBRARY_H
#include "all_headers.h"

extern State state;
extern Wall map[MAP_WIDTH][MAP_HEIGHT];
bool handle_input();
void vertical_line(int x, int y0, int y, u32 color);
void parse_map();
void cast_rays();
void fill_screen();
#endif //RENDERER_LIBRARY_H
