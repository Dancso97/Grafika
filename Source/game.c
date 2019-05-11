//
// Created by Dani on 2019. 04
//

#include <GL/glut.h>

#include "game.h"
#include "model.h"
#include "draw.h"
#include "texture.h"
#include "constants.h"

GameObject gameObjects[2];
Model models[1]; //azért van rá szükség mert többször is le lehet rakni ugyan azt az objektumot
Texture textures[8]; //azért van rá szükség mert több textúrája is lehet egy objektumnak

void initGame() {
    load_model("Model/planet", &(models[0]));

    scale_model(&(models[0]), 0.2, 0.2, 0.2);

    loadTexture(&(textures[0]), "Texture/EarthMap.jpg");
    loadTexture(&(textures[1]), "Texture/MoonMap.jpg");

	//Skybox
	loadTexture(&(textures[2]), "Texture/cwd_ft.JPG");
	loadTexture(&(textures[3]), "Texture/cwd_rt.JPG");
	loadTexture(&(textures[4]), "Texture/cwd_lf.JPG");
	loadTexture(&(textures[5]), "Texture/cwd_dn.JPG");
	loadTexture(&(textures[6]), "Texture/cwd_up.JPG");
    loadTexture(&(textures[7]), "Texture/cwd_bk.JPG");


    gameObjects[0].model = models[0];
    gameObjects[0].texture = textures[0];
    gameObjects[0].posX = -2.0;
    gameObjects[0].posY = 0.0;
    gameObjects[0].posZ = 0.0;
    gameObjects[0].rotateX = 0.0;
    gameObjects[0].rotateY = 0.0;
    gameObjects[0].rotateZ = 0.0;

    gameObjects[1].model = models[0];
    gameObjects[1].texture = textures[1];
    gameObjects[1].posX = 2.0;
    gameObjects[1].posY = 0.0;
    gameObjects[1].posZ = 0.0;
    gameObjects[1].rotateX = 0.0;
    gameObjects[1].rotateY = 0.0;
    gameObjects[1].rotateZ = 0.0;
}

void renderGame() {
    // egyesével rajzoljuk ki az objektumokat:
	glPushMatrix();
    draw_Sky(textures);
	glPopMatrix();
	
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, gameObjects[0].texture.id);
    glTranslatef(gameObjects[0].posX, gameObjects[0].posY, gameObjects[0].posZ);

    glRotatef(gameObjects[0].rotateX, 1, 0, 0);
    glRotatef(gameObjects[0].rotateY, 0, 1, 0);
    glRotatef(gameObjects[0].rotateZ, 0, 0, 1);
    draw_model(&(gameObjects[0].model));
    glPopMatrix();

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, gameObjects[1].texture.id);
    glTranslatef(gameObjects[1].posX, gameObjects[1].posY, gameObjects[1].posZ);

    glRotatef(gameObjects[1].rotateX, 1, 0, 0);
    glRotatef(gameObjects[1].rotateY, 0, 1, 0);
    glRotatef(gameObjects[1].rotateZ, 0, 0, 1);
    draw_model(&(gameObjects[1].model));
    glPopMatrix();

    // de lehet ciklussal is:
    // for(int i = 0; i < 2; i++)
    // {
    //   glPushMatrix();
    //     glBindTexture(GL_TEXTURE_2D, gameObjects[i].texture.id);
    //     glTranslatef(gameObjects[i].posX, gameObjects[i].posY, gameObjects[i].posZ);

    //     glRotatef(gameObjects[i].rotateX, 1, 0, 0);
    //     glRotatef(gameObjects[i].rotateY, 0, 1, 0);
    //     glRotatef(gameObjects[i].rotateZ, 0, 0, 1);
    //     draw_model(&(gameObjects[i].model) );
    //   glPopMatrix();
    // }

}

void updateAnimatedObject(double rotationDegree) {
	gameObjects[0].rotateY = rotationDegree;
}
