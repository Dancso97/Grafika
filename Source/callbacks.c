//
// Created by Dani on 2019. 04.
//
#include <GL/glut.h>

#include "callbacks.h"
#include "constants.h"
#include "camera.h"
#include "game.h"
#include "light.h"
#include "helpmenu.h"
#include "camera.h"


void setCallbacks() {
    //glut callback-ek beállítása

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouseHandler);
    glutMouseWheelFunc(mouseScrollHandler);
    glutMotionFunc(mouseMotionHandler);
    glutKeyboardFunc(keyboardNormalButtonHandler);
    glutSpecialFunc(keyboardSpecialButtonHandler);
    glutIdleFunc(idle);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    // kirenderelendő részek jönnek ide, például objektumok kirajzolása

    renderCamera();
    renderLight();
    renderGame();
    renderHelpMenuIfVisible();

    glPopMatrix();
    glutSwapBuffers();
}

// az ablak újra méretezését kezeli, megtartva a ASPECT_RATIO-t és VIEWPORT_RATIO-t
void reshape(GLsizei width, GLsizei height) {
    int x, y, w, h;
    double ratio = (double) width / height;
    double viewportRatio = WINDOW_VIEWPORT_RATIO;

    if (ratio > viewportRatio) {
        w = (int) ((double) height * viewportRatio);
        h = height;
        x = (width - w) / 2;
        y = 0;
    } else {
        w = width;
        h = (int) ((double) width / viewportRatio);
        x = 0;
        y = (height - h) / 2;
    }

    glViewport(x, y, w, h);
}

void mouseHandler(int button, int state, int x, int y) {
    cameraMouseHandler(button, state, x, y);

    // újrarenderelés kikényszeríése
    glutPostRedisplay();
}

void mouseScrollHandler(int wheel, int direction, int x, int y) {
    cameraMouseScrollHandler(wheel, direction, x, y);

    // újrarenderelés kikényszeríése
    glutPostRedisplay();
}

void mouseMotionHandler(int x, int y) {
    cameraMouseMotionHandler(x, y);

    // újrarenderelés kikényszeríése
    glutPostRedisplay();
}

void keyboardNormalButtonHandler(unsigned char key, int x, int y) {
    lightKeyboardNormalButtonHandler(key, x, y);

    // újrarenderelés kikényszeríése
    glutPostRedisplay();
}

void keyboardSpecialButtonHandler(int key, int x, int y) {
    helpmenuKeyboardSpecialButtonHandler(key, x, y);

    // újrarenderelés kikényszeríése
    glutPostRedisplay();
}

void idle() {
    // animációhoz callbackek mehetnek ide
    // gyakorlatilag bármi ami háttérfolyamat

    // FONTOS glutPostRedisplay() alapvetően ne tegyünk ide,
    //    mert a program folyamatosan frissíteni fogja a képet (display metódussal) fölöslegesen
	
	const int rotationPeriodTimeInSec = 10;
	
	int currentTime = glutGet(GLUT_ELAPSED_TIME);
	double rotationRatio = (double)currentTime / (rotationPeriodTimeInSec * 1000);
	double rotationPercentage = rotationRatio - (int) rotationRatio;
	
	double rotationDegree = 360 * rotationPercentage;
	updateAnimatedObject(rotationDegree);
	glutPostRedisplay();
}

