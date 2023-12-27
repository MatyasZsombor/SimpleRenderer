#ifndef RENDERER_LIBRARY_H
#define RENDERER_LIBRARY_H
#include "all_headers.h"
#include "constants.h"

extern Player player;
extern Vector cameraPlane;
extern int map[MAP_WIDTH][MAP_HEIGHT];
extern Vector dir;
extern double moveSpeed;
extern double rotSpeed;
void draw_map2d(int map[MAP_WIDTH][MAP_HEIGHT]);
void draw_player();
void inputs(unsigned char key, int x, int y);
void cast_rays();
#endif //RENDERER_LIBRARY_H
