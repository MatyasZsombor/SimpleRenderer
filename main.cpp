#include "header_files/all_headers.h"

Player player = Player();

const int map[] = {
1,1,1,1,1,1,1,1,
1,0,0,0,1,0,0,1,
1,0,0,0,0,0,0,1,
1,0,0,1,0,0,0,1,
1,1,0,0,0,0,0,1,
1,0,1,0,1,0,0,1,
1,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1
};

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw_map2d(map, 8, 8);
    cast_rays(map, 8, 8);
    draw_player();
    glutSwapBuffers();
}

void init()
{

    glClearColor(0.3, 0.3, 0.3, 0);
    gluOrtho2D(0, 1024, 512, 0);
    player.pos.x = 300;
    player.pos.y = 300;
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1024, 512);
    glutCreateWindow("Simple Ray caster");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(inputs);
    glutMainLoop();
    return 0;
}
