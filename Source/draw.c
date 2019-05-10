//
// Created by Dani on 2019. 04
//

#include <GL/glut.h>

#include "../Include/draw.h"
#include "../Include/model.h"
#include "../Include/constants.h"

void draw_triangles(const struct Model *model) {
    int i, k;
    int vertex_index, texture_index, normal_index;
    double x, y, z, normal_x, normal_y, normal_z, u, v;

    glBegin(GL_TRIANGLES);

    for (i = 0; i < model->n_triangles; ++i) {
        for (k = 0; k < 3; ++k) {

            texture_index = model->triangles[i].points[k].texture_index;
            u = model->texture_vertices[texture_index].u;
            v = model->texture_vertices[texture_index].v;
            glTexCoord2f(u, 1 - v);

            normal_index = model->triangles[i].points[k].normal_index;
            normal_x = model->normals[normal_index].x;
            normal_y = model->normals[normal_index].y;
            normal_z = model->normals[normal_index].z;
            glNormal3d(normal_x, normal_y, normal_z);

            vertex_index = model->triangles[i].points[k].vertex_index;
            x = model->vertices[vertex_index].x;
            y = model->vertices[vertex_index].y;
            z = model->vertices[vertex_index].z;
            glVertex3d(x, y, z);
        }
    }

    glEnd();
}

void draw_quads(const struct Model *model) {
    int i, k;
    int vertex_index, texture_index, normal_index;
    double x, y, z, u, v;

    glBegin(GL_QUADS);

    for (i = 0; i < model->n_quads; ++i) {
        for (k = 0; k < 4; ++k) {

            texture_index = model->quads[i].points[k].texture_index;
            u = model->texture_vertices[texture_index].u;
            v = model->texture_vertices[texture_index].v;
            // NOTE: The 1-v is model file specific!
            glTexCoord2f(u, 1 - v);

            vertex_index = model->quads[i].points[k].vertex_index;
            x = model->vertices[vertex_index].x;
            y = model->vertices[vertex_index].y;
            z = model->vertices[vertex_index].z;
            glVertex3d(x, y, z);
        }
    }

    glEnd();
}

void draw_model(const struct Model *model) {
    draw_triangles(model);
}

void draw_Sky(GLuint texture){
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    // elől
    glTexCoord2d(0, 0); glVertex3d(80, 0, 0);
    glTexCoord2d(1, 0); glVertex3d(80, 80, 0);
    glTexCoord2d(1, 1); glVertex3d(0, 80, 0);
    glTexCoord2d(0, 1); glVertex3d(0, 0, 0);

    // bal oldal
    glTexCoord2d(0, 0); glVertex3d(80, 0, 0);
    glTexCoord2d(1, 0); glVertex3d(80, 80, 0);
    glTexCoord2d(1, 1); glVertex3d(80, 80, 80);
    glTexCoord2d(0, 1); glVertex3d(80, 0, 80);

    // hátul
    glTexCoord2d(0, 0); glVertex3d(0, 0, 0);
    glTexCoord2d(1, 0); glVertex3d(0, 80, 0);
    glTexCoord2d(1, 1); glVertex3d(0, 80, 80);
    glTexCoord2d(0, 1); glVertex3d(0, 0, 80);

    // jobb oldal
    glTexCoord2d(0, 0); glVertex3d(0, 0, 0);
    glTexCoord2d(1, 0); glVertex3d(80, 0, 0);
    glTexCoord2d(1, 1); glVertex3d(80, 0, 80);
    glTexCoord2d(0, 1); glVertex3d(0, 0, 80);

    // fent
    glTexCoord2d(0, 0); glVertex3d(0, 80, 80);
    glTexCoord2d(1, 0); glVertex3d(80, 80, 80);
    glTexCoord2d(1, 1); glVertex3d(80, 80, 0);
    glTexCoord2d(0, 1); glVertex3d(0, 80, 0);

    // lent
    glTexCoord2d(0, 0); glVertex3d(80, 0, 80);
    glTexCoord2d(1, 0); glVertex3d(80, 80, 80);
    glTexCoord2d(1, 1); glVertex3d(0, 80, 80);
    glTexCoord2d(0, 1); glVertex3d(0, 0, 80);
    glEnd();
}