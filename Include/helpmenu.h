//
// Created by Dani on 2019. 04.
//

#ifndef HELPMENU_H
#define HELPMENU_H

#include <stdbool.h>

#include "texture.h"

typedef struct HelpMenu {
    bool isShown;
    Texture texture;
} HelpMenu;

void initHelpMenu();

void helpmenuKeyboardSpecialButtonHandler(int key, int x, int y);

void renderHelpMenuIfVisible();

void renderHelpMenu();

#endif //HELPMENU_H
