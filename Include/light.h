//
// Created by Dani on 2019. 04.
//

#ifndef LIGHT_H
#define LIGHT_H

#include <GL/glut.h>

typedef struct Light {
    GLenum id;
    GLfloat position[4];
    GLfloat color[4];
    double intensity;
} Light;

void initLight();

void disableGlobalAmbientLight();

void lightKeyboardNormalButtonHandler(unsigned char key, int x, int y);

void renderLight();

#endif //LIGHT_H
