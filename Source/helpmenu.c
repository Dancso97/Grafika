//
// Created by Dani on 2019. 04
//

#include <GL/glut.h>
#include <stdbool.h>

#include "texture.h"
#include "constants.h"
#include "helpmenu.h"

HelpMenu helpMenu;

void initHelpMenu() {
    helpMenu.isShown = false;
    loadTexture(&(helpMenu.texture), "Texture/help.png");
    // ezt a képet fogjuk megjeleníteni mint help menüt
}

void helpmenuKeyboardSpecialButtonHandler(int key, int x, int y) {
    if (key == GLUT_KEY_F1) {
        helpMenu.isShown = !helpMenu.isShown;
    }
}

void renderHelpMenuIfVisible() {
    if (helpMenu.isShown) {
        renderHelpMenu();
    }
}

void renderHelpMenu() {
    glPushMatrix();
    GLint viewport[4];
    GLdouble modelview[16];
    GLdouble projection[16];
    double w = glutGet(GLUT_WINDOW_WIDTH);
    double h = glutGet(GLUT_WINDOW_HEIGHT);
    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    glGetIntegerv(GL_VIEWPORT, viewport);
    double depth = 0.01;

    GLdouble upRight[3];
    GLdouble upLeft[3];
    GLdouble downRight[3];
    GLdouble downLeft[3];

    gluUnProject(w, h, depth, modelview, projection, viewport, &upRight[0], &upRight[1], &upRight[2]);
    gluUnProject(0, h, depth, modelview, projection, viewport, &upLeft[0], &upLeft[1], &upLeft[2]);
    gluUnProject(w, 0, depth, modelview, projection, viewport, &downRight[0], &downRight[1], &downRight[2]);
    gluUnProject(0, 0, depth, modelview, projection, viewport, &downLeft[0], &downLeft[1], &downLeft[2]);

    double hRatio;
    double wRatio;
    if (h > w) {
        hRatio = (double) h / w;
        wRatio = 1.0;
    } else {
        hRatio = 1.0;
        wRatio = (double) w / h;
    }

    glDisable(GL_LIGHTING);
    glBindTexture(GL_TEXTURE_2D, helpMenu.texture.id);
    glBegin(GL_QUADS);
    glTexCoord2f(-((wRatio - 1) / 2), hRatio - ((hRatio - 1) / 2));
    glVertex3f(downLeft[0], downLeft[1], downLeft[2]);

    glTexCoord2f(wRatio - ((wRatio - 1) / 2), hRatio - ((hRatio - 1) / 2));
    glVertex3f(downRight[0], downRight[1], downRight[2]);

    glTexCoord2f(wRatio - ((wRatio - 1) / 2), -(hRatio - 1) / 2);
    glVertex3f(upRight[0], upRight[1], upRight[2]);

    glTexCoord2f(-((wRatio - 1) / 2), -(hRatio - 1) / 2);
    glVertex3f(upLeft[0], upLeft[1], upLeft[2]);
    glEnd();
    glEnable(GL_LIGHTING);

    glPopMatrix();
}
