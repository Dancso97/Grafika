//
// Created by Dani on 2019. 04
//

#include <GL/glut.h>

#include "../Include/light.h"
#include "../Include/constants.h"

Light light;

void initLight() {
    light.id = GL_LIGHT0;

    light.position[0] = 100.0;   //x
    light.position[1] = 100.0;   //y
    light.position[2] = 100.0;   //z
    light.position[3] = 0.0;     //4. dimenzió

    light.color[0] = 1.0;        //Red
    light.color[1] = 1.0;        //Green
    light.color[2] = 1.0;        //Blue
    light.color[3] = 1.0;        //Alpha

    light.intensity = 1.0;

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    disableGlobalAmbientLight();
}

void disableGlobalAmbientLight() {
    GLfloat glob_ambient[] = {0.0, 0.0, 0.0, 1.0};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, glob_ambient);
}

void lightKeyboardNormalButtonHandler(unsigned char key, int x, int y) {
    switch (key) {
        case '+':
            light.intensity += 0.025;
            break;
        case '-':
            light.intensity -= 0.025;
            break;
    }

    if (light.intensity > 1.5) {
        light.intensity = 1.5;
    }
    if (light.intensity < 0.0) {
        light.intensity = 0.0;
    }
}

void renderLight() {

    GLfloat colorCorrectedByIntensity[] =
            {
                    light.color[0] * light.intensity,
                    light.color[1] * light.intensity,
                    light.color[2] * light.intensity,
                    light.color[3]
            };

    glLightfv(light.id, GL_POSITION, light.position);
    glLightfv(light.id, GL_AMBIENT, colorCorrectedByIntensity);
    glLightfv(light.id, GL_DIFFUSE, colorCorrectedByIntensity);
    glLightfv(light.id, GL_SPECULAR, colorCorrectedByIntensity);
}
