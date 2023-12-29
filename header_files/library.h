#ifndef RENDERER_LIBRARY_H
#define RENDERER_LIBRARY_H
#include "all_headers.h"

extern State state;
extern int map[MAP_WIDTH * MAP_HEIGHT];
void draw_line(Vector s, Vector e, int w, RGB color);
void cast_rays();
void fill_screen();
#endif //RENDERER_LIBRARY_H
