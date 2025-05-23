/*
** EPITECH PROJECT, 2025
** destroy_textured_sprite
** File description:
** destroy_textured_sprite.c
*/
#include "wolfengine.h"

void destroy_textured_sprite(sfSprite *sprite)
{
    const sfTexture *sprite_texture = (sprite == NULL) ? NULL
        : sfSprite_getTexture(sprite);

    if (sprite != NULL) {
        sfSprite_destroy((void *)sprite);
        if (sprite_texture != NULL)
            sfTexture_destroy((void *)sprite_texture);
    }
}
