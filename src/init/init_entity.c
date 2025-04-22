/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-marin.jeunot
** File description:
** init_entity
*/

#include "wolfengine.h"

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
    entity->sprite->sprite_bg = NULL;
    entity->sprite->texture_bg = NULL;
    entity->anim->current_frame = 0;
    entity->anim->max_frame = 0;
    entity->anim->rect = (sfIntRect){0, 0, 0, 0};
    return entity;
}
