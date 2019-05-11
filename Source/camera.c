//
// Created by Dani on 2019. 04.
//

#include <GL/glut.h>
#include <math.h>
#include <stdbool.h>

#include "camera.h"
#include "constants.h"

Camera camera;

void initCamera() {
    camera.zoomFactor = 7.0;
    camera.horizontalAngleRadian = M_PI / 2;
    camera.verticalAngleRadian = M_PI / 4;
    camera.startCapturingMouseMovement = FALSE;
    camera.mouseOriginalPositionX = 0;
    camera.mouseOriginalPositionY = 0;
}

void renderCamera() {
    gluLookAt(
            cos(camera.horizontalAngleRadian) * cos(camera.verticalAngleRadian) * camera.zoomFactor,
            sin(camera.verticalAngleRadian) * camera.zoomFactor,
            sin(camera.horizontalAngleRadian) * cos(camera.verticalAngleRadian) * camera.zoomFactor,
            0.0, 0.0, 0.0,
            cos(camera.horizontalAngleRadian) * cos(camera.verticalAngleRadian + (M_PI / 2)),
            sin(camera.verticalAngleRadian + (M_PI / 2)),
            sin(camera.horizontalAngleRadian) * cos(camera.verticalAngleRadian + (M_PI / 2))
    );
}

void cameraMouseHandler(int button, int state, int x, int y) {
// only	start motion if the left button is pressed
    if (button == GLUT_MIDDLE_BUTTON) {

        // when the button is released
        if (state == GLUT_UP) {
            camera.startCapturingMouseMovement = FALSE;
        }
        // when the button is pressed
        if (state == GLUT_DOWN) {
            camera.startCapturingMouseMovement = TRUE;
            camera.mouseOriginalPositionX = x;
            camera.mouseOriginalPositionY = y;
        }
    }

}

void cameraMouseScrollHandler(int wheel, int direction, int x, int y) {
    direction = direction * (-1);
    camera.zoomFactor += 0.1 * direction;

    if (camera.zoomFactor > 17.0) {
        camera.zoomFactor = 17.0;
    }
    if (camera.zoomFactor < 7.0) {
        camera.zoomFactor = 7.0;
    }
}

void cameraMouseMotionHandler(int x, int y) {
    if (camera.startCapturingMouseMovement) {

        // update angles
        camera.horizontalAngleRadian += (x - camera.mouseOriginalPositionX) * 0.01;
        camera.verticalAngleRadian += (y - camera.mouseOriginalPositionY) * 0.01;

        // check limits
        if (camera.verticalAngleRadian < 0) {
            camera.verticalAngleRadian = 0;
        }
        if (camera.verticalAngleRadian > (M_PI / 2)) {
            camera.verticalAngleRadian = (M_PI / 2);
        }

        // refresh mouse position
        camera.mouseOriginalPositionY = y;
        camera.mouseOriginalPositionX = x;
    }
}

