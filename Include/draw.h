//
// Created by Dani on 2019. 04.
//

#ifndef DRAW_H
#define DRAW_H

#include "model.h"
#include "texture.h"


/**
 * Draws the given model (1.param)
 */
void draw_model(const struct Model *model);

/**
 * Draws the triangles of the model.
 */
void draw_triangles(const struct Model *model);

/**
 * Draws the quads of the model.
 */
void draw_quads(const struct Model *model);

void draw_Sky(Texture* texture);

#endif /* DRAW_H */
