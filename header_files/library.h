#ifndef RENDERER_LIBRARY_H
#define RENDERER_LIBRARY_H
#include "all_headers.h"
#define PI M_PIf
#define FLT_MAX std::numeric_limits<float>::max()
#define DEGREE (PI / 180)
extern Player player;
void draw_map2d(const int map[], int h, int w);
void draw_player();
void inputs(unsigned char key, int x, int y);
void cast_rays(const int map[], int h, int w);
#endif //RENDERER_LIBRARY_H
