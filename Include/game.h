//
// Created by Dani on 2019. 04
//

#ifndef GAME_H
#define GAME_H

#include "model.h"
#include "texture.h"

typedef struct GameObject {
    Texture texture;
    Model model;
    double posX;
    double posY;
    double posZ;
    double rotateX;
    double rotateY;
    double rotateZ;
} GameObject;

void initGame();

void renderGame();


#endif //GAME_H
