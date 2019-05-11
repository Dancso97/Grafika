//
// Created by Dani on 2019. 04
//

#include <GL/glut.h>

#include "draw.h"
#include "model.h"
#include "constants.h"

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

void draw_Sky(Texture* texture){
	//Skyboxra kikapcsoljunk a fényeket hogy a képet adjuk vissza
	glDisable(GL_LIGHTING);
	
	// elől
	glBindTexture(GL_TEXTURE_2D, texture[2].id);
    glBegin(GL_QUADS);
		glTexCoord2d(0, 0); glVertex3d(100, -100, 100);
		glTexCoord2d(1, 0); glVertex3d(100, 100, 100);
		glTexCoord2d(1, 1); glVertex3d(-100, 100, 100);
		glTexCoord2d(0, 1); glVertex3d(-100, -100, 100);
	glEnd();

    // jobb oldal
	glBindTexture(GL_TEXTURE_2D, texture[3].id);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0); glVertex3d(100, -100, -100);
		glTexCoord2d(1, 0); glVertex3d(100, 100, -100);
		glTexCoord2d(1, 1); glVertex3d(100, 100, 100);
		glTexCoord2d(0, 1); glVertex3d(100, -100, 100);
	glEnd();
	
    // bal
	glBindTexture(GL_TEXTURE_2D, texture[4].id);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0); glVertex3d(-100, -100, -100);
		glTexCoord2d(1, 0); glVertex3d(-100, 100, -100);
		glTexCoord2d(1, 1); glVertex3d(-100, 100, 100);
		glTexCoord2d(0, 1); glVertex3d(-100, -100, 100);
	glEnd();
	
    // alul
	glBindTexture(GL_TEXTURE_2D, texture[5].id);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0); glVertex3d(-100, -100, -100);
		glTexCoord2d(1, 0); glVertex3d(100, -100, -100);
		glTexCoord2d(1, 1); glVertex3d(100, -100, 100);
		glTexCoord2d(0, 1); glVertex3d(-100, -100, 100);
	glEnd();
	
    // fent
	glBindTexture(GL_TEXTURE_2D, texture[6].id);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0); glVertex3d(-100, 100, 100);
		glTexCoord2d(1, 0); glVertex3d(100, 100, 100);
		glTexCoord2d(1, 1); glVertex3d(100, 100, -100);
		glTexCoord2d(0, 1); glVertex3d(-100, 100, -100);
	glEnd();
	
    // hátul
	glBindTexture(GL_TEXTURE_2D, texture[7].id);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0); glVertex3d(100, -100, -100);
		glTexCoord2d(1, 0); glVertex3d(100, 100, -100);
		glTexCoord2d(1, 1); glVertex3d(-100, 100, -100);
		glTexCoord2d(0, 1); glVertex3d(-100, -100, -100);
	glEnd();
	
	//Visszakapcsoljuk a fényeket
	glEnable(GL_LIGHTING);
}