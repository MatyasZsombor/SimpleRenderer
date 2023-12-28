#include <iostream>
#include "header_files/all_headers.h"

void cast_rays()
{
    for(int x = 0; x < SCREEN_WIDTH; x++)
    {
        float cameraX = 2 * x / float(SCREEN_WIDTH - 1);

        Vector rayDir = Vector(player.dir.x + cameraPlane.x * cameraX, player.dir.y + cameraPlane.y * cameraX);
        Vector mapPos = Vector(int(player.pos.x), int(player.pos.y));
        Vector sideDist = Vector();
        Vector deltaDist = Vector(rayDir.x == 0 ? 1e30 : std::abs(1 / rayDir.x), rayDir.y == 0 ? 1e30 : std::abs(1 / rayDir.y));
        Vector step = Vector();

        float perpWallDist;
        int hit = 0;
        int side;

        if(rayDir.x < 0)
        {
            step.x = -1;
            sideDist.x = (player.pos.x - mapPos.x) * deltaDist.x;
        }
        else
        {
            step.x = 1;
            sideDist.x = (mapPos.x + 1.0 - player.pos.x) * deltaDist.x;
        }
        if(rayDir.y < 0)
        {
            step.y = -1;
            sideDist.y = (player.pos.y - mapPos.y) * deltaDist.y;
        }
        else
        {
            step.y = 1;
            sideDist.y = (mapPos.y + 1.0 - player.pos.y) * deltaDist.y;
        }

        while(hit == 0)
        {
            if(sideDist.x < sideDist.y)
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
            if(map[int(mapPos.x)][int(mapPos.y)] > 0) { hit = 1; }
        }

        if(side == 0) { perpWallDist = (sideDist.x - deltaDist.x); }
        else { perpWallDist = (sideDist.y - deltaDist.y); }

        int lineH = (int)(SCREEN_HEIGHT / perpWallDist);

        int start = -lineH / 2 + SCREEN_HEIGHT / 2;
        if(start < 0) { start = 0; }
        int end = lineH / 2 + SCREEN_HEIGHT / 2;
        if(end >= SCREEN_HEIGHT) { end = SCREEN_HEIGHT - 1; }

        RGB color;
        switch(map[int(mapPos.x)][int(mapPos.y)])
        {
            case 1:  color = RGB(1, 0, 0);  break; //red
            case 2:  color = RGB(0, 1, 0);  break; //green
            case 3:  color = RGB(0, 0, 1);   break; //blue
            case 4:  color = RGB(1, 1, 1);  break; //white
            default: color = RGB(1, 1, 0); break; //yellow
        }

        if (side == 1) {color.divide(2);}
        Vector s = Vector(x, start);
        Vector e = Vector(x, end);
        draw_line(s, e, 1, color);
    }
}

void draw_line(Vector s, Vector e, int w, RGB color)
{
    glColor3f(color.red, color.green, color.blue);
    glLineWidth(w);
    glBegin(GL_LINES);
    glVertex2f(s.x, s.y);
    glVertex2f(e.x, e.y);
    glEnd();
}

void inputs(unsigned char key, int x, int y)
{
    if(key == 'w')
    {
        if(map[int(player.pos.x + player.dir.x * moveSpeed)][int(player.pos.y)] == 0) { player.pos.x += player.dir.x * moveSpeed; }
        if(map[int(player.pos.x)][int(player.pos.y + player.dir.y * moveSpeed)] == 0) { player.pos.y += player.dir.y * moveSpeed; }
    }
    if(key == 's')
    {
        if(map[int(player.pos.x - player.dir.x * moveSpeed)][int(player.pos.y)] == 0) { player.pos.x -= player.dir.x * moveSpeed; }
        if(map[int(player.pos.x)][int(player.pos.y - player.dir.y * moveSpeed)] == 0) { player.pos.y -= player.dir.y * moveSpeed; }
    }
    if (key == 'd')
    {
        double oldDirX = player.dir.x;
        player.dir = Vector(player.dir.x * cosf(-rotSpeed) - player.dir.y * sinf(-rotSpeed), oldDirX * sinf(-rotSpeed) + player.dir.y * cosf(-rotSpeed));
        double oldPlaneX = cameraPlane.x;
        cameraPlane = Vector(cameraPlane.x * cosf(-rotSpeed) - cameraPlane.y * sin(-rotSpeed), oldPlaneX * sin(-rotSpeed) + cameraPlane.y * cos(-rotSpeed));
    }
    if (key == 'a')
    {
        double oldDirX = player.dir.x;
        player.dir = Vector(player.dir.x * cosf(rotSpeed) - player.dir.y * sinf(rotSpeed), oldDirX * sinf(rotSpeed) + player.dir.y * cosf(rotSpeed));
        double oldPlaneX = cameraPlane.x;
        cameraPlane = Vector(cameraPlane.x * cosf(rotSpeed) - cameraPlane.y * sin(rotSpeed), oldPlaneX * sinf(rotSpeed) + cameraPlane.y * cosf(rotSpeed));
    }
    if(key == 27)
    {
        exit(0);
    }
    std::cout << player.dir.x << std::endl;
    std::cout << player.dir.y << std::endl;
    glutPostRedisplay();
}