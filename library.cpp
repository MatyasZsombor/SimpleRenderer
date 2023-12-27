#include "header_files/all_headers.h"

void cast_rays()
{
    for(int x = 0; x < SCREEN_WIDTH; x++)
    {
        float cameraX = 2 * x / float(SCREEN_WIDTH - 1);

        Vector rayDir = Vector(dir.x + cameraPlane.x * cameraX, dir.y + cameraPlane.y * cameraX);
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

        int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

        int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
        if(drawStart < 0) { drawStart = 0; }
        int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
        if(drawEnd >= SCREEN_HEIGHT) { drawEnd = SCREEN_HEIGHT - 1; }

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

        glColor3f(color.red, color.green, color.blue);
        glLineWidth(1);
        glBegin(GL_LINES);
        glVertex2f(x, drawStart);
        glVertex2f(x, drawEnd);
        glEnd();
    }
}

void inputs(unsigned char key, int x, int y)
{
    if(key == 'w')
    {
        player.pos.x += dir.x * 2;
        player.pos.y += dir.y * 2;
    }
    if(key == 's')
    {
        player.pos.x -= dir.x * 2;
        player.pos.y -= dir.y * 2;
    }
    if(key == 27)
    {
        exit(0);
    }
    glutPostRedisplay();
}