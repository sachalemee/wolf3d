/*
** EPITECH PROJECT, 2025
** G-ING-200-PAR-2-1-myworld-sacha.lemee
** File description:
** set_sprite.c
*/

#include "buttons.h"
#include "wolfengine.h"

void set_sprite(buttons_t *button, sfFloatRect bounds,
    sfVector2f origin, char *path)
{
    sfVector2u size_texture = {0};
    sfVector2f scale = {0};

    button->texture = sfTexture_createFromFile(path, NULL);
    if (button->texture == NULL)
        return;
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    size_texture = sfTexture_getSize(button->texture);
    scale = (sfVector2f){(button->size.x - 6) /
        (float)(size_texture.x - 6), (button->size.y - 6)
        / (float)(size_texture.y - 6)};
    button->scale = scale;
    sfSprite_setScale(button->sprite, scale);
    bounds = sfSprite_getGlobalBounds(button->sprite);
    origin = (sfVector2f){button->pos.x + ((button->size.x / 2.0f)
        - (bounds.width / 2.0f)), button->pos.y +
        ((button->size.y / 2.0f) - (bounds.height / 2.0f))};
    sfSprite_setPosition(button->sprite, origin);
}
