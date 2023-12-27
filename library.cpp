#include "header_files/all_headers.h"

float dx, dy;

void cast_rays(const int map[], int h, int w)
{
    glColor3f(0,1,1); glBegin(GL_QUADS); glVertex2i(526,  0); glVertex2i(1006,  0); glVertex2i(1006,160); glVertex2i(526,160); glEnd();
    glColor3f(0,0,1); glBegin(GL_QUADS); glVertex2i(526,160); glVertex2i(1006,160); glVertex2i(1006,320); glVertex2i(526,320); glEnd();

    float xO, yO, rayY, rayX;
    int mapPos;
    float rAngle = player.angle - DEGREE * 30;
    if(rAngle < 0){ rAngle += 2 * PI; }
    if(rAngle > 2 * PI) { rAngle -= 2 * PI; }

    for (int numR = 0; numR < 60; numR++)
    {
        int depthOfField = 0;
        float aTan = -1 / tanf(rAngle);
        float hDist = FLT_MAX, hX = player.pos.x, hY = player.pos.y;

        if(rAngle > M_PIf)
        {
            rayY = (((int)(player.pos.y)>>6)<<6) - 0.0001; // NOLINT(*-narrowing-conversions)
            rayX = (player.pos.y - rayY) * aTan + player.pos.x;
            yO = (float)-(w * h);
            xO = -yO * aTan;
        }
        if(rAngle < M_PIf)
        {
            rayY = (((int)player.pos.y>>6)<<6) + (w * h); // NOLINT(*-narrowing-conversions)
            rayX = (player.pos.y - rayY) * aTan + player.pos.x;
            yO = (float)(w * h);
            xO = -yO * aTan;
        }
        if(rAngle == 0 || rAngle == M_PIf)
        {
            rayX = player.pos.x;
            rayY = player.pos.y;
            depthOfField = 8;
        }

        while(depthOfField < 8)
        {
            int mapX = (int) (rayX)>>6;
            int mapY = (int) (rayY)>>6;
            mapPos = mapY * w + mapX;

            if(mapPos > 0 && mapPos < w * h && map[mapPos] > 0)
            {
                hX = rayX, hY = rayY;
                hDist = distance(hX, hY, player.pos.x, player.pos.y);
                depthOfField = 8;
            }
            else{ rayX += xO; rayY += yO; depthOfField += 1; }
        }

        float nTan = -tanf(rAngle);
        depthOfField = 0;
        float vDist = FLT_MAX, vX = player.pos.x, vY = player.pos.y;

        if(rAngle > PI / 2 && rAngle < 3 * PI / 2)
        {
            rayX = (((int)(player.pos.x)>>6)<<6) - 0.0001; // NOLINT(*-narrowing-conversions)
            rayY = (player.pos.x - rayX) * nTan + player.pos.y;
            xO = (float)-(w * h);
            yO = -xO * nTan;
        }
        if(rAngle < PI / 2 || rAngle > 3 * PI / 2)
        {
            rayX = (((int)player.pos.x>>6)<<6) + (w * h); // NOLINT(*-narrowing-conversions)
            rayY = (player.pos.x - rayX) * nTan + player.pos.y;
            xO = (float)(w * h);
            yO = -xO * nTan;
        }
        if(rAngle == 0 || rAngle == PI)
        {
            rayX = player.pos.x;
            rayY = player.pos.y;
            depthOfField = 8;
        }

        while(depthOfField < 8)
        {
            int mapX = (int) (rayX)>>6;
            int mapY = (int) (rayY)>>6;
            mapPos = mapY * w + mapX;

            if(mapPos > 0 && mapPos < w * h && map[mapPos] > 0)
            {
                vX = rayX, vY = rayY;
                vDist = distance(vX, vY, player.pos.x, player.pos.y);
                depthOfField = 8;
            }
            else{ rayX += xO; rayY += yO; depthOfField += 1; }
        }

        float fDist;
        if(vDist < hDist)
        {
            rayX = vX, rayY = vY; fDist = vDist;
            glColor3f(0.9, 0 , 0);
        }
        if(hDist < vDist)
        {
            rayX = hX, rayY = hY; fDist = hDist;
            glColor3f(0.7f, 0, 0);
        }

        glLineWidth(3);
        glBegin(GL_LINES);
        glVertex2f(player.pos.x, player.pos.y);
        glVertex2f(rayX, rayY);
        glEnd();

        float correctAngle = player.angle - rAngle;

        if(correctAngle < 0){ correctAngle += 2 * PI; }
        if(correctAngle > 2 * PI) { correctAngle -= 2 * PI; }

        fDist *= cosf(correctAngle);
        float lineHeight = (float)(w * h * 320) / fDist;
        float lineOffset = 160 - lineHeight / 2;
        if(lineHeight  > 320) { lineHeight = 320; }

        glLineWidth(8);
        glBegin(GL_LINES);
        glVertex2f((float)numR * 8 + 530, lineOffset);
        glVertex2f((float)numR * 8 + 530, lineHeight + lineOffset);

        rAngle += DEGREE;
        if(rAngle < 0){ rAngle += 2 * PI; }
        if(rAngle > 2 * PI) { rAngle -= 2 * PI; }
    }
}

void draw_player()
{
    glColor3f(1, 1, 0);
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2f(player.pos.x, player.pos.y);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(player.pos.x, player.pos.y);
    glVertex2f(player.pos.x + dx * 5, player.pos.y + dy * 5);
    glEnd();
}

void inputs(unsigned char key, int x, int y)
{
    if(key == 'a')
    {
        player.angle -= 0.1;
        if(player.angle < 0){player.angle += 2 * PI;}
        dx = cosf(player.angle) * 5;
        dy = sinf(player.angle) * 5;
    }
    if(key == 'd')
    {
        player.angle += 0.1;
        if(player.angle > 2 * PI){player.angle -= 2 * PI;}
        dx = cosf(player.angle) * 5;
        dy = sinf(player.angle) * 5;
    }
    if(key == 'w')
    {
        player.pos.x += dx;
        player.pos.y += dy;
    }
    if(key == 's')
    {
        player.pos.x -= dx;
        player.pos.y -= dy;
    }
    glutPostRedisplay();
}

void draw_map2d(const int map[], int h, int w)
{
    for (int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(map[i * w + j] == 1){ glColor3f(1,1,1); }
            else { glColor3f(0, 0, 0); }
            int xO = j * h * w, yO = i * h * w;
            glBegin(GL_QUADS);
            glVertex2i(xO + 1, yO + 1);
            glVertex2i(xO + 1, yO + w * h - 1);
            glVertex2i(xO + w * h - 1, yO + w * h- 1);
            glVertex2i(xO + w * h - 1, yO + 1);
        }
    }
    glEnd();
}