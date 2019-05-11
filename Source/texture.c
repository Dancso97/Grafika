//
// Created by Dani on 2019. 04
//

#include <GL/glut.h>
#include <SOIL/SOIL.h>
#include <stdio.h>

#include "texture.h"
#include "constants.h"

void loadTexture(Texture *texture, const char filename[100]) {
    glGenTextures(1, &texture->id);

    int width;
    int height;

    texture->image = (Pixel *) SOIL_load_image(filename, &width, &height, 0, SOIL_LOAD_RGBA);
    if (texture->image == NULL) {
        printf("Could not load texture: %s\n", filename);
        printf("The error was: %s\n", SOIL_last_result());
    } else {
        printf("Texture loaded: %s\n", filename);
    }

    glBindTexture(GL_TEXTURE_2D, texture->id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, (Pixel *) texture->image);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    float border_color[4] = {0, 0, 0, 0.7};
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, border_color);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}
