//
// Created by Dani on 2019. 04
//

#include <GL/glut.h>

#include "../Include/constants.h"
#include "../Include/callbacks.h"
#include "../Include/camera.h"
#include "../Include/game.h"
#include "../Include/light.h"
#include "../Include/helpmenu.h"

void initOpenGLConfig() {
    glShadeModel(GL_SMOOTH);
    glEnable(GL_NORMALIZE);
    glEnable(GL_AUTO_NORMAL);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0);

    //camera projekció beállítása
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(WINDOW_ASPECT_RATIO, WINDOW_VIEWPORT_RATIO, 0.01, 1000.0);
    //

    //textúra beállítások
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glEnable(GL_TEXTURE_2D);
    //
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(WINDOW_DEFAULT_WIDTH, WINDOW_DEFAULT_HEIGHT);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    int window = glutCreateWindow("Tutorial_1");
    glutSetWindow(window);

    initOpenGLConfig();
    initCamera();
    initLight();
    initGame();
    initHelpMenu();

    setCallbacks();

    glutMainLoop();
    return 0;
}
