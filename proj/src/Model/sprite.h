//
// Created by joao on 26-04-2024.
//

#ifndef SHARED_SPRITE_H
#define SHARED_SPRITE_H
#include "Controller/Video/graphic.h"
typedef struct {
    int x, y; // current position
    int width, height; // dimensions
    int xspeed, yspeed; // current speed
    uint32_t *map; // the pixmap
} Sprite;
Sprite *create_sprite(xpm_map_t pic);
void destroy_sprite(Sprite *sp);
#endif //SHARED_SPRITE_H
