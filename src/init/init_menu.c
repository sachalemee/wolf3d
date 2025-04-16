/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-marin.jeunot
** File description:
** init_menu
*/

#include "wolfengine.h"
#include <stdlib.h>
#include <stddef.h>

entity_t *init_entity(void)
{
    entity_t *entity = malloc(sizeof(entity_t));

    if (entity == NULL)
        return NULL;
    entity->sprite = malloc(sizeof(sprite_t));
    if (entity->sprite == NULL)
        return NULL;
    entity->anim = malloc(sizeof(anim_t));
    if (entity->anim == NULL)
        return NULL;
    entity->sprite->sprite = NULL;
    entity->sprite->texture = NULL;
    entity->anim->current_frame = 0;
    entity->anim->max_frame = 0;
    entity->anim->rect = (sfIntRect){0, 0, 0, 0};
    return entity;
}

int init_menu(entity_t *entity)
{
    entity = init_entity();
    entity->sprite->texture = sfTexture_createFromFile(BACKGROUND_MENU, sfFalse);
    entity->sprite->sprite = sfSprite_create();
    sfSprite_setTexture(entity->sprite->sprite, entity->sprite->texture, sfTrue);
    entity->anim->rect = (sfIntRect){0, 0, 1791, 1000};
    entity->anim->clock_anim = sfClock_create();
    entity->anim->current_frame = 0;
    entity->anim->max_frame = 8;
    return 0;
}

