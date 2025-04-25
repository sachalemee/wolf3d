/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-marin.jeunot
** File description:
** init_entity
*/

#include "wolfengine.h"

void destroy_entity(entity_t *entity)
{
    if (entity != NULL) {
        if (entity->sprite.texture_bg != NULL)
            sfTexture_destroy(entity->sprite.texture_bg);
        if (entity->sprite.sprite_bg != NULL)
            sfSprite_destroy(entity->sprite.sprite_bg);
    }
    free(entity);
}

int init_entity(entity_t **entity)
{
    *entity = calloc(1, sizeof(entity_t));
    if (*entity != NULL) {
        (*entity)->sprite.texture_bg =
            sfTexture_createFromFile(BG_MENU, sfFalse);
        (*entity)->sprite.sprite_bg = sfSprite_create();
    }
    if (*entity == NULL
        || (*entity)->sprite.texture_bg == NULL
        || (*entity)->sprite.sprite_bg == NULL) {
        destroy_entity(*entity);
        return FAILURE;
    }
    sfSprite_setTexture((*entity)->sprite.sprite_bg,
        (*entity)->sprite.texture_bg, sfTrue);
    (*entity)->anim.rect = (sfIntRect){BACKGROUND_MENU_DEF};
    (*entity)->anim.current_frame = 0;
    (*entity)->anim.max_frame = BG_MAX_FRAME;
    return SUCCESS;
}
